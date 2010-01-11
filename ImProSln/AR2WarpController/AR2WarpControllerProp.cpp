#include "stdafx.h"
#include "AR2WarpControllerProp.h"

IMPLEMENT_DYNAMIC(AR2WarpControllerPropertyPage, CMFCBasePropertyPage)


void AR2WarpControllerPropertyPage::DoDataExchange(CDataExchange* pDX)
{
	CMFCBasePropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(AR2WarpControllerPropertyPage, CMFCBasePropertyPage)
END_MESSAGE_MAP()


// CHomoWarpMFCPropertyPage message handlers


AR2WarpControllerPropertyPage::AR2WarpControllerPropertyPage(IUnknown *pUnk) : 
CMFCBasePropertyPage(NAME("AR2WarpControllerPropertyPage"), pUnk),
m_pFilter(0)
{

}

AR2WarpControllerPropertyPage::~AR2WarpControllerPropertyPage()
{
	if (m_pFilter != NULL)
	{
		m_pFilter->Release();
		m_pFilter = NULL;
	}
}

//override CBasePropertyPage Method
HRESULT AR2WarpControllerPropertyPage::OnConnect(IUnknown *pUnk)
{
	return S_OK;
}
HRESULT AR2WarpControllerPropertyPage::OnDisconnect(void)
{
	return S_OK;
}
BOOL AR2WarpControllerPropertyPage::OnReceiveMessage(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return TRUE;
}
HRESULT AR2WarpControllerPropertyPage::OnActivate(void)
{
	return S_OK;
}
HRESULT AR2WarpControllerPropertyPage::OnApplyChanges(void)
{
	return S_OK;
}

CUnknown *WINAPI AR2WarpControllerPropertyPage::CreateInstance(LPUNKNOWN punk, HRESULT *phr)
{
	ASSERT(phr);
	// assuming we don't want to modify the data
	AR2WarpControllerPropertyPage *pNewObject = new AR2WarpControllerPropertyPage(punk);

	if(pNewObject == NULL) {
		if (phr)
			*phr = E_OUTOFMEMORY;
	}

	return pNewObject;
}