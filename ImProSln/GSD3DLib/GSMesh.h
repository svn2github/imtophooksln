#pragma once
#include "GSD3DBaseClass.h"
#include <map>
using namespace std;

class GSD3DLIB_API GSMeshBase : public IGSMeshBase, public GSDXBase
{
public:
	struct CUSTOMVERTEX
	{
		D3DXVECTOR3 position; // The position
		D3DXVECTOR3 normal;
		FLOAT       tu, tv;   // The texture coordinates
		static D3D11_INPUT_ELEMENT_DESC layout[];
	};
protected:
	FLOAT m_color[4];
	
	ID3D11Buffer* m_pVertexBuffer;
	ID3D11Buffer* m_pIndexBuffer;
	map<ID3DBlob*, ID3D11InputLayout*> m_pVertexLayout;
protected:
	GSMeshBase();
	virtual HRESULT ClearVertexLayout();
	virtual HRESULT GenerateVertexLayout(ID3DBlob* pShaderBuffer, ID3D11InputLayout*& pLayout);
public:
	virtual HRESULT InitGeometry(){return E_NOTIMPL;};

public:
	GSMeshBase(ID3D11Device* pDevice, ID3D11DeviceContext* pContext, IDXGISwapChain* pSwapChain);
	virtual ~GSMeshBase();
	virtual ID3D11Buffer* GetVertexBuffer();
	virtual ID3D11Buffer* GetIndexBuffer();
	virtual UINT GetVertexNumber();
	virtual UINT GetVertexStride();
	virtual HRESULT GetVertexLayout(ID3DBlob* pShaderBuffer, ID3D11InputLayout*& pLayout);
	
	virtual D3D11_PRIMITIVE_TOPOLOGY GetPrimitiveTopology();
};

class GSD3DLIB_API GS3DPlane : public GSMeshBase, public GS3DObj, public GSRefCount
{
private:
	virtual HRESULT InitGeometry();
public:
	GS3DPlane(ID3D11Device* pDevice, ID3D11DeviceContext* pContext, IDXGISwapChain* pSwapChain);
	virtual ~GS3DPlane();


};
