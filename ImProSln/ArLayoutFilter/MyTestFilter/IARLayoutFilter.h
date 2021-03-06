#pragma once
// {60428265-23E1-4551-B13A-6F6029B89D0B}
DEFINE_GUID(IID_IARLayoutFilter, 
			0x60428265, 0x23e1, 0x4551, 0xb1, 0x3a, 0x6f, 0x60, 0x29, 0xb8, 0x9d, 0xb);

// {6B6AFF82-D374-40f5-9F77-C1652EB512CF}
DEFINE_GUID(CLSID_ARLayoutFilter, 
			0x6b6aff82, 0xd374, 0x40f5, 0x9f, 0x77, 0xc1, 0x65, 0x2e, 0xb5, 0x12, 0xcf);

// {5CDCA877-D333-43f4-839F-C74ADDF9E188}
DEFINE_GUID(CLSID_ARLayoutPropPage, 
			0x5cdca877, 0xd333, 0x43f4, 0x83, 0x9f, 0xc7, 0x4a, 0xdd, 0xf9, 0xe1, 0x88);


// {06F71C44-D839-4948-B5AB-F161BF157AEB}
DEFINE_GUID(IID_IARLayoutDXFilter, 
			0x6f71c44, 0xd839, 0x4948, 0xb5, 0xab, 0xf1, 0x61, 0xbf, 0x15, 0x7a, 0xeb);

#include "MyMediaSample.h"

#include "ARToolKitPlus/TrackerMultiMarker.h"
using namespace ARToolKitPlus;

MIDL_INTERFACE("06F71C44-D839-4948-B5AB-F161BF157AEB")

IARLayoutDXFilter: public IUnknown
{
public:
	virtual bool LoadConfigFromFile(WCHAR* filename);
	virtual bool SaveConfigToFile(WCHAR* filename);
	virtual bool DecideLayout(fRECT* camRects, UINT numCamRect,
		fRECT* fingerRects, UINT numFingerRects, bool& bLayoutChanged, float fingerExtend = 0.07);
	virtual bool initARMarkers(UINT numLevel = 2, UINT intMarkerBits = 8, UINT intBorderBits = 2, float intWidthBits = 80);
	virtual int GetNumMarker();
	virtual bool SetMarkerVisible(int idx, bool bVisible);
	virtual bool SetMarkerVisibleByID(int id, bool bVisible);
	virtual int GetMarkerID(int idx);
	
	virtual HRESULT GetARLayoutConfig(ARMultiEachMarkerInfoT* ARConfig);
	virtual int GetARLayoutSize() ;

	virtual BOOL SetFrameRate(float fps);
	virtual float GetFrameRate();
	
};