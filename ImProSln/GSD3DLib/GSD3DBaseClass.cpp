#include "stdafx.h"
#include "GSMacro.h"
#include "GSD3DBaseClass.h"
#include <DXUT.h>
#include <math.h>
#include <algorithm>

GSRefCount::GSRefCount()
{
	m_nRef = 1;
}
GSRefCount::~GSRefCount()
{
}
ULONG GSRefCount::AddRef()
{
	return ++m_nRef;
}

ULONG GSRefCount::Release()
{
	if (--m_nRef > 0)
	{
		return m_nRef;
	}
	else
	{
		delete this;
	}
	return 0;
}

GSDXBase::GSDXBase()
{
	m_pDevice = NULL;
	m_pDeviceContext = NULL;
	m_pSwapChain = NULL;
}
GSDXBase::GSDXBase(ID3D11Device* pDevice, ID3D11DeviceContext* pContext, IDXGISwapChain* pSwapChain)
{
	m_pDevice = pDevice;
	m_pDeviceContext = pContext;
	m_pSwapChain = pSwapChain;

	SAFE_ADDREF(m_pDevice);
	SAFE_ADDREF(m_pDeviceContext);
	SAFE_ADDREF(m_pSwapChain);
}
GSDXBase::~GSDXBase()
{
	SAFE_RELEASE(m_pDevice);
	SAFE_RELEASE(m_pDeviceContext);
	SAFE_RELEASE(m_pSwapChain);
}
ID3D11Device* GSDXBase::GetD3DDevice()
{
	return m_pDevice;
}
ID3D11DeviceContext* GSDXBase::GetDeviceContext()
{
	return m_pDeviceContext;
}
IDXGISwapChain* GSDXBase::GetSwapChain()
{
	return m_pSwapChain;
}
HRESULT GSDXBase::CreateD3DDevice(HWND hwnd, UINT bufW, UINT bufH)
{
	SAFE_RELEASE(m_pDevice);
	SAFE_RELEASE(m_pDeviceContext);
	SAFE_RELEASE(m_pSwapChain);

	if (hwnd == NULL || bufW <= 0 || bufH <= 0)
		return E_FAIL;

	HRESULT hr = S_OK;
	DXGI_SWAP_CHAIN_DESC sd;
	ZeroMemory( &sd, sizeof( sd ) );
	sd.BufferCount = 1;
	sd.BufferDesc.Width = bufW;
	sd.BufferDesc.Height = bufH;
	sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	sd.BufferDesc.RefreshRate.Numerator = 60;
	sd.BufferDesc.RefreshRate.Denominator = 1;
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	sd.OutputWindow = hwnd;
	sd.SampleDesc.Count = 1;
	sd.SampleDesc.Quality = 0;
	sd.Windowed = TRUE;

	D3D_FEATURE_LEVEL  FeatureLevelsRequested[] = 
	{
		D3D_FEATURE_LEVEL_11_0,
		D3D_FEATURE_LEVEL_10_1,
		D3D_FEATURE_LEVEL_10_0,
		D3D_FEATURE_LEVEL_9_3,
		D3D_FEATURE_LEVEL_9_2,
		D3D_FEATURE_LEVEL_9_1,
	};
	UINT               numLevelsRequested = 6;
	D3D_FEATURE_LEVEL  FeatureLevelsSupported;
	UINT createDeviceFlags = 0;

#ifdef _DEBUG
	createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

	if( FAILED (hr = D3D11CreateDeviceAndSwapChain( NULL, 
		D3D_DRIVER_TYPE_HARDWARE, 
		NULL, 
		createDeviceFlags,
		FeatureLevelsRequested, 
		numLevelsRequested, 
		D3D11_SDK_VERSION, 
		&sd, 
		&m_pSwapChain, 
		&m_pDevice, 
		&FeatureLevelsSupported,
		&m_pDeviceContext )))
	{
		return hr;
	}
	ID3D11RenderTargetView* pRTView = NULL;
	ID3D11DepthStencilView* pDSView = NULL;
	initRenderTargetState(pRTView);
	initDepthStencilState(pDSView);
	initViewPort();
	m_pDeviceContext->OMSetRenderTargets(1, &pRTView, pDSView);
	SAFE_RELEASE(pRTView);
	SAFE_RELEASE(pDSView);
	return S_OK;
}
HRESULT GSDXBase::initViewPort()
{
	if (m_pDevice == NULL || m_pSwapChain == NULL || m_pDeviceContext == NULL)
		return E_FAIL;
	HRESULT hr = S_OK;
	ID3D11Texture2D* pBuffer = NULL;
	hr = m_pSwapChain->GetBuffer( 0, __uuidof( ID3D11Texture2D ), ( LPVOID* )&pBuffer );
	if( FAILED( hr ) )
		return hr;
	D3D11_TEXTURE2D_DESC desc;
	pBuffer->GetDesc(&desc);

	D3D11_VIEWPORT vp;
	vp.Width = desc.Width;
	vp.Height = desc.Height;
	vp.MinDepth = 0.0f;
	vp.MaxDepth = 1.0f;
	vp.TopLeftX = 0;
	vp.TopLeftY = 0;
	m_pDeviceContext->RSSetViewports( 1, &vp );

	SAFE_RELEASE(pBuffer);
	return S_OK;
}
HRESULT GSDXBase::initRenderTargetState(ID3D11RenderTargetView*& pOutRTView)
{
	if (m_pDevice == NULL || m_pSwapChain == NULL || m_pDeviceContext == NULL)
		return E_FAIL;
	HRESULT hr = S_OK;
	ID3D11Texture2D* pBuffer = NULL;
	hr = m_pSwapChain->GetBuffer( 0, __uuidof( ID3D11Texture2D ), ( LPVOID* )&pBuffer );
	if( FAILED( hr ) )
		return hr;
	ID3D11RenderTargetView* pRTView = NULL;
	hr = m_pDevice->CreateRenderTargetView( pBuffer, NULL, &pRTView );

	SAFE_RELEASE(pBuffer);
	if( FAILED( hr ) )
		return hr;
	pOutRTView = pRTView; 
	return S_OK;
}
HRESULT GSDXBase::initDepthStencilState(ID3D11DepthStencilView*& pDSView)
{
	if (m_pDevice == NULL || m_pSwapChain == NULL || m_pDeviceContext == NULL)
		return E_FAIL;
	HRESULT hr = S_OK;
	ID3D11Texture2D* pBuffer = NULL;
	hr = m_pSwapChain->GetBuffer( 0, __uuidof( ID3D11Texture2D ), ( LPVOID* )&pBuffer );
	if( FAILED( hr ) )
		return hr;
	D3D11_TEXTURE2D_DESC desc;
	pBuffer->GetDesc(&desc);
	SAFE_RELEASE(pBuffer);

	ID3D11Texture2D* pDepthStencil = NULL;
	D3D11_TEXTURE2D_DESC descDepth;
	descDepth.Width = desc.Width;
	descDepth.Height = desc.Height;
	descDepth.MipLevels = 1;
	descDepth.ArraySize = 1;
	descDepth.Format = DXGI_FORMAT_D32_FLOAT;
	descDepth.SampleDesc.Count = 1;
	descDepth.SampleDesc.Quality = 0;
	descDepth.Usage = D3D11_USAGE_DEFAULT;
	descDepth.BindFlags = D3D11_BIND_DEPTH_STENCIL;
	descDepth.CPUAccessFlags = 0;
	descDepth.MiscFlags = 0;
	hr = m_pDevice->CreateTexture2D( &descDepth, NULL, &pDepthStencil );
	if (FAILED(hr))
		return E_FAIL;
	
	D3D11_DEPTH_STENCIL_DESC dsDesc;
	// Depth test parameters
	dsDesc.DepthEnable = true;
	dsDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
	dsDesc.DepthFunc = D3D11_COMPARISON_LESS;

	// Stencil test parameters
	dsDesc.StencilEnable = true;
	dsDesc.StencilReadMask = 0xFF;
	dsDesc.StencilWriteMask = 0xFF;

	// Stencil operations if pixel is front-facing
	dsDesc.FrontFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
	dsDesc.FrontFace.StencilDepthFailOp = D3D11_STENCIL_OP_INCR;
	dsDesc.FrontFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
	dsDesc.FrontFace.StencilFunc = D3D11_COMPARISON_ALWAYS;

	// Stencil operations if pixel is back-facing
	dsDesc.BackFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
	dsDesc.BackFace.StencilDepthFailOp = D3D11_STENCIL_OP_DECR;
	dsDesc.BackFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
	dsDesc.BackFace.StencilFunc = D3D11_COMPARISON_ALWAYS;

	// Create depth stencil state
	ID3D11DepthStencilState * pDSState = NULL;
	hr = m_pDevice->CreateDepthStencilState(&dsDesc, &pDSState);
	if (FAILED(hr))
		return E_FAIL;
	// Bind depth stencil state
	m_pDeviceContext->OMSetDepthStencilState(pDSState, 1);
	SAFE_RELEASE(pDSState);

	/*D3D11_DEPTH_STENCIL_VIEW_DESC descDSV;
	descDSV.Format = DXGI_FORMAT_D32_FLOAT;
	descDSV.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
	descDSV.Texture2D.MipSlice = 0;
	*/
	// Create the depth stencil view
	ID3D11DepthStencilView* pDSV = NULL;
	hr = m_pDevice->CreateDepthStencilView( pDepthStencil, // Depth stencil texture
		NULL, // Depth stencil desc
		&pDSV );  // [out] Depth stencil view
	if (FAILED(hr))
		return E_FAIL;
   
	SAFE_RELEASE(pDepthStencil);
	pDSView = pDSV;
	return S_OK;
}
GS3DObj::GS3DObj()
{
	D3DXCreateMatrixStack(0, &m_pMatrixStack);
	m_pMatrixStack->LoadIdentity();
}
GS3DObj::~GS3DObj()
{
	if (m_pMatrixStack != NULL)
	{
		m_pMatrixStack->Release();
		m_pMatrixStack = NULL;
	}
}
D3DXMATRIX GS3DObj::GetTransform()
{
	return *m_pMatrixStack->GetTop();
}

