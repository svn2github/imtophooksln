// SyncFilter.cpp : 定義 DLL 的初始化常式。
//

#include "stdafx.h"
#include "SyncFilterApp.h"

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


BEGIN_MESSAGE_MAP(CSyncFilterApp, CWinApp)
END_MESSAGE_MAP()


// CSyncFilterApp 建構

CSyncFilterApp::CSyncFilterApp()
{
	// TODO: 在此加入建構程式碼，
	// 將所有重要的初始設定加入 InitInstance 中
}


// 僅有的一個 CSyncFilterApp 物件

CSyncFilterApp theApp;


// CSyncFilterApp 初始設定

BOOL CSyncFilterApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
