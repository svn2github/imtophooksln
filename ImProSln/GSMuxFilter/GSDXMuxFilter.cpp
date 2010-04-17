#include "stdafx.h"
#include "GSDXMuxFilter.h"
#include "GSD3DMediaType.h"
#include "GSMacro.h"

GSDXMuxInputPin::GSDXMuxInputPin(
		__in_opt LPCTSTR pObjectName,
		__inout GSMuxFilter *pTransformFilter,
		__inout HRESULT * phr,
		__in_opt LPCWSTR pName) : GSMuxInputPin(pObjectName, pTransformFilter, phr, pName)
{

}
#ifdef UNICODE
GSDXMuxInputPin::GSDXMuxInputPin(
		__in_opt LPCSTR pObjectName,
		__inout GSMuxFilter *pTransformFilter,
		__inout HRESULT * phr,
		__in_opt LPCWSTR pName) : GSMuxInputPin(pObjectName, pTransformFilter, phr, pName)
{

}
#endif
GSDXMuxInputPin::~GSDXMuxInputPin()
{

}
HRESULT GSDXMuxInputPin::NonDelegatingQueryInterface(REFIID riid, __deref_out void **ppv)
{
	if (riid == IID_IGSDXSharePin) 
	{
		return GetInterface(static_cast<IGSDXSharePin*>(this), ppv);
	}
	else
	{
		// Call the parent class.
		return __super::NonDelegatingQueryInterface(riid, ppv);
	}
}
HRESULT GSDXMuxInputPin::CompleteConnect(IPin *pReceivePin)
{
	HRESULT hr = S_OK;
	IGSDXSharePin* pDXPin = NULL;
	hr = pReceivePin->QueryInterface(IID_IGSDXSharePin, (void**)&pDXPin);
	if (pDXPin != NULL)
	{
		SetConnectedPin(pDXPin);
		pDXPin->Release();
		pDXPin = NULL;
	}
	hr = __super::CompleteConnect(pReceivePin);
	if (FAILED(hr)) {
		SetConnectedPin(NULL);
		return hr;
	}
	return hr;	
}
HRESULT GSDXMuxInputPin::BreakConnect()
{
	HRESULT hr = S_OK;
	hr = __super::BreakConnect();
	if (SUCCEEDED(hr))
		SetConnectedPin(NULL);
	return hr; 
}
GSDXMuxOutputPin::GSDXMuxOutputPin(
		__in_opt LPCTSTR pObjectName,
		__inout GSMuxFilter *pTransformFilter,
		__inout HRESULT * phr,
		__in_opt LPCWSTR pName) : GSMuxOutputPin(pObjectName, pTransformFilter, phr, pName)
{

}
#ifdef UNICODE
GSDXMuxOutputPin::GSDXMuxOutputPin(
		__in_opt LPCSTR pObjectName,
		__inout GSMuxFilter *pTransformFilter,
		__inout HRESULT * phr,
		__in_opt LPCWSTR pName) : GSMuxOutputPin(pObjectName, pTransformFilter, phr, pName)
{

}
#endif
GSDXMuxOutputPin::~GSDXMuxOutputPin()
{

}

HRESULT GSDXMuxOutputPin::NonDelegatingQueryInterface(REFIID riid, __deref_out void **ppv)
{
	if (riid == IID_IGSDXSharePin) 
	{
		return GetInterface(static_cast<IGSDXSharePin*>(this), ppv);
	}
	else
	{
		// Call the parent class.
		return __super::NonDelegatingQueryInterface(riid, ppv);
	}
}

HRESULT GSDXMuxOutputPin::CompleteConnect(IPin *pReceivePin)
{
	HRESULT hr = S_OK;
	IGSDXSharePin* pDXPin = NULL;
	hr = pReceivePin->QueryInterface(IID_IGSDXSharePin, (void**)&pDXPin);
	if (pDXPin != NULL)
	{
		SetConnectedPin(pDXPin);
		pDXPin->Release();
		pDXPin = NULL;
	}
	hr = __super::CompleteConnect(pReceivePin);
	if (FAILED(hr)) {
		SetConnectedPin(NULL);
		return hr;
	}
	return hr;	
}

