#pragma once

// {D99B1E26-91D6-4c4e-B66F-71AAD8E601CC}

#include "IDXBlendFilter.h"
#include "MFCBasePropertyPage.h"
#include "resource.h"
#include "afxwin.h"


class DXBlendFilterProp : public CMFCBasePropertyPage
{
	DECLARE_DYNAMIC(DXBlendFilterProp)

public:
	DXBlendFilterProp(IUnknown *pUnk);  // standard constructor
	virtual ~DXBlendFilterProp();

	// Dialog Data


protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

protected:
	IDXBlendFilter *m_pFilter;
	bool GetSetting();
	bool ApplySetting();
	
	BOOL OpenFileDialog(HWND hwndParent, WCHAR* pwcsFilter, WCHAR* pwcsDialogTitle, DWORD dwflag, WCHAR* pOutStr, BOOL saveDlg = FALSE);
public:
	// Dialog Data
	enum {IDD = IDD_DXBlendProp};
	//override CBasePropertyPage Method
	virtual HRESULT OnConnect(IUnknown *pUnk);
	virtual HRESULT OnDisconnect(void);
	virtual BOOL OnReceiveMessage(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	virtual HRESULT OnActivate(void);
	virtual HRESULT OnApplyChanges(void);

	static CUnknown *WINAPI CreateInstance(LPUNKNOWN punk, HRESULT *phr);
public: //inherit from CMFCBaseProperty Page
	virtual int GetDialogResourceID() { return IDD_DXBlendProp;};
	virtual int GetTitileResourceID() { return IDS_DXBlendProp_Title;};
	CStatic m_picWMap1;
	CEdit m_edWMap1;
	CButton m_btnBrowse1;
	CButton m_btnLoad1;
	afx_msg void OnBnClickedbtnbrowse1();
	afx_msg void OnBnClickedbtnbrowse2();
	afx_msg void OnBnClickedbtnbrowse3();
	afx_msg void OnBnClickedbtnbrowse4();
	CEdit m_edWMap2;
	CEdit m_edWMap3;
	CEdit m_edWMap4;
	afx_msg void OnBnClickedbtnload1();
	afx_msg void OnBnClickedbtnload2();
	afx_msg void OnBnClickedbtnload3();
	afx_msg void OnBnClickedbtnload4();
};
