#include "winuser.h"
#include "stdafx.h"
#include "ARTagProp.h"
#include "resource.h"
#include "ARTagFilter.h"
extern CARTagFilterApp theApp;
ARTagPropertyPage::ARTagPropertyPage(IUnknown *pUnk) : 
CBasePropertyPage(NAME("ARTagProp"), pUnk, IDD_ARTag_PROPPAGE, IDS_ARTag_PROPPAGE_TITLE),
m_pARProperty(0)
{
	m_hWndXSize = 0;
	m_hWndYSize = 0;
	
}

ARTagPropertyPage::~ARTagPropertyPage()
{

}

HRESULT ARTagPropertyPage::OnConnect(IUnknown *pUnk)
{
	if (pUnk == NULL)
	{
		return E_POINTER;
	}
	if (m_pARProperty == NULL)
	{
		pUnk->QueryInterface(IID_IARTagDSFilter, 
		reinterpret_cast<void**>(&m_pARProperty));
		return S_OK;
	}
	return S_OK;
}

HRESULT ARTagPropertyPage::OnDisconnect(void)
{
	if (m_pARProperty)
	{
		m_pARProperty->Release();
		m_pARProperty = NULL;
	}
	return S_OK;
}

CUnknown *WINAPI ARTagPropertyPage::CreateInstance(LPUNKNOWN punk, HRESULT *phr)
{
	ASSERT(phr);
	// assuming we don't want to modify the data
	ARTagPropertyPage *pNewObject = new ARTagPropertyPage(punk);

	if(pNewObject == NULL) {
		if (phr)
			*phr = E_OUTOFMEMORY;
	}

	return pNewObject;
}
void ARTagPropertyPage::SetDirty()
{
	m_bDirty = TRUE;
	HRESULT hr = S_OK;

	if (m_pPageSite) {
		hr = m_pPageSite->OnStatusChange(PROPPAGESTATUS_DIRTY);
		int test = 0;
	}

}
HRESULT ARTagPropertyPage::ApplyCameraSetting()
{
	if (m_pARProperty == NULL )
	{
		return E_FAIL;
	}

	int xsize, ysize;
	double mat[16] = {0};
	double dist_factor[4] = {0};
	WCHAR tmpStr[MAX_PATH];
	try
	{

		GetWindowText(m_hWndXSize, tmpStr, MAX_PATH);
		swscanf_s(tmpStr, L"%d", &xsize);

		GetWindowText(m_hWndYSize, tmpStr, MAX_PATH);
		swscanf_s(tmpStr, L"%d", &ysize);

		for (int i =0; i< 4; i++)
		{
			GetWindowText(m_hWndDistFactor[i], tmpStr, MAX_PATH);
			swscanf_s(tmpStr, L"%lf", &(dist_factor[i]));

		}
		for (int i =0; i< 16; i++)
		{
			GetWindowText(m_hWndMat[i], tmpStr, MAX_PATH);
			swscanf_s(tmpStr, L"%lf", &(mat[i]));
		}

	}
	catch (CException* e)
	{
		ASSERT("Wrong Input Format!!");
		return E_FAIL;
	}
	m_pARProperty->setCamera(xsize, ysize, mat, dist_factor, 1.0, 1000.0);

	swprintf_s(tmpStr, L"%.5f %.5f %.5f %.5f", dist_factor[0], dist_factor[1], dist_factor[2], dist_factor[3]);
	theApp.WriteProfileString(L"Camera Setting", L"dist_Factor", tmpStr);
	swprintf_s(tmpStr, L"%.5f %.5f %.5f %.5f \
						%.5f %.5f %.5f %.5f \
						%.5f %.5f %.5f %.5f \
						%.5f %.5f %.5f %.5f ",
						mat[0], mat[1],  mat[2],  mat[3],
						mat[4], mat[5],  mat[6],  mat[7],
						mat[8], mat[9],  mat[10], mat[11],
						mat[12], mat[13], mat[14],  mat[15]);
	theApp.WriteProfileString(L"Camera Setting", L"mat", tmpStr);
}
BOOL ARTagPropertyPage::OnReceiveMessage(HWND hwnd,
										 UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	WCHAR str[MAX_PATH] = {0};
	switch (uMsg) {
	case WM_COMMAND:
		{
			DWORD cmd = LOWORD(wParam);
			DWORD cmd2 = HIWORD(wParam);
			
			bool dirty = false;
			swprintf_s(str, MAX_PATH, L"@@@@ cmd1 = %d, cmd2 = %d \n", cmd, cmd2);
			OutputDebugStringW(str);
			if ((cmd2 == EN_CHANGE) && (cmd == IDC_DISTFACTOR1 || cmd == IDC_DISTFACTOR2 || cmd == IDC_DISTFACTOR3 || cmd == IDC_DISTFACTOR4 ||
				cmd == IDC_XSIZE || cmd == IDC_YSIZE || 
				cmd == IDC_Mat00 || cmd == IDC_Mat01 || cmd == IDC_Mat02 || cmd == IDC_Mat03 || 
				cmd == IDC_Mat10 || cmd == IDC_Mat11 || cmd == IDC_Mat12 || cmd == IDC_Mat13 || 
				cmd == IDC_Mat20 || cmd == IDC_Mat21 || cmd == IDC_Mat22 || cmd == IDC_Mat23 || 
				cmd == IDC_Mat30 || cmd == IDC_Mat31 || cmd == IDC_Mat32 || cmd == IDC_Mat33 )) 
			{
				SetDirty();
				return 1;
			}	
		}
		break;
	}
	return __super::OnReceiveMessage(hwnd,uMsg,wParam,lParam);
}

