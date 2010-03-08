#include "BackGroundHomo.h"

IplImage*camImage;
CvPoint camPoint[4];
float srcP[4][2] = {0};
int pointCount = 0 ;
bool Finish = false ;
float dst[] = { 0, 0,
WIDTH-1, 0,
WIDTH-1, HEIGHT-1,
0, HEIGHT-1
};
float zero[3][3] = {0};



void mouseClick(int event, int x, int y, int flags, void* param){

    CvPoint pot;
	switch( event )
	{
	case CV_EVENT_LBUTTONDOWN:
		
		if(Finish == true)
			break ;
		srcP[pointCount][0] = x;
		srcP[pointCount][1] = y ;
    	pointCount++ ;
		if (pointCount >=4)
		{
			Finish = true ;
		}
		break;
	}
}

float Distance(CvPoint P1, CvPoint P2){
	float xTemp = P1.x-P2.x;
	float yTemp = P1.y-P2.y;
	return sqrt(pow(xTemp,2) + pow(yTemp,2)) ;
}

BackGroundHomo::BackGroundHomo(){
 mappingTable = cvCreateImage(cvSize(WIDTH,HEIGHT),8,3);
 gray0Image = cvCreateImage(cvSize(WIDTH,HEIGHT),IPL_DEPTH_8U,1);
 gray255Image = cvCreateImage(cvSize(WIDTH,HEIGHT),IPL_DEPTH_8U,1);
 backgroundImg = cvCreateImage(cvSize(WIDTH,HEIGHT),IPL_DEPTH_8U,1);
 resultImg = cvCreateImage(cvSize(WIDTH,HEIGHT),IPL_DEPTH_8U,1);
 MatHomography = cvCreateMat( 3, 3, CV_32F);
}

BackGroundHomo::~BackGroundHomo(){
	cvReleaseMat(&MatHomography);
	cvReleaseImage(&mappingTable);
	cvReleaseImage(&gray0Image);
	cvReleaseImage(&gray255Image);
	cvReleaseImage(&resultImg);
	cvReleaseImage(&backgroundImg);

}


void BackGroundHomo::loadHomo(char* homoName , char*mappingName){
	MatHomography = (CvMat*)cvLoad(homoName);
	mappingTable = (IplImage*)cvLoad(mappingName);

	int white ,black;
	for(int i=0;i<mappingTable->height;i++)
	{
		for(int j=0;j<mappingTable->width;j++)
		{
			black = cvGet2D(mappingTable,i,j).val[0];
			white = cvGet2D(mappingTable,i,j).val[1];			
			if(cvGet2D(backgroundImg,i,j).val[0] == 0){
				cvSet2D(backgroundImg,i,j,cvScalar(black,black,black));
			}
			else 
				cvSet2D(backgroundImg,i,j,cvScalar(white,white,white));
		}
	}

	//IplImage * tmpImg = cvCreateImage(cvSize(backgroundImg->width,backgroundImg->height),8,1);
	//cvDilate(backgroundImg,tmpImg,0,1);
	//cvDilate(tmpImg,backgroundImg,0,1);
	//cvReleaseImage(& tmpImg);
}

void BackGroundHomo::changeBG(IplImage* BGImg){

	int white ,black;
	for(int i=0;i<mappingTable->height;i++)
	{
		for(int j=0;j<mappingTable->width;j++)
		{
			black = cvGet2D(mappingTable,i,j).val[0];
			white = cvGet2D(mappingTable,i,j).val[1];			
			if(cvGet2D(BGImg,i,j).val[0] == 0){
				cvSet2D(BGImg,i,j,cvScalar(black,black,black));
			}
			else 
				cvSet2D(BGImg,i,j,cvScalar(white,white,white));
		}
	}

}

