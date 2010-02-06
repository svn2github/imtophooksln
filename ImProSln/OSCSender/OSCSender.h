// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the OSCSENDER_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// OSCSENDER_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef OSCSENDER_EXPORTS
#define OSCSENDER_API __declspec(dllexport)
#else
#define OSCSENDER_API __declspec(dllimport)
#endif
#pragma once
#include "ITouchListener.h"
#include "osc/OscOutboundPacketStream.h"
#include "ip/UdpSocket.h"
#include <string>
#include <map>
using namespace touchlib;
using namespace std;

class OSCSENDER_API OSCSender : public ITouchListener
{
public:
	static int m_ref;
	static OSCSender* GetOSCSender();
	HRESULT AddRef();
	HRESULT Release();

	void connectSocket(string ip_address, int port);
	void disConnectSocket();
	bool isConnected();
	void fingerDown(TouchData data);
	void fingerUpdate(TouchData data);
	void fingerUp(TouchData data);
	void frame();
	void clearFingers();

public:
	string m_ipAddress;
	int m_port;
protected:
	OSCSender(void);
	virtual ~OSCSender(void);
	UdpTransmitSocket* m_transmitSocket;
	map<int, TouchData> m_fingerList;
	int m_frameSeq;
};
