#pragma once
// {D2547418-CD0E-F164-FE3C-36E1868AE047}
DEFINE_GUID(IID_IGSFrameCaptureFilter, 
			0xd2547418, 0xcd0e, 0xf164, 0xfe, 0x3c, 0x36, 0xe1, 0x86, 0x8a, 0xe0, 0x47);
// {5B8E4447-9C47-C966-A6DB-8B3BBC3C2AFE}
DEFINE_GUID(CLSID_GSFrameCaptureFilter, 
			0x5b8e4447, 0x9c47, 0xc966, 0xa6, 0xdb, 0x8b, 0x3b, 0xbc, 0x3c, 0x2a, 0xfeB);
// {5499D048-A573-2B81-EF4B-855069F3BBBC}
DEFINE_GUID(CLSID_GSFrameCaptureFilterProp, 
			0x5499d048, 0xa573, 0x2b81, 0xef, 0x4b, 0x85, 0x50, 0x69, 0xf3, 0xbb, 0xbc);



MIDL_INTERFACE("D2547418-CD0E-F164-FE3C-36E1868AE047")
IGSFrameCaptureFilter: public IUnknown
{
public:
	virtual void setIsSaveImg() ;
	virtual void resetSavingCount() ;
	virtual void setImgName(WCHAR* name) ;




};
