#pragma once
#include "MFCBasePropertyPage.h"
#include "resource.h"
// CHomoWarpMFCPropertyPage dialog

class CHomoWarpMFCPropertyPage : public CMFCBasePropertyPage
{
	DECLARE_DYNAMIC(CHomoWarpMFCPropertyPage)

public:
	CHomoWarpMFCPropertyPage(IUnknown *pUnk);  // standard constructor
	virtual ~CHomoWarpMFCPropertyPage();

// Dialog Data


protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

protected:
	IHomoWarpFilter *m_pFilter;
	HWND m_slrLTx;
	HWND m_slrLTy;
	HWND m_slrLBx;
	HWND m_slrLBy;
	HWND m_slrRBx;
	HWND m_slrRBy;
	HWND m_slrRTx;
	HWND m_slrRTy;

	HWND m_txtLT;
	HWND m_txtLB;
	HWND m_txtRB;
	HWND m_txtRT;
	static const int m_slrScale = 100;
	void SetDirty();
	bool GetSetting();
	bool ApplySetting();
	bool updateSliderTxt();
public:
	// Dialog Data
	enum {IDD = IDD_HomoWarpPropertyPage};
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
