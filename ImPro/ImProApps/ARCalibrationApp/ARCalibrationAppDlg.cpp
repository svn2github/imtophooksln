// ARCalibrationAppDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ARCalibrationApp.h"
#include "ARCalibrationAppDlg.h"
#include <d3dx9math.h>
#include "cv.h"
#include "highgui.h"


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
	m_detectedARMarker = NULL ;
	m_configMarker = NULL ;


	m_numConfigMarker = 0 ;
	m_CalibTimer = 1 ;
	m_itertimeNow = 0 ;
	m_numDetectedMarker = 0 ;
	m_calibBasis = 0 ;
	m_iterativeTime = 5 ;
	m_isInit = false;
	m_startCalib = false ;


	D3DXMatrixIdentity(&m_CamwarpMat);
	D3DXMatrixIdentity(&m_ARwarpMat);
	D3DXMatrixIdentity(&m_newARMat);
	D3DXMatrixIdentity(&m_newCamMat);

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

	DDX_Control(pDX, IDC_btnARTagProp, m_btnARTagProp);
	DDX_Control(pDX, IDC_btnProjSetting, m_btnProjSetting);
	DDX_Control(pDX, IDC_btnCalibOnce, m_btnCalibOnce);
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
	ON_BN_CLICKED(IDC_btnEndCalib, &CARCalibrationAppDlg::OnBnClickedbtnendcalib)
	ON_BN_CLICKED(IDC_btnARTagProp, &CARCalibrationAppDlg::OnBnClickedbtnartagprop)
	ON_BN_CLICKED(IDC_btnProjSetting, &CARCalibrationAppDlg::OnBnClickedbtnprojsetting)
	ON_BN_CLICKED(IDC_btnCalibOnce, &CARCalibrationAppDlg::OnBnClickedbtncalibonce)
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
	m_cbIterTime.AddString(L"10");
	m_cbIterTime.AddString(L"15");
	m_cbIterTime.AddString(L"20");
	m_cbIterTime.AddString(L"30");

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
	m_cbCam.SetCurSel(0);

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
	m_btnARTagProp.EnableWindow(TRUE);
	
	m_btnCamProp.EnableWindow(TRUE);
	m_btnCamWarpProp.EnableWindow(TRUE);
	m_btnCamPinProp.EnableWindow(TRUE);

    m_btnARRenderProp.EnableWindow(TRUE);

	m_btnSaveGraph.EnableWindow(TRUE);
	m_btnStartCalib.EnableWindow(FALSE);
	m_btnProjSetting.EnableWindow(TRUE);
	
}

void CARCalibrationAppDlg::OnBnClickedbtnclosecam()
{
	if (m_pCalibDS)
	{
		m_pCalibDS->CloseCamera();
		delete m_pCalibDS;
		m_pCalibDS = NULL;
	}

	m_isInit = false ;
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
	m_btnARTagProp.EnableWindow(FALSE);


	m_btnStartCalib.EnableWindow(FALSE);
	m_btnEndCalib.EnableWindow(FALSE);
	m_btnProjSetting.EnableWindow(FALSE);
	
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

	if(m_isInit == false){
		ARCalibInit();
		m_isInit = true ;
	}
	m_btnPlay.EnableWindow(FALSE);
	m_btnPause.EnableWindow(TRUE);
	m_btnStop.EnableWindow(TRUE);
	m_btnStartCalib.EnableWindow(TRUE);
	m_cbIterTime.EnableWindow(TRUE);
	m_startCalib = false ;
	m_itertimeNow = 0;
	
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
	m_btnStartCalib.EnableWindow(FALSE);
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
	m_btnStartCalib.EnableWindow(FALSE);
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
	m_startCalib = true ;
	m_itertimeNow = 0 ;
	m_pCalibDS->m_pIARWarpFilter->GetWarpMatrix(m_ARwarpMat);
	m_pCalibDS->m_pICamWarpFilter->GetWarpMatrix(m_CamwarpMat);
	
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
	m_btnARTagProp.EnableWindow(TRUE);
	m_btnProjSetting.EnableWindow(FALSE);

	SetTimer(m_CalibTimer, 500, 0);
	
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
		m_projctor = m_cbProj.GetCurSel();  // 0 : IR 1 : Color 
}

