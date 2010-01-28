#include "stdafx.h"
#include "TouchLibFilterProp.h"
#include "TouchLibFilterApp.h"
extern CTouchLibFilterApp theApp;

IMPLEMENT_DYNAMIC(TouchLibPropPage, CMFCBasePropertyPage)
void TouchLibPropPage::DoDataExchange(CDataExchange* pDX)
{
	CMFCBasePropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edFingerMsg);
	DDX_Text(pDX, IDC_EDIT1, m_strFingerMsg);
	DDX_Control(pDX, IDC_CKSHOWMSG, m_ckShowMsg);
	DDX_Control(pDX, IDC_CKShowConfig, m_ckShowConfigWnd);
}


BEGIN_MESSAGE_MAP(TouchLibPropPage, CMFCBasePropertyPage)
	ON_BN_CLICKED(IDC_BTNCLEAR, &TouchLibPropPage::OnBnClickedBtnclear)
	ON_BN_CLICKED(IDC_CKSHOWMSG, &TouchLibPropPage::OnBnClickedCkshowmsg)
	ON_BN_CLICKED(IDC_CKShowConfig, &TouchLibPropPage::OnBnClickedCkshowconfig)
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
	EnableWindow(TRUE);
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
