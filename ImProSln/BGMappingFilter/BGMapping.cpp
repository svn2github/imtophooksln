#include "stdafx.h"
#include "BGMapping.h"


#define BLACK_VALUE 130
#define SHOW_WINDOW true


BGTag::BGTag(){
	CurTag = 0 ;
	TagID  = 0 ;
	tagTop.x = 0 ;
	tagTop.y = 0 ;
    tagDown.x = 0 ;
	tagDown.y = 0 ;
	isVisible = true ;
	tagRec.height = 0 ;
	tagRec.width  = 0 ;
	tagRec.x = 0 ; 
	tagRec.y = 0 ;
}

BGTag::~BGTag(){
	if(tagImg != NULL)
		cvReleaseImage(&tagImg) ;
} 

BackGroundMapping::BackGroundMapping(int returnW, int returnH,int camChannel,char* fileDir){

	BGthreshold = 0;
	BlackValue = 0;
	WhiteValue = 0 ;
	camFlip = false; 
	layoutFlip = false ;
    kerMat = cvCreateMat(5,5,CV_32F);
	initKernel(0.5,0.3,0.2);
	historyBG.clear();
	imgIndex = 0 ;
	tagTranNum = 0 ;
	imgH = returnH ;
	imgW = returnW ;

	for(int i = 0 ; i < imgMAX ; i ++){
		imgPool[i] = cvCreateImage(cvSize(returnW,returnH),IPL_DEPTH_8U,1);
	}
	char bgMaskName[100];
	sprintf(bgMaskName,"%s\\BackgroundCaliData\\bgMask.jpg",fileDir);
	bgMask = cvLoadImage(bgMaskName,0);

	char settingFile[100];
	sprintf(settingFile,"%s\\ProjectorCalibData\\adjustValue.txt",fileDir) ;

	
	FILE  * pFile ;
	pFile = fopen(settingFile,"r");
	fscanf(pFile ,"[ %d %d %d %d %d %d] \n",&BGthreshold , &BlackValue,&WhiteValue,&camFlip,&layoutFlip, &outputFlip);  // threshold , blackvalue , whiteValue
	mappingTable = cvCreateImage(cvSize(returnW,returnH),8,3);
	backgroundImg = cvCreateImage(cvSize(returnW,returnH),IPL_DEPTH_8U,1);
	binaryResult = cvCreateImage(cvSize(returnW,returnH),IPL_DEPTH_8U,1);
	resultImg = cvCreateImage(cvSize(returnW,returnH),IPL_DEPTH_8U,1);
	tmpImg = cvCreateImage(cvSize(returnW,returnH),IPL_DEPTH_8U,1);
	result4CImg = cvCreateImage(cvSize(returnW,returnH),IPL_DEPTH_8U,camChannel);
	MatHomography = cvCreateMat( 3, 3, CV_32F);
	kernelElement = cvCreateStructuringElementEx(3,3,0,0,CV_SHAPE_ELLIPSE,NULL);
	binarySrc =  cvCreateImage(cvSize(returnW,returnH),IPL_DEPTH_8U,1);

	char whiteBGName[100];
	sprintf(whiteBGName,"%s\\BackgroundCaliData\\BG.jpg",fileDir);
	whiteBG = cvLoadImage(whiteBGName,0);
	loadBGTranData(fileDir);	
	cvSetZero(backgroundImg);
	
	historyBG.push_back(backgroundImg);

}

BackGroundMapping::~BackGroundMapping(){
	cvDestroyAllWindows();
	cvReleaseMat(&MatHomography);
	if(mappingTable != NULL)
	cvReleaseImage(&mappingTable);	
	if(binaryResult != NULL)
	cvReleaseImage(&binaryResult);
	if(resultImg != NULL)
    cvReleaseImage(&resultImg);
	if(tmpImg != NULL)
	cvReleaseImage(&tmpImg);
	if(result4CImg != NULL)
	cvReleaseImage(&result4CImg);
	if(backgroundImg != NULL)
	cvReleaseImage(&backgroundImg);

	cvReleaseStructuringElement(&kernelElement);
	cvReleaseImage(&binarySrc);
	for(int i = 0 ; i < imgMAX; i ++){
		if(historyBG[i] != NULL){
			cvReleaseImage(&historyBG[i]);
		}
	}
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

	//cvCopy(backgroundImg,temp);
	cvFilter2D(backgroundImg,imgPool[imgIndex],kerMat);
	cvSmooth(imgPool[imgIndex],backgroundImg,2,3);
	cvCopy(backgroundImg,imgPool[imgIndex]);
	historyBG.push_back(imgPool[imgIndex]);
	imgIndex++;
	if(imgIndex == imgMAX){
		imgIndex = 0 ;
	}

}

void BackGroundMapping::loadHomo(char *homoName, char *mTableName){

	MatHomography = (CvMat*)cvLoad(homoName);
	mappingTable = (IplImage*)cvLoad(mTableName);
}

