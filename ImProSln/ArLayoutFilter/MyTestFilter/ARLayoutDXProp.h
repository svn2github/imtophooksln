#pragma once

#include "IARLayoutFilter.h"
#include "MFCBasePropertyPage.h"
#include "streams.h"
#include "resource.h"
#include "afxwin.h"
// {5CDCA877-D333-43f4-839F-C74ADDF9E188}
DEFINE_GUID(CLSID_ARLayoutPropPage, 
			0x5cdca877, 0xd333, 0x43f4, 0x83, 0x9f, 0xc7, 0x4a, 0xdd, 0xf9, 0xe1, 0x88);

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
};
