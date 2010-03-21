#pragma once
#include "MFCBasePropertyPage.h"
#include "resource.h"
#include "afxwin.h"
#include "IBGMappingFilter.h"

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
	static CUnknown *WINAPI CreateInstance(LPUNKNOWN punk, HRESULT *phr);
public:
	HRESULT updateSliderTxt();
	HWND m_threshold;
	HWND m_txt;
	HWND m_blackValue;
	HWND m_Btxt;
	HWND m_whiteValue;
	HWND m_Wtxt;

	CButton* m_checkCamFlip;
	CButton* m_checkLayoutFlip;
	CButton* m_checkOutputFlip;





public: //inherit from CMFCBaseProperty Page
	virtual int GetDialogResourceID();
	virtual int GetTitileResourceID();
	
	afx_msg void OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult);

	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEditWhite();
	afx_msg void OnBnClickedCheckLayout();
	afx_msg void OnNMCustomdrawSliderWhite(NMHDR *pNMHDR, LRESULT *pResult);
};
