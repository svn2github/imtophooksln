#include "stdafx.h"
#include "GSFrameCaptureFilterProp.h"
#include "GSFrameCaptureFilterApp.h"


IMPLEMENT_DYNAMIC(GSFrameCaptureFilterProp, GSMFCProp)

extern CGSFrameCaptureFilterApp theApp;

void GSFrameCaptureFilterProp::DoDataExchange(CDataExchange* pDX)
{
	__super::DoDataExchange(pDX);
}
BOOL GSFrameCaptureFilterProp::OnInitDialog()
{
	BOOL ret = __super::OnInitDialog();

	return ret;
}

BEGIN_MESSAGE_MAP(GSFrameCaptureFilterProp, GSMFCProp)
END_MESSAGE_MAP()




GSFrameCaptureFilterProp::GSFrameCaptureFilterProp(IUnknown *pUnk) : 
GSMFCProp(NAME("GSFrameCaptureFilterProp"), pUnk),
m_pFilter(0)
{
}

GSFrameCaptureFilterProp::~GSFrameCaptureFilterProp()
{
	if (m_pFilter != NULL)
	{
		m_pFilter->Release();
		m_pFilter = NULL;
	}
}

//override CBasePropertyPage Method
HRESULT GSFrameCaptureFilterProp::OnConnect(IUnknown *pUnk)
{
	//override CBasePropertyPage Method
	if (pUnk == NULL)
	{
		return E_POINTER;
	}
	if (m_pFilter == NULL)
	{
		pUnk->QueryInterface(IID_IGSFrameCaptureFilter, 
			reinterpret_cast<void**>(&m_pFilter));
		return S_OK;
	}
	return S_OK;
}
HRESULT GSFrameCaptureFilterProp::OnDisconnect(void)
{
	if (m_pFilter != NULL)
	{
		m_pFilter->Release();
		m_pFilter = NULL;
	}
	return S_OK;
}
BOOL GSFrameCaptureFilterProp::OnReceiveMessage(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return TRUE;
}
HRESULT GSFrameCaptureFilterProp::OnActivate(void)
{
	if (m_pFilter != NULL)
		EnableWindow(TRUE);
	else
		EnableWindow(FALSE);

	

	return S_OK;
}
HRESULT GSFrameCaptureFilterProp::OnApplyChanges(void)
{
	return S_OK;
}

CUnknown *WINAPI GSFrameCaptureFilterProp::CreateInstance(LPUNKNOWN punk, HRESULT *phr)
{
	ASSERT(phr);
	// assuming we don't want to modify the data
	GSFrameCaptureFilterProp *pNewObject = new GSFrameCaptureFilterProp(punk);

	if(pNewObject == NULL) {
		if (phr)
			*phr = E_OUTOFMEMORY;
	}

	return pNewObject;
}
