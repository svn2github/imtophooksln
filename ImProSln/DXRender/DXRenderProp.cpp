#include "stdafx.h"
#include "DXRenderProp.h"

IMPLEMENT_DYNAMIC(DXRenderFilterProp, CMFCBasePropertyPage)


void DXRenderFilterProp::DoDataExchange(CDataExchange* pDX)
{
	CMFCBasePropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CKHideBorder, m_ckHideBorder);
	DDX_Control(pDX, IDC_CK_FlipX, m_ckFlipX);
	DDX_Control(pDX, IDC_CK_FlipY, m_ckFlipY);
	DDX_Control(pDX, IDC_edX, m_edX);
	DDX_Control(pDX, IDC_edY, m_edY);
	DDX_Control(pDX, IDC_edWidth, m_edWidth);
	DDX_Control(pDX, IDC_edHeight, m_edHeight);
	DDX_Control(pDX, IDC_CKMaxWnd, m_ckMaxWnd);
	DDX_Control(pDX, IDC_CHECK1, m_ckDrawFPS);
	DDX_Control(pDX, IDC_RAPoint, m_raPoint);
	
}


BEGIN_MESSAGE_MAP(DXRenderFilterProp, CMFCBasePropertyPage)
	ON_BN_CLICKED(IDC_CKHideBorder, &DXRenderFilterProp::OnBnClickedCkhideborder)
	ON_BN_CLICKED(IDC_CK_FlipX, &DXRenderFilterProp::OnBnClickedCkFlipx)
	ON_BN_CLICKED(IDC_CK_FlipY, &DXRenderFilterProp::OnBnClickedCkFlipy)
//	ON_EN_KILLFOCUS(IDC_edX, &DXRenderFilterProp::OnEnKillfocusedx)
//	ON_EN_CHANGE(IDC_edX, &DXRenderFilterProp::OnEnChangeedx)
ON_EN_KILLFOCUS(IDC_edX, &DXRenderFilterProp::OnEnKillfocusedx)
ON_EN_KILLFOCUS(IDC_edY, &DXRenderFilterProp::OnEnKillfocusedy)
ON_EN_KILLFOCUS(IDC_edWidth, &DXRenderFilterProp::OnEnKillfocusedwidth)
ON_EN_KILLFOCUS(IDC_edHeight, &DXRenderFilterProp::OnEnKillfocusedheight)
ON_BN_CLICKED(IDC_CKMaxWnd, &DXRenderFilterProp::OnBnClickedCkmaxwnd)
//ON_EN_UPDATE(IDC_edX, &DXRenderFilterProp::OnEnUpdateedx)
//ON_EN_CHANGE(IDC_edX, &DXRenderFilterProp::OnEnChangeedx)
ON_EN_UPDATE(IDC_edX, &DXRenderFilterProp::OnEnUpdateedx)
ON_EN_UPDATE(IDC_edY, &DXRenderFilterProp::OnEnUpdateedy)
ON_EN_UPDATE(IDC_edWidth, &DXRenderFilterProp::OnEnUpdateedwidth)
ON_EN_UPDATE(IDC_edHeight, &DXRenderFilterProp::OnEnUpdateedheight)
ON_BN_CLICKED(IDC_CHECK1, &DXRenderFilterProp::OnBnClickedCheck1)
//ON_NOTIFY(BCN_HOTITEMCHANGE, IDC_RAPoint, &DXRenderFilterProp::OnBnHotItemChangeRapoint)
ON_BN_CLICKED(IDC_RAPoint, &DXRenderFilterProp::OnBnClickedRapoint)
ON_BN_CLICKED(IDC_RALinear, &DXRenderFilterProp::OnBnClickedRalinear)
END_MESSAGE_MAP()


// CHomoWarpMFCPropertyPage message handlers


DXRenderFilterProp::DXRenderFilterProp(IUnknown *pUnk) : 
CMFCBasePropertyPage(NAME("DXRenderFilterProp"), pUnk),
m_pFilter(0)
{

}

DXRenderFilterProp::~DXRenderFilterProp()
{
	if (m_pFilter != NULL)
	{
		m_pFilter->Release();
		m_pFilter = NULL;
	}
}

//override CBasePropertyPage Method
HRESULT DXRenderFilterProp::OnConnect(IUnknown *pUnk)
{
	if (pUnk == NULL)
	{
		return E_POINTER;
	}
	if (m_pFilter == NULL)
	{
		pUnk->QueryInterface(IID_IDXRenderer, 
			reinterpret_cast<void**>(&m_pFilter));
		return S_OK;
	}
	return S_OK;
}
HRESULT DXRenderFilterProp::OnDisconnect(void)
{
	return S_OK;
}
BOOL DXRenderFilterProp::OnReceiveMessage(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return TRUE;
}
HRESULT DXRenderFilterProp::OnActivate(void)
{
	if (m_pFilter != NULL)
	{
		this->EnableWindow(TRUE);
	}
	GetSetting();
	return S_OK;
}
bool DXRenderFilterProp::GetSetting()
{
	if (m_pFilter == NULL)
	{
		return false;
	}
	WCHAR str[MAX_PATH] = {0};
	int sampleType = m_pFilter->GetSampleType();
	if (sampleType == 0)
	{
		m_raPoint.SetCheck(TRUE);
	}
	else
	{
		CButton* raLinear = (CButton*)GetDlgItem(IDC_RALinear);
		raLinear->SetCheck(TRUE);
	}
	bool flipX = m_pFilter->GetFlipX();
	bool flipY = m_pFilter->GetFlipY();
	m_ckFlipX.SetCheck(flipX);
	m_ckFlipY.SetCheck(flipY);
	BOOL isZoomed = m_pFilter->IsWindowZoom();
	BOOL isHideBorder = m_pFilter->IsHideBorder();
	m_ckHideBorder.SetCheck(isHideBorder);
	m_ckMaxWnd.SetCheck(m_pFilter->IsWindowZoom());

	bool bDrawFPS = m_pFilter->GetbDrawFPS();
	m_ckDrawFPS.SetCheck(bDrawFPS);

	BOOL bMaxWnd = m_pFilter->IsWindowZoom(); 
	m_ckMaxWnd.SetCheck(bMaxWnd);
	RECT rect;
	if (FAILED(m_pFilter->GetWindowRect(rect)))
		return false;

	swprintf_s(str, MAX_PATH, L"%d", rect.left);
	m_edX.SetWindowText(str);
	swprintf_s(str, MAX_PATH, L"%d", rect.top);
	m_edY.SetWindowText(str);
	swprintf_s(str, MAX_PATH, L"%d", rect.right - rect.left);
	m_edWidth.SetWindowText(str);
	swprintf_s(str, MAX_PATH, L"%d", rect.bottom - rect.top);
	m_edHeight.SetWindowText(str);
	return true;
}

