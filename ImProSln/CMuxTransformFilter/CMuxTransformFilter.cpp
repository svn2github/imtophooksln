#include "CMuxTransformFilter.h"


CMuxTransformFilter::CMuxTransformFilter(__in_opt LPCTSTR pName, __inout_opt LPUNKNOWN pUnk, REFCLSID  clsid) :
CBaseFilter(pName, pUnk, &m_csFilter, clsid), m_bEOSDelivered(FALSE), m_bQualityChanged(FALSE), 
m_bSampleSkipped(FALSE)
{
	
}
#ifdef UNICODE
CMuxTransformFilter::CMuxTransformFilter(__in_opt LPCSTR pName,
								   __inout_opt LPUNKNOWN pUnk,
								   REFCLSID  clsid) :
CBaseFilter(pName,pUnk,&m_csFilter, clsid), m_bEOSDelivered(FALSE), m_bQualityChanged(FALSE),
m_bSampleSkipped(FALSE)
{
#ifdef PERF
	RegisterPerfId();
#endif //  PERF
}
#endif

CMuxTransformFilter::~CMuxTransformFilter()
{
	for (int i =0; i < m_pInputPins.size(); i++)
	{
		m_pInputPins.at(i)->Release();
		m_pInputPins.at(i) = NULL;
	}
	m_pOutputPins.clear();
	for (int i =0; i < m_pOutputPins.size(); i++)
	{
		m_pOutputPins[i]->Release();
		m_pOutputPins[i] = NULL;
	}
	m_pOutputPins.clear();
}

int CMuxTransformFilter::GetPinCount()
{
	return m_pInputPins.size() + m_pOutputPins.size();
}
CBasePin* CMuxTransformFilter::GetPin(int n)
{
	HRESULT hr = CreatePins();
	if (FAILED(hr))
	{
		return NULL;
	}
	if (n < m_pInputPins.size())
	{
		return m_pInputPins[n];
	}
	else if ( n < GetPinCount())
	{
		return m_pOutputPins[GetPinCount() - n - 1];
	}
	else
	{
		return NULL;
	}
}
HRESULT CMuxTransformFilter::FindPin(LPCWSTR Id, __deref_out IPin **ppPin)
{
	CheckPointer(ppPin,E_POINTER);
	ValidateReadWritePtr(ppPin,sizeof(IPin *));
	if (wcsstr(Id, L"In") != NULL)
	{
		int idx = -1;
		swscanf(Id, L"In %d", &idx);
		if (idx >= 0 && idx < m_pInputPins.size())
		{
			*ppPin = m_pInputPins[idx];
		}
	}
	else if (wcsstr(Id, L"Out") != NULL)
	{
		int idx = -1;
		swscanf(Id, L"In %d", &idx);
		if (idx >= 0 && idx < m_pOutputPins.size())
		{
			*ppPin = m_pOutputPins[idx];
		}
	}
	else
	{
		*ppPin = NULL;
		return VFW_E_NOT_FOUND;
	}

	HRESULT hr = NOERROR;
	//  AddRef() returned pointer - but GetPin could fail if memory is low.
	if (*ppPin) {
		(*ppPin)->AddRef();
	} else {
		hr = E_OUTOFMEMORY;  // probably.  There's no pin anyway.
	}
	return hr;
}

