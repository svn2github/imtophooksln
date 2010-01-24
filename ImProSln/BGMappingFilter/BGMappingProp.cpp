// HomoWarpMFCPropertyPage.cpp : implementation file
//

#include "stdafx.h"
#include "BGMappingFilter.h"
#include "BGMappingProp.h"

#include "DSMacro.h"
#include "resource.h"
// CHomoWarpMFCPropertyPage dialog

IMPLEMENT_DYNAMIC(CBGMappingPorpertyPage, CMFCBasePropertyPage)


void CBGMappingPorpertyPage::DoDataExchange(CDataExchange* pDX)
{
	CBGMappingPorpertyPage::DoDataExchange(pDX);
	
}


BEGIN_MESSAGE_MAP(CBGMappingPorpertyPage, CMFCBasePropertyPage)

END_MESSAGE_MAP()


// CHomoWarpMFCPropertyPage message handlers


CBGMappingPorpertyPage::CBGMappingPorpertyPage(IUnknown *pUnk) : 
CMFCBasePropertyPage(NAME("BackGroundMapping Page"), pUnk),
m_pFilter(0)
{
	
}

CBGMappingPorpertyPage::~CBGMappingPorpertyPage()
{
	if (m_pFilter != NULL)
	{
		m_pFilter->Release();
		m_pFilter = NULL;
	}
}


HRESULT CBGMappingPorpertyPage::OnConnect(IUnknown *pUnk)
{
	if (pUnk == NULL)
	{
		return E_POINTER;
	}
	if (m_pFilter == NULL)
	{
		pUnk->QueryInterface(IID_IBGMappingFilter, 
			reinterpret_cast<void**>(&m_pFilter));
		return S_OK;
	}
	return S_OK;
}

HRESULT CBGMappingPorpertyPage::OnDisconnect(void)
{
	if (m_pFilter)
	{
		m_pFilter->Release();
		m_pFilter = NULL;
	}
	return S_OK;
}

CUnknown *WINAPI CBGMappingPorpertyPage::CreateInstance(LPUNKNOWN punk, HRESULT *phr)
{
	ASSERT(phr);
	// assuming we don't want to modify the data
	CBGMappingPorpertyPage *pNewObject = new CBGMappingPorpertyPage(punk);

	if(pNewObject == NULL) {
		if (phr)
			*phr = E_OUTOFMEMORY;
	}

	return pNewObject;
}


HRESULT CBGMappingPorpertyPage::OnApplyChanges(void)
{
	
		return S_OK;
}

BOOL CBGMappingPorpertyPage::OnReceiveMessage(HWND hwnd,
												UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	WCHAR str[MAX_PATH] = {0};
	int cmd = 0;

	switch (uMsg) {
	case WM_COMMAND:

		break;
	
	}
	return S_OK;
	
}


HRESULT CBGMappingPorpertyPage::OnActivate(void)
{
	HWND m_Dlg = GetSafeHwnd();
	if (m_pFilter == NULL)
	{
		::EnableWindow(m_Dlg, FALSE);
		return S_OK;
	}
	::EnableWindow(m_Dlg, TRUE);

	return NOERROR;
}


int CBGMappingPorpertyPage::GetDialogResourceID() 
{ 
	return IDD_BGMappingPropPage;
}

int CBGMappingPorpertyPage::GetTitileResourceID() 
{ 
	return 0;//IDS_HomoWarpPropertyDlg_Title;
}
