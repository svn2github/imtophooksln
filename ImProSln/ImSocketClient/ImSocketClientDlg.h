
// ImSocketClientDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "..\ImHookProcess\ImSocket.h"

// CImSocketClientDlg dialog
class CImSocketClientDlg : public CDialog
{
// Construction
public:
	CImSocketClientDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_IMSOCKETCLIENT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;
	CWinApp* m_pApp;
	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnConnect();
	CButton m_btnConnect;
	CButton m_btnDisconnect;
	CString m_strStatus;
	CButton m_btnSetTTS_H;
	CButton m_btnSetTTS_L;

	ImSocket* m_pSocket;
	

	afx_msg void OnStnClickedTxtLv4x();
	


	afx_msg void onSliderHV1X(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void onSliderHV1Y(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void onSliderHV2X(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void onSliderHV2Y(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void onSliderHV3X(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void onSliderHV3Y(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void onSliderHV4X(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void onSliderHV4Y(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void onSliderLV1X(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void onSliderLV1Y(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void onSliderLV2X(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void onSliderLV2Y(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void onSliderLV3X(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void onSliderLV3Y(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void onSliderLV4X(NMHDR *pNMHDR, LRESULT *pResult);
	
	afx_msg void onSliderLV4Y(NMHDR *pNMHDR, LRESULT *pResult);
	CSliderCtrl m_sliderHV1X;
	CSliderCtrl m_sliderHV1Y;
	CSliderCtrl m_sliderHV2X;
	CSliderCtrl m_sliderHV2Y;
	CSliderCtrl m_sliderHV3X;
	CSliderCtrl m_sliderHV3Y;
	CSliderCtrl m_sliderHV4X;
	CSliderCtrl m_sliderHV4Y;
	CSliderCtrl m_sliderLV1X;
	CSliderCtrl m_sliderLV1Y;
	CSliderCtrl m_sliderLV2X;
	CSliderCtrl m_sliderLV2Y;
	CSliderCtrl m_sliderLV3X;
	CSliderCtrl m_sliderLV3Y;
	CSliderCtrl m_sliderLV4X;
	CSliderCtrl m_sliderLV4Y;
	CStatic m_txtHV1X;
	CStatic m_txtHV1Y;
	CStatic m_txtHV2X;
	CStatic m_txtHV2Y;
	CStatic m_txtHV3X;
	CStatic m_txtHV3Y;
	CStatic m_txtHV4X;
	CStatic m_txtHV4Y;
	CStatic m_txtLV1X;
	CStatic m_txtLV1Y;
	CStatic m_txtLV2X;
	CStatic m_txtLV2Y;
	CStatic m_txtLV3X;
	CStatic m_txtLV3Y;
	CStatic m_txtLV4X;
	CStatic m_txtLV4Y;
	CEdit m_edPort;
	CEdit m_edIP;
	CStatic m_txtStatus;
	CEdit m_edHostPort;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnDestroy();
	afx_msg void OnClickSetTTS_H();
	afx_msg void OnClickSetTTS_L();

	LRESULT OnSocketReceive(WPARAM wParam, LPARAM lParam);
	LRESULT OnSocketClose(WPARAM wParam, LPARAM lParam);
};
