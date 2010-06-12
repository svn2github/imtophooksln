// OSCSender.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "OSCSender.h"
#include <math.h>
#include "Streams.h"
#define OUTPUT_BUFFER_SIZE 2048

CCritSec g_csOSCSender;

OSCSender* g_OSCSender = NULL;
int OSCSender::m_ref = 0;
OSCSender* OSCSender::GetOSCSender()
{
	CAutoLock lck(&g_csOSCSender);
	if (g_OSCSender == NULL)
	{
		g_OSCSender = new OSCSender();
	}
	g_OSCSender->AddRef();
	return g_OSCSender;
}
HRESULT OSCSender::AddRef()
{
	CAutoLock lck(&g_csOSCSender);
	m_ref++;
	return S_OK;
}
HRESULT OSCSender::Release()
{
	CAutoLock lck(&g_csOSCSender);
	m_ref--;
	if (m_ref <= 0)
	{
		delete g_OSCSender;
		g_OSCSender = NULL;
	}
	return S_OK;
}
OSCSender::OSCSender(void)
{	
	m_transmitSocket = NULL;
	m_frameSeq = 0;
	memset(m_ipAddress, 0, sizeof(char)*MAX_PATH);
	sprintf_s(m_ipAddress, MAX_PATH, "127.0.0.1");
	m_port = 3333;
}

OSCSender::~OSCSender(void)
{
	if (m_transmitSocket != NULL)
	{
		delete m_transmitSocket;
		m_transmitSocket = NULL;
	}
}
void OSCSender::connectSocket(char* ip_address, int port)
{	
	CAutoLock lck(&g_csOSCSender);
	if (m_transmitSocket != NULL)
	{
		delete m_transmitSocket;
		m_transmitSocket = NULL;
	}

	m_transmitSocket = new UdpTransmitSocket( IpEndpointName( ip_address, port ) );
	m_frameSeq = 0;
	m_port = port;
	strcpy_s(m_ipAddress, ip_address);
}
void OSCSender::disConnectSocket()
{
	CAutoLock lck(&g_csOSCSender);
	if (m_transmitSocket != NULL)
	{
		delete m_transmitSocket;
		m_transmitSocket = NULL;
	}
}
bool OSCSender::isConnected()
{
	CAutoLock lck(&g_csOSCSender);
	if (m_transmitSocket == NULL)
	{
		return false;
	}
	return true;
}
void OSCSender::fingerDown(TouchData data)
{
	CAutoLock lck(&g_csOSCSender);
	if (m_transmitSocket == NULL)
	{
		return;
	}
	if(!(data.X == 0.00 && data.Y == 0.00))
	{
		m_fingerList[data.ID] = data;
	}
	frame();
}
void OSCSender::fingerUpdate(TouchData data)
{
	CAutoLock lck(&g_csOSCSender);
	if (m_transmitSocket == NULL)
	{
		return;
	}
	m_fingerList[data.ID] = data;
	frame();
}
void OSCSender::fingerUp(TouchData data)
{
	CAutoLock lck(&g_csOSCSender);
	if (m_transmitSocket == NULL)
	{
		return;
	}
	std::map<int, TouchData>::iterator iter;
	for(iter=m_fingerList.begin(); iter != m_fingerList.end(); iter++)
	{
		if(iter->second.ID == data.ID)
		{
			m_fingerList.erase(iter);
			break;
		}
	}
	frame();
}

