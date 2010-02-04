#include "D3DEnv.h"
#include <algorithm>
extern HMODULE GetModule();
vector<D3DEnv*> D3DEnv::m_pAllInstances;

IDirect3D9* g_pD3D = NULL;
HWND		g_hWndD3D = 0;
IDirect3DDevice9* g_pD3DDevice9 = NULL;
extern HMODULE GetModule();

D3DEnv::D3DEnv()
{
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
	if (m_pAllInstances.size() == 0 && g_hWndD3D != 0)
	{
		::DestroyWindow(g_hWndD3D);
		g_hWndD3D = 0;
	}
}
HRESULT D3DEnv::ReleaseD3D()
{
	return S_OK;
}
BOOL D3DEnv::IsD3DReady()
{
	return TRUE;
}

HWND D3DEnv::GetD3DWnd()
{
	if (g_hWndD3D == 0)
	{
		RegisterWndClass(GetModule());
		CreateD3DWindow(0, 0, g_hWndD3D);
	}
	return g_hWndD3D;
}
IDirect3DDevice9* D3DEnv::GetD3DDevice()
{
	if (g_pD3DDevice9 == NULL)
	{
		g_pD3DDevice9 = CreateD3DDevice(GetD3D9(), GetD3DWnd(), 0, 0);
	}
	return g_pD3DDevice9;
}

HRESULT D3DEnv::initD3D(UINT winW = 0, UINT winH = 0)
{
	return S_OK;
}
IDirect3D9* D3DEnv::GetD3D9()
{
	if (g_pD3D == NULL)
	{
		g_pD3D = Direct3DCreate9( D3D_SDK_VERSION );
	}
	return g_pD3D;
}

LRESULT D3DEnv::D3DWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
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

	wcex.style			= CS_HREDRAW | CS_VREDRAW | CS_NOCLOSE;
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


HRESULT D3DEnv::CreateD3DWindow(UINT winW, UINT winH, HWND& hwnd)
{
	if (winW != 0 && winH != 0)
	{
		if (hwnd == 0)
		{
			hwnd = CreateWindowExW(WS_EX_APPWINDOW, L"D3DWnd", L"D3DWnd", WS_OVERLAPPEDWINDOW,
				CW_USEDEFAULT, 0, winW, winH, NULL, NULL, GetModule(), NULL);
			ShowWindow(hwnd, FALSE);
		}
	}
	else
	{
		if (hwnd == 0)
		{
			hwnd = CreateWindowExW(WS_EX_APPWINDOW, L"D3DWnd", L"D3DWnd", WS_OVERLAPPEDWINDOW,
				CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, GetModule(), NULL);
			ShowWindow(hwnd, FALSE);
		}
	}
	return S_OK;
}

IDirect3DDevice9* D3DEnv::CreateD3DDevice(IDirect3D9* pD3D9, HWND hwnd,  UINT rtWidth, UINT rtHeight)
{
	if (pD3D9 == NULL)
	{
		return FALSE;
	}
	IDirect3DDevice9* pDevice = NULL;
	// Set up the structure used to create the D3DDevice. Since we are now
	// using more complex geometry, we will create a device with a zbuffer.
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory( &d3dpp, sizeof(d3dpp) );
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	int screenW, screenH;
	if (rtWidth == 0 || rtHeight == 0)
	{
		HDC dc = GetDC(hwnd);
		screenW = GetDeviceCaps(dc, HORZRES);
		screenH = GetDeviceCaps(dc, VERTRES);
	}
	else
	{
		screenW = rtWidth;
		screenH = rtHeight;
	}
	d3dpp.BackBufferWidth = screenW;
	d3dpp.BackBufferHeight = screenH;

	d3dpp.EnableAutoDepthStencil = TRUE;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
	d3dpp.Flags |= D3DPRESENTFLAG_LOCKABLE_BACKBUFFER;

	// Create the D3DDevice
	if( FAILED( pD3D9->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL,  hwnd,
		D3DCREATE_HARDWARE_VERTEXPROCESSING | D3DCREATE_DISABLE_DRIVER_MANAGEMENT_EX, &d3dpp, &pDevice )))
	{
		OutputDebugStringW(L"@@@@ CreateDevice Failed!! in CreateD3DDevice() \n");
		return FALSE;
	}
	D3DCAPS9 caps;
	pDevice->GetDeviceCaps(&caps);
	if (caps.TextureCaps & D3DPTEXTURECAPS_NONPOW2CONDITIONAL)
	{
		int powerof2Width = 1;
		int powerof2Height = 1;
		while (powerof2Width < screenW)
		{
			powerof2Width *= 2;
		}
		while (powerof2Height < screenH)
		{
			powerof2Height *= 2;
		}
		d3dpp.BackBufferWidth = powerof2Width;
		d3dpp.BackBufferHeight = powerof2Height;
		pDevice->Release();
		pDevice = NULL;
		if( FAILED( pD3D9->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hwnd,
			D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dpp, &pDevice )))
		{
			OutputDebugStringW(L"@@@@ CreateDevice Failed!! in MS3DDisplay::InitDevice() \n");
			return FALSE;
		}
	}

	// Turn on the zbuffer
	pDevice->SetRenderState( D3DRS_ZENABLE, TRUE );
	// Turn on ambient lighting 
	pDevice->SetRenderState( D3DRS_AMBIENT, 0xffffffff );
	pDevice->SetRenderState( D3DRS_CULLMODE, D3DCULL_CW);

	pDevice->SetTextureStageState(0, D3DTSS_CONSTANT, 0xfffffffff );
	pDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);
	pDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_CONSTANT);
	pDevice->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_TEXTURE);
	pDevice->SetTextureStageState(1, D3DTSS_COLOROP, D3DTOP_DISABLE);

	return pDevice;
}