// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"

#include "Psapi.h"
#include "IHookInject.h"
#include "HookInject.h"
#include "wchar.h"
#include <detours.h>

HMODULE	 g_hModule = 0;
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  dwReason,
                       LPVOID lpReserved
					 )
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		HOOKED_WNDDESTORY = RegisterWindowMessage(HOOKED_WNDDESTORY_MSG);
		HOOKED_SETHOOKCLIENT = RegisterWindowMessage(HOOKED_SETHOOKCLIENT_MSG);
		OutputDebugStringW(L"@@@@ DLL_PROCESS_ATTACH!!\n");
		if (g_hHookServerProcID == 0)
		{
			g_hModule = hModule;
			DWORD err = GetLastError();
			g_hHookServerProcID = GetCurrentProcessId();
			WCHAR str[MAX_PATH] = {0};
			swprintf_s(str, L"@@@@ HookServer: %d \n", GetCurrentProcessId());
			OutputDebugStringW(str);

		}
		else if (( GetCurrentProcessId() != g_hHookServerProcID) && g_hHookClientProcID == 0)
		{
			g_hHookClientProcID = GetCurrentProcessId();
			WCHAR str[MAX_PATH] = {0};
			swprintf_s(str, L"@@@@ HookClient: %Xh \n", GetCurrentProcessId());
			OutputDebugStringW(str);
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


