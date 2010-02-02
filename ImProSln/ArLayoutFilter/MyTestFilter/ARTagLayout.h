
#ifndef _ARTAG
#define _ARTAG
#include "stdafx.h"
#include "cv.h"
#include "highgui.h"
#include <cvaux.h>
#include <vector>
#include <string>

using namespace std;

class Point2D{
public :
	float x;
	float y;

};

class ARTag{
public :
	int tagNum;
	float PosX;   
	float PosY;
	Point2D center;
	float tagSize; 
	bool isVisible;	
	IplImage* tagImage;
	bool reDraw ;

	ARTag() ;
	ARTag(int Num, float x,float y, float size, bool visible, char* tagDir) ;
	void setVisible(bool state) ;
	void changeSize(float size);
};		
class ARLayout{

public :
	vector <ARTag> Layout ;
	IplImage* layoutImage;
	ARLayout(int imageWidth, int imageHeight, int numX, int numY,int space, char* tagDir);
	ARLayout() ;
	int LayoutWidth;
	int LayoutHeight;
	int numTagX;
	int numTagY;
	int TotalTag ;
	int Space ;
	char ARtagDir[100];

	void LayoutGenerate(int imageWidth, int imageHeight, int numX, int numY,int space);
	void LoadLayout(char* fileName) ;
	void combineTagtoIplImage();
	void checkTag(float x, float y);
	void changeLayout();
	float tagSizeArrange() ;  // return tag size
	IplImage* getLayout();
	
	
	void setNumTagX(int numX) ;
	void setNumTagY(int numY) ;
	void setSpace(int tagSpace) ;

};

#endif