#include "stdafx.h"
#include "HookD3D.h"

using namespace HookD3D;
namespace HookD3D
{
/*
bool ReleaseHookD3D()
{

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
*/
};