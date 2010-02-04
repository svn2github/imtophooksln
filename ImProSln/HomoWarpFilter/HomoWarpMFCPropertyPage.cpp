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
	DDX_Control(pDX, IDC_edLT, m_edLT);
	DDX_Control(pDX, IDC_edRT, m_edRT);
	DDX_Control(pDX, IDC_edLB, m_edLB);
	DDX_Control(pDX, IDC_edRB, m_edRB);
}


BEGIN_MESSAGE_MAP(CHomoWarpMFCPropertyPage, CMFCBasePropertyPage)

	ON_BN_CLICKED(IDC_CHK_FlipY, &CHomoWarpMFCPropertyPage::OnBnClickedChkFlipy)
	ON_EN_KILLFOCUS(IDC_edLT, &CHomoWarpMFCPropertyPage::OnEnKillfocusedlt)
	ON_EN_KILLFOCUS(IDC_edRT, &CHomoWarpMFCPropertyPage::OnEnKillfocusedrt)
	ON_EN_KILLFOCUS(IDC_edLB, &CHomoWarpMFCPropertyPage::OnEnKillfocusedlb)
	ON_EN_KILLFOCUS(IDC_edRB, &CHomoWarpMFCPropertyPage::OnEnKillfocusedrb)
	ON_EN_CHANGE(IDC_edLT, &CHomoWarpMFCPropertyPage::OnEnChangeedlt)
	ON_EN_CHANGE(IDC_edRT, &CHomoWarpMFCPropertyPage::OnEnChangeedrt)
	ON_EN_CHANGE(IDC_edLB, &CHomoWarpMFCPropertyPage::OnEnChangeedlb)
	ON_EN_CHANGE(IDC_edRB, &CHomoWarpMFCPropertyPage::OnEnChangeedrb)
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
	swprintf_s(str, MAX_PATH, L"%.2f, %.2f", LTx, LTy);
	m_edLT.SetWindowText(str);

	swprintf_s(str, MAX_PATH, L"%.2f, %.2f", LBx, LBy);
	m_edLB.SetWindowText(str);

	swprintf_s(str, MAX_PATH, L"%.2f, %.2f", RBx, RBy);
	m_edRB.SetWindowText(str);

	swprintf_s(str, MAX_PATH, L"%.2f, %.2f", RTx, RTy);
	m_edRT.SetWindowText(str);
	return true;
}

bool CHomoWarpMFCPropertyPage::ApplySettingFromEdit()
{
	if (m_pFilter == NULL)
	{
		return false;
	}
	WCHAR str[MAX_PATH];
	double LTx = 0;
	double LTy = 0;

	double LBx = 0;
	double LBy = 0;

	double RBx = 0;
	double RBy = 0;

	double RTx = 0;
	double RTy = 0;
	try
	{
		m_edLT.GetWindowText(str, MAX_PATH);
		swscanf_s(str, L"%lf, %lf", &LTx, &LTy );
		
		m_edLB.GetWindowText(str, MAX_PATH);
		swscanf_s(str, L"%lf, %lf", &LBx, &LBy );

		m_edRB.GetWindowText(str, MAX_PATH);
		swscanf_s(str, L"%lf, %lf", &RBx, &RBy );

		m_edRT.GetWindowText(str, MAX_PATH);
		swscanf_s(str, L"%lf, %lf", &RTx, &RTy );

		m_pFilter->SetWarpVertex(LTx, LTy, LBx, LBy, RBx, RBy, RTx, RTy);
		m_pFilter->SetIsFlipY(m_ckFlipY.GetCheck());
	}
	catch(exception e)
	{
		return false;
	}
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


	::SLIDER_SetRange(m_slrLTx, -m_slrScale*m_slrRangeScale, m_slrScale*m_slrRangeScale);
	::SLIDER_SetRange(m_slrLTy, -m_slrScale*m_slrRangeScale, m_slrScale*m_slrRangeScale);
	::SLIDER_SetRange(m_slrLBx, -m_slrScale*m_slrRangeScale, m_slrScale*m_slrRangeScale);
	::SLIDER_SetRange(m_slrLBy, -m_slrScale*(m_slrRangeScale-1), m_slrScale*(m_slrRangeScale+1));
	::SLIDER_SetRange(m_slrRBx, -m_slrScale*(m_slrRangeScale-1), m_slrScale*(m_slrRangeScale+1));
	::SLIDER_SetRange(m_slrRBy, -m_slrScale*(m_slrRangeScale-1), m_slrScale*(m_slrRangeScale+1));
	::SLIDER_SetRange(m_slrRTx, -m_slrScale*(m_slrRangeScale-1), m_slrScale*(m_slrRangeScale+1));
	::SLIDER_SetRange(m_slrRTy, -m_slrScale*m_slrRangeScale, m_slrScale*m_slrRangeScale);

	GetSetting();
	return NOERROR;
}
HRESULT CHomoWarpMFCPropertyPage::OnApplyChanges(void)
{
	if (ApplySettingFromEdit())
	{
		GetSetting();
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

void CHomoWarpMFCPropertyPage::OnEnKillfocusedlt()
{
	ApplySettingFromEdit();
	GetSetting();
}

void CHomoWarpMFCPropertyPage::OnEnKillfocusedrt()
{
	ApplySettingFromEdit();
	GetSetting();
}

void CHomoWarpMFCPropertyPage::OnEnKillfocusedlb()
{
	ApplySettingFromEdit();
	GetSetting();
}

void CHomoWarpMFCPropertyPage::OnEnKillfocusedrb()
{
	ApplySettingFromEdit();
	GetSetting();
}

void CHomoWarpMFCPropertyPage::OnEnChangeedlt()
{
	SetDirty();
}

void CHomoWarpMFCPropertyPage::OnEnChangeedrt()
{
	SetDirty();
}

void CHomoWarpMFCPropertyPage::OnEnChangeedlb()
{
	SetDirty();
}

void CHomoWarpMFCPropertyPage::OnEnChangeedrb()
{
	SetDirty();
}
