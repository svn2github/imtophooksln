#include "stdafx.h"
#include "ARCalibDS.h"

ARCalibDS::ARCalibDS(void)
{
	m_pARLayoutFilter = NULL;
	m_pIARLayoutFilter = NULL;	
	m_pARLayoutOutputPin = NULL;

	m_pDXCamRenderFilter = NULL;
	m_pIDXCamRenderFilter = NULL;
	m_pDXCamRenderInputPin = NULL;

	m_pDXARRenderFilter = NULL;
	m_pIDXARRenderFilter = NULL;
	m_pDXARRenderInputPin = NULL;
	
	m_pCamFilter = NULL;
	m_pCamOutputPin = NULL;
	
	m_pCamWarpFilter = NULL;
	m_pICamWarpFilter = NULL;
	m_pCamWarpInputPin = NULL;
	m_pCamWarpOutputPin = NULL;

	m_pARWarpFilter = NULL;
	m_pIARWarpFilter = NULL;
	m_pARWarpInputPin = NULL;
	m_pARWarpOutputPin = NULL;

	m_pARTagFilter = NULL;
	m_pIARTagFilter = NULL;
	m_pARTagInputPin = NULL;	
	m_pARTagOutputPin = NULL;

}

ARCalibDS::~ARCalibDS(void)
{

}

void ARCalibDS::CloseCamera(){
	m_pARLayoutFilter = NULL;
	m_pIARLayoutFilter = NULL;	
	m_pARLayoutOutputPin = NULL;

	m_pDXCamRenderFilter = NULL;
	m_pIDXCamRenderFilter = NULL;
	m_pDXCamRenderInputPin = NULL;

	m_pDXARRenderFilter = NULL;
	m_pIDXARRenderFilter = NULL;
	m_pDXARRenderInputPin = NULL;

	m_pCamFilter = NULL;
	m_pCamOutputPin = NULL;

	m_pCamWarpFilter = NULL;
	m_pICamWarpFilter = NULL;
	m_pCamWarpInputPin = NULL;
	m_pCamWarpOutputPin = NULL;

	m_pARWarpFilter = NULL;
	m_pIARWarpFilter = NULL;
	m_pARWarpInputPin = NULL;
	m_pARWarpOutputPin = NULL;

	m_pARTagFilter = NULL;
	m_pIARTagFilter = NULL;
	m_pARTagInputPin = NULL;	
	m_pARTagOutputPin = NULL;

	__super ::CloseCamera();

}
HRESULT ARCalibDS::ConnectGraph(){

	HRESULT hr;
	hr = m_pGraph->Connect(m_pARLayoutOutputPin, m_pARWarpInputPin);
	hr = m_pGraph->Connect(m_pARWarpOutputPin, m_pDXARRenderInputPin);

	hr = m_pGraph->Connect(m_pCameraOutput, m_pCamWarpInputPin);
	hr = m_pGraph->Connect(m_pCamWarpOutputPin, m_pARTagInputPin);
	hr = m_pGraph->Connect(m_pARTagOutputPin, m_pDXCamRenderInputPin);

	return S_OK;
}

HRESULT ARCalibDS::ConfigFilters()
{
	HRESULT hr = __super::ConfigFilters();
	if (m_pIARWarpFilter == NULL || m_pICamWarpFilter == NULL || FAILED(hr))
	{
		return E_FAIL;
	}
	m_pIARWarpFilter->SetIsFlipY(false);
	m_pICamWarpFilter->SetIsFlipY(true);
	
	return S_OK;
}