void OSCSender::frame()
{
	CAutoLock lck(&g_csOSCSender);
	if(!m_transmitSocket)
		return;

	// send update messages..

	char buffer[OUTPUT_BUFFER_SIZE];
	char buffer2[OUTPUT_BUFFER_SIZE];
	osc::OutboundPacketStream p( buffer, OUTPUT_BUFFER_SIZE );
	osc::OutboundPacketStream p2( buffer2, OUTPUT_BUFFER_SIZE );

	std::map<int, TouchData>::iterator iter1, iter2, iter_last;	    

	if(m_fingerList.size() > 0)
	{
		//p << osc::BeginBundleImmediate;


		int scount = 0, acount = 0;
		iter1=m_fingerList.begin();

		bool done=false;

		while(!done)
		{
			p.Clear();
			p2.Clear();


			p << osc::BeginBundle();
			p2 << osc::BeginBundle();

			for(; iter1 != m_fingerList.end(); iter1++)
			{
				TouchData d = (*iter1).second;
				float m = sqrtf((d.dX*d.dX) + (d.dY*d.dY));
				float area = d.area;
				//	printf(d.area);
				//	printf("%d\n", d.tagID);
				if(!(d.X == 0 && d.Y == 0)) {
					if(d.tagID == 0)
					{
						// don't send extra info
#ifdef OSC_STRICT
						p << osc::BeginMessage( "/tuio/2Dcur" ) << "set" << d.ID << d.X << d.Y << d.dX << d.dY << m << osc::EndMessage;
#else
						p << osc::BeginMessage( "/tuio/2Dcur" ) << "set" << d.ID << d.X << d.Y << d.dX << d.dY << m << d.width << d.height << osc::EndMessage;
						//pressure
						//p << osc::BeginMessage( "/tuio/2Dcur" ) << "set" << d.ID << d.X << d.Y << d.dX << d.dY << m << d.width << d.height << d.weight << osc::EndMessage;

#endif
					} else {
						// is a fiducial tag

						//FIXME: should we send height and width for obj's too?
						p2 << osc::BeginMessage( "/tuio/2Dobj" ) << "set" << d.ID << d.tagID << d.X << d.Y << d.angle << d.dX << d.dY << 0.0 << m << 0.0 << osc::EndMessage;
					}

					scount ++;
					if(scount >= 10)
					{
						scount = 0;
						break;
					}
				}
			}

			if(iter1 == m_fingerList.end())
				done = true;



			p << osc::BeginMessage( "/tuio/2Dcur" );
			p << "alive";
			p2 << osc::BeginMessage( "/tuio/2Dobj" );
			p2 << "alive";

			for(iter2=m_fingerList.begin(); iter2 != m_fingerList.end(); iter2++)
			{
				TouchData d = (*iter2).second;
				if(d.tagID == 0)
				{
					if(!(d.X == 0 && d.Y == 0)) {
						p << d.ID;
					}
				} else {
					if(!(d.X == 0 && d.Y == 0)) {
						p2 << d.ID;
					}
				}
			}
			p << osc::EndMessage;
			p << osc::BeginMessage( "/tuio/2Dcur" ) << "fseq" << m_frameSeq << osc::EndMessage;
			p << osc::EndBundle;

			p2 << osc::EndMessage;
			p2 << osc::BeginMessage( "/tuio/2Dobj" ) << "fseq" << m_frameSeq << osc::EndMessage;
			p2 << osc::EndBundle;



			//printf("%d size. %d #fingers\n", p.Size(), fingerList.size());
			m_frameSeq ++; 
			if(p.IsReady())
				m_transmitSocket->Send( p.Data(), p.Size() );

			//if(p2.IsReady())
			//transmitSocket->Send( p2.Data(), p2.Size() );
		}


	} else {
		// do we even need to do this?

		//p << osc::BeginBundleImmediate;
		p.Clear();
		p << osc::BeginBundle();

		p << osc::BeginMessage( "/tuio/2Dcur" );
		p << "alive";
		p << osc::EndMessage;

		p << osc::BeginMessage( "/tuio/2Dcur" ) << "fseq" << m_frameSeq << osc::EndMessage;

		p << osc::EndBundle;

		m_frameSeq ++;
		//printf("%d size\n", p.Size());

		if(p.IsReady())
			m_transmitSocket->Send( p.Data(), p.Size() );
	}
}

void OSCSender::sendHighResBoundingBox(int id, float rect[4], float orgPt[4][2])
{
	CAutoLock lck(&g_csOSCSender);
	if(!m_transmitSocket)
		return;

	// send update messages..

	char buffer[OUTPUT_BUFFER_SIZE];
	osc::OutboundPacketStream p( buffer, OUTPUT_BUFFER_SIZE );
	p.Clear();
	p << osc::BeginBundle();
	p << osc::BeginMessage( "/tuio/BoundingBox" ) << "set" << id << rect[0] << rect[1] << rect[2] << rect[3]  << osc::EndMessage;
	p << osc::BeginMessage( "/tuio/originalPts" ) << "set" << id << orgPt[0][0] << orgPt[0][1]
			<< orgPt[1][0] << orgPt[1][1] << orgPt[2][0] << orgPt[2][1] << orgPt[3][0] << orgPt[3][1] << osc::EndMessage;
	p << osc::EndBundle;
	if(p.IsReady())
		m_transmitSocket->Send( p.Data(), p.Size() );
}
void OSCSender::sendDetectedARTag(float* tagRects, int* tagIDs, UINT nTag)
{
	CAutoLock lck(&g_csOSCSender);
	if(!m_transmitSocket || tagRects == NULL || tagIDs == NULL || nTag == 0)
		return;

	// send update messages..

	char buffer[OUTPUT_BUFFER_SIZE];
	osc::OutboundPacketStream p( buffer, OUTPUT_BUFFER_SIZE );
	p.Clear();
	p << osc::BeginBundle();
	for (int i =0; i < nTag; i++)
	{
		p << osc::BeginMessage( "/tuio/ARTag" ) << "set" << tagIDs[i] << tagRects[8*i+0] <<  tagRects[8*i+1]  <<  tagRects[8*i+2]  <<  tagRects[8*i+3] << osc::EndMessage;
	}
	p << osc::EndBundle;
	if(p.IsReady())
		m_transmitSocket->Send( p.Data(), p.Size() );
}
void OSCSender::clearFingers()
{
	CAutoLock lck(&g_csOSCSender);
	m_fingerList.clear();
}