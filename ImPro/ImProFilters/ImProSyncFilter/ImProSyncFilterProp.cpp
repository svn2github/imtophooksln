#include "stdafx.h"
#include "ImProSyncFilterProp.h"
#include "ImProSyncFilterApp.h"


IMPLEMENT_DYNAMIC(ImProSyncFilterProp, GSMFCProp)

extern CImProSyncFilterApp theApp;

void ImProSyncFilterProp::DoDataExchange(CDataExchange* pDX)
{
	__super::DoDataExchange(pDX);
}
BOOL ImProSyncFilterProp::OnInitDialog()
{
	BOOL ret = __super::OnInitDialog();

	return ret;
}

BEGIN_MESSAGE_MAP(ImProSyncFilterProp, GSMFCProp)
END_MESSAGE_MAP()




ImProSyncFilterProp::ImProSyncFilterProp(IUnknown *pUnk) : 
GSMFCProp(NAME("ImProSyncFilterProp"), pUnk),
m_pFilter(0)
{
}

ImProSyncFilterProp::~ImProSyncFilterProp()
{
	if (m_pFilter != NULL)
	{
		m_pFilter->Release();
		m_pFilter = NULL;
	}
}

//override CBasePropertyPage Method
HRESULT ImProSyncFilterProp::OnConnect(IUnknown *pUnk)
{
	//override CBasePropertyPage Method
	if (pUnk == NULL)
	{
		return E_POINTER;
	}
	if (m_pFilter == NULL)
	{
		pUnk->QueryInterface(IID_IImProSyncFilter, 
			reinterpret_cast<void**>(&m_pFilter));
		return S_OK;
	}
	return S_OK;
}
HRESULT ImProSyncFilterProp::OnDisconnect(void)
{
	if (m_pFilter != NULL)
	{
		m_pFilter->Release();
		m_pFilter = NULL;
	}
	return S_OK;
}
BOOL ImProSyncFilterProp::OnReceiveMessage(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return TRUE;
}
HRESULT ImProSyncFilterProp::OnActivate(void)
{
	if (m_pFilter != NULL)
		EnableWindow(TRUE);
	else
		EnableWindow(FALSE);

	

	return S_OK;
}
HRESULT ImProSyncFilterProp::OnApplyChanges(void)
{
	return S_OK;
}

CUnknown *WINAPI ImProSyncFilterProp::CreateInstance(LPUNKNOWN punk, HRESULT *phr)
{
	ASSERT(phr);
	// assuming we don't want to modify the data
	ImProSyncFilterProp *pNewObject = new ImProSyncFilterProp(punk);

	if(pNewObject == NULL) {
		if (phr)
			*phr = E_OUTOFMEMORY;
	}

	return pNewObject;
}
