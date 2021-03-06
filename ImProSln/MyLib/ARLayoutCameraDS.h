#pragma once
#include "DSBaseClass.h"
#include "CameraDS.h"
#include <InitGuid.h>
#include "IARLayoutFilter.h"
#include "IDXRenderer.h"
#include "IHomoWarpFilter.h"
#include "IDXBlendFilter.h"
#include "IProjectSettingFilter.h"

#define NUMCAM 4
#define DXBLEND_PINNUM 4
 class DSBASECLASSES_API ARLayoutCameraDS :
	public CCameraDS
{
protected:
	CComPtr<IBaseFilter> m_pARLayoutFilter;
	CComPtr<IARLayoutDXFilter> m_pIARLayoutFilter;	
	CComPtr<IPin> m_pARLayoutOutputPin;

	CComPtr<IBaseFilter> m_pDXRenderFilter;
	CComPtr<IDXRenderer> m_pIDXRenderFilter;
	CComPtr<IPin> m_pDXRenderInputPin;

	CComPtr<IBaseFilter> m_pCamFilter[NUMCAM];
	CComPtr<IPin> m_pCamOutputPin[NUMCAM];

	CComPtr<IBaseFilter> m_pCamWarpFilter[NUMCAM];
	CComPtr<IHomoWarpFilter> m_pICamWarpFilter[NUMCAM];
	CComPtr<IPin> m_pCamWarpInputPin[NUMCAM];
	CComPtr<IPin> m_pCamWarpOutputPin[NUMCAM];


	CComPtr<IBaseFilter> m_pDXBlendFilter;
	CComPtr<IDXBlendFilter> m_pIDXBlendFilter;
	CComPtr<IPin> m_pDXBlendInputPin[DXBLEND_PINNUM];
	CComPtr<IPin> m_pDXBlendOutputPin;

	CComPtr<IBaseFilter> m_pARWarpFilter;
	CComPtr<IHomoWarpFilter> m_pIARWarpFilter;
	CComPtr<IPin> m_pARWarpInputPin;
	CComPtr<IPin> m_pARWarpOutputPin;

	CComPtr<IBaseFilter> m_pProjSetFilter;
	CComPtr<IProjectSettingFilter> m_pIProjSetFilter ;

	CComPtr<IBaseFilter> m_pBlendWarpFilter;
	CComPtr<IHomoWarpFilter> m_pIBlendWarpFilter;
	CComPtr<IPin> m_pBlendWarpInputPin;
	CComPtr<IPin> m_pBlendWarpOutputPin;



	//overwrite CCameraDS function
	virtual HRESULT ConnectGraph();
	virtual HRESULT CreateFilters(int nCamID, bool bDisplayProperties, int nWidth, int nHeight);
	virtual HRESULT ConfigFilters();
public:
	virtual HRESULT AddCamera(int nCamID, bool bDisplayProperties=true);
	virtual HRESULT RemoveCamera(int idx);
	virtual void CloseCamera();
	virtual HRESULT ShowDXRenderProp();
	virtual HRESULT ShowDXBlendProp();
	virtual HRESULT ShowARLayoutProp();
	virtual HRESULT ShowARWarpProp();
	virtual HRESULT ShowCamWarpProp(int idx);
	virtual HRESULT ShowCamProp(int idx);
	virtual HRESULT ShowCamPinProp(int idx);
	virtual HRESULT ShowProjSetProp() ;
	virtual HRESULT ShowBlendWarpProp();

	virtual int GetNumMarker();
	virtual HRESULT SetMarkerVisible(int idx, BOOL bVisible);
	virtual HRESULT SetMarkerVisibleByID(int id, BOOL bVisible);
	virtual int GetMarkerID(int idx);
public:
	ARLayoutCameraDS(void);
	~ARLayoutCameraDS(void);
};
