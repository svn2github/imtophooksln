#pragma once

#include "dshow.h"
#include "Streams.h"
#include <initguid.h>
#include "combase.h"
#include "ARTagDSFilter.h"
#include "DSMacro.h"



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

class ARTagGeneralPage : public CBasePropertyPage
{
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
	BOOL OpenFileDialog(HWND hwndParent, WCHAR* pwcsFilter, WCHAR* pwcsDialogTitle, DWORD dwflag, WCHAR* pOutStr, BOOL saveDlg);
};

