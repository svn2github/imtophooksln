#include "stdafx.h"
#include "GSDXMuxFilter.h"


GSDXMuxInputPin::GSDXMuxInputPin(
		__in_opt LPCTSTR pObjectName,
		__inout GSMuxFilter *pTransformFilter,
		__inout HRESULT * phr,
		__in_opt LPCWSTR pName) : GSMuxInputPin(pObjectName, pTransformFilter, phr, pName)
{

}
#ifdef UNICODE
GSDXMuxInputPin::GSDXMuxInputPin(
		__in_opt LPCSTR pObjectName,
		__inout GSMuxFilter *pTransformFilter,
		__inout HRESULT * phr,
		__in_opt LPCWSTR pName) : GSMuxInputPin(pObjectName, pTransformFilter, phr, pName)
{

}
#endif
GSDXMuxInputPin::~GSDXMuxInputPin()
{

}
HRESULT GSDXMuxInputPin::NonDelegatingQueryInterface(REFIID riid, __deref_out void **ppv)
{
	if (riid == IID_IGSDXSharePin) 
	{
		return GetInterface(static_cast<IGSDXSharePin*>(this), ppv);
	}
	else
	{
		// Call the parent class.
		return __super::NonDelegatingQueryInterface(riid, ppv);
	}
}
HRESULT GSDXMuxInputPin::CompleteConnect(IPin *pReceivePin)
{
	HRESULT hr = S_OK;
	IGSDXSharePin* pDXPin = NULL;
	hr = pReceivePin->QueryInterface(IID_IGSDXSharePin, (void**)&pDXPin);
	if (pDXPin != NULL)
	{
		SetConnectedPin(pDXPin);
		pDXPin->Release();
		pDXPin = NULL;
	}
	hr = __super::CompleteConnect(pReceivePin);
	if (FAILED(hr)) {
		SetConnectedPin(NULL);
		return hr;
	}
	return hr;	
}
HRESULT GSDXMuxInputPin::BreakConnect()
{
	HRESULT hr = S_OK;
	hr = __super::BreakConnect();
	if (SUCCEEDED(hr))
		SetConnectedPin(NULL);
	return hr; 
}
GSDXMuxOutputPin::GSDXMuxOutputPin(
		__in_opt LPCTSTR pObjectName,
		__inout GSMuxFilter *pTransformFilter,
		__inout HRESULT * phr,
		__in_opt LPCWSTR pName) : GSMuxOutputPin(pObjectName, pTransformFilter, phr, pName)
{

}
#ifdef UNICODE
GSDXMuxOutputPin::GSDXMuxOutputPin(
		__in_opt LPCSTR pObjectName,
		__inout GSMuxFilter *pTransformFilter,
		__inout HRESULT * phr,
		__in_opt LPCWSTR pName) : GSMuxOutputPin(pObjectName, pTransformFilter, phr, pName)
{

}
#endif
GSDXMuxOutputPin::~GSDXMuxOutputPin()
{

}

HRESULT GSDXMuxOutputPin::NonDelegatingQueryInterface(REFIID riid, __deref_out void **ppv)
{
	if (riid == IID_IGSDXSharePin) 
	{
		return GetInterface(static_cast<IGSDXSharePin*>(this), ppv);
	}
	else
	{
		// Call the parent class.
		return __super::NonDelegatingQueryInterface(riid, ppv);
	}
}

HRESULT GSDXMuxOutputPin::CompleteConnect(IPin *pReceivePin)
{
	HRESULT hr = S_OK;
	IGSDXSharePin* pDXPin = NULL;
	hr = pReceivePin->QueryInterface(IID_IGSDXSharePin, (void**)&pDXPin);
	if (pDXPin != NULL)
	{
		SetConnectedPin(pDXPin);
		pDXPin->Release();
		pDXPin = NULL;
	}
	hr = __super::CompleteConnect(pReceivePin);
	if (FAILED(hr)) {
		SetConnectedPin(NULL);
		return hr;
	}
	return hr;	
}

HRESULT GSDXMuxOutputPin::BreakConnect()
{
	HRESULT hr = S_OK;
	hr = __super::BreakConnect();
	if (SUCCEEDED(hr))
		SetConnectedPin(NULL);
	return hr; 
}

GSDXMuxStream::GSDXMuxStream(__in_opt LPCTSTR pObjectName,
		__inout GSMuxFilter *pms,
		__inout HRESULT *phr,
		__in_opt LPCWSTR pName) : GSMuxStream(pObjectName, pms, phr, pName)
{

}
#ifdef UNICODE
GSDXMuxStream::GSDXMuxStream(__in_opt LPCSTR pObjectName,
		__inout GSMuxFilter *pms,
		__inout HRESULT *phr,
		__in_opt LPCWSTR pName) : GSMuxStream(pObjectName, pms, phr, pName)
{

}
#endif
GSDXMuxStream::~GSDXMuxStream(void)
{
		
}

HRESULT GSDXMuxStream::NonDelegatingQueryInterface(REFIID riid, __deref_out void **ppv)
{
	if (riid == IID_IGSDXSharePin) 
	{
		return GetInterface(static_cast<IGSDXSharePin*>(this), ppv);
	}
	else
	{
		// Call the parent class.
		return __super::NonDelegatingQueryInterface(riid, ppv);
	}
}

HRESULT GSDXMuxStream::CompleteConnect(IPin *pReceivePin)
{
	HRESULT hr = S_OK;
	IGSDXSharePin* pDXPin = NULL;
	hr = pReceivePin->QueryInterface(IID_IGSDXSharePin, (void**)&pDXPin);
	if (pDXPin != NULL)
	{
		SetConnectedPin(pDXPin);
		pDXPin->Release();
		pDXPin = NULL;
	}
	hr = __super::CompleteConnect(pReceivePin);
	if (FAILED(hr)) {
		SetConnectedPin(NULL);
		return hr;
	}
	return hr;	
}
HRESULT GSDXMuxStream::BreakConnect()
{
	HRESULT hr = S_OK;
	hr = __super::BreakConnect();
	if (SUCCEEDED(hr))
		SetConnectedPin(NULL);
	return hr; 
}


GSDXMuxFilter::GSDXMuxFilter(__in_opt LPCTSTR pName, __inout_opt LPUNKNOWN pUnk, REFCLSID  clsid) : GSMuxFilter(pName, pUnk, clsid)
{

}

#ifdef UNICODE
GSDXMuxFilter::GSDXMuxFilter(__in_opt LPCSTR pName, __inout_opt LPUNKNOWN pUnk, REFCLSID  clsid) : GSMuxFilter(pName, pUnk, clsid)
{

}
#endif

GSDXMuxFilter::~GSDXMuxFilter()
{

}


HRESULT GSDXMuxFilter::NonDelegatingQueryInterface(REFIID riid, __deref_out void **ppv)
{
	if (riid == IID_IGSDXShareFilter) 
	{
		return GetInterface(static_cast<IGSDXShareFilter*>(this), ppv);
	}
	else
	{
		// Call the parent class.
		return __super::NonDelegatingQueryInterface(riid, ppv);
	}
}


