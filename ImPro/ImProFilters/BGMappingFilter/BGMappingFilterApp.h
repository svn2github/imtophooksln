// BGMappingFilter.h : main header file for the BGMappingFilter DLL
//

#pragma once

#ifndef __AFXWIN_H__
#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CBGMappingFilterApp
// See BGMappingFilter.cpp for the implementation of this class
//
HMODULE GetModule();
class CBGMappingFilterApp : public CWinApp
{
public:
	CBGMappingFilterApp();

	// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
