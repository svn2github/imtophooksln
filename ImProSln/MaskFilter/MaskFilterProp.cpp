#include "stdafx.h"
#include "MaskFilterProp.h"
#include "MaskFilterApp.h"


IMPLEMENT_DYNAMIC(MaskFilterPropPage, CMFCBasePropertyPage)

extern CMaskFilterApp theApp;



void MaskFilterPropPage::DoDataExchange(CDataExchange* pDX)
{
	CMFCBasePropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_raBlockAll, m_raBlockAll);
	DDX_Control(pDX, IDC_raPassAll, m_raPassAll);
	DDX_Control(pDX, IDC_raBlend, m_raBlend);
	DDX_Control(pDX, IDC_EDIT1, m_edPath);
	DDX_Control(pDX, IDC_btnBrowse, m_btnBrowse);
	DDX_Control(pDX, IDC_btnLoadMask, m_btnLoad);
}
BOOL MaskFilterPropPage::OnInitDialog()
{
	BOOL ret = __super::OnInitDialog();

	return ret;
}

BEGIN_MESSAGE_MAP(MaskFilterPropPage, CMFCBasePropertyPage)
	ON_WM_CREATE()

	ON_BN_CLICKED(IDC_raBlockAll, &MaskFilterPropPage::OnBnClickedrablockall)
	ON_BN_CLICKED(IDC_raPassAll, &MaskFilterPropPage::OnBnClickedrapassall)
	ON_BN_CLICKED(IDC_raBlend, &MaskFilterPropPage::OnBnClickedrablend)
	ON_BN_CLICKED(IDC_btnBrowse, &MaskFilterPropPage::OnBnClickedbtnbrowse)
	ON_BN_CLICKED(IDC_btnLoadMask, &MaskFilterPropPage::OnBnClickedbtnloadmask)
END_MESSAGE_MAP()


// CHomoWarpMFCPropertyPage message handlers


MaskFilterPropPage::MaskFilterPropPage(IUnknown *pUnk) : 
CMFCBasePropertyPage(NAME("MaskFilterPropPage"), pUnk),
m_pFilter(0)
{
}

MaskFilterPropPage::~MaskFilterPropPage()
{
	if (m_pFilter != NULL)
	{
		m_pFilter->Release();
		m_pFilter = NULL;
	}
}

//override CBasePropertyPage Method
HRESULT MaskFilterPropPage::OnConnect(IUnknown *pUnk)
{
	//override CBasePropertyPage Method
	if (pUnk == NULL)
	{
		return E_POINTER;
	}
	if (m_pFilter == NULL)
	{
		pUnk->QueryInterface(IID_IMaskFilter, 
			reinterpret_cast<void**>(&m_pFilter));
		return S_OK;
	}
	return S_OK;
}
HRESULT MaskFilterPropPage::OnDisconnect(void)
{
	if (m_pFilter != NULL)
	{
		m_pFilter->Release();
		m_pFilter = NULL;
	}
	return S_OK;
}
BOOL MaskFilterPropPage::OnReceiveMessage(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return TRUE;
}
HRESULT MaskFilterPropPage::OnActivate(void)
{
	if (m_pFilter != NULL)
		EnableWindow(TRUE);
	else
		EnableWindow(FALSE);

	CString path;
	path = theApp.GetProfileString(L"MySetting",L"LoadMaskPath", L"");
	m_edPath.SetWindowText(path);
	GetSetting();
	return S_OK;
}
HRESULT MaskFilterPropPage::OnApplyChanges(void)
{
	return S_OK;
}

CUnknown *WINAPI MaskFilterPropPage::CreateInstance(LPUNKNOWN punk, HRESULT *phr)
{
	ASSERT(phr);
	// assuming we don't want to modify the data
	MaskFilterPropPage *pNewObject = new MaskFilterPropPage(punk);

	if(pNewObject == NULL) {
		if (phr)
			*phr = E_OUTOFMEMORY;
	}

	return pNewObject;
}
void MaskFilterPropPage::OnBnClickedrablockall()
{
	if (m_pFilter == NULL)
		return;
	m_raBlockAll.SetCheck(TRUE);
	m_raPassAll.SetCheck(FALSE);
	m_raBlend.SetCheck(FALSE);
	m_pFilter->SetMaskFlag(0);
}

void MaskFilterPropPage::OnBnClickedrapassall()
{
	if (m_pFilter == NULL)
		return;
	m_raBlockAll.SetCheck(FALSE);
	m_raPassAll.SetCheck(TRUE);
	m_raBlend.SetCheck(FALSE);
	m_pFilter->SetMaskFlag(1);
}

void MaskFilterPropPage::OnBnClickedrablend()
{
	if (m_pFilter == NULL)
		return;
	m_raBlockAll.SetCheck(FALSE);
	m_raPassAll.SetCheck(FALSE);
	m_raBlend.SetCheck(TRUE);
	m_pFilter->SetMaskFlag(2);
}

void MaskFilterPropPage::OnBnClickedbtnbrowse()
{
	WCHAR curDic[MAX_PATH] = {0};
	GetCurrentDirectoryW(MAX_PATH, curDic);
	OPENFILENAME openfn;
	WCHAR cFname[256];
	WCHAR szFilterOpn[]=TEXT("image files \0*.jpg;*.png;*.bmp;*.tga\0All files (*.*)\0*.*\0\0");
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

void MaskFilterPropPage::OnBnClickedbtnloadmask()
{
	CString path;
	m_edPath.GetWindowText(path);
	bool ret = m_pFilter->LoadMaskFromFile((WCHAR*)(LPCWSTR)path);
	if (!ret)
	{
		MessageBox(L"LoadFile Failed!!", L"Error!!");
		return;
	}
	theApp.WriteProfileString(L"MySetting",L"LoadMaskPath",path);
}

bool MaskFilterPropPage::GetSetting()
{
	if (m_pFilter == NULL)
		return false;
	int flag = m_pFilter->GetMaskFlag();
	m_raBlockAll.SetCheck(FALSE);
	m_raPassAll.SetCheck(FALSE);
	m_raBlend.SetCheck(FALSE);
	if (flag == 0)
	{
		m_raBlockAll.SetCheck(TRUE);
	}
	else if (flag == 1)
	{
		m_raPassAll.SetCheck(TRUE);
	}
	else if (flag == 2)
	{
		m_raBlend.SetCheck(TRUE);
	}
	return true;
}
bool MaskFilterPropPage::ApplySetting()
{
	return true;
}