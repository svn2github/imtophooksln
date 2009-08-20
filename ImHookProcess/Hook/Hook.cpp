// Hook.cpp : 定義 DLL 應用程式的進入點。
//

#include "stdafx.h"
#include "Hook.h"
#include <detours.h>
#include "wchar.h"
#include "Psapi.h"
#include <string.h>
#include <d3dx9.h>
#include "MSSD3DClass.h"


#pragma comment(lib, "psapi")

////////////////////Share Data Segation///////////
#pragma data_seg(".MuscleSeg")
HWND g_hHookServerWnd = NULL;
DWORD g_hHookServerProcID = 0;

HWND g_hHookClientWnd = NULL;
DWORD g_hHookClientProcID = 0;

#pragma data_seg()
#pragma comment(linker, "/section:.MuscleSeg,rws")
//////////////////////////////////////////////////
#ifdef _MANAGEDbeginSce
#pragma managed(push, off)
#endif
//////////////////////////////////////////
HMODULE g_hModule = NULL;
LONG_PTR g_orgWndProc = NULL;
UINT HOOKED_WNDDESTORY = 0;
UINT HOOKED_DOHOOK_CREATEDEVICE = 0;

/////////////for hook D3D///////////////////
LPDIRECT3D9             g_pD3D           = NULL;
LPDIRECT3DDEVICE9       g_pd3dDevice     = NULL; 
IDirect3DTexture9*      g_pRenderTarget = NULL;
IDirect3DSurface9*      g_pBackupRenderTarget = NULL;

MS3DPlane* g_pDisplayPlane = NULL;

const UINT RENDER_TARGET_W = 256;
const UINT RENDER_TARGET_H = 256;

const long OFFSET_D3D_CREATEDEVICE = 0x40;
const long OFFSET_D3D_BEGINSCENE = 0x0A4;
const long OFFSET_D3D_ENDSCENE = 0x0A8;
const long OFFSET_D3D_PRESENT = 0x44;
bool DetourFunction(void*& targetAddress, void* hookAddress, WCHAR* funcName);
bool ReleaseResource();
bool myRender(IDirect3DDevice9* pDevice);
////////////////////////////////////////////
LRESULT CALLBACK HookWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam,LPARAM lParam);


////////////////////////////////////////////
BOOL (WINAPI* pShowWindow)(HWND hWnd, int nCmdShow) = ShowWindow;
BOOL WINAPI pHookShowWindow(HWND hWnd, int nCmdShow);
IDirect3D9* (WINAPI* pDirect3DCreate9)(UINT SDKVersion) = Direct3DCreate9;
IDirect3D9* WINAPI pHookDirect3DCreate9(UINT SDKVersion);

HRESULT (WINAPI* pRealD3DCreateDevice)(void* _THIS, UINT Adapter,D3DDEVTYPE DeviceType,HWND hFocusWindow,DWORD BehaviorFlags,D3DPRESENT_PARAMETERS* pPresentationParameters,IDirect3DDevice9** ppReturnedDeviceInterface) = NULL;
HRESULT WINAPI pHookD3DCreateDevice(void* _THIS, UINT Adapter,D3DDEVTYPE DeviceType,HWND hFocusWindow,DWORD BehaviorFlags,D3DPRESENT_PARAMETERS* pPresentationParameters,IDirect3DDevice9** ppReturnedDeviceInterface);

HRESULT (WINAPI* pRealBeginScene)(void* _THIS) = NULL;
HRESULT WINAPI pHookBeginScene(void* _THIS);

HRESULT (WINAPI* pRealEndScene)(void*_THIS) = NULL;
HRESULT WINAPI pHookEndScene(void* _THIS);


