#include "stdafx.h"
#include "GSDXFilterBase.h"
#include "DXUT.h"
#include "GSD3DMediaType.h"
#include "GSMacro.h"
GSDXFilterBase::GSDXFilterBase()
{
	m_pD3DDisplay = NULL;

}
GSDXFilterBase::~GSDXFilterBase()
{
	ReleaseD3D();
}

HRESULT GSDXFilterBase::ReleaseD3D()
{
	SAFE_RELEASE(m_pD3DDisplay);
	ReleaseAllTextures();
	return S_OK;
}
HRESULT GSDXFilterBase::ReleaseAllTextures()
{
	for (int i =0; i < m_pOutTextureList.size(); i++)
	{
		SAFE_RELEASE(m_pOutTextureList.at(i));
	}
	m_pOutTextureList.clear();
	for (int i =0; i < m_pInTextureList.size(); i++)
	{
		SAFE_RELEASE(m_pInTextureList.at(i));
	}
	m_pInTextureList.clear();
	for (int i =0; i < m_pRenderTargetList.size(); i++)
	{
		SAFE_RELEASE(m_pRenderTargetList.at(i));
	}
	m_pRenderTargetList.clear();
	return S_OK;
}

HRESULT GSDXFilterBase::initD3D(LPCWSTR szEffectPath, UINT szSize, UINT bufW, UINT bufH, UINT nInTex, UINT nOutTex, UINT nRT,ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext, IDXGISwapChain* pSwapChain)
{
	HRESULT hr = S_OK;
	SAFE_RELEASE(m_pD3DDisplay);
	if (pDevice == NULL || pDeviceContext == NULL || pSwapChain == NULL)
	{
		m_pD3DDisplay = Create3DDisplay(bufW, bufH);
	}
	else
	{
		m_pD3DDisplay = Create3DDisplay(pDevice, pDeviceContext, pSwapChain);
	}
	if (m_pD3DDisplay == NULL)
	{
		return E_FAIL;
	}
	
	hr = m_pD3DDisplay->LoadEffectFromFile(szEffectPath, szSize);
	hr = CreateTextures(bufW, bufH, nInTex, nOutTex, nRT);

	return S_OK;	
}

GSRenderBase::CBEffectSetting GSDXFilterBase::GetCBEffectSetting()
{
	return OnEffectSetting;
}

HRESULT GSDXFilterBase::OnEffectSetting(ID3DX11Effect* pEffect, void* self)
{
	if (pEffect == NULL || self == NULL )
		return E_FAIL;

	GSDXFilterBase* pSelf = (GSDXFilterBase*)self;
	if (pSelf->m_pD3DDisplay == NULL)
		return E_FAIL;

	IGSCamera* pCamera = pSelf->m_pD3DDisplay->GetCamera();
	if (pCamera == NULL)
		return E_FAIL;
	
	ID3DX11EffectVariable* worldViewProj = pEffect->GetVariableByName("WorldViewProj")->AsMatrix();
	ID3DX11EffectVariable* sampleType = pEffect->GetVariableByName("g_sampleType")->AsScalar();
	ID3DX11EffectVariable* bFlipY = pEffect->GetVariableByName("g_bFlipY")->AsScalar();
	
	if (!worldViewProj->IsValid() || !sampleType->IsValid() || !bFlipY->IsValid())
		return E_FAIL;
	
	BOOL _bFlipY = false;
	int _sampleType = 1;
	D3DXMATRIX matView = pCamera->GetViewMatrix();
	D3DXMATRIX matProj = pCamera->GetProjMatrix();
	D3DXMATRIX matWorld;
	D3DXMatrixIdentity(&matWorld);
	D3DXMATRIX matWorldViewProj = matWorld * matView * matProj;
	worldViewProj->SetRawValue((void*)&matWorldViewProj, 0, sizeof(matWorldViewProj));
	sampleType->SetRawValue((void*)&sampleType, 0, sizeof(_sampleType));
	bFlipY->SetRawValue((void*)&_bFlipY, 0, sizeof(_bFlipY));

	return S_OK;
}

