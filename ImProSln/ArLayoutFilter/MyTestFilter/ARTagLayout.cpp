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

	//sprintf(fileName,"bch/BchThin_%04d.png",tagNum) ;
	//sprintf(fileName,"%s\\bch\\BchThin_%04d.png",tagDir,tagNum) ;
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
	TotalTag = numX * numY ;
	int noTag = 0 ;
	for(int i = 0 ;i < 100 ; i ++){

		ARtagDir[i] = tagDir[i] ;

	}
	
	float startX =Space, startY = Space ;
	float size = min((LayoutWidth-numX*Space)/numX, (LayoutHeight-numY*Space)/numY); 

	if((LayoutWidth-numX*Space)/numX > (LayoutHeight-numY*Space)/numY){
		numY = (int)LayoutHeight/(size + Space);
	}

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
	TotalTag = numTagX * numTagY ;
	int noTag = 0 ;

	float startX =Space, startY = Space ;
	float size = min((LayoutWidth-numTagX*Space)/numTagX, (LayoutHeight-numTagY*Space)/numTagY); 

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


void ARLayout::LayoutGenerate(int imageWidth , int imageHeight, int numX, int numY, int space){

	int totalTag = numX * numY ;
	float startX =space, startY = space ;
	float size = max((imageWidth-numX*space)/numX, (imageHeight-numY*space)/numY); 

	FILE *fptr = fopen("data\\layout.txt", "w" );

	fprintf( fptr, "%d %d\n", imageWidth, imageHeight);
	fprintf( fptr, "%d %d %d\n", numX, numY, space);

	for(int i = 0 ; i < numX ; i ++){
		for(int j = 0 ; j< numY ; j ++){						 
			fprintf( fptr, "%d %f %f %f \n", i* numY + j, startX,startY,size); 
			startY = startY + space + size;
		}
		startX = startX + space + size;
		startY = space;
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
void ARLayout::setTagDir(char* Dir){

	char fileName[100] ;

	//sprintf(fileName,TEXT("%s\\%s\0"), szCurrentDir, BITMAP_NAME);
	sprintf(fileName,"%s\\bch\BchThin_%04d.png",Dir,3) ;

}