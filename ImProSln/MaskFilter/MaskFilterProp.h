#pragma once
#include "IMaskFilter.h"
#include "MFCBasePropertyPage.h"
#include "streams.h"
#include "resource.h"
#include "afxwin.h"



class MaskFilterPropPage : public CMFCBasePropertyPage
{
	DECLARE_DYNAMIC(MaskFilterPropPage)

public:
	MaskFilterPropPage(IUnknown *pUnk);  // standard constructor
	virtual ~MaskFilterPropPage();

	// Dialog Data


protected:
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

protected:
	IMaskFilter *m_pFilter;
	bool GetSetting();
	bool ApplySetting();

public:
	// Dialog Data
	enum {IDD = IDD_MaskFilterPropPage};
	//override CBasePropertyPage Method
	virtual HRESULT OnConnect(IUnknown *pUnk);
	virtual HRESULT OnDisconnect(void);
	virtual BOOL OnReceiveMessage(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	virtual HRESULT OnActivate(void);
	virtual HRESULT OnApplyChanges(void);

	static CUnknown *WINAPI CreateInstance(LPUNKNOWN punk, HRESULT *phr);
public: //inherit from CMFCBaseProperty Page
	virtual int GetDialogResourceID() { return IDD_MaskFilterPropPage;}
	virtual int GetTitileResourceID() { return IDS_MaskFilterPropPage_Title;}


	afx_msg void OnBnClickedrablockall();
	CButton m_raBlockAll;
	CButton m_raPassAll;
	CButton m_raBlend;
	afx_msg void OnBnClickedrapassall();
	afx_msg void OnBnClickedrablend();
	CEdit m_edPath;
	CButton m_btnBrowse;
	CButton m_btnLoad;
	afx_msg void OnBnClickedbtnbrowse();
	afx_msg void OnBnClickedbtnloadmask();
	afx_msg void OnBnClickedbtnbrowse2();
	CEdit m_edARLayoutPath;
	CButton m_btnARLayoutBrowse;
	CButton m_btnARLayoutLoad;
	afx_msg void OnBnClickedbtnloadmask2();
	CButton m_ckMaskFlipY;
	afx_msg void OnBnClickedckmaskflipy();
};
