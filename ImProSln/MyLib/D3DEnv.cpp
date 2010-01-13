#include "D3DEnv.h"
#include <algorithm>
extern HMODULE GetModule();
vector<D3DEnv*> D3DEnv::m_pAllInstances;

D3DEnv::D3DEnv()
{
	m_hWndD3D = NULL;
	m_pD3D = NULL;
	m_pAllInstances.push_back(this);
}

D3DEnv::~D3DEnv()
{
	ReleaseD3D();
	vector<D3DEnv*>::iterator thisIter = find(m_pAllInstances.begin(), m_pAllInstances.end(), this);
	if (thisIter != m_pAllInstances.end())
	{
		m_pAllInstances.erase(thisIter);
	}
}
HRESULT D3DEnv::ReleaseD3D()
{
	if (m_pD3D != NULL)
	{
		m_pD3D->Release();
		m_pD3D = NULL;
	}
	if (m_hWndD3D != 0)
	{
		::CloseWindow(m_hWndD3D);
		m_hWndD3D = 0;
	}
	return S_OK;
}

HWND D3DEnv::GetD3DWnd()
{
	return m_hWndD3D;
}

IDirect3D9* D3DEnv::GetD3D()
{
	return m_pD3D;
}

HRESULT D3DEnv::initD3D(UINT winW = 0, UINT winH = 0)
{
	HRESULT hr = S_FALSE;
	RegisterWndClass(GetModule());
	if (winW != 0 && winH != 0)
	{
		if (m_hWndD3D == 0)
		{
			m_hWndD3D = CreateWindowExW(NULL, L"D3DWnd", L"D3DWnd", WS_EX_TOPMOST |/* WS_POPUP |*/ WS_OVERLAPPEDWINDOW,
				CW_USEDEFAULT, 0, winW, winH, NULL, NULL, GetModule(), NULL);
		}
	}
	else
	{
		if (m_hWndD3D == 0)
		{
			m_hWndD3D = CreateWindowExW(NULL, L"D3DWnd", L"D3DWnd", WS_EX_TOPMOST |/* WS_POPUP |*/ WS_OVERLAPPEDWINDOW,
				CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, GetModule(), NULL);
		}
	}
	if (m_hWndD3D == NULL)
	{
		DWORD err = GetLastError();
		WCHAR str[MAX_PATH];
		swprintf_s(str, MAX_PATH, L"@@@@@ CreateWindow Failed!! in CreateLowDisplay, Error code = %h \n", err);
		OutputDebugStringW(str);

	}	
	ShowWindow(m_hWndD3D, FALSE);


	if (m_pD3D == NULL)
	{
		if( NULL == ( m_pD3D = Direct3DCreate9( D3D_SDK_VERSION ) ) )
		{
			OutputDebugStringW(L"@@@@@ Direct3DCreate9 Failed!! in CreateLowDisplay\n");
			return FALSE;
		}
	}
	return hr;
}


LRESULT D3DEnv::D3DWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int i = 0;
	switch (message)
	{
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

ATOM D3DEnv::RegisterWndClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= D3DWndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= NULL;
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= NULL;
	wcex.lpszClassName	= L"D3DWnd";
	wcex.hIconSm		= NULL;
	ATOM ret = RegisterClassEx(&wcex);

	return ret;
}