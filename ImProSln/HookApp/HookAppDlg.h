// HookAppDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "HookDS.h"

// CHookAppDlg dialog
class CHookAppDlg : public CDialog
{
// Construction
public:
	CHookAppDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_HOOKAPP_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HookDS* m_pDS;


	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CButton m_btnInitDS;
	CButton m_btnUnInitDS;
	CButton m_btnPlay;
	CButton m_btnPause;
	CButton m_btnStop;
	CButton m_btnSaveGraph;
	afx_msg void OnBnClickedBtninitds();
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedBtnuninitds();
	afx_msg void OnBnClickedbtnplay();
	afx_msg void OnBnClickedbtnpause();
	afx_msg void OnBnClickedbtnstop();
	afx_msg void OnBnClickedSavegraph();
	CComboBox m_cbStream;
	CButton m_btnHookFilterProp;
	CButton m_btnHookPinProp;
	CButton m_btnWarpProp;
	CButton m_btnDXRenderProp;
	afx_msg void OnBnClickedbtnhookfilterprop();
	afx_msg void OnCbnSelchangeCbstream();
	afx_msg void OnBnClickedbtnhookpinprop();
	afx_msg void OnBnClickedbtnwarpprop();
	afx_msg void OnBnClickedbtndxrenderprop();
};
