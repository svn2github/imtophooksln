#include "d3dx9math.h"

class countAllData
{
public:

	countAllData();

	double g_cvTrans[4][4];
	
	void countLoc(double x,double y,double z, double LeftDownLong, double LeftDownLat, double LeftTopLong, double LeftTopLat, double RightDownLong, double RightDownLat);
	void countLookat(D3DXMATRIX camera);
	void countLookup(D3DXMATRIX camera);
	void countTilt(void);
	void countHeading(void);
	void countRoll(void);
	void countIntersectPoint(D3DXVECTOR3 origin_point, D3DXVECTOR3 lookat,double LeftDownLong, double LeftDownLat, double LeftTopLong, double LeftTopLat, double RightDownLong, double RightDownLat);
	void countSVAngle(D3DXVECTOR3 SVBase, D3DXVECTOR3 SVCamera);

	void computeNeedData(double cvTrans[4][4], double LeftDownLong, double LeftDownLat, double LeftTopLong, double LeftTopLat, double RightDownLong, double RightDownLat);
	
	double getLongitude(void);
	double getLatitude(void);
	double getAltitude(void);
	double getTilt(void);
	double getHeading(void);
	double getRoll(void);
	double getAltitude_scale(void);
	double getSVAngle(void);

	D3DXVECTOR3 getIntersect_origin_point(void);
	D3DXVECTOR3 getIntersect_point(void);


private:

	D3DXMATRIX camera;
	D3DXMATRIX cameraInv;

	D3DXVECTOR3 lookat;  //camera�ݪ���V��vector 
	D3DXVECTOR3 lookup;  //camera�� up vector
	D3DXVECTOR3 origin_point;
	D3DXVECTOR3 origin_lookup;  //��l��camera up vector
	D3DXVECTOR3 google_earth_point;
	D3DXVECTOR3 intersect_origin_point;
	D3DXVECTOR3 intersect_point;
	D3DXVECTOR3 mid_point;  //��l�������I

	//count small view angle
	D3DXVECTOR3 SVBase;
	D3DXVECTOR3 SVCamera;

	double longitude;
	double latitude;
	double altitude;
	double tilt;
	double heading;
	double roll;
	double altitude_scale;
	double SVAngle;

};