HRESULT GSDXFilterBase::CopyGSTexture2Sample(GSTexture2D* pGSTexture, IMediaSample *pSample, const CMediaType* pMediaType)
{
	if (pGSTexture == NULL || pSample == NULL || pMediaType == NULL)
		return E_FAIL;

	HRESULT hr = S_OK;
	CAutoLock lck(pGSTexture->GetCritSec());

	if (IsEqualGUID(*pMediaType->Type(), GSMEDIATYPE_GSDX11_SHAREDEVICE_MEDIATYPE) || IsEqualGUID(*pMediaType->Type(), GSMEDIATYPE_GSDX11_MEDIATYPE))
	{	
		if (IsEqualGUID(*pMediaType->Subtype(), GSMEDIASUBTYPE_GSTEX2D_POINTER))
		{
			//just copy pointer
			BYTE* pSampleBuf = NULL;
			pSample->GetPointer(&pSampleBuf);
			if (pSample->GetSize() < sizeof(GSTexture2D*))
			{
				return E_FAIL;
			}
			memcpy(pSampleBuf, &pGSTexture,  sizeof(GSTexture2D*));
			return S_OK;
		}
	}
	else if (IsEqualGUID(*pMediaType->Type(), MEDIATYPE_Video) )
	{
		if (IsEqualGUID(*pMediaType->Subtype(), MEDIASUBTYPE_RGB32))
		{
			BYTE* pSampleBuf = NULL;
			pSample->GetPointer(&pSampleBuf);

			ID3D11Texture2D* pTexture = pGSTexture->GetTexture();
			ID3D11DeviceContext* pDeviceContext = pGSTexture->GetDeviceContext();
			D3D11_MAPPED_SUBRESOURCE mappedResource = {0};
			if (pTexture == NULL || pDeviceContext == NULL)
				return E_FAIL;
			hr = pDeviceContext->Map(pTexture, 0, D3D11_MAP_READ, 0, &mappedResource);
			if (FAILED(hr))
			{
				return E_FAIL;
			}
			memcpy((void*)pSampleBuf, mappedResource.pData, pSample->GetSize());
			pDeviceContext->Unmap(pTexture, 0);
			return S_OK;
		}
	}
	return E_FAIL;
}