void CARCalibrationAppDlg::OnCbnSelchangecbcalibbasis()
{
	if (m_pCalibDS == NULL) 
		return ;
	m_calibBasis = m_cbCalibBasis.GetCurSel();  // 0 : camera 1 : proj
}

void CARCalibrationAppDlg::ARCalibInit(){
	
	m_itertimeNow = 0 ;
	double camMat[16] = {0};
	double distFactor[4] = {0};
	double worldScale[3] = {1};
	
	m_pCalibDS->m_pIARTagFilter->getCamera(m_camW, m_camH,camMat,distFactor);
	m_pCalibDS->m_pIARTagFilter->getWorldBasisScale(worldScale);
	
	void* argv[1] = {(void*)this};

	m_numConfigMarker = m_pCalibDS->m_pIARLayoutFilter->GetARLayoutSize() ;
	
	m_configMarker = new ConfigMarker[m_numConfigMarker];
	m_layoutConfig = new ARMultiEachMarkerInfoT[m_numConfigMarker];
	memset((void*)m_layoutConfig, 0, sizeof(ARMultiEachMarkerInfoT)* m_numConfigMarker);   //init
	memset((void*)m_configMarker, 0, sizeof(ConfigMarker)* m_numConfigMarker);

	m_detectedARMarker = new DetectedMarker[m_numConfigMarker];
	m_pCalibDS->m_pIARLayoutFilter->GetARLayoutConfig(m_layoutConfig);

	for(int index = 0 ; index < m_numConfigMarker ; index ++){
		
		D3DXMATRIX matMark, invMatY;
		D3DXMatrixIdentity(&matMark);
		D3DXMatrixScaling(&invMatY, 1, -1, 1);

		for(int row=0; row < 3; row++)
		{
			for (int col = 0; col < 4; col++)
			{
				matMark.m[col][row] = m_layoutConfig[index].trans[row][col];
			}
		}
		m_configMarker[index].id = m_layoutConfig[index].patt_id;
		m_detectedARMarker[index].id = m_layoutConfig[index].patt_id;

		
		D3DXVECTOR3 v[4] = { D3DXVECTOR3(0,0,0), D3DXVECTOR3(0, -m_layoutConfig[index].width, 0),
			D3DXVECTOR3(m_layoutConfig[index].width, -m_layoutConfig[index].width, 0), D3DXVECTOR3(m_layoutConfig[index].width, 0, 0)};

		matMark = matMark*invMatY;
		for (int i =0; i < 4; i++)
		{
			D3DXVec3TransformCoord(&v[i], &v[i], &matMark);
			m_configMarker[index].vertex[i][0] = v[i].x;
			m_configMarker[index].vertex[i][1] = v[i].y;
		}
		double tmpx , tmpy ;
		tmpx = m_configMarker[index].vertex[1][0];
		tmpy = m_configMarker[index].vertex[1][1];

		m_configMarker[index].vertex[1][0] = m_configMarker[index].vertex[3][0];
		m_configMarker[index].vertex[1][1] = m_configMarker[index].vertex[3][1];

		m_configMarker[index].vertex[3][0] = tmpx ;
		m_configMarker[index].vertex[3][1] = tmpy ;

		// trans from  0  3    to  0  1 
		//			   1  2        3  2

	}

	m_pCalibDS->SetARCallback(this->ARTagCallback, 1, argv);

}

BOOL CARCalibrationAppDlg::ARTagCallback(int numDetected, const ARMarkerInfo* markinfos, const ARMultiMarkerInfoT* config, const double* matView, const double* matProj, int argc, void* argv[])
{
	CARCalibrationAppDlg* pSelf = (CARCalibrationAppDlg*)(argv[0]);
	
	if(pSelf->m_startCalib == true ){
		pSelf->getDetectSize();
		CAutoLock lck(&pSelf->m_csdetectedTag);
		int configSize = config->marker_num ;		
		for(int index = 0 ; index < numDetected ; index ++){
			for(int j = 0  ; j < configSize ; j++){
				if(markinfos[index].id == config->marker[j].patt_id){
					pSelf->m_detectedARMarker[j].dir = markinfos[index].dir;
					pSelf->m_detectedARMarker[j].isVisible = true ;
					pSelf->m_detectedARMarker[j].id = config->marker[j].patt_id ;
					
					for (int i =0; i < 4; i++){
						pSelf->m_detectedARMarker[j].vertex[i][0] = markinfos[index].vertex[i][0]/pSelf->m_camW;
						pSelf->m_detectedARMarker[j].vertex[i][1] = markinfos[index].vertex[i][1]/pSelf->m_camH;
					}
				}
			}
		}
		
	}
	return TRUE;
}

