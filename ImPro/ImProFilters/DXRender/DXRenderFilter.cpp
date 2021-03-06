#include "stdafx.h"
#include "DXRenderFilter.h"
#include "DXRenderProp.h"
#include "DXRenderApp.h"
#include "MyMediaSample.h"
#include "DXRenderDisplay.h"
#include "CMuxTransformFilter.h"
DXRenderFilter::DXRenderFilter(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData)
: DXBaseRenderer(CLSID_DXRenderFilter, NAME("DXRender Filter"), pOuter, phr)
{
	m_ThreadHandle = 0;
}
DXRenderFilter::~DXRenderFilter()
{

}

CUnknown *WINAPI DXRenderFilter::CreateInstance(LPUNKNOWN punk, HRESULT *phr)
{
	ASSERT(phr);
	// assuming we don't want to modify the data
	DXRenderFilter *pNewObject = new DXRenderFilter(punk, phr, FALSE);

	if(pNewObject == NULL) {
		if (phr)
			*phr = E_OUTOFMEMORY;
	}
	return pNewObject;
}

HRESULT DXRenderFilter::NonDelegatingQueryInterface(REFIID iid, void **ppv)
{
	if (iid == IID_IDXRenderer) 
	{
		return GetInterface(static_cast<IDXRenderer*>(this), ppv);
	}
	else if (iid == IID_ISpecifyPropertyPages)
	{
		return GetInterface(
			static_cast<ISpecifyPropertyPages*>(this),	ppv);
	}
	else if (iid == IID_IGSPersist)
	{
		return GetInterface(
			static_cast<IGSPersist*>(this),	ppv);
	}
	else
	{
		// Call the parent class.
		return CBaseFilter::NonDelegatingQueryInterface(iid, ppv);
	}
}
HRESULT DXRenderFilter::OnStartStreaming()
{
	m_ThreadHandle = 0;
	return S_OK;
}

HRESULT DXRenderFilter::OnStopStreaming()
{
	m_ThreadHandle = 0;
	return S_OK;
}
HRESULT DXRenderFilter::CheckMediaType(const CMediaType *pmt)
{
	GUID guidSubType = *pmt->Subtype();
	if (IsEqualGUID(*pmt->Type(), MEDIATYPE_Video)) 
	{
		VIDEOINFOHEADER* pvi = (VIDEOINFOHEADER*)pmt->Format();
		BITMAPINFOHEADER bitHeader = pvi->bmiHeader;
		if (bitHeader.biCompression)
		{
			return E_FAIL;
		}
		if (!(IsEqualGUID(*pmt->FormatType(), FORMAT_VideoInfo)))
		{
			return E_FAIL;
		}
		if(IsEqualGUID(guidSubType, MEDIASUBTYPE_RGB24))
		{
			return S_OK;
		}
		else if(IsEqualGUID(guidSubType, MEDIASUBTYPE_RGB32) ||
			IsEqualGUID(guidSubType, MEDIASUBTYPE_ARGB32))
		{
			return S_OK;
		}
	}
	else if (IsEqualGUID(*pmt->Type(), GUID_D3DMEDIATYPE) && 
		IsEqualGUID(guidSubType, GUID_D3DXTEXTURE9_POINTER))
	{
		return S_OK;
	}
	else if (IsEqualGUID(*pmt->Type(), GUID_D3DMEDIATYPE) && 
		IsEqualGUID(guidSubType, GUID_D3DSHARE_RTTEXTURE_POINTER))
	{
		return S_OK;
	}
	return E_FAIL;
}
HRESULT DXRenderFilter::SetMediaType(const CMediaType *pmt)
{
	m_InputMT = *pmt;
	return S_OK;
}
HRESULT DXRenderFilter::CompleteConnect(IPin *pReceivePin)
{
	if (m_pD3DDisplay == NULL)
	{
		CMediaType mt = m_InputMT;
		GUID fmt = *mt.FormatType();
		if (IsEqualGUID(*mt.FormatType(), GUID_FORMATTYPE_D3DXTEXTURE9DESC))
		{	
			D3DSURFACE_DESC *desc = (D3DSURFACE_DESC*) mt.pbFormat;
			if (IsEqualGUID(*mt.Subtype(), GUID_D3DSHARE_RTTEXTURE_POINTER))
			{
				IDirect3DDevice9* pDevice = NULL;
				m_pInputPin->QueryD3DDevice(pDevice);
				if (pDevice == NULL)
					return E_FAIL;
				initD3D(desc->Width, desc->Height, pDevice);
				pDevice->Release();
				pDevice = NULL;
			}
			else if (IsEqualGUID(*mt.Subtype(), GUID_D3DXTEXTURE9_POINTER))
			{
				initD3D(desc->Width, desc->Height);
			}
			else
			{
				return E_FAIL;
			}

		}
		else if (IsEqualGUID(*mt.FormatType(), FORMAT_VideoInfo))
		{
			VIDEOINFOHEADER *pvi = (VIDEOINFOHEADER *) mt.pbFormat;
			BITMAPINFOHEADER bitHeader = pvi->bmiHeader;
			initD3D(bitHeader.biWidth, bitHeader.biHeight);
		} 
	
	}
	FILTER_INFO filterInfo;
	this->QueryFilterInfo(&filterInfo);

	HWND displayWnd = GetDisplayWindow();
	SetWindowText(displayWnd, filterInfo.achName);

	m_pD3DDisplay->ShowDisplayWnd(TRUE);
	if (filterInfo.pGraph != NULL)
	{
		filterInfo.pGraph->Release();
		filterInfo.pGraph = NULL;
	}
	return __super::CompleteConnect(pReceivePin);
}
HRESULT DXRenderFilter::BreakConnect()
{
	ReleaseD3D();
	return __super::BreakConnect();
}
HRESULT DXRenderFilter::GetPages(CAUUID *pPages)
{
	pPages->cElems = 1;
	pPages->pElems = (GUID*)CoTaskMemAlloc(sizeof(GUID));
	if (pPages->pElems == NULL) 
	{
		return E_OUTOFMEMORY;
	}
	pPages->pElems[0] = CLSID_DXRenderPropPage;
	return S_OK;
}

