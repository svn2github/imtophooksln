#include "stdafx.h"
#include "GSDXRenderer.h"
#include "GSDXRendererApp.h"
#include "GSDXShareFilter.h"
#include "GSD3DMediaType.h"
#include "DXUT.h"
GSDXRenderer::GSDXRenderer(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData)
: GSDXBaseRenderer(CLSID_GSDXRenderer, NAME("GSDXRenderer"), pOuter, phr)
{

}
GSDXRenderer::~GSDXRenderer()
{

}

CUnknown *WINAPI GSDXRenderer::CreateInstance(LPUNKNOWN punk, HRESULT *phr)
{
	ASSERT(phr);
	// assuming we don't want to modify the data
	GSDXRenderer *pNewObject = new GSDXRenderer(punk, phr, FALSE);

	if(pNewObject == NULL) {
		if (phr)
			*phr = E_OUTOFMEMORY;
	}
	return pNewObject;
}

HRESULT GSDXRenderer::NonDelegatingQueryInterface(REFIID iid, void **ppv)
{
	if (iid == IID_IGSDXRenderer) 
	{
		return GetInterface(static_cast<IGSDXRenderer*>(this), ppv);
	}

	else if (iid == IID_IGSDXShareFilter)
	{
		return GetInterface(
			static_cast<IGSDXShareFilter*>(this),	ppv);
	}
	else
	{
		// Call the parent class.
		return CBaseFilter::NonDelegatingQueryInterface(iid, ppv);
	}
}

HRESULT GSDXRenderer::CheckMediaType(const CMediaType *pmt)
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
		else if(IsEqualGUID(guidSubType, MEDIASUBTYPE_RGB32) ||
			IsEqualGUID(guidSubType, MEDIASUBTYPE_ARGB32))
		{
			return S_OK;
		}
	}
	else if (IsEqualGUID(*pmt->Type(), GSMEDIATYPE_GSDX11_MEDIATYPE) && 
		IsEqualGUID(guidSubType, GSMEDIASUBTYPE_GSTEX2D_POINTER))
	{
		return S_OK;
	}
	else if (IsEqualGUID(*pmt->Type(),  GSMEDIATYPE_GSDX11_SHAREDEVICE_MEDIATYPE) && 
		IsEqualGUID(guidSubType, GSMEDIASUBTYPE_GSTEX2D_POINTER))
	{
		return S_OK;
	}
	return E_FAIL;
}