HRESULT GS3DObj::SetTransform(const D3DXMATRIX* mat)
{
	return m_pMatrixStack->LoadMatrix(mat);
}


HRESULT GS3DObj::Translate(D3DXVECTOR3& t)
{
	m_pMatrixStack->Translate(t.x, t.y, t.z);
	return S_OK;
}
HRESULT GS3DObj::RotateAxis(CONST D3DXVECTOR3 * pV, FLOAT angle)
{
	m_pMatrixStack->RotateAxis(pV, angle);
	return S_OK;
}
HRESULT GS3DObj::Scale(D3DXVECTOR3& s)
{
	m_pMatrixStack->Scale(s.x, s.y, s.z);
	return S_OK;
}
HRESULT GS3DObj::ResetTransform()
{
	m_pMatrixStack->LoadIdentity();
	return S_OK;
}
HRESULT GS3DObj::PushMatrix()
{
	m_pMatrixStack->Push();
	return S_OK;
}
HRESULT GS3DObj::PopMatrix()
{
	m_pMatrixStack->Pop();
	return S_OK;
}
HRESULT GS3DObj::SetPosition(D3DXVECTOR3 pos)
{
	D3DXMATRIX mat = GetTransform();
	mat.m[3][0] = pos.x;
	mat.m[3][1] = pos.y;
	mat.m[3][2] = pos.z;
	m_pMatrixStack->LoadMatrix(&mat);

	return S_OK;
}