HRESULT DXRenderFilter::DoRenderSample(IMediaSample *pMediaSample)
{
	{
		CAutoLock lck(&m_csThreadHandle);
		if (m_ThreadHandle == 0)
		{
			m_ThreadHandle = GetCurrentThread();
		}
	}
	CopyInputImage2InputTexture(pMediaSample, &m_InputMT, false);
	{
		CCritSec* pD3DCS = NULL;
		QueryD3DDeviceCS(NULL, pD3DCS);
		if (pD3DCS == NULL)
			return S_FALSE;
		CAutoLock lck(pD3DCS);
		m_pD3DDisplay->SetTexture(m_pInTexture);
		m_pD3DDisplay->Render();
		m_pD3DDisplay->SetTexture(NULL);
	}
	return S_OK;
}

void DXRenderFilter::OnReceiveFirstSample(IMediaSample *pMediaSample)
{
	{
		CAutoLock lck(&m_csThreadHandle);
		if (m_ThreadHandle == 0)
		{
			m_ThreadHandle = GetCurrentThread();
		}
	}
	CopyInputImage2InputTexture(pMediaSample, &m_InputMT, false);
	{
		CCritSec* pD3DCS = NULL;
		QueryD3DDeviceCS(NULL, pD3DCS);
		if (pD3DCS == NULL)
			return ;
		CAutoLock lck(pD3DCS);
		m_pD3DDisplay->SetTexture(m_pInTexture);
		m_pD3DDisplay->Render();
		m_pD3DDisplay->SetTexture(NULL);
	}

	return ;
}


MS3DDisplay* DXRenderFilter::Create3DDisplay(IDirect3D9* pD3D, int rtWidth, int rtHeight)
{
	return new DXRenderDisplay(pD3D, rtWidth, rtHeight);
}
MS3DDisplay* DXRenderFilter::Create3DDisplay(IDirect3DDevice9* pDevice, int rtWidth, int rtHeight)
{
	return new DXRenderDisplay(pDevice, rtWidth, rtHeight);
}
BOOL DXRenderFilter::IsReadyCloseWindow()
{
	if (m_State == State_Running)
	{
		return FALSE;
	}
	return TRUE;
}

HWND DXRenderFilter::GetDisplayWindow()
{
	if( m_pD3DDisplay == NULL)
	{
		return 0;
	}
	return m_pD3DDisplay->GetDisplayWindow();
}

int DXRenderFilter::GetSampleType()
{
	if (m_pD3DDisplay == NULL)
		return false;
	CAutoLock lck(&m_csDisplayState);
	return ((DXRenderDisplay*)m_pD3DDisplay)->m_sampleType;
}
bool DXRenderFilter::SetSampleType(int v)
{
	if (m_pD3DDisplay == NULL)
		return false;
	CAutoLock lck(&m_csDisplayState);
	((DXRenderDisplay*)m_pD3DDisplay)->m_sampleType = v;
	return true;
}

