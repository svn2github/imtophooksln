#pragma once

// {787BA1EF-C5EF-428a-9129-354FDC0C8DAB}
DEFINE_GUID(IID_IBGMappingFilter, 
			0x787ba1ef, 0xc5ef, 0x428a, 0x91, 0x29, 0x35, 0x4f, 0xdc, 0xc, 0x8d, 0xab);
MIDL_INTERFACE("787BA1EF-C5EF-428a-9129-354FDC0C8DAB")

IBGMappingFilter: public IUnknown
{
public:
	virtual HRESULT setBGThreshold(int BGthres) ;
	virtual int getBGThreshold();
	virtual HRESULT setWhiteValue(int wValue) ;
	virtual int getWhiteValue();
	virtual HRESULT setBlackValue(int bValue) ;
	virtual int getBlackValue();

	virtual HRESULT setCamFlip(bool value) ;
	virtual bool getCamFlip();
	virtual HRESULT setLayoutFlip(bool value) ;
	virtual bool getLayoutFlip();
	virtual HRESULT setOutputFlip(bool value) ;
	virtual bool getOutputFlip();
};
