#pragma once
#include "camerads.h"
#include "..\DXRender\IDXRenderer.h"
#include "..\HomoWarpFilter\IHomoWarpFilter.h"
class TestCamera :
	public CCameraDS
{
protected:
	CComPtr<IBaseFilter> m_pDXRenderer;
	CComPtr<IPin> m_pDXRendererInputPin;	
	CComPtr<IBaseFilter> m_pHomoWarpFilter;
	CComPtr<IPin> m_pHomoWarpInputPin;
	CComPtr<IPin> m_pHomoWarpOutD3DPin;
	virtual HRESULT ConnectGraph();
	virtual HRESULT CreateFilters(int nCamID, bool bDisplayProperties, int nWidth, int nHeight);
public:

	TestCamera(void);
	~TestCamera(void);
};
