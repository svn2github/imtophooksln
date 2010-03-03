#include "stdafx.h"
#include "TouchLibFilter.h"
#include "TouchLibFilterProp.h"
#include "TouchLibFilterApp.h"
#include "cv.h"
#include "MyMediaSample.h"
#include "d3dx9.h"
#include "highgui.h"
#include "BackgroundFilter.h"
#include <algorithm>
TouchLibFilter::TouchLibFilter(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData)
: CMuxTransformFilter(NAME("TouchLib Filter"), 0, CLSID_TouchLibFilter)
{ 
	m_monolabel = "null";
	m_bgLabel = "null";
	m_shpLabel = "null";
	m_scalerLabel = "null";
	m_rectifyLabel = "null";
	m_pTouchScreen = NULL;
	m_oscSender = OSCSender::GetOSCSender();
	m_bFingerFlipY = false;

	m_ROIData.m_nRECTs = 1;
	m_ROIData.m_pRECTs = new fRECT[1];
	m_ROIData.m_pRECTs[0].left = 0; m_ROIData.m_pRECTs[0].top = 0;
	m_ROIData.m_pRECTs[0].right = 1; m_ROIData.m_pRECTs[0].bottom = 1;
}
TouchLibFilter::~TouchLibFilter()
{
	DestoryTouchScreen();
	if (m_oscSender != NULL)
	{
		m_oscSender->Release();
		m_oscSender = NULL;
	}
}

CUnknown *WINAPI TouchLibFilter::CreateInstance(LPUNKNOWN punk, HRESULT *phr)
{
	ASSERT(phr);
	// assuming we don't want to modify the data
	TouchLibFilter *pNewObject = new TouchLibFilter(punk, phr, FALSE);

	if(pNewObject == NULL) {
		if (phr)
			*phr = E_OUTOFMEMORY;
	}
	return pNewObject;
}

HRESULT TouchLibFilter::NonDelegatingQueryInterface(REFIID iid, void **ppv)
{
	if (iid == IID_ITouchLibFilter) 
	{
		return GetInterface(static_cast<ITouchLibFilter*>(this), ppv);
	}
	else if (iid == IID_ISpecifyPropertyPages)
	{
		return GetInterface(
			static_cast<ISpecifyPropertyPages*>(this),	ppv);
	}
	else if (iid == IID_IMSPersist)
	{
		return GetInterface(
			static_cast<IMSPersist*>(this),	ppv);
	}
	else
	{
		// Call the parent class.
		return CBaseFilter::NonDelegatingQueryInterface(iid, ppv);
	}
}


HRESULT TouchLibFilter::Receive(IMediaSample *pSample, const IPin* pReceivePin)
{
	if (m_pInputPins.size() >= 0 && pReceivePin == m_pInputPins[0] )
	{
		return ReceiveInput0(pSample, pReceivePin);
	}
	else if (m_pInputPins.size() >= 1 && pReceivePin == m_pInputPins[1])
	{
		return ReceiveROI(pSample, pReceivePin);
	}
	return S_FALSE;
}

HRESULT TouchLibFilter::CreatePins()
{
	HRESULT hr = S_OK;
	if (m_pInputPins.size() < 2 || m_pOutputPins.size() < 1) {
		for (int c = 0; c< m_pInputPins.size(); c++)
		{
			delete m_pInputPins[c];
			m_pInputPins[c] = NULL;
		}
		m_pInputPins.clear();
		for (int c = 0; c< m_pOutputPins.size(); c++)
		{
			delete m_pOutputPins[c];
			m_pOutputPins[c] = NULL;
		}
		m_pOutputPins.clear();

		CMuxTransformInputPin* pInput0 = new CMuxTransformInputPin(NAME("CMuxTransform input pin"),
			this,              // Owner filter
			&hr,               // Result code
			L"input");      // Pin name
		//  Can't fail
		CMuxTransformInputPin* pInput1 = new CMuxTransformInputPin(NAME("Touchlib ROI pin"),
			this,              // Owner filter
			&hr,               // Result code
			L"ROI data");      // Pin name
		

		CMuxTransformOutputPin* pOutput0 = new CMuxTransformOutputPin(NAME("Transform output pin"),
			this,            // Owner filter
			&hr,             // Result code
			L"output");   // Pin name
		// Can't fail
		CMuxTransformOutputPin* pOutput1 = new CMuxTransformOutputPin(NAME("Transform output pin"),
			this,            // Owner filter
			&hr,             // Result code
			L"foreground");   // Pin name
		// Can't fail

		m_pInputPins.push_back(pInput0);
		m_pInputPins.push_back(pInput1);
		m_pOutputPins.push_back(pOutput0);
		m_pOutputPins.push_back(pOutput1);

	}
	return S_OK;
}

