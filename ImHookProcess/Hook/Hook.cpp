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

D3DXVECTOR2 g_TTSRegion_L[4] = {D3DXVECTOR2(0,0), D3DXVECTOR2(0, 1), 
						D3DXVECTOR2(1,0), D3DXVECTOR2(1, 1)};
D3DXVECTOR2 g_TTSRegion_H[4] = {D3DXVECTOR2(0,0), D3DXVECTOR2(0, 1), 
						D3DXVECTOR2(1,0), D3DXVECTOR2(1, 1)};
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
UINT HOOKED_ENABLEEDITWARP_LOW = 0;
UINT HOOKED_ENABLEEDITTTS_LOW = 0;
UINT HOOKED_ENABLEEDITWARP_HIGH = 0;
UINT HOOKED_ENABLEEDITTTS_HIGH = 0;
UINT HOOKED_SETTTS_LOW = 0;
UINT HOOKED_SETTTS_HIGH = 0;

WCHAR g_szLWndName[MAX_PATH] = L"ImLowResolution";
WCHAR g_szHWndName[MAX_PATH] = L"ImHighResolution";

BOOL (WINAPI* pShowWindow)(HWND hWnd, int nCmdShow) = ShowWindow;
BOOL WINAPI pHookShowWindow(HWND hWnd, int nCmdShow);

/////////////for use D3D Display///////////////////


IDirect3D9* g_pD3D = NULL;
MS3DDisplay* g_pLowDisplay = NULL;
MS3DDisplay* g_pHighDisplay = NULL;

BOOL CreateLowDisplay(HMODULE hModule);
BOOL CreateHighDisplay(HMODULE hModule);

/////////////////////////////////////////////
bool DetourFunction(void*& targetAddress, void* hookAddress, WCHAR* funcName);
bool ReleaseResource();
bool DetourAllGDI();
bool HookWndProc(HWND hwnd, LONG WndProc, LONG_PTR& orgWndProc);
bool UnHookWndProc(HWND hwnd);
////////////////////////////////////////////
LRESULT CALLBACK HookWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam,LPARAM lParam);
LRESULT CALLBACK LowResolutionWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK HighResolutionWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
////////////for hook GDI Drawing command/////////////////
HWND g_LowWnd = NULL;
HWND g_HighWnd = NULL;
BOOL (WINAPI* pRealBitBlt)(HDC, int, int, int, int, HDC, int, int, DWORD) = BitBlt;
BOOL WINAPI pHookBitBlt(HDC, int, int, int, int, HDC, int, int, DWORD);

HDC (WINAPI* pRealBeginPaint)(HWND hWnd, LPPAINTSTRUCT lpPaint) = BeginPaint;
HDC WINAPI pHookBeginPaint(HWND hWnd, LPPAINTSTRUCT lpPaint);

BOOL (WINAPI* pRealEndPaint)(HWND hWnd, CONST PAINTSTRUCT *lpPaint) = EndPaint;
BOOL WINAPI pHookEndPaint(HWND hWnd, CONST PAINTSTRUCT *lpPaint);
/*
for bitmap

AlphaBlend
ExtFloodFill
FloodFill
GradientFill
PlgBlt
SetDIBColorTable
SetDIBits
SetDIBitsToDevice
SetPixel 
SetPixelV 
SetStretchBltMode 
StretchBlt
StretchDIBits
TransparentBlt

//FillShape
Ellipse
Chord
FillRect
InvertRect
Pie
Polygon
PolyPolygon
Rectangle
RoundRect

//Font
DrawText 
DrawTextEx 
PolyTextOut 
SetTextAlign 
SetTextCharacterExtra 
SetTextColor 
SetTextJustification 
TabbedTextOut
TextOut

//Paint
DrawAnimatedRects	
DrawCaption
DrawEdge
DrawFocusRect
DrawFrameControl

*/
/////////////////////


ATOM RegisterLWndClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= LowResolutionWndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= NULL;
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= NULL;
	wcex.lpszClassName	= g_szLWndName;
	wcex.hIconSm		= NULL;
	ATOM ret = RegisterClassEx(&wcex);

	return ret;
}


