#pragma once
#include "IARLayoutFilter.h"
#include "MFCBasePropertyPage.h"
#include "streams.h"
#include "resource.h"
// {5CDCA877-D333-43f4-839F-C74ADDF9E188}
DEFINE_GUID(CLSID_ARLayoutPropPage, 
			0x5cdca877, 0xd333, 0x43f4, 0x83, 0x9f, 0xc7, 0x4a, 0xdd, 0xf9, 0xe1, 0x88);

class ARLayoutPropPage : public CMFCBasePropertyPage
{
	DECLARE_DYNAMIC(ARLayoutPropPage)

public:
	ARLayoutPropPage(IUnknown *pUnk);  // standard constructor
	virtual ~ARLayoutPropPage();

	// Dialog Data


protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

protected:
	IARLayoutFilter *m_pFilter;
public:
	// Dialog Data
	enum {IDD = IDD_ARLayoutPropPage};
	//override CBasePropertyPage Method
	virtual HRESULT OnConnect(IUnknown *pUnk);
	virtual HRESULT OnDisconnect(void);
	virtual BOOL OnReceiveMessage(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	virtual HRESULT OnActivate(void);
	virtual HRESULT OnApplyChanges(void);

	static CUnknown *WINAPI CreateInstance(LPUNKNOWN punk, HRESULT *phr);
public: //inherit from CMFCBaseProperty Page
	virtual int GetDialogResourceID() { return IDD_ARLayoutPropPage;}
	virtual int GetTitileResourceID() { return IDS_ARLayoutPropPageTitle;}

	afx_msg void OnBnClickedButton1();
};
