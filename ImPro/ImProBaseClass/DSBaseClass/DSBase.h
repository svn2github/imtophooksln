#pragma once
#include "DSBaseClass.h"
#include "dshow.h"
#include "Streams.h"
#include <initguid.h>
#include "combase.h"

class DSBASECLASSES_API CDSBase
{
protected:
	CComPtr<IGraphBuilder> m_pGraph;
	CComPtr<IMediaControl> m_pMediaControl;
	CComPtr<IMediaEvent> m_pMediaEvent;	
	CComPtr<IVideoWindow> m_pVideoWindow;

protected:
	virtual HRESULT ConfigFilters();
	virtual HRESULT ConnectGraph();
	virtual HRESULT CreateGraph(IGraphBuilder** ppGraph);
	virtual HRESULT CreateFilters();
	virtual HRESULT ShowFilterProp(IUnknown* pFilter);

public:
	CDSBase();
	virtual ~CDSBase();
	virtual HRESULT InitDS();
	virtual HRESULT UnInitDS();
	virtual HRESULT Play();
	virtual HRESULT Stop();
	virtual HRESULT Pause();
	virtual HRESULT SaveGraphFile(WCHAR *wszPath);
	virtual HRESULT SetVideoWindow(HWND hwnd);

};


