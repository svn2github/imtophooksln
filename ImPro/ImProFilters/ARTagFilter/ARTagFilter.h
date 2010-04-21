// ARTagFilter.h : main header file for the ARTagFilter DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols

#include <d3d9.h>
// CARTagFilterApp
// See ARTagFilter.cpp for the implementation of this class
//

HMODULE GetModule();

class CARTagFilterApp : public CWinApp
{
public:
	CARTagFilterApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

