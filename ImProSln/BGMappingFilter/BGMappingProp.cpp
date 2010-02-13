// HomoWarpMFCPropertyPage.cpp : implementation file
//

#include "stdafx.h"
#include "BGMappingFilter.h"
#include "BGMappingProp.h"
#include "DSMacro.h"
#include "resource.h"


// CHomoWarpMFCPropertyPage dialog

IMPLEMENT_DYNAMIC(CBGMappingPorpertyPage, CMFCBasePropertyPage)

BEGIN_MESSAGE_MAP(CBGMappingPorpertyPage, CMFCBasePropertyPage)

END_MESSAGE_MAP()


// CHomoWarpMFCPropertyPage message handlers


CBGMappingPorpertyPage::CBGMappingPorpertyPage(IUnknown *pUnk) : 
CMFCBasePropertyPage(NAME("BackGroundMapping Page"), pUnk),
m_pFilter(0)
{
	m_threshold = 0 ;
	m_txt = 0 ;
	m_blackValue = 0 ;
	m_Btxt = 0 ;
	m_whiteValue = 0 ;
	m_Wtxt = 0 ;
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
	case WM_HSCROLL:
		updateSliderTxt();
		break;
	}
	return S_OK;	
}


HRESULT CBGMappingPorpertyPage::updateSliderTxt(){

	if (m_pFilter == NULL)
	{
		return false;
	}

	m_pFilter->setBGThreshold(::SLIDER_GetPos(m_threshold));
	SetDlgItemInt(IDC_ThresholdTxt,m_pFilter->getBGThreshold());
	m_pFilter->setWhiteValue(::SLIDER_GetPos(m_whiteValue));
	SetDlgItemInt(IDC_EDIT_WHITE,m_pFilter->getWhiteValue());
	m_pFilter->setBlackValue(::SLIDER_GetPos(m_blackValue));
	SetDlgItemInt(IDC_EDIT_BLACK,m_pFilter->getBlackValue());
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
	m_threshold = ::GetDlgItem(m_Dlg,IDC_Slider_Threshold);
	m_txt = ::GetDlgItem(m_Dlg, IDC_ThresholdTxt);

	m_whiteValue = ::GetDlgItem(m_Dlg,IDC_SLIDER_WHITE);
	m_Wtxt = ::GetDlgItem(m_Dlg, IDC_EDIT_WHITE);
	m_blackValue = ::GetDlgItem(m_Dlg,IDC_SLIDER_BLACK);
	m_Btxt = ::GetDlgItem(m_Dlg, IDC_EDIT_BLACK);
	
	::SLIDER_SetRange(m_threshold, 0, 255);
	::SLIDER_SetPos(m_threshold,m_pFilter->getBGThreshold());
	SetDlgItemInt(IDC_ThresholdTxt,m_pFilter->getBGThreshold());

	::SLIDER_SetRange(m_blackValue, 0, 255);
	::SLIDER_SetPos(m_blackValue,m_pFilter->getBlackValue());
	SetDlgItemInt(IDC_EDIT_BLACK,m_pFilter->getBlackValue());

	::SLIDER_SetRange(m_whiteValue, 0, 255);
	::SLIDER_SetPos(m_whiteValue,m_pFilter->getWhiteValue());
	SetDlgItemInt(IDC_EDIT_WHITE,m_pFilter->getWhiteValue());
	return S_OK;
}


int CBGMappingPorpertyPage::GetDialogResourceID() 
{ 
	return IDD_BGMappingPropPage;
}

int CBGMappingPorpertyPage::GetTitileResourceID() 
{ 
	return IDS_BGMappingPropertyPageTitle;
}

void CBGMappingPorpertyPage::OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}


