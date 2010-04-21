// HookAppDlg.cpp : implementation file
//

#include "stdafx.h"
#include "HookApp.h"
#include "HookAppDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHookAppDlg dialog




CHookAppDlg::CHookAppDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHookAppDlg::IDD, pParent)
{
	m_pDS = NULL;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CHookAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BtnInitDS, m_btnInitDS);
	DDX_Control(pDX, IDC_BtnUnInitDS, m_btnUnInitDS);
	DDX_Control(pDX, IDC_btnPlay, m_btnPlay);
	DDX_Control(pDX, IDC_btnPause, m_btnPause);
	DDX_Control(pDX, IDC_btnStop, m_btnStop);
	DDX_Control(pDX, IDC_SaveGraph, m_btnSaveGraph);
	DDX_Control(pDX, IDC_CBStream, m_cbStream);
	DDX_Control(pDX, IDC_btnHookFilterProp, m_btnHookFilterProp);
	DDX_Control(pDX, IDC_btnHookPinProp, m_btnHookPinProp);
	DDX_Control(pDX, IDC_btnWarpProp, m_btnWarpProp);
	DDX_Control(pDX, IDC_btnDXRenderProp, m_btnDXRenderProp);
}

BEGIN_MESSAGE_MAP(CHookAppDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BtnInitDS, &CHookAppDlg::OnBnClickedBtninitds)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BtnUnInitDS, &CHookAppDlg::OnBnClickedBtnuninitds)
	ON_BN_CLICKED(IDC_btnPlay, &CHookAppDlg::OnBnClickedbtnplay)
	ON_BN_CLICKED(IDC_btnPause, &CHookAppDlg::OnBnClickedbtnpause)
	ON_BN_CLICKED(IDC_btnStop, &CHookAppDlg::OnBnClickedbtnstop)
	ON_BN_CLICKED(IDC_SaveGraph, &CHookAppDlg::OnBnClickedSavegraph)
	ON_BN_CLICKED(IDC_btnHookFilterProp, &CHookAppDlg::OnBnClickedbtnhookfilterprop)
	ON_CBN_SELCHANGE(IDC_CBStream, &CHookAppDlg::OnCbnSelchangeCbstream)
	ON_BN_CLICKED(IDC_btnHookPinProp, &CHookAppDlg::OnBnClickedbtnhookpinprop)
	ON_BN_CLICKED(IDC_btnWarpProp, &CHookAppDlg::OnBnClickedbtnwarpprop)
	ON_BN_CLICKED(IDC_btnDXRenderProp, &CHookAppDlg::OnBnClickedbtndxrenderprop)
END_MESSAGE_MAP()


// CHookAppDlg message handlers

BOOL CHookAppDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	WCHAR str[MAX_PATH] = {0};
	for (int i = 0 ; i < NUMHOOKPIN; i++)
	{
		swprintf_s(str, MAX_PATH, L"stream %d", i);
		m_cbStream.AddString(str);
	}
	m_cbStream.SetCurSel(0);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CHookAppDlg::OnPaint()
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
HCURSOR CHookAppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CHookAppDlg::OnBnClickedBtninitds()
{
	if (m_pDS != NULL)
	{
		delete m_pDS;
		m_pDS = NULL;
	}
	m_pDS = new HookDS();
	m_pDS->InitDS();

	m_btnInitDS.EnableWindow(FALSE);
	m_btnUnInitDS.EnableWindow(TRUE);

	m_btnPlay.EnableWindow(TRUE);
	m_btnPause.EnableWindow(FALSE);
	m_btnStop.EnableWindow(FALSE);

	m_btnSaveGraph.EnableWindow(TRUE);

	m_btnHookFilterProp.EnableWindow(TRUE);
	m_btnHookPinProp.EnableWindow(TRUE);
	m_btnWarpProp.EnableWindow(TRUE);
	m_btnDXRenderProp.EnableWindow(TRUE);
}

void CHookAppDlg::OnDestroy()
{
	CDialog::OnDestroy();

	if (m_pDS != NULL)
	{
		m_pDS->Stop();
		delete m_pDS;
		m_pDS = NULL;
	}
}

void CHookAppDlg::OnBnClickedBtnuninitds()
{
	if (m_pDS != NULL)
	{
		delete m_pDS;
		m_pDS = NULL;
	}
	m_btnInitDS.EnableWindow(TRUE);
	m_btnUnInitDS.EnableWindow(FALSE);

	m_btnPlay.EnableWindow(FALSE);
	m_btnPause.EnableWindow(FALSE);
	m_btnStop.EnableWindow(FALSE);

	m_btnSaveGraph.EnableWindow(FALSE);

	m_btnHookFilterProp.EnableWindow(FALSE);
	m_btnHookPinProp.EnableWindow(FALSE);
	m_btnWarpProp.EnableWindow(FALSE);
	m_btnDXRenderProp.EnableWindow(FALSE);
}

void CHookAppDlg::OnBnClickedbtnplay()
{
	if (m_pDS == NULL)
		return;
	HRESULT hr;
	hr = m_pDS->Play();
	if (FAILED(hr))
		return;
	m_btnPlay.EnableWindow(FALSE);
	m_btnPause.EnableWindow(TRUE);
	m_btnStop.EnableWindow(TRUE);
}

void CHookAppDlg::OnBnClickedbtnpause()
{
	if (m_pDS == NULL)
		return;
	HRESULT hr;
	hr = m_pDS->Pause();
	if (FAILED(hr))
		return;
	m_btnPlay.EnableWindow(TRUE);
	m_btnPause.EnableWindow(FALSE);
	m_btnStop.EnableWindow(TRUE);
}

void CHookAppDlg::OnBnClickedbtnstop()
{
	if (m_pDS == NULL)
		return;
	HRESULT hr;
	hr = m_pDS->Stop();
	if (FAILED(hr))
		return;
	m_btnPlay.EnableWindow(TRUE);
	m_btnPause.EnableWindow(FALSE);
	m_btnStop.EnableWindow(FALSE);
}

void CHookAppDlg::OnBnClickedSavegraph()
{
	if (m_pDS == NULL)
	{
		return;
	}
	m_pDS->SaveGraphFile(L"test.grf");
}

void CHookAppDlg::OnBnClickedbtnhookfilterprop()
{
	if (m_pDS == NULL)
		return;
	m_pDS->ShowHookFilterProp();
}

void CHookAppDlg::OnCbnSelchangeCbstream()
{
}

void CHookAppDlg::OnBnClickedbtnhookpinprop()
{
	if (m_pDS == NULL)
		return;
	WCHAR str[MAX_PATH] = {0};
	m_cbStream.GetLBText(m_cbStream.GetCurSel(), str);
	int CurSel = 0;
	swscanf_s(str, L"stream %d", &CurSel);

	m_pDS->ShowHookPinProp(CurSel);
}

void CHookAppDlg::OnBnClickedbtnwarpprop()
{
	if (m_pDS == NULL)
		return;
	WCHAR str[MAX_PATH] = {0};
	m_cbStream.GetLBText(m_cbStream.GetCurSel(), str);
	int CurSel = 0;
	swscanf_s(str, L"stream %d", &CurSel);

	m_pDS->ShowWarpProp(CurSel);
}

void CHookAppDlg::OnBnClickedbtndxrenderprop()
{
	if (m_pDS == NULL)
		return;
	WCHAR str[MAX_PATH] = {0};
	m_cbStream.GetLBText(m_cbStream.GetCurSel(), str);
	int CurSel = 0;
	swscanf_s(str, L"stream %d", &CurSel);

	m_pDS->ShowDXRenderProp(CurSel);
}
