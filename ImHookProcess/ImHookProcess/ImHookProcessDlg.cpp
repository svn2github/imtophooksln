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



CImHookProcessDlg::CImHookProcessDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CImHookProcessDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_HookedWnd = NULL;
	m_pMonitorDlg = NULL;
	m_pApp = AfxGetApp();
	
}

void CImHookProcessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_EDIT3, m_edProcPath);
	DDX_Control(pDX, IDC_BUTTON3, m_btnBrowse);
	DDX_Control(pDX, IDC_BUTTON4, m_btnCreateProc);
}

BEGIN_MESSAGE_MAP(CImHookProcessDlg, CDialog)
	ON_REGISTERED_MESSAGE(HOOKED_WNDDESTORY, onHookedDestory)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON3, &CImHookProcessDlg::onBrowseProcPath)
	ON_BN_CLICKED(IDC_BUTTON4, &CImHookProcessDlg::onDetourCreateProc)
END_MESSAGE_MAP()


// CImHookProcessDlg message handlers

BOOL CImHookProcessDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	CString createProcPath;

	createProcPath = m_pApp->GetProfileString(L"MySetting", L"CreateProcPath",L"");
	m_edProcPath.SetWindowText(createProcPath);

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
	
	m_pMonitorDlg = new CDialog();
    
	m_pMonitorDlg->Create(IDD_MonitorWnd,this);
	m_pMonitorDlg->ShowWindow(SW_SHOW);
	
	SetTimer(DRAWING_TIMER_IDX, 30,0);
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
	if (m_pMonitorDlg != NULL)
	{
		delete m_pMonitorDlg;
		m_pMonitorDlg = NULL;
	}
}


void CImHookProcessDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此加入您的訊息處理常式程式碼和 (或) 呼叫預設值

	CDialog::OnTimer(nIDEvent);
	try
	{
		if (m_HookedWnd == NULL || m_pMonitorDlg == NULL)
		{
			return;
		}
		//m_HookedWnd = GetDesktopWindow();
		CDC* hookedDC = m_HookedWnd->GetDCEx(NULL, DCX_WINDOW);
		CDC* monitorDC = m_pMonitorDlg->GetDC();
		RECT rectM, rectH;
		m_pMonitorDlg->GetWindowRect(&rectM);
		m_HookedWnd->GetWindowRect(&rectH);
		StretchBlt(monitorDC->GetSafeHdc(), 0, 0, rectM.right-rectM.left, rectM.bottom-rectM.top, 
			hookedDC->GetSafeHdc(), 0, 0,rectH.right-rectH.left, rectH.bottom-rectH.top, SRCCOPY);
		return;
	}
	catch (CException* e)
	{
		return ;
	}
}

void CImHookProcessDlg::onUnHook()
{
	m_HookedWnd == NULL;
	if (m_pMonitorDlg != NULL)
		m_pMonitorDlg->DestroyWindow();
		delete m_pMonitorDlg;
		m_pMonitorDlg = NULL;
	KillTimer(DRAWING_TIMER_IDX);
	m_btnBrowse.EnableWindow(TRUE);
	m_btnCreateProc.EnableWindow(TRUE);
	m_edProcPath.EnableWindow(TRUE);
	

}

LRESULT CImHookProcessDlg::onHookedDestory(WPARAM wParam, LPARAM lParam)
{
	OutputDebugStringW(L"@@@@@@@ onHookedDestory called!!!");
	this->onUnHook();
	return S_OK;
}


void CImHookProcessDlg::onBrowseProcPath()
{
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
		HWND sWnd, cWnd;
		HOOKAPI::GetHookedWnd(sWnd, cWnd);
		if (sWnd != this->GetSafeHwnd())
		{
			OutputDebugStringW(L"@@@@ UnExpected Error!! Server hWnd didn't match!!");
			return; 
		}
		m_HookedWnd = FromHandle(cWnd);
		onWindowHooked();
		//m_btnCreateProc.EnableWindow(FALSE);
		//m_btnBrowse.EnableWindow(FALSE);
		//m_edProcPath.EnableWindow(FALSE);

		
	}

}

