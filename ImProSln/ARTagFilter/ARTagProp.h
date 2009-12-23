#pragma once

#include "dshow.h"
#include "Streams.h"
#include <initguid.h>
#include "combase.h"
#include "ARTagDSFilter.h"
class ARTagPropertyPage : public CBasePropertyPage
{
protected:
	IARTagFilter *m_pARProperty;    // Pointer to the filter's custom interface.
	
	HWND m_hWndDistFactor[4];
	HWND m_hWndMat[16];
	HWND m_hWndXSize;
	HWND m_hWndYSize;

	void SetDirty();
	HRESULT ApplyCameraSetting();
public:
	ARTagPropertyPage(IUnknown *pUnk);
	~ARTagPropertyPage();


	//override CBasePropertyPage Method
	virtual HRESULT OnConnect(IUnknown *pUnk);
	virtual HRESULT OnDisconnect(void);
	virtual BOOL OnReceiveMessage(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	virtual HRESULT OnActivate(void);
	virtual HRESULT OnApplyChanges(void);

	//
	static CUnknown *WINAPI CreateInstance(LPUNKNOWN punk, HRESULT *phr);

};