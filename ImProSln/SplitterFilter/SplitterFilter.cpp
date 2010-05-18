#include "stdafx.h"
#include "SplitterFilter.h"
#include "SplitterFilterApp.h"


SplitterFilter::SplitterFilter(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData)
: CMuxTransformFilter(NAME("Splitter Filter"), 0, CLSID_SplitterFilter)
{ 
	getData = false ;
	isSaveImg = 0 ;
	saveCount = 0 ;
	imgH = 480; 
	imgW = 640;
	imgChannel = 3 ;

	
}
SplitterFilter::~SplitterFilter()
{
	
}


CUnknown *WINAPI SplitterFilter::CreateInstance(LPUNKNOWN punk, HRESULT *phr)
{
	ASSERT(phr);
	// assuming we don't want to modify the data
	SplitterFilter *pNewObject = new SplitterFilter(punk, phr, FALSE);

	if(pNewObject == NULL) {
		if (phr)
			*phr = E_OUTOFMEMORY;
	}
	return pNewObject;
}

HRESULT SplitterFilter::NonDelegatingQueryInterface(REFIID iid, void **ppv)
{
	if (iid == IID_ISplitterFilter) 
	{
		return GetInterface(static_cast<ISplitterFilter*>(this), ppv);
	}
	else
	{
		// Call the parent class.
		return CBaseFilter::NonDelegatingQueryInterface(iid, ppv);
	}
}


HRESULT SplitterFilter::ReceiveCameraImg(IMediaSample *pSample, const IPin* pReceivePin)
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

	hr = InitializeOutputSample(pSample, pReceivePin, GetConnectedOutputPin(), &pOutSample);

	if (FAILED(hr)) {
		return hr;
	}

	// Start timing the transform (if PERF is defined)
	MSR_START(m_idTransform);

	hr = Transform(pSample, pOutSample);

	// Stop the clock and log it (if PERF is defined)
	MSR_STOP(m_idTransform);

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



CMuxTransformOutputPin* SplitterFilter::GetConnectedOutputPin()
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



HRESULT SplitterFilter::Receive(IMediaSample *pSample, const IPin* pReceivePin)
{
	HRESULT hr;
	if (m_pInputPins.size() >= 1 && pReceivePin == m_pInputPins[0])
	{
		getData = true ;
		pSample->GetPointer(&InData);	
		long cbData = pSample->GetSize();
		return ReceiveCameraImg(pSample, pReceivePin);
	}
	return S_OK;


}
HRESULT SplitterFilter::CreatePins()
{
	HRESULT hr = S_OK;
	if (m_pInputPins.size() < 1 || m_pOutputPins.size() < 1) {
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
		ASSERT(SUCCEEDED(hr));
		if (pInput0 == NULL) {
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
			return NULL;
		}

		CMuxTransformStream* pOutputStream = new CMuxTransformStream(NAME("Transform output pin"),
			&hr,             // Result code
			this,            // Owner filter
			L"outputStream");   // Pin name
		// Can't fail
		ASSERT(SUCCEEDED(hr));
		if (pOutputStream == NULL) {
			delete pInput0;
			pInput0 = NULL;
			delete pOutput;
			pOutput = NULL;
			return NULL;
		}

		m_pInputPins.push_back(pInput0);
		m_pOutputPins.push_back(pOutput);
		m_pStreamPins.push_back(pOutputStream);

	}
	return S_OK;
}

HRESULT SplitterFilter::CheckInputType( const CMediaType * pmt , const IPin* pPin)
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
	
	return E_FAIL;
}

HRESULT SplitterFilter::FillBuffer(IMediaSample *pSamp, IPin* pPin)
{

	if (m_pStreamPins.size() > 0 && getData == true && m_pStreamPins[0] == pPin)
	{
		CMediaType mt;
		mt = ((CMuxTransformStream*)pPin)->CurrentMediaType();
		BYTE* pOutData = NULL;
		pSamp->GetPointer(&pOutData);
		long size = pSamp->GetSize();
		memcpy(pOutData,InData,size);
		getData = false ;	
	}
	return S_OK;
}

bool SplitterFilter::IsAcceptedType(const CMediaType *pmt){
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
HRESULT SplitterFilter::CheckOutputType( const CMediaType * pmt , const IPin* pPin)
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

	if (m_pStreamPins.size() > 0 && m_pStreamPins[0] == pPin)
	{
		CheckPointer(pmt, E_POINTER);
		if(IsAcceptedType(pmt)){
			return NOERROR;
		}		
	}
	return E_FAIL;
}

