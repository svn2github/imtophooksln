// ARCalibrationAppDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "ARCalibDS.h"
#include <map>
using namespace std;

class DetectedMarker{
public :
	int id ;
	int dir ;
	bool isVisible ;
	double vertex[4][2];

	DetectedMarker() ;
	void setInvisible();
};

class ConfigMarker{
	int id ;
	double vertex[4][2];
};

// CARCalibrationAppDlg dialog
class CARCalibrationAppDlg : public CDialog
{
// Construction
public:
	CARCalibrationAppDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_ARCALIBRATIONAPP_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedbtncamprop();
	afx_msg void OnBnClickedbtnopencam();
	afx_msg void OnBnClickedbtnclosecam();
	afx_msg void OnBnClickedbtncamwarpprop();
	afx_msg void OnBnClickedbtncampinprop();
	afx_msg void OnBnClickedbtncamrenderprop();
	afx_msg void OnBnClickedbtnarprop();
	afx_msg void OnBnClickedbtnarwarpprop();
	afx_msg void OnBnClickedbtnarrenderprop();
	afx_msg void OnBnClickedbtnplay();
	afx_msg void OnBnClickedbtnpause();
	afx_msg void OnBnClickedbtnstop();
	afx_msg void OnBnClickedbtnsavegraph();
	afx_msg void OnBnClickedbtnstartcalib();
	afx_msg void OnBnClickedbtnexit();
	afx_msg void OnCbnSelchangecbitertime();
	afx_msg void OnCbnSelchangecbproj();
	afx_msg void OnCbnSelchangecbcalibbasis();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	
	CButton m_btnCamProp;
	CButton m_btnCamWarpProp;
	CButton m_btnCamPinProp;
	CButton m_btnCamRenderProp;
	CButton m_btnARRenderProp;
	CButton m_btnARWarpProp;
	CButton m_btnARProp;
	CButton m_btnPlay;
	CButton m_btnPause;
	CButton m_btnStop;
	CButton m_btnSaveGraph;
	CButton m_btnStartCalib;
	CButton m_btnOpenCam;
	CButton m_btnCloseCam;
	CButton m_btnExit;
	CButton m_btnEndCalib;
	
	CComboBox m_cbCam;
	CComboBox m_cbProj;
	CComboBox m_cbIterTime;
	CComboBox m_cbCalibBasis;
	
	

protected:
	ARCalibDS* m_pCalibDS;
	map<CString, int> m_CamDevice;



public:
	int m_itertimeNow ;
	int m_iterativeTime ;
	int m_calibBasis ;   // 0 : cam 1: proj
	int m_projctor ; // 0 : IR 1: Color
	
	D3DXMATRIX m_ARwarpMat;
	D3DXMATRIX m_CamwarpMat;
	D3DXMATRIX m_tmpMat;
	ARMultiEachMarkerInfoT* m_layoutConfig;
	DetectedMarker* m_foundARMarker ;
	UINT m_CalibTimer;
	int m_numMarker;

	void ARCalibInit();
	void Calibration();
	static BOOL __stdcall ARTagCallback(int numDetected, const ARMarkerInfo* markinfos, const ARMultiMarkerInfoT* config, const double* matView, const double* matProj, int argc, void* argv[]);


};
