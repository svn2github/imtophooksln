#include "StdAfx.h"
#include "TestCamera.h"

TestCamera::TestCamera(void)
{
}

TestCamera::~TestCamera(void)
{
}
HRESULT TestCamera::ConnectGraph()
{
	HRESULT hr;
	hr = m_pGraph->Connect(m_pCameraOutput, m_pHomoWarpInputPin);
	hr = m_pGraph->Connect(m_pHomoWarpOutD3DPin, m_pDXRendererInputPin);
	if (FAILED(hr))
		return hr;
	return hr;
}
HRESULT TestCamera::CreateFilters(int nCamID, bool bDisplayProperties, int nWidth, int nHeight)
{
	HRESULT hr;
	hr = CoCreateInstance(CLSID_DXRenderFilter, NULL, CLSCTX_INPROC_SERVER, 
		IID_IBaseFilter, (LPVOID *)&m_pDXRenderer);
	if (FAILED(hr))
		return hr;
	hr = m_pDXRenderer->FindPin(L"In", &m_pDXRendererInputPin);	

	hr = CoCreateInstance(CLSID_HomoWarpFilter, NULL, CLSCTX_INPROC_SERVER, 
		IID_IBaseFilter, (LPVOID *)&m_pHomoWarpFilter);
	hr = m_pHomoWarpFilter->FindPin(L"input", &m_pHomoWarpInputPin);	
	hr = m_pHomoWarpFilter->FindPin(L"d3dsurf", &m_pHomoWarpOutD3DPin);


	m_pGraph->AddFilter(m_pDXRenderer, L"DXRenderer");
	m_pGraph->AddFilter(m_pHomoWarpFilter, L"DXRenderer");
	return __super::CreateFilters(nCamID, bDisplayProperties, nWidth, nHeight);
}