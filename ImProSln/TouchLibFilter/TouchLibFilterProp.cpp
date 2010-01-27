#include "stdafx.h"
#include "TouchLibFilterProp.h"
#include "TouchLibFilterApp.h"
extern CTouchLibFilterApp theApp;

IMPLEMENT_DYNAMIC(TouchLibPropPage, CMFCBasePropertyPage)
void TouchLibPropPage::DoDataExchange(CDataExchange* pDX)
{
	CMFCBasePropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(TouchLibPropPage, CMFCBasePropertyPage)
END_MESSAGE_MAP()


// CHomoWarpMFCPropertyPage message handlers


TouchLibPropPage::TouchLibPropPage(IUnknown *pUnk) : 
CMFCBasePropertyPage(NAME("TouchLibPropPage"), pUnk),
m_pFilter(0)
{

}

TouchLibPropPage::~TouchLibPropPage()
{
	if (m_pFilter != NULL)
	{
		m_pFilter->Release();
		m_pFilter = NULL;
	}
}

//override CBasePropertyPage Method
HRESULT TouchLibPropPage::OnConnect(IUnknown *pUnk)
{
	//override CBasePropertyPage Method
	if (pUnk == NULL)
	{
		return E_POINTER;
	}
	if (m_pFilter == NULL)
	{
		pUnk->QueryInterface(IID_ITouchLibFilter, 
			reinterpret_cast<void**>(&m_pFilter));
		return S_OK;
	}
	return S_OK;
}
HRESULT TouchLibPropPage::OnDisconnect(void)
{
	if (m_pFilter != NULL)
	{
		m_pFilter->Release();
		m_pFilter = NULL;
	}
	return S_OK;
}
BOOL TouchLibPropPage::OnReceiveMessage(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return TRUE;
}
HRESULT TouchLibPropPage::OnActivate(void)
{
	EnableWindow(TRUE);
	return S_OK;
}
HRESULT TouchLibPropPage::OnApplyChanges(void)
{
	return S_OK;
}

CUnknown *WINAPI TouchLibPropPage::CreateInstance(LPUNKNOWN punk, HRESULT *phr)
{
	ASSERT(phr);
	// assuming we don't want to modify the data
	TouchLibPropPage *pNewObject = new TouchLibPropPage(punk);

	if(pNewObject == NULL) {
		if (phr)
			*phr = E_OUTOFMEMORY;
	}

	return pNewObject;
}
