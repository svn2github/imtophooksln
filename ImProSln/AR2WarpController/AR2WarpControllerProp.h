#pragma once
#include "IAR2WarpController.h"
#include "MFCBasePropertyPage.h"
#include "streams.h"
#include "resource.h"
#include "afxwin.h"


class AR2WarpControllerPropertyPage : public CMFCBasePropertyPage
{
	DECLARE_DYNAMIC(AR2WarpControllerPropertyPage)

public:
	AR2WarpControllerPropertyPage(IUnknown *pUnk);  // standard constructor
	virtual ~AR2WarpControllerPropertyPage();

	// Dialog Data


protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

protected:
	IAR2WarpController *m_pFilter;
	bool GetSetting();
public:
	// Dialog Data
	enum {IDD = IDD_AR2WarpControllerPropertyPage};
	//override CBasePropertyPage Method
	virtual HRESULT OnConnect(IUnknown *pUnk);
	virtual HRESULT OnDisconnect(void);
	virtual BOOL OnReceiveMessage(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	virtual HRESULT OnActivate(void);
	virtual HRESULT OnApplyChanges(void);

	static CUnknown *WINAPI CreateInstance(LPUNKNOWN punk, HRESULT *phr);
public: //inherit from CMFCBaseProperty Page
	virtual int GetDialogResourceID() { return IDD_AR2WarpControllerPropertyPage;}
	virtual int GetTitileResourceID() { return IDS_AR2WarpControllerTitle;}

	CEdit m_edIP;
	CEdit m_edPort;
	CButton m_btnConnect;

	afx_msg void OnBnClickedBtnconnect();
};
