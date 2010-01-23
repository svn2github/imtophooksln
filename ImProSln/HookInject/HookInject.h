#pragma once

#include "Psapi.h"
#include "wchar.h"
#include <detours.h>
#pragma comment(lib, "psapi")

bool DetourFunction(void*& targetAddress, void* hookAddress, WCHAR* funcName);
bool ReleaseResource();
bool DetourAllGDI();
bool HookWndProc(HWND hwnd, LONG WndProc, LONG_PTR& orgWndProc);
bool UnHookWndProc(HWND hwnd);
bool _SetHookClient(HWND hClient);

////////////////////////////////////////////
extern LONG_PTR g_orgWndProc;
extern UINT HOOKED_WNDDESTORY;
extern UINT HOOKED_SETHOOKCLIENT;
extern HWND g_hHookServerWnd;
extern DWORD g_hHookServerProcID;
extern HWND g_hHookClientWnd;
extern DWORD g_hHookClientProcID;
////////////for hook GDI Drawing command/////////////////
extern BOOL (WINAPI* pRealBitBlt)(HDC, int, int, int, int, HDC, int, int, DWORD);
BOOL WINAPI pHookBitBlt(HDC, int, int, int, int, HDC, int, int, DWORD);

extern HDC (WINAPI* pRealBeginPaint)(HWND hWnd, LPPAINTSTRUCT lpPaint);
HDC WINAPI pHookBeginPaint(HWND hWnd, LPPAINTSTRUCT lpPaint);

extern BOOL (WINAPI* pRealEndPaint)(HWND hWnd, CONST PAINTSTRUCT *lpPaint);
BOOL WINAPI pHookEndPaint(HWND hWnd, CONST PAINTSTRUCT *lpPaint);


extern BOOL (WINAPI* pShowWindow)(HWND hWnd, int nCmdShow);
BOOL WINAPI pHookShowWindow(HWND hWnd, int nCmdShow);



LRESULT CALLBACK HookWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam,LPARAM lParam);
LRESULT CALLBACK LowResolutionWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK HighResolutionWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);