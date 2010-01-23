#pragma once
// {7F0E386C-4E82-4998-8B6C-32D7787C700E}
DEFINE_GUID(IID_IHookDrawingFilter, 
			0x7f0e386c, 0x4e82, 0x4998, 0x8b, 0x6c, 0x32, 0xd7, 0x78, 0x7c, 0x70, 0xe);


MIDL_INTERFACE("7F0E386C-4E82-4998-8B6C-32D7787C700E")
IHookDrawingFilter: public IUnknown
{
public:
	virtual BOOL IsHooked();
	virtual HWND GetHookedWindow();
	virtual BOOL SetHookedWindow(HWND hwnd);
};
