#pragma once
#include <d3dx9.h>
#include "streams.h"
// {60ED1F46-5744-409c-B8B9-3824D1D7B8FE}
DEFINE_GUID(IID_IMaskFilter, 
			0x60ed1f46, 0x5744, 0x409c, 0xb8, 0xb9, 0x38, 0x24, 0xd1, 0xd7, 0xb8, 0xfe);

// {021720BF-468F-4b5e-B538-829A1EE57972}
DEFINE_GUID(CLSID_MaskFilter, 
			0x21720bf, 0x468f, 0x4b5e, 0xb5, 0x38, 0x82, 0x9a, 0x1e, 0xe5, 0x79, 0x72);

// {AE0C61A4-3FDE-441e-9DA1-300CB5B5AC92}
DEFINE_GUID(CLSID_MaskFilterProp, 
			0xae0c61a4, 0x3fde, 0x441e, 0x9d, 0xa1, 0x30, 0xc, 0xb5, 0xb5, 0xac, 0x92);


MIDL_INTERFACE("60ED1F46-5744-409c-B8B9-3824D1D7B8FE")
IMaskFilter: public IUnknown
{
public:
	virtual BOOL SetMaskFlag(int flag);
	virtual int GetMaskFlag();
	virtual BOOL LoadMaskFromFile(WCHAR* path);
};
