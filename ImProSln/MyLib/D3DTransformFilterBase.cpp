#include "D3DTransformFilterBase.h"

D3DTransformFilterBase::D3DTransformFilterBase()
{

	m_pD3DDisplay = NULL;
	m_pOutTexture = NULL;
	m_pInTexture = NULL;
}

D3DTransformFilterBase::~D3DTransformFilterBase()
{
	ReleaseD3D();
}

HRESULT D3DTransformFilterBase::ReleaseD3D()
{
	if (m_pD3DDisplay != NULL)
	{
		delete m_pD3DDisplay;
		m_pD3DDisplay = NULL;
	}
	/*if (m_pInTexture != NULL)
	{
		m_pInTexture->Release();
		m_pInTexture = NULL;
	}
	if (m_pOutTexture != NULL)
	{
		m_pOutTexture->Release();
		m_pOutTexture = NULL;
	}*/
	__super::ReleaseD3D();
	return S_OK;
}
HRESULT D3DTransformFilterBase::initD3D(UINT rtWidth, UINT rtHeight)
{
	HRESULT hr;
	hr = D3DEnv::initD3D(rtWidth, rtHeight);
	if (m_pD3DDisplay != NULL)
	{
		delete m_pD3DDisplay;
		m_pD3DDisplay = NULL;
	}
	m_pD3DDisplay = Create3DDisplay(m_hWndD3D, m_pD3D, rtWidth, rtHeight);
	if (m_pD3DDisplay == NULL)
	{
		return S_FALSE;
	}

	hr = CreateInOutTextures(rtWidth, rtHeight);
	return hr;
}

