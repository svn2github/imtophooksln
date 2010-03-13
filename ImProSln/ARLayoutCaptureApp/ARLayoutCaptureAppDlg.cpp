// ARLayoutCaptureAppDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ARLayoutCaptureApp.h"
#include "ARLayoutCaptureAppDlg.h"
#include "cv.h"
#include "highgui.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CARLayoutCaptureAppDlg dialog




CARLayoutCaptureAppDlg::CARLayoutCaptureAppDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CARLayoutCaptureAppDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pDSCam = NULL;
}

void CARLayoutCaptureAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_btnOpenCamera, m_btnOpenCam);
	DDX_Control(pDX, IDC_btnDestoryCamera, m_btnCloseCam);
	DDX_Control(pDX, IDC_btnPlay, m_btnPlay);
	DDX_Control(pDX, IDC_btnPasue, m_btnPause);
	DDX_Control(pDX, IDC_btnStop, m_btnStop);
	DDX_Control(pDX, IDC_btnSaveGraph, m_btnSaveGraph);
	DDX_Control(pDX, IDC_btnARProp, m_btnARProp);
	DDX_Control(pDX, IDC_btnARWarpProp, m_btnARWarpProp);
	DDX_Control(pDX, IDC_btnDXRenderProp, m_btnDXRenderProp);
	DDX_Control(pDX, IDC_btnCamProp, m_btnCamProp);
	DDX_Control(pDX, IDC_btnCamWarp, m_btnCamWarpProp);
	DDX_Control(pDX, IDC_CamView, m_camView);
	DDX_Control(pDX, IDC_btnCamPinProp, m_btnCamPinProp);
	DDX_Control(pDX, IDC_btnLastTag, m_btnLastTag);
	DDX_Control(pDX, IDC_btnNextTag, m_btnNextTag);
	DDX_Control(pDX, IDC_txtCurTag, m_txtCurTag);
	DDX_Control(pDX, IDC_btnClear, m_btnClear);
	DDX_Control(pDX, IDC_btnCaptureBG, m_btnCaptureBG);
	DDX_Control(pDX, IDC_btnCaptureTag, m_btnCaptureTag);
	DDX_Control(pDX, IDC_cbAvgFrame, m_cbAvgFrame);
}

BEGIN_MESSAGE_MAP(CARLayoutCaptureAppDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_btnOpenCamera, &CARLayoutCaptureAppDlg::OnBnClickedbtnopencamera)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_btnDestoryCamera, &CARLayoutCaptureAppDlg::OnBnClickedbtndestorycamera)
	ON_BN_CLICKED(IDC_btnPlay, &CARLayoutCaptureAppDlg::OnBnClickedbtnplay)
	ON_BN_CLICKED(IDC_btnPasue, &CARLayoutCaptureAppDlg::OnBnClickedbtnpasue)
	ON_BN_CLICKED(IDC_btnStop, &CARLayoutCaptureAppDlg::OnBnClickedbtnstop)
	ON_BN_CLICKED(IDC_btnSaveGraph, &CARLayoutCaptureAppDlg::OnBnClickedbtnsavegraph)
	ON_BN_CLICKED(IDC_btnARProp, &CARLayoutCaptureAppDlg::OnBnClickedbtnarprop)
	ON_BN_CLICKED(IDC_btnARWarpProp, &CARLayoutCaptureAppDlg::OnBnClickedbtnarwarpprop)
	ON_BN_CLICKED(IDC_btnDXRenderProp, &CARLayoutCaptureAppDlg::OnBnClickedbtndxrenderprop)
	ON_BN_CLICKED(IDC_btnCamProp, &CARLayoutCaptureAppDlg::OnBnClickedbtncamprop)
	ON_BN_CLICKED(IDC_btnCamPinProp, &CARLayoutCaptureAppDlg::OnBnClickedbtncampinprop)
	ON_BN_CLICKED(IDC_btnCamWarp, &CARLayoutCaptureAppDlg::OnBnClickedbtncamwarp)
	ON_BN_CLICKED(IDC_btnLastTag, &CARLayoutCaptureAppDlg::OnBnClickedbtnlasttag)
	ON_BN_CLICKED(IDC_btnNextTag, &CARLayoutCaptureAppDlg::OnBnClickedbtnnexttag)
	ON_BN_CLICKED(IDC_btnClear, &CARLayoutCaptureAppDlg::OnBnClickedbtnclear)
	ON_BN_CLICKED(IDC_btnCaptureBG, &CARLayoutCaptureAppDlg::OnBnClickedbtncapturebg)
	ON_CBN_SELCHANGE(IDC_cbAvgFrame, &CARLayoutCaptureAppDlg::OnCbnSelchangecbavgframe)
