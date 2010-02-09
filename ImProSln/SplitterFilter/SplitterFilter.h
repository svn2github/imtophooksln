#pragma once
#include "ISplitterFilter.h"
#include "dshow.h"
#include "Streams.h"
#include <initguid.h>
#include "combase.h"
#include "CMuxTransformFilter.h"
#include "cv.h"

// {CF964951-80EE-45d3-8B02-9041902F91FB}
DEFINE_GUID(CLSID_SplitterFilter, 
			0xcf964951, 0x80ee, 0x45d3, 0x8b, 0x2, 0x90, 0x41, 0x90, 0x2f, 0x91, 0xfb);


class SplitterFilter :
	public CMuxTransformFilter, public ISplitterFilter
{

public:
	static CUnknown *WINAPI CreateInstance(LPUNKNOWN punk, HRESULT *phr);

	//for COM interface 
	STDMETHODIMP NonDelegatingQueryInterface(REFIID iid, void **ppv);
	DECLARE_IUNKNOWN;

	//implement CMuxTransformFilter Interface
	virtual HRESULT Receive(IMediaSample *pSample, const IPin* pReceivePin);
	virtual HRESULT CreatePins();
	virtual HRESULT CheckInputType(const CMediaType* mtIn, const IPin* pPin);
	virtual HRESULT CheckOutputType(const CMediaType* mtOut, const IPin* pPin);
	virtual HRESULT DecideBufferSize(IMemAllocator * pAllocator, const IPin* pOutPin,
		__inout ALLOCATOR_PROPERTIES *pprop);
	virtual HRESULT GetMediaType(int iPosition, const IPin* pOutPin, __inout CMediaType *pMediaType);
	virtual HRESULT CompleteConnect(PIN_DIRECTION direction, const IPin* pMyPin, const IPin* pOtherPin);
	virtual HRESULT BreakConnect(PIN_DIRECTION dir, const IPin* pPin);
	virtual HRESULT FillBuffer(IMediaSample *pSamp, IPin* pPin);

	//implement DShow Property Page
	//STDMETHODIMP     GetPages(CAUUID *pPages);

protected:
	HRESULT Transform( IMediaSample *pIn, IMediaSample *pOut);
protected:
	virtual bool  IsAcceptedType(const CMediaType *pMT);
	BYTE* InData;
	bool getData ;

private:
	virtual HRESULT ReceiveCameraImg(IMediaSample *pSample, const IPin* pReceivePin);
	virtual CMuxTransformOutputPin* GetConnectedOutputPin();
public:
	SplitterFilter(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData);
	virtual ~SplitterFilter();
private:

	
	CCritSec m_cSharedState;            // Protects our internal state
	IplImage* backgroundIplImg;
	IplImage* foregroundIplImg;
	IplImage* cameraInputIplImg;

};
