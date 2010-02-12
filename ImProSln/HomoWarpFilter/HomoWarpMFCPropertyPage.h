#pragma once
#include "MFCBasePropertyPage.h"

#include "resource.h"
#include "afxwin.h"
#include "cv.h"
// CHomoWarpMFCPropertyPage dialog
DEFINE_GUID(CLSID_HomoWarpFilterPropertyPage, 
			0xf3dbd46e, 0x12c6, 0x4652, 0x9a, 0x2e, 0x6, 0x3a, 0xc6, 0x23, 0xe8, 0x46);

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
	IplImage* m_pEditImage;
	IplImage* m_pEditImage_bk;
	HWND m_slrLTx;
	HWND m_slrLTy;
	HWND m_slrLBx;
	HWND m_slrLBy;
	HWND m_slrRBx;
	HWND m_slrRBy;
	HWND m_slrRTx;
	HWND m_slrRTy;

	static const int m_slrScale = 100;
	static const float m_slrRangeScale;
	void SetDirty();
	bool GetSetting();
	bool ApplySetting();
	bool updateSliderTxt();
	bool ApplySettingFromEdit();
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
	
	CButton m_ckFlipY;
	afx_msg void OnBnClickedChkFlipy();
	CEdit m_edLT;
	CEdit m_edRT;
	CEdit m_edLB;
	CEdit m_edRB;
	CEdit m_edPath;
	afx_msg void OnEnKillfocusedlt();
	afx_msg void OnEnKillfocusedrt();
	afx_msg void OnEnKillfocusedlb();
	afx_msg void OnEnKillfocusedrb();
	afx_msg void OnEnChangeedlt();
	afx_msg void OnEnChangeedrt();
	afx_msg void OnEnChangeedlb();
	afx_msg void OnEnChangeedrb();
	afx_msg void OnBnClickedbtnbrowse();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedBtnLoad();
	afx_msg void OnBnClickedbtneditwnd();
	bool SetWarpByEditPts();
	bool GetEditPtsByWarpMatrix();
	static void MouseCallback(int event, int x, int y, int flags, void* param);
	D3DXVECTOR2 m_editWarpPt[4];
	int m_currEditIdx;;
	int m_bEditing;
	CButton m_ckInvWarp;
	afx_msg void OnBnClickedCkinvwarp();
};
