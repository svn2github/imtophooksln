#include "stdafx.h"
#include "TouchLibFilterProp.h"
#include "TouchLibFilterApp.h"
#include <string>
#include <math.h>
using namespace std;
extern CTouchLibFilterApp theApp;

IMPLEMENT_DYNAMIC(TouchLibPropPage, CMFCBasePropertyPage)
void TouchLibPropPage::DoDataExchange(CDataExchange* pDX)
{
	CMFCBasePropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edFingerMsg);
	DDX_Text(pDX, IDC_EDIT1, m_strFingerMsg);
	DDX_Control(pDX, IDC_CKSHOWMSG, m_ckShowMsg);
	DDX_Control(pDX, IDC_CKShowConfig, m_ckShowConfigWnd);
	DDX_Control(pDX, IDC_BTNCONNECT, m_btnConnect);
	DDX_Control(pDX, IDC_EDIT2, m_edIP);
	DDX_Control(pDX, IDC_EDIT3, m_edPort);
	DDX_Control(pDX, IDC_ckBeginTrack, m_ckBeginTrack);
	DDX_Control(pDX, IDC_ckDrawFinger, m_ckDrawFinger);
	DDX_Control(pDX, IDC_CKFingerFlipY, m_ckFingerFlipY);
	DDX_Control(pDX, IDC_CKDrawROI, m_ckDrawROI);
	DDX_Control(pDX, IDC_CKSkipBG, m_ckSkipBGRemove);
	DDX_Control(pDX, IDC_SLRNUMFRAMEFIX, m_slrNumFrameFix);
	DDX_Control(pDX, IDC_TXTNumFrameFix, m_txtNumFrameFix);
	DDX_Control(pDX, IDC_ckUseKalman, m_ckUseKalman);
	DDX_Control(pDX, IDC_slrMNoise, m_slrMNoise);
	DDX_Control(pDX, IDC_txtMNoise, m_txtMNoise);
}


BEGIN_MESSAGE_MAP(TouchLibPropPage, CMFCBasePropertyPage)
	ON_BN_CLICKED(IDC_BTNCLEAR, &TouchLibPropPage::OnBnClickedBtnclear)
	ON_BN_CLICKED(IDC_CKSHOWMSG, &TouchLibPropPage::OnBnClickedCkshowmsg)
	ON_BN_CLICKED(IDC_CKShowConfig, &TouchLibPropPage::OnBnClickedCkshowconfig)
	ON_BN_CLICKED(IDC_BTNCONNECT, &TouchLibPropPage::OnBnClickedBtnconnect)
	ON_BN_CLICKED(IDC_btnClearBg, &TouchLibPropPage::OnBnClickedBtnClearBG)
	ON_BN_CLICKED(IDC_ckBeginTrack, &TouchLibPropPage::OnBnClickedckbegintrack)
	ON_BN_CLICKED(IDC_ckDrawFinger, &TouchLibPropPage::OnBnClickedckdrawfinger)
	ON_BN_CLICKED(IDC_CKFingerFlipY, &TouchLibPropPage::OnBnClickedCkfingerflipy)
	ON_BN_CLICKED(IDC_CKDrawROI, &TouchLibPropPage::OnBnClickedCkdrawroi)
	ON_BN_CLICKED(IDC_CKSkipBG, &TouchLibPropPage::OnBnClickedCkskipbg)
	ON_NOTIFY(TRBN_THUMBPOSCHANGING, IDC_SLRNUMFRAMEFIX, &TouchLibPropPage::OnTRBNThumbPosChangingSlrnumframefix)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLRNUMFRAMEFIX, &TouchLibPropPage::OnNMCustomdrawSlrnumframefix)
	ON_BN_CLICKED(IDC_ckUseKalman, &TouchLibPropPage::OnBnClickedckusekalman)
	ON_NOTIFY(TRBN_THUMBPOSCHANGING, IDC_slrMNoise, &TouchLibPropPage::OnTRBNThumbPosChangingslrmnoise)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_slrMNoise, &TouchLibPropPage::OnNMCustomdrawslrmnoise)
END_MESSAGE_MAP()


// CHomoWarpMFCPropertyPage message handlers


TouchLibPropPage::TouchLibPropPage(IUnknown *pUnk) : 
CMFCBasePropertyPage(NAME("TouchLibPropPage"), pUnk),
m_pFilter(0)
, m_strFingerMsg(_T(""))
{

}

TouchLibPropPage::~TouchLibPropPage()
{
	if (m_pFilter != NULL)
	{
		m_pFilter->Release();
		m_pFilter = NULL;
	}
}

