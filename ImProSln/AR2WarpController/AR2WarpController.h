#pragma once
#include "IAR2WarpController.h"
#include "CMuxTransformFilter.h"
#include <d3dx9.h>
#include "cv.h"
#include "MyMediaSample.h"
#include "ARToolKitPlus/TrackerMultiMarker.h"
#include "pointTrans.h"
#include "..\OSCSender\OSCSender.h"
using namespace ARToolKitPlus;

#define NUMCAM 3
// {F0272060-6BF7-4714-AB76-90FB089BB99A}
DEFINE_GUID(CLSID_AR2WarpController, 
			0xf0272060, 0x6bf7, 0x4714, 0xab, 0x76, 0x90, 0xfb, 0x8, 0x9b, 0xb9, 0x9a);

class AR2WarpController :
	public CMuxTransformFilter, public IAR2WarpController, public ISpecifyPropertyPages
{
public:
	static CUnknown *WINAPI CreateInstance(LPUNKNOWN punk, HRESULT *phr);

	//for COM interface 
	STDMETHODIMP NonDelegatingQueryInterface(REFIID iid, void **ppv);
	DECLARE_IUNKNOWN;

	//implement CMuxTransformFilter Interface
	virtual HRESULT Receive(IMediaSample *pSample, const IPin* pReceivePin);
	virtual HRESULT ReceiveARResult(IMediaSample *pSample, const IPin* pReceivePin);
	virtual HRESULT ReceiveTouchResult(IMediaSample *pSample, const IPin* pReceivePin);
	virtual HRESULT CreatePins();
	virtual HRESULT CheckInputType(const CMediaType* mtIn, const IPin* pPin);
	virtual HRESULT CheckOutputType(const CMediaType* mtOut, const IPin* pPin);
	virtual HRESULT DecideBufferSize(IMemAllocator * pAllocator, const IPin* pOutPin,
		__inout ALLOCATOR_PROPERTIES *pprop);
	virtual HRESULT GetMediaType(int iPosition, const IPin* pOutPin, __inout CMediaType *pMediaType);
	virtual HRESULT CompleteConnect(PIN_DIRECTION direction, const IPin* pMyPin, const IPin* pOtherPin);
	//implement DShow Property Page
	STDMETHODIMP     GetPages(CAUUID *pPages);


public:
	AR2WarpController(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData);
	virtual ~AR2WarpController();
	virtual bool IsOSCConnected();
	virtual bool ConnectOSC(string ipaddress, int port);
	virtual bool DisConnectOSC();
	virtual bool GetIPAddress(string& outIpAddress);
	virtual int GetPort();


protected:
	double  m_RANSIC_Threshold;
	CCritSec m_csMatCam2VW[NUMCAM];
	CCritSec m_csMatPro2VW[NUMCAM];
	CCritSec m_csFGList;
	D3DXMATRIX* m_matCam2VW[NUMCAM];
	D3DXMATRIX* m_matPro2VW[NUMCAM];
	OSCSender* m_pOSCSender;


	ForegroundRegion* m_pFGList;
	virtual CCritSec* GetReceiveCS(IPin* pPin);
	virtual bool GetARTag2DRect(fRECT* retRect, const ARMultiEachMarkerInfoT* pMarker);
	virtual bool ARTag2VW(const ARMultiEachMarkerInfoT* pMarker, D3DXVECTOR3*& vts);
	virtual bool SendWarpConfig(int camIDx);
	virtual bool SendARLayoutStartegyData();
	virtual bool SendBoundingBox2OSCSender();
	// function for projector coordinate to virtual world
	
	ProjectorTrans2World* projCoord ;
	virtual HRESULT GetProjHomo(CvMat* camPoints, CvMat* worldPoints); 

	IPin* GetARResultPin(int idx);
	IPin* GetWarpConfigPin(int idx);
	IPin* GetARLayoutPin();
};
