#pragma once
#include "streams.h"
#include "IMSPersist.h"
// {F82B96A4-08A1-4b61-91AB-13D869E80393}
DEFINE_GUID(IID_IProjectSettingFilter, 
			0xf82b96a4, 0x8a1, 0x4b61, 0x91, 0xab, 0x13, 0xd8, 0x69, 0xe8, 0x3, 0x93);

// {E905B595-CF03-49da-AA9A-E626045DD727}
DEFINE_GUID(CLSID_ProjectSettingFilter, 
			0xe905b595, 0xcf03, 0x49da, 0xaa, 0x9a, 0xe6, 0x26, 0x4, 0x5d, 0xd7, 0x27);

// {43DB74F5-E60B-47c1-AE79-A1C1A8452654}
DEFINE_GUID(CLSID_ProjectSettingFilterProp, 
			0x43db74f5, 0xe60b, 0x47c1, 0xae, 0x79, 0xa1, 0xc1, 0xa8, 0x45, 0x26, 0x54);

MIDL_INTERFACE("F82B96A4-08A1-4b61-91AB-13D869E80393")
IProjectSettingFilter: public IUnknown
{
public:
	
};
