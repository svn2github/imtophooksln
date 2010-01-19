
#ifndef _ARTAG
#define _ARTAG
#include "stdafx.h"
#include "cv.h"
#include "highgui.h"
#include <cvaux.h>
#include <vector>
#include <string>

using namespace std;

#pragma comment(lib, "cv200.lib")
#pragma comment(lib, "highgui200.lib")
#pragma comment(lib, "cxcore200.lib")
#pragma comment(lib, "cvaux200.lib")

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
	void setTagDir(char* Dir);
	IplImage* getLayout();
	void changeLayout();
	
	void setNumTagX(int numX) ;
	void setNumTagY(int numY) ;
	void setSpace(int tagSpace) ;

};

#endif