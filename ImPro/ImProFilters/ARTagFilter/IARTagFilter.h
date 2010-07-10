#pragma once
#include <InitGuid.h>
#include "ARToolKitPlus/TrackerMultiMarker.h"
using namespace ARToolKitPlus;

DEFINE_GUID(CLSID_ARTagDSFilter, 
			0x889c4fa1, 0xfb51, 0x4118, 0x80, 0xb8, 0xc0, 0x3f, 0x51, 0x4a, 0xab, 0x3);

DEFINE_GUID(IID_IARTagDSFilter, 
			0xe47942df, 0xb438, 0x4d85, 0xa9, 0xec, 0x7b, 0x56, 0x55, 0xe6, 0x8d, 0xfd);

// {4AE740F1-4AB8-4436-B346-189DD369B965}
DEFINE_GUID(CLSID_ARTagCameraProperty, 
			0x4ae740f1, 0x4ab8, 0x4436, 0xb3, 0x46, 0x18, 0x9d, 0xd3, 0x69, 0xb9, 0x65);

// {3333AFC9-B73B-440b-85FF-3656E4457958}
DEFINE_GUID(CLSID_ARTagProperty, 
			0x3333afc9, 0xb73b, 0x440b, 0x85, 0xff, 0x36, 0x56, 0xe4, 0x45, 0x79, 0x58);


MIDL_INTERFACE("E47942DF-B438-4d85-A9EC-7B5655E68DFD")
IARTagFilter: public IUnknown
{
public:
	typedef BOOL (__stdcall* CallbackFuncPtr)(int numDetected, const ARMarkerInfo* markinfos, const ARMultiMarkerInfoT* config, const double* matView, const double* matProj, int argc, void* argv[]);
	virtual BOOL SetCallback(CallbackFuncPtr pfunc, int argc, void* argv[]) = 0;

	virtual bool IsReady() = 0;
	virtual bool setMarkInfo(ARMultiEachMarkerInfoT *marker, int numMarker) = 0;
	virtual bool setCamera(int xsize, int ysize, double* mat, double* dist_factor,double nNearClip, double nFarClip) = 0;
	virtual bool getCamera(int& xsize, int &ysize, double* mat, double* dist_factor) = 0;
	virtual HRESULT loadCameraFromXMLFile(WCHAR* filename) = 0;
	virtual HRESULT loadARConfigFromFile(WCHAR* filename) = 0;
	virtual bool setBorderWidth(double borderWidth) = 0;
	virtual double getBorderWidth() = 0;
	virtual bool setThreshold(int t) = 0;
	virtual int getThreshold() = 0;

	virtual bool setConfThreshold(float v) = 0;
	virtual float getConfThreshold() = 0;
	virtual bool setAutoThreshold(bool nEnable) = 0;
	virtual bool getAutoThreshold() = 0;
	virtual bool setMultiThreshold(bool nEnable) = 0;
	virtual bool getMultiThreshold() = 0;

	virtual bool setUndistortionMode(int mode) = 0;
	virtual int getUndistortionMode() = 0;
	virtual bool setMarkerMode(int mode) = 0;
	virtual int getMarkerMode() = 0;
	virtual bool setPoseEstimator(int rpp) = 0;
	virtual int getPoseEstimator() = 0;
	virtual bool getbDrawTag() = 0;
	virtual bool setbDrawTag(bool v) = 0;
	virtual bool getbDrawReproPt() = 0;
	virtual bool setbDrawReproPt(bool v) = 0;
	virtual bool getbGuessPose() = 0;
	virtual bool setbGuessPose(bool v) = 0;
	virtual bool getbUseKalman() = 0;
	virtual bool setbUseKalman(bool v) = 0;
	virtual bool getbMaskTag() = 0;
	virtual bool setbMaskTag(bool v) = 0;
	virtual float getMaskScale() = 0;
	virtual bool setMaskScale(float v) = 0;

	virtual BOOL GetMeasureNoiseCov(float& fNoiseCov) = 0;
	virtual BOOL SetMeasureNoiseCov(float fNoiseCov) = 0;

	virtual bool setWorldBasisScale(double v[3]) = 0;
	virtual bool getWorldBasisScale(double v[3]) = 0;

	
	virtual HRESULT GetIPAddress(char* ipaddress, UINT szBuf) = 0;
	virtual HRESULT GetPort(UINT& port) = 0;
	virtual BOOL IsOSCConnected() = 0;
	virtual HRESULT ConnectOSC(char* ipaddress, int port) = 0;
	virtual HRESULT DisConnectOSC() = 0;
};