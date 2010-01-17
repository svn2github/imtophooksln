#include "MyMediaSample.h"

ARTagResultData::ARTagResultData(const ARMultiMarkerInfoT* pMarkerConfig, const int nDetected,
				const ARMarkerInfo* pDetectedMarks, const double* matARView, const double* matARProj)
				: m_pMarkerConfig(pMarkerConfig), m_nDetected(nDetected), 
				m_pDetectedMarks(pDetectedMarks), m_matARView(matARView), m_matARProj(matARProj)
{
	m_screenW = 0;
	m_screenH = 0; 
}
ARTagResultData::~ARTagResultData()
{

}