#pragma once
#include "IHookDrawingFilter.h"
#include "dshow.h"
#include "Streams.h"
#include <initguid.h>
#include "combase.h"
#include "CMuxTransformFilter.h"
#include "D3DTransformFilterBase.h"

// {30A0104E-A12F-4238-9BA4-D195BA8FB58A}
DEFINE_GUID(CLSID_HookDrawingFilter, 
			0x30a0104e, 0xa12f, 0x4238, 0x9b, 0xa4, 0xd1, 0x95, 0xba, 0x8f, 0xb5, 0x8a);


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
	virtual MS3DDisplay* Create3DDisplay(HWND hWndD3D,IDirect3D9* pD3D, int rtWidth, int rtHeight);
	virtual ATOM RegisterWndClass(HINSTANCE hInstance);
	virtual HRESULT CreateD3DWindow(UINT winW, UINT winH);
	static LRESULT CALLBACK HookDrawingWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
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
	BOOL m_bHooked;
	HWND m_hHookedWnd;
	CCritSec m_csInTexture;
	void onHookedWindowDestory();
	void onBitBltCalled();
	BOOL DrawBitBlt(HDC hdc, int x, int y, int width, int height, int dcW, int dcH, HDC hdcSrc, int x1, int y1, int srcW, int srcH, DWORD rop);
};
