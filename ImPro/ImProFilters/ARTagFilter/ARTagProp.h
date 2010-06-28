#pragma once

#include "dshow.h"
#include "Streams.h"
#include <initguid.h>
#include "combase.h"
#include "ARTagDSFilter.h"
#include "DSMacro.h"
#include "GSMFCProp.h"
#include "Resource.h"
#include "afxwin.h"

class ARTagCameraSettingPage : public CBasePropertyPage
{
protected:
	IARTagFilter *m_pARProperty;    // Pointer to the filter's custom interface.
	
	HWND m_hWndDistFactor[4];
	HWND m_hWndMat[16];
	HWND m_hWndXSize;
	HWND m_hWndYSize;
	HWND m_hWndLoad;
	HWND m_edXaxis;
	HWND m_edYaxis;
	HWND m_edZaxis;

	void SetDirty();
	bool GetSetting();
	HRESULT ApplyCameraSetting();
	bool WriteProfileSetting();
public:
	ARTagCameraSettingPage(IUnknown *pUnk);
	~ARTagCameraSettingPage();
	//override CBasePropertyPage Method
	virtual HRESULT OnConnect(IUnknown *pUnk);
	virtual HRESULT OnDisconnect(void);
	virtual BOOL OnReceiveMessage(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	virtual HRESULT OnActivate(void);
	virtual HRESULT OnApplyChanges(void);
	BOOL OpenFileDialog(HWND hwndParent, WCHAR* pwcsFilter, WCHAR* pwcsDialogTitle, DWORD dwflag, WCHAR* pOutStr, BOOL saveDlg);
	//
	static CUnknown *WINAPI CreateInstance(LPUNKNOWN punk, HRESULT *phr);

};

class ARTagGeneralPage : public GSMFCProp
{
	DECLARE_DYNAMIC(ARTagGeneralPage)
protected:
	IARTagFilter *m_pARProperty;    // Pointer to the filter's custom interface.
	HWND m_cbPoseEstimator;
	HWND m_cbMarkerMode;
	HWND m_cbUnDistortMode;
	HWND m_ckDrawTag;
	HWND m_ckDrawReProj;
	HWND m_ckGuessPose;
	HWND m_ckAutoThreshold;
	HWND m_ckUseKalman;
	HWND m_ckMaskTag;

	HWND m_slrThreshold;
	HWND m_slrBorderW;
	HWND m_txtThreshold;;
	HWND m_txtBorderW;

	HWND m_txtMeasureNoise;
	HWND m_slrMeasureNoise;



	static const int m_BorderWScale = 1000;
	static const int m_MNoiseScale = 10;
	void SetDirty();
	bool GetSetting();
	bool ApplySetting();
	bool updateSliderTxt();


	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	DECLARE_MESSAGE_MAP()
public:
	ARTagGeneralPage(IUnknown *pUnk);
	~ARTagGeneralPage();

	enum {IDD = IDD_ARTag_GeneralSettingPage};
	
	//override CBasePropertyPage Method
	virtual HRESULT OnConnect(IUnknown *pUnk);
	virtual HRESULT OnDisconnect(void);
	virtual BOOL OnReceiveMessage(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	virtual HRESULT OnActivate(void);
	virtual HRESULT OnApplyChanges(void);

	static CUnknown *WINAPI CreateInstance(LPUNKNOWN punk, HRESULT *phr);
	BOOL OpenFileDialog(HWND hwndParent, WCHAR* pwcsFilter, WCHAR* pwcsDialogTitle, DWORD dwflag, WCHAR* pOutStr, BOOL saveDlg);
	virtual int GetDialogResourceID() { return IDD_ARTag_GeneralSettingPage;}
	virtual int GetTitileResourceID() { return IDS_ARTag_GENERALPAGE_TITLE;}
	CEdit m_edIP;
	CEdit m_edPort;
	CButton m_btnConnect;
	afx_msg void OnBnClickedBtnconnect();
};