HRESULT (WINAPI* pRealPresent)(void* _THIS, CONST RECT* ,CONST RECT* ,HWND ,CONST RGNDATA* ) = NULL;
HRESULT WINAPI pHookPresent(void* _THIS, CONST RECT* ,CONST RECT* ,HWND ,CONST RGNDATA* );
////////////////////////////////////////////

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	g_hModule = hModule;

	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		HOOKED_WNDDESTORY = RegisterWindowMessage(HOOKED_WNDDESTORY_MSG);
		HOOKED_DOHOOK_CREATEDEVICE = RegisterWindowMessage(HOOKED_DOHOOKCREATEDEVICE_MSG);
		OutputDebugStringW(L"@@@@ DLL_PROCESS_ATTACH!!\n");
		if (g_hHookServerProcID == 0)
		{
			g_hHookServerProcID = GetCurrentProcessId();
			WCHAR str[MAX_PATH] = {0};
			swprintf_s(str, L"@@@@ HookServer: %d \n", GetCurrentProcessId());
			OutputDebugStringW(str);

			DetourFunction((void*&)pShowWindow, pHookShowWindow, L"ShowWindow");
		}
		else if (( GetCurrentProcessId() != g_hHookServerProcID) && g_hHookClientProcID == 0)
		{
			g_hHookClientProcID = GetCurrentProcessId();	
			WCHAR str[MAX_PATH] = {0};
			swprintf_s(str, L"@@@@ HookClient: %d \n", GetCurrentProcessId());
			OutputDebugStringW(str);

			DetourFunction((void*&)pShowWindow, pHookShowWindow, L"ShowWindow");
			DetourFunction((void*&)pDirect3DCreate9, pHookDirect3DCreate9, L"Direct3DCreate9");
		}
		else
		{
			WCHAR strout[MAX_PATH] = {0};
			swprintf_s(strout, MAX_PATH, L"@@@@  Unexpected process loaded hook.dll    procID = %d \n", GetCurrentProcessId() );
			OutputDebugStringW(strout);
		}
		break;
	case DLL_THREAD_ATTACH:
		
		break;
	case DLL_THREAD_DETACH:
		
		break;
	case DLL_PROCESS_DETACH:
		OutputDebugStringW(L"@@@@ DLL_PROCESS_DETACH!!\n");
		if ( g_hHookServerProcID == GetCurrentProcessId())
		{
			g_hHookServerProcID = 0;
			g_hHookServerWnd = NULL;

			WCHAR str[MAX_PATH] = {0};
			swprintf_s(str, L"@@@@ HookServer = NULL");
			OutputDebugStringW(str);
		}
		else if(g_hHookClientProcID == GetCurrentProcessId())
		{
			g_hHookClientProcID = 0;
			g_hHookClientWnd = NULL;

			WCHAR str[MAX_PATH] = {0};
			swprintf_s(str, L"@@@@ HookClient = NULL");
			OutputDebugStringW(str);
		}
		ReleaseResource();
		break;
	}
	
	return TRUE;
}

#ifdef _MANAGED
#pragma managed(pop)
#endif



HOOK_API int HOOKAPI::SetHookServerAndClient(HWND hServer, HWND hClient)
{
	OutputDebugStringW(L"@@@@  setHookServerAndClient  ---->\n");
	if (hServer == NULL || hClient == NULL)
	{
		return 1;
	}
	g_hHookServerWnd = hServer;
	g_hHookClientWnd = hClient;
	
	OutputDebugStringW(L"@@@@  setHookServerAndClient  <----\n");
	return 0;
}
HOOK_API bool HOOKAPI::GetHookedWnd(HWND& serverWnd, HWND& clientWnd)
{
	serverWnd = g_hHookServerWnd;
	clientWnd = g_hHookClientWnd;
	return true;
}

