#include "stdafx.h"
#include "GSARTagLayoutFilterProp.h"
#include "GSARTagLayoutFilterApp.h"


IMPLEMENT_DYNAMIC(GSARTagLayoutFilterProp, GSMFCProp)

extern CGSARTagLayoutFilterApp theApp;

void GSARTagLayoutFilterProp::DoDataExchange(CDataExchange* pDX)
{
	__super::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_slrBlackLevel, m_slrBlackLevel);
	DDX_Control(pDX, IDC_txtBlackLevel, m_txtBlackLevel);
	DDX_Control(pDX, IDC_cbFPS, m_cbFPS);
}
BOOL GSARTagLayoutFilterProp::OnInitDialog()
{
	BOOL ret = __super::OnInitDialog();

	return ret;
}

BEGIN_MESSAGE_MAP(GSARTagLayoutFilterProp, GSMFCProp)

	ON_CBN_SELCHANGE(IDC_cbFPS, &GSARTagLayoutFilterProp::OnCbnSelchangecbfps)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_slrBlackLevel, &GSARTagLayoutFilterProp::OnNMCustomdrawslrblacklevel)
END_MESSAGE_MAP()




GSARTagLayoutFilterProp::GSARTagLayoutFilterProp(IUnknown *pUnk) : 
GSMFCProp(NAME("GSARTagLayoutFilterProp"), pUnk),
m_pFilter(0)
{
}

GSARTagLayoutFilterProp::~GSARTagLayoutFilterProp()
{
	if (m_pFilter != NULL)
	{
		m_pFilter->Release();
		m_pFilter = NULL;
	}
}

//override CBasePropertyPage Method
HRESULT GSARTagLayoutFilterProp::OnConnect(IUnknown *pUnk)
{
	//override CBasePropertyPage Method
	if (pUnk == NULL)
	{
		return E_POINTER;
	}
	if (m_pFilter == NULL)
	{
		pUnk->QueryInterface(IID_IGSARTagLayoutFilter, 
			reinterpret_cast<void**>(&m_pFilter));
		return S_OK;
	}
	return S_OK;
}
HRESULT GSARTagLayoutFilterProp::OnDisconnect(void)
{
	if (m_pFilter != NULL)
	{
		m_pFilter->Release();
		m_pFilter = NULL;
	}
	return S_OK;
}
BOOL GSARTagLayoutFilterProp::OnReceiveMessage(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return TRUE;
}
HRESULT GSARTagLayoutFilterProp::OnActivate(void)
{
	if (m_pFilter != NULL)
		EnableWindow(TRUE);
	else
		EnableWindow(FALSE);

	m_slrBlackLevel.SetRange(0, 10, FALSE);


	m_cbFPS.AddString(L"500");
	m_cbFPS.AddString(L"120");
	m_cbFPS.AddString(L"60");
	m_cbFPS.AddString(L"30");
	m_cbFPS.AddString(L"20");
	m_cbFPS.AddString(L"15");
	m_cbFPS.AddString(L"10");
	m_cbFPS.AddString(L"5");

	GetSetting();

	return S_OK;
}
HRESULT GSARTagLayoutFilterProp::OnApplyChanges(void)
{
	return S_OK;
}

CUnknown *WINAPI GSARTagLayoutFilterProp::CreateInstance(LPUNKNOWN punk, HRESULT *phr)
{
	ASSERT(phr);
	// assuming we don't want to modify the data
	GSARTagLayoutFilterProp *pNewObject = new GSARTagLayoutFilterProp(punk);

	if(pNewObject == NULL) {
		if (phr)
			*phr = E_OUTOFMEMORY;
	}

	return pNewObject;
}

HRESULT GSARTagLayoutFilterProp::GetSetting()
{
	if (m_pFilter == NULL)
		return E_FAIL;
	
	WCHAR str[MAX_PATH] = {0};

	
	float blackLevel = m_pFilter->GetBlackLevel();
	int nBlackLevel = blackLevel*10;
	m_slrBlackLevel.SetPos(nBlackLevel);
	swprintf_s(str, MAX_PATH, L"%.1f", blackLevel);
	m_txtBlackLevel.SetWindowText(str);

	float fps = m_pFilter->GetFrameRate();
	int cbCount = m_cbFPS.GetCount();

	double cbFPS;
	int chooseIdx = -1;
	float minError = 1000;

	for (int i =0 ; i< cbCount; i++)
	{
		m_cbFPS.GetLBText(i, str);
		swscanf_s(str, L"%lf", &cbFPS);
		if (abs(fps - cbFPS) < minError)
		{
			chooseIdx = i;
			minError = abs(fps - cbFPS);
		}
	}
	if (chooseIdx != -1)
		m_cbFPS.SetCurSel(chooseIdx);

	return S_OK;
}


void GSARTagLayoutFilterProp::OnCbnSelchangecbfps()
{
	if (m_pFilter == NULL)
		return;
	int idx = m_cbFPS.GetCurSel();
	WCHAR str[MAX_PATH] = {0};
	m_cbFPS.GetLBText(idx, str);
	double cbFps = 0;
	swscanf_s(str, L"%lf", &cbFps);
	m_pFilter->SetFrameRate(cbFps);
}

void GSARTagLayoutFilterProp::OnNMCustomdrawslrblacklevel(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;

	if (m_pFilter == NULL)
		return ;
	WCHAR str[MAX_PATH] = {0};
	int nBlackLevel = m_slrBlackLevel.GetPos();
	float blackLevel = nBlackLevel*0.1;
	m_pFilter->SetBlackLevel(blackLevel);

	m_slrBlackLevel.SetPos(nBlackLevel);
	swprintf_s(str, MAX_PATH, L"%.1f", blackLevel);
	m_txtBlackLevel.SetWindowText(str);
}
