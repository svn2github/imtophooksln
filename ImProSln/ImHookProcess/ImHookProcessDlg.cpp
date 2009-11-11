// ImHookProcessDlg.cpp : implementation file
//
#include "stdafx.h"
#include "ImHookProcess.h"
#include "ImHookProcessDlg.h"
#include "..\\Hook\Hook.h"
#include <detours.h>
#include "afxsock.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#define DRAWING_TIMER_IDX 1



// CImHookProcessDlg dialog
static UINT HOOKED_WNDDESTORY = ::RegisterWindowMessage(HOOKED_WNDDESTORY_MSG);
static UINT HOOKED_ENABLEEDITWARP_LOW = ::RegisterWindowMessage(HOOKED_ENABLEEDITWARP_LOW_MSG);
static UINT HOOKED_ENABLEEDITTTS_LOW = ::RegisterWindowMessage(HOOKED_ENABLEEDITTTS_LOW_MSG);
static UINT HOOKED_ENABLEEDITWARP_HIGH = ::RegisterWindowMessage(HOOKED_ENABLEEDITWARP_HIGH_MSG);
static UINT HOOKED_ENABLEEDITTTS_HIGH = ::RegisterWindowMessage(HOOKED_ENABLEEDITTTS_HIGH_MSG);
CImHookProcessDlg::CImHookProcessDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CImHookProcessDlg::IDD, pParent)
	, m_recData(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_HookedWnd = NULL;
	m_pApp = AfxGetApp();
}

void CImHookProcessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_EDIT3, m_edProcPath);
	DDX_Control(pDX, IDC_BUTTON3, m_btnBrowse);
	DDX_Control(pDX, IDC_BUTTON4, m_btnCreateProc);
	DDX_Control(pDX, IDC_EDIT1, m_edWndName);
	DDX_Control(pDX, IDC_EDIT2, m_edWndClass);
	DDX_Control(pDX, IDC_BUTTON1, m_btnFindWindow);

	DDX_Control(pDX, IDC_CKEDITWARP, m_ckEditWarp);
	DDX_Control(pDX, IDC_CHK_EDITTTS, m_ckEditTTS);
	DDX_Control(pDX, IDC_CHECK1, m_ckEditWarpHigh);
	DDX_Control(pDX, IDC_CHECK2, m_ckEditTTSHigh);
	DDX_Control(pDX, IDC_BUTTON2, m_btnListen);
	DDX_Control(pDX, IDC_BUTTON5, m_btnStop);
	DDX_Control(pDX, IDC_EDIT4, m_edPort);
	DDX_Control(pDX, IDC_STATIC_STATUS, m_txtStatus);
	DDX_Control(pDX, IDC_EDIT_RecData, m_edRecData);
	DDX_Text(pDX, IDC_EDIT_RecData, m_recData);
}

BEGIN_MESSAGE_MAP(CImHookProcessDlg, CDialog)
	ON_REGISTERED_MESSAGE(HOOKED_WNDDESTORY, onHookedDestory)
	ON_REGISTERED_MESSAGE(SOCKET_ACCEPT, CImHookProcessDlg::OnSocketAccept)
	ON_REGISTERED_MESSAGE(SOCKET_REC, CImHookProcessDlg::OnSocketReceive)
	ON_REGISTERED_MESSAGE(SOCKET_CLOSE, CImHookProcessDlg::OnSocketClose)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON3, &CImHookProcessDlg::onBrowseProcPath)
	ON_BN_CLICKED(IDC_BUTTON4, &CImHookProcessDlg::onDetourCreateProc)
	ON_BN_CLICKED(IDC_BUTTON1, &CImHookProcessDlg::onFindWindow)
	ON_BN_CLICKED(IDC_CKEDITWARP, &CImHookProcessDlg::OnBnClickedCkeditwarp)
	ON_BN_CLICKED(IDC_CHK_EDITTTS, &CImHookProcessDlg::OnBnClickedChkEdittts)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_CHECK1, &CImHookProcessDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK2, &CImHookProcessDlg::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_BUTTON2, &CImHookProcessDlg::OnBtnListenClicked)
	ON_BN_CLICKED(IDC_BUTTON5, &CImHookProcessDlg::OnBtnStopClicked)
END_MESSAGE_MAP()


// CImHookProcessDlg message handlers

