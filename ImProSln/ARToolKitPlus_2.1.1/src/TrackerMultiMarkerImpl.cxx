/* ========================================================================
 * PROJECT: ARToolKitPlus
 * ========================================================================
 * This work is based on the original ARToolKit developed by
 *   Hirokazu Kato
 *   Mark Billinghurst
 *   HITLab, University of Washington, Seattle
 * http://www.hitl.washington.edu/artoolkit/
 *
 * Copyright of the derived and new portions of this work
 *     (C) 2006 Graz University of Technology
 *
 * This framework is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This framework is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this framework; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * For further information please contact 
 *   Dieter Schmalstieg
 *   <schmalstieg@icg.tu-graz.ac.at>
 *   Graz University of Technology, 
 *   Institut for Computer Graphics and Vision,
 *   Inffeldgasse 16a, 8010 Graz, Austria.
 * ========================================================================
 ** @author   Daniel Wagner
 *
 * $Id: TrackerMultiMarkerImpl.cxx 164 2006-05-02 11:29:10Z daniel $
 * @file
 * ======================================================================== */
#include "ARToolKitPlus/TrackerMultiMarkerImpl.h"

#ifndef __ARTOOLKITPLUS_TRACKERMULTIMARKERIMPL_HEADERFILE__
#error ARToolKitPlus/TrackerMultiMarkerImpl.cxx should not be compiled directly, but only if included from ARToolKitPlus/TrackerMultiMarkerImpl.h
#endif


