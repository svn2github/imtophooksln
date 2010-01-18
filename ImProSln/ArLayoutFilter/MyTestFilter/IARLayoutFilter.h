#pragma once

// {60428265-23E1-4551-B13A-6F6029B89D0B}
DEFINE_GUID(IID_IARLayoutFilter, 
			0x60428265, 0x23e1, 0x4551, 0xb1, 0x3a, 0x6f, 0x60, 0x29, 0xb8, 0x9d, 0xb);

MIDL_INTERFACE("60428265-23E1-4551-B13A-6F6029B89D0B")


IARLayoutFilter: public IUnknown
{
public:
	virtual int getNumOfX() ;
	virtual int getNumOfY() ;
	//virtual void setTagProp(int tagID,int posX, int posY, int width,bool isVisible);
	virtual HRESULT setNumOfX(int numX) ;
	virtual HRESULT setNumOfY(int numY) ;

};
