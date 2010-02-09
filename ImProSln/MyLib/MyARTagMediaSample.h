#pragma once
#include <initguid.h>

// {D4989B9C-752D-4c2d-8F7F-D4400570F493}
DEFINE_GUID(GUID_ARResult, 
			0xd4989b9c, 0x752d, 0x4c2d, 0x8f, 0x7f, 0xd4, 0x40, 0x5, 0x70, 0xf4, 0x93);

#include "ARToolKitPlus/TrackerMultiMarker.h"
using namespace ARToolKitPlus;
class ARTagResultData
{
public:
	const ARMultiMarkerInfoT* m_pMarkerConfig;
	const int m_nDetected;
	const ARMarkerInfo* m_pDetectedMarks;
	const double* m_matARView;
	const double* m_matARProj;
	double m_basisScale[3];
	int m_screenW;
	int m_screenH; 
public:
	ARTagResultData();
	ARTagResultData(const ARMultiMarkerInfoT* pMarkerConfig, const int nDetected,
		const ARMarkerInfo* pDetectedMarks, const double* matARView, const double* matARProj);
	~ARTagResultData();
};