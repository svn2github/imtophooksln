#pragma once

// {D99B1E26-91D6-4c4e-B66F-71AAD8E601CC}

#include "IDXBlendFilter.h"
#include "MFCBasePropertyPage.h"
#include "resource.h"
#include "afxwin.h"


class DXBlendFilterProp : public CMFCBasePropertyPage
{
	DECLARE_DYNAMIC(DXBlendFilterProp)

public:
	DXBlendFilterProp(IUnknown *pUnk);  // standard constructor
	virtual ~DXBlendFilterProp();

	// Dialog Data


protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

protected:
	IDXBlendFilter *m_pFilter;
	bool GetSetting();
	bool ApplySetting();
	
	
public:
	// Dialog Data
	enum {IDD = IDD_DXBlendProp};
	//override CBasePropertyPage Method
	virtual HRESULT OnConnect(IUnknown *pUnk);
	virtual HRESULT OnDisconnect(void);
	virtual BOOL OnReceiveMessage(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	virtual HRESULT OnActivate(void);
	virtual HRESULT OnApplyChanges(void);

	static CUnknown *WINAPI CreateInstance(LPUNKNOWN punk, HRESULT *phr);
public: //inherit from CMFCBaseProperty Page
	virtual int GetDialogResourceID() { return IDD_DXBlendProp;};
	virtual int GetTitileResourceID() { return IDS_DXBlendProp_Title;};
};
