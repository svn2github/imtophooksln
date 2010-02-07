#pragma once
#include "ITouchListener.h"
#include <string>
using namespace std;
using namespace touchlib;
// {C4454D89-08E8-4ad4-A001-2D1C9A5D62E0}
DEFINE_GUID(IID_ITouchLibFilter, 
			0xc4454d89, 0x8e8, 0x4ad4, 0xa0, 0x1, 0x2d, 0x1c, 0x9a, 0x5d, 0x62, 0xe0);


MIDL_INTERFACE("C4454D89-08E8-4ad4-A001-2D1C9A5D62E0")
ITouchLibFilter: public IUnknown
{
public:
	virtual bool ShowConfigWindow(bool bShow);
	virtual void registerListener(ITouchListener *listener);
	virtual void unregisterListener(ITouchListener *listener);
	virtual bool IsOSCConnected();
	virtual bool ConnectOSC(string ipaddress, int port);
	virtual bool DisConnectOSC();
	virtual bool GetIPAddress(string& outIpAddress);
	virtual int GetPort();
	virtual bool IsTouchReady();
	virtual bool ClearBackground();
	virtual bool setStartTracking(bool bStart);
	virtual bool getStartTracking(bool& bStart);
	virtual bool getDrawFingers();
	virtual bool setDrawFingers(bool drawing);
};
