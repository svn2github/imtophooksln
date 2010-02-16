#include "Stdafx.h"
#include "ARLayoutDXProp.h"
#include "MyTestFilter.h"
extern CMyTestFilterApp theApp;

IMPLEMENT_DYNAMIC(ARLayoutDXPropPage, CMFCBasePropertyPage)


void ARLayoutDXPropPage::DoDataExchange(CDataExchange* pDX)
{
	CMFCBasePropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDFilePath, m_edFilePath);
	DDX_Control(pDX, IDC_EDLeft, m_edLeft);
	DDX_Control(pDX, IDC_EDRight, m_edRight);
	DDX_Control(pDX, IDC_EDTop, m_edTop);
	DDX_Control(pDX, IDC_EDBottom, m_edBottom);
	DDX_Control(pDX, IDC_COMBO1, m_cbARLevel);
}


BEGIN_MESSAGE_MAP(ARLayoutDXPropPage, CMFCBasePropertyPage)
	ON_BN_CLICKED(IDC_BTNBrowse, &ARLayoutDXPropPage::OnBnClickedBtnbrowse)
	ON_BN_CLICKED(IDC_BTN_SAVE, &ARLayoutDXPropPage::OnBnClickedBtnSave)
	ON_BN_CLICKED(IDC_BTN_Load, &ARLayoutDXPropPage::OnBnClickedBtnLoad)
	ON_BN_CLICKED(IDC_BTNTest, &ARLayoutDXPropPage::OnBnClickedBtntest)
	ON_CBN_SELCHANGE(IDC_COMBO1, &ARLayoutDXPropPage::OnCbnSelchangeCombo1)
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

	m_edLeft.SetWindowText(L"0.0");
	m_edRight.SetWindowText(L"1.0");
	m_edTop.SetWindowText(L"0.0");
	m_edBottom.SetWindowText(L"1.0");

	m_cbARLevel.AddString(L"3 Level(4x4 8x8 16x16)");
	m_cbARLevel.AddString(L"2 Level(8x8 16x16)");
	m_cbARLevel.SetCurSel(0);
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

void ARLayoutDXPropPage::OnBnClickedBtntest()
{
	if (m_pFilter == NULL)
		return;

	WCHAR str[MAX_PATH];
	
	double l = 0, t = 0, b = 0, r = 0;
	m_edLeft.GetWindowText(str, MAX_PATH);
	swscanf_s(str, L"%lf", &l);
	
	m_edRight.GetWindowText(str, MAX_PATH);
	swscanf_s(str, L"%lf", &r);

	m_edTop.GetWindowText(str, MAX_PATH);
	swscanf_s(str, L"%lf", &t);

	m_edBottom.GetWindowText(str, MAX_PATH);
	swscanf_s(str, L"%lf", &b);

	fRECT camView[1];
	camView[0].left = l;  camView[0].right = r;
	camView[0].bottom = b; camView[0].top = t;

	m_pFilter->DecideLayout(camView, 1, NULL, 0);

}


void ARLayoutDXPropPage::OnCbnSelchangeCombo1()
{
	if (m_pFilter == NULL)
		return;
	int curSel = m_cbARLevel.GetCurSel();
	if (curSel == 0	)
	{
		m_pFilter->initARMarkers(2, 8, 2, 80);
	}
	else if (curSel == 1)
	{
		m_pFilter->initARMarkers(3, 8, 2, 40);
	}
}
