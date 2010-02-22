#include "stdafx.h"
#include "ProjectSettingFilterProp.h"
#include "ProjectSettingFilterApp.h"


IMPLEMENT_DYNAMIC(ProjectSettingPropPage, CMFCBasePropertyPage)

extern CProjectSettingFilterApp theApp;



void ProjectSettingPropPage::DoDataExchange(CDataExchange* pDX)
{
	CMFCBasePropertyPage::DoDataExchange(pDX);

}
BOOL ProjectSettingPropPage::OnInitDialog()
{
	BOOL ret = __super::OnInitDialog();

	return ret;
}

BEGIN_MESSAGE_MAP(ProjectSettingPropPage, CMFCBasePropertyPage)
END_MESSAGE_MAP()


// CHomoWarpMFCPropertyPage message handlers


ProjectSettingPropPage::ProjectSettingPropPage(IUnknown *pUnk) : 
CMFCBasePropertyPage(NAME("ProjectSettingPropPage"), pUnk),
m_pFilter(0)
{
}

ProjectSettingPropPage::~ProjectSettingPropPage()
{
	if (m_pFilter != NULL)
	{
		m_pFilter->Release();
		m_pFilter = NULL;
	}
}

//override CBasePropertyPage Method
HRESULT ProjectSettingPropPage::OnConnect(IUnknown *pUnk)
{
	//override CBasePropertyPage Method
	if (pUnk == NULL)
	{
		return E_POINTER;
	}
	if (m_pFilter == NULL)
	{
		pUnk->QueryInterface(IID_IProjectSettingFilter, 
			reinterpret_cast<void**>(&m_pFilter));
		return S_OK;
	}
	return S_OK;
}
HRESULT ProjectSettingPropPage::OnDisconnect(void)
{
	if (m_pFilter != NULL)
	{
		m_pFilter->Release();
		m_pFilter = NULL;
	}
	return S_OK;
}
BOOL ProjectSettingPropPage::OnReceiveMessage(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return TRUE;
}
HRESULT ProjectSettingPropPage::OnActivate(void)
{
	if (m_pFilter != NULL)
		EnableWindow(TRUE);
	else
		EnableWindow(FALSE);

	return S_OK;
}
HRESULT ProjectSettingPropPage::OnApplyChanges(void)
{
	return S_OK;
}

CUnknown *WINAPI ProjectSettingPropPage::CreateInstance(LPUNKNOWN punk, HRESULT *phr)
{
	ASSERT(phr);
	// assuming we don't want to modify the data
	ProjectSettingPropPage *pNewObject = new ProjectSettingPropPage(punk);

	if(pNewObject == NULL) {
		if (phr)
			*phr = E_OUTOFMEMORY;
	}

	return pNewObject;
}
