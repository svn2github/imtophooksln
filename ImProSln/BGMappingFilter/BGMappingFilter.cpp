#include "stdafx.h"
#include "BGMappingFilter.h"
#include "BGMappingFilterApp.h"
#include "BGMappingProp.h"
#include "MyMediaSample.h"

BGMappingFilter::BGMappingFilter(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData)
: CMuxTransformFilter(NAME("Background Mapping Filter"), 0, CLSID_BGMappingFilter)
{ 
	backgroundIplImg = NULL;
	foregroundIplImg = NULL;
	cameraInputIplImg = NULL;
	camChannel = 3 ;
	layoutChannel = 3;
	 cameraW  = 640;
	 cameraH  = 480;
	 layoutW  = 800;
	 layoutH  = 600;
	isReceiveCam = false ;
	isReceiveBG = false ;
	
}
BGMappingFilter::~BGMappingFilter()
{
	if(backgroundIplImg!= NULL)
	cvReleaseImage(&backgroundIplImg);
	if(foregroundIplImg!= NULL)
	cvReleaseImage(&foregroundIplImg);
	if(cameraInputIplImg!= NULL)
	cvReleaseImage(&cameraInputIplImg);

}


CUnknown *WINAPI BGMappingFilter::CreateInstance(LPUNKNOWN punk, HRESULT *phr)
{
	ASSERT(phr);
	// assuming we don't want to modify the data
	BGMappingFilter *pNewObject = new BGMappingFilter(punk, phr, FALSE);

	if(pNewObject == NULL) {
		if (phr)
			*phr = E_OUTOFMEMORY;
	}
	return pNewObject;
}

HRESULT BGMappingFilter::NonDelegatingQueryInterface(REFIID iid, void **ppv)
{
	if (iid == IID_IBGMappingFilter) 
	{
		return GetInterface(static_cast<IBGMappingFilter*>(this), ppv);
	}
	if (iid == IID_ISpecifyPropertyPages)
	{
		return GetInterface(
			static_cast<ISpecifyPropertyPages*>(this),	ppv);
	}
	else
	{
		// Call the parent class.
		return CBaseFilter::NonDelegatingQueryInterface(iid, ppv);
	}
}


