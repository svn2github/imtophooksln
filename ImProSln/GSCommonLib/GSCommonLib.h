#pragma once
#include "IGSCommonLib.h"
#include "streams.h"
#include "GSMacro.h"
class GSRefCount : public IGSRefCount
{
protected:
	int m_nRef;
public:
	GSRefCount();
	virtual ~GSRefCount();
	unsigned long AddRef();
	unsigned long Release();
};

class GSCritSec : public GSRefCount
{
protected:
	CCritSec m_CritSec;
public:
	CCritSec* GetCritSec();
	void Lock();
	void Unlock();
};

class GSCritSecBase 
{
protected:
	GSCritSec* m_pGSCritSec;
public:
	GSCritSecBase(); 
	~GSCritSecBase(); 
	GSCritSec* GetGSCritSec();// need to Release 
};

class GSAutoLock {
protected:
	GSCritSec *m_pLock;

public:
	GSAutoLock(GSCritSec * plock);
	~GSAutoLock();
};
