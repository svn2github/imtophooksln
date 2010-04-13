// GSDXRenderer.h : main header file for the GSDXRenderer DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CGSDXRendererApp
// See GSDXRenderer.cpp for the implementation of this class
//

class CGSDXRendererApp : public CWinApp
{
public:
	CGSDXRendererApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