HRESULT SplitterFilter::CompleteConnect(PIN_DIRECTION direction, const IPin* pMyPin, const IPin* pOtherPin)
{
	HRESULT hr = S_OK;
	if (direction == PINDIR_INPUT && m_pInputPins.size() > 0 && m_pInputPins[0] == pMyPin)
	{
		CMediaType inputMT = ((CMuxTransformInputPin*)pMyPin)->CurrentMediaType();
		VIDEOINFOHEADER *pvi = (VIDEOINFOHEADER *) inputMT.pbFormat;
		BITMAPINFOHEADER bitHeader = pvi->bmiHeader;
		imgH = bitHeader.biHeight;
		imgW = bitHeader.biWidth;

		GUID guidSubType = inputMT.subtype;
		if (IsEqualGUID(guidSubType, MEDIASUBTYPE_RGB24))
		{
			imgChannel = 3 ;
		}
		else if(IsEqualGUID(guidSubType, MEDIASUBTYPE_RGB32) || IsEqualGUID(guidSubType, MEDIASUBTYPE_ARGB32))
		{
			imgChannel = 4 ;
		}
		return S_OK;

	}

	else if (direction == PINDIR_INPUT && m_pInputPins.size() > 1 && m_pInputPins[1] == pMyPin)
	{
		CMediaType inputMT = ((CMuxTransformInputPin*)pMyPin)->CurrentMediaType();
		VIDEOINFOHEADER *pvi = (VIDEOINFOHEADER *) inputMT.pbFormat;
		BITMAPINFOHEADER bitHeader = pvi->bmiHeader;
		return S_OK;
	}
	return S_OK;
}

HRESULT SplitterFilter::BreakConnect(PIN_DIRECTION dir, const IPin* pPin)
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

HRESULT SplitterFilter::Transform( IMediaSample *pIn, IMediaSample *pOut)
{
	HRESULT hr = S_OK;
	long cbData;
	BYTE* outByte;
	// Access the sample's data buffer
	pIn->GetPointer(&InData);
	pOut->GetPointer(&outByte);
	cbData = pOut->GetSize();

	// for save img 
	isSaveImg ++ ;
	if(isSaveImg % 1000 == 0){
		IplImage* savetmp = cvCreateImageHeader(cvSize(imgW, imgH), 8, imgChannel);
		savetmp->imageData = (char*)InData;
		char saveName[MAX_PATH] ;
		sprintf(saveName,"saveImg\\cam_%d.jpg",saveCount);
		cvSaveImage(saveName,savetmp);
		cvReleaseImageHeader(&savetmp);	
		isSaveImg = 0 ;
	}
	memcpy (outByte,InData,cbData);
	return S_OK;
}


HRESULT SplitterFilter::DecideBufferSize(IMemAllocator *pAlloc, const IPin* pOutPin, ALLOCATOR_PROPERTIES *pProp)
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
	if (m_pOutputPins.size() > 0 && m_pOutputPins[0] == pOutPin )
	{
		VIDEOINFOHEADER *pvi = (VIDEOINFOHEADER *) inputMT.pbFormat;
		BITMAPINFOHEADER bitHeader = pvi->bmiHeader;

		pProp->cBuffers = 1;
		pProp->cbBuffer = inputMT.GetSampleSize();//bitHeader.biWidth*bitHeader.biHeight;

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

	if (m_pOutputPins.size()>0 &&m_pStreamPins.size() > 0 && m_pStreamPins[0] == pOutPin )
	{
		VIDEOINFOHEADER *pvi = (VIDEOINFOHEADER *) inputMT.pbFormat;
		BITMAPINFOHEADER bitHeader = pvi->bmiHeader;

		pProp->cBuffers = 1;
		pProp->cbBuffer = inputMT.GetSampleSize();//bitHeader.biWidth*bitHeader.biHeight;

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

HRESULT SplitterFilter::GetMediaType(int iPosition, const IPin* pOutPin, __inout CMediaType *pMediaType)
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
	else if (m_pStreamPins.size() > 0 && m_pStreamPins[0] == pOutPin)
	{
		CMediaType inputMT = m_pInputPins[0]->CurrentMediaType(); 
		long size = inputMT.GetSampleSize();

		*pMediaType = inputMT;
		return S_OK;
	}
	return VFW_S_NO_MORE_ITEMS;
}
//
//HRESULT SplitterFilter::GetPages(CAUUID *pPages)
//{
//	pPages->cElems = 1;
//	pPages->pElems = (GUID*)CoTaskMemAlloc(sizeof(GUID));
//	if (pPages->pElems == NULL) 
//	{
//		return E_OUTOFMEMORY;
//	}
////	pPages->pElems[0] = CLSID_BGMappingPropertyPage;
//	return S_OK;
//}
//
