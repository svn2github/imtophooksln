#include "stdafx.h"
#include "ARLayoutReg.h"
#include "ARLayoutDXFilter.h"
#include "ARLayoutDXProp.h"
#include "ImProGUID.h"

// Setup data for filter registration
//

const AMOVIESETUP_MEDIATYPE sudPinTypes[] =
{	
{ &MEDIATYPE_Video, &MEDIASUBTYPE_RGB24 },
{ &MEDIATYPE_Video, &MEDIASUBTYPE_RGB32 },
{ &GUID_D3DMEDIATYPE, &GUID_D3DSHARE_RTTEXTURE_POINTER },
{ &GUID_D3DMEDIATYPE, &GUID_D3DXTEXTURE9_POINTER }
};

//For DLL Register
static WCHAR g_wszName[] = L"ARLayoutFilter";
const AMOVIESETUP_PIN psudARLayoutFilterPins[] =
{ 
	{ 
		L"config",		// Pin's string name
			FALSE,			// Is it rendered
			FALSE,			// Is it an output
			FALSE,			// Allowed none
			FALSE,			// Allowed many
			&CLSID_NULL,	// Connects to filter
			L"Output",		// Connects to pin
			1,				// Number of types
			sudPinTypes	// Pin type information
	},
	{ 
		L"Layout",		// Pin's string name
			FALSE,			// Is it rendered
			TRUE,			// Is it an output
			FALSE,			// Allowed none
			FALSE,			// Allowed many
			&CLSID_NULL,	// Connects to filter
			L"Input",		// Connects to pin
			4,				// Number of types
			sudPinTypes	// Pin type information
	},
	{
	      L"markinfo",		// Pin's string name
			FALSE,			// Is it rendered
			TRUE,			// Is it an output
			FALSE,			// Allowed none
			FALSE,			// Allowed many
			&CLSID_NULL,	// Connects to filter
			L"Input",		// Connects to pin
			1,				// Number of types
			sudPinTypes	// Pin type information
		},
		{
			L"ROI",		// Pin's string name
			FALSE,			// Is it rendered
			TRUE,			// Is it an output
			FALSE,			// Allowed none
			FALSE,			// Allowed many
			&CLSID_NULL,	// Connects to filter
			L"Input",		// Connects to pin
			1,				// Number of types
			sudPinTypes	// Pin type information
	  }
};


const REGFILTER2 sudARLayoutFilter =
{ 	1,                // Version number.
MERIT_NORMAL,     // Merit.
4,                        // Number of pins.
psudARLayoutFilterPins };         // lpPin



STDAPI DllRegisterServer(void)
{
#ifdef _AFXDLL
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
#endif
	HRESULT hr = AMovieDllRegisterServer2(TRUE);
	if (FAILED(hr))
	{
		return hr;
	}
	
	IFilterMapper2 *pFM2 = NULL;
	hr = CoCreateInstance(CLSID_FilterMapper2, NULL, CLSCTX_INPROC_SERVER,
		IID_IFilterMapper2, (void **)&pFM2);
	if (SUCCEEDED(hr))
	{
		hr = pFM2->CreateCategory(GUID_ImProFilter_Category, MERIT_NORMAL,
			L"ImPro Filters");
		hr = pFM2->RegisterFilter(
			CLSID_ARLayoutFilter,              // Filter CLSID. 
			g_wszName,                       // Filter name.
			NULL ,                            // Device moniker. 
			&GUID_ImProFilter_Category,  // Video compressor category.
			g_wszName,                       // Instance data.
			&sudARLayoutFilter                   // Filter information.
			);
		pFM2->Release();
	}
	return hr;
}

STDAPI DllUnregisterServer()
{
#ifdef _AFXDLL
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
#endif
	HRESULT hr = AMovieDllRegisterServer2(FALSE);
	if (FAILED(hr))
	{
		return hr;
	}
	IFilterMapper2 *pFM2 = NULL;
	hr = CoCreateInstance(CLSID_FilterMapper2, NULL, CLSCTX_INPROC_SERVER,
		IID_IFilterMapper2, (void **)&pFM2);
	if (SUCCEEDED(hr))
	{
		hr = pFM2->UnregisterFilter(&GUID_ImProFilter_Category, 
			g_wszName, CLSID_ARLayoutFilter);
		pFM2->Release();
	}
	return hr;
}

CFactoryTemplate g_Templates[] = 
{

	{ 
		g_wszName,
			&CLSID_ARLayoutFilter,
			ARLayoutDXFilter::CreateInstance,
			NULL,
			NULL
	},
	{
		L"ARLayout Property Page",
			&CLSID_ARLayoutPropPage,
			ARLayoutDXPropPage::CreateInstance,
			NULL,
			NULL
	}
};

int g_cTemplates = sizeof(g_Templates) / sizeof(g_Templates[0]);  


extern "C" BOOL WINAPI DllEntryPoint(HINSTANCE, ULONG, LPVOID);
extern "C" BOOL WINAPI _DllMainCRTStartup(HINSTANCE, ULONG, LPVOID);

HMODULE g_module = 0;
HMODULE GetDLLModule()
{
	return g_module;
}
BOOL APIENTRY FilterDllMain(HMODULE	hModule, 
							DWORD  dwReason, 
							LPVOID lpReserved)
{
	g_module = hModule;
	_DllMainCRTStartup((HINSTANCE)hModule, dwReason, lpReserved);
	return DllEntryPoint((HINSTANCE)(hModule), dwReason, lpReserved);
}

HMODULE GetModule()
{
	return g_module;
}
