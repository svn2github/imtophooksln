#pragma once

#include "Psapi.h"
#include "wchar.h"
#include <detours.h>
#include "streams.h"
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
extern UINT HOOKED_BITBLTCALLED;
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
template <class T, UINT Qsize>
class MyQueue
{
protected:
	CCritSec m_csBitBltQueue;
	T m_obj[Qsize];
	UINT m_idxFront;
	UINT m_idxBack;
	UINT m_count;

public:
	MyQueue()
	{
		m_idxFront = 0;
		m_idxBack =0;
		m_count = 0;
	}
	~MyQueue()
	{

	}
	
	bool Push(T& inst)
	{
		CAutoLock lck(&m_csBitBltQueue);
		if (m_count >= Qsize)
		{
			return false;
		}
		m_obj[m_idxFront] = inst;
		m_idxFront = (m_idxFront+1) % Qsize;
		m_count++;
		return true;
	};
	bool Pop(T& inst)
	{
		CAutoLock lck(&m_csBitBltQueue);
		if (m_count <= 0 )
		{
			return false;
		}
		inst = m_obj[m_idxBack];
		m_idxBack = (m_idxBack+1) % Qsize;
		m_count--;
		return true;
	}
	bool IsEmpty()
	{
		CAutoLock lck(&m_csBitBltQueue);
		if (m_count <= 0)
		{
			return true;
		}
		return false;
	}
	bool Clear()
	{
		CAutoLock lck(&m_csBitBltQueue);
		m_idxFront = 0;
		m_idxBack = 0;
		m_count = 0;
		return true;
	}
	bool IsFull()
	{
		CAutoLock lck(&m_csBitBltQueue);
		if (m_count >= Qsize)
		{
			return true;
		}
		return false;
	}
};