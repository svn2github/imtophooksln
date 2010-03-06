#pragma once

// {D99B1E26-91D6-4c4e-B66F-71AAD8E601CC}

#include "IDXRenderer.h"
#include "MFCBasePropertyPage.h"
#include "resource.h"
#include "afxwin.h"


class DXRenderFilterProp : public CMFCBasePropertyPage
{
	DECLARE_DYNAMIC(DXRenderFilterProp)

public:
	DXRenderFilterProp(IUnknown *pUnk);  // standard constructor
	virtual ~DXRenderFilterProp();

	// Dialog Data


protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

protected:
	IDXRenderer *m_pFilter;
	bool GetSetting();
	bool ApplySetting();
public:
	// Dialog Data
	enum {IDD = IDD_DXRenderFilterProp};
	//override CBasePropertyPage Method
	virtual HRESULT OnConnect(IUnknown *pUnk);
	virtual HRESULT OnDisconnect(void);
	virtual BOOL OnReceiveMessage(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	virtual HRESULT OnActivate(void);
	virtual HRESULT OnApplyChanges(void);

	//
	static CUnknown *WINAPI CreateInstance(LPUNKNOWN punk, HRESULT *phr);
public: //inherit from CMFCBaseProperty Page
	virtual int GetDialogResourceID() { return IDD_DXRenderFilterProp;};
	virtual int GetTitileResourceID() { return IDS_DXRenderFilterProp_Title;};
	afx_msg void OnBnClickedCkhideborder();
	CButton m_ckHideBorder;
	CButton m_ckFlipX;
	CButton m_ckFlipY;
	afx_msg void OnBnClickedCkFlipx();
	afx_msg void OnBnClickedCkFlipy();
//	afx_msg void OnEnKillfocusedx();
	CEdit m_edX;
	CEdit m_edY;
	CEdit m_edWidth;
	CEdit m_edHeight;
	CButton m_ckMaxWnd;
//	afx_msg void OnEnChangeedx();
	afx_msg void OnEnKillfocusedx();
	afx_msg void OnEnKillfocusedy();
	afx_msg void OnEnKillfocusedwidth();
	afx_msg void OnEnKillfocusedheight();
	afx_msg void OnBnClickedCkmaxwnd();
//	afx_msg void OnEnUpdateedx();
//	afx_msg void OnEnChangeedx();
	afx_msg void OnEnUpdateedx();
	afx_msg void OnEnUpdateedy();
	afx_msg void OnEnUpdateedwidth();
	afx_msg void OnEnUpdateedheight();
	CButton m_ckDrawFPS;
	afx_msg void OnBnClickedCheck1();
	CButton m_raPoint;
//	afx_msg void OnBnHotItemChangeRapoint(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedRapoint();
	afx_msg void OnBnClickedRalinear();
};
