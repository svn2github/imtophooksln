// AR2WarpController.h : main header file for the AR2WarpController DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CAR2WarpControllerApp
// See AR2WarpController.cpp for the implementation of this class
//
HMODULE GetModule();
class CAR2WarpControllerApp : public CWinApp
{
public:
	CAR2WarpControllerApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
