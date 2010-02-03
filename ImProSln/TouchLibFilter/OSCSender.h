#pragma once
#include "ITouchListener.h"
#include "osc/OscOutboundPacketStream.h"
#include "ip/UdpSocket.h"
#include <string>
#include <map>
using namespace touchlib;
using namespace std;
class OSCSender : public ITouchListener
{
public:
	OSCSender(void);
	virtual ~OSCSender(void);

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
	UdpTransmitSocket* m_transmitSocket;
	map<int, TouchData> m_fingerList;
	int m_frameSeq;

};
