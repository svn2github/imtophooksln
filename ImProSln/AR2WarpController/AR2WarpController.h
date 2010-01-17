#pragma once
#include "IAR2WarpController.h"
#include "CMuxTransformFilter.h"

// {F0272060-6BF7-4714-AB76-90FB089BB99A}
DEFINE_GUID(CLSID_AR2WarpController, 
			0xf0272060, 0x6bf7, 0x4714, 0xab, 0x76, 0x90, 0xfb, 0x8, 0x9b, 0xb9, 0x9a);

class AR2WarpController :
	public CMuxTransformFilter, public IAR2WarpController, public ISpecifyPropertyPages
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
	//implement DShow Property Page
	STDMETHODIMP     GetPages(CAUUID *pPages);
public:
	AR2WarpController(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData);
	virtual ~AR2WarpController();
protected:
	double  m_RANSIC_Threshold;
	virtual CCritSec* GetReceiveCS(IPin* pPin);
};
