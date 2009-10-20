
// ImSocketClientDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ImSocketClient.h"
#include "ImSocketClientDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CImSocketClientDlg dialog




CImSocketClientDlg::CImSocketClientDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CImSocketClientDlg::IDD, pParent)
	, m_strStatus(_T(""))

{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pApp = AfxGetApp();
}

void CImSocketClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BTN_CONNECT, m_btnConnect);
	DDX_Control(pDX, IDC_BUTTON2, m_btnDisconnect);
	DDX_Text(pDX, IDC_STATIC_STATUS, m_strStatus);
	DDX_Control(pDX, IDC_BUTTON3, m_btnSetTTS_H);
	DDX_Control(pDX, IDC_BUTTON4, m_btnSetTTS_L);

	DDX_Control(pDX, IDC_SLIDER1, m_sliderHV1X);
	DDX_Control(pDX, IDC_SLIDER2, m_sliderHV1Y);
	DDX_Control(pDX, IDC_SLIDER3, m_sliderHV2X);
	DDX_Control(pDX, IDC_SLIDER4, m_sliderHV2Y);
	DDX_Control(pDX, IDC_SLIDER5, m_sliderHV3X);
	DDX_Control(pDX, IDC_SLIDER6, m_sliderHV3Y);
	DDX_Control(pDX, IDC_SLIDER7, m_sliderHV4X);
	DDX_Control(pDX, IDC_SLIDER8, m_sliderHV4Y);
	DDX_Control(pDX, IDC_SLIDER9, m_sliderLV1X);
	DDX_Control(pDX, IDC_SLIDER10, m_sliderLV1Y);
	DDX_Control(pDX, IDC_SLIDER11, m_sliderLV2X);
	DDX_Control(pDX, IDC_SLIDER12, m_sliderLV2Y);
	DDX_Control(pDX, IDC_SLIDER13, m_sliderLV3X);
	DDX_Control(pDX, IDC_SLIDER14, m_sliderLV3Y);
	DDX_Control(pDX, IDC_SLIDER15, m_sliderLV4X);
	DDX_Control(pDX, IDC_SLIDER16, m_sliderLV4Y);
	DDX_Control(pDX, IDC_TXT_HV1X, m_txtHV1X);
	DDX_Control(pDX, IDC_TXT_HV1Y, m_txtHV1Y);
	DDX_Control(pDX, IDC_TXT_HV2X, m_txtHV2X);
	DDX_Control(pDX, IDC_TXT_HV2Y, m_txtHV2Y);
	DDX_Control(pDX, IDC_TXT_HV3X, m_txtHV3X);
	DDX_Control(pDX, IDC_TXT_HV3Y, m_txtHV3Y);
	DDX_Control(pDX, IDC_TXT_HV4X, m_txtHV4X);
	DDX_Control(pDX, IDC_TXT_HV4Y, m_txtHV4Y);
	DDX_Control(pDX, IDC_TXT_LV1X, m_txtLV1X);
	DDX_Control(pDX, IDC_TXT_LV1Y, m_txtLV1Y);
	DDX_Control(pDX, IDC_TXT_LV2X, m_txtLV2X);
	DDX_Control(pDX, IDC_TXT_LV2Y, m_txtLV2Y);
	DDX_Control(pDX, IDC_TXT_LV3X, m_txtLV3X);
	DDX_Control(pDX, IDC_TXT_LV3Y, m_txtLV3Y);
	DDX_Control(pDX, IDC_TXT_LV4X, m_txtLV4X);
	DDX_Control(pDX, IDC_TXT_LV4Y, m_txtLV4Y);
	DDX_Control(pDX, IDC_EDIT1, m_edPort);
	DDX_Control(pDX, IDC_EDIT2, m_edIP);
	DDX_Control(pDX, IDC_STATIC_STATUS, m_txtStatus);
	DDX_Control(pDX, IDC_EDIT3, m_edHostPort);
}

