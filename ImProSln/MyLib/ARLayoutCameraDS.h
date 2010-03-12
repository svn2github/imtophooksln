#pragma once
#include "CameraDS.h"
#include "IARLayoutFilter.h"
#include "IDXRenderer.h"

class ARLayoutCameraDS :
	public CCameraDS
{
protected:
	CComPtr<IBaseFilter> m_pARLayoutFilter;
	CComPtr<IARLayoutDXFilter> m_pIARLayoutFilter;	
	CComPtr<IPin> m_pARLayoutOutputPin;

	CComPtr<IBaseFilter> m_pDXRenderFilter;
	CComPtr<IDXRenderer> m_pIDXRenderFilter;
	//overwrite CCameraDS function
	virtual HRESULT ConnectGraph();
	virtual HRESULT CreateFilters(int nCamID, bool bDisplayProperties, int nWidth, int nHeight);
public:
	
	virtual void CloseCamera();
	virtual BOOL ShowDXRenderProp();
public:
	ARLayoutCameraDS(void);
	~ARLayoutCameraDS(void);
};
