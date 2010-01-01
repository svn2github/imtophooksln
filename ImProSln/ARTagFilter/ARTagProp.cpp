#include "winuser.h"
#include "stdafx.h"
#include "ARTagProp.h"
#include "resource.h"
#include "ARTagFilter.h"
#include <windowsx.h>

#define SLIDER_GetRangeMin(hWndTrack) SendMessage(hWndTrack, TBM_GETRANGEMIN,0,0)
#define SLIDER_GetRangeMax(hWndTrack) SendMessage(hWndTrack, TBM_GETRANGEMAX,0,0)
 
#define SLIDER_GetPos(hWndTrack)  SendMessage(hWndTrack, TBM_GETPOS, 0, 0)
#define SLIDER_SetPos(hWndTrack, pos)  SendMessage(hWndTrack, TBM_SETPOS, (WPARAM) TRUE,(LPARAM) pos)
#define SLIDER_SetRange(hWndTrack, iMin, iMax)  SendMessage(hWndTrack, TBM_SETRANGE, (WPARAM) TRUE, (LPARAM) MAKELONG(iMin, iMax))   



extern CARTagFilterApp theApp;
ARTagCameraSettingPage::ARTagCameraSettingPage(IUnknown *pUnk) : 
CBasePropertyPage(NAME("ARTagProp"), pUnk, IDD_ARTag_CAMSETTING_PAGE, IDS_ARTag_PROPPAGE_TITLE),
m_pARProperty(0)
{
	m_hWndXSize = 0;
	m_hWndYSize = 0;
}

ARTagCameraSettingPage::~ARTagCameraSettingPage()
{

}

HRESULT ARTagCameraSettingPage::OnConnect(IUnknown *pUnk)
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

HRESULT ARTagCameraSettingPage::OnDisconnect(void)
{
	if (m_pARProperty)
	{
		m_pARProperty->Release();
		m_pARProperty = NULL;
	}
	return S_OK;
}

