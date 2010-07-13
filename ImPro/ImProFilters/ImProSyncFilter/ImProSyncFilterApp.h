// ImProSyncFilter.h : main header file for the ImProSyncFilter DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CImProSyncFilterApp
// See ImProSyncFilter.cpp for the implementation of this class
//

class CImProSyncFilterApp : public CWinApp
{
public:
	CImProSyncFilterApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