namespace ARToolKitPlus
{


ARMM_TEMPL_FUNC
ARMM_TEMPL_TRACKER::TrackerMultiMarkerImpl(int nWidth, int nHeight)
{
	this->logger = NULL;
	for (int i =0; i <3; i++)
		m_basisScale[i] = 1;


	this->screenWidth = nWidth;
	this->screenHeight = nHeight;

	useDetectLite = true;
	numDetected = 0;
	m_numLastDetected = 0;

	config = 0;

	this->thresh = 150;

	if(this->marker_infoTWO==NULL)
		this->marker_infoTWO = artkp_Alloc<ARMarkerInfo2>(AR_TEMPL_TRACKER::MAX_IMAGE_PATTERNS);
}


ARMM_TEMPL_FUNC
ARMM_TEMPL_TRACKER::~TrackerMultiMarkerImpl()
{
	cleanup();
	if(config)
		arMultiFreeConfig(config);
}


ARMM_TEMPL_FUNC bool
ARMM_TEMPL_TRACKER::init(const char* nCamParamFile, const char* nMultiFile, ARFloat nNearClip, ARFloat nFarClip,
						 ARToolKitPlus::Logger* nLogger)
{
	// init some "static" from TrackerMultiMarker
	//
	if(this->marker_infoTWO==NULL)
		this->marker_infoTWO = artkp_Alloc<ARMarkerInfo2>(AR_TEMPL_TRACKER::MAX_IMAGE_PATTERNS);

	this->logger = nLogger;

	if(!loadCameraFile(nCamParamFile, nNearClip, nFarClip))
		return false;

	if(config)
		arMultiFreeConfig(config);

    if((config = arMultiReadConfigFile(nMultiFile)) == NULL )
        return false;

	if(this->logger)
		this->logger->artLogEx("INFO: %d markers loaded from config file", config->marker_num);

    return true;
}

ARMM_TEMPL_FUNC bool
ARMM_TEMPL_TRACKER::init(int xsize, int ysize, double* mat, double * dist_factor, 
						 ARFloat nNearClip, ARFloat nFarClip, ARMultiEachMarkerInfoT *marker, int numMarker)
{
	// init some "static" from TrackerMultiMarker
	//
	if(this->marker_infoTWO==NULL)
		this->marker_infoTWO = artkp_Alloc<ARMarkerInfo2>(AR_TEMPL_TRACKER::MAX_IMAGE_PATTERNS);

	if (!this->setCamera(xsize, ysize, mat, dist_factor, nNearClip, nFarClip))
	{
		return false;
	}

	if(config)
		arMultiFreeConfig(config);
	setMarkInfo(marker, numMarker);

	return true;
}
ARMM_TEMPL_FUNC bool 
ARMM_TEMPL_TRACKER::setMarkInfo(ARMultiEachMarkerInfoT *marker, int numMarker)
{
	if(config)
		arMultiFreeConfig(config);
	config = new ARMultiMarkerInfoT();
	config->marker_num = numMarker;
	for (int i = 0; i < 3; i++)
	{
		for (int j =0; j< 4; j++)
		{
			config->trans[i][j] = 0;
			config->transR[i][j] = 0;
		}
	}
	config->prevF = 0;
	config->marker = marker;
	ARFloat wpos3d[4][2];
	for( int i = 0; i < numMarker; i++ ) 
	{
		wpos3d[0][0] = (marker[i].center[0] - marker[i].width*0.5f)*m_basisScale[0];
		wpos3d[0][1] = (marker[i].center[1] + marker[i].width*0.5f)*m_basisScale[1];
		wpos3d[1][0] = (marker[i].center[0] + marker[i].width*0.5f)*m_basisScale[0];
		wpos3d[1][1] = (marker[i].center[1] + marker[i].width*0.5f)*m_basisScale[1];
		wpos3d[2][0] = (marker[i].center[0] + marker[i].width*0.5f)*m_basisScale[0];
		wpos3d[2][1] = (marker[i].center[1] - marker[i].width*0.5f)*m_basisScale[1];
		wpos3d[3][0] = (marker[i].center[0] - marker[i].width*0.5f)*m_basisScale[0];
		wpos3d[3][1] = (marker[i].center[1] - marker[i].width*0.5f)*m_basisScale[1];
		for( int j = 0; j < 4; j++ ) {
			marker[i].pos3d[j][0] = marker[i].trans[0][0] * wpos3d[j][0]
			+ marker[i].trans[0][1] * wpos3d[j][1]
			+ marker[i].trans[0][3];
			marker[i].pos3d[j][1] = marker[i].trans[1][0] * wpos3d[j][0]
			+ marker[i].trans[1][1] * wpos3d[j][1]
			+ marker[i].trans[1][3];
			marker[i].pos3d[j][2] = marker[i].trans[2][0] * wpos3d[j][0]
			+ marker[i].trans[2][1] * wpos3d[j][1]
			+ marker[i].trans[2][3];
		}
	}
	return true;
}

ARMM_TEMPL_FUNC bool
ARMM_TEMPL_TRACKER::setBasisScale(ARFloat basisScale[3])
{
	for (int i =0; i<3; i++)
	{
		m_basisScale[i] = basisScale[i];
	}
	if (config == NULL)
	{
		return true;
	}
	ARMultiMarkerInfoT* cfg = config;
	ARMultiEachMarkerInfoT* marker = cfg->marker;
	ARFloat wpos3d[4][2];
	for( int i = 0; i < cfg->marker_num; i++ ) 
	{
		wpos3d[0][0] = (marker[i].center[0] - marker[i].width*0.5f)*m_basisScale[0];
		wpos3d[0][1] = (marker[i].center[1] + marker[i].width*0.5f)*m_basisScale[1];
		wpos3d[1][0] = (marker[i].center[0] + marker[i].width*0.5f)*m_basisScale[0];
		wpos3d[1][1] = (marker[i].center[1] + marker[i].width*0.5f)*m_basisScale[1];
		wpos3d[2][0] = (marker[i].center[0] + marker[i].width*0.5f)*m_basisScale[0];
		wpos3d[2][1] = (marker[i].center[1] - marker[i].width*0.5f)*m_basisScale[1];
		wpos3d[3][0] = (marker[i].center[0] - marker[i].width*0.5f)*m_basisScale[0];
		wpos3d[3][1] = (marker[i].center[1] - marker[i].width*0.5f)*m_basisScale[1];
		for( int j = 0; j < 4; j++ ) {
			marker[i].pos3d[j][0] = marker[i].trans[0][0] * wpos3d[j][0]
			+ marker[i].trans[0][1] * wpos3d[j][1]
			+ marker[i].trans[0][3];
			marker[i].pos3d[j][1] = marker[i].trans[1][0] * wpos3d[j][0]
			+ marker[i].trans[1][1] * wpos3d[j][1]
			+ marker[i].trans[1][3];
			marker[i].pos3d[j][2] = marker[i].trans[2][0] * wpos3d[j][0]
			+ marker[i].trans[2][1] * wpos3d[j][1]
			+ marker[i].trans[2][3];
		}
	}
	return true;
}
ARMM_TEMPL_FUNC int
ARMM_TEMPL_TRACKER::calc(const unsigned char* nImage, bool bGuessPose)
{
	if (this->config == NULL)
	{
		return 0;
	}
	m_numLastDetected = numDetected;
	numDetected = 0;
	int				tmpNumDetected = 0;
    ARMarkerInfo    *tmp_markers = NULL;
	
	autoThreshold.reset();
	map<int, ARMarkerInfo> markerInfoList;
	vector<int> preferThreshold;
	//WCHAR str[MAX_PATH] = {0};
	//OutputDebugStringW(L"@@@@@@@@@\n");
	for(int numTries = 0;;)
	{
		
		tmpNumDetected = 0;
		tmp_markers = NULL;
		int ret = 0;
		//swprintf_s(str, MAX_PATH, L"@@@@ Use Thresh = %d \n", thresh);
		//OutputDebugStringW(str);
		if(useDetectLite)
		{
			ret = arDetectMarkerLite(const_cast<unsigned char*>(nImage), this->thresh, &tmp_markers, &tmpNumDetected);
		}
		else
		{
			ret = arDetectMarker(const_cast<unsigned char*>(nImage), this->thresh, &tmp_markers, &tmpNumDetected);
		}
		int numFound = 0;

		if (autoThreshold.enable && autoThreshold.useMultiThreshold)
		{
			for (int i = 0; i < tmpNumDetected; i++)
			{
				numFound++;
				bool alreadyFound = false;
				if (markerInfoList.find(tmp_markers[i].id) != markerInfoList.end())
				{
					numFound--;
					alreadyFound = true;	
				}
				if (!alreadyFound)
				{
					markerInfoList[tmp_markers[i].id] = tmp_markers[i];
				}
			}
		}
		if(!autoThreshold.enable)
			break;
		else if (autoThreshold.useMultiThreshold)
		{
			if (numFound > 0)
			{
				preferThreshold.push_back(thresh);
			}
			
			if (autoThreshold.thresholdList.size() > numTries)
			{
				if (thresh == autoThreshold.thresholdList[numTries])
				{

				}
				thresh = autoThreshold.thresholdList[numTries];
				//swprintf_s(str, MAX_PATH,L"@@@@ Prefer AutoThresh = %d \n", thresh);
				//OutputDebugStringW(str);	
			}
			else
			{
				thresh = (rand() % 230) + 10;
				//swprintf_s(str, MAX_PATH,L"@@@@ rand AutoThresh = %d \n", thresh);
				//OutputDebugStringW(str);
			}
			if(++numTries > autoThreshold.numRandomRetries)
				break;
		}
		else
		{
			if (tmpNumDetected)
				break;
			else
			{
				thresh = (rand() % 230) + 10;
				//swprintf_s(str, MAX_PATH,L"@@@@ rand AutoThresh = %d \n", thresh);
				//OutputDebugStringW(str);
				if(++numTries > autoThreshold.numRandomRetries)
					break;
			}
		}
	}	
	//OutputDebugStringW(L"@@@@@@@@@\n");
	if (autoThreshold.enable && autoThreshold.useMultiThreshold)
	{
		autoThreshold.thresholdList = preferThreshold;
		for (map<int, ARMarkerInfo>::iterator iter = markerInfoList.begin();
			iter != markerInfoList.end(); iter++)
		{
			if (iter->second.id != -1)
			{
				detectedMarkers[numDetected] = iter->second;
				detectedMarkerIDs[numDetected++] = iter->second.id;
				if(numDetected>=__MAX_IMAGE_PATTERNS)							// increase this value if more markers should be possible to be detected in one image...
					break;
			}
		}
	}
	else
	{
		if (autoThreshold.enable)
			thresh = autoThreshold.calc();
		for (int i =0; i < tmpNumDetected; i++)
		{
			if (tmp_markers[i].id != -1)
			{
				detectedMarkers[numDetected] = tmp_markers[i];
				detectedMarkerIDs[numDetected++] = tmp_markers[i].id;
				if(numDetected>=__MAX_IMAGE_PATTERNS)							// increase this value if more markers should be possible to be detected in one image...
					break;
			}
		}
	
	}
	/*
	if(executeMultiMarkerPoseEstimator(tmp_markers, tmpNumDetected, config) < 0)
		return 0;

	*/
	
	if (bGuessPose && m_numLastDetected > 0)
	{
		double lastExtrinsic[16];
		for (int row =0; row < 4; row++)
		{
			for(int col =0; col < 4; col++)
			{
				lastExtrinsic[row*4 + col] = config->cvTrans[row][col];
			}
		}
		executeCVPoseEstimator(tmp_markers, tmpNumDetected, config, true, lastExtrinsic);
	}
	else
	{
		executeCVPoseEstimator(tmp_markers, tmpNumDetected, config, false, NULL);
	}
	ARFloat cvTran[3][4] = {0};
	for (int row = 0; row <3; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			cvTran[row][col] = config->cvTrans[row][col];
		}
	}
	convertTransformationMatrixToOpenGLStyle(cvTran, this->gl_para);
	return numDetected;
}


