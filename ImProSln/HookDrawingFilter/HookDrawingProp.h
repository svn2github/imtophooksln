#pragma once
#include "IHookDrawingFilter.h"
#include "MFCBasePropertyPage.h"
#include "streams.h"
#include "resource.h"
#include "afxwin.h"

class HookDrawingPropPage : public CMFCBasePropertyPage
{
	DECLARE_DYNAMIC(HookDrawingPropPage)

public:
	HookDrawingPropPage(IUnknown *pUnk);  // standard constructor
	virtual ~HookDrawingPropPage();

	// Dialog Data


protected:
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

protected:
	IHookDrawingFilter *m_pFilter;
	STARTUPINFO m_si;
	PROCESS_INFORMATION m_pi;
	BOOL onWindowHooked();
	bool GetSetting();
public:
	// Dialog Data
	enum {IDD = IDD_HookDrawingPropPage};
	//override CBasePropertyPage Method
	virtual HRESULT OnConnect(IUnknown *pUnk);
	virtual HRESULT OnDisconnect(void);
	virtual BOOL OnReceiveMessage(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	virtual HRESULT OnActivate(void);
	virtual HRESULT OnApplyChanges(void);

	static CUnknown *WINAPI CreateInstance(LPUNKNOWN punk, HRESULT *phr);
public: //inherit from CMFCBaseProperty Page
	virtual int GetDialogResourceID() { return IDD_HookDrawingPropPage;}
	virtual int GetTitileResourceID() { return IDS_HookDrawingPropPage_Title;}

	CEdit m_edDetourPath;
	CButton m_btnBrowse;
	CButton m_btnCreateProc;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();

	CEdit m_edWndName;
	CEdit m_edWndClass;
	CComboBox m_cbResolution;
	afx_msg void OnCbnSelchangeCbres();
};
