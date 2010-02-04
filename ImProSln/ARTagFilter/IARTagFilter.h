#pragma once
#include "ARToolKitPlus/TrackerMultiMarker.h"
using namespace ARToolKitPlus;
DEFINE_GUID(IID_IARTagDSFilter, 
			0xe47942df, 0xb438, 0x4d85, 0xa9, 0xec, 0x7b, 0x56, 0x55, 0xe6, 0x8d, 0xfd);

MIDL_INTERFACE("E47942DF-B438-4d85-A9EC-7B5655E68DFD")
IARTagFilter: public IUnknown
{
public:
	typedef BOOL (__stdcall* CallbackFuncPtr)(int numDetected, const ARMarkerInfo* markinfos, const double* matView, const double* matProj);
	virtual BOOL SetCallback(CallbackFuncPtr pfunc);

	virtual bool IsReady();
	virtual bool setMarkInfo(ARMultiEachMarkerInfoT *marker, int numMarker);
	virtual bool setCamera(int xsize, int ysize, double* mat, double* dist_factor,double nNearClip, double nFarClip);
	virtual bool getCamera(int& xsize, int &ysize, double* mat, double* dist_factor);
	virtual HRESULT loadCameraFromXMLFile(WCHAR* filename);
	virtual HRESULT loadARConfigFromFile(WCHAR* filename);
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

	virtual bool setWorldBasisScale(double v[3]);
	virtual bool getWorldBasisScale(double v[3]);
};