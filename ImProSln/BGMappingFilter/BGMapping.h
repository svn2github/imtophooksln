#ifndef _BGHOMO
#define _BGHOMO
#include "cv.h"
#include "highgui.h"
#include <cvaux.h>
#include "stdafx.h"


using namespace std;

class BackGroundMapping{

public:
	BackGroundMapping(int w , int h ,int camChannel,char* fileDir);
	~BackGroundMapping();
	
	void loadHomo(char* homoName , char* mTableName);
	IplImage* getForeground(IplImage* srcImg);
	void setBackground(IplImage* BGImg);  
	void initKernel(float center, float inner , float outer);

public:
	std::vector<CvRect> foregroundLists;
	std::vector<CvRect>* GetForegroundRect()
	{	return &foregroundLists;};
	void findForegroundRect(IplImage* FGImage);


public:
	CvMat srcPoint;
	CvMat dstPoint;
	CvMat* MatHomography;
	CvMat* kerMat;


	IplImage*mappingTable;
	IplImage*backgroundImg;
	IplImage*resultImg;
	IplImage*result4CImg;
	IplImage*foregroundImg;
	IplImage*binarySrc;
	IplImage*binaryResult;

	IplConvKernel* kernelElement;

	int BGthreshold;
	int BlackValue;
	int WhiteValue;

	bool isDilate;
	bool camFlip;
	bool layoutFlip;
	bool outputFlip;
};
#endif