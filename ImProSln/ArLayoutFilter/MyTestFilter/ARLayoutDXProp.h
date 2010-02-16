#pragma once

#include "IARLayoutFilter.h"
#include "MFCBasePropertyPage.h"
#include "streams.h"
#include "resource.h"
#include "afxwin.h"

class ARLayoutDXPropPage : public CMFCBasePropertyPage
{
	DECLARE_DYNAMIC(ARLayoutDXPropPage)

public:
	ARLayoutDXPropPage(IUnknown *pUnk);  // standard constructor
	virtual ~ARLayoutDXPropPage();

	// Dialog Data


protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

protected:
	IARLayoutDXFilter *m_pFilter;
public:
	// Dialog Data
	enum {IDD = IDD_ARLayoutDXFilterPropPage};
	//override CBasePropertyPage Method
	virtual HRESULT OnConnect(IUnknown *pUnk);
	virtual HRESULT OnDisconnect(void);
	virtual BOOL OnReceiveMessage(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	virtual HRESULT OnActivate(void);
	virtual HRESULT OnApplyChanges(void);

	static CUnknown *WINAPI CreateInstance(LPUNKNOWN punk, HRESULT *phr);
public: //inherit from CMFCBaseProperty Page
	virtual int GetDialogResourceID() { return IDD_ARLayoutDXFilterPropPage;}
	virtual int GetTitileResourceID() { return IDS_ARLayoutPropPageTitle;}

	afx_msg void OnBnClickedBtnbrowse();
	CEdit m_edFilePath;
	afx_msg void OnBnClickedBtnSave();
	afx_msg void OnBnClickedBtnLoad();
	CEdit m_edLeft;
	CEdit m_edRight;
	CEdit m_edTop;
	CEdit m_edBottom;
	afx_msg void OnBnClickedBtntest();
	CComboBox m_cbARLevel;
	afx_msg void OnCbnSelchangeCombo1();
};
