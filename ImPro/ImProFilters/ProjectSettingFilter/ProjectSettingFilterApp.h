// ProjectSettingFilter.h : main header file for the ProjectSettingFilter DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CProjectSettingFilterApp
// See ProjectSettingFilter.cpp for the implementation of this class
//
HMODULE GetModule();
class CProjectSettingFilterApp : public CWinApp
{
public:
	CProjectSettingFilterApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
