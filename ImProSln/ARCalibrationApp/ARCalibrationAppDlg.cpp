// ARCalibrationAppDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ARCalibrationApp.h"
#include "ARCalibrationAppDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CARCalibrationAppDlg dialog

DetectedMarker::DetectedMarker(){
	id = 0 ;
	for(int i = 0 ; i < 4 ; i++){
		for(int j = 0 ; j <2 ; j ++){
			vertex[i][j] = 0 ;
		}
	}
	dir = 0 ;
	isVisible = false ;
}
void DetectedMarker::setInvisible(){
	isVisible = false ;
}


CARCalibrationAppDlg::CARCalibrationAppDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CARCalibrationAppDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pCalibDS = NULL ;
	m_layoutConfig = NULL ;
	m_foundARMarker = NULL ;
	m_numMarker = 0 ;
	m_CalibTimer = 1 ;
	m_itertimeNow = 0 ;


	D3DXMatrixIdentity(&m_CamwarpMat);
	D3DXMatrixIdentity(&m_ARwarpMat);
	D3DXMatrixIdentity(&m_tmpMat);

}

void CARCalibrationAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_btnCamProp, m_btnCamProp);
	DDX_Control(pDX, IDC_btnCamWarpProp, m_btnCamWarpProp);
	DDX_Control(pDX, IDC_btnCamPinProp, m_btnCamPinProp);
	DDX_Control(pDX, IDC_btnCamRenderProp, m_btnCamRenderProp);
	DDX_Control(pDX, IDC_btnARRender, m_btnARRenderProp);
	DDX_Control(pDX, IDC_btnARWarp, m_btnARWarpProp);
	DDX_Control(pDX, IDC_btnARProp, m_btnARProp);
	DDX_Control(pDX, IDC_btnPlay, m_btnPlay);
	DDX_Control(pDX, IDC_btnPause, m_btnPause);
	DDX_Control(pDX, IDC_btnStop, m_btnStop);
	DDX_Control(pDX, IDC_btnSaveGraph, m_btnSaveGraph);
	DDX_Control(pDX, IDC_btnStartCalib, m_btnStartCalib);
	DDX_Control(pDX, IDC_btnOpenCam, m_btnOpenCam);
	DDX_Control(pDX, IDC_btnCloseCam, m_btnCloseCam);
	DDX_Control(pDX, IDC_cbCam, m_cbCam);
	DDX_Control(pDX, IDC_cbProj, m_cbProj);
	DDX_Control(pDX, IDC_cbIterTime, m_cbIterTime);
	DDX_Control(pDX, IDC_cbCalibBasis, m_cbCalibBasis);
	DDX_Control(pDX, IDC_btnExit, m_btnExit);
	DDX_Control(pDX, IDC_btnEndCalib, m_btnEndCalib);
}

BEGIN_MESSAGE_MAP(CARCalibrationAppDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_btnCamProp, &CARCalibrationAppDlg::OnBnClickedbtncamprop)
	ON_BN_CLICKED(IDC_btnOpenCam, &CARCalibrationAppDlg::OnBnClickedbtnopencam)
	ON_BN_CLICKED(IDC_btnCloseCam, &CARCalibrationAppDlg::OnBnClickedbtnclosecam)
	ON_BN_CLICKED(IDC_btnCamWarpProp, &CARCalibrationAppDlg::OnBnClickedbtncamwarpprop)
	ON_BN_CLICKED(IDC_btnCamPinProp, &CARCalibrationAppDlg::OnBnClickedbtncampinprop)
	ON_BN_CLICKED(IDC_btnCamRenderProp, &CARCalibrationAppDlg::OnBnClickedbtncamrenderprop)
	ON_BN_CLICKED(IDC_btnARProp, &CARCalibrationAppDlg::OnBnClickedbtnarprop)
	ON_BN_CLICKED(IDC_btnARWarp, &CARCalibrationAppDlg::OnBnClickedbtnarwarpprop)
	ON_BN_CLICKED(IDC_btnARRender, &CARCalibrationAppDlg::OnBnClickedbtnarrenderprop)
	ON_BN_CLICKED(IDC_btnPlay, &CARCalibrationAppDlg::OnBnClickedbtnplay)
	ON_BN_CLICKED(IDC_btnPause, &CARCalibrationAppDlg::OnBnClickedbtnpause)
	ON_BN_CLICKED(IDC_btnStop, &CARCalibrationAppDlg::OnBnClickedbtnstop)
	ON_BN_CLICKED(IDC_btnSaveGraph, &CARCalibrationAppDlg::OnBnClickedbtnsavegraph)
	ON_BN_CLICKED(IDC_btnStartCalib, &CARCalibrationAppDlg::OnBnClickedbtnstartcalib)
	ON_BN_CLICKED(IDC_btnExit, &CARCalibrationAppDlg::OnBnClickedbtnexit)
	ON_CBN_SELCHANGE(IDC_cbIterTime, &CARCalibrationAppDlg::OnCbnSelchangecbitertime)
	ON_CBN_SELCHANGE(IDC_cbProj, &CARCalibrationAppDlg::OnCbnSelchangecbproj)
	ON_CBN_SELCHANGE(IDC_cbCalibBasis, &CARCalibrationAppDlg::OnCbnSelchangecbcalibbasis)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CARCalibrationAppDlg message handlers

