// ImHookProcessDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "ImSocket.h"

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
	afx_msg void onUnHook();
	
	afx_msg void onBrowseProcPath();
	afx_msg void onDetourCreateProc();
	CEdit m_edProcPath;
	CButton m_btnBrowse;
	CButton m_btnCreateProc;
	afx_msg void onFindWindow();
	CEdit m_edWndName;
	CEdit m_edWndClass;
	CButton m_btnFindWindow;
	CStatic m_WarpBox;
	CButton m_WarpBtnV1;
	CButton m_WarpBtnV2;
	CButton m_WarpBtnV3;
	CButton m_WarpBtnV4;
	afx_msg void OnBnDropDownbtnv1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedCkeditwarp();
	CButton m_ckEditWarp;
	afx_msg void OnBnClickedChkEdittts();
	CButton m_ckEditTTS;
	afx_msg void OnClose();
	CButton m_ckEditWarpHigh;
	CButton m_ckEditTTSHigh;
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCheck2();

public: //for socket
	ImSocket* m_sListener;
	ImSocket* m_sConnected;
	CButton m_btnListen;
	CButton m_btnStop;
	CEdit m_edPort;
	CStatic m_txtStatus;
	CEdit m_edRecData;
	afx_msg void OnBtnListenClicked();
	
	LRESULT OnSocketReceive(WPARAM wParam, LPARAM lParam);
	LRESULT OnSocketClose(WPARAM wParam, LPARAM lParam);
	LRESULT OnSocketAccept(WPARAM wParam, LPARAM lParam);

	afx_msg void OnBtnStopClicked();
	CString m_recData;
};