BEGIN_MESSAGE_MAP(CImSocketClientDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BTN_CONNECT, &CImSocketClientDlg::OnBnClickedBtnConnect)
	ON_REGISTERED_MESSAGE(SOCKET_REC, CImSocketClientDlg::OnSocketReceive)
	ON_REGISTERED_MESSAGE(SOCKET_CLOSE, CImSocketClientDlg::OnSocketClose)

	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER1, &CImSocketClientDlg::onSliderHV1X)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER2, &CImSocketClientDlg::onSliderHV1Y)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER3, &CImSocketClientDlg::onSliderHV2X)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER4, &CImSocketClientDlg::onSliderHV2Y)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER5, &CImSocketClientDlg::onSliderHV3X)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER6, &CImSocketClientDlg::onSliderHV3Y)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER7, &CImSocketClientDlg::onSliderHV4X)
	ON_NOTIFY(NM_OUTOFMEMORY, IDC_SLIDER8, &CImSocketClientDlg::onSliderHV4Y)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER9, &CImSocketClientDlg::onSliderLV1X)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER10, &CImSocketClientDlg::onSliderLV1Y)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER11, &CImSocketClientDlg::onSliderLV2X)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER12, &CImSocketClientDlg::onSliderLV2Y)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER13, &CImSocketClientDlg::onSliderLV3X)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER14, &CImSocketClientDlg::onSliderLV3Y)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER15, &CImSocketClientDlg::onSliderLV4X)
	
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER16, &CImSocketClientDlg::onSliderLV4Y)
	ON_BN_CLICKED(IDC_BUTTON2, &CImSocketClientDlg::OnBnClickedButton2)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON3, &CImSocketClientDlg::OnClickSetTTS_H)
	ON_BN_CLICKED(IDC_BUTTON4, &CImSocketClientDlg::OnClickSetTTS_L)
END_MESSAGE_MAP()


// CImSocketClientDlg message handlers