ATOM RegisterHWndClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;

	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= NULL;
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= NULL;
	wcex.hIconSm		= NULL;

	wcex.lpfnWndProc	= HighResolutionWndProc;
	wcex.lpszClassName	= g_szHWndName;
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
		HOOKED_ENABLEEDITWARP_LOW = RegisterWindowMessage(HOOKED_ENABLEEDITWARP_LOW_MSG);
		HOOKED_ENABLEEDITTTS_LOW = RegisterWindowMessage(HOOKED_ENABLEEDITTTS_LOW_MSG);
		HOOKED_ENABLEEDITWARP_HIGH = RegisterWindowMessage(HOOKED_ENABLEEDITWARP_HIGH_MSG);
		HOOKED_ENABLEEDITTTS_HIGH = RegisterWindowMessage(HOOKED_ENABLEEDITTTS_HIGH_MSG);

		HOOKED_SETTTS_LOW = RegisterWindowMessage(HOOKED_SETTTS_LOW_MSG);
		HOOKED_SETTTS_HIGH = RegisterWindowMessage(HOOKED_SETTTS_HIGH_MSG);

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
			
			CreateLowDisplay(hModule);
			CreateHighDisplay(hModule);
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
		
		break;
	}
	return TRUE;
}

BOOL __stdcall OnReceiveMouseMessage(void* _THIS, WPARAM wparam, LPARAM lparam, void* data)
{
	if (g_hHookClientWnd == NULL || g_orgWndProc == NULL)
		return FALSE;
	struct TData
	{
		UINT msg;
		float tU;
		float tV;
	};
	TData* tdata = (TData*)data;
	RECT wrect;
	GetClientRect(g_hHookClientWnd, &wrect);
	unsigned short xPos = (wrect.right - wrect.left) * tdata->tU;
	unsigned short yPos = (wrect.bottom - wrect.top) * tdata->tV;
	lparam = (yPos << 16) | xPos ;

	PostMessage(g_hHookClientWnd, tdata->msg, wparam, lparam);
	//CallWindowProcW((WNDPROC)g_orgWndProc, g_hHookClientWnd,  tdata->msg, wparam, lparam );
	if (tdata->msg != WM_MOUSEMOVE)
	{
		WCHAR msg[MAX_PATH] = {0};
		switch (tdata->msg)
		{
			case WM_LBUTTONDOWN:
				swprintf_s(msg, MAX_PATH, L" WM_LBUTTONDOWN");
				break;
			case WM_LBUTTONUP:
				swprintf_s(msg, MAX_PATH, L" WM_LBUTTONUP");
				break;
			case WM_RBUTTONDOWN:
				swprintf_s(msg, MAX_PATH, L" WM_RBUTTONDOWN");
				break;
			case WM_RBUTTONUP:
				swprintf_s(msg, MAX_PATH, L" WM_RBUTTONUP");
				break;
		}
		WCHAR str[MAX_PATH];
		UINT xp = LOWORD(lparam);
		UINT yp = HIWORD(lparam);
		swprintf_s(str, MAX_PATH, L"@@@@ PostMessage xPos = %d, yPos = %d, %s \n", xp, yp, msg);
		OutputDebugStringW(str);
	}
	return TRUE;
}


BOOL CreateLowDisplay(HMODULE hModule)
{
	OutputDebugStringW(L"@@@@@ CreateLowDisplay called!! \n");
	if (g_pLowDisplay != NULL)
	{
		OutputDebugStringW(L"@@@@@ g_pLowDisplay != NULL, CreateLowDisplay return FALSE \n");
		return FALSE;
	}
	OutputDebugStringW(L"@@@@@before RegisterWndClass!! \n");
	RegisterLWndClass(hModule);
	g_LowWnd = CreateWindowExW(NULL, g_szLWndName, L"Low Resolution", WS_EX_TOPMOST |/* WS_POPUP |*/ WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT,0, NULL, NULL, hModule, NULL);
	
	if (g_LowWnd == NULL)
	{
		DWORD err = GetLastError();
		WCHAR str[MAX_PATH];
		swprintf_s(str, MAX_PATH, L"@@@@@ CreateWindow Failed!! in CreateLowDisplay, Error code = %h \n", err);
		OutputDebugStringW(str);
		
	}

	ShowWindow(g_LowWnd, TRUE);
	
	if (g_pD3D == NULL)
	{
		if( NULL == ( g_pD3D = Direct3DCreate9( D3D_SDK_VERSION ) ) )
		{
			OutputDebugStringW(L"@@@@@ Direct3DCreate9 Failed!! in CreateLowDisplay\n");
			return FALSE;
		}
	}
	
	g_pLowDisplay = new MS3DDisplay(g_LowWnd, g_pD3D);
	g_pLowDisplay->SetCaptureRegion(0.0, 0.0, 0.5, 0.7);
	
	return TRUE;
}


