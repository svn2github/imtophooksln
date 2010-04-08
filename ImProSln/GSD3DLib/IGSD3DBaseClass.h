#pragma once
#include <D3D11.h>
#include <D3DX11.h>
#include <D3DX10math.h>
#include <D3Dcompiler.h>
class IGSMeshBase;
class IGSEffectBase;

class IGSRefCount
{
public:
	STDMETHOD_(ULONG, AddRef)() = 0;
	STDMETHOD_(ULONG, Release)() = 0;
};


class GSD3DLIB_API IGSRenderBase
{	
public:
	virtual HRESULT RenderMesh(IGSMeshBase* pMesh, IGSEffectBase* pEffect, ID3D11DeviceContext* pDeviceContext) = 0;
};


class GSD3DLIB_API IGS3DBase
{
public:
	virtual D3DXMATRIX GetTransform() = 0;
	virtual HRESULT Translate(D3DXVECTOR3& t) = 0;
	virtual HRESULT RotateAxis(CONST D3DXVECTOR3 * pV, FLOAT angle) = 0;
	virtual HRESULT Scale(D3DXVECTOR3& s) = 0;
	virtual HRESULT ResetTransform() = 0;
	virtual HRESULT PushMatrix() = 0;
	virtual HRESULT PopMatrix()= 0;
};


class GSD3DLIB_API IGSMeshBase
{
public: 
	virtual ID3D11Buffer* GetVertexBuffer() = 0;
	virtual ID3D11Buffer* GetIndexBuffer() = 0;
	virtual UINT GetVertexNumber() = 0;
	virtual UINT GetPrimitiveNumber() = 0;
	virtual UINT GetVertexStride() = 0;
};


class GSD3DLIB_API IGSEffectBase
{
public:
	virtual ID3D11PixelShader* GetPSShader() = 0;
	virtual ID3D11VertexShader* GetVSShader() = 0;
	virtual ID3DBlob* GetVSShaderBuffer() = 0;
	virtual ID3DBlob* GetPSShaderBuffer() = 0;
	
};


class GSD3DLIB_API IGSCamera
{
public:
	virtual HRESULT SetEyePos(D3DXVECTOR3& vEyePt) = 0;
	virtual HRESULT SetLookAt(D3DXVECTOR3& vLookPt) = 0;
	virtual HRESULT SetUpVec(D3DXVECTOR3& vUpVec) = 0;
	virtual D3DXVECTOR3 GetEyePos() = 0;
	virtual D3DXVECTOR3 GetLookAt() = 0;
	virtual D3DXVECTOR3 GetUpVec() = 0;
	virtual D3DXMATRIX GetViewMatrix() = 0;
	virtual D3DXMATRIX GetProjMatrix() = 0;

};