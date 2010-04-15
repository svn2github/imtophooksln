#pragma once
#include "dshow.h"
#include "Streams.h"
#include <initguid.h>
#include "combase.h"
#include <vector>
#include "GSPinDesc.h"

using namespace std;
class GSMuxFilter;

class GSMuxInputPin : public CBaseInputPin
{
	friend class GSMuxFilter;
public:
	bool m_bVisible;
protected:
	GSMuxFilter *m_pTransformFilter;
public:
	// override to expose IDXBasePin
	DECLARE_IUNKNOWN
	virtual STDMETHODIMP NonDelegatingQueryInterface(REFIID riid, __deref_out void **ppv);
	GSMuxInputPin(
		__in_opt LPCTSTR pObjectName,
		__inout GSMuxFilter *pTransformFilter,
		__inout HRESULT * phr,
		__in_opt LPCWSTR pName);
#ifdef UNICODE
	GSMuxInputPin(
		__in_opt LPCSTR pObjectName,
		__inout GSMuxFilter *pTransformFilter,
		__inout HRESULT * phr,
		__in_opt LPCWSTR pName);
#endif
	virtual ~GSMuxInputPin();

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
	virtual HRESULT GetConnectedPin(IPin*& pPin);
};
class GSMuxOutputPin : public CBaseOutputPin
{
	friend class GSMuxFilter;
public:
	bool m_bVisible;
protected:
	GSMuxFilter *m_pTransformFilter;

public:

	// implement IMediaPosition by passing upstream
	IUnknown * m_pPosition;

	GSMuxOutputPin(
		__in_opt LPCTSTR pObjectName,
		__inout GSMuxFilter *pTransformFilter,
		__inout HRESULT * phr,
		__in_opt LPCWSTR pName);
#ifdef UNICODE
	GSMuxOutputPin(
		__in_opt LPCSTR pObjectName,
		__inout GSMuxFilter *pTransformFilter,
		__inout HRESULT * phr,
		__in_opt LPCWSTR pName);
#endif
	virtual ~GSMuxOutputPin();

	DECLARE_IUNKNOWN;
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
	virtual IMemAllocator* Allocator() {return m_pAllocator;};
	virtual HRESULT GetConnectedPin(IPin*& pPin);

};

class GSMuxStream : public CAMThread, public CBaseOutputPin

{
	friend class GSMuxFilter;
public:
	// override to expose IDXBasePin
	DECLARE_IUNKNOWN;
	virtual STDMETHODIMP NonDelegatingQueryInterface(REFIID riid, __deref_out void **ppv);
	GSMuxStream(__in_opt LPCTSTR pObjectName,
		__inout GSMuxFilter *pms,
		__inout HRESULT *phr,
		__in_opt LPCWSTR pName);
#ifdef UNICODE
	GSMuxStream(__in_opt LPCSTR pObjectName,
		__inout GSMuxFilter *pms,
		__inout HRESULT *phr,
		__in_opt LPCWSTR pName);
#endif
	virtual ~GSMuxStream(void);  // virtual destructor ensures derived class destructors are called too.

protected:
	GSMuxFilter *m_pFilter;	// The parent of this stream

	// *
	// * Data Source
	// *
	// * The following three functions: FillBuffer, OnThreadCreate/Destroy, are
	// * called from within the ThreadProc. They are used in the creation of
	// * the media samples this pin will provide
	// *
	virtual HRESULT DecideBufferSize(
		IMemAllocator * pAlloc,
		__inout ALLOCATOR_PROPERTIES *pProp);

	// Override this to provide the worker thread a means
	// of processing a buffer
	virtual HRESULT FillBuffer(IMediaSample *pSamp);
	// implement it by calling filter
	virtual HRESULT CheckConnect(IPin *pPin);
	virtual HRESULT BreakConnect();
	virtual HRESULT CompleteConnect(IPin *pReceivePin);
	// Called as the thread is created/destroyed - use to perform
	// jobs such as start/stop streaming mode
	// If OnThreadCreate returns an error the thread will exit.
	virtual HRESULT OnThreadCreate(void);
	virtual HRESULT OnThreadDestroy(void);
	virtual HRESULT OnThreadStartPlay(void);

	// *
	// * Worker Thread
	// *

	HRESULT Active(void);    // Starts up the worker thread
	HRESULT Inactive(void);  // Exits the worker thread.

public:
	bool m_bVisible;
	// thread commands
	enum Command {CMD_INIT, CMD_PAUSE, CMD_RUN, CMD_STOP, CMD_EXIT};
	HRESULT Init(void) { return CallWorker(CMD_INIT); }
	HRESULT Exit(void) { return CallWorker(CMD_EXIT); }
	HRESULT Run(void) { return CallWorker(CMD_RUN); }
	HRESULT Pause(void) { return CallWorker(CMD_PAUSE); }
	HRESULT Stop(void) { return CallWorker(CMD_STOP); }
	virtual STDMETHODIMP Notify(IBaseFilter * pSender, Quality q);
	virtual CMediaType& CurrentMediaType() { return m_mt; };

