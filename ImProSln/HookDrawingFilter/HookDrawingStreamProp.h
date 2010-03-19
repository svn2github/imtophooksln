#pragma once
#include "IHookDrawingStream.h"
#include "MFCBasePropertyPage.h"
#include "streams.h"
#include "resource.h"
#include "afxwin.h"

class HookDrawingStreamPropPage : public CMFCBasePropertyPage
{
	DECLARE_DYNAMIC(HookDrawingStreamPropPage)

public:
	HookDrawingStreamPropPage(IUnknown *pUnk);  // standard constructor
	virtual ~HookDrawingStreamPropPage();

	// Dialog Data


protected:
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

protected:
	IHookDrawingStream *m_pPin;
	CEdit m_edLeft;
	CEdit m_edRight;
	CEdit m_edTop;
	CEdit m_edBottom;
	bool GetSetting();
	bool ApplySetting();

public:
	// Dialog Data
	enum {IDD = IDD_HookDrawingStreamPropPage};
	//override CBasePropertyPage Method
	virtual HRESULT OnConnect(IUnknown *pUnk);
	virtual HRESULT OnDisconnect(void);
	virtual BOOL OnReceiveMessage(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	virtual HRESULT OnActivate(void);
	virtual HRESULT OnApplyChanges(void);

	static CUnknown *WINAPI CreateInstance(LPUNKNOWN punk, HRESULT *phr);
public: //inherit from CMFCBaseProperty Page
	virtual int GetDialogResourceID() { return IDD_HookDrawingStreamPropPage;}
	virtual int GetTitileResourceID() { return IDS_HookDrawingStreamPropPage_Title;}


	afx_msg void OnEnKillfocusedleft();
	afx_msg void OnEnKillfocusedright();
	afx_msg void OnEnKillfocusedtop();
	afx_msg void OnEnKillfocusedbottom();
	afx_msg void OnEnChangeedtop();
	afx_msg void OnEnChangeedleft();
	afx_msg void OnEnChangeedright();
	afx_msg void OnEnChangeedbottom();
	afx_msg void OnCbnSelchangeCombo1();
	CComboBox m_cbResolution;
	CComboBox m_cbFPS;
	afx_msg void OnCbnSelchangecbfps();
};
