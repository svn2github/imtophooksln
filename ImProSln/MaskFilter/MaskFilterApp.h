// MaskFilter.h : main header file for the MaskFilter DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMaskFilterApp
// See MaskFilter.cpp for the implementation of this class
//
HMODULE GetModule();
class CMaskFilterApp : public CWinApp
{
public:
	CMaskFilterApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