// override state changes to allow derived transform filter
// to control streaming start/stop
BOOL CMuxTransformFilter::IsAnyInputPinConnect()
{
	for (int i =0; i< m_pInputPins.size(); i++)
	{
		if (m_pInputPins[i]->IsConnected())
		{
			return TRUE;
		}
	}
	return FALSE;
}
BOOL CMuxTransformFilter::IsAnyOutPinConnect()
{
	for (int i =0; i< m_pOutputPins.size(); i++)
	{
		if (m_pOutputPins[i]->IsConnected())
		{
			return TRUE;
		}
	}
	return FALSE;
}
HRESULT CMuxTransformFilter::Stop()
{
	CAutoLock lck1(&m_csFilter);
	if (m_State == State_Stopped) {
		return NOERROR;
	}

	// Succeed the Stop if we are not completely connected
	ASSERT(m_pInputPins.size() == 0 || m_pOutputPins.size() != 0);
	if ( IsAnyInputPinConnect() == FALSE || IsAnyOutPinConnect() == FALSE) {
			m_State = State_Stopped;
			m_bEOSDelivered = FALSE;
			return NOERROR;
	}

	ASSERT(m_pInputPins.size());
	ASSERT(m_pOutputPins.size());

	// decommit the input pin before locking or we can deadlock
	for (int i = 0; i < m_pInputPins.size(); i++)
	{
		m_pInputPins[i]->Inactive();
	}
	// synchronize with Receive calls

	CAutoLock lck2(&m_csReceive);
	for (int i = 0 ; i < m_pOutputPins.size(); i++)
	{
		m_pOutputPins[i]->Inactive();
	}

	// allow a class derived from CTransformFilter
	// to know about starting and stopping streaming
	HRESULT hr = StopStreaming();
	if (SUCCEEDED(hr)) {
		// complete the state transition
		m_State = State_Stopped;
		m_bEOSDelivered = FALSE;
	}
	return hr;
}


HRESULT CMuxTransformFilter::Pause()
{
	CAutoLock lck(&m_csFilter);
	HRESULT hr = NOERROR;

	if (m_State == State_Paused) {
		// (This space left deliberately blank)
	}

	// If we have no input pin or it isn't yet connected then when we are
	// asked to pause we deliver an end of stream to the downstream filter.
	// This makes sure that it doesn't sit there forever waiting for
	// samples which we cannot ever deliver without an input connection.

	else if (IsAnyInputPinConnect() == FALSE) {
		if (m_pOutputPins.size() && m_bEOSDelivered == FALSE) {
			for (int i =0; i < m_pOutputPins.size(); i++)
			{
				m_pOutputPins[i]->DeliverEndOfStream();
			}
			m_bEOSDelivered = TRUE;
		}
		m_State = State_Paused;
	}

	// We may have an input connection but no output connection
	// However, if we have an input pin we do have an output pin

	else if (IsAnyOutPinConnect() == FALSE) {
		m_State = State_Paused;
	}

	else {
		if (m_State == State_Stopped) {
			// allow a class derived from CTransformFilter
			// to know about starting and stopping streaming
			CAutoLock lck2(&m_csReceive);
			hr = StartStreaming();
		}
		if (SUCCEEDED(hr)) {
			hr = CBaseFilter::Pause();
		}
	}

	m_bSampleSkipped = FALSE;
	m_bQualityChanged = FALSE;
	return hr;
}


HRESULT CMuxTransformFilter::StartStreaming()
{
	return NOERROR;
}


HRESULT CMuxTransformFilter::StopStreaming()
{
	return NOERROR;
}

HRESULT CMuxTransformFilter::AlterQuality(Quality q)
{
	UNREFERENCED_PARAMETER(q);
	return S_FALSE;
}
HRESULT CMuxTransformFilter::EndOfStream(void)
{
	HRESULT hr = NOERROR;
	for (int i =0 ; i < m_pOutputPins.size(); i++ )
	{
		hr = m_pOutputPins[i]->DeliverEndOfStream();
		if (FAILED(hr))
		{
			return hr;
		}
	}
	return hr;
}
HRESULT CMuxTransformFilter::BeginFlush(void)
{
	HRESULT hr = NOERROR;
	for (int i =0; i< m_pOutputPins.size(); i++)
	{
		// block receives -- done by caller (CBaseInputPin::BeginFlush)

		// discard queued data -- we have no queued data

		// free anyone blocked on receive - not possible in this filter

		// call downstream
		hr = m_pOutputPins[i]->DeliverBeginFlush();
	}
	return hr;
}

