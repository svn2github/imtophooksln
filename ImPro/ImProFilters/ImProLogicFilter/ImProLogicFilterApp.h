// ImProLogicFilter.h : main header file for the ImProLogicFilter DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CImProLogicFilterApp
// See ImProLogicFilter.cpp for the implementation of this class
//

class CImProLogicFilterApp : public CWinApp
{
public:
	CImProLogicFilterApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
