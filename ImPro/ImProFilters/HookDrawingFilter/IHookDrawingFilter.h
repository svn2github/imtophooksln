#pragma once
// {7F0E386C-4E82-4998-8B6C-32D7787C700E}
DEFINE_GUID(IID_IHookDrawingFilter, 
			0x7f0e386c, 0x4e82, 0x4998, 0x8b, 0x6c, 0x32, 0xd7, 0x78, 0x7c, 0x70, 0xe);

// {30A0104E-A12F-4238-9BA4-D195BA8FB58A}
DEFINE_GUID(CLSID_HookDrawingFilter, 
			0x30a0104e, 0xa12f, 0x4238, 0x9b, 0xa4, 0xd1, 0x95, 0xba, 0x8f, 0xb5, 0x8a);

// {C160BE7D-BF4C-4c6a-8403-16A333EF7BC8}
DEFINE_GUID(CLSID_HookDrawingPropPage, 
			0xc160be7d, 0xbf4c, 0x4c6a, 0x84, 0x3, 0x16, 0xa3, 0x33, 0xef, 0x7b, 0xc8);

MIDL_INTERFACE("7F0E386C-4E82-4998-8B6C-32D7787C700E")
IHookDrawingFilter: public IUnknown
{
public:
	virtual BOOL IsHooked();
	virtual HWND GetHookedWindow();
	virtual BOOL SetHookedWindow(HWND hwnd);
	virtual HRESULT CreateAdditionalTexture(UINT idx, UINT w, UINT h);
	virtual HRESULT CreateInTexture(UINT w, UINT h);
	virtual BOOL GetSourceResolution(UINT& w, UINT& h);
	virtual BOOL SetSourceResolution(UINT w, UINT h);
	virtual	BOOL CaptureHookWnd();
};
