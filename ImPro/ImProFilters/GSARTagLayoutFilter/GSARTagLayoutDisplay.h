#pragma once
#include "gsd3ddisplay.h"
#include "GSARTagLayoutFilter.h"
using namespace GSARLayoutNS;

class GSARTagLayoutDisplay : public GS3DDisplay
{
private:
	 // for ARLayout strategy.
	CCritSec m_csParaSetting;

	float m_minMarkerWidth;
	vector<vector<int>> m_TagIntersectTable;
	

	HRESULT generateAllMarkerRect();
	HRESULT generateARTagMesh();
	HRESULT generateIntersectTable();
	HRESULT _SetEffectPara(ID3DX11Effect* pEffect, GSEffectSettingEntry* pEntries, UINT nEntry);
protected:
	float m_blackLevel;

	GSARTagLayout* m_pLayout;
	GS3DPlane* m_pARTagMesh[NUMARTAG];
	GSTexture2D* m_pARTagTexture[NUMARTAG];
	GSBoundingBox2D* m_allMarkerRects[NUMARTAG];

	ID3D11ShaderResourceView* m_pTmpSView;
	GS3DPlane* m_pTmpPlane;
public:
	GSARTagLayoutDisplay(UINT bufW, UINT bufH);
	GSARTagLayoutDisplay(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext, IDXGISwapChain* pSwapChain);
	virtual ~GSARTagLayoutDisplay(void);
	virtual HRESULT Render();

	virtual HRESULT RenderMesh(IGSMeshBase* pMesh, ID3D11DeviceContext* pDeviceContext, IGSEffectBase* pGSEffect, UINT idxTech = 0);
	virtual HRESULT initARLayout(UINT numLevel, UINT intMarkerBits, UINT intBorderBits, float intWidthBits);

	virtual int GetNumMarker();
	virtual HRESULT SetMarkerVisible(int idx, BOOL bVisible);
	virtual HRESULT SetMarkerVisibleByID(int id, BOOL bVisible);
	virtual int GetMarkerID(int idx);

	virtual HRESULT LoadARTagTexture();
	virtual HRESULT OnEffectSetting();

	virtual HRESULT DecideLayout(GSBoundingBox2D* camRects, UINT numCamRect,
		GSBoundingBox2D* fingerRects, UINT numFingerRects, BOOL& bLayoutChanged, float fingerExtend = 0.07);

	virtual HRESULT GetLayout(GSARTagLayout*& pLayout);

	virtual float GetBlackLevel();
	virtual HRESULT SetBlackLevel(float level);
};