HRESULT GSDXMuxOutputPin::BreakConnect()
{
	HRESULT hr = S_OK;
	hr = __super::BreakConnect();
	if (SUCCEEDED(hr))
		SetConnectedPin(NULL);
	return hr; 
}

GSDXMuxStream::GSDXMuxStream(__in_opt LPCTSTR pObjectName,
		__inout GSMuxFilter *pms,
		__inout HRESULT *phr,
		__in_opt LPCWSTR pName) : GSMuxStream(pObjectName, pms, phr, pName)
{

}
#ifdef UNICODE
GSDXMuxStream::GSDXMuxStream(__in_opt LPCSTR pObjectName,
		__inout GSMuxFilter *pms,
		__inout HRESULT *phr,
		__in_opt LPCWSTR pName) : GSMuxStream(pObjectName, pms, phr, pName)
{

}
#endif
GSDXMuxStream::~GSDXMuxStream(void)
{
		
}

HRESULT GSDXMuxStream::NonDelegatingQueryInterface(REFIID riid, __deref_out void **ppv)
{
	if (riid == IID_IGSDXSharePin) 
	{
		return GetInterface(static_cast<IGSDXSharePin*>(this), ppv);
	}
	else
	{
		// Call the parent class.
		return __super::NonDelegatingQueryInterface(riid, ppv);
	}
}

HRESULT GSDXMuxStream::CompleteConnect(IPin *pReceivePin)
{
	HRESULT hr = S_OK;
	IGSDXSharePin* pDXPin = NULL;
	hr = pReceivePin->QueryInterface(IID_IGSDXSharePin, (void**)&pDXPin);
	if (pDXPin != NULL)
	{
		SetConnectedPin(pDXPin);
		pDXPin->Release();
		pDXPin = NULL;
	}
	hr = __super::CompleteConnect(pReceivePin);
	if (FAILED(hr)) {
		SetConnectedPin(NULL);
		return hr;
	}
	return hr;	
}
HRESULT GSDXMuxStream::BreakConnect()
{
	HRESULT hr = S_OK;
	hr = __super::BreakConnect();
	if (SUCCEEDED(hr))
		SetConnectedPin(NULL);
	return hr; 
}


GSDXMuxFilter::GSDXMuxFilter(__in_opt LPCTSTR pName, __inout_opt LPUNKNOWN pUnk, REFCLSID  clsid) : GSMuxFilter(pName, pUnk, clsid)
{

}

#ifdef UNICODE
GSDXMuxFilter::GSDXMuxFilter(__in_opt LPCSTR pName, __inout_opt LPUNKNOWN pUnk, REFCLSID  clsid) : GSMuxFilter(pName, pUnk, clsid)
{

}
#endif

GSDXMuxFilter::~GSDXMuxFilter()
{

}


HRESULT GSDXMuxFilter::NonDelegatingQueryInterface(REFIID riid, __deref_out void **ppv)
{
	if (riid == IID_IGSDXShareFilter) 
	{
		return GetInterface(static_cast<IGSDXShareFilter*>(this), ppv);
	}
	else
	{
		// Call the parent class.
		return __super::NonDelegatingQueryInterface(riid, ppv);
	}
}