bool DXRenderFilter::GetFlipX()
{
	if (m_pD3DDisplay == NULL)
		return false;
	CAutoLock lck(&m_csDisplayState);
	CAutoLock lck0(&m_csD3DDisplay);
	return ((DXRenderDisplay*)m_pD3DDisplay)->m_bFlipX;
}
bool DXRenderFilter::SetFlipX(bool v)
{
	if (m_pD3DDisplay == NULL)
		return false;
	CAutoLock lck(&m_csDisplayState);
	CAutoLock lck0(&m_csD3DDisplay);
	((DXRenderDisplay*)m_pD3DDisplay)->m_bFlipX = v;
	return true;
}
bool DXRenderFilter::GetFlipY()
{
	if (m_pD3DDisplay == NULL)
		return false;
	CAutoLock lck(&m_csDisplayState);
	CAutoLock lck0(&m_csD3DDisplay);
	return ((DXRenderDisplay*)m_pD3DDisplay)->m_bFlipY;
}
bool DXRenderFilter::SetFlipY(bool v)
{
	if (m_pD3DDisplay == NULL)
		return false;
	CAutoLock lck(&m_csDisplayState);
	CAutoLock lck0(&m_csD3DDisplay);
	((DXRenderDisplay*)m_pD3DDisplay)->m_bFlipY = v;
	return true;
}
bool DXRenderFilter::GetbDrawFPS()
{
	if (m_pD3DDisplay == NULL)
		return false;
	CAutoLock lck(&m_csDisplayState);
	CAutoLock lck0(&m_csD3DDisplay);
	return ((DXRenderDisplay*)m_pD3DDisplay)->m_bDrawFPS;
}
bool DXRenderFilter::SetbDrawFPS(bool v)
{
	if (m_pD3DDisplay == NULL)
		return false;
	CAutoLock lck(&m_csDisplayState);
	CAutoLock lck0(&m_csD3DDisplay);
	((DXRenderDisplay*)m_pD3DDisplay)->m_bDrawFPS = v;
	return true;
}

BOOL DXRenderFilter::GetRenderThreadPriority(int& nPriority)
{
	CAutoLock lck(&m_csThreadHandle);
	if (m_ThreadHandle == 0)
		return FALSE;
	nPriority = GetThreadPriority(m_ThreadHandle);
	return TRUE;
}
BOOL DXRenderFilter::SetRenderThreadPriority(int nPriority)
{
	CAutoLock lck(&m_csThreadHandle);
	if (m_ThreadHandle == 0)
		return FALSE;
	return SetThreadPriority(m_ThreadHandle, nPriority);
	
}
DWORD DXRenderFilter::GetProcessPriority()
{
	HANDLE hProcess = GetCurrentProcess();
	return GetPriorityClass(hProcess);
}
BOOL DXRenderFilter::SetProcessPriority(DWORD dwPriorityClass)
{
	HANDLE hProcess = GetCurrentProcess();
	return SetPriorityClass(hProcess, dwPriorityClass);
}
HRESULT DXRenderFilter::SaveToFile(WCHAR* path)
{
	CAutoLock lck(&m_csDisplayState);
	FILE* filestream = NULL;

	_wfopen_s(&filestream, path, L"w");
	if (filestream == NULL)
	{
		return false;
	}
	
	RECT rect;
	GetWindowRect(rect);
	BOOL isZoomed = IsWindowZoom();
	BOOL isHideBorder = IsHideBorder();

	fwprintf_s(filestream, L"%d %d %d \n", GetFlipX(), GetFlipY(), GetbDrawFPS());
	fwprintf_s(filestream, L"%d %d %d %d\n", rect.left, rect.top, rect.right, rect.bottom);
	fwprintf_s(filestream, L"%d %d \n", isZoomed, isHideBorder);
	fwprintf_s(filestream, L"%d \n", GetSampleType());
	fclose(filestream);
	return S_OK;
}
HRESULT DXRenderFilter::LoadFromFile(WCHAR* path)
{
	FILE* filestream = NULL;
	_wfopen_s(&filestream, path, L"r");
	if (filestream == NULL)
	{
		return false;
	}
	int bFlipX =0, bFlipY = 0, bDrawFPS = 0;
	int sampleType = 0;
	RECT rect;
	memset(&rect, 0, sizeof(RECT));
	BOOL isZoomed = FALSE;;
	BOOL isHideBorder = FALSE;

	fwscanf_s(filestream, L"%d %d %d\n", &bFlipX, &bFlipY, &bDrawFPS);
	fwscanf_s(filestream, L"%d %d %d %d\n", &rect.left, &rect.top, &rect.right, &rect.bottom);
	fwscanf_s(filestream, L"%d %d \n", &isZoomed, &isHideBorder);
	fwscanf_s(filestream, L"%d \n", &sampleType);

	SetSampleType(sampleType);
	SetFlipX(bFlipX);
	SetFlipY(bFlipY);
	SetbDrawFPS(bDrawFPS);
	SetWindowRect(rect);
	SetHideBorder(isHideBorder);
	SetWindowZoom(isZoomed);
	

	fclose(filestream);
	return S_OK;
}