ARMM_TEMPL_FUNC void
ARMM_TEMPL_TRACKER::getDetectedMarkers(int*& nMarkerIDs)
{
	nMarkerIDs = detectedMarkerIDs;
}


ARMM_TEMPL_FUNC void
ARMM_TEMPL_TRACKER::getARMatrix(ARFloat nMatrix[3][4]) const
{
	for(int i=0; i<3; i++)
		for(int j=0; j<4; j++)
			nMatrix[i][j] = config->trans[i][j];
}



ARMM_TEMPL_FUNC void*
ARMM_TEMPL_TRACKER::operator new(size_t size)
{
#ifndef _ARTKP_NO_MEMORYMANAGER_
	if(memManager)
		return memManager->getMemory(size);
	else
#endif //_ARTKP_NO_MEMORYMANAGER_
		return malloc(size);
}


ARMM_TEMPL_FUNC void
ARMM_TEMPL_TRACKER::operator delete(void *rawMemory)
{
	if(!rawMemory)
		return;

#ifndef _ARTKP_NO_MEMORYMANAGER_
	if(memManager)
		memManager->releaseMemory(rawMemory);
	else
#endif //_ARTKP_NO_MEMORYMANAGER_
		free(rawMemory);
}


ARMM_TEMPL_FUNC size_t
ARMM_TEMPL_TRACKER::getMemoryRequirements()
{
	size_t size = sizeof(ARMM_TEMPL_TRACKER);

	size += AR_TEMPL_TRACKER::getDynamicMemoryRequirements();

	return size;
}


}	// namespace ARToolKitPlus
