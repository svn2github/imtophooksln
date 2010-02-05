#ifndef _BGHOMO
#define _BGHOMO
#include "cv.h"
#include "highgui.h"
#include <cvaux.h>
#include <vector>
#include <string>
#include <iostream>


using namespace std;

#pragma comment(lib, "cv.lib")
#pragma comment(lib, "highgui.lib")
#pragma comment(lib, "cxcore.lib")
#pragma comment(lib, "cvaux.lib")

#define WIDTH 640
#define HEIGHT 480

class BackGroundHomo{

public:
	BackGroundHomo();
	~BackGroundHomo();
	void findHomo();
	void buildMappingTable();
	void warpCaliImg(char* srcImgName,IplImage* dstImg);
	void warpCaliCapture(IplImage*srcImg, IplImage* dstImg);
	void loadHomo(char* homoName , char* mTableName);
	int  getMappingValue(float x, float y,int oriIntensity);
	void convertImg(IplImage* inputImg);
	void setBackground(IplImage* markBGImg);
	void warpImg(IplImage* srcImg);
	void changeBG(IplImage* BGImg);
	
public:
	CvMat srcPoint;
	CvMat dstPoint;
	CvMat* MatHomography;

	IplImage*gray0Image;
	IplImage*gray255Image;
	IplImage*mappingTable;
	IplImage*backgroundImg;
	IplImage*oribackgroundImg;
	IplImage*resultImg;
};
#endif