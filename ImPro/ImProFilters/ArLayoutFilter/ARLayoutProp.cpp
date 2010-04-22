#include "stdafx.h"
#include "ARLayoutProp.h"


IMPLEMENT_DYNAMIC(ARLayoutPropPage, CMFCBasePropertyPage)


void ARLayoutPropPage::DoDataExchange(CDataExchange* pDX)
{
	CMFCBasePropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ARLayoutPropPage, CMFCBasePropertyPage)

	ON_BN_CLICKED(IDC_BUTTON1, &ARLayoutPropPage::OnBnClickedButton1)
END_MESSAGE_MAP()


// CHomoWarpMFCPropertyPage message handlers


ARLayoutPropPage::ARLayoutPropPage(IUnknown *pUnk) : 
CMFCBasePropertyPage(NAME("ARLayoutPropPage"), pUnk),
m_pFilter(0)
{
}

ARLayoutPropPage::~ARLayoutPropPage()
{
	if (m_pFilter != NULL)
	{
		m_pFilter->Release();
		m_pFilter = NULL;
	}
}

//override CBasePropertyPage Method
HRESULT ARLayoutPropPage::OnConnect(IUnknown *pUnk)
{
	if (pUnk == NULL)
	{
		return E_POINTER;
	}
	if (m_pFilter == NULL)
	{
		pUnk->QueryInterface(IID_IARLayoutFilter, 
			reinterpret_cast<void**>(&m_pFilter));
		return S_OK;
	}
	return S_OK;
}
HRESULT ARLayoutPropPage::OnDisconnect(void)
{
	if (m_pFilter)
	{
		m_pFilter->Release();
		m_pFilter = NULL;
	}
	return S_OK;
}
BOOL ARLayoutPropPage::OnReceiveMessage(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	
	return TRUE;
}
HRESULT ARLayoutPropPage::OnActivate(void)
{
	if (m_pFilter == NULL)
	{
		::EnableWindow(this->GetSafeHwnd(), FALSE);
		return S_OK;
	}
	::EnableWindow(this->GetSafeHwnd(), TRUE);
	
	int numX = m_pFilter->getNumOfX();
	int numY = m_pFilter->getNumOfY();

	SetDlgItemInt(IDC_NumX,numX);
    SetDlgItemInt(IDC_NumY,numY);

	return S_OK;
}
HRESULT ARLayoutPropPage::OnApplyChanges(void)
{
	return S_OK;
}

CUnknown *WINAPI ARLayoutPropPage::CreateInstance(LPUNKNOWN punk, HRESULT *phr)
{
	ASSERT(phr);
	// assuming we don't want to modify the data
	ARLayoutPropPage *pNewObject = new ARLayoutPropPage(punk);

	if(pNewObject == NULL) {
		if (phr)
			*phr = E_OUTOFMEMORY;
	}

	return pNewObject;
}

void ARLayoutPropPage::OnBnClickedButton1()
{
	int numX = GetDlgItemInt(IDC_NumX);
	int numY = GetDlgItemInt(IDC_NumY);
	int tagSize = GetDlgItemInt(IDC_WIDTH);
	m_pFilter->setNumOfX(numX);
	m_pFilter->setNumOfY(numY);
}
