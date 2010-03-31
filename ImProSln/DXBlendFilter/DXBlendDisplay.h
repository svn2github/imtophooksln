#pragma once
#include "mssd3dclass.h"

class DXBlendDisplay :
	public MS3DDisplay
{	
private:

public:
	
public:
	virtual ID3DXEffect* GetEffect();
	virtual BOOL Render();
	virtual BOOL Render(LPDIRECT3DTEXTURE9 pTexture);
	virtual BOOL Render(IDirect3DBaseTexture9* pTexture, ID3DXEffect* pEffect);
	virtual BOOL Render(LPDIRECT3DTEXTURE9 pSrc1, LPDIRECT3DTEXTURE9 pSrc2, 
		LPDIRECT3DTEXTURE9 pWeight1); // weight2 is 1.
protected:
	
public:
	DXBlendDisplay(IDirect3D9* pD3D, UINT rtWidth, UINT rtHeight);
	DXBlendDisplay(IDirect3DDevice9* pDevice, UINT rtWidth, UINT rtHeight);
	~DXBlendDisplay(void);

};