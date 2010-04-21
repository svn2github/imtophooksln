// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"

HMODULE			 g_hModule = 0;

HMODULE GetModule()
{
	return g_hModule;
}
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		g_hModule = hModule;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		g_hModule = 0;
		break;
	}
	return TRUE;
}