HRESULT CMuxTransformFilter::EndFlush(void)
{
	// sync with pushing thread -- we have no worker thread

	// ensure no more data to go downstream -- we have no queued data

	// call EndFlush on downstream pins
	ASSERT (m_pOutputPins.size() != 0);
	for (int i = 0 ; i < m_pOutputPins.size(); i++)
	{
		return m_pOutputPins[i]->DeliverEndFlush();
	}
	// caller (the input pin's method) will unblock Receives
}

HRESULT CMuxTransformFilter::NewSegment(
							 REFERENCE_TIME tStart,
							 REFERENCE_TIME tStop,
							 double dRate)
{
	for (int i = 0; i < m_pOutputPins.size(); i++)
	{
		m_pOutputPins[i]->DeliverNewSegment(tStart, tStop, dRate);
	}
	return S_OK;
}


HRESULT CMuxTransformFilter::SetMediaType(PIN_DIRECTION direction,IPin* pPin, const CMediaType *pmt)
{
	UNREFERENCED_PARAMETER(direction);
	UNREFERENCED_PARAMETER(pmt);
	UNREFERENCED_PARAMETER(pPin);
	return NOERROR;
}


HRESULT CMuxTransformFilter::CheckConnect(PIN_DIRECTION dir, IPin* pMyPin, IPin *pOtherPin)
{
	UNREFERENCED_PARAMETER(dir);
	UNREFERENCED_PARAMETER(pOtherPin);
	UNREFERENCED_PARAMETER(pMyPin);
	return NOERROR;
}


HRESULT CMuxTransformFilter::BreakConnect(PIN_DIRECTION dir, IPin* pPin)
{
	UNREFERENCED_PARAMETER(dir);
	UNREFERENCED_PARAMETER(pPin);
	return NOERROR;
}


// Let derived classes know about connection completion

HRESULT CMuxTransformFilter::CompleteConnect(PIN_DIRECTION dir, IPin* pMyPin, IPin *pOtherPin)
{
	UNREFERENCED_PARAMETER(dir);
	UNREFERENCED_PARAMETER(pMyPin);
	UNREFERENCED_PARAMETER(pOtherPin);
	return NOERROR;
}


