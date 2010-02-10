
// ImProClientMFCAppDlg.h : header file
//

#pragma once

#include "afxwin.h"
#include "ARTagCameraDS.h"
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
	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtncapturecam();
	static BOOL __stdcall ARTagCallback(int numDetected, const ARMarkerInfo* markinfos, const double* matView, const double* matProj, int argc, void* argv[]);


public:
	static void CaptureCallback(IplImage *frame);
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedBtnstopcapture();
	CButton m_btnCaptureCam;
	CButton m_btnStopCapture;
	CStatic m_picCapturePreview;
	CButton m_btnStartTrack;
	ARTagCameraDS* m_pDSCam;
	afx_msg void OnBnClickedSavegraph();
	CButton m_btnPlay;
	CButton m_btnPause;
	CButton m_btnStop;
	afx_msg void OnBnClickedbtnplay();
	afx_msg void OnBnClickedbtnpause();
	afx_msg void OnBnClickedbtnstop();
	CButton m_btnSaveGraph;
};
