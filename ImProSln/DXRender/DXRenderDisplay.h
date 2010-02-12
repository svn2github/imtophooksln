#pragma once
#include "mssd3dclass.h"

class DXRenderDisplay :
	public MS3DDisplay
{	
public:
	bool m_bFlipX;
	bool m_bFlipY;
	
public:
	virtual ID3DXEffect* GetEffect();
	virtual BOOL Render();
	virtual BOOL Render(IDirect3DBaseTexture9* pTexture);
	virtual BOOL Render(IDirect3DBaseTexture9* pTexture, ID3DXEffect* pEffect);
public:
	DXRenderDisplay(IDirect3D9* pD3D, UINT rtWidth, UINT rtHeight);
	DXRenderDisplay(IDirect3DDevice9* pDevice, UINT rtWidth, UINT rtHeight);
	~DXRenderDisplay(void);
	
};