#pragma once


#include "dshow.h"
#include "Streams.h"
#include <initguid.h>
#include "combase.h"
#include <vector>
using namespace std;

class CMuxTransformFilter;
class CMuxTransformInputPin : public CBaseInputPin
{
	friend class CMuxTransformFilter;

protected:
	CMuxTransformFilter *m_pTransformFilter;
	
public:

	CMuxTransformInputPin(
		__in_opt LPCTSTR pObjectName,
		__inout CMuxTransformFilter *pTransformFilter,
		__inout HRESULT * phr,
		__in_opt LPCWSTR pName);
#ifdef UNICODE
	CMuxTransformInputPin(
		__in_opt LPCSTR pObjectName,
		__inout CMuxTransformFilter *pTransformFilter,
		__inout HRESULT * phr,
		__in_opt LPCWSTR pName);
#endif
	virtual ~CMuxTransformInputPin();

	virtual STDMETHODIMP QueryId(__deref_out LPWSTR * Id)
	{
		return AMGetWideString(m_pName, Id);
	}

	// Grab and release extra interfaces if required

	virtual HRESULT CheckConnect(IPin *pPin);
	virtual HRESULT BreakConnect();
	virtual HRESULT CompleteConnect(IPin *pReceivePin);

	// check that we can support this output type
	virtual HRESULT CheckMediaType(const CMediaType* mtIn);

	// set the connection media type
	virtual HRESULT SetMediaType(const CMediaType* mt);
	virtual CMediaType GetCurMediaType();
	// --- IMemInputPin -----

	// here's the next block of data from the stream.
	// AddRef it yourself if you need to hold it beyond the end
	// of this call.
	virtual STDMETHODIMP Receive(IMediaSample * pSample);

	// provide EndOfStream that passes straight downstream
	// (there is no queued data)
	virtual STDMETHODIMP EndOfStream(void);

	// passes it to CTransformFilter::BeginFlush
	virtual STDMETHODIMP BeginFlush(void);

	// passes it to CTransformFilter::EndFlush
	virtual STDMETHODIMP EndFlush(void);

	virtual STDMETHODIMP NewSegment(
		REFERENCE_TIME tStart,
		REFERENCE_TIME tStop,
		double dRate);

	// Check if it's OK to process samples
	virtual HRESULT CheckStreaming();

	// Media type
public:
	virtual CMediaType& CurrentMediaType() { return m_mt; };
};
class CMuxTransformOutputPin : public CBaseOutputPin
{
	friend class CMuxTransformFilter;

protected:
	CMuxTransformFilter *m_pTransformFilter;

public:

	// implement IMediaPosition by passing upstream
	IUnknown * m_pPosition;

	CMuxTransformOutputPin(
		__in_opt LPCTSTR pObjectName,
		__inout CMuxTransformFilter *pTransformFilter,
		__inout HRESULT * phr,
		__in_opt LPCWSTR pName);
#ifdef UNICODE
	CMuxTransformOutputPin(
		__in_opt LPCSTR pObjectName,
		__inout CMuxTransformFilter *pTransformFilter,
		__inout HRESULT * phr,
		__in_opt LPCWSTR pName);
#endif
	virtual ~CMuxTransformOutputPin();

	// override to expose IMediaPosition
	virtual STDMETHODIMP NonDelegatingQueryInterface(REFIID riid, __deref_out void **ppv);

	// --- CBaseOutputPin ------------

	virtual STDMETHODIMP QueryId(__deref_out LPWSTR * Id)
	{
		return AMGetWideString(m_pName, Id);
	}

	// Grab and release extra interfaces if required

	virtual HRESULT CheckConnect(IPin *pPin);
	virtual HRESULT BreakConnect();
	virtual HRESULT CompleteConnect(IPin *pReceivePin);

	// check that we can support this output type
	virtual HRESULT CheckMediaType(const CMediaType* mtOut);

	// set the connection media type
	virtual HRESULT SetMediaType(const CMediaType *pmt);
	virtual CMediaType GetCurMediaType();
	// called from CBaseOutputPin during connection to ask for
	// the count and size of buffers we need.
	virtual HRESULT DecideBufferSize(
		IMemAllocator * pAlloc,
		__inout ALLOCATOR_PROPERTIES *pProp);

	// returns the preferred formats for a pin
	virtual HRESULT GetMediaType(int iPosition, __inout CMediaType *pMediaType);

