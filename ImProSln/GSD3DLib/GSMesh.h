#pragma once
#include "GSD3DBaseClass.h"

class GSD3DLIB_API GSMeshBase : public IGSMeshBase, public GSDXBase
{
public:
	struct CUSTOMVERTEX
	{
		D3DXVECTOR3 position; // The position
		D3DXVECTOR3 normal;
		FLOAT       tu, tv;   // The texture coordinates
		static D3D10_INPUT_ELEMENT_DESC layout[];
	};
protected:
	FLOAT m_color[4];
	ID3D11InputLayout* m_pVertexLayout;
	ID3D11Buffer* m_pVertexBuffer;
	ID3D11Buffer* m_pIndexBuffer;
protected:
	GSMeshBase();

public:
	virtual HRESULT InitGeometry(){return E_NOTIMPL;};

public:
	GSMeshBase(ID3D11Device* pDevice, ID3D11DeviceContext* pContext);
	virtual ~GSMeshBase();
	virtual ID3D11Buffer* GetVertexBuffer();
	virtual ID3D11Buffer* GetIndexBuffer();
	virtual UINT GetVertexNumber();
	virtual UINT GetVertexStride();

	virtual HRESULT GetVertex(UINT idx, void* pVertex);
	virtual HRESULT SetVertex(UINT idx, void* pVertex);
	virtual HRESULT GetVertexLayout(ID3D11InputLayout*& pLayout);
};

class GSD3DLIB_API GS3DPlane : public GSMeshBase, public GS3DObj
{
private:
	virtual HRESULT InitGeometry();
public:
	GS3DPlane(ID3D11Device* pDevice, ID3D11DeviceContext* pContext);
	virtual ~GS3DPlane();
	virtual HRESULT Render();

};
