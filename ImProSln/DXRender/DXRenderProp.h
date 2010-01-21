#pragma once

// {D99B1E26-91D6-4c4e-B66F-71AAD8E601CC}
DEFINE_GUID(CLSID_DXRenderPropPage, 
			0xd99b1e26, 0x91d6, 0x4c4e, 0xb6, 0x6f, 0x71, 0xaa, 0xd8, 0xe6, 0x1, 0xcc);
#include "IDXRenderer.h"
#include "MFCBasePropertyPage.h"
#include "resource.h"
#include "afxwin.h"


class DXRenderFilterProp : public CMFCBasePropertyPage
{
	DECLARE_DYNAMIC(DXRenderFilterProp)

public:
	DXRenderFilterProp(IUnknown *pUnk);  // standard constructor
	virtual ~DXRenderFilterProp();

	// Dialog Data


protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

protected:
	IDXRenderer *m_pFilter;

public:
	// Dialog Data
	enum {IDD = IDD_DXRenderFilterProp};
	//override CBasePropertyPage Method
	virtual HRESULT OnConnect(IUnknown *pUnk);
	virtual HRESULT OnDisconnect(void);
	virtual BOOL OnReceiveMessage(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	virtual HRESULT OnActivate(void);
	virtual HRESULT OnApplyChanges(void);

	//
	static CUnknown *WINAPI CreateInstance(LPUNKNOWN punk, HRESULT *phr);
public: //inherit from CMFCBaseProperty Page
	virtual int GetDialogResourceID() { return IDD_DXRenderFilterProp;};
	virtual int GetTitileResourceID() { return IDS_DXRenderFilterProp_Title;};
};
