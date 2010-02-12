#pragma once
#include "IDXRenderer.h"
#include "dshow.h"
#include "Streams.h"
#include <initguid.h>
#include "combase.h"
#include "D3DTransformFilterBase.h"
// {9CE5FC93-4F69-4498-94B7-9CF1D0C8CA15}
DEFINE_GUID(CLSID_DXRenderFilter, 
			0x9ce5fc93, 0x4f69, 0x4498, 0x94, 0xb7, 0x9c, 0xf1, 0xd0, 0xc8, 0xca, 0x15);


class DXRenderFilter :
	public CBaseRenderer, public IDXRenderer,
	public ISpecifyPropertyPages, public D3DTransformFilterBase
{
protected:
	CCritSec m_csDisplayState;
	CMediaType m_InputMT;

public:
	static CUnknown *WINAPI CreateInstance(LPUNKNOWN punk, HRESULT *phr);

	//for COM interface 
	STDMETHODIMP NonDelegatingQueryInterface(REFIID iid, void **ppv);
	DECLARE_IUNKNOWN;

	// from CBaseRenderer
	virtual HRESULT CompleteConnect(IPin *pReceivePin);
	virtual HRESULT BreakConnect();

	virtual HRESULT DoRenderSample(IMediaSample *pMediaSample);
	virtual HRESULT CheckMediaType(const CMediaType *);
	virtual void OnReceiveFirstSample(IMediaSample *pMediaSample);
	virtual HRESULT SetMediaType(const CMediaType *pmt);
	// from ISpecifyPropertyPage
	STDMETHODIMP     GetPages(CAUUID *pPages);

    //from D3DTransformFilterBase
	virtual MS3DDisplay* Create3DDisplay(IDirect3D9* pD3D, int rtWidth, int rtHeight);
	virtual MS3DDisplay* Create3DDisplay(IDirect3DDevice9* pDevice, int rtWidth, int rtHeight);
	virtual BOOL IsReadyCloseWindow();
public:
	DXRenderFilter(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData);
	virtual ~DXRenderFilter();
	virtual HWND GetDisplayWindow();

	virtual bool GetFlipX();
	virtual bool SetFlipX(bool v);
	virtual bool GetFlipY();
	virtual bool SetFlipY(bool v);
};