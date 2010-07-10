#ifndef _ARTAGDSFILTER_H
#define  _ARTAGDSFILTER_H

#include "dshow.h"
#include "Streams.h"
#include <initguid.h>
#include "combase.h"
#include "IARTagFilter.h"
#include "ARToolKitPlus/TrackerMultiMarker.h"
#include "D3DTransformFilterBase.h"
#include "CMuxTransformFilter.h"
#include "cv.h"
#include "IGSPersist.h"
#include "GSTUIOSender.h"

class ARTagDSFilter :
	public CMuxTransformFilter, public IARTagFilter,
	public ISpecifyPropertyPages, public IGSPersist
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
	//from IGSPersist
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
	virtual bool setAutoThreshold(bool nEnable);
	virtual bool getAutoThreshold();
	virtual bool setMultiThreshold(bool nEnable);
	virtual bool getMultiThreshold();
	virtual int getAutoThresholdRetryNum();
	virtual bool setAutoThresholdRetryNum(int nRetry);

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
	virtual bool getbGuessPose();
	virtual bool setbGuessPose(bool v);
	virtual bool getbUseKalman();
	virtual bool setbUseKalman(bool v);
	virtual bool getbMaskTag();
	virtual bool setbMaskTag(bool v);

	virtual float getMaskScale();
	virtual bool setMaskScale(float v);

	virtual BOOL GetMeasureNoiseCov(float& fNoiseCov);
	virtual BOOL SetMeasureNoiseCov(float fNoiseCov);

	virtual bool IsReady();
	virtual bool setWorldBasisScale(double v[3]);
	virtual bool getWorldBasisScale(double v[3]);
	virtual BOOL SetCallback(CallbackFuncPtr pfunc, int argc, void* argv[]);

	virtual HRESULT GetIPAddress(char* ipaddress, UINT szBuf);
	virtual HRESULT GetPort(UINT& port);
	virtual BOOL IsOSCConnected();
	virtual HRESULT ConnectOSC(char* ipaddress, int port);
	virtual HRESULT DisConnectOSC();
private:
	HRESULT VariantFromString(PCWSTR wszValue, VARIANT &Variant);

	bool ARTag2World3D(const ARMultiEachMarkerInfoT* pMarker, D3DXVECTOR3*& vts, double basisScale[3]);
	bool ARTag2VW(const ARMultiEachMarkerInfoT* pMarker, D3DXVECTOR3*& vts);
protected:
	GSTUIOSender m_TUIOSender;
	//
	CCritSec m_csWorldBasisScale;
	double m_WorldBasisScale[3];

	bool             m_bGuessPose;
	bool			 m_bDrawTag;
	bool             m_bDrawReproPt;
	bool             m_bMaskTag;
	float            m_maskScale;

	CallbackFuncPtr  m_pCallback;
	int m_callbackArgc;
	void** m_callbackArgv;

	UINT m_imgW, m_imgH;

	ARToolKitPlus::TrackerMultiMarker *m_ARTracker;
	CCritSec m_csARTracker;
	bool             IsAcceptedType(const CMediaType *pMT);
	//for Override D3DTransformFilterBase
	virtual HRESULT DoTransform(IMediaSample *pIn, const CMediaType* pInType,
		IMediaSample *pOut, const CMediaType* pOutType);
	virtual HRESULT Transform( IMediaSample *pIn, IMediaSample *pOut);
	HRESULT DrawARTag(IplImage* img, ARMarkerInfo* markinfos, int numMarkinfo);
	HRESULT MaskTag(IplImage* img, ARMarkerInfo* markinfos, int numMarkinfo);
	D3DXMATRIX m_matIntri;
	HRESULT ShowReprojectImage(IplImage* srcImage, int nDetected, const ARMarkerInfo* detectedMarkers, 
		const ARMultiMarkerInfoT* config, const double* matView, const double* matProj);

	HRESULT SendTUIO(ARMarkerInfo* pMarkinfos, UINT numDetected);
public:
	ARTagDSFilter(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData);
	virtual ~ARTagDSFilter();

};

#endif