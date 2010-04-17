#pragma once
#include <d3d11.h>
#include <D3DX11.h>
#include <D3DX10Math.h>
#include "cv.h"
// {340E01BC-44CF-43ab-AA00-C5513A5444E7}
DEFINE_GUID(IID_IGSHomoWarpFilter, 
			0x340e01bc, 0x44cf, 0x43ab, 0xaa, 0x0, 0xc5, 0x51, 0x3a, 0x54, 0x44, 0xe7);

// {44D81154-CDC8-4cbd-A225-05925CE01088}
DEFINE_GUID(CLSID_GSHomoWarpFilter, 
			0x44d81154, 0xcdc8, 0x4cbd, 0xa2, 0x25, 0x5, 0x92, 0x5c, 0xe0, 0x10, 0x88);

// {A17054A8-46F4-4e20-AEBB-B1CE41232C85}
DEFINE_GUID(CLSID_GSHomoWarpFilterProp, 
			0xa17054a8, 0x46f4, 0x4e20, 0xae, 0xbb, 0xb1, 0xce, 0x41, 0x23, 0x2c, 0x85);



MIDL_INTERFACE("340E01BC-44CF-43ab-AA00-C5513A5444E7")
IGSHomoWarpFilter: public IUnknown
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

};
