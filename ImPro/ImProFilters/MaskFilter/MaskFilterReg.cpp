#include "stdafx.h"
#include "MaskFilterReg.h"
#include "ImProGUID.h"

static WCHAR g_wszName[] = L"Mask Filter";
const AMOVIESETUP_PIN psudMaskFilterPins[] =
{ { L"input"            // strName
, FALSE               // bRendered
, FALSE               // bOutput
, FALSE               // bZero
, FALSE               // bMany
, &CLSID_NULL         // clsConnectsToFilter
, L""                 // strConnectsToPin
, 0                   // nTypes
, NULL                // lpTypes
},
{ L"AR conf"            // strName
, FALSE               // bRendered
, FALSE               // bOutput
, FALSE               // bZero
, FALSE               // bMany
, &CLSID_NULL         // clsConnectsToFilter
, L""                 // strConnectsToPin
, 0                   // nTypes
, NULL                // lpTypes
}
, { L"output"           // strName
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


const REGFILTER2 sudMaskFilter =
{ 	1,                // Version number.
MERIT_DO_NOT_USE, // Merit.
2,                // Number of pins.
psudMaskFilterPins };         // lpPin


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
			CLSID_MaskFilter,              // Filter CLSID. 
			g_wszName,                       // Filter name.
			NULL ,                            // Device moniker. 
			&GUID_ImProFilter_Category,  // Video compressor category.
			g_wszName,                       // Instance data.
			&sudMaskFilter                   // Filter information.
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
			g_wszName, CLSID_MaskFilter);
		pFM2->Release();
	}
	return hr;
}

CFactoryTemplate g_Templates[] = 
{
	{ 
		g_wszName,
			&CLSID_MaskFilter,
			MaskFilter::CreateInstance,
			NULL,
			NULL
	},
	{
		L"Mask Property Page",
			&CLSID_MaskFilterProp,
			MaskFilterPropPage::CreateInstance,
			NULL,
			NULL
		}
};

int g_cTemplates = sizeof(g_Templates) / sizeof(g_Templates[0]);  

