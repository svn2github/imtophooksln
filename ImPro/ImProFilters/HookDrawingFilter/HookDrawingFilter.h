#pragma once
#include "IHookDrawingFilter.h"
#include "dshow.h"
#include "Streams.h"
#include <initguid.h>
#include "combase.h"
#include "CMuxTransformFilter.h"
#include "D3DTransformFilterBase.h"
#include "IHookDrawingStream.h"
#include "MSPersist.h"
#include "MyMediaSample.h"

#define NUMHOOKPIN 4
#define RENDERSTEP 2
class HookDrawingStream : public CMuxTransformStream, public IHookDrawingStream, 
	public ISpecifyPropertyPages
	
{
protected:
	float m_fps;
	virtual float GetFrameRateLimit();

public:
	D3DXMATRIX m_matTTS;
	CCritSec m_csMatTTS;
	virtual const D3DXMATRIX* GetWarpMatrix();
	virtual BOOL SetWarpMatrix(const D3DXMATRIX& mat);
	virtual BOOL SetWarpByPts(const D3DXVECTOR2& lt, const D3DXVECTOR2& lb,
		const D3DXVECTOR2& rb, const D3DXVECTOR2& rt);
	virtual BOOL GetWarpPts(D3DXVECTOR2& lt, D3DXVECTOR2& lb, D3DXVECTOR2& rb, 
				D3DXVECTOR2& rt);
	virtual BOOL GetResolution(UINT& resW, UINT& resH);
	virtual BOOL SetResolution(UINT resW, UINT resH);
	virtual float GetFrameRate();
	virtual BOOL SetFrameRate(float fps);
	//ISpecifyPropertyPages
	STDMETHODIMP     GetPages(CAUUID *pPages);
	//for COM interface 
	STDMETHODIMP NonDelegatingQueryInterface(REFIID iid, void **ppv);
	DECLARE_IUNKNOWN;
public:
	HookDrawingStream(__in_opt LPCTSTR pObjectName,
		__inout HRESULT *phr,
		__inout CMuxTransformFilter *pms,
		__in_opt LPCWSTR pName);
#ifdef UNICODE
	HookDrawingStream(__in_opt LPCSTR pObjectName,
		__inout HRESULT *phr,
		__inout CMuxTransformFilter *pms,
		__in_opt LPCWSTR pName);
#endif
	virtual ~HookDrawingStream(void);  // virtual destructor ensures derived class destructors are called too.

};