	// inherited from IQualityControl via CBasePin
	virtual STDMETHODIMP Notify(IBaseFilter * pSender, Quality q);

	// Media type
public:
	virtual CMediaType& CurrentMediaType() { return m_mt; };

};
class CMuxTransformFilter : public CBaseFilter
{
public:
	virtual int GetPinCount();
	virtual CBasePin * GetPin(int n);
	STDMETHODIMP FindPin(LPCWSTR Id, __deref_out IPin **ppPin);
	STDMETHODIMP Stop();
	STDMETHODIMP Pause();
public:

	CMuxTransformFilter(__in_opt LPCTSTR , __inout_opt LPUNKNOWN, REFCLSID clsid);
#ifdef UNICODE
	CMuxTransformFilter(__in_opt LPCSTR , __inout_opt LPUNKNOWN, REFCLSID clsid);
#endif
	virtual ~CMuxTransformFilter();
	// These must be supplied in a derived class
	virtual HRESULT Receive(IMediaSample *pSample, const IPin* pReceivePin) = 0;
	virtual HRESULT CheckInputType(const CMediaType* mtIn, const IPin* pPin) PURE;
	virtual HRESULT CheckOutputType(const CMediaType* mtOut, const IPin* pPin) PURE;
	virtual HRESULT DecideBufferSize(
		IMemAllocator * pAllocator, const IPin* pOutPin,
		__inout ALLOCATOR_PROPERTIES *pprop) PURE;
	virtual HRESULT GetMediaType(int iPosition, const IPin* pOutPin, __inout CMediaType *pMediaType) PURE;
	// =================================================================
	// ----- Optional Override Methods           -----------------------
	// =================================================================

	// you can also override these if you want to know about streaming
	virtual HRESULT StartStreaming();
	virtual HRESULT StopStreaming();

	// override if you can do anything constructive with quality notifications
	virtual HRESULT AlterQuality(Quality q);

	// override this to know when the media type is actually set
	virtual HRESULT SetMediaType(PIN_DIRECTION direction, const IPin* pPin, const CMediaType *pmt);

	// chance to grab extra interfaces on connection
	virtual HRESULT CheckConnect(PIN_DIRECTION dir, const IPin* pMyPin, const IPin* pOtherPin);
	virtual HRESULT BreakConnect(PIN_DIRECTION dir, const IPin* pPin);
	virtual HRESULT CompleteConnect(PIN_DIRECTION direction, const IPin* pMyPin, const IPin* pOtherPin);



	// Standard setup for output sample
	virtual HRESULT InitializeOutputSample(IMediaSample *pSample, const IPin* pInputPin, const IPin* pOutputPin, __deref_out IMediaSample **ppOutSample);

	// if you override Receive, you may need to override these three too
	virtual HRESULT EndOfStream(void);
	virtual HRESULT BeginFlush(void);
	virtual HRESULT EndFlush(void);
	virtual HRESULT NewSegment(
		REFERENCE_TIME tStart,
		REFERENCE_TIME tStop,
		double dRate);

#ifdef PERF
	// Override to register performance measurement with a less generic string
	// You should do this to avoid confusion with other filters
	virtual void RegisterPerfId()
	{m_idTransform = MSR_REGISTER(TEXT("Transform"));}
#endif // PERF


	// implementation details

protected:

#ifdef PERF
	int m_idTransform;                 // performance measuring id
#endif
	BOOL m_bEOSDelivered;              // have we sent EndOfStream
	BOOL m_bSampleSkipped;             // Did we just skip a frame
	BOOL m_bQualityChanged;            // Have we degraded?

	// critical section protecting filter state.
	CCritSec m_csFilter;
	// critical section stopping state changes (ie Stop) while we're
	// processing a sample.
	//
	// This critical section is held when processing
	// events that occur on the receive thread - Receive() and EndOfStream().
	//
	// If you want to hold both m_csReceive and m_csFilter then grab
	// m_csFilter FIRST - like CTransformFilter::Stop() does.

	CCritSec m_csReceive;

	// these hold our input and output pins

	friend class CMuxTransformInputPin;
	friend class CMuxTransformOutputPin;
	vector<CMuxTransformInputPin*> m_pInputPins;
	vector<CMuxTransformOutputPin*> m_pOutputPins;

private:
	virtual BOOL IsAnyInputPinConnect();
	virtual BOOL IsAnyOutPinConnect();
protected:
	virtual HRESULT CreatePins() = 0;

};

