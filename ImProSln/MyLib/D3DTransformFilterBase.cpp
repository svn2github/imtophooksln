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
	m_texW = 0; 
	m_texH = 0;
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
HRESULT D3DTransformFilterBase::initD3D(UINT rtWidth, UINT rtHeight, IDirect3DDevice9* pDevice)
{
	HRESULT hr;
	hr = D3DEnv::initD3D(rtWidth, rtHeight, pDevice);
	if (m_pD3DDisplay != NULL)
	{
		delete m_pD3DDisplay;
		m_pD3DDisplay = NULL;
	}
	if (pDevice == NULL)
	{
		m_pD3DDisplay = Create3DDisplay(GetD3D9(), rtWidth, rtHeight);
	}
	else
	{
		m_pD3DDisplay = Create3DDisplay(pDevice, rtWidth, rtHeight);
	}
	if (m_pD3DDisplay == NULL)
	{
		return S_FALSE;
	}
	m_pD3DDisplay->SetDeviceLostCallback((MS3DDisplay::DeviceLostCallBack)OnBeforeDisplayResetDevice, 
		(MS3DDisplay::DeviceLostCallBack)OnAfterDisplayResetDevice, (void*)this);
	hr = CreateTextures(rtWidth, rtHeight);
	m_texW = rtWidth;
	m_texH = rtHeight;
	return hr;
}