HRESULT TouchLibFilter::CheckInputType( const CMediaType * pmt , const IPin* pPin)
{
	CheckPointer(pmt, E_POINTER);
	if (m_pInputPins.size() >= 1 && m_pInputPins[0] == pPin) 
	{	
		CheckPointer(pmt, E_POINTER);
		if (!IsEqualGUID(*pmt->FormatType(), FORMAT_VideoInfo)) 
		{
			return E_INVALIDARG;
		}
		// Can we transform this type
		if(IsAcceptedType(pmt)){
			return NOERROR;
		}
	}
	else if (m_pInputPins.size() >= 2 && m_pInputPins[1] == pPin)
	{	
		CheckPointer(pmt, E_POINTER);
		
		if (IsEqualGUID(*pmt->Type(), GUID_MyMediaSample) && 
			IsEqualGUID(*pmt->Subtype(), GUID_ROIData))
		{
			return NOERROR;
		}
	}
	return E_FAIL;
}

HRESULT TouchLibFilter::CheckOutputType( const CMediaType * pmt , const IPin* pPin)
{
	if (m_pOutputPins.size() > 0 && m_pOutputPins[0] == pPin)
	{
		CheckPointer(pmt, E_POINTER);
		if (*pmt->FormatType() != FORMAT_VideoInfo) {
			return E_INVALIDARG;
		}

		// Can we transform this type
		if(IsAcceptedType(pmt)){
			return NOERROR;
		}
	}
	if (m_pOutputPins.size() > 1 && m_pOutputPins[1] == pPin)
	{
		CheckPointer(pmt, E_POINTER);
		if (!IsEqualGUID(*pmt->Type(), GUID_MyMediaSample) || !IsEqualGUID(*pmt->Subtype(), GUID_ForegroundRegion_Data))
		{
			return E_INVALIDARG;
		}
		return S_OK;
	}
	return E_FAIL;
}

HRESULT TouchLibFilter::CompleteConnect(PIN_DIRECTION direction, const IPin* pMyPin, const IPin* pOtherPin)
{
	if (m_pInputPins.size() >= 1 && m_pInputPins[0] == pMyPin)
	{
		CMediaType mt = m_pInputPins[0]->CurrentMediaType();
		if (IsEqualGUID(*mt.Type(), GUID_MyMediaSample) && IsEqualGUID(*mt.Subtype(), GUID_D3DXTEXTURE9_POINTER))
		{
			D3DSURFACE_DESC* desc = ((D3DSURFACE_DESC* ) (mt.pbFormat));
			CreateTouchScreen(desc->Width, desc->Height, false);
		}
		else
		{
			VIDEOINFOHEADER *pvi = (VIDEOINFOHEADER *) mt.pbFormat;
			BITMAPINFOHEADER bitHeader = pvi->bmiHeader;
			CreateTouchScreen(bitHeader.biWidth, bitHeader.biHeight, false);
		}
	}

	return S_OK;
}

HRESULT TouchLibFilter::BreakConnect(PIN_DIRECTION dir, const IPin* pPin)
{
	if (pPin = m_pInputPins[1])
	{
		ROIData roiData;
		roiData.m_nRECTs = 1;
		roiData.m_pRECTs = new fRECT[1];
		roiData.m_pRECTs[0].left = 0; roiData.m_pRECTs[0].top = 0;
		roiData.m_pRECTs[0].right = 1; roiData.m_pRECTs[0].bottom = 1;
		CAutoLock lck(&m_csROIData);
		m_ROIData = roiData;
	}
	return __super::BreakConnect(dir, pPin);
}


