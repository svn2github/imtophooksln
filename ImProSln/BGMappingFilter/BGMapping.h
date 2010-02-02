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
/*
#pragma comment(lib, "cv.lib")
#pragma comment(lib, "highgui.lib")
#pragma comment(lib, "cxcore.lib")
#pragma comment(lib, "cvaux.lib")
*/

class BackGroundMapping{

public:
	BackGroundMapping(int w , int h);
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

	IplImage*mappingTable;
	IplImage*backgroundImg;
	IplImage*resultImg;
	IplImage*foregroundImg;
	IplConvKernel* kernelElement;

	int BGthreshold;
	bool isDilate;
};
#endif