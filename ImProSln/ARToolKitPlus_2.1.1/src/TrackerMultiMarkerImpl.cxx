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

PoseKalman::PoseKalman()
{
	m_TKalman = generateKalman(Kalman_Translate);
	m_QuaternionKalman = generateKalman(Kalman_Quanterion);
	m_lostTimes = 0;
	
	memset(m_lastT, 0, sizeof(m_lastT) );
}
PoseKalman::~PoseKalman()
{
	if (m_TKalman != NULL)
	{
		cvReleaseKalman(&m_TKalman);
		m_TKalman = NULL;
	}
	if (m_QuaternionKalman != NULL)
	{
		cvReleaseKalman(&m_QuaternionKalman);
		m_QuaternionKalman = NULL;
	}
}

BOOL PoseKalman::init(float* curT, float* curR)
{
	if (m_TKalman == NULL || m_QuaternionKalman == NULL
		|| curT == NULL || curR == NULL)
		return FALSE;
	//* state is (x, y, z, vx, vy, vz, rx, ry, rz, vrz, vry, vrz, rlength )*/
	float Rlength = sqrt(curR[0]*curR[0] + curR[1]*curR[1] +curR[2]*curR[2]);
	float normCurR[3] = {0}; 
	for (int i =0; i < 3; i++)
	{
		normCurR[i] = curR[i] / Rlength;
	}

	float axisAngle[4] = {normCurR[0], normCurR[1], normCurR[2], Rlength};
	float quanterion[4] = {0};
	AxisAngle2Quaternion(axisAngle, quanterion);

	m_TKalman->state_post->data.fl[0] = curT[0];
	m_TKalman->state_post->data.fl[1] = curT[1] ;
	m_TKalman->state_post->data.fl[2] = curT[2];
	m_TKalman->state_post->data.fl[3] = 0;
	m_TKalman->state_post->data.fl[4] = 0;
	m_TKalman->state_post->data.fl[5] = 0;

	m_QuaternionKalman->state_post->data.fl[0] = quanterion[0];
	m_QuaternionKalman->state_post->data.fl[1] = quanterion[1];
	m_QuaternionKalman->state_post->data.fl[2] = quanterion[2];
	m_QuaternionKalman->state_post->data.fl[3] = quanterion[3];

	m_QuaternionKalman->state_post->data.fl[4] = 0;
	m_QuaternionKalman->state_post->data.fl[5] = 0;
	m_QuaternionKalman->state_post->data.fl[6] = 0;
	m_QuaternionKalman->state_post->data.fl[7] = 0;

	memcpy(m_lastT, curT, sizeof(m_lastT));	
	memcpy(m_lastQuaterion, quanterion, sizeof(m_lastQuaterion));


	return TRUE;
}
BOOL PoseKalman::update(float* curT, float* curR)
{
	if (m_TKalman == NULL || m_QuaternionKalman == NULL ||
		curT == NULL || curR == NULL)
		return FALSE;
	//measure: x, y, z, vx, vy, vz, rx, ry, rz, vrx, vry, vrz ,rlength, rvlength
	CvMat* measurementT = cvCreateMat( 6, 1, CV_32FC1 );
	CvMat* measurementQ = cvCreateMat(8, 1, CV_32FC1 );
	measurementT->data.fl[0] = curT[0];
	measurementT->data.fl[1] = curT[1];
	measurementT->data.fl[2] = curT[2];
	measurementT->data.fl[3] = curT[0] - m_lastT[0];
	measurementT->data.fl[4] = curT[1] - m_lastT[1];
	measurementT->data.fl[5] = curT[2] - m_lastT[2];
	
	float Rlength = sqrt(curR[0]*curR[0] + curR[1]*curR[1] +curR[2]*curR[2]);


	float normCurR[3] = {0}; 
	for (int i =0; i < 3; i++)
	{
		normCurR[i] = curR[i] / Rlength;
	}

	float quanterion[4] = {0};
	float equalQuanterion[4] = {0};
	float mQuanterion[4] = {0};
	float measureAxisAngle[4] = {normCurR[0], normCurR[1], normCurR[2], Rlength};
	AxisAngle2Quaternion(measureAxisAngle, mQuanterion);

	for (int i =0; i < 4; i++)
		equalQuanterion[i] = -mQuanterion[i];

	float dEQ = (equalQuanterion[0] - m_lastQuaterion[0])*(equalQuanterion[0] - m_lastQuaterion[0]) +
				(equalQuanterion[1] - m_lastQuaterion[1])*(equalQuanterion[1] - m_lastQuaterion[1]) +
				(equalQuanterion[2] - m_lastQuaterion[2])*(equalQuanterion[2] - m_lastQuaterion[2]) +
				(equalQuanterion[3] - m_lastQuaterion[3])*(equalQuanterion[3] - m_lastQuaterion[3]);
	float dQ =  (mQuanterion[0] - m_lastQuaterion[0])*(mQuanterion[0] - m_lastQuaterion[0]) +
		(mQuanterion[1] - m_lastQuaterion[1])*(mQuanterion[1] - m_lastQuaterion[1]) +
		(mQuanterion[2] - m_lastQuaterion[2])*(mQuanterion[2] - m_lastQuaterion[2]) +
		(mQuanterion[3] - m_lastQuaterion[3])*(mQuanterion[3] - m_lastQuaterion[3]);

	if (dEQ > dQ)
	{
		for (int i = 0; i <4; i++)
			quanterion[i] = mQuanterion[i];
	}
	else
	{
		for (int i = 0; i <4; i++)
			quanterion[i] = equalQuanterion[i];
	}
	measurementQ->data.fl[0] = quanterion[0];
	measurementQ->data.fl[1] = quanterion[1];
	measurementQ->data.fl[2] = quanterion[2];
	measurementQ->data.fl[3] = quanterion[3];

	measurementQ->data.fl[4] = quanterion[0] - m_lastQuaterion[0];
	measurementQ->data.fl[5] = quanterion[1] - m_lastQuaterion[1];
	measurementQ->data.fl[6] = quanterion[2] - m_lastQuaterion[2];
	measurementQ->data.fl[7] = quanterion[3] - m_lastQuaterion[3];
	

	cvKalmanCorrect(m_TKalman, measurementT);
	cvKalmanCorrect(m_QuaternionKalman, measurementQ);
	
	cvReleaseMat(&measurementT);
	cvReleaseMat(&measurementQ);
	measurementT = NULL;

	measurementQ = NULL;
	memcpy(m_lastT, curT, sizeof(m_lastT));
	memcpy(m_lastQuaterion, quanterion, sizeof(m_lastQuaterion));
	//if we never call predict, openCV kalman will in a wrong state.
	float predT[4] = {0}, predR[4] = {0};
	this->predict(1, predT, predR);

	return TRUE;
}
BOOL PoseKalman::predict(int dt, float* predT, float* predR, float* predV, float* predVR)
{
	if (m_TKalman == NULL || m_QuaternionKalman == NULL ||
		predT == NULL || predR == NULL || dt < 0)
		return FALSE;
	if (dt == 0)
	{
		predT[0] = m_TKalman->state_post->data.fl[0];
		predT[1] = m_TKalman->state_post->data.fl[1];
		predT[2] = m_TKalman->state_post->data.fl[2];

		if (predV != NULL)
		{
			predV[0] = m_TKalman->state_post->data.fl[3];
			predV[1] = m_TKalman->state_post->data.fl[4];
			predV[2] = m_TKalman->state_post->data.fl[5];
		}
	
		float quanterion[4] = {m_QuaternionKalman->state_post->data.fl[0],
		m_QuaternionKalman->state_post->data.fl[1],
		m_QuaternionKalman->state_post->data.fl[2],
		m_QuaternionKalman->state_post->data.fl[3]};

		float axisAngle[4] = {0};
		Quaternion2AxisAngle(quanterion, axisAngle);

		float axisLength = sqrt(axisAngle[0]*axisAngle[0] + 
			axisAngle[1]*axisAngle[1]+ axisAngle[2]*axisAngle[2]);
		
		for (int i = 0; i < 3 ;i++)
		{
			predR[i] = axisAngle[i]/axisLength * axisAngle[3];
		}
	}
	else
	{
		const float orgAT[] = { 1,0,0, 1,0,0, // 1*x + 0*y + 0z + 1Vx + 0*Vy + 0Vz = x
			0,1,0, 0,1,0,   // 0*x + 1*y + 0z + 0Vx + 1*Vy + 0Vz = y
			0,0,1, 0,0,1,   // 0*x + 0*y + 1z + 0Vx + 0*Vy + 1Vz = z
			0,0,0, 1,0,0,   // 0*x + 0*y + 0z + 1Vx + 0*Vy + 0Vz = Vx
			0,0,0, 0,1,0,   // 0*x + 0*y + 0z + 0Vx + 1*Vy + 0Vz = Vy
			0,0,0, 0,0,1};  // 0*x + 0*y + 0z + 0Vx + 0*Vy + 1Vz = Vz
		const float AT[] = { 1,0,0, dt,0,0, // 1*x + 0*y + 0z + 1Vx + 0*Vy + 0Vz = x
			0,1,0, 0,dt,0,   // 0*x + 1*y + 0z + 0Vx + 1*Vy + 0Vz = y
			0,0,1, 0,0,dt,   // 0*x + 0*y + 1z + 0Vx + 0*Vy + 1Vz = z
			0,0,0, 1,0,0,   // 0*x + 0*y + 0z + 1Vx + 0*Vy + 0Vz = Vx
			0,0,0, 0,1,0,   // 0*x + 0*y + 0z + 0Vx + 1*Vy + 0Vz = Vy
			0,0,0, 0,0,1};  // 0*x + 0*y + 0z + 0Vx + 0*Vy + 1Vz = Vz
	

		const float orgAQ[] = { 1,0,0,0, 1,0,0,0,
			0,1,0,0, 0,1,0,0,
			0,0,1,0, 0,0,1,0,
			0,0,0,1, 0,0,0,1,
			0,0,0,0, 1,0,0,0,
			0,0,0,0, 0,1,0,0,
			0,0,0,0, 0,0,1,0,
			0,0,0,0, 0,0,0,1};
		const float AQ[] = { 1,0,0,0, dt,0,0,0,
			0,1,0,0, 0,dt,0,0,
			0,0,1,0, 0,0,dt,0,
			0,0,0,1, 0,0,0,dt,
			0,0,0,0, 1,0,0,0,
			0,0,0,0, 0,1,0,0,
			0,0,0,0, 0,0,1,0,
			0,0,0,0, 0,0,0,1};


		memcpy( m_TKalman->transition_matrix->data.fl, AT, sizeof(AT));
		memcpy( m_QuaternionKalman->transition_matrix->data.fl, AQ, sizeof(AQ));
		const CvMat* predictResultT = cvKalmanPredict(m_TKalman, NULL);
		predT[0] = predictResultT->data.fl[0];
		predT[1] = predictResultT->data.fl[1];
		predT[2] = predictResultT->data.fl[2];

		if (predV != NULL)
		{
			predV[0] = predictResultT->data.fl[3];
			predV[1] = predictResultT->data.fl[4];
			predV[2] = predictResultT->data.fl[5];
		}

		const CvMat* predictResultQ = cvKalmanPredict(m_QuaternionKalman, NULL);
		
		float quanterion[4] = {predictResultQ->data.fl[0],
							predictResultQ->data.fl[1],
							predictResultQ->data.fl[2],
							predictResultQ->data.fl[3]};

		float axisAngle[4] = {0};
		Quaternion2AxisAngle(quanterion, axisAngle);
		float axisLength = sqrt(axisAngle[0]*axisAngle[0] + 
			axisAngle[1]*axisAngle[1]+ axisAngle[2]*axisAngle[2]);
		while(axisAngle[3] > 2*CV_PI)
		{
			axisAngle[3] -= 2*CV_PI;
		}
		while(axisAngle[3] < 0)
		{
			axisAngle[3] += 2*CV_PI;
		}
		for (int i = 0; i < 3 ;i++)
		{
			predR[i] = axisAngle[i]/axisLength * axisAngle[3];
		}

		memcpy( m_TKalman->transition_matrix->data.fl, orgAT, sizeof(orgAT));	
		memcpy( m_QuaternionKalman->transition_matrix->data.fl, orgAQ, sizeof(orgAQ));
	}

	return TRUE;
}
BOOL PoseKalman::GetLastPose(float* lastT, float* lastR)
{
	if (lastT == NULL || lastR == NULL)
		return FALSE;
	memcpy(m_lastT, lastT, sizeof(m_lastT) );
	return TRUE;
}
BOOL PoseKalman::GetMeasureNoiseCov(float& fNoiseCov)
{
	if (m_QuaternionKalman == NULL)
		return FALSE;
	fNoiseCov = m_QuaternionKalman->measurement_noise_cov->data.fl[0];
	return TRUE;
}
BOOL PoseKalman::SetMeasureNoiseCov(float fNoiseCov)
{
	if (m_QuaternionKalman == NULL)
		return FALSE;
	cvSetIdentity(m_QuaternionKalman->measurement_noise_cov, cvRealScalar(fNoiseCov));
	return TRUE;
}
CvKalman* PoseKalman::generateKalman(KalmanType kType)
{
	if (kType == Kalman_Translate)
	{
		const float A[] = { 1,0,0, 1,0,0, // 1*x + 0*y + 0z + 1Vx + 0*Vy + 0Vz = x
			0,1,0, 0,1,0,   // 0*x + 1*y + 0z + 0Vx + 1*Vy + 0Vz = y
			0,0,1, 0,0,1,   // 0*x + 0*y + 1z + 0Vx + 0*Vy + 1Vz = z
			0,0,0, 1,0,0,   // 0*x + 0*y + 0z + 1Vx + 0*Vy + 0Vz = Vx
			0,0,0, 0,1,0,   // 0*x + 0*y + 0z + 0Vx + 1*Vy + 0Vz = Vy
			0,0,0, 0,0,1};   // 0*x + 0*y + 0z + 0Vx + 0*Vy + 1Vz = Vz
			
		CvKalman* retKalman = NULL;
		retKalman = cvCreateKalman( 6, 6, 0 );

		memcpy( retKalman->transition_matrix->data.fl, A, sizeof(A));
		cvSetIdentity( retKalman->measurement_matrix, cvRealScalar(1) );
		cvSetIdentity( retKalman->process_noise_cov, cvRealScalar(1e-5) );
		cvSetIdentity( retKalman->measurement_noise_cov, cvRealScalar(1e-5) );
		cvSetIdentity( retKalman->error_cov_post, cvRealScalar(1));
		cvSetIdentity( retKalman->error_cov_pre, cvRealScalar(1));

		cvZero(retKalman->temp1);
		cvZero(retKalman->temp2);
		cvZero(retKalman->temp3);
		cvZero(retKalman->temp4);
		cvZero(retKalman->temp5);
		cvZero(retKalman->gain);
		return retKalman;
	}

	else if (kType == Kalman_Quanterion)
	{
		const float A[] = { 1,0,0,0, 1,0,0,0,
							0,1,0,0, 0,1,0,0,
							0,0,1,0, 0,0,1,0,
		                    0,0,0,1, 0,0,0,1,
							0,0,0,0, 1,0,0,0,
		                    0,0,0,0, 0,1,0,0,
		                    0,0,0,0, 0,0,1,0,
		                    0,0,0,0, 0,0,0,1};

		CvKalman* retKalman = NULL;
		retKalman = cvCreateKalman(8, 8, 0 );

		memcpy( retKalman->transition_matrix->data.fl, A, sizeof(A));
		
		cvSetIdentity( retKalman->measurement_matrix, cvRealScalar(1) );
		cvSetIdentity( retKalman->process_noise_cov, cvRealScalar(1e-5) );
		cvSetIdentity( retKalman->measurement_noise_cov, cvRealScalar(1e-1) );
		cvSetIdentity( retKalman->error_cov_post, cvRealScalar(1));
		cvSetIdentity( retKalman->error_cov_pre, cvRealScalar(1));

		cvZero( retKalman->error_cov_post);
		cvZero(retKalman->temp1);
		cvZero(retKalman->temp2);
		cvZero(retKalman->temp3);
		cvZero(retKalman->temp4);
		cvZero(retKalman->temp5);
		cvZero(retKalman->gain);
		return retKalman;
	}
	return NULL;
}

