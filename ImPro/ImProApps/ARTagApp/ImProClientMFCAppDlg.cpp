
// ImProClientMFCAppDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ImProClientMFCApp.h"
#include "ImProClientMFCAppDlg.h"
#include <math.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CImProClientMFCAppDlg dialog





CImProClientMFCAppDlg::CImProClientMFCAppDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CImProClientMFCAppDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pDSCam = NULL;
}

void CImProClientMFCAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BtnCaptureCam, m_btnCaptureCam);
	DDX_Control(pDX, IDC_BtnStopCapture, m_btnStopCapture);
	DDX_Control(pDX, IDC_picCapturePreview, m_picCapturePreview);
	DDX_Control(pDX, IDC_btnPlay, m_btnPlay);
	DDX_Control(pDX, IDC_btnPause, m_btnPause);
	DDX_Control(pDX, IDC_btnStop, m_btnStop);
	DDX_Control(pDX, IDC_SaveGraph, m_btnSaveGraph);
	DDX_Control(pDX, IDC_btnShowCamProp, m_btnCamProp);
	DDX_Control(pDX, IDC_btnCamPinProp, m_btnCamPinProp);
	DDX_Control(pDX, IDC_btnARProp, m_btnARProp);
}

BEGIN_MESSAGE_MAP(CImProClientMFCAppDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BtnCaptureCam, &CImProClientMFCAppDlg::OnBnClickedBtncapturecam)
	ON_BN_CLICKED(IDC_BtnStopCapture, &CImProClientMFCAppDlg::OnBnClickedBtnstopcapture)
	ON_BN_CLICKED(IDC_SaveGraph, &CImProClientMFCAppDlg::OnBnClickedSavegraph)
	ON_BN_CLICKED(IDC_btnPlay, &CImProClientMFCAppDlg::OnBnClickedbtnplay)
	ON_BN_CLICKED(IDC_btnPause, &CImProClientMFCAppDlg::OnBnClickedbtnpause)
	ON_BN_CLICKED(IDC_btnStop, &CImProClientMFCAppDlg::OnBnClickedbtnstop)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_btnShowCamProp, &CImProClientMFCAppDlg::OnBnClickedbtnshowcamprop)
	ON_BN_CLICKED(IDC_btnCamPinProp, &CImProClientMFCAppDlg::OnBnClickedbtncampinprop)
	ON_BN_CLICKED(IDC_btnARProp, &CImProClientMFCAppDlg::OnBnClickedbtnarprop)
END_MESSAGE_MAP()


// CImProClientMFCAppDlg message handlers

BOOL CImProClientMFCAppDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	
	m_btnCaptureCam.EnableWindow(TRUE);
	m_btnStopCapture.EnableWindow(FALSE);
	m_hWndCaptureWnd = 0;
	

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CImProClientMFCAppDlg::OnPaint()
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
HCURSOR CImProClientMFCAppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CImProClientMFCAppDlg::OnBnClickedBtncapturecam()
{

	if (m_pDSCam != NULL)
	{
		delete m_pDSCam;
		m_pDSCam = NULL;
	}
	bool ret;
	m_hWndCaptureWnd = m_picCapturePreview.GetSafeHwnd();
	m_pDSCam = new ARTagCameraDS();
	ret = m_pDSCam->OpenCamera(0, true);
	ret = m_pDSCam->SetVideoWindow(m_hWndCaptureWnd);
	void* argv[1] = {(void*)this};
	m_pDSCam->SetARCallback(this->ARTagCallback, 1, argv);
	
	m_btnCaptureCam.EnableWindow(FALSE);
	m_btnStopCapture.EnableWindow(TRUE);

	m_btnPlay.EnableWindow(TRUE);
	m_btnPause.EnableWindow(FALSE);
	m_btnStop.EnableWindow(FALSE);

	m_btnSaveGraph.EnableWindow(TRUE);
	m_btnCamProp.EnableWindow(TRUE);
	m_btnCamPinProp.EnableWindow(TRUE);
	m_btnARProp.EnableWindow(TRUE);
}

void CImProClientMFCAppDlg::CaptureCallback(IplImage *frame)
{
	OutputDebugStringW(L"@@@@@ CaptureCallBack!!!!!\n");
}



void CImProClientMFCAppDlg::OnBnClickedBtnstopcapture()
{
	if (m_pDSCam)
	{
		m_pDSCam->CloseCamera();
		delete m_pDSCam;
		m_pDSCam = NULL;
	}
	m_btnCaptureCam.EnableWindow(TRUE);
	m_btnStopCapture.EnableWindow(FALSE);

	m_btnPlay.EnableWindow(FALSE);
	m_btnPause.EnableWindow(FALSE);
	m_btnStop.EnableWindow(FALSE);

	m_btnSaveGraph.EnableWindow(FALSE);
	m_btnCamProp.EnableWindow(FALSE);
	m_btnCamPinProp.EnableWindow(FALSE);
	m_btnARProp.EnableWindow(FALSE);
}


void CImProClientMFCAppDlg::OnBnClickedSavegraph()
{
	
	if (m_pDSCam == NULL)
	{
		return;
	}
	m_pDSCam->SaveGraphFile(L"test.grf");
}

void CImProClientMFCAppDlg::OnBnClickedbtnplay()
{
	if (m_pDSCam == NULL)
		return;
	HRESULT hr;
	hr = m_pDSCam->Play();
	if (FAILED(hr))
		return;
	m_btnPlay.EnableWindow(FALSE);
	m_btnPause.EnableWindow(TRUE);
	m_btnStop.EnableWindow(TRUE);
}

void CImProClientMFCAppDlg::OnBnClickedbtnpause()
{
	if (m_pDSCam == NULL)
		return;
	HRESULT hr;
	hr = m_pDSCam->Pause();
	if (FAILED(hr))
		return;
	m_btnPlay.EnableWindow(TRUE);
	m_btnPause.EnableWindow(FALSE);
	m_btnStop.EnableWindow(TRUE);
}

void CImProClientMFCAppDlg::OnBnClickedbtnstop()
{
	if (m_pDSCam == NULL)
		return;
	HRESULT hr;
	hr = m_pDSCam->Stop();
	if (FAILED(hr))
		return;
	m_btnPlay.EnableWindow(TRUE);
	m_btnPause.EnableWindow(FALSE);
	m_btnStop.EnableWindow(FALSE);
}

BOOL CImProClientMFCAppDlg::ARTagCallback(int numDetected, const ARMarkerInfo* markinfos, const ARMultiMarkerInfoT* config, const double* matView, const double* matProj, int argc, void* argv[])
{
	WCHAR str[MAX_PATH];
	swprintf_s(str, MAX_PATH, L"@@@@@ Got ARCallback!! numDetected = %d\n ", numDetected  );
	OutputDebugStringW(str);
	return TRUE;
}
void CImProClientMFCAppDlg::OnDestroy()
{
	if (m_pDSCam != NULL)
	{
		m_pDSCam->Stop();
		delete m_pDSCam;
		m_pDSCam = NULL;
	}
	CDialog::OnDestroy();
	
}

void CImProClientMFCAppDlg::OnBnClickedbtnshowcamprop()
{
	if (m_pDSCam == NULL)
		return;
	m_pDSCam->ShowCamProp();
}

void CImProClientMFCAppDlg::OnBnClickedbtncampinprop()
{
	if (m_pDSCam == NULL)
		return;
	m_pDSCam->ShowCamPinProp();
}

void CImProClientMFCAppDlg::OnBnClickedbtnarprop()
{
	if (m_pDSCam == NULL)
		return;
	m_pDSCam->ShowARProp();
}
