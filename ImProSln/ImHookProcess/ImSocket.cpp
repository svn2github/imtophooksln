
#include "StdAfx.h"
#include "ImSocket.h"

ImSocket::ImSocket(CDialog* pdlg)
{
	m_pDlg = pdlg;
}

ImSocket::~ImSocket(void)
{
}

void ImSocket::OnAccept(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(nErrorCode==0)
	{
		PostMessageW(m_pDlg->GetSafeHwnd(), SOCKET_ACCEPT, NULL, NULL); 
	}
	CSocket::OnAccept(nErrorCode);
}

void ImSocket::OnClose(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(nErrorCode==0)
	{
		PostMessageW(m_pDlg->GetSafeHwnd(), SOCKET_CLOSE, NULL, NULL); 
	}
	CSocket::OnClose(nErrorCode);
}

void ImSocket::OnConnect(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class

	
	CSocket::OnConnect(nErrorCode);
}

void ImSocket::OnOutOfBandData(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	CSocket::OnOutOfBandData(nErrorCode);
}

void ImSocket::OnReceive(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(nErrorCode==0)
	{
		PostMessageW(m_pDlg->GetSafeHwnd(), SOCKET_REC, NULL, NULL); 
	}
	
	CSocket::OnReceive(nErrorCode);
}

void ImSocket::OnSend(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	CSocket::OnSend(nErrorCode);
}


void ImSocket::SetParentDlg(CDialog *pDlg)
{
	m_pDlg=pDlg;
}