
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
	m_pARTracker = NULL;
	m_pDSCam = NULL;
}

void CImProClientMFCAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BtnCaptureCam, m_btnCaptureCam);
	DDX_Control(pDX, IDC_BtnStopCapture, m_btnStopCapture);
	DDX_Control(pDX, IDC_picCapturePreview, m_picCapturePreview);
	DDX_Control(pDX, IDC_btnStartTrack, m_btnStartTrack);
}

BEGIN_MESSAGE_MAP(CImProClientMFCAppDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BtnCaptureCam, &CImProClientMFCAppDlg::OnBnClickedBtncapturecam)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BtnStopCapture, &CImProClientMFCAppDlg::OnBnClickedBtnstopcapture)
	ON_BN_CLICKED(IDC_btnStartTrack, &CImProClientMFCAppDlg::OnBnClickedbtnstarttrack)
	ON_BN_CLICKED(IDC_SaveGraph, &CImProClientMFCAppDlg::OnBnClickedSavegraph)
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
/*
	int ncams = cvcamGetCamerasCount();//returns the number of available cameras in the 
	//system
	cvcamSetProperty(0, CVCAM_PROP_ENABLE, CVCAMTRUE); //Selects the 1-st found 
	//camera
	cvcamSetProperty(0, CVCAM_PROP_RENDER, CVCAMTRUE); //We¡¦ll render stream
	//from this source
	//here I assume your create a window and store it¡¦s id in MyWin variable.
	//MyWin is of type HWND on Windows and Window on linux
	m_hWndCaptureWnd = m_picCapturePreview.GetSafeHwnd();
	cvcamSetProperty(0, CVCAM_PROP_WINDOW, &m_hWndCaptureWnd);   // Selects a window for  
	//video rendering
	cvcamSetProperty(0, CVCAM_PROP_CALLBACK, CImProClientMFCAppDlg::CaptureCallback);//this callback will

	RECT rect;
	m_picCapturePreview.GetWindowRect(&rect);
	int width = rect.right - rect.left;
	int height = rect.bottom - rect.top;
	cvcamSetProperty(0,CVCAM_RNDWIDTH, &width);
	cvcamSetProperty(0,CVCAM_RNDHEIGHT, &height);

	//process every frame
	cvcamInit( );
	cvcamStart( );

*/
	if (m_pDSCam != NULL)
	{
		delete m_pDSCam;
		m_pDSCam = NULL;
	}
	bool ret;
	m_hWndCaptureWnd = m_picCapturePreview.GetSafeHwnd();
	m_pDSCam = new CCameraDS();
	ret = m_pDSCam->OpenCamera(0, true, 320, 240);
	ret = m_pDSCam->SetVideoWindow(m_hWndCaptureWnd);
	
	m_btnCaptureCam.EnableWindow(FALSE);
	m_btnStopCapture.EnableWindow(TRUE);
	
}

void CImProClientMFCAppDlg::CaptureCallback(IplImage *frame)
{
	OutputDebugStringW(L"@@@@@ CaptureCallBack!!!!!\n");
}

void CImProClientMFCAppDlg::OnDestroy()
{
	CDialog::OnDestroy();
	cvcamStop();
	cvcamExit();
	if (m_pARTracker != NULL)
	{
		delete m_pARTracker;
		m_pARTracker = NULL;
	}
	if (m_pDSCam != NULL)
	{
		delete m_pDSCam;
		m_pDSCam = NULL;
	}
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
}

