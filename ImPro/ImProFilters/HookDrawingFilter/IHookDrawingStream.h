#pragma once
#include <d3dx9.h>
#include <d3dx9math.h>
// {E8CE80E8-D089-43b8-A201-3D0E322A09B7}
DEFINE_GUID(IID_IHookDrawingStream, 
			0xe8ce80e8, 0xd089, 0x43b8, 0xa2, 0x1, 0x3d, 0xe, 0x32, 0x2a, 0x9, 0xb7);

// {ABD0634D-075F-4f30-8040-67C8703D8DA7}
DEFINE_GUID(CLSID_HookDrawingStreamPropPage, 
			0xabd0634d, 0x75f, 0x4f30, 0x80, 0x40, 0x67, 0xc8, 0x70, 0x3d, 0x8d, 0xa7);


MIDL_INTERFACE("E8CE80E8-D089-43b8-A201-3D0E322A09B7")
IHookDrawingStream: public IUnknown
{
public:
	virtual const D3DXMATRIX* GetWarpMatrix();
	virtual BOOL SetWarpMatrix(const D3DXMATRIX& mat);
	virtual BOOL SetWarpByPts(const D3DXVECTOR2& lt, const D3DXVECTOR2& lb,
		const D3DXVECTOR2& rb, const D3DXVECTOR2& rt);
	virtual BOOL GetWarpPts(D3DXVECTOR2& lt, D3DXVECTOR2& lb, D3DXVECTOR2& rb, 
		D3DXVECTOR2& rt);

	virtual BOOL GetResolution(UINT& resW, UINT& resH);
	virtual BOOL SetResolution(UINT resW, UINT resH);
	virtual float GetFrameRate();
	virtual BOOL SetFrameRate(float fps);
};
