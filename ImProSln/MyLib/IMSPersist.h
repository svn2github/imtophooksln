#pragma once

class IMSPersist 
{
	virtual int GetNumInstance() = 0;
	virtual HRESULT GetInstance(UINT idx, IMSPersist*& pInst) = 0;
	virtual HRESULT SaveToFile(WCHAR* filename) = 0;
	virtual HRESULT LoadFromFile(WCHAR* filename) = 0;
};