HRESULT BGMappingFilter::ReceiveCameraImg(IMediaSample *pSample, const IPin* pReceivePin)
{
	if (m_pOutputPins.size() < 1)
	{
		return S_FALSE;
	}

	//if(isReceiveBG == true){
	//	BG->setBackground(backgroundIplImg);
	//	isReceiveBG = false ;
	//}

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

	hr = InitializeOutputSample(pSample, pReceivePin, GetConnectedOutputPin(), &pOutSample);

	if (FAILED(hr)) {
		return hr;
	}

	// Start timing the transform (if PERF is defined)
	MSR_START(m_idTransform);
	hr = Transform(pSample, pOutSample);

	if(hr == S_OK){
		SendForegroundRect();
	}

	// Stop the clock and log it (if PERF is defined)
	//MSR_STOP(m_idTransform);

	if (FAILED(hr)) {
		DbgLog((LOG_TRACE,1,TEXT("Error from transform")));
	} else {
		// the Transform() function can return S_FALSE to indicate that the
		// sample should not be delivered; we only deliver the sample if it's
		// really S_OK (same as NOERROR, of course.)
		if (hr == NOERROR) {
			hr = GetConnectedOutputPin()->Deliver(pOutSample);// m_pInputPin->Receive(pOutSample);
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

HRESULT BGMappingFilter::ReceiveBackground(IMediaSample *pSample, const IPin* pReceivePin)
{	
	AM_SAMPLE2_PROPERTIES * const pProps = ((CMuxTransformInputPin*)pReceivePin)->SampleProps();
	if (pProps->dwStreamId != AM_STREAM_MEDIA) {
		return S_OK;
	}
	ASSERT(pSample);
	long bsize = pSample->GetSize();

	BYTE* backgroundByteData;
	pSample->GetPointer(&backgroundByteData);
	IplImage* backgroundtmp = cvCreateImageHeader(cvSize(layoutW, layoutH), 8, layoutChannel);
	backgroundtmp->imageData = (char*)backgroundByteData;

	cvResize(backgroundtmp,backgroundIplImg);

	CAutoLock cAutoLockShared(&m_cSharedState);
	//isReceiveBG = true ;
	BG->setBackground(backgroundIplImg);
	cvReleaseImageHeader(&backgroundtmp);

	return S_OK;
}

CMuxTransformOutputPin* BGMappingFilter::GetConnectedOutputPin()
{
	for (int i =0; i< m_pOutputPins.size(); i++)
	{
		if (m_pOutputPins[i]->IsConnected())
		{
			return m_pOutputPins[i];
		}
	}
	return NULL;
}



HRESULT BGMappingFilter::Receive(IMediaSample *pSample, const IPin* pReceivePin)
{
	HRESULT hr = S_OK;
	if (m_pInputPins.size() >= 1 && pReceivePin == m_pInputPins[0])
	{
		CAutoLock lck(&m_csBGSetting);
		hr = ReceiveCameraImg(pSample, pReceivePin);

	}
	if (m_pInputPins.size() >= 2 && pReceivePin == m_pInputPins[1])
	{
		CAutoLock lck(&m_csBGSetting);
		hr = ReceiveBackground(pSample, pReceivePin);
	}
	return hr;

}
HRESULT BGMappingFilter::CreatePins()
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
			L"cameraImage");      // Pin name
		//  Can't fail
		ASSERT(SUCCEEDED(hr));
		if (pInput0 == NULL) {
			return NULL;
		}

		CMuxTransformInputPin* pInput1 = new CMuxTransformInputPin(NAME("CMuxTransform input pin"),
			this,              // Owner filter
			&hr,               // Result code
			L"layoutImage");      // Pin name
		//  Can't fail
		ASSERT(SUCCEEDED(hr));
		if (pInput1 == NULL) {
			delete pInput0;
			pInput0 = NULL;
			return NULL;
		}

		CMuxTransformOutputPin* pOutput = new CMuxTransformOutputPin(NAME("Transform output pin"),
			this,            // Owner filter
			&hr,             // Result code
			L"output");   // Pin name
		// Can't fail
		ASSERT(SUCCEEDED(hr));
		if (pOutput == NULL) {
			delete pInput0;
			pInput0 = NULL;
			delete pInput1;
			pInput1 = NULL;
			return NULL;
		}

		CMuxTransformOutputPin* pOutputFG = new CMuxTransformOutputPin(NAME("Transform output pin"),
			this,            // Owner filter
			&hr,             // Result code
			L"FGConfig");   // Pin name
		// Can't fail
		ASSERT(SUCCEEDED(hr));
		if (pOutputFG == NULL) {
			delete pInput0;
			pInput0 = NULL;
			delete pInput1;
			pInput1 = NULL;
			delete pOutput;
			return NULL;
		}
		
		m_pInputPins.push_back(pInput0);
		m_pInputPins.push_back(pInput1);
		m_pOutputPins.push_back(pOutput);
		m_pOutputPins.push_back(pOutputFG);
	
	}
	return S_OK;
}

HRESULT BGMappingFilter::CheckInputType( const CMediaType * pmt , const IPin* pPin)
{
	CheckPointer(pmt, E_POINTER);
	if (m_pInputPins.size() >= 1 && m_pInputPins[0] == pPin)
	{
		if (*pmt->FormatType() != FORMAT_VideoInfo) {
			return E_INVALIDARG;
		}
		if (IsEqualGUID(*pmt->Type(), MEDIATYPE_Video) && 
			(IsEqualGUID(MEDIASUBTYPE_RGB24, *pmt->Subtype()) || IsEqualGUID(MEDIASUBTYPE_RGB32, *pmt->Subtype())))
			return NOERROR;
	}
	else if (m_pInputPins.size() >= 2 && m_pInputPins[1] == pPin)
	{
		if (*pmt->FormatType() != FORMAT_VideoInfo) {
			return E_INVALIDARG;
		}
		if (IsEqualGUID(*pmt->Type(), MEDIATYPE_Video) && 
			(IsEqualGUID(MEDIASUBTYPE_RGB24, *pmt->Subtype())))
			return NOERROR;		
	}
	return E_FAIL;
}

bool BGMappingFilter::IsAcceptedType(const CMediaType *pmt){
	GUID guidSubType = *pmt->Subtype();

	if (IsEqualGUID(*pmt->Type(), MEDIATYPE_Video)) 
	{
		if(IsEqualGUID(guidSubType, MEDIASUBTYPE_RGB24))
		{
			return true;
		}
		else if(IsEqualGUID(guidSubType, MEDIASUBTYPE_RGB32))			
		{
			return true;
		}
	}
	return false;
}
HRESULT BGMappingFilter::CheckOutputType( const CMediaType * pmt , const IPin* pPin)
{
	if (m_pInputPins.size() ==  2 && m_pOutputPins.size() > 0 && m_pOutputPins[0] == pPin)
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
		if (!IsEqualGUID(*pmt->Type(), GUID_IMPRO_FeedbackTYPE) || !IsEqualGUID(*pmt->Subtype(), GUID_ForegroundRegion_Data))
		{
			return E_INVALIDARG;
		}
		return S_OK;
	}

	return E_FAIL;
}