void CImProClientMFCAppDlg::OnBnClickedbtnstarttrack()
{
	/*
	// TODO: Add your control notification handler code here
	if (m_hWndCaptureWnd == 0)
	{
		return;
	}
	
	int width = 0;
	int height = 0;
	int bpp = 1;
	CameraDescription camDesc;
	VidFormat vfmt;
	cvcamGetProperty(0,  CVCAM_SRCWIDTH, &width);
	cvcamGetProperty(0,  CVCAM_SRCHEIGHT, &height);
	cvcamGetProperty(0, CVCAM_DESCRIPTION, &camDesc);
	cvcamGetProperty(0, CVCAM_VIDEOFORMAT, &vfmt);
	size_t        numPixels = width*height*bpp;
	size_t        numBytesRead;
	const char    *fName = "data/markerboard_480-499.raw";
	unsigned char *cameraBuffer = new unsigned char[numPixels];
	
	//if (m_tracker == NULL)
	//	m_tracker = new ARToolKitPlus::TrackerMultiMarkerImpl<6,6,6, 1, 16>(width,height);
	// try to load a test camera image.
	// these images files are expected to be simple 8-bit raw pixel
	// data without any header. the images are expetected to have a
	// size of 320x240.
	//
	if(FILE* fp = fopen(fName, "rb"))
	{
		numBytesRead = fread(cameraBuffer, 1, numPixels, fp);
		fclose(fp);
	}
	else
	{
		printf("Failed to open %s\n", fName);
		delete cameraBuffer;
		return ;
	}

	if(numBytesRead != numPixels)
	{
		printf("Failed to read %s\n", fName);
		delete cameraBuffer;
		return ;
	}

	// create a tracker that does:
	//  - 6x6 sized marker images
	//  - samples at a maximum of 6x6
	//  - works with luminance (gray) images
	//  - can load a maximum of 1 pattern
	//  - can detect a maximum of 8 patterns in one image
	TrackerMultiMarker *tracker = NULL;//
	tracker = new TrackerMultiMarkerImpl<6,6,6, 1, 16>(width, height);

	const char* description = tracker->getDescription();
	printf("ARToolKitPlus compile-time information:\n%s\n\n", description);

	// set a logger so we can output error messages
	//
//	tracker->setLogger(&logger);
	tracker->setPixelFormat(ARToolKitPlus::PIXEL_FORMAT_LUM);

	// load a camera file. two types of camera files are supported:
	//  - Std. ARToolKit
	//  - MATLAB Camera Calibration Toolbox
	if(!tracker->init("data/LogitechPro4000.dat", "data/markerboard_480-499.cfg", 1.0f, 1000.0f))
	{
		printf("ERROR: init() failed\n");
		delete cameraBuffer;
		delete tracker;
		return ;
	}

	// the marker in the BCH test image has a thiner border...
	tracker->setBorderWidth(0.125f);

	// set a threshold. we could also activate automatic thresholding
	tracker->setThreshold(160);

	// let's use lookup-table undistortion for high-speed
	// note: LUT only works with images up to 1024x1024
	tracker->setUndistortionMode(ARToolKitPlus::UNDIST_LUT);

	// RPP is more robust than ARToolKit's standard pose estimator
	//tracker->setPoseEstimator(ARToolKitPlus::POSE_ESTIMATOR_RPP);

	// switch to simple ID based markers
	// use the tool in tools/IdPatGen to generate markers
	tracker->setMarkerMode(ARToolKitPlus::MARKER_ID_SIMPLE);

	// do the OpenGL camera setup
	//glMatrixMode(GL_PROJECTION)
	//glLoadMatrixf(tracker->getProjectionMatrix());

	// here we go, just one call to find the camera pose
	int numDetected = tracker->calc(cameraBuffer);

	// use the result of calc() to setup the OpenGL transformation
	//glMatrixMode(GL_MODELVIEW)
	//glLoadMatrixf(tracker->getModelViewMatrix());

	printf("\n%d good Markers found and used for pose estimation.\nPose-Matrix:\n  ", numDetected);
	for(int i=0; i<16; i++)
		printf("%.2f  %s", tracker->getModelViewMatrix()[i], (i%4==3)?"\n  " : "");

	bool showConfig = true;

	if(showConfig)
	{
		const ARToolKitPlus::ARMultiMarkerInfoT *artkpConfig = tracker->getMultiMarkerConfig();
		printf("%d markers defined in multi marker cfg\n", artkpConfig->marker_num);

		printf("marker matrices:\n");
		for(int multiMarkerCounter = 0; multiMarkerCounter < artkpConfig->marker_num; multiMarkerCounter++)
		{
			printf("marker %d, id %d:\n", multiMarkerCounter, artkpConfig->marker[multiMarkerCounter].patt_id);
			for(int row = 0; row < 3; row++)
			{
				for(int column = 0; column < 4; column++)
					printf("%.2f  ", artkpConfig->marker[multiMarkerCounter].trans[row][column]);
				printf("\n");
			}
		}
	}

	delete [] cameraBuffer;
	delete tracker;
	*/
}

void CImProClientMFCAppDlg::OnBnClickedSavegraph()
{
	
	if (m_pDSCam == NULL)
	{
		return;
	}
	m_pDSCam->SaveGraphFile(L"test.grf");
}
