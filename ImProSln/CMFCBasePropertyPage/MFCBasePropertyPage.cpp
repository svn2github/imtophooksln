// MFCBasePropertyPage.cpp : implementation file
//

#include "stdafx.h"
#include "MFCBasePropertyPage.h"


// CMFCBasePropertyPage dialog

IMPLEMENT_DYNAMIC(CMFCBasePropertyPage, CDialog)

CMFCBasePropertyPage::CMFCBasePropertyPage(LPCTSTR pName, LPUNKNOWN pUnk)
: CDialog(), CUnknown(pName,pUnk)
{
	m_pPageSite = NULL;
	m_bObjectSet = NULL;
	m_bDirty = FALSE;
}

CMFCBasePropertyPage::~CMFCBasePropertyPage()
{
	if (m_pPageSite != NULL)
	{
		m_pPageSite->Release();
		m_pPageSite = NULL;
	}
}
LRESULT CMFCBasePropertyPage::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	this->OnReceiveMessage(GetSafeHwnd(), message, wParam, lParam);
	return CDialog::WindowProc(message, wParam, lParam);
}
void CMFCBasePropertyPage::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMFCBasePropertyPage, CDialog)
END_MESSAGE_MAP()


// CMFCBasePropertyPage message handlers

STDMETHODIMP CMFCBasePropertyPage::NonDelegatingQueryInterface(REFIID riid, __deref_out void **ppv)
{
	if (riid == IID_IPropertyPage) {
		return ::GetInterface((IPropertyPage *)this,ppv);
	} else {
		return CUnknown::NonDelegatingQueryInterface(riid,ppv);
	}
}
STDMETHODIMP_(ULONG) CMFCBasePropertyPage::NonDelegatingRelease()
{
	LONG lRef = InterlockedDecrement(&m_cRef);
	if (lRef == 0) {
		m_cRef++;
		SetPageSite(NULL);
		SetObjects(0,NULL);
		delete this;
		return ULONG(0);
	} else {
		//  Don't touch m_cRef again here!
		return max(ULONG(lRef),1ul);
	}
}
STDMETHODIMP_(ULONG) CMFCBasePropertyPage::NonDelegatingAddRef()
{
	LONG lRef = InterlockedIncrement(&m_cRef);
	ASSERT(lRef > 0);
	return max(ULONG(m_cRef),1ul);
}
STDMETHODIMP CMFCBasePropertyPage::SetPageSite(__in_opt LPPROPERTYPAGESITE pPageSite)
{
	if (pPageSite) {

		if (m_pPageSite) {
			return E_UNEXPECTED;
		}

		m_pPageSite = pPageSite;
		m_pPageSite->AddRef();

	} else {

		if (m_pPageSite == NULL) {
			return E_UNEXPECTED;
		}

		m_pPageSite->Release();
		m_pPageSite = NULL;
	}
	return NOERROR;
}
STDMETHODIMP CMFCBasePropertyPage::Activate(HWND hwndParent, LPCRECT prect,BOOL fModal)
{
	CheckPointer(prect,E_POINTER);
	if (m_bObjectSet == FALSE) return E_UNEXPECTED;

	// if we already exist - exit
	if (IsWindow(*this)) return E_UNEXPECTED;

	CWnd		*parent = CWnd::FromHandle(hwndParent);
	BOOL ok = Create(GetDialogResourceID(), FromHandle(hwndParent));

	if (!ok) return E_OUTOFMEMORY;

	OnActivate();
	Move(prect);
	return Show(SW_SHOWNORMAL);

}
STDMETHODIMP CMFCBasePropertyPage::Deactivate(void)
{
	HWND myhwnd = GetSafeHwnd();
	if (myhwnd == NULL) {
		return E_UNEXPECTED;
	}
	OnDeactivate();
	// Destroy the dialog window
	DestroyWindow();
	return NOERROR;
}
STDMETHODIMP CMFCBasePropertyPage::GetPageInfo(__out LPPROPPAGEINFO pPageInfo)
{
	CheckPointer(pPageInfo,E_POINTER);
	WCHAR wszTitle[STR_MAX_LENGTH];
	WideStringFromResource(wszTitle, GetTitileResourceID());

	// Allocate dynamic memory for the property page title

	LPOLESTR pszTitle;
	HRESULT hr = AMGetWideString(wszTitle, &pszTitle);
	if (FAILED(hr)) {
		NOTE("No caption memory");
		return hr;
	}

	pPageInfo->cb               = sizeof(PROPPAGEINFO);
	pPageInfo->pszTitle         = pszTitle;
	pPageInfo->pszDocString     = NULL;
	pPageInfo->pszHelpFile      = NULL;
	pPageInfo->dwHelpContext    = 0;

	// Set defaults in case GetDialogSize fails
	pPageInfo->size.cx          = 340;
	pPageInfo->size.cy          = 150;

	// let's retrieve the size
	HWND	hwnd_temp;
	
	hwnd_temp = ::CreateDialogParam(::AfxGetInstanceHandle(), 
		MAKEINTRESOURCE(GetDialogResourceID()), 
		::GetDesktopWindow(),
		NULL,
		0);
	if (hwnd_temp != NULL) {

		RECT	rc;
		rc.left = rc.right = rc.top = rc.bottom = 0;
		::GetWindowRect(hwnd_temp, &rc);

		// get the size
		pPageInfo->size.cx		= rc.right - rc.left;
		pPageInfo->size.cy		= rc.bottom - rc.top;

		// kill the window
		::DestroyWindow(hwnd_temp);
	}
	return NOERROR;
}
STDMETHODIMP CMFCBasePropertyPage::SetObjects(ULONG cObjects, __in_ecount_opt(cObjects) LPUNKNOWN *ppUnk)
{
	if (cObjects == 1) {

		if ((ppUnk == NULL) || (*ppUnk == NULL)) {
			return E_POINTER;
		}

		// Set a flag to say that we have set the Object
		m_bObjectSet = TRUE ;
		return OnConnect(*ppUnk);

	} else if (cObjects == 0) {

		// Set a flag to say that we have not set the Object for the page
		m_bObjectSet = FALSE ;
		return OnDisconnect();
	}

	DbgBreak("No support for more than one object");
	return E_UNEXPECTED;
}
STDMETHODIMP CMFCBasePropertyPage::Show(UINT nCmdShow)
{
	HWND hwnd = GetSafeHwnd();
	if (hwnd == NULL) {
		return E_UNEXPECTED;
	}

	// Ignore wrong show flags

	if ((nCmdShow != SW_SHOW) && (nCmdShow != SW_SHOWNORMAL) && (nCmdShow != SW_HIDE)) {
		return E_INVALIDARG;
	}
	this->ShowWindow(nCmdShow);
	this->InvalidateRect(NULL,TRUE);
}
STDMETHODIMP CMFCBasePropertyPage::Move(LPCRECT prect)
{
	CheckPointer(prect,E_POINTER);
	HWND hwnd = GetSafeHwnd();
	
	if (hwnd == NULL) {
		return E_UNEXPECTED;
	}
	
	MoveWindow(              // Property page handle
		prect->left,         // x coordinate
		prect->top,          // y coordinate
		WIDTH(prect),        // Overall window width
		HEIGHT(prect),       // And likewise height
		TRUE);               // Should we repaint it

	return NOERROR;
}
STDMETHODIMP CMFCBasePropertyPage::IsPageDirty(void)
{
	return m_bDirty ? S_OK : S_FALSE;
}
STDMETHODIMP CMFCBasePropertyPage::Apply(void)
{

	if (m_bObjectSet == FALSE) {
		return E_UNEXPECTED;
	}

	// Must have had a site set

	if (m_pPageSite == NULL) {
		return E_UNEXPECTED;
	}

	// Has anything changed

	if (m_bDirty == FALSE) {
		return NOERROR;
	}

	// Commit derived class changes

	HRESULT hr = OnApplyChanges();
	if (SUCCEEDED(hr)) {
		m_bDirty = FALSE;
	}
	 return hr;
}
