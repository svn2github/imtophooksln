// ARCalibrationAppDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "ARCalibDS.h"
#include <map>
using namespace std;


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
	
	CComboBox m_cbCam;
	CComboBox m_cbProj;
	CComboBox m_cbIterTime;
	CComboBox m_cbCalibBasis;
	
	int m_iterativeTime ;
	int m_calibBasis ;   // 0 : cam 1: proj
	int m_projctor ; // 0 : IR 1: Color
	

protected:
	ARCalibDS* m_pCalibDS;
	map<CString, int> m_CamDevice;

public:
	afx_msg void OnCbnSelchangecbitertime();
	CButton m_btnEndCalib;
	afx_msg void OnCbnSelchangecbproj();
	afx_msg void OnCbnSelchangecbcalibbasis();
};
