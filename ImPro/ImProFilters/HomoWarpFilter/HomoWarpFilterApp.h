// HomoWarpFilter.h : main header file for the HomoWarpFilter DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CHomoWarpFilterApp
// See HomoWarpFilter.cpp for the implementation of this class
//
HMODULE GetModule();
class CHomoWarpFilterApp : public CWinApp
{
public:
	CHomoWarpFilterApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
