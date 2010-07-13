#pragma once
#include "IImProSyncFilter.h"
#include "GSMFCProp.h"
#include "streams.h"
#include "resource.h"
#include "afxwin.h"
#include "afxcmn.h"



class ImProSyncFilterProp : public GSMFCProp
{
	DECLARE_DYNAMIC(ImProSyncFilterProp)

public:
	ImProSyncFilterProp(IUnknown *pUnk);  // standard constructor
	virtual ~ImProSyncFilterProp();

	// Dialog Data
	CEdit m_edPath;

protected:
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

protected:
	IImProSyncFilter *m_pFilter;
public:
	// Dialog Data
	enum {IDD = IDD_ImProSyncFilterProp};
	//override CBasePropertyPage Method
	virtual HRESULT OnConnect(IUnknown *pUnk);
	virtual HRESULT OnDisconnect(void);
	virtual BOOL OnReceiveMessage(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	virtual HRESULT OnActivate(void);
	virtual HRESULT OnApplyChanges(void);

	static CUnknown *WINAPI CreateInstance(LPUNKNOWN punk, HRESULT *phr);
public: //inherit from CMFCBaseProperty Page
	virtual int GetDialogResourceID() { return IDD_ImProSyncFilterProp;}
	virtual int GetTitileResourceID() { return IDS_ImProSyncFilterProp_Title;}


};
