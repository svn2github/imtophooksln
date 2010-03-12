// ARLayoutCaptureAppDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "ARLayoutCameraDS.h"

// CARLayoutCaptureAppDlg dialog
class CARLayoutCaptureAppDlg : public CDialog
{
// Construction
public:
	CARLayoutCaptureAppDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_ARLAYOUTCAPTUREAPP_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	ARLayoutCameraDS* m_pDSCam;

	HICON m_hIcon;
	HWND m_hWndCaptureWnd;
	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CButton m_btnOpenCam;
	CButton m_btnCloseCam;
	CButton m_btnPlay;
	CButton m_btnPause;
	CButton m_btnStop;
	CButton m_btnSaveGraph;
	CButton m_btnARProp;
	CButton m_btnARWarpProp;
	CButton m_btnDXRenderProp;
	CButton m_btnCamProp;
	CButton m_btnCamWarpProp;
	CButton m_btnCamPinProp;
	afx_msg void OnBnClickedbtnopencamera();
	afx_msg void OnDestroy();
	CStatic m_camView;

	afx_msg void OnBnClickedbtndestorycamera();
	afx_msg void OnBnClickedbtnplay();
	afx_msg void OnBnClickedbtnpasue();
	afx_msg void OnBnClickedbtnstop();
	afx_msg void OnBnClickedbtnsavegraph();
	afx_msg void OnBnClickedbtnarprop();
	afx_msg void OnBnClickedbtnarwarpprop();
	afx_msg void OnBnClickedbtndxrenderprop();
	afx_msg void OnBnClickedbtncamprop();
	afx_msg void OnBnClickedbtncampinprop();
	afx_msg void OnBnClickedbtncamwarp();
};
