#include "stdafx.h"
#include "HookDrawingFilter.h"
#include "HookDrawingFilterApp.h"
#include "cv.h"


HookDrawingFilter::HookDrawingFilter(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData)
: CMuxSourceFilter(NAME("HookDrawing Filter"), 0, CLSID_HookDrawingFilter)
{ 

}
HookDrawingFilter::~HookDrawingFilter()
{

}

CUnknown *WINAPI HookDrawingFilter::CreateInstance(LPUNKNOWN punk, HRESULT *phr)
{
	ASSERT(phr);
	// assuming we don't want to modify the data
	HookDrawingFilter *pNewObject = new HookDrawingFilter(punk, phr, FALSE);

	if(pNewObject == NULL) {
		if (phr)
			*phr = E_OUTOFMEMORY;
	}
	return pNewObject;
}

HRESULT HookDrawingFilter::NonDelegatingQueryInterface(REFIID iid, void **ppv)
{
	if (iid == IID_IHookDrawingFilter) 
	{
		return GetInterface(static_cast<IHookDrawingFilter*>(this), ppv);
	}
	/*if (iid == IID_ISpecifyPropertyPages)
	{
		return GetInterface(
			static_cast<ISpecifyPropertyPages*>(this),	ppv);
	}*/
	else
	{
		// Call the parent class.
		return CBaseFilter::NonDelegatingQueryInterface(iid, ppv);
	}
}

HRESULT HookDrawingFilter::CreatePins()
{
	return S_OK;
}
HRESULT HookDrawingFilter::FillBuffer(IMediaSample *pSamp, IPin* pPin)
{
	return S_FALSE;
}
HRESULT HookDrawingFilter::GetMediaType(int iPosition, __inout CMediaType *pMediaType, IPin* pPin)
{
	return S_FALSE;
}