void CARCalibrationAppDlg::Calibration(){

	CAutoLock lck(&m_csdetectedTag);
	getDetectSize();
	if(m_numDetectedMarker == 0)
		return ;
	m_itertimeNow++ ;

	float* t = (float*)malloc(4*2*m_numDetectedMarker*sizeof(float));
	float* d = (float*)malloc(4*2*m_numDetectedMarker*sizeof(float));
	int nValidDetected = 0;
	memset(t,0,4*2*m_numDetectedMarker*sizeof(float));
	memset(d,0,4*2*m_numDetectedMarker*sizeof(float));

	float s[] = {0,0,0,
				 0,0,0,
				 0,0,0};
	CvMat mat = cvMat(3,3, CV_32F, &s);

	TransDetectedMarker();

	for(int i = 0 ; i < m_numConfigMarker ; i ++){
		if(m_detectedARMarker[i].isVisible == true){
			nValidDetected++;
			t[4*2*(nValidDetected-1) + 0] = m_configMarker[i].vertex[0][0];  t[4*2*(nValidDetected-1) + 1] = m_configMarker[i].vertex[0][1];
			t[4*2*(nValidDetected-1) + 2] = m_configMarker[i].vertex[1][0];  t[4*2*(nValidDetected-1) + 3] = m_configMarker[i].vertex[1][1];
			t[4*2*(nValidDetected-1) + 4] = m_configMarker[i].vertex[2][0];  t[4*2*(nValidDetected-1) + 5] = m_configMarker[i].vertex[2][1];
			t[4*2*(nValidDetected-1) + 6] = m_configMarker[i].vertex[3][0];  t[4*2*(nValidDetected-1) + 7] = m_configMarker[i].vertex[3][1];

			d[4*2*(nValidDetected-1) + 0] = m_detectedARMarker[i].vertex[0][0];  d[4*2*(nValidDetected-1) + 1] = m_detectedARMarker[i].vertex[0][1];
			d[4*2*(nValidDetected-1) + 2] = m_detectedARMarker[i].vertex[1][0];  d[4*2*(nValidDetected-1) + 3] = m_detectedARMarker[i].vertex[1][1];
			d[4*2*(nValidDetected-1) + 4] = m_detectedARMarker[i].vertex[2][0];  d[4*2*(nValidDetected-1) + 5] = m_detectedARMarker[i].vertex[2][1];
			d[4*2*(nValidDetected-1) + 6] = m_detectedARMarker[i].vertex[3][0];  d[4*2*(nValidDetected-1) + 7] = m_detectedARMarker[i].vertex[3][1];			
		
			WCHAR str[MAX_PATH] = {0};
			for(int t = 0 ; t <4 ; t ++){
				swprintf_s(str, MAX_PATH, L"%d config %f  %f \n",i, m_configMarker[i].vertex[t][0]*m_camW,m_configMarker[i].vertex[t][1]*m_camH);
				OutputDebugStringW(str);
				swprintf_s(str, MAX_PATH, L"%d detect %f  %f \n",i ,m_detectedARMarker[i].vertex[t][0]*m_camW, m_detectedARMarker[i].vertex[t][1]*m_camH);
				OutputDebugStringW(str);
				swprintf_s(str, MAX_PATH, L"%d diff %f  %f \n",i ,m_detectedARMarker[i].vertex[t][0]*m_camW-m_configMarker[i].vertex[t][0]*m_camW, m_detectedARMarker[i].vertex[t][1]*m_camH-m_configMarker[i].vertex[t][1]*m_camH);
				OutputDebugStringW(str);

			}
		
		}
	}

	WCHAR str[MAX_PATH] = {0};
	swprintf_s(str, MAX_PATH, L"nValidDetected %d numDetected %d \n",nValidDetected,m_numDetectedMarker);
	OutputDebugStringW(str);

	CvMat configPt;
	CvMat detectedPt;
	double m_RANSIC_Threshold = 1;

	configPt = cvMat(m_numDetectedMarker*4, 2, CV_32F, t); //t: virtual space, d: camera space
	detectedPt = cvMat(m_numDetectedMarker*4, 2, CV_32F, d);
	
	if(m_calibBasis == 0) {// use cam as basis
		cvFindHomography(&configPt, &detectedPt, &mat ); // camera to virtual space
		
		WCHAR str[MAX_PATH] = {0};
		for(int t = 0 ; t <3 ; t ++){
		swprintf_s(str, MAX_PATH, L"HOMO %f  %f  %f \n", mat.data.fl[t*3+0], mat.data.fl[t*3+1], mat.data.fl[t*3+2]);
		OutputDebugStringW(str);
		}
		D3DXMatrixIdentity(&m_newARMat);
		m_newARMat._11 = mat.data.fl[0*3 + 0];
		m_newARMat._21 = mat.data.fl[0*3 + 1];
		m_newARMat._31 = mat.data.fl[0*3 + 2];

		m_newARMat._12 = mat.data.fl[1*3 + 0];
		m_newARMat._22 = mat.data.fl[1*3 + 1];
		m_newARMat._32 = mat.data.fl[1*3 + 2];

		m_newARMat._13 = mat.data.fl[2*3 + 0];
		m_newARMat._23 = mat.data.fl[2*3 + 1];
		m_newARMat._33 = mat.data.fl[2*3 + 2];

		m_ARwarpMat = m_ARwarpMat * m_newARMat ;

		m_pCalibDS->m_pIARWarpFilter->SetWarpMatrix(m_ARwarpMat);
	}
	else if(m_calibBasis == 1){  // use AR as basis
		cvFindHomography(&detectedPt, &configPt, &mat);//, CV_RANSAC,m_RANSIC_Threshold ); // camera to virtual space

		cvInvert(&mat, &mat);

		WCHAR str[MAX_PATH] = {0};
		for(int t = 0 ; t <3 ; t ++){
			swprintf_s(str, MAX_PATH, L"HOMO %f  %f  %f \n", mat.data.fl[t*3+0], mat.data.fl[t*3+1], mat.data.fl[t*3+2]);
			OutputDebugStringW(str);
		}

		D3DXMatrixIdentity(&m_newCamMat);
		m_newCamMat._11 = mat.data.fl[0*3 + 0];
		m_newCamMat._21 = mat.data.fl[0*3 + 1];
		m_newCamMat._31 = mat.data.fl[0*3 + 2];

		m_newCamMat._12 = mat.data.fl[1*3 + 0];
		m_newCamMat._22 = mat.data.fl[1*3 + 1];
		m_newCamMat._32 = mat.data.fl[1*3 + 2];

		m_newCamMat._13 = mat.data.fl[2*3 + 0];
		m_newCamMat._23 = mat.data.fl[2*3 + 1];
		m_newCamMat._33 = mat.data.fl[2*3 + 2];

		m_CamwarpMat = m_CamwarpMat * m_newCamMat; 

		m_pCalibDS->m_pICamWarpFilter->SetWarpMatrix(m_CamwarpMat);
	}

	free(t);
	free(d);

}

