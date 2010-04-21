#pragma once
#include "streams.h"
#ifdef MSPERSIST_EXPORTS
#define MSPERSIST_API __declspec(dllexport)
#else
#define MSPERSIST_API __declspec(dllimport)
#endif
// {E46638C6-5A96-4e8b-B6BB-E10D36A4FE88}
DEFINE_GUID(IID_IMSPersist, 
			0xe46638c6, 0x5a96, 0x4e8b, 0xb6, 0xbb, 0xe1, 0xd, 0x36, 0xa4, 0xfe, 0x88);
MIDL_INTERFACE("E46638C6-5A96-4e8b-B6BB-E10D36A4FE88")
IMSPersist : public IUnknown
{
public:
	virtual int GetNumPersistInstance() = 0;
	virtual HRESULT GetPersistInstance(UINT idx, IMSPersist*& pInst) = 0;
	virtual HRESULT SaveToFile(WCHAR* filename) = 0;
	virtual HRESULT LoadFromFile(WCHAR* filename) = 0;
	virtual HRESULT GetName(WCHAR* name, UINT szName) = 0;
};