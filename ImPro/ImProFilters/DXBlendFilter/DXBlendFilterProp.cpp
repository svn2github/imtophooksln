#include "stdafx.h"
#include "DXBlendFilterProp.h"
#include "DXBlendFilter.h"
#include "cv.h"
#include "highgui.h"
IMPLEMENT_DYNAMIC(DXBlendFilterProp, CMFCBasePropertyPage)


void DXBlendFilterProp::DoDataExchange(CDataExchange* pDX)
{
	CMFCBasePropertyPage::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_picWMap1, m_picWMap1);
	DDX_Control(pDX, IDC_edWMap1, m_edWMap1);
	DDX_Control(pDX, IDC_btnBrowse1, m_btnBrowse1);

	DDX_Control(pDX, IDC_edWMap2, m_edWMap2);
	DDX_Control(pDX, IDC_edWMap3, m_edWMap3);
	DDX_Control(pDX, IDC_edWMap4, m_edWMap4);
	DDX_Control(pDX, IDC_picWMap2, m_picWMap2);
	DDX_Control(pDX, IDC_picWMap3, m_picWMap3);
	DDX_Control(pDX, IDC_picWMap4, m_picWMap4);
}


BEGIN_MESSAGE_MAP(DXBlendFilterProp, CMFCBasePropertyPage)

	ON_BN_CLICKED(IDC_btnBrowse1, &DXBlendFilterProp::OnBnClickedbtnbrowse1)
	ON_BN_CLICKED(IDC_btnBrowse2, &DXBlendFilterProp::OnBnClickedbtnbrowse2)
	ON_BN_CLICKED(IDC_btnBrowse3, &DXBlendFilterProp::OnBnClickedbtnbrowse3)
	ON_BN_CLICKED(IDC_btnBrowse4, &DXBlendFilterProp::OnBnClickedbtnbrowse4)
	ON_BN_CLICKED(IDC_btnLoad1, &DXBlendFilterProp::OnBnClickedbtnload1)
	ON_BN_CLICKED(IDC_btnLoad2, &DXBlendFilterProp::OnBnClickedbtnload2)
	ON_BN_CLICKED(IDC_btnLoad3, &DXBlendFilterProp::OnBnClickedbtnload3)
	ON_BN_CLICKED(IDC_btnLoad4, &DXBlendFilterProp::OnBnClickedbtnload4)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CHomoWarpMFCPropertyPage message handlers


DXBlendFilterProp::DXBlendFilterProp(IUnknown *pUnk) : 
CMFCBasePropertyPage(NAME("DXBlendFilterProp"), pUnk),
m_pFilter(0)
{
	for (int i =0; i < NUMINPUT; i++)
	{
		m_bmpWMap[i] = 0;
	}
	
}

DXBlendFilterProp::~DXBlendFilterProp()
{
	if (m_pFilter != NULL)
	{
		m_pFilter->Release();
		m_pFilter = NULL;
	}
	cvDestroyAllWindows();
}

//override CBasePropertyPage Method
HRESULT DXBlendFilterProp::OnConnect(IUnknown *pUnk)
{
	if (pUnk == NULL)
	{
		return E_POINTER;
	}
	if (m_pFilter == NULL)
	{
		pUnk->QueryInterface(IID_IDXBlendFilter, 
			reinterpret_cast<void**>(&m_pFilter));
		return S_OK;
	}
	return S_OK;
}
HRESULT DXBlendFilterProp::OnDisconnect(void)
{
	return S_OK;
}
BOOL DXBlendFilterProp::OnReceiveMessage(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return TRUE;
}
HRESULT DXBlendFilterProp::OnActivate(void)
{
	if (m_pFilter != NULL)
	{
		this->EnableWindow(TRUE);
	}
	GetSetting();
	return S_OK;
}

bool DXBlendFilterProp::GetSetting()
{
	if (m_pFilter == NULL)
	{
		return false;
	}
	WCHAR str[MAX_PATH] = {0};
	CEdit* tmpArray[] = {&m_edWMap1 ,&m_edWMap2 ,&m_edWMap3, &m_edWMap4};
	for (int i =0; i < NUMINPUT; i++)
	{
		m_pFilter->GetWeightMapPath(i, str);
		tmpArray[i]->SetWindowText(str);
	}
	return true;
}

bool DXBlendFilterProp::ApplySetting()
{
	if (m_pFilter == NULL)
		return false;


	return true;
}
HRESULT DXBlendFilterProp::OnApplyChanges(void)
{
	return S_OK;
}