HRESULT TouchLibFilter::DecideBufferSize(IMemAllocator *pAlloc, const IPin* pOutPin, ALLOCATOR_PROPERTIES *pProp)
{
	HRESULT hr = NOERROR;
	if (m_pInputPins.size() <= 0)
	{
		return S_FALSE;
	}
	CMediaType inputMT = GetConnectedInputPin()->CurrentMediaType();
	if (inputMT.Type() == NULL)
	{
		return S_FALSE;
	}
	if (m_pOutputPins.size() > 0 && m_pOutputPins[0] == pOutPin) 
	{
		VIDEOINFOHEADER *pvi = (VIDEOINFOHEADER *) inputMT.pbFormat;
		BITMAPINFOHEADER bitHeader = pvi->bmiHeader;

		pProp->cBuffers = 1;
		pProp->cbBuffer = inputMT.GetSampleSize();
		if (pProp->cbAlign == 0)
		{
			pProp->cbAlign = 1;
		}

		ALLOCATOR_PROPERTIES Actual;
		hr = pAlloc->SetProperties(pProp,&Actual);
		if (FAILED(hr)) {
			return hr;
		}
		ASSERT( Actual.cBuffers == 1 );
		if (pProp->cBuffers > Actual.cBuffers ||
			pProp->cbBuffer > Actual.cbBuffer) {
				return E_FAIL;
		}
	}
	else if	(m_pOutputPins.size() > 1 && m_pOutputPins[1] == pOutPin)
	{
		pProp->cBuffers = 1;
		pProp->cbBuffer = sizeof(ForegroundRegion);
		if (pProp->cbAlign == 0)
		{
			pProp->cbAlign = 1;
		}
		ALLOCATOR_PROPERTIES Actual;
		hr = pAlloc->SetProperties(pProp,&Actual);
		if (FAILED(hr)) {
			return hr;
		}
		ASSERT( Actual.cBuffers == 1 );
		if (pProp->cBuffers > Actual.cBuffers ||
			pProp->cbBuffer > Actual.cbBuffer) {
				return E_FAIL;
		}
	}

	return NOERROR;
}


HRESULT TouchLibFilter::GetMediaType(int iPosition, const IPin* pOutPin, __inout CMediaType *pMediaType)
{
	if (iPosition < 0) {
		return E_INVALIDARG;
	}
	if (iPosition >= 1) { // WATCH OUT !!
		return VFW_S_NO_MORE_ITEMS;
	}
	if (m_pInputPins.size() <= 0)
	{
		return VFW_S_NO_MORE_ITEMS;
	}
	if (m_pOutputPins.size() > 0 && m_pOutputPins[0] == pOutPin)
	{
		CMediaType inputMT = m_pInputPins[0]->CurrentMediaType();
		*pMediaType = inputMT;
		return S_OK;
	}
	if (m_pOutputPins.size() > 1 && m_pOutputPins[1] == pOutPin)
	{
		CMediaType mt;
		mt.SetType(&GUID_MyMediaSample);
		mt.SetSubtype(&GUID_ForegroundRegion_Data);
		mt.SetSampleSize(sizeof(ForegroundRegion));
		*pMediaType = mt;
		return S_OK;
	}

	return VFW_S_NO_MORE_ITEMS;
}


bool TouchLibFilter::IsAcceptedType(const CMediaType *pmt)
{
	GUID guidSubType = *pmt->Subtype();

	if (IsEqualGUID(*pmt->Type(), MEDIATYPE_Video)) 
	{
		VIDEOINFOHEADER* pvi = (VIDEOINFOHEADER*)pmt->Format();
		BITMAPINFOHEADER bitHeader = pvi->bmiHeader;
		if (bitHeader.biCompression)
		{
			return false;
		}
		if(IsEqualGUID(guidSubType, MEDIASUBTYPE_RGB24))
		{
			return true;
		}
		else if(IsEqualGUID(guidSubType, MEDIASUBTYPE_RGB32) ||
			IsEqualGUID(guidSubType, MEDIASUBTYPE_ARGB32))
		{
			return true;
		}
	}
	
	return false;
}

HRESULT TouchLibFilter::GetPages(CAUUID *pPages)
{
	pPages->cElems = 1;
	pPages->pElems = (GUID*)CoTaskMemAlloc(sizeof(GUID));
	if (pPages->pElems == NULL) 
	{
		return E_OUTOFMEMORY;
	}
	pPages->pElems[0] = CLSID_TouchLibPropPage;
	return S_OK;
}