bool PoseKalman::Quaternion2AxisAngle(const float* quaternion, float* axisAngle)
{
	if (axisAngle == NULL || quaternion == NULL)
		return false;
	
	D3DXQUATERNION d3dQ(0,0,0,0);
	d3dQ.x = quaternion[0];  
	d3dQ.y = quaternion[1];
	d3dQ.z = quaternion[2];
	d3dQ.w = quaternion[3];
	D3DXVECTOR3 axis(0,0,0);
	FLOAT angle = 0;
	HRESULT hr = S_OK;
	D3DXQuaternionNormalize(&d3dQ, &d3dQ);
	D3DXQuaternionToAxisAngle(&d3dQ, &axis, &angle);
	
	axisAngle[0] = axis.x;
	axisAngle[1] = axis.y;
	axisAngle[2] = axis.z;
	axisAngle[3] = angle;

	return true;
}
bool PoseKalman::AxisAngle2Quaternion(float* axisAngle, float* quaternion)
{
	if (axisAngle == NULL || quaternion == NULL)
		return false;

	D3DXQUATERNION d3dQ(0,0,0,0);
	
	D3DXVECTOR3 axis(axisAngle[0], axisAngle[1], axisAngle[2]);
	float angle = axisAngle[3];
	D3DXQuaternionRotationAxis(&d3dQ, &axis, angle);
	D3DXQuaternionNormalize(&d3dQ, &d3dQ);
	quaternion[0] = d3dQ.x;
	quaternion[1] = d3dQ.y;
	quaternion[2] = d3dQ.z;
	quaternion[3] = d3dQ.w;
	return true;
}