// Set up our output sample
HRESULT CMuxTransformFilter::InitializeOutputSample(IMediaSample *pSample, IPin* pInputPin, IPin* pOutputPin, __deref_out IMediaSample **ppOutSample )
{
	IMediaSample *pOutSample;
	CMuxTransformInputPin* pInPin = (CMuxTransformInputPin*) pInputPin;
	CMuxTransformOutputPin* pOutPin = (CMuxTransformOutputPin*) pOutPin;
	// default - times are the same

	AM_SAMPLE2_PROPERTIES * const pProps = pInPin->SampleProps();
	DWORD dwFlags = m_bSampleSkipped ? AM_GBF_PREVFRAMESKIPPED : 0;

	// This will prevent the image renderer from switching us to DirectDraw
	// when we can't do it without skipping frames because we're not on a
	// keyframe.  If it really has to switch us, it still will, but then we
	// will have to wait for the next keyframe
	if (!(pProps->dwSampleFlags & AM_SAMPLE_SPLICEPOINT)) {
		dwFlags |= AM_GBF_NOTASYNCPOINT;
	}

	ASSERT(pOutPin->m_pAllocator != NULL);
	HRESULT hr = pOutPin->m_pAllocator->GetBuffer(
		&pOutSample
		, pProps->dwSampleFlags & AM_SAMPLE_TIMEVALID ?
		&pProps->tStart : NULL
		, pProps->dwSampleFlags & AM_SAMPLE_STOPVALID ?
		&pProps->tStop : NULL
		, dwFlags
		);
	*ppOutSample = pOutSample;
	if (FAILED(hr)) {
		return hr;
	}

	ASSERT(pOutSample);
	IMediaSample2 *pOutSample2;
	if (SUCCEEDED(pOutSample->QueryInterface(IID_IMediaSample2,
		(void **)&pOutSample2))) {
			/*  Modify it */
			AM_SAMPLE2_PROPERTIES OutProps;
			EXECUTE_ASSERT(SUCCEEDED(pOutSample2->GetProperties(
				FIELD_OFFSET(AM_SAMPLE2_PROPERTIES, tStart), (PBYTE)&OutProps)
				));
			OutProps.dwTypeSpecificFlags = pProps->dwTypeSpecificFlags;
			OutProps.dwSampleFlags =
				(OutProps.dwSampleFlags & AM_SAMPLE_TYPECHANGED) |
				(pProps->dwSampleFlags & ~AM_SAMPLE_TYPECHANGED);
			OutProps.tStart = pProps->tStart;
			OutProps.tStop  = pProps->tStop;
			OutProps.cbData = FIELD_OFFSET(AM_SAMPLE2_PROPERTIES, dwStreamId);
			hr = pOutSample2->SetProperties(
				FIELD_OFFSET(AM_SAMPLE2_PROPERTIES, dwStreamId),
				(PBYTE)&OutProps
				);
			if (pProps->dwSampleFlags & AM_SAMPLE_DATADISCONTINUITY) {
				m_bSampleSkipped = FALSE;
			}
			pOutSample2->Release();
	} else {
		if (pProps->dwSampleFlags & AM_SAMPLE_TIMEVALID) {
			pOutSample->SetTime(&pProps->tStart,
				&pProps->tStop);
		}
		if (pProps->dwSampleFlags & AM_SAMPLE_SPLICEPOINT) {
			pOutSample->SetSyncPoint(TRUE);
		}
		if (pProps->dwSampleFlags & AM_SAMPLE_DATADISCONTINUITY) {
			pOutSample->SetDiscontinuity(TRUE);
			m_bSampleSkipped = FALSE;
		}
		// Copy the media times

		LONGLONG MediaStart, MediaEnd;
		if (pSample->GetMediaTime(&MediaStart,&MediaEnd) == NOERROR) {
			pOutSample->SetMediaTime(&MediaStart,&MediaEnd);
		}
	}
	return S_OK;
}


CMuxTransformInputPin::CMuxTransformInputPin(
									   __in_opt LPCTSTR pObjectName,
									   __inout CMuxTransformFilter *pTransformFilter,
									   __inout HRESULT * phr,
									   __in_opt LPCWSTR pName)
									   : CBaseInputPin(pObjectName, pTransformFilter, &pTransformFilter->m_csFilter, phr, pName)
{
	DbgLog((LOG_TRACE,2,TEXT("CMuxTransformInputPin::CMuxTransformInputPin")));
	AMGetWideString(pName, &m_pName);
	m_pTransformFilter = pTransformFilter;
}


#ifdef UNICODE
CMuxTransformInputPin::CMuxTransformInputPin(
									   __in_opt LPCSTR pObjectName,
									   __inout CMuxTransformFilter *pTransformFilter,
									   __inout HRESULT * phr,
									   __in_opt LPCWSTR pName)
									   : CBaseInputPin(pObjectName, pTransformFilter, &pTransformFilter->m_csFilter, phr, pName)
{
	DbgLog((LOG_TRACE,2,TEXT("CTransformInputPin::CTransformInputPin")));
	AMGetWideString(pName, &m_pName);
	m_pTransformFilter = pTransformFilter;
}
#endif


HRESULT
CMuxTransformInputPin::CheckConnect(IPin *pPin)
{
	HRESULT hr = m_pTransformFilter->CheckConnect(PINDIR_INPUT, this, pPin);
	if (FAILED(hr)) {
		return hr;
	}
	return CBaseInputPin::CheckConnect(pPin);
}


// provides derived filter a chance to release it's extra interfaces

HRESULT
CMuxTransformInputPin::BreakConnect()
{
	//  Can't disconnect unless stopped
	ASSERT(IsStopped());
	m_pTransformFilter->BreakConnect(PINDIR_INPUT, this);
	return CBaseInputPin::BreakConnect();
}