void BackGroundHomo::setBackground(IplImage* markBGImg){

	cvNamedWindow("BackgroundImage") ;

	char Input;
	while(Finish == false){
		cvShowImage("BackgroundImage",markBGImg);
		Input = cvWaitKey(1) ;
		cvSetMouseCallback("BackgroundImage",mouseClick) ;	
	}
	// source Point 1--->2
	              //     |
	              //4<---3

	srcPoint =  cvMat(4,2,CV_32F,&srcP);
	dstPoint =  cvMat(4,2,CV_32F,&dst);	

	cvFindHomography(&srcPoint,&dstPoint,MatHomography);
	cvSave("HomoMat.txt",MatHomography);
}
void BackGroundHomo ::warpImg(IplImage* srcImg){

	IplImage * saveImg =  cvCreateImage(cvGetSize(resultImg),8,1);
	cvWarpPerspective(srcImg,resultImg,MatHomography);
	cvCopy(resultImg,saveImg);
	cvNamedWindow("homo");
	cvShowImage("homo",resultImg);
	cvSub(resultImg,backgroundImg,resultImg);
	cvThreshold(resultImg,resultImg,100,255,0);
	/*cvNamedWindow("Background");
	cvShowImage("Background",backgroundImg);*/
	cvNamedWindow("result");
	cvShowImage("result",resultImg);
	
	char input = cvWaitKey(1);
	if(input == 's'){
		cvSaveImage("oriImg.jpg",resultImg);
		cvSaveImage("BKImg.jpg",backgroundImg);
		cvSaveImage("resultImg.jpg",resultImg);
	}
	cvReleaseImage(&saveImg);
}

void BackGroundHomo::warpCaliCapture(IplImage* srcImg,IplImage* dstImg){

	cvWarpPerspective(srcImg,dstImg,MatHomography);
}

void BackGroundHomo::warpCaliImg(char* srcFileName,IplImage* dstImg){
	
	IplImage * srcImg = cvLoadImage(srcFileName,0);
	cvWarpPerspective(srcImg,dstImg,MatHomography);

	/*cvShowImage("warp",dstImg);
	cvWaitKey(0);*/

	// set value pixel by pixel
	//float oriP[3][1],newP[3][1],homo[3][3] ;
	//CvMat oriPoint = cvMat(3,1,CV_32F,oriP) ;
	//CvMat newPoint = cvMat(3,1,CV_32F,newP) ;
	//CvMat iMatHomo = cvMat(3,3,CV_32F,homo) ;	

	//cvInvert(&matHomo,&iMatHomo);
	//int oriX, oriY ;

	//for (int h = 0 ; h <HEIGHT ; h ++){
	//	for(int w = 0; w < WIDTH ; w ++)
	//	{
	//		newPoint.data.fl[0]= (float)h/HEIGHT;   // normalize in 0~1
	//	    newPoint.data.fl[1]= (float)w/WIDTH;
	//		newPoint.data.fl[2]= 1 ;

	//		cvmMul(&iMatHomo,&newPoint,&oriPoint);
	//		oriX = oriPoint.data.fl[0];
	//		oriY = oriPoint.data.fl[1];
	//		dstImg->imageData[h*WIDTH+w] = camImage->imageData[oriY*camImage->width+oriX];
	//	   // cvSet2D(dstImg,w,h,cvGet2D(srcImg,oriX,oriY));
	//	}
	//}

}
void BackGroundHomo::buildMappingTable(){
	
		CvScalar Scalar1;
			cvShowImage("checkBG",backgroundImg);
		int white ,black;
		for(int i=0;i<mappingTable->height;i++)
		{
			for(int j=0;j<mappingTable->width;j++)
			{
			
				Scalar1.val[0] = cvGet2D(gray0Image,i,j).val[0];
				Scalar1.val[1] = cvGet2D(gray255Image,i,j).val[0];
				black = Scalar1.val[0];
				white = Scalar1.val[1];
				cvSet2D(mappingTable,i,j,Scalar1);
				if(cvGet2D(backgroundImg,i,j).val[0] < 128){
					cvSet2D(backgroundImg,i,j,cvScalar(black,black,black));
				}
				else 
					cvSet2D(backgroundImg,i,j,cvScalar(white,white,white));
			}
		}
	/*	IplImage * newMappingTable = cvCreateImage(cvSize(640,480),8,3);

		cvResize(mappingTable,newMappingTable);*/
		cvSave("mTable.txt",mappingTable);
	
}

int BackGroundHomo::getMappingValue(float x, float y , int oriIntensity){   // x and y are in 0~1 
	float newIntensity ;

	float length = cvGet2D(mappingTable,x,y).val[1] - cvGet2D(mappingTable,x,y).val[0];
	newIntensity = ((float)oriIntensity/ length )*255;
	return newIntensity;
}

void BackGroundHomo::convertImg(IplImage* inputImg){

	for(int h = 0 ; h < inputImg->height ; h ++){
		for (int w = 0 ; w < inputImg->width ; w ++)
		{
			int oriIntensity = inputImg->imageData[h*inputImg->width + w] ;
			inputImg->imageData[h*inputImg->width + w] = getMappingValue(h,w,oriIntensity);
		}
	}
}