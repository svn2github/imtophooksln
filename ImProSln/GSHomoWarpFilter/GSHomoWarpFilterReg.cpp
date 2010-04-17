#include "stdafx.h"
#include "GSHomoWarpFilterReg.h"
#include "GShowGUID.h"

GUID g_CategoryID = GUID_GShowFilter_Category;

WCHAR g_FilterName[] = L"GSHomoWarpFilter";
GUID g_FILTER_CLSID = CLSID_GSHomoWarpFilter;
LPFNNewCOMObject g_pNewFilterFunc = GSHomoWarpFilter::CreateInstance;

WCHAR g_PropPageName[] = L"GSHomoWarp PropPage";
//GUID g_PROP_CLSID = CLSID_;
LPFNNewCOMObject g_pNewPropFunc = NULL;


const AMOVIESETUP_PIN psudPins[] =
{  { L"input"            // strName
, FALSE               // bRendered
, FALSE               // bOutput
, FALSE               // bZero
, FALSE               // bMany
, &CLSID_NULL         // clsConnectsToFilter
, L""                 // strConnectsToPin
, 0                   // nTypes
, NULL                // lpTypes
},
{ L"config"            // strName
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

const REGFILTER2 sudFilter =
{ 	1,                // Version number.
MERIT_DO_NOT_USE, // Merit.
3,                // Number of pins.
psudPins };         // lpPin

CFactoryTemplate g_Templates[] = 
{
	{ 
		g_FilterName,
		&g_FILTER_CLSID,
		g_pNewFilterFunc,
		NULL,
		NULL
	}
	/*{
		L"IGSHomoWarpFilter Property Page",
			&CLSID_DXRenderPropPage,
			GSHomoWarpFilterProp::CreateInstance,
			NULL,
			NULL
		}*/
};

int g_cTemplates = sizeof(g_Templates) / sizeof(g_Templates[0]);  


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
		hr = pFM2->CreateCategory(g_CategoryID, MERIT_NORMAL,
			L"GShow Filters");
		hr = pFM2->RegisterFilter(
			g_FILTER_CLSID,              // Filter CLSID. 
			g_FilterName,                       // Filter name.
			NULL ,                            // Device moniker. 
			&g_CategoryID,  // Video compressor category.
			g_FilterName,                       // Instance data.
			&sudFilter                   // Filter information.
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
		hr = pFM2->UnregisterFilter(&g_CategoryID, 
			g_FilterName, g_FILTER_CLSID);
		pFM2->Release();
	}
	return hr;
}
