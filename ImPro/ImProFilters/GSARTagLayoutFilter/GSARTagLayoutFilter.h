#pragma once

#include "IGSARTagLayoutFilter.h"
#include "dshow.h"
#include "Streams.h"
#include <initguid.h>
#include "combase.h"
#include "GSDXFilterBase.h"
#include "GSDXMuxFilter.h"
#include "IGSPersist.h"
#include "MyMediaSample.h"
#include "MyARTagMediaSample.h"
#include "cv.h"
#define NUMARTAG 512

using namespace GSARLayoutNS;

ARLayoutConfigData* GSARTagLayout2ARLayoutConfig(GSARTagLayout* inData);

class GSARTagLayoutFilter :
	public GSDXMuxFilter, public IGSARTagLayoutFilter,
	public ISpecifyPropertyPages, public IGSPersist
{
public:
	static CUnknown *WINAPI CreateInstance(LPUNKNOWN punk, HRESULT *phr);

	//for COM interface 
	STDMETHODIMP NonDelegatingQueryInterface(REFIID iid, void **ppv);
	DECLARE_IUNKNOWN;

	//implement DShow Property Page
	STDMETHODIMP     GetPages(CAUUID *pPages);
	//from CMSPersist
	virtual HRESULT SaveToFile(WCHAR* path);
	virtual HRESULT LoadFromFile(WCHAR* path);
	virtual HRESULT GetName(WCHAR* name, UINT szName);

protected:
	float m_FPSLimit;
	CCritSec m_csRenderPara;
	UINT m_bufW, m_bufH;

	CCritSec m_csStrategyData;
	GSARLayoutStartegyData* m_pStrategyData;
	
	CCritSec m_csLayoutChange;
	BOOL m_bLayoutChange;

	CCritSec m_csROIRects;
	vector<fRECT> m_ROIRects;

	IplImage* m_pROIImg;
	bool sendROIData();
	HRESULT SendLayoutData();
	BOOL GetLayoutChanged();
	void SetLayoutChanged(BOOL bChanged);
	HRESULT GetROIData(ROIData*& roiData);
	HRESULT ComputeROIs();
	//from GSDXMuxFilter Interface
	virtual HRESULT _CreatePins(GSFILTER_INPUTPIN_DESC* inDesc, UINT szIn, GSFILTER_OUTPUTPIN_DESC* outDesc, UINT szOut, GSFILTER_STREAMPIN_DESC* streamDesc, UINT szStream );
	virtual HRESULT CreatePins();
	virtual HRESULT InitFilter();
	virtual HRESULT GetEffectFilePath(WCHAR* szPath, UINT szSize);
	virtual float GetFrameRateLimit(IPin* pPin);

	static HRESULT __stdcall OnFillBuffer(void* self, IMediaSample *pSample, IPin* pPin);
	static HRESULT __stdcall PreReceive_ReceiveConfig(void* self, IMediaSample *pSample, const IPin* pReceivePin, IMediaSample*& pOutSample);
	
	virtual GS3DDisplay* Create3DDisplay(UINT bufW, UINT bufH);
	virtual GS3DDisplay* Create3DDisplay(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext, IDXGISwapChain* pSwapChain);

public:
	GSARTagLayoutFilter(IUnknown * pOuter, HRESULT *phr, BOOL ModifiesData);
	virtual ~GSARTagLayoutFilter();

	virtual HRESULT DecideLayout(GSBoundingBox2D* camRects, UINT numCamRect,
		GSBoundingBox2D* fingerRects, UINT numFingerRects, BOOL& bLayoutChanged, float fingerExtend = 0.07);
	
	virtual HRESULT initARLayout(UINT numLevel = 2, UINT intMarkerBits = 8, UINT intBorderBits = 2, float intWidthBits = 80);
	virtual int GetNumMarker();
	virtual HRESULT SetMarkerVisible(int idx, BOOL bVisible);
	virtual HRESULT SetMarkerVisibleByID(int id, BOOL bVisible);
	virtual int GetMarkerID(int idx);
	virtual float GetBlackLevel();
	virtual HRESULT SetBlackLevel(float level);

	virtual HRESULT SetFrameRate(float fps);
	virtual float GetFrameRate();

};

