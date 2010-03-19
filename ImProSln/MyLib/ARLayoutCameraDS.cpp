#include "ARLayoutCameraDS.h"

ARLayoutCameraDS::ARLayoutCameraDS(void)
{
	m_pARLayoutFilter = NULL;
	m_pIARLayoutFilter = NULL;	
	m_pARLayoutOutputPin = NULL;

	m_pDXRenderFilter = NULL;
	m_pIDXRenderFilter = NULL;
	m_pDXRenderInputPin = NULL;

	m_pCamWarpFilter = NULL;
	m_pICamWarpFilter = NULL;
	m_pCamWarpInputPin = NULL;
	m_pCamWarpOutputPin = NULL;

	m_pARWarpFilter = NULL;
	m_pIARWarpFilter = NULL;
	m_pARWarpInputPin = NULL;
	m_pARWarpOutputPin = NULL;
}

ARLayoutCameraDS::~ARLayoutCameraDS(void)
{

}
void ARLayoutCameraDS::CloseCamera()
{
	m_pARLayoutFilter = NULL;
	m_pIARLayoutFilter = NULL;	
	m_pARLayoutOutputPin = NULL;

	m_pDXRenderFilter = NULL;
	m_pIDXRenderFilter = NULL;
	m_pDXRenderInputPin = NULL;

	m_pCamWarpFilter = NULL;
	m_pICamWarpFilter = NULL;
	m_pCamWarpInputPin = NULL;
	m_pCamWarpOutputPin = NULL;

	m_pARWarpFilter = NULL;
	m_pIARWarpFilter = NULL;
	m_pARWarpInputPin = NULL;
	m_pARWarpOutputPin = NULL;
	__super::CloseCamera();

}
HRESULT ARLayoutCameraDS::ConfigFilters()
{
	HRESULT hr = __super::ConfigFilters();
	if (m_pIARWarpFilter == NULL || m_pICamWarpFilter == NULL || FAILED(hr))
	{
		return E_FAIL;
	}
		
	m_pIARWarpFilter->SetIsFlipY(false);
	m_pICamWarpFilter->SetIsFlipY(false);

	return S_OK;
}

HRESULT ARLayoutCameraDS::ConnectGraph()
{
	HRESULT hr;
	hr = m_pGraph->Connect(m_pARLayoutOutputPin, m_pARWarpInputPin);
	hr = m_pGraph->Connect(m_pARWarpOutputPin, m_pDXRenderInputPin);

	hr = m_pGraph->Connect(m_pCameraOutput, m_pCamWarpInputPin);
	hr = m_pGraph->Connect(m_pCamWarpOutputPin, m_pGrabberInput);
	hr = m_pGraph->Connect(m_pGrabberOutput, m_pRenderInputPin);


	return S_OK;
}
HRESULT ARLayoutCameraDS::CreateFilters(int nCamID, bool bDisplayProperties, int nWidth, int nHeight)
{
	HRESULT hr = __super::CreateFilters(nCamID, bDisplayProperties, nWidth, nHeight);
	if (FAILED(hr))
		return hr;

	hr = CoCreateInstance(CLSID_ARLayoutFilter, NULL, CLSCTX_INPROC_SERVER, 
		IID_IBaseFilter, (LPVOID *)&m_pARLayoutFilter);
	hr = m_pARLayoutFilter->QueryInterface(IID_IARLayoutDXFilter,(LPVOID *) &m_pIARLayoutFilter);

	hr = CoCreateInstance(CLSID_HomoWarpFilter, NULL, CLSCTX_INPROC_SERVER, 
		IID_IBaseFilter, (LPVOID *)&m_pARWarpFilter);
	hr = m_pARWarpFilter->QueryInterface(IID_IHomoWarpFilter, (LPVOID *)&m_pIARWarpFilter);

	hr = CoCreateInstance(CLSID_DXRenderFilter, NULL, CLSCTX_INPROC_SERVER, 
		IID_IBaseFilter, (LPVOID *)&m_pDXRenderFilter);
	hr = m_pDXRenderFilter->QueryInterface(IID_IDXRenderer, (LPVOID *)&m_pIDXRenderFilter); 


	hr = CoCreateInstance(CLSID_HomoWarpFilter, NULL, CLSCTX_INPROC_SERVER, 
		IID_IBaseFilter, (LPVOID *)&m_pCamWarpFilter);
	hr = m_pCamWarpFilter->QueryInterface(IID_IHomoWarpFilter, (LPVOID *)&m_pICamWarpFilter);


	hr = m_pARLayoutFilter->FindPin(L"Layout", &m_pARLayoutOutputPin);
	hr = m_pARWarpFilter->FindPin(L"input", &m_pARWarpInputPin);
	hr = m_pARWarpFilter->FindPin(L"d3dsurf", &m_pARWarpOutputPin);
	hr = m_pDXRenderFilter->FindPin(L"In", &m_pDXRenderInputPin);

	hr = m_pCamWarpFilter->FindPin(L"input", &m_pCamWarpInputPin);
	hr = m_pCamWarpFilter->FindPin(L"output", &m_pCamWarpOutputPin);
	
	hr = m_pGraph->AddFilter(m_pARLayoutFilter, L"ARLayout");
	hr = m_pGraph->AddFilter(m_pARWarpFilter, L"AR HomoWarp");
	hr = m_pGraph->AddFilter(m_pDXRenderFilter, L"DXRender");
	hr = m_pGraph->AddFilter(m_pCamWarpFilter, L"Cam HomoWarp");

	return S_OK;
}

HRESULT ARLayoutCameraDS::ShowDXRenderProp()
{
	return ShowFilterProp(m_pDXRenderFilter);
}
HRESULT ARLayoutCameraDS::ShowARLayoutProp()
{
	return ShowFilterProp(m_pARLayoutFilter);
}
HRESULT ARLayoutCameraDS::ShowARWarpProp()
{
	return ShowFilterProp(m_pARWarpFilter);
}
HRESULT ARLayoutCameraDS::ShowCamWarpProp()
{
	return ShowFilterProp(m_pCamWarpFilter);
}
int ARLayoutCameraDS::GetNumMarker()
{
	if (m_pIARLayoutFilter == NULL)
		return 0;
	return m_pIARLayoutFilter->GetNumMarker();
}
HRESULT ARLayoutCameraDS::SetMarkerVisible(int idx, BOOL bVisible)
{
	if (m_pIARLayoutFilter == NULL)
		return 0;
	return m_pIARLayoutFilter->SetMarkerVisible(idx, bVisible);
}
HRESULT ARLayoutCameraDS::SetMarkerVisibleByID(int id, BOOL bVisible)
{
	if (m_pIARLayoutFilter == NULL)
		return 0;
	return m_pIARLayoutFilter->SetMarkerVisibleByID(id, bVisible);
	
}
int ARLayoutCameraDS::GetMarkerID(int idx)
{
	if (m_pIARLayoutFilter == NULL)
		return -1;
	return m_pIARLayoutFilter->GetMarkerID(idx);
}
