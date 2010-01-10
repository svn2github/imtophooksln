#pragma once
#include "dshow.h"
#include "Streams.h"
#include <d3dx9.h>

class D3DEnv
{
protected:
	HWND			 m_hWndD3D ;
	IDirect3D9*      m_pD3D;
public:
	D3DEnv();
	virtual ~D3DEnv();

protected:
	virtual HWND GetD3DWnd();
	virtual IDirect3D9* GetD3D();
	virtual HRESULT initD3D(UINT winW, UINT winH);

	static LRESULT CALLBACK D3DWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	static ATOM RegisterWndClass(HINSTANCE hInstance);
};
