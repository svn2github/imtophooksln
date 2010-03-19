#include "stdafx.h"
#include "AR2WarpControllerProp.h"

IMPLEMENT_DYNAMIC(AR2WarpControllerPropertyPage, CMFCBasePropertyPage)


void AR2WarpControllerPropertyPage::DoDataExchange(CDataExchange* pDX)
{
	CMFCBasePropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_IP, m_edIP);
	DDX_Control(pDX, IDC_Port, m_edPort);
	DDX_Control(pDX, IDC_BTNCONNECT, m_btnConnect);
}


BEGIN_MESSAGE_MAP(AR2WarpControllerPropertyPage, CMFCBasePropertyPage)
	ON_BN_CLICKED(IDC_BTNCONNECT, &AR2WarpControllerPropertyPage::OnBnClickedBtnconnect)
END_MESSAGE_MAP()


// CHomoWarpMFCPropertyPage message handlers


AR2WarpControllerPropertyPage::AR2WarpControllerPropertyPage(IUnknown *pUnk) : 
CMFCBasePropertyPage(NAME("AR2WarpControllerPropertyPage"), pUnk),
m_pFilter(0)
{

}

AR2WarpControllerPropertyPage::~AR2WarpControllerPropertyPage()
{
	if (m_pFilter != NULL)
	{
		m_pFilter->Release();
		m_pFilter = NULL;
	}
}

//override CBasePropertyPage Method
HRESULT AR2WarpControllerPropertyPage::OnConnect(IUnknown *pUnk)
{
	if (pUnk == NULL)
	{
		return E_POINTER;
	}
	if (m_pFilter == NULL)
	{
		pUnk->QueryInterface(IID_IAR2WarpController, 
			reinterpret_cast<void**>(&m_pFilter));
	}
	return S_OK;
}
HRESULT AR2WarpControllerPropertyPage::OnDisconnect(void)
{
	if (m_pFilter != NULL)
	{
		m_pFilter->Release();
		m_pFilter = NULL;
	}
	return S_OK;
}
BOOL AR2WarpControllerPropertyPage::OnReceiveMessage(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return TRUE;
}
HRESULT AR2WarpControllerPropertyPage::OnActivate(void)
{
	if (m_pFilter != NULL)
	{
		EnableWindow(TRUE);
		GetSetting();
	}
	else
	{
		EnableWindow(FALSE);
	}
	return S_OK;
}
HRESULT AR2WarpControllerPropertyPage::OnApplyChanges(void)
{
	return S_OK;
}

CUnknown *WINAPI AR2WarpControllerPropertyPage::CreateInstance(LPUNKNOWN punk, HRESULT *phr)
{
	ASSERT(phr);
	// assuming we don't want to modify the data
	AR2WarpControllerPropertyPage *pNewObject = new AR2WarpControllerPropertyPage(punk);

	if(pNewObject == NULL) {
		if (phr)
			*phr = E_OUTOFMEMORY;
	}

	return pNewObject;
}

bool AR2WarpControllerPropertyPage::GetSetting()
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

void AR2WarpControllerPropertyPage::OnBnClickedBtnconnect()
{
	if (m_pFilter == NULL)
	{
		return;
	}
	char addressIP[MAX_PATH] = {0};
	::GetWindowTextA(m_edIP.GetSafeHwnd(), addressIP, MAX_PATH);
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