CUnknown *WINAPI DXBlendFilterProp::CreateInstance(LPUNKNOWN punk, HRESULT *phr)
{
	ASSERT(phr);
	// assuming we don't want to modify the data
	DXBlendFilterProp *pNewObject = new DXBlendFilterProp(punk);

	if(pNewObject == NULL) {
		if (phr)
			*phr = E_OUTOFMEMORY;
	}

	return pNewObject;
}


BOOL DXBlendFilterProp::OpenFileDialog(HWND hwndParent, WCHAR* pwcsFilter, WCHAR* pwcsDialogTitle, DWORD dwflag, WCHAR* pOutStr, BOOL saveDlg)
{
	if (pOutStr == NULL)
	{
		return FALSE;
	}
	WCHAR wszCur[_MAX_PATH] = {0};
	GetCurrentDirectoryW(_MAX_PATH, wszCur);
	//TODO: the buffer may be not large enough under multiple selection case.
	//		We'll have to hook the dialog to dynamically decide the buffer size.
	const int nBufSize = dwflag & OFN_ALLOWMULTISELECT ? 21000 : MAX_PATH;
	WCHAR* fnBuf = new WCHAR[nBufSize];
	fnBuf[0] = L'\0';
	OPENFILENAME ofn;
	ZeroMemory(&ofn, sizeof(OPENFILENAME)); 
	ofn.lStructSize       = sizeof(OPENFILENAME);
	ofn.hwndOwner         = hwndParent;         
	ofn.hInstance         = GetModuleHandle(NULL);  
	ofn.lpstrFilter       = pwcsFilter;
	ofn.lpstrCustomFilter = NULL;     
	ofn.nMaxCustFilter    = 0;
	ofn.nFilterIndex      = 0;
	ofn.lpstrFile         = fnBuf;     
	ofn.nMaxFile          = nBufSize;
	ofn.lpstrFileTitle    = NULL;          
	ofn.nMaxFileTitle     = 0;     
	ofn.lpstrInitialDir   = _T("");
	ofn.lpstrTitle        = pwcsDialogTitle;
	ofn.nFileOffset       = 0;            
	ofn.nFileExtension    = 0;
	ofn.lpstrDefExt       = _T(""); 
	ofn.lCustData         = 0;           
	ofn.lpfnHook          = NULL; //OFNHookFilter; 
	ofn.lpTemplateName    = NULL; 
	ofn.Flags             = OFN_EXPLORER | OFN_ENABLEHOOK | OFN_PATHMUSTEXIST | dwflag; // | OFN_ENABLEHOOK | OFN_ENABLEINCLUDENOTIFY;

	BOOL bRet = FALSE;

	if (saveDlg)
	{
		ofn.Flags |= OFN_OVERWRITEPROMPT;
		bRet = GetSaveFileName(&ofn);
	}
	else
		bRet = GetOpenFileName(&ofn);


	//restore the current directory changed by GetOpenFileName.
	SetCurrentDirectoryW(wszCur);
	if(!bRet)
	{
		DWORD dwErr = CommDlgExtendedError();
		delete[] fnBuf;
		fnBuf = NULL;
		//dwErr == 0 if user cancel
		if(dwErr == 0)
			return FALSE;
		else
			return FALSE;
	}
	else
	{

		wcscpy(pOutStr, fnBuf);
		delete[] fnBuf;
		fnBuf = NULL;
		return TRUE;		
	}

}

void DXBlendFilterProp::OnBnClickedbtnbrowse1()
{
	WCHAR path[MAX_PATH] = {0};
	WCHAR szFilterOpn[] = TEXT("image files \0*.jpg;*.png;*.bmp;*.tga\0All files (*.*)\0*.*\0\0");
	BOOL ret = OpenFileDialog(this->GetSafeHwnd(), szFilterOpn, L"Choose Weight Map File", 0, path, FALSE);
	if (ret)
	{
		m_edWMap1.SetWindowText(path);
	}
}

void DXBlendFilterProp::OnBnClickedbtnbrowse2()
{
	WCHAR path[MAX_PATH] = {0};
	WCHAR szFilterOpn[] = TEXT("image files \0*.jpg;*.png;*.bmp;*.tga\0All files (*.*)\0*.*\0\0");
	BOOL ret = OpenFileDialog(this->GetSafeHwnd(), szFilterOpn, L"Choose Weight Map File", 0, path, FALSE);
	if (ret)
	{
		m_edWMap2.SetWindowText(path);
	}
}

