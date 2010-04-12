#include "stdafx.h"
#include "GSDXShareFilter.h"

GSDXSharePin::GSDXSharePin()
{
	m_pConnectedPin = NULL;
}
GSDXSharePin::~GSDXSharePin()
{
	if (m_pConnectedPin != NULL)
	{
		m_pConnectedPin->Release();
		m_pConnectedPin = NULL;
	}
}

HRESULT GSDXSharePin::SetConnectedPin(IGSDXSharePin* pPin)
{
	if (m_pConnectedPin != NULL)
	{
		m_pConnectedPin->Release();
		m_pConnectedPin = NULL;
	}
	m_pConnectedPin = pPin;
	if (m_pConnectedPin != NULL)
	{
		m_pConnectedPin->AddRef();
	}
	return S_OK;
}
HRESULT GSDXSharePin::GetConnectedPin(IGSDXSharePin*& pPin)
{
	pPin = m_pConnectedPin;
	return S_OK;
}
HRESULT GSDXShareInputPin::QueryD3DDevice(ID3D11Device*& outDevice, ID3D11DeviceContext*& outDeviceContext, IDXGISwapChain*& outSwapChain)
{
	HRESULT hr = S_OK;
	IGSDXSharePin* connectedPin = NULL;
	GetConnectedPin(connectedPin);
	if (connectedPin == NULL)
		return S_FALSE;

	hr = connectedPin->QueryD3DDevice(outDevice, outDeviceContext, outSwapChain);
	return hr;
}

HRESULT GSDXShareInputPin::QueryD3DDeviceCS(CCritSec*& cs)
{
	HRESULT hr = S_OK;
	IGSDXSharePin* connectedPin = NULL;
	GetConnectedPin(connectedPin);
	if (connectedPin == NULL)
		return S_FALSE;

	hr = connectedPin->QueryD3DDeviceCS(cs);
	return hr;
}

HRESULT GSDXShareOutputPin::QueryD3DDevice(ID3D11Device*& outDevice, ID3D11DeviceContext*& outDeviceContext, IDXGISwapChain*& outSwapChain)
{
	IGSDXShareFilter* pFilter = NULL;
	GetD3DFilter(pFilter);
	if (pFilter == NULL)
		return S_FALSE;
	return pFilter->QueryD3DDevice(this, outDevice, outDeviceContext, outSwapChain);
}
HRESULT GSDXShareOutputPin::QueryD3DDeviceCS(CCritSec*& cs)
{
	IGSDXShareFilter* pFilter = NULL;
	GetD3DFilter(pFilter);
	if (pFilter == NULL)
		return S_FALSE;
	return pFilter->QueryD3DDeviceCS(this, cs);
}