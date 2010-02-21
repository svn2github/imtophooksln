#pragma once

#include "mssd3dclass.h"
#include "MyARTagMediaSample.h"

#define MASKSIZE 256

class MaskFilterDisplay : public MS3DDisplay
{
protected:
	enum MaskFlag 
	{
		BlockAll = 0,
		PassAll = 1,
		BlendMask = 2
	};
	MaskFlag m_maskFlag;
	LPDIRECT3DTEXTURE9 m_pMaskTexture;
	LPDIRECT3DTEXTURE9 m_pMaskRectTexture;
	bool m_bMaskFlipY;
	MS3DPlane* m_pMarkerMesh;
	MS3DPlane* m_pWarpMesh;
	MSCamera* m_pMaskCamera;
	virtual ID3DXEffect* GetEffect();
	virtual BOOL CreateMaskTexture(UINT rtWidth, UINT rtHeight);
	bool CreateMarkerMesh();
	bool CreateWarpMesh();

	virtual HRESULT OnBeforeResetDevice(IDirect3DDevice9 * pd3dDevice,	
		void* pUserContext);
	virtual HRESULT OnAfterResetDevice(IDirect3DDevice9 * pd3dDevice,	
		void* pUserContext);
public:
	MaskFilterDisplay(IDirect3D9* pD3D, UINT rtWidth, UINT rtHeight);
	MaskFilterDisplay(IDirect3DDevice9* pDevice, UINT rtWidth, UINT rtHeight);
	~MaskFilterDisplay(void);

	virtual BOOL Render();
	virtual BOOL Render(IDirect3DBaseTexture9* pTexture);
	virtual BOOL Render(IDirect3DBaseTexture9* pTexture, ID3DXEffect* pEffect);
	virtual BOOL SetMaskFlag(int flag);
	virtual int GetMaskFlag();
	virtual BOOL LoadMaskFromFile(WCHAR* path);
	virtual BOOL GenerateMaskFromARLauout(const ARMultiMarkerInfoT* pMarkerConfig, float fMaskScale = 1.2);
	virtual BOOL GenerateMaskFromARLayoutFile(WCHAR* path, float fMaskScale = 1.2);
	virtual BOOL GenerateMaskFromWarpMatrix(D3DXMATRIX warpMat[], int numMatrix, float fMaskScale = 1.2);
	virtual BOOL GenerateMaskFromVertices(D3DXVECTOR2* pts[], int numRects, float fMaskScale = 1.2);
	virtual BOOL ClearMask();
	virtual BOOL GetMaskFlipY();
	virtual BOOL SetMaskFlipY(bool bFlipY);

	virtual BOOL GenerateARMarkinfo(ARMultiEachMarkerInfoT* ARMarkers, int numMarker, ARMultiMarkerInfoT*& config);
};