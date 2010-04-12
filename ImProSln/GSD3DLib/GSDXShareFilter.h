#pragma once
#include "dshow.h"
#include "Streams.h"
#include <initguid.h>
#include "combase.h"
#include <D3D11.h>
#include <D3DX11.h>
// {7093A7B9-D31D-49b6-A43B-5D8300910390}
DEFINE_GUID(IID_IGSDXSharePin, 
			0x7093a7b9, 0xd31d, 0x49b6, 0xa4, 0x3b, 0x5d, 0x83, 0x0, 0x91, 0x3, 0x90);


// {581540A6-1FC5-4690-9F9A-9663BBFA8D94}
DEFINE_GUID(IID_IGSDXShareFilter, 
			0x581540a6, 0x1fc5, 0x4690, 0x9f, 0x9a, 0x96, 0x63, 0xbb, 0xfa, 0x8d, 0x94);

interface IGSDXShareFilter;

MIDL_INTERFACE("7093A7B9-D31D-49b6-A43B-5D8300910390")
IGSDXSharePin : public IUnknown
{
public:
	virtual HRESULT SetConnectedPin(IGSDXSharePin* pPin) = 0;
	virtual HRESULT GetD3DFilter(IGSDXShareFilter*& pFilter) = 0;
	virtual HRESULT GetConnectedPin(IGSDXSharePin*& pPin) = 0;
	virtual HRESULT QueryD3DDevice(ID3D11Device*& outDevice, ID3D11DeviceContext*& outDeviceContext, IDXGISwapChain*& outSwapChain) = 0;
	virtual HRESULT QueryD3DDeviceCS(CCritSec*& cs) = 0;
};

MIDL_INTERFACE("581540A6-1FC5-4690-9F9A-9663BBFA8D94")
IGSDXShareFilter : public IUnknown
{
public:
	virtual HRESULT QueryD3DDeviceCS(IGSDXSharePin* pPin, CCritSec*& cs) = 0;
	virtual HRESULT QueryD3DDevice(IGSDXSharePin* pPin, ID3D11Device*& outDevice, ID3D11DeviceContext*& outDeviceContext, IDXGISwapChain*& outSwapChain) = 0;
};

class GSDXSharePin;
class GSDXShareFilter : public IGSDXShareFilter
{
public:
	/////have to be overwrite by child class////////
	virtual HRESULT QueryD3DDeviceCS(IGSDXSharePin* pPin, CCritSec*& cs) {return E_NOTIMPL; };
	virtual HRESULT QueryD3DDevice(IGSDXSharePin* pPin, ID3D11Device*& outDevice,
		ID3D11DeviceContext*& outDeviceContext, IDXGISwapChain*& outSwapChain) {return E_NOTIMPL; };
};

class GSDXSharePin : public IGSDXSharePin
{
protected:
	IGSDXSharePin* m_pConnectedPin;

public:
	GSDXSharePin();
	~GSDXSharePin();
	virtual HRESULT SetConnectedPin(IGSDXSharePin* pPin);
	virtual HRESULT GetConnectedPin(IGSDXSharePin*& pPin);
	virtual HRESULT GetD3DFilter(IGSDXShareFilter*& pFilter) = 0;
	virtual HRESULT QueryD3DDevice(ID3D11Device*& outDevice, ID3D11DeviceContext*& outDeviceContext, IDXGISwapChain*& outSwapChain) = 0;
	virtual HRESULT QueryD3DDeviceCS(CCritSec*& cs) = 0;
};

class GSDXShareOutputPin : public GSDXSharePin
{
public:
	virtual HRESULT GetD3DFilter(IGSDXShareFilter*& pFilter){return E_NOTIMPL;};
	virtual HRESULT QueryD3DDevice(ID3D11Device*& outDevice, ID3D11DeviceContext*& outDeviceContext, IDXGISwapChain*& outSwapChain);
	virtual HRESULT QueryD3DDeviceCS(CCritSec*& cs);
};

class GSDXShareInputPin : public GSDXSharePin
{
public:
	virtual HRESULT GetD3DFilter(IGSDXShareFilter*& pFilter) {return E_NOTIMPL;};
	virtual HRESULT QueryD3DDevice(ID3D11Device*& outDevice, ID3D11DeviceContext*& outDeviceContext, IDXGISwapChain*& outSwapChain);
	virtual HRESULT QueryD3DDeviceCS(CCritSec*& cs);
};