#pragma once
#include <initguid.h>
#include "ARToolKitPlus/TrackerMultiMarker.h"
//#include "ARToolKitPlus/arMulti.h"
// {CCBA1F17-0B65-4b88-AE98-CF864D4EB425}
DEFINE_GUID(GUID_MyMediaSample, 
			0xccba1f17, 0xb65, 0x4b88, 0xae, 0x98, 0xcf, 0x86, 0x4d, 0x4e, 0xb4, 0x25);

// {547D0928-D9CE-4064-9D87-3ABE57333711}
DEFINE_GUID(GUID_WarpConfig, 
			0x547d0928, 0xd9ce, 0x4064, 0x9d, 0x87, 0x3a, 0xbe, 0x57, 0x33, 0x37, 0x11);

// {D4989B9C-752D-4c2d-8F7F-D4400570F493}
DEFINE_GUID(GUID_ARResult, 
			0xd4989b9c, 0x752d, 0x4c2d, 0x8f, 0x7f, 0xd4, 0x40, 0x5, 0x70, 0xf4, 0x93);

using namespace ARToolKitPlus;
class WarpConfigData
{
public:
	float warpMat[4][4];
};

class ARTagResultData
{
public:
	const ARMultiMarkerInfoT* m_pMarkerConfig;
	const int m_nDetected;
	const ARMarkerInfo* m_pDetectedMarks;
	const double* m_matARView;
	const double* m_matARProj;
	int m_screenW;
	int m_screenH; 
public:
	ARTagResultData();
	ARTagResultData(const ARMultiMarkerInfoT* pMarkerConfig, const int nDetected,
		const ARMarkerInfo* pDetectedMarks, const double* matARView, const double* matARProj);
	~ARTagResultData();
};