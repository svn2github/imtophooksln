// CMuxTransformFilter.h : main header file for the CMuxTransformFilter DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CCMuxTransformFilterApp
// See CMuxTransformFilter.cpp for the implementation of this class
//

class CCMuxTransformFilterApp : public CWinApp
{
public:
	CCMuxTransformFilterApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
