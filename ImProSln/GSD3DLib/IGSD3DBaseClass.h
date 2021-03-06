#pragma once
#include <D3D11.h>
#include <D3DX11.h>
#include <D3DX10math.h>
#include <D3Dcompiler.h>
#include "d3dx11effect.h"
class IGSMeshBase;
class IGSEffectBase;


class GSD3DLIB_API IGSRenderBase
{	
public:
	virtual HRESULT SetRenderTarget(ID3D11DeviceContext* pDeviceContext, ID3D11RenderTargetView* pRenderTarget) = 0;
	virtual HRESULT ResetRenderTarget(ID3D11DeviceContext* pDeviceContext) = 0;
	virtual HRESULT RenderMesh(IGSMeshBase* pMesh, ID3D11DeviceContext* pDeviceContext, IGSEffectBase* pGSEffect, UINT idxTech = 0) = 0;
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
	virtual UINT GetVertexStride() = 0;
	virtual HRESULT GetVertexLayout(ID3DX11Effect* pEffect, ID3D11InputLayout*& pLayout) = 0;
	virtual D3D11_PRIMITIVE_TOPOLOGY GetPrimitiveTopology() = 0;
};


class GSD3DLIB_API IGSEffectBase
{
public:
	virtual ID3DBlob* GetEffectBuffer() = 0;
	virtual ID3DX11Effect* GetEffect() = 0;
	virtual HRESULT LoadFromFile(LPCWSTR szFileName) = 0; 
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

class GSD3DLIB_API IGSWnd
{
public:
	virtual HRESULT ShowWnd(BOOL bShow) = 0;
	virtual HWND GetHwnd() = 0;
	virtual HRESULT CreateWnd(UINT wndWidth, UINT wndHeight) = 0;

};

class GSD3DLIB_API IGSD3DDisplay
{
public:
	virtual IGSCamera* GetCamera() = 0;
	virtual BOOL IsDeviceFromOther() = 0;
	virtual HRESULT Render() = 0;
};