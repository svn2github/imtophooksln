#pragma once
#include "mssd3dclass.h"

class DXRenderDisplay :
	public MS3DDisplay
{	
private:
	//variables for fps computing
	DWORD lasttime;
	DWORD currtime;
	int count;
	float fps; 
	int imgW;
	int imgH;
public:
	bool m_bFlipX;
	bool m_bFlipY;
	bool m_bDrawFPS;
	LPD3DXFONT m_pD3DFont;
public:
	virtual ID3DXEffect* GetEffect();
	virtual BOOL Render();
	virtual BOOL Render(IDirect3DBaseTexture9* pTexture);
	virtual BOOL Render(IDirect3DBaseTexture9* pTexture, ID3DXEffect* pEffect);
protected:
	virtual HRESULT OnBeforeResetDevice(IDirect3DDevice9 * pd3dDevice,	
		void* pUserContext);
	virtual HRESULT OnAfterResetDevice(IDirect3DDevice9 * pd3dDevice,	
		void* pUserContext);

public:
	DXRenderDisplay(IDirect3D9* pD3D, UINT rtWidth, UINT rtHeight);
	DXRenderDisplay(IDirect3DDevice9* pDevice, UINT rtWidth, UINT rtHeight);
	~DXRenderDisplay(void);
	
};