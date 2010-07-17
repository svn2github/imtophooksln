#include "stdafx.h"
#include "pointTrans.h"
#include "common.h"

#define BLENDVALUE 0.5
#define PROJECTIONBIOS 2

ProjectorTrans2World::ProjectorTrans2World(){

}
// tableW and tableH is the real size of the table in mm 710 * 520
ProjectorTrans2World::ProjectorTrans2World(int tableW , int tableH ,char* fileDir, int camIndex){
	pro2CamExtrinsic = NULL;
	proIntrinsic = NULL;
	camIntrinsic = NULL;
	proDisto = NULL;
	camDisto = NULL;;

	invProIntrinsic = NULL;
	pro2WorldRotation = NULL;

	cam2WorldExtrinsic = NULL;
	pro2WorldExtrinsic = NULL;
	world2CamExtrinsic = NULL;
	proPositionInWorld = NULL;
	cameraPoint = NULL;
	objectPoint = NULL;
    oriProPos = NULL;

	rotateW2C = NULL;
	transW2C = NULL;
	rotateRodrigues = NULL;

	proVector = NULL ;
	proVectorInWorld = NULL;
	pro3DPointsMat = NULL;
	proHomoMat = NULL;
	firstProjPoints = true ;
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

	proVector = cvCreateMat(3,1,CV_32F);
	proVectorInWorld = cvCreateMat(3,1,CV_32F);

	//ProjResHeight = projHeight;
	//ProjResWidth = projWidth;
	tableHeight = tableH;
	tableWidth = tableW;

	rotateW2C = cvCreateMat( 3, 3, CV_32F);
	transW2C = cvCreateMat( 3, 1, CV_32F);
	rotateRodrigues = cvCreateMat( 3, 1, CV_32F);
	pro3DPointsMat = cvCreateMat(4,2,CV_32F);
	proHomoMat = cvCreateMat( 3, 3, CV_32F);
	 
	loadCalibParam(fileDir,camIndex);	 
	cvInvert(pro2CamExtrinsic,pro2CamExtrinsic,CV_SVD);
	cvInvert(proIntrinsic,invProIntrinsic,CV_SVD);
}
void ProjectorTrans2World::Init(int tableW , int tableH ,char* fileDir, int camIndex){
	pro2CamExtrinsic = NULL;
	proIntrinsic = NULL;
	camIntrinsic = NULL;
	proDisto = NULL;
	camDisto = NULL;;

	invProIntrinsic = NULL;
	pro2WorldRotation = NULL;

	cam2WorldExtrinsic = NULL;
	pro2WorldExtrinsic = NULL;
	world2CamExtrinsic = NULL;
	proPositionInWorld = NULL;
	cameraPoint = NULL;
	objectPoint = NULL;
	oriProPos = NULL;

	rotateW2C = NULL;
	transW2C = NULL;
	rotateRodrigues = NULL;

	proVector = NULL ;
	proVectorInWorld = NULL;
	pro3DPointsMat = NULL;
	proHomoMat = NULL;
	firstProjPoints = true ;
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

	proVector = cvCreateMat(3,1,CV_32F);
	proVectorInWorld = cvCreateMat(3,1,CV_32F);

	//ProjResHeight = projHeight;
	//ProjResWidth = projWidth;
	tableHeight = tableH;
	tableWidth = tableW;

	rotateW2C = cvCreateMat( 3, 3, CV_32F);
	transW2C = cvCreateMat( 3, 1, CV_32F);
	rotateRodrigues = cvCreateMat( 3, 1, CV_32F);
	pro3DPointsMat = cvCreateMat(4,2,CV_32F);
	proHomoMat = cvCreateMat( 3, 3, CV_32F);

	loadCalibParam(fileDir,camIndex);	 
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

	cvReleaseMat(& proVector) ;
	cvReleaseMat(& proVectorInWorld);
	cvReleaseMat(& pro3DPointsMat);
	cvReleaseMat(& proHomoMat);

	if (rotateW2C != NULL)
		cvReleaseMat(&rotateW2C);
	if (transW2C != NULL)
		cvReleaseMat(&transW2C);
	if (rotateRodrigues != NULL)
		cvReleaseMat(&rotateRodrigues);

}


