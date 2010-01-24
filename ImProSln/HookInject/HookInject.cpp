// HookInject.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "IHookInject.h"
#include "HookInject.h"
#include "dshow.h"
#include "Streams.h"
#include <queue>
using namespace std;
using namespace HOOKINJECT;
LONG_PTR g_orgWndProc = NULL;
UINT HOOKED_WNDDESTORY = 0;
UINT HOOKED_SETHOOKCLIENT = 0;
UINT HOOKED_BITBLTCALLED = 0;
////////////////////Share Data Segation///////////
#define QUEUE_SIZE 500
#pragma data_seg(".MuscleSeg")
HWND g_hHookServerWnd = NULL;
DWORD g_hHookServerProcID = 0;
HWND g_hHookClientWnd = NULL;
DWORD g_hHookClientProcID = 0;
MyQueue<DrawBitBltCommand, 500> g_BitBltCmdQueue = MyQueue<DrawBitBltCommand, 500>();

#pragma data_seg()
#pragma comment(linker, "/section:.MuscleSeg,rws")
/////////HOOOOOOOOOOOOOOOOK///////////////////////
BOOL (WINAPI* pRealBitBlt)(HDC, int, int, int, int, HDC, int, int, DWORD) = BitBlt;
BOOL WINAPI pHookBitBlt(HDC, int, int, int, int, HDC, int, int, DWORD);

HDC (WINAPI* pRealBeginPaint)(HWND hWnd, LPPAINTSTRUCT lpPaint) = BeginPaint;
HDC WINAPI pHookBeginPaint(HWND hWnd, LPPAINTSTRUCT lpPaint);

BOOL (WINAPI* pRealEndPaint)(HWND hWnd, CONST PAINTSTRUCT *lpPaint) = EndPaint;
BOOL WINAPI pHookEndPaint(HWND hWnd, CONST PAINTSTRUCT *lpPaint);


BOOL (WINAPI* pShowWindow)(HWND hWnd, int nCmdShow) = ShowWindow;
BOOL WINAPI pHookShowWindow(HWND hWnd, int nCmdShow);
//////////////////////////////////////////////////

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
bool ReleaseResource()
{
	ClearBitBltCmd();
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

bool DetourAllGDI()
{
	DetourFunction((void*&)pRealBitBlt, pHookBitBlt, L"GDI::BitBlt");
	return true;
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
	HWND hwnd = WindowFromDC(hdc);
	if (g_hHookClientWnd != NULL && g_hHookServerWnd != NULL)
	{
		if (hwnd != g_hHookClientWnd)
		{
			return ret;
		}
		PushBitBltCmd(DrawBitBltCommand(hdc, x, y, width, height, hdcSrc,
			x1, y1, rop));
		SendMessage(g_hHookServerWnd, HOOKED_BITBLTCALLED, NULL, NULL);
	}

	return ret;
}

HDC WINAPI pHookBeginPaint(HWND hWnd, LPPAINTSTRUCT lpPaint)
{
	HDC ret = pRealBeginPaint(hWnd, lpPaint);
	return ret;
}

BOOL WINAPI pHookEndPaint(HWND hWnd, CONST PAINTSTRUCT *lpPaint)
{
	BOOL ret = pRealEndPaint(hWnd, lpPaint);
	return ret;
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

bool _SetHookClient(HWND hClient)
{
	UnHookWndProc(g_hHookClientWnd);
	g_hHookClientWnd = hClient;
	HookWndProc(g_hHookClientWnd, (LONG)HookWindowProc, g_orgWndProc);

	//RepaintClientWindow();
	return true;
}



//////////////////////////////////
HOOKINJECT_API bool HOOKINJECT::SetHookClient(HWND hClient)
{
	SendMessageW(g_hHookClientWnd, HOOKED_SETHOOKCLIENT, (WPARAM)hClient, NULL);
	return true;
}
HOOKINJECT_API bool HOOKINJECT::GetHookClient(HWND& clientWnd)
{
	clientWnd = g_hHookClientWnd;
	return true;
}

HOOKINJECT_API bool HOOKINJECT::SetHookServerProcID(DWORD procID)
{
	g_hHookServerProcID = procID;
	return true;
}
HOOKINJECT_API bool HOOKINJECT::GetHookServerProcID(DWORD& procID)
{
	procID = g_hHookServerProcID;
	return true;
}
HOOKINJECT_API bool HOOKINJECT::SetHookServer(HWND hServerWnd)
{
	g_hHookServerWnd = hServerWnd;
	return true;
}
HOOKINJECT_API bool HOOKINJECT::GetHookServer(HWND& hServerWnd)
{
	hServerWnd = g_hHookServerWnd;
	return true;
}
HOOKINJECT_API bool HOOKINJECT::PushBitBltCmd(DrawBitBltCommand& cmd)
{

	g_BitBltCmdQueue.Push(cmd);
	return true;
}
HOOKINJECT_API bool HOOKINJECT::PopBitBltCmd(DrawBitBltCommand& cmd)
{
	if (g_BitBltCmdQueue.IsEmpty())
	{
		return false;
	}
	bool ret = g_BitBltCmdQueue.Pop(cmd);
	return ret;
}
HOOKINJECT_API bool HOOKINJECT::ClearBitBltCmd()
{

	g_BitBltCmdQueue.Clear();
	return true;
}
HOOKINJECT::DrawBitBltCommand::DrawBitBltCommand()
{
	m_hdc = 0;
	m_x = 0;
	m_y = 0;
	m_width = 0;
	m_height = 0;
	m_hdcSrc = 0;
	m_x1 = 0;
	m_y1 = 0;
	m_rop = 0;
}
HOOKINJECT::DrawBitBltCommand::DrawBitBltCommand(HDC hdc,int x,int y,int width,
		int height, HDC hdcSrc, int x1, int y1, DWORD rop)
{
	m_hdc = hdc;
	m_x = x;
	m_y = y;
	m_width = width;
	m_height = height;
	m_hdcSrc = hdcSrc;
	m_x1 = x1;
	m_y1 = y1;
	m_rop = rop;
}