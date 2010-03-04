#include "stdafx.h"
#include "SyncFilter.h"
#include "SyncFilterApp.h"
#include "MyMediaSample.h"
#include "MyARTagMediaSample.h"



SyncFilter::SyncFilter(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData)
: CMuxTransformFilter(NAME("Sync Filter"), 0, CLSID_SyncFilter)
{ 
	Dirty =false ;

}
SyncFilter::~SyncFilter()
{

}


CUnknown *WINAPI SyncFilter::CreateInstance(LPUNKNOWN punk, HRESULT *phr)
{
	ASSERT(phr);
	// assuming we don't want to modify the data
	SyncFilter *pNewObject = new SyncFilter(punk, phr, FALSE);

	if(pNewObject == NULL) {
		if (phr)
			*phr = E_OUTOFMEMORY;
	}
	return pNewObject;
}

HRESULT SyncFilter::NonDelegatingQueryInterface(REFIID iid, void **ppv)
{
	if (iid == IID_ISyncFilter) 
	{
		return GetInterface(static_cast<ISyncFilter*>(this), ppv);
	}
	else
	{
		// Call the parent class.
		return CBaseFilter::NonDelegatingQueryInterface(iid, ppv);
	}
}

HRESULT SyncFilter::ReceiveCameraImg(IMediaSample *pSample, const IPin* pReceivePin)
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

	hr = InitializeOutputSample(pSample, pReceivePin, GetConnectedOutputPin(0), &pOutSample);

	if (FAILED(hr)) {
		return hr;
	}

	// Start timing the transform (if PERF is defined)
	MSR_START(m_idTransform);

	hr = CamTransform(pSample, pOutSample);

	// Stop the clock and log it (if PERF is defined)
	MSR_STOP(m_idTransform);

	if (FAILED(hr)) {
		DbgLog((LOG_TRACE,1,TEXT("Error from transform")));
	} else {
		if (hr == NOERROR) {
			hr = GetConnectedOutputPin(0)->Deliver(pOutSample);// m_pInputPin->Receive(pOutSample);
			m_bSampleSkipped = FALSE;	// last thing no longer dropped
		} else {
		if (S_FALSE == hr) {
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

	pOutSample->Release();
	return S_OK;
}

HRESULT SyncFilter::ReceiveDirty(){
	setDirty(true);
    return S_OK;
}

HRESULT SyncFilter::ReceiveLayoutImg(IMediaSample *pSample, const IPin* pReceivePin)
{
	if (m_pOutputPins.size() < 2)
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
	hr = InitializeOutputSample(pSample, pReceivePin, GetConnectedOutputPin(1), &pOutSample);
	if (FAILED(hr)) {
		return hr;
	}
	MSR_START(m_idTransform);

	hr = LayoutTransform(pSample, pOutSample);

	MSR_STOP(m_idTransform);

	if (FAILED(hr)) {
		DbgLog((LOG_TRACE,1,TEXT("Error from transform")));
	} else {
		if (hr == NOERROR) {

			if(Dirty == true){
				hr = GetConnectedOutputPin(1)->Deliver(pOutSample);// Pin1 :: BG  only deliver in layout change
			}
			hr = GetConnectedOutputPin(2)->Deliver(pOutSample);// Pin2 :: Render every frame deliver
			m_bSampleSkipped = FALSE;	// last thing no longer dropped
		} else {
		
			if (S_FALSE == hr) {
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
	pOutSample->Release();
	setDirty(false);
	setBlock(false);

	return S_OK;
}



CMuxTransformOutputPin* SyncFilter::GetConnectedOutputPin(int i )
{
	
	if (m_pOutputPins[i]->IsConnected())
	{
		return m_pOutputPins[i];
	}
	
	return NULL;
}



HRESULT SyncFilter::Receive(IMediaSample *pSample, const IPin* pReceivePin)
{
	HRESULT hr = S_OK;
	if (m_pInputPins.size() >= 3 && pReceivePin == m_pInputPins[0] && !getBlock())
	{
		pSample->GetPointer(&CamData);
		OutputDebugStringW(L"@@@@ ReceiveCam ---->");
		hr = ReceiveCameraImg(pSample, pReceivePin);
		OutputDebugStringW(L"@@@@ ReceiveCam <----");
	}
	if (m_pInputPins.size() >= 3 && pReceivePin == m_pInputPins[1])
	{
		OutputDebugStringW(L"@@@@ ReceiveDirty ---->");
		hr = ReceiveDirty();
		OutputDebugStringW(L"@@@@ ReceiveDirty <----");

	}
	if (m_pInputPins.size() >= 3 && pReceivePin == m_pInputPins[2])
	{
		if(getDirty() == true){
			setBlock(true);
		}
		pSample->GetPointer(&LayoutData);	
		OutputDebugStringW(L"@@@@ ReceiveLayout ---->");
		hr = ReceiveLayoutImg(pSample, pReceivePin);
		OutputDebugStringW(L"@@@@ ReceiveLayout <----");
	}
	return hr;
}

HRESULT SyncFilter::CreatePins()
{
	HRESULT hr = S_OK;
	if (m_pInputPins.size() < 3 || m_pOutputPins.size() < 3) {
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

		CMuxTransformInputPin* pInput0 = new CMuxTransformInputPin(NAME("Camera input pin"),
			this,              // Owner filter
			&hr,               // Result code
			L"camInput");      // Pin name
		//  Can't fail
	
		CMuxTransformInputPin* pInput1 = new CMuxTransformInputPin(NAME("Dirty  pin"),
			this,              // Owner filter
			&hr,               // Result code
			L"Dirty");      // Pin name
		//  Can't fail
	
		CMuxTransformInputPin* pInput2 = new CMuxTransformInputPin(NAME("Layout input pin"),
			this,              // Owner filter
			&hr,               // Result code
			L"Layout");      // Pin name
		//  Can't fail

		CMuxTransformOutputPin* pOut0 = new CMuxTransformOutputPin(NAME("camera output pin"),
			this,            // Owner filter
			&hr,             // Result code
			L"CamOut");   // Pin name
		// Can't fail

		CMuxTransformOutputPin* pOut1 = new CMuxTransformOutputPin(NAME("BG output pin"),
			this,            // Owner filter
			&hr,             // Result code
			L"BG");   // Pin name
		// Can't fail

		CMuxTransformOutputPin* pOut2 = new CMuxTransformOutputPin(NAME("Render output pin"),
			this,            // Owner filter
			&hr,             // Result code
			L"Render");   // Pin name
		// Can't fail
		
		m_pInputPins.push_back(pInput0);
		m_pInputPins.push_back(pInput1);
		m_pInputPins.push_back(pInput2);

		m_pOutputPins.push_back(pOut0);
		m_pOutputPins.push_back(pOut1);
		m_pOutputPins.push_back(pOut2);

	}
	return S_OK;
}

HRESULT SyncFilter::CheckInputType( const CMediaType * pmt , const IPin* pPin)
{
	CheckPointer(pmt, E_POINTER);
	if (m_pInputPins.size() >= 1 && m_pInputPins[0] == pPin)   // camera image
	{
		if (*pmt->FormatType() != FORMAT_VideoInfo) {
			return E_INVALIDARG;
		}
		if (IsEqualGUID(*pmt->Type(), MEDIATYPE_Video) && 
			(IsEqualGUID(MEDIASUBTYPE_RGB24, *pmt->Subtype()) || IsEqualGUID(MEDIASUBTYPE_RGB32, *pmt->Subtype())))
			return NOERROR;
	}

	else if (m_pInputPins.size() >= 1 && m_pInputPins[1] == pPin)    // dirty Pin
	{
		if (IsEqualGUID(*pmt->Type(), GUID_MyMediaSample) && 
			(IsEqualGUID(GUID_ARLayoutConfigData, *pmt->Subtype()) ))
			return NOERROR;

	}

	if (m_pInputPins.size() >= 1 && m_pInputPins[2] == pPin)      // layout image
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

bool SyncFilter::IsAcceptedType(const CMediaType *pmt){
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
HRESULT SyncFilter::CheckOutputType( const CMediaType * pmt , const IPin* pPin)
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

	if (m_pOutputPins.size() > 0 && m_pOutputPins[1] == pPin)
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

	if (m_pOutputPins.size() > 0 && m_pOutputPins[2] == pPin)
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

	return E_FAIL;
}

HRESULT SyncFilter::CompleteConnect(PIN_DIRECTION direction, const IPin* pMyPin, const IPin* pOtherPin)
{
	HRESULT hr = S_OK;
	if (direction == PINDIR_INPUT && m_pInputPins.size() > 0 && m_pInputPins[0] == pMyPin)
	{
		CMediaType inputMT = ((CMuxTransformInputPin*)pMyPin)->CurrentMediaType();
		VIDEOINFOHEADER *pvi = (VIDEOINFOHEADER *) inputMT.pbFormat;
		BITMAPINFOHEADER bitHeader = pvi->bmiHeader;
		GUID guidSubType = inputMT.subtype;
		return S_OK;

	}

	else if (direction == PINDIR_INPUT && m_pInputPins.size() > 1 && m_pInputPins[2] == pMyPin)
	{
		CMediaType inputMT = ((CMuxTransformInputPin*)pMyPin)->CurrentMediaType();
		VIDEOINFOHEADER *pvi = (VIDEOINFOHEADER *) inputMT.pbFormat;
		BITMAPINFOHEADER bitHeader = pvi->bmiHeader;
		return S_OK;
	}
	return S_OK;
}

HRESULT SyncFilter::BreakConnect(PIN_DIRECTION dir, const IPin* pPin)
{
	return __super::BreakConnect(dir, pPin);
}

HRESULT SyncFilter::CamTransform( IMediaSample *pIn, IMediaSample *pOut)
{
	HRESULT hr = S_OK;
	long cbData;
	BYTE* outByte;
	// Access the sample's data buffer
	pIn->GetPointer(&CamData);
	pOut->GetPointer(&outByte);
	cbData = pOut->GetSize();
	memcpy (outByte,CamData,cbData);
	return S_OK;
}

HRESULT SyncFilter::LayoutTransform( IMediaSample *pIn, IMediaSample *pOut)
{
	HRESULT hr = S_OK;
	long cbData;
	BYTE* outByte;
	// Access the sample's data buffer
	pIn->GetPointer(&LayoutData);
	pOut->GetPointer(&outByte);
	cbData = pOut->GetSize();
	memcpy (outByte,LayoutData,cbData);
	return S_OK;
}


HRESULT SyncFilter::DecideBufferSize(IMemAllocator *pAlloc, const IPin* pOutPin, ALLOCATOR_PROPERTIES *pProp)
{
	HRESULT hr = NOERROR;
	if (m_pInputPins.size() <= 2)
	{
		return S_FALSE;
	}
	CMediaType inputPin1MT = m_pInputPins[0]->CurrentMediaType();
	CMediaType inputPin2MT = m_pInputPins[2]->CurrentMediaType();

	if (inputPin1MT.Type() == NULL || inputPin2MT.Type() == NULL)
	{
		return S_FALSE;
	}
	if (m_pOutputPins.size() > 0 && m_pOutputPins[0] == pOutPin )
	{
		VIDEOINFOHEADER *pvi = (VIDEOINFOHEADER *) inputPin1MT.pbFormat;
		BITMAPINFOHEADER bitHeader = pvi->bmiHeader;

		pProp->cBuffers = 1;
		pProp->cbBuffer = inputPin1MT.GetSampleSize();//bitHeader.biWidth*bitHeader.biHeight;

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

	if (m_pOutputPins.size() > 0 && m_pOutputPins[1] == pOutPin )
	{
		VIDEOINFOHEADER *pvi = (VIDEOINFOHEADER *) inputPin2MT.pbFormat;
		BITMAPINFOHEADER bitHeader = pvi->bmiHeader;

		pProp->cBuffers = 1;
		pProp->cbBuffer = inputPin2MT.GetSampleSize();

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

	if (m_pOutputPins.size() > 0 && m_pOutputPins[2] == pOutPin )
	{
		VIDEOINFOHEADER *pvi = (VIDEOINFOHEADER *) inputPin2MT.pbFormat;
		BITMAPINFOHEADER bitHeader = pvi->bmiHeader;

		pProp->cBuffers = 1;
		pProp->cbBuffer = inputPin2MT.GetSampleSize();//bitHeader.biWidth*bitHeader.biHeight;

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

HRESULT SyncFilter::GetMediaType(int iPosition, const IPin* pOutPin, __inout CMediaType *pMediaType)
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
	else if (m_pOutputPins.size() > 1 && m_pOutputPins[2] != NULL && m_pOutputPins[1] == pOutPin)
	{
		CMediaType inputMT = m_pInputPins[2]->CurrentMediaType(); 
		long size = inputMT.GetSampleSize();

		*pMediaType = inputMT;
		return S_OK;
	}
	else if (m_pOutputPins.size() > 2 && m_pOutputPins[2] != NULL && m_pOutputPins[2] == pOutPin)
	{
		CMediaType inputMT = m_pInputPins[2]->CurrentMediaType(); 
		long size = inputMT.GetSampleSize();

		*pMediaType = inputMT;
		return S_OK;
	}
	return VFW_S_NO_MORE_ITEMS;
}

bool SyncFilter::getDirty(){
	CAutoLock lck(&locDirty);
	return Dirty;
}

HRESULT SyncFilter::setDirty(bool isDirty){
	CAutoLock lck(&locDirty);
	Dirty = isDirty;
	return S_OK;
}

bool SyncFilter::getBlock(){
	CAutoLock lck(&locBlock);
	return Block;
}

HRESULT SyncFilter::setBlock(bool isBlock){
	CAutoLock lck(&locBlock);
	Block = isBlock;
	return S_OK;
}