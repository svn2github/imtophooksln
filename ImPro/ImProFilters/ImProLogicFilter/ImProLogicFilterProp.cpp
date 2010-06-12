#include "stdafx.h"
#include "ImProLogicFilterProp.h"
#include "ImProLogicFilterApp.h"


IMPLEMENT_DYNAMIC(ImProLogicFilterProp, GSMFCProp)

extern CImProLogicFilterApp theApp;

void ImProLogicFilterProp::DoDataExchange(CDataExchange* pDX)
{
	__super::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_IP, m_edIP);
	DDX_Control(pDX, IDC_BTNCONNECT, m_btnConnect);
	DDX_Control(pDX, IDC_Port, m_edPort);
}
BOOL ImProLogicFilterProp::OnInitDialog()
{
	BOOL ret = __super::OnInitDialog();

	return ret;
}

BEGIN_MESSAGE_MAP(ImProLogicFilterProp, GSMFCProp)
	ON_BN_CLICKED(IDC_BTNCONNECT, &ImProLogicFilterProp::OnBnClickedBtnconnect)
END_MESSAGE_MAP()




ImProLogicFilterProp::ImProLogicFilterProp(IUnknown *pUnk) : 
GSMFCProp(NAME("ImProLogicFilterProp"), pUnk),
m_pFilter(0)
{
}

ImProLogicFilterProp::~ImProLogicFilterProp()
{
	if (m_pFilter != NULL)
	{
		m_pFilter->Release();
		m_pFilter = NULL;
	}
}

//override CBasePropertyPage Method
HRESULT ImProLogicFilterProp::OnConnect(IUnknown *pUnk)
{
	//override CBasePropertyPage Method
	if (pUnk == NULL)
	{
		return E_POINTER;
	}
	if (m_pFilter == NULL)
	{
		pUnk->QueryInterface(IID_IImProLogicFilter, 
			reinterpret_cast<void**>(&m_pFilter));
		return S_OK;
	}
	return S_OK;
}
HRESULT ImProLogicFilterProp::OnDisconnect(void)
{
	if (m_pFilter != NULL)
	{
		m_pFilter->Release();
		m_pFilter = NULL;
	}
	return S_OK;
}
BOOL ImProLogicFilterProp::OnReceiveMessage(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return TRUE;
}
HRESULT ImProLogicFilterProp::OnActivate(void)
{
	if (m_pFilter != NULL)
		EnableWindow(TRUE);
	else

		EnableWindow(FALSE);

	GetSetting();

	return S_OK;
}
HRESULT ImProLogicFilterProp::OnApplyChanges(void)
{
	return S_OK;
}

CUnknown *WINAPI ImProLogicFilterProp::CreateInstance(LPUNKNOWN punk, HRESULT *phr)
{
	ASSERT(phr);
	// assuming we don't want to modify the data
	ImProLogicFilterProp *pNewObject = new ImProLogicFilterProp(punk);

	if(pNewObject == NULL) {
		if (phr)
			*phr = E_OUTOFMEMORY;
	}

	return pNewObject;
}


HRESULT ImProLogicFilterProp::GetSetting()
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

void ImProLogicFilterProp::OnBnClickedBtnconnect()
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
