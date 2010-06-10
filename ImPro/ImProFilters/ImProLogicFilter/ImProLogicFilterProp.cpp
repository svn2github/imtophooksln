#include "stdafx.h"
#include "ImProLogicFilterProp.h"
#include "ImProLogicFilterApp.h"


IMPLEMENT_DYNAMIC(ImProLogicFilterProp, GSMFCProp)

extern CImProLogicFilterApp theApp;

void ImProLogicFilterProp::DoDataExchange(CDataExchange* pDX)
{
	__super::DoDataExchange(pDX);
}
BOOL ImProLogicFilterProp::OnInitDialog()
{
	BOOL ret = __super::OnInitDialog();

	return ret;
}

BEGIN_MESSAGE_MAP(ImProLogicFilterProp, GSMFCProp)
END_MESSAGE_MAP()




ImProLogicFilterProp::ImProLogicFilterProp(IUnknown *pUnk) : 
GSMFCProp(NAME("ImProLogicFilterProp"), pUnk),
m_pFilter(0)
{
}

ImProLogicFilterProp::~ImProLogicFilterProp()
{
	if (m_pFilter != NULL)
	{
		m_pFilter->Release();
		m_pFilter = NULL;
	}
}

//override CBasePropertyPage Method
HRESULT ImProLogicFilterProp::OnConnect(IUnknown *pUnk)
{
	//override CBasePropertyPage Method
	if (pUnk == NULL)
	{
		return E_POINTER;
	}
	if (m_pFilter == NULL)
	{
		pUnk->QueryInterface(IID_IImProLogicFilter, 
			reinterpret_cast<void**>(&m_pFilter));
		return S_OK;
	}
	return S_OK;
}
HRESULT ImProLogicFilterProp::OnDisconnect(void)
{
	if (m_pFilter != NULL)
	{
		m_pFilter->Release();
		m_pFilter = NULL;
	}
	return S_OK;
}
BOOL ImProLogicFilterProp::OnReceiveMessage(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return TRUE;
}
HRESULT ImProLogicFilterProp::OnActivate(void)
{
	if (m_pFilter != NULL)
		EnableWindow(TRUE);
	else
		EnableWindow(FALSE);

	

	return S_OK;
}
HRESULT ImProLogicFilterProp::OnApplyChanges(void)
{
	return S_OK;
}

CUnknown *WINAPI ImProLogicFilterProp::CreateInstance(LPUNKNOWN punk, HRESULT *phr)
{
	ASSERT(phr);
	// assuming we don't want to modify the data
	ImProLogicFilterProp *pNewObject = new ImProLogicFilterProp(punk);

	if(pNewObject == NULL) {
		if (phr)
			*phr = E_OUTOFMEMORY;
	}

	return pNewObject;
}
