#ifndef _HOOKD3D_H
#define _HOOKD3D_H
/*
#include <detours.h>
#include <string.h>
#include <d3dx9.h>
#include "wchar.h"
*/
namespace HookD3D
{
	/*
	LPDIRECT3D9             g_pD3D           = NULL;
	LPDIRECT3DDEVICE9       g_pd3dDevice     = NULL; 

	const UINT RENDER_TARGET_W = 256;
	const UINT RENDER_TARGET_H = 256;

	const long OFFSET_D3D_CREATEDEVICE = 0x40;
	const long OFFSET_D3D_BEGINSCENE = 0x0A4;
	const long OFFSET_D3D_ENDSCENE = 0x0A8;
	const long OFFSET_D3D_PRESENT = 0x44;


	bool DetourFunction(void*& targetAddress, void* hookAddress, WCHAR* funcName);
	bool ReleaseResource();

////////////////////////////////////////////

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
*/
};
#endif
