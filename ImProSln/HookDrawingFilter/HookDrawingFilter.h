#pragma once
#include "IHookDrawingFilter.h"
#include "dshow.h"
#include "Streams.h"
#include <initguid.h>
#include "combase.h"
#include "CMuxTransformFilter.h"
#include "D3DTransformFilterBase.h"
#include "IHookDrawingStream.h"
// {30A0104E-A12F-4238-9BA4-D195BA8FB58A}
DEFINE_GUID(CLSID_HookDrawingFilter, 
			0x30a0104e, 0xa12f, 0x4238, 0x9b, 0xa4, 0xd1, 0x95, 0xba, 0x8f, 0xb5, 0x8a);

class HookDrawingStream : public CMuxTransformStream, public IHookDrawingStream, 
	public ISpecifyPropertyPages
	
{
public:
	D3DXMATRIX m_matTTS;
	CCritSec m_csMatTTS;
	virtual const D3DXMATRIX* GetWarpMatrix();
	virtual BOOL SetWarpMatrix(const D3DXMATRIX& mat);
	virtual BOOL SetWarpByPts(const D3DXVECTOR2& lt, const D3DXVECTOR2& lb,
		const D3DXVECTOR2& rb, const D3DXVECTOR2& rt);
	virtual BOOL GetWarpPts(D3DXVECTOR2& lt, D3DXVECTOR2& lb, D3DXVECTOR2& rb, 
				D3DXVECTOR2& rt);
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
	,public ISpecifyPropertyPages
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
	//Derive from D3DTransformFilterBase
	virtual HRESULT CreateTextures(UINT w, UINT h);
	virtual MS3DDisplay* Create3DDisplay(IDirect3D9* pD3D, int rtWidth, int rtHeight);
	virtual MS3DDisplay* Create3DDisplay(IDirect3DDevice9* pDevice, int rtWidth, int rtHeight);
	static LRESULT CALLBACK HookDrawingWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	virtual HRESULT CompleteConnect(PIN_DIRECTION direction, const IPin* pMyPin, const IPin* pOtherPin);
	virtual HRESULT BreakConnect(PIN_DIRECTION dir, const IPin* pPin);

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
protected:
	const int m_numPins;
	HWND m_hHookedWnd;
	HWND m_hHookRecMsgWnd;
	CCritSec m_csFillBuffer;

	vector<LPDIRECT3DTEXTURE9> m_pAddOutTexture;
	BOOL SwitchOutTexture(int idx);
	void onHookedWindowDestory();
	void onBitBltCalled();
	BOOL DrawBitBlt(HDC hdc, int x, int y, int width, int height, int dcW, int dcH, HDC hdcSrc, int x1, int y1, int srcW, int srcH, DWORD rop);
	BOOL CaptureHookWnd();
	ATOM RegisterHookWndClass(HINSTANCE hInstance);
	HRESULT CreateHookWindow(UINT winW, UINT winH);
};