bool TouchLibFilter::CreateTouchScreen(float cw, float ch, bool bSkipbackgroundRemove)
{
	if (m_pTouchScreen != NULL)
	{
		delete m_pTouchScreen;
		m_pTouchScreen = NULL;
	}
	m_pTouchScreen = new CTouchScreen(cw, ch);
	m_pTouchScreen->setDebugMode(false);
	m_monolabel = m_pTouchScreen->pushFilter("mono");
	if (!bSkipbackgroundRemove)
	{
		m_bgLabel = m_pTouchScreen->pushFilter("backgroundremove");
		m_pTouchScreen->setParameter(m_bgLabel, "threshold", "0");
	}
	m_shpLabel = m_pTouchScreen->pushFilter("simplehighpass");
	m_pTouchScreen->setParameter( m_shpLabel, "blur", "13");
	m_pTouchScreen->setParameter( m_shpLabel, "noise", "3");

	m_scalerLabel = m_pTouchScreen->pushFilter("scaler");
	m_pTouchScreen->setParameter(m_scalerLabel, "level", "70");

	m_rectifyLabel = m_pTouchScreen->pushFilter("rectify");
	m_pTouchScreen->setParameter(m_rectifyLabel, "level", "75");
	if (!bSkipbackgroundRemove)
	{
		m_pTouchScreen->setParameter(m_bgLabel, "mask", (char*)m_pTouchScreen->getCameraPoints());
		m_pTouchScreen->setParameter(m_bgLabel, "capture", "");
	}
	m_pTouchScreen->registerListener((ITouchListener*)this);
	registerListener(m_oscSender);
	
	return true;
}
bool TouchLibFilter::SetBGThreshold(int threshold)
{
	if (m_pTouchScreen == NULL)
	{
		return false;
	}
	if (m_bgLabel == "null")
	{
		return false;
	}
	char para[MAX_PATH];
	sprintf(para, "%d", threshold);
	m_pTouchScreen->setParameter(m_bgLabel, "threshold", para);
	return true;
}

bool TouchLibFilter::GetBGThreshold(int& threshold)
{
	if (m_pTouchScreen == NULL)
	{
		return false;
	}
	if (m_bgLabel == "null")
	{
		return false;
	}
	list<Filter*> pFilterList = m_pTouchScreen->findFiltersPtr(m_bgLabel);
	if (pFilterList.size() <= 0)
		return false;
	Filter* pBgFilter = *pFilterList.begin();
	ParameterMap paraMap;
	pBgFilter->getParameters(paraMap);

	if (paraMap.find("threshold") == paraMap.end())
		return false;
	
	sscanf_s(paraMap["threshold"].c_str(), "%d", &threshold);
	return true;
}
bool TouchLibFilter::SetSimpleHighPassBlur(int blur)
{
	if (m_pTouchScreen == NULL)
	{
		return false;
	}
	if (m_shpLabel == "null")
	{
		return false;
	}
	char para[MAX_PATH];
	sprintf(para, "%d", blur);
	m_pTouchScreen->setParameter(m_shpLabel, "blur", para);

	return true;
}

bool TouchLibFilter::GetSimpleHighPassBlur(int& blur)
{
	if (m_pTouchScreen == NULL)
	{
		return false;
	}
	if (m_shpLabel == "null")
	{
		return false;
	}
	list<Filter*> pFilterList = m_pTouchScreen->findFiltersPtr(m_shpLabel);
	if (pFilterList.size() <= 0)
		return false;

	Filter* pSHPFilter = *pFilterList.begin();
	ParameterMap paraMap;
	pSHPFilter->getParameters(paraMap);

	if (paraMap.find("blur") == paraMap.end())
		return false;

	sscanf_s(paraMap["blur"].c_str(), "%d", &blur);
	return true;
}

bool TouchLibFilter::SetSimpleHighPassDeNoise(int deNoise)
{
	if (m_pTouchScreen == NULL)
	{
		return false;
	}
	if (m_shpLabel == "null")
	{
		return false;
	}
	char para[MAX_PATH];
	sprintf(para, "%d", deNoise);
	m_pTouchScreen->setParameter(m_shpLabel, "noise", para);
	return true;
}
bool TouchLibFilter::GetSimpleHighPassDeNoise(int& deNoise)
{
	if (m_pTouchScreen == NULL)
	{
		return false;
	}
	if (m_shpLabel == "null")
	{
		return false;
	}
	list<Filter*> pFilterList = m_pTouchScreen->findFiltersPtr(m_shpLabel);
	if (pFilterList.size() <= 0)
		return false;

	Filter* pSHPFilter = *pFilterList.begin();
	ParameterMap paraMap;
	pSHPFilter->getParameters(paraMap);

	if (paraMap.find("noise") == paraMap.end())
		return false;

	sscanf_s(paraMap["noise"].c_str(), "%d", &deNoise);
	return true;
}

