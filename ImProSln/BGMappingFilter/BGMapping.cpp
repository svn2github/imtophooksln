#include "stdafx.h"
#include "BGMapping.h"

#define BLACK_VALUE 10


BackGroundMapping::BackGroundMapping(int returnW, int returnH, int imgChannel,char* fileDir){

	BGthreshold = 0;
	BlackValue = 0;
	WhiteValue = 0 ;

	char settingFile[100];

	sprintf(settingFile,"%s\\ProjectorCalibData\\adjustValue.txt",fileDir) ;

	FILE  * pFile ;
	pFile = fopen(settingFile,"r");
	fscanf(pFile ,"[ %d %d %d ] \n",&BGthreshold , &BlackValue,&WhiteValue);  // threshold , blackvalue , whiteValue


	mappingTable = cvCreateImage(cvSize(returnW,returnH),8,3);
	backgroundImg = cvCreateImage(cvSize(returnW,returnH),IPL_DEPTH_8U,1);
	binaryResult = cvCreateImage(cvSize(returnW,returnH),IPL_DEPTH_8U,1);
	resultImg = cvCreateImage(cvSize(returnW,returnH),IPL_DEPTH_8U,1);
	result4CImg = cvCreateImage(cvSize(returnW,returnH),IPL_DEPTH_8U,3);
	MatHomography = cvCreateMat( 3, 3, CV_32F);
	kernelElement = cvCreateStructuringElementEx(3,3,0,0,CV_SHAPE_ELLIPSE,NULL);
	binarySrc =  cvCreateImage(cvSize(returnW,returnH),IPL_DEPTH_8U,1);
	cvSetZero(backgroundImg);
	
}

BackGroundMapping::~BackGroundMapping(){
	cvDestroyAllWindows();
	cvReleaseMat(&MatHomography);
	cvReleaseImage(&mappingTable);	
	cvReleaseImage(&binaryResult);
    cvReleaseImage(&resultImg);
	cvReleaseImage(&backgroundImg);
	cvReleaseStructuringElement(&kernelElement);
	cvReleaseImage(&binarySrc);
}

void BackGroundMapping::setBackground(IplImage *BGImg){

    int white ,black;
 
	for(int i=0;i<mappingTable->height;i++)
	{
		for(int j=0;j<mappingTable->width;j++)
		{
			black = cvGet2D(mappingTable,i,j).val[0] + BlackValue;
			white = cvGet2D(mappingTable,i,j).val[1] - WhiteValue;	
			if(cvGet2D(BGImg,i,j).val[0] < BLACK_VALUE){
				cvSet2D(backgroundImg,i,j,cvScalar(black,black,black));
			}
			else 
				cvSet2D(backgroundImg,i,j,cvScalar(white,white,white));
		}
	}
	IplImage *temp = cvCreateImage(cvGetSize(backgroundImg),8,1) ;
	cvCopy(backgroundImg,temp);

	/*if(isDilate){
		cvDilate(temp,backgroundImg,kernelElement,1);
	}
	else*/
	cvSmooth(temp,backgroundImg,2,5);

	cvReleaseImage(&temp);
}

void BackGroundMapping::loadHomo(char *homoName, char *mTableName){

	MatHomography = (CvMat*)cvLoad(homoName);
	mappingTable = (IplImage*)cvLoad(mTableName);
}

IplImage* BackGroundMapping::getForeground(IplImage* srcImg){
	
	cvCvtColor( srcImg, resultImg, CV_RGB2GRAY);
	cvShowImage("BG",backgroundImg);
	cvShowImage("SRC",srcImg);
	cvWaitKey(1);

	CvScalar subValue = cvScalar(BGthreshold,BGthreshold,BGthreshold);
	cvSub(resultImg,backgroundImg,resultImg);
	//cvSubS(resultImg,subValue,resultImg);
	if(BGthreshold != 0){
		cvThreshold(resultImg,resultImg,BGthreshold,255,0);
	}
	cvCvtColor( resultImg, result4CImg, CV_GRAY2RGB);
	findForegroundRect(resultImg);
	return result4CImg;
}

void  BackGroundMapping::findForegroundRect(IplImage *FGImage){
	CvMemStorage* storage = cvCreateMemStorage(0);

	CvSeq* cont = 0; 

	cvFindContours( FGImage, storage, &cont, sizeof(CvContour), CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE );
	foregroundLists.clear();
	for( ; cont != 0; cont = cont->h_next )	{
		int count = cont->total; // This is number point in contour
		foregroundLists.push_back(cvContourBoundingRect(cont));

		//cvDrawContours(FGImage, cont, CV_RGB(255,255,255), CV_RGB(255,255,255), 3, 2, CV_FILLED);
		//cvShowImage("Contours",FGImage);
		//cvWaitKey(1);
	}

	cvReleaseMemStorage(&storage);
}



//int BackGroundMapping::getThreshold(){
//	return BGthreshold ;
//}
//
//void BackGroundMapping::setThreshold(int threshold){
//	BGthreshold = threshold;
//}
