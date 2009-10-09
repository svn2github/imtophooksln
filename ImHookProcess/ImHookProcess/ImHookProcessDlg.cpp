// ImHookProcessDlg.cpp : implementation file
//
#include "stdafx.h"
#include "ImHookProcess.h"
#include "ImHookProcessDlg.h"
#include "..\\Hook\Hook.h"
#include <detours.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#define DRAWING_TIMER_IDX 1

// CImHookProcessDlg dialog
static UINT HOOKED_WNDDESTORY = ::RegisterWindowMessage(HOOKED_WNDDESTORY_MSG);
static UINT HOOKED_ENABLEEDITWARP = ::RegisterWindowMessage(HOOKED_ENABLEEDITWARP_MSG);
static UINT HOOKED_ENABLEEDITTTS = ::RegisterWindowMessage(HOOKED_ENABLEEDITTTS_MSG);
CImHookProcessDlg::CImHookProcessDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CImHookProcessDlg::IDD, pParent)
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
}

BEGIN_MESSAGE_MAP(CImHookProcessDlg, CDialog)
	ON_REGISTERED_MESSAGE(HOOKED_WNDDESTORY, onHookedDestory)
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

	createProcPath = m_pApp->GetProfileString(L"MySetting", L"CreateProcPath",L"");
	strClassName = m_pApp->GetProfileString(L"MySetting", L"HookedClassName",L"");
	strWndName= m_pApp->GetProfileString(L"MySetting", L"HookedWndName",L"");
	m_edWndClass.SetWindowText(strClassName);
	m_edWndName.SetWindowText(strWndName);
	m_edProcPath.SetWindowText(createProcPath);

	m_edWndClass.EnableWindow(FALSE);
	m_edWndName.EnableWindow(FALSE);
	m_btnFindWindow.EnableWindow(FALSE);

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
	Sleep(1000);
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

	::PostMessageW(m_HookedWnd->GetSafeHwnd(),HOOKED_ENABLEEDITWARP, checked, NULL);
	
}

void CImHookProcessDlg::OnBnClickedChkEdittts()
{
	if (m_HookedWnd == NULL)
		return ;
	int checked = m_ckEditTTS.GetCheck();

	::PostMessageW(m_HookedWnd->GetSafeHwnd(),HOOKED_ENABLEEDITTTS, checked, NULL);
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
