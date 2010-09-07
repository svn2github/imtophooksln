#include "d3dx9math.h"

class GEPosition
{
public:

	GEPosition();

	double g_cvTrans[4][4];
	
	D3DXVECTOR3 countGELoc(double x, double y, double z);
	void countLookat(D3DXMATRIX camera);
	void countLookup(D3DXMATRIX camera);
	void countTilt(void);
	void countHeading(void);
	void countRoll(void);
	D3DXVECTOR3 countIntersectPointWithGround(D3DXVECTOR3 start_point, D3DXVECTOR3 end_point);
	void countSVAngle(void);
	double countTheta(D3DXVECTOR3 vector, D3DXVECTOR3 vectorBase);

	void computeNeedData(double ratioW, double ratioH, double focalLength, double cvTrans[4][4], 
		double LDLon, double LDLat, double LTLon, double LTLat, 
		double RDLon, double RDLat);
	
	D3DXVECTOR3 getOriginalPoint(void);
	D3DXVECTOR3 getGEPoint(void);
	D3DXVECTOR3 getLookat(void);
	double getLongitude(void);
	double getLatitude(void);
	double getAltitude(void);
	double getLongitude_LT(void);
	double getLatitude_LT(void);
	double getAltitude_LT(void);
	double getLongitude_LD(void);
	double getLatitude_LD(void);
	double getAltitude_LD(void);
	double getLongitude_RT(void);
	double getLatitude_RT(void);
	double getAltitude_RT(void);
	double getLongitude_RD(void);
	double getLatitude_RD(void);
	double getAltitude_RD(void);
	double getTilt(void);
	double getHeading(void);
	double getRoll(void);
	double getAltitude_scale(void);
	double getSVAngle(void);

	D3DXVECTOR3 getIntersect_origin_point(void);
	D3DXVECTOR3 getIntersect_point(void);

	D3DXVECTOR3 getGEGroundPointLT(void);
	D3DXVECTOR3 getGEGroundPointLD(void);
	D3DXVECTOR3 getGEGroundPointRT(void);
	D3DXVECTOR3 getGEGroundPointRD(void);


private:

	double LeftDownLong;
	double LeftDownLat;
	double LeftTopLong;
	double LeftTopLat; 
	double RightDownLong;
	double RightDownLat;

	D3DXMATRIX camera;
	D3DXMATRIX cameraInv;

	D3DXVECTOR3 lookat;  //camera看的方向的vector 
	D3DXVECTOR3 lookup;  //camera的 up vector
	D3DXVECTOR3 origin_lookup;  //原始的camera up vector

	D3DXVECTOR3 origin_point;
	D3DXVECTOR3 origin_point_LT;
	D3DXVECTOR3 origin_point_LD;
	D3DXVECTOR3 origin_point_RT;
	D3DXVECTOR3 origin_point_RD;
	
	D3DXVECTOR3 google_earth_point;
	D3DXVECTOR3 google_earth_point_LT;
	D3DXVECTOR3 google_earth_point_LD;
	D3DXVECTOR3 google_earth_point_RT;
	D3DXVECTOR3 google_earth_point_RD;

	D3DXVECTOR3 GEGroundPointLT;
	D3DXVECTOR3 GEGroundPointLD;
	D3DXVECTOR3 GEGroundPointRT;
	D3DXVECTOR3 GEGroundPointRD;

	D3DXVECTOR3 intersect_origin_point;
	D3DXVECTOR3 intersect_point;
	D3DXVECTOR3 mid_point;  //桌子的中心點

	int SVFlag;

	double camera_focalLength;
	double width_ratio;
	double high_ratio;

	double longitude;
	double latitude;
	double altitude;
	double tilt;
	double heading;
	double roll;
	double altitude_scale;
	double SVAngle;

	double longitude_LT;
	double latitude_LT;
	double altitude_LT;

	double longitude_LD;
	double latitude_LD;
	double altitude_LD;

	double longitude_RT;
	double latitude_RT;
	double altitude_RT;

	double longitude_RD;
	double latitude_RD;
	double altitude_RD;

};