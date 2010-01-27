#pragma once
#include "ITouchLibFilter.h"
#include "dshow.h"
#include "Streams.h"
#include <initguid.h>
#include "combase.h"
#include "CMuxTransformFilter.h"

// {F982AA58-0213-4235-B342-314D853D5CEE}
DEFINE_GUID(CLSID_TouchLibFilter, 
			0xf982aa58, 0x213, 0x4235, 0xb3, 0x42, 0x31, 0x4d, 0x85, 0x3d, 0x5c, 0xee);


class TouchLibFilter :
	public CMuxTransformFilter, public ITouchLibFilter,
	public ISpecifyPropertyPages
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
	//implement DShow Property Page
	STDMETHODIMP     GetPages(CAUUID *pPages);
	//implement ITouchLibFilterProperty

protected:
	bool IsAcceptedType(const CMediaType *pmt);
	
public:
	TouchLibFilter(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData);
	virtual ~TouchLibFilter();
};
