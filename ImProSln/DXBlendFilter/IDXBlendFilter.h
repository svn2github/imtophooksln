#pragma once
#include "cv.h"
// {BEE0CA6B-0635-4487-AA1F-CF6DD16A9DBE}
DEFINE_GUID(IID_IDXBlendFilter, 
			0xbee0ca6b, 0x635, 0x4487, 0xaa, 0x1f, 0xcf, 0x6d, 0xd1, 0x6a, 0x9d, 0xbe);
// {99EC0D77-BA38-483d-B76B-CB6806ED1791}
DEFINE_GUID(CLSID_DXBlendFilter, 
			0x99ec0d77, 0xba38, 0x483d, 0xb7, 0x6b, 0xcb, 0x68, 0x6, 0xed, 0x17, 0x91);

// {15E111A9-6464-484f-A89A-655CF205ADEE}
DEFINE_GUID(CLSID_DXBlendFilterProp, 
			0x15e111a9, 0x6464, 0x484f, 0xa8, 0x9a, 0x65, 0x5c, 0xf2, 0x5, 0xad, 0xee);

MIDL_INTERFACE("BEE0CA6B-0635-4487-AA1F-CF6DD16A9DBE")
IDXBlendFilter: public IUnknown
{
public:
	virtual HRESULT LoadWeightMap(int idx, WCHAR* path) = 0;
	virtual HRESULT GetWeightMapPath(int idx, WCHAR* path) = 0;
	virtual HRESULT GetCloneWeightMap(int idx, IplImage*& pImg) = 0;
};
