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
// {06F71C44-D839-4948-B5AB-F161BF157AEB}
DEFINE_GUID(IID_IARLayoutDXFilter, 
			0x6f71c44, 0xd839, 0x4948, 0xb5, 0xab, 0xf1, 0x61, 0xbf, 0x15, 0x7a, 0xeb);

MIDL_INTERFACE("06F71C44-D839-4948-B5AB-F161BF157AEB")

IARLayoutDXFilter: public IUnknown
{
public:

};