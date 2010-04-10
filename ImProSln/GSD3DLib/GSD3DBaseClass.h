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
	IDXGISwapChain*          m_pSwapChain;
public:
	GSDXBase();
	GSDXBase(ID3D11Device* pDevice, ID3D11DeviceContext* pContext, IDXGISwapChain* pSwapChain);
	virtual ~GSDXBase();
	virtual ID3D11Device* GetD3DDevice();
	virtual ID3D11DeviceContext* GetDeviceContext();
	virtual HRESULT CreateD3DDevice(HWND hwnd, UINT bufW, UINT bufH);
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



class GSD3DLIB_API GSTexture2D
{
protected:
	ID3D11Texture2D* m_pTexture;
public:
	GSTexture2D();
	~GSTexture2D();
	virtual ID3D11Texture2D* GetTexture();
	virtual HRESULT SetTexture(ID3D11Texture2D* pTexture);
	virtual HRESULT Create(ID3D11Device* pDevice, UINT texW, UINT texH, UINT MipLevels = 1, D3D11_USAGE Usage = D3D11_USAGE_DYNAMIC, 
		DXGI_FORMAT format = DXGI_FORMAT_R8G8B8A8_UNORM, UINT BindFlags = D3D11_BIND_SHADER_RESOURCE | D3D11_BIND_RENDER_TARGET, 
		UINT CPUAccessFlags = D3D11_CPU_ACCESS_WRITE | D3D11_CPU_ACCESS_READ, UINT MiscFlags = /*D3D11_RESOURCE_MISC_SHARED |*/ D3D11_RESOURCE_MISC_GDI_COMPATIBLE );
};


class GSD3DLIB_API GSRenderBase : public IGSRenderBase
{	
protected:
	vector<ID3D11RenderTargetView*> m_pBackupRenderTarget;
protected:
	virtual HRESULT SetEffectVariables(IGSEffectBase* pGSEffect) = 0;
public:
	GSRenderBase();
	~GSRenderBase();
	virtual HRESULT RenderMesh(IGSMeshBase* pMesh, ID3D11DeviceContext* pDeviceContext, IGSEffectBase* pGSEffect, UINT idxTech = 0);
	virtual HRESULT SetRenderTarget(ID3D11DeviceContext* pDeviceContext, ID3D11RenderTargetView* pRenderTarget);
	virtual HRESULT ResetRenderTarget(ID3D11DeviceContext* pDeviceContext);
};