void ProjectorTrans2World::loadCalibParam(char* fileDir, int camIndex){

	char Dir[100];
	sprintf(Dir,"%s\\ProjectorCalibData\\caliPara%d.txt",fileDir,camIndex) ;

	fstream file ;
	char temp ;
	float value ;
	string s ;
	file.open( Dir , ios::in ) ;   // count the number of line in txt 

	getline(file,s) ;

	for(int i = 0 ; i < 3 ; i ++){
		for(int j = 0 ; j < 3 ; j ++){
			file >> value ;
			cvmSet(camIntrinsic,i,j , value) ;
		}
	}
	getline(file,s) ;  // for change line
	getline(file,s) ;

	for( int  j = 0 ; j < 4 ; j ++){
		file >> value ;
		cvmSet(camDisto,j,0 , value) ;
	}

	getline(file,s) ;
	getline(file,s) ;

	for(int i = 0 ; i < 3 ; i ++){
		for(int j = 0 ; j < 3 ; j ++){
			file >> value ;
			cvmSet(proIntrinsic,i,j , value) ;
		}
	}
	getline(file,s) ;
	getline(file,s) ;

	for( int  j = 0 ; j < 4 ; j ++){
		file >> value ;
		cvmSet(proDisto,j,0 , value) ;
	}

	getline(file,s) ;
	getline(file,s) ;

	for(int i = 0 ; i < 4 ; i ++){
		for(int j = 0 ; j < 4 ; j ++){
			file >> value ;
			cvmSet(pro2CamExtrinsic,i,j , value) ;
		}
	}
	getline(file,s) ;
	getline(file,s) ;

	file >> ProjResWidth ;
	file >> ProjResHeight ;
	initProjRes(ProjResWidth,ProjResHeight);

	file.close();

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

	// trans the point form normalize to real image size(pixel) and table size(mm) 
	CvMat* object3D = cvCreateMat(cvGetSize(objectPoint).height,3,CV_32F);
	for(int i = 0 ; i < cvGetSize(objectPoint).height ; i++){
		cvmSet(object3D,i,0,cvmGet(objectPoint,i,0)*tableWidth);
		cvmSet(object3D,i,1,cvmGet(objectPoint,i,1)*tableHeight );
		cvmSet(object3D,i,2,0);
	}

	CvMat* camOriSizePoint = cvCreateMat(cvGetSize(cameraPoint).height,2,CV_32F);
	for(int i = 0 ; i < cvGetSize(cameraPoint).height ; i++){
		cvmSet(camOriSizePoint,i,0,cvmGet(cameraPoint,i,0)*640);
		cvmSet(camOriSizePoint,i,1,cvmGet(cameraPoint,i,1)*480); 
	}
	cvFindExtrinsicCameraParams2(object3D,camOriSizePoint,camIntrinsic,camDisto,rotateRodrigues,transW2C);
	
	cvRodrigues2(rotateRodrigues,rotateW2C);
	buildExtrinsicMat(rotateW2C,transW2C,world2CamExtrinsic);


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

void ProjectorTrans2World::initProjRes(int width, int height){
	projCorner[0] = PROJECTIONBIOS ;
	projCorner[1] = PROJECTIONBIOS ;
	projCorner[2] = width - PROJECTIONBIOS ;
	projCorner[3] = PROJECTIONBIOS ;
	projCorner[4] = width - PROJECTIONBIOS ;
	projCorner[5] = height - PROJECTIONBIOS ;
	projCorner[6] = PROJECTIONBIOS ;
	projCorner[7] = height - PROJECTIONBIOS ;

	projCornerMat = cvMat(4,2,CV_32F,projCorner);

	ProjResWidth = width;
	ProjResHeight = height;

}
void ProjectorTrans2World::setTableSize(int TableW , int TableH){
  tableHeight = TableH;
  tableWidth = TableW;
}
int* ProjectorTrans2World::getTableSize(){
	int tableSize[2];
	tableSize[0] = tableWidth;
	tableSize[1] = tableHeight;
	return tableSize;
}

void ProjectorTrans2World::getProjHomo(){

	findPro2WorldExtrinsic();

	CvMat* proj2DPoint  = cvCreateMat(3,1,CV_32F);
	CvMat* projboundPoint  = cvCreateMat(4,2,CV_32F);
	CvPoint3D32f projIn3D ;
	char outmsg[100] ;
	
	float minX = 9999, minY= 9999, maxX= -9999, maxY= -9999;  // for finding bounding box
	for(int i = 0 ; i < 4 ; i ++){
		proj2DPoint->data.fl[0] = projCorner[i*2];
		proj2DPoint->data.fl[1] = projCorner[i*2+1];
		proj2DPoint->data.fl[2] = 1;

	    projIn3D = findPro3D(proj2DPoint);	
		proj3DPoints[i][0] = projIn3D.x/tableWidth;
		proj3DPoints[i][1] = projIn3D.y/tableHeight;
		
		if(firstProjPoints == true){
			pre_proj3DPoints[i][0] = proj3DPoints[i][0] ;
			pre_proj3DPoints[i][1] = proj3DPoints[i][1] ;
		}

		proj3DPoints[i][0]  = BLENDVALUE * proj3DPoints[i][0] + (1-BLENDVALUE) * pre_proj3DPoints[i][0];
		proj3DPoints[i][1]  = BLENDVALUE * proj3DPoints[i][1] +  (1-BLENDVALUE) * pre_proj3DPoints[i][1];

		pre_proj3DPoints[i][0] = proj3DPoints[i][0] ;
		pre_proj3DPoints[i][1] = proj3DPoints[i][1] ;

		cvmSet(pro3DPointsMat,i,0, proj3DPoints[i][0]);
		cvmSet(pro3DPointsMat,i,1, proj3DPoints[i][1]);

		if(minX > proj3DPoints[i][0])
			minX = proj3DPoints[i][0];

	    if(maxX < proj3DPoints[i][0])
			maxX = proj3DPoints[i][0];
		
		if(minY > proj3DPoints[i][1])
			minY = proj3DPoints[i][1];

	    if(maxY < proj3DPoints[i][1])
			maxY = proj3DPoints[i][1];
	}

	projBox[0] = minX;
	projBox[1] = minY;
	projBox[2] = maxX;
	projBox[3] = maxY;
	float xLength = maxX - minX;
	float yLength = maxY - minY;
	
	for(int i = 0 ;i< 4; i ++){
		cvmSet(pro3DPointsMat,i,0,(float)(cvmGet(pro3DPointsMat,i,0)-minX)/xLength);
		cvmSet(pro3DPointsMat,i,1,(float)(cvmGet(pro3DPointsMat,i,1)-minY)/yLength);
		//_dprintf(L" proj3DpointNormal %f %f ", cvmGet(pro3DPointsMat,i,0),cvmGet(pro3DPointsMat,i,1));
	}
	

	cvmSet(projboundPoint,0,0,0);
	cvmSet(projboundPoint,0,1,0);

	cvmSet(projboundPoint,1,0,1);
	cvmSet(projboundPoint,1,1,0);

	cvmSet(projboundPoint,2,0,1);
	cvmSet(projboundPoint,2,1,1);

	cvmSet(projboundPoint,3,0,0);
	cvmSet(projboundPoint,3,1,1);

	cvFindHomography(projboundPoint,pro3DPointsMat,proHomoMat);
	
	cvReleaseMat(&proj2DPoint);
	cvReleaseMat(&projboundPoint);
}