bool TouchLibFilter::SetScaleLevel(int level)
{
	if (m_pTouchScreen == NULL)
	{
		return false;
	}
	if (m_scalerLabel == "null")
	{
		return false;
	}
	char para[MAX_PATH];
	sprintf(para, "%d", level);
	m_pTouchScreen->setParameter(m_scalerLabel, "level", para);
	return true;
}
bool TouchLibFilter::GetScaleLevel(int& level)
{
	if (m_pTouchScreen == NULL)
	{
		return false;
	}
	if (m_scalerLabel == "null")
	{
		return false;
	}
	list<Filter*> pFilterList = m_pTouchScreen->findFiltersPtr(m_scalerLabel);
	if (pFilterList.size() <= 0)
		return false;

	Filter* pScaleFilter = *pFilterList.begin();
	ParameterMap paraMap;
	pScaleFilter->getParameters(paraMap);

	if (paraMap.find("level") == paraMap.end())
		return false;

	sscanf_s(paraMap["level"].c_str(), "%d", &level);
	return true;
}

bool TouchLibFilter::SetRectifyLevel(int level)
{
	if (m_pTouchScreen == NULL)
	{
		return false;
	}
	if (m_rectifyLabel == "null")
	{
		return false;
	}
	char para[MAX_PATH];
	sprintf(para, "%d", level);
	m_pTouchScreen->setParameter(m_rectifyLabel, "level", para);
	return true;
}

bool TouchLibFilter::GetRectifyLevel(int& level)
{
	if (m_pTouchScreen == NULL)
	{
		return false;
	}
	if (m_rectifyLabel == "null")
	{
		return false;
	}
	list<Filter*> pFilterList = m_pTouchScreen->findFiltersPtr(m_rectifyLabel);
	if (pFilterList.size() <= 0)
		return false;
	Filter* pRectifyFilter = *pFilterList.begin();
	ParameterMap paraMap;
	pRectifyFilter->getParameters(paraMap);

	if (paraMap.find("level") == paraMap.end())
		return false;

	sscanf_s(paraMap["level"].c_str(), "%d", &level);
	return true;
}


bool TouchLibFilter::DestoryTouchScreen()
{
	if (m_pTouchScreen != NULL)
	{
		delete m_pTouchScreen;
		m_pTouchScreen = NULL;
	}
	return true;
}
bool TouchLibFilter::ShowConfigWindow(bool bShow)
{
	if (m_pTouchScreen == NULL)
	{
		return false;
	}
	CAutoLock lck(&m_csTouchScreen);
	return m_pTouchScreen->showFilterOutputs(bShow);
}

