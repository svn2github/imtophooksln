#pragma once
#include "DSBaseClass.h"
#include "CameraDS.h"
#include <InitGuid.h>
#include "IARLayoutFilter.h"
#include "IDXRenderer.h"
#include "IHomoWarpFilter.h"

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

	CComPtr<IBaseFilter> m_pCamWarpFilter;
	CComPtr<IHomoWarpFilter> m_pICamWarpFilter;
	CComPtr<IPin> m_pCamWarpInputPin;
	CComPtr<IPin> m_pCamWarpOutputPin;

	CComPtr<IBaseFilter> m_pARWarpFilter;
	CComPtr<IHomoWarpFilter> m_pIARWarpFilter;
	CComPtr<IPin> m_pARWarpInputPin;
	CComPtr<IPin> m_pARWarpOutputPin;

	//overwrite CCameraDS function
	virtual HRESULT ConnectGraph();
	virtual HRESULT CreateFilters(int nCamID, bool bDisplayProperties, int nWidth, int nHeight);
	virtual HRESULT ConfigFilters();
public:
	
	virtual void CloseCamera();
	virtual HRESULT ShowDXRenderProp();
	virtual HRESULT ShowARLayoutProp();
	virtual HRESULT ShowARWarpProp();
	virtual HRESULT ShowCamWarpProp();

	virtual int GetNumMarker();
	virtual HRESULT SetMarkerVisible(int idx, BOOL bVisible);
	virtual HRESULT SetMarkerVisibleByID(int id, BOOL bVisible);
	virtual int GetMarkerID(int idx);
public:
	ARLayoutCameraDS(void);
	~ARLayoutCameraDS(void);
};
