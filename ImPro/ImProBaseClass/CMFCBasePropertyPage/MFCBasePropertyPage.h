#pragma once

#include "dshow.h"
#include "Streams.h"
#include <initguid.h>
#include "combase.h"

// CMFCBasePropertyPage dialog

class CMFCBasePropertyPage : public CDialog, public IPropertyPage, public CUnknown 
{
	DECLARE_DYNAMIC(CMFCBasePropertyPage)
public:
	CMFCBasePropertyPage(LPCTSTR pName, LPUNKNOWN pUnk); 
	virtual ~CMFCBasePropertyPage();
	STDMETHODIMP QueryInterface(REFIID riid, __deref_out void **ppv) {      
		return CUnknown::GetOwner()->QueryInterface(riid,ppv);            
	};                                                          
	STDMETHODIMP_(ULONG) AddRef() {                             
	return CUnknown::GetOwner()->AddRef();                            
	};                                                          
	STDMETHODIMP_(ULONG) Release() {                            
	return CUnknown::GetOwner()->Release();                           
	};


protected:
	virtual void SetDirty();
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	DECLARE_MESSAGE_MAP()
private:
	 BOOL m_bObjectSet ;     
protected:
	 BOOL m_bDirty;  
	 LPPROPERTYPAGESITE m_pPageSite; 
protected: // have to be implemented by derived class
	virtual int GetDialogResourceID() PURE;
	virtual int GetTitileResourceID() PURE;

	virtual HRESULT OnConnect(IUnknown *pUnknown) { return NOERROR; };
	virtual HRESULT OnDisconnect() { return NOERROR; };
	virtual HRESULT OnActivate() { return NOERROR; };
	virtual HRESULT OnDeactivate() { return NOERROR; };
	virtual HRESULT OnApplyChanges() { return NOERROR; };
	virtual BOOL OnReceiveMessage(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam){ return TRUE; };
public:
	STDMETHODIMP NonDelegatingQueryInterface(REFIID riid, __deref_out void **ppv);
	STDMETHODIMP_(ULONG) NonDelegatingRelease();
	STDMETHODIMP_(ULONG) NonDelegatingAddRef();
	STDMETHODIMP SetPageSite(__in_opt LPPROPERTYPAGESITE pPageSite);
	STDMETHODIMP Activate(HWND hwndParent, LPCRECT prect,BOOL fModal);
	STDMETHODIMP Deactivate(void);
	STDMETHODIMP GetPageInfo(__out LPPROPPAGEINFO pPageInfo);
	STDMETHODIMP SetObjects(ULONG cObjects, __in_ecount_opt(cObjects) LPUNKNOWN *ppUnk);
	STDMETHODIMP Show(UINT nCmdShow);
	STDMETHODIMP Move(LPCRECT prect);
	STDMETHODIMP IsPageDirty(void) ;
	STDMETHODIMP Apply(void);
    STDMETHODIMP Help(LPCWSTR lpszHelpDir) { return E_NOTIMPL; }
    STDMETHODIMP TranslateAccelerator(__inout LPMSG lpMsg) { return E_NOTIMPL; }
};
