#include "stdafx.h"
#include "BGMapping.h"


#define BLACK_VALUE 130
#define SHOW_WINDOW false
#define SVAE_IMG  false 



BGTag::BGTag(){
	CurTag = 0 ;
	TagID  = 0 ;
	tagTop.x = 0 ;
	tagTop.y = 0 ;
    tagDown.x = 0 ;
	tagDown.y = 0 ;
	isVisible = false ;
	tagRec.height = 0 ;
	tagRec.width  = 0 ;
	tagRec.x = 0 ; 
	tagRec.y = 0 ;
}

BGTag::~BGTag(){
	if(tagImg != NULL){
		cvReleaseImage(&tagImg) ;
		tagImg = NULL;
	} 
}

BGCandidateImgPool::BGCandidateImgPool(){
	
	 isBlendImg = false;
	 layoutType = 0;
	 layoutTotalTag = 0;
	 layoutVisibleTable.clear();

}
BGCandidateImgPool::~BGCandidateImgPool(){
	if(BGimg != NULL){
		cvReleaseImage(&BGimg);
		BGimg = NULL;
	}
	layoutVisibleTable.clear();
}

void BGCandidateImgPool::setToPool(IplImage* background, bool Blend){
	cvCopy(background,BGimg);
	isBlendImg = Blend; 
}


BGCandidate ::BGCandidate(){
}

BGCandidate ::~BGCandidate(){
}


void BGCandidate::init(int imgH, int imgW){
	for(int i = 0 ; i <imgMAX ; i ++){
		unusedImg.push_back(i);
	}
	for(int i = 0 ;i < imgMAX ; i ++){
		bgImgPool[i].BGimg = cvCreateImage(cvSize(imgW,imgH),IPL_DEPTH_8U,1);
	}
}

int BGCandidate::getUnusedImgIndex(){
	int unusedNo = 0 ;
	
	if(unusedImg.empty() == true){
		unusedNo = usedImg[0];
		usedImg.erase(usedImg.begin());
		usedImg.push_back(unusedNo);
	}
	else{
		unusedNo = unusedImg[0];
		unusedImg.erase(unusedImg.begin());
		usedImg.push_back(unusedNo);
	}
	return unusedNo;
}

int BGCandidate::getUsedImgCount(){
	return usedImg.size();
}

IplImage* BGCandidate::getUsedImg(int index){
	return bgImgPool[usedImg[index]].BGimg;
//return imgPool[usedImg[index]];
}

void BGCandidate::setToUnused(int index){

	for(int i = 0 ; i < index ; i ++){
		unusedImg.push_back(usedImg[0]);
		usedImg.erase(usedImg.begin());
	}
} 

BackGroundMapping::BackGroundMapping(int returnW, int returnH,int camChannel,char* fileDir){

	BGthreshold = 0;
	erodeValue = 0;
	subValue = 0 ;
	camFlip = false; 
	layoutFlip = false ;
    kerMat = cvCreateMat(5,5,CV_32F);
	initKernel(0.5,0.3,0.2);
	historyBG.clear();
	imgIndex = 0 ;
	tagTranNum = 0 ;
	imgH = returnH ;
	imgW = returnW ;

	candidate.init(imgH,imgW);

	char bgMaskName[100];
	sprintf(bgMaskName,"%s\\BackgroundCaliData\\bgMask.jpg",fileDir);
	bgMask = cvLoadImage(bgMaskName,0);

	char settingFile[100];
	sprintf(settingFile,"%s\\ProjectorCalibData\\adjustValue.txt",fileDir) ;

	FILE  * pFile ;
	pFile = fopen(settingFile,"r");
	fscanf(pFile ,"[ %d %d %d %d %d %d] \n",&BGthreshold , &erodeValue,&subValue,&camFlip,&layoutFlip, &outputFlip);  // threshold , blackvalue , whiteValue
	
	mappingTable = cvCreateImage(cvSize(returnW,returnH),8,3);
	backgroundImg = cvCreateImage(cvSize(returnW,returnH),IPL_DEPTH_8U,1);
	blendBG = cvCreateImage(cvSize(returnW,returnH),IPL_DEPTH_8U,1);

	camImg = cvCreateImage(cvSize(returnW,returnH),IPL_DEPTH_8U,1);
	tmpImg = cvCreateImage(cvSize(returnW,returnH),IPL_DEPTH_8U,1);
	result4CImg = cvCreateImage(cvSize(returnW,returnH),IPL_DEPTH_8U,camChannel);
	MatHomography = cvCreateMat( 3, 3, CV_32F);
	kernelElement = cvCreateStructuringElementEx(3,3,0,0,CV_SHAPE_ELLIPSE,NULL);

	char whiteBGName[100];
	sprintf(whiteBGName,"%s\\BackgroundCaliData\\BG.png",fileDir);
	whiteBG = cvLoadImage(whiteBGName,0);

	loadBGTranData(fileDir);	
	cvSetZero(backgroundImg);

	isBlend = false ;
	
}

