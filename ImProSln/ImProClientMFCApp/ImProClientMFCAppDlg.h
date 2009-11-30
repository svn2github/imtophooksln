
// ImProClientMFCAppDlg.h : header file
//

#pragma once
#include "cv.h"
#include "cvcam.h"
#include "highgui.h"


#include "afxwin.h"
#include "CameraDS.h"
// CImProClientMFCAppDlg dialog
class CImProClientMFCAppDlg : public CDialog
{
// Construction
public:
	CImProClientMFCAppDlg(CWnd* pParent = NULL);	// standard constructor
	
// Dialog Data
	enum { IDD = IDD_IMPROCLIENTMFCAPP_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;
	HWND m_hWndCaptureWnd;
	ARToolKitPlus::Tracker* m_pARTracker;
	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtncapturecam();
public:
	static void CaptureCallback(IplImage *frame);
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedBtnstopcapture();
	CButton m_btnCaptureCam;
	CButton m_btnStopCapture;
	CStatic m_picCapturePreview;
	CButton m_btnStartTrack;
	CCameraDS* m_pDSCam;
	afx_msg void OnBnClickedbtnstarttrack();
	afx_msg void OnBnClickedSavegraph();
};