IplImage* BackGroundMapping::getForeground(IplImage* srcImg){
	
	
	int realBGindex  = 0;
	int minValue = 1e10 ;
	cvCvtColor( srcImg, resultImg, CV_RGB2GRAY);
	if(camFlip ==true){
		cvFlip(resultImg);
	}
	
	if(SHOW_WINDOW){
	cvShowImage("background",backgroundImg);
	cvShowImage("src",resultImg);
	}
	int BGSize = historyBG.size();

	for(int i = 0 ;i < BGSize; i ++){
	    cvAbsDiff(resultImg,historyBG[i],tmpImg);

		CvScalar sum = cvSum(tmpImg);
		//double sumRes = imgSum(tmpImg);
		if(sum.val[0] <= minValue){
			minValue = sum.val[0];
			realBGindex = i ;
					
		}	
	}

	if(historyBG[realBGindex] != NULL){
		
		cvSub(resultImg,historyBG[realBGindex],resultImg);
		cvAnd(resultImg,bgMask,resultImg);
		if(SHOW_WINDOW){
			cvShowImage("realBG",historyBG[realBGindex]);
		}
	
	}
	if(realBGindex != 0){
		historyBG.erase(historyBG.begin(),historyBG.begin()+realBGindex-1);
		
	}
	if(SHOW_WINDOW){
		cvShowImage("result",resultImg);
	}
	cvCvtColor(resultImg, result4CImg, CV_GRAY2RGB);

	if(BGthreshold != 0){
		cvThreshold(resultImg,resultImg,BGthreshold,255,0);
		if (SHOW_WINDOW)
		{
			cvShowImage("threshold",resultImg);
			cvWaitKey(1);
		}
	}
	findForegroundRect(resultImg);

	if(outputFlip == true){
		cvFlip(result4CImg);
	}
	return result4CImg;
}


void BackGroundMapping::initKernel(float center, float inner , float outer){

	outer = outer /16;   // average to all the outer block in 5*5 and there are 16 blocks 
	inner = inner /8 ;
	
	for(int i = 0 ; i < 5 ; i ++){
		for(int j = 0 ; j < 5 ; j ++){
			if(i == 0 || i == 4 || j == 0 || j == 4){
				cvmSet(kerMat,i,j,outer);
			}
			else if(i == 2 && j == 2){
				cvmSet(kerMat,i,j,center);
			}
			else 
				cvmSet(kerMat,i,j,inner);
		}
	}
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

void BackGroundMapping::loadBGTranData(char* fileDir){

	char tagConfigFile[100];
	sprintf(tagConfigFile,"%s\BackgroundCaliData\\tagConfig.txt",fileDir) ;

	FILE  * pFile ;
	pFile = fopen(tagConfigFile,"r");
	fscanf(pFile,"%d " ,&tagTranNum);
	for(int i = 0 ; i < tagTranNum ; i ++){
		BGTag *newTag = new BGTag() ;

		fscanf(pFile,"\n%d %d\n%f %f %f %f \n%s \n",&newTag->CurTag , &newTag->TagID,&newTag->tagTop.x,&newTag->tagTop.y,
		&newTag->tagDown.x, &newTag->tagDown.y ,&newTag->imgPath);

		newTag->tagRec.x = newTag->tagTop.x * imgW;
		newTag->tagRec.y = newTag->tagTop.y * imgH;

		newTag->tagImg = cvLoadImage(newTag->imgPath,0);
		newTag->tagRec.height = newTag->tagImg->height ;
		newTag->tagRec.width = newTag->tagImg->width ;
		newTag->isVisible = true ;
		BGTran.push_back(newTag);
	}
}


void BackGroundMapping::setTranBG(){

	cvResize(whiteBG, backgroundImg);

	for (int i = 0 ; i < tagTranNum ; i ++)
	{
		if(BGTran[i]->isVisible){
			cvSetImageROI(backgroundImg,BGTran[i]->tagRec) ;
			cvSub(backgroundImg,BGTran[i]->tagImg,backgroundImg);
			cvResetImageROI(backgroundImg);
		}
	}
	cvShowImage("tranBG",backgroundImg);
	cvWaitKey(1);


	cvCopy(backgroundImg,imgPool[imgIndex]);
	historyBG.push_back(imgPool[imgIndex]);
	imgIndex++;
	if(imgIndex == imgMAX){
		imgIndex = 0 ;
	}

}


double BackGroundMapping::imgSum(IplImage* img){
	double sumResult  = 0 ;
	for(int i=0;i<mappingTable->height;i++)
	{
		for(int j=0;j<mappingTable->width;j++)
		{		
			sumResult += img->imageData[i*img->width+j] ;
		}
	}
	return sumResult;

}

void BackGroundMapping::setLayoutType(int type){
	
}