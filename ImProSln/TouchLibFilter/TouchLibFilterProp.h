#pragma once
#include "ITouchLibFilter.h"
#include "ITouchListener.h"
#include "MFCBasePropertyPage.h"
#include "resource.h"
#include "afxwin.h"
// TouchLibPropPage dialog
using namespace touchlib ;
// {FBEAA4C2-1F38-4572-9F9E-54A9782EC777}
DEFINE_GUID(CLSID_TouchLibPropPage, 
			0xfbeaa4c2, 0x1f38, 0x4572, 0x9f, 0x9e, 0x54, 0xa9, 0x78, 0x2e, 0xc7, 0x77);

class TouchLibPropPage : public CMFCBasePropertyPage, public ITouchListener
{
	DECLARE_DYNAMIC(TouchLibPropPage)

public:
	TouchLibPropPage(IUnknown *pUnk);  // standard constructor
	virtual ~TouchLibPropPage();

	// Dialog Data


protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

protected:
	ITouchLibFilter *m_pFilter;

	bool GetSetting();
	bool ApplySetting();

public:
	// Dialog Data
	enum {IDD = IDD_TouchLibPropPage};
	//override CBasePropertyPage Method
	virtual HRESULT OnConnect(IUnknown *pUnk);
	virtual HRESULT OnDisconnect(void);
	virtual BOOL OnReceiveMessage(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	virtual HRESULT OnActivate(void);
	virtual HRESULT OnApplyChanges(void);

	//
	static CUnknown *WINAPI CreateInstance(LPUNKNOWN punk, HRESULT *phr);
public: //inherit from CMFCBaseProperty Page
	virtual int GetDialogResourceID() { return IDD_TouchLibPropPage;}
	virtual int GetTitileResourceID() { return IDS_TouchLibPropPage_Title;}
	virtual void fingerDown(TouchData data);
	virtual void fingerUpdate(TouchData data) ;
	virtual void fingerUp(TouchData data);
	afx_msg void OnBnClickedBtnshowconfigwnd();

	CEdit m_edFingerMsg;
	CString m_strFingerMsg;
	WCHAR m_tmpStr[MAX_PATH];
	afx_msg void OnBnClickedBtnclear();
	afx_msg void OnBnClickedCkshowmsg();
	CButton m_ckShowMsg;
	CButton m_ckShowConfigWnd;
	afx_msg void OnBnClickedCkshowconfig();
	CButton m_btnConnect;
	CEdit m_edIP;
	CEdit m_edPort;
	afx_msg void OnBnClickedBtnconnect();
	afx_msg void OnBnClickedBtnClearBG();
};
