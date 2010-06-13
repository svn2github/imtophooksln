#include <InitGuid.h>
#include "MyARTagMediaSample.h"


ARTagResultData::ARTagResultData(const ARMultiMarkerInfoT* pMarkerConfig, const int nDetected,
								 const ARMarkerInfo* pDetectedMarks, const double* matARView, const double* matARProj)
								 : m_pMarkerConfig(pMarkerConfig), m_nDetected(nDetected), 
								 m_pDetectedMarks(pDetectedMarks), m_matARView(matARView), m_matARProj(matARProj)
{
	m_screenW = 0;
	m_screenH = 0; 
	m_basisScale[0] = 1.0; m_basisScale[1] = 1.0; m_basisScale[2] = 1.0;
}
ARTagResultData::~ARTagResultData()
{

}


ARLayoutConfigData::ARLayoutConfigData() : m_ARMarkers(NULL), m_numMarker(0)
{	}

ARLayoutConfigData::ARLayoutConfigData(const ARLayoutConfigData &rhs)
{
	this->m_numMarker = rhs.m_numMarker;
	if (rhs.m_numMarker != 0)
	{
		this->m_ARMarkers = new ARMultiEachMarkerInfoT[rhs.m_numMarker];
		memcpy(this->m_ARMarkers, rhs.m_ARMarkers, sizeof(ARMultiEachMarkerInfoT)*rhs.m_numMarker);
	}
}
ARLayoutConfigData::~ARLayoutConfigData()
{	
	if (m_ARMarkers != NULL)
	{
		delete[] m_ARMarkers;
		m_ARMarkers = NULL;
	}
}

ARLayoutConfigData& ARLayoutConfigData::operator = (const ARLayoutConfigData &rhs)
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
