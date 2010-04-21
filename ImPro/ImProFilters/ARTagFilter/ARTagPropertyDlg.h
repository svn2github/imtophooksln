#pragma once


// ARTagPropertyDlg dialog
#include "resource.h"
class ARTagPropertyDlg : public CDialog
{
	DECLARE_DYNAMIC(ARTagPropertyDlg)

public:
	ARTagPropertyDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~ARTagPropertyDlg();

// Dialog Data
	enum { IDD = IDD_ARTag_PROPPAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
