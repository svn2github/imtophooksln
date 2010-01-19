#pragma once

#include "dshow.h"
#include "Streams.h"
#include <initguid.h>
#include "combase.h"
#include "ARTagDSFilter.h"
#include "DSMacro.h"

// {4AE740F1-4AB8-4436-B346-189DD369B965}
DEFINE_GUID(CLSID_ARTagCameraProperty, 
			0x4ae740f1, 0x4ab8, 0x4436, 0xb3, 0x46, 0x18, 0x9d, 0xd3, 0x69, 0xb9, 0x65);

// {3333AFC9-B73B-440b-85FF-3656E4457958}
DEFINE_GUID(CLSID_ARTagProperty, 
			0x3333afc9, 0xb73b, 0x440b, 0x85, 0xff, 0x36, 0x56, 0xe4, 0x45, 0x79, 0x58);

class ARTagCameraSettingPage : public CBasePropertyPage
{
protected:
	IARTagFilter *m_pARProperty;    // Pointer to the filter's custom interface.
	
	HWND m_hWndDistFactor[4];
	HWND m_hWndMat[16];
	HWND m_hWndXSize;
	HWND m_hWndYSize;
	HWND m_hWndLoad;
	void SetDirty();
	bool GetSetting();
	HRESULT ApplyCameraSetting();
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

class ARTagGeneralPage : public CBasePropertyPage
{
protected:
	IARTagFilter *m_pARProperty;    // Pointer to the filter's custom interface.
	HWND m_cbPoseEstimator;
	HWND m_cbMarkerMode;
	HWND m_cbUnDistortMode;
	HWND m_ckDrawTag;
	HWND m_slrThreshold;
	HWND m_slrBorderW;
	HWND m_txtThreshold;;
	HWND m_txtBorderW;

	HWND m_txtConfThreshold;
	HWND m_slrConfThreshold;

	static const int m_BorderWScale = 1000;
	static const int m_ConfScale = 100;
	void SetDirty();
	bool GetSetting();
	bool ApplySetting();
	bool updateSliderTxt();
public:
	ARTagGeneralPage(IUnknown *pUnk);
	~ARTagGeneralPage();

	
	//override CBasePropertyPage Method
	virtual HRESULT OnConnect(IUnknown *pUnk);
	virtual HRESULT OnDisconnect(void);
	virtual BOOL OnReceiveMessage(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	virtual HRESULT OnActivate(void);
	virtual HRESULT OnApplyChanges(void);

	static CUnknown *WINAPI CreateInstance(LPUNKNOWN punk, HRESULT *phr);

};

