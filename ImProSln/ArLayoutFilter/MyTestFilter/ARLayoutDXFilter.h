#pragma once

#include "dshow.h"
#include "Streams.h"
#include <initguid.h>
#include "combase.h"
#include "IARLayoutFilter.h"
#include "CMuxTransformFilter.h"
#include "MSSD3DClass.h"
#include "D3DTransformFilterBase.h"
#include "ARToolKitPlus/TrackerMultiMarker.h"
#include "MyMediaSample.h"
#include <vector>
#include "cv.h"
using namespace std;
using namespace ARToolKitPlus;

class ARLayoutDXFilter :
	public CMuxTransformFilter, public IARLayoutDXFilter, ISpecifyPropertyPages,
	public D3DTransformFilterBase, D3DBaseFilter
{
public:
	static CUnknown *WINAPI CreateInstance(LPUNKNOWN punk, HRESULT *phr);
	DECLARE_IUNKNOWN;
	STDMETHODIMP NonDelegatingQueryInterface(REFIID iid, void **ppv);
	STDMETHODIMP Notify (IBaseFilter *pSender, Quality q);
	STDMETHODIMP     GetPages(CAUUID *pPages);

	//Derive from CMuxTransformFilter
	virtual HRESULT CreatePins();
	virtual HRESULT Receive(IMediaSample *pSample, const IPin* pReceivePin);
	virtual HRESULT FillBuffer(IMediaSample *pSamp, IPin* pPin);
	virtual HRESULT GetMediaType(int iPosition, const IPin* pOutPin, __inout CMediaType *pMediaType);
	virtual HRESULT CheckOutputType(const CMediaType* mtOut, const IPin* pPin);
	virtual HRESULT CheckInputType(const CMediaType* mtIn, const IPin* pPin);
	virtual HRESULT DecideBufferSize(
		IMemAllocator * pAllocator, const IPin* pOutPin,
		__inout ALLOCATOR_PROPERTIES *pprop);
	virtual HRESULT StartStreaming();

	virtual BOOL SetFrameRate(float fps);
	virtual float GetFrameRate();
	//Derive from D3DTransformFilter
	virtual MS3DDisplay* Create3DDisplay(IDirect3D9* pD3D, int rtWidth, int rtHeight);
	virtual MS3DDisplay* Create3DDisplay(IDirect3DDevice9* pDevice, int rtWidth, int rtHeight);
	//from D3DBaseFilter
	virtual HRESULT QueryD3DDevice(IDXBasePin* pPin, IDirect3DDevice9*& outDevice);
	virtual HRESULT QueryD3DDeviceCS(IDXBasePin* pPin, CCritSec*& cs);
protected:
	virtual float GetFrameRateLimit(IPin* pPin);
protected:
	CCritSec m_csARMarker;
	ARMultiEachMarkerInfoT* m_ARMarkers;
	int m_numMarker;
	float m_minMarkerWidth;
	CCritSec m_csARStrategyData;
	ARLayoutStartegyData* m_pARStrategyData;
	CCritSec m_csFrameRate;
	float m_FrameRate;
	bool m_bLayoutChange;

	CCritSec m_csROIRects;
	IplImage* m_pROIImage;
	vector<fRECT> m_ROIRects;
	vector<vector<int>> m_TagIntersectTable;
	vector<fRECT> m_allMarkerRects;

	bool generateAllMarkerRect(ARMultiEachMarkerInfoT* ARMarkers, int numMarker, 
		vector<fRECT>& allMarkerRects);
	bool generateIntersectTable(ARMultiEachMarkerInfoT* ARMarkers, int numMarker,
		vector<vector<int>>& table);
	bool sendConfigData();
	bool sendROIData();
public:
	ARLayoutDXFilter(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData);
	virtual ~ARLayoutDXFilter();
	virtual bool LoadConfigFromFile(WCHAR* filename);
	virtual bool SaveConfigToFile(WCHAR* filename);
	virtual bool DecideLayout(fRECT* camRects, UINT numCamRect,
		fRECT* fingerRects, UINT numFingerRects, bool& bLayoutChanged, float fingerExtend = 0.07);
	virtual bool initARMarkers(UINT numLevel = 2, UINT intMarkerBits = 8, UINT intBorderBits = 2, float intWidthBits = 80);

	virtual int GetNumMarker();
	virtual bool SetMarkerVisible(int idx, bool bVisible);
	virtual bool SetMarkerVisibleByID(int id, bool bVisible);
	virtual int GetMarkerID(int idx);
private:
	bool GetARTag2DRect(fRECT* retRect, const ARMultiEachMarkerInfoT* pMarker, float fScale = 1.0);
	ARMultiEachMarkerInfoT* GetARMarker(int id);
	HRESULT ReceiveConfig(IMediaSample *pSample, const IPin* pReceivePin);
	HRESULT ComputeROIs(const ARMultiMarkerInfoT* pMarkerConfig);
	HRESULT CreateROIImage(int width, int height);
	HRESULT GetROIData(ROIData*& roiData);


	HRESULT GetARLayoutConfig(ARMultiEachMarkerInfoT* ARConfig);
	int GetARLayoutSize() ;

};