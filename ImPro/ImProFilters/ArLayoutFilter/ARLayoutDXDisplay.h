#pragma once
#include "mssd3dclass.h"
#include <map>
#include "ARToolKitPlus/TrackerMultiMarker.h"
using namespace ARToolKitPlus;
using namespace std;
#define NUMMARKER 512
class ARLayoutDXDisplay :
	public MS3DDisplay
{	
protected:
	
	MS3DPlane* m_pMarkerMesh;
	map<int, LPDIRECT3DTEXTURE9> m_pMarkerTextures;
	bool LoadARMarkTexture();
	bool CreateMarkerMesh();

	virtual HRESULT OnBeforeResetDevice(IDirect3DDevice9 * pd3dDevice,	
		void* pUserContext);
	virtual HRESULT OnAfterResetDevice(IDirect3DDevice9 * pd3dDevice,	
		void* pUserContext);

public:
	virtual ID3DXEffect* GetEffect();
	virtual BOOL Render(const ARMultiMarkerInfoT* pMarkerConfig);
	virtual BOOL Render();
	virtual BOOL Render(IDirect3DBaseTexture9* pTexture);
	virtual BOOL Render(IDirect3DBaseTexture9* pTexture, ID3DXEffect* pEffect);
	virtual BOOL RenderMask(const ARMultiMarkerInfoT* pMarkerConfig, float fMaskScale);
public:
	ARLayoutDXDisplay(IDirect3D9* pD3D, UINT rtWidth, UINT rtHeight);
	ARLayoutDXDisplay(IDirect3DDevice9* pDevice, UINT rtWidth, UINT rtHeight);
	~ ARLayoutDXDisplay(void);

};