bool SetMsgHook()
{	
	if( g_orgWndProc != NULL && g_hHookClientWnd == NULL)
		return 0; 
	OutputDebugStringW(L"@@@@ setMsgHook called!!\n");
	g_orgWndProc = SetWindowLongPtrW(g_hHookClientWnd, GWLP_WNDPROC, (LONG)HookWindowProc);
	if (g_orgWndProc != 0)
	{
		return 0;
	}
	DWORD err = GetLastError();
	WCHAR str[MAX_PATH];
	swprintf_s(str,MAX_PATH, L"@@@@ setMsgHook failed!!\n @@@@ Error Code: %d \n @@@@orgWndProc: %d \n", err, g_orgWndProc);
	OutputDebugStringW(str);

	return 1;
}
bool GetMyRenderTarget(IDirect3DSurface9*& pTarget)
{
	if (g_pRenderTarget != NULL)
	{
		if (FAILED(g_pRenderTarget->GetSurfaceLevel(0, &pTarget)))
			return false;
		//pTarget = g_pRenderTarget;
		return true;
	}
	if (g_pd3dDevice == NULL)
	{
		return false;
	}
	HRESULT hr;
	//hr = g_pd3dDevice->CreateRenderTarget(RENDER_TARGET_W, RENDER_TARGET_H, D3DFMT_A8R8G8B8, D3DMULTISAMPLE_NONE, 0,
	//	TRUE, &g_pRenderTarget, NULL);
	hr = D3DXCreateTexture(g_pd3dDevice, RENDER_TARGET_W, RENDER_TARGET_H, 1, D3DUSAGE_RENDERTARGET,
		D3DFMT_A8R8G8B8, D3DPOOL_DEFAULT, &g_pRenderTarget);
	if (FAILED(hr))
		return false;
	if (FAILED(g_pRenderTarget->GetSurfaceLevel(0, &pTarget)))
		return false;
	return true;
}
bool ReleaseResource()
{
	/*
	if (g_pRenderTarget != NULL)
	{
		g_pRenderTarget->Release();
		g_pRenderTarget = NULL;
	}
	*/
	if (g_pDisplayPlane != NULL)
	{
		delete g_pDisplayPlane;
		g_pDisplayPlane = NULL;
	}
	if (g_pBackupRenderTarget != NULL)
	{
		g_pBackupRenderTarget->Release();
		g_pBackupRenderTarget = NULL;
	}
	if(g_pd3dDevice != NULL)
	{
		g_pd3dDevice->Release();
		g_pd3dDevice = NULL;
	}
	if (g_pD3D != NULL)
	{
		g_pD3D->Release();
		g_pd3dDevice = NULL;
	}
	return true;
}
bool DetourFunction(void*& targetAddress, void* hookAddress, WCHAR* funcName)
{
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach(&(PVOID&)targetAddress,  hookAddress);
	WCHAR str[MAX_PATH] = {0};
	if(DetourTransactionCommit() == NO_ERROR)
	{
		swprintf_s(str, MAX_PATH, L"@@@@ %s detoured successfully!!\n", funcName);
		OutputDebugStringW(str);
		return true;
	}
	else
	{
		swprintf_s(str, MAX_PATH, L"@@@@ %s detoured failed!!\n", funcName);
		OutputDebugStringW(str);
		return false;
	}
}

void SetupViewPort()
{
	D3DXVECTOR3 vEyePt( 0.0f, 0.0f,-5.0f );
	D3DXVECTOR3 vLookatPt( 0.0f, 0.0f, 0.0f );
	D3DXVECTOR3 vUpVec( 0.0f, 1.0f, 0.0f );
	D3DXMATRIXA16 matView;
	D3DXMatrixLookAtLH( &matView, &vEyePt, &vLookatPt, &vUpVec );
	g_pd3dDevice->SetTransform( D3DTS_VIEW, &matView );
	D3DXMATRIXA16 matProj;
	D3DXMatrixPerspectiveFovLH( &matProj, D3DX_PI/4, 1.0f, 1.0f, 100.0f );
	g_pd3dDevice->SetTransform( D3DTS_PROJECTION, &matProj );
}
// For the projection matrix, we set up a perspective transform (which
// transforms geometry from 3D view space to 2D viewport space, with
// a perspective divide making objects smaller in the distance). To build
// a perpsective transform, we need the field of view (1/4 pi is common),
// the aspect ratio, and the near and far clipping planes (which define at
// what distances geometry should be no longer be rendered).


LRESULT CALLBACK HookWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam,LPARAM lParam)
{
	
	if (hwnd == g_hHookClientWnd && g_hHookClientWnd != 0)
	{
		if (uMsg == WM_CLOSE)
		{ 
			OutputDebugStringW(L"@@@@ WM_HookCLOSE!!\n");
			SendMessage(g_hHookServerWnd, HOOKED_WNDDESTORY, 0, 0);
		}
		else if(uMsg == WM_DESTROY)
		{
			OutputDebugStringW(L"@@@@ WM_HookDESTORY!!\n");
			SendMessage(g_hHookServerWnd, HOOKED_WNDDESTORY, 0, 0);
		}
	}
	LRESULT lr = CallWindowProcW((WNDPROC)g_orgWndProc,hwnd, uMsg, wParam, lParam );

	return lr;
}

BOOL WINAPI pHookShowWindow(HWND hWnd, int nCmdShow)
{
	BOOL ret = pShowWindow(hWnd, nCmdShow);
	if (GetCurrentProcessId() == g_hHookServerProcID && g_hHookServerProcID != 0)
	{
		if (g_hHookServerWnd == NULL)
		{
			g_hHookServerWnd = hWnd;
			WCHAR str[MAX_PATH];
			swprintf_s(str,MAX_PATH, L"@@@@ g_hHookServerWnd = %d \n", hWnd);
			OutputDebugStringW(str);
		}
	}
	else if (GetCurrentProcessId() == g_hHookClientProcID && g_hHookClientProcID != 0)
	{
		if (g_hHookClientWnd == NULL)
		{
			g_hHookClientWnd = hWnd;
			WCHAR str[MAX_PATH];
			swprintf_s(str,MAX_PATH, L"@@@@ g_hHookClientWnd = %d \n", hWnd);
			OutputDebugStringW(str);
			SetMsgHook();
		}
	}
	return ret;
}

