#pragma once
#include <initguid.h>

// {D4989B9C-752D-4c2d-8F7F-D4400570F493}
DEFINE_GUID(GUID_ARResult, 
			0xd4989b9c, 0x752d, 0x4c2d, 0x8f, 0x7f, 0xd4, 0x40, 0x5, 0x70, 0xf4, 0x93);

// {0FB35002-CD0B-46bd-ABE0-EDAA96F722EE}
DEFINE_GUID(GUID_ARLayoutConfigData, 
			0xfb35002, 0xcd0b, 0x46bd, 0xab, 0xe0, 0xed, 0xaa, 0x96, 0xf7, 0x22, 0xee);

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

class ARLayoutConfigData
{
public:
	ARMultiEachMarkerInfoT* m_ARMarkers;
	int m_numMarker;
	ARLayoutConfigData() : m_ARMarkers(NULL), m_numMarker(0)
	{	}
	~ARLayoutConfigData()
	{	
		if (m_ARMarkers != NULL)
		{
			delete[] m_ARMarkers;
			m_ARMarkers = NULL;
		}
	}

	ARLayoutConfigData& operator = (const ARLayoutConfigData &rhs)
	{
		if (m_ARMarkers != NULL)
		{
			delete [] m_ARMarkers;
			m_ARMarkers = NULL;
			this->m_numMarker = 0;
		}
		this->m_numMarker = rhs.m_numMarker;
		if (rhs.m_numMarker != 0)
		{
			this->m_ARMarkers = new ARMultiEachMarkerInfoT[rhs.m_numMarker];
			memcpy(this->m_ARMarkers, rhs.m_ARMarkers, sizeof(ARMultiEachMarkerInfoT)*rhs.m_numMarker);
		}
		return *this;
	}


};