// DXBlendFilter.h : main header file for the DXBlendFilter DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CDXBlendFilterApp
// See DXBlendFilter.cpp for the implementation of this class
//
HMODULE GetModule();
class CDXBlendFilterApp : public CWinApp
{
public:
	CDXBlendFilterApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