HRESULT ARCalibDS::CreateFilters(int nCamID, bool bDisplayProperties, int nWidth, int nHeight){
	
	HRESULT hr = __super::CreateFilters(nCamID, bDisplayProperties, nWidth, nHeight);
	if (FAILED(hr))
		return hr;
	m_pCamFilter = m_pDeviceFilter;
	m_pCamOutputPin = m_pCameraOutput;
	WCHAR str[MAX_PATH] = {0};
	
	// create filter
	hr = CoCreateInstance(CLSID_ARLayoutFilter, NULL, CLSCTX_INPROC_SERVER, 
		IID_IBaseFilter, (LPVOID *)&m_pARLayoutFilter);
	hr = m_pARLayoutFilter->QueryInterface(IID_IARLayoutDXFilter,(LPVOID *) &m_pIARLayoutFilter);

	hr = CoCreateInstance(CLSID_HomoWarpFilter, NULL, CLSCTX_INPROC_SERVER, 
		IID_IBaseFilter, (LPVOID *)&m_pARWarpFilter);
	hr = m_pARWarpFilter->QueryInterface(IID_IHomoWarpFilter, (LPVOID *)&m_pIARWarpFilter);

	hr = CoCreateInstance(CLSID_DXRenderFilter, NULL, CLSCTX_INPROC_SERVER, 
		IID_IBaseFilter, (LPVOID *)&m_pDXCamRenderFilter);
	hr = m_pDXCamRenderFilter->QueryInterface(IID_IDXRenderer, (LPVOID *)&m_pIDXCamRenderFilter); 

	hr = CoCreateInstance(CLSID_DXRenderFilter, NULL, CLSCTX_INPROC_SERVER, 
		IID_IBaseFilter, (LPVOID *)&m_pDXARRenderFilter);
	hr = m_pDXARRenderFilter->QueryInterface(IID_IDXRenderer, (LPVOID *)&m_pIDXARRenderFilter); 

	hr = CoCreateInstance(CLSID_HomoWarpFilter, NULL, CLSCTX_INPROC_SERVER, 
		IID_IBaseFilter, (LPVOID *)&m_pCamWarpFilter);
	hr = m_pCamWarpFilter->QueryInterface(IID_IHomoWarpFilter, (LPVOID *)&m_pICamWarpFilter);

	hr = CoCreateInstance(CLSID_ARTagDSFilter, NULL, CLSCTX_INPROC_SERVER, 
		IID_IBaseFilter, (LPVOID *)&m_pARTagFilter);
	hr = m_pARTagFilter->QueryInterface(IID_IARTagDSFilter, (void**)&m_pIARTagFilter);


	hr = m_pARLayoutFilter->FindPin(L"Layout", &m_pARLayoutOutputPin);
	
	hr = m_pARWarpFilter->FindPin(L"input", &m_pARWarpInputPin);
	hr = m_pARWarpFilter->FindPin(L"d3dsurf", &m_pARWarpOutputPin);
	
	hr = m_pDXCamRenderFilter->FindPin(L"In", &m_pDXCamRenderInputPin);
	
	hr = m_pDXARRenderFilter->FindPin(L"In", &m_pDXARRenderInputPin);

	hr = m_pCamWarpFilter->FindPin(L"input", &m_pCamWarpInputPin);
	hr = m_pCamWarpFilter->FindPin(L"output", &m_pCamWarpOutputPin);
	
	hr = m_pARTagFilter->FindPin(L"input", &m_pARTagInputPin);
	hr = m_pARTagFilter->FindPin(L"output", &m_pARTagOutputPin);

	hr = m_pGraph->AddFilter(m_pARLayoutFilter, L"ARLayout");
	hr = m_pGraph->AddFilter(m_pARWarpFilter, L"AR HomoWarp");
	hr = m_pGraph->AddFilter(m_pDXCamRenderFilter, L"CamDXRender");
	hr = m_pGraph->AddFilter(m_pDXARRenderFilter, L"ARDXRender");
	hr = m_pGraph->AddFilter(m_pCamWarpFilter, L"Cam HomoWarp");
	hr = m_pGraph->AddFilter(m_pARTagFilter, L"ARTagFilter");

	return S_OK;
}


BOOL ARCalibDS::SetARCallback(IARTagFilter::CallbackFuncPtr pcallback, int argc, void* argv[])
{	
	if (m_pIARTagFilter == NULL)
	{
		return false;
	}
	return m_pIARTagFilter->SetCallback(pcallback, argc, argv);
}


HRESULT ARCalibDS::ShowDXCamRenderProp(){
	return ShowFilterProp(m_pDXCamRenderFilter);
}
HRESULT ARCalibDS::ShowDXARRenderProp(){
	return ShowFilterProp(m_pDXARRenderFilter);
}
HRESULT ARCalibDS::ShowARProp(){
	return ShowFilterProp(m_pARLayoutFilter);
}
HRESULT ARCalibDS::ShowARWarpProp(){
	return ShowFilterProp(m_pARWarpFilter);
}
HRESULT ARCalibDS::ShowCamWarpProp(){
	return ShowFilterProp(m_pCamWarpFilter);
}
HRESULT ARCalibDS::ShowCamProp(){
	return ShowFilterProp(m_pCamFilter);
}
HRESULT ARCalibDS::ShowCamPinProp(){
	return ShowFilterProp(m_pCamOutputPin);
}