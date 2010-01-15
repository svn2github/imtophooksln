#ifndef _ARTAGDSFILTER_H
#define  _ARTAGDSFILTER_H

#include "dshow.h"
#include "Streams.h"
#include <initguid.h>
#include "combase.h"
#include "ARToolKitPlus/TrackerMultiMarker.h"
#include "ARTagD3DDisplay.h"
#include "D3DTransformFilterBase.h"
#include "CMuxTransformFilter.h"

DEFINE_GUID(CLSID_ARTagDSFilter, 
			0x889c4fa1, 0xfb51, 0x4118, 0x80, 0xb8, 0xc0, 0x3f, 0x51, 0x4a, 0xab, 0x3);


class ARTagDSFilter :
	public CMuxTransformFilter, public IARTagFilter, public D3DTransformFilterBase,
	public ISpecifyPropertyPages
{

public:
	static CUnknown *WINAPI CreateInstance(LPUNKNOWN punk, HRESULT *phr);

	//for COM interface 
	
	STDMETHODIMP NonDelegatingQueryInterface(REFIID iid, void **ppv);
	DECLARE_IUNKNOWN;
	//implement CMuxTransformFilter Method
	virtual HRESULT Receive(IMediaSample *pSample, const IPin* pReceivePin);
	virtual HRESULT CreatePins();
	virtual HRESULT CheckInputType(const CMediaType* mtIn, const IPin* pPin);
	virtual HRESULT CheckOutputType(const CMediaType* mtOut, const IPin* pPin);
	virtual HRESULT DecideBufferSize(IMemAllocator * pAllocator, const IPin* pOutPin,
		__inout ALLOCATOR_PROPERTIES *pprop);
	virtual HRESULT GetMediaType(int iPosition, const IPin* pOutPin, __inout CMediaType *pMediaType);
	virtual HRESULT CompleteConnect(PIN_DIRECTION direction, const IPin* pMyPin, const IPin* pOtherPin);

	//implement DShow Property Page
	STDMETHODIMP     GetPages(CAUUID *pPages);
	//implement IARTagProperty
	virtual bool setCamera(int xsize, int ysize, double* mat, double* dist_factor,ARFloat nNearClip, ARFloat nFarClip);

	virtual bool getCamera(int& xsize, int &ysize, double* mat, double* dist_factor);
	virtual bool setMarkInfo(ARMultiEachMarkerInfoT *marker, int numMarker);

	virtual bool setBorderWidth(double borderWidth);
	virtual double getBorderWidth();
	virtual bool setThreshold(int t);
	virtual int getThreshold();
	virtual bool setConfThreshold(float v);
	virtual float getConfThreshold();

	virtual bool setUndistortionMode(int mode);
	virtual int getUndistortionMode();
	virtual bool setMarkerMode(int mode);
	virtual int getMarkerMode();
	virtual bool setPoseEstimator(int rpp);
	virtual int getPoseEstimator();
	virtual bool getbDrawTag();
	virtual bool setbDrawTag(bool v);
	virtual bool IsReady();

	virtual BOOL SetCallback(CallbackFuncPtr pfunc);

protected:

	//
	bool			 m_bDrawTag;
	CallbackFuncPtr  m_pCallback;
	ARToolKitPlus::TrackerMultiMarker *m_ARTracker;

	bool             IsAcceptedType(const CMediaType *pMT);
	//for Override D3DTransformFilterBase
	virtual MS3DDisplay* Create3DDisplay(HWND hWndD3D,IDirect3D9* pD3D, int rtWidth, int rtHeight);
	virtual HRESULT DoTransform(IMediaSample *pIn, const CMediaType* pInType);
	virtual HRESULT Transform( IMediaSample *pIn);
public:
	ARTagDSFilter(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData);
	virtual ~ARTagDSFilter();
};

#endif