	virtual HRESULT GetConnectedPin(IPin*& pPin);
protected:
	Command GetRequest(void) { return (Command) CAMThread::GetRequest(); }
	BOOL    CheckRequest(Command *pCom) { return CAMThread::CheckRequest( (DWORD *) pCom); }

	// override these if you want to add thread commands
	virtual DWORD ThreadProc(void);  		// the thread function

	virtual HRESULT DoBufferProcessingLoop(void);    // the loop executed whilst running
	virtual float GetFrameRateLimit();
	// *
	// * AM_MEDIA_TYPE support
	// *

	// If you support more than one media type then override these 2 functions
	virtual HRESULT CheckMediaType(const CMediaType *pMediaType);
	virtual HRESULT GetMediaType(int iPosition, __inout CMediaType *pMediaType);  // List pos. 0-n

	virtual STDMETHODIMP QueryId(__deref_out LPWSTR * Id)
	{
		return AMGetWideString(m_pName, Id);
	}
};

class GSMuxFilter : public CBaseFilter
{
public:
	virtual int GetPinCount();
	virtual CBasePin * GetPin(int n);
	STDMETHODIMP FindPin(LPCWSTR Id, __deref_out IPin **ppPin);
	STDMETHODIMP Stop();
	STDMETHODIMP Pause();
public:

	GSMuxFilter(__in_opt LPCTSTR , __inout_opt LPUNKNOWN, REFCLSID clsid);
#ifdef UNICODE
	GSMuxFilter(__in_opt LPCSTR , __inout_opt LPUNKNOWN, REFCLSID clsid);
#endif
	virtual ~GSMuxFilter();

	// These must be supplied in a derived class 
	// Transform Filter Method
	virtual HRESULT Receive(IMediaSample *pSample, const IPin* pReceivePin) { return E_UNEXPECTED; };
	virtual HRESULT CheckInputType(const CMediaType* mtIn, const IPin* pPin) { return E_UNEXPECTED;};
	virtual HRESULT CheckOutputType(const CMediaType* mtOut, const IPin* pPin) { return E_UNEXPECTED;};
	virtual HRESULT DecideBufferSize(
		IMemAllocator * pAllocator, const IPin* pOutPin,
		__inout ALLOCATOR_PROPERTIES *pprop);
	virtual HRESULT GetMediaType(int iPosition, const IPin* pOutPin, __inout CMediaType *pMediaType) { return E_UNEXPECTED;};
	// Source Filter Method

	virtual HRESULT FillBuffer(IMediaSample *pSamp, IPin* pPin) { return E_UNEXPECTED; };
	virtual float GetFrameRateLimit(IPin* pPin) { return 10000.0;}
	// =================================================================
	// ----- Optional Override Methods           -----------------------
	// =================================================================
	// Source Filter Method 
	virtual HRESULT OnThreadCreate(IPin* pPin){return NOERROR;};
	virtual HRESULT OnThreadDestroy(IPin* pPin){return NOERROR;};
	virtual HRESULT OnThreadStartPlay(IPin* pPin){return NOERROR;};

	// Transform Filter Method
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
	virtual STDMETHODIMP Notify(IBaseFilter * pSender, Quality q, IPin* pPin);
	virtual HRESULT EndOfStream(void);
	virtual HRESULT BeginFlush(void);
	virtual HRESULT EndFlush(void);
	virtual HRESULT NewSegment(
		REFERENCE_TIME tStart,
		REFERENCE_TIME tStop,
		double dRate);

	CCritSec*	pStateLock(void) { return &m_csFilter; }
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

	friend class GSMuxInputPin;
	friend class GSMuxOutputPin;
	vector<GSMuxInputPin*> m_pInputPins;
	vector<GSMuxOutputPin*> m_pOutputPins;
	vector<GSMuxStream*> m_pStreamPins;
private:
	virtual BOOL IsAnyInputPinConnect();
	virtual BOOL IsAnyOutPinConnect();
protected:
	virtual HRESULT CreatePins() = 0;
	virtual CCritSec* GetReceiveCS(IPin* pPin);
	// functions for implement TransformFilter methods
	vector<GSFILTER_PIN_DESC> m_pInputPinDesc;
	vector<GSFILTER_PIN_DESC> m_pOutputPinDesc;
	vector<GSFILTER_PIN_DESC> m_pStreamPinDesc;

public:
	// functions for implement TransformFilter methods
};
