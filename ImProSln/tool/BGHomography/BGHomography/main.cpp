#include "BackGroundHomo.h"
#define CALIBRATION true
#define CAMWIDTH 640
#define CAMHEIGHT 480

void main(){
	BackGroundHomo* bg = new BackGroundHomo() ;

	bool caliFinish = false ;
	bool whiteOK = false ;
	
	CvCapture *capture;	
	IplImage *frame;
	IplImage * whiteBG = cvLoadImage("white.bmp",0);
	IplImage * blackBG = cvLoadImage("black.bmp",0);
	IplImage * tagBG = cvLoadImage("bg.bmp",0);
	IplImage *binary_img = cvCreateImage(cvSize(CAMWIDTH,CAMHEIGHT),8,1);
	cvResize(tagBG,bg->backgroundImg );

	capture =cvCaptureFromCAM(0);
	cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH, CAMWIDTH);
	cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT, CAMHEIGHT); 
	cvNamedWindow("Webcam",0);

	if(CALIBRATION){
		while(caliFinish == false){

			frame = cvQueryFrame(capture);
			cvCvtColor( frame, binary_img, CV_RGB2GRAY );
			cvShowImage("Webcam",frame);
			cvNamedWindow("bgCali");
			if(whiteOK == false){
				cvShowImage("bgCali",whiteBG);
			}
			char input;
			input = cvWaitKey(1);
			if(input == 'w'){
				bg->setBackground(binary_img);
				bg->warpCaliCapture(binary_img,bg->gray255Image);
				whiteOK = true ;
				
			}
			if(whiteOK == true){
				cvShowImage("bgCali",blackBG);
				cvWaitKey(1);	
				if(input == 'b'){
					bg->warpCaliCapture(binary_img,bg->gray0Image);
					caliFinish = true ;
					cvShowImage("bgCali",tagBG);
				}
			}
			
		}
		bg->buildMappingTable();
	}

	else{
		bg->loadHomo("HomoMat.txt","mTable.txt");
		
	}
	IplImage *temp = cvCreateImage(cvGetSize(bg->backgroundImg),8,1) ;
	cvCopy(bg->backgroundImg,temp) ;

	IplConvKernel* element = cvCreateStructuringElementEx(5,5,0,0,CV_SHAPE_ELLIPSE,NULL);
	
	//cvDilate(temp,bg->backgroundImg,element,1);
	cvSmooth(temp,bg->backgroundImg ,2,9);
	//cvSmooth(temp,bg->backgroundImg ,2,9);
	cvNamedWindow("Background");
	cvShowImage("Background",bg->backgroundImg);


	while(true)
	{
		frame = cvQueryFrame(capture);
		cvCvtColor( frame, binary_img, CV_RGB2GRAY );
		bg->warpImg(binary_img);
	}
	
	cvReleaseCapture(&capture);
	cvReleaseImage(&frame);
	cvDestroyWindow("Webcam");
}