HRESULT GSDXFilterBase::CopySample2GSTexture(GSTexture2D*& pGSTexture, IMediaSample *pSample, const CMediaType* pMediaType)
{
	if (pGSTexture == NULL || pSample == NULL || pMediaType == NULL)
		return E_FAIL;

	HRESULT hr = S_OK;
	CAutoLock lck(pGSTexture->GetCritSec());
	if (IsEqualGUID(*pMediaType->Type(), GSMEDIATYPE_GSDX11_SHAREDEVICE_MEDIATYPE))
	{
		if (IsEqualGUID(*pMediaType->Subtype(), GSMEDIASUBTYPE_GSTEX2D_POINTER))
		{
			BYTE* pSampleBuf = NULL;
			pSample->GetPointer(&pSampleBuf);
			GSTexture2D* pInSampleTex = *(GSTexture2D**)pSampleBuf;
			if (pInSampleTex == NULL)
			{
				return E_FAIL;
			}
			SAFE_RELEASE(pGSTexture);
			pGSTexture = pInSampleTex;
			SAFE_ADDREF(pGSTexture);
		}
	}
	else if ( IsEqualGUID(*pMediaType->Type(), GSMEDIATYPE_GSDX11_MEDIATYPE))
	{	
		if (IsEqualGUID(*pMediaType->Subtype(), GSMEDIASUBTYPE_GSTEX2D_POINTER))
		{
			//just copy pointer	
			BYTE* pSampleBuf = NULL;
			pSample->GetPointer(&pSampleBuf);
			GSTexture2D* pInSampleTex = *(GSTexture2D**)pSampleBuf;
			if (pInSampleTex == NULL)
			{
				return E_FAIL;
			}
			ID3D11Texture2D* pTexture = pGSTexture->GetTexture();
			if (pTexture == NULL)
				return E_FAIL;
			D3D11_TEXTURE2D_DESC texDesc;
			pTexture->GetDesc(&texDesc);
			if (texDesc.MiscFlags & D3D11_RESOURCE_MISC_SHARED) 
			{
				SAFE_RELEASE(pGSTexture);
				pGSTexture = pInSampleTex;
				SAFE_ADDREF(pGSTexture);
			}
			else
			{
				ID3D11Texture2D* pInSampleDXTex = pInSampleTex->GetTexture();
				ID3D11DeviceContext* pDeviceContext = pInSampleTex->GetDeviceContext();
				if (pInSampleDXTex == NULL || pDeviceContext == NULL)
					return E_FAIL;
				pDeviceContext->CopyResource(pTexture, pInSampleDXTex);
			}
			return S_OK;
		}
	}
	else if (IsEqualGUID(*pMediaType->Type(), MEDIATYPE_Video) )
	{
		if (IsEqualGUID(*pMediaType->Subtype(), MEDIASUBTYPE_RGB32))
		{
			BYTE* pSampleBuf = NULL;
			pSample->GetPointer(&pSampleBuf);
			
			ID3D11Texture2D* pTexture = pGSTexture->GetTexture();
			ID3D11DeviceContext* pDeviceContext = pGSTexture->GetDeviceContext();
			D3D11_MAPPED_SUBRESOURCE mappedResource = {0};
			if (pTexture == NULL || pDeviceContext == NULL)
				return E_FAIL;
			hr = pDeviceContext->Map(pTexture, 0, D3D11_MAP_READ, 0, &mappedResource);
			if (FAILED(hr))
			{
				return E_FAIL;
			}
			memcpy(mappedResource.pData, (void*)pSampleBuf, pSample->GetSize());
			pDeviceContext->Unmap(pTexture, 0);
			return S_OK;
		}
	}
	return E_FAIL;
}

HRESULT GSDXFilterBase::CopyGSTexture(GSTexture2D* pSrc, GSTexture2D* pDest)
{
	if (pSrc == NULL || pDest == NULL )
		return E_FAIL;
	
	CAutoLock lck1(pSrc->GetCritSec());
	CAutoLock lck2(pDest->GetCritSec());

	ID3D11Texture2D* pSrcTex = pSrc->GetTexture();
	ID3D11Texture2D* pDestTex = pSrc->GetTexture();
	
	if (pSrcTex == NULL || pDestTex == NULL)
		return E_FAIL;
	ID3D11DeviceContext* pDeviceContext = pDest->GetDeviceContext();
	if (pDeviceContext == NULL)
		return E_FAIL;

	pDeviceContext->CopyResource(pDestTex, pSrcTex);
	return S_OK;
}

