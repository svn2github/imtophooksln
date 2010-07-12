#include "stdafx.h"
#include "BGMapping.h"

#define MAX_REF 2
#define SAVE_THRES 150000
#define USEMASK true // for single camera 



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
	refCount = 0;
	if(tagVisibleTable != NULL){
		tagVisibleTable = NULL;
	}

}
BGCandidateImgPool::~BGCandidateImgPool(){
	if(BGimg != NULL){
		cvReleaseImage(&BGimg);
		BGimg = NULL;
	}
	layoutVisibleTable.clear();
	if(tagVisibleTable != NULL){
		tagVisibleTable = NULL;
	}
}

void BGCandidateImgPool::setToPool(IplImage* background, bool Blend){
	cvCopy(background,BGimg);
	isBlendImg = Blend; 
}


BGCandidate ::BGCandidate(){
}

BGCandidate ::~BGCandidate(){
	for(int i = 0 ;i < imgMAX ; i ++){
		if (bgImgPool[i].BGimg != NULL)
		{
			cvReleaseImage(&bgImgPool[i].BGimg);
			bgImgPool[i].BGimg = NULL;
		}
	}
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
}

int BGCandidate ::getUsedImgID(int index){
	return usedImg[index];

}

void BGCandidate::setToUnused(int index){

	/*for(int i = 0 ; i < index ; i ++){
		bgImgPool[usedImg[i]].refCount++;
		if(bgImgPool[usedImg[i]].refCount >= MAX_REF){
			bgImgPool[usedImg[i]].refCount = 0 ;
			unusedImg.push_back(usedImg[0]);
			usedImg.erase(usedImg.begin());
			index -- ;
		}
	}*/

	for(int i = 0 ; i < index ; i ++){
		unusedImg.push_back(usedImg[0]);
		usedImg.erase(usedImg.begin());
	}
} 

BackGroundMapping::BackGroundMapping(int returnW, int returnH,int camChannel,char* fileDir){

	ROIthreshold = 0;
	erodeValue = 0;
	absDiffsubValue = 0 ;
	BGadjustValue = 0 ;

	camFlip = false; 
	layoutFlip = false ;
	showWindow = true; 
	saveImage = false ;


	historyBG.clear();
	imgIndex = 0 ;
	tagTranNum = 0 ;
	imgH = returnH ;
	imgW = returnW ;
	m_layoutIndex = 0 ;
	isUsingMask = false ;

	candidate.init(imgH,imgW);

	char bgMaskName[100];
	GetCurrentDirectoryW(_MAX_PATH, curDir);

	sprintf(bgMaskName,"%s\\BackgroundCaliData\\bgMask.jpg",fileDir);
	bgMask = cvLoadImage(bgMaskName,0);

	char settingFile[100];
	sprintf(settingFile,"%s\\ProjectorCalibData\\adjustValue.txt",fileDir) ;

	FILE  * pFile ;
	pFile = fopen(settingFile,"r");
	fscanf(pFile ,"[ %d %d %d %d %d %d %d %d %d ] \n",&ROIthreshold , &absDiffsubValue,&BGadjustValue,&erodeValue,&camFlip,&layoutFlip, &outputFlip, &showWindow, &saveImage);  // threshold , blackvalue , whiteValue

	mappingTable = cvCreateImage(cvSize(returnW,returnH),8,3);
	backgroundImg = cvCreateImage(cvSize(returnW,returnH),IPL_DEPTH_8U,1);
	blendBG = cvCreateImage(cvSize(returnW,returnH),IPL_DEPTH_8U,1);

	camImg = cvCreateImage(cvSize(returnW,returnH),IPL_DEPTH_8U,1);
	absDiffImg = cvCreateImage(cvSize(returnW,returnH),IPL_DEPTH_8U,1);
	subImg = cvCreateImage(cvSize(returnW,returnH),IPL_DEPTH_8U,1);
	tmpImg = cvCreateImage(cvSize(returnW,returnH),IPL_DEPTH_8U,1);
	thresholdROIImg = cvCreateImage(cvSize(returnW,returnH),IPL_DEPTH_8U,1);
	erodeImg = cvCreateImage(cvSize(returnW,returnH),IPL_DEPTH_8U,1);

	spotMask= cvCreateImage(cvSize(returnW,returnH),IPL_DEPTH_8U,1);
	cvResize(bgMask,spotMask,1);
	result4CImg = cvCreateImage(cvSize(returnW,returnH),IPL_DEPTH_8U,camChannel);
	MatHomography = cvCreateMat( 3, 3, CV_32F);
	kernelElement = cvCreateStructuringElementEx(3,3,0,0,CV_SHAPE_ELLIPSE,NULL);

	char whiteBGName[100];
	sprintf(whiteBGName,"%s\\BackgroundCaliData\\BG.jpg",fileDir);
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
	if(spotMask != NULL){
		cvReleaseImage(&spotMask);
		spotMask = NULL ;
	}
	cvReleaseStructuringElement(&kernelElement);
	for(int i = 0 ; i < imgMAX; i ++){
		if(historyBG[i] != NULL){
			cvReleaseImage(&historyBG[i]);
			historyBG[i] = NULL;
		}

	}
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

	int threadID = GetCurrentThreadId();
	char windowName[MAX_PATH] ;
	WCHAR windowTitle[MAX_PATH] ;

	cvCvtColor( srcImg, camImg, CV_RGB2GRAY);
	if(camFlip == true){
		cvFlip(camImg);
	}

	int BGCandiSize = candidate.usedImg.size();

	for(int i = 0 ;i < BGCandiSize; i ++){
		cvAddS(candidate.getUsedImg(i),cvScalar(BGadjustValue,BGadjustValue,BGadjustValue),tmpImg);
	
		cvAbsDiff(camImg,tmpImg,tmpImg);
		
		cvSubS(tmpImg,cvScalar(absDiffsubValue,absDiffsubValue,absDiffsubValue),subImg);
		
		cvErode(subImg,tmpImg,NULL,erodeValue);

		if(USEMASK == true ){  
			cvAnd(tmpImg,spotMask,tmpImg);			
		}
		
		CvScalar sum = cvSum(tmpImg);

		if(sum.val[0] < minValue){
			minValue = sum.val[0];
			realBGindex = i;			
		}	

		if(minValue > SAVE_THRES && saveImage == true && saveIndex <1000){
			char saveName[MAX_PATH] ;
			WCHAR imgPath[MAX_PATH] ;
			swprintf_s(imgPath, MAX_PATH, L"%s\\debugImg\\%d_cand_%d.jpg",curDir,saveIndex,i);
			wcstombs(saveName, imgPath, MAX_PATH);

			cvSaveImage(saveName,candidate.getUsedImg(i));
			sprintf(saveName,"debugImg\\%d_cand_%d_sub_%f.jpg",saveIndex,i,sum.val[0]);
			cvSaveImage(saveName,tmpImg);
		}
	}

	for(int i = 0 ; i < candidate.getUsedImgCount(); i ++){
		if(candidate.bgImgPool[candidate.getUsedImgID(i)].layoutType == candidate.bgImgPool[candidate.getUsedImgID(realBGindex)].layoutType){
			realBGindex = i ;
			break ;
		}
	}

	if(candidate.getUsedImgCount() != 0 ){
		if(candidate.getUsedImg(realBGindex) != NULL){
			cvAddS(candidate.getUsedImg(realBGindex),cvScalar(BGadjustValue,BGadjustValue,BGadjustValue),backgroundImg);
			swprintf_s(windowTitle, MAX_PATH, L"Background %d",threadID);
			wcstombs(windowName, windowTitle, MAX_PATH);
			if(showWindow){
				cvShowImage( windowName , backgroundImg);
			}
			else{
				cvDestroyWindow(windowName);
			}

			cvAbsDiff(camImg,backgroundImg,tmpImg);

			cvSubS(tmpImg,cvScalar(absDiffsubValue,absDiffsubValue,absDiffsubValue),tmpImg);

			swprintf_s(windowTitle, MAX_PATH, L"AbsDiffSub %d",threadID);
			wcstombs(windowName, windowTitle, MAX_PATH);
			if(showWindow){
				cvShowImage(windowName,tmpImg);
			}
			else{
				cvDestroyWindow(windowName);
			}

			swprintf_s(windowTitle, MAX_PATH, L"cameraImg %d",threadID);
			wcstombs(windowName, windowTitle, MAX_PATH);
			
			if(showWindow){
				cvShowImage(windowName, camImg);		
			}
			else{
				cvDestroyWindow(windowName);
			}

			if(minValue > SAVE_THRES && saveImage == true && saveIndex <1000){
				char saveName[MAX_PATH] ;
				WCHAR imgPath[MAX_PATH] ;
				swprintf_s(imgPath, MAX_PATH, L"%s\\debugImg\\%d_src.jpg",curDir,saveIndex);
				wcstombs(saveName, imgPath, MAX_PATH);
				cvSaveImage(saveName,camImg);
			}		

			cvSub(camImg,backgroundImg,subImg);
			if(USEMASK == true){
				cvAnd(subImg,spotMask,subImg);
			}
			swprintf_s(windowTitle, MAX_PATH, L"subImg %d",threadID);
			wcstombs(windowName, windowTitle, MAX_PATH);
			if(showWindow){	
				cvShowImage(windowName, subImg);	
				cvWaitKey(1);
			}
			else {
				cvDestroyWindow(windowName);
			}
		}
	}

	if(minValue > SAVE_THRES && saveImage == true && saveIndex <1000){
		char saveName[MAX_PATH] ;
		WCHAR imgPath[MAX_PATH] ;
		swprintf_s(imgPath, MAX_PATH, L"%s\\debugImg\\%d_sBG_%d.jpg",curDir,saveIndex,realBGindex);
		wcstombs(saveName, imgPath, MAX_PATH);
		cvSaveImage(saveName,backgroundImg);
		
		swprintf_s(imgPath, MAX_PATH, L"%s\\debugImg\\sub_%d.jpg",curDir,saveIndex);
		wcstombs(saveName, imgPath, MAX_PATH);
		cvSaveImage(saveName,subImg);

		saveIndex++;
	}

	if(realBGindex != 0){
		candidate.setToUnused(realBGindex);
	}

	cvErode(subImg,erodeImg,NULL,1);
	cvDilate(erodeImg,erodeImg,NULL,1);

	cvCvtColor(erodeImg, result4CImg, CV_GRAY2RGB);

	if(ROIthreshold != 0){
		cvThreshold(erodeImg,thresholdROIImg,ROIthreshold,255,0);
	}
	findForegroundRect(thresholdROIImg);

	if(outputFlip == true){
		cvFlip(result4CImg);
	}

	if(candidate.bgImgPool[realBGindex].isBlendImg == true){
		isBlend = true ;
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

void BackGroundMapping::loadBGTranData(char* fileDir){

	char tagConfigFile[100];
	sprintf(tagConfigFile,"%s\BackgroundCaliData\\tagConfig.txt",fileDir) ;

	FILE  * pFile ;
	pFile = fopen(tagConfigFile,"r");
	fscanf(pFile,"%d " ,&tagTranNum);

	BGConfig = new BGTag[tagTranNum];

	for(int i = 0 ; i < tagTranNum ; i++){
		BGTag *newTag = new BGTag() ;

		fscanf(pFile,"\n%d %d\n%f %f %f %f \n%s \n",&newTag->CurTag , &newTag->TagID,&newTag->tagTop.x,&newTag->tagTop.y,
			&newTag->tagDown.x, &newTag->tagDown.y ,&newTag->imgPath);

		BGConfig[i].CurTag = newTag->CurTag;
		BGConfig[i].TagID = newTag->TagID;
		BGConfig[i].tagDown = newTag->tagDown;
		BGConfig[i].tagTop = newTag->tagTop;
	
		BGConfig[i].tagRec.x = newTag->tagTop.x * (imgW-1) + 0.5;  // plus 0.5 for round off
		BGConfig[i].tagRec.y = newTag->tagTop.y * (imgH-1) + 0.5;

		BGConfig[i].tagImg = cvLoadImage(newTag->imgPath,0);
		BGConfig[i].tagRec.height = BGConfig[i].tagImg->height ;
		BGConfig[i].tagRec.width = BGConfig[i].tagImg->width ;
		BGConfig[i].isVisible = false ;

	}
	
}


void BackGroundMapping::setTranBG(){
	cvResize(whiteBG, backgroundImg);

	for (int i = 0 ; i < tagTranNum ; i ++)
	{
		if(BGConfig[i].isVisible){
			
			cvSetImageROI(backgroundImg,BGConfig[i].tagRec) ;
			cvSub(backgroundImg,BGConfig[i].tagImg,backgroundImg);
			cvResetImageROI(backgroundImg);
		}
	}


	int preIndex = candidate.usedImg.size()-1;
	int index = candidate.getUnusedImgIndex();

	cvCopy(backgroundImg,candidate.bgImgPool[index].BGimg);
	candidate.bgImgPool[index].layoutTotalTag = tagTranNum ;
	candidate.bgImgPool[index].isBlendImg = false ;
	candidate.bgImgPool[index].refCount = 0 ;
	candidate.bgImgPool[index].layoutVisibleTable.clear();
	candidate.bgImgPool[index].tagVisibleTable = new bool [tagTranNum];

	for(int i = 0 ; i < tagTranNum ; i ++){
		
		candidate.bgImgPool[index].tagVisibleTable[i] = BGConfig[i].isVisible  ; 
	}

	if(candidate.getUsedImgCount() == 1){
		candidate.bgImgPool[index].layoutType = m_layoutIndex;
		m_layoutIndex ++ ;
	}

	else{
	
		bool layoutMatch = true ;
		for(int j = 0 ; j < candidate.getUsedImgCount() ; j ++){

			for(int tagIndex = 0 ; tagIndex < tagTranNum ; tagIndex ++){
				if(candidate.bgImgPool[candidate.getUsedImgID(j)].tagVisibleTable[tagIndex] != candidate.bgImgPool[index].tagVisibleTable[tagIndex]){
					layoutMatch = false ;
					break ;
				}
			}
			if(layoutMatch == true ){
				candidate.bgImgPool[index].layoutType= candidate.bgImgPool[candidate.getUsedImgID(j)].layoutType;
				break;
			}
		}
		if(layoutMatch == false){
			candidate.bgImgPool[index].layoutType = m_layoutIndex;
			m_layoutIndex ++ ;
		}

	}


	 //add blend Img into the bgImgPool
	/*if(preIndex >= 0){
	cvAddWeighted(candidate.bgImgPool[index].BGimg,0.5,candidate.bgImgPool[preIndex].BGimg,0.5,0,blendBG);
	int blendIndex = candidate.getUnusedImgIndex();

	cvCopy(blendBG,candidate.bgImgPool[blendIndex].BGimg);
	candidate.bgImgPool[blendIndex].layoutTotalTag = tagTranNum ;
	candidate.bgImgPool[blendIndex].isBlendImg = true ;
	candidate.bgImgPool[blendIndex].layoutVisibleTable.clear();


	for(int i = 0 ; i < tagTranNum ; i ++){
	bool tmpVisible = BGTran[i]->isVisible ;
	candidate.bgImgPool[blendIndex].layoutVisibleTable.push_back(tmpVisible);
	}

	if(candidate.getUsedImgCount() == 1){
	candidate.bgImgPool[blendIndex].layoutType = m_layoutIndex;
	m_layoutIndex ++ ;
	}

	else{
	bool layoutMatch = true ;
	for(int j = 0 ; j < candidate.getUsedImgCount() ; j ++){
	for(int tagIndex = 0 ; tagIndex < tagTranNum ; tagIndex ++){
	if(candidate.bgImgPool[candidate.getUsedImgID(j)].layoutVisibleTable[tagIndex] != candidate.bgImgPool[blendIndex].layoutVisibleTable[tagIndex]){
	layoutMatch = false ;
	break ;
	}
	}
	if(layoutMatch == true){
	candidate.bgImgPool[blendIndex].layoutType = candidate.bgImgPool[candidate.getUsedImgID(j)].layoutType;
	break;
	}
	}
	if(layoutMatch == false ){
	candidate.bgImgPool[blendIndex].layoutType = m_layoutIndex;
	m_layoutIndex ++ ;
	}
	}
	}*/

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