HRESULT DXRenderFilter::GetName(WCHAR* name, UINT szName)
{
	if (name == NULL)
	{
		return S_FALSE;
	}
	FILTER_INFO filterInfo;
	this->QueryFilterInfo(&filterInfo);
	wcscpy_s(name, szName, filterInfo.achName);
	if (filterInfo.pGraph != NULL)
	{
		filterInfo.pGraph->Release();
		filterInfo.pGraph = NULL;
	}
	return S_OK;
}
BOOL DXRenderFilter::IsHideBorder()
{
	HWND hwnd = GetDisplayWindow();
	if (hwnd == 0)
	{
		return FALSE;
	}
	LONG wndStyle = GetWindowLong(hwnd, GWL_STYLE);
	return !(WS_BORDER & wndStyle);
}
BOOL DXRenderFilter::SetHideBorder(BOOL bHideBorder)
{
	HWND hwnd = GetDisplayWindow();
	if (hwnd == 0)
	{
		return FALSE;
	}
	LONG wndStyle = GetWindowLong(hwnd, GWL_STYLE);
	LONG newStyle = 0;
	bool checked = bHideBorder;
	if (checked)
	{
		LONG removeBORDER = 0xFFFFFFFF ^ WS_BORDER;
		newStyle = removeBORDER & wndStyle;
		SetWindowLong(hwnd, GWL_STYLE, newStyle);
	}
	else
	{
		newStyle = WS_BORDER | wndStyle;
		SetWindowLong(hwnd, GWL_STYLE, newStyle);
	}
	return TRUE;
}
BOOL DXRenderFilter::IsWindowZoom()
{
	if (m_pD3DDisplay == NULL)
		return S_FALSE;
	HWND hwnd = m_pD3DDisplay->GetDisplayWindow();
	if (hwnd == 0)
		return S_FALSE;
	return ::IsZoomed(hwnd);
}
HRESULT DXRenderFilter::SetWindowZoom(BOOL bZoom)
{
	if (m_pD3DDisplay == NULL)
		return S_FALSE;
	HWND hwnd = m_pD3DDisplay->GetDisplayWindow();
	if (hwnd == 0)
		return S_FALSE;
	if (bZoom)
		::ShowWindow(hwnd, SW_MAXIMIZE);
	else
		::ShowWindow(hwnd, SW_RESTORE);
	return S_OK;
}
HRESULT DXRenderFilter::GetWindowRect(RECT& rect)
{
	if (m_pD3DDisplay == NULL)
		return S_FALSE;
	HWND hwnd = m_pD3DDisplay->GetDisplayWindow();
	if (hwnd == 0)
		return S_FALSE;
	BOOL ret = ::GetWindowRect(hwnd, &rect);
	if (ret)
		return S_OK;
	else
		return S_FALSE;
}
HRESULT DXRenderFilter::SetWindowRect(RECT rect)
{

	if (m_pD3DDisplay == NULL)
		return S_FALSE;
	HWND hwnd = m_pD3DDisplay->GetDisplayWindow();
	if (hwnd == 0)
		return S_FALSE;

	BOOL ret = ::SetWindowPos(hwnd, HWND_NOTOPMOST, rect.left, rect.top, 
		rect.right - rect.left, rect.bottom - rect.top, SWP_SHOWWINDOW | SWP_NOACTIVATE );

	return S_OK;
}

HRESULT DXRenderFilter::QueryD3DDeviceCS(IDXBasePin* pPin, CCritSec*& cs)
{
	if (m_pD3DDisplay == NULL)
		return S_FALSE;
	if (m_pD3DDisplay->IsDeviceFromOther())
	{
		IDXBasePin* pDXInPin = NULL;
		m_pInputPin->QueryInterface(IID_IDXBasePin, (void**)&pDXInPin);
		if (pDXInPin == NULL)
			return S_FALSE;
		pDXInPin->QueryD3DDeviceCS(cs);
		pDXInPin->Release();
		pDXInPin = NULL;
		return S_OK;
	}
	else
	{
		cs = &m_csD3DDisplay;
		return S_OK;
	}
}