HRESULT TouchLibFilter::TransformInput0(IMediaSample *pSample, IMediaSample *pOut)
{
	if (m_pInputPins.size() < 1)
		return S_FALSE;
	if (m_pTouchScreen == NULL)
	{
		return S_FALSE;
	}
	BYTE* pInData = NULL; 
	BYTE* pOutData = NULL;
	pOut->GetPointer(&pOutData);
	IplImage* pSrc = NULL;
	IplImage* pDest = NULL;

	int channel = 4;
	CMediaType mt = ((CMuxTransformInputPin*)this->GetConnectedInputPin())->CurrentMediaType();
	

	VIDEOINFOHEADER *pvi = (VIDEOINFOHEADER *) mt.pbFormat;
	BITMAPINFOHEADER bitHeader = pvi->bmiHeader;
	
	if (IsEqualGUID(*mt.Subtype(), MEDIASUBTYPE_RGB24)) 
	{
		channel = 3;
	}
	else if (IsEqualGUID(*mt.Subtype(), MEDIASUBTYPE_RGB32) ||
		IsEqualGUID(*mt.Subtype(), MEDIASUBTYPE_ARGB32))
	{
		channel = 4;
	}
	else
	{
		return S_FALSE;
	}
	pSrc = cvCreateImageHeader(cvSize(bitHeader.biWidth, bitHeader.biHeight), 8, channel);
	pDest = cvCreateImageHeader(cvSize(bitHeader.biWidth, bitHeader.biHeight), 8, channel);
	


	pSample->GetPointer(&pInData);
	pOut->GetPointer(&pOutData);
	pSrc->imageData = (char*)pInData;
	pDest->imageData = (char*)pOutData;
	if (GetbFlipY())
	{
		cvFlip(pSrc, NULL, 0);
	}
	{
		ROIData roiData;
		{
			CAutoLock lck(&m_csROIData);
			roiData = m_ROIData;
		}
		CAutoLock lck(&m_csTouchScreen);
		
		m_pTouchScreen->processOnce(pSrc, &roiData);
		m_pTouchScreen->getEvents();
	}
	
	cvCopy(pSrc, pDest);
	if (GetbFlipY())
	{
		cvFlip(pSrc, NULL, 0);
	}
	if (pSrc != NULL)
	{
		cvReleaseImageHeader(&pSrc);
		pSrc = NULL;
	}
	if (pDest != NULL)
	{
		cvReleaseImageHeader(&pDest);
		pDest = NULL;
	}
	return S_OK;
}
CMuxTransformInputPin* TouchLibFilter::GetConnectedInputPin()
{
	for (int i =0; i< m_pInputPins.size(); i++)
	{
		if (m_pInputPins[i]->IsConnected())
		{
			return m_pInputPins[i];
		}
	}
	return NULL;
}
HRESULT TouchLibFilter::ReceiveInput0(IMediaSample *pSample, const IPin* pReceivePin)
{
	if (m_pOutputPins.size() < 1)
	{
		return S_FALSE;
	}

	AM_SAMPLE2_PROPERTIES * const pProps = ((CMuxTransformInputPin*)pReceivePin)->SampleProps();
	if (pProps->dwStreamId != AM_STREAM_MEDIA) {
		return S_OK;
	}
	ASSERT(pSample);
	IMediaSample * pOutSample;
	// If no output to deliver to then no point sending us data
	ASSERT (m_pOutputPins.size() != NULL);
	HRESULT hr;
	// Set up the output sample

	hr = InitializeOutputSample(pSample, pReceivePin, m_pOutputPins[0], &pOutSample);

	if (FAILED(hr)) {
		return hr;
	}

	// Start timing the transform (if PERF is defined)
	MSR_START(m_idTransform);

	hr = TransformInput0(pSample, pOutSample);
	if (SUCCEEDED(hr))
	{
		SendForegroundSample();
	}
	// Stop the clock and log it (if PERF is defined)
	MSR_STOP(m_idTransform);

	if (FAILED(hr)) {
		DbgLog((LOG_TRACE,1,TEXT("Error from transform")));
	} else {
		// the Transform() function can return S_FALSE to indicate that the
		// sample should not be delivered; we only deliver the sample if it's
		// really S_OK (same as NOERROR, of course.)
		if (hr == NOERROR) {
			hr = m_pOutputPins[0]->Deliver(pOutSample);// m_pInputPin->Receive(pOutSample);
			m_bSampleSkipped = FALSE;	// last thing no longer dropped
		} else {
			// S_FALSE returned from Transform is a PRIVATE agreement
			// We should return NOERROR from Receive() in this cause because returning S_FALSE
			// from Receive() means that this is the end of the stream and no more data should
			// be sent.
			if (S_FALSE == hr) {

				//  Release the sample before calling notify to avoid
				//  deadlocks if the sample holds a lock on the system
				//  such as DirectDraw buffers do
				pOutSample->Release();
				m_bSampleSkipped = TRUE;
				if (!m_bQualityChanged) {
					NotifyEvent(EC_QUALITY_CHANGE,0,0);
					m_bQualityChanged = TRUE;
				}
				return NOERROR;
			}
		}
	}

	// release the output buffer. If the connected pin still needs it,
	// it will have addrefed it itself.
	pOutSample->Release();
	return S_OK;

}

