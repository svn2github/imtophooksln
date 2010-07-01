#pragma once

#include "IImProLogicFilter.h"
#include "dshow.h"
#include "Streams.h"
#include <initguid.h>
#include "combase.h"
#include "GSDXFilterBase.h"
#include "GSDXMuxFilter.h"
#include "IGSPersist.h"
#include "IGSARTagLayoutFilter.h"
#include "MyMediaSample.h"
#include "ARToolKitPlus/TrackerMultiMarker.h"
#include "pointTrans.h"
#include "IGSMaskFilter.h"
#include "OSCSender.h"
using namespace ARToolKitPlus;
using namespace GSARLayoutNS;
using namespace GSMaskNS;
#define NUMCAM 4

class ImProLogicFilter :
	public GSMuxFilter, public IImProLogicFilter,
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

	//implement IImProLogicFilter
private:
	bool GetARTag2DRect(fRECT* retRect, const ARMultiEachMarkerInfoT* pMarker);
	bool ARTag2VW(const ARMultiEachMarkerInfoT* pMarker, D3DXVECTOR3*& vts);

	IPin* GetWarpFromARPin(UINT idx);
	IPin* GetARStrategyPin();

	HRESULT GetWarpFromAR_PinIndex(const IPin* pPin, UINT& idx);
	HRESULT GetARResult_PinIndex(const IPin* pPin, UINT& idx);

protected:
	double m_RANSIC_Threshold;
	BOOL m_dirtyWarpFromAR[NUMCAM];
	BOOL m_dirtyLowResMask;
	BOOL m_dirtyARStrategy;
	/*
	CCritSec m_csDirtyWarpFromAR[NUMCAM];
	CCritSec m_csDirtyLowResMask;
	CCritSec m_csDirtyARStrategy;
	CCritSec m_csMatCam2VW[NUMCAM];
	CCritSec m_csMatPro2VW[NUMCAM];
	CCritSec m_csTouchResult;
	CCritSec m_csProjCoord;
	*/
	CCritSec m_csState;


	D3DXMATRIX* m_matPro2VW[NUMCAM];
	D3DXMATRIX* m_matCam2VW[NUMCAM];
	GSARLayoutStartegyData* m_pARStrategyData;
	ForegroundRegion* m_pTouchResult;
	GSMaskConfigData* m_pMaskSendData;
	
	OSCSender* m_pOSCSender;



	// function for projector coordinate to virtual world
	ProjectorTrans2World* projCoord;
	virtual HRESULT GetProjCorner(CvMat* camPoints, CvMat* worldPoints); 
	int tableHeight;
	int tableWidth;
	CvMat* W2CMat ;

	//////////
	HRESULT SetDirty_WarpFromAR(UINT idx, BOOL bDirty);
	HRESULT SetDirty_LowResMask(BOOL bDirty);
	HRESULT SetDirty_ARStrategy(BOOL bDirty);

	virtual HRESULT CreatePins();
	
	static HRESULT __stdcall PreReceive_ARResultFromTable(void* self, IMediaSample *pSample, const IPin* pReceivePin, IMediaSample*& pOutSample);

	static HRESULT __stdcall PreReceive_ARResult(void* self, IMediaSample *pSample, const IPin* pReceivePin, IMediaSample*& pOutSample);
	static HRESULT __stdcall PreReceive_TouchResult(void* self, IMediaSample *pSample, const IPin* pReceivePin, IMediaSample*& pOutSample);

	static HRESULT __stdcall FillBuffer_WarpFromAR(void* self, IMediaSample *pSample, IPin* pPin);
	static HRESULT __stdcall FillBuffer_LowResMask(void* self, IMediaSample *pSample, IPin* pPin);
	static HRESULT __stdcall FillBuffer_ARStrategy(void* self, IMediaSample *pSample, IPin* pPin);

	HRESULT SendBoundingBox2OSCSender();
	HRESULT SendDetectedARFromTable2OSCSender(float* tagRects, INT* tagIDs, UINT nTagRect);
public:
	ImProLogicFilter(IUnknown * pOuter, HRESULT *phr, BOOL ModifiesData);
	virtual ~ImProLogicFilter();

	virtual BOOL IsOSCConnected();
	virtual HRESULT ConnectOSC(char* ipaddress, int port);
	virtual HRESULT DisConnectOSC();
	virtual HRESULT GetIPAddress(char* outIpAddress);
	virtual int GetPort();
};
