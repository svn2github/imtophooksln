#include "stdafx.h"
#include "ProjectSettingFilterProp.h"
#include "ProjectSettingFilterApp.h"
#include "ProjectSettingFilter.h"

IMPLEMENT_DYNAMIC(ProjectSettingPropPage, CMFCBasePropertyPage)

extern CProjectSettingFilterApp theApp;



void ProjectSettingPropPage::DoDataExchange(CDataExchange* pDX)
{
	CMFCBasePropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDPath, m_edPath);
}
BOOL ProjectSettingPropPage::OnInitDialog()
{
	BOOL ret = __super::OnInitDialog();

	return ret;
}

BEGIN_MESSAGE_MAP(ProjectSettingPropPage, CMFCBasePropertyPage)
	ON_BN_CLICKED(IDC_btnBrowse, &ProjectSettingPropPage::OnBnClickedbtnbrowse)
	ON_BN_CLICKED(IDC_BTN_LOAD, &ProjectSettingPropPage::OnBnClickedBtnLoad)
	ON_BN_CLICKED(IDC_BTN_Save, &ProjectSettingPropPage::OnBnClickedBtnSave)
END_MESSAGE_MAP()




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
	CString path;
	path = theApp.GetProfileString(L"MySetting",L"ProjectSettingPath", L"");
	m_edPath.SetWindowText(path);

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

void ProjectSettingPropPage::OnBnClickedbtnbrowse()
{
	WCHAR curDic[MAX_PATH] = {0};
	GetCurrentDirectoryW(MAX_PATH, curDic);
	OPENFILENAME openfn;
	WCHAR cFname[256];
	WCHAR szFilterOpn[]=TEXT("Config files (*.txt)\0*.txt\0All files (*.*)\0*.*\0\0");
	DWORD nFilterIndex=1;
	cFname[0]=0x00;
	ZeroMemory(&openfn, sizeof(openfn));
	openfn.hwndOwner=GetActiveWindow()->GetSafeHwnd();
	openfn.lpstrFile=cFname;
	openfn.nMaxFile=sizeof(cFname);
	openfn.lStructSize=sizeof(openfn);
	openfn.lpstrFilter=szFilterOpn; 
	openfn.nFilterIndex=nFilterIndex;
	//openfn.lpstrInitialDir=szCurDir;
	openfn.Flags= OFN_PATHMUSTEXIST | OFN_LONGNAMES | OFN_HIDEREADONLY;
	BOOL hr = GetOpenFileName(&openfn );
	SetCurrentDirectoryW(curDic);
	if (!hr)
	{
		return ;
	}
	m_edPath.SetWindowText(openfn.lpstrFile);
}

void ProjectSettingPropPage::OnBnClickedBtnLoad()
{
	CString path;
	m_edPath.GetWindowText(path);
	CComPtr<IMSPersist> pPersist = NULL;
	m_pFilter->QueryInterface(IID_IMSPersist, (void**)&pPersist);
	HRESULT ret = pPersist->LoadFromFile((WCHAR*)(LPCWSTR)path);
	if (FAILED(ret))
	{
		MessageBox(L"LoadFile Failed!!", L"Error!!");
		return;
	}
	theApp.WriteProfileString(L"MySetting",L"ProjectSettingPath", path);
}

void ProjectSettingPropPage::OnBnClickedBtnSave()
{
	CString path;
	m_edPath.GetWindowText(path);
	CComPtr<IMSPersist> pPersist = NULL;
	m_pFilter->QueryInterface(IID_IMSPersist, (void**)&pPersist);
	HRESULT ret = pPersist->SaveToFile((WCHAR*)(LPCWSTR)path);
	if (FAILED(ret))
	{
		MessageBox(L"LoadFile Failed!!", L"Error!!");
		return;
	}
	theApp.WriteProfileString(L"MySetting",L"ProjectSettingPath", path);

}