HRESULT GSDXMuxFilter::GetMediaType(int iPosition, const IPin* pOutPin, __inout CMediaType *pMediaType)
{
	if (iPosition < 0 || pOutPin == NULL )
		return E_FAIL;
	HRESULT hr = S_OK;

	UINT pinIdx = 0;
	GSPIN_TYPE pinType = GSINPUT_PIN;

	hr = _GetPinIdx(pOutPin, pinIdx, pinType);
	if (FAILED(hr) || ( pinType != GSOUTPUT_PIN && pinType != GSSTREAM_PIN))
		return E_FAIL;
	if (pinType == GSOUTPUT_PIN)
	{
		if (pinIdx >= m_pOutputPinDesc.size())
			return E_FAIL;

		UINT nAllowMTs = m_pOutputPinDesc[pinIdx].acceptTypes.nAcceptType;
		if (iPosition >= nAllowMTs)
			return VFW_S_NO_MORE_ITEMS;
		CMediaType mt;
		GSOUTPIN_ACCEPT_MEDIATYPE allowMT = m_pOutputPinDesc[pinIdx].acceptTypes.pAcceptTypes[iPosition];

		if (allowMT.pMainType != NULL)
		{
			mt.SetType(allowMT.pMainType);
		}
		if (allowMT.pSubType != NULL)
		{
			mt.SetSubtype(allowMT.pSubType);
		}
		mt.SetTemporalCompression(allowMT.bCompression);
		UINT bufW = 0, bufH = 0;
		if (allowMT.refFlag == GSREF_ACCEPT_MEDIATYPE)
		{
			bufW = allowMT.bufW;
			bufH = allowMT.bufH;
			mt.SetSampleSize(allowMT.nSampleSize);
		}
		else if (allowMT.refFlag == GSREF_INPUT_PIN)
		{
			UINT nMatchIdx = m_pOutputPinDesc[pinIdx].nMatchIdx;
			if (nMatchIdx >= m_pInputPins.size() )
				return E_INVALIDARG;

			CMediaType inputMT = m_pInputPins[nMatchIdx]->CurrentMediaType();
			if (IsEqualGUID(*inputMT.FormatType(), FORMAT_VideoInfo))
			{				
				VIDEOINFOHEADER* pvi = (VIDEOINFOHEADER*)inputMT.Format();
				bufW = pvi->bmiHeader.biWidth;
				bufH = pvi->bmiHeader.biHeight;
				if (!IsEqualGUID(*allowMT.pSubType, MEDIASUBTYPE_RGB32) && !IsEqualGUID(*allowMT.pSubType, MEDIASUBTYPE_ARGB32))
					return E_INVALIDARG;
				mt.SetSampleSize(bufW*bufH*4);
			}
			else
			{
				return E_INVALIDARG;
			}
		}
		else if (allowMT.refFlag == GSREF_RENDERTARGET)
		{
			UINT nMatchIdx = m_pOutputPinDesc[pinIdx].nMatchIdx;
			if (nMatchIdx >= m_pRenderTargetList.size() || m_pRenderTargetList[nMatchIdx] == NULL)
				return E_INVALIDARG;
			ID3D11Texture2D* pTex = m_pRenderTargetList[nMatchIdx]->GetTexture();
			if (pTex == NULL)
				return E_INVALIDARG;
			D3D11_TEXTURE2D_DESC texDesc;
			pTex->GetDesc(&texDesc);
			bufW = texDesc.Width;
			bufH = texDesc.Height;
			if (IsEqualGUID(*allowMT.pSubType, GSMEDIASUBTYPE_GSTEX2D_POINTER))
			{
				mt.SetSampleSize(sizeof(GSTexture2D*));
			}
			else if (IsEqualGUID(*allowMT.pFormatType, FORMAT_VideoInfo) && 
				(IsEqualGUID(*allowMT.pSubType,  MEDIASUBTYPE_RGB32) || IsEqualGUID(*allowMT.pSubType, MEDIASUBTYPE_ARGB32)))
			{
				mt.SetSampleSize(bufW*bufH*4);
			}
			else
			{
				return E_INVALIDARG;
			}
		}
		else
		{
			return E_INVALIDARG;
		}
		if (allowMT.pFormatType != NULL)
		{
			if (IsEqualGUID(*allowMT.pFormatType, FORMAT_VideoInfo))
			{
				if (!IsEqualGUID(*allowMT.pSubType, MEDIASUBTYPE_RGB32) && !IsEqualGUID(*allowMT.pSubType, MEDIASUBTYPE_ARGB32))
					return E_INVALIDARG;
				mt.SetFormatType(allowMT.pFormatType);
				VIDEOINFOHEADER pvi;
				memset((void*)&pvi, 0, sizeof(VIDEOINFOHEADER));
				pvi.bmiHeader.biSizeImage = 0; //for uncompressed image
				pvi.bmiHeader.biWidth = bufW;
				pvi.bmiHeader.biHeight = bufH;
				pvi.bmiHeader.biBitCount = 32;
				SetRectEmpty(&(pvi.rcSource));
				SetRectEmpty(&(pvi.rcTarget));
				mt.SetFormat((BYTE*)&pvi, sizeof(VIDEOINFOHEADER));
			}
			else if (IsEqualGUID(*allowMT.pFormatType, GSFORMAT_DX11TEX2D_DESC))
			{
				if (allowMT.refFlag != GSREF_RENDERTARGET)
					return E_INVALIDARG;
				UINT nMatchIdx = m_pOutputPinDesc[pinIdx].nMatchIdx;
				if (nMatchIdx >= m_pRenderTargetList.size() || m_pRenderTargetList[nMatchIdx] == NULL)
					return E_INVALIDARG;
				mt.SetFormatType(&GSFORMAT_DX11TEX2D_DESC);

				ID3D11Texture2D* pTex = m_pRenderTargetList[nMatchIdx]->GetTexture();
				if (pTex == NULL)
					return E_INVALIDARG;
				D3D11_TEXTURE2D_DESC texDesc;
				pTex->GetDesc(&texDesc);
				mt.SetFormat((BYTE*)&texDesc, sizeof(D3D11_TEXTURE2D_DESC));
			}
			else
			{
				return E_INVALIDARG;
			}
		}
		*pMediaType = mt;
		return S_OK;
	}
	else if (pinType == GSSTREAM_PIN)
	{
		if (pinIdx >= m_pStreamPinDesc.size())
			return E_FAIL;

		UINT nAllowMTs = m_pStreamPinDesc[pinIdx].acceptTypes.nAcceptType;
		if (iPosition >= nAllowMTs)
			return VFW_S_NO_MORE_ITEMS;
		CMediaType mt;
		GSOUTPIN_ACCEPT_MEDIATYPE allowMT = m_pStreamPinDesc[pinIdx].acceptTypes.pAcceptTypes[iPosition];

		if (allowMT.pMainType != NULL)
		{
			mt.SetType(allowMT.pMainType);
		}
		if (allowMT.pSubType != NULL)
		{
			mt.SetSubtype(allowMT.pSubType);
		}
		mt.SetTemporalCompression(allowMT.bCompression);
		UINT bufW = 0, bufH = 0;
		if (allowMT.refFlag == GSREF_ACCEPT_MEDIATYPE)
		{
			bufW = allowMT.bufW;
			bufH = allowMT.bufH;
			mt.SetSampleSize(allowMT.nSampleSize);
		}
		else if (allowMT.refFlag == GSREF_INPUT_PIN)
		{
			UINT nMatchIdx = m_pStreamPinDesc[pinIdx].nMatchIdx;
			if (nMatchIdx >= m_pInputPins.size() )
				return E_INVALIDARG;

			CMediaType inputMT = m_pInputPins[nMatchIdx]->CurrentMediaType();
			if (IsEqualGUID(*inputMT.FormatType(), FORMAT_VideoInfo))
			{				
				VIDEOINFOHEADER* pvi = (VIDEOINFOHEADER*)inputMT.Format();
				bufW = pvi->bmiHeader.biWidth;
				bufH = pvi->bmiHeader.biHeight;
				if (!IsEqualGUID(*allowMT.pSubType, MEDIASUBTYPE_RGB32) && !IsEqualGUID(*allowMT.pSubType, MEDIASUBTYPE_ARGB32))
					return E_INVALIDARG;
				mt.SetSampleSize(bufW*bufH*4);
			}
			else
			{
				return E_INVALIDARG;
			}
		}
		else if (allowMT.refFlag == GSREF_RENDERTARGET)
		{
			UINT nMatchIdx = m_pStreamPinDesc[pinIdx].nMatchIdx;
			if (nMatchIdx >= m_pRenderTargetList.size() || m_pRenderTargetList[nMatchIdx] == NULL)
				return E_INVALIDARG;
			ID3D11Texture2D* pTex = m_pRenderTargetList[nMatchIdx]->GetTexture();
			if (pTex == NULL)
				return E_INVALIDARG;
			D3D11_TEXTURE2D_DESC texDesc;
			pTex->GetDesc(&texDesc);
			bufW = texDesc.Width;
			bufH = texDesc.Height;
			if (IsEqualGUID(*allowMT.pSubType, GSMEDIASUBTYPE_GSTEX2D_POINTER))
			{
				mt.SetSampleSize(sizeof(GSTexture2D*));
			}
			else if (IsEqualGUID(*allowMT.pFormatType, FORMAT_VideoInfo) && 
				(IsEqualGUID(*allowMT.pSubType,  MEDIASUBTYPE_RGB32) || IsEqualGUID(*allowMT.pSubType, MEDIASUBTYPE_ARGB32)))
			{
				mt.SetSampleSize(bufW*bufH*4);
			}
			else
			{
				return E_INVALIDARG;
			}
		}
		else
		{
			return E_INVALIDARG;
		}
		if (allowMT.pFormatType != NULL)
		{
			if (IsEqualGUID(*allowMT.pFormatType, FORMAT_VideoInfo))
			{
				if (!IsEqualGUID(*allowMT.pSubType, MEDIASUBTYPE_RGB32) && !IsEqualGUID(*allowMT.pSubType, MEDIASUBTYPE_ARGB32))
					return E_INVALIDARG;
				mt.SetFormatType(allowMT.pFormatType);
				VIDEOINFOHEADER pvi;
				memset((void*)&pvi, 0, sizeof(VIDEOINFOHEADER));
				pvi.bmiHeader.biSizeImage = 0; //for uncompressed image
				pvi.bmiHeader.biWidth = bufW;
				pvi.bmiHeader.biHeight = bufH;
				pvi.bmiHeader.biBitCount = 32;
				SetRectEmpty(&(pvi.rcSource));
				SetRectEmpty(&(pvi.rcTarget));
				mt.SetFormat((BYTE*)&pvi, sizeof(VIDEOINFOHEADER));
			}
			else if (IsEqualGUID(*allowMT.pFormatType, GSFORMAT_DX11TEX2D_DESC))
			{
				if (allowMT.refFlag != GSREF_RENDERTARGET)
					return E_INVALIDARG;
				UINT nMatchIdx = m_pStreamPinDesc[pinIdx].nMatchIdx;
				if (nMatchIdx >= m_pRenderTargetList.size() || m_pRenderTargetList[nMatchIdx] == NULL)
					return E_INVALIDARG;
				mt.SetFormatType(&GSFORMAT_DX11TEX2D_DESC);

				ID3D11Texture2D* pTex = m_pRenderTargetList[nMatchIdx]->GetTexture();
				if (pTex == NULL)
					return E_INVALIDARG;
				D3D11_TEXTURE2D_DESC texDesc;
				pTex->GetDesc(&texDesc);
				mt.SetFormat((BYTE*)&texDesc, sizeof(D3D11_TEXTURE2D_DESC));
			}
			else
			{
				return E_INVALIDARG;
			}
		}
		*pMediaType = mt;
		return S_OK;
	}

	return VFW_S_NO_MORE_ITEMS;
}

