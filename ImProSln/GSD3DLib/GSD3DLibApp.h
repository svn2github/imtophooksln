// GSD3DLib.h : main header file for the GSD3DLib DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CGSD3DLibApp
// See GSD3DLib.cpp for the implementation of this class
//

class CGSD3DLibApp : public CWinApp
{
public:
	CGSD3DLibApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
