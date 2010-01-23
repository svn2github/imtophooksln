#pragma once
#include "mssd3dclass.h"

class HookDrawingDisplay :
	public MS3DDisplay
{
protected:

	virtual ID3DXEffect* GetEffect();
	virtual BOOL Render();
	virtual BOOL Render(IDirect3DBaseTexture9* pTexture);
	virtual BOOL Render(IDirect3DBaseTexture9* pTexture, ID3DXEffect* pEffect);
public:
	HookDrawingDisplay(HWND hWnd, IDirect3D9* pD3D, UINT rtWidth, UINT rtHeight);
	~HookDrawingDisplay(void);
};