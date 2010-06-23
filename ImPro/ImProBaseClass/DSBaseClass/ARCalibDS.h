#pragma once
#include "DSBaseClass.h"
#include "CameraDS.h"
#include <InitGuid.h>
#include "IARLayoutFilter.h"
#include "IDXRenderer.h"
#include "IHomoWarpFilter.h"
#include "IARTagFilter.h"
#include "IProjectSettingFilter.h"

//#include "IGSARTagLayoutFilter.h"
#include "IGSDXRenderer.h"
#include "IGSDXBlendFilter.h"
#include "IGSHomoWarpFilter.h"
#include "IGSProjSettingFilter.h"

class DSBASECLASSES_API ARCalibDS :
	public CCameraDS
{
public:

    // ARLayout ->  Warp  ->  Render
	// Cam -> Warp -> ARTag -> Render
	CComPtr<IBaseFilter> m_pARLayoutFilter;
	CComPtr<IARLayoutDXFilter> m_pIARLayoutFilter;	
	CComPtr<IPin> m_pARLayoutOutputPin;

	CComPtr<IBaseFilter> m_pDXCamRenderFilter;
	CComPtr<IDXRenderer> m_pIDXCamRenderFilter;
	CComPtr<IPin> m_pDXCamRenderInputPin;

	CComPtr<IBaseFilter> m_pDXARRenderFilter;
	CComPtr<IDXRenderer> m_pIDXARRenderFilter;
	CComPtr<IPin> m_pDXARRenderInputPin;

	CComPtr<IBaseFilter> m_pCamFilter;
	CComPtr<IPin> m_pCamOutputPin;

	CComPtr<IBaseFilter> m_pCamWarpFilter;
	CComPtr<IHomoWarpFilter> m_pICamWarpFilter;
	CComPtr<IPin> m_pCamWarpInputPin;
	CComPtr<IPin> m_pCamWarpOutputPin;

	CComPtr<IBaseFilter> m_pARWarpFilter;
	CComPtr<IHomoWarpFilter> m_pIARWarpFilter;
	CComPtr<IPin> m_pARWarpInputPin;
	CComPtr<IPin> m_pARWarpOutputPin;

	CComPtr<IBaseFilter> m_pARTagFilter;
	CComPtr<IARTagFilter> m_pIARTagFilter;
	CComPtr<IPin> m_pARTagInputPin;	
	CComPtr<IPin> m_pARTagOutputPin;

	CComPtr<IBaseFilter> m_pProjSetFilter;
	CComPtr<IProjectSettingFilter> m_pIProjSetFilter ;

	//overwrite CCameraDS function
	virtual HRESULT ConnectGraph();
	virtual HRESULT CreateFilters(int nCamID, bool bDisplayProperties, int nWidth, int nHeight);
	virtual HRESULT ConfigFilters();

public:
	virtual void CloseCamera();
	
	virtual HRESULT ShowDXCamRenderProp();
	virtual HRESULT ShowDXARRenderProp();
	
	virtual HRESULT ShowARProp();
	virtual HRESULT ShowARWarpProp();
	
	virtual HRESULT ShowCamWarpProp();
	virtual HRESULT ShowCamProp();
	virtual HRESULT ShowCamPinProp();
	virtual HRESULT ShowARTagProp() ;
	virtual HRESULT ShowProjSetProp() ;

public:
	ARCalibDS(void);
	virtual ~ARCalibDS(void);
	virtual BOOL SetARCallback(IARTagFilter::CallbackFuncPtr pcallback, int argc, void* argv[]);


};