CUnknown *WINAPI ARTagCameraSettingPage::CreateInstance(LPUNKNOWN punk, HRESULT *phr)
{
	ASSERT(phr);
	// assuming we don't want to modify the data
	ARTagCameraSettingPage *pNewObject = new ARTagCameraSettingPage(punk);

	if(pNewObject == NULL) {
		if (phr)
			*phr = E_OUTOFMEMORY;
	}

	return pNewObject;
}
void ARTagCameraSettingPage::SetDirty()
{
	m_bDirty = TRUE;
	HRESULT hr = S_OK;

	if (m_pPageSite) {
		hr = m_pPageSite->OnStatusChange(PROPPAGESTATUS_DIRTY);
	}

}
HRESULT ARTagCameraSettingPage::ApplyCameraSetting()
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
BOOL ARTagCameraSettingPage::OnReceiveMessage(HWND hwnd,
										 UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	WCHAR str[MAX_PATH] = {0};
	switch (uMsg) {
	case WM_COMMAND:
		{
			DWORD cmd = LOWORD(wParam);
			DWORD cmd2 = HIWORD(wParam);
			
			bool dirty = false;
			//swprintf_s(str, MAX_PATH, L"@@@@ cmd1 = %d, cmd2 = %d \n", cmd, cmd2);
			//OutputDebugStringW(str);
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

HRESULT ARTagCameraSettingPage::OnActivate(void)
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
HRESULT ARTagCameraSettingPage::OnApplyChanges(void)
{
    HRESULT hr = ApplyCameraSetting();

	if (FAILED(hr))
	{
		return E_FAIL;
	}
	return S_OK;
}





ARTagGeneralPage::ARTagGeneralPage(IUnknown *pUnk) : 
CBasePropertyPage(NAME("ARTag GeneralPage"), pUnk, IDD_ARTag_GeneralSettingPage, IDS_ARTag_GENERALPAGE),
m_pARProperty(0)
{
	m_cbPoseEstimator = 0;
	m_cbMarkerMode = 0;
	m_cbUnDistortMode = 0;
	m_ckDrawTag = 0;
	m_slrThreshold = 0;
	m_slrBorderW = 0;
	m_txtThreshold = 0;
	m_txtBorderW = 0;
}

ARTagGeneralPage::~ARTagGeneralPage()
{

}


HRESULT ARTagGeneralPage::OnConnect(IUnknown *pUnk)
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

HRESULT ARTagGeneralPage::OnDisconnect(void)
{
	if (m_pARProperty)
	{
		m_pARProperty->Release();
		m_pARProperty = NULL;
	}
	return S_OK;
}

CUnknown *WINAPI ARTagGeneralPage::CreateInstance(LPUNKNOWN punk, HRESULT *phr)
{
	ASSERT(phr);
	// assuming we don't want to modify the data
	ARTagGeneralPage *pNewObject = new ARTagGeneralPage(punk);

	if(pNewObject == NULL) {
		if (phr)
			*phr = E_OUTOFMEMORY;
	}

	return pNewObject;
}
bool ARTagGeneralPage::GetSetting()
{
	if (m_pARProperty == NULL)
	{
		return false;
	}
	bool bDrawTag = m_pARProperty->getbDrawTag();
	Button_SetCheck(m_ckDrawTag, bDrawTag);
	int poseEstimator = m_pARProperty->getPoseEstimator();
	ComboBox_SetCurSel(m_cbPoseEstimator, poseEstimator);
	int markermode = m_pARProperty->getMarkerMode();
	ComboBox_SetCurSel(m_cbMarkerMode, markermode);
	int undistortMode = m_pARProperty->getUndistortionMode();
	ComboBox_SetCurSel(m_cbUnDistortMode, undistortMode);
	int threshold = m_pARProperty->getThreshold();
	SLIDER_SetPos(m_slrThreshold, threshold);
	float borderW = m_pARProperty->getBorderWidth();
	int borderWValue = (int)(borderW*m_BorderWScale);
	SLIDER_SetPos(m_slrBorderW, borderWValue);
	WCHAR str[MAX_PATH] = {0};
	swprintf_s(str, MAX_PATH, L"%d", threshold);
	SetWindowText(m_txtThreshold, str);

	swprintf_s(str, MAX_PATH, L"%.3f", SLIDER_GetPos(m_slrBorderW)/(float)m_BorderWScale);
	SetWindowText(m_txtBorderW, str);
}
bool ARTagGeneralPage::ApplySetting()
{
	if (m_pARProperty == NULL)
	{
		return false;
	}
	bool bDrawTag = Button_GetCheck(m_ckDrawTag);
	m_pARProperty->setbDrawTag(bDrawTag);

	int poseEstimator = ComboBox_GetCurSel(m_cbPoseEstimator);
	m_pARProperty->setPoseEstimator(poseEstimator);
	
	int markermode = ComboBox_GetCurSel(m_cbMarkerMode);
	m_pARProperty->setMarkerMode(markermode);
	
	int undistortMode = ComboBox_GetCurSel(m_cbUnDistortMode);
	m_pARProperty->setUndistortionMode(undistortMode);

	int threshold = SLIDER_GetPos(m_slrThreshold);
	m_pARProperty->setThreshold(threshold);
	
	int borderWValue = SLIDER_GetPos(m_slrBorderW);
	float borderW = borderWValue / (float)m_BorderWScale;
	m_pARProperty->setBorderWidth(borderW);

	return true;
}
bool ARTagGeneralPage::updateSliderTxt()
{
	int threshold = SLIDER_GetPos(m_slrThreshold);

	int borderWValue = SLIDER_GetPos(m_slrBorderW);
	float borderW = borderWValue / (float)m_BorderWScale;

	WCHAR str[MAX_PATH] = {0};
	swprintf_s(str, MAX_PATH, L"%d", threshold);
	SetWindowText(m_txtThreshold, str);

	swprintf_s(str, MAX_PATH, L"%.3f", borderW);
	SetWindowText(m_txtBorderW, str);
	return true;
}

void ARTagGeneralPage::SetDirty()
{
	m_bDirty = TRUE;
	HRESULT hr = S_OK;

	if (m_pPageSite) {
		hr = m_pPageSite->OnStatusChange(PROPPAGESTATUS_DIRTY);
	}

}

BOOL ARTagGeneralPage::OnReceiveMessage(HWND hwnd,
											  UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	WCHAR str[MAX_PATH] = {0};
	int cmd = 0;
	swprintf_s(str, MAX_PATH, L"@@@@@ uMsg = %d \n", uMsg);
	OutputDebugString(str);
	switch (uMsg) {
	case WM_COMMAND:
		cmd = HIWORD(wParam);
		swprintf_s(str, MAX_PATH, L"@@@@@ cmd = %d \n", cmd);
		OutputDebugString(str);
		if (cmd == CBN_SELCHANGE || BM_SETCHECK) {
			SetDirty();
			
		}
		break;
	case WM_HSCROLL:
		updateSliderTxt();
		int threshold = SLIDER_GetPos(m_slrThreshold);
		m_pARProperty->setThreshold(threshold);

		int borderWValue = SLIDER_GetPos(m_slrBorderW);
		float borderW = borderWValue / (float)m_BorderWScale;
		m_pARProperty->setBorderWidth(borderW);
		break;
	}
	return __super::OnReceiveMessage(hwnd,uMsg,wParam,lParam);
}


HRESULT ARTagGeneralPage::OnActivate(void)
{
	if (m_pARProperty == NULL || m_pARProperty->IsReady() == false)
	{
		::EnableWindow(this->m_Dlg, FALSE);
		return S_OK;
	}
	::EnableWindow(this->m_Dlg, TRUE);

	if (m_pARProperty == NULL || m_pARProperty->IsReady() == false)
	{
		::EnableWindow(this->m_Dlg, FALSE);
		return S_OK;
	}
	::EnableWindow(this->m_Dlg, TRUE);
	m_ckDrawTag = GetDlgItem(m_Dlg, IDC_CHK_DRAWTAG);
	m_cbPoseEstimator = GetDlgItem(m_Dlg, IDC_COMBO_PoseEstimator);
	m_cbMarkerMode = GetDlgItem(m_Dlg, IDC_COMBO_MarkerMode);
	m_cbUnDistortMode = GetDlgItem(m_Dlg, IDC_COMBO_UndistortMode);
	m_slrBorderW = GetDlgItem(m_Dlg, IDC_SLIDER_BorderW);
	m_slrThreshold = GetDlgItem(m_Dlg, IDC_SLIDER_Threshold);
    m_txtBorderW = GetDlgItem(m_Dlg, IDC_txtBorderW);
	m_txtThreshold = GetDlgItem(m_Dlg, IDC_txtThreshold);
	ComboBox_AddString(m_cbPoseEstimator, L"Normal");
	ComboBox_AddString(m_cbPoseEstimator, L"Cont");
	ComboBox_AddString(m_cbPoseEstimator, L"RPP");
	//ComboBox_SetCurSel(m_cbPoseEstimator,2);
	
	ComboBox_AddString(m_cbMarkerMode, L"MARKER_TEMPLATE");
	ComboBox_AddString(m_cbMarkerMode, L"MARKER_ID_SIMPLE");
	ComboBox_AddString(m_cbMarkerMode, L"MARKER_ID_BCH");
	//ComboBox_SetCurSel(m_cbMarkerMode,1);

	ComboBox_AddString(m_cbUnDistortMode, L"UNDIST_NONE");
	ComboBox_AddString(m_cbUnDistortMode, L"UNDIST_STD");
	ComboBox_AddString(m_cbUnDistortMode, L"UNDIST_LUT");
	//ComboBox_SetCurSel(m_cbUnDistortMode,2);
	
	SLIDER_SetRange(m_slrThreshold, 0, 255);
	SLIDER_SetRange(m_slrBorderW, 0, m_BorderWScale);
	GetSetting();
	return NOERROR;
}
HRESULT ARTagGeneralPage::OnApplyChanges(void)
{
	if (ApplySetting())
	{
		return S_OK;
	}
	else
	{
		return S_FALSE;
	}
}
