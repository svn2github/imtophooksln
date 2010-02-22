#include "stdafx.h"
#include "ProjectSettingFilter.h"
#include "ProjectSettingFilterProp.h"
#include "ProjectSettingFilterApp.h"

ProjectSettingFilter::ProjectSettingFilter(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData)
: CMuxTransformFilter(NAME("Project Setting Filter"), 0, CLSID_ProjectSettingFilter)
{ 

}
ProjectSettingFilter::~ProjectSettingFilter()
{

}

CUnknown *WINAPI ProjectSettingFilter::CreateInstance(LPUNKNOWN punk, HRESULT *phr)
{
	ASSERT(phr);
	// assuming we don't want to modify the data
	ProjectSettingFilter *pNewObject = new ProjectSettingFilter(punk, phr, FALSE);

	if(pNewObject == NULL) {
		if (phr)
			*phr = E_OUTOFMEMORY;
	}
	return pNewObject;
}

HRESULT ProjectSettingFilter::NonDelegatingQueryInterface(REFIID iid, void **ppv)
{
	if (iid == IID_IProjectSettingFilter) 
	{
		return GetInterface(static_cast<IProjectSettingFilter*>(this), ppv);
	}
	if (iid == IID_ISpecifyPropertyPages)
	{
		return GetInterface(
			static_cast<ISpecifyPropertyPages*>(this),	ppv);
	}
	else
	{
		// Call the parent class.
		return CBaseFilter::NonDelegatingQueryInterface(iid, ppv);
	}
}

HRESULT ProjectSettingFilter::CreatePins()
{
	return S_OK;
}

HRESULT ProjectSettingFilter::GetPages(CAUUID *pPages)
{
	pPages->cElems = 1;
	pPages->pElems = (GUID*)CoTaskMemAlloc(sizeof(GUID));
	if (pPages->pElems == NULL) 
	{
		return E_OUTOFMEMORY;
	}
	pPages->pElems[0] = CLSID_ProjectSettingFilterProp;
	return S_OK;
}
