#pragma once
#include "oaidl.h"
#include "ocidl.h"
#include <atlbase.h>
#include "dshow.h"

class CDSBase
{
protected:
	CComPtr<IGraphBuilder> m_pGraph;
	CComPtr<IMediaControl> m_pMediaControl;
	CComPtr<IMediaEvent> m_pMediaEvent;	
	CComPtr<IVideoWindow> m_pVideoWindow;

protected:
	virtual bool InitDS();
	virtual bool UnInitDS();

	virtual HRESULT ConfigFilters();
	virtual HRESULT ConnectGraph();
	virtual HRESULT CreateGraph(IGraphBuilder** ppGraph);
	virtual HRESULT CreateFilters();
	virtual HRESULT ShowFilterProp(IUnknown* pFilter);

public:
	CDSBase();
	virtual ~CDSBase();

	virtual HRESULT Play();
	virtual HRESULT Stop();
	virtual HRESULT Pause();
	virtual HRESULT SaveGraphFile(WCHAR *wszPath);
	virtual HRESULT SetVideoWindow(HWND hwnd);

};


