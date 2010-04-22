// MyTestFilter.h : main header file for the MyTestFilter DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMyTestFilterApp
// See MyTestFilter.cpp for the implementation of this class
//

class CMyTestFilterApp : public CWinApp
{
public:
	CMyTestFilterApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