BOOL CImHookProcessDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	CString strClassName, strWndName, createProcPath;
	int portNum = m_pApp->GetProfileInt(L"MySetting", L"SocketPort", 2222);
	createProcPath = m_pApp->GetProfileString(L"MySetting", L"CreateProcPath",L"");
	strClassName = m_pApp->GetProfileString(L"MySetting", L"HookedClassName",L"");
	strWndName= m_pApp->GetProfileString(L"MySetting", L"HookedWndName",L"");

	m_edWndClass.SetWindowText(strClassName);
	m_edWndName.SetWindowText(strWndName);
	m_edProcPath.SetWindowText(createProcPath);
	WCHAR strPortNum[MAX_PATH];
	swprintf_s(strPortNum, MAX_PATH, L"%d", portNum);
	m_edPort.SetWindowText(strPortNum);
	WSADATA wsaData;

	int iResult  = 0;
	iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
	if (iResult != 0) {
		printf("WSAStartup failed: %d\n", iResult);
		return 1;
	}

	m_sListener = NULL;
	m_sConnected = NULL;

	m_txtStatus.SetWindowText(L"Idle...!!!");

	m_edWndClass.EnableWindow(FALSE);
	m_edWndName.EnableWindow(FALSE);
	m_btnFindWindow.EnableWindow(FALSE);
	m_btnStop.EnableWindow(FALSE);
	//m_edRecData.EnableWindow(FALSE);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CImHookProcessDlg::OnPaint()
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
HCURSOR CImHookProcessDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


bool CImHookProcessDlg::onWindowHooked()
{
	m_btnCreateProc.EnableWindow(FALSE);
	m_btnBrowse.EnableWindow(FALSE);
	m_edProcPath.EnableWindow(FALSE);
	
	m_edWndClass.EnableWindow(TRUE);
	m_edWndName.EnableWindow(TRUE);
	m_btnFindWindow.EnableWindow(TRUE);
	return true;
}
int CImHookProcessDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	return 0;
}

void CImHookProcessDlg::OnDestroy()
{
	CDialog::OnDestroy();
	WSACleanup();
}



void CImHookProcessDlg::onUnHook()
{
	m_HookedWnd == NULL;
	m_btnBrowse.EnableWindow(TRUE);
	m_btnCreateProc.EnableWindow(TRUE);
	m_edProcPath.EnableWindow(TRUE);
	
	m_btnFindWindow.EnableWindow(FALSE);
}

LRESULT CImHookProcessDlg::onHookedDestory(WPARAM wParam, LPARAM lParam)
{
	OutputDebugStringW(L"@@@@@@@ onHookedDestory called!!!");
	this->onUnHook();
	return S_OK;
}


void CImHookProcessDlg::onBrowseProcPath()
{
	WCHAR curDic[MAX_PATH] = {0};
	GetCurrentDirectoryW(MAX_PATH, curDic);
	OPENFILENAME openfn;
	WCHAR cFname[256];
	WCHAR szFilterOpn[]=TEXT("Executable files (*.exe)\0*.exe\0Dynamic Link Libraries (*.dll)\0*.dll\0OLE-ActiveX Controls (*.ocx)\0*.ocx\0Screen Savers (*.scr)\0*.scr\0All files (*.*)\0*.*\0\0");
	DWORD nFilterIndex=1;
	cFname[0]=0x00;
	ZeroMemory(&openfn, sizeof(openfn));
	openfn.hwndOwner=GetActiveWindow()->GetSafeHwnd();
	openfn.lpstrFile=cFname;
	openfn.nMaxFile=sizeof(cFname);
	openfn.lStructSize=sizeof(openfn);
	openfn.lpstrFilter=szFilterOpn; 
	openfn.nFilterIndex=nFilterIndex;
	//openfn.lpstrInitialDir=szCurDir;
	openfn.Flags=OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_LONGNAMES | OFN_HIDEREADONLY;
	BOOL hr = GetOpenFileName(&openfn );
	SetCurrentDirectoryW(curDic);
	if (!hr)
	{
		return ;
	}
	m_edProcPath.SetWindowText(openfn.lpstrFile);
	
}

