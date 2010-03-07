#include "D3DBaseFilter.h"

D3DBasePin::D3DBasePin()
{
	m_pConnectedPin = NULL;
}
D3DBasePin::~D3DBasePin()
{
	if (m_pConnectedPin != NULL)
	{
		m_pConnectedPin->Release();
		m_pConnectedPin = NULL;
	}
}

HRESULT D3DBasePin::SetConnectedPin(IDXBasePin* pPin)
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
HRESULT D3DBasePin::GetConnectedPin(IDXBasePin*& pPin)
{
	pPin = m_pConnectedPin;
	return S_OK;
}
HRESULT D3DBaseInputPin::QueryD3DDevice(IDirect3DDevice9*& outDevice)
{
	HRESULT hr = S_OK;
	IDXBasePin* connectedPin = NULL;
	GetConnectedPin(connectedPin);
	if (connectedPin == NULL)
		return S_FALSE;
	
	hr = connectedPin->QueryD3DDevice(outDevice);
	return hr;
}

HRESULT D3DBaseOutputPin::QueryD3DDevice(IDirect3DDevice9*& outDevice)
{
	IDXBaseFilter* pFilter = NULL;
	GetD3DFilter(pFilter);
	if (pFilter == NULL)
		return S_FALSE;
	return ((D3DBaseFilter*)pFilter)->QueryD3DDevice(this, outDevice);
}

