#include "StdAfx.h"
#include "TestCamera.h"

TestCamera::TestCamera(void)
{
	m_pARLayoutFilter = NULL;
	m_pARLayoutInputConfigPin = NULL;
	m_pARLayoutOutputPin = NULL;

	m_pTouchLibFilter = NULL;
	m_pTouchLibInputPin = NULL;
	m_pTouchLibOutputPin = NULL;
	m_pTouchLibFGOutPin = NULL;

	m_pAR2WarpFilter = NULL;
	m_pAR2WarpInputTouchPin = NULL;
	m_pAR2WarpOutputARConfigPin = NULL;

}

TestCamera::~TestCamera(void)
{
	m_pARLayoutFilter = NULL;
	m_pARLayoutInputConfigPin = NULL;
	m_pARLayoutOutputPin = NULL;

	m_pTouchLibFilter = NULL;
	m_pTouchLibInputPin = NULL;
	m_pTouchLibOutputPin = NULL;
	m_pTouchLibFGOutPin = NULL;

	m_pAR2WarpFilter = NULL;
	m_pAR2WarpInputTouchPin = NULL;
	m_pAR2WarpOutputARConfigPin = NULL;
}
HRESULT TestCamera::ConnectGraph()
{
	HRESULT hr;
	hr = m_pGraph->Connect(m_pARLayoutOutputPin, m_pTouchLibInputPin);
	hr = m_pGraph->Connect(m_pTouchLibOutputPin, m_pDXRendererInputPin);
	hr = m_pGraph->Connect(m_pTouchLibFGOutPin, m_pAR2WarpInputTouchPin);
	hr = m_pGraph->Connect(m_pAR2WarpOutputARConfigPin, m_pARLayoutInputConfigPin);
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


	hr = CoCreateInstance(CLSID_ARLayoutFilter, NULL, CLSCTX_INPROC_SERVER, 
		IID_IBaseFilter, (LPVOID *)&m_pARLayoutFilter);
	
	hr = CoCreateInstance(CLSID_TouchLibFilter, NULL, CLSCTX_INPROC_SERVER, 
		IID_IBaseFilter, (LPVOID *)&m_pTouchLibFilter);
	
	hr = CoCreateInstance(CLSID_AR2WarpController, NULL, CLSCTX_INPROC_SERVER, 
		IID_IBaseFilter, (LPVOID *)&m_pAR2WarpFilter);


	hr = m_pARLayoutFilter->FindPin(L"config", &m_pARLayoutInputConfigPin);	
	hr = m_pARLayoutFilter->FindPin(L"Layout", &m_pARLayoutOutputPin);
	
	hr = m_pTouchLibFilter->FindPin(L"input", &m_pTouchLibInputPin);
	hr = m_pTouchLibFilter->FindPin(L"output", &m_pTouchLibOutputPin);
	hr = m_pTouchLibFilter->FindPin(L"foreground", &m_pTouchLibFGOutPin);
	

	hr = m_pAR2WarpFilter->FindPin(L"touch result", &m_pAR2WarpInputTouchPin);
	hr = m_pAR2WarpFilter->FindPin(L"ARLayout config", &m_pAR2WarpOutputARConfigPin);

	m_pGraph->AddFilter(m_pDXRenderer, L"DXRenderer");
	m_pGraph->AddFilter(m_pHomoWarpFilter, L"DXRenderer");
	m_pGraph->AddFilter(m_pARLayoutFilter, L"ARLayout");
	m_pGraph->AddFilter(m_pTouchLibFilter, L"TouchLib");
	m_pGraph->AddFilter(m_pAR2WarpFilter, L"AR2Warp");

	return __super::CreateFilters(nCamID, bDisplayProperties, nWidth, nHeight);
}