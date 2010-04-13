#pragma once
#include "IGSDXRenderer.h"
#include "dshow.h"
#include "Streams.h"
#include <initguid.h>
#include "combase.h"
#include "GSDXFilterBase.h"
#include "GSDXBaseRenderer.h"

class GSDXRenderer :
    public IGSDXRenderer, public GSDXBaseRenderer,
	public GSDXFilterBase
{
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

	virtual BOOL IsReadyCloseWindow();
	//from GSDXShareFilter
	virtual HRESULT QueryD3DDeviceCS(IGSDXSharePin* pPin, CCritSec*& cs);
public:
	GSDXRenderer(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData);
	virtual ~GSDXRenderer();
	virtual HWND GetDisplayWindow();

	virtual BOOL IsWindowZoom();
	virtual HRESULT GetWindowRect(RECT& rect);
	virtual HRESULT SetWindowRect(RECT rect);
	virtual HRESULT SetWindowZoom(BOOL bZoom);
	virtual BOOL SetHideBorder(BOOL bHideBorder);
	virtual BOOL IsHideBorder();
	

};