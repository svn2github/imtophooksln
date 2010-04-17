// GSHomoWarpFilter.h : main header file for the GSHomoWarpFilter DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CGSHomoWarpFilterApp
// See GSHomoWarpFilter.cpp for the implementation of this class
//

class CGSHomoWarpFilterApp : public CWinApp
{
public:
	CGSHomoWarpFilterApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
