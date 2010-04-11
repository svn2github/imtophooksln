#include "stdafx.h"
#include "GSMesh.h"
#include <DXUT.h>
#include <algorithm>

D3D11_INPUT_ELEMENT_DESC GSMeshBase::CUSTOMVERTEX::layout[] = {
	{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
	{ "NORMAL", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 },
	{ "TEXCOORD0", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 24, D3D11_INPUT_PER_VERTEX_DATA, 0 } };

//////////GSMeshBase//////////////
GSMeshBase::GSMeshBase()
{
	m_pDevice = NULL;
	m_pVertexBuffer = NULL;
	m_pIndexBuffer = NULL;
	
	for (int i =0; i < 4; i ++)
	{
		m_color[i] = 1.0;
	}
}
GSMeshBase::GSMeshBase(ID3D11Device* pDevice, ID3D11DeviceContext* pContext, IDXGISwapChain* pSwapChain) : GSDXBase(pDevice, pContext, pSwapChain)
{
	m_pVertexBuffer = NULL;
	m_pIndexBuffer = NULL;
	
	for (int i =0; i < 4; i ++)
	{
		m_color[i] = 1.0;
	}
}

GSMeshBase::~GSMeshBase()
{
	SAFE_RELEASE(m_pVertexBuffer);
	SAFE_RELEASE(m_pIndexBuffer);
	ClearVertexLayout();

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


HRESULT GSMeshBase::GetVertexLayout(ID3DBlob* pShaderBuffer, ID3D11InputLayout*& pLayout)
{
	if ( pShaderBuffer == NULL)
		return E_FAIL;
	if (m_pVertexLayout.find(pShaderBuffer) == m_pVertexLayout.end())
	{
		ID3D11InputLayout* pNewLayout = NULL;
		this->GenerateVertexLayout(pShaderBuffer, pNewLayout);
		if (pNewLayout == NULL)
		{
			return E_FAIL;
		}
		m_pVertexLayout[pShaderBuffer] = pNewLayout;
	}
	pLayout = m_pVertexLayout[pShaderBuffer];
	return S_OK;
}
HRESULT GSMeshBase::ClearVertexLayout()
{
	for (map<ID3DBlob*, ID3D11InputLayout*>::iterator iter = m_pVertexLayout.begin(); iter != m_pVertexLayout.end(); iter++)
	{
		SAFE_RELEASE(iter->second);
	}
	m_pVertexLayout.clear();
	return S_OK;
}

HRESULT GSMeshBase::GenerateVertexLayout(ID3DBlob* pShaderBuffer, ID3D11InputLayout*& pLayout)
{
	if (m_pDevice == NULL || pShaderBuffer == NULL)
		return E_FAIL;
	SAFE_RELEASE(pLayout);
	HRESULT hr = S_OK;	
	hr = m_pDevice->CreateInputLayout( (const D3D11_INPUT_ELEMENT_DESC*)CUSTOMVERTEX::layout, sizeof(CUSTOMVERTEX::layout)/sizeof(CUSTOMVERTEX), pShaderBuffer->GetBufferPointer(), 
		pShaderBuffer->GetBufferSize(), &pLayout);
	
	return hr;
}

D3D11_PRIMITIVE_TOPOLOGY GSMeshBase::GetPrimitiveTopology()
{
	return D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
}

GS3DPlane::GS3DPlane(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext, IDXGISwapChain* pSwapChain) : GSMeshBase(pDevice, pDeviceContext, pSwapChain)
{
	InitGeometry();
}

GS3DPlane::~GS3DPlane()
{

}

HRESULT GS3DPlane::InitGeometry()
{
	HRESULT hr;
	if (m_pDevice == NULL)
	{
		return E_FAIL;
	}
	SAFE_RELEASE(m_pVertexBuffer);
	SAFE_RELEASE(m_pIndexBuffer);
	
	CUSTOMVERTEX vertices[] = 
	{
		// {Position, Normal, tu, tv}
		{D3DXVECTOR3(-1, 1, 0), D3DXVECTOR3(0, 0, -1), 0.0, 0.0}, 
		{D3DXVECTOR3(-1,-1, 0), D3DXVECTOR3(0, 0, -1), 0.0, 1.0},
		{D3DXVECTOR3( 1,-1, 0), D3DXVECTOR3(0, 0, -1), 1.0, 1.0},
		{D3DXVECTOR3( 1, 1, 0), D3DXVECTOR3(0, 0, -1), 0.0, 1.0},
	};

	D3D11_BUFFER_DESC bd;
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof(vertices);
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd.CPUAccessFlags = 0;
	bd.MiscFlags = 0;
	D3D11_SUBRESOURCE_DATA InitData;
	InitData.pSysMem = vertices;
	
	hr = m_pDevice->CreateBuffer( &bd, &InitData, &m_pVertexBuffer);
	if( FAILED( hr ) )
		return hr;

	DWORD indices[] =
	{
		0,1,2,
		3,1,2
	};
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof( indices );
	bd.BindFlags = D3D11_BIND_INDEX_BUFFER;
	bd.CPUAccessFlags = 0;
	bd.MiscFlags = 0;
	InitData.pSysMem = indices;
	hr = m_pDevice->CreateBuffer( &bd, &InitData, &m_pIndexBuffer );
	if( FAILED( hr ) )
		return hr;
	
	return S_OK;

}