HRESULT ARTagPropertyPage::OnActivate(void)
{
	if (m_pARProperty == NULL || m_pARProperty->IsReady() == false)
	{
		::EnableWindow(this->m_Dlg, FALSE);
		return S_OK;
	}
	::EnableWindow(this->m_Dlg, TRUE);
	m_hWndXSize = GetDlgItem(m_Dlg, IDC_XSIZE);
	m_hWndYSize = GetDlgItem(m_Dlg, IDC_YSIZE);
	
	m_hWndDistFactor[0] = GetDlgItem(m_Dlg, IDC_DISTFACTOR1);
	m_hWndDistFactor[1] = GetDlgItem(m_Dlg, IDC_DISTFACTOR2);
	m_hWndDistFactor[2] = GetDlgItem(m_Dlg, IDC_DISTFACTOR3);
	m_hWndDistFactor[3] = GetDlgItem(m_Dlg, IDC_DISTFACTOR4);

	m_hWndMat[0] = GetDlgItem(m_Dlg, IDC_Mat00);
	m_hWndMat[1] = GetDlgItem(m_Dlg, IDC_Mat01);
	m_hWndMat[2] = GetDlgItem(m_Dlg, IDC_Mat02);
	m_hWndMat[3] = GetDlgItem(m_Dlg, IDC_Mat03);

	m_hWndMat[4] = GetDlgItem(m_Dlg, IDC_Mat10);
	m_hWndMat[5] = GetDlgItem(m_Dlg, IDC_Mat11);
	m_hWndMat[6] = GetDlgItem(m_Dlg, IDC_Mat12);
	m_hWndMat[7] = GetDlgItem(m_Dlg, IDC_Mat13);

	m_hWndMat[8] = GetDlgItem(m_Dlg, IDC_Mat20);
	m_hWndMat[9] = GetDlgItem(m_Dlg, IDC_Mat21);
	m_hWndMat[10] = GetDlgItem(m_Dlg, IDC_Mat22);
	m_hWndMat[11] = GetDlgItem(m_Dlg, IDC_Mat23);

	m_hWndMat[12] = GetDlgItem(m_Dlg, IDC_Mat30);
	m_hWndMat[13] = GetDlgItem(m_Dlg, IDC_Mat31);
	m_hWndMat[14] = GetDlgItem(m_Dlg, IDC_Mat32);
	m_hWndMat[15] = GetDlgItem(m_Dlg, IDC_Mat33);
	int xsize, ysize;
	double mat[16] = {0};
	double dist_factor[4] = {0};
	m_pARProperty->getCamera(xsize, ysize, mat, dist_factor);
	WCHAR tmpStr[MAX_PATH];
	swprintf_s(tmpStr, MAX_PATH, L"%d", xsize);
	SetWindowText(m_hWndXSize, tmpStr);
	swprintf_s(tmpStr, MAX_PATH, L"%d", ysize);
	SetWindowText(m_hWndYSize, tmpStr);
	for (int i =0; i< 4; i++)
	{
		swprintf_s(tmpStr, MAX_PATH, L"%.2f", dist_factor[i]);
		SetWindowText(m_hWndDistFactor[i], tmpStr);
	}
	for (int i =0; i< 16; i++)
	{
		swprintf_s(tmpStr, MAX_PATH, L"%.2f", mat[i]);
		SetWindowText(m_hWndMat[i], tmpStr);
	}


	return NOERROR;
}
HRESULT ARTagPropertyPage::OnApplyChanges(void)
{
    HRESULT hr = ApplyCameraSetting();

	if (FAILED(hr))
	{
		return E_FAIL;
	}
	return S_OK;
}