void CImHookProcessDlg::onDetourCreateProc()
{
	CString path;
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	char detourDllPath[MAX_PATH] = {0};
	GetCurrentDirectoryA(MAX_PATH, (LPSTR)detourDllPath);
	sprintf_s(detourDllPath, MAX_PATH, "%s\\detoured.dll\0",detourDllPath);

	char dllName[MAX_PATH] = {0};
	GetCurrentDirectoryA(MAX_PATH, (LPSTR)dllName);
	sprintf_s(dllName, MAX_PATH, "%s\\hook.dll\0",dllName);


	ZeroMemory(&si, sizeof(si));
	ZeroMemory(&pi, sizeof(pi));

	si.cb = sizeof(si);
	m_edProcPath.GetWindowText(path);
	
	DWORD dwFlags = CREATE_DEFAULT_ERROR_MODE;
	BOOL hr = DetourCreateProcessWithDll(NULL, (LPWSTR)(LPCWSTR)path,
		NULL, NULL, TRUE, dwFlags, NULL, NULL,
		&si, &pi, detourDllPath, dllName, NULL);
	Sleep(2500);
	if (hr )
	{
		m_pApp->WriteProfileString(L"MySetting",L"CreateProcPath",path);
		HWND cWnd;
		HOOKAPI::GetHookClient(cWnd);

		m_HookedWnd = FromHandle(cWnd);
		onWindowHooked();
	}
}


void CImHookProcessDlg::onFindWindow()
{
	CString strClassName, strWindowName;
	m_edWndClass.GetWindowText(strClassName);
	m_edWndName.GetWindowText(strWindowName);
	CWnd* hwnd = FindWindow(strClassName, strWindowName);
	if (hwnd == NULL)
	{
		return ;
	}
	m_HookedWnd = hwnd;
	HOOKAPI::SetHookClient(hwnd->GetSafeHwnd());

	m_pApp->WriteProfileString(L"MySetting",L"HookedClassName",strClassName);
	m_pApp->WriteProfileString(L"MySetting",L"HookedWndName",strWindowName);
}

void CImHookProcessDlg::OnBnClickedCkeditwarp()
{
	if (m_HookedWnd == NULL)
		return ;
	int checked = m_ckEditWarp.GetCheck();
	OutputDebugStringW(L"@@@@@ Send HOOKED_ENABLEEDITWARP_LOW Message!! \n");
	::PostMessageW(m_HookedWnd->GetSafeHwnd(),HOOKED_ENABLEEDITWARP_LOW, checked, NULL);
	
}

void CImHookProcessDlg::OnBnClickedChkEdittts()
{
	if (m_HookedWnd == NULL)
		return ;
	int checked = m_ckEditTTS.GetCheck();
	OutputDebugStringW(L"@@@@@ Send HOOKED_ENABLEEDITTTS_LOW Message!! \n");
	::PostMessageW(m_HookedWnd->GetSafeHwnd(),HOOKED_ENABLEEDITTTS_LOW, checked, NULL);
}

void CImHookProcessDlg::OnClose()
{
	// TODO: Add your message handler code here and/or call default
	if (m_HookedWnd != NULL)
	{
		::PostMessageW(m_HookedWnd->GetSafeHwnd(), WM_CLOSE, NULL, NULL);
	}
	CDialog::OnClose();
}

void CImHookProcessDlg::OnBnClickedCheck1()
{
	if (m_HookedWnd == NULL)
		return ;
	int checked = m_ckEditWarpHigh.GetCheck();
	OutputDebugStringW(L"@@@@@ Send HOOKED_ENABLEEDITWARP_HIGH Message!! \n");
	::PostMessageW(m_HookedWnd->GetSafeHwnd(),HOOKED_ENABLEEDITWARP_HIGH, checked, NULL);
}

void CImHookProcessDlg::OnBnClickedCheck2()
{
	if (m_HookedWnd == NULL)
		return ;
	int checked = m_ckEditTTSHigh.GetCheck();
	OutputDebugStringW(L"@@@@@ Send HOOKED_ENABLEEDITTTS_HIGH Message!! \n");
	::PostMessageW(m_HookedWnd->GetSafeHwnd(),HOOKED_ENABLEEDITTTS_HIGH, checked, NULL);
}


