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

	ON_BN_CLICKED(IDC_BUTTON1, &CBGMappingPorpertyPage::OnBnClickedButton1)
	
END_MESSAGE_MAP()


// CHomoWarpMFCPropertyPage message handlers


CBGMappingPorpertyPage::CBGMappingPorpertyPage(IUnknown *pUnk) : 
CMFCBasePropertyPage(NAME("BackGroundMapping Page"), pUnk),
m_pFilter(0)
{
	m_threshold = 0 ;
	m_txt = 0 ;
	m_erodeValue = 0 ;
	m_Btxt = 0 ;
	m_subValue = 0 ;
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
	m_pFilter->setBGThreshold(SLIDER_GetPos(m_threshold));
	SetDlgItemInt(IDC_EDIT_threshold,m_pFilter->getBGThreshold());

	m_pFilter->setAbsDiffSubValue(SLIDER_GetPos(m_subValue));
	SetDlgItemInt(IDC_EDIT_DiffSub,m_pFilter->getAbsDiffSubValue());
	
	m_pFilter->setBGAdjustValue(SLIDER_GetPos(m_BGadjustValue));
	SetDlgItemInt(IDC_EDIT_BGAdjust,m_pFilter->getBGAdjustValue());

	m_pFilter->setErodeValue(SLIDER_GetPos(m_erodeValue));
	SetDlgItemInt(IDC_EDIT_Erode,m_pFilter->getErodeValue());
	
	m_pFilter->setCamFlip(m_checkCamFlip->GetCheck());
	m_pFilter->setLayoutFlip(m_checkLayoutFlip->GetCheck());
	m_pFilter->setOutputFlip(m_checkOutputFlip->GetCheck());
	m_pFilter->setShowWindow(m_checkShowWindow->GetCheck());
	m_pFilter->setSaveImg(m_checkSaveImg->GetCheck());
	
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
	m_txt = ::GetDlgItem(m_Dlg, IDC_EDIT_threshold);

	m_subValue = ::GetDlgItem(m_Dlg,IDC_SLIDER_diffSub);
	m_Wtxt = ::GetDlgItem(m_Dlg, IDC_EDIT_DiffSub);

	m_erodeValue = ::GetDlgItem(m_Dlg,IDC_SLIDER_erode);
	m_Btxt = ::GetDlgItem(m_Dlg, IDC_EDIT_Erode);

	m_BGadjustValue = ::GetDlgItem(m_Dlg,IDC_SLIDER_BGAdiustValue);
	m_Atxt = ::GetDlgItem(m_Dlg,IDC_EDIT_BGAdjust);

	m_checkCamFlip = (CButton*)GetDlgItem(IDC_CHECK_camera);
	m_checkLayoutFlip = (CButton*)GetDlgItem(IDC_CHECK_Layout);
	m_checkOutputFlip = (CButton*)GetDlgItem(IDC_CHECK_Output);
	m_checkShowWindow = (CButton*)GetDlgItem(IDC_CHECK_Show);
	m_checkSaveImg = (CButton*)GetDlgItem(IDC_CHECK_Save);

	SLIDER_SetRange(m_threshold, 0, 255);
	SLIDER_SetPos(m_threshold,m_pFilter->getBGThreshold());
	SetDlgItemInt(IDC_EDIT_threshold,m_pFilter->getBGThreshold());

	SLIDER_SetRange(m_erodeValue, 0, 10);
	SLIDER_SetPos(m_erodeValue,m_pFilter->getErodeValue());
	SetDlgItemInt(IDC_EDIT_Erode,m_pFilter->getErodeValue());

	SLIDER_SetRange(m_subValue, 0, 255);
	SLIDER_SetPos(m_subValue,m_pFilter->getAbsDiffSubValue());
	SetDlgItemInt(IDC_EDIT_DiffSub,m_pFilter->getAbsDiffSubValue());

	SLIDER_SetRange(m_BGadjustValue,-255, 255);
	SLIDER_SetPos(m_BGadjustValue,m_pFilter->getBGAdjustValue());
	SetDlgItemInt(IDC_EDIT_BGAdjust,m_pFilter->getBGAdjustValue());

	m_checkCamFlip->SetCheck(m_pFilter->getCamFlip());
	m_checkLayoutFlip->SetCheck(m_pFilter->getLayoutFlip());
	m_checkOutputFlip->SetCheck(m_pFilter->getOutputFlip());
	m_checkShowWindow->SetCheck(m_pFilter->getShowWindow());
	m_checkSaveImg->SetCheck(m_pFilter->getSaveImg());
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



void CBGMappingPorpertyPage::OnBnClickedButton1()  // save Button
{

	m_pFilter->setCamFlip(m_checkCamFlip->GetCheck());
	m_pFilter->setLayoutFlip(m_checkLayoutFlip->GetCheck());
	m_pFilter->setOutputFlip(m_checkOutputFlip->GetCheck());
	m_pFilter->setShowWindow(m_checkShowWindow->GetCheck());
	m_pFilter->setSaveImg(m_checkSaveImg->GetCheck());

	extern HMODULE GetModule();
	WCHAR str[MAX_PATH] = {0};
	HMODULE module = GetModule();
	GetModuleFileName(module, str, MAX_PATH);
	// Gets filename
	WCHAR* pszFile = wcsrchr(str, '\\');
	pszFile++;    // Moves on from \
	// Get path
	WCHAR szPath[MAX_PATH] = L"";
	_tcsncat(szPath, str, pszFile - str);

	char fileDir[100];
	int size= wcslen(szPath);

	wcstombs(fileDir, szPath, size+1);
	
	char Dir[100];
	sprintf(Dir,"%s\\ProjectorCalibData\\adjustValue.txt",fileDir) ;

	FILE  * pFile ;
	pFile = fopen(Dir,"w");

	fprintf(pFile ,"[ %d %d %d %d %d %d %d %d %d] \n",m_pFilter->getBGThreshold() ,m_pFilter->getAbsDiffSubValue(),m_pFilter->getBGAdjustValue(), m_pFilter->getErodeValue(),m_pFilter->getCamFlip(),m_pFilter->getLayoutFlip(),m_pFilter->getOutputFlip(), m_pFilter->getShowWindow(), m_pFilter->getSaveImg());  

	fclose(pFile);
}