IDirect3D9* WINAPI pHookDirect3DCreate9(UINT SDKVersion)
{
	IDirect3D9* ret = pDirect3DCreate9(SDKVersion);
	if(ret != NULL)
	{
		g_pD3D = ret;
		g_pD3D->AddRef();
		WCHAR str[MAX_PATH];
		swprintf_s(str, MAX_PATH, L"@@@@ D3D Hooked!! g_pD3D = %d \n", g_pD3D); 
		OutputDebugStringW(str);
		if (pRealD3DCreateDevice == NULL)
		{
			void * pvtbl;
			memcpy(&pvtbl, g_pD3D, sizeof(pvtbl));
			pRealD3DCreateDevice = (HRESULT (__stdcall*)(void*, UINT, D3DDEVTYPE,HWND,DWORD,D3DPRESENT_PARAMETERS*, IDirect3DDevice9**))  *(DWORD*)((PBYTE)pvtbl + OFFSET_D3D_CREATEDEVICE);		
			swprintf_s(str, MAX_PATH, L"@@@@ pvtble = %Xh,\n@@@@ OFFSET_D3D_CREATEDEVICE = %Xh \n @@@@ g_pD3DCreateDevice_Address = %Xh \n", (DWORD)pvtbl,  OFFSET_D3D_CREATEDEVICE, pRealD3DCreateDevice);
			OutputDebugStringW(str);			
			DetourFunction((void*&)pRealD3DCreateDevice, pHookD3DCreateDevice, L"D3DCreateDevice");
		}
	}
	return ret;
}
HRESULT WINAPI pHookD3DCreateDevice(void* _THIS, UINT Adapter,D3DDEVTYPE DeviceType,HWND hFocusWindow,DWORD BehaviorFlags,D3DPRESENT_PARAMETERS* pPresentationParameters,IDirect3DDevice9** ppReturnedDeviceInterface)
{
	OutputDebugStringW(L"@@@@ HookD3DCreateDevice called!!\n");	
	HRESULT ret = pRealD3DCreateDevice(_THIS, Adapter, DeviceType, hFocusWindow, BehaviorFlags, pPresentationParameters,ppReturnedDeviceInterface);
	
	if (ret == S_OK)
	{
		g_pd3dDevice = *ppReturnedDeviceInterface;
		g_pd3dDevice->AddRef();
		WCHAR str[MAX_PATH];
		swprintf_s(str, MAX_PATH, L"@@@@ D3D Hooked!! g_pd3dDevice = %d \n", g_pd3dDevice);
		OutputDebugStringW(str);
		if (pRealBeginScene == NULL && pRealEndScene == NULL && pRealPresent == NULL)
		{
			void * pvtbl;
			memcpy(&pvtbl, g_pd3dDevice, sizeof(pvtbl));
			pRealBeginScene = (HRESULT (__stdcall*)(void*))  *(DWORD*)((PBYTE)pvtbl + OFFSET_D3D_BEGINSCENE);		
			DetourFunction((void*&)pRealBeginScene,pHookBeginScene, L"D3DBeginScene");

			pRealEndScene =  (HRESULT (__stdcall*)(void*))  *(DWORD*)((PBYTE)pvtbl + OFFSET_D3D_ENDSCENE);
			DetourFunction((void*&)pRealEndScene, pHookEndScene, L"D3DEndScene");

			pRealPresent = (HRESULT (__stdcall*)(void* , CONST RECT* ,CONST RECT* ,HWND ,CONST RGNDATA* ))*(DWORD*)((PBYTE)pvtbl + OFFSET_D3D_PRESENT);
			DetourFunction((void*&)pRealPresent, pHookPresent, L"D3DPresent");
		}
	}
	else
	{
		WCHAR str[MAX_PATH];
		swprintf_s(str, MAX_PATH, L"@@@@ g_pD3D->CreateDevice Failed!! hr = %d \n", ret);
		OutputDebugStringW(str);
	}
	return ret;
}

