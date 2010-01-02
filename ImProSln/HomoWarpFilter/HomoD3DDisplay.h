#pragma once
#include "mssd3dclass.h"

class HomoD3DDisplay :
	public MS3DDisplay
{
protected:
	D3DXMATRIX m_matTTS;
public:
	virtual BOOL SetMatTTS(const D3DXMATRIX* mat);
	virtual ID3DXEffect* GetEffect();
	virtual BOOL Render();
	virtual BOOL Render(IDirect3DBaseTexture9* pTexture);
	virtual BOOL Render(IDirect3DBaseTexture9* pTexture, ID3DXEffect* pEffect);
public:
	HomoD3DDisplay(HWND hWnd, IDirect3D9* pD3D, UINT rtWidth, UINT rtHeight);
	~HomoD3DDisplay(void);
};
