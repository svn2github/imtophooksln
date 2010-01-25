#include "stdafx.h"
#include "HookDrawingProp.h"
#include "HookDrawingFilterApp.h"
#include "detours.h"
#include "..\HookInject\IHookInject.h"
extern CHookDrawingFilterApp theApp;
IMPLEMENT_DYNAMIC(HookDrawingPropPage, CMFCBasePropertyPage)


void HookDrawingPropPage::DoDataExchange(CDataExchange* pDX)
{
	CMFCBasePropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT3, m_edDetourPath);
	DDX_Control(pDX, IDC_BUTTON3, m_btnBrowse);
	DDX_Control(pDX, IDC_BUTTON4, m_btnCreateProc);

}
BOOL HookDrawingPropPage::OnInitDialog()
{
	BOOL ret = __super::OnInitDialog();
	CString createProcPath;
	createProcPath = theApp.GetProfileString(L"MySetting", L"CreateProcPath",L"");
	m_edDetourPath.SetWindowText(createProcPath);
	if (m_pFilter->IsHooked())
	{
		onWindowHooked();
	}
	return ret;
}

BEGIN_MESSAGE_MAP(HookDrawingPropPage, CMFCBasePropertyPage)
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_BUTTON3, &HookDrawingPropPage::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &HookDrawingPropPage::OnBnClickedButton4)

END_MESSAGE_MAP()


// CHomoWarpMFCPropertyPage message handlers


HookDrawingPropPage::HookDrawingPropPage(IUnknown *pUnk) : 
CMFCBasePropertyPage(NAME("HookDrawingPropPage"), pUnk),
m_pFilter(0)
{
	ZeroMemory(&m_si, sizeof(m_si));
	ZeroMemory(&m_pi, sizeof(m_pi));
	m_si.cb = sizeof(m_si);
}

HookDrawingPropPage::~HookDrawingPropPage()
{
	if (m_pFilter != NULL)
	{
		m_pFilter->Release();
		m_pFilter = NULL;
	}
}

//override CBasePropertyPage Method
HRESULT HookDrawingPropPage::OnConnect(IUnknown *pUnk)
{
	//override CBasePropertyPage Method
	if (pUnk == NULL)
	{
		return E_POINTER;
	}
	if (m_pFilter == NULL)
	{
		pUnk->QueryInterface(IID_IHookDrawingFilter, 
			reinterpret_cast<void**>(&m_pFilter));
		return S_OK;
	}
	return S_OK;
}
HRESULT HookDrawingPropPage::OnDisconnect(void)
{
	if (m_pFilter != NULL)
	{
		m_pFilter->Release();
		m_pFilter = NULL;
	}
	return S_OK;
}
BOOL HookDrawingPropPage::OnReceiveMessage(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return TRUE;
}
HRESULT HookDrawingPropPage::OnActivate(void)
{
	EnableWindow(TRUE);
	return S_OK;
}
HRESULT HookDrawingPropPage::OnApplyChanges(void)
{
	return S_OK;
}

CUnknown *WINAPI HookDrawingPropPage::CreateInstance(LPUNKNOWN punk, HRESULT *phr)
{
	ASSERT(phr);
	// assuming we don't want to modify the data
	HookDrawingPropPage *pNewObject = new HookDrawingPropPage(punk);

	if(pNewObject == NULL) {
		if (phr)
			*phr = E_OUTOFMEMORY;
	}

	return pNewObject;
}
int HookDrawingPropPage::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMFCBasePropertyPage::OnCreate(lpCreateStruct) == -1)
		return -1;
	return 0;
}

void HookDrawingPropPage::OnBnClickedButton3()
{
	WCHAR curDic[MAX_PATH] = {0};
	GetCurrentDirectoryW(MAX_PATH, curDic);
	OPENFILENAME openfn;
	WCHAR cFname[256];
	WCHAR szFilterOpn[]=TEXT("Executable files (*.exe)\0*.exe\0Dynamic Link Libraries (*.dll)\0*.dll\0OLE-ActiveX Controls (*.ocx)\0*.ocx\0Screen Savers (*.scr)\0*.scr\0All files (*.*)\0*.*\0\0");
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
	openfn.Flags=OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_LONGNAMES | OFN_HIDEREADONLY;
	BOOL hr = GetOpenFileName(&openfn );
	SetCurrentDirectoryW(curDic);
	if (!hr)
	{
		return ;
	}
	m_edDetourPath.SetWindowText(openfn.lpstrFile);
}

void HookDrawingPropPage::OnBnClickedButton4()
{
	CString path;

	WCHAR detourDllPath[MAX_PATH] = {0};
	HMODULE module = GetModule();
	GetModuleFileName(module, detourDllPath, MAX_PATH);
	// Gets filename
	WCHAR* pszFile = wcsrchr(detourDllPath, '\\');
	pszFile++;    // Moves on from \
	// Get path
	WCHAR szPath[MAX_PATH] = L"";
	_tcsncat(szPath, detourDllPath, pszFile - detourDllPath);

	swprintf_s(detourDllPath, MAX_PATH, L"%sdetoured.dll\0", szPath);

	WCHAR dllName[MAX_PATH] = {0};
	swprintf_s(dllName, MAX_PATH, L"%sHookInject.dll\0",szPath);





	m_edDetourPath.GetWindowText(path);
	char mbsDetourDLLPath[MAX_PATH] = {0};
	char mbsDllName[MAX_PATH] = {0};
	wcstombs_s(NULL, mbsDetourDLLPath, MAX_PATH*sizeof(char), detourDllPath, MAX_PATH*sizeof(WCHAR));
	wcstombs_s(NULL, mbsDllName, MAX_PATH*sizeof(char), dllName, MAX_PATH*sizeof(WCHAR));
	DWORD dwFlags = CREATE_DEFAULT_ERROR_MODE ;
	LPWSTR test = (LPWSTR)(LPCWSTR)path;
	BOOL hr = DetourCreateProcessWithDllW(NULL, (LPWSTR)(LPCWSTR)path,
		NULL, NULL, TRUE, dwFlags, NULL, NULL,
		&m_si, &m_pi, mbsDetourDLLPath, mbsDllName, NULL);
	Sleep(1000);
	if (hr )
	{
		theApp.WriteProfileString(L"MySetting",L"CreateProcPath",path);
		HWND cWnd;
		HOOKINJECT::GetHookClient(cWnd);
		m_pFilter->SetHookedWindow(cWnd);
		onWindowHooked();
	}
}

BOOL HookDrawingPropPage::onWindowHooked()
{
	m_btnCreateProc.EnableWindow(FALSE);
	m_btnBrowse.EnableWindow(FALSE);
	m_edDetourPath.EnableWindow(FALSE);
	return TRUE;
}
