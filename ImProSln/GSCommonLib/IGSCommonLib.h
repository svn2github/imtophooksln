#pragma once
class IGSRefCount
{
public:
	virtual unsigned long AddRef() = 0;
	virtual unsigned long Release() = 0;
};