END_MESSAGE_MAP()


// CARLayoutCaptureAppDlg message handlers

BOOL CARLayoutCaptureAppDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	m_btnOpenCam.EnableWindow(TRUE);
	m_btnCloseCam.EnableWindow(FALSE);
	m_hWndCaptureWnd = 0;
	m_curTag = -1;
	m_pBG = NULL;
	m_pCaptureFrame = NULL;
	m_pDiff = NULL;
	m_pTmpImage = NULL;

	m_cbAvgFrame.AddString(L"1");
	m_cbAvgFrame.AddString(L"3");
	m_cbAvgFrame.AddString(L"5");
	m_cbAvgFrame.AddString(L"10");
	m_cbAvgFrame.SetCurSel(0);
	m_nAvgFrame = 1;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CARLayoutCaptureAppDlg::OnPaint()
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
HCURSOR CARLayoutCaptureAppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CARLayoutCaptureAppDlg::OnBnClickedbtnopencamera()
{

	if (m_pDSCam != NULL)
	{
		delete m_pDSCam;
		m_pDSCam = NULL;
	}
	bool ret;
	m_hWndCaptureWnd = m_camView.GetSafeHwnd();
	m_pDSCam = new ARLayoutCameraDS();
	ret = m_pDSCam->OpenCamera(0, true);
	ret = m_pDSCam->SetVideoWindow(m_hWndCaptureWnd);

	m_btnOpenCam.EnableWindow(FALSE);
	m_btnCloseCam.EnableWindow(TRUE);

	m_btnPlay.EnableWindow(TRUE);
	m_btnPause.EnableWindow(FALSE);
	m_btnStop.EnableWindow(FALSE);

	m_btnSaveGraph.EnableWindow(TRUE);

	m_btnARProp.EnableWindow(TRUE);
	m_btnARWarpProp.EnableWindow(TRUE);
	m_btnDXRenderProp.EnableWindow(TRUE);
	m_btnCamProp.EnableWindow(TRUE);
	m_btnCamWarpProp.EnableWindow(TRUE);
	m_btnCamPinProp.EnableWindow(TRUE);

	m_btnLastTag.EnableWindow(TRUE);
	m_btnNextTag.EnableWindow(TRUE);
	m_btnClear.EnableWindow(TRUE);

	m_btnCaptureBG.EnableWindow(TRUE);
	m_btnCaptureTag.EnableWindow(TRUE);
}

void CARLayoutCaptureAppDlg::OnDestroy()
{
	CDialog::OnDestroy();
	
	if (m_pDSCam != NULL)
	{
		delete m_pDSCam;
		m_pDSCam = NULL;
	}
	if (m_pBG != NULL)
	{
		cvReleaseImage(&m_pBG);
		m_pBG = NULL;
	}
	if (m_pCaptureFrame != NULL)
	{
		cvReleaseImage(&m_pCaptureFrame);
		m_pCaptureFrame = NULL;
	}
	if (m_pDiff != NULL)
	{
		cvReleaseImage(&m_pDiff);
		m_pDiff = NULL;
	}
	if (m_pTmpImage != NULL)
	{
		cvReleaseImage(&m_pTmpImage);
		m_pTmpImage = NULL;
	}
	cvDestroyAllWindows();
}

void CARLayoutCaptureAppDlg::OnBnClickedbtndestorycamera()
{
	if (m_pDSCam)
	{
		m_pDSCam->CloseCamera();
		delete m_pDSCam;
		m_pDSCam = NULL;
	}
	m_btnOpenCam.EnableWindow(TRUE);
	m_btnCloseCam.EnableWindow(FALSE);

	m_btnPlay.EnableWindow(FALSE);
	m_btnPause.EnableWindow(FALSE);
	m_btnStop.EnableWindow(FALSE);

	m_btnSaveGraph.EnableWindow(FALSE);

	m_btnARProp.EnableWindow(FALSE);
	m_btnARWarpProp.EnableWindow(FALSE);
	m_btnDXRenderProp.EnableWindow(FALSE);
	m_btnCamProp.EnableWindow(FALSE);
	m_btnCamWarpProp.EnableWindow(FALSE);
	m_btnCamPinProp.EnableWindow(FALSE);

	m_btnLastTag.EnableWindow(FALSE);
	m_btnNextTag.EnableWindow(FALSE);
	m_btnClear.EnableWindow(FALSE);

	m_btnCaptureBG.EnableWindow(FALSE);
	m_btnCaptureTag.EnableWindow(FALSE);
}

void CARLayoutCaptureAppDlg::OnBnClickedbtnplay()
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

void CARLayoutCaptureAppDlg::OnBnClickedbtnpasue()
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

void CARLayoutCaptureAppDlg::OnBnClickedbtnstop()
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

void CARLayoutCaptureAppDlg::OnBnClickedbtnsavegraph()
{
	if (m_pDSCam == NULL)
	{
		return;
	}
	m_pDSCam->SaveGraphFile(L"test.grf");
}

void CARLayoutCaptureAppDlg::OnBnClickedbtnarprop()
{
	if (m_pDSCam == NULL)
		return;
	m_pDSCam->ShowARLayoutProp();
}

void CARLayoutCaptureAppDlg::OnBnClickedbtnarwarpprop()
{
	if (m_pDSCam == NULL)
		return;
	m_pDSCam->ShowARWarpProp();
}

void CARLayoutCaptureAppDlg::OnBnClickedbtndxrenderprop()
{
	if (m_pDSCam == NULL)
		return;
	m_pDSCam->ShowDXRenderProp();
}

void CARLayoutCaptureAppDlg::OnBnClickedbtncamprop()
{
	if (m_pDSCam == NULL)
		return;
	m_pDSCam->ShowCamProp();
}

void CARLayoutCaptureAppDlg::OnBnClickedbtncampinprop()
{
	if (m_pDSCam == NULL)
		return;
	m_pDSCam->ShowCamPinProp();
}

void CARLayoutCaptureAppDlg::OnBnClickedbtncamwarp()
{
	if (m_pDSCam == NULL)
		return;
	m_pDSCam->ShowCamWarpProp();
}

void CARLayoutCaptureAppDlg::OnBnClickedbtnlasttag()
{
	if (m_pDSCam == NULL)
		return ;
	int numMarker = m_pDSCam->GetNumMarker();
	m_curTag = (m_curTag - 1) % numMarker;
	while (m_curTag < 0)
	{
		m_curTag += numMarker;
	}
	ShowCurTag();
}

BOOL CARLayoutCaptureAppDlg::ShowCurTag()
{
	if (m_pDSCam == NULL)
		return FALSE;
	int numMarker = m_pDSCam->GetNumMarker();
	for (int i = 0; i < numMarker; i++)
	{
		if ( i != m_curTag)
		{
			m_pDSCam->SetMarkerVisible(i, FALSE);
		}
		else
		{
			m_pDSCam->SetMarkerVisible(i, TRUE);
		}
	}
	WCHAR str[MAX_PATH] = {0};
	swprintf_s(str, MAX_PATH, L"%d", m_curTag);
	m_txtCurTag.SetWindowText(str);
	return TRUE;
}
BOOL CARLayoutCaptureAppDlg::ClearTag()
{
	if (m_pDSCam == NULL)
		return FALSE;
	int numMarker = m_pDSCam->GetNumMarker();
	for (int i = 0; i < numMarker; i++)
	{
		m_pDSCam->SetMarkerVisible(i, FALSE);
	}
	return TRUE;
}

BOOL CARLayoutCaptureAppDlg::CaptureBG()
{
	int avgNum = m_nAvgFrame;
	HRESULT hr = S_OK;
	for (int i =0 ; i<avgNum; i++)
	{
		Sleep(50);
		hr = m_pDSCam->QueryFrame(m_pTmpImage);
		if (FAILED(hr))
		{
			return FALSE;
		}
		if (m_pBG == NULL)
		{
			m_pBG = cvCloneImage(m_pTmpImage);
		}
		if (i == 0)
		{
			cvZero(m_pBG);
		}
		cvAddWeighted(m_pBG, 1.0, m_pTmpImage, 1.0/avgNum, 0, m_pBG);
	}
	return TRUE;
}



void CARLayoutCaptureAppDlg::OnBnClickedbtnnexttag()
{
	if (m_pDSCam == NULL)
		return ;
	int numMarker = m_pDSCam->GetNumMarker();
	m_curTag = (m_curTag + 1) % numMarker;
	while (m_curTag < 0)
	{
		m_curTag += numMarker;
	}
	ShowCurTag();
}

void CARLayoutCaptureAppDlg::OnBnClickedbtnclear()
{	
	if (m_pDSCam == NULL)
		return ;
	ClearTag();
}

void CARLayoutCaptureAppDlg::OnBnClickedbtncapturebg()
{
	if (m_pDSCam == NULL)
		return ;
	CaptureBG();
	cvShowImage("BG", m_pBG);
	return;
}

void CARLayoutCaptureAppDlg::OnCbnSelchangecbavgframe()
{
	if (m_pDSCam == NULL)
		return ;
	int curIdx = m_cbAvgFrame.GetCurSel();
	CString strAvgFrame;
	m_cbAvgFrame.GetLBText(curIdx, strAvgFrame);
	swscanf_s(strAvgFrame, L"%d", &m_nAvgFrame);
}
