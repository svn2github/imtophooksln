// ARTagPropertyDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ARTagFilter.h"
#include "ARTagPropertyDlg.h"


// ARTagPropertyDlg dialog

IMPLEMENT_DYNAMIC(ARTagPropertyDlg, CDialog)

ARTagPropertyDlg::ARTagPropertyDlg(CWnd* pParent /*=NULL*/)
	: CDialog()
{
	
}

ARTagPropertyDlg::~ARTagPropertyDlg()
{
}

void ARTagPropertyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ARTagPropertyDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &ARTagPropertyDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// ARTagPropertyDlg message handlers

void ARTagPropertyDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	OutputDebugStringW(L"@@@@@ ARTagPropertyDlg::OnBnClickedButton1 called!!");
}