BOOL CImSocketClientDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	WCHAR str[MAX_PATH] = {0};
	swprintf_s(str, MAX_PATH, L"%d", m_pApp->GetProfileInt(L"MySetting",L"SocketPort",2222));
	m_edPort.SetWindowText(str);
	swprintf_s(str, MAX_PATH, L"%d", m_pApp->GetProfileInt(L"MySetting",L"HostPort",2323));
	m_edHostPort.SetWindowText(str);

	m_edIP.SetWindowText(m_pApp->GetProfileString(L"MySetting",L"IPAddress", L"127.0.0.1"));
	m_btnDisconnect.EnableWindow(FALSE);

	m_sliderHV1X.SetPos(0);
	m_sliderHV1Y.SetPos(0);
	m_sliderHV2X.SetPos(0);
	m_sliderHV2Y.SetPos(m_sliderHV2Y.GetRangeMax());
	m_sliderHV3X.SetPos(m_sliderHV3X.GetRangeMax());
	m_sliderHV3Y.SetPos(0);
	m_sliderHV4X.SetPos(m_sliderHV4X.GetRangeMax());
	m_sliderHV4Y.SetPos(m_sliderHV4Y.GetRangeMax());

	m_sliderLV1X.SetPos(0);
	m_sliderLV1Y.SetPos(0);
	m_sliderLV2X.SetPos(0);
	m_sliderLV2Y.SetPos(m_sliderLV2Y.GetRangeMax());
	m_sliderLV3X.SetPos(m_sliderLV3X.GetRangeMax());
	m_sliderLV3Y.SetPos(0);
	m_sliderLV4X.SetPos(m_sliderLV4X.GetRangeMax());
	m_sliderLV4Y.SetPos(m_sliderLV4Y.GetRangeMax());
	
	float v =  (float)m_sliderHV1X.GetPos()/(m_sliderHV1X.GetRangeMax() - m_sliderHV1X.GetRangeMin());
	swprintf_s(str, MAX_PATH, L"%.2f", v);
	m_txtHV1X.SetWindowText(str);

	v =  (float)m_sliderHV1Y.GetPos()/(m_sliderHV1Y.GetRangeMax() - m_sliderHV1Y.GetRangeMin());
	swprintf_s(str, MAX_PATH, L"%.2f", v);
	m_txtHV1Y.SetWindowText(str);

	v =  (float)m_sliderHV2X.GetPos()/(m_sliderHV2X.GetRangeMax() - m_sliderHV2X.GetRangeMin());
	swprintf_s(str, MAX_PATH, L"%.2f", v);
	m_txtHV2X.SetWindowText(str);

	v =  (float)m_sliderHV2Y.GetPos()/(m_sliderHV2Y.GetRangeMax() - m_sliderHV2Y.GetRangeMin());
	swprintf_s(str, MAX_PATH, L"%.2f", v);
	m_txtHV2Y.SetWindowText(str);

	v =  (float)m_sliderHV3X.GetPos()/(m_sliderHV3X.GetRangeMax() - m_sliderHV3X.GetRangeMin());
	swprintf_s(str, MAX_PATH, L"%.2f", v);
	m_txtHV3X.SetWindowText(str);

	v =  (float)m_sliderHV3Y.GetPos()/(m_sliderHV3Y.GetRangeMax() - m_sliderHV3Y.GetRangeMin());
	swprintf_s(str, MAX_PATH, L"%.2f", v);
	m_txtHV3Y.SetWindowText(str);

	v =  (float)m_sliderHV4X.GetPos()/(m_sliderHV4X.GetRangeMax() - m_sliderHV4X.GetRangeMin());
	swprintf_s(str, MAX_PATH, L"%.2f", v);
	m_txtHV4X.SetWindowText(str);

	v =  (float)m_sliderHV4Y.GetPos()/(m_sliderHV4Y.GetRangeMax() - m_sliderHV4Y.GetRangeMin());
	swprintf_s(str, MAX_PATH, L"%.2f", v);
	m_txtHV4Y.SetWindowText(str);




	v =  (float)m_sliderLV1X.GetPos()/(m_sliderLV1X.GetRangeMax() - m_sliderLV1X.GetRangeMin());
	swprintf_s(str, MAX_PATH, L"%.2f", v);
	m_txtLV1X.SetWindowText(str);

	v =  (float)m_sliderLV1Y.GetPos()/(m_sliderLV1Y.GetRangeMax() - m_sliderLV1Y.GetRangeMin());
	swprintf_s(str, MAX_PATH, L"%.2f", v);
	m_txtLV1Y.SetWindowText(str);

	v =  (float)m_sliderLV2X.GetPos()/(m_sliderLV2X.GetRangeMax() - m_sliderLV2X.GetRangeMin());
	swprintf_s(str, MAX_PATH, L"%.2f", v);
	m_txtLV2X.SetWindowText(str);

	v =  (float)m_sliderLV2Y.GetPos()/(m_sliderLV2Y.GetRangeMax() - m_sliderLV2Y.GetRangeMin());
	swprintf_s(str, MAX_PATH, L"%.2f", v);
	m_txtLV2Y.SetWindowText(str);

	v =  (float)m_sliderLV3X.GetPos()/(m_sliderLV3X.GetRangeMax() - m_sliderLV3X.GetRangeMin());
	swprintf_s(str, MAX_PATH, L"%.2f", v);
	m_txtLV3X.SetWindowText(str);

	v =  (float)m_sliderLV3Y.GetPos()/(m_sliderLV3Y.GetRangeMax() - m_sliderLV3Y.GetRangeMin());
	swprintf_s(str, MAX_PATH, L"%.2f", v);
	m_txtLV3Y.SetWindowText(str);

	v =  (float)m_sliderLV4X.GetPos()/(m_sliderLV4X.GetRangeMax() - m_sliderLV4X.GetRangeMin());
	swprintf_s(str, MAX_PATH, L"%.2f", v);
	m_txtLV4X.SetWindowText(str);

	v =  (float)m_sliderLV4Y.GetPos()/(m_sliderLV4Y.GetRangeMax() - m_sliderLV4Y.GetRangeMin());
	swprintf_s(str, MAX_PATH, L"%.2f", v);
	m_txtLV4Y.SetWindowText(str);



	WSADATA wsaData;

	int iResult  = 0;
	iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
	if (iResult != 0) {
		printf("WSAStartup failed: %d\n", iResult);
		return 1;
	}
	m_pSocket = new ImSocket(this);
	//m_pSocket.SetParentDlg(this);



	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CImSocketClientDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CImSocketClientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CImSocketClientDlg::OnBnClickedBtnConnect()
{
	UpdateData(TRUE);
	WCHAR strPortNum[MAX_PATH] = {0};
	WCHAR strHostPortNum[MAX_PATH] = {0};
	WCHAR strIP[MAX_PATH] = {0};

	int portNum = 0;
	int hostPortNum = 0;
	m_edPort.GetWindowText(strPortNum, MAX_PATH);
	swscanf_s(strPortNum, L"%d", &portNum);
	m_edHostPort.GetWindowText(strHostPortNum, MAX_PATH);
	swscanf_s(strHostPortNum, L"%d", &hostPortNum);
	m_edIP.GetWindowText(strIP, MAX_PATH);
	if (m_pSocket != NULL)
	{
		delete m_pSocket;
		m_pSocket = new ImSocket(this);
	}
	BOOL ret = m_pSocket->Create(hostPortNum);
	if (!ret)
	{
		DWORD err = GetLastError();
		WCHAR str[MAX_PATH];
		swprintf_s(str, MAX_PATH, L"Create Socket Failed!!! Error Code = %d", err);
		m_txtStatus.SetWindowText(str);
		return;
	}
	ret = m_pSocket->Connect(strIP, portNum);
	if (!ret)
	{
		DWORD err = GetLastError();
		WCHAR str[MAX_PATH];
		swprintf_s(str, MAX_PATH, L"Connect Failed!!! Error Code = %d", err);
		m_txtStatus.SetWindowText(str);
		return;
	}
	UpdateData(FALSE);
	m_txtStatus.SetWindowText(L"Connect Succeed!!!");
	
	m_edPort.EnableWindow(FALSE);
	m_btnConnect.EnableWindow(FALSE);
	m_btnDisconnect.EnableWindow(TRUE); 
	m_edIP.EnableWindow(FALSE);
	m_edHostPort.EnableWindow(FALSE);
	m_pApp->WriteProfileInt(L"MySetting",L"SocketPort",portNum);
	m_pApp->WriteProfileString(L"MySetting",L"IPAddress", strIP);
}


