#include "stdafx.h"
#include "ProjectSettingFilter.h"
#include "ProjectSettingFilterProp.h"
#include "ProjectSettingFilterApp.h"
#include <direct.h>

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
	else if (iid == IID_ISpecifyPropertyPages)
	{
		return GetInterface(
			static_cast<ISpecifyPropertyPages*>(this),	ppv);
	}
	else if (iid == IID_IMSPersist)
	{
		return GetInterface(static_cast<IMSPersist*>(this), ppv);
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
HRESULT ProjectSettingFilter::SaveToFile(WCHAR* path)
{
	int numPersist = GetNumPersistInstance();
	if (numPersist <= 0)
		return S_FALSE;
	IFilterGraph* pGraph = this->GetFilterGraph();
	if (pGraph == NULL)
	{
		return S_FALSE;
	}
	FILE* filestream = NULL;
	_wfopen_s(&filestream, path, L"w");
	if (filestream == NULL)
	{
		return false;
	}

	WCHAR filterName[MAX_PATH] = {0};
	WCHAR confPath[MAX_PATH] = {0};

	WCHAR* pszFile = wcsrchr(path, '\\');
	pszFile++;    // Moves on from \
	// Get path
	WCHAR szPath[MAX_PATH] = L"";
	_tcsncat(szPath, path, pszFile - path);
	fwprintf_s(filestream, L"%d\n", numPersist-1); // don't save itself
	
	WCHAR* tmp = wcsrchr(pszFile, '.');
	int res = (int)(tmp - pszFile);
	WCHAR confName[MAX_PATH] = {0};
	memcpy(confName, pszFile, sizeof(WCHAR)*res);
	confName[res] = '\0';
	WCHAR dirName[MAX_PATH] = {0};
	swprintf_s(dirName, MAX_PATH, L"%s%s", szPath, confName);
	_wmkdir(dirName);
	for (int i = 0; i< numPersist; i++)
	{
		IMSPersist* pPersist = NULL;
		GetPersistInstance(i, pPersist);
		pPersist->GetName(filterName, MAX_PATH);
		if (pPersist == this)
		{
			continue;
		}
		IBaseFilter* pFilter = NULL;
		pGraph->FindFilterByName(filterName, &pFilter);
		if (pFilter == NULL)
		{
			continue;
		}
		swprintf_s(confPath, MAX_PATH, L"%s%s\\%s.txt", szPath, confName, filterName);
		pPersist->SaveToFile(confPath);
		
		fwprintf_s(filestream, L"%s\n%s\n",filterName, confPath);
		if (pFilter != NULL)
		{
			pFilter->Release();
			pFilter = NULL;
		}
	
	}
	fclose(filestream);
	return S_OK;
}
HRESULT ProjectSettingFilter::LoadFromFile(WCHAR* path)
{
	HRESULT hr = S_OK;
	IFilterGraph* pGraph = this->GetFilterGraph();
	if (pGraph == NULL)
		return S_FALSE;

	FILE* filestream = NULL;
	_wfopen_s(&filestream, path, L"r");
	if (filestream == NULL)
	{
		return false;
	}
	WCHAR filterName[MAX_PATH] = {'\0'};
	WCHAR confPath[MAX_PATH] = {'\0'};
	int numPersist = 0;
	fwscanf_s(filestream, L"%d\n", &numPersist);
	
 	for (int i = 0; i< numPersist; i++)
	{
        fgetws(filterName, MAX_PATH, filestream);
		fgetws(confPath, MAX_PATH, filestream);

		WCHAR* tmp = wcsrchr(filterName, '\n' );
		if (tmp != NULL)
			*tmp = '\0';
		tmp = wcsrchr(confPath, '\n' );
		if (tmp != NULL)
			*tmp = '\0';

		IBaseFilter* pFilter = NULL;
		IMSPersist* pPersist = NULL;
		hr = pGraph->FindFilterByName(filterName, &pFilter);
		if (pFilter == NULL)
		{
			continue;
		}
		pFilter->QueryInterface(IID_IMSPersist, (void**)&pPersist);
		if (pPersist == NULL)
		{
			pFilter->Release();
			pFilter = NULL;
			continue;
		}
		pPersist->LoadFromFile(confPath);

		if (pFilter != NULL)
		{
			pFilter->Release();
			pFilter = NULL;
		}
		if (pPersist != NULL)
		{
			pPersist->Release();
			pPersist = NULL;
		}
	
	}
	fclose(filestream );

	return S_OK;
}
HRESULT ProjectSettingFilter::GetName(WCHAR* name, UINT szName)
{
	if (name == NULL)
		return S_FALSE;
	FILTER_INFO filterInfo;
	this->QueryFilterInfo(&filterInfo);
	wcscpy_s(name, szName, filterInfo.achName);
	if (filterInfo.pGraph != NULL)
	{
		filterInfo.pGraph->Release();
		filterInfo.pGraph = NULL;
	}
	return S_OK;
}