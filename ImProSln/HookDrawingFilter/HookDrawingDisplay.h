#pragma once
#include "mssd3dclass.h"

class HookDrawingDisplay :
	public MS3DDisplay
{
protected:
	D3DXMATRIX m_matTTS;
	virtual ID3DXEffect* GetEffect();
	virtual BOOL Render();
	virtual BOOL Render(IDirect3DBaseTexture9* pTexture);
	virtual BOOL Render(IDirect3DBaseTexture9* pTexture, ID3DXEffect* pEffect);
public:
	HookDrawingDisplay(IDirect3D9* pD3D, UINT rtWidth, UINT rtHeight);
	HookDrawingDisplay(IDirect3DDevice9* pDevice, UINT rtWidth, UINT rtHeight);
	~HookDrawingDisplay(void);
	virtual BOOL SetMatTTS(const D3DXMATRIX* mat);
};