class HookDrawingFilter :
	public CMuxTransformFilter, public IHookDrawingFilter, public D3DTransformFilterBase
	,public ISpecifyPropertyPages, public CMSPersist
{

public:
	static CUnknown *WINAPI CreateInstance(LPUNKNOWN punk, HRESULT *phr);
	//Derive from CMuxTransformFilter

	virtual HRESULT CreatePins();
	virtual HRESULT FillBuffer(IMediaSample *pSamp, IPin* pPin);
	virtual HRESULT GetMediaType(int iPosition, const IPin* pOutPin, __inout CMediaType *pMediaType);
	virtual HRESULT CheckOutputType(const CMediaType* mtOut, const IPin* pPin);
	virtual HRESULT DecideBufferSize(
		IMemAllocator * pAllocator, const IPin* pOutPin,
		__inout ALLOCATOR_PROPERTIES *pprop);
	virtual float GetFrameRateLimit(IPin* pPin) { return 60.0;}
	//Derive from D3DTransformFilterBase
	virtual HRESULT initD3D(UINT rtWidth, UINT rtHeight );
	virtual HRESULT initAddTextures(UINT w, UINT h);
	virtual HRESULT CreateAdditionalTexture(UINT idx, UINT w, UINT h);
	virtual HRESULT CreateInTexture(UINT w, UINT h);
	virtual MS3DDisplay* Create3DDisplay(IDirect3D9* pD3D, int rtWidth, int rtHeight);
	virtual MS3DDisplay* Create3DDisplay(IDirect3DDevice9* pDevice, int rtWidth, int rtHeight);
	static LRESULT CALLBACK HookDrawingWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	HRESULT SetRenderTarget(int idx);
	HRESULT ResetRenderTarget();
	HRESULT CopyRenderTarget2OutputData(int idx, IMediaSample *pOut, const CMediaType* pOutMediaType);
	HRESULT CopyRenderTarget2OutputTexture(int idx);
	virtual HRESULT CompleteConnect(PIN_DIRECTION direction, const IPin* pMyPin, const IPin* pOtherPin);
	virtual HRESULT BreakConnect(PIN_DIRECTION dir, const IPin* pPin);
	//from IMSPersist
	virtual HRESULT SaveToFile(WCHAR* path);
	virtual HRESULT LoadFromFile(WCHAR* path);
	virtual HRESULT GetName(WCHAR* name, UINT szName);

	//from D3DBaseFilter
	virtual HRESULT QueryD3DDevice(IDXBasePin* pPin, IDirect3DDevice9*& outDevice);
	virtual HRESULT QueryD3DDeviceCS(IDXBasePin* pPin, CCritSec*& cs);
	//ISpecifyPropertyPages
	STDMETHODIMP     GetPages(CAUUID *pPages);
	//for COM interface 
	STDMETHODIMP NonDelegatingQueryInterface(REFIID iid, void **ppv);
	DECLARE_IUNKNOWN;

public:
	HookDrawingFilter(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData);
	virtual ~HookDrawingFilter();

public:
	virtual BOOL IsHooked();
	virtual HWND GetHookedWindow();
	virtual BOOL SetHookedWindow(HWND hwnd);
	virtual BOOL GetWarpMatrix(UINT idx, D3DXMATRIX& matWarp);
	virtual BOOL SetWarpMatrix(UINT idx, const D3DXMATRIX& matWarp);
	virtual BOOL GetResolution(IPin* pPin, UINT& resW, UINT& resH);
	virtual BOOL SetResolution(IPin* pPin, UINT resW, UINT resH);
	virtual BOOL GetSourceResolution(UINT& resW, UINT& resH);
	virtual BOOL SetSourceResolution(UINT resW, UINT resH);
	virtual	BOOL CaptureHookWnd();
protected:
	
	HWND m_hHookedWnd;
	HWND m_hHookRecMsgWnd;
	CCritSec m_csFillBuffer;
	CCritSec m_csAddTextures[NUMHOOKPIN];
	CCritSec m_csAddRenderTarget[NUMHOOKPIN];
	CCritSec m_csHookDirty[NUMHOOKPIN];
	CCritSec m_csHookRenderState;
	BOOL m_bHookDirty[NUMHOOKPIN];


	vector<LPDIRECT3DTEXTURE9> m_pAddOutTexture;
	vector<LPDIRECT3DTEXTURE9> m_pAddRenderTarget;
	BOOL CopyInTexture2OutTexture(int idx);
	BOOL CopyOutputTexture2OutputData(int idx, IMediaSample *pOut, const CMediaType* pOutMediaType, bool bFlipY = false);
	void onHookedWindowDestory();
	void onBitBltCalled();
	BOOL DrawBitBlt(HDC hdc, int x, int y, int width, int height, int dcW, int dcH, HDC hdcSrc, int x1, int y1, int srcW, int srcH, DWORD rop);
	ATOM RegisterHookWndClass(HINSTANCE hInstance);
	HRESULT CreateHookWindow(UINT winW, UINT winH);

	BOOL GetHookDirty(int idx);
	BOOL SetHookDirty(int idx, BOOL v);
	
	static HRESULT CALLBACK OnBeforeDisplayResetDevice(IDirect3DDevice9 * pd3dDevice, 
		void* pUserContext);
	static HRESULT CALLBACK OnAfterDisplayResetDevice(IDirect3DDevice9 * pd3dDevice, 
		void* pUserContext);
};
