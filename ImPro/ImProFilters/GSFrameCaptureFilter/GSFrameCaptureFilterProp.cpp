#include "stdafx.h"
#include "GSFrameCaptureFilterProp.h"
#include "GSFrameCaptureFilterApp.h"


IMPLEMENT_DYNAMIC(GSFrameCaptureFilterProp, GSMFCProp)

extern CGSFrameCaptureFilterApp theApp;

void GSFrameCaptureFilterProp::DoDataExchange(CDataExchange* pDX)
{
	__super::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_btnSaveImg, m_btnSaveImg);
	DDX_Control(pDX, IDC_EDT_Name, m_edt_name);
	DDX_Control(pDX, IDC_Btn_Reset, m_btn_reset);
}
BOOL GSFrameCaptureFilterProp::OnInitDialog()
{
	BOOL ret = __super::OnInitDialog();

	return ret;
}

BEGIN_MESSAGE_MAP(GSFrameCaptureFilterProp, GSMFCProp)
	ON_BN_CLICKED(IDC_btnSaveImg, &GSFrameCaptureFilterProp::OnBnClickedbtnsaveimg)
	ON_BN_CLICKED(IDC_Btn_Reset, &GSFrameCaptureFilterProp::OnBnClickedBtnReset)
	ON_EN_CHANGE(IDC_EDT_Name, &GSFrameCaptureFilterProp::OnEnChangeEdtName)
END_MESSAGE_MAP()




GSFrameCaptureFilterProp::GSFrameCaptureFilterProp(IUnknown *pUnk) : 
GSMFCProp(NAME("GSFrameCaptureFilterProp"), pUnk),
m_pFilter(0)
{
}

GSFrameCaptureFilterProp::~GSFrameCaptureFilterProp()
{
	if (m_pFilter != NULL)
	{
		m_pFilter->Release();
		m_pFilter = NULL;
	}
}

//override CBasePropertyPage Method
HRESULT GSFrameCaptureFilterProp::OnConnect(IUnknown *pUnk)
{
	//override CBasePropertyPage Method
	if (pUnk == NULL)
	{
		return E_POINTER;
	}
	if (m_pFilter == NULL)
	{
		pUnk->QueryInterface(IID_IGSFrameCaptureFilter, 
			reinterpret_cast<void**>(&m_pFilter));
		return S_OK;
	}
	return S_OK;
}
HRESULT GSFrameCaptureFilterProp::OnDisconnect(void)
{
	if (m_pFilter != NULL)
	{
		m_pFilter->Release();
		m_pFilter = NULL;
	}
	return S_OK;
}
BOOL GSFrameCaptureFilterProp::OnReceiveMessage(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return TRUE;
}
HRESULT GSFrameCaptureFilterProp::OnActivate(void)
{
	if (m_pFilter != NULL)
		EnableWindow(TRUE);
	else
		EnableWindow(FALSE);

	

	return S_OK;
}
HRESULT GSFrameCaptureFilterProp::OnApplyChanges(void)
{
	return S_OK;
}

CUnknown *WINAPI GSFrameCaptureFilterProp::CreateInstance(LPUNKNOWN punk, HRESULT *phr)
{
	ASSERT(phr);
	// assuming we don't want to modify the data
	GSFrameCaptureFilterProp *pNewObject = new GSFrameCaptureFilterProp(punk);

	if(pNewObject == NULL) {
		if (phr)
			*phr = E_OUTOFMEMORY;
	}

	return pNewObject;
}

void GSFrameCaptureFilterProp::OnBnClickedbtnsaveimg()
{
	WCHAR* wtmpName;

	CString csFileName;	
	m_edt_name.GetWindowText(csFileName);

	
	wtmpName=csFileName.GetBuffer(0);
	
	int size= wcslen(wtmpName);
	
	m_pFilter->setImgName(wtmpName);
	m_pFilter->setIsSaveImg();
	
}

void GSFrameCaptureFilterProp::OnBnClickedBtnReset()
{
	m_pFilter->resetSavingCount();
}

void GSFrameCaptureFilterProp::OnEnChangeEdtName()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the GSMFCProp::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}
