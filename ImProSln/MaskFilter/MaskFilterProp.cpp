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
	DDX_Control(pDX, IDC_EDIT2, m_edARLayoutPath);
	DDX_Control(pDX, IDC_btnBrowse2, m_btnARLayoutBrowse);
	DDX_Control(pDX, IDC_btnLoadMask2, m_btnARLayoutLoad);
	DDX_Control(pDX, IDC_ckMaskFlipY, m_ckMaskFlipY);
	DDX_Control(pDX, IDC_EDIT3, m_edWarpPath);
	DDX_Control(pDX, IDC_btnBrowse3, m_btnWarpBrowse);
	DDX_Control(pDX, IDC_btnLoadMask3, m_btnWarpLoad);
	DDX_Control(pDX, IDC_EDIT4, m_edMaskScale);
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
	ON_BN_CLICKED(IDC_btnBrowse2, &MaskFilterPropPage::OnBnClickedbtnbrowse2)
	ON_BN_CLICKED(IDC_btnLoadMask2, &MaskFilterPropPage::OnBnClickedbtnloadmask2)
	ON_BN_CLICKED(IDC_ckMaskFlipY, &MaskFilterPropPage::OnBnClickedckmaskflipy)
	ON_BN_CLICKED(IDC_btnBrowse3, &MaskFilterPropPage::OnBnClickedbtnbrowse3)
	ON_BN_CLICKED(IDC_btnLoadMask3, &MaskFilterPropPage::OnBnClickedbtnloadmask3)
	ON_BN_CLICKED(IDC_btnTest, &MaskFilterPropPage::OnBnClickedbtntest)
	ON_EN_KILLFOCUS(IDC_EDIT4, &MaskFilterPropPage::OnEnKillfocusEdit4)
	ON_BN_CLICKED(IDC_btnClearMAsk, &MaskFilterPropPage::OnBnClickedbtnclearmask)
END_MESSAGE_MAP()


// CHomoWarpMFCPropertyPage message handlers


MaskFilterPropPage::MaskFilterPropPage(IUnknown *pUnk) : 
CMFCBasePropertyPage(NAME("MaskFilterPropPage"), pUnk),
m_pFilter(0)
, m_fMaskScale(1.0)
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
	path = theApp.GetProfileString(L"MySetting",L"LoadMaskFromARLayoutPath",L"");
	m_edARLayoutPath.SetWindowText(path);
	path = theApp.GetProfileString(L"MySetting",L"LoadMaskFromWarpPath", L"");
	m_edWarpPath.SetWindowText(path);
	WCHAR str[MAX_PATH];
	swprintf_s(str, MAX_PATH, L"%.2f", m_fMaskScale);
	m_edMaskScale.SetWindowText(str);

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
void MaskFilterPropPage::OnBnClickedbtnbrowse2()
{
	WCHAR curDic[MAX_PATH] = {0};
	GetCurrentDirectoryW(MAX_PATH, curDic);
	OPENFILENAME openfn;
	WCHAR cFname[256];
	WCHAR szFilterOpn[]=TEXT("ARLayout files \0*.txt\0All files (*.*)\0*.*\0\0");
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
	m_edARLayoutPath.SetWindowText(openfn.lpstrFile);
}

void MaskFilterPropPage::OnBnClickedbtnloadmask2()
{
	CString path;
	m_edARLayoutPath.GetWindowText(path);
	bool ret = m_pFilter->GenerateMaskFromARLayoutFile((WCHAR*)(LPCWSTR)path,  m_fMaskScale);
	if (!ret)
	{
		MessageBox(L"LoadFile Failed!!", L"Error!!");
		return;
	}
	theApp.WriteProfileString(L"MySetting",L"LoadMaskFromARLayoutPath",path);
}

void MaskFilterPropPage::OnBnClickedckmaskflipy()
{
	if (m_pFilter == NULL)
		return ;
	m_pFilter->SetMaskFlipY(m_ckMaskFlipY.GetCheck());
}

void MaskFilterPropPage::OnBnClickedbtnbrowse3()
{
	WCHAR curDic[MAX_PATH] = {0};
	GetCurrentDirectoryW(MAX_PATH, curDic);
	OPENFILENAME openfn;
	WCHAR cFname[256];
	WCHAR szFilterOpn[]=TEXT("Warp Config \0*.txt\0All files (*.*)\0*.*\0\0");
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
	m_edWarpPath.SetWindowText(openfn.lpstrFile);
}

void MaskFilterPropPage::OnBnClickedbtnloadmask3()
{
	CString path;
	m_edWarpPath.GetWindowText(path);
	bool ret = m_pFilter->GenerateMaskFromWarpConfigFile((WCHAR*)(LPCWSTR)path);
	if (!ret)
	{
		MessageBox(L"LoadFile Failed!!", L"Error!!");
		return;
	}
	theApp.WriteProfileString(L"MySetting",L"LoadMaskFromWarpPath", path);
}

void MaskFilterPropPage::OnBnClickedbtntest()
{
	D3DXVECTOR2 pts[3][4];
	pts[0][0] = D3DXVECTOR2(0.125, 0.125); pts[0][1] = D3DXVECTOR2(0.125, 0.25); 
	pts[0][2] = D3DXVECTOR2(0.25, 0.25); pts[0][3] = D3DXVECTOR2(0.25, 0.125);

	pts[1][0] = D3DXVECTOR2(0.625, 0.625); pts[1][1] = D3DXVECTOR2(0.625, 0.75); 
	pts[1][2] = D3DXVECTOR2(0.75, 0.75); pts[1][3] = D3DXVECTOR2(0.75, 0.625);

	pts[2][0] = D3DXVECTOR2(0.125, 0.625); pts[2][1] = D3DXVECTOR2(0.125, 0.75); 
	pts[2][2] = D3DXVECTOR2(0.25, 0.75); pts[2][3] = D3DXVECTOR2(0.25, 0.625);


	m_pFilter->GenerateMaskFromVertices(pts, 3, m_fMaskScale); 
}

void MaskFilterPropPage::OnEnKillfocusEdit4()
{
	CString str;
	m_edMaskScale.GetWindowText(str);
	WCHAR wstr[MAX_PATH];
	wcscpy(wstr, str);
	double fMaskScale = 1.0;
	swscanf_s(wstr, L"%lf", &fMaskScale);
	m_fMaskScale = fMaskScale;
}

void MaskFilterPropPage::OnBnClickedbtnclearmask()
{
	if (m_pFilter == NULL)
		return;
	m_pFilter->ClearMask();
}
