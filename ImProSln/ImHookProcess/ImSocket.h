#pragma once
#include "afxsock.h"

#define SOCKET_REC_MSG L"SOCKET_REC_MSG-901CF8C1-7671-4c8e-B62E-250339B671A0"
#define SOCKET_ACCEPT_MSG L"SOCKET_ACCEPT_MSG-FB71E848-2DD0-49c9-AD33-A432DF71F066"
#define SOCKET_CLOSE_MSG L"SOCKET_CLOSE_MSG-228E61CB-0EC7-434a-BEA5-51A8850598F8"

static UINT SOCKET_REC = ::RegisterWindowMessage(SOCKET_REC_MSG);
static UINT SOCKET_ACCEPT = ::RegisterWindowMessage(SOCKET_ACCEPT_MSG);
static UINT SOCKET_CLOSE = ::RegisterWindowMessage(SOCKET_CLOSE_MSG);



struct STData
{
	static const int STDataSIZE = 4 + 4 + 4*8;
	enum SCMD
	{
		SETTTS_L,
		SETMASK_L,
		SETTTS_H,
		SETMASK_H
	};
	int size;
	SCMD cmd;
	float v1_x, v1_y, v2_x, v2_y, v3_x, v3_y, v4_x, v4_y;
	STData()
	{
		size = sizeof(STData);
		cmd = SETTTS_L;
		v1_x = 0; v1_y = 0; 
		v2_x = 0; v2_y = 1;
		v3_x = 1; v3_y = 0;
		v4_x = 1; v4_y = 1;

	}
	BOOL ToString(char*& buf)
	{
		if (buf != NULL)
		{
			delete[] buf;
			buf = NULL;
		}
		buf = new char[STDataSIZE];
		((int*)buf)[0] = STDataSIZE;
		((int*)buf)[1] = cmd;
		((float*)buf)[2] = v1_x;
		((float*)buf)[3] = v1_y;
		((float*)buf)[4] = v2_x;
		((float*)buf)[5] = v2_y;
		((float*)buf)[6] = v3_x;
		((float*)buf)[7] = v3_y;
		((float*)buf)[8] = v4_x;
		((float*)buf)[9] = v4_y;
		return TRUE;
	}
	BOOL FromString(char* buf)
	{
		if (buf == NULL)
		{
			return FALSE;
		}
		size = ((int*)buf)[0];
		cmd = (SCMD)((int*)buf)[1];
		v1_x = ((float*)buf)[2];
		v1_y = ((float*)buf)[3];
		v2_x = ((float*)buf)[4];
		v2_y = ((float*)buf)[5];
		v3_x = ((float*)buf)[6];
		v3_y = ((float*)buf)[7];
		v4_x = ((float*)buf)[8];
		v4_y = ((float*)buf)[9];
	}
};


class ImSocket :public CSocket
{
protected:
	 CDialog* m_pDlg;
public:
	ImSocket(CDialog* pDlg);
	virtual ~ImSocket(void);

	virtual void OnAccept(int nErrorCode);
	virtual void OnClose(int nErrorCode);
	virtual void OnConnect(int nErrorCode);
	virtual void OnOutOfBandData(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	virtual void OnSend(int nErrorCode);
	void SetParentDlg(CDialog *pDlg);

};