BOOL CARCalibrationAppDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	m_btnOpenCam.EnableWindow(TRUE);
	m_btnCloseCam.EnableWindow(FALSE);

	m_cbIterTime.AddString(L"5");
	m_cbIterTime.AddString(L"7");
	m_cbIterTime.AddString(L"10");
	m_cbIterTime.AddString(L"15");
	m_cbIterTime.AddString(L"20");

	m_cbIterTime.SetCurSel(0);
	m_iterativeTime = 5;

	m_cbProj.AddString(L"IR");
	m_cbProj.AddString(L"Color");
	m_cbProj.SetCurSel(0);
	
	m_cbCalibBasis.AddString(L"Camera");
	m_cbCalibBasis.AddString(L"Projector");
	m_cbCalibBasis.SetCurSel(0);


	int camCount = CCameraDS::CameraCount();
	m_CamDevice.clear();
	for (int i =0; i< camCount; i++)
	{
		WCHAR sName[MAX_PATH] = {0};
		CCameraDS::CameraName(i, sName, MAX_PATH);
		swprintf_s(sName, MAX_PATH, L"%s%d", sName, i);
		m_cbCam.AddString(sName);
		CString camName = sName;
		m_CamDevice[camName] = i;

	}

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CARCalibrationAppDlg::OnPaint()
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
HCURSOR CARCalibrationAppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CARCalibrationAppDlg::OnBnClickedbtnopencam()
{

	if (m_pCalibDS != NULL)
	{
		delete m_pCalibDS;
		m_pCalibDS = NULL;
	}
	bool ret;
	CString cbStr;
	int nCamID = -1;

	m_cbCam.GetLBText(m_cbCam.GetCurSel(), cbStr);
	nCamID = m_CamDevice[cbStr];

	m_pCalibDS = new ARCalibDS();
	ret = m_pCalibDS->OpenCamera(nCamID, true);


	m_cbCam.EnableWindow(FALSE);
	
	m_btnOpenCam.EnableWindow(FALSE);
	m_btnCloseCam.EnableWindow(TRUE);

	m_btnPlay.EnableWindow(TRUE);
	m_btnPause.EnableWindow(FALSE);
	m_btnStop.EnableWindow(FALSE);

	m_btnARProp.EnableWindow(TRUE);
	m_btnARWarpProp.EnableWindow(TRUE);
	m_btnCamRenderProp.EnableWindow(TRUE);
	
	m_btnCamProp.EnableWindow(TRUE);
	m_btnCamWarpProp.EnableWindow(TRUE);
	m_btnCamPinProp.EnableWindow(TRUE);

    m_btnARRenderProp.EnableWindow(TRUE);

	m_btnSaveGraph.EnableWindow(TRUE);
	m_btnStartCalib.EnableWindow(TRUE);
}

void CARCalibrationAppDlg::OnBnClickedbtnclosecam()
{
	if (m_pCalibDS)
	{
		m_pCalibDS->CloseCamera();
		delete m_pCalibDS;
		m_pCalibDS = NULL;
	}
	m_cbCam.EnableWindow(TRUE);
	m_cbProj.EnableWindow(TRUE);
	m_cbIterTime.EnableWindow(TRUE);
	m_cbCalibBasis.EnableWindow(TRUE);

	m_btnOpenCam.EnableWindow(TRUE);
	m_btnCloseCam.EnableWindow(FALSE);

	m_btnPlay.EnableWindow(FALSE);
	m_btnPause.EnableWindow(FALSE);
	m_btnStop.EnableWindow(FALSE);

	m_btnSaveGraph.EnableWindow(FALSE);

	m_btnARProp.EnableWindow(FALSE);
	m_btnARWarpProp.EnableWindow(FALSE);
	
	m_btnCamRenderProp.EnableWindow(FALSE);
	m_btnARRenderProp.EnableWindow(FALSE);
	
	m_btnCamProp.EnableWindow(FALSE);
	m_btnCamWarpProp.EnableWindow(FALSE);
	m_btnCamPinProp.EnableWindow(FALSE);

	m_btnStartCalib.EnableWindow(FALSE);
	m_btnEndCalib.EnableWindow(FALSE);
	
}