void CImSocketClientDlg::onSliderHV1X(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	*pResult = 0;
	
	float v =  (float)m_sliderHV1X.GetPos()/(m_sliderHV1X.GetRangeMax() - m_sliderHV1X.GetRangeMin());
	WCHAR str[MAX_PATH];
	swprintf_s(str, MAX_PATH, L"%.2f", v);
	m_txtHV1X.SetWindowText(str);
	this->OnClickSetTTS_H();
}

void CImSocketClientDlg::onSliderHV1Y(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	*pResult = 0;

	float v =  (float)m_sliderHV1Y.GetPos()/(m_sliderHV1Y.GetRangeMax() - m_sliderHV1Y.GetRangeMin());
	WCHAR str[MAX_PATH];
	swprintf_s(str, MAX_PATH, L"%.2f", v);
	m_txtHV1Y.SetWindowText(str);
	this->OnClickSetTTS_H();

}

void CImSocketClientDlg::onSliderHV2X(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	*pResult = 0;
	float v =  (float)m_sliderHV2X.GetPos()/(m_sliderHV2X.GetRangeMax() - m_sliderHV2X.GetRangeMin());
	WCHAR str[MAX_PATH];
	swprintf_s(str, MAX_PATH, L"%.2f", v);
	m_txtHV2X.SetWindowText(str);
	this->OnClickSetTTS_H();
}

void CImSocketClientDlg::onSliderHV2Y(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	*pResult = 0;
	float v =  (float)m_sliderHV2Y.GetPos()/(m_sliderHV2Y.GetRangeMax() - m_sliderHV2Y.GetRangeMin());
	WCHAR str[MAX_PATH];
	swprintf_s(str, MAX_PATH, L"%.2f", v);
	m_txtHV2Y.SetWindowText(str);
	this->OnClickSetTTS_H();
}

void CImSocketClientDlg::onSliderHV3X(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	*pResult = 0;
	float v =  (float)m_sliderHV3X.GetPos()/(m_sliderHV3X.GetRangeMax() - m_sliderHV3X.GetRangeMin());
	WCHAR str[MAX_PATH];
	swprintf_s(str, MAX_PATH, L"%.2f", v);
	m_txtHV3X.SetWindowText(str);
	this->OnClickSetTTS_H();
}

void CImSocketClientDlg::onSliderHV3Y(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	*pResult = 0;
	float v =  (float)m_sliderHV3Y.GetPos()/(m_sliderHV3Y.GetRangeMax() - m_sliderHV3Y.GetRangeMin());
	WCHAR str[MAX_PATH];
	swprintf_s(str, MAX_PATH, L"%.2f", v);
	m_txtHV3Y.SetWindowText(str);
	this->OnClickSetTTS_H();
}

void CImSocketClientDlg::onSliderHV4X(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	*pResult = 0;

	float v =  (float)m_sliderHV4X.GetPos()/(m_sliderHV4X.GetRangeMax() - m_sliderHV4X.GetRangeMin());
	WCHAR str[MAX_PATH];
	swprintf_s(str, MAX_PATH, L"%.2f", v);
	m_txtHV4X.SetWindowText(str);
	this->OnClickSetTTS_H();
}