D3DXVECTOR3 GS3DObj::GetPosition()
{
	D3DXMATRIX mat = GetTransform();
	D3DXVECTOR3 ret(0,0,0);
	ret.x = mat.m[3][0];
	ret.y = mat.m[3][1];
	ret.z = mat.m[3][2];
	return ret;
}
//////////Texture Base////////////
GSTexture2D::GSTexture2D(ID3D11Device* pDevice, ID3D11DeviceContext* pContext, IDXGISwapChain* pSwapChain) : GSDXBase(pDevice, pContext, pSwapChain)
{
	m_pTexture = NULL;
	m_pRenderTargetView = NULL;
	m_pShaderResourceView = NULL;
}
GSTexture2D::~GSTexture2D()
{
	SAFE_RELEASE(m_pTexture);
	SAFE_RELEASE(m_pRenderTargetView);
	SAFE_RELEASE(m_pShaderResourceView);
}
ID3D11Texture2D* GSTexture2D::GetTexture()
{
	return m_pTexture;
}
HRESULT GSTexture2D::SetTexture(ID3D11Texture2D* pTexture)
{
	SAFE_RELEASE(m_pTexture);
	m_pTexture = pTexture;
	SAFE_ADDREF(pTexture);
	return S_OK;
}
HRESULT GSTexture2D::Create(UINT texW, UINT texH, UINT MipLevels, D3D11_USAGE Usage, 
					   DXGI_FORMAT format, UINT BindFlags, UINT CPUAccessFlags , UINT MiscFlags)

