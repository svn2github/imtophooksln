#pragma once
#include "IARTagFilter.h"
#include "mssd3dclass.h"
#include <vector>
#include "ARToolKitPlus/armulti.h"
using namespace ARToolKitPlus;
using namespace std;

class MS3DARMarker : public MS3DPlane
{
private:
	LPD3DXMESH m_pIDMesh;
	int m_markerID;
	HRESULT CreateD3DXTextMesh( IDirect3DDevice9* pd3dDevice, LPD3DXMESH* ppMesh, WCHAR* txt, WCHAR* pstrFont, DWORD dwSize,
		BOOL bBold, BOOL bItalic );
public:
	MS3DARMarker(IDirect3DDevice9* pDevice);
	~MS3DARMarker();
	BOOL SetMarkID(int _id);
	int GetMarkID() { return m_markerID;};
	virtual BOOL Render();

};

class ARTagD3DDisplay :	public MS3DDisplay
{
protected:
	ID3DXSprite* m_pD3DSprite;
	ID3DXLine* m_pD3DLine;
	LPD3DXFONT m_pD3DFont;
public:

	virtual BOOL Render(ARMarkerInfo* markinfos, int numMarkinfo, int imgW, int imgH);
	virtual BOOL Render();
	virtual BOOL Render(IDirect3DBaseTexture9* pTexture);
	virtual BOOL Render(IDirect3DBaseTexture9* pTexture, ID3DXEffect* pEffect);
	
public:
	ARTagD3DDisplay(IDirect3D9* pD3D, UINT rtWidth, UINT rtHeight);
	ARTagD3DDisplay(IDirect3DDevice9* pD3D, UINT rtWidth, UINT rtHeight);
	~ARTagD3DDisplay(void);
};

