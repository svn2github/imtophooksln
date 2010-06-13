// GSARTagLayoutFilter.h : main header file for the GSARTagLayoutFilter DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CGSARTagLayoutFilterApp
// See GSARTagLayoutFilter.cpp for the implementation of this class
//

class CGSARTagLayoutFilterApp : public CWinApp
{
public:
	CGSARTagLayoutFilterApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
