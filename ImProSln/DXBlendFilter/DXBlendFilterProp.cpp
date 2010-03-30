#include "stdafx.h"
#include "DXBlendFilterProp.h"

IMPLEMENT_DYNAMIC(DXBlendFilterProp, CMFCBasePropertyPage)


void DXBlendFilterProp::DoDataExchange(CDataExchange* pDX)
{
	CMFCBasePropertyPage::DoDataExchange(pDX);
	
}


BEGIN_MESSAGE_MAP(DXBlendFilterProp, CMFCBasePropertyPage)

END_MESSAGE_MAP()


// CHomoWarpMFCPropertyPage message handlers


DXBlendFilterProp::DXBlendFilterProp(IUnknown *pUnk) : 
CMFCBasePropertyPage(NAME("DXBlendFilterProp"), pUnk),
m_pFilter(0)
{

}

DXBlendFilterProp::~DXBlendFilterProp()
{
	if (m_pFilter != NULL)
	{
		m_pFilter->Release();
		m_pFilter = NULL;
	}
}

//override CBasePropertyPage Method
HRESULT DXBlendFilterProp::OnConnect(IUnknown *pUnk)
{
	if (pUnk == NULL)
	{
		return E_POINTER;
	}
	if (m_pFilter == NULL)
	{
		pUnk->QueryInterface(IID_IDXBlendFilter, 
			reinterpret_cast<void**>(&m_pFilter));
		return S_OK;
	}
	return S_OK;
}
HRESULT DXBlendFilterProp::OnDisconnect(void)
{
	return S_OK;
}
BOOL DXBlendFilterProp::OnReceiveMessage(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return TRUE;
}
HRESULT DXBlendFilterProp::OnActivate(void)
{
	if (m_pFilter != NULL)
	{
		this->EnableWindow(TRUE);
	}

	GetSetting();
	return S_OK;
}

bool DXBlendFilterProp::GetSetting()
{
	if (m_pFilter == NULL)
	{
		return false;
	}
	WCHAR str[MAX_PATH] = {0};
	return true;
}

bool DXBlendFilterProp::ApplySetting()
{
	if (m_pFilter == NULL)
		return false;


	return true;
}
HRESULT DXBlendFilterProp::OnApplyChanges(void)
{
	return S_OK;
}

CUnknown *WINAPI DXBlendFilterProp::CreateInstance(LPUNKNOWN punk, HRESULT *phr)
{
	ASSERT(phr);
	// assuming we don't want to modify the data
	DXBlendFilterProp *pNewObject = new DXBlendFilterProp(punk);

	if(pNewObject == NULL) {
		if (phr)
			*phr = E_OUTOFMEMORY;
	}

	return pNewObject;
}
