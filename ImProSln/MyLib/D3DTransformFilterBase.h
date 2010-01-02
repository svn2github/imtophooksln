#pragma once
#include "dshow.h"
#include "Streams.h"
#include "MSSD3DClass.h"

class D3DTransformFilterBase
{
protected:
	HWND			 m_hWndD3D ;
	IDirect3D9*      m_pD3D;
	MS3DDisplay*  m_pD3DDisplay;

	LPDIRECT3DTEXTURE9 m_pOutTexture;
	LPDIRECT3DTEXTURE9 m_pInTexture;

	virtual HRESULT DoTransform(IMediaSample *pIn, IMediaSample *pOut, const CMediaType* pInType);
	virtual HRESULT CreateInOutTextures(UINT w, UINT h);
	virtual MS3DDisplay* Create3DDisplay(HWND hWndD3D,IDirect3D9* pD3D, int rtWidth, int rtHeight) = 0;
	virtual HWND GetD3DWnd();
	virtual IDirect3D9* GetD3D();
	virtual HRESULT initD3D(UINT rtWidth = 0, UINT rtHeight = 0);
	virtual BOOL ReleaseD3D();

	static LRESULT CALLBACK D3DWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	static ATOM RegisterWndClass(HINSTANCE hInstance);

public:
	D3DTransformFilterBase();
	virtual ~D3DTransformFilterBase();
};