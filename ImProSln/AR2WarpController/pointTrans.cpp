#include "stdafx.h"
#include "pointTrans.h"
#include "common.h"

ProjectorTrans2World::ProjectorTrans2World(int projWidth , int projHeight ,char* fileDir){
	
	// init the mat for camera and projector parameters 
	proIntrinsic = cvCreateMat(3,3,CV_32F) ;
	camIntrinsic=cvCreateMat(3,3,CV_32F);
	camDisto=cvCreateMat(4,1,CV_32F);
	proDisto = cvCreateMat(4,1,CV_32F);
	pro2CamExtrinsic = cvCreateMat(4,4,CV_32F) ;

	cam2WorldExtrinsic = cvCreateMat(4,4,CV_32F) ;
	pro2WorldExtrinsic = cvCreateMat(4,4,CV_32F);
	world2CamExtrinsic = cvCreateMat(4,4,CV_32F);
	
	invProIntrinsic = cvCreateMat(3,3,CV_32F) ; 
	pro2WorldRotation = cvCreateMat(3,3,CV_32F) ; 
	proPositionInWorld = cvCreateMat(4,1,CV_32F);
	 
	// set projector's original at [0,0,0,1]
	oriProPos = cvCreateMat(4,1,CV_32F);
	cvSetZero(oriProPos);
	oriProPos->data.fl[3] = 1 ;  

    targetPoint = cvCreateMat(3,1,CV_32F);
	proVector = cvCreateMat(3,1,CV_32F);
	proVectorInWorld = cvCreateMat(3,1,CV_32F);

	ProjResHeight = projHeight;
	ProjResWidth = projWidth;
	tableHeight = 190;
	tableWidth = 190;

	rotateW2C = cvCreateMat( 3, 3, CV_32F);
	transW2C = cvCreateMat( 3, 1, CV_32F);
	rotateTmp = cvCreateMat( 3, 1, CV_32F);
	pro3DPoints = cvCreateMat(4,3,CV_32F);
	proHomoMat = cvCreateMat( 3, 3, CV_32F);
	 
	setResolution(projWidth,projHeight);
	loadCalibParam(fileDir);	 
	cvInvert(pro2CamExtrinsic,pro2CamExtrinsic,CV_SVD);
	cvInvert(proIntrinsic,invProIntrinsic,CV_SVD);
}

ProjectorTrans2World::~ProjectorTrans2World(){

	cvReleaseMat(& proIntrinsic) ;
	cvReleaseMat(& camIntrinsic);
	cvReleaseMat(& camDisto);
	cvReleaseMat(& proDisto);
	cvReleaseMat(& pro2CamExtrinsic);

	cvReleaseMat(& invProIntrinsic);
	cvReleaseMat(& cam2WorldExtrinsic);
	cvReleaseMat(& world2CamExtrinsic);
	
	cvReleaseMat(& pro2WorldRotation);
	cvReleaseMat(& pro2WorldExtrinsic);
	cvReleaseMat(& proPositionInWorld);
	
	cvReleaseMat(& cameraPoint);
	cvReleaseMat(& objectPoint);
	cvReleaseMat(& oriProPos);

	cvReleaseMat(& targetPoint);
	cvReleaseMat(& proVector) ;
	cvReleaseMat(& proVectorInWorld);
	cvReleaseMat(& pro3DPoints);
	cvReleaseMat(& proHomoMat);
}


void ProjectorTrans2World::loadCalibParam(char* fileDir){

	char Dir[100];
	sprintf(Dir,"%s\\ProjectorCalibData\\ProDisto.txt",fileDir) ;
	proDisto = (CvMat*)cvLoad(Dir);
	sprintf(Dir,"%s\\ProjectorCalibData\\CamDisto.txt",fileDir) ;
	camDisto = (CvMat*)cvLoad(Dir);
	sprintf(Dir,"%s\\ProjectorCalibData\\ProIntrinsic.txt",fileDir) ;
	proIntrinsic = (CvMat*)cvLoad(Dir);
	sprintf(Dir,"%s\\ProjectorCalibData\\CamIntrinsic.txt",fileDir) ;
	camIntrinsic = (CvMat*)cvLoad(Dir);
	sprintf(Dir,"%s\\ProjectorCalibData\\pro2CamExtrinsic.txt",fileDir) ;
	pro2CamExtrinsic = (CvMat*)cvLoad(Dir);

}
void ProjectorTrans2World::buildExtrinsicMat(CvMat* rotation, CvMat* translate, CvMat* dstExtrinsicMat){

	for(int i = 0 ; i <3 ; i ++){
		for(int j = 0 ; j <3 ; j ++){
			cvmSet(dstExtrinsicMat,i,j,cvmGet(rotation,i,j));
		}
		cvmSet(dstExtrinsicMat,i,3,cvmGet(translate,i,0));
	}
	for(int i = 0 ; i < 3 ; i ++){
		cvmSet(dstExtrinsicMat,3,i,0);
	}
	cvmSet(dstExtrinsicMat,3,3,1);
}

