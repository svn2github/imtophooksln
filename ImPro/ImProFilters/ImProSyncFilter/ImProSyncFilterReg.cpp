#include "stdafx.h"
#include "ImProSyncFilterReg.h"
#include "GShowGUID.h"
#include "ImProSyncFilterProp.h"
#include "GSMacro.h"
#include "GSD3DMediaType.h"
#include "GSMediaType.h"

GUID g_CategoryID = GUID_GShowFilter_Category;

WCHAR g_FilterName[] = L"ImPro Sync Filter";
GUID g_FILTER_CLSID = CLSID_ImProSyncFilter;
LPFNNewCOMObject g_pNewFilterFunc = ImProSyncFilter::CreateInstance;

WCHAR g_PropPageName[] = L"ImPro Sync Filter PropPage";
GUID g_PROP_CLSID = CLSID_ImProSyncFilterProp;
LPFNNewCOMObject g_pNewPropFunc = ImProSyncFilterProp::CreateInstance;


AMOVIESETUP_MEDIATYPE g_inputMTs[] =
{
	{&GSMEDIATYPE_GSDX11_SHAREDEVICE_MEDIATYPE, &MEDIASUBTYPE_NULL},
	{&GSMEDIATYPE_GSDX11_MEDIATYPE, &MEDIASUBTYPE_NULL},
	{&MEDIATYPE_Video, &MEDIASUBTYPE_NULL}
};

AMOVIESETUP_MEDIATYPE g_outputMTs[] =
{
	{&GSMEDIATYPE_GSDX11_SHAREDEVICE_MEDIATYPE, &MEDIASUBTYPE_NULL},
	{&GSMEDIATYPE_GSDX11_MEDIATYPE, &MEDIASUBTYPE_NULL},
	{&MEDIATYPE_Video, &MEDIASUBTYPE_NULL}
};


const AMOVIESETUP_PIN psudPins[] =
{  { L"input"            // strName
, FALSE               // bRendered
, FALSE               // bOutput
, FALSE               // bZero
, FALSE               // bMany
, &CLSID_NULL         // clsConnectsToFilter
, L""                 // strConnectsToPin
, ARRAYSIZE(g_inputMTs)   // nTypes
, g_inputMTs           // lpTypes
},
{ L"output"           // strName
, FALSE               // bRendered
, TRUE                // bOutput
, FALSE               // bZero
, FALSE               // bMany
, &CLSID_NULL         // clsConnectsToFilter
, L""                 // strConnectsToPin
, ARRAYSIZE(g_outputMTs) // nTypes
, g_outputMTs          // lpTypes
}
};

const REGFILTER2 sudFilter =
{ 	1,                // Version number.
MERIT_NORMAL, // Merit.
ARRAYSIZE(psudPins),                // Number of pins.
psudPins };         // lpPin


CFactoryTemplate g_Templates[] = 
{
	{ 
		g_FilterName,
		&g_FILTER_CLSID,
		g_pNewFilterFunc,
		NULL,
		NULL
	},
	{
		g_PropPageName,
			&g_PROP_CLSID,
			g_pNewPropFunc,
			NULL,
			NULL
	}
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
