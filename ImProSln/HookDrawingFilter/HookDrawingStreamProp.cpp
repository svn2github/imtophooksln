#include "stdafx.h"
#include "HookDrawingStreamProp.h"
#include "HookDrawingFilterApp.h"

extern CHookDrawingFilterApp theApp;
IMPLEMENT_DYNAMIC(HookDrawingStreamPropPage, CMFCBasePropertyPage)


void HookDrawingStreamPropPage::DoDataExchange(CDataExchange* pDX)
{
	CMFCBasePropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_edLeft, m_edLeft);
	DDX_Control(pDX, IDC_edRight, m_edRight);
	DDX_Control(pDX, IDC_edTop, m_edTop);
	DDX_Control(pDX, IDC_edBottom, m_edBottom);
}
BOOL HookDrawingStreamPropPage::OnInitDialog()
{
	BOOL ret = __super::OnInitDialog();
	
	return ret;
}

BEGIN_MESSAGE_MAP(HookDrawingStreamPropPage, CMFCBasePropertyPage)
	ON_EN_KILLFOCUS(IDC_edLeft, &HookDrawingStreamPropPage::OnEnKillfocusedleft)
	ON_EN_KILLFOCUS(IDC_edRight, &HookDrawingStreamPropPage::OnEnKillfocusedright)
	ON_EN_KILLFOCUS(IDC_edTop, &HookDrawingStreamPropPage::OnEnKillfocusedtop)
	ON_EN_KILLFOCUS(IDC_edBottom, &HookDrawingStreamPropPage::OnEnKillfocusedbottom)
	ON_EN_CHANGE(IDC_edTop, &HookDrawingStreamPropPage::OnEnChangeedtop)
	ON_EN_CHANGE(IDC_edLeft, &HookDrawingStreamPropPage::OnEnChangeedleft)
	ON_EN_CHANGE(IDC_edRight, &HookDrawingStreamPropPage::OnEnChangeedright)
	ON_EN_CHANGE(IDC_edBottom, &HookDrawingStreamPropPage::OnEnChangeedbottom)
END_MESSAGE_MAP()


// CHomoWarpMFCPropertyPage message handlers


HookDrawingStreamPropPage::HookDrawingStreamPropPage(IUnknown *pUnk) : 
CMFCBasePropertyPage(NAME("HookDrawingStreamPropPage"), pUnk),
m_pPin(0)
{
	
}

HookDrawingStreamPropPage::~HookDrawingStreamPropPage()
{
	if (m_pPin != NULL)
	{
		m_pPin->Release();
		m_pPin = NULL;
	}
}

//override CBasePropertyPage Method
HRESULT HookDrawingStreamPropPage::OnConnect(IUnknown *pUnk)
{
	//override CBasePropertyPage Method
	if (pUnk == NULL)
	{
		return E_POINTER;
	}
	if (m_pPin == NULL)
	{
		pUnk->QueryInterface(IID_IHookDrawingStream, 
			reinterpret_cast<void**>(&m_pPin));
		return S_OK;
	}
	return S_OK;
}
HRESULT HookDrawingStreamPropPage::OnDisconnect(void)
{
	if (m_pPin != NULL)
	{
		m_pPin->Release();
		m_pPin = NULL;
	}
	return S_OK;
}
BOOL HookDrawingStreamPropPage::OnReceiveMessage(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return TRUE;
}
HRESULT HookDrawingStreamPropPage::OnActivate(void)
{
	EnableWindow(TRUE);
	GetSetting();
	return S_OK;
}
HRESULT HookDrawingStreamPropPage::OnApplyChanges(void)
{
	if (ApplySetting())
	{
		return S_OK;
	}
	return S_FALSE;
}

CUnknown *WINAPI HookDrawingStreamPropPage::CreateInstance(LPUNKNOWN punk, HRESULT *phr)
{
	ASSERT(phr);
	// assuming we don't want to modify the data
	HookDrawingStreamPropPage *pNewObject = new HookDrawingStreamPropPage(punk);

	if(pNewObject == NULL) {
		if (phr)
			*phr = E_OUTOFMEMORY;
	}

	return pNewObject;
}
bool HookDrawingStreamPropPage::GetSetting()
{
	if (m_pPin == NULL)
		return false;
	D3DXVECTOR2 lt, lb, rb, rt;
	m_pPin->GetWarpPts(lt, lb, rb, rt);
	WCHAR str[MAX_PATH];
	swprintf_s(str, MAX_PATH, L"%.2f", lt.x);
	m_edLeft.SetWindowText(str);
	swprintf_s(str, MAX_PATH, L"%.2f", lt.y);
	m_edTop.SetWindowText(str);

	swprintf_s(str, MAX_PATH, L"%.2f", rb.x);
	m_edRight.SetWindowText(str);
	swprintf_s(str, MAX_PATH, L"%.2f", rb.y);
	m_edBottom.SetWindowText(str);

	return true;
}
bool HookDrawingStreamPropPage::ApplySetting()
{
	
	WCHAR str[MAX_PATH];
	float l = 0, r = 0, t = 0, b = 0;
	try
	{
		m_edLeft.GetWindowText(str, MAX_PATH);
		swscanf_s(str, L"%f", &l );
		m_edRight.GetWindowText(str, MAX_PATH);
		swscanf_s(str, L"%f", &r );
		m_edTop.GetWindowText(str, MAX_PATH);
		swscanf_s(str, L"%f", &t );
		m_edBottom.GetWindowText(str, MAX_PATH);
		swscanf_s(str, L"%f", &b );
		D3DXVECTOR2 lt(l, t);
		D3DXVECTOR2 lb(l, b);
		D3DXVECTOR2 rb(r, b);
		D3DXVECTOR2 rt(r, t);
		m_pPin->SetWarpByPts(lt, lb, rb, rt);
	}
	catch (CException* e)
	{
		ASSERT("Wrong Input Format!!");
		return false;
	}
	return true;
}
void HookDrawingStreamPropPage::OnEnKillfocusedleft()
{
	ApplySetting();
}

void HookDrawingStreamPropPage::OnEnKillfocusedright()
{
	ApplySetting();
}

void HookDrawingStreamPropPage::OnEnKillfocusedtop()
{
	ApplySetting();
}

void HookDrawingStreamPropPage::OnEnKillfocusedbottom()
{
	ApplySetting();
}

void HookDrawingStreamPropPage::OnEnChangeedtop()
{
	SetDirty();
}

void HookDrawingStreamPropPage::OnEnChangeedleft()
{	
	SetDirty();
}

void HookDrawingStreamPropPage::OnEnChangeedright()
{
	SetDirty();
}

void HookDrawingStreamPropPage::OnEnChangeedbottom()
{
	SetDirty();
}
