#pragma once
#include <d3dx9.h>
#include "cv.h"
#include "streams.h"
// {39D3E390-A98E-45ee-B496-ED6C69283C79}
DEFINE_GUID(IID_IHomoWarpFilter, 
			0x39d3e390, 0xa98e, 0x45ee, 0xb4, 0x96, 0xed, 0x6c, 0x69, 0x28, 0x3c, 0x79);
// {B2D25611-792D-44b4-BF50-4440E3BC647A}
DEFINE_GUID(CLSID_HomoWarpFilter, 
			0xb2d25611, 0x792d, 0x44b4, 0xbf, 0x50, 0x44, 0x40, 0xe3, 0xbc, 0x64, 0x7a);

DEFINE_GUID(CLSID_HomoWarpFilterPropertyPage, 
			0xf3dbd46e, 0x12c6, 0x4652, 0x9a, 0x2e, 0x6, 0x3a, 0xc6, 0x23, 0xe8, 0x46);


MIDL_INTERFACE("39D3E390-A98E-45ee-B496-ED6C69283C79")
IHomoWarpFilter: public IUnknown
{
public:
	virtual HRESULT SetWarpVertex(float LTx, float LTy, float LBx, float LBy, 
		float RBx, float RBy, float RTx, float RTy);
	virtual HRESULT GetWarpVertex(float& LTx, float& LTy, float& LBx, float& LBy, 
		float& RBx, float& RBy, float& RTx, float& RTy);
	virtual HRESULT SetWarpMatrix(const D3DXMATRIX& mat);
	virtual HRESULT GetWarpMatrix(D3DXMATRIX& mat);

	virtual bool GetIsFlipY();
	virtual bool SetIsFlipY(bool bFlipY);
	virtual bool GetIsInvWarp();
	virtual bool SetIsInvWarp(bool bInv);

	virtual bool SaveConfigToFile(WCHAR* path);
	virtual bool LoadConfigFromFile(WCHAR* path);
	
	virtual IplImage* GetInIplmage();
	virtual CCritSec* GetD3DCS();

	
};
