#ifndef _BGHOMO
#define _BGHOMO
#include "cv.h"
#include "highgui.h"
#include <cvaux.h>
#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

#pragma comment(lib, "cv.lib")
#pragma comment(lib, "highgui.lib")
#pragma comment(lib, "cxcore.lib")
#pragma comment(lib, "cvaux.lib")

#define WIDTH 800
#define HEIGHT 600

class BackGroundMapping{

public:
	BackGroundMapping();
	~BackGroundMapping();
	
	void loadHomo(char* homoName , char* mTableName);
	IplImage* getForeground(IplImage* srcImg);
	void setBackground(IplImage* BGImg);   // input the ori LayoutImage
	void setThreshold(int threshold);
	int getThreshold();

public:
	CvMat srcPoint;
	CvMat dstPoint;
	CvMat* MatHomography;

	IplImage*gray0Image;
	IplImage*gray255Image;
	IplImage*mappingTable;
	IplImage*backgroundImg;
	IplImage*resultImg;
	IplImage*foregroundImg;
	IplConvKernel* kernelElement;

	int BGthreshold;
	bool isDilate;
};
#endif