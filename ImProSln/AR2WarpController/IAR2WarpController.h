#pragma once
#include <string>
using namespace std;
// {88108F51-8473-4d59-A96E-79D1AC244018}
DEFINE_GUID(IID_IAR2WarpController, 
			0x88108f51, 0x8473, 0x4d59, 0xa9, 0x6e, 0x79, 0xd1, 0xac, 0x24, 0x40, 0x18);

MIDL_INTERFACE("88108F51-8473-4d59-A96E-79D1AC244018")
IAR2WarpController: public IUnknown
{
public:
	virtual bool IsOSCConnected();
	virtual bool ConnectOSC(string ipaddress, int port);
	virtual bool DisConnectOSC();
	virtual bool GetIPAddress(string& outIpAddress);
	virtual int  GetPort();
};

