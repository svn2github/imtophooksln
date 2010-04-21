// TouchLibFilter.h : main header file for the TouchLibFilter DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CTouchLibFilterApp
// See TouchLibFilter.cpp for the implementation of this class
//

class CTouchLibFilterApp : public CWinApp
{
public:
	CTouchLibFilterApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
