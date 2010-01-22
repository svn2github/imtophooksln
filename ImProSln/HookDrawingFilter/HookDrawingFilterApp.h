// HookDrawingFilter.h : main header file for the HookDrawingFilter DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CHookDrawingFilterApp
// See HookDrawingFilter.cpp for the implementation of this class
//

class CHookDrawingFilterApp : public CWinApp
{
public:
	CHookDrawingFilterApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
