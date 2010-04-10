#pragma once
#include "GSD3DBaseClass.h"

class GSWnd : public IGSWnd
{
protected:
	HWND m_hWnd;
protected:
	virtual HRESULT _GetWndClassName(WCHAR* wndClassName, UINT szSize);
	virtual HRESULT _GetWndName(WCHAR* wndName, UINT szSize);
	virtual HRESULT _CreateWindow(UINT wndWidth, UINT wndHeight, HWND& hwnd);
	virtual ATOM _RegisterWndClass(HINSTANCE hInstance);
public:
	GSWnd();
	~GSWnd();
	virtual HRESULT ShowWnd(BOOL bShow);
	virtual HWND GetHwnd();
	virtual HRESULT CreateWnd(UINT wndWidth, UINT wndHeight);

	static LRESULT CALLBACK GSWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};