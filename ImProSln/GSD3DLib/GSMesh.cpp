#include "stdafx.h"
#include "GSMesh.h"
#include <DXUT.h>

D3D10_INPUT_ELEMENT_DESC GSMeshBase::CUSTOMVERTEX::layout[] = {
	{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D10_INPUT_PER_VERTEX_DATA, 0 },
	{ "NORMAL", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 12, D3D10_INPUT_PER_VERTEX_DATA, 0 },
	{ "TEXCOORD0", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 24, D3D10_INPUT_PER_VERTEX_DATA, 0 } };

//////////GSMeshBase//////////////
GSMeshBase::GSMeshBase()
{
	m_pDevice = NULL;
	m_pVertexBuffer = NULL;
	m_pIndexBuffer = NULL;
	m_pVertexLayout = NULL;
	for (int i =0; i < 4; i ++)
	{
		m_color[i] = 1.0;
	}
}
GSMeshBase::GSMeshBase(ID3D11Device* pDevice, ID3D11DeviceContext* pContext) : GSDXBase(pDevice, pContext)
{
	m_pVertexBuffer = NULL;
	m_pIndexBuffer = NULL;
	m_pVertexLayout = NULL;
	for (int i =0; i < 4; i ++)
	{
		m_color[i] = 1.0;
	}
}

GSMeshBase::~GSMeshBase()
{
	SAFE_RELEASE(m_pVertexBuffer);
	SAFE_RELEASE(m_pIndexBuffer);
	SAFE_RELEASE(m_pVertexLayout);
}


ID3D11Buffer* GSMeshBase::GetVertexBuffer()
{
	return m_pVertexBuffer;
}
ID3D11Buffer* GSMeshBase::GetIndexBuffer()
{
	return m_pIndexBuffer;
}
UINT GSMeshBase::GetVertexNumber()
{	
	if (m_pVertexBuffer == NULL)
	{
		return 0;
	}
	D3D11_BUFFER_DESC desc;
	m_pVertexBuffer->GetDesc(&desc);
	return desc.ByteWidth / sizeof(CUSTOMVERTEX);
}

UINT GSMeshBase::GetVertexStride()
{
	return sizeof(CUSTOMVERTEX);
}


/*
HRESULT GSMeshBase::Render()
{
	
	if (m_pDeviceContext == NULL || m_pVertexBuffer == NULL || m_pIndexBuffer == NULL)
		return E_FAIL;
	D3D11_BUFFER_DESC indexDesc;
	m_pIndexBuffer->GetDesc(&indexDesc);
	UINT indexCount = indexDesc.ByteWidth / sizeof(UINT);
	HRESULT hr = S_OK;
	UINT stride = sizeof(CUSTOMVERTEX);
	UINT offset = 0;

	//hr = m_pDeviceContext->IASetInputLayout(CUSTOMVERTEX::layout);
	m_pDeviceContext->IASetPrimitiveTopology(GetPrimitiveTopology());
	m_pDeviceContext->IASetVertexBuffers( 0, 1, &m_pVertexBuffer, &stride, &offset );
	m_pDeviceContext->IASetIndexBuffer(m_pIndexBuffer, DXGI_FORMAT_R32_UINT, 0);
	m_pDeviceContext->DrawIndexed( indexCount, 0, 0);
	
	return S_OK;
}
*/
HRESULT GSMeshBase::GetVertex(UINT idx, void* pVertex)
{
	ID3D11Buffer* pVertexBuffer = GetVertexBuffer();
	if (pVertexBuffer == NULL || m_pDeviceContext == NULL || pVertex == NULL)
		return E_FAIL;
	if (idx >= this->GetVertexNumber())
		return E_FAIL;

	CUSTOMVERTEX* pData = NULL;
	D3D11_MAPPED_SUBRESOURCE* pSubResource = NULL;
	m_pDeviceContext->Map(pVertexBuffer, 0, D3D11_MAP_READ, D3D11_MAP_FLAG_DO_NOT_WAIT, pSubResource);
	pData = (CUSTOMVERTEX*)pSubResource->pData;
	
	*(CUSTOMVERTEX*)pVertex = pData[idx];
	m_pDeviceContext->Unmap(pVertexBuffer, 0);
	return S_OK;
}