void CARCalibrationAppDlg::OnBnClickedbtncamprop()
{
	if (m_pCalibDS == NULL)
		return;
	m_pCalibDS->ShowCamProp();
}
void CARCalibrationAppDlg::OnBnClickedbtncamwarpprop()
{
	if (m_pCalibDS == NULL)
		return;
	m_pCalibDS->ShowCamWarpProp();
}

void CARCalibrationAppDlg::OnBnClickedbtncampinprop()
{
	if (m_pCalibDS == NULL)
		return;
	m_pCalibDS->ShowCamPinProp();
}

void CARCalibrationAppDlg::OnBnClickedbtncamrenderprop()
{
	if (m_pCalibDS == NULL)
		return;
	m_pCalibDS->ShowDXCamRenderProp();
}

void CARCalibrationAppDlg::OnBnClickedbtnarprop()
{
	if (m_pCalibDS == NULL)
		return;
	m_pCalibDS->ShowARProp();
}

void CARCalibrationAppDlg::OnBnClickedbtnarwarpprop()
{
	if (m_pCalibDS == NULL)
		return;
	m_pCalibDS->ShowARWarpProp();
}

void CARCalibrationAppDlg::OnBnClickedbtnarrenderprop()
{
	if (m_pCalibDS == NULL)
		return;
	m_pCalibDS->ShowDXARRenderProp();
}

void CARCalibrationAppDlg::OnBnClickedbtnplay()
{
	if (m_pCalibDS == NULL)
		return;
	HRESULT hr;
	hr = m_pCalibDS->Play();
	if (FAILED(hr))
		return;
	m_btnPlay.EnableWindow(FALSE);
	m_btnPause.EnableWindow(TRUE);
	m_btnStop.EnableWindow(TRUE);
}

void CARCalibrationAppDlg::OnBnClickedbtnpause()
{
	if (m_pCalibDS == NULL)
		return;
	HRESULT hr;
	hr = m_pCalibDS->Pause();
	if (FAILED(hr))
		return;
	m_btnPlay.EnableWindow(TRUE);
	m_btnPause.EnableWindow(FALSE);
	m_btnStop.EnableWindow(TRUE);
}

void CARCalibrationAppDlg::OnBnClickedbtnstop()
{
	if (m_pCalibDS == NULL)
		return;
	HRESULT hr;
	hr = m_pCalibDS->Stop();
	if (FAILED(hr))
		return;
	m_btnPlay.EnableWindow(TRUE);
	m_btnPause.EnableWindow(FALSE);
	m_btnStop.EnableWindow(FALSE);
}

void CARCalibrationAppDlg::OnBnClickedbtnsavegraph()
{

	if (m_pCalibDS == NULL)
	{
		return;
	}
	m_pCalibDS->SaveGraphFile(L"ARCalib.grf");
}

void CARCalibrationAppDlg::OnBnClickedbtnstartcalib()
{
	if (m_pCalibDS == NULL)
	{
		return;
	}
	m_cbCam.EnableWindow(FALSE);
	m_cbProj.EnableWindow(FALSE);
	m_cbIterTime.EnableWindow(FALSE);
	m_cbCalibBasis.EnableWindow(FALSE);

	m_btnOpenCam.EnableWindow(FALSE);
	m_btnCloseCam.EnableWindow(FALSE);

	m_btnPlay.EnableWindow(FALSE);
	m_btnPause.EnableWindow(FALSE);
	m_btnStop.EnableWindow(FALSE);

	m_btnSaveGraph.EnableWindow(FALSE);

	m_btnARProp.EnableWindow(FALSE);
	m_btnARWarpProp.EnableWindow(FALSE);

	m_btnCamRenderProp.EnableWindow(FALSE);
	m_btnARRenderProp.EnableWindow(FALSE);

	m_btnCamProp.EnableWindow(FALSE);
	m_btnCamWarpProp.EnableWindow(FALSE);
	m_btnCamPinProp.EnableWindow(FALSE);

	m_btnStartCalib.EnableWindow(FALSE);
	m_btnEndCalib.EnableWindow(TRUE);

	SetTimer(m_CalibTimer, 1000, 0);

	ARCalibInit();
	
}