HRESULT WINAPI pHookBeginScene(void* _THIS)
{
	//OutputDebugStringW(L"@@@@ pHookBeginScene called!!\n");	

	LPDIRECT3DDEVICE9 self = (LPDIRECT3DDEVICE9)_THIS;
	IDirect3DSurface9* pTarget = NULL;
	HRESULT hr;
	if (!GetMyRenderTarget(pTarget))
	{
		OutputDebugStringW(L"@@@@ self->GetMyRenderTarget failed in pHookBeginScene()!! \n");
		hr = pRealBeginScene(_THIS);
		return hr;
	}
	if (g_pBackupRenderTarget != NULL)
	{
		OutputDebugStringW(L"@@@@ another BeginScene called!! \n");
		hr = pRealBeginScene(_THIS);
		return hr;
	}
	if (FAILED(self->GetRenderTarget(0, &g_pBackupRenderTarget)))
	{
		OutputDebugStringW(L"@@@@ self->GetRenderTarget failed in pHookBeginScene()!! \n");
		hr = pRealBeginScene(_THIS);
		return hr;
	}
	HRESULT hr2;
	hr2 = self->SetRenderTarget(0, pTarget);
	if (FAILED(hr2))
	{
		WCHAR str[MAX_PATH];
		swprintf_s(str, MAX_PATH, L"@@@@ self->SetRenderTarget failed in pHookBeginScene()!! Error code: %d \n", hr2);
		OutputDebugStringW(str);
		swprintf_s(str, MAX_PATH, L"@@@@ pTarget = %Xh \n", pTarget);
		OutputDebugStringW(str);
	}
	self->Clear( 0, NULL, D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER, 
		D3DCOLOR_XRGB(0,0,255), 1.0f, 0 );
	hr = pRealBeginScene(_THIS);
	return hr;
}

HRESULT WINAPI pHookEndScene(void* _THIS)
{
	//OutputDebugStringW(L"@@@@ pHookEndScene called!!\n");	
	HRESULT hr = pRealEndScene(_THIS);
	LPDIRECT3DDEVICE9 self = (LPDIRECT3DDEVICE9)_THIS;
	if (g_pBackupRenderTarget != NULL)
	{
		self->SetRenderTarget(0, g_pBackupRenderTarget);
		g_pBackupRenderTarget->Release();
		g_pBackupRenderTarget = NULL;
	}
	return hr;
}
HRESULT WINAPI pHookPresent(void* _THIS, CONST RECT* pSourceRect,CONST RECT* pDestRect,HWND hDestWindowOverride,CONST RGNDATA* pDirtyRegion)
{
	//OutputDebugStringW(L"@@@@ pHookPresent called!!\n");	
	HRESULT hr;
	pRealBeginScene(_THIS);
	myRender((IDirect3DDevice9*)_THIS);
	pRealEndScene(_THIS);
	hr = pRealPresent(_THIS, pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion);
	return hr;
}
bool myRender(IDirect3DDevice9* pDevice)
{
	pDevice->Clear( 0, NULL, D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER, 
		D3DCOLOR_XRGB(128,128,128), 1.0f, 0 );
	if (pDevice == NULL)
	{
		return false;
	}
	if (g_pRenderTarget != NULL)
	{
		if (g_pDisplayPlane == NULL)
		{
			g_pDisplayPlane = new MS3DPlane(g_pd3dDevice);
			g_pDisplayPlane->InitGeometry();
			g_pDisplayPlane->Scale(D3DXVECTOR3(20, 20, 0));
			g_pDisplayPlane->Translate(D3DXVECTOR3(0, 0, 30));
		}
		HRESULT hr2;

		SetupViewPort();
		g_pDisplayPlane->Translate(D3DXVECTOR3(0, 0, -30));
		g_pDisplayPlane->Rotate(D3DXVECTOR3(D3DX_PI/360.0, 0, 0));
		g_pDisplayPlane->Translate(D3DXVECTOR3(0, 0, 30));
		hr2 = pDevice->SetTexture(0, g_pRenderTarget);
		hr2 = pDevice->SetStreamSource(0, g_pDisplayPlane->GetVertexBuffer(), 0, sizeof(MS3DPlane::CUSTOMVERTEX));
		hr2 = pDevice->SetIndices(g_pDisplayPlane->GetIndexBuffer());
		hr2 = pDevice->SetFVF(g_pDisplayPlane->GetVertexFMT());
		hr2 = pDevice->SetTransform(D3DTS_WORLD, &g_pDisplayPlane->GetTransform());
		hr2 = pDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST,0,0, g_pDisplayPlane->GetVertexNumber(),
			0, g_pDisplayPlane->GetPrimitiveNumber());
		hr2 = pDevice->SetTexture(0, NULL);

	}
	return true;
}