HRESULT BGMappingFilter::CompleteConnect(PIN_DIRECTION direction, const IPin* pMyPin, const IPin* pOtherPin)
{
	HRESULT hr = S_OK;
	if (direction == PINDIR_INPUT && m_pInputPins.size() > 0 && m_pInputPins[0] == pMyPin)
	{
		CMediaType inputMT = ((CMuxTransformInputPin*)pMyPin)->CurrentMediaType();
		VIDEOINFOHEADER *pvi = (VIDEOINFOHEADER *) inputMT.pbFormat;
		BITMAPINFOHEADER bitHeader = pvi->bmiHeader;
		cameraW = bitHeader.biWidth;
		cameraH = bitHeader.biHeight;
        GUID guidSubType = inputMT.subtype;
		if (IsEqualGUID(guidSubType, MEDIASUBTYPE_RGB24))
		{
			camChannel = 3;
		}
		else if(IsEqualGUID(guidSubType, MEDIASUBTYPE_RGB32) || IsEqualGUID(guidSubType, MEDIASUBTYPE_ARGB32))
		{
			camChannel = 4;
		}

		cameraInputIplImg = cvCreateImage(cvSize(cameraW, cameraH), 8, camChannel);
		foregroundIplImg = cvCreateImage(cvSize(cameraW, cameraH), 8, camChannel);

		return S_OK;

	}

	else if (direction == PINDIR_INPUT && m_pInputPins.size() > 1 && m_pInputPins[1] == pMyPin)
	{
		CMediaType inputMT = ((CMuxTransformInputPin*)pMyPin)->CurrentMediaType();
		VIDEOINFOHEADER *pvi = (VIDEOINFOHEADER *) inputMT.pbFormat;
		BITMAPINFOHEADER bitHeader = pvi->bmiHeader;
		layoutW = bitHeader.biWidth;
		layoutH = bitHeader.biHeight;

		GUID guidSubType = inputMT.subtype;
		if (IsEqualGUID(guidSubType, MEDIASUBTYPE_RGB24))
		{
			layoutChannel = 3;
		}
		else if(IsEqualGUID(guidSubType, MEDIASUBTYPE_RGB32) || IsEqualGUID(guidSubType, MEDIASUBTYPE_ARGB32))
		{
			layoutChannel = 4;
		}
		backgroundIplImg = cvCreateImage(cvSize(cameraW, cameraH), 8, layoutChannel);

		// set the calibration data of homo and mapping table
		extern HMODULE GetModule();
		WCHAR str[MAX_PATH] = {0};
		HMODULE module = GetModule();
		GetModuleFileName(module, str, MAX_PATH);
		// Gets filename
		WCHAR* pszFile = wcsrchr(str, '\\');
		pszFile++;    // Moves on from \
		// Get path
		WCHAR szPath[MAX_PATH] = L"";
		_tcsncat(szPath, str, pszFile - str);

		char fileDir[100];
		int size= wcslen(szPath);
		char homoDir[100];
		char mTableDir[100];

		wcstombs(fileDir, szPath, size+1);
		sprintf(homoDir,"%s\\BackgroundCaliData\\HomoMat.txt",fileDir) ;
		sprintf(mTableDir,"%s\\BackgroundCaliData\\mTable.txt",fileDir) ;

		BG = new BackGroundMapping(cameraW,cameraH,camChannel,fileDir);
		BG->loadHomo(homoDir,mTableDir);

		return S_OK;
	}
	return S_OK;
}

HRESULT BGMappingFilter::BreakConnect(PIN_DIRECTION dir, const IPin* pPin)
{
	if (dir == PINDIR_OUTPUT)
	{
		for (int i =0; i< m_pOutputPins.size(); i++)
		{
			m_pOutputPins[i]->m_bVisible = true;
		}
	}
	return __super::BreakConnect(dir, pPin);
}