// Let derived class know when the input pin is connected

HRESULT
CMuxTransformInputPin::CompleteConnect(IPin *pReceivePin)
{
	HRESULT hr = m_pTransformFilter->CompleteConnect(PINDIR_INPUT, this, pReceivePin);
	if (FAILED(hr)) {
		return hr;
	}
	return CBaseInputPin::CompleteConnect(pReceivePin);
}


// check that we can support a given media type

HRESULT
CMuxTransformInputPin::CheckMediaType(const CMediaType* pmt)
{
	// Check the input type

	HRESULT hr = m_pTransformFilter->CheckInputType(pmt, this);
	return hr;
}


// set the media type for this connection

HRESULT
CMuxTransformInputPin::SetMediaType(const CMediaType* mtIn)
{
	// Set the base class media type (should always succeed)
	HRESULT hr = CBasePin::SetMediaType(mtIn);
	if (FAILED(hr)) {
		return hr;
	}

	// check the transform can be done (should always succeed)
	ASSERT(SUCCEEDED(m_pTransformFilter->CheckInputType(mtIn, this)));

	return m_pTransformFilter->SetMediaType(PINDIR_INPUT, this, mtIn);
}

HRESULT CMuxTransformInputPin::CheckStreaming()
{
	ASSERT(m_pTransformFilter->m_pOutputPins.size() != 0);
	if (!m_pTransformFilter->IsAnyOutPinConnect()) {
		return VFW_E_NOT_CONNECTED;
	} else {
		//  Shouldn't be able to get any data if we're not connected!
		ASSERT(IsConnected());

		//  we're flushing
		if (m_bFlushing) {
			return S_FALSE;
		}
		//  Don't process stuff in Stopped state
		if (IsStopped()) {
			return VFW_E_WRONG_STATE;
		}
		if (m_bRunTimeError) {
			return VFW_E_RUNTIME_ERROR;
		}
		return S_OK;
	}
}

// =================================================================
// Implements IMemInputPin interface
// =================================================================


// provide EndOfStream that passes straight downstream
// (there is no queued data)
STDMETHODIMP
CMuxTransformInputPin::EndOfStream(void)
{
	CAutoLock lck(&m_pTransformFilter->m_csReceive);
	HRESULT hr = CheckStreaming();
	if (S_OK == hr) {
		hr = m_pTransformFilter->EndOfStream();
	}
	return hr;
}

// enter flushing state. Call default handler to block Receives, then
// pass to overridable method in filter
STDMETHODIMP
CMuxTransformInputPin::BeginFlush(void)
{
	CAutoLock lck(&m_pTransformFilter->m_csFilter);
	//  Are we actually doing anything?
	ASSERT(m_pTransformFilter->m_pOutputPins.size() != 0);
	if (!IsConnected() ||
		!m_pTransformFilter->IsAnyOutPinConnect()) {
			return VFW_E_NOT_CONNECTED;
	}
	HRESULT hr = CBaseInputPin::BeginFlush();
	if (FAILED(hr)) {
		return hr;
	}
	return m_pTransformFilter->BeginFlush();
}


// leave flushing state.
// Pass to overridable method in filter, then call base class
// to unblock receives (finally)
STDMETHODIMP
CMuxTransformInputPin::EndFlush(void)
{
	CAutoLock lck(&m_pTransformFilter->m_csFilter);
	//  Are we actually doing anything?
	ASSERT(m_pTransformFilter->m_pOutputPins.size() != 0);
	if (!IsConnected() ||
		!m_pTransformFilter->IsAnyOutPinConnect()) {
			return VFW_E_NOT_CONNECTED;
	}

	HRESULT hr = m_pTransformFilter->EndFlush();
	if (FAILED(hr)) {
		return hr;
	}
	return CBaseInputPin::EndFlush();
}


// here's the next block of data from the stream.
// AddRef it yourself if you need to hold it beyond the end
// of this call.

