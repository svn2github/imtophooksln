// SyncFilter.cpp : �w�q DLL ����l�Ʊ`���C
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


// CSyncFilterApp �غc

CSyncFilterApp::CSyncFilterApp()
{
	// TODO: �b���[�J�غc�{���X�A
	// �N�Ҧ����n����l�]�w�[�J InitInstance ��
}


// �Ȧ����@�� CSyncFilterApp ����

CSyncFilterApp theApp;


// CSyncFilterApp ��l�]�w

BOOL CSyncFilterApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