void CARCalibrationAppDlg::saveD3DMat(D3DXMATRIX* D3Dmat, char* fileName){
	
	float s[] = {0,0,0,
		0,0,0,
		0,0,0};
	CvMat mat = cvMat(3,3, CV_32F, &s);

	for(int x = 0 ; x < 3 ; x++)
		for(int y = 0 ; y <3 ; y++){
			mat.data.fl[x*3 + y] = D3Dmat->m[x][y] ;
		}
	cvSave(fileName,&mat);
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
	
			m_btnARWarpProp.EnableWindow(TRUE);	
			m_btnCamWarpProp.EnableWindow(TRUE);			

			m_btnSaveGraph.EnableWindow(TRUE);
			m_btnStartCalib.EnableWindow(FALSE);
			m_btnARTagProp.EnableWindow(TRUE);
			m_btnProjSetting.EnableWindow(TRUE);
			m_startCalib = false ;
			OnBnClickedbtnendcalib();
			return;
		}
		
		Calibration();
		ResetDetectedMarker();
		
	}

	CDialog::OnTimer(nIDEvent);
}

void CARCalibrationAppDlg::OnBnClickedbtnendcalib()
{
	if (m_pCalibDS == NULL)
		return;
	HRESULT hr;
	hr = m_pCalibDS->Stop();
	if (FAILED(hr))
		return;
	
	m_itertimeNow = 0 ;
	m_startCalib = false ;
	
	m_cbCam.EnableWindow(FALSE);
	m_cbCalibBasis.EnableWindow(TRUE);

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
	m_btnStartCalib.EnableWindow(FALSE);
	m_btnARTagProp.EnableWindow(TRUE);
	m_btnProjSetting.EnableWindow(TRUE);
}

