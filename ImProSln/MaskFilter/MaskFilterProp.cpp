#include "stdafx.h"
#include "MaskFilterProp.h"
#include "MaskFilterApp.h"


IMPLEMENT_DYNAMIC(MaskFilterPropPage, CMFCBasePropertyPage)

extern CMaskFilterApp theApp;



void MaskFilterPropPage::DoDataExchange(CDataExchange* pDX)
{
	CMFCBasePropertyPage::DoDataExchange(pDX);
}
BOOL MaskFilterPropPage::OnInitDialog()
{
	BOOL ret = __super::OnInitDialog();

	return ret;
}

BEGIN_MESSAGE_MAP(MaskFilterPropPage, CMFCBasePropertyPage)
	ON_WM_CREATE()

END_MESSAGE_MAP()


// CHomoWarpMFCPropertyPage message handlers


MaskFilterPropPage::MaskFilterPropPage(IUnknown *pUnk) : 
CMFCBasePropertyPage(NAME("MaskFilterPropPage"), pUnk),
m_pFilter(0)
{
}

MaskFilterPropPage::~MaskFilterPropPage()
{
	if (m_pFilter != NULL)
	{
		m_pFilter->Release();
		m_pFilter = NULL;
	}
}

//override CBasePropertyPage Method
HRESULT MaskFilterPropPage::OnConnect(IUnknown *pUnk)
{
	//override CBasePropertyPage Method
	if (pUnk == NULL)
	{
		return E_POINTER;
	}
	if (m_pFilter == NULL)
	{
		pUnk->QueryInterface(IID_IMaskFilter, 
			reinterpret_cast<void**>(&m_pFilter));
		return S_OK;
	}
	return S_OK;
}
HRESULT MaskFilterPropPage::OnDisconnect(void)
{
	if (m_pFilter != NULL)
	{
		m_pFilter->Release();
		m_pFilter = NULL;
	}
	return S_OK;
}
BOOL MaskFilterPropPage::OnReceiveMessage(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return TRUE;
}
HRESULT MaskFilterPropPage::OnActivate(void)
{
	EnableWindow(TRUE);
	return S_OK;
}
HRESULT MaskFilterPropPage::OnApplyChanges(void)
{
	return S_OK;
}

CUnknown *WINAPI MaskFilterPropPage::CreateInstance(LPUNKNOWN punk, HRESULT *phr)
{
	ASSERT(phr);
	// assuming we don't want to modify the data
	MaskFilterPropPage *pNewObject = new MaskFilterPropPage(punk);

	if(pNewObject == NULL) {
		if (phr)
			*phr = E_OUTOFMEMORY;
	}

	return pNewObject;
}