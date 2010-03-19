#pragma once
#include "DSBaseClass.h"
#include "camerads.h"
#include "IARTagFilter.h"

class DSBASECLASSES_API ARTagCameraDS :
	public CCameraDS
{
protected:
	CComPtr<IBaseFilter> m_pARTagFilter;
	CComPtr<IARTagFilter> m_pIARTagFilter;
	CComPtr<IPin> m_pARTagInputPin;	
	CComPtr<IPin> m_pARTagOutputPin;
	CComPtr<IBaseFilter> m_pSmartTee;
	CComPtr<IPin> m_pSmartTeeInputPin;
	CComPtr<IPin> m_pSmartTeeCapturePin;
	CComPtr<IPin> m_pSmartTeePreviewPin;
	//overwrite CCameraDS function
	virtual HRESULT ConnectGraph();
	virtual HRESULT CreateFilters(int nCamID, bool bDisplayProperties, int nWidth, int nHeight);
public:
	ARTagCameraDS(void);
	virtual ~ARTagCameraDS(void);
	virtual void CloseCamera();
	virtual BOOL SetARCallback(IARTagFilter::CallbackFuncPtr pcallback, int argc, void* argv[]);
	virtual BOOL ShowARProp();
};
