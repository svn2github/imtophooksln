#include "stdafx.h"
#include "ProjectSettingFilterReg.h"
#include "ImProGUID.h"

static WCHAR g_wszName[] = L"Project Setting Filter";
const AMOVIESETUP_PIN* psudProjectSettingFilterPins = NULL;


const REGFILTER2 sudProjectSettingFilter =
{ 	1,                // Version number.
MERIT_DO_NOT_USE, // Merit.
0,                // Number of pins.
psudProjectSettingFilterPins };         // lpPin


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
			CLSID_ProjectSettingFilter,              // Filter CLSID. 
			g_wszName,                       // Filter name.
			NULL ,                            // Device moniker. 
			&GUID_ImProFilter_Category,  // Video compressor category.
			g_wszName,                       // Instance data.
			&sudProjectSettingFilter                   // Filter information.
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
			g_wszName, CLSID_ProjectSettingFilter);
		pFM2->Release();
	}
	return hr;
}

CFactoryTemplate g_Templates[] = 
{
	{ 
		g_wszName,
			&CLSID_ProjectSettingFilter,
			ProjectSettingFilter::CreateInstance,
			NULL,
			NULL
	},
	{
		L"Mask Property Page",
			&CLSID_ProjectSettingFilterProp,
			ProjectSettingPropPage::CreateInstance,
			NULL,
			NULL
		}
};

int g_cTemplates = sizeof(g_Templates) / sizeof(g_Templates[0]);  