HRESULT TouchLibFilter::ReceiveROI(IMediaSample *pSample, const IPin* pReceivePin)
{
	ROIData* sData = NULL;
	pSample->GetPointer((BYTE**)&sData);
	if (sData == NULL)
	{
		return S_FALSE;
	}
	CAutoLock lck(&m_csROIData);
	m_ROIData = *sData;
	return S_OK;
}
HRESULT TouchLibFilter::SendForegroundSample()
{
	if (m_pOutputPins.size() <= 1 || !m_pOutputPins[1]->IsConnected())
	{
		return S_FALSE;
	}
	HRESULT hr = S_OK;
	vector<CvRect>* fgList = m_pTouchScreen->GetForeground();
	IMemAllocator* pAllocator = m_pOutputPins[1]->Allocator();
	CMediaSample* pSendSample = NULL;
	pAllocator->GetBuffer((IMediaSample**)&pSendSample, NULL, NULL, 0);
	if (pSendSample == NULL)
	{
		return S_FALSE;
	}
	VIDEOINFOHEADER *pvi = (VIDEOINFOHEADER *) m_pInputPins[0]->CurrentMediaType().pbFormat;
	BITMAPINFOHEADER bitHeader = pvi->bmiHeader;

	ForegroundRegion sendData;
	if ( fgList->size() <= 0)
	{
		sendData.foregroundRects = NULL;
		sendData.numForeground = 0;	
	}
	else
	{
		sendData.numForeground = fgList->size();
		sendData.foregroundRects = new fRECT[fgList->size()];
		memset((void*)sendData.foregroundRects, 0, fgList->size()*sizeof(fRECT));
		for (int i =0; i< fgList->size(); i++)
		{
			sendData.foregroundRects[i].left = (float)fgList->at(i).x / (float)bitHeader.biWidth;
			sendData.foregroundRects[i].top = (float)fgList->at(i).y / (float)bitHeader.biHeight;
			sendData.foregroundRects[i].right = (fgList->at(i).x + fgList->at(i).width) /(float)bitHeader.biWidth;
			sendData.foregroundRects[i].bottom = (fgList->at(i).y + fgList->at(i).height) /(float)bitHeader.biHeight;
		}
	}
	hr = pSendSample->SetPointer((BYTE*)&sendData, sizeof(ForegroundRegion));
	hr = m_pOutputPins[1]->Deliver(pSendSample);
	if (pSendSample != NULL)
	{
		pSendSample->Release();
		pSendSample = NULL;
	}
	return S_OK;

}
void TouchLibFilter::registerListener(ITouchListener *listener)
{
	CAutoLock lck(&m_csListenerList);
	m_listenerList.push_back(listener);
}
void TouchLibFilter::unregisterListener(ITouchListener *listener)
{
	CAutoLock lck(&m_csListenerList);
	std::vector<ITouchListener *>::iterator iter;
	iter = find(m_listenerList.begin(), m_listenerList.end(), listener);
	if (iter == m_listenerList.end())	
	{
		return;
	}
	m_listenerList.erase(iter);
}

//ITouchListener
void TouchLibFilter::fingerDown(TouchData data)
{
	for (int i =0; i< m_listenerList.size(); i++)
	{
		m_listenerList[i]->fingerDown(data);
	}
	
}
//! Notify that a finger has just been made active. 
void TouchLibFilter::fingerUpdate(TouchData data)
{
	for (int i =0; i< m_listenerList.size(); i++)
	{
		m_listenerList[i]->fingerUpdate(data);
	}
}
//! A finger is no longer active..
void TouchLibFilter::fingerUp(TouchData data)
{
	for (int i =0; i< m_listenerList.size(); i++)
	{
		m_listenerList[i]->fingerUp(data);
	}
}

bool TouchLibFilter::IsOSCConnected()
{
	return m_oscSender->isConnected();
}
bool TouchLibFilter::ConnectOSC(string ipaddress, int port)
{
	if (m_oscSender->isConnected())
	{
		return false;
	}
	m_oscSender->connectSocket(ipaddress, port);
	return true;
}
bool TouchLibFilter::DisConnectOSC()
{
	m_oscSender->disConnectSocket();
	return true;
}
bool TouchLibFilter::GetIPAddress(string& outIpAddress)
{
	outIpAddress = m_oscSender->m_ipAddress;
	return true;
}
int TouchLibFilter::GetPort()
{
	return m_oscSender->m_port;
}
bool TouchLibFilter::IsTouchReady()
{
	return (m_pTouchScreen != NULL);
}
bool TouchLibFilter::ClearBackground()
{
	if (m_pTouchScreen == NULL)
	{
		return false;
	}
	if (m_bgLabel == "null")
	{
		return false;
	}
	CAutoLock lck(&m_csTouchScreen);
	std::list<Filter*> bgFilter = m_pTouchScreen->findFiltersPtr(m_bgLabel);
	if (bgFilter.size() <= 0 )
	{
		return false;
	}
	((BackgroundFilter*)*bgFilter.begin())->clearBackground();

	return true;
}

bool TouchLibFilter::setStartTracking(bool bStart)
{
	if (m_pTouchScreen == NULL)
		return false;
	CAutoLock lck(&m_csTouchScreen);
	if (bStart)
		m_pTouchScreen->beginTracking();
	else
	{
		m_pTouchScreen->endTracking();
	}
	return true;
}
bool TouchLibFilter::getStartTracking(bool& bStart)
{
	if (m_pTouchScreen == NULL)
	{
		bStart = false;
		return false;
	}
	CAutoLock lck(&m_csTouchScreen);
	bStart = m_pTouchScreen->isTracking();
	return true;
}