//override CBasePropertyPage Method
HRESULT TouchLibPropPage::OnConnect(IUnknown *pUnk)
{
	//override CBasePropertyPage Method
	if (pUnk == NULL)
	{
		return E_POINTER;
	}
	if (m_pFilter == NULL)
	{
		pUnk->QueryInterface(IID_ITouchLibFilter, 
			reinterpret_cast<void**>(&m_pFilter));
	}
	return S_OK;
}
HRESULT TouchLibPropPage::OnDisconnect(void)
{
	if (m_pFilter != NULL)
	{
		m_pFilter->unregisterListener(this);
		m_pFilter->Release();
		m_pFilter = NULL;
	}
	return S_OK;
}
BOOL TouchLibPropPage::OnReceiveMessage(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return TRUE;
}
HRESULT TouchLibPropPage::OnActivate(void)
{
	if (m_pFilter != NULL && m_pFilter->IsTouchReady())
	{
		EnableWindow(TRUE);
		m_slrNumFrameFix.SetRangeMin(0, TRUE);
		m_slrNumFrameFix.SetRangeMax(15, TRUE);
		m_slrMNoise.SetRangeMin(0, TRUE);
		m_slrMNoise.SetRangeMax(10, TRUE);
		GetSetting();
	}
	else
	{
		EnableWindow(FALSE);
	}
	return S_OK;
}
HRESULT TouchLibPropPage::OnApplyChanges(void)
{
	return S_OK;
}

CUnknown *WINAPI TouchLibPropPage::CreateInstance(LPUNKNOWN punk, HRESULT *phr)
{
	ASSERT(phr);
	// assuming we don't want to modify the data
	TouchLibPropPage *pNewObject = new TouchLibPropPage(punk);

	if(pNewObject == NULL) {
		if (phr)
			*phr = E_OUTOFMEMORY;
	}

	return pNewObject;
}
void TouchLibPropPage::fingerDown(TouchData data)
{
	UINT length = m_edFingerMsg.GetWindowTextLength();
	UINT limit = m_edFingerMsg.GetLimitText();
	if (length + MAX_PATH > limit)
	{
		m_edFingerMsg.SetSel(0, limit/2, TRUE); 
		m_edFingerMsg.ReplaceSel(L"");
	}
	swprintf_s(m_tmpStr, MAX_PATH, L"fingerDown id = %d, tagID = %d, x = %.2f, y= %.2f \n",
		data.ID, data.tagID, data.X, data.Y);

	m_edFingerMsg.SetSel (0xffff, 0xffff);  //select position after last char in editbox
	m_edFingerMsg.ReplaceSel (m_tmpStr); 
	
}
void TouchLibPropPage::fingerUpdate(TouchData data)
{
	UINT length = m_edFingerMsg.GetWindowTextLength();
	UINT limit = m_edFingerMsg.GetLimitText();
	if (length + MAX_PATH > limit)
	{
		m_edFingerMsg.SetSel(0, limit/2, TRUE); 
		m_edFingerMsg.ReplaceSel(L"");
	}
	swprintf_s(m_tmpStr, MAX_PATH, L"fingerUpdate id = %d, tagID = %d, x = %.2f, y= %.2f \n",
		data.ID, data.tagID, data.X, data.Y);

	m_edFingerMsg.SetSel (0xffff, 0xffff);  //select position after last char in editbox
	m_edFingerMsg.ReplaceSel (m_tmpStr); 
}
void TouchLibPropPage::fingerUp(TouchData data)
{
	UINT length = m_edFingerMsg.GetWindowTextLength();
	UINT limit = m_edFingerMsg.GetLimitText();
	if (length + MAX_PATH > limit)
	{
		m_edFingerMsg.SetSel(0, limit/2, TRUE); 
		m_edFingerMsg.ReplaceSel(L"");
	}
	swprintf_s(m_tmpStr, MAX_PATH, L"fingerUp id = %d, tagID = %d, x = %.2f, y= %.2f \n",
		data.ID, data.tagID, data.X, data.Y);
	m_edFingerMsg.SetSel (0xffff, 0xffff);  //select position after last char in editbox
	m_edFingerMsg.ReplaceSel (m_tmpStr); 
}

void TouchLibPropPage::OnBnClickedBtnclear()
{
	m_edFingerMsg.SetSel(0, -1, TRUE); 
	m_edFingerMsg.ReplaceSel(L"");
}

void TouchLibPropPage::OnBnClickedCkshowmsg()
{
	if (m_ckShowMsg.GetCheck())
	{
		if (m_pFilter)
			m_pFilter->registerListener(this);
	}
	else
	{
		if (m_pFilter)
			m_pFilter->unregisterListener(this);
	}
}

void TouchLibPropPage::OnBnClickedCkshowconfig()
{
	if (m_pFilter == NULL)
		return;
	m_pFilter->ShowConfigWindow(m_ckShowConfigWnd.GetCheck());
}

