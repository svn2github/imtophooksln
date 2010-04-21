// ProjectSettingFilter.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "ProjectSettingFilterApp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

HMODULE			 g_hModule = 0;

extern "C" BOOL WINAPI DllEntryPoint(HINSTANCE, ULONG, LPVOID);
extern "C" BOOL WINAPI _DllMainCRTStartup(HINSTANCE, ULONG, LPVOID);

HMODULE GetModule()
{
	return g_hModule;
}

BOOL APIENTRY FilterDllMain(HMODULE hModule, 
							DWORD  dwReason, 
							LPVOID lpReserved)
{

	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		g_hModule = hModule;
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:

		break;
	}

	_DllMainCRTStartup((HINSTANCE)hModule, dwReason, lpReserved);
	return DllEntryPoint((HINSTANCE)(hModule), dwReason, lpReserved);
}


BEGIN_MESSAGE_MAP(CProjectSettingFilterApp, CWinApp)
END_MESSAGE_MAP()


// CProjectSettingFilterApp construction

CProjectSettingFilterApp::CProjectSettingFilterApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CProjectSettingFilterApp object

CProjectSettingFilterApp theApp;


// CProjectSettingFilterApp initialization

BOOL CProjectSettingFilterApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
