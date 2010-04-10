#pragma once
#include "GSD3DLib.h"
#include "IGSD3DBaseClass.h"
#include <vector>
#include <assert.h>
#include <D3D11.h>
#include <D3DX11.h>
#include <D3DX10math.h>

using namespace std;

class GSD3DLIB_API GSRefCount : public IGSRefCount
{
protected:
	int m_nRef;
public:
	GSRefCount();
	~GSRefCount();
	STDMETHOD_(ULONG, AddRef)();
	STDMETHOD_(ULONG, Release)();
};

class GSD3DLIB_API GSDXBase
{
protected:
	ID3D11Device*            m_pDevice;
	ID3D11DeviceContext*     m_pDeviceContext;

public:
	GSDXBase();
	GSDXBase(ID3D11Device* pDevice, ID3D11DeviceContext* pContext);
	virtual ~GSDXBase();
	virtual ID3D11Device* GetD3DDevice();
	virtual ID3D11DeviceContext* GetDeviceContext();
};

class GSD3DLIB_API GS3DObj : public IGS3DBase
{
protected:
	ID3DXMatrixStack* m_pMatrixStack;
public:
	GS3DObj();
	virtual ~GS3DObj();
	virtual D3DXMATRIX GetTransform();
	virtual HRESULT SetTransform(const D3DXMATRIX* mat);
	virtual HRESULT Translate(D3DXVECTOR3& t);
	virtual HRESULT RotateAxis(CONST D3DXVECTOR3 * pV, FLOAT angle);
	virtual HRESULT Scale(D3DXVECTOR3& s);
	virtual HRESULT ResetTransform();
	virtual HRESULT PushMatrix();
	virtual HRESULT PopMatrix();
	virtual HRESULT SetPosition(D3DXVECTOR3 pos);
	virtual D3DXVECTOR3 GetPosition();
};



class GSD3DLIB_API GSTextureBase
{
protected:
	ID3D11Texture2D* m_pTexture;
public:
	GSTextureBase();
	~GSTextureBase();
	ID3D11Texture2D* GetTexture();
	HRESULT SetTexture(ID3D11Texture2D* pTexture);
};


class GSD3DLIB_API GSRenderBase
{	
public:
	virtual HRESULT SetEffectVariables(IGSEffectBase* pGSEffect) = 0;
public:
	virtual HRESULT RenderMesh(IGSMeshBase* pMesh, ID3D11DeviceContext* pDeviceContext, IGSEffectBase* pGSEffect, UINT idxTech = 0);
	
};