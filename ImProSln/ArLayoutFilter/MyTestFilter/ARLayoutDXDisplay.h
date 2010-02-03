#pragma once
#include "mssd3dclass.h"
#include <map>
#include "ARToolKitPlus/TrackerMultiMarker.h"
using namespace ARToolKitPlus;
using namespace std;
#define NUMMARKER 511
class ARLayoutDXDisplay :
	public MS3DDisplay
{	
protected:
	
	MS3DPlane* m_pMarkerMesh;
	map<int, LPDIRECT3DTEXTURE9> m_pMarkerTextures;
	bool LoadARMarkTexture();
	bool CreateMarkerMesh();
public:
	virtual ID3DXEffect* GetEffect();
	virtual BOOL Render(const ARMultiMarkerInfoT* pMarkerConfig);
	virtual BOOL Render();
	virtual BOOL Render(IDirect3DBaseTexture9* pTexture);
	virtual BOOL Render(IDirect3DBaseTexture9* pTexture, ID3DXEffect* pEffect);
public:
	ARLayoutDXDisplay(IDirect3D9* pD3D, UINT rtWidth, UINT rtHeight);
	ARLayoutDXDisplay(IDirect3DDevice9* pDevice, UINT rtWidth, UINT rtHeight);
	~ ARLayoutDXDisplay(void);

};