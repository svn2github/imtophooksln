// HomoWarpMFCPropertyPage.cpp : implementation file
//

#include "stdafx.h"
#include "HomoWarpFilter.h"
#include "HomoWarpMFCPropertyPage.h"

#include "DSMacro.h"
#include "resource.h"
// CHomoWarpMFCPropertyPage dialog

IMPLEMENT_DYNAMIC(CHomoWarpMFCPropertyPage, CMFCBasePropertyPage)


void CHomoWarpMFCPropertyPage::DoDataExchange(CDataExchange* pDX)
{
	CMFCBasePropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHK_FlipY, m_ckFlipY);
}


BEGIN_MESSAGE_MAP(CHomoWarpMFCPropertyPage, CMFCBasePropertyPage)

	ON_BN_CLICKED(IDC_CHK_FlipY, &CHomoWarpMFCPropertyPage::OnBnClickedChkFlipy)
END_MESSAGE_MAP()


// CHomoWarpMFCPropertyPage message handlers


CHomoWarpMFCPropertyPage::CHomoWarpMFCPropertyPage(IUnknown *pUnk) : 
CMFCBasePropertyPage(NAME("HomoWarp Page"), pUnk),
m_pFilter(0)
{
	m_slrLTx = 0;
	m_slrLTy = 0;
	m_slrLBx = 0;
	m_slrLBy = 0;
	m_slrRBx = 0;
	m_slrRBy = 0;
	m_slrRTx = 0;
	m_slrRTy = 0;

	m_txtLT = 0;
	m_txtLB = 0;
	m_txtRB = 0;
	m_txtRT = 0;
}

CHomoWarpMFCPropertyPage::~CHomoWarpMFCPropertyPage()
{
	if (m_pFilter != NULL)
	{
		m_pFilter->Release();
		m_pFilter = NULL;
	}
}


HRESULT CHomoWarpMFCPropertyPage::OnConnect(IUnknown *pUnk)
{
	if (pUnk == NULL)
	{
		return E_POINTER;
	}
	if (m_pFilter == NULL)
	{
		pUnk->QueryInterface(IID_IHomoWarpFilter, 
			reinterpret_cast<void**>(&m_pFilter));
		return S_OK;
	}
	return S_OK;
}

HRESULT CHomoWarpMFCPropertyPage::OnDisconnect(void)
{
	if (m_pFilter)
	{
		m_pFilter->Release();
		m_pFilter = NULL;
	}
	return S_OK;
}

CUnknown *WINAPI CHomoWarpMFCPropertyPage::CreateInstance(LPUNKNOWN punk, HRESULT *phr)
{
	ASSERT(phr);
	// assuming we don't want to modify the data
	CHomoWarpMFCPropertyPage *pNewObject = new CHomoWarpMFCPropertyPage(punk);

	if(pNewObject == NULL) {
		if (phr)
			*phr = E_OUTOFMEMORY;
	}

	return pNewObject;
}
bool CHomoWarpMFCPropertyPage::GetSetting()
{
	if (m_pFilter == NULL)
	{
		return false;
	}
	float LTx, LTy, LBx, LBy, RBx, RBy, RTx, RTy = 0;
	HRESULT hr = m_pFilter->GetWarpVertex(LTx, LTy, LBx, LBy, RBx, RBy, RTx, RTy);
	if (FAILED(hr))
	{
		return false;
	}
	::SLIDER_SetPos(m_slrLTx, (int)(LTx * m_slrScale));
	::SLIDER_SetPos(m_slrLTy, (int)(LTy * m_slrScale));

	::SLIDER_SetPos(m_slrLBx, (int)(LBx * m_slrScale));
	::SLIDER_SetPos(m_slrLBy, (int)(LBy * m_slrScale));

	::SLIDER_SetPos(m_slrRBx, (int)(RBx * m_slrScale));
	::SLIDER_SetPos(m_slrRBy, (int)(RBy * m_slrScale));

	::SLIDER_SetPos(m_slrRTx, (int)(RTx * m_slrScale));
	::SLIDER_SetPos(m_slrRTy, (int)(RTy * m_slrScale));
	
	m_ckFlipY.SetCheck(m_pFilter->GetIsFlipY());
	updateSliderTxt();
	return true;
}
bool CHomoWarpMFCPropertyPage::ApplySetting()
{
	if (m_pFilter == NULL)
	{
		return false;
	}
	float LTx = (1.0/m_slrScale) * ::SLIDER_GetPos(m_slrLTx);
	float LTy = (1.0/m_slrScale) * ::SLIDER_GetPos(m_slrLTy);

	float LBx = (1.0/m_slrScale) * ::SLIDER_GetPos(m_slrLBx);
	float LBy = (1.0/m_slrScale) * ::SLIDER_GetPos(m_slrLBy);

	float RBx = (1.0/m_slrScale) * ::SLIDER_GetPos(m_slrRBx);
	float RBy = (1.0/m_slrScale) * ::SLIDER_GetPos(m_slrRBy);

	float RTx = (1.0/m_slrScale) * ::SLIDER_GetPos(m_slrRTx);
	float RTy = (1.0/m_slrScale) * ::SLIDER_GetPos(m_slrRTy);

	m_pFilter->SetWarpVertex(LTx, LTy, LBx, LBy, RBx, RBy, RTx, RTy);
	m_pFilter->SetIsFlipY(m_ckFlipY.GetCheck());
	return true;
}
bool CHomoWarpMFCPropertyPage::updateSliderTxt()
{
	float LTx = (1.0/m_slrScale) * ::SLIDER_GetPos(m_slrLTx);
	float LTy = (1.0/m_slrScale) * ::SLIDER_GetPos(m_slrLTy);

	float LBx = (1.0/m_slrScale) * ::SLIDER_GetPos(m_slrLBx);
	float LBy = (1.0/m_slrScale) * ::SLIDER_GetPos(m_slrLBy);

	float RBx = (1.0/m_slrScale) * ::SLIDER_GetPos(m_slrRBx);
	float RBy = (1.0/m_slrScale) * ::SLIDER_GetPos(m_slrRBy);

	float RTx = (1.0/m_slrScale) * ::SLIDER_GetPos(m_slrRTx);
	float RTy = (1.0/m_slrScale) * ::SLIDER_GetPos(m_slrRTy);

	WCHAR str[MAX_PATH] = {0};
	swprintf_s(str, MAX_PATH, L"(%.2f, %.2f)", LTx, LTy);
	::SetWindowText(m_txtLT, str);

	swprintf_s(str, MAX_PATH, L"(%.2f, %.2f)", LBx, LBy);
	::SetWindowText(m_txtLB, str);

	swprintf_s(str, MAX_PATH, L"(%.2f, %.2f)", RBx, RBy);
	::SetWindowText(m_txtRB, str);

	swprintf_s(str, MAX_PATH, L"(%.2f, %.2f)", RTx, RTy);
	::SetWindowText(m_txtRT, str);
	return true;
}