bool DXRenderFilterProp::ApplySetting()
{
	if (m_pFilter == NULL)
		return false;
	CString tmpStr;
	int x = 0, y = 0, width =0, height = 0; 
	m_edX.GetWindowText(tmpStr);
	swscanf_s(tmpStr, L"%d", &x );
	m_edY.GetWindowText(tmpStr);
	swscanf_s(tmpStr, L"%d", &y );
	m_edWidth.GetWindowText(tmpStr);
	swscanf_s(tmpStr, L"%d", &width);
	m_edHeight.GetWindowText(tmpStr);
	swscanf_s(tmpStr, L"%d", &height);
	
	RECT rect;
	rect.left = x;
	rect.right =x+ width;
	rect.top = y;
	rect.bottom = y + height;
	m_pFilter->SetWindowRect(rect);
	
	return true;
}
HRESULT DXRenderFilterProp::OnApplyChanges(void)
{
	return S_OK;
}

CUnknown *WINAPI DXRenderFilterProp::CreateInstance(LPUNKNOWN punk, HRESULT *phr)
{
	ASSERT(phr);
	// assuming we don't want to modify the data
	DXRenderFilterProp *pNewObject = new DXRenderFilterProp(punk);

	if(pNewObject == NULL) {
		if (phr)
			*phr = E_OUTOFMEMORY;
	}

	return pNewObject;
}
void DXRenderFilterProp::OnBnClickedCkhideborder()
{
	if (m_pFilter == NULL)
		return;
	m_pFilter->SetHideBorder(m_ckHideBorder.GetCheck());
}

void DXRenderFilterProp::OnBnClickedCkFlipx()
{
	if (m_pFilter == NULL)
		return;
	m_pFilter->SetFlipX(m_ckFlipX.GetCheck());
}

void DXRenderFilterProp::OnBnClickedCkFlipy()
{
	if (m_pFilter == NULL)
		return;
	m_pFilter->SetFlipY(m_ckFlipY.GetCheck());
}

void DXRenderFilterProp::OnEnKillfocusedx()
{
	ApplySetting();
}

void DXRenderFilterProp::OnEnKillfocusedy()
{
	ApplySetting();
}

void DXRenderFilterProp::OnEnKillfocusedwidth()
{
	ApplySetting();
}

void DXRenderFilterProp::OnEnKillfocusedheight()
{
	ApplySetting();
}

void DXRenderFilterProp::OnBnClickedCkmaxwnd()
{
	m_pFilter->SetWindowZoom(m_ckMaxWnd.GetCheck());
	GetSetting();
}


void DXRenderFilterProp::OnEnUpdateedx()
{
	SetDirty();
}

void DXRenderFilterProp::OnEnUpdateedy()
{
	SetDirty();
}

void DXRenderFilterProp::OnEnUpdateedwidth()
{
	SetDirty();
}

void DXRenderFilterProp::OnEnUpdateedheight()
{
	SetDirty();
}

void DXRenderFilterProp::OnBnClickedCheck1()
{
	if (m_pFilter == NULL)
		return ;
	m_pFilter->SetbDrawFPS(m_ckDrawFPS.GetCheck());
}

//void DXRenderFilterProp::OnBnHotItemChangeRapoint(NMHDR *pNMHDR, LRESULT *pResult)
//{
//	// This feature requires Internet Explorer 6 or greater.
//	// The symbol _WIN32_IE must be >= 0x0600.
//	LPNMBCHOTITEM pHotItem = reinterpret_cast<LPNMBCHOTITEM>(pNMHDR);
//	// TODO: Add your control notification handler code here
//	*pResult = 0;
//}

void DXRenderFilterProp::OnBnClickedRapoint()
{
	if (m_pFilter == NULL)
		return;
	CButton* raLinear = (CButton*)GetDlgItem(IDC_RALinear);
	int idx = 0;
	if (m_raPoint.GetCheck())
	{
		idx = 0;
	}
	else if (raLinear->GetCheck())
	{
		idx = 1;
	}
	m_pFilter->SetSampleType(idx);
}

void DXRenderFilterProp::OnBnClickedRalinear()
{
	if (m_pFilter == NULL)
		return;
	CButton* raLinear = (CButton*)GetDlgItem(IDC_RALinear);
	int idx = 0;
	if (m_raPoint.GetCheck())
	{
		idx = 0;
	}
	else if (raLinear->GetCheck())
	{
		idx = 1;
	}
	m_pFilter->SetSampleType(idx);
}