HRESULT BGMappingFilter::Transform( IMediaSample *pIn, IMediaSample *pOut)
{

	HRESULT hr = S_OK;
	long cbData;
	BYTE* cameraByteData;
	BYTE* foregroundByteData;
	// Access the sample's data buffer
	pIn->GetPointer(&cameraByteData);
	pOut->GetPointer(&foregroundByteData);
	cbData = pOut->GetSize();
    
	IplImage* camtmp = cvCreateImageHeader(cvSize(cameraW, cameraH), 8, camChannel);
	camtmp->imageData = (char*)cameraByteData;
	cvCopy(camtmp,cameraInputIplImg);
	cvReleaseImageHeader(&camtmp);	
	
	CAutoLock cAutoLockShared(&m_cSharedState);
	foregroundIplImg = BG->getForeground(cameraInputIplImg);
	memcpy (foregroundByteData, (BYTE*)foregroundIplImg->imageData,cbData);

	return S_OK;
}


HRESULT BGMappingFilter::DecideBufferSize(IMemAllocator *pAlloc, const IPin* pOutPin, ALLOCATOR_PROPERTIES *pProp)
{
	HRESULT hr = NOERROR;
	if (m_pInputPins.size() <= 0)
	{
		return S_FALSE;
	}
	CMediaType inputMT = m_pInputPins[0]->CurrentMediaType();
	if (inputMT.Type() == NULL)
	{
		return S_FALSE;
	}
	if (m_pInputPins.size() > 1 && m_pOutputPins.size() > 0 && m_pOutputPins[0] == pOutPin )
	{
		VIDEOINFOHEADER *pvi = (VIDEOINFOHEADER *) inputMT.pbFormat;
		BITMAPINFOHEADER bitHeader = pvi->bmiHeader;

		pProp->cBuffers = 1;
		pProp->cbBuffer = inputMT.GetSampleSize();//bitHeader.biWidth*bitHeader.biHeight;
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

HRESULT BGMappingFilter::GetMediaType(int iPosition, const IPin* pOutPin, __inout CMediaType *pMediaType)
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
		long size = inputMT.GetSampleSize();
		
		*pMediaType = inputMT;
		return S_OK;
	}
	if (m_pOutputPins.size() > 1 && m_pOutputPins[1] == pOutPin)
	{
		CMediaType mt;
		mt.SetType(&GUID_IMPRO_FeedbackTYPE);
		mt.SetSubtype(&GUID_ForegroundRegion_Data);
		mt.SetSampleSize(sizeof(ForegroundRegion));
		*pMediaType = mt;
		return S_OK;
	}
	return VFW_S_NO_MORE_ITEMS;
}

HRESULT BGMappingFilter::GetPages(CAUUID *pPages)
{
	pPages->cElems = 1;
	pPages->pElems = (GUID*)CoTaskMemAlloc(sizeof(GUID));
	if (pPages->pElems == NULL) 
	{
		return E_OUTOFMEMORY;
	}
	pPages->pElems[0] = CLSID_BGMappingPropertyPage;
	return S_OK;
}

int BGMappingFilter::getBGThreshold(){
	if(BG->BGthreshold == NULL)
		return 0 ;
	return BG->BGthreshold;
}

HRESULT BGMappingFilter::setBGThreshold(int BGthres){
	BG->BGthreshold = BGthres;
	return S_OK;
}

int BGMappingFilter::getBlackValue(){
	if(BG->BlackValue == NULL)
		return 0 ;
	return BG->BlackValue;
}

HRESULT BGMappingFilter::setBlackValue(int bValue){
	BG->BlackValue = bValue;
	return S_OK;
}


int BGMappingFilter::getWhiteValue(){
	if(BG->WhiteValue == NULL)
		return 0 ;
	return BG->WhiteValue;
}

HRESULT BGMappingFilter::setWhiteValue(int wValue){
	BG->WhiteValue = wValue;
	return S_OK;
}

HRESULT BGMappingFilter::SendForegroundRect(){
	if (m_pOutputPins.size() <= 1 || !m_pOutputPins[1]->IsConnected())
	{
		return S_FALSE;
	}
	HRESULT hr = S_OK;
	vector<CvRect>* fgList = BG->GetForegroundRect();
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
HRESULT BGMappingFilter::setCamFlip(bool value){
	BG->camFlip = value ;
	return S_OK;
}
bool BGMappingFilter:: getCamFlip(){
	return BG->camFlip;

}
HRESULT BGMappingFilter:: setLayoutFlip(bool value) {
	BG->layoutFlip = value ;
	return S_OK;
}
bool BGMappingFilter::getLayoutFlip(){
	return BG->layoutFlip;
}

HRESULT BGMappingFilter:: setOutputFlip(bool value) {
	BG->outputFlip = value ;
	return S_OK;
}
bool BGMappingFilter::getOutputFlip(){
	return BG->outputFlip;
}