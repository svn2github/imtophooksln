#pragma once
#include "IHomoWarpFilter.h"
#include "dshow.h"
#include "Streams.h"
#include <initguid.h>
#include "combase.h"
#include "HomoD3DDisplay.h"
#include "D3DTransformFilterBase.h"

// {B2D25611-792D-44b4-BF50-4440E3BC647A}
DEFINE_GUID(CLSID_HomoWarpFilter, 
			0xb2d25611, 0x792d, 0x44b4, 0xbf, 0x50, 0x44, 0x40, 0xe3, 0xbc, 0x64, 0x7a);


class HomoWarpFilter :
	public CTransformFilter, public IHomoWarpFilter,
	public ISpecifyPropertyPages, public D3DTransformFilterBase
{

public:
	static CUnknown *WINAPI CreateInstance(LPUNKNOWN punk, HRESULT *phr);

	//for COM interface 
	STDMETHODIMP NonDelegatingQueryInterface(REFIID iid, void **ppv);
	DECLARE_IUNKNOWN;

	//implement DShow Interface
	virtual HRESULT          CheckInputType( const CMediaType * pmt );
	virtual HRESULT          CheckTransform(const CMediaType *pmtIn, const CMediaType *pmtOut);
	virtual HRESULT          CompleteConnect(PIN_DIRECTION direction, IPin *pReceivePin);
	virtual HRESULT          Transform( IMediaSample *pIn, IMediaSample *pOut);
	virtual HRESULT          DecideBufferSize(IMemAllocator *pAllocator, ALLOCATOR_PROPERTIES *pProp);
	virtual HRESULT          GetMediaType(int iPosition, CMediaType *pMediaType);
	//implement DShow Property Page
	STDMETHODIMP     GetPages(CAUUID *pPages);
	//implement IHomoWarpFilterProperty
	virtual HRESULT SetWarpVertex(float LTx, float LTy, float LBx, float LBy, 
									float RBx, float RBy, float RTx, float RTy);
	virtual HRESULT GetWarpVertex(float& LTx, float& LTy, float& LBx, float& LBy, 
		float& RBx, float& RBy, float& RTx, float& RTy);

protected:
	D3DXMATRIX m_matTTS;
	D3DXMATRIX ComputeTTS(const D3DXVECTOR2& v1, const D3DXVECTOR2& v2, const D3DXVECTOR2& v3, const D3DXVECTOR2& v4);

protected:

	CMediaType       m_InputMT;
	CMediaType       m_OutputMT;
	virtual bool         IsAcceptedType(const CMediaType *pMT);
	//for implement D3DTransformFilterBase Method
	virtual MS3DDisplay* Create3DDisplay(HWND hWndD3D,IDirect3D9* pD3D, int rtWidth, int rtHeight);
public:
	HomoWarpFilter(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData);
	virtual ~HomoWarpFilter();
};
