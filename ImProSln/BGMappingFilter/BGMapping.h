#ifndef _BGHOMO
#define _BGHOMO
#include "cv.h"
#include "highgui.h"
#include <cvaux.h>
#include "stdafx.h"
#include <vector>
#define imgMAX 30


using namespace std;

class BGTag{
public:
	BGTag();
	~BGTag();
	int CurTag ;
	int TagID ;
	CvPoint2D32f tagTop;
	CvPoint2D32f tagDown;
	CvRect tagRec ;
	char imgPath[260] ;
	IplImage* tagImg;
	bool isVisible;
};

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

	void loadBGTranData(char* fileDir);
	void getARLayout();
	void setTranBG();
	void setLayoutType(int type);
	double imgSum(IplImage* img);

public:
	CvMat srcPoint;
	CvMat dstPoint;
	CvMat* MatHomography;
	CvMat* kerMat;

	IplImage*mappingTable;
	IplImage*backgroundImg;
	IplImage*resultImg;
	IplImage*tmpImg;
	IplImage*result4CImg;
	IplImage*foregroundImg;
	IplImage*binarySrc;
	IplImage*binaryResult;
	IplImage*imgPool[imgMAX];
	IplImage* bgMask ;
	IplImage* whiteBG ;

	vector<IplImage*> historyBG ;
	vector<BGTag*> BGTran ;
	int tagTranNum ;

	IplConvKernel* kernelElement;

	int BGthreshold;
	int BlackValue;
	int subValue;
	int imgIndex ;
	int imgH ;
	int imgW ;

	bool isDilate;
	bool camFlip;
	bool layoutFlip;
	bool outputFlip;

	int layoutType ; // 0::RGB   1::MarkerInfo 
};


#endif