HRESULT GSDXFilterBase::DoTransform(IMediaSample *pInSample, IMediaSample *pOutSample, const CMediaType* pInType, const CMediaType* pOutType)
{
	HRESULT hr = S_OK;
	if (m_pInTextureList.size() < 1 || m_pRenderTargetList.size() < 1 || m_pOutTextureList.size() < 1 || m_pD3DDisplay == NULL)
		return E_FAIL;
	hr = CopySample2GSTexture(m_pInTextureList[0], pInSample, pInType);

	if (FAILED(hr))
		return E_FAIL;
	{
		CAutoLock lck0(m_pD3DDisplay->GetCritSec());
		CAutoLock lck1(m_pInTextureList[0]->GetCritSec());
		CAutoLock lck2(m_pRenderTargetList[0]->GetCritSec());
		
		ID3D11RenderTargetView* pRTView = NULL;
		ID3D11DeviceContext* pDeviceContext = NULL;
		pDeviceContext = m_pD3DDisplay->GetDeviceContext();
		hr = m_pRenderTargetList[0]->GetRenderTargetView(pRTView);

		if (pRTView == NULL || pDeviceContext == NULL)
			return E_FAIL;

		hr = m_pD3DDisplay->SetRenderTarget(pDeviceContext, pRTView);
		hr = m_pD3DDisplay->Render();
		hr = m_pD3DDisplay->ResetRenderTarget(pDeviceContext);	
	}

	hr = CopyGSTexture2Sample(m_pRenderTargetList[0], pOutSample, pOutType );
	if (FAILED(hr))
	{
		hr = CopyGSTexture(m_pRenderTargetList[0], m_pOutTextureList[0]);
		if (FAILED(hr))
			return E_FAIL;
		hr = CopySample2GSTexture(m_pOutTextureList[0], pOutSample, pOutType);
		if (FAILED(hr))
			return E_FAIL;
	}
	return S_OK;
}
HRESULT GSDXFilterBase::CreateTextures(UINT bufW, UINT bufH, UINT nIn, UINT nRT, UINT nOut)
{
	if (m_pD3DDisplay == NULL)
		return E_FAIL;
	HRESULT hr = S_OK;
	ID3D11Device* pDevice = m_pD3DDisplay->GetD3DDevice();
	ID3D11DeviceContext* pDeviceContext = m_pD3DDisplay->GetDeviceContext();
	IDXGISwapChain* pSwapChain = m_pD3DDisplay->GetSwapChain();
	if (pDevice == NULL || pDeviceContext == NULL || pSwapChain == NULL)
		return E_FAIL;
	for (int i =0; i < nIn; i++)
	{
		GSTexture2D* pTex = new GSTexture2D(pDevice, pDeviceContext, pSwapChain);
		hr = pTex->Create(bufW, bufH, 1, D3D11_USAGE_DYNAMIC, DXGI_FORMAT_R8G8B8A8_UNORM, 
			D3D11_BIND_SHADER_RESOURCE, D3D11_CPU_ACCESS_WRITE, 0);
		if (FAILED(hr))
		{
			return E_FAIL;
		}
		m_pInTextureList.push_back(pTex);
	}

	for (int i =0; i < nOut; i++)
	{
		GSTexture2D* pTex = new GSTexture2D(pDevice, pDeviceContext, pSwapChain);
		hr = pTex->Create(bufW, bufH, 1, D3D11_USAGE_STAGING, DXGI_FORMAT_R8G8B8A8_UNORM, 
			0, D3D11_CPU_ACCESS_WRITE | D3D11_CPU_ACCESS_READ, 0);
		if (FAILED(hr))
		{
			return E_FAIL;
		}
		m_pOutTextureList.push_back(pTex);
	}

	for (int i =0; i < nOut; i++)
	{
		GSTexture2D* pTex = new GSTexture2D(pDevice, pDeviceContext, pSwapChain);
		hr = pTex->Create(bufW, bufH, 1, D3D11_USAGE_DEFAULT, DXGI_FORMAT_R8G8B8A8_UNORM, 
			D3D11_BIND_SHADER_RESOURCE | D3D11_BIND_RENDER_TARGET, D3D11_RESOURCE_MISC_SHARED);
		if (FAILED(hr))
		{
			return E_FAIL;
		}
		m_pRenderTargetList.push_back(pTex);
	}
	return S_OK;
}
GS3DDisplay* GSDXFilterBase::Create3DDisplay(UINT bufW, UINT bufH)
{
	return new GS3DDisplay(bufW, bufH);
}
GS3DDisplay* GSDXFilterBase::Create3DDisplay(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext, IDXGISwapChain* pSwapChain)
{
	return new GS3DDisplay(pDevice, pDeviceContext, pSwapChain);
}