BOOL CreateHighDisplay(HMODULE hModule)
{
	OutputDebugStringW(L"@@@@@ CreateLowDisplay called!! \n");
	if (g_pHighDisplay != NULL)
	{
		OutputDebugStringW(L"@@@@@ g_pLowDisplay != NULL, CreateLowDisplay return FALSE \n");
		return FALSE;
	}
	OutputDebugStringW(L"@@@@@before RegisterWndClass!! \n");
	RegisterHWndClass(hModule);
	g_HighWnd = CreateWindowExW(NULL, g_szHWndName, L"High Resolution", WS_EX_TOPMOST |/* WS_POPUP |*/ WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT,0, NULL, NULL, hModule, NULL);

	if (g_HighWnd == NULL)
	{
		DWORD err = GetLastError();
		WCHAR str[MAX_PATH];
		swprintf_s(str, MAX_PATH, L"@@@@@ CreateWindow Failed!! in CreateLowDisplay, Error code = %h \n", err);
		OutputDebugStringW(str);

	}

	ShowWindow(g_HighWnd, TRUE);

	if (g_pD3D == NULL)
	{
		if( NULL == ( g_pD3D = Direct3DCreate9( D3D_SDK_VERSION ) ) )
		{
			OutputDebugStringW(L"@@@@@ Direct3DCreate9 Failed!! in CreateLowDisplay\n");
			return FALSE;
		}
	}

	g_pHighDisplay = new MS3DDisplay(g_HighWnd, g_pD3D);
	g_pHighDisplay->SetCaptureRegion(0.5,0.0,1.0,1.0);

	return TRUE;
}



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
	
	//RepaintClientWindow();
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

HOOK_API bool HOOKAPI::SetTTSRegion_Low(float v1_x, float v1_y, float v2_x, float v2_y, 
							   float v3_x, float v3_y, float v4_x, float v4_y)
{
	g_TTSRegion_L[0].x = v1_x; g_TTSRegion_L[0].y = v1_y; 
	g_TTSRegion_L[1].x = v2_x; g_TTSRegion_L[1].y = v2_y; 
	g_TTSRegion_L[2].x = v3_x; g_TTSRegion_L[2].y = v3_y; 
	g_TTSRegion_L[3].x = v4_x; g_TTSRegion_L[3].y = v4_y; 
	PostMessage(g_hHookClientWnd, HOOKED_SETTTS_LOW, NULL, NULL);
	return true;
}
HOOK_API bool HOOKAPI::GetTTSRegion_Low(float& v1_x, float& v1_y, float& v2_x, float& v2_y, 
			float& v3_x, float& v3_y, float& v4_x, float& v4_y)
{
	v1_x = g_TTSRegion_L[0].x; v1_y = g_TTSRegion_L[0].y; 
	v2_x = g_TTSRegion_L[1].x; v2_y = g_TTSRegion_L[1].y; 
	v3_x = g_TTSRegion_L[2].x; v3_y = g_TTSRegion_L[2].y; 
	v4_x = g_TTSRegion_L[3].x; v4_y = g_TTSRegion_L[3].y; 
	return true;
}

HOOK_API bool HOOKAPI::SetTTSRegion_High(float v1_x, float v1_y, float v2_x, float v2_y, 
							   float v3_x, float v3_y, float v4_x, float v4_y)
{
	OutputDebugStringW(L"@@@@ SetTTSRegion_High Called!! \n");
	g_TTSRegion_H[0].x = v1_x; g_TTSRegion_H[0].y = v1_y; 
	g_TTSRegion_H[1].x = v2_x; g_TTSRegion_H[1].y = v2_y; 
	g_TTSRegion_H[2].x = v3_x; g_TTSRegion_H[2].y = v3_y; 
	g_TTSRegion_H[3].x = v4_x; g_TTSRegion_H[3].y = v4_y; 
	PostMessage(g_hHookClientWnd, HOOKED_SETTTS_HIGH, NULL, NULL);
	return true;
}
HOOK_API bool HOOKAPI::GetTTSRegion_High(float& v1_x, float& v1_y, float& v2_x, float& v2_y, 
							   float& v3_x, float& v3_y, float& v4_x, float& v4_y)
{
	v1_x = g_TTSRegion_H[0].x; v1_y = g_TTSRegion_H[0].y; 
	v2_x = g_TTSRegion_H[1].x; v2_y = g_TTSRegion_H[1].y; 
	v3_x = g_TTSRegion_H[2].x; v3_y = g_TTSRegion_H[2].y; 
	v4_x = g_TTSRegion_H[3].x; v4_y = g_TTSRegion_H[3].y; 
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
	
	if (g_pLowDisplay != NULL)
	{
		delete g_pLowDisplay;
		g_pLowDisplay = NULL;
	}
	
	if (g_pD3D != NULL)
	{
		
		g_pD3D->Release();
		g_pD3D = NULL;
	}

	return true;
}