HRESULT GSDXRenderer::CompleteConnect(IPin *pReceivePin)
{
	if (m_pD3DDisplay == NULL)
	{
		WCHAR effectPath[MAX_PATH] = L"..\\fx\\GSBasicEffect.fx";
		CMediaType mt = m_pInputPin->CurrentMediaType();
		GUID fmt = *mt.FormatType();
		if (IsEqualGUID(*mt.FormatType(), GSFORMAT_DX11TEX2D_DESC))
		{	
			D3D11_TEXTURE2D_DESC* desc = NULL;
			desc = (D3D11_TEXTURE2D_DESC*) mt.pbFormat;
			
			if (IsEqualGUID(*mt.Type(), GSMEDIATYPE_GSDX11_SHAREDEVICE_MEDIATYPE))
			{
				ID3D11Device* pDevice = NULL;
				ID3D11DeviceContext* pDeviceContext = NULL;
				IDXGISwapChain* pSwapChain = NULL;
				m_pInputPin->QueryD3DDevice(pDevice, pDeviceContext, pSwapChain);
				if (pDevice == NULL || pDeviceContext || pSwapChain == NULL)
					return S_FALSE;
				
				initD3D(effectPath, MAX_PATH, desc->Width, desc->Height, 1, 1, 1, pDevice, pDeviceContext, pSwapChain);
				SAFE_RELEASE(pDevice);
				SAFE_RELEASE(pDeviceContext);
				SAFE_RELEASE(pSwapChain);
			}
			else if (IsEqualGUID(*mt.Subtype(),  GSMEDIATYPE_GSDX11_MEDIATYPE))
			{
				initD3D(effectPath, MAX_PATH, desc->Width, desc->Height, 1, 1, 1);
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
			initD3D(effectPath, MAX_PATH, bitHeader.biWidth, bitHeader.biHeight, 1, 1, 1);
		} 

	}
	FILTER_INFO filterInfo;
	this->QueryFilterInfo(&filterInfo);

	HWND displayWnd = GetDisplayWindow();
	SetWindowText(displayWnd, filterInfo.achName);

	m_pD3DDisplay->ShowWnd(TRUE);
	if (filterInfo.pGraph != NULL)
	{
		filterInfo.pGraph->Release();
		filterInfo.pGraph = NULL;
	}
	return __super::CompleteConnect(pReceivePin);
}
HRESULT GSDXRenderer::BreakConnect()
{
	ReleaseD3D();
	return __super::BreakConnect();
}


HRESULT GSDXRenderer::DoRenderSample(IMediaSample *pMediaSample)
{
	if (m_pInTextureList.size() <= 0 || m_pD3DDisplay == NULL)
		return E_FAIL;
	CMediaType mt = m_pInputPin->CurrentMediaType();
	CopySample2GSTexture(m_pInTextureList[0], pMediaSample, &mt);
	{
		CCritSec* pD3DCS = NULL;
		QueryD3DDeviceCS(NULL, pD3DCS);
		if (pD3DCS == NULL)
			return S_FALSE;
		CAutoLock lck(pD3DCS);
		m_pD3DDisplay->Render();
	}
	return S_OK;
}

void GSDXRenderer::OnReceiveFirstSample(IMediaSample *pMediaSample)
{
	if (m_pInTextureList.size() <= 0 || m_pD3DDisplay == NULL)
		return ;
	CMediaType mt = m_pInputPin->CurrentMediaType();
	CopyGSTexture2Sample(m_pInTextureList[0], pMediaSample, &mt);
	{
		CCritSec* pD3DCS = NULL;
		QueryD3DDeviceCS(NULL, pD3DCS);
		if (pD3DCS == NULL)
			return ;
		CAutoLock lck(pD3DCS);
		m_pD3DDisplay->Render();
	}
	return ;
}

BOOL GSDXRenderer::IsReadyCloseWindow()
{
	if (m_State == State_Running)
	{
		return FALSE;
	}
	return TRUE;
}

HWND GSDXRenderer::GetDisplayWindow()
{
	if( m_pD3DDisplay == NULL)
	{
		return 0;
	}
	return m_pD3DDisplay->GetHwnd();
}


BOOL GSDXRenderer::IsHideBorder()
{
	HWND hwnd = GetDisplayWindow();
	if (hwnd == 0)
	{
		return FALSE;
	}
	LONG wndStyle = GetWindowLong(hwnd, GWL_STYLE);
	return !(WS_BORDER & wndStyle);
}
BOOL GSDXRenderer::SetHideBorder(BOOL bHideBorder)
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
BOOL GSDXRenderer::IsWindowZoom()
{
	if (m_pD3DDisplay == NULL)
		return S_FALSE;
	HWND hwnd = m_pD3DDisplay->GetHwnd();
	if (hwnd == 0)
		return S_FALSE;
	return ::IsZoomed(hwnd);
}
HRESULT GSDXRenderer::SetWindowZoom(BOOL bZoom)
{
	if (m_pD3DDisplay == NULL)
		return S_FALSE;
	HWND hwnd = m_pD3DDisplay->GetHwnd();
	if (hwnd == 0)
		return S_FALSE;
	if (bZoom)
		::ShowWindow(hwnd, SW_MAXIMIZE);
	else
		::ShowWindow(hwnd, SW_RESTORE);
	return S_OK;
}
HRESULT GSDXRenderer::GetWindowRect(RECT& rect)
{
	if (m_pD3DDisplay == NULL)
		return S_FALSE;
	HWND hwnd = m_pD3DDisplay->GetHwnd();
	if (hwnd == 0)
		return S_FALSE;
	BOOL ret = ::GetWindowRect(hwnd, &rect);
	if (ret)
		return S_OK;
	else
		return S_FALSE;
}
HRESULT GSDXRenderer::SetWindowRect(RECT rect)
{

	if (m_pD3DDisplay == NULL)
		return S_FALSE;
	HWND hwnd = m_pD3DDisplay->GetHwnd();
	if (hwnd == 0)
		return S_FALSE;

	BOOL ret = ::SetWindowPos(hwnd, HWND_NOTOPMOST, rect.left, rect.top, 
		rect.right - rect.left, rect.bottom - rect.top, SWP_SHOWWINDOW | SWP_NOACTIVATE );

	return S_OK;
}