void CImSocketClientDlg::onSliderHV4Y(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	*pResult = 0;
	float v =  (float)m_sliderHV4Y.GetPos()/(m_sliderHV4Y.GetRangeMax() - m_sliderHV4Y.GetRangeMin());
	WCHAR str[MAX_PATH];
	swprintf_s(str, MAX_PATH, L"%.2f", v);
	m_txtHV4Y.SetWindowText(str);
	this->OnClickSetTTS_H();
}



void CImSocketClientDlg::onSliderLV1X(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	*pResult = 0;

	float v =  (float)m_sliderLV1X.GetPos()/(m_sliderLV1X.GetRangeMax() - m_sliderLV1X.GetRangeMin());
	WCHAR str[MAX_PATH];
	swprintf_s(str, MAX_PATH, L"%.2f", v);
	m_txtLV1X.SetWindowText(str);
	this->OnClickSetTTS_L();
}

void CImSocketClientDlg::onSliderLV1Y(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	*pResult = 0;

	float v =  (float)m_sliderLV1Y.GetPos()/(m_sliderLV1Y.GetRangeMax() - m_sliderLV1Y.GetRangeMin());
	WCHAR str[MAX_PATH];
	swprintf_s(str, MAX_PATH, L"%.2f", v);
	m_txtLV1Y.SetWindowText(str);
	this->OnClickSetTTS_L();

}

void CImSocketClientDlg::onSliderLV2X(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	*pResult = 0;
	float v =  (float)m_sliderLV2X.GetPos()/(m_sliderLV2X.GetRangeMax() - m_sliderLV2X.GetRangeMin());
	WCHAR str[MAX_PATH];
	swprintf_s(str, MAX_PATH, L"%.2f", v);
	m_txtLV2X.SetWindowText(str);
	this->OnClickSetTTS_L();
}

void CImSocketClientDlg::onSliderLV2Y(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	*pResult = 0;
	float v =  (float)m_sliderLV2Y.GetPos()/(m_sliderLV2Y.GetRangeMax() - m_sliderLV2Y.GetRangeMin());
	WCHAR str[MAX_PATH];
	swprintf_s(str, MAX_PATH, L"%.2f", v);
	m_txtLV2Y.SetWindowText(str);
	this->OnClickSetTTS_L();
}

void CImSocketClientDlg::onSliderLV3X(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	*pResult = 0;
	float v =  (float)m_sliderLV3X.GetPos()/(m_sliderLV3X.GetRangeMax() - m_sliderLV3X.GetRangeMin());
	WCHAR str[MAX_PATH];
	swprintf_s(str, MAX_PATH, L"%.2f", v);
	m_txtLV3X.SetWindowText(str);
	this->OnClickSetTTS_L();
}

void CImSocketClientDlg::onSliderLV3Y(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	*pResult = 0;
	float v =  (float)m_sliderLV3Y.GetPos()/(m_sliderLV3Y.GetRangeMax() - m_sliderLV3Y.GetRangeMin());
	WCHAR str[MAX_PATH];
	swprintf_s(str, MAX_PATH, L"%.2f", v);
	m_txtLV3Y.SetWindowText(str);
	this->OnClickSetTTS_L();
}

void CImSocketClientDlg::onSliderLV4X(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	*pResult = 0;

	float v =  (float)m_sliderLV4X.GetPos()/(m_sliderLV4X.GetRangeMax() - m_sliderLV4X.GetRangeMin());
	WCHAR str[MAX_PATH];
	swprintf_s(str, MAX_PATH, L"%.2f", v);
	m_txtLV4X.SetWindowText(str);
	this->OnClickSetTTS_L();
}

void CImSocketClientDlg::onSliderLV4Y(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	*pResult = 0;
	float v =  (float)m_sliderLV4Y.GetPos()/(m_sliderHV4Y.GetRangeMax() - m_sliderLV4Y.GetRangeMin());
	WCHAR str[MAX_PATH];
	swprintf_s(str, MAX_PATH, L"%.2f", v);
	m_txtLV4Y.SetWindowText(str);
	this->OnClickSetTTS_L();
}

void CImSocketClientDlg::OnBnClickedButton2()
{
	UpdateData(FALSE);
	m_pSocket->Close();
	
	m_txtStatus.SetWindowText(L"Disconnect!!");	
	
	m_edPort.EnableWindow(TRUE);
	m_edIP.EnableWindow(TRUE);
	m_btnConnect.EnableWindow(TRUE);
	m_btnDisconnect.EnableWindow(FALSE);
	m_edHostPort.EnableWindow(TRUE);
}

