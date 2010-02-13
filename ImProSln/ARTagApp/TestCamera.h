#pragma once
#include "camerads.h"
#include "..\DXRender\IDXRenderer.h"
#include "..\HomoWarpFilter\IHomoWarpFilter.h"
#include "..\ArLayoutFilter\MyTestFilter\IARLayoutFilter.h"
#include "..\TouchLibFilter\ITouchLibFilter.h"
#include "..\AR2WarpController\IAR2WarpController.h"
class TestCamera :
	public CCameraDS
{
protected:
	CComPtr<IBaseFilter> m_pDXRenderer;
	CComPtr<IPin> m_pDXRendererInputPin;	
	CComPtr<IBaseFilter> m_pHomoWarpFilter;
	CComPtr<IPin> m_pHomoWarpInputPin;
	CComPtr<IPin> m_pHomoWarpOutD3DPin;

	CComPtr<IBaseFilter> m_pARLayoutFilter;
	CComPtr<IPin> m_pARLayoutInputConfigPin;
	CComPtr<IPin> m_pARLayoutOutputPin;

	CComPtr<IBaseFilter> m_pTouchLibFilter;
	CComPtr<IPin> m_pTouchLibInputPin;
	CComPtr<IPin> m_pTouchLibOutputPin;
	CComPtr<IPin> m_pTouchLibFGOutPin;

	CComPtr<IBaseFilter> m_pAR2WarpFilter;
	CComPtr<IPin> m_pAR2WarpInputTouchPin;
	CComPtr<IPin> m_pAR2WarpOutputARConfigPin;

	virtual HRESULT ConnectGraph();
	virtual HRESULT CreateFilters(int nCamID, bool bDisplayProperties, int nWidth, int nHeight);
public:

	TestCamera(void);
	~TestCamera(void);
};
