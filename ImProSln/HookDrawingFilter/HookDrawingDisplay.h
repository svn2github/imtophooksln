#pragma once
#include "mssd3dclass.h"

class HookDrawingDisplay :
	public MS3DDisplay
{

protected:
	//for RenderMask
	LPDIRECT3DTEXTURE9 m_pMaskTexture;
	LPDIRECT3DTEXTURE9 m_pMaskRectTexture;
	
	MS3DPlane* m_pWarpMesh;
	MSCamera* m_pMaskCamera;
	LPD3DXEFFECT m_pMaskEffect;

	virtual BOOL CreateMaskTexture();
	bool CreateMarkerMesh();
	bool CreateWarpMesh();
	BOOL GenerateMaskFromVertices(D3DXVECTOR2* pts[], int numRects, float fMaskScale);

public:
	virtual BOOL ClearMask();
	virtual BOOL SetMaskTexture(LPDIRECT3DTEXTURE9 maskTexture);
	virtual BOOL GetMaskTexture(LPDIRECT3DTEXTURE9& output);
public:
	enum SampleType
	{
		POINT = 0,
		LINEAR = 1
	};
	SampleType m_sampleType;
	bool m_bFlipX;
	bool m_bFlipY;
	bool m_bDrawFPS;

	enum MaskFlag 
	{
		BlockAll = 0,
		PassAll = 1,
		BlendMask = 2
	};
	MaskFlag m_maskFlag;
	bool m_bMaskFlipY;
private:
	//fps compute
	DWORD lasttime;
	DWORD currtime;
	int count;
	float fps; 
	int imgW;
	int imgH;
	LPD3DXFONT m_pD3DFont;
protected:
	D3DXMATRIX m_matTTS;
	virtual ID3DXEffect* GetEffect();
	virtual ID3DXEffect* GetMaskEffect();
public:
	HookDrawingDisplay(IDirect3D9* pD3D, UINT rtWidth, UINT rtHeight);
	HookDrawingDisplay(IDirect3DDevice9* pDevice, UINT rtWidth, UINT rtHeight);
	~HookDrawingDisplay(void);
	virtual BOOL SetMatTTS(const D3DXMATRIX* mat);
	virtual BOOL RenderMask();
	virtual BOOL Render();
	virtual BOOL Render(IDirect3DBaseTexture9* pTexture);
	virtual BOOL Render(IDirect3DBaseTexture9* pTexture, ID3DXEffect* pEffect);

};