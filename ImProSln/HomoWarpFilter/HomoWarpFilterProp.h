#pragma once
#include "IHomoWarpFilter.h"
// {F3DBD46E-12C6-4652-9A2E-063AC623E846}
DEFINE_GUID(CLSID_HomoWarpFilterPropertyPage, 
			0xf3dbd46e, 0x12c6, 0x4652, 0x9a, 0x2e, 0x6, 0x3a, 0xc6, 0x23, 0xe8, 0x46);


#include "dshow.h"
#include "Streams.h"

class HomoWarpPropertyPage : public CBasePropertyPage
{
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
	HomoWarpPropertyPage(IUnknown *pUnk);
	~HomoWarpPropertyPage();
	//override CBasePropertyPage Method
	virtual HRESULT OnConnect(IUnknown *pUnk);
	virtual HRESULT OnDisconnect(void);
	virtual BOOL OnReceiveMessage(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	virtual HRESULT OnActivate(void);
	virtual HRESULT OnApplyChanges(void);

	//
	static CUnknown *WINAPI CreateInstance(LPUNKNOWN punk, HRESULT *phr);
};

