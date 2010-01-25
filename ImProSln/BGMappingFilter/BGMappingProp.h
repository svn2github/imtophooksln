#pragma once
#include "MFCBasePropertyPage.h"
#include "resource.h"
#include "afxwin.h"
// CHomoWarpMFCPropertyPage dialog
// {54A10265-D314-48b4-9518-F9896C1A6C68}
DEFINE_GUID(CLSID_BGMappingPropertyPage, 
			0x54a10265, 0xd314, 0x48b4, 0x95, 0x18, 0xf9, 0x89, 0x6c, 0x1a, 0x6c, 0x68);


class CBGMappingPorpertyPage : public CMFCBasePropertyPage
{
	DECLARE_DYNAMIC(CBGMappingPorpertyPage)

public:
	CBGMappingPorpertyPage(IUnknown *pUnk);  // standard constructor
	virtual ~CBGMappingPorpertyPage();

// Dialog Data


protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

protected:
	IBGMappingFilter *m_pFilter;

public:
	// Dialog Data
	enum {IDD = IDD_BGMappingPropPage};
	//override CBasePropertyPage Method
	virtual HRESULT OnConnect(IUnknown *pUnk);
	virtual HRESULT OnDisconnect(void);
	virtual BOOL OnReceiveMessage(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	virtual HRESULT OnActivate(void);
	virtual HRESULT OnApplyChanges(void);

	//
	static CUnknown *WINAPI CreateInstance(LPUNKNOWN punk, HRESULT *phr);
public: //inherit from CMFCBaseProperty Page
	virtual int GetDialogResourceID();
	virtual int GetTitileResourceID();
	
};