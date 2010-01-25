#include "stdafx.h"
#include "HookDrawingReg.h"
#include "HookDrawingProp.h"
#include "HookDrawingStreamProp.h"

static WCHAR g_wszName[] = L"HookDrawing Filter";
const AMOVIESETUP_PIN psudHookDrawingFilterPins[] =
{
{ L"output"           // strName
, FALSE               // bRendered
, TRUE                // bOutput
, FALSE               // bZero
, FALSE               // bMany
, &CLSID_NULL         // clsConnectsToFilter
, L""                 // strConnectsToPin
, 0                   // nTypes
, NULL                // lpTypes
}
};


const REGFILTER2 sudHookDrawingFilter =
{ 	1,                // Version number.
MERIT_DO_NOT_USE, // Merit.
1,                // Number of pins.
psudHookDrawingFilterPins };         // lpPin


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
		hr = pFM2->RegisterFilter(
			CLSID_HookDrawingFilter,              // Filter CLSID. 
			g_wszName,                       // Filter name.
			NULL ,                            // Device moniker. 
			&CLSID_LegacyAmFilterCategory,  // Video compressor category.
			g_wszName,                       // Instance data.
			&sudHookDrawingFilter                   // Filter information.
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
		hr = pFM2->UnregisterFilter(&CLSID_VideoCompressorCategory, 
			g_wszName, CLSID_HookDrawingFilter);
		pFM2->Release();
	}
	return hr;
}

CFactoryTemplate g_Templates[] = 
{
	{ 
		g_wszName,
			&CLSID_HookDrawingFilter,
			HookDrawingFilter::CreateInstance,
			NULL,
			NULL
	},
	{
		L"HookDrawing Prop Page",
			&CLSID_HookDrawingPropPage,
			HookDrawingPropPage::CreateInstance,
			NULL,
			NULL
	},
	{
		L"Hook Stream Prop Page",
			&CLSID_HookDrawingStreamPropPage,
			HookDrawingStreamPropPage::CreateInstance,
			NULL,
			NULL
	}
};

int g_cTemplates = sizeof(g_Templates) / sizeof(g_Templates[0]);  