void CImSocketClientDlg::OnDestroy()
{
	CDialog::OnDestroy();
	if (m_pSocket != NULL)
	{
		delete m_pSocket;
		m_pSocket = NULL;
	}
	// TODO: Add your message handler code here
}

void CImSocketClientDlg::OnClickSetTTS_H()
{
	// TODO: Add your control notification handler code here
	if (m_pSocket == NULL)
	{
		return;
	}

	STData data;
	data.cmd = STData::SETTTS_H;
	data.v1_x = (float)m_sliderHV1X.GetPos()/(m_sliderHV1X.GetRangeMax() - m_sliderHV1X.GetRangeMin());
	data.v1_y = (float)m_sliderHV1Y.GetPos()/(m_sliderHV1Y.GetRangeMax() - m_sliderHV1Y.GetRangeMin());

	data.v2_x = (float)m_sliderHV2X.GetPos()/(m_sliderHV2X.GetRangeMax() - m_sliderHV2X.GetRangeMin());
	data.v2_y = (float)m_sliderHV2Y.GetPos()/(m_sliderHV2Y.GetRangeMax() - m_sliderHV2Y.GetRangeMin());

	data.v3_x = (float)m_sliderHV3X.GetPos()/(m_sliderHV3X.GetRangeMax() - m_sliderHV3X.GetRangeMin());
	data.v3_y = (float)m_sliderHV3Y.GetPos()/(m_sliderHV3Y.GetRangeMax() - m_sliderHV3Y.GetRangeMin());

	data.v4_x = (float)m_sliderHV4X.GetPos()/(m_sliderHV4X.GetRangeMax() - m_sliderHV4X.GetRangeMin());
	data.v4_y = (float)m_sliderHV4Y.GetPos()/(m_sliderHV4Y.GetRangeMax() - m_sliderHV4Y.GetRangeMin());
	char* pBuf = NULL; 
	data.ToString(pBuf);
	m_pSocket->Send((void*)pBuf, data.size);

	delete[] pBuf;
}

void CImSocketClientDlg::OnClickSetTTS_L()
{
	// TODO: Add your control notification handler code here
	// TODO: Add your control notification handler code here
	if (m_pSocket == NULL)
	{
		return;
	}

	STData data;
	data.cmd = STData::SETTTS_L;
	data.v1_x = (float)m_sliderLV1X.GetPos()/(m_sliderLV1X.GetRangeMax() - m_sliderLV1X.GetRangeMin());
	data.v1_y = (float)m_sliderLV1Y.GetPos()/(m_sliderLV1Y.GetRangeMax() - m_sliderLV1Y.GetRangeMin());

	data.v2_x = (float)m_sliderLV2X.GetPos()/(m_sliderLV2X.GetRangeMax() - m_sliderLV2X.GetRangeMin());
	data.v2_y = (float)m_sliderLV2Y.GetPos()/(m_sliderLV2Y.GetRangeMax() - m_sliderLV2Y.GetRangeMin());

	data.v3_x = (float)m_sliderLV3X.GetPos()/(m_sliderLV3X.GetRangeMax() - m_sliderLV3X.GetRangeMin());
	data.v3_y = (float)m_sliderLV3Y.GetPos()/(m_sliderLV3Y.GetRangeMax() - m_sliderLV3Y.GetRangeMin());

	data.v4_x = (float)m_sliderLV4X.GetPos()/(m_sliderLV4X.GetRangeMax() - m_sliderLV4X.GetRangeMin());
	data.v4_y = (float)m_sliderLV4Y.GetPos()/(m_sliderLV4Y.GetRangeMax() - m_sliderLV4Y.GetRangeMin());
	char* pBuf = NULL; 
	data.ToString(pBuf);
	m_pSocket->Send((void*)pBuf, data.size);

	delete[] pBuf;
}


LRESULT CImSocketClientDlg::OnSocketReceive(WPARAM wParam, LPARAM lParam)
{
	char *pBuf =new char [1025];
	int iLen;
	iLen=m_pSocket->Receive(pBuf,1024);
	if(iLen==SOCKET_ERROR)
	{
		AfxMessageBox(L"Could not Receieve");
	}
	else
	{
	
	}
	return S_OK;
}



LRESULT CImSocketClientDlg::OnSocketClose(WPARAM wParam, LPARAM lParam)
{
	AfxMessageBox(L"Connected Is Closed!!!");
	this->OnBnClickedButton2(); 
	return S_OK;
}