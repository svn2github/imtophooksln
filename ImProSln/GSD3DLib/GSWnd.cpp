#include "stdafx.h"
#include "GSWnd.h"

extern HMODULE GetModule();

GSWnd::GSWnd()
{
	m_hWnd = 0;
}

GSWnd::~GSWnd()
{
	
}
HRESULT GSWnd::_GetWndClassName(WCHAR* wndClassName, UINT szSize)
{
	if (wndClassName == NULL || szSize <= 0)
		return E_FAIL;
	swprintf_s(wndClassName, szSize, L"GSWnd");
	return S_OK;
}
HRESULT GSWnd::_GetWndName(WCHAR* wndName, UINT szSize)
{
	if (wndName == NULL || szSize <= 0)
		return E_FAIL;
	swprintf_s(wndName, szSize, L"GSWnd");
	return S_OK;
}
ATOM GSWnd::_RegisterWndClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;	
	WCHAR wndClassName[MAX_PATH] = {0};
	_GetWndClassName(wndClassName, MAX_PATH);

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style			= CS_HREDRAW | CS_VREDRAW | CS_NOCLOSE;
	wcex.lpfnWndProc	= GSWndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= NULL;
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= NULL;
	wcex.lpszClassName	= wndClassName;
	wcex.hIconSm		= NULL;
	ATOM ret = RegisterClassEx(&wcex);

	return ret;
}

HRESULT GSWnd::_CreateWindow(UINT wndWidth, UINT wndHeight, HWND& hwnd)
{
	WCHAR wndName[MAX_PATH] = {0};
	WCHAR wndClassName[MAX_PATH] = {0};
	_GetWndName(wndName, MAX_PATH);
	_GetWndClassName(wndClassName, MAX_PATH);
	if (wndWidth != 0 && wndWidth != 0)
	{
		hwnd = CreateWindowExW(WS_EX_APPWINDOW, wndClassName, wndName, WS_MINIMIZEBOX| WS_MAXIMIZEBOX |WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT, 0, wndWidth, wndHeight, NULL, NULL, GetModule(), NULL);
	}
	else
	{
		hwnd = CreateWindowExW(WS_EX_APPWINDOW, wndClassName, wndName, WS_MINIMIZEBOX| WS_MAXIMIZEBOX | WS_OVERLAPPEDWINDOW,
				CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, GetModule(), NULL);		
	}
	return S_OK;
}

HRESULT GSWnd::ShowWnd(BOOL bShow)
{
	if (m_hWnd == 0)
	{
		return S_FALSE;
	}
	ShowWindow(m_hWnd, bShow);
	return S_OK;
}
HWND GSWnd::GetHwnd()
{
	return m_hWnd;
}

HRESULT GSWnd::CreateWnd(UINT wndWidth, UINT wndHeight)
{
	HRESULT hr = S_OK;
	if (m_hWnd != 0)
	{
		::DestroyWindow(m_hWnd);
		m_hWnd = 0;
	}
	if (FAILED(this->_RegisterWndClass(GetModule())))
		return E_FAIL;
	if (FAILED(this->_CreateWindow(wndWidth, wndHeight, m_hWnd)))
		return E_FAIL;
	
	return S_OK;
}

LRESULT GSWnd::GSWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HRESULT hr = S_OK;
	switch (message)
	{
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}