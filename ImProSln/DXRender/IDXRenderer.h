#pragma once

// {5AE768BF-3EFB-418f-BFA4-4974586AC071}
DEFINE_GUID(IID_IDXRenderer, 
			0x5ae768bf, 0x3efb, 0x418f, 0xbf, 0xa4, 0x49, 0x74, 0x58, 0x6a, 0xc0, 0x71);

DEFINE_GUID(CLSID_DXRenderPropPage, 
			0xd99b1e26, 0x91d6, 0x4c4e, 0xb6, 0x6f, 0x71, 0xaa, 0xd8, 0xe6, 0x1, 0xcc);

// {9CE5FC93-4F69-4498-94B7-9CF1D0C8CA15}
DEFINE_GUID(CLSID_DXRenderFilter, 
			0x9ce5fc93, 0x4f69, 0x4498, 0x94, 0xb7, 0x9c, 0xf1, 0xd0, 0xc8, 0xca, 0x15);

MIDL_INTERFACE("5AE768BF-3EFB-418f-BFA4-4974586AC071")
IDXRenderer: public IUnknown
{
	virtual HWND GetDisplayWindow();
	virtual int  GetSampleType();
	virtual bool SetSampleType(int v);
	virtual bool GetFlipX();
	virtual bool SetFlipX(bool v);
	virtual bool GetFlipY();
	virtual bool SetFlipY(bool v);
	virtual bool GetbDrawFPS();
	virtual bool SetbDrawFPS(bool v);

	virtual BOOL IsWindowZoom();
	virtual HRESULT GetWindowRect(RECT& rect);
	virtual HRESULT SetWindowRect(RECT rect);
	virtual HRESULT SetWindowZoom(BOOL bZoom);
	virtual BOOL SetHideBorder(BOOL bHideBorder);
	virtual BOOL IsHideBorder();

	virtual DWORD GetProcessPriority();
	virtual BOOL SetProcessPriority(DWORD dwPriorityClass);
	virtual BOOL GetRenderThreadPriority(int& nPriority);
	virtual BOOL SetRenderThreadPriority(int nPriority);

};