HRESULT
CMuxTransformInputPin::Receive(IMediaSample * pSample)
{
	HRESULT hr;
	CAutoLock lck(&m_pTransformFilter->m_csReceive);
	ASSERT(pSample);

	// check all is well with the base class
	hr = CBaseInputPin::Receive(pSample);
	if (S_OK == hr) {
		hr = m_pTransformFilter->Receive(pSample, this);
	}
	return hr;
}

// override to pass downstream
STDMETHODIMP 
CMuxTransformInputPin::NewSegment(
							   REFERENCE_TIME tStart,
							   REFERENCE_TIME tStop,
							   double dRate)
{
	//  Save the values in the pin
	CBasePin::NewSegment(tStart, tStop, dRate);
	return m_pTransformFilter->NewSegment(tStart, tStop, dRate);
}


CMuxTransformOutputPin::CMuxTransformOutputPin(
	__in_opt LPCTSTR pObjectName,
	__inout CMuxTransformFilter *pTransformFilter,
	__inout HRESULT * phr,
	__in_opt LPCWSTR pPinName)
	: CBaseOutputPin(pObjectName, pTransformFilter, &pTransformFilter->m_csFilter, phr, pPinName),
	m_pPosition(NULL)
{
	DbgLog((LOG_TRACE,2,TEXT("CMuxTransformOutputPin::CMuxTransformOutputPin")));
	AMGetWideString(pPinName, &m_pName);
	m_pTransformFilter = pTransformFilter;
}

#ifdef UNICODE
CMuxTransformOutputPin::CMuxTransformOutputPin(
	__in_opt LPCSTR pObjectName,
	__inout CMuxTransformFilter *pTransformFilter,
	__inout HRESULT * phr,
	__in_opt LPCWSTR pPinName)
	: CBaseOutputPin(pObjectName, pTransformFilter, &pTransformFilter->m_csFilter, phr, pPinName),
	m_pPosition(NULL)
{
	DbgLog((LOG_TRACE,2,TEXT("CMuxTransformOutputPin::CMuxTransformOutputPin")));
	AMGetWideString(pPinName, &m_pName);
	m_pTransformFilter = pTransformFilter;

}
#endif

// destructor

CMuxTransformOutputPin::~CMuxTransformOutputPin()
{
	DbgLog((LOG_TRACE,2,TEXT("CMuxTransformOutputPin::~CMuxTransformOutputPin")));

	if (m_pPosition) m_pPosition->Release();
}


// overriden to expose IMediaPosition and IMediaSeeking control interfaces

STDMETHODIMP
CMuxTransformOutputPin::NonDelegatingQueryInterface(REFIID riid, __deref_out void **ppv)
{
	CheckPointer(ppv,E_POINTER);
	ValidateReadWritePtr(ppv,sizeof(PVOID));
	*ppv = NULL;

	if (riid == IID_IMediaPosition || riid == IID_IMediaSeeking) {
		// we should have an input pin by now

		ASSERT(m_pTransformFilter->m_pInputPins.size() != 0);

		if (m_pPosition == NULL) {

			HRESULT hr = CreatePosPassThru(
				GetOwner(),
				FALSE,
				(IPin *)m_pTransformFilter->m_pInputPins[0],
				&m_pPosition);
			if (FAILED(hr)) {
				return hr;
			}
		}
		return m_pPosition->QueryInterface(riid, ppv);
	} else {
		return CBaseOutputPin::NonDelegatingQueryInterface(riid, ppv);
	}
}


// provides derived filter a chance to grab extra interfaces

HRESULT
CMuxTransformOutputPin::CheckConnect(IPin *pPin)
{
	// we should have an input connection first

	ASSERT(m_pTransformFilter->m_pInputPins.size() != 0);
	if ((m_pTransformFilter->IsAnyInputPinConnect() == FALSE)) {
		return E_UNEXPECTED;
	}

	HRESULT hr = m_pTransformFilter->CheckConnect(PINDIR_OUTPUT,this, pPin);
	if (FAILED(hr)) {
		return hr;
	}
	return CBaseOutputPin::CheckConnect(pPin);
}


