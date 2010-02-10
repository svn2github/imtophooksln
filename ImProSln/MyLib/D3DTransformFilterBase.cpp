#include "D3DTransformFilterBase.h"
#include "cv.h"
#include "MyMediaSample.h"
#include "CMuxTransformFilter.h"

D3DTransformFilterBase::D3DTransformFilterBase()
{
	m_pD3DDisplay = NULL;
	m_pOutTexture = NULL;
	m_pInTexture = NULL;
	m_pRenderTarget = NULL;
	m_pBackupRenderTarget = NULL;
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
	CAutoLock lck(&m_csInTexture);
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
	if (m_pBackupRenderTarget != NULL)
	{
		m_pBackupRenderTarget->Release();
		m_pBackupRenderTarget = NULL;
	}
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
	m_pD3DDisplay = Create3DDisplay(GetD3D9(), rtWidth, rtHeight);
	if (m_pD3DDisplay == NULL)
	{
		return S_FALSE;
	}

	hr = CreateTextures(rtWidth, rtHeight);
	return hr;
}

HRESULT D3DTransformFilterBase::CopyRenderTarget2OutputTexture()
{
	HRESULT hr;
	if (m_pD3DDisplay == NULL)
		return S_FALSE;
	IDirect3DDevice9 * pDevice = m_pD3DDisplay->GetD3DDevice();

	LPDIRECT3DSURFACE9 pOutSurface = NULL;
	LPDIRECT3DSURFACE9 pRenderTarget = NULL;
	D3DSURFACE_DESC surRenderDesc, surOutDesc;
	m_pOutTexture->GetSurfaceLevel(0, &pOutSurface);
	m_pRenderTarget->GetSurfaceLevel(0, &pRenderTarget);
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
HRESULT D3DTransformFilterBase::CopyInputImage2InputTexture(IMediaSample *pIn, const CMediaType* pInMediaType, bool bFlipY = false )
{
	if (pIn == NULL || pInMediaType == NULL)
	{
		return S_FALSE;
	}
	HRESULT hr = S_OK;
	CAutoLock lck(&m_csInTexture);
	GUID guidSubType = pInMediaType->subtype;

	LPDIRECT3DSURFACE9 pInSurface = NULL;
	D3DSURFACE_DESC surInDesc;
	m_pInTexture->GetSurfaceLevel(0, &pInSurface);
	pInSurface->GetDesc(&surInDesc);
	IplImage* pImg = NULL;

	if (IsEqualGUID(*pInMediaType->Type(), GUID_MyMediaSample) && IsEqualGUID(guidSubType, GUID_D3DXTEXTURE9_POINTER))
	{
		LPDIRECT3DTEXTURE9 pInputTexture = NULL;
		LPDIRECT3DSURFACE9 pInputSurface = NULL;
		pIn->GetPointer((BYTE**)&pInputTexture);
		if (pInputTexture == NULL)
		{
			return E_FAIL;
		}
		DWORD filterFlag = D3DX_FILTER_LINEAR;
		hr = pInputTexture->GetSurfaceLevel(0, &pInputSurface);
		hr = D3DXLoadSurfaceFromSurface(pInSurface, NULL, NULL, pInputSurface, NULL, NULL,
			filterFlag, 0);
		if (pInputSurface != NULL)
		{
			pInputSurface->Release();
			pInputSurface = NULL;
		}
	}
	else
	{
		BYTE* pInData = NULL;
		hr = pIn->GetPointer(&pInData);
		if (FAILED(hr))
			return hr;
		VIDEOINFOHEADER *pvi = (VIDEOINFOHEADER *) pInMediaType->pbFormat;
		BITMAPINFOHEADER bitHeader = pvi->bmiHeader;
		RECT rect;
		rect.left = 0;
		rect.right = bitHeader.biWidth;
		rect.top = 0;
		rect.bottom = bitHeader.biHeight;
		if (IsEqualGUID(guidSubType, MEDIASUBTYPE_RGB24))
		{
			hr = D3DXLoadSurfaceFromMemory(pInSurface, NULL, NULL, pInData, D3DFMT_R8G8B8, bitHeader.biWidth * 3, NULL, &rect, D3DX_FILTER_LINEAR, NULL);
		}
		else if (IsEqualGUID(guidSubType, MEDIASUBTYPE_ARGB32) || IsEqualGUID(guidSubType, MEDIASUBTYPE_RGB32) )
		{
			hr = D3DXLoadSurfaceFromMemory(pInSurface, NULL, NULL, pInData, D3DFMT_A8R8G8B8, bitHeader.biWidth * 4, NULL, &rect, D3DX_FILTER_LINEAR, NULL);
		}
		else
		{
			hr = E_FAIL;
		}
	}
	if (bFlipY)
	{
		D3DLOCKED_RECT surRect;
		pInSurface->LockRect(&surRect, NULL, 0);
		pImg = cvCreateImageHeader(cvSize(surInDesc.Width, surInDesc.Height), 8, 4);
		pImg->imageData = (char*)surRect.pBits;
		cvFlip(pImg, NULL, 0);
		pInSurface->UnlockRect();
	}
	if ( pInSurface != NULL)
	{
		pInSurface->Release();
		pInSurface = NULL;
	}
	if (pImg != NULL)
	{
		cvReleaseImageHeader(&pImg);
	}
	return hr;
}
HRESULT D3DTransformFilterBase::CopyOutputTexture2OutputData(IMediaSample *pOut, const CMediaType* pOutMediaType, bool bFlipY = false)
{
	if (pOut == NULL)
	{
		return S_FALSE;
	}
	HRESULT hr;
	GUID guidSubType = pOutMediaType->subtype;
	
	LPDIRECT3DSURFACE9 pOutSurface = NULL;
	D3DSURFACE_DESC surOutDesc;
	m_pOutTexture->GetSurfaceLevel(0, &pOutSurface);
	pOutSurface->GetDesc(&surOutDesc);
	D3DLOCKED_RECT rect;
	
	if (IsEqualGUID(*pOutMediaType->Type(), GUID_MyMediaSample) && IsEqualGUID(*pOutMediaType->Subtype(), GUID_D3DXTEXTURE9_POINTER))
	{	
		((CMediaSample*)pOut)->SetPointer((BYTE*)m_pOutTexture, sizeof(LPDIRECT3DTEXTURE9));
	}
	else
	{
		BYTE* pOutData = NULL;
		pOut->GetPointer(&pOutData);
		int channel = 4;
		VIDEOINFOHEADER *pvi = (VIDEOINFOHEADER *) pOutMediaType->pbFormat;
		BITMAPINFOHEADER bitHeader = pvi->bmiHeader;
		int surHeight = surOutDesc.Height;
		int surWidth = surOutDesc.Width;
		int height = bitHeader.biHeight;
		int width = bitHeader.biWidth;
		if (IsEqualGUID(guidSubType, MEDIASUBTYPE_RGB24))
		{
			channel = 3;
		}
		else if(IsEqualGUID(guidSubType, MEDIASUBTYPE_RGB32) || IsEqualGUID(guidSubType, MEDIASUBTYPE_ARGB32))
		{
			channel = 4;
		}
		pOutSurface->LockRect(&rect, NULL, D3DLOCK_READONLY);
		if (bFlipY)
		{	
			int x = 0; int y = 0; int dstX = 0; int dstY = 0;
			float tmpW = ((float)surWidth) / width;
			float tmpH = ((float)surHeight) / height;
			for( y = 0; y < height; y++ )
			{
				for ( x = 0; x< width; x++)
				{
					dstX = x * tmpW;  dstY = y * tmpH;
					pOutData[(height - y -1)*width*channel + x*channel] = ((BYTE*)rect.pBits)[(int)(dstY*rect.Pitch + dstX*4)];
					pOutData[(height - y -1)*width*channel + x*channel + 1] = ((BYTE*)rect.pBits)[(int)(dstY*rect.Pitch + dstX*4 + 1)];
					pOutData[(height - y -1)*width*channel + x*channel + 2] = ((BYTE*)rect.pBits)[(int)(dstY*rect.Pitch + dstX*4 + 2)];
				}
			}
		}
		else
		{
			int x = 0; int y = 0; int dstX = 0; int dstY = 0;
			float tmpW = ((float)surWidth) / width;
			float tmpH = ((float)surHeight) / height;
			for( y = 0; y < height; y++ )
			{
				for ( x = 0; x< width; x++)
				{
					dstX = x * tmpW;  dstY = y * tmpH;
					pOutData[y*width*channel + x*channel] = ((BYTE*)rect.pBits)[(int)(dstY*rect.Pitch + dstX*4)];
					pOutData[y*width*channel + x*channel + 1] = ((BYTE*)rect.pBits)[(int)(dstY*rect.Pitch + dstX*4 + 1)];
					pOutData[y*width*channel + x*channel + 2] = ((BYTE*)rect.pBits)[(int)(dstY*rect.Pitch + dstX*4 + 2)];
				}
			}
			
		}
		pOutSurface->UnlockRect();
	}
	if (pOutSurface != NULL)
	{
		pOutSurface->Release();
		pOutSurface = NULL;
	}
	return S_OK;
}

HRESULT D3DTransformFilterBase::DoTransform(IMediaSample *pIn, IMediaSample *pOut, const CMediaType* pInType, const CMediaType* pOutType, bool bFlipY = true)
{		
	CopyInputImage2InputTexture(pIn, pInType, bFlipY);
	SetRenderTarget();
	{
		CAutoLock lck(&m_csInTexture);
		m_pD3DDisplay->SetTexture(m_pInTexture);
		m_pD3DDisplay->Render();
	}
	ResetRenderTarget();
	CopyRenderTarget2OutputTexture();	
	CopyOutputTexture2OutputData(pOut, pOutType, true);
	return S_OK;
}
HRESULT D3DTransformFilterBase::CreateTextures(UINT w, UINT h)
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
	if (m_pRenderTarget != NULL)
	{
		m_pRenderTarget->Release();
		m_pRenderTarget = NULL;
	}
	if (w == 0 || h == 0)
	{
		HDC dc = GetDC(GetD3DWnd());
		w = GetDeviceCaps(dc, HORZRES);
		h = GetDeviceCaps(dc, VERTRES);
	}
	hr = D3DXCreateTexture(m_pD3DDisplay->GetD3DDevice(), w, h, 
		0,  0, D3DFMT_X8R8G8B8, D3DPOOL_SYSTEMMEM, &m_pOutTexture);
	if (FAILED(hr))
	{
		return hr;
	}
	hr=	D3DXCreateTexture(m_pD3DDisplay->GetD3DDevice(), w, h, 
		0,  0, D3DFMT_X8R8G8B8, D3DPOOL_MANAGED, &m_pInTexture);
	if (FAILED(hr))
	{
		return hr;
	}
	hr=	D3DXCreateTexture(m_pD3DDisplay->GetD3DDevice(), w, h, 
		0,  D3DUSAGE_RENDERTARGET, D3DFMT_X8R8G8B8, D3DPOOL_DEFAULT , &m_pRenderTarget);
	return hr;
}

HRESULT D3DTransformFilterBase::SetRenderTarget()
{
	if (m_pRenderTarget == NULL || m_pD3DDisplay == NULL)
	{
		return S_FALSE;
	}
	HRESULT hr;
	LPDIRECT3DSURFACE9 pRTSurface = NULL;
	IDirect3DDevice9* pDevice = m_pD3DDisplay->GetD3DDevice();
	hr = m_pRenderTarget->GetSurfaceLevel(0, &pRTSurface);
	
	hr = pDevice->GetRenderTarget(0, &m_pBackupRenderTarget);
	hr = pDevice->SetRenderTarget(0, pRTSurface);

	if (pRTSurface != NULL)
	{
		pRTSurface->Release();
		pRTSurface = NULL;
	}
	return S_OK;
}
HRESULT D3DTransformFilterBase::ResetRenderTarget()
{
	if (m_pBackupRenderTarget == NULL || m_pD3DDisplay == NULL)
	{
		return S_FALSE;
	}
	IDirect3DDevice9* pDevice = m_pD3DDisplay->GetD3DDevice();
	pDevice->SetRenderTarget(0, m_pBackupRenderTarget);

	m_pBackupRenderTarget->Release();
	m_pBackupRenderTarget = NULL;
}