bool TouchLibPropPage::GetSetting()
{
	if (m_pFilter == NULL)
	{
		return false;
	}
	char ipaddress[MAX_PATH] = {0};
	int port = 3333;
	m_pFilter->GetIPAddress(ipaddress);
	::SetWindowTextA(m_edIP.GetSafeHwnd(),ipaddress);
	WCHAR str[MAX_PATH];
	port = m_pFilter->GetPort();
	swprintf(str, MAX_PATH, L"%d", port);
	m_edPort.SetWindowText(str);
	bool bStartTracking = false;
	m_pFilter->getStartTracking(bStartTracking);
	m_ckBeginTrack.SetCheck(bStartTracking);
	m_ckDrawFinger.SetCheck(m_pFilter->getDrawFingers());
	m_ckFingerFlipY.SetCheck(m_pFilter->GetbFlipY());
	m_ckDrawROI.SetCheck(m_pFilter->getDrawROI());
	m_ckSkipBGRemove.SetCheck(m_pFilter->GetIsSkipBGRemove());
	m_ckUseKalman.SetCheck(m_pFilter->getUseKalmanFilter());

	m_slrNumFrameFix.SetPos(m_pFilter->getNumFrameFix());
	swprintf_s(str, MAX_PATH, L"%d", m_pFilter->getNumFrameFix());
	m_txtNumFrameFix.SetWindowText(str);
	float mnoise = 0.01;
	int intMNoise = 2;
	m_pFilter->getKalmanMNoise(mnoise);
	intMNoise = abs(log10(mnoise));
	m_slrMNoise.SetPos(intMNoise);
	swprintf_s(str, MAX_PATH, L"%d", intMNoise);
	m_txtMNoise.SetWindowText(str);


	if (m_pFilter->IsOSCConnected())
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
	return true;
}
bool TouchLibPropPage::ApplySetting()
{
	return true;
}
void TouchLibPropPage::OnBnClickedBtnconnect()
{
	if (m_pFilter == NULL)
	{
		return;
	}
	char addressIP[MAX_PATH] = {0};
	::GetWindowTextA(m_edIP.GetSafeHwnd(), addressIP , MAX_PATH);
	int port = 3333;
	WCHAR str[MAX_PATH];
	m_edPort.GetWindowText(str, MAX_PATH);
	swscanf_s(str, L"%d", &port);
	if (m_pFilter->IsOSCConnected())
	{
		m_pFilter->DisConnectOSC();
	}
	else
	{
		m_pFilter->ConnectOSC(addressIP, port);
	}
	GetSetting();
}
void TouchLibPropPage::OnBnClickedBtnClearBG()
{
	if (m_pFilter == NULL)
	{
		return ;
	}
	m_pFilter->ClearBackground();
	return;
}
void TouchLibPropPage::OnBnClickedckbegintrack()
{
	if (m_pFilter == NULL)
	{
		return;
	}
	int bCk = m_ckBeginTrack.GetCheck();
	m_pFilter->setStartTracking(bCk);
	return;
}

void TouchLibPropPage::OnBnClickedckdrawfinger()
{
	if (m_pFilter == NULL)
		return;
	m_pFilter->setDrawFingers(m_ckDrawFinger.GetCheck());
}


void TouchLibPropPage::OnBnClickedCkfingerflipy()
{
	if (m_pFilter == NULL)
		return;
	m_pFilter->SetbFlipY(m_ckFingerFlipY.GetCheck());
}

void TouchLibPropPage::OnBnClickedCkdrawroi()
{
	if (m_pFilter == NULL)
		return;
	m_pFilter->setDrawROI(m_ckDrawROI.GetCheck());
}

void TouchLibPropPage::OnBnClickedCkskipbg()
{
	if (m_pFilter == NULL)
		return;
	m_pFilter->SetIsSKipBGRemove(m_ckSkipBGRemove.GetCheck());
}

void TouchLibPropPage::OnTRBNThumbPosChangingSlrnumframefix(NMHDR *pNMHDR, LRESULT *pResult)
{
	// This feature requires Windows Vista or greater.
	// The symbol _WIN32_WINNT must be >= 0x0600.
	NMTRBTHUMBPOSCHANGING *pNMTPC = reinterpret_cast<NMTRBTHUMBPOSCHANGING *>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}

void TouchLibPropPage::OnNMCustomdrawSlrnumframefix(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
	if (m_pFilter == NULL)
		return;
	WCHAR str[MAX_PATH];
	int numFrameFix = m_slrNumFrameFix.GetPos();
	m_pFilter->setNumFrameFix(numFrameFix);
	swprintf_s(str, MAX_PATH, L"%d", numFrameFix);
	m_txtNumFrameFix.SetWindowText(str);
}

void TouchLibPropPage::OnBnClickedckusekalman()
{
	if (m_pFilter == NULL)
		return;
	WCHAR str[MAX_PATH];
	bool bUseKalman  = m_ckUseKalman.GetCheck();
	m_pFilter->setUseKalmanFilter(bUseKalman);
}

void TouchLibPropPage::OnTRBNThumbPosChangingslrmnoise(NMHDR *pNMHDR, LRESULT *pResult)
{
	// This feature requires Windows Vista or greater.
	// The symbol _WIN32_WINNT must be >= 0x0600.
	NMTRBTHUMBPOSCHANGING *pNMTPC = reinterpret_cast<NMTRBTHUMBPOSCHANGING *>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
	
	
}

void TouchLibPropPage::OnNMCustomdrawslrmnoise(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;

	WCHAR str[MAX_PATH] = {0};
	float mnoise = 0.01;
	int intMNoise = 2;

	intMNoise = m_slrMNoise.GetPos();
	swprintf_s(str, MAX_PATH, L"%d", intMNoise);
	m_txtMNoise.SetWindowText(str);
	mnoise = pow(0.1, intMNoise);
	m_pFilter->setKalmanMNoise(mnoise);
}