HRESULT GSMeshBase::SetVertex(UINT idx, void* pVertex)
{
	ID3D11Buffer* pVertexBuffer = GetVertexBuffer();
	if (pVertexBuffer == NULL || m_pDeviceContext == NULL || pVertex == NULL)
		return E_FAIL;
	if (idx >= this->GetVertexNumber())
		return E_FAIL;
	D3D11_MAPPED_SUBRESOURCE* pSubResource = NULL;
	m_pDeviceContext->Map(pVertexBuffer, 0, D3D11_MAP_WRITE, D3D11_MAP_FLAG_DO_NOT_WAIT, pSubResource);

	CUSTOMVERTEX* pData = NULL;
	pData = (CUSTOMVERTEX*)pSubResource->pData;
	pData[idx] = *(CUSTOMVERTEX*)pVertex;
	m_pDeviceContext->Unmap(pVertexBuffer, 0);
	return S_OK;
}

HRESULT GSMeshBase::GetVertexLayout(ID3D11InputLayout*& pLayout)
{
	SAFE_RELEASE(pLayout);

	if (m_pVertexLayout == NULL)
	{
		if (m_pDevice == NULL)
			return E_FAIL;

		//hr = m_pDevice->CreateInputLayout( CUSTOMVERTEX::layout, sizeof(CUSTOMVERTEX::layout)/sizeof(CUSTOMVERTEX), PassDesc.pIAInputSignature,
		//	PassDesc.IAInputSignatureSize, &g_pVertexLayout );
	}

	return S_OK;
}

GS3DPlane::GS3DPlane(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext) : GSMeshBase(pDevice, pDeviceContext)
{
	InitGeometry();
}
GS3DPlane::~GS3DPlane()
{

}
HRESULT GS3DPlane::InitGeometry()
{
	HRESULT hr;
	/*if (m_pMesh != NULL)
	{
		m_pMesh->Release();
		m_pMesh = NULL;
	}
	hr = D3DXCreateMeshFVF(4,4, D3DXMESH_32BIT | D3DXMESH_VB_MANAGED | D3DXMESH_IB_MANAGED, 
		D3DFVF_XYZ|D3DFVF_NORMAL|D3DFVF_TEX1, m_pDevice, &m_pMesh);
	if (FAILED(hr))
	{
		OutputDebugStringW(L"@@@@ InitGeometry D3DXCreateMeshFVF Failed in GS3DPlane!!\n");
		return FALSE;
	}
	IDirect3DVertexBuffer9* pVertexBuffer = NULL;
	m_pMesh->GetVertexBuffer(&pVertexBuffer);
	CUSTOMVERTEX* pVertices = NULL;

	if( FAILED( pVertexBuffer->Lock( 0, 0, (void**)&pVertices, 0 ) ) )
		return FALSE;
	pVertices[0].position = D3DXVECTOR3(-1, 1, 0);
	pVertices[1].position = D3DXVECTOR3(-1, -1, 0);
	pVertices[2].position = D3DXVECTOR3(1, -1, 0);
	pVertices[3].position = D3DXVECTOR3(1, 1, 0);


	pVertices[0].normal = D3DXVECTOR3(0, 0, -1);
	pVertices[1].normal = D3DXVECTOR3(0, 0, -1);
	pVertices[2].normal = D3DXVECTOR3(0, 0, -1);
	pVertices[3].normal = D3DXVECTOR3(0, 0, -1);


	pVertices[0].tu = 0;	pVertices[0].tv = 0;
	pVertices[1].tu = 0;    pVertices[1].tv = 1;
	pVertices[2].tu = 1;	pVertices[2].tv = 1;
	pVertices[3].tu = 1;    pVertices[3].tv = 0;

	pVertexBuffer->Unlock();

	IDirect3DIndexBuffer9* pIndexBuffer = NULL;
	m_pMesh->GetIndexBuffer(&pIndexBuffer);

	UINT* pIndex = NULL;
	if (FAILED(pIndexBuffer->Lock(0, 0, (void**)&pIndex, 0)))
		return FALSE;

	pIndex[0] = 0;	pIndex[1] = 1;  pIndex[2] = 3;
	pIndex[3] = 3;  pIndex[4] = 1;  pIndex[5] = 2;

	pIndexBuffer->Unlock();*/
	return S_OK;

}

HRESULT GS3DPlane::Render()
{
	HRESULT hr;
	
	return S_OK;
}
