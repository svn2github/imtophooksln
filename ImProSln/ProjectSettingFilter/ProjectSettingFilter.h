#pragma once
#include "IProjectSettingFilter.h"
#include "dshow.h"
#include "Streams.h"
#include <initguid.h>
#include "combase.h"
#include "CMuxTransformFilter.h"
#include "MSPersist.h"

class ProjectSettingFilter :
	public CMuxTransformFilter, public IProjectSettingFilter,
	public ISpecifyPropertyPages, public CMSPersist
{

public:
	static CUnknown *WINAPI CreateInstance(LPUNKNOWN punk, HRESULT *phr);

	//for COM interface 
	STDMETHODIMP NonDelegatingQueryInterface(REFIID iid, void **ppv);
	DECLARE_IUNKNOWN;
	
	virtual HRESULT CreatePins();
	//implement DShow Property Page
	STDMETHODIMP     GetPages(CAUUID *pPages);
	//from CMSPersist
	virtual HRESULT SaveToFile(WCHAR* path);
	virtual HRESULT LoadFromFile(WCHAR* path);
	virtual HRESULT GetName(WCHAR* name, UINT szName);

public:
	ProjectSettingFilter(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData);
	virtual ~ProjectSettingFilter();
};
