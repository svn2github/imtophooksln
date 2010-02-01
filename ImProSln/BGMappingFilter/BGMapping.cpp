#include "stdafx.h"
#include "BGMapping.h"
BackGroundMapping::BackGroundMapping(){
	BGthreshold = 70 ;
	mappingTable = cvCreateImage(cvSize(WIDTH,HEIGHT),8,3);
	gray0Image =   cvCreateImage(cvSize(WIDTH,HEIGHT),IPL_DEPTH_8U,1);
	gray255Image = cvCreateImage(cvSize(WIDTH,HEIGHT),IPL_DEPTH_8U,1);
	backgroundImg = cvCreateImage(cvSize(WIDTH,HEIGHT),IPL_DEPTH_8U,1);
	resultImg = cvCreateImage(cvSize(WIDTH,HEIGHT),IPL_DEPTH_8U,1);
	MatHomography = cvCreateMat( 3, 3, CV_32F);
	kernelElement = cvCreateStructuringElementEx(3,3,0,0,CV_SHAPE_ELLIPSE,NULL);
}

BackGroundMapping::~BackGroundMapping(){
	cvReleaseMat(&MatHomography);
	cvReleaseImage(&mappingTable);
	cvReleaseImage(&gray0Image);
	cvReleaseImage(&gray255Image);
	cvReleaseImage(&resultImg);
	cvReleaseImage(&backgroundImg);
}

void BackGroundMapping::setBackground(IplImage *BGImg){

	int white ,black;
	for(int i=0;i<mappingTable->height;i++)
	{
		for(int j=0;j<mappingTable->width;j++)
		{
			black = cvGet2D(mappingTable,i,j).val[0];
			white = cvGet2D(mappingTable,i,j).val[1];			
			if(cvGet2D(BGImg,i,j).val[0] == 0){
				cvSet2D(backgroundImg,i,j,cvScalar(black,black,black));
			}
			else 
				cvSet2D(backgroundImg,i,j,cvScalar(white,white,white));
		}
	}
	IplImage *temp = cvCreateImage(cvGetSize(backgroundImg),8,1) ;
	cvCopy(backgroundImg,temp);

	if(isDilate){
		cvDilate(temp,backgroundImg,kernelElement,1);
	}
	else
	cvSmooth(temp,backgroundImg,2,9);
	cvReleaseImage(&temp);
}

void BackGroundMapping::loadHomo(char *homoName, char *mTableName){

	MatHomography = (CvMat*)cvLoad(homoName);
	mappingTable = (IplImage*)cvLoad(mTableName);
}

IplImage* BackGroundMapping::getForeground(IplImage* srcImg){
	
	cvWarpPerspective(srcImg,resultImg,MatHomography);
	cvSub(resultImg,backgroundImg,resultImg);
	cvThreshold(resultImg,resultImg,BGthreshold,255,0);

	return resultImg;
}


int BackGroundMapping::getThreshold(){
	return BGthreshold ;
}

void BackGroundMapping::setThreshold(int threshold){
	BGthreshold = threshold;
}
