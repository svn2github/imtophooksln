#pragma once
#include "IHookDrawingFilter.h"
#include "dshow.h"
#include "Streams.h"
#include <initguid.h>
#include "combase.h"
#include "MuxSourceFilter.h"
// {2D695412-05AE-4d4b-AADE-EC05F5931A88}
DEFINE_GUID(CLSID_HookDrawingFilter, 
			0x2d695412, 0x5ae, 0x4d4b, 0xaa, 0xde, 0xec, 0x5, 0xf5, 0x93, 0x1a, 0x88);


class HookDrawingFilter :
	public CMuxSourceFilter, public IHookDrawingFilter
{

public:
	static CUnknown *WINAPI CreateInstance(LPUNKNOWN punk, HRESULT *phr);
	//Derive from CMuxSourceFilter

	virtual HRESULT CreatePins();
	virtual HRESULT FillBuffer(IMediaSample *pSamp, IPin* pPin);
	virtual HRESULT GetMediaType(int iPosition, __inout CMediaType *pMediaType, IPin* pPin); 
	//for COM interface 
	STDMETHODIMP NonDelegatingQueryInterface(REFIID iid, void **ppv);
	DECLARE_IUNKNOWN;

public:
	HookDrawingFilter(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData);
	virtual ~HookDrawingFilter();
};