#include "stdafx.h"
#include "ARTagLayout.h"

ARTag::ARTag(){
	tagNum = 0;
	PosX = 0;
	PosY = 0;
	tagSize = 1;
	reDraw = true ;
	isVisible = false;		
}

ARTag::ARTag(int Num, float x, float y, float size, bool visible,char* tagDir){
	tagNum = Num;
	PosX = x;
	PosY = y;
	tagSize = size;
	center.x = x+size/2;
	center.y = y+size/2;
	isVisible = visible;	
	reDraw = true ;
	char fileName[100] ;

	sprintf(fileName,"%s\\ARToolKitPlus_AllMarkers\\marker_%03d.png",tagDir,tagNum) ;
	
	IplImage* tmptag = cvLoadImage(fileName,0);
	tagImage = cvCreateImage(cvSize(tagSize,tagSize),8,1);
	cvResize(tmptag,tagImage,CV_INTER_NN);
	cvReleaseImage(&tmptag);

}
void ARTag::setVisible(bool state){
	isVisible =  state;
}


void ARTag::changeSize(float size){
	tagSize = size; 
}

ARLayout::ARLayout(){
	LayoutWidth = 0;
	LayoutHeight = 0;
	TotalTag = 0;
	numTagX = 0;
	numTagY = 0 ;
	Space =0 ;

}
ARLayout::ARLayout(int imageWidth , int imageHeight, int numX, int numY, int tagspace, char* tagDir){
	LayoutWidth = imageWidth;
	LayoutHeight = imageHeight;
	layoutImage = cvCreateImage(cvSize(LayoutWidth,LayoutHeight),8,1);
	numTagX = numX ;
	numTagY = numY ;
	Space = tagspace;
	float size = tagSizeArrange();

	TotalTag = numX * numY ;
	int noTag = 0 ;
	for(int i = 0 ;i < 100 ; i ++){

		ARtagDir[i] = tagDir[i] ;

	}
	
	float startX =Space, startY = Space ;
	for(int i = 0 ; i < numX ; i ++){
		for(int j = 0 ; j< numY ; j ++){

			ARTag *tag = new ARTag(i* numY + j,startX,startY,size,true,ARtagDir) ;
			startY = startY + Space + size;
			Layout.push_back(*tag) ;
		}
		startX = startX + Space + size;
		startY = Space;
	}

	combineTagtoIplImage();
}

void ARLayout::changeLayout(){

	Layout.clear();
	float size = tagSizeArrange();

	TotalTag = numTagX * numTagY ;
	int noTag = 0 ;

	float startX =Space, startY = Space ;

	for(int i = 0 ; i < numTagX ; i ++){
		for(int j = 0 ; j< numTagY ; j ++){

			ARTag *tag = new ARTag(i* numTagY + j,startX,startY,size,true,ARtagDir) ;
			startY = startY + Space + size;

			Layout.push_back(*tag) ;
		}
		startX = startX + Space + size;
		startY = Space;
	}

	combineTagtoIplImage();

}

void ARLayout::setNumTagX(int numX){

	numTagX = numX ;
}

void ARLayout::setNumTagY(int numY){

	numTagY = numY ;
}

void ARLayout::setSpace(int tagSpace){

	Space = tagSpace ;
}

void ARLayout::LayoutGenerate(int imageWidth , int imageHeight, int numX, int numY, int tagspace){
	
	numTagX = numX ;
	numTagY = numY ;
	Space = tagspace;
	float size = tagSizeArrange();

	TotalTag = numTagX * numTagY ;
	float startX =Space, startY = Space ;

	FILE *fptr = fopen("data\\layout.txt", "w" );

	fprintf( fptr, "%d %d\n", imageWidth, imageHeight);
	fprintf( fptr, "%d %d %d\n", numTagX, numTagY, Space);

	for(int i = 0 ; i < numTagX ; i ++){
		for(int j = 0 ; j< numTagY ; j ++){						 
			fprintf( fptr, "%d %f %f %f \n", i* numTagY + j, startX,startY,size); 
			startY = startY + Space + size;
		}
		startX = startX + Space + size;
		startY = Space;
	}

	fclose( fptr );
}

void ARLayout ::LoadLayout(char * fileName){
	FILE *fptr = fopen(fileName, "r" );

	fscanf( fptr, "%d %d\n", &LayoutWidth, &LayoutHeight);
	fscanf( fptr, "%d %d %d\n", &numTagX, &numTagY,&Space);
	TotalTag = numTagX * numTagY ;
	int noTag ;
	float startX, startY, size ;

	for(int i = 0 ; i < TotalTag ; i ++){

		fscanf( fptr, "%d %f %f %f \n",&noTag, &startX,&startY,&size); 
		ARTag *tag = new ARTag(noTag, startX,startY,size,true,fileName) ;		 
		Layout.push_back(*tag) ;		
	}

	fclose( fptr );
}


void ARLayout::checkTag(float x, float y){
	for(int i = 0 ; i < TotalTag; i ++){
		if(x > Layout[i].PosX && x < Layout[i].PosX+Layout[i].tagSize && y > Layout[i].PosY && y < Layout[i].PosY+Layout[i].tagSize){
			if(Layout[i].isVisible == true){
				Layout[i].setVisible(false) ;	
			}
			else 
				Layout[i].setVisible(true) ;	
		}

	}
}

void ARLayout::combineTagtoIplImage(){

	cvSet(layoutImage,cvScalar(255,0,0));
	for(int i = 0 ; i < TotalTag; i ++){

		if(Layout[i].isVisible == true){
			CvSize size = cvGetSize(Layout[i].tagImage);
			layoutImage->origin = Layout[i].tagImage->origin; 
			cvSetImageROI(layoutImage, cvRect(Layout[i].PosX,Layout[i].PosY, size.width, size.height));
			cvCopy(Layout[i].tagImage, layoutImage);
		}
	}
	cvResetImageROI(layoutImage);
	cvFlip(layoutImage,layoutImage);  // for dShow to show the right direction of tag

	// **show the layoutImage in opencv will made the Dshow not work
	/*cvNamedWindow("test");
	cvShowImage("test",layoutImage);
	cvWaitKey(0);*/  
}


IplImage* ARLayout::getLayout(){

	return layoutImage;

}
float ARLayout::tagSizeArrange(){
	int size = max((LayoutWidth-numTagX*Space)/numTagX, (LayoutHeight-numTagY*Space)/numTagY); 

	if((LayoutWidth-numTagX*Space)/numTagX > (LayoutHeight-numTagY*Space)/numTagY){
		numTagY = (int)LayoutHeight/(size + Space);
	}
	else if((LayoutWidth-numTagX*Space)/numTagX < (LayoutHeight-numTagY*Space)/numTagY){
		numTagX = (int)LayoutWidth/(size + Space);
	}
	return size; 
}