// DXRender.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "DXRenderApp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: If this DLL is dynamically linked against the MFC DLLs,
//		any functions exported from this DLL which call into
//		MFC must have the AFX_MANAGE_STATE macro added at the
//		very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the 
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

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

// CDXRenderApp

BEGIN_MESSAGE_MAP(CDXRenderApp, CWinApp)
END_MESSAGE_MAP()


// CDXRenderApp construction

CDXRenderApp::CDXRenderApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CDXRenderApp object

CDXRenderApp theApp;


// CDXRenderApp initialization

BOOL CDXRenderApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