bool TouchLibFilter::getDrawFingers()
{
	if (m_pTouchScreen == NULL)
	{
		return false;
	}
	CAutoLock lck(&m_csTouchScreen);
	return m_pTouchScreen->getDrawFingers();
}
bool TouchLibFilter::setDrawFingers(bool drawing)
{
	if (m_pTouchScreen == NULL)
	{
		return false;
	}
	CAutoLock lck(&m_csTouchScreen);
	return m_pTouchScreen->setDrawFingers(drawing);
}


bool TouchLibFilter::getDrawROI()
{
	if (m_pTouchScreen == NULL)
	{
		return false;
	}
	CAutoLock lck(&m_csTouchScreen);
	return m_pTouchScreen->getDrawROI();
}
bool TouchLibFilter::setDrawROI(bool drawing)
{
	if (m_pTouchScreen == NULL)
	{
		return false;
	}
	CAutoLock lck(&m_csTouchScreen);
	return m_pTouchScreen->setDrawROI(drawing);
}

HRESULT TouchLibFilter::SaveToFile(WCHAR* path)
{
	FILE* filestream = NULL;
	_wfopen_s(&filestream, path, L"w");
	if (filestream == NULL)
	{
		return false;
	}
	int bgThreshold = 0;
	int deNoise = 3;
	int blur = 13;
	int scaleLevel = 70;
	int rectifyLevel = 75;
	bool bStartTracking = false;
	bool bDrawFinger = false;
	bool bDrawROI = false;
	bool bFlipY = false;
	GetBGThreshold(bgThreshold);
	GetSimpleHighPassDeNoise(deNoise);
	GetSimpleHighPassBlur(blur);
	GetScaleLevel(scaleLevel);
	GetRectifyLevel(rectifyLevel);
	
	getStartTracking(bStartTracking);
	bDrawFinger = getDrawFingers();
	bDrawROI = getDrawROI();
	bFlipY = GetbFlipY();
	fwprintf_s(filestream, L"%d %d %d %d %d\n %d %d %d %d\n",
		bgThreshold, blur, deNoise, scaleLevel, rectifyLevel,
		bStartTracking, bDrawFinger, bDrawROI, bFlipY);
	fclose(filestream);
	return S_OK;
}
HRESULT TouchLibFilter::LoadFromFile(WCHAR* path)
{
	FILE* filestream = NULL;
	_wfopen_s(&filestream, path, L"r");
	if (filestream == NULL)
	{
		return false;
	}
	int bgThreshold = 0;
	int deNoise = 3;
	int blur = 13;
	int scaleLevel = 70;
	int rectifyLevel = 75;

	int bStartTracking = false;
	int bDrawFinger = false;
	int bDrawROI = false;
	int bFlipY = false;
	fwscanf_s(filestream, L"%d %d %d %d %d\n %d %d %d %d\n",
		&bgThreshold, &blur, &deNoise, &scaleLevel, &rectifyLevel, 
		&bStartTracking, &bDrawFinger, &bDrawROI, &bFlipY);
	fclose(filestream);

	SetBGThreshold(bgThreshold);
	SetSimpleHighPassDeNoise(deNoise);
	SetSimpleHighPassBlur(blur);
	SetScaleLevel(scaleLevel);
	SetRectifyLevel(rectifyLevel);

	setStartTracking(bStartTracking);
	setDrawFingers(bDrawFinger);
	setDrawROI(bDrawROI);
	SetbFlipY(bFlipY);
	return S_OK;
}
HRESULT TouchLibFilter::GetName(WCHAR* name, UINT szName)
{
	if (name == NULL)
	{
		return S_FALSE;
	}
	FILTER_INFO filterInfo;
	this->QueryFilterInfo(&filterInfo);
	wcscpy_s(name, szName, filterInfo.achName);
	if (filterInfo.pGraph != NULL)
	{
		filterInfo.pGraph->Release();
		filterInfo.pGraph = NULL;
	}
	return S_OK;
}

bool TouchLibFilter::GetbFlipY()
{
	CAutoLock lck(&m_csFilterState);
	return m_bFingerFlipY;
}
bool TouchLibFilter::SetbFlipY(bool v)
{
	CAutoLock lck(&m_csFilterState);
	m_bFingerFlipY = v;
	return true;
}