HRESULT D3DTransformFilterBase::CopyRenderTarget2OutputTexture()
{
	HRESULT hr;
	IDirect3DDevice9 * pDevice = m_pD3DDisplay->GetD3DDevice();

	LPDIRECT3DSURFACE9 pOutSurface = NULL;
	LPDIRECT3DSURFACE9 pRenderTarget = NULL;
	D3DSURFACE_DESC surRenderDesc, surOutDesc;
	m_pOutTexture->GetSurfaceLevel(0, &pOutSurface);
	hr = pDevice->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &pRenderTarget );
	pRenderTarget->GetDesc(&surRenderDesc);
	pOutSurface->GetDesc(&surOutDesc);
	hr = pDevice->GetRenderTargetData(pRenderTarget, pOutSurface);
	if (pOutSurface != NULL)
	{
		pOutSurface->Release();
		pOutSurface = NULL;
	}
	if (pRenderTarget != NULL)
	{
		pRenderTarget->Release();
		pRenderTarget = NULL;
	}
	return S_OK;
}
HRESULT D3DTransformFilterBase::CopyInputImage2InputTexture(IMediaSample *pIn, const CMediaType* pInMediaType )
{
	if (pIn == NULL || pInMediaType == NULL)
	{
		return S_FALSE;
	}
	HRESULT hr = S_OK;
	BYTE* pInData = NULL;

	hr = pIn->GetPointer(&pInData);
	if (FAILED(hr))
		return hr;

	GUID guidSubType = pInMediaType->subtype;

	VIDEOINFOHEADER *pvi = (VIDEOINFOHEADER *) pInMediaType->pbFormat;
	BITMAPINFOHEADER bitHeader = pvi->bmiHeader;


	LPDIRECT3DSURFACE9 pInSurface = NULL;
	D3DSURFACE_DESC surInDesc;
	m_pInTexture->GetSurfaceLevel(0, &pInSurface);
	pInSurface->GetDesc(&surInDesc);

	

	RECT rect;
	rect.left = 0;
	rect.right = bitHeader.biWidth;
	rect.top = 0;
	rect.bottom = bitHeader.biHeight;
	if (IsEqualGUID(guidSubType, MEDIASUBTYPE_RGB24))
	{
		hr = D3DXLoadSurfaceFromMemory(pInSurface, NULL, NULL, pInData, D3DFMT_R8G8B8, bitHeader.biWidth * 3, NULL, &rect, D3DX_DEFAULT, NULL);
	}
	else if (IsEqualGUID(guidSubType, MEDIASUBTYPE_ARGB32) || IsEqualGUID(guidSubType, MEDIASUBTYPE_RGB32) )
	{
		hr = D3DXLoadSurfaceFromMemory(pInSurface, NULL, NULL, pInData, D3DFMT_A8R8G8B8, bitHeader.biWidth * 4, NULL, &rect, D3DX_DEFAULT, NULL);
	}
	else
	{
		hr = E_FAIL;
	}
	if ( pInSurface != NULL)
	{
		pInSurface->Release();
		pInSurface = NULL;
	}
	return hr;
}
HRESULT D3DTransformFilterBase::CopyOutputTexture2OutputData(IMediaSample *pOut, const CMediaType* pOutMediaType, bool bFlipY = false)
{
	if (pOut == NULL)
	{
		return S_FALSE;
	}
	BYTE* pOutData = NULL;
	pOut->GetPointer(&pOutData);
	
	GUID guidSubType = pOutMediaType->subtype;
	int channel = 4;
	LPDIRECT3DSURFACE9 pOutSurface = NULL;
	D3DSURFACE_DESC surOutDesc;
	m_pOutTexture->GetSurfaceLevel(0, &pOutSurface);
	pOutSurface->GetDesc(&surOutDesc);
	D3DLOCKED_RECT rect;
	pOutSurface->LockRect(&rect, NULL, D3DLOCK_READONLY);
	int height = surOutDesc.Height;
	int width = surOutDesc.Width;
	if (IsEqualGUID(guidSubType, MEDIASUBTYPE_RGB24))
	{
		channel = 3;
	}
	else if(IsEqualGUID(guidSubType, MEDIASUBTYPE_RGB32) || IsEqualGUID(guidSubType, MEDIASUBTYPE_ARGB32))
	{
		channel = 4;
	}
	if (bFlipY)
	{
		for(int y = 0; y < height; y++ )
		{
			for (int x = 0; x< width; x++)
			{
				pOutData[(height - y -1)*width*channel + x*channel] = ((BYTE*)rect.pBits)[y*rect.Pitch + x*4];
				pOutData[(height - y -1)*width*channel + x*channel + 1] = ((BYTE*)rect.pBits)[y*rect.Pitch + x*4 + 1];
				pOutData[(height - y -1)*width*channel + x*channel + 2] = ((BYTE*)rect.pBits)[y*rect.Pitch + x*4 + 2];
			}
		}
	}
	else
	{
		
		for(int y = 0; y < height; y++ )
		{
			for (int x = 0; x< width; x++)
			{
				pOutData[y*width*channel + x*channel] = ((BYTE*)rect.pBits)[y*rect.Pitch + x*4];
				pOutData[y*width*channel + x*channel + 1] = ((BYTE*)rect.pBits)[y*rect.Pitch + x*4 + 1];
				pOutData[y*width*channel + x*channel + 2] = ((BYTE*)rect.pBits)[y*rect.Pitch + x*4 + 2];
			}
		}
		
	}
	pOutSurface->UnlockRect();
	if (pOutSurface != NULL)
	{
		pOutSurface->Release();
		pOutSurface = NULL;
	}
}

HRESULT D3DTransformFilterBase::DoTransform(IMediaSample *pIn, IMediaSample *pOut, const CMediaType* pInType, const CMediaType* pOutType)
{
	CopyInputImage2InputTexture(pIn, pInType);
	m_pD3DDisplay->SetTexture(m_pInTexture);
	m_pD3DDisplay->Render();
	CopyRenderTarget2OutputTexture();
	CopyOutputTexture2OutputData(pOut, pOutType);

	return S_OK;
}
HRESULT D3DTransformFilterBase::CreateInOutTextures(UINT w, UINT h)
{
	HRESULT hr = S_FALSE;
	if (m_pInTexture != NULL)
	{
		m_pInTexture->Release();
		m_pInTexture = NULL;
	}
	if (m_pOutTexture != NULL)
	{
		m_pOutTexture->Release();
		m_pOutTexture = NULL;
	}
	hr = D3DXCreateTexture(m_pD3DDisplay->GetD3DDevice(), w, h, 
		0,  D3DUSAGE_DYNAMIC, D3DFMT_X8R8G8B8, D3DPOOL_SYSTEMMEM , &m_pOutTexture);
	if (FAILED(hr))
	{
		return hr;
	}
	hr=	D3DXCreateTexture(m_pD3DDisplay->GetD3DDevice(), w, h, 
		0,  D3DUSAGE_DYNAMIC, D3DFMT_X8R8G8B8, D3DPOOL_DEFAULT , &m_pInTexture);
	return hr;
}