void CImHookProcessDlg::OnBtnListenClicked()
{
	UpdateData(TRUE);
	WCHAR strPortNum[MAX_PATH] = {0};
	int portNum = 0;
	m_edPort.GetWindowText(strPortNum, MAX_PATH);

	swscanf_s(strPortNum, L"%d", &portNum);
	if (m_sListener != NULL)
	{
		delete m_sListener;
		m_sListener = NULL;
	}
	m_sListener = new ImSocket(this);
	BOOL ret = m_sListener->Create(portNum); 
	if(m_sListener->Listen()==FALSE)
	{
		DWORD err = GetLastError();
		WCHAR str[MAX_PATH];
		swprintf_s(str, MAX_PATH,L"Unable to Listen on that port,please try another port.\n \
								  Error Code = %d",err);
		AfxMessageBox(str);
		m_sListener->Close(); 
		return;			
	}
	m_txtStatus.SetWindowText(L"Listening For Connections!!!");
	UpdateData(FALSE);
	m_edPort.EnableWindow(FALSE);
	m_btnListen.EnableWindow(FALSE);
	m_btnStop.EnableWindow(TRUE); 
	m_pApp->WriteProfileInt(L"MySetting",L"SocketPort",portNum);
}
LRESULT CImHookProcessDlg::OnSocketReceive(WPARAM wParam, LPARAM lParam)
{
	char *pBuf =new char [1025];
	WCHAR strData[MAX_PATH] = {0};
	int iLen;
	iLen=m_sConnected->Receive(pBuf,1024);
	if(iLen==SOCKET_ERROR)
	{
		AfxMessageBox(L"Could not Receieve");
	}
	else
	{
		pBuf[iLen] = NULL;	
		UpdateData(FALSE);
		//m_sConnected.Send(pBuf, iLen);
		
		if (iLen == STData::STDataSIZE)
		{
			STData recData;
			recData.FromString(pBuf);
			if (recData.size != STData.STDataSIZE)
			{
				delete pBuf;
				return E_FAIL;
			}
			switch (recData.cmd)
			{
			case STData::SETTTS_L:
				HOOKAPI::SetTTSRegion_Low(recData.v1_x, recData.v1_y, recData.v2_x, recData.v2_y,
					recData.v3_x, recData.v3_y, recData.v4_x, recData.v4_y);
				swprintf_s(strData, MAX_PATH, L"SETTTS_L, (%.1f, %.1f), (%.1f, %.1f), (%.1f, %.1f), (%.1f, %.1f) \n",
					recData.v1_x, recData.v1_y, recData.v2_x, recData.v2_y,
					recData.v3_x, recData.v3_y, recData.v4_x, recData.v4_y);
				m_recData.Insert(m_recData.GetLength(), strData);
				UpdateData(FALSE);
				break;
			case STData::SETMASK_L:
				break;
			case STData::SETTTS_H:
				UpdateData(TRUE);
				HOOKAPI::SetTTSRegion_High(recData.v1_x, recData.v1_y, recData.v2_x, recData.v2_y,
					recData.v3_x, recData.v3_y, recData.v4_x, recData.v4_y);
				swprintf_s(strData, MAX_PATH, L"SETTTS_H, (%.1f, %.1f), (%.1f, %.1f), (%.1f, %.1f), (%.1f, %.1f) \n",
					recData.v1_x, recData.v1_y, recData.v2_x, recData.v2_y,
					recData.v3_x, recData.v3_y, recData.v4_x, recData.v4_y);
				m_recData.Insert(m_recData.GetLength(), strData);
				UpdateData(FALSE);
				break;
			case STData::SETMASK_H:
				break;
			default:
				break;
			}
		}
		delete pBuf;
	}
	return S_OK;
}

LRESULT CImHookProcessDlg::OnSocketAccept(WPARAM wParam, LPARAM lParam)
{
	CString strIP;
	UINT port;
	if (m_sConnected != NULL)
	{
		delete m_sConnected;
		m_sConnected = NULL;	
	}
	m_sConnected = new ImSocket(this);
	if(m_sListener->Accept(*m_sConnected))
	{
		m_sConnected->GetSockName(strIP,port);
		m_txtStatus.SetWindowText(L"Client Connected,IP :"+ strIP);
		
		//m_sConnected.Send("Connected To Server", strlen("Connected To Server")); 
		UpdateData(FALSE);
	}
	else
	{
		AfxMessageBox(L"Cannot Accept Connection");
	}
	return S_OK;
}

LRESULT CImHookProcessDlg::OnSocketClose(WPARAM wParam, LPARAM lParam)
{
	AfxMessageBox(L"Socket Is Closed!!!");
	OnBtnStopClicked(); 
	return S_OK;
}
void CImHookProcessDlg::OnBtnStopClicked()
{

	m_sConnected->Close(); 
	m_sListener->Close(); 

	m_txtStatus.SetWindowText(L"Idle!!");	
	UpdateData(FALSE);
	m_edPort.EnableWindow(TRUE);
	m_btnListen.EnableWindow(TRUE);
	m_btnStop.EnableWindow(FALSE);
}
