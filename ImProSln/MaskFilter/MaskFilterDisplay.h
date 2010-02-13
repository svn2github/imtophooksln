#pragma once
#include "mssd3dclass.h"

class MaskFilterDisplay :
	public MS3DDisplay
{
protected:
	virtual ID3DXEffect* GetEffect();
	virtual BOOL Render();
	virtual BOOL Render(IDirect3DBaseTexture9* pTexture);
	virtual BOOL Render(IDirect3DBaseTexture9* pTexture, ID3DXEffect* pEffect);
public:
	MaskFilterDisplay(IDirect3D9* pD3D, UINT rtWidth, UINT rtHeight);
	MaskFilterDisplay(IDirect3DDevice9* pDevice, UINT rtWidth, UINT rtHeight);
	~MaskFilterDisplay(void);
};