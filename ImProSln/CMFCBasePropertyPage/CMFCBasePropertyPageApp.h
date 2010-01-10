// CMFCBasePropertyPage.h : main header file for the CMFCBasePropertyPage DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CCMFCBasePropertyPageApp
// See CMFCBasePropertyPage.cpp for the implementation of this class
//

class CCMFCBasePropertyPageApp : public CWinApp
{
public:
	CCMFCBasePropertyPageApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
