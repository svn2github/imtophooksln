#include "MSSD3DClass.h"

MS3DObj::MS3DObj()
{
	D3DXMatrixIdentity(&m_matWorld);
}
MS3DObj::~MS3DObj()
{

}
D3DXMATRIX MS3DObj::GetTransform()
{
	return m_matWorld;
}
BOOL MS3DObj::Translate(D3DXVECTOR3& t)
{
	D3DXMATRIX matT;
	D3DXMatrixTranslation(&matT, t.x, t.y, t.z);
	D3DXMatrixMultiply(&m_matWorld, &m_matWorld, &matT);
	return TRUE;
}
BOOL MS3DObj::Rotate(D3DXVECTOR3& rot)
{
	D3DXMATRIXA16 matR;
	D3DXMatrixRotationX(&matR, rot.x);
	D3DXMatrixMultiply(&m_matWorld, &m_matWorld, &matR);
	D3DXMatrixRotationX(&matR, rot.y);
	D3DXMatrixMultiply(&m_matWorld, &m_matWorld, &matR);
	D3DXMatrixRotationX(&matR, rot.z);
	D3DXMatrixMultiply(&m_matWorld, &m_matWorld, &matR);
	return TRUE;
}
BOOL MS3DObj::Scale(D3DXVECTOR3& s)
{
	D3DXMATRIXA16 matS;
	D3DXMatrixScaling(&matS, s.x, s.y, s.z);
	D3DXMatrixMultiply(&m_matWorld, &m_matWorld, &matS);
	return TRUE;
}
BOOL MS3DObj::ResetTransform()
{
	D3DXMatrixIdentity(&m_matWorld);
	while (!m_matStack.empty())
	{
		m_matStack.pop();
	}
	return TRUE;
}
BOOL MS3DObj::PushMatrix()
{
	m_matStack.push(m_matWorld);
	return TRUE;
}
BOOL MS3DObj::PopMatrix()
{
	if (m_matStack.size() <= 0)
		return FALSE;
	m_matWorld = m_matStack.top();
	return TRUE;
}

//////////MS3DPlane//////////////

MS3DPlane::MS3DPlane(IDirect3DDevice9* pDevice)
{
	m_pDevice = pDevice;
	m_pDevice->AddRef();
	m_pVertices = NULL;
	m_pIndices = NULL;
	m_vertexFMT = D3DFVF_XYZ|D3DFVF_NORMAL|D3DFVF_TEX1;
	m_indexFMT = D3DFMT_INDEX16;
}

MS3DPlane::~MS3DPlane()
{
	ReleaseResource();
}
void MS3DPlane::ReleaseResource()
{
	if (m_pVertices != NULL)
	{
		m_pVertices->Release();
		m_pVertices = NULL;
	}
	if (m_pIndices != NULL)
	{
		m_pIndices ->Release();
		m_pIndices = NULL;
	}
	if (m_pDevice != NULL)
	{
		m_pDevice->Release();
		m_pDevice = NULL;
	}
}
BOOL MS3DPlane::InitGeometry()
{
	HRESULT hr;
	if (m_pVertices != NULL)
	{
		m_pVertices->Release();
		m_pVertices = NULL;
	}
	if (m_pIndices != NULL)
	{
		m_pIndices ->Release();
		m_pIndices = NULL;
	}

	hr = m_pDevice->CreateVertexBuffer(sizeof(MS3DPlane::CUSTOMVERTEX)*4, 0, m_vertexFMT,
		D3DPOOL_MANAGED, &m_pVertices, NULL);
	if (FAILED(hr))
	{
		OutputDebugStringW(L"@@@@ InitGeometry CreateVertexBuffer Failed in MS3DPlane!!\n");
		return FALSE;
	}
	CUSTOMVERTEX* pVertices = NULL;

	if( FAILED( m_pVertices->Lock( 0, 0, (void**)&pVertices, 0 ) ) )
		return FALSE;
	pVertices[0].position = D3DXVECTOR3(-0.5, 0.5, 0);
	pVertices[1].position = D3DXVECTOR3(-0.5, -0.5, 0);
	pVertices[2].position = D3DXVECTOR3(0.5, -0.5, 0);
	pVertices[3].position = D3DXVECTOR3(0.5, 0.5, 0);

	pVertices[0].normal = D3DXVECTOR3(0, 0, 1);
	pVertices[1].normal = D3DXVECTOR3(0, 0, 1);
	pVertices[2].normal = D3DXVECTOR3(0, 0, 1);
	pVertices[3].normal = D3DXVECTOR3(0, 0, 1);

	pVertices[0].tu = 0;	pVertices[0].tv = 0;
	pVertices[1].tu = 0;    pVertices[1].tv = 1;
	pVertices[2].tu = 1;	pVertices[2].tv = 1;
	pVertices[3].tu = 1;    pVertices[3].tv = 0;
	m_pVertices->Unlock();

	hr = m_pDevice->CreateIndexBuffer( sizeof(unsigned short)*6, 0, m_indexFMT, D3DPOOL_MANAGED, &m_pIndices, NULL);
	if (FAILED(hr))
	{
		OutputDebugStringW(L"@@@@ InitGeometry CreateIndexBuffer Failed in MS3DPlane!!\n");
		return FALSE;
	}

	unsigned short* pIndex = NULL;
	if (FAILED(m_pIndices->Lock(0, 0, (void**)&pIndex, 0)))
		return FALSE;
	
	pIndex[0] = 0;	pIndex[1] = 1;  pIndex[2] = 3;
	pIndex[3] = 3;  pIndex[4] = 1;  pIndex[5] = 2;

	m_pIndices->Unlock();
	return TRUE;

}

IDirect3DVertexBuffer9* MS3DPlane::GetVertexBuffer()
{
	return m_pVertices;
}
IDirect3DIndexBuffer9* MS3DPlane::GetIndexBuffer()
{
	return m_pIndices;
}
UINT MS3DPlane::GetVertexNumber()
{	
	if (m_pVertices == NULL)
	{
		return 0;
	}
	D3DVERTEXBUFFER_DESC desc;
	if (FAILED(m_pVertices->GetDesc(&desc)))
		return 0;
	return desc.Size/sizeof(MS3DPlane::CUSTOMVERTEX);
}

UINT MS3DPlane::GetPrimitiveNumber()
{
	if (m_pIndices == NULL)
	{
		return 0;
	}
	D3DINDEXBUFFER_DESC desc;
	if (FAILED(m_pIndices->GetDesc(&desc)))
		return 0;
	if (m_indexFMT == D3DFMT_INDEX16)
		return (desc.Size/sizeof(unsigned short))/3;
	else
		return (desc.Size/sizeof(unsigned int))/3;
}
DWORD MS3DPlane::GetVertexFMT()
{
	return m_vertexFMT;
}

D3DFORMAT MS3DPlane::GetIndexFMT()
{
	return m_indexFMT;
}