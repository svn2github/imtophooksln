// ImHookProcessDlg.h : header file
//

#pragma once
#include "afxwin.h"


// CImHookProcessDlg dialog
class CImHookProcessDlg : public CDialog
{
// Construction
public:
	CImHookProcessDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_IMHOOKPROCESS_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;
	CWnd* m_HookedWnd;

	CWinApp* m_pApp;
	CDialog* m_pMonitorDlg;


	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void onHookWnd();
	afx_msg LRESULT onHookedDestory(WPARAM, LPARAM);

private:
	bool onCaptureDraw();
	bool onWindowHooked();
	bool onInjectHookDLL();

public:

	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void onUnHook();
	
	afx_msg void onBrowseProcPath();
	afx_msg void onDetourCreateProc();
	CEdit m_edProcPath;
	CButton m_btnBrowse;
	CButton m_btnCreateProc;
};
