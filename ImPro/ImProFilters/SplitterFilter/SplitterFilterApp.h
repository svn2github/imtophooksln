// SplitterFilter.h : main header file for the SplitterFilter DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CSplitterFilterApp
// See SplitterFilter.cpp for the implementation of this class
//

HMODULE GetModule();


class CSplitterFilterApp : public CWinApp
{
public:
	CSplitterFilterApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