void CARCalibrationAppDlg::ResetDetectedMarker(){

	memset((void*)m_detectedARMarker, 0, sizeof(DetectedMarker)* m_numConfigMarker);	

}

void CARCalibrationAppDlg::TransDetectedMarker(){

	for(int i = 0 ;i < m_numConfigMarker ; i ++){
		if(m_detectedARMarker[i].isVisible == true){
			
			double tmpV[4][2] = {0};
			switch (m_detectedARMarker[i].dir)
			{
				case 0:
					for(int h = 0 ; h < 2 ; h ++){
						tmpV[0][h] = m_detectedARMarker[i].vertex[2][h];
						tmpV[1][h] = m_detectedARMarker[i].vertex[3][h];
						tmpV[2][h] = m_detectedARMarker[i].vertex[0][h];
						tmpV[3][h] = m_detectedARMarker[i].vertex[1][h];
					}
					break;
				case 1:
					for(int h = 0 ; h < 2 ; h ++){
						tmpV[0][h] = m_detectedARMarker[i].vertex[1][h];
						tmpV[1][h] = m_detectedARMarker[i].vertex[2][h];
						tmpV[2][h] = m_detectedARMarker[i].vertex[3][h];
						tmpV[3][h] = m_detectedARMarker[i].vertex[0][h];
					}
					break;
				case 2:
					for(int h = 0 ; h < 2 ; h ++){
						tmpV[0][h] = m_detectedARMarker[i].vertex[0][h];
						tmpV[1][h] = m_detectedARMarker[i].vertex[1][h];
						tmpV[2][h] = m_detectedARMarker[i].vertex[2][h];
						tmpV[3][h] = m_detectedARMarker[i].vertex[3][h];
					}
					break;
				case 3:
					for(int h = 0 ; h < 2 ; h ++){
						tmpV[0][h] = m_detectedARMarker[i].vertex[3][h];
						tmpV[1][h] = m_detectedARMarker[i].vertex[0][h];
						tmpV[2][h] = m_detectedARMarker[i].vertex[1][h];
						tmpV[3][h] = m_detectedARMarker[i].vertex[2][h];
					}
					break;
				default:
					continue;
					break;
			}
			
			for(int index = 0 ; index < 4 ; index ++){
				m_detectedARMarker[i].vertex[index][0] = tmpV[index][0];
				m_detectedARMarker[i].vertex[index][1] = tmpV[index][1];
			}		
		}
	}
		
}
void CARCalibrationAppDlg::OnBnClickedbtnartagprop()
{
	if (m_pCalibDS == NULL)
		return;
	m_pCalibDS->ShowARTagProp();	
}

void CARCalibrationAppDlg::OnBnClickedbtnprojsetting()
{
	if (m_pCalibDS == NULL)
		return;
	m_pCalibDS->ShowProjSetProp();
	
}

void CARCalibrationAppDlg::getDetectSize(){
	CAutoLock lck(&m_csdetectedTag);
	m_numDetectedMarker = 0 ;
	for(int i = 0 ; i < m_numConfigMarker ; i ++){
		if(m_detectedARMarker[i].isVisible == true){
			 ++m_numDetectedMarker ;
		}
	}
}

void CARCalibrationAppDlg::OnBnClickedbtncalibonce()
{

	if (m_pCalibDS == NULL)
	{
		return;
	}
	if(!m_startCalib){
		m_startCalib = true ;
		m_itertimeNow = 0 ;
		m_pCalibDS->m_pIARWarpFilter->GetWarpMatrix(m_ARwarpMat);
		m_pCalibDS->m_pICamWarpFilter->GetWarpMatrix(m_CamwarpMat);
	
		m_cbCam.EnableWindow(FALSE);
		m_cbProj.EnableWindow(FALSE);
		m_cbIterTime.EnableWindow(TRUE);
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
		m_btnARTagProp.EnableWindow(TRUE);
		m_btnProjSetting.EnableWindow(FALSE);
		Calibration();
		ResetDetectedMarker();
	}
	Calibration();
	ResetDetectedMarker();
}