HRESULT GSDXMuxFilter::CompleteConnect_InitD3D(void* self, PIN_DIRECTION direction, const IPin* pMyPin, const IPin* pOtherPin)
{
	if (self == NULL || pMyPin == NULL || pOtherPin == NULL)
		return E_FAIL;
	GSDXMuxFilter* pSelf = (GSDXMuxFilter*) self;
	HRESULT hr = S_OK;

	UINT pinIdx = 0;
	GSPIN_TYPE pinType = GSINPUT_PIN;

	hr = pSelf->_GetPinIdx(pMyPin, pinIdx, pinType);
	if (FAILED(hr) || pinType != GSINPUT_PIN)
		return E_FAIL;

	CMediaType inputMT = ((GSDXMuxInputPin*)pMyPin)->CurrentMediaType();
	if (IsEqualGUID(*inputMT.Type(), GSMEDIATYPE_GSDX11_MEDIATYPE)) 
	{
		if (IsEqualGUID(*inputMT.Subtype(), GSMEDIASUBTYPE_GSTEX2D_POINTER) 
			&& IsEqualGUID(*inputMT.FormatType(), GSFORMAT_DX11TEX2D_DESC))
		{
			WCHAR effectPath[MAX_PATH] = {0};
			hr = pSelf->GetEffectFilePath(effectPath, MAX_PATH);
			if (FAILED(hr))
				return E_FAIL;
			D3D11_TEXTURE2D_DESC* texDesc = (D3D11_TEXTURE2D_DESC*)inputMT.pbFormat;
			if (texDesc == NULL)
				return E_FAIL;
			hr = pSelf->initD3D(effectPath, MAX_PATH, texDesc->Width, texDesc->Height);
			return hr;
		}
		else
		{
			return E_FAIL;
		}
	}
	else if (IsEqualGUID(*inputMT.Type(), GSMEDIATYPE_GSDX11_SHAREDEVICE_MEDIATYPE))
	{
		if (IsEqualGUID(*inputMT.Subtype(), GSMEDIASUBTYPE_GSTEX2D_POINTER) && 
			IsEqualGUID(*inputMT.FormatType(), GSFORMAT_DX11TEX2D_DESC))
		{
			D3D11_TEXTURE2D_DESC* texDesc = (D3D11_TEXTURE2D_DESC*)inputMT.pbFormat;
			IGSDXSharePin* pMyDXPin = NULL;
			hr = pSelf->m_pInputPins[pinIdx]->QueryInterface(IID_IGSDXSharePin, (LPVOID *)&pMyDXPin);
			if (pMyDXPin == NULL)
				return E_FAIL;
			ID3D11Device* pDevice = NULL;
			ID3D11DeviceContext* pDeviceContext = NULL;
			IDXGISwapChain* pSwapChain = NULL;
			hr = pMyDXPin->QueryD3DDevice(pDevice, pDeviceContext, pSwapChain);
			if (pDevice == NULL || pDeviceContext == NULL || pSwapChain == NULL)
				return E_FAIL;

			WCHAR effectPath[MAX_PATH] = {0};
			hr = pSelf->GetEffectFilePath(effectPath, MAX_PATH);
			if (FAILED(hr))
				return E_FAIL;

			hr = pSelf->initD3D(effectPath, MAX_PATH, texDesc->Width, texDesc->Height, 1, 1, 1, pDevice, pDeviceContext, pSwapChain);
			SAFE_RELEASE(pMyDXPin);
			SAFE_RELEASE(pDevice);
			SAFE_RELEASE(pDeviceContext);
			SAFE_RELEASE(pSwapChain);
			return hr;
		}
		else
		{
			return E_FAIL;
		}
	}
	else if (IsEqualGUID(*inputMT.Type(), MEDIATYPE_Video))
	{
		if (IsEqualGUID(*inputMT.FormatType(), FORMAT_VideoInfo))
		{
			WCHAR effectPath[MAX_PATH] = {0};
			hr = pSelf->GetEffectFilePath(effectPath, MAX_PATH);
			if (FAILED(hr))
				return E_FAIL;
			VIDEOINFOHEADER *pvi = (VIDEOINFOHEADER *) inputMT.pbFormat;
			BITMAPINFOHEADER bitHeader = pvi->bmiHeader;
			pSelf->initD3D(effectPath, MAX_PATH, bitHeader.biWidth, bitHeader.biHeight);
		}
		else
		{
			return E_FAIL;
		}
	}
	
	return S_OK;
}
HRESULT GSDXMuxFilter::Transform_D3DRender(void* self, IMediaSample *pInSample, CMediaType* inMT, 
										   IMediaSample *pOutSample, CMediaType* outMT)
{
	if (self == NULL || pInSample == NULL || pOutSample == NULL || inMT == NULL || outMT == NULL)
	{
		return E_FAIL;
	}
	GSDXMuxFilter* pSelf = (GSDXMuxFilter*)self;
	HRESULT hr = S_OK;
	hr = pSelf->DoTransform(pInSample, pOutSample, inMT, outMT);
	return hr;
}
HRESULT GSDXMuxFilter::BreakConnect_ReleaseD3D(void* self, PIN_DIRECTION dir, const IPin* pPin)
{
	if (self == NULL || pPin == NULL)
	{
		return E_FAIL;
	}
	GSDXMuxFilter* pSelf = (GSDXMuxFilter*)self;
	return pSelf->ReleaseD3D();
}

HRESULT GSDXMuxFilter::GetEffectFilePath(WCHAR* szPath, UINT szSize)
{
	if (szPath == NULL || szSize == 0)
		return E_FAIL;
	swprintf_s(szPath, szSize, L"../fx/GSBasicEffect.fx");
	return S_OK;
}