// provides derived filter a chance to release it's extra interfaces

HRESULT
CMuxTransformOutputPin::BreakConnect()
{
	//  Can't disconnect unless stopped
	ASSERT(IsStopped());
	m_pTransformFilter->BreakConnect(PINDIR_OUTPUT, this);
	return CBaseOutputPin::BreakConnect();
}


// Let derived class know when the output pin is connected

HRESULT
CMuxTransformOutputPin::CompleteConnect(IPin *pReceivePin)
{
	HRESULT hr = m_pTransformFilter->CompleteConnect(PINDIR_OUTPUT, this, pReceivePin);
	if (FAILED(hr)) {
		return hr;
	}
	return CBaseOutputPin::CompleteConnect(pReceivePin);
}


// check a given transform - must have selected input type first

HRESULT
CMuxTransformOutputPin::CheckMediaType(const CMediaType* pmtOut)
{
	// must have selected input first
	ASSERT(m_pTransformFilter->m_pInputPins.size() != 0);
	if ((m_pTransformFilter->IsAnyOutPinConnect() == FALSE)) {
		return E_INVALIDARG;
	}
	return m_pTransformFilter->CheckOutputType(pmtOut, this);
}


// called after we have agreed a media type to actually set it in which case
// we run the CheckTransform function to get the output format type again

HRESULT
CMuxTransformOutputPin::SetMediaType(const CMediaType* pmtOut)
{
	HRESULT hr = NOERROR;
	ASSERT(m_pTransformFilter->m_pInputPins.size() != 0);

	// Set the base class media type (should always succeed)
	hr = CBasePin::SetMediaType(pmtOut);
	if (FAILED(hr)) {
		return hr;
	}
	return m_pTransformFilter->SetMediaType(PINDIR_OUTPUT, this, pmtOut);
}


// pass the buffer size decision through to the main transform class

HRESULT
CMuxTransformOutputPin::DecideBufferSize(
									  IMemAllocator * pAllocator,
									  __inout ALLOCATOR_PROPERTIES* pProp)
{
	return m_pTransformFilter->DecideBufferSize(pAllocator, this, pProp);
}



// return a specific media type indexed by iPosition

HRESULT
CMuxTransformOutputPin::GetMediaType(
								  int iPosition,
								  __inout CMediaType *pMediaType)
{
	ASSERT(m_pTransformFilter->m_pInputPins.size() != NULL);

	//  We don't have any media types if our input is not connected

	if (m_pTransformFilter->IsAnyInputPinConnect()) {
		return m_pTransformFilter->GetMediaType(iPosition,this, pMediaType);
	} else {
		return VFW_S_NO_MORE_ITEMS;
	}
}


// Override this if you can do something constructive to act on the
// quality message.  Consider passing it upstream as well

// Pass the quality mesage on upstream.

STDMETHODIMP
CMuxTransformOutputPin::Notify(IBaseFilter * pSender, Quality q)
{
	UNREFERENCED_PARAMETER(pSender);
	ValidateReadPtr(pSender,sizeof(IBaseFilter));

	// First see if we want to handle this ourselves
	HRESULT hr = m_pTransformFilter->AlterQuality(q);
	if (hr!=S_FALSE) {
		return hr;        // either S_OK or a failure
	}

	// S_FALSE means we pass the message on.
	// Find the quality sink for our input pin and send it there

	ASSERT(m_pTransformFilter->m_pInputPins.size() != 0);
	HRESULT errorHr = S_OK;
	for (int i =0; i < m_pTransformFilter->m_pInputPins.size(); i++)
	{
		hr = m_pTransformFilter->m_pInputPins[i]->PassNotify(q);
		if (FAILED(hr))
		{
			errorHr = hr;
		}
	}
	return errorHr;
} // Notify

