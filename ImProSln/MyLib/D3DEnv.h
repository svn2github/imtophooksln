#pragma once
#include "dshow.h"
#include "Streams.h"
#include <d3dx9.h>
#include <vector>
using namespace std;
class D3DEnv
{
protected:
	static vector<D3DEnv*> m_pAllInstances;

	HWND			 m_hWndD3D ;
	IDirect3D9*      m_pD3D;
public:
	D3DEnv();
	virtual ~D3DEnv();

protected:
	virtual HWND GetD3DWnd();
	virtual IDirect3D9* GetD3D();
	virtual HRESULT initD3D(UINT winW, UINT winH);
	virtual HRESULT CreateD3DWindow(UINT winW, UINT winH);
	virtual HRESULT ReleaseD3D();
	virtual BOOL IsD3DReady();
	virtual BOOL IsReadyCloseWindow() { return TRUE;};

	static LRESULT CALLBACK D3DWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	virtual ATOM RegisterWndClass(HINSTANCE hInstance);
};

