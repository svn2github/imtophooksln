#pragma once

#include "IGSFrameCaptureFilter.h"
#include "dshow.h"
#include "Streams.h"
#include <initguid.h>
#include "combase.h"
#include "GSDXFilterBase.h"
#include "GSDXMuxFilter.h"
#include "IGSPersist.h"

class GSFrameCaptureFilter :
	public GSMuxFilter, public IGSFrameCaptureFilter,
	public ISpecifyPropertyPages, public IGSPersist
{
public:
	static CUnknown *WINAPI CreateInstance(LPUNKNOWN punk, HRESULT *phr);

	//for COM interface 
	STDMETHODIMP NonDelegatingQueryInterface(REFIID iid, void **ppv);
	DECLARE_IUNKNOWN;

	//implement DShow Property Page
	STDMETHODIMP     GetPages(CAUUID *pPages);
	//from CMSPersist
	virtual HRESULT SaveToFile(WCHAR* path);
	virtual HRESULT LoadFromFile(WCHAR* path);
	virtual HRESULT GetName(WCHAR* name, UINT szName);

	//implement IGSFrameCaptureFilter
	
protected:
	virtual HRESULT CreatePins();

	static HRESULT __stdcall OnTransform(void* self, IMediaSample *pInSample, CMediaType* pInMT, 
		IMediaSample *pOutSample, CMediaType* pOutMT);

public:
	GSFrameCaptureFilter(IUnknown * pOuter, HRESULT *phr, BOOL ModifiesData);
	virtual ~GSFrameCaptureFilter();
};
