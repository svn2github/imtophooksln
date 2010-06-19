#pragma once
#include "IDXRenderer.h"
#include "dshow.h"
#include "Streams.h"
#include <initguid.h>
#include "combase.h"
#include "D3DTransformFilterBase.h"
#include "IGSPersist.h"
#include "DXBaseRenderer.h"

class DXRenderFilter :
	public DXBaseRenderer, public IDXRenderer,
	public ISpecifyPropertyPages, public D3DTransformFilterBase,
	public IGSPersist
{
protected:
	CCritSec m_csDisplayState;
	CMediaType m_InputMT;
	CCritSec m_csThreadHandle;
	HANDLE m_ThreadHandle;
public:
	static CUnknown *WINAPI CreateInstance(LPUNKNOWN punk, HRESULT *phr);

	//for COM interface 
	STDMETHODIMP NonDelegatingQueryInterface(REFIID iid, void **ppv);
	DECLARE_IUNKNOWN;

	// from CBaseRenderer
	virtual HRESULT OnStartStreaming();
	virtual HRESULT OnStopStreaming();

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
	//from D3DBaseFilter
	virtual HRESULT QueryD3DDeviceCS(IDXBasePin* pPin, CCritSec*& cs);
public:
	DXRenderFilter(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData);
	virtual ~DXRenderFilter();
	virtual HWND GetDisplayWindow();
	
	virtual int  GetSampleType();
	virtual bool SetSampleType(int v);
	virtual bool GetFlipX();
	virtual bool SetFlipX(bool v);
	virtual bool GetFlipY();
	virtual bool SetFlipY(bool v);
	virtual bool GetbDrawFPS();
	virtual bool SetbDrawFPS(bool v);
	
	virtual DWORD GetProcessPriority();
    virtual BOOL SetProcessPriority(DWORD dwPriorityClass);
	virtual BOOL GetRenderThreadPriority(int& nPriority);
	virtual BOOL SetRenderThreadPriority(int nPriority);

	virtual BOOL IsWindowZoom();
	virtual HRESULT GetWindowRect(RECT& rect);
	virtual HRESULT SetWindowRect(RECT rect);
	virtual HRESULT SetWindowZoom(BOOL bZoom);
	virtual BOOL SetHideBorder(BOOL bHideBorder);
	virtual BOOL IsHideBorder();
	//from IGSPersist
	virtual HRESULT SaveToFile(WCHAR* path);
	virtual HRESULT LoadFromFile(WCHAR* path);
	virtual HRESULT GetName(WCHAR* name, UINT szName);

};