// DCCaptureFilter.h : main header file for the DCCaptureFilter DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CDCCaptureFilterApp
// See DCCaptureFilter.cpp for the implementation of this class
//

class CDCCaptureFilterApp : public CWinApp
{
public:
	CDCCaptureFilterApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