{
	if (m_pDevice == NULL)
		return E_FAIL;
	SAFE_RELEASE(m_pTexture);
	HRESULT hr = S_OK;
	CD3D11_TEXTURE2D_DESC desc;
	desc.Width = texW;
	desc.Height = texH;
	desc.MipLevels = desc.ArraySize = MipLevels;
	desc.Format = format;
	desc.SampleDesc.Count = 1;
	desc.SampleDesc.Quality = 0;
	desc.Usage = Usage;
	desc.BindFlags = BindFlags;
	desc.CPUAccessFlags = CPUAccessFlags;
	desc.MiscFlags = MiscFlags;

	ID3D11Texture2D *pTexture = NULL;
	hr = m_pDevice->CreateTexture2D( &desc, NULL, &m_pTexture );
	return hr;
}
HRESULT GSTexture2D::CreateRenderTargetView()
{
	if (m_pDevice == NULL || m_pTexture == NULL)
	{
		return E_FAIL;
	}
	SAFE_RELEASE(m_pRenderTargetView);
	HRESULT hr = S_OK;
	hr = m_pDevice->CreateRenderTargetView(m_pTexture, NULL, &m_pRenderTargetView );
	return hr;
}
HRESULT GSTexture2D::CreateShaderResourceView()
{
	if (m_pDevice == NULL || m_pTexture == NULL)
	{
		return E_FAIL;
	}
	SAFE_RELEASE(m_pShaderResourceView);
	HRESULT hr = S_OK;
	hr = m_pDevice->CreateShaderResourceView(m_pTexture, NULL, &m_pShaderResourceView );
	return hr;
}
HRESULT GSTexture2D::GetRenderTargetView(ID3D11RenderTargetView*& pRenderTargetView)
{
	if (m_pTexture == NULL)
		return E_FAIL;
	SAFE_RELEASE(pRenderTargetView);
	if (m_pRenderTargetView == NULL)
	{
		if (FAILED(CreateRenderTargetView()))
		{
			return E_FAIL;
		}
	}
	pRenderTargetView = m_pRenderTargetView;
	return S_OK;

}
HRESULT GSTexture2D::GetShaderResourceView(ID3D11ShaderResourceView*& pShaderResourceView)
{
	if (m_pTexture == NULL)
		return E_FAIL;
	SAFE_RELEASE(pShaderResourceView);
	if (m_pShaderResourceView == NULL)
	{
		if (FAILED(CreateShaderResourceView()))
		{
			return E_FAIL;
		}
	}
	pShaderResourceView = m_pShaderResourceView;
	return S_OK;
}