void DXBlendFilterProp::OnBnClickedbtnbrowse3()
{
	WCHAR path[MAX_PATH] = {0};
	WCHAR szFilterOpn[] = TEXT("image files \0*.jpg;*.png;*.bmp;*.tga\0All files (*.*)\0*.*\0\0");
	BOOL ret = OpenFileDialog(this->GetSafeHwnd(), szFilterOpn, L"Choose Weight Map File", 0, path, FALSE);
	if (ret)
	{
		m_edWMap3.SetWindowText(path);
	}
	
}

void DXBlendFilterProp::OnBnClickedbtnbrowse4()
{
	WCHAR path[MAX_PATH] = {0};
	WCHAR szFilterOpn[] = TEXT("image files \0*.jpg;*.png;*.bmp;*.tga\0All files (*.*)\0*.*\0\0");
	BOOL ret = OpenFileDialog(this->GetSafeHwnd(), szFilterOpn, L"Choose Weight Map File", 0, path, FALSE);
	if (ret)
	{
		m_edWMap4.SetWindowText(path);
	}
	
}

void DXBlendFilterProp::OnBnClickedbtnload1()
{
	if (m_pFilter == NULL)
		return ;
	CString path;
	m_edWMap1.GetWindowText(path);
	m_pFilter->LoadWeightMap(0, (WCHAR*)(LPCWSTR)path);
	UpdateWeightMap(0);
}

void DXBlendFilterProp::OnBnClickedbtnload2()
{
	if (m_pFilter == NULL)
		return ;
	CString path;
	m_edWMap2.GetWindowText(path);
	m_pFilter->LoadWeightMap(1, (WCHAR*)(LPCWSTR)path);
	UpdateWeightMap(1);
}

void DXBlendFilterProp::OnBnClickedbtnload3()
{
	if (m_pFilter == NULL)
		return ;
	CString path;
	m_edWMap3.GetWindowText(path);
	m_pFilter->LoadWeightMap(2, (WCHAR*)(LPCWSTR)path);
	UpdateWeightMap(2);
}

void DXBlendFilterProp::OnBnClickedbtnload4()
{
	if (m_pFilter == NULL)
		return ;
	CString path;
	m_edWMap4.GetWindowText(path);
	m_pFilter->LoadWeightMap(3, (WCHAR*)(LPCWSTR)path);
	UpdateWeightMap(3);
}


BOOL DXBlendFilterProp::UpdateWeightMap(int idx)
{
	if (idx <0 || idx > NUMINPUT)
	{
		return FALSE;
	}
	if (m_pFilter == NULL)
	{
		return TRUE;
	}
	RECT rect;
	CDC* pDC = NULL;
	switch (idx)
	{
	case 0:
		pDC = m_picWMap1.GetDC();
		m_picWMap1.GetClientRect(&rect);
		break;
	case 1:
		pDC = m_picWMap2.GetDC();
		m_picWMap2.GetClientRect(&rect);
		break;
	case 2:
		pDC = m_picWMap3.GetDC();
		m_picWMap3.GetClientRect(&rect);
		break;
	case 3:
		pDC = m_picWMap4.GetDC();
		m_picWMap4.GetClientRect(&rect);
		break;
	default:
		return FALSE;
	}
	IplImage* pImg = NULL;
	m_pFilter->GetCloneWeightMap(idx, pImg);
	if (pImg == NULL)
	{
		ReleaseDC(pDC);
		pDC = NULL;
		return FALSE;
	}
	int winW = rect.right - rect.left;
	int winH = rect.bottom - rect.top;

	for (int y =0; y < winH; y++ )
	{
		for (int x = 0; x < winW; x++ )
		{
			int imgX = x * pImg->width / (float)winW;
			int imgY = y * pImg->width / (float)winH;
			int r = pImg->imageData[imgY*pImg->widthStep + imgX*4];
			int g = pImg->imageData[imgY*pImg->widthStep + imgX*4+1];
			int b = pImg->imageData[imgY*pImg->widthStep + imgX*4+2];
			COLORREF color = RGB(r, g, b);
			pDC->SetPixel(x, y, color);
		}
	}
	if (pImg != NULL)
	{
		cvReleaseImage(&pImg);
		pImg = NULL;
	}
	if (pDC != NULL	)
	{
		ReleaseDC(pDC);
		pDC = NULL;
	}
	return TRUE;
}
void DXBlendFilterProp::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	for (int i =0; i< NUMINPUT; i++)
		UpdateWeightMap(i);
}
