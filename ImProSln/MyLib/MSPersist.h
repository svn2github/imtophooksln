// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the MSPERSIST_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// MSPERSIST_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#pragma once

#include "IMSPersist.h"
// This class is exported from the MSPersist.dll
class MSPERSIST_API CMSPersist : public IMSPersist
{
public:
	CMSPersist(void);
	~CMSPersist();
	virtual int GetNumPersistInstance();
	virtual HRESULT GetPersistInstance(UINT idx, IMSPersist*& pInst);
	virtual HRESULT SaveToFile(WCHAR* filename) = 0;
	virtual HRESULT LoadFromFile(WCHAR* filename) = 0;
	virtual HRESULT GetName(WCHAR* name, UINT szName) = 0;
};
