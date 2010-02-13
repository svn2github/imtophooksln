#pragma once
#include "mssd3dclass.h"

class MaskFilterDisplay :
	public MS3DDisplay
{
protected:
	enum MaskFlag 
	{
		BlockAll,
		PassAll,
		BlendMask
	};
	MaskFlag m_maskFlag;
	LPDIRECT3DTEXTURE9 m_pMaskTexture;

	virtual ID3DXEffect* GetEffect();
	virtual BOOL CreateTexture(UINT rtWidth, UINT rtHeight);
public:
	MaskFilterDisplay(IDirect3D9* pD3D, UINT rtWidth, UINT rtHeight);
	MaskFilterDisplay(IDirect3DDevice9* pDevice, UINT rtWidth, UINT rtHeight);
	~MaskFilterDisplay(void);

	virtual BOOL Render();
	virtual BOOL Render(IDirect3DBaseTexture9* pTexture);
	virtual BOOL Render(IDirect3DBaseTexture9* pTexture, ID3DXEffect* pEffect);
};