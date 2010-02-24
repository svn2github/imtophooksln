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
#include "cv.h"
#include "MSPersist.h"


class ARTagDSFilter :
	public CMuxTransformFilter, public IARTagFilter, public D3DTransformFilterBase,
	public ISpecifyPropertyPages, public CMSPersist
{
private: 
	bool initARSetting(int width, int height, const CMediaType* inputMT);
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
	//from IMSPersist
	virtual HRESULT SaveToFile(WCHAR* path);
	virtual HRESULT LoadFromFile(WCHAR* path);
	virtual HRESULT GetName(WCHAR* name, UINT szName);
	//implement IARTagProperty
	virtual bool setCamera(int xsize, int ysize, double* mat, double* dist_factor,ARFloat nNearClip, ARFloat nFarClip);
	virtual bool getCamera(int& xsize, int &ysize, double* mat, double* dist_factor);
	virtual HRESULT loadCameraFromXMLFile(WCHAR* filename);
	virtual HRESULT loadARConfigFromFile(WCHAR* filename);
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
	virtual bool getbDrawReproPt();
	virtual bool setbDrawReproPt(bool v);

	virtual bool IsReady();
	virtual bool setWorldBasisScale(double v[3]);
	virtual bool getWorldBasisScale(double v[3]);
	virtual BOOL SetCallback(CallbackFuncPtr pfunc, int argc, void* argv[]);
private:
	HRESULT VariantFromString(PCWSTR wszValue, VARIANT &Variant);

	bool ARTag2World3D(const ARMultiEachMarkerInfoT* pMarker, D3DXVECTOR3*& vts, double basisScale[3]);
	bool ARTag2VW(const ARMultiEachMarkerInfoT* pMarker, D3DXVECTOR3*& vts);
protected:
	
	//
	CCritSec m_csWorldBasisScale;
	double m_WorldBasisScale[3];

	bool			 m_bDrawTag;
	bool             m_bDrawReproPt;
	CallbackFuncPtr  m_pCallback;
	int m_callbackArgc;
	void** m_callbackArgv;

	ARToolKitPlus::TrackerMultiMarker *m_ARTracker;
	CCritSec m_csARTracker;
	bool             IsAcceptedType(const CMediaType *pMT);
	//for Override D3DTransformFilterBase
	virtual MS3DDisplay* Create3DDisplay(IDirect3D9* pD3D, int rtWidth, int rtHeight);
	virtual MS3DDisplay* Create3DDisplay(IDirect3DDevice9* pDevice, int rtWidth, int rtHeight);
	virtual HRESULT DoTransform(IMediaSample *pIn, const CMediaType* pInType,
		IMediaSample *pOut, const CMediaType* pOutType);
	virtual HRESULT Transform( IMediaSample *pIn, IMediaSample *pOut);
	HRESULT DrawARTag(IplImage* img, ARMarkerInfo* markinfos, int numMarkinfo);

	D3DXMATRIX m_matIntri;
	HRESULT ShowReprojectImage(IplImage* srcImage, int nDetected, const ARMarkerInfo* detectedMarkers, 
		const ARMultiMarkerInfoT* config, const double* matView, const double* matProj);


public:
	ARTagDSFilter(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData);
	virtual ~ARTagDSFilter();
};

#endif