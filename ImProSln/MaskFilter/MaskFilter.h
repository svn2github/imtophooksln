#pragma once
#include "IMaskFilter.h"
#include "dshow.h"
#include "Streams.h"
#include <initguid.h>
#include "combase.h"
#include "MaskFilterDisplay.h"
#include "D3DTransformFilterBase.h"
#include "CMuxTransformFilter.h"
#include "MyMediaSample.h"
#include "MSPersist.h"
class MaskFilter :
	public CMuxTransformFilter, public IMaskFilter,
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
	//implement DShow Property Page
	STDMETHODIMP     GetPages(CAUUID *pPages);
	//from IMSPersist
	virtual HRESULT SaveToFile(WCHAR* path);
	virtual HRESULT LoadFromFile(WCHAR* path);
	virtual HRESULT GetName(WCHAR* name, UINT szName);
	//from D3DBaseFilter
	virtual HRESULT QueryD3DDevice(IDXBasePin* pPin, IDirect3DDevice9*& outDevice);
	virtual HRESULT QueryD3DDeviceCS(IDXBasePin* pPin, CCritSec*& cs);
	//implement IMaskFilterProperty
	virtual BOOL SetMaskFlag(int flag);
	virtual int GetMaskFlag();
	virtual BOOL LoadMaskFromFile(WCHAR* path);
	virtual BOOL GenerateMaskFromARLayout(const ARMultiMarkerInfoT* pMarkerConfig, float fMaskScale = 1.2);
	virtual BOOL GenerateMaskFromARLayoutFile(WCHAR* path, float fMaskScale = 1.2);
	virtual BOOL GenerateMaskFromWarpMatrix(D3DXMATRIX warpMat[], int numMatrix);
	virtual BOOL GenerateMaskFromWarpConfigFile(WCHAR* path);
	virtual BOOL GenerateMaskFromVertices(D3DXVECTOR2* pts[], int numRects, float fMaskScale = 1.2);
	virtual BOOL GetMaskFlipY();
	virtual BOOL SetMaskFlipY(bool bFlipY);
	virtual BOOL ClearMask();
	virtual float GetMaskScale();
	virtual BOOL SetMaskScale(float fScale);
protected:
	CCritSec m_csDisplayState;
	CCritSec m_csMaskVertexData;
	CCritSec m_csARLayoutConfig;
	CCritSec m_csMaskScale;
	float m_fMaskScale;
	ARLayoutConfigData* m_pARLayoutConfig;
	MaskVertexData* m_pMaskVertexData;
	HRESULT UpdateMask();
protected:

	virtual bool         IsAcceptedType(const CMediaType *pMT);
	//for implement D3DTransformFilterBase Method
	virtual MS3DDisplay* Create3DDisplay(IDirect3D9* pD3D, int rtWidth, int rtHeight);
	virtual MS3DDisplay* Create3DDisplay(IDirect3DDevice9* pDevice, int rtWidth, int rtHeight);
	
	virtual HRESULT ReceiveInput0(IMediaSample *pSample, const IPin* pReceivePin);
	virtual HRESULT ReceiveInput1(IMediaSample *pSample, const IPin* pReceivePin);
	virtual HRESULT ReceiveInput2(IMediaSample *pSample, const IPin* pReceivePin);
	virtual HRESULT Transform( IMediaSample *pIn, IMediaSample *pOut);
public:
	MaskFilter(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData);
	virtual ~MaskFilter();
};
