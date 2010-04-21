
#include "DSBase.h"



CDSBase::CDSBase()
{
	CoInitialize(NULL);
	m_pMediaEvent = NULL;
	m_pGraph = NULL;
	m_pMediaControl = NULL;
	m_pVideoWindow = NULL;
}

CDSBase::~CDSBase()
{
	UnInitDS();
	CoUninitialize();
}

HRESULT CDSBase::UnInitDS()
{
	m_pGraph = NULL;
	m_pMediaControl = NULL;
	m_pMediaEvent = NULL;
	m_pVideoWindow = NULL;
	return S_OK;
}

HRESULT CDSBase::InitDS()
{
	HRESULT hr = S_OK;
	// Create the Filter Graph Manager.
	hr = CreateGraph((IGraphBuilder**)&m_pGraph);
	hr = CreateFilters();
	hr = ConnectGraph();
	hr = ConfigFilters();

	return S_OK;
}
HRESULT CDSBase::ConfigFilters()
{
	return S_OK;
}
HRESULT CDSBase::ConnectGraph()
{
	return S_OK;
}
HRESULT CDSBase::CreateGraph(IGraphBuilder** ppGraph)
{
	HRESULT hr;
	hr = CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC_SERVER,
		IID_IGraphBuilder, (void **)ppGraph);

	hr = m_pGraph->QueryInterface(IID_IMediaControl, (void **) &m_pMediaControl);
	hr = m_pGraph->QueryInterface(IID_IMediaEvent, (void **) &m_pMediaEvent);
	hr = m_pGraph->QueryInterface(IID_IVideoWindow, (LPVOID *) &m_pVideoWindow);
	return hr;
}
HRESULT CDSBase::CreateFilters()
{
	return S_OK;
}
HRESULT CDSBase::ShowFilterProp(IUnknown* pFilter)
{
	if (pFilter == NULL)
		return S_FALSE;

	CComPtr<ISpecifyPropertyPages> pPages;

	HRESULT hr = pFilter->QueryInterface(IID_ISpecifyPropertyPages, (void**)&pPages);
	if (SUCCEEDED(hr))
	{
		CAUUID caGUID;
		pPages->GetPages(&caGUID);

		OleCreatePropertyFrame(NULL, 0, 0,
			L"Property Sheet", 1,
			(IUnknown **)&(pFilter),
			caGUID.cElems,
			caGUID.pElems,
			0, 0, NULL);
		CoTaskMemFree(caGUID.pElems);
	}
	pPages = NULL;
	return S_OK;
}

HRESULT CDSBase::SaveGraphFile(WCHAR *wszPath) 
{
	const WCHAR wszStreamName[] = L"ActiveMovieGraph"; 
	CComPtr<IGraphBuilder> pGraph = m_pGraph;
	HRESULT hr;

	IStorage *pStorage = NULL;
	hr = StgCreateDocfile(
		wszPath,
		STGM_CREATE | STGM_TRANSACTED | STGM_READWRITE | STGM_SHARE_EXCLUSIVE,
		0, &pStorage);
	if(FAILED(hr)) 
	{
		return hr;
	}

	IStream *pStream;
	hr = pStorage->CreateStream(
		wszStreamName,
		STGM_WRITE | STGM_CREATE | STGM_SHARE_EXCLUSIVE,
		0, 0, &pStream);
	if (FAILED(hr)) 
	{
		pStorage->Release();    
		return hr;
	}

	IPersistStream *pPersist = NULL;
	pGraph->QueryInterface(IID_IPersistStream, (void**)&pPersist);
	hr = pPersist->Save(pStream, TRUE);
	pStream->Release();
	pPersist->Release();
	if (SUCCEEDED(hr)) 
	{
		hr = pStorage->Commit(STGC_DEFAULT);
	}
	pStorage->Release();
	return hr;
}

HRESULT CDSBase::Play()
{
	if (m_pMediaControl == NULL)
		return S_FALSE;
	return m_pMediaControl->Run();
}
HRESULT CDSBase::Stop()
{
	if (m_pMediaControl == NULL)
		return S_FALSE;
	return m_pMediaControl->Stop();
}
HRESULT CDSBase::Pause()
{
	if (m_pMediaControl == NULL)
		return S_FALSE;
	return m_pMediaControl->Pause();
}

HRESULT CDSBase::SetVideoWindow(HWND hwnd)
{
	if (m_pVideoWindow == NULL)
		return false;
	HRESULT hr = S_OK;
	hr = m_pVideoWindow->put_Owner((OAHWND)hwnd);
	hr = m_pVideoWindow->put_WindowStyle(WS_CHILD | WS_CLIPCHILDREN);
	hr = m_pVideoWindow->put_Visible(OATRUE);
	hr = m_pVideoWindow->put_MessageDrain((OAHWND)hwnd);
	RECT rect;
	GetWindowRect(hwnd, &rect);
	hr = m_pVideoWindow->SetWindowPosition(0, 0, rect.right- rect.left,
		rect.bottom- rect.top);
	return hr;
}
