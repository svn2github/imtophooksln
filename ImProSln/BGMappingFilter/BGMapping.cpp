#include "stdafx.h"
#include "BGMapping.h"

#define BLACK_VALUE 130


BackGroundMapping::BackGroundMapping(int returnW, int returnH,int camChannel,char* fileDir){

	BGthreshold = 0;
	BlackValue = 0;
	WhiteValue = 0 ;
	camFlip = false; 
	layoutFlip = false ;

	char settingFile[100];

	sprintf(settingFile,"%s\\ProjectorCalibData\\adjustValue.txt",fileDir) ;

	FILE  * pFile ;
	pFile = fopen(settingFile,"r");
	fscanf(pFile ,"[ %d %d %d %d %d %d] \n",&BGthreshold , &BlackValue,&WhiteValue,&camFlip,&layoutFlip, &outputFlip);  // threshold , blackvalue , whiteValue
	mappingTable = cvCreateImage(cvSize(returnW,returnH),8,3);
	backgroundImg = cvCreateImage(cvSize(returnW,returnH),IPL_DEPTH_8U,1);
	binaryResult = cvCreateImage(cvSize(returnW,returnH),IPL_DEPTH_8U,1);
	resultImg = cvCreateImage(cvSize(returnW,returnH),IPL_DEPTH_8U,1);
	result4CImg = cvCreateImage(cvSize(returnW,returnH),IPL_DEPTH_8U,camChannel);
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
	if(layoutFlip == true){
		cvFlip(BGImg);
	}
	int BGchannel = BGImg->nChannels;
	int mapChannel = mappingTable->nChannels;

	for(int i=0;i<mappingTable->height;i++)
	{
		for(int j=0;j<mappingTable->width;j++)
		{
			black = (int)(uchar)mappingTable->imageData[i*mappingTable->width*mapChannel+j*mapChannel] + BlackValue;
			white = (int)(uchar)mappingTable->imageData[i*mappingTable->width*mapChannel+j*mapChannel+1] -WhiteValue;
			
			if((int)(uchar)BGImg->imageData[i*BGImg->widthStep+j*BGchannel]< BLACK_VALUE){
				backgroundImg->imageData[i*backgroundImg->width+j] = black;
			}
			else {
				backgroundImg->imageData[i*backgroundImg->width+j] = white;
			}
	
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
	if(camFlip ==true){
	cvFlip(resultImg);
	}
	CvScalar subValue = cvScalar(BGthreshold,BGthreshold,BGthreshold);
	/*cvShowImage("background",backgroundImg);
	cvShowImage("src",resultImg);*/
	cvSub(resultImg,backgroundImg,resultImg);
	/*cvShowImage("result",resultImg);
	cvWaitKey(1);*/

	if(BGthreshold != 0){
		cvThreshold(resultImg,resultImg,BGthreshold,255,0);
	}
	cvCvtColor( resultImg, result4CImg, CV_GRAY2RGB);
	findForegroundRect(resultImg);
	if(outputFlip == true){
		cvFlip(result4CImg);
	}
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
	}

	cvReleaseMemStorage(&storage);
}
