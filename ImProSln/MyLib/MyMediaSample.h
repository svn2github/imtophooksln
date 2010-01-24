#pragma once
#include <initguid.h>

//#include "ARToolKitPlus/arMulti.h"
// {CCBA1F17-0B65-4b88-AE98-CF864D4EB425}
DEFINE_GUID(GUID_MyMediaSample, 
			0xccba1f17, 0xb65, 0x4b88, 0xae, 0x98, 0xcf, 0x86, 0x4d, 0x4e, 0xb4, 0x25);

// {547D0928-D9CE-4064-9D87-3ABE57333711}
DEFINE_GUID(GUID_WarpConfig, 
			0x547d0928, 0xd9ce, 0x4064, 0x9d, 0x87, 0x3a, 0xbe, 0x57, 0x33, 0x37, 0x11);

// {619A00B3-63BF-430c-93A5-01A73235BDCA}
DEFINE_GUID(GUID_D3DXTEXTURE9_POINTER, 
			0x619a00b3, 0x63bf, 0x430c, 0x93, 0xa5, 0x1, 0xa7, 0x32, 0x35, 0xbd, 0xca);

// {F6DE4088-A0E1-49f9-9401-34576F948052}
DEFINE_GUID(GUID_FORMATTYPE_D3DXTEXTURE9DESC, 
			0xf6de4088, 0xa0e1, 0x49f9, 0x94, 0x1, 0x34, 0x57, 0x6f, 0x94, 0x80, 0x52);


class WarpConfigData
{
public:
	float warpMat[4][4];
};
