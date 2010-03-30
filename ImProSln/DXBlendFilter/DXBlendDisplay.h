#pragma once
#include "mssd3dclass.h"

class DXBlendDisplay :
	public MS3DDisplay
{	
private:
	//variables for fps computing
public:

public:
	virtual ID3DXEffect* GetEffect();
	virtual BOOL Render();
	virtual BOOL Render(IDirect3DBaseTexture9* pTexture);
	virtual BOOL Render(IDirect3DBaseTexture9* pTexture, ID3DXEffect* pEffect);
protected:
	
public:
	DXBlendDisplay(IDirect3D9* pD3D, UINT rtWidth, UINT rtHeight);
	DXBlendDisplay(IDirect3DDevice9* pDevice, UINT rtWidth, UINT rtHeight);
	~DXBlendDisplay(void);

};