GSRenderBase::GSRenderBase()
{
	m_pCBEffectSetting = NULL;
	m_pCBParam = NULL;
}
GSRenderBase::~GSRenderBase()
{
	for (int i =0; i < m_pBackupRenderTarget.size(); i++)
	{
		SAFE_RELEASE(m_pBackupRenderTarget.at(i));
	}
	m_pBackupRenderTarget.clear();
	m_pCBEffectSetting = NULL;
	m_pCBParam = NULL;
}
HRESULT GSRenderBase::RenderMesh(IGSMeshBase* pMesh, ID3D11DeviceContext* pDeviceContext, IGSEffectBase* pGSEffect, UINT idxTech)
{
	if (pMesh == NULL || pGSEffect == NULL || pDeviceContext == NULL || m_pCBEffectSetting == NULL)
	{
		return E_FAIL;
	}
	HRESULT hr = S_OK;
	float ClearColor[4] = { 0.25f, 0.25f, 0.25f, 0.55f };
	ID3D11RenderTargetView* pRTView = NULL;
	ID3D11DepthStencilView* pDSView = NULL;
	pDeviceContext->OMGetRenderTargets(1, &pRTView, &pDSView);
	pDeviceContext->ClearRenderTargetView( pRTView, ClearColor );
	pDeviceContext->ClearDepthStencilView( pDSView, D3D11_CLEAR_DEPTH, 1.0, 0 );
	SAFE_RELEASE(pRTView);
	SAFE_RELEASE(pDSView);
	ID3D11Buffer* pVertexBuffer = pMesh->GetVertexBuffer();
	ID3D11Buffer* pIndexBuffer = pMesh->GetIndexBuffer();

	if (pVertexBuffer == NULL || pIndexBuffer == NULL)
		return E_FAIL;

	ID3DX11Effect* pEffect = pGSEffect->GetEffect();
	if (pEffect == NULL)
	{
		return E_FAIL;
	}
	D3DX11_TECHNIQUE_DESC tDesc;
	ID3DX11EffectPass* pPass = NULL;
	ID3DX11EffectTechnique* pTechnique = pEffect->GetTechniqueByIndex(0);
	if (pTechnique == NULL)
		return E_FAIL;
	pTechnique->GetDesc(&tDesc);

	D3D11_BUFFER_DESC indexDesc;
	
	pIndexBuffer->GetDesc(&indexDesc);
	UINT indexCount = indexDesc.ByteWidth / sizeof(UINT);

	UINT stride = pMesh->GetVertexStride();
	UINT offset = 0;
	ID3D11InputLayout* pLayout = NULL;
	pMesh->GetVertexLayout(pEffect, pLayout);

	pDeviceContext->IASetInputLayout(pLayout);
	pDeviceContext->IASetPrimitiveTopology(pMesh->GetPrimitiveTopology());
	pDeviceContext->IASetVertexBuffers( 0, 1, &pVertexBuffer, &stride, &offset );
	pDeviceContext->IASetIndexBuffer(pIndexBuffer, DXGI_FORMAT_R32_UINT, 0);

	m_pCBEffectSetting(pEffect, m_pCBParam);

	for (int iPass = 0; iPass < tDesc.Passes; iPass++)
	{
		pPass = pTechnique->GetPassByIndex(iPass);
		pPass->Apply(0, pDeviceContext);
		pDeviceContext->DrawIndexed( indexCount, 0, 0);
	}
	
	return S_OK;
}

HRESULT GSRenderBase::SetRenderTarget(ID3D11DeviceContext* pDeviceContext, ID3D11RenderTargetView* pRenderTarget)
{
	if (pDeviceContext == NULL || pRenderTarget == NULL)
		return E_FAIL;
	HRESULT hr = S_OK;
	ID3D11RenderTargetView* pBackup = NULL;
	pDeviceContext->OMGetRenderTargets(1, &pBackup, NULL);
	
	m_pBackupRenderTarget.push_back(pBackup);
	SAFE_ADDREF(pBackup);
	pDeviceContext->OMSetRenderTargets(1, &pRenderTarget, NULL);
	
	SAFE_RELEASE(pBackup);
	return S_OK;
}
HRESULT GSRenderBase::ResetRenderTarget(ID3D11DeviceContext* pDeviceContext)
{
	if (pDeviceContext == NULL)
		return E_FAIL;
	if (m_pBackupRenderTarget.size() <= 0)
		return E_FAIL;

	ID3D11RenderTargetView* pBackupRenderTarget = m_pBackupRenderTarget[ m_pBackupRenderTarget.size()-1];
	m_pBackupRenderTarget.pop_back();
	
	pDeviceContext->OMSetRenderTargets(1, &pBackupRenderTarget, NULL);
	SAFE_RELEASE(pBackupRenderTarget);
	return S_OK;
}

HRESULT GSRenderBase::SetCBEffectSetting(CBEffectSetting pfunc, void* self)
{
	m_pCBEffectSetting = pfunc;
	m_pCBParam = self;
	return S_OK;
}
HRESULT GSRenderBase::ClearCBEffectSetting()
{
	m_pCBEffectSetting = NULL;
	m_pCBParam = NULL;
	return S_OK;
}