#include "stdafx.h"
#include "DXRenderProp.h"

IMPLEMENT_DYNAMIC(DXRenderFilterProp, CMFCBasePropertyPage)


void DXRenderFilterProp::DoDataExchange(CDataExchange* pDX)
{
	CMFCBasePropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DXRenderFilterProp, CMFCBasePropertyPage)
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