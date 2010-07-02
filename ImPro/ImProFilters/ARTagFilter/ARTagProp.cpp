#include "winuser.h"
#include "stdafx.h"
#include "ARTagProp.h"
#include "resource.h"
#include "ARTagFilter.h"
#include <windowsx.h>

extern CARTagFilterApp theApp;
ARTagCameraSettingPage::ARTagCameraSettingPage(IUnknown *pUnk) : 
CBasePropertyPage(NAME("ARTagProp"), pUnk, IDD_ARTag_CAMSETTING_PAGE, IDS_ARTag_PROPPAGE_TITLE),
m_pARProperty(0)
{
	m_hWndXSize = 0;
	m_hWndYSize = 0;
	m_hWndLoad = 0;
	m_edXaxis = 0;
	m_edYaxis = 0;
	m_edZaxis = 0;
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
bool ARTagCameraSettingPage::GetSetting()
{
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
		swprintf_s(tmpStr, MAX_PATH, L"%.6f", dist_factor[i]);
		SetWindowText(m_hWndDistFactor[i], tmpStr);
	}
	for (int i =0; i< 16; i++)
	{
		swprintf_s(tmpStr, MAX_PATH, L"%.6f", mat[i]);
		SetWindowText(m_hWndMat[i], tmpStr);
	}
	double v[3];
	m_pARProperty->getWorldBasisScale(v);
	swprintf_s(tmpStr, MAX_PATH, L"%.6f", v[0]);
	SetWindowText(m_edXaxis, tmpStr);
	swprintf_s(tmpStr, MAX_PATH, L"%.6f", v[1]);
	SetWindowText(m_edYaxis, tmpStr);
	swprintf_s(tmpStr, MAX_PATH, L"%.6f", v[2]);
	SetWindowText(m_edZaxis, tmpStr);


	return true;
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
	double basisscale[3] = {0};
	WCHAR tmpStr[MAX_PATH];
	try
	{
		GetWindowText(m_edXaxis, tmpStr, MAX_PATH);
		if (wcscmp(tmpStr, L"") == 0)
		{
			return S_FALSE;
		}
		swscanf_s(tmpStr, L"%lf", &(basisscale[0]));

		GetWindowText(m_edYaxis, tmpStr, MAX_PATH);
		swscanf_s(tmpStr, L"%lf", &(basisscale[1]));

		GetWindowText(m_edZaxis, tmpStr, MAX_PATH);
		swscanf_s(tmpStr, L"%lf", &(basisscale[2]));


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
	m_pARProperty->setWorldBasisScale(basisscale);
	WriteProfileSetting();
	return S_OK;
}

bool ARTagCameraSettingPage::WriteProfileSetting()
{
	int xsize, ysize;
	double mat[16] = {0};
	double dist_factor[4] = {0};
	m_pARProperty->getCamera(xsize, ysize, mat, dist_factor);
	
	WCHAR tmpStr[MAX_PATH];
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
	return true;
}
BOOL ARTagCameraSettingPage::OpenFileDialog(HWND hwndParent, WCHAR* pwcsFilter, WCHAR* pwcsDialogTitle, DWORD dwflag, WCHAR* pOutStr, BOOL saveDlg = FALSE)
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

			if ((cmd2 == EN_CHANGE) && (cmd == IDC_DISTFACTOR1 || cmd == IDC_DISTFACTOR2 || cmd == IDC_DISTFACTOR3 || cmd == IDC_DISTFACTOR4 ||
				cmd == IDC_XSIZE || cmd == IDC_YSIZE || 
				cmd == IDC_Mat00 || cmd == IDC_Mat01 || cmd == IDC_Mat02 || cmd == IDC_Mat03 || 
				cmd == IDC_Mat10 || cmd == IDC_Mat11 || cmd == IDC_Mat12 || cmd == IDC_Mat13 || 
				cmd == IDC_Mat20 || cmd == IDC_Mat21 || cmd == IDC_Mat22 || cmd == IDC_Mat23 || 
				cmd == IDC_Mat30 || cmd == IDC_Mat31 || cmd == IDC_Mat32 || cmd == IDC_Mat33 ||
				cmd == IDC_edXaxis || cmd == IDC_edYaxis || cmd == IDC_edZaxis )) 
			{
				SetDirty();
				return 1;
			}	
			if (cmd2 == BN_CLICKED && cmd == IDC_BTN_Load)
			{
				WCHAR pFileName[MAX_PATH] = {0};
				OpenFileDialog(m_Dlg, L"*.xml", L"Choose CameraINI File", 0, pFileName);
				if (pFileName != NULL)
				{
					m_pARProperty->loadCameraFromXMLFile(pFileName);
					WriteProfileSetting();
					GetSetting();
				}
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

	m_hWndLoad = GetDlgItem(m_Dlg, IDC_BTN_Load);

	m_edXaxis = GetDlgItem(m_Dlg, IDC_edXaxis);
	m_edYaxis = GetDlgItem(m_Dlg, IDC_edYaxis);
	m_edZaxis = GetDlgItem(m_Dlg, IDC_edZaxis);

	GetSetting();

	return NOERROR;
}
HRESULT ARTagCameraSettingPage::OnApplyChanges(void)
{
	if (m_hwnd == NULL)
		return S_FALSE;
    HRESULT hr = ApplyCameraSetting();

	if (FAILED(hr))
	{
		return E_FAIL;
	}
	return S_OK;
}




IMPLEMENT_DYNAMIC(ARTagGeneralPage, GSMFCProp)

BEGIN_MESSAGE_MAP(ARTagGeneralPage, GSMFCProp)
	
	ON_BN_CLICKED(IDC_BTNCONNECT, &ARTagGeneralPage::OnBnClickedBtnconnect)
END_MESSAGE_MAP()


ARTagGeneralPage::ARTagGeneralPage(IUnknown *pUnk) : 
GSMFCProp(NAME("ARTagGeneralPage"), pUnk),
m_pARProperty(0)
{
	m_cbPoseEstimator = 0;
	m_cbMarkerMode = 0;
	m_cbUnDistortMode = 0;
	m_ckDrawTag = 0;
	m_ckDrawReProj = 0;
	m_ckGuessPose = 0;
	m_ckAutoThreshold = 0;
	m_ckUseKalman = 0;
	m_slrThreshold = 0;
	m_slrBorderW = 0;
	m_txtThreshold = 0;
	m_txtBorderW = 0;
	m_txtMeasureNoise = 0;
	m_slrMeasureNoise = 0;
	m_ckMaskTag = 0;
}
BOOL ARTagGeneralPage::OnInitDialog()
{
	BOOL ret = __super::OnInitDialog();

	return ret;
}
void ARTagGeneralPage::DoDataExchange(CDataExchange* pDX)
{
	GSMFCProp::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_edIP, m_edIP);
	DDX_Control(pDX, IDC_edPort, m_edPort);
	DDX_Control(pDX, IDC_BTNCONNECT, m_btnConnect);
}
ARTagGeneralPage::~ARTagGeneralPage()
{
	if (m_pARProperty != NULL)
	{
		m_pARProperty->Release();
		m_pARProperty = NULL;
	}
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
	bool bDrawReproj = m_pARProperty->getbDrawReproPt();
	Button_SetCheck(m_ckDrawReProj, bDrawReproj);
	bool bDrawTag = m_pARProperty->getbDrawTag();
	Button_SetCheck(m_ckDrawTag, bDrawTag);
	bool bGuessPose = m_pARProperty->getbGuessPose();
	Button_SetCheck(m_ckGuessPose, bGuessPose);
	bool bAutoThreshold = m_pARProperty->getAutoThreshold();
	Button_SetCheck(m_ckAutoThreshold, bAutoThreshold);
	bool bUseKalman = m_pARProperty->getbUseKalman();
	Button_SetCheck(m_ckUseKalman, bUseKalman);
	bool bMaskTag = m_pARProperty->getbMaskTag();
	Button_SetCheck(m_ckMaskTag, bMaskTag);
	int poseEstimator = m_pARProperty->getPoseEstimator();
	ComboBox_SetCurSel(m_cbPoseEstimator, poseEstimator);
	int markermode = m_pARProperty->getMarkerMode();
	ComboBox_SetCurSel(m_cbMarkerMode, markermode);
	int undistortMode = m_pARProperty->getUndistortionMode();
	ComboBox_SetCurSel(m_cbUnDistortMode, undistortMode);
	int threshold = m_pARProperty->getThreshold();
	SLIDER_SetPos(m_slrThreshold, threshold);
	float measurenoise = 0.001;
	m_pARProperty->GetMeasureNoiseCov(measurenoise);
	int intMeasurenoise = abs(log10(measurenoise));
	SLIDER_SetPos(m_slrMeasureNoise, intMeasurenoise);
	float borderW = m_pARProperty->getBorderWidth();
	int borderWValue = (int)(borderW*m_BorderWScale);
	SLIDER_SetPos(m_slrBorderW, borderWValue);
	WCHAR str[MAX_PATH] = {0};
	swprintf_s(str, MAX_PATH, L"%d", threshold);
	::SetWindowText(m_txtThreshold, str);

	swprintf_s(str, MAX_PATH, L"%.3f", SLIDER_GetPos(m_slrBorderW)/(float)m_BorderWScale);
	::SetWindowText(m_txtBorderW, str);

	swprintf_s(str, MAX_PATH, L"%d", intMeasurenoise);
	::SetWindowText(m_txtMeasureNoise, str);

	char ipaddress[MAX_PATH] = {0};
	UINT port = 3333;
	m_pARProperty->GetIPAddress(ipaddress, MAX_PATH);
	::SetWindowTextA(m_edIP.GetSafeHwnd(),ipaddress);
	m_pARProperty->GetPort(port);
	swprintf(str, MAX_PATH, L"%d", port);
	m_edPort.SetWindowText(str);

	if (m_pARProperty->IsOSCConnected())
	{
		m_edIP.EnableWindow(FALSE);
		m_edPort.EnableWindow(FALSE);
		m_btnConnect.SetWindowText(L"DisConnect");
	}
	else
	{
		m_edIP.EnableWindow(TRUE);
		m_edPort.EnableWindow(TRUE);
		m_btnConnect.SetWindowText(L"Connect");
	}

}
bool ARTagGeneralPage::ApplySetting()
{
	if (m_pARProperty == NULL)
	{
		return false;
	}
	bool bAutoThreshold = Button_GetCheck(m_ckAutoThreshold);
	m_pARProperty->setAutoThreshold(bAutoThreshold);

	bool bUseKalman = Button_GetCheck(m_ckUseKalman);
	m_pARProperty->setbUseKalman(bUseKalman);

	bool bDrawReproj = Button_GetCheck(m_ckDrawReProj);
	m_pARProperty->setbDrawReproPt(bDrawReproj);
	bool bDrawTag = Button_GetCheck(m_ckDrawTag);
	m_pARProperty->setbDrawTag(bDrawTag);
	bool bGuessPose = Button_GetCheck(m_ckGuessPose);
	m_pARProperty->setbGuessPose(bGuessPose);
	bool bMaskTag = Button_GetCheck(m_ckMaskTag);
	m_pARProperty->setbMaskTag(bMaskTag);



	int poseEstimator = ComboBox_GetCurSel(m_cbPoseEstimator);
	m_pARProperty->setPoseEstimator(poseEstimator);
	
	int markermode = ComboBox_GetCurSel(m_cbMarkerMode);
	m_pARProperty->setMarkerMode(markermode);
	
	int undistortMode = ComboBox_GetCurSel(m_cbUnDistortMode);
	m_pARProperty->setUndistortionMode(undistortMode);

	int threshold = SLIDER_GetPos(m_slrThreshold);
	m_pARProperty->setThreshold(threshold);
	
	int intMeasureNoise = SLIDER_GetPos(m_slrMeasureNoise);
	float measurenoise = pow(0.1, intMeasureNoise);
	m_pARProperty->SetMeasureNoiseCov(measurenoise);
	
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

	int intMeasureNoise = SLIDER_GetPos(m_slrMeasureNoise);
	

	WCHAR str[MAX_PATH] = {0};
	swprintf_s(str, MAX_PATH, L"%d", threshold);
	::SetWindowText(m_txtThreshold, str);

	swprintf_s(str, MAX_PATH, L"%.3f", borderW);
	::SetWindowText(m_txtBorderW, str);

	swprintf_s(str, MAX_PATH, L"%d", abs(intMeasureNoise));
	::SetWindowText(m_txtMeasureNoise, str);
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
BOOL ARTagGeneralPage::OpenFileDialog(HWND hwndParent, WCHAR* pwcsFilter, WCHAR* pwcsDialogTitle, DWORD dwflag, WCHAR* pOutStr, BOOL saveDlg = FALSE)
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
BOOL ARTagGeneralPage::OnReceiveMessage(HWND hwnd,
											  UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	WCHAR str[MAX_PATH] = {0};
	DWORD cmd = 0;
	DWORD cmd2 = 0;
	switch (uMsg) {
	case WM_COMMAND:
		cmd = LOWORD(wParam);
		cmd2 = HIWORD(wParam);
		
		if (cmd2 == CBN_SELCHANGE || BM_SETCHECK) {
			SetDirty();
		}

		if (cmd2 == BN_CLICKED && cmd == IDC_BtnLoadARTag)
		{
			WCHAR pFileName[MAX_PATH] = {0};
			
			OpenFileDialog(this->GetSafeHwnd(), L"*.txt", L"Choose ARTagConfig File", 0, pFileName);
			if (pFileName != NULL)
			{
				m_pARProperty->loadARConfigFromFile(pFileName);
			}
		}

		break;
	case WM_HSCROLL:
		updateSliderTxt();
		int threshold = SLIDER_GetPos(m_slrThreshold);
		m_pARProperty->setThreshold(threshold);

		int borderWValue = SLIDER_GetPos(m_slrBorderW);
		float borderW = borderWValue / (float)m_BorderWScale;
		m_pARProperty->setBorderWidth(borderW);

		int intMeasureNoise = SLIDER_GetPos(m_slrMeasureNoise);
		float measureNoise = pow(0.1, intMeasureNoise);
		m_pARProperty->SetMeasureNoiseCov(measureNoise);
		break;
	}
	return __super::OnReceiveMessage(hwnd,uMsg,wParam,lParam);
}


HRESULT ARTagGeneralPage::OnActivate(void)
{
	if (m_pARProperty == NULL || m_pARProperty->IsReady() == false)
	{
		this->EnableWindow(FALSE);
		return S_OK;
	}
	this->EnableWindow(TRUE);
	m_ckGuessPose = ::GetDlgItem(GetSafeHwnd(), IDC_CKGuessPose);
	m_ckAutoThreshold = ::GetDlgItem(GetSafeHwnd(), IDC_CKAutoThreshold);
	m_ckUseKalman = ::GetDlgItem(GetSafeHwnd(), IDC_CKUseKalman);
	m_ckDrawReProj = ::GetDlgItem(GetSafeHwnd(), IDC_CKReProj);
	m_ckDrawTag = ::GetDlgItem(GetSafeHwnd(), IDC_CHK_DRAWTAG);
	m_ckMaskTag = ::GetDlgItem(GetSafeHwnd(), IDC_CKMaskTag);

	m_cbPoseEstimator = ::GetDlgItem(GetSafeHwnd(), IDC_COMBO_PoseEstimator);
	m_cbMarkerMode = ::GetDlgItem(GetSafeHwnd(), IDC_COMBO_MarkerMode);
	m_cbUnDistortMode = ::GetDlgItem(GetSafeHwnd(), IDC_COMBO_UndistortMode);
	m_slrBorderW = ::GetDlgItem(GetSafeHwnd(), IDC_SLIDER_BorderW);
	m_slrThreshold = ::GetDlgItem(GetSafeHwnd(), IDC_SLIDER_Threshold);
    m_txtBorderW = ::GetDlgItem(GetSafeHwnd(), IDC_txtBorderW);
	m_txtThreshold = ::GetDlgItem(GetSafeHwnd(), IDC_txtThreshold);
	m_txtMeasureNoise = ::GetDlgItem(GetSafeHwnd(), IDC_txtMeasureNoise);;
	m_slrMeasureNoise = ::GetDlgItem(GetSafeHwnd(), IDC_SLIDER_MeasureNoise);

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
	SLIDER_SetRange(m_slrMeasureNoise, 0, m_MNoiseScale);
	SLIDER_SetRange(m_slrThreshold, 0, 255);
	SLIDER_SetRange(m_slrBorderW, 0, m_BorderWScale);
	GetSetting();
	return NOERROR;
}
HRESULT ARTagGeneralPage::OnApplyChanges(void)
{
	if (GetSafeHwnd() == NULL)
		return S_FALSE;
	if (ApplySetting())
	{
		return S_OK;
	}
	else
	{
		return S_FALSE;
	}
}


void ARTagGeneralPage::OnBnClickedBtnconnect()
{
	if (m_pARProperty == NULL)
	{
		return;
	}
	char addressIP[MAX_PATH] = {0};
	::GetWindowTextA(m_edIP.GetSafeHwnd(), addressIP , MAX_PATH);
	int port = 3333;
	WCHAR str[MAX_PATH];
	m_edPort.GetWindowText(str, MAX_PATH);
	swscanf_s(str, L"%d", &port);
	if (m_pARProperty->IsOSCConnected())
	{
		m_pARProperty->DisConnectOSC();
	}
	else
	{
		m_pARProperty->ConnectOSC(addressIP, port);
	}
	GetSetting();
}