void ProjectorTrans2World::findCam2WorldExtrinsic(CvMat* cameraPoint, CvMat* objectPoint){

	CvMat* object3D = cvCreateMat(cvGetSize(objectPoint).height,3,CV_32F);
	for(int i = 0 ; i < cvGetSize(objectPoint).height ; i++){
		cvmSet(object3D,i,0,cvmGet(objectPoint,i,0)*tableWidth);
		cvmSet(object3D,i,1,cvmGet(objectPoint,i,1)*tableHeight);
		cvmSet(object3D,i,2,0);
	}

	CvMat* camOriSizePoint = cvCreateMat(cvGetSize(cameraPoint).height,2,CV_32F);
	for(int i = 0 ; i < cvGetSize(cameraPoint).height ; i++){
		_DPRINTF((L"cameraPoint %f %f ",cameraPoint->data.fl[i*2],cameraPoint->data.fl[i*2+1]));
		cvmSet(camOriSizePoint,i,0,cvmGet(cameraPoint,i,0)*640);
		cvmSet(camOriSizePoint,i,1,cvmGet(cameraPoint,i,1)*480);

	}
	cvFindExtrinsicCameraParams2(object3D,camOriSizePoint,camIntrinsic,camDisto,rotateTmp,transW2C);
    cvRodrigues2(rotateTmp,rotateW2C);

	buildExtrinsicMat(rotateW2C,transW2C,world2CamExtrinsic);
	findPro2WorldExtrinsic();

	cvReleaseMat(&object3D);
	cvReleaseMat(&camOriSizePoint);

}

void ProjectorTrans2World::findPro2WorldExtrinsic(){
    
	cvInvert(world2CamExtrinsic,cam2WorldExtrinsic);
	cvmMul(cam2WorldExtrinsic,pro2CamExtrinsic,pro2WorldExtrinsic);
	
	for(int i = 0 ; i <3 ; i ++){
		for(int j = 0 ; j <3  ; j ++){
			cvmSet(pro2WorldRotation,i,j,cvmGet(pro2WorldExtrinsic,i,j));
		}
	}	
}

//find the four corners of projector's 3D position in world coordinate

CvPoint3D32f ProjectorTrans2World:: findPro3D(CvMat* pointMat){
	CvPoint3D32f proIn3D ;

	cvmMul(invProIntrinsic,pointMat,proVector);
	cvmMul(pro2WorldRotation,proVector,proVectorInWorld);
	cvmMul(pro2WorldExtrinsic,oriProPos,proPositionInWorld);

	float scale ;
	scale = -(proPositionInWorld->data.fl[2]/ proVectorInWorld->data.fl[2]);
	proIn3D.x = proPositionInWorld->data.fl[0] + scale * proVectorInWorld->data.fl[0] ;
	proIn3D.y = proPositionInWorld->data.fl[1] + scale * proVectorInWorld->data.fl[1] ;
	proIn3D.z = 0 ;

	return proIn3D;
}

void ProjectorTrans2World::setResolution(int width , int height){

    projCorner[0] = 0 ;
	projCorner[1] = 0 ;
	projCorner[2] = width ;
	projCorner[3] = 0 ;
	projCorner[4] = width ;
	projCorner[5] = height ;
	projCorner[6] = 0 ;
	projCorner[7] = height ;

	projCornerMat = cvMat(4,2,CV_32F,projCorner);

	ProjResWidth = width;
	ProjResHeight = height;

}
int* ProjectorTrans2World::getResolution(){
	int res[2];
	res[0] = ProjResWidth;
	res[1] = ProjResHeight;
	return res;
}

void ProjectorTrans2World::getProjHomo(){
	CvMat* proj2DPoint  = cvCreateMat(3,1,CV_32F);
	CvPoint3D32f projIn3D ;
	
	float minX = 9999, minY= 9999, maxX= -9999, maxY= -9999;
	for(int i = 0 ; i < 4 ; i ++){
		proj2DPoint->data.fl[0] = projCorner[i*2];
		proj2DPoint->data.fl[1] = projCorner[i*2+1];
		proj2DPoint->data.fl[2] = 1;

	    projIn3D = findPro3D(proj2DPoint);	
		CvMat* imgPoint = cvCreateMat(4,2,CV_32F);
		cvProjectPoints2(pro3DPoints,rotateTmp,transW2C,camIntrinsic,camDisto,imgPoint);
		_DPRINTF((L"projOnImg %f %f ",imgPoint->data.fl[i*2],imgPoint->data.fl[i*2+1]));

		projIn3D.x = projIn3D.x/tableWidth ;
		projIn3D.y = projIn3D.y/tableHeight ;

		cvmSet(pro3DPoints,i,0,projIn3D.x);
		cvmSet(pro3DPoints,i,1,projIn3D.y);
		cvmSet(pro3DPoints,i,2,projIn3D.z);

		proj3DPoints[i][0] = projIn3D.x;
		proj3DPoints[i][1] = projIn3D.y;

		if(minX > projIn3D.x)
			minX = projIn3D.x;

	    if(maxX < projIn3D.x)
			maxX = projIn3D.x;
		
		if(minY > projIn3D.y)
			minY = projIn3D.y;

	    if(maxY < projIn3D.y)
			maxY = projIn3D.y;
		_DPRINTF((L"proj3D %f %f ",pro3DPoints->data.fl[i*2],pro3DPoints->data.fl[i*2+1]));
	}

	projBox[0] = minX;
	projBox[1] = minY;
	projBox[2] = maxX;
	projBox[3] = maxY;


	
	cvFindHomography(pro3DPoints,&projCornerMat,proHomoMat);
	cvReleaseMat(&proj2DPoint);
}