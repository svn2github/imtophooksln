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
	DDX_Control(pDX, IDC_btnShowDiff, m_btnShowDiff);
	DDX_Control(pDX, IDC_btnCropDiff, m_btnCropDiff);
	DDX_Control(pDX, IDC_slrROIThreshold, m_slrROIThreshold);
	DDX_Control(pDX, IDC_txtROIThreshold, m_txtROIThreshold);
	DDX_Control(pDX, IDC_EDPath, m_edSavePath);
	DDX_Control(pDX, IDC_btnStartAutoCapture, m_btnStartAutoCapture);
	DDX_Control(pDX, IDC_cbCam, m_cbCam1);
	DDX_Control(pDX, IDC_btnSaveCurShot, m_btnSaveCurShot);
	DDX_Control(pDX, IDC_cbCam2, m_cbCam2);
	DDX_Control(pDX, IDC_cbCam3, m_cbCam3);
	DDX_Control(pDX, IDC_cbCam4, m_cbCam4);
	DDX_Control(pDX, IDC_btnCamProp2, m_btnCamProp2);
	DDX_Control(pDX, IDC_btnCamProp3, m_btnCamProp3);
	DDX_Control(pDX, IDC_btnCamProp4, m_btnCamProp4);
	DDX_Control(pDX, IDC_btnCamPinProp2, m_btnCamPinProp2);
	DDX_Control(pDX, IDC_btnCamPinProp3, m_btnCamPinProp3);
	DDX_Control(pDX, IDC_btnCamPinProp4, m_btnCamPinProp4);
	DDX_Control(pDX, IDC_btnCamWarp2, m_btnCamWarp2);
	DDX_Control(pDX, IDC_btnCamWarp3, m_btnCamWarp3);
	DDX_Control(pDX, IDC_btnCamWarp4, m_btnCamWarp4);
	DDX_Control(pDX, IDC_btnDXBlendProp, m_btnDXBlendProp);
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
	ON_BN_CLICKED(IDC_btnCaptureTag, &CARLayoutCaptureAppDlg::OnBnClickedbtncapturetag)
	ON_BN_CLICKED(IDC_btnShowDiff, &CARLayoutCaptureAppDlg::OnBnClickedbtnshowdiff)

	ON_NOTIFY(NM_CUSTOMDRAW, IDC_slrROIThreshold, &CARLayoutCaptureAppDlg::OnNMCustomdrawslrroithreshold)
	ON_BN_CLICKED(IDC_btnCropDiff, &CARLayoutCaptureAppDlg::OnBnClickedbtncropdiff)
	ON_BN_CLICKED(IDC_btnBrowse, &CARLayoutCaptureAppDlg::OnBnClickedbtnbrowse)
	ON_BN_CLICKED(IDC_btnStartAutoCapture, &CARLayoutCaptureAppDlg::OnBnClickedbtnstartautocapture)
	ON_WM_TIMER()

	ON_BN_CLICKED(IDC_btnSaveCurShot, &CARLayoutCaptureAppDlg::OnBnClickedbtnsavecurshot)
	ON_CBN_SELENDCANCEL(IDC_cbCam1, &CARLayoutCaptureAppDlg::OnCbnSelendcancelcbcam1)
	ON_CBN_SELCHANGE(IDC_cbCam2, &CARLayoutCaptureAppDlg::OnCbnSelchangecbcam2)
	ON_BN_CLICKED(IDC_btnCamProp2, &CARLayoutCaptureAppDlg::OnBnClickedbtncamprop2)
	ON_BN_CLICKED(IDC_btnCamPinProp2, &CARLayoutCaptureAppDlg::OnBnClickedbtncampinprop2)
	ON_BN_CLICKED(IDC_btnCamWarp2, &CARLayoutCaptureAppDlg::OnBnClickedbtncamwarp2)
	ON_CBN_SELCHANGE(IDC_cbCam3, &CARLayoutCaptureAppDlg::OnCbnSelchangecbcam3)
	ON_CBN_SELCHANGE(IDC_cbCam4, &CARLayoutCaptureAppDlg::OnCbnSelchangecbcam4)
	ON_BN_CLICKED(IDC_btnDXBlendProp, &CARLayoutCaptureAppDlg::OnBnClickedbtndxblendprop)
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
    m_pCroppedDiff = NULL;
	m_pROITmpImage = NULL;

	m_cbAvgFrame.AddString(L"1");
	m_cbAvgFrame.AddString(L"3");
	m_cbAvgFrame.AddString(L"5");
	m_cbAvgFrame.AddString(L"10");
	m_cbAvgFrame.SetCurSel(2);
	m_nAvgFrame = 5;

	int camCount = CCameraDS::CameraCount();
	m_CamDevice.clear();
	for (int i =0; i< camCount; i++)
	{
		WCHAR sName[MAX_PATH] = {0};
		CCameraDS::CameraName(i, sName, MAX_PATH);
		m_cbCam1.AddString(sName);
		m_cbCam2.AddString(sName);
		m_cbCam3.AddString(sName);
		m_cbCam4.AddString(sName);
		CString camName = sName;
		m_CamDevice[camName] = i;

	}

	if (camCount > 0)
	{
		m_cbCam1.SetCurSel(0);
	}
	m_cbCam2.SetCurSel(-1);
	m_cbCam3.SetCurSel(-1);
	m_cbCam4.SetCurSel(-1);
	m_slrROIThreshold.SetRangeMax(30, TRUE);
	m_slrROIThreshold.SetRangeMin(0, TRUE);
	m_slrROIThreshold.SetPos(5);
	m_CaptureTimer = 1;
	CString path;
	path = theApp.GetProfileString(L"MySetting",L"ARLayoutCaptureSavePath", L"");
	m_edSavePath.SetWindowText(path);
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
	CString cbStr;
	int nCamID = -1;
	
	m_cbCam1.GetLBText(m_cbCam1.GetCurSel(), cbStr);
	nCamID = m_CamDevice[cbStr];

	m_hWndCaptureWnd = m_camView.GetSafeHwnd();
	m_pDSCam = new ARLayoutCameraDS();
	ret = m_pDSCam->OpenCamera(nCamID, true);
	ret = m_pDSCam->SetVideoWindow(m_hWndCaptureWnd);

	m_cbCam1.EnableWindow(FALSE);
	m_cbCam2.EnableWindow(TRUE);
	//m_cbCam3.EnableWindow(TRUE);
	//m_cbCam4.EnableWindow(TRUE);

	m_btnOpenCam.EnableWindow(FALSE);
	m_btnCloseCam.EnableWindow(TRUE);

	m_btnPlay.EnableWindow(TRUE);
	m_btnPause.EnableWindow(FALSE);
	m_btnStop.EnableWindow(FALSE);

	m_btnSaveGraph.EnableWindow(TRUE);

	m_btnARProp.EnableWindow(TRUE);
	m_btnARWarpProp.EnableWindow(TRUE);
	m_btnDXRenderProp.EnableWindow(TRUE);
	m_btnDXBlendProp.EnableWindow(TRUE);
	m_btnCamProp.EnableWindow(TRUE);
	m_btnCamWarpProp.EnableWindow(TRUE);
	m_btnCamPinProp.EnableWindow(TRUE);

	m_btnLastTag.EnableWindow(TRUE);
	m_btnNextTag.EnableWindow(TRUE);
	m_btnClear.EnableWindow(TRUE);

	m_btnCaptureBG.EnableWindow(TRUE);
	m_btnCaptureTag.EnableWindow(TRUE);
	m_btnShowDiff.EnableWindow(TRUE);
	m_btnCropDiff.EnableWindow(TRUE);

	m_btnStartAutoCapture.EnableWindow(TRUE);
	m_btnSaveCurShot.EnableWindow(TRUE);
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
	if (m_pCroppedDiff != NULL)
	{
		cvReleaseImage(&m_pCroppedDiff);
		m_pCroppedDiff = NULL;
	}
	if (m_pTmpImage != NULL)
	{
		cvReleaseImage(&m_pTmpImage);
		m_pTmpImage = NULL;
	}
	if (m_pROITmpImage != NULL)
	{
		cvReleaseImage(&m_pROITmpImage);
		m_pROITmpImage = NULL;
	}
	cvDestroyAllWindows();
	KillTimer(m_CaptureTimer);
}

void CARLayoutCaptureAppDlg::OnBnClickedbtndestorycamera()
{
	if (m_pDSCam)
	{
		m_pDSCam->CloseCamera();
		delete m_pDSCam;
		m_pDSCam = NULL;
	}
	m_cbCam1.EnableWindow(TRUE);
	m_btnOpenCam.EnableWindow(TRUE);
	m_btnCloseCam.EnableWindow(FALSE);

	m_btnPlay.EnableWindow(FALSE);
	m_btnPause.EnableWindow(FALSE);
	m_btnStop.EnableWindow(FALSE);

	m_btnSaveGraph.EnableWindow(FALSE);

	m_btnARProp.EnableWindow(FALSE);
	m_btnARWarpProp.EnableWindow(FALSE);
	m_btnDXRenderProp.EnableWindow(FALSE);
	m_btnDXBlendProp.EnableWindow(FALSE);
	m_btnCamProp.EnableWindow(FALSE);
	m_btnCamWarpProp.EnableWindow(FALSE);
	m_btnCamPinProp.EnableWindow(FALSE);

	m_btnLastTag.EnableWindow(FALSE);
	m_btnNextTag.EnableWindow(FALSE);
	m_btnClear.EnableWindow(FALSE);

	m_btnCaptureBG.EnableWindow(FALSE);
	m_btnCaptureTag.EnableWindow(FALSE);
	m_btnShowDiff.EnableWindow(FALSE);
	m_btnCropDiff.EnableWindow(FALSE);

	m_btnStartAutoCapture.EnableWindow(FALSE);
	m_btnSaveCurShot.EnableWindow(FALSE);


	m_cbCam2.EnableWindow(FALSE);
	m_cbCam3.EnableWindow(FALSE);
	m_cbCam4.EnableWindow(FALSE);
	m_cbCam2.SetCurSel(-1);
	m_cbCam3.SetCurSel(-1);
	m_cbCam4.SetCurSel(-1);

	m_btnCamPinProp2.EnableWindow(FALSE);
	m_btnCamProp2.EnableWindow(FALSE);
	m_btnCamWarp2.EnableWindow(FALSE);

	m_btnCamPinProp3.EnableWindow(FALSE);
	m_btnCamProp3.EnableWindow(FALSE);
	m_btnCamWarp3.EnableWindow(FALSE);

	m_btnCamPinProp4.EnableWindow(FALSE);
	m_btnCamProp4.EnableWindow(FALSE);
	m_btnCamWarp4.EnableWindow(FALSE);
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
	m_pDSCam->ShowCamProp(0);
}

void CARLayoutCaptureAppDlg::OnBnClickedbtncampinprop()
{
	if (m_pDSCam == NULL)
		return;
	m_pDSCam->ShowCamPinProp(0);
}

void CARLayoutCaptureAppDlg::OnBnClickedbtncamwarp()
{
	if (m_pDSCam == NULL)
		return;
	m_pDSCam->ShowCamWarpProp(0);
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
BOOL CARLayoutCaptureAppDlg::GenerateDiff()
{
	if (m_pBG == NULL || m_pCaptureFrame == NULL ||
		m_pBG->imageSize != m_pCaptureFrame->imageSize)
	{
		return FALSE;
	}
	if (m_pDiff == NULL)
	{
		m_pDiff = cvCloneImage(m_pBG);
	}
	if (m_pDiff->imageSize != m_pBG->imageSize)
	{
		return FALSE;
	}
	cvSub(m_pBG, m_pCaptureFrame, m_pDiff);

	return TRUE;
}
BOOL CARLayoutCaptureAppDlg::ComputeDiffROI(int threshold, fRECT& roiRECT, BOOL bDrawOnDiff)
{
	if (m_pDiff == NULL)
	{
		return S_FALSE;
	}
	if (m_pROITmpImage == NULL)
	{
		m_pROITmpImage = cvCreateImage(cvSize(m_pDiff->width, m_pDiff->height), 
			IPL_DEPTH_8U, 1);
	}
	if (m_pROITmpImage->width != m_pDiff->width || 
		m_pROITmpImage->height != m_pDiff->height)
	{
		return FALSE;
	}
	if(strcmpi(m_pDiff->colorModel, "BGRA") == 0)
		cvCvtColor(m_pDiff, m_pROITmpImage, CV_BGRA2GRAY);
	else if(strcmpi(m_pDiff->colorModel, "BGR") == 0)
		cvCvtColor(m_pDiff, m_pROITmpImage, CV_BGR2GRAY);
	else if(strcmpi(m_pDiff->colorModel, "RGB") == 0) 
		cvCvtColor(m_pDiff, m_pROITmpImage, CV_RGB2GRAY);
	
	cvThreshold(m_pROITmpImage, m_pROITmpImage, threshold, 255,  CV_THRESH_BINARY);	
	CvMemStorage* storage = cvCreateMemStorage(0);
	CvSeq* cont = 0; 
	CvRect cvROIRect;
	fRECT fROIRect;
	fRECT maxROIRect;

	double maxSum = 0;

	int imgW = m_pROITmpImage->width; 
	int imgH = m_pROITmpImage->height;
	if (imgW -1 <= 0 || imgH -1 <= 0 )
	{
		cvReleaseMemStorage(&storage);
		return E_FAIL;
	}
	bool bFindContour = false;
	cvFindContours(m_pROITmpImage, storage, &cont, sizeof(CvContour), CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE );
	for( ; cont != 0; cont = cont->h_next )	{
		int count = cont->total; // This is number point in contour
		
		cvROIRect = cvContourBoundingRect(cont);

		cvSetImageROI(m_pDiff, cvROIRect);
		double roiSum = cvSumPixels(m_pDiff);
		cvResetImageROI(m_pDiff);
		if (roiSum > maxSum)
		{
			fROIRect.left = cvROIRect.x /(float) (imgW - 1);
			fROIRect.top = cvROIRect.y /(float) (imgH - 1);
			fROIRect.right = (cvROIRect.x + cvROIRect.width) / (float)(imgW -1);
			fROIRect.bottom = (cvROIRect.y + cvROIRect.height) / (float)(imgH -1);

			maxSum = roiSum;
			maxROIRect = fROIRect;
			bFindContour = true;
		}
	}
	cvReleaseMemStorage(&storage);
	if (!bFindContour )
		return FALSE;

	roiRECT = maxROIRect;
	if (bDrawOnDiff)
	{
		CvPoint p0, p1;
		p0.x = roiRECT.left * (imgW -1); p0.y = roiRECT.top * (imgH - 1);
		p1.x = roiRECT.right * (imgW -1); p1.y = roiRECT.bottom * (imgH - 1);
		cvDrawRect(m_pDiff, p0, p1, cvScalar(0, 0, 255, 255), 3);
		
	}
	return TRUE;
}
BOOL CARLayoutCaptureAppDlg::GenerateCroppedDiff(fRECT* roi)
{
	if (m_pDiff == NULL)
	{
		return S_FALSE;
	}
	if (m_pCroppedDiff == NULL)
	{
		m_pCroppedDiff = cvCloneImage(m_pDiff);
	}
	cvResetImageROI(m_pCroppedDiff);
	if (m_pDiff->imageSize != m_pCroppedDiff->imageSize)
	{
		return FALSE;
	}
	cvCopyImage(m_pDiff, m_pCroppedDiff);
	fRECT roiRECT;
	CvRect cvROIRect;
	int threshold = m_slrROIThreshold.GetPos(); 
	if(!ComputeDiffROI(threshold, roiRECT, true))
		return FALSE;
	int imgW = m_pDiff->width;
	int imgH = m_pDiff->height;
	cvROIRect.x = roiRECT.left * (imgW -1); 
	cvROIRect.y = roiRECT.top * (imgH -1); 
	cvROIRect.width = (roiRECT.right - roiRECT.left)*imgW;
	cvROIRect.height = (roiRECT.bottom - roiRECT.top)*imgH;
	cvSetImageROI(m_pCroppedDiff, cvROIRect);
	if (roi != NULL)
		*roi = roiRECT;
	return TRUE;
}

BOOL CARLayoutCaptureAppDlg::CaptureCamFrame(IplImage*& pFrame)
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
		if (pFrame == NULL)
		{
			pFrame = cvCloneImage(m_pTmpImage);
		}
		if (i == 0)
		{
			cvZero(pFrame);
		}
		cvAddWeighted(pFrame, 1.0, m_pTmpImage, 1.0/avgNum, 0, pFrame);
	}

	return TRUE;
}
BOOL CARLayoutCaptureAppDlg::CaptureBG()
{
	return CaptureCamFrame(m_pBG);
}
BOOL CARLayoutCaptureAppDlg::CaptureTag()
{
	return CaptureCamFrame(m_pCaptureFrame);
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

void CARLayoutCaptureAppDlg::OnBnClickedbtncapturetag()
{
	if (m_pDSCam == NULL)
		return ;
	CaptureTag();
	cvShowImage("Tag", m_pCaptureFrame);
}

void CARLayoutCaptureAppDlg::OnBnClickedbtnshowdiff()
{
	if (m_pDSCam == NULL)
		return ;
	GenerateDiff();
	cvShowImage("Diff", m_pDiff);
}


void CARLayoutCaptureAppDlg::OnNMCustomdrawslrroithreshold(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
	int slrPos = m_slrROIThreshold.GetPos();
	WCHAR str[MAX_PATH] = {0};
	swprintf_s(str, MAX_PATH, L"%d", slrPos);
	m_txtROIThreshold.SetWindowText(str);
}

void CARLayoutCaptureAppDlg::OnBnClickedbtncropdiff()
{
	if (m_pDSCam == NULL)
		return ;

	GenerateCroppedDiff();
	cvShowImage("Cropped Diff", m_pCroppedDiff);
}

BOOL CARLayoutCaptureAppDlg::SaveCroppedDiff(WCHAR* path)
{
	if (m_pCroppedDiff == NULL)
	{
		return FALSE;
	}
	char filename[MAX_PATH];
	wcstombs(filename, path, MAX_PATH);
	cvSaveImage(filename, m_pCroppedDiff);
	return TRUE;
}

BOOL CARLayoutCaptureAppDlg::CaptureCurrentShot()
{
	if (m_pDSCam == NULL)
		return FALSE;

	WCHAR path[MAX_PATH] = {0};
	WCHAR dirName[MAX_PATH] = {0};
	WCHAR confName[MAX_PATH] = {0};
	WCHAR imgPath[MAX_PATH] = {0};
	WCHAR shotConfPath[MAX_PATH] = {0};
	
	GetSavePath(path, dirName, confName);
	int mkdirRet = _wmkdir(dirName);
	swprintf_s(imgPath, MAX_PATH, L"%s\\%03d.png", dirName, m_curTag);

	
	fRECT roiRECT;
	ClearTag();
	Sleep(200);
	CaptureBG();

	ShowCurTag();
	Sleep(200);
	CaptureTag();
	cvShowImage("Tag", m_pCaptureFrame);
	GenerateDiff();
	cvShowImage("Diff", m_pDiff);
	GenerateCroppedDiff(&roiRECT);
	cvShowImage("Diff", m_pDiff);
	cvShowImage("Cropped Diff", m_pCroppedDiff);

	SaveCroppedDiff(imgPath);

	swprintf_s(shotConfPath, MAX_PATH, L"%s\\shot_config_%03d.txt", 
		dirName, m_curTag);
	FILE* file = NULL;
	_wfopen_s(&file, shotConfPath, L"w");
	if (file == NULL)
	{
		return FALSE;
	}

	int patt_id = m_pDSCam->GetMarkerID(m_curTag);


	fwprintf_s(file, L"\n%d %d\n%f %f %f %f \n%s \n", m_curTag, patt_id, 
		roiRECT.left, roiRECT.top, roiRECT.right, roiRECT.bottom,
		imgPath);
	if (file != NULL)
	{
		fclose(file);
		file = NULL;
	}
	return TRUE;
}
void CARLayoutCaptureAppDlg::OnBnClickedbtnbrowse()
{
	WCHAR curDic[MAX_PATH] = {0};
	GetCurrentDirectoryW(MAX_PATH, curDic);
	OPENFILENAME openfn;
	WCHAR cFname[256];
	WCHAR szFilterOpn[]=TEXT("Config files (*.txt)\0*.txt\0All files (*.*)\0*.*\0\0");
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
	openfn.Flags= OFN_PATHMUSTEXIST | OFN_LONGNAMES | OFN_HIDEREADONLY;
	BOOL hr = GetOpenFileName(&openfn );
	SetCurrentDirectoryW(curDic);
	if (!hr)
	{
		return ;
	}
	m_edSavePath.SetWindowText(openfn.lpstrFile);
}
BOOL CARLayoutCaptureAppDlg::GetSavePath(WCHAR* path, WCHAR* imageFolder, WCHAR* confName)
{
	if (path == NULL || imageFolder == NULL || confName == NULL)
		return FALSE;
	CString cstrPath;
	m_edSavePath.GetWindowText(cstrPath);
	WCHAR* pszFile = wcsrchr((WCHAR*)(LPCWSTR)cstrPath, '\\');
	pszFile++;    // Moves on from \
	// Get path
	WCHAR szPath[MAX_PATH] = L"";
	_tcsncat(szPath, cstrPath, pszFile - cstrPath);

	WCHAR* tmp = wcsrchr(pszFile, '.');
	int res = (int)(tmp - pszFile);
	WCHAR tmpConfName[MAX_PATH] = {0};
	memcpy(tmpConfName, pszFile, sizeof(WCHAR)*res);
	tmpConfName[res] = '\0';
	WCHAR dirName[MAX_PATH] = {0};
	swprintf_s(dirName, MAX_PATH, L"%s%s", szPath, tmpConfName);

	wcscpy_s(path, MAX_PATH,(WCHAR*)(LPCWSTR)cstrPath);
	wcscpy_s(imageFolder,MAX_PATH, dirName);
	wcscpy_s(confName, MAX_PATH, tmpConfName);
	return TRUE;
}
void CARLayoutCaptureAppDlg::OnBnClickedbtnstartautocapture()
{
	if (m_pDSCam == NULL)
	{
		return;
	}
	WCHAR path[MAX_PATH] = {0};
	WCHAR dirName[MAX_PATH] = {0};
	WCHAR confName[MAX_PATH] = {0};
	WCHAR bgPath[MAX_PATH] = {0};
	GetSavePath(path, dirName, confName);

	swprintf_s(bgPath, MAX_PATH, L"%s\\BG.png", dirName);
	char bgPathMbs[MAX_PATH] = {0};
	wcstombs(bgPathMbs, bgPath, MAX_PATH);

	int mkdirRet = _wmkdir(dirName);
	if (mkdirRet < 0)
		return;
	int numMarker = m_pDSCam->GetNumMarker();
	FILE* openfile = NULL;
	_wfopen_s(&openfile, path, L"w");
	fwprintf_s(openfile, L"%d \n", numMarker);
	fclose(openfile);

	m_btnOpenCam.EnableWindow(FALSE);
	m_btnCloseCam.EnableWindow(FALSE);

	m_btnPlay.EnableWindow(FALSE);
	m_btnPause.EnableWindow(FALSE);
	m_btnStop.EnableWindow(FALSE);

	m_btnSaveGraph.EnableWindow(FALSE);

	m_btnARProp.EnableWindow(FALSE);
	m_btnARWarpProp.EnableWindow(FALSE);
	m_btnDXRenderProp.EnableWindow(FALSE);
	m_btnDXBlendProp.EnableWindow(FALSE);
	m_btnCamProp.EnableWindow(FALSE);
	m_btnCamWarpProp.EnableWindow(FALSE);
	m_btnCamPinProp.EnableWindow(FALSE);

	m_btnLastTag.EnableWindow(FALSE);
	m_btnNextTag.EnableWindow(FALSE);
	m_btnClear.EnableWindow(FALSE);

	m_btnCaptureBG.EnableWindow(FALSE);
	m_btnCaptureTag.EnableWindow(FALSE);
	m_btnShowDiff.EnableWindow(FALSE);
	m_btnCropDiff.EnableWindow(FALSE);

	m_btnStartAutoCapture.EnableWindow(FALSE);
	m_btnSaveCurShot.EnableWindow(FALSE);

	m_edSavePath.EnableWindow(FALSE);

	m_cbAvgFrame.EnableWindow(FALSE);
	m_slrROIThreshold.EnableWindow(FALSE);
	

	ClearTag();
	Sleep(200);
	CaptureBG();
	cvSaveImage(bgPathMbs, m_pBG);
	m_curTag = -1;
	
	SetTimer(m_CaptureTimer, 500, 0);

	theApp.WriteProfileString(L"MySetting",L"ARLayoutCaptureSavePath", path);
}

void CARLayoutCaptureAppDlg::OnTimer(UINT_PTR nIDEvent)
{
	if (nIDEvent == m_CaptureTimer)
	{
		int numMarker = m_pDSCam->GetNumMarker();
		if (m_curTag == numMarker -1)
		{
			KillTimer(m_CaptureTimer);
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
			m_btnShowDiff.EnableWindow(TRUE);
			m_btnCropDiff.EnableWindow(TRUE);

			m_btnStartAutoCapture.EnableWindow(TRUE);
			m_btnSaveCurShot.EnableWindow(TRUE);
			m_edSavePath.EnableWindow(TRUE);

			m_cbAvgFrame.EnableWindow(TRUE);
			m_slrROIThreshold.EnableWindow(TRUE);

			cvDestroyAllWindows();
			return;
		}
		m_curTag++;
		fRECT roiRECT;

		ShowCurTag();
		Sleep(200);
		CaptureTag();
		cvShowImage("Tag", m_pCaptureFrame);
		GenerateDiff();
		cvShowImage("Diff", m_pDiff);
		GenerateCroppedDiff(&roiRECT);
		cvShowImage("Diff", m_pDiff);
		cvShowImage("Cropped Diff", m_pCroppedDiff);

		WCHAR path[MAX_PATH] = {0};
		WCHAR dirName[MAX_PATH] = {0};
		WCHAR confName[MAX_PATH] = {0};
		WCHAR imgPath[MAX_PATH] = {0};
		GetSavePath(path, dirName, confName);
		FILE* file = NULL;
		_wfopen_s(&file, path, L"r+");
		if (file == NULL)
		{
			return ;
		}
		fseek(file, 0, SEEK_END);
		
		int patt_id = m_pDSCam->GetMarkerID(m_curTag);

		swprintf_s(imgPath, MAX_PATH, L"%s\\%03d.png", dirName, m_curTag);
		fwprintf_s(file, L"\n%d %d\n%f %f %f %f \n%s \n", m_curTag, patt_id, 
			roiRECT.left, roiRECT.top, roiRECT.right, roiRECT.bottom,
			imgPath);
		if (file != NULL)
		{
			fclose(file);
			file = NULL;
		}
		SaveCroppedDiff(imgPath);
	}
	// TODO: Add your message handler code here and/or call default

	CDialog::OnTimer(nIDEvent);
}


void CARLayoutCaptureAppDlg::OnBnClickedbtnsavecurshot()
{
	CaptureCurrentShot();
}

void CARLayoutCaptureAppDlg::OnCbnSelendcancelcbcam1()
{
	// TODO: Add your control notification handler code here
}

void CARLayoutCaptureAppDlg::OnCbnSelchangecbcam2()
{
	if (m_pDSCam == NULL)
		return;
	CString cbStr;
	int nCamID = -1;
	HRESULT hr = S_OK;
	m_cbCam2.GetLBText(m_cbCam2.GetCurSel(), cbStr);
	nCamID = m_CamDevice[cbStr];

	hr = m_pDSCam->RemoveCamera(1);
	hr = m_pDSCam->AddCamera(nCamID, true);
	if (SUCCEEDED(hr))
	{
		m_btnCamPinProp2.EnableWindow(TRUE);
		m_btnCamProp2.EnableWindow(TRUE);
		m_btnCamWarp2.EnableWindow(TRUE);
		m_cbCam2.EnableWindow(FALSE);
		m_cbCam3.EnableWindow(TRUE);
	}
}

void CARLayoutCaptureAppDlg::OnBnClickedbtncamprop2()
{
	if (m_pDSCam == NULL)
		return;
	m_pDSCam->ShowCamProp(1);
}

void CARLayoutCaptureAppDlg::OnBnClickedbtncampinprop2()
{
	if (m_pDSCam == NULL)
		return;
	m_pDSCam->ShowCamPinProp(1);
}

void CARLayoutCaptureAppDlg::OnBnClickedbtncamwarp2()
{
	if (m_pDSCam == NULL)
		return;
	m_pDSCam->ShowCamWarpProp(1);
}

void CARLayoutCaptureAppDlg::OnCbnSelchangecbcam3()
{
	if (m_pDSCam == NULL)
		return;
	CString cbStr;
	int nCamID = -1;
	HRESULT hr = S_OK;
	m_cbCam3.GetLBText(m_cbCam3.GetCurSel(), cbStr);
	nCamID = m_CamDevice[cbStr];

	hr = m_pDSCam->RemoveCamera(2);
	hr = m_pDSCam->AddCamera(nCamID, true);
	if (SUCCEEDED(hr))
	{
		m_btnCamPinProp3.EnableWindow(TRUE);
		m_btnCamProp3.EnableWindow(TRUE);
		m_btnCamWarp3.EnableWindow(TRUE);
		m_cbCam3.EnableWindow(FALSE);
		m_cbCam4.EnableWindow(TRUE);
	}
}

void CARLayoutCaptureAppDlg::OnCbnSelchangecbcam4()
{
	if (m_pDSCam == NULL)
		return;
	CString cbStr;
	int nCamID = -1;
	HRESULT hr = S_OK;
	m_cbCam4.GetLBText(m_cbCam4.GetCurSel(), cbStr);
	nCamID = m_CamDevice[cbStr];

	hr = m_pDSCam->RemoveCamera(3);
	hr = m_pDSCam->AddCamera(nCamID, true);
	if (SUCCEEDED(hr))
	{
		m_btnCamPinProp4.EnableWindow(TRUE);
		m_btnCamProp4.EnableWindow(TRUE);
		m_btnCamWarp4.EnableWindow(TRUE);
		m_cbCam4.EnableWindow(FALSE);
	}
}

void CARLayoutCaptureAppDlg::OnBnClickedbtndxblendprop()
{
	if (m_pDSCam == NULL)
		return;
	m_pDSCam->ShowDXBlendProp();
}
