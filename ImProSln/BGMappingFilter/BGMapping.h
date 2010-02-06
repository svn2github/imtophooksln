#ifndef _BGHOMO
#define _BGHOMO
#include "cv.h"
#include "highgui.h"
#include <cvaux.h>
#include "stdafx.h"
//#include <vector>
//#include <string>
//#include <iostream>

using namespace std;

class BackGroundMapping{

public:
	BackGroundMapping(int w , int h , int imgChannel);
	~BackGroundMapping();
	
	void loadHomo(char* homoName , char* mTableName);
	IplImage* getForeground(IplImage* srcImg);
	void setBackground(IplImage* BGImg);  
	void setThreshold(int threshold);
	int getThreshold();

public:
	CvMat srcPoint;
	CvMat dstPoint;
	CvMat* MatHomography;

	IplImage*mappingTable;
	IplImage*backgroundImg;
	IplImage*resultImg;
	IplImage*result4CImg;
	IplImage*foregroundImg;
	IplImage*binarySrc;
	IplImage*binaryResult;

	IplConvKernel* kernelElement;

	int BGthreshold;
	bool isDilate;
};
#endif