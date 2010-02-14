#pragma once
#include "IMaskFilter.h"
#include "dshow.h"
#include "Streams.h"
#include <initguid.h>
#include "combase.h"
#include "MaskFilterDisplay.h"
#include "D3DTransformFilterBase.h"
#include "CMuxTransformFilter.h"

class MaskFilter :
	public CMuxTransformFilter, public IMaskFilter,
	public ISpecifyPropertyPages, public D3DTransformFilterBase
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
	//implement IMaskFilterProperty
	virtual BOOL SetMaskFlag(int flag);
	virtual int GetMaskFlag();
	virtual BOOL LoadMaskFromFile(WCHAR* path);
	virtual BOOL GenerateMaskFromARLayout(const ARMultiMarkerInfoT* pMarkerConfig);
	virtual BOOL GenerateMaskFromARLayoutFile(WCHAR* path);
	virtual BOOL GetMaskFlipY();
	virtual BOOL SetMaskFlipY(bool bFlipY);
	//virtual BOOL GenerateMaskFromWarpMatrix(WCHAR* path);
protected:
	CCritSec m_csDisplayState;
	
protected:

	virtual bool         IsAcceptedType(const CMediaType *pMT);
	//for implement D3DTransformFilterBase Method
	virtual MS3DDisplay* Create3DDisplay(IDirect3D9* pD3D, int rtWidth, int rtHeight);
	virtual MS3DDisplay* Create3DDisplay(IDirect3DDevice9* pDevice, int rtWidth, int rtHeight);
	
	virtual HRESULT ReceiveInput0(IMediaSample *pSample, const IPin* pReceivePin);
	virtual HRESULT ReceiveInput1(IMediaSample *pSample, const IPin* pReceivePin);
	virtual HRESULT Transform( IMediaSample *pIn, IMediaSample *pOut);
public:
	MaskFilter(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData);
	virtual ~MaskFilter();
};
