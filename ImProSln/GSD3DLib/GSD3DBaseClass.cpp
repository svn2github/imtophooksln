#include "stdafx.h"
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

}
GSDXBase::GSDXBase(ID3D11Device* pDevice, ID3D11DeviceContext* pContext)
{
	m_pDevice = pDevice;
	if (m_pDevice != NULL)
		m_pDevice->AddRef();
	m_pDeviceContext = pContext;
	if (m_pDeviceContext != NULL)
		m_pDeviceContext->AddRef();

}
GSDXBase::~GSDXBase()
{
	SAFE_RELEASE(m_pDevice);
	SAFE_RELEASE(m_pDeviceContext);
}
ID3D11Device* GSDXBase::GetD3DDevice()
{
	return m_pDevice;
}
ID3D11DeviceContext* GSDXBase::GetDeviceContext()
{
	return m_pDeviceContext;
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
GSTextureBase::GSTextureBase()
{
	m_pTexture = NULL;
}
GSTextureBase::~GSTextureBase()
{
	SAFE_RELEASE(m_pTexture);
	
}
ID3D11Texture2D* GSTextureBase::GetTexture()
{
	return m_pTexture;
}
HRESULT GSTextureBase::SetTexture(ID3D11Texture2D* pTexture)
{
	SAFE_RELEASE(m_pTexture);
	m_pTexture = pTexture;
	if (pTexture != NULL)
	{
		pTexture->AddRef();
	}
	return S_OK;
}


HRESULT GSRenderBase::RenderMesh(IGSMeshBase* pMesh, IGSEffectBase* pEffect, ID3D11DeviceContext* pDeviceContext)
{
	if (pMesh == NULL || pEffect == NULL || pDeviceContext == NULL )
	{
		return E_FAIL;
	}
	
	ID3D11Buffer* pVertexBuffer = pMesh->GetVertexBuffer();
	ID3D11Buffer* pIndexBuffer = pMesh->GetIndexBuffer();

	if (pVertexBuffer == NULL || pIndexBuffer == NULL)
		return E_FAIL;

	ID3D11PixelShader* pPSShader = pEffect->GetPSShader();
	ID3D11VertexShader* pVSShader = pEffect->GetVSShader();
	
	if (pPSShader == NULL || pVSShader == NULL)
	{
		return E_FAIL;
	}

	D3D11_BUFFER_DESC indexDesc;
	pIndexBuffer->GetDesc(&indexDesc);
	UINT indexCount = indexDesc.ByteWidth / sizeof(UINT);
	HRESULT hr = S_OK;
	UINT stride = pMesh->GetVertexStride();
	UINT offset = 0;
	ID3D11InputLayout* pLayout = NULL;
	pMesh->GetVertexLayout(pEffect, pLayout);

	pDeviceContext->VSSetShader( pVSShader, NULL, 0 );
	pDeviceContext->PSSetShader( pPSShader, NULL, 0 );

	pDeviceContext->IASetInputLayout(pLayout);
	pDeviceContext->IASetPrimitiveTopology(pMesh->GetPrimitiveTopology());
	pDeviceContext->IASetVertexBuffers( 0, 1, &pVertexBuffer, &stride, &offset );
	pDeviceContext->IASetIndexBuffer(pIndexBuffer, DXGI_FORMAT_R32_UINT, 0);
	pDeviceContext->DrawIndexed( indexCount, 0, 0);
	return S_OK;
}
