#pragma once
#include "IDXBlendFilter.h"
#include "dshow.h"
#include "Streams.h"
#include <initguid.h>
#include "combase.h"
#include "DXBlendDisplay.h"
#include "D3DTransformFilterBase.h"
#include "CMuxTransformFilter.h"
#include "MSPersist.h"

#define NUMINPUT 4

class DXBlendFilter :
	public CMuxTransformFilter, public IDXBlendFilter,
	public ISpecifyPropertyPages, public D3DTransformFilterBase,
	public CMSPersist
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
	STDMETHODIMP     GetPages(CAUUID *pPages);
	//from IMSPersist
	virtual HRESULT SaveToFile(WCHAR* path);
	virtual HRESULT LoadFromFile(WCHAR* path);
	virtual HRESULT GetName(WCHAR* name, UINT szName);
	//from D3DBaseFilter
	virtual HRESULT QueryD3DDevice(IDXBasePin* pPin, IDirect3DDevice9*& outDevice);
	virtual HRESULT QueryD3DDeviceCS(IDXBasePin* pPin, CCritSec*& cs);
	//implement IDXBlendFilterProperty
protected:
	CCritSec m_csInTextureList[NUMINPUT];
	LPDIRECT3DTEXTURE9 m_pInTextureList[NUMINPUT];
	
protected:

	//virtual float GetFrameRateLimit(IPin* pPin) { return 60;}
	
	virtual HRESULT CreateInTexture(int idx, UINT w, UINT h);
	virtual HRESULT CopyInputImage2InputTexture(int idx, IMediaSample *pIn, const CMediaType* pInMediaType, bool bFlipY = false );
protected:

	virtual bool         IsAcceptedType(const CMediaType *pMT);
	//for implement D3DTransformFilterBase Method

	virtual MS3DDisplay* Create3DDisplay(IDirect3D9* pD3D, int rtWidth, int rtHeight);
	virtual MS3DDisplay* Create3DDisplay(IDirect3DDevice9* pDevice, int rtWidth, int rtHeight);
private:
	CAMEvent m_FillBufferEndSignal;
	CAMEvent m_ReceiveEndSignal[NUMINPUT];
	CCritSec m_csInputDirty[NUMINPUT];
	BOOL m_InputDirty[NUMINPUT];
	BOOL GetInputDirty(int idx);
	BOOL SetInputDirty(int idx, BOOL v);
public:
	DXBlendFilter(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData);
	virtual ~DXBlendFilter();
};
