// GSFrameCaptureFilter.h : main header file for the GSFrameCaptureFilter DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CGSFrameCaptureFilterApp
// See GSFrameCaptureFilter.cpp for the implementation of this class
//

class CGSFrameCaptureFilterApp : public CWinApp
{
public:
	CGSFrameCaptureFilterApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
