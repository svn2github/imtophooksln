#pragma once
#include "dshow.h"
#include "Streams.h"
#include <d3dx9.h>
#include <vector>

using namespace std;

class D3DEnv
{
private:
	static ATOM RegisterWndClass(HINSTANCE hInstance);
	static IDirect3DDevice9* CreateD3DDevice(IDirect3D9* pD3D9, HWND hwnd,  UINT rtWidth, UINT rtHeight);
	static HRESULT CreateD3DWindow(UINT winW, UINT winH, HWND& hwnd);
protected:
	static vector<D3DEnv*> m_pAllInstances;
	static IDirect3D9* GetD3D9();
	static HWND GetD3DWnd();
	static IDirect3DDevice9* GetD3DDevice();
public:
	D3DEnv();
	virtual ~D3DEnv();
protected:
	virtual HRESULT initD3D(UINT winW, UINT winH);
	virtual HRESULT ReleaseD3D();
	virtual BOOL IsD3DReady();
	virtual BOOL IsReadyCloseWindow() { return TRUE;};

	static LRESULT CALLBACK D3DWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

};



