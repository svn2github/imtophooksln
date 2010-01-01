
//For DLL Register
#include "stdafx.h"
#include "ARTagReg.h"



static WCHAR g_wszName[] = L"ARTagFilter";
const AMOVIESETUP_PIN psudARTagFilterPins[] =
{ { L"Input"            // strName
, FALSE               // bRendered
, FALSE               // bOutput
, FALSE               // bZero
, FALSE               // bMany
, &CLSID_NULL         // clsConnectsToFilter
, L""                 // strConnectsToPin
, 0                   // nTypes
, NULL                // lpTypes
}
, { L"Output"           // strName
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

const REGFILTER2 sudARTagFilter =
{ 	1,                // Version number.
MERIT_DO_NOT_USE, // Merit.
2,                // Number of pins.
psudARTagFilterPins };         // lpPin

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
			CLSID_ARTagDSFilter,              // Filter CLSID. 
			g_wszName,                       // Filter name.
			NULL ,                            // Device moniker. 
			&CLSID_LegacyAmFilterCategory,  // Video compressor category.
			g_wszName,                       // Instance data.
			&sudARTagFilter                   // Filter information.
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
			g_wszName, CLSID_ARTagDSFilter);
		pFM2->Release();
	}
	return hr;
}




CFactoryTemplate g_Templates[] = 
{
	{ 
		g_wszName,
			&CLSID_ARTagDSFilter,
			ARTagDSFilter::CreateInstance,
			NULL,
			NULL
	},
	{ 
		L"ARTag Camera Page",
			&CLSID_ARTagCameraProperty,
			ARTagCameraSettingPage::CreateInstance, 
			NULL, NULL
	},
	{ 
			L"ARTag General Page",
				&CLSID_ARTagProperty,
				ARTagGeneralPage::CreateInstance, 
				NULL, NULL
	}
};

int g_cTemplates = sizeof(g_Templates) / sizeof(g_Templates[0]);  


//
// DllEntryPoint
//

