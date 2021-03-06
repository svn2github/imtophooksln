#pragma once
// {6B51D25F-D02F-6C86-8BD2-BD58596CF157}
DEFINE_GUID(IID_IImProLogicFilter, 
			0x6b51d25f, 0xd02f, 0x6c86, 0x8b, 0xd2, 0xbd, 0x58, 0x59, 0x6c, 0xf1, 0x57);
// {10DCD17F-81A2-AF0F-5C84-FF4F88042F48}
DEFINE_GUID(CLSID_ImProLogicFilter, 
			0x10dcd17f, 0x81a2, 0xaf0f, 0x5c, 0x84, 0xff, 0x4f, 0x88, 0x04, 0x2f, 0x48B);
// {035B1C2F-FAB9-A20C-781F-533CA4B2A8DC}
DEFINE_GUID(CLSID_ImProLogicFilterProp, 
			0x035b1c2f, 0xfab9, 0xa20c, 0x78, 0x1f, 0x53, 0x3c, 0xa4, 0xb2, 0xa8, 0xdc);



MIDL_INTERFACE("6B51D25F-D02F-6C86-8BD2-BD58596CF157")
IImProLogicFilter: public IUnknown
{
public:
	virtual BOOL IsOSCConnected();
	virtual HRESULT ConnectOSC(char* ipaddress, int port);
	virtual HRESULT DisConnectOSC();
	virtual HRESULT GetIPAddress(char* outIpAddress);
	virtual int GetPort();
};
