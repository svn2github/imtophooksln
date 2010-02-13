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


};
