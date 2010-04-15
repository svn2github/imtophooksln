#include "stdafx.h"
#include "GSMuxFilter.h"

GSMuxFilter::GSMuxFilter(__in_opt LPCTSTR pName, __inout_opt LPUNKNOWN pUnk, REFCLSID  clsid) :
CBaseFilter(pName, pUnk, &m_csFilter, clsid), m_bEOSDelivered(FALSE), m_bQualityChanged(FALSE), 
m_bSampleSkipped(FALSE)
{
	
}
#ifdef UNICODE
GSMuxFilter::GSMuxFilter(__in_opt LPCSTR pName,
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

GSMuxFilter::~GSMuxFilter()
{
	for (int i =0; i < m_pInputPins.size(); i++)
	{
		delete m_pInputPins.at(i);
		m_pInputPins.at(i) = NULL;
	}
	m_pInputPins.clear();
	for (int i =0; i < m_pOutputPins.size(); i++)
	{
		delete m_pOutputPins[i];
		m_pOutputPins[i] = NULL;
	}
	m_pOutputPins.clear();
	for (int i =0; i < m_pStreamPins.size(); i++)
	{
		delete m_pStreamPins[i];
		m_pStreamPins[i] = NULL;
	}
	m_pStreamPins.clear();
}

int GSMuxFilter::GetPinCount()
{
	HRESULT hr = CreatePins();
	if (FAILED(hr))
	{
		return 0;
	}
	int count = 0;
	for (int i =0; i <  m_pInputPins.size(); i++)
	{
		if (m_pInputPins[i]->m_bVisible)
		{
			count++;
		}
	}
	for (int i =0; i < m_pOutputPins.size(); i++)
	{
		if (m_pOutputPins[i]->m_bVisible)
		{
			count++;
		}
	}
	for (int i=0; i < m_pStreamPins.size(); i++)
	{
		if (m_pStreamPins[i]->m_bVisible)
		{
			count++;
		}
	}
	return count;
}
STDMETHODIMP GSMuxFilter::Notify(IBaseFilter * pSender, Quality q, IPin* pPin)
{
	return S_OK;
}
CBasePin* GSMuxFilter::GetPin(int n)
{
	HRESULT hr = CreatePins();
	if (FAILED(hr))
	{
		return NULL;
	}
	for ( int i = 0; i < m_pInputPins.size(); i++)
	{
		if (m_pInputPins[i]->m_bVisible)
		{
			if (n == 0)
			{
				return m_pInputPins[i];
			}
			n--;
		}
	}
	for ( int i = 0; i < m_pOutputPins.size(); i++)
	{
		if (m_pOutputPins[i]->m_bVisible)
		{
			if (n == 0)
			{
				return m_pOutputPins[i];
			}
			n--;
		}
	}
	for ( int i = 0; i < m_pStreamPins.size(); i++)
	{
		if (m_pStreamPins[i]->m_bVisible)
		{
			if (n == 0)
			{
				return m_pStreamPins[i];
			}
			n--;
		}
	}
	return NULL;
}
HRESULT GSMuxFilter::FindPin(LPCWSTR Id, __deref_out IPin **ppPin)
{
	CheckPointer(ppPin,E_POINTER);
	ValidateReadWritePtr(ppPin,sizeof(IPin *));
	HRESULT hr = NOERROR;
	hr = CreatePins();
	for (int i =0; i < m_pInputPins.size(); i++)
	{
		if (wcscmp(m_pInputPins[i]->m_pName, Id) == 0)
		{
			*ppPin = m_pInputPins[i];
			if (*ppPin) {
				(*ppPin)->AddRef();
			}
			return hr;
		}
	}
	for (int i =0; i < m_pOutputPins.size(); i++)
	{
		if (wcscmp(m_pOutputPins[i]->m_pName, Id) == 0)
		{
			*ppPin = m_pOutputPins[i];
			if (*ppPin) {
				(*ppPin)->AddRef();
			}
			return hr;
		}
	}
	for (int i =0; i < m_pStreamPins.size(); i++)
	{
		if (wcscmp(m_pStreamPins[i]->m_pName, Id) == 0)
		{
			*ppPin = m_pStreamPins[i];
			if (*ppPin) {
				(*ppPin)->AddRef();
			}
			return hr;
		}
	}
	*ppPin = NULL;
	return VFW_E_NOT_FOUND;
}

// override state changes to allow derived transform filter
// to control streaming start/stop
BOOL GSMuxFilter::IsAnyInputPinConnect()
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
BOOL GSMuxFilter::IsAnyOutPinConnect()
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
CCritSec* GSMuxFilter::GetReceiveCS(IPin* pPin)
{
	return NULL;
}
HRESULT GSMuxFilter::Stop()
{
	CAutoLock lck1(&m_csFilter);
	if (m_State == State_Stopped) {
		return NOERROR;
	}

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
	for (int i = 0 ; i < m_pStreamPins.size(); i++)
	{
		m_pStreamPins[i]->Inactive();
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


HRESULT GSMuxFilter::Pause()
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

	/*else if (IsAnyInputPinConnect() == FALSE) {
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
	}*/

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


HRESULT GSMuxFilter::StartStreaming()
{
	return NOERROR;
}


HRESULT GSMuxFilter::StopStreaming()
{
	return NOERROR;
}

HRESULT GSMuxFilter::AlterQuality(Quality q)
{
	UNREFERENCED_PARAMETER(q);
	return S_FALSE;
}
HRESULT GSMuxFilter::EndOfStream(void)
{
	HRESULT hr = NOERROR;
	for (int i =0 ; i < m_pOutputPins.size(); i++ )
	{
		if (m_pOutputPins[i]->IsConnected())
		{
			hr = m_pOutputPins[i]->DeliverEndOfStream();
		}
	}
	return hr;
}
HRESULT GSMuxFilter::BeginFlush(void)
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

HRESULT GSMuxFilter::EndFlush(void)
{
	// sync with pushing thread -- we have no worker thread

	// ensure no more data to go downstream -- we have no queued data

	// call EndFlush on downstream pins
	HRESULT errhr = S_OK; 
	HRESULT hr = S_OK;
	ASSERT (m_pOutputPins.size() != 0);
	for (int i = 0 ; i < m_pOutputPins.size(); i++)
	{
		if (m_pOutputPins[i]->IsConnected())
		{
			hr = m_pOutputPins[i]->DeliverEndFlush();
			if (FAILED(hr))
			{
				errhr = hr; 
			}
		}
	}
	return errhr;
	// caller (the input pin's method) will unblock Receives
}

HRESULT GSMuxFilter::NewSegment(
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


HRESULT GSMuxFilter::SetMediaType(PIN_DIRECTION direction,const IPin* pPin, const CMediaType *pmt)
{
	UNREFERENCED_PARAMETER(direction);
	UNREFERENCED_PARAMETER(pmt);
	UNREFERENCED_PARAMETER(pPin);
	return NOERROR;
}


HRESULT GSMuxFilter::CheckConnect(PIN_DIRECTION dir, const IPin* pMyPin, const IPin* pOtherPin)
{
	UNREFERENCED_PARAMETER(dir);
	UNREFERENCED_PARAMETER(pOtherPin);
	UNREFERENCED_PARAMETER(pMyPin);
	return NOERROR;
}


HRESULT GSMuxFilter::BreakConnect(PIN_DIRECTION dir, const IPin* pPin)
{
	UNREFERENCED_PARAMETER(dir);
	UNREFERENCED_PARAMETER(pPin);
	return NOERROR;
}


// Let derived classes know about connection completion

HRESULT GSMuxFilter::CompleteConnect(PIN_DIRECTION dir, const IPin* pMyPin, const IPin* pOtherPin)
{
	UNREFERENCED_PARAMETER(dir);
	UNREFERENCED_PARAMETER(pMyPin);
	UNREFERENCED_PARAMETER(pOtherPin);
	return NOERROR;
}


// Set up our output sample
HRESULT GSMuxFilter::InitializeOutputSample(IMediaSample *pSample, const IPin* pInputPin, const IPin* pOutputPin, __deref_out IMediaSample **ppOutSample )
{
	IMediaSample *pOutSample;
	GSMuxInputPin* pInPin = (GSMuxInputPin*) pInputPin;
	GSMuxOutputPin* pOutPin = (GSMuxOutputPin*) pOutputPin;
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
HRESULT GSMuxFilter::DecideBufferSize(IMemAllocator * pAlloc, const IPin* pOutPin,
								 __inout ALLOCATOR_PROPERTIES *pProp)
{
	if (pAlloc == NULL || pOutPin == NULL || pProp == NULL)
	{
		return E_FAIL;
	}
	HRESULT hr = S_OK;
	CMediaType* mt = NULL;
	for (int i = 0; i < m_pOutputPins.size();i++)
	{
		if (pOutPin == m_pOutputPins[i] && mt == NULL)
		{
			mt = new CMediaType();
			*mt = ((GSMuxOutputPin*)pOutPin)->CurrentMediaType();
			break;
		}
	}
	if (mt == NULL)
	{
		for (int i = 0; i < m_pStreamPins.size();i++)
		{
			if (pOutPin == m_pStreamPins[i] && mt == NULL)
			{
				mt = new CMediaType();
				*mt = ((GSMuxStream*)pOutPin)->CurrentMediaType();
				break;
			}
		}
	}
	if (mt == NULL)
	{
		return E_FAIL;
	}
	pProp->cBuffers = 1;
	pProp->cbBuffer = mt->GetSampleSize();
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
	return S_OK;
}
GSMuxInputPin::GSMuxInputPin(
									   __in_opt LPCTSTR pObjectName,
									   __inout GSMuxFilter *pTransformFilter,
									   __inout HRESULT * phr,
									   __in_opt LPCWSTR pName)
									   : CBaseInputPin(pObjectName, pTransformFilter, &pTransformFilter->m_csFilter, phr, pName)
{
	m_bVisible = true;
	DbgLog((LOG_TRACE,2,TEXT("GSMuxInputPin::GSMuxInputPin")));
	m_pTransformFilter = pTransformFilter;
}


#ifdef UNICODE
GSMuxInputPin::GSMuxInputPin(
									   __in_opt LPCSTR pObjectName,
									   __inout GSMuxFilter *pTransformFilter,
									   __inout HRESULT * phr,
									   __in_opt LPCWSTR pName)
									   : CBaseInputPin(pObjectName, pTransformFilter, &pTransformFilter->m_csFilter, phr, pName)
{
	m_bVisible = true;
	DbgLog((LOG_TRACE,2,TEXT("CTransformInputPin::CTransformInputPin")));
	m_pTransformFilter = pTransformFilter;
}
GSMuxInputPin::~GSMuxInputPin()
{
}
#endif

HRESULT GSMuxInputPin::NonDelegatingQueryInterface(REFIID riid, __deref_out void **ppv)
{
	return __super::NonDelegatingQueryInterface(riid, ppv);
}
HRESULT
GSMuxInputPin::CheckConnect(IPin *pPin)
{
	HRESULT hr = m_pTransformFilter->CheckConnect(PINDIR_INPUT, this, pPin);
	if (FAILED(hr)) {
		return hr;
	}
	return CBaseInputPin::CheckConnect(pPin);
}


// provides derived filter a chance to release it's extra interfaces

HRESULT
GSMuxInputPin::BreakConnect()
{
	//  Can't disconnect unless stopped
	ASSERT(IsStopped());
	m_pTransformFilter->BreakConnect(PINDIR_INPUT, this);
	//SetConnectedPin(NULL);
	return CBaseInputPin::BreakConnect();
}


// Let derived class know when the input pin is connected

HRESULT
GSMuxInputPin::CompleteConnect(IPin *pReceivePin)
{
	HRESULT hr = S_OK;
	hr = m_pTransformFilter->CompleteConnect(PINDIR_INPUT, this, pReceivePin);
	if (FAILED(hr)) {
		return hr;
	}
	return CBaseInputPin::CompleteConnect(pReceivePin);
}


// check that we can support a given media type

HRESULT
GSMuxInputPin::CheckMediaType(const CMediaType* pmt)
{
	// Check the input type

	HRESULT hr = m_pTransformFilter->CheckInputType(pmt, this);
	return hr;
}


// set the media type for this connection

HRESULT
GSMuxInputPin::SetMediaType(const CMediaType* mtIn)
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

HRESULT GSMuxInputPin::CheckStreaming()
{

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

// =================================================================
// Implements IMemInputPin interface
// =================================================================


// provide EndOfStream that passes straight downstream
// (there is no queued data)
STDMETHODIMP
GSMuxInputPin::EndOfStream(void)
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
GSMuxInputPin::BeginFlush(void)
{
	CAutoLock lck(&m_pTransformFilter->m_csFilter);
	//  Are we actually doing anything?

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
GSMuxInputPin::EndFlush(void)
{
	CAutoLock lck(&m_pTransformFilter->m_csFilter);
	//  Are we actually doing anything?
	ASSERT(m_pTransformFilter->m_pOutputPins.size() != 0);
	if (!IsConnected()){
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
GSMuxInputPin::Receive(IMediaSample * pSample)
{
	HRESULT hr;
	CCritSec* receiveCS = m_pTransformFilter->GetReceiveCS(this);
	if (receiveCS != NULL)
	{
		CAutoLock lck(receiveCS);
		ASSERT(pSample);

		// check all is well with the base class
		hr = CBaseInputPin::Receive(pSample);
		if (S_OK == hr) {
			hr = m_pTransformFilter->Receive(pSample, this);
		}
	}
	else
	{
		ASSERT(pSample);
		// check all is well with the base class
		hr = CBaseInputPin::Receive(pSample);
		if (S_OK == hr) {
			hr = m_pTransformFilter->Receive(pSample, this);
		}
	}
	return hr;
}

// override to pass downstream
STDMETHODIMP 
GSMuxInputPin::NewSegment(
							   REFERENCE_TIME tStart,
							   REFERENCE_TIME tStop,
							   double dRate)
{
	//  Save the values in the pin
	CBasePin::NewSegment(tStart, tStop, dRate);
	return m_pTransformFilter->NewSegment(tStart, tStop, dRate);
}

HRESULT GSMuxInputPin::GetConnectedPin(IPin*& pPin)
{
	pPin = m_Connected;
	return S_OK;
}

GSMuxOutputPin::GSMuxOutputPin(
	__in_opt LPCTSTR pObjectName,
	__inout GSMuxFilter *pTransformFilter,
	__inout HRESULT * phr,
	__in_opt LPCWSTR pPinName)
	: CBaseOutputPin(pObjectName, pTransformFilter, &pTransformFilter->m_csFilter, phr, pPinName),
	m_pPosition(NULL)
{
	m_bVisible = true;
	DbgLog((LOG_TRACE,2,TEXT("GSMuxOutputPin::GSMuxOutputPin")));
	m_pTransformFilter = pTransformFilter;
}

#ifdef UNICODE
GSMuxOutputPin::GSMuxOutputPin(
	__in_opt LPCSTR pObjectName,
	__inout GSMuxFilter *pTransformFilter,
	__inout HRESULT * phr,
	__in_opt LPCWSTR pPinName)
	: CBaseOutputPin(pObjectName, pTransformFilter, &pTransformFilter->m_csFilter, phr, pPinName),
	m_pPosition(NULL)
{
	m_bVisible = true;
	DbgLog((LOG_TRACE,2,TEXT("GSMuxOutputPin::GSMuxOutputPin")));
	m_pTransformFilter = pTransformFilter;

}
#endif

// destructor

GSMuxOutputPin::~GSMuxOutputPin()
{
	DbgLog((LOG_TRACE,2,TEXT("GSMuxOutputPin::~GSMuxOutputPin")));
	if (m_pPosition) 
	{
		m_pPosition->Release();
	}
	
}


// overriden to expose IMediaPosition and IMediaSeeking control interfaces

STDMETHODIMP
GSMuxOutputPin::NonDelegatingQueryInterface(REFIID riid, __deref_out void **ppv)
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
	} 
	else 
	{
		return __super::NonDelegatingQueryInterface(riid, ppv);
	}
}


// provides derived filter a chance to grab extra interfaces

HRESULT
GSMuxOutputPin::CheckConnect(IPin *pPin)
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
GSMuxOutputPin::BreakConnect()
{
	//  Can't disconnect unless stopped
	ASSERT(IsStopped());
	m_pTransformFilter->BreakConnect(PINDIR_OUTPUT, this);
	//SetConnectedPin(NULL);
	return CBaseOutputPin::BreakConnect();
}


// Let derived class know when the output pin is connected

HRESULT
GSMuxOutputPin::CompleteConnect(IPin *pReceivePin)
{
	HRESULT hr = S_OK;
	
	hr = m_pTransformFilter->CompleteConnect(PINDIR_OUTPUT, this, pReceivePin);
	if (FAILED(hr)) {
		return hr;
	}
	return CBaseOutputPin::CompleteConnect(pReceivePin);
}


// check a given transform - must have selected input type first

HRESULT
GSMuxOutputPin::CheckMediaType(const CMediaType* pmtOut)
{
	// must have selected input first
	ASSERT(m_pTransformFilter->m_pInputPins.size() != 0);
	if ((m_pTransformFilter->IsAnyInputPinConnect() == FALSE)) {
		return E_INVALIDARG;
	}
	return m_pTransformFilter->CheckOutputType(pmtOut, this);
}


// called after we have agreed a media type to actually set it in which case
// we run the CheckTransform function to get the output format type again

HRESULT
GSMuxOutputPin::SetMediaType(const CMediaType* pmtOut)
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
GSMuxOutputPin::DecideBufferSize(
									  IMemAllocator * pAllocator,
									  __inout ALLOCATOR_PROPERTIES* pProp)
{
	return m_pTransformFilter->DecideBufferSize(pAllocator, this, pProp);
}



// return a specific media type indexed by iPosition

HRESULT
GSMuxOutputPin::GetMediaType(
								  int iPosition,
								  __inout CMediaType *pMediaType)
{
	ASSERT(m_pTransformFilter->m_pInputPins.size() != 0);

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
GSMuxOutputPin::Notify(IBaseFilter * pSender, Quality q)
{
	this->CurrentMediaType();
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
		if (m_pTransformFilter->m_pInputPins[i]->IsConnected())
		{
			hr = m_pTransformFilter->m_pInputPins[i]->PassNotify(q);
		}
		if (FAILED(hr))
		{
			errorHr = hr;
		}
	}
	return errorHr;
} // Notify

HRESULT GSMuxOutputPin::GetConnectedPin(IPin*& pPin)
{
	pPin = m_Connected;
	return S_OK;
}

GSMuxStream::GSMuxStream(
							 __in_opt LPCTSTR pObjectName,
							  __inout GSMuxFilter *ps,
							 __inout HRESULT *phr,
							 __in_opt LPCWSTR pPinName)
							 : CBaseOutputPin(pObjectName, ps, ps->pStateLock(), phr, pPinName),
							 m_pFilter(ps) {
	m_bVisible = true;
	
}

#ifdef UNICODE
GSMuxStream::GSMuxStream(
							 __in_opt LPCSTR pObjectName,
							 __inout GSMuxFilter *ps,
							 __inout HRESULT *phr,
							 __in_opt LPCWSTR pPinName)
							 : CBaseOutputPin(pObjectName, ps, ps->pStateLock(), phr, pPinName),
							 m_pFilter(ps) {
	m_bVisible = true;
}
#endif
//
// GSMuxStream::Destructor
//
// Decrements the number of pins on this filter
GSMuxStream::~GSMuxStream(void) {

}

// override to expose IMediaPosition
HRESULT GSMuxStream::NonDelegatingQueryInterface(REFIID riid, __deref_out void **ppv)
{
	return __super::NonDelegatingQueryInterface(riid, ppv);	
}

STDMETHODIMP GSMuxStream::Notify(IBaseFilter * pSender, Quality q)
{
	if (m_pFilter == NULL)
	{
		return S_FALSE;
	}
	return m_pFilter->Notify(pSender, q, this);
}
HRESULT GSMuxStream::FillBuffer(IMediaSample *pSamp)
{
	if (m_pFilter == NULL)
	{
		return S_FALSE;
	}
	return m_pFilter->FillBuffer(pSamp, this);
}

HRESULT GSMuxStream::CheckConnect(IPin *pPin)
{
	if (m_pFilter == NULL)
	{
		return S_FALSE;
	}	
	HRESULT hr = m_pFilter->CheckConnect(PINDIR_OUTPUT, this, pPin);
	if (FAILED(hr)) {
		return hr;
	}
	return __super::CheckConnect(pPin);
}
HRESULT GSMuxStream::BreakConnect()
{
	if (m_pFilter == NULL)
	{
		return S_FALSE;
	}	
	HRESULT hr = m_pFilter->BreakConnect(PINDIR_OUTPUT, this);
	if (FAILED(hr)) {
		return hr;
	}
	
	return __super::BreakConnect();
}
HRESULT GSMuxStream::CompleteConnect(IPin *pReceivePin)
{
	if (m_pFilter == NULL)
	{
		return S_FALSE;
	}
	HRESULT hr = S_OK;
	
	hr = m_pFilter->CompleteConnect(PINDIR_OUTPUT, this, pReceivePin);
	if (FAILED(hr)) {
		
		return hr;
	}
	return __super::CompleteConnect(pReceivePin);

}
HRESULT GSMuxStream::DecideBufferSize(
								 IMemAllocator * pAlloc,
								 __inout ALLOCATOR_PROPERTIES *pProp)
{
	if (m_pFilter == NULL)
	{
		return S_FALSE;
	}
	return m_pFilter->DecideBufferSize(pAlloc, this, pProp);
}
HRESULT GSMuxStream::OnThreadCreate(void)
{
	if (m_pFilter == NULL)
	{
		return S_FALSE;
	}
	return m_pFilter->OnThreadCreate(this);
}
HRESULT GSMuxStream::OnThreadDestroy(void)
{
	if (m_pFilter == NULL)
	{
		return S_FALSE;
	}
	return m_pFilter->OnThreadDestroy(this);
}
HRESULT GSMuxStream::OnThreadStartPlay(void)
{
	if (m_pFilter == NULL)
	{
		return S_FALSE;
	}
	return m_pFilter->OnThreadStartPlay(this);
}

HRESULT GSMuxStream::GetMediaType(int iPosition, CMediaType *pMediaType)
{
	if (m_pFilter == NULL)
	{
		return S_FALSE;
	}
	return m_pFilter->GetMediaType(iPosition, this, pMediaType);
}
HRESULT GSMuxStream::CheckMediaType(const CMediaType *pMediaType) {
	if (m_pFilter == NULL)
	{
		return S_FALSE;
	}
	CAutoLock lock(m_pFilter->pStateLock());
	return m_pFilter->CheckOutputType(pMediaType, this);
}

//
// Active
//
// The pin is active - start up the worker thread
HRESULT GSMuxStream::Active(void) {

	CAutoLock lock(m_pFilter->pStateLock());

	HRESULT hr;

	if (m_pFilter->IsActive()) {
		return S_FALSE;	// succeeded, but did not allocate resources (they already exist...)
	}

	// do nothing if not connected - its ok not to connect to
	// all pins of a source filter
	if (!IsConnected()) {
		return NOERROR;
	}

	hr = CBaseOutputPin::Active();
	if (FAILED(hr)) {
		return hr;
	}

	ASSERT(!ThreadExists());

	// start the thread
	if (!Create()) {
		return E_FAIL;
	}

	// Tell thread to initialize. If OnThreadCreate Fails, so does this.
	hr = Init();
	if (FAILED(hr))
		return hr;

	return Pause();
}


//
// Inactive
//
// Pin is inactive - shut down the worker thread
// Waits for the worker to exit before returning.
HRESULT GSMuxStream::Inactive(void) {

	CAutoLock lock(m_pFilter->pStateLock());

	HRESULT hr;

	// do nothing if not connected - its ok not to connect to
	// all pins of a source filter
	if (!IsConnected()) {
		return NOERROR;
	}

	// !!! need to do this before trying to stop the thread, because
	// we may be stuck waiting for our own allocator!!!

	hr = CBaseOutputPin::Inactive();  // call this first to Decommit the allocator
	if (FAILED(hr)) {
		return hr;
	}

	if (ThreadExists()) {
		hr = Stop();

		if (FAILED(hr)) {
			return hr;
		}

		hr = Exit();
		if (FAILED(hr)) {
			return hr;
		}

		Close();	// Wait for the thread to exit, then tidy up.
	}

	// hr = CBaseOutputPin::Inactive();  // call this first to Decommit the allocator
	//if (FAILED(hr)) {
	//	return hr;
	//}

	return NOERROR;
}


//
// ThreadProc
//
// When this returns the thread exits
// Return codes > 0 indicate an error occured
DWORD GSMuxStream::ThreadProc(void) {

	HRESULT hr;  // the return code from calls
	Command com;

	do {
		com = GetRequest();
		if (com != CMD_INIT) {
			DbgLog((LOG_ERROR, 1, TEXT("Thread expected init command")));
			Reply((DWORD) E_UNEXPECTED);
		}
	} while (com != CMD_INIT);

	DbgLog((LOG_TRACE, 1, TEXT("GSMuxStream worker thread initializing")));

	hr = OnThreadCreate(); // perform set up tasks
	if (FAILED(hr)) {
		DbgLog((LOG_ERROR, 1, TEXT("GSMuxStream::OnThreadCreate failed. Aborting thread.")));
		OnThreadDestroy();
		Reply(hr);	// send failed return code from OnThreadCreate
		return 1;
	}

	// Initialisation suceeded
	Reply(NOERROR);

	Command cmd;
	do {
		cmd = GetRequest();

		switch (cmd) {

	case CMD_EXIT:
		Reply(NOERROR);
		break;

	case CMD_RUN:
		DbgLog((LOG_ERROR, 1, TEXT("CMD_RUN received before a CMD_PAUSE???")));
		// !!! fall through???

	case CMD_PAUSE:
		Reply(NOERROR);
		DoBufferProcessingLoop();
		break;

	case CMD_STOP:
		Reply(NOERROR);
		break;

	default:
		DbgLog((LOG_ERROR, 1, TEXT("Unknown command %d received!"), cmd));
		Reply((DWORD) E_NOTIMPL);
		break;
		}
	} while (cmd != CMD_EXIT);

	hr = OnThreadDestroy();	// tidy up.
	if (FAILED(hr)) {
		DbgLog((LOG_ERROR, 1, TEXT("GSMuxStream::OnThreadDestroy failed. Exiting thread.")));
		return 1;
	}

	DbgLog((LOG_TRACE, 1, TEXT("GSMuxStream worker thread exiting")));
	return 0;
}

float GSMuxStream::GetFrameRateLimit()
{
	if (m_pFilter == NULL)
		return 10000.0; //default value
	return m_pFilter->GetFrameRateLimit(this);
}
//
// DoBufferProcessingLoop
//
// Grabs a buffer and calls the users processing function.
// Overridable, so that different delivery styles can be catered for.
HRESULT GSMuxStream::DoBufferProcessingLoop(void) {

	Command com;

	OnThreadStartPlay();

	do {
		DWORD currTime = 0;
		DWORD lastTime = 0;
		DWORD elapsedTime = 0;
		DWORD idealElapsedTime = 1.0 / GetFrameRateLimit() * 1000.0;
		while (!CheckRequest(&com)) {
			currTime = timeGetTime();
			elapsedTime = currTime - lastTime;
			
			if (elapsedTime < idealElapsedTime )
			{
				//Sleep(1);
				continue;
			}
			lastTime = currTime;
			IMediaSample *pSample;
			HRESULT hr = GetDeliveryBuffer(&pSample,NULL,NULL,0);
			if (FAILED(hr)) {
				Sleep(1);
				continue;	// go round again. Perhaps the error will go away
				// or the allocator is decommited & we will be asked to
				// exit soon.
			}
			
			// Virtual function user will override.
			hr = FillBuffer(pSample);

			if (hr == S_OK) {
				hr = Deliver(pSample);
				pSample->Release();

				// downstream filter returns S_FALSE if it wants us to
				// stop or an error if it's reporting an error.
				if(hr != S_OK)
				{
					DbgLog((LOG_TRACE, 2, TEXT("Deliver() returned %08x; stopping"), hr));
					return S_OK;
				}

			} else if (hr == S_FALSE) {
				// derived class wants us to skip pushing data
				pSample->Release();
			}
			else {
				// derived class encountered an error
				pSample->Release();
				DbgLog((LOG_ERROR, 1, TEXT("Error %08lX from FillBuffer!!!"), hr));
				DeliverEndOfStream();
				m_pFilter->NotifyEvent(EC_ERRORABORT, hr, 0);
				return hr;
			}

			// all paths release the sample
		}

		// For all commands sent to us there must be a Reply call!

		if (com == CMD_RUN || com == CMD_PAUSE) {
			Reply(NOERROR);
		} else if (com != CMD_STOP) {
			Reply((DWORD) E_UNEXPECTED);
			DbgLog((LOG_ERROR, 1, TEXT("Unexpected command!!!")));
		}
	} while (com != CMD_STOP);

	return S_FALSE;
}

HRESULT GSMuxStream::GetConnectedPin(IPin*& pPin)
{
	pPin = m_Connected;
	return S_OK;
}
