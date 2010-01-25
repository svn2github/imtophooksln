#pragma once
#include "IHookDrawingFilter.h"
#include "MFCBasePropertyPage.h"
#include "streams.h"
#include "resource.h"
#include "afxwin.h"
// {C160BE7D-BF4C-4c6a-8403-16A333EF7BC8}
DEFINE_GUID(CLSID_HookDrawingPropPage, 
			0xc160be7d, 0xbf4c, 0x4c6a, 0x84, 0x3, 0x16, 0xa3, 0x33, 0xef, 0x7b, 0xc8);




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
};
