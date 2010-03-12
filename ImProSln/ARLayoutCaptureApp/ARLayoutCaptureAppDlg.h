// ARLayoutCaptureAppDlg.h : header file
//

#pragma once


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
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};
