#include "Stdafx.h"
#include "ARLayoutDXProp.h"
#include "MyTestFilter.h"
extern CMyTestFilterApp theApp;

IMPLEMENT_DYNAMIC(ARLayoutDXPropPage, CMFCBasePropertyPage)


void ARLayoutDXPropPage::DoDataExchange(CDataExchange* pDX)
{
	CMFCBasePropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDFilePath, m_edFilePath);
}


BEGIN_MESSAGE_MAP(ARLayoutDXPropPage, CMFCBasePropertyPage)
	ON_BN_CLICKED(IDC_BTNBrowse, &ARLayoutDXPropPage::OnBnClickedBtnbrowse)
	ON_BN_CLICKED(IDC_BTN_SAVE, &ARLayoutDXPropPage::OnBnClickedBtnSave)
	ON_BN_CLICKED(IDC_BTN_Load, &ARLayoutDXPropPage::OnBnClickedBtnLoad)
END_MESSAGE_MAP()


// CHomoWarpMFCPropertyPage message handlers


ARLayoutDXPropPage::ARLayoutDXPropPage(IUnknown *pUnk) : 
CMFCBasePropertyPage(NAME("ARLayoutDXPropPage"), pUnk),
m_pFilter(0)
{
}

ARLayoutDXPropPage::~ARLayoutDXPropPage()
{
	if (m_pFilter != NULL)
	{
		m_pFilter->Release();
		m_pFilter = NULL;
	}
}

//override CBasePropertyPage Method
HRESULT ARLayoutDXPropPage::OnConnect(IUnknown *pUnk)
{
	if (pUnk == NULL)
	{
		return E_POINTER;
	}
	if (m_pFilter == NULL)
	{
		pUnk->QueryInterface(IID_IARLayoutDXFilter, 
			reinterpret_cast<void**>(&m_pFilter));
		return S_OK;
	}
	return S_OK;
}
HRESULT ARLayoutDXPropPage::OnDisconnect(void)
{
	if (m_pFilter)
	{
		m_pFilter->Release();
		m_pFilter = NULL;
	}
	return S_OK;
}
BOOL ARLayoutDXPropPage::OnReceiveMessage(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{

	return TRUE;
}
HRESULT ARLayoutDXPropPage::OnActivate(void)
{
	if (m_pFilter == NULL)
	{
		::EnableWindow(this->GetSafeHwnd(), FALSE);
		return S_OK;
	}
	::EnableWindow(this->GetSafeHwnd(), TRUE);
	CString path;
	path = theApp.GetProfileString(L"MySetting",L"ARLayoutConfigPath", L"");
	m_edFilePath.SetWindowText(path);
	return S_OK;
}
HRESULT ARLayoutDXPropPage::OnApplyChanges(void)
{
	return S_OK;
}

CUnknown *WINAPI ARLayoutDXPropPage::CreateInstance(LPUNKNOWN punk, HRESULT *phr)
{
	ASSERT(phr);
	// assuming we don't want to modify the data
	ARLayoutDXPropPage *pNewObject = new ARLayoutDXPropPage(punk);

	if(pNewObject == NULL) {
		if (phr)
			*phr = E_OUTOFMEMORY;
	}

	return pNewObject;
}

void ARLayoutDXPropPage::OnBnClickedBtnbrowse()
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
	m_edFilePath.SetWindowText(openfn.lpstrFile);
}

void ARLayoutDXPropPage::OnBnClickedBtnSave()
{
	CString path;
	
	m_edFilePath.GetWindowText(path);
	bool ret = m_pFilter->SaveConfigToFile((WCHAR*)(LPCWSTR)path);
	if (!ret)
	{
		MessageBox(L"OpenFile Failed!!", L"Error!!");
		return;
	}
	theApp.WriteProfileString(L"MySetting",L"ARLayoutConfigPath",path);
	
	
}

void ARLayoutDXPropPage::OnBnClickedBtnLoad()
{
	CString path;
	m_edFilePath.GetWindowText(path);
	bool ret = m_pFilter->LoadConfigFromFile((WCHAR*)(LPCWSTR)path);
	if (!ret)
	{
		MessageBox(L"LoadFile Failed!!", L"Error!!");
		return;
	}
	theApp.WriteProfileString(L"MySetting",L"ARLayoutConfigPath",path);
}
