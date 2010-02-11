
#include "ARTagCameraDS.h"
#include "IARTagFilter.h"
ARTagCameraDS::ARTagCameraDS(void) : CCameraDS()
{
	m_pARTagFilter = NULL;
	m_pIARTagFilter = NULL;
	m_pARTagInputPin = NULL;
	m_pARTagOutputPin = NULL;
	m_pSmartTee = NULL;
	m_pSmartTeeInputPin = NULL;
	m_pSmartTeeCapturePin = NULL;
	m_pSmartTeePreviewPin = NULL;
}

ARTagCameraDS::~ARTagCameraDS(void)
{
	m_pARTagFilter = NULL;
	m_pIARTagFilter = NULL;
	m_pARTagInputPin = NULL;
	m_pARTagOutputPin = NULL;
	m_pSmartTee = NULL;
	m_pSmartTeeInputPin = NULL;
	m_pSmartTeeCapturePin = NULL;
	m_pSmartTeePreviewPin = NULL;
}


void ARTagCameraDS::CloseCamera()
{
	m_pARTagFilter = NULL;
	m_pIARTagFilter = NULL;
	m_pARTagInputPin = NULL;
	m_pARTagOutputPin = NULL;
	m_pSmartTee = NULL;
	m_pSmartTeeInputPin = NULL;
	m_pSmartTeeCapturePin = NULL;
	m_pSmartTeePreviewPin = NULL;

	__super::CloseCamera();
}

HRESULT ARTagCameraDS::ConnectGraph()
{
	HRESULT hr;
	hr = m_pGraph->Connect(m_pCameraOutput, m_pSmartTeeInputPin);
	if (FAILED(hr))
		return hr;
	hr = m_pGraph->Connect(m_pSmartTeePreviewPin, m_pARTagInputPin);
	if (FAILED(hr))
		return hr;
	hr = m_pGraph->Connect(m_pARTagOutputPin, m_pGrabberInput);
	if (FAILED(hr))
		return hr;
	hr = m_pGraph->Connect(m_pGrabberOutput, m_pRenderInputPin);
	
	return S_OK;
}
HRESULT ARTagCameraDS::CreateFilters(int nCamID, bool bDisplayProperties, int nWidth, int nHeight)
{
	HRESULT hr;
	hr = CoCreateInstance(CLSID_ARTagDSFilter, NULL, CLSCTX_INPROC_SERVER, 
		IID_IBaseFilter, (LPVOID *)&m_pARTagFilter);
	if (FAILED(hr))
		return hr;
	hr = m_pARTagFilter->QueryInterface(IID_IARTagDSFilter, (void**)&m_pIARTagFilter);
	
	hr = m_pARTagFilter->FindPin(L"input", &m_pARTagInputPin);
	hr = m_pARTagFilter->FindPin(L"output", &m_pARTagOutputPin);
	
	hr = CoCreateInstance(CLSID_SmartTee, NULL, CLSCTX_INPROC_SERVER, 
		IID_IBaseFilter, (LPVOID*)&m_pSmartTee);

	hr = m_pSmartTee->FindPin(L"Input", (IPin**)&m_pSmartTeeInputPin);
	hr = m_pSmartTee->FindPin(L"Capture", (IPin**)&m_pSmartTeeCapturePin);
	hr = m_pSmartTee->FindPin(L"Preview", (IPin**)&m_pSmartTeePreviewPin);
	
	m_pGraph->AddFilter(m_pARTagFilter, L"ARTagFilter");
	m_pGraph->AddFilter(m_pSmartTee, L"Smart Tee");
	return __super::CreateFilters(nCamID, bDisplayProperties, nWidth, nHeight);
}

BOOL ARTagCameraDS::SetARCallback(IARTagFilter::CallbackFuncPtr pcallback, int argc, void* argv[])
{	
	if (m_pIARTagFilter == NULL)
	{
		return false;
	}
	return m_pIARTagFilter->SetCallback(pcallback, argc, argv);
}