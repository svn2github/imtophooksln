#include "stdafx.h"
#include "GSCommonLib.h"


CCritSec* GSCritSec::GetCritSec() 
{ 
	return &m_CritSec;
}

void GSCritSec::Lock()
{
	m_CritSec.Lock();
}

void GSCritSec::Unlock()
{
	m_CritSec.Unlock();
}

GSCritSecBase::GSCritSecBase() 
{ 
	m_pGSCritSec = NULL; 
	m_pGSCritSec = new GSCritSec();
}
GSCritSecBase::~GSCritSecBase() 
{ 
	SAFE_RELEASE(m_pGSCritSec);
}
GSCritSec* GSCritSecBase::GetGSCritSec() 
{ 
	return m_pGSCritSec;
};

GSAutoLock::GSAutoLock(GSCritSec * plock)
{
	m_pLock = plock;
	SAFE_ADDREF(m_pLock);
	m_pLock->Lock();
};

GSAutoLock::~GSAutoLock() {
	m_pLock->Unlock();
	SAFE_RELEASE(m_pLock);
};

GSRefCount::GSRefCount()
{
	m_nRef = 1;
}
GSRefCount::~GSRefCount()
{
}
ULONG GSRefCount::AddRef()
{
	return ++m_nRef;
}

ULONG GSRefCount::Release()
{
	if (--m_nRef > 0)
	{
		return m_nRef;
	}
	else
	{
		delete this;
	}
	return 0;
}
