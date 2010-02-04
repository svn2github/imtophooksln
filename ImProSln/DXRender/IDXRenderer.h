#pragma once

// {5AE768BF-3EFB-418f-BFA4-4974586AC071}
DEFINE_GUID(IID_IDXRenderer, 
			0x5ae768bf, 0x3efb, 0x418f, 0xbf, 0xa4, 0x49, 0x74, 0x58, 0x6a, 0xc0, 0x71);


MIDL_INTERFACE("5AE768BF-3EFB-418f-BFA4-4974586AC071")
IDXRenderer: public IUnknown
{
	virtual HWND GetDisplayWindow();
};