BackGroundMapping::~BackGroundMapping(){
	cvDestroyAllWindows();
	cvReleaseMat(&MatHomography);

	if(mappingTable != NULL){
	cvReleaseImage(&mappingTable);
	mappingTable = NULL ;
	}
	if( camImg != NULL){
		cvReleaseImage(&camImg);
		camImg = NULL ;
	}
	if(tmpImg != NULL){
		cvReleaseImage(&tmpImg);
		tmpImg = NULL; 
	}
	if(result4CImg != NULL){
		cvReleaseImage(&result4CImg);
		result4CImg = NULL ;
	}
	if(backgroundImg != NULL){
		cvReleaseImage(&backgroundImg);
		backgroundImg = NULL ;
	}
	if(blendBG != NULL){
		cvReleaseImage(&blendBG);
		blendBG = NULL ;
	}
	cvReleaseStructuringElement(&kernelElement);
	for(int i = 0 ; i < imgMAX; i ++){
		if(historyBG[i] != NULL){
			cvReleaseImage(&historyBG[i]);
			historyBG[i] = NULL;
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
			black = (int)(uchar)mappingTable->imageData[i*mappingTable->width*mapChannel+j*mapChannel] + erodeValue;
			white = (int)(uchar)mappingTable->imageData[i*mappingTable->width*mapChannel+j*mapChannel+1] -subValue;
			
			if((int)(uchar)BGImg->imageData[i*BGImg->widthStep+j*BGchannel]< BLACK_VALUE){
				backgroundImg->imageData[i*backgroundImg->width+j] = black;
			}
			else {
				backgroundImg->imageData[i*backgroundImg->width+j] = white;
			}
	
		}
	}		

	//cvCopy(backgroundImg,temp);
	//cvFilter2D(backgroundImg,imgPool[imgIndex],kerMat);
	//cvSmooth(imgPool[imgIndex],backgroundImg,2,3);
	//cvCopy(backgroundImg,imgPool[imgIndex]);
	//
	/*historyBG.push_back(imgPool[imgIndex]);
	imgIndex++;
	if(imgIndex == imgMAX){
		imgIndex = 0 ;
	}*/

}

void BackGroundMapping::loadHomo(char *homoName, char *mTableName){

	MatHomography = (CvMat*)cvLoad(homoName);
	mappingTable = (IplImage*)cvLoad(mTableName);
}

int saveIndex = 0 ;

IplImage* BackGroundMapping::getForeground(IplImage* srcImg){

	isBlend = false ;
	
	int realBGindex  = 0;
	int minValue = 1e10 ;
	int candSubValue = subValue - 10 ;
	if(candSubValue > 0){
		candSubValue = -candSubValue;
	}

	cvCvtColor( srcImg, camImg, CV_RGB2GRAY);
	if(camFlip == true){
		cvFlip(camImg);
	}

	int BGCandiSize = candidate.usedImg.size();

	for(int i = 0 ;i < BGCandiSize; i ++){
		cvAddS(candidate.getUsedImg(i),cvScalar(candSubValue,candSubValue,candSubValue),tmpImg);
		if(SHOW_WINDOW){
			char frame[MAX_PATH];
			sprintf(frame ,"%d",i) ;
			cvShowImage(frame,tmpImg);
		}
	    cvAbsDiff(camImg,tmpImg,tmpImg);
		cvErode(tmpImg,tmpImg,NULL,erodeValue);
		
		if(camImg->width == bgMask->width){  
			cvAnd(tmpImg,bgMask,tmpImg);
		}

		if(SHOW_WINDOW){
			char frame[MAX_PATH];
			sprintf(frame ,"sub%d",i) ;
			cvShowImage(frame,tmpImg);
		}
		CvScalar sum = cvSum(tmpImg);
		if(sum.val[0] < minValue){
			minValue = sum.val[0];
			realBGindex = i;			
		}	
	}
	
	if(candidate.getUsedImg(realBGindex) != NULL){
		cvAddS(candidate.getUsedImg(realBGindex),cvScalar(subValue,subValue,subValue),tmpImg);
			
		cvShowImage("BG" , tmpImg);
		cvShowImage("src", camImg);				
		if(minValue > 300000 && SVAE_IMG == true){
			char saveName[MAX_PATH] ;
			sprintf(saveName,"debugImg\\%d_src.jpg",saveIndex);
			cvSaveImage(saveName,camImg);
			for(int candS = 0 ; candS < BGCandiSize ; candS++){
				sprintf(saveName,"debugImg\\%d_cand_%d.jpg",saveIndex,candS);
				cvSaveImage(saveName,candidate.getUsedImg(candS));

			}
		}
		cvSub(camImg,tmpImg,camImg);
		if(camImg->width == bgMask->width){
			cvAnd(camImg,bgMask,camImg);
		}
		cvShowImage("sub", camImg);	
		cvWaitKey(1);
	}

	if(minValue > 300000 && SVAE_IMG == true){
		char saveName[MAX_PATH] ;
		sprintf(saveName,"debugImg\\%d_BG_%d.jpg",saveIndex,realBGindex);
		cvSaveImage(saveName,tmpImg);
		sprintf(saveName,"debugImg\\sub_%d.jpg",saveIndex);
		cvSaveImage(saveName,camImg);
		saveIndex++;
	}

	if(realBGindex != 0){
		candidate.setToUnused(realBGindex);
	}

	cvErode(camImg,camImg,NULL,erodeValue);
	cvDilate(camImg,camImg,NULL,erodeValue);
	if(SHOW_WINDOW){
		cvShowImage("erode",camImg);
		cvWaitKey();
	}

	cvCvtColor(camImg, result4CImg, CV_GRAY2RGB);

	if(BGthreshold != 0){
		cvThreshold(camImg,camImg,BGthreshold,255,0);
	}
	findForegroundRect(camImg);

	if(outputFlip == true){
		cvFlip(result4CImg);
	}
	if(SHOW_WINDOW){
	cvDestroyAllWindows();
	}

	if(candidate.bgImgPool[realBGindex].isBlendImg == true){
		isBlend = true ;
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
		newTag->isVisible = false ;
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

	int preIndex = candidate.usedImg.size()-1;
	int index = candidate.getUnusedImgIndex();
	
	cvCopy(backgroundImg,candidate.bgImgPool[index].BGimg);
	candidate.bgImgPool[index].layoutTotalTag = tagTranNum ;
	candidate.bgImgPool[index].isBlendImg = false ;
	
	for(int i = 0 ; i < tagTranNum ; i ++){
		bool tmpVisible = BGTran[i]->isVisible ;
		candidate.bgImgPool[index].layoutVisibleTable.push_back(tmpVisible);
	}


	// add blend Img into the bgImgPool
	if(preIndex >= 0){
		cvAddWeighted(candidate.bgImgPool[index].BGimg,0.5,candidate.bgImgPool[preIndex].BGimg,0.5,0,blendBG);
		int blendIndex = candidate.getUnusedImgIndex();
		
		cvCopy(blendBG,candidate.bgImgPool[blendIndex].BGimg);
		candidate.bgImgPool[blendIndex].layoutTotalTag = tagTranNum ;
		candidate.bgImgPool[blendIndex].isBlendImg = true ;

		for(int i = 0 ; i < tagTranNum ; i ++){
			bool tmpVisible = BGTran[i]->isVisible ;
			candidate.bgImgPool[blendIndex].layoutVisibleTable.push_back(tmpVisible);
		}
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
