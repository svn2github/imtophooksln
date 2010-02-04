#include "stdafx.h"
#include "DXRenderProp.h"

IMPLEMENT_DYNAMIC(DXRenderFilterProp, CMFCBasePropertyPage)


void DXRenderFilterProp::DoDataExchange(CDataExchange* pDX)
{
	CMFCBasePropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CKHideBorder, m_ckHideBorder);
}


BEGIN_MESSAGE_MAP(DXRenderFilterProp, CMFCBasePropertyPage)
	ON_BN_CLICKED(IDC_CKHideBorder, &DXRenderFilterProp::OnBnClickedCkhideborder)
END_MESSAGE_MAP()


// CHomoWarpMFCPropertyPage message handlers


DXRenderFilterProp::DXRenderFilterProp(IUnknown *pUnk) : 
CMFCBasePropertyPage(NAME("DXRenderFilterProp"), pUnk),
m_pFilter(0)
{

}

DXRenderFilterProp::~DXRenderFilterProp()
{
	if (m_pFilter != NULL)
	{
		m_pFilter->Release();
		m_pFilter = NULL;
	}
}

//override CBasePropertyPage Method
HRESULT DXRenderFilterProp::OnConnect(IUnknown *pUnk)
{
	if (pUnk == NULL)
	{
		return E_POINTER;
	}
	if (m_pFilter == NULL)
	{
		pUnk->QueryInterface(IID_IDXRenderer, 
			reinterpret_cast<void**>(&m_pFilter));
		return S_OK;
	}
	return S_OK;
}
HRESULT DXRenderFilterProp::OnDisconnect(void)
{
	return S_OK;
}
BOOL DXRenderFilterProp::OnReceiveMessage(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return TRUE;
}
HRESULT DXRenderFilterProp::OnActivate(void)
{
	if (m_pFilter != NULL)
	{
		this->EnableWindow(TRUE);
	}
	
	return S_OK;
}
HRESULT DXRenderFilterProp::OnApplyChanges(void)
{
	return S_OK;
}

CUnknown *WINAPI DXRenderFilterProp::CreateInstance(LPUNKNOWN punk, HRESULT *phr)
{
	ASSERT(phr);
	// assuming we don't want to modify the data
	DXRenderFilterProp *pNewObject = new DXRenderFilterProp(punk);

	if(pNewObject == NULL) {
		if (phr)
			*phr = E_OUTOFMEMORY;
	}

	return pNewObject;
}
void DXRenderFilterProp::OnBnClickedCkhideborder()
{
	if (m_pFilter == NULL)
		return;
	HWND hwnd = m_pFilter->GetDisplayWindow();
	if (hwnd == 0)
	{
		return;
	}
	LONG wndStyle = GetWindowLong(hwnd, GWL_STYLE);
	LONG newStyle = 0;
	bool checked = m_ckHideBorder.GetCheck();
	if (checked)
	{
		newStyle = WS_BORDER ^ wndStyle;
		SetWindowLong(hwnd, GWL_STYLE, newStyle);
	}
	else
	{
		newStyle = WS_BORDER | wndStyle;
		SetWindowLong(hwnd, GWL_STYLE, newStyle);
	}
}