HRESULT D3DTransformFilterBase::CopyRenderTarget2OutputTexture()
{
	HRESULT hr;
	if (m_pD3DDisplay == NULL || m_pOutTexture == NULL || m_pRenderTarget == NULL)
		return S_FALSE;
	
	if (FAILED(TestDisplayDeviceLost()))
		return S_FALSE;
	CAutoLock lck0(&m_csD3DDisplay);
	CAutoLock lck1(&m_csOutTexture);
	CAutoLock lck2(&m_csRenderTarget);
	IDirect3DDevice9* pDevice = m_pD3DDisplay->GetD3DDevice();

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
	if (pIn == NULL || pInMediaType == NULL || m_pInTexture == NULL)
	{
		return S_FALSE;
	}
	HRESULT hr = S_OK;

	if (FAILED(TestDisplayDeviceLost()))
	{
		return S_FALSE;
	}
	CAutoLock lck(&m_csInTexture);
	IDirect3DDevice9* pDevice = m_pD3DDisplay->GetD3DDevice();
	GUID guidSubType = pInMediaType->subtype;

	LPDIRECT3DSURFACE9 pInSurface = NULL;
	D3DSURFACE_DESC surInDesc;
	m_pInTexture->GetLevelDesc(0, &surInDesc);
	
	IplImage* pImg = NULL;
	if (IsEqualGUID(*pInMediaType->Type(), GUID_D3DMEDIATYPE) && IsEqualGUID(guidSubType, GUID_D3DSHARE_RTTEXTURE_POINTER))
	{
		LPDIRECT3DTEXTURE9 pInputTexture = NULL;
		pIn->GetPointer((BYTE**)&pInputTexture);
		if (pInputTexture == NULL)
		{
			return E_FAIL;
		}
		if (m_pInTexture != NULL)
		{
			m_pInTexture->Release();
			m_pInTexture = NULL;
		}
		m_pInTexture = pInputTexture;
		m_pInTexture->AddRef();
	}
	else if (IsEqualGUID(*pInMediaType->Type(), GUID_D3DMEDIATYPE) && IsEqualGUID(guidSubType, GUID_D3DXTEXTURE9_POINTER))
	{
		m_pInTexture->GetSurfaceLevel(0, &pInSurface);
		LPDIRECT3DTEXTURE9 pInputTexture = NULL;
		LPDIRECT3DSURFACE9 pInputSurface = NULL;
		D3DSURFACE_DESC inputDesc;
		pIn->GetPointer((BYTE**)&pInputTexture);
		if (pInputTexture == NULL)
		{
			return E_FAIL;
		}
		hr = pInputTexture->GetSurfaceLevel(0, &pInputSurface);
		pInputSurface->GetDesc(&inputDesc);

		DWORD filterFlag = D3DX_FILTER_POINT;
		
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
			hr = D3DXLoadSurfaceFromMemory(pInSurface, NULL, NULL, pInData, D3DFMT_R8G8B8, bitHeader.biWidth * 3, NULL, &rect, D3DX_FILTER_POINT, NULL);
		}
		else if (IsEqualGUID(guidSubType, MEDIASUBTYPE_ARGB32) || IsEqualGUID(guidSubType, MEDIASUBTYPE_RGB32) )
		{
			hr = D3DXLoadSurfaceFromMemory(pInSurface, NULL, NULL, pInData, D3DFMT_A8R8G8B8, bitHeader.biWidth * 4, NULL, &rect, D3DX_FILTER_POINT, NULL);
		}
		else
		{
			hr = E_FAIL;
		}
	}
	if (bFlipY && !IsEqualGUID(guidSubType, GUID_D3DSHARE_RTTEXTURE_POINTER))
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
HRESULT D3DTransformFilterBase::CopyRenderTarget2OutputData(IMediaSample *pOut, const CMediaType* pOutMediaType)
{
	if (pOut == NULL || m_pRenderTarget == NULL)
	{
		return S_FALSE;
	}
	HRESULT hr = S_OK;
	if (FAILED(TestDisplayDeviceLost()))
	{
		return S_FALSE;
	}
	CAutoLock lck(&m_csOutTexture);
	IDirect3DDevice9* pDevice = m_pD3DDisplay->GetD3DDevice();
	GUID guidSubType = pOutMediaType->subtype;


	D3DSURFACE_DESC surOutDesc;
	hr = m_pRenderTarget->GetLevelDesc(0, &surOutDesc);
	D3DLOCKED_RECT rect;

	if (IsEqualGUID(*pOutMediaType->Type(), GUID_D3DMEDIATYPE) && IsEqualGUID(*pOutMediaType->Subtype(), GUID_D3DSHARE_RTTEXTURE_POINTER))
	{	
		((CMediaSample*)pOut)->SetPointer((BYTE*)m_pRenderTarget, sizeof(LPDIRECT3DTEXTURE9));
	}
	else
	{
		return S_FALSE;
	}
	return S_OK;
}
HRESULT D3DTransformFilterBase::CopyOutputTexture2OutputData(IMediaSample *pOut, const CMediaType* pOutMediaType, bool bFlipY = false)
{
	if (pOut == NULL || m_pOutTexture == NULL)
	{
		return S_FALSE;
	}
	HRESULT hr = S_OK;
	if (FAILED(TestDisplayDeviceLost()))
	{
		return S_FALSE;
	}
	CAutoLock lck(&m_csOutTexture);
	IDirect3DDevice9* pDevice = m_pD3DDisplay->GetD3DDevice();
	GUID guidSubType = pOutMediaType->subtype;
	
	LPDIRECT3DSURFACE9 pOutSurface = NULL;
	D3DSURFACE_DESC surOutDesc;
	m_pOutTexture->GetSurfaceLevel(0, &pOutSurface);
	pOutSurface->GetDesc(&surOutDesc);
	D3DLOCKED_RECT rect;
	
	if (IsEqualGUID(*pOutMediaType->Type(), GUID_D3DMEDIATYPE) && IsEqualGUID(*pOutMediaType->Subtype(), GUID_D3DXTEXTURE9_POINTER))
	{	
		((CMediaSample*)pOut)->SetPointer((BYTE*)m_pOutTexture, sizeof(LPDIRECT3DTEXTURE9));
	}
	else if(IsEqualGUID(*pOutMediaType->Type(), GUID_D3DMEDIATYPE) && IsEqualGUID(*pOutMediaType->Subtype(), GUID_D3DSHARE_RTTEXTURE_POINTER))
	{
		return S_FALSE;
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

HRESULT D3DTransformFilterBase::DoTransform(IMediaSample *pIn, IMediaSample *pOut, const CMediaType* pInType, const CMediaType* pOutType, bool bFlipY)
{		
	HRESULT hr = S_OK;
	hr = CopyInputImage2InputTexture(pIn, pInType, bFlipY);
	if (FAILED(hr))
		return S_FALSE;
	hr = SetRenderTarget();
	if (FAILED(hr))
		return S_FALSE;
	{
		CAutoLock lck0(&m_csD3DDisplay);
		CAutoLock lck1(&m_csInTexture);
		CAutoLock lck2(&m_csRenderTarget);
		m_pD3DDisplay->SetTexture(m_pInTexture);
		m_pD3DDisplay->Render();
		m_pD3DDisplay->SetTexture(NULL);
	}
	hr = ResetRenderTarget();
	if (FAILED(hr))
		return S_FALSE;
	if (IsEqualGUID(*pOutType->Type(), GUID_D3DMEDIATYPE) && IsEqualGUID(*pOutType->Subtype(), GUID_D3DSHARE_RTTEXTURE_POINTER))
	{
		hr = CopyRenderTarget2OutputData(pOut, pOutType);
	}
	else
	{
		hr = CopyRenderTarget2OutputTexture();
		if (FAILED(hr))
			return S_FALSE;
		hr = CopyOutputTexture2OutputData(pOut, pOutType, true);
	}

	return S_OK;
}
HRESULT D3DTransformFilterBase::CreateTextures(UINT w, UINT h)
{
	HRESULT hr = S_FALSE;
	CAutoLock lck0(&m_csInTexture);
	CAutoLock lck1(&m_csOutTexture);
	CAutoLock lck2(&m_csRenderTarget);
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
	HRESULT hr;
	if (FAILED(TestDisplayDeviceLost()))
	{
		return S_FALSE;
	}
	CAutoLock lck0(&m_csD3DDisplay);
	CAutoLock lck1(&m_csRenderTarget);
	if (m_pRenderTarget == NULL || m_pD3DDisplay == NULL)
	{
		return S_FALSE;
	}
	IDirect3DDevice9* pDevice = m_pD3DDisplay->GetD3DDevice();
	LPDIRECT3DSURFACE9 pRTSurface = NULL;
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
	if (FAILED(TestDisplayDeviceLost()))
		return S_FALSE;
	CAutoLock lck0(&m_csD3DDisplay);
	CAutoLock lck1(&m_csRenderTarget);
	HRESULT hr = S_OK;
	if (m_pBackupRenderTarget == NULL || m_pD3DDisplay == NULL)
	{
		return S_FALSE;
	}
	IDirect3DDevice9* pDevice = m_pD3DDisplay->GetD3DDevice();
	pDevice->SetRenderTarget(0, m_pBackupRenderTarget);

	m_pBackupRenderTarget->Release();
	m_pBackupRenderTarget = NULL;
	return S_OK;
}
HRESULT D3DTransformFilterBase::OnBeforeResetDevice(IDirect3DDevice9 * pd3dDevice,	
									void* pUserContext)
{

	return __super::OnBeforeResetDevice(pd3dDevice, pUserContext);
}
HRESULT D3DTransformFilterBase::OnAfterResetDevice(IDirect3DDevice9 * pd3dDevice,	
								    void* pUserContext)
{

	return __super::OnAfterResetDevice(pd3dDevice, pUserContext);
}

HRESULT D3DTransformFilterBase::TestDisplayDeviceLost()
{
	if (m_pD3DDisplay == NULL)
		return S_FALSE;
	HRESULT hr = S_OK;
	
	IDirect3DDevice9* pDevice = m_pD3DDisplay->GetD3DDevice();
	hr = pDevice->TestCooperativeLevel();
	if (FAILED(hr))
	{
		if (hr == D3DERR_DEVICELOST)
		{
			return S_FALSE;
		}
		else if (hr == D3DERR_DEVICENOTRESET)
		{
			SendMessageW(m_pD3DDisplay->GetDisplayWindow(), MS3DDisplay::D3DDEVICELOST, 0, 0);
		}
	}
	return hr;
}
HRESULT D3DTransformFilterBase::OnBeforeDisplayResetDevice(IDirect3DDevice9 * pd3dDevice, 
										 void* pUserContext)
{
	D3DTransformFilterBase* pThis = (D3DTransformFilterBase*) pUserContext; 
	if (pThis == NULL)
		return S_FALSE;

	if (pThis->m_pInTexture != NULL)
	{
		pThis->m_pInTexture->Release();
		pThis->m_pInTexture = NULL;
	}
	if (pThis->m_pOutTexture != NULL)
	{
		pThis->m_pOutTexture->Release();
		pThis->m_pOutTexture = NULL;
	}
	if (pThis->m_pRenderTarget != NULL)
	{
		pThis->m_pRenderTarget->Release();
		pThis->m_pRenderTarget = NULL;
	}

	return S_OK;
}
HRESULT D3DTransformFilterBase::OnAfterDisplayResetDevice(IDirect3DDevice9 * pd3dDevice, 
										  void* pUserContext)
{
	D3DTransformFilterBase* pThis = (D3DTransformFilterBase*) pUserContext; 
	if (pThis == NULL)
		return S_FALSE;
	if (pd3dDevice == NULL)
		return S_FALSE;
	pd3dDevice->SetRenderState( D3DRS_ZENABLE, TRUE );
	// Turn on ambient lighting 
	pd3dDevice->SetRenderState( D3DRS_AMBIENT, 0xffffffff );
	pd3dDevice->SetRenderState( D3DRS_CULLMODE, D3DCULL_CW);

	pd3dDevice->SetTextureStageState(0, D3DTSS_CONSTANT, 0xfffffffff );
	pd3dDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);
	pd3dDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_CONSTANT);
	pd3dDevice->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_TEXTURE);
	pd3dDevice->SetTextureStageState(1, D3DTSS_COLOROP, D3DTOP_DISABLE);
	pThis->CreateTextures(pThis->m_texW, pThis->m_texH);
	return S_OK;
}