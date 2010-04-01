#include "ARLayoutCameraDS.h"

ARLayoutCameraDS::ARLayoutCameraDS(void)
{
	m_pARLayoutFilter = NULL;
	m_pIARLayoutFilter = NULL;	
	m_pARLayoutOutputPin = NULL;

	m_pDXRenderFilter = NULL;
	m_pIDXRenderFilter = NULL;
	m_pDXRenderInputPin = NULL;
	for (int i =0; i < NUMCAM; i++)
	{
		m_pCamFilter[i] = NULL;
		m_pCamWarpFilter[i] = NULL;
		m_pICamWarpFilter[i] = NULL;
		m_pCamWarpInputPin[i] = NULL;
		m_pCamWarpOutputPin[i] = NULL;
		m_pCamOutputPin[i] = NULL;
	}

	m_pARWarpFilter = NULL;
	m_pIARWarpFilter = NULL;
	m_pARWarpInputPin = NULL;
	m_pARWarpOutputPin = NULL;


	m_pDXBlendFilter = NULL;
	m_pIDXBlendFilter = NULL;
	for (int i =0; i < DXBLEND_PINNUM; i++)
		m_pDXBlendInputPin[i] = NULL;

	m_pDXBlendOutputPin = NULL;

	
	
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

	for (int i =0; i < NUMCAM; i++)
	{
		m_pCamFilter[i] = NULL;
		m_pCamOutputPin[i] = NULL;
		m_pCamWarpFilter[i] = NULL;
		
		m_pICamWarpFilter[i] = NULL;
		m_pCamWarpInputPin[i] = NULL;
		m_pCamWarpOutputPin[i] = NULL;
	}
	m_pARWarpFilter = NULL;
	m_pIARWarpFilter = NULL;
	m_pARWarpInputPin = NULL;
	m_pARWarpOutputPin = NULL;

	m_pDXBlendFilter = NULL;
	for (int i =0; i < DXBLEND_PINNUM; i++)
	{
		m_pDXBlendInputPin[i] = NULL;
	}
	m_pDXBlendOutputPin = NULL;

	__super::CloseCamera();

}

HRESULT ARLayoutCameraDS::AddCamera(int nCamID, bool bDisplayProperties)
{
	int idx = -1;
	for (int i =0; i < NUMCAM; i++)
	{
		if (m_pCamFilter[i] == NULL)
		{
			idx = i;
			break;
		}
	}
	if (idx < 0 )
		return E_FAIL;
	OAFilterState fstate;
	m_pMediaControl->GetState(1000, &fstate);
	if (fstate != State_Stopped)
	{
		return E_FAIL;
	}
	HRESULT hr = S_OK;

	BindFilter(nCamID, &m_pCamFilter[idx]);
	CComPtr<IEnumPins> pEnum;
	m_pCamFilter[idx]->EnumPins(&pEnum);
	hr = pEnum->Reset();
	hr = pEnum->Next(1, &m_pCamOutputPin[idx], NULL);
	
	if (m_pCamWarpFilter[idx] != NULL)
	{
		m_pGraph->RemoveFilter(m_pCamWarpFilter[idx]);
		m_pCamWarpFilter[idx] = NULL;
		m_pCamWarpInputPin[idx] = NULL;
		m_pCamWarpOutputPin[idx] = NULL;
	}

	hr = CoCreateInstance(CLSID_HomoWarpFilter, NULL, CLSCTX_INPROC_SERVER, 
		IID_IBaseFilter, (LPVOID *)&m_pCamWarpFilter[idx]);
	
	hr = m_pCamWarpFilter[idx]->QueryInterface(IID_IHomoWarpFilter, (LPVOID *)&m_pICamWarpFilter[idx]);
	hr = m_pCamWarpFilter[idx]->FindPin(L"input", &m_pCamWarpInputPin[idx]);
	hr = m_pCamWarpFilter[idx]->FindPin(L"d3dsurf", &m_pCamWarpOutputPin[idx]);
	WCHAR str[MAX_PATH] = {0};
	swprintf_s(str, MAX_PATH, L"Camera%d", idx);
	hr = m_pGraph->AddFilter(m_pCamFilter[idx], str);
	swprintf_s(str, MAX_PATH, L"Cam%d HomoWarp", idx);
	hr = m_pGraph->AddFilter(m_pCamWarpFilter[idx], str);

	ShowFilterProp(m_pCamOutputPin[idx]);
	m_pGraph->Connect(m_pCamOutputPin[idx], m_pCamWarpInputPin[idx]);
	m_pGraph->Connect(m_pCamWarpOutputPin[idx], m_pDXBlendInputPin[idx]);

	return S_OK;
}
HRESULT ARLayoutCameraDS::RemoveCamera(int idx)
{
	if (idx < 0 || idx > NUMCAM)
		return E_FAIL;
	if (m_pCamFilter[idx] == NULL || m_pGraph == NULL)
		return E_FAIL;
	HRESULT hr = S_OK;
	hr = m_pGraph->RemoveFilter(m_pCamFilter[idx]);
	hr = m_pGraph->RemoveFilter(m_pCamWarpFilter[idx]);
	m_pCamFilter[idx] = NULL;
	m_pCamOutputPin[idx] = NULL;
	m_pCamWarpFilter[idx] = NULL;
	m_pCamWarpInputPin[idx] = NULL;
	m_pCamWarpOutputPin[idx] = NULL;
	return S_OK;
}
HRESULT ARLayoutCameraDS::ConfigFilters()
{
	HRESULT hr = __super::ConfigFilters();
	if (m_pIARWarpFilter == NULL || m_pICamWarpFilter == NULL || FAILED(hr))
	{
		return E_FAIL;
	}
		
	m_pIARWarpFilter->SetIsFlipY(false);
	for (int i =0; i < NUMCAM; i++)
	{
		if (m_pICamWarpFilter[i] == NULL)
			continue;
		m_pICamWarpFilter[i]->SetIsFlipY(true);
	}
	return S_OK;
}

