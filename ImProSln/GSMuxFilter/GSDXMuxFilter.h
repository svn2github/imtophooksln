#pragma once
#include "GSMuxFilter.h"
#include "dshow.h"
#include "Streams.h"
#include <initguid.h>
#include "combase.h"
#include "GSDXFilterBase.h"
#include "GSDXShareFilter.h"
class GSDXMuxInputPin : public GSMuxInputPin, public GSDXShareInputPin
{
	friend class GSMuxFilter;
public:

	GSDXMuxInputPin(
		__in_opt LPCTSTR pObjectName,
		__inout GSMuxFilter *pTransformFilter,
		__inout HRESULT * phr,
		__in_opt LPCWSTR pName);
#ifdef UNICODE
	GSDXMuxInputPin(
		__in_opt LPCSTR pObjectName,
		__inout GSMuxFilter *pTransformFilter,
		__inout HRESULT * phr,
		__in_opt LPCWSTR pName);
#endif
	virtual ~GSDXMuxInputPin();
	// overwrite GSMuxInputPin
	virtual STDMETHODIMP NonDelegatingQueryInterface(REFIID riid, __deref_out void **ppv);
	virtual HRESULT CompleteConnect(IPin *pReceivePin);
	virtual HRESULT BreakConnect();
	//from GSDXShareInputPin
	virtual HRESULT GetD3DFilter(IGSDXShareFilter*& pFilter);
};
class GSDXMuxOutputPin : public GSMuxOutputPin, public GSDXShareOutputPin
{
	friend class GSDXMuxFilter;
public:
	GSDXMuxOutputPin(
		__in_opt LPCTSTR pObjectName,
		__inout GSMuxFilter *pTransformFilter,
		__inout HRESULT * phr,
		__in_opt LPCWSTR pName);
#ifdef UNICODE
	GSDXMuxOutputPin(
		__in_opt LPCSTR pObjectName,
		__inout GSMuxFilter *pTransformFilter,
		__inout HRESULT * phr,
		__in_opt LPCWSTR pName);
#endif
	virtual ~GSDXMuxOutputPin();
	// overwrite GSMuxOutputPin
	virtual STDMETHODIMP NonDelegatingQueryInterface(REFIID riid, __deref_out void **ppv);
	virtual HRESULT CompleteConnect(IPin *pReceivePin);
	virtual HRESULT BreakConnect();
	//from GSDXShareOutputPin
	virtual HRESULT GetD3DFilter(IGSDXShareFilter*& pFilter);
};

class GSDXMuxStream : public GSMuxStream, public GSDXShareOutputPin

{
	friend class GSMuxFilter;
public:

	GSDXMuxStream(__in_opt LPCTSTR pObjectName,
		__inout GSMuxFilter *pms,
		__inout HRESULT *phr,
		__in_opt LPCWSTR pName);
#ifdef UNICODE
	GSDXMuxStream(__in_opt LPCSTR pObjectName,
		__inout GSMuxFilter *pms,
		__inout HRESULT *phr,
		__in_opt LPCWSTR pName);
#endif
	virtual ~GSDXMuxStream(void);  // virtual destructor ensures derived class destructors are called too.
	// overwrite GSMuxStream
	virtual STDMETHODIMP NonDelegatingQueryInterface(REFIID riid, __deref_out void **ppv);
	virtual HRESULT CompleteConnect(IPin *pReceivePin);
	virtual HRESULT BreakConnect();
	//from GSDXShareOutputPin
	virtual HRESULT GetD3DFilter(IGSDXShareFilter*& pFilter);
};

class GSDXMuxFilter : public GSMuxFilter, public GSDXFilterBase, public GSDXShareFilter
{
public:
	GSDXMuxFilter(__in_opt LPCTSTR , __inout_opt LPUNKNOWN, REFCLSID clsid);
#ifdef UNICODE
	GSDXMuxFilter(__in_opt LPCSTR , __inout_opt LPUNKNOWN, REFCLSID clsid);
#endif
	virtual ~GSDXMuxFilter();
	virtual STDMETHODIMP NonDelegatingQueryInterface(REFIID riid, __deref_out void **ppv);
	// from GSDXShareFilter
	virtual HRESULT QueryD3DDeviceCS(IGSDXSharePin* pPin, CCritSec*& cs);
	virtual HRESULT QueryD3DDevice(IGSDXSharePin* pPin, ID3D11Device*& outDevice,
		ID3D11DeviceContext*& outDeviceContext, IDXGISwapChain*& outSwapChain);

	//overwrite GSMuxFilter functions
	virtual HRESULT GetMediaType(int iPosition, const IPin* pOutPin, __inout CMediaType *pMediaType);
	
protected: //default Response Functions
	static HRESULT __stdcall CompleteConnect_InitD3D(void* self, PIN_DIRECTION direction, const IPin* pMyPin, const IPin* pOtherPin);
	static HRESULT __stdcall Transform_D3DRender(void* self, IMediaSample *pInSample, CMediaType* pInMT, 
		IMediaSample *pOutSample, CMediaType* pOutMT);
	static HRESULT __stdcall BreakConnect_ReleaseD3D(void* self, PIN_DIRECTION dir, const IPin* pPin);
	// Response Functions needs
	virtual HRESULT GetEffectFilePath(WCHAR* szPath, UINT szSize);
};

