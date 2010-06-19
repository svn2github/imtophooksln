#pragma once
#include "IGSFrameCaptureFilter.h"
#include "GSMFCProp.h"
#include "streams.h"
#include "resource.h"
#include "afxwin.h"
#include "afxcmn.h"



class GSFrameCaptureFilterProp : public GSMFCProp
{
	DECLARE_DYNAMIC(GSFrameCaptureFilterProp)

public:
	GSFrameCaptureFilterProp(IUnknown *pUnk);  // standard constructor
	virtual ~GSFrameCaptureFilterProp();

	// Dialog Data
	CEdit m_edPath;

protected:
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

protected:
	IGSFrameCaptureFilter *m_pFilter;
public:
	// Dialog Data
	enum {IDD = IDD_GSFrameCaptureFilterProp};
	//override CBasePropertyPage Method
	virtual HRESULT OnConnect(IUnknown *pUnk);
	virtual HRESULT OnDisconnect(void);
	virtual BOOL OnReceiveMessage(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	virtual HRESULT OnActivate(void);
	virtual HRESULT OnApplyChanges(void);

	static CUnknown *WINAPI CreateInstance(LPUNKNOWN punk, HRESULT *phr);
public: //inherit from CMFCBaseProperty Page
	virtual int GetDialogResourceID() { return IDD_GSFrameCaptureFilterProp;}
	virtual int GetTitileResourceID() { return IDS_GSFrameCaptureFilterProp_Title;}


	CButton m_btnSaveImg;
	afx_msg void OnBnClickedbtnsaveimg();

	
};