bool DetourAllGDI()
{
	DetourFunction((void*&)pRealBitBlt, pHookBitBlt, L"GDI::BitBlt");
	
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


LRESULT CALLBACK LowResolutionWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if (g_pLowDisplay != NULL)
	{
		if (g_pLowDisplay->WndProc(hWnd, message, wParam, lParam))
		{
			return 0;
		}
	}
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

		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		SendMessage(g_hHookServerWnd, HOOKED_WNDDESTORY, 0, 0);
		SendMessage(g_HighWnd, HOOKED_WNDDESTORY, 0, 0);
		ReleaseResource();
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}


LRESULT CALLBACK HighResolutionWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if (g_pHighDisplay != NULL)
	{
		if (g_pHighDisplay->WndProc(hWnd, message, wParam, lParam))
		{
			return 0;
		}
	}
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

		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		SendMessage(g_hHookServerWnd, HOOKED_WNDDESTORY, 0, 0);
		SendMessage(g_LowWnd, HOOKED_WNDDESTORY, 0, 0);
		ReleaseResource();
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
		if (uMsg == HOOKED_ENABLEEDITWARP_LOW)
		{
			if (g_pLowDisplay != NULL)
			{
				OutputDebugStringW(L"@@@@@ HOOKED_ENABLEEDITWARP_LOW Received!!!\n");
				g_pLowDisplay->SetEditWarpEnable(wParam);
			}
		}
		else if (uMsg == HOOKED_ENABLEEDITTTS_LOW)
		{
			if (g_pLowDisplay != NULL)
			{
				OutputDebugStringW(L"@@@@@ HOOKED_ENABLEEDITTTS_LOW Received!!!\n");
				g_pLowDisplay->SetEditTTSEnable(wParam);
			}
		}

		else if (uMsg == HOOKED_ENABLEEDITWARP_HIGH)
		{
			if (g_pHighDisplay != NULL)
			{
				OutputDebugStringW(L"@@@@@ HOOKED_ENABLEEDITWARP_HIGH Received!!!\n");
				g_pHighDisplay->SetEditWarpEnable(wParam);
			}
		}
		else if (uMsg == HOOKED_ENABLEEDITTTS_HIGH)
		{
			if (g_pHighDisplay != NULL)
			{
				OutputDebugStringW(L"@@@@@ HOOKED_ENABLEEDITTTS_HIGH Received!!!\n");
				g_pHighDisplay->SetEditTTSEnable(wParam);
			}
		}
		else if (uMsg == HOOKED_SETTTS_LOW)
		{
			if (g_pLowDisplay != NULL)
			{
				OutputDebugStringW(L"@@@@@ HOOKED_SETTTS_LOW Received!!!\n");
				g_pLowDisplay->SetTTS(g_TTSRegion_L[0], g_TTSRegion_L[1], 
					g_TTSRegion_L[2], g_TTSRegion_L[3]);
			}
		}
		else if (uMsg == HOOKED_SETTTS_HIGH)
		{
			if (g_pHighDisplay != NULL)
			{
				OutputDebugStringW(L"@@@@@ HOOKED_SETTTS_HIGH Received!!!\n");
				g_pHighDisplay->SetTTS(g_TTSRegion_H[0], g_TTSRegion_H[1], 
					g_TTSRegion_H[2], g_TTSRegion_H[3]);
			}
		}
		if (uMsg == WM_CLOSE)
		{ 
			OutputDebugStringW(L"@@@@ WM_HookCLOSE!!\n");
			SendMessage(g_hHookServerWnd, HOOKED_WNDDESTORY, 0, 0);
		}
		else if(uMsg == WM_DESTROY)
		{
			OutputDebugStringW(L"@@@@ WM_HookDESTORY!!\n");
			SendMessage(g_hHookServerWnd, HOOKED_WNDDESTORY, 0, 0);
			ReleaseResource();
		}
		else if (uMsg == HOOKED_SETHOOKCLIENT)
		{
			OutputDebugStringW(L"@@@@ HOOKED_RESETWNDPROC_MSG!!\n");
			_SetHookClient((HWND)wParam);
		}
		else if (uMsg == WM_PAINT)
		{
			OutputDebugStringW(L"@@@@@ WM_PAINT!!!!\n");
		}
	}
	LRESULT lr = 0;
	lr = CallWindowProcW((WNDPROC)g_orgWndProc,hwnd, uMsg, wParam, lParam );
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
			if (g_hHookClientWnd)
			{
				
				//EnableWindow(g_hHookClientWnd, FALSE);
			}
		}
	}
	return ret;
}