void CARCalibrationAppDlg::OnBnClickedbtnexit()
{
	if(m_pCalibDS == NULL){
		exit(0);
	}
	m_pCalibDS->CloseCamera();
	delete m_pCalibDS;
	m_pCalibDS = NULL;
	exit(0);
}


void CARCalibrationAppDlg::OnCbnSelchangecbitertime()
{
	if (m_pCalibDS == NULL)
		return ;
	int iterTime = m_cbIterTime.GetCurSel();
	CString strIterTime;
	m_cbIterTime.GetLBText(iterTime, strIterTime);
	swscanf_s(strIterTime, L"%d", &m_iterativeTime);
}

void CARCalibrationAppDlg::OnCbnSelchangecbproj()   
{
	if (m_pCalibDS == NULL)
		return ;
	int proj = m_cbProj.GetCurSel();  // 0 : IR 1 : Color 
}

void CARCalibrationAppDlg::OnCbnSelchangecbcalibbasis()
{
	if (m_pCalibDS == NULL) 
		return ;
	int calibBasis = m_cbCalibBasis.GetCurSel();  // 0 : camera 1 : proj
}

void CARCalibrationAppDlg::ARCalibInit(){
	
	m_pCalibDS->m_pIARWarpFilter->GetWarpMatrix(m_ARwarpMat);
	m_pCalibDS->m_pICamWarpFilter->GetWarpMatrix(m_CamwarpMat);
	
	void* argv[1] = {(void*)this};

	m_numMarker = m_pCalibDS->m_pIARLayoutFilter->GetARLayoutSize() ;
	m_layoutConfig = new ARMultiEachMarkerInfoT[m_numMarker];
	memset((void*)m_layoutConfig, 0, sizeof(ARMultiEachMarkerInfoT)* m_numMarker);
	
	m_foundARMarker = new DetectedMarker[m_numMarker];
	m_pCalibDS->m_pIARLayoutFilter->GetARLayoutConfig(m_layoutConfig);

	m_pCalibDS->SetARCallback(this->ARTagCallback, 1, argv);

}

BOOL CARCalibrationAppDlg::ARTagCallback(int numDetected, const ARMarkerInfo* markinfos, const ARMultiMarkerInfoT* config, const double* matView, const double* matProj, int argc, void* argv[])
{
	/*WCHAR str[MAX_PATH];
	swprintf_s(str, MAX_PATH, L"@@@@@ Got ARCallback!! numDetected = %d\n ", numDetected );
	OutputDebugStringW(str);*/

	for(int i = 0 ; i < numDetected ; i ++){
		/*for(int j = 0  ; j < m_numMarker ; j++){
		}*/
	}

	return TRUE;
}

void CARCalibrationAppDlg::Calibration(){

}

void CARCalibrationAppDlg::OnTimer(UINT_PTR nIDEvent)
{
	if(nIDEvent == m_CalibTimer){
		if(m_itertimeNow == m_iterativeTime){
			KillTimer(m_CalibTimer);
			m_cbCam.EnableWindow(FALSE);

			m_btnOpenCam.EnableWindow(FALSE);
			m_btnCloseCam.EnableWindow(TRUE);

			m_btnPlay.EnableWindow(TRUE);
			m_btnPause.EnableWindow(FALSE);
			m_btnStop.EnableWindow(FALSE);

			m_btnARProp.EnableWindow(TRUE);
			m_btnARWarpProp.EnableWindow(TRUE);
			m_btnCamRenderProp.EnableWindow(TRUE);

			m_btnCamProp.EnableWindow(TRUE);
			m_btnCamWarpProp.EnableWindow(TRUE);
			m_btnCamPinProp.EnableWindow(TRUE);

			m_btnARRenderProp.EnableWindow(TRUE);

			m_btnSaveGraph.EnableWindow(TRUE);
			m_btnStartCalib.EnableWindow(TRUE);
			
			return;
		}
		m_itertimeNow++ ;
		Calibration();
	}

	CDialog::OnTimer(nIDEvent);
}