HRESULT ARLayoutCameraDS::ConnectGraph()
{
	HRESULT hr;
	hr = m_pGraph->Connect(m_pARLayoutOutputPin, m_pARWarpInputPin);
	hr = m_pGraph->Connect(m_pARWarpOutputPin, m_pDXRenderInputPin);

	hr = m_pGraph->Connect(m_pCameraOutput, m_pCamWarpInputPin[0]);
	hr = m_pGraph->Connect(m_pCamWarpOutputPin[0], m_pDXBlendInputPin[0]);
	hr = m_pGraph->Connect(m_pDXBlendOutputPin, m_pGrabberInput);
	hr = m_pGraph->Connect(m_pGrabberOutput, m_pRenderInputPin);


	return S_OK;
}
HRESULT ARLayoutCameraDS::CreateFilters(int nCamID, bool bDisplayProperties, int nWidth, int nHeight)
{
	HRESULT hr = __super::CreateFilters(nCamID, bDisplayProperties, nWidth, nHeight);
	if (FAILED(hr))
		return hr;
	m_pCamFilter[0] = m_pDeviceFilter;
	m_pCamOutputPin[0] = m_pCameraOutput;
	WCHAR str[MAX_PATH] = {0};
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
		IID_IBaseFilter, (LPVOID *)&m_pCamWarpFilter[0]);
	hr = m_pCamWarpFilter[0]->QueryInterface(IID_IHomoWarpFilter, (LPVOID *)&m_pICamWarpFilter[0]);
	
	hr = CoCreateInstance(CLSID_DXBlendFilter, NULL, CLSCTX_INPROC_SERVER, 
		IID_IBaseFilter, (LPVOID *)&m_pDXBlendFilter);
	hr = m_pDXBlendFilter->QueryInterface(IID_IDXBlendFilter, (LPVOID *)&m_pIDXBlendFilter);

	for (int i =0; i <DXBLEND_PINNUM; i++)
	{
		swprintf_s(str, MAX_PATH, L"input%d", i);
		hr = m_pDXBlendFilter->FindPin(str, &m_pDXBlendInputPin[i]);
	}
	hr = m_pDXBlendFilter->FindPin(L"output", &m_pDXBlendOutputPin);


	hr = m_pARLayoutFilter->FindPin(L"Layout", &m_pARLayoutOutputPin);
	hr = m_pARWarpFilter->FindPin(L"input", &m_pARWarpInputPin);
	hr = m_pARWarpFilter->FindPin(L"d3dsurf", &m_pARWarpOutputPin);
	hr = m_pDXRenderFilter->FindPin(L"In", &m_pDXRenderInputPin);

	hr = m_pCamWarpFilter[0]->FindPin(L"input", &m_pCamWarpInputPin[0]);
	hr = m_pCamWarpFilter[0]->FindPin(L"d3dsurf", &m_pCamWarpOutputPin[0]);
	
	




	hr = m_pGraph->AddFilter(m_pARLayoutFilter, L"ARLayout");
	hr = m_pGraph->AddFilter(m_pARWarpFilter, L"AR HomoWarp");
	hr = m_pGraph->AddFilter(m_pDXRenderFilter, L"DXRender");
	hr = m_pGraph->AddFilter(m_pCamWarpFilter[0], L"Cam HomoWarp");
	hr = m_pGraph->AddFilter(m_pDXBlendFilter, L"DXBlend");
	return S_OK;
}

HRESULT ARLayoutCameraDS::ShowDXRenderProp()
{
	return ShowFilterProp(m_pDXRenderFilter);
}
HRESULT ARLayoutCameraDS::ShowDXBlendProp()
{
	return ShowFilterProp(m_pDXBlendFilter);
}
HRESULT ARLayoutCameraDS::ShowARLayoutProp()
{
	return ShowFilterProp(m_pARLayoutFilter);
}
HRESULT ARLayoutCameraDS::ShowARWarpProp()
{
	return ShowFilterProp(m_pARWarpFilter);
}
HRESULT ARLayoutCameraDS::ShowCamWarpProp(int idx)
{
	return ShowFilterProp(m_pCamWarpFilter[idx]);
}
HRESULT ARLayoutCameraDS::ShowCamProp(int idx)
{
	if (idx < 0 || idx > NUMCAM || m_pCamFilter[idx] == NULL)
		return E_FAIL;
	return ShowFilterProp(m_pCamFilter[idx]);
}
HRESULT ARLayoutCameraDS::ShowCamPinProp(int idx)
{
	if (idx < 0 || idx > NUMCAM || m_pCamOutputPin[idx] == NULL)
		return E_FAIL;
	return ShowFilterProp(m_pCamOutputPin[idx]);
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
