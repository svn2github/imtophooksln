#pragma once

#include "dshow.h"
#include "Streams.h"
#include <initguid.h>
#include "combase.h"
#include "ARTagLayout.h"
#include "IARLayoutFilter.h"
#include "CMuxTransformFilter.h"
#include "ARLayoutFilter.h"
#include "MSSD3DClass.h"
#include "D3DTransformFilterBase.h"
#include "ARToolKitPlus/TrackerMultiMarker.h"
using namespace ARToolKitPlus;

class ARLayoutDXFilter :
	public CMuxTransformFilter, public IARLayoutDXFilter, ISpecifyPropertyPages,
	public D3DTransformFilterBase
{
public:
	static CUnknown *WINAPI CreateInstance(LPUNKNOWN punk, HRESULT *phr);
	DECLARE_IUNKNOWN;
	STDMETHODIMP NonDelegatingQueryInterface(REFIID iid, void **ppv);
	STDMETHODIMP Notify (IBaseFilter *pSender, Quality q);
	STDMETHODIMP     GetPages(CAUUID *pPages);

	//Derive from CMuxTransformFilter
	virtual HRESULT CreatePins();
	virtual HRESULT FillBuffer(IMediaSample *pSamp, IPin* pPin);
	virtual HRESULT GetMediaType(int iPosition, const IPin* pOutPin, __inout CMediaType *pMediaType);
	virtual HRESULT CheckOutputType(const CMediaType* mtOut, const IPin* pPin);
	virtual HRESULT DecideBufferSize(
		IMemAllocator * pAllocator, const IPin* pOutPin,
		__inout ALLOCATOR_PROPERTIES *pprop);
	//Derive from D3DTransformFilter

	virtual MS3DDisplay* Create3DDisplay(IDirect3D9* pD3D, int rtWidth, int rtHeight);
	virtual MS3DDisplay* Create3DDisplay(IDirect3DDevice9* pDevice, int rtWidth, int rtHeight);

protected:
	ARMultiEachMarkerInfoT* m_ARMarkers;
	int m_numMarker;
	bool initARMarkers();
public:
	ARLayoutDXFilter(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData);
	virtual ~ARLayoutDXFilter();
	virtual bool LoadConfigFromFile(WCHAR* filename);
	virtual bool SaveConfigToFile(WCHAR* filename);


};