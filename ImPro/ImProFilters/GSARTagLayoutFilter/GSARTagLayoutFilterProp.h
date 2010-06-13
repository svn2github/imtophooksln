#pragma once
#include "IGSARTagLayoutFilter.h"
#include "GSMFCProp.h"
#include "streams.h"
#include "resource.h"
#include "afxwin.h"
#include "afxcmn.h"



class GSARTagLayoutFilterProp : public GSMFCProp
{
	DECLARE_DYNAMIC(GSARTagLayoutFilterProp)

public:
	GSARTagLayoutFilterProp(IUnknown *pUnk);  // standard constructor
	virtual ~GSARTagLayoutFilterProp();

	// Dialog Data
	CEdit m_edPath;

protected:
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

protected:
	IGSARTagLayoutFilter *m_pFilter;

	HRESULT GetSetting();
public:
	// Dialog Data
	enum {IDD = IDD_GSARTagLayoutFilterProp};
	//override CBasePropertyPage Method
	virtual HRESULT OnConnect(IUnknown *pUnk);
	virtual HRESULT OnDisconnect(void);
	virtual BOOL OnReceiveMessage(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	virtual HRESULT OnActivate(void);
	virtual HRESULT OnApplyChanges(void);

	static CUnknown *WINAPI CreateInstance(LPUNKNOWN punk, HRESULT *phr);
public: //inherit from CMFCBaseProperty Page
	virtual int GetDialogResourceID() { return IDD_GSARTagLayoutFilterProp;}
	virtual int GetTitileResourceID() { return IDS_GSARTagLayoutFilterProp_Title;}


	CSliderCtrl m_slrBlackLevel;
	CStatic m_txtBlackLevel;
	
	CComboBox m_cbFPS;
	
	afx_msg void OnCbnSelchangecbfps();
	afx_msg void OnNMCustomdrawslrblacklevel(NMHDR *pNMHDR, LRESULT *pResult);
};
