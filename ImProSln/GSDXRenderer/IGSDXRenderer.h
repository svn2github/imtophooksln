#pragma once


// {68AD9452-985D-4dda-BFC3-F8EF156646D9}
DEFINE_GUID(IID_IGSDXRenderer, 
			0x68ad9452, 0x985d, 0x4dda, 0xbf, 0xc3, 0xf8, 0xef, 0x15, 0x66, 0x46, 0xd9);

// {E882AFB4-640F-41bb-BE44-2C1B2E04D38C}
DEFINE_GUID(CLSID_GSDXRenderer, 
			0xe882afb4, 0x640f, 0x41bb, 0xbe, 0x44, 0x2c, 0x1b, 0x2e, 0x4, 0xd3, 0x8c);

MIDL_INTERFACE("68AD9452-985D-4dda-BFC3-F8EF156646D9")
IGSDXRenderer: public IUnknown
{
	virtual HWND GetDisplayWindow();

	virtual BOOL IsWindowZoom();
	virtual HRESULT GetWindowRect(RECT& rect);
	virtual HRESULT SetWindowRect(RECT rect);
	virtual HRESULT SetWindowZoom(BOOL bZoom);
	virtual BOOL SetHideBorder(BOOL bHideBorder);
	virtual BOOL IsHideBorder();

};