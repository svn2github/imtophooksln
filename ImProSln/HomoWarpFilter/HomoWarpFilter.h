#pragma once
#include "IHomoWarpFilter.h"
#include "dshow.h"
#include "Streams.h"
#include <initguid.h>
#include "combase.h"
#include "HomoD3DDisplay.h"
#include "D3DTransformFilterBase.h"
#include "CMuxTransformFilter.h"
#include "MSPersist.h"
class HomoWarpFilter :
	public CMuxTransformFilter, public IHomoWarpFilter,
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
	//implement IHomoWarpFilterProperty
	virtual HRESULT SetWarpVertex(float LTx, float LTy, float LBx, float LBy, 
									float RBx, float RBy, float RTx, float RTy);
	virtual HRESULT GetWarpVertex(float& LTx, float& LTy, float& LBx, float& LBy, 
		float& RBx, float& RBy, float& RTx, float& RTy);

	virtual HRESULT SetWarpMatrix(const D3DXMATRIX& mat);
	virtual HRESULT GetWarpMatrix(D3DXMATRIX& mat);

	virtual bool GetIsFlipY() { return m_bFlipY;};
	virtual bool SetIsFlipY(bool bFlipY) { m_bFlipY = bFlipY; return true;};

	virtual bool GetIsInvWarp();
	virtual bool SetIsInvWarp(bool bInv);

	virtual bool SaveConfigToFile(WCHAR* path);
	virtual bool LoadConfigFromFile(WCHAR* path);
	virtual LPDIRECT3DTEXTURE9 GetInTexture();
	virtual CCritSec* GetCSInTexture();
protected:
	
	bool m_bFlipY;
	bool m_bInvTTS;
	CCritSec m_accessWarpMatCS;
	D3DXMATRIX m_matTTS;
	D3DXMATRIX m_InvmatTTS;
	D3DXMATRIX ComputeTTS(const D3DXVECTOR2& v1, const D3DXVECTOR2& v2, const D3DXVECTOR2& v3, const D3DXVECTOR2& v4);
	HRESULT Transform( IMediaSample *pIn, IMediaSample *pOut);
	
protected:

	virtual bool         IsAcceptedType(const CMediaType *pMT);
	//for implement D3DTransformFilterBase Method
	
	virtual MS3DDisplay* Create3DDisplay(IDirect3D9* pD3D, int rtWidth, int rtHeight);
	virtual MS3DDisplay* Create3DDisplay(IDirect3DDevice9* pDevice, int rtWidth, int rtHeight);
private:
	virtual HRESULT ReceiveInput0(IMediaSample *pSample, const IPin* pReceivePin);
	virtual HRESULT ReceiveInput1(IMediaSample *pSample, const IPin* pReceivePin);
	virtual CMuxTransformOutputPin* GetConnectedOutputPin();
public:
	HomoWarpFilter(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData);
	virtual ~HomoWarpFilter();
};
