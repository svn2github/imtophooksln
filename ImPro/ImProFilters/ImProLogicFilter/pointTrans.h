#include "cv.h"
#include "highgui.h"
#include <cvaux.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

#define CAMWIDTH 640
#define CAMHEIGHT 480

class ProjectorTrans2World{
public :
	ProjectorTrans2World();
	ProjectorTrans2World(int tableW, int tableH ,char* fileDir, int camIndex);
	~ProjectorTrans2World() ;
	void Init(int tableW, int tableH ,char* fileDir, int camIndex);

	void findCam2WorldExtrinsic(CvMat* cameraPoint, CvMat* objectPoint);
	void findPro2WorldExtrinsic();
	void loadCalibParam(char* fileDir, int camIndex);

	// combine rotation matrix and translation matrix into a 4*4 extrinsic matrix
	void buildExtrinsicMat(CvMat* rotation, CvMat* translate, CvMat* dstExtrinsicMat);
	CvPoint3D32f findPro3D(CvMat* pointMat);
	void setTableSize(int width , int height);
	int* getTableSize();
	void getProjHomo();
	void initProjRes(int width, int height);
	CvPoint2D32f findPro3DcvPoint(CvPoint point);


public:
	CvMat* pro2CamExtrinsic;
	CvMat* proIntrinsic;
	CvMat* camIntrinsic;
	CvMat* proDisto;
	CvMat* camDisto;

	CvMat* invProIntrinsic;
	CvMat* pro2WorldRotation;

	CvMat* cam2WorldExtrinsic;
	CvMat* pro2WorldExtrinsic;
	CvMat* world2CamExtrinsic;
	CvMat* proPositionInWorld;
	CvMat* cameraPoint;
	CvMat* objectPoint;
	CvMat* oriProPos;

	CvMat* rotateW2C;
	CvMat* transW2C ;
	CvMat* rotateRodrigues ;

	// for findPro3D
	CvMat* proVector ;
	CvMat* proVectorInWorld;
	CvMat* pro3DPointsMat;
	CvMat* proHomoMat;
	CvMat projCornerMat;

	float proj3DPoints[4][2];  
	float projBox[4];
	float projCorner[8];
	float projHomo[3][3];
	int ProjResWidth ;   // resolution width
	int ProjResHeight;
	int tableWidth;
	int tableHeight;

	float pre_proj3DPoints[4][2];  
	bool firstProjPoints ;

};