#include "stdafx.h"
#include "GSDXRendererReg.h"
#include "GShowGUID.h"

static WCHAR g_wszName[] = L"GSDXRenderer";
const AMOVIESETUP_PIN psudGSDXRendererPins[] =
{ { L"input"            // strName
, FALSE               // bRendered
, FALSE               // bOutput
, FALSE               // bZero
, FALSE               // bMany
, &CLSID_NULL         // clsConnectsToFilter
, L""                 // strConnectsToPin
, 0                   // nTypes
, NULL                // lpTypes
}
};


const REGFILTER2 sudGSDXRenderer =
{ 	1,                // Version number.
MERIT_DO_NOT_USE, // Merit.
1,                // Number of pins.
psudGSDXRendererPins };         // lpPin


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
		hr = pFM2->CreateCategory(GUID_GShowFilter_Category, MERIT_NORMAL,
			L"GShow Filters");
		hr = pFM2->RegisterFilter(
			CLSID_GSDXRenderer,              // Filter CLSID. 
			g_wszName,                       // Filter name.
			NULL ,                            // Device moniker. 
			&GUID_GShowFilter_Category,  // Video compressor category.
			g_wszName,                       // Instance data.
			&sudGSDXRenderer                   // Filter information.
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
		hr = pFM2->UnregisterFilter(&GUID_GShowFilter_Category, 
			g_wszName, CLSID_GSDXRenderer);
		pFM2->Release();
	}
	return hr;
}

CFactoryTemplate g_Templates[] = 
{
	{ 
		g_wszName,
			&CLSID_GSDXRenderer,
			GSDXRenderer::CreateInstance,
			NULL,
			NULL
	},
	/*{
		L"IGSDXRenderer Property Page",
			&CLSID_DXRenderPropPage,
			GSDXRendererProp::CreateInstance,
			NULL,
			NULL
		}*/
};

int g_cTemplates = sizeof(g_Templates) / sizeof(g_Templates[0]);  

