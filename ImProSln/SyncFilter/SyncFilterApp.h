// SyncFilter.h : SyncFilter DLL ���D�n���Y��
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �]�t���ɮ׫e���]�t 'stdafx.h'"
#endif

#include "resource.h"		// �D�n�Ÿ�


// CSyncFilterApp
// �o�����O����@�аѾ\ SyncFilter.cpp
//

class CSyncFilterApp : public CWinApp
{
public:
	CSyncFilterApp();

// �мg
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
