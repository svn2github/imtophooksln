#pragma once
// {39D3E390-A98E-45ee-B496-ED6C69283C79}
DEFINE_GUID(IID_IHomoWarpFilter, 
			0x39d3e390, 0xa98e, 0x45ee, 0xb4, 0x96, 0xed, 0x6c, 0x69, 0x28, 0x3c, 0x79);


MIDL_INTERFACE("39D3E390-A98E-45ee-B496-ED6C69283C79")
IHomoWarpFilter: public IUnknown
{
public:
	virtual HRESULT SetWarpVertex(float LTx, float LTy, float LBx, float LBy, 
		float RBx, float RBy, float RTx, float RTy);
	virtual HRESULT GetWarpVertex(float& LTx, float& LTy, float& LBx, float& LBy, 
		float& RBx, float& RBy, float& RTx, float& RTy);
};

