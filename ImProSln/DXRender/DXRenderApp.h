// DXRender.h : main header file for the DXRender DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CDXRenderApp
// See DXRender.cpp for the implementation of this class
//

class CDXRenderApp : public CWinApp
{
public:
	CDXRenderApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