bool PoseKalman::QuanterionMultiply(float* Q1, float* Q2, float* Qout)
{
	if (Q1 == NULL || Q2 == NULL || Qout == NULL)
	{
		return false;
	}
	D3DXQUATERNION dxQ1(0,0,0,0), dxQ2(0,0,0,0), dxQ3(0,0,0,0);
	dxQ1.x = Q1[0]; dxQ1.y = Q1[1]; dxQ1.z = Q1[2]; dxQ1.w = Q1[3];
	dxQ2.x = Q1[0]; dxQ2.y = Q1[1]; dxQ2.z = Q1[2]; dxQ2.w = Q1[3];
	D3DXQuaternionNormalize(&dxQ1, &dxQ1);
	D3DXQuaternionNormalize(&dxQ2, &dxQ2);
	D3DXQuaternionMultiply(&dxQ3, &dxQ1, &dxQ2);
	Qout[0] = dxQ3.x; Qout[1] = dxQ3.y; Qout[2] = dxQ3.z; Qout[3] = dxQ3.w;
	return true;

}
namespace ARToolKitPlus
{



ARMM_TEMPL_FUNC
ARMM_TEMPL_TRACKER::TrackerMultiMarkerImpl(int nWidth, int nHeight)
{
	m_pPoseKalman = NULL;
	m_nFixFrame = 0;
	m_KalmanMNoise = 0.1;
	this->logger = NULL;
	for (int i =0; i <3; i++)
		m_basisScale[i] = 1;

	this->screenWidth = nWidth;
	this->screenHeight = nHeight;
	bUseKalman = false;
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

	if (m_pPoseKalman != NULL)
	{
		delete m_pPoseKalman;
		m_pPoseKalman = NULL;
	}
}


ARMM_TEMPL_FUNC bool ARMM_TEMPL_TRACKER::predictCVPose(int dt, float* cvTrans)
{
	if (m_pPoseKalman == NULL || cvTrans == NULL)
	{
		return false;
	}
	float predT[4] = {0}, predR[4] = {0};
	float initV[9] = {0};
	m_pPoseKalman->predict(dt, predT, predR);
	CvMat cvRotVec = cvMat(3, 1, CV_32F, predR);
	CvMat cvRotMat = cvMat(3, 3, CV_32F, initV);
	
	cvRodrigues2(&cvRotVec, &cvRotMat);
	
	for(int i = 0 ; i <3 ; i ++){
		for(int j = 0 ; j <3 ; j ++){
			cvTrans[i*4 + j] = cvmGet(&cvRotMat,i,j);
		}
		cvTrans[i*4 + 3] = predT[i];
	}
	for(int i = 0 ; i < 3 ; i ++){ 
		cvTrans[3*4 + i] = 0;
	}
	cvTrans[3*4 + 3] = 1;
	return true;
}
ARMM_TEMPL_FUNC bool ARMM_TEMPL_TRACKER::getbUseKalman()
{
	return bUseKalman;
}
ARMM_TEMPL_FUNC bool ARMM_TEMPL_TRACKER::setbUseKalman(bool v)
{
	bUseKalman = v;
	return true;
}
ARMM_TEMPL_FUNC BOOL ARMM_TEMPL_TRACKER::GetMeasureNoiseCov(float& fNoiseCov)
{
	fNoiseCov = m_KalmanMNoise;
	return TRUE;
}
ARMM_TEMPL_FUNC BOOL ARMM_TEMPL_TRACKER::SetMeasureNoiseCov(float fNoiseCov)
{
	m_KalmanMNoise = fNoiseCov;
	if (m_pPoseKalman != NULL)
		m_pPoseKalman->SetMeasureNoiseCov(fNoiseCov);
	return TRUE;
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
		executeCVPoseEstimator(detectedMarkers, numDetected, config, true, lastExtrinsic);
	}
	else
	{
		executeCVPoseEstimator(detectedMarkers, numDetected, config, false, NULL);
	}
	if (bUseKalman)
	{
		updatePoseKalman(detectedMarkers, numDetected, config);
		replaceCvPoseByKalman(config);
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

ARMM_TEMPL_FUNC bool ARMM_TEMPL_TRACKER::updatePoseKalman(ARMarkerInfo *marker_info, int marker_num, ARMultiMarkerInfoT *config)
{
	if (config == NULL)
		return false;

	float* curT = NULL;
	float* curR = NULL;

	if (marker_num > 0)
	{
		curR = new float[3];
		curR[0] = config->rotVector[0];
		curR[1] = config->rotVector[1];
		curR[2] = config->rotVector[2];
		curT = new float[3];
		curT[0] = config->cvTrans[0][3];
		curT[1] = config->cvTrans[1][3];
		curT[2] = config->cvTrans[2][3];
		
	}
	if (marker_num > 0 && m_pPoseKalman == NULL)
	{
		m_pPoseKalman = new PoseKalman();
		m_pPoseKalman->init(curT, curR);
		m_pPoseKalman->SetMeasureNoiseCov(m_KalmanMNoise);

	}
	else if (marker_num > 0 && m_pPoseKalman != NULL)
	{
		m_pPoseKalman->update(curT, curR);
		m_pPoseKalman->m_lostTimes = 0;
	}
	else if ( marker_num <= 0 && m_pPoseKalman == NULL)
	{
		// do nothing
	}
	else if ( marker_num <= 0 && m_pPoseKalman != NULL)
	{
		m_pPoseKalman->m_lostTimes++;
		if (m_pPoseKalman->m_lostTimes > m_nFixFrame)
		{
			delete m_pPoseKalman;
			m_pPoseKalman = NULL;
		}

	}
	if ( curT != NULL)
	{
		delete [] curT;
		curT = NULL;
	}
	if ( curR != NULL)
	{
		delete [] curR;
		curR = NULL;
	}
	return true;
}
ARMM_TEMPL_FUNC	bool ARMM_TEMPL_TRACKER::replaceCvPoseByKalman(ARMultiMarkerInfoT *config)
{
	if (m_pPoseKalman == NULL || config == NULL)
	{
		return false;
	}

	float curT[3] = {0};
	float curR[3] = {0};
	m_pPoseKalman->predict(m_pPoseKalman->m_lostTimes, curT, curR);
	
	CvMat* cvRotMat = NULL;
	CvMat* cvRotVec = NULL;
	cvRotMat = cvCreateMat(3, 3, CV_32F);
	cvRotVec = cvCreateMat(3, 1, CV_32F);
	WCHAR str[MAX_PATH] = {0};
	
	float normCurR[3] = {0}, angle = 0;
	angle = sqrt(curR[0]*curR[0] + curR[1]*curR[1] + curR[2]*curR[2]);
	for (int i =0; i <3; i++)
	{
		normCurR[i] = curR[i] / angle;
	}

	float normOrgR[3] = {0}, OrgAngle = 0;
	OrgAngle = sqrt(config->rotVector[0]*config->rotVector[0] + 
		config->rotVector[1]*config->rotVector[1] + config->rotVector[2]*config->rotVector[2]);
	for (int i =0; i <3; i++)
	{
		normOrgR[i] = config->rotVector[i] / OrgAngle;
	}
	
	for (int i = 0; i <3; i ++)
	{
		cvRotVec->data.fl[i] = curR[i];
	}
	cvRodrigues2(cvRotVec, cvRotMat);
	
	for(int i = 0 ; i <3 ; i ++){
		for(int j = 0 ; j <3 ; j ++){
			config->cvTrans[i][j] = cvmGet(cvRotMat,i,j);
		}
		config->cvTrans[i][3] = curT[i];
	}
	for(int i = 0 ; i < 3 ; i ++){ 
		config->cvTrans[3][i] = 0;
	}
	config->cvTrans[3][3] = 1;
	if (m_pPoseKalman->m_lostTimes > 0)
	{
		config->bKalmanFixed = true;
	}
	else
	{
		config->bKalmanFixed = false;
	}
	cvReleaseMat(&cvRotMat);
	cvReleaseMat(&cvRotVec);
	return true;
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