BOOL WINAPI pHookBitBlt(HDC hdc, int x, int y, int width, int height, HDC hdcSrc, int x1, int y1, DWORD rop)
{
	
	BOOL ret = pRealBitBlt(hdc, x, y, width, height, hdcSrc, x1, y1, rop);
	if (g_LowWnd != NULL && g_HighWnd != NULL && g_hHookClientWnd != NULL && g_pLowDisplay != NULL && g_pHighDisplay != NULL)
	{
		HWND hwnd = WindowFromDC(hdc);
		if (hwnd != g_hHookClientWnd)
		{
			return ret;
		}

		RECT rect;
		GetClientRect(hwnd, &rect);

		int dcW = rect.right - rect.left;
		int dcH = rect.bottom - rect.top;

		POINT pt;  pt.x = x; pt.y = y;
		MapWindowPoints(hwnd, g_hHookClientWnd, &pt,1);
		
		float low_l, low_t, low_r, low_b;
		float high_l, high_t, high_r, high_b;
		
		g_pLowDisplay->GetCaptureRegion(low_l, low_t, low_r, low_b);
		g_pHighDisplay->GetCaptureRegion(high_l, high_t, high_r, high_b);
	
		float tSrcX_L = dcW * low_l;
		float tSrcY_L = dcH * low_t;
		float sSrcX_L = low_r - low_l;
		float sSrcY_L = low_b - low_t;

		float tSrcX_H = dcW * high_l;
		float tSrcY_H = dcH * high_t;
		float sSrcX_H = high_r - high_l;
		float sSrcY_H = high_b - high_t;
		
		/*WCHAR str[MAX_PATH];
		swprintf_s(str,MAX_PATH, L"@@@@ x = %d. y = %d, width = %d, height = %d\n", x, y, width, height);
		OutputDebugStringW(str);
		swprintf_s(str,MAX_PATH, L"@@@@ mx = %.2f, my = %.2f, mwidth = %.2f, mheight = %.2f\n", (pt.x - tSrcX_H)*(1.0/sSrcX_H), (pt.y - tSrcY_H)*(1.0/sSrcX_H),
			width*(1.0/sSrcX_H), height*(1.0/sSrcY_H));
		OutputDebugStringW(str);
		*/
		g_pLowDisplay->DrawBitBlt(hdc, (pt.x - tSrcX_L)*(1.0/sSrcX_L), (pt.y - tSrcY_L)*(1.0/sSrcY_L), width*(1.0/sSrcX_L), height*(1.0/sSrcY_L), dcW, dcH, hdcSrc, x1, y1, width, height, rop);
		g_pHighDisplay->DrawBitBlt(hdc,(pt.x - tSrcX_H)*(1.0/sSrcX_H), (pt.y - tSrcY_H)*(1.0/sSrcY_H), width*(1.0/sSrcX_H), height*(1.0/sSrcY_H), dcW, dcH, hdcSrc, x1, y1, width, height, rop);

	}
	return TRUE;
}

HDC WINAPI pHookBeginPaint(HWND hWnd, LPPAINTSTRUCT lpPaint)
{
	HDC ret = pRealBeginPaint(hWnd, lpPaint);
	//pRealBeginPaint(g_LowWnd, lpPaint);
	return ret;
}

BOOL WINAPI pHookEndPaint(HWND hWnd, CONST PAINTSTRUCT *lpPaint)
{
	BOOL ret = pRealEndPaint(hWnd, lpPaint);
	//pRealEndPaint(g_LowWnd, lpPaint);
	return ret;
}