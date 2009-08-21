// Hook.cpp : 定義 DLL 應用程式的進入點。
//

#include "stdafx.h"

#include "Hook.h"
#include "wchar.h"
#include "Psapi.h"
#include <string.h>
#include <d3dx9.h>
#include "MSSD3DClass.h"
#include <detours.h>

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

#define HOOKED_SETHOOKCLIENT_MSG L"HOOKED_RESETWNDPROC_MSG-49353183-2419-4f6a-AC41-C663EFDCEB1F"
HMODULE g_hModule = NULL;
LONG_PTR g_orgWndProc = NULL;
UINT HOOKED_WNDDESTORY = 0;
UINT HOOKED_DOHOOK_CREATEDEVICE = 0;
UINT HOOKED_SETHOOKCLIENT = 0;
WCHAR szHWndName[MAX_PATH] = L"ImHighResolution";

BOOL (WINAPI* pShowWindow)(HWND hWnd, int nCmdShow) = ShowWindow;
BOOL WINAPI pHookShowWindow(HWND hWnd, int nCmdShow);
/////////////for use D3D Display///////////////////
IDirect3DTexture9*      g_pRenderTarget = NULL;
IDirect3DSurface9*      g_pBackupRenderTarget = NULL;
MS3DPlane* g_pDisplayPlane = NULL;


/////////////////////////////////////////////
bool DetourFunction(void*& targetAddress, void* hookAddress, WCHAR* funcName);
bool ReleaseResource();
bool DetourAllGDI();
bool HookWndProc(HWND hwnd, LONG WndProc, LONG_PTR& orgWndProc);
bool UnHookWndProc(HWND hwnd);
////////////////////////////////////////////
LRESULT CALLBACK HookWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam,LPARAM lParam);
LRESULT CALLBACK HighResolutionWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
////////////for hook GDI Drawing command/////////////////
HWND g_HighWnd = NULL;
BOOL (WINAPI* pRealBitBlt)(HDC, int, int, int, int, HDC, int, int, DWORD) = BitBlt;
BOOL WINAPI pHookBitBlt(HDC, int, int, int, int, HDC, int, int, DWORD);

HDC (WINAPI* pRealBeginPaint)(HWND hWnd, LPPAINTSTRUCT lpPaint) = BeginPaint;
HDC WINAPI pHookBeginPaint(HWND hWnd, LPPAINTSTRUCT lpPaint);

BOOL (WINAPI* pRealEndPaint)(HWND hWnd, CONST PAINTSTRUCT *lpPaint) = EndPaint;
BOOL WINAPI pHookEndPaint(HWND hWnd, CONST PAINTSTRUCT *lpPaint);
/*
 AlphaBlend






 */
/////////////////////


ATOM RegisterWndClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= HighResolutionWndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= NULL;
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= NULL;
	wcex.lpszClassName	= szHWndName;
	wcex.hIconSm		= NULL;
	ATOM ret = RegisterClassEx(&wcex);
	return ret;
}

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
		HOOKED_SETHOOKCLIENT = RegisterWindowMessage(HOOKED_SETHOOKCLIENT_MSG);
		HOOKED_DOHOOK_CREATEDEVICE = RegisterWindowMessage(HOOKED_DOHOOKCREATEDEVICE_MSG);
		OutputDebugStringW(L"@@@@ DLL_PROCESS_ATTACH!!\n");
		if (g_hHookServerProcID == 0)
		{
			DWORD err = GetLastError();
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
			swprintf_s(str, L"@@@@ HookClient: %Xh \n", GetCurrentProcessId());
			OutputDebugStringW(str);

			RegisterWndClass(hModule);
			g_HighWnd = CreateWindowW(szHWndName, L"High Resolution",WS_OVERLAPPEDWINDOW | WS_SIZEBOX | WS_MINIMIZEBOX,
				CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hModule, NULL);
			ShowWindow(g_HighWnd, TRUE);
			DetourAllGDI();
			DetourFunction((void*&)pShowWindow, pHookShowWindow, L"ShowWindow");
			
		}
		else
		{
			WCHAR strout[MAX_PATH] = {0};
			swprintf_s(strout, MAX_PATH, L"@@@@  Unexpected process loaded hook.dll   procID = %Xh, clientProcID = %Xh \n", GetCurrentProcessId(), g_hHookClientProcID );
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

BOOL CALLBACK RepaintFuncCallback(HWND hWnd, LPARAM lparm)
{
	WCHAR str[MAX_PATH];
	swprintf_s(str, MAX_PATH, L"@@@@ Repaint Callback Wnd: %Xh", hWnd);
	OutputDebugStringW(str);
	RedrawWindow(hWnd, NULL, NULL, RDW_FRAME );
	
	return TRUE;
}
bool RepaintClientWindow()
{
	if (g_hHookClientWnd == NULL)
	{
		return false;
	}
	RedrawWindow(g_hHookClientWnd, NULL, NULL, RDW_FRAME );
	EnumChildWindows(g_hHookClientWnd, RepaintFuncCallback, NULL);
	return true;
}
bool _SetHookClient(HWND hClient)
{
	UnHookWndProc(g_hHookClientWnd);
	g_hHookClientWnd = hClient;
	HookWndProc(g_hHookClientWnd, (LONG)HookWindowProc, g_orgWndProc);
	RepaintClientWindow();
	return true;
}

HOOK_API bool HOOKAPI::SetHookClient(HWND hClient)
{
	SendMessageW(g_hHookClientWnd, HOOKED_SETHOOKCLIENT, (WPARAM)hClient, NULL);
	return true;
}
HOOK_API bool HOOKAPI::GetHookClient(HWND& clientWnd)
{
	clientWnd = g_hHookClientWnd;
	return true;
}
bool UnHookWndProc(HWND hwnd)
{
	if( g_orgWndProc == NULL && hwnd == NULL)
		return false; 
	OutputDebugStringW(L"@@@@ UnHookWndProc called!!\n");
	LONG_PTR ret = SetWindowLongPtrW(hwnd, GWLP_WNDPROC, (LONG)g_orgWndProc);
	if (ret != NULL)
	{
		return true;
	}
	DWORD err = GetLastError();
	WCHAR str[MAX_PATH];
	swprintf_s(str,MAX_PATH, L"@@@@ UnHookWndProc failed!!\n @@@@ Error Code: %d \n ", err);
	OutputDebugStringW(str);

	return false;
}
bool HookWndProc(HWND hwnd, LONG WndProc, LONG_PTR& orgWndProc)
{	
	if( orgWndProc != NULL && hwnd == NULL)
		return 0; 
	OutputDebugStringW(L"@@@@ HookWndProc called!!\n");
	orgWndProc = SetWindowLongPtrW(hwnd, GWLP_WNDPROC, (LONG)WndProc);
	if (orgWndProc != 0)
	{
		return true;
	}
	DWORD err = GetLastError();
	WCHAR str[MAX_PATH];
	swprintf_s(str,MAX_PATH, L"@@@@ HookWndProc failed!!\n @@@@ Error Code: %d \n @@@@orgWndProc: %d \n", err, orgWndProc);
	OutputDebugStringW(str);

	return false;
}


bool ReleaseResource()
{
	if (g_pBackupRenderTarget != NULL)
	{
		g_pBackupRenderTarget->Release();
		g_pBackupRenderTarget = NULL;
	}
	return true;

}

bool DetourAllGDI()
{
	DetourFunction((void*&)pRealBitBlt, pHookBitBlt, L"GDI::BitBlt");
	DetourFunction((void*&)pRealBeginPaint, pHookBeginPaint, L"GDI::BeginPaint");
	DetourFunction((void*&)pRealEndPaint, pHookEndPaint, L"GDI::EndPaint");
	
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


// For the projection matrix, we set up a perspective transform (which
// transforms geometry from 3D view space to 2D viewport space, with
// a perspective divide making objects smaller in the distance). To build
// a perpsective transform, we need the field of view (1/4 pi is common),
// the aspect ratio, and the near and far clipping planes (which define at
// what distances geometry should be no longer be rendered).


LRESULT CALLBACK HighResolutionWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// 剖析功能表選取項目:
		switch (wmId)
		{

		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: 在此加入任何繪圖程式碼...
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

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
		else if (uMsg == HOOKED_SETHOOKCLIENT)
		{
			OutputDebugStringW(L"@@@@ HOOKED_RESETWNDPROC_MSG!!\n");
			_SetHookClient((HWND)wParam);
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
			swprintf_s(str,MAX_PATH, L"@@@@ g_hHookServerWnd = %Xh \n", hWnd);
			OutputDebugStringW(str);
		}
	}
	else if (GetCurrentProcessId() == g_hHookClientProcID && g_hHookClientProcID != 0)
	{
		if (g_hHookClientWnd == NULL)
		{
			g_hHookClientWnd = hWnd;
			WCHAR str[MAX_PATH];
			swprintf_s(str,MAX_PATH, L"@@@@ g_hHookClientWnd = %Xh \n", hWnd);
			OutputDebugStringW(str);
			HookWndProc(g_hHookClientWnd, (LONG)HookWindowProc, g_orgWndProc);
		}
	}
	return ret;
}

BOOL WINAPI pHookBitBlt(HDC hdc, int x, int y, int cx, int cy, HDC hdcSrc, int x1, int y1, DWORD rop)
{
	//OutputDebugStringW(L"@@@@ pHookBitBlt called!!\n");
	BOOL ret = pRealBitBlt(hdc, x, y, cx, cy, hdcSrc, x1, y1, rop);
	if (g_HighWnd != NULL && g_hHookClientWnd != NULL)
	{
		HWND hwnd = WindowFromDC(hdc);

		HDC clientDC = GetDC(g_hHookClientWnd);
		POINT pt;  pt.x = x; pt.y = y;
		
		MapWindowPoints(hwnd,g_hHookClientWnd, &pt,1);
		StretchBlt(GetDC(g_HighWnd), pt.x*2, pt.y*2, cx*2, cy*2, hdcSrc, x1, y1, cx, cy, rop);

		//WCHAR str[MAX_PATH];
		//swprintf(str, MAX_PATH,L"@@@@ from (%3d, %3d) to (%3d, %3d) \n", x, y, pt.x, pt.y);
		//OutputDebugStringW(str);
		//pRealBitBlt(GetDC(g_HighWnd), x, y, cx*2, cy*2, hdcSrc, x1, y1, rop);
	}
	return TRUE;
}

HDC WINAPI pHookBeginPaint(HWND hWnd, LPPAINTSTRUCT lpPaint)
{
	HDC ret = pRealBeginPaint(hWnd, lpPaint);
	//pRealBeginPaint(g_HighWnd, lpPaint);
	return ret;
}

BOOL WINAPI pHookEndPaint(HWND hWnd, CONST PAINTSTRUCT *lpPaint)
{
	BOOL ret = pRealEndPaint(hWnd, lpPaint);
	//pRealEndPaint(g_HighWnd, lpPaint);
	return ret;
}