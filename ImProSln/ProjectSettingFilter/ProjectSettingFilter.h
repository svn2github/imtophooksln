#pragma once
#include "IProjectSettingFilter.h"
#include "dshow.h"
#include "Streams.h"
#include <initguid.h>
#include "combase.h"
#include "CMuxTransformFilter.h"

class ProjectSettingFilter :
	public CMuxTransformFilter, public IProjectSettingFilter,
	public ISpecifyPropertyPages
{

public:
	static CUnknown *WINAPI CreateInstance(LPUNKNOWN punk, HRESULT *phr);

	//for COM interface 
	STDMETHODIMP NonDelegatingQueryInterface(REFIID iid, void **ppv);
	DECLARE_IUNKNOWN;
	
	virtual HRESULT CreatePins();
	//implement DShow Property Page
	STDMETHODIMP     GetPages(CAUUID *pPages);
public:
	ProjectSettingFilter(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData);
	virtual ~ProjectSettingFilter();
};
