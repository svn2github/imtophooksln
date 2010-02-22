#pragma once
#include "IProjectSettingFilter.h"
#include "MFCBasePropertyPage.h"
#include "streams.h"
#include "resource.h"
#include "afxwin.h"
#include "afxcmn.h"



class ProjectSettingPropPage : public CMFCBasePropertyPage
{
	DECLARE_DYNAMIC(ProjectSettingPropPage)

public:
	ProjectSettingPropPage(IUnknown *pUnk);  // standard constructor
	virtual ~ProjectSettingPropPage();

	// Dialog Data


protected:
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

protected:
	IProjectSettingFilter *m_pFilter;
public:
	// Dialog Data
	enum {IDD = IDD_ProjectSettingPropPage};
	//override CBasePropertyPage Method
	virtual HRESULT OnConnect(IUnknown *pUnk);
	virtual HRESULT OnDisconnect(void);
	virtual BOOL OnReceiveMessage(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	virtual HRESULT OnActivate(void);
	virtual HRESULT OnApplyChanges(void);

	static CUnknown *WINAPI CreateInstance(LPUNKNOWN punk, HRESULT *phr);
public: //inherit from CMFCBaseProperty Page
	virtual int GetDialogResourceID() { return IDD_ProjectSettingPropPage;}
	virtual int GetTitileResourceID() { return IDS_ProjectSettingPropPage_Title;}

};