void CHomoWarpMFCPropertyPage::SetDirty()
{
	m_bDirty = TRUE;
	HRESULT hr = S_OK;

	if (m_pPageSite) {
		hr = m_pPageSite->OnStatusChange(PROPPAGESTATUS_DIRTY);
	}

}

BOOL CHomoWarpMFCPropertyPage::OnReceiveMessage(HWND hwnd,
											UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	WCHAR str[MAX_PATH] = {0};
	int cmd = 0;

	switch (uMsg) {
	case WM_COMMAND:

		break;
	case WM_HSCROLL:
		updateSliderTxt();
		ApplySetting();
		break;
	}
	return S_OK;
	//return __super::OnReceiveMessage(hwnd,uMsg,wParam,lParam);
}


HRESULT CHomoWarpMFCPropertyPage::OnActivate(void)
{
	HWND m_Dlg = GetSafeHwnd();
	if (m_pFilter == NULL)
	{
		::EnableWindow(m_Dlg, FALSE);
		return S_OK;
	}
	::EnableWindow(m_Dlg, TRUE);

	m_slrLTx = ::GetDlgItem(m_Dlg, IDC_SLIDER_LTx);
	m_slrLTy = ::GetDlgItem(m_Dlg, IDC_SLIDER_LTy);
	m_slrLBx = ::GetDlgItem(m_Dlg, IDC_SLIDER_LBx);
	m_slrLBy = ::GetDlgItem(m_Dlg, IDC_SLIDER_LBy);
	m_slrRBx = ::GetDlgItem(m_Dlg, IDC_SLIDER_RBx);
	m_slrRBy = ::GetDlgItem(m_Dlg, IDC_SLIDER_RBy);
	m_slrRTx = ::GetDlgItem(m_Dlg, IDC_SLIDER_RTx);
	m_slrRTy = ::GetDlgItem(m_Dlg, IDC_SLIDER_RTy);

	m_txtLT = ::GetDlgItem(m_Dlg, IDC_txtLT);
	m_txtLB = ::GetDlgItem(m_Dlg, IDC_txtLB);
	m_txtRB = ::GetDlgItem(m_Dlg, IDC_txtRB);
	m_txtRT = ::GetDlgItem(m_Dlg, IDC_txtRT);

	::SLIDER_SetRange(m_slrLTx, -m_slrScale, m_slrScale);
	::SLIDER_SetRange(m_slrLTy, -m_slrScale, m_slrScale);
	::SLIDER_SetRange(m_slrLBx, -m_slrScale, m_slrScale);
	::SLIDER_SetRange(m_slrLBy,  0, 2.0*m_slrScale);
	::SLIDER_SetRange(m_slrRBx,  0, 2.0*m_slrScale);
	::SLIDER_SetRange(m_slrRBy,  0, 2.0*m_slrScale);
	::SLIDER_SetRange(m_slrRTx,  0, 2.0*m_slrScale);
	::SLIDER_SetRange(m_slrRTy, -m_slrScale, m_slrScale);

	GetSetting();
	return NOERROR;
}
HRESULT CHomoWarpMFCPropertyPage::OnApplyChanges(void)
{
	if (ApplySetting())
	{
		return S_OK;
	}
	else
	{
		return S_FALSE;
	}
}

int CHomoWarpMFCPropertyPage::GetDialogResourceID() 
{ 
	return IDD_HomoWarpPropertyPage;
}

int CHomoWarpMFCPropertyPage::GetTitileResourceID() 
{ 
	return IDS_HomoWarpPropertyDlg_Title;
}

void CHomoWarpMFCPropertyPage::OnBnClickedChkFlipy()
{
	SetDirty();
}
