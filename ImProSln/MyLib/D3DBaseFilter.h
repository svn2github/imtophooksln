#pragma once
#include "dshow.h"
#include "Streams.h"
#include <initguid.h>
#include "combase.h"
#include <d3d9.h>

// {073A6A32-43E9-43e4-9C39-56B7D8049681}
DEFINE_GUID(GUID_D3DMEDIATYPE, 
			0x73a6a32, 0x43e9, 0x43e4, 0x9c, 0x39, 0x56, 0xb7, 0xd8, 0x4, 0x96, 0x81);

// {619A00B3-63BF-430c-93A5-01A73235BDCA}
DEFINE_GUID(GUID_D3DXTEXTURE9_POINTER, 
			0x619a00b3, 0x63bf, 0x430c, 0x93, 0xa5, 0x1, 0xa7, 0x32, 0x35, 0xbd, 0xca);

// {4C6C3CB6-012A-4b92-8856-09C543C5B412}
DEFINE_GUID(GUID_D3DSHARE_RTTEXTURE_POINTER, 
			0x4c6c3cb6, 0x12a, 0x4b92, 0x88, 0x56, 0x9, 0xc5, 0x43, 0xc5, 0xb4, 0x12);

// {F6DE4088-A0E1-49f9-9401-34576F948052}
DEFINE_GUID(GUID_FORMATTYPE_D3DXTEXTURE9DESC, 
			0xf6de4088, 0xa0e1, 0x49f9, 0x94, 0x1, 0x34, 0x57, 0x6f, 0x94, 0x80, 0x52);

// {898D165E-0360-4587-B36F-5BF957EBF0E3}
DEFINE_GUID(IID_IDXBasePin, 
			0x898d165e, 0x360, 0x4587, 0xb3, 0x6f, 0x5b, 0xf9, 0x57, 0xeb, 0xf0, 0xe3);

// {E8DD41CD-403F-4cf9-9C53-133767A0A2C4}
DEFINE_GUID(IID_IDXBaseFilter, 
			0xe8dd41cd, 0x403f, 0x4cf9, 0x9c, 0x53, 0x13, 0x37, 0x67, 0xa0, 0xa2, 0xc4);

interface IDXBaseFilter;

MIDL_INTERFACE("898D165E-0360-4587-B36F-5BF957EBF0E3")
IDXBasePin : public IUnknown
{
public:
	virtual HRESULT SetConnectedPin(IDXBasePin* pPin) = 0;
	virtual HRESULT GetD3DFilter(IDXBaseFilter*& pFilter) = 0;
	virtual HRESULT GetConnectedPin(IDXBasePin*& pPin) = 0;
	virtual HRESULT QueryD3DDevice(IDirect3DDevice9*& outDevice) = 0;
};

MIDL_INTERFACE("E8DD41CD-403F-4cf9-9C53-133767A0A2C4")
IDXBaseFilter : public IUnknown
{
public:
	virtual HRESULT QueryD3DDevice(IDXBasePin* pPin, IDirect3DDevice9*& outDevice) = 0;
};

class D3DBasePin;
class D3DBaseFilter : public IDXBaseFilter
{
public:
	/////have to be overwrite by child class////////
	virtual HRESULT QueryD3DDevice(IDXBasePin* pPin, IDirect3DDevice9*& outDevice) {return E_NOTIMPL; };
};

class D3DBasePin : public IDXBasePin
{
protected:
	IDXBasePin* m_pConnectedPin;
	
public:

	D3DBasePin();
	~D3DBasePin();
	virtual HRESULT SetConnectedPin(IDXBasePin* pPin);
	virtual HRESULT GetConnectedPin(IDXBasePin*& pPin);
	virtual HRESULT GetD3DFilter(IDXBaseFilter*& pFilter) = 0;
	virtual HRESULT QueryD3DDevice(IDirect3DDevice9*& outDevice) = 0;
};

class D3DBaseOutputPin : public D3DBasePin
{
public:
	virtual HRESULT GetD3DFilter(IDXBaseFilter*& pFilter){return E_NOTIMPL;};
	virtual HRESULT QueryD3DDevice(IDirect3DDevice9*& outDevice);
};

class D3DBaseInputPin : public D3DBasePin
{
public:
	virtual HRESULT GetD3DFilter(IDXBaseFilter*& pFilter) {return E_NOTIMPL;};
	virtual HRESULT QueryD3DDevice(IDirect3DDevice9*& outDevice);
};