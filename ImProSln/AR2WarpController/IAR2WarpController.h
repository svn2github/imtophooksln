#pragma once
#include <string>
using namespace std;
// {88108F51-8473-4d59-A96E-79D1AC244018}
DEFINE_GUID(IID_IAR2WarpController, 
			0x88108f51, 0x8473, 0x4d59, 0xa9, 0x6e, 0x79, 0xd1, 0xac, 0x24, 0x40, 0x18);
// {F0272060-6BF7-4714-AB76-90FB089BB99A}
DEFINE_GUID(CLSID_AR2WarpController, 
			0xf0272060, 0x6bf7, 0x4714, 0xab, 0x76, 0x90, 0xfb, 0x8, 0x9b, 0xb9, 0x9a);

// {A3A24F60-5604-46f2-B6CA-B23F24E5E052}
DEFINE_GUID(CLSID_AR2WarpControllerPropertyPage, 
			0xa3a24f60, 0x5604, 0x46f2, 0xb6, 0xca, 0xb2, 0x3f, 0x24, 0xe5, 0xe0, 0x52);

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

