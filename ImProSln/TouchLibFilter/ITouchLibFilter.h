#pragma once
#include "ITouchListener.h"
#include <string>
using namespace std;
using namespace touchlib;
// {C4454D89-08E8-4ad4-A001-2D1C9A5D62E0}
DEFINE_GUID(IID_ITouchLibFilter, 
			0xc4454d89, 0x8e8, 0x4ad4, 0xa0, 0x1, 0x2d, 0x1c, 0x9a, 0x5d, 0x62, 0xe0);

// {F982AA58-0213-4235-B342-314D853D5CEE}
DEFINE_GUID(CLSID_TouchLibFilter, 
			0xf982aa58, 0x213, 0x4235, 0xb3, 0x42, 0x31, 0x4d, 0x85, 0x3d, 0x5c, 0xee);
// {FBEAA4C2-1F38-4572-9F9E-54A9782EC777}
DEFINE_GUID(CLSID_TouchLibPropPage, 
			0xfbeaa4c2, 0x1f38, 0x4572, 0x9f, 0x9e, 0x54, 0xa9, 0x78, 0x2e, 0xc7, 0x77);



MIDL_INTERFACE("C4454D89-08E8-4ad4-A001-2D1C9A5D62E0")
ITouchLibFilter: public IUnknown
{
public:
	virtual bool ShowConfigWindow(bool bShow);
	virtual void registerListener(ITouchListener *listener);
	virtual void unregisterListener(ITouchListener *listener);
	virtual bool IsOSCConnected();
	virtual bool ConnectOSC(char* ipaddress, int port);
	virtual bool DisConnectOSC();
	virtual bool GetIPAddress(char* outIpAddress);
	virtual int GetPort();
	virtual bool IsTouchReady();
	virtual bool ClearBackground();
	virtual bool setStartTracking(bool bStart);
	virtual bool getStartTracking(bool& bStart);
	virtual bool getDrawFingers();
	virtual bool setDrawFingers(bool drawing);
	virtual bool getDrawROI();
	virtual bool setDrawROI(bool drawing);

	virtual bool SetBGThreshold(int threshold);
	virtual bool GetBGThreshold(int& threshold);
	virtual bool SetSimpleHighPassBlur(int blur);
	virtual bool GetSimpleHighPassBlur(int& blur);
	virtual	bool SetSimpleHighPassDeNoise(int deNoise);
	virtual bool GetSimpleHighPassDeNoise(int& deNoise);
	virtual bool SetScaleLevel(int level);
	virtual bool GetScaleLevel(int& level);
	virtual bool SetRectifyLevel(int level);
	virtual bool GetRectifyLevel(int& level);
	virtual bool GetbFlipY();
	virtual bool SetbFlipY(bool v);

	virtual HRESULT SaveToFile(WCHAR* filename);
	virtual HRESULT LoadFromFile(WCHAR* filename);
	virtual HRESULT GetName(WCHAR* name, UINT szName);

	virtual bool GetIsSkipBGRemove();
	virtual bool SetIsSKipBGRemove(bool isSkipBG);
};
