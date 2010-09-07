#include "stdafx.h"
#include "GEPosition.h"
#include "d3dx9math.h"
#include "math.h"
#include <string.h>
#include "Streams.h"
#include <stdio.h>

#define PI 3.1416

GEPosition::GEPosition() 
{
	altitude = 0;  
	heading = 0;
	latitude = 0;
	longitude = 0;
	roll = 0;
	tilt = 0;

	longitude_LT = 0;
	latitude_LT = 0;
	altitude_LT = 0;

	longitude_LD = 0;
	latitude_LD = 0;
	altitude_LD = 0;

	longitude_RT = 0;
	latitude_RT = 0;
	altitude_RT = 0;

	longitude_RD = 0;
	latitude_RD = 0;
	altitude_RD = 0;

	altitude_scale = 1.0;

	SVAngle = 0;
	SVFlag = 1;

}

double GEPosition::countTheta(D3DXVECTOR3 vector, D3DXVECTOR3 vectorBase)
{
	double cosin = 0;
	double arcosin = 0;

	D3DXVec3Normalize(&vector,&vector);
	D3DXVec3Normalize(&vectorBase,&vectorBase);

	cosin = D3DXVec3Dot(&vector, &vectorBase);
	arcosin = acos(cosin);

	return (double)180*(double)arcosin / (double)PI;
	
}

D3DXVECTOR3 GEPosition::countGELoc(double x, double y, double z)
{
	D3DXVECTOR3 result;

	result.x = LeftTopLong + abs(RightDownLong - LeftDownLong) * x * (3.0 / 4.0);
	//result.x = LeftTopLong + abs(RightDownLong - LeftDownLong) * x;
	result.y = LeftTopLat + abs(LeftDownLat - LeftTopLat) * y;
	result.z = abs(LeftDownLat - LeftTopLat) * z;

	return result;

}

void GEPosition::countLookat(D3DXMATRIX camera)
{
	lookat.x = -camera.m[0][2];
	lookat.y = -camera.m[1][2];
	lookat.z = -camera.m[2][2];
	D3DXVec3Normalize(&lookat, &lookat);
	int test = 0;
}

void GEPosition::countLookup(D3DXMATRIX camera)
{
	lookup.x = camera.m[0][1];
	lookup.y = camera.m[1][1];
	lookup.z = camera.m[2][1];
	D3DXVec3Normalize(&lookup,&lookup);
}

void GEPosition::countTilt()
{
	double cosin = 0;
	double arcosin = 0;

	D3DXVECTOR3 normalLookat;
	
	D3DXVec3Normalize(&normalLookat,&lookat);
	D3DXVECTOR3 viewDown(0, 0, -1);
	cosin = D3DXVec3Dot(&lookat,&viewDown);
	arcosin = acos(cosin);
	tilt = (double)180*(double)arcosin / (double)PI;

	int test = 0;
}

void GEPosition::countHeading()
{
	D3DXVECTOR3 lookatXY(lookat.x, lookat.y, 0);
	D3DXVec3Normalize(&lookatXY, &lookatXY);
	D3DXVECTOR3 north(0, 1, 0);
	double cosin = D3DXVec3Dot(&lookatXY, &north);
	double arccosin = acos(cosin);
	if (lookatXY.x < 0)
		arccosin = 2*D3DX_PI - arccosin;
	heading = (double)180*(double)arccosin / (double)PI;
	int test = 0;
}

void GEPosition::countRoll()
{
	D3DXVECTOR3 zaxis;
	D3DXVECTOR3 axis3;
	D3DXVECTOR3 result;
	
	double dist_lookup = 0;
	double dist_origin_lookup = 0;
	double cosin = 0;
	double arcosin = 0;
	double angle = 0;

	zaxis.x = 0;
	zaxis.y = 0;
	zaxis.z = 1;

	D3DXVec3Cross(&axis3, &lookat, &zaxis);
	D3DXVec3Cross(&origin_lookup,&axis3, &lookat);
	D3DXVec3Normalize(&origin_lookup,&origin_lookup);
	D3DXVec3Cross(&result,&origin_lookup,&lookup);

	cosin = D3DXVec3Dot(&lookup,&origin_lookup); 
	
	arcosin = acos(cosin);
	angle = (double)180*(double)arcosin / (double)PI;
			
	if(result.x * this->lookat.x <= 0 || result.y * this->lookat.y <=0)	 roll = angle;
	else	roll = -angle;

	/*if (Double::IsNaN(roll))
	{
		int test = 0;
	}*/

}

D3DXVECTOR3 GEPosition::countIntersectPointWithGround(D3DXVECTOR3 start_point, D3DXVECTOR3 end_point)
{
	D3DXVECTOR3 intersect_temp_point;

	D3DXPLANE ground;
	ground.a = 0;
	ground.b = 0;
	ground.c = 1;
	ground.d = 0;

	//D3DXPlaneIntersectLine(&intersect_origin_point,&ground,&origin_point,&ending_point);
	D3DXPlaneIntersectLine(&intersect_temp_point,&ground,&start_point,&end_point);
	
	return countGELoc(intersect_temp_point.x,intersect_temp_point.y,intersect_temp_point.z);

}

void GEPosition::countSVAngle()
{
	D3DXVECTOR3 lookatXY(lookat.x, lookat.y, 0);
	D3DXVec3Normalize(&lookatXY,&lookatXY);
	D3DXVECTOR3 N(0,1,0);
	D3DXVECTOR3 S(0,-1,0);
	D3DXVECTOR3 E(1,0,0);
	D3DXVECTOR3 W(-1,0,0);

	double NAngle = countTheta(lookatXY,N);
	double SAngle = countTheta(lookatXY,S);
	double EAngle = countTheta(lookatXY,E);
	double WAngle = countTheta(lookatXY,W);

	int scopeBig = 60;
	int scopeSmall = 30;

	if(tilt <= 20)	SVAngle = SVAngle;	
	else{
		switch(SVFlag){
			case 1:
				if(NAngle <= scopeBig)	SVAngle = 0;
				else if(SAngle <= scopeBig)	SVAngle = 180;
				else if(EAngle <= scopeSmall)	{SVAngle = 90;	SVFlag = 2;}
				else if(WAngle <= scopeSmall)	{SVAngle = 270;	SVFlag = 2;}
				break;
			case 2:
				if(NAngle <= scopeSmall)	{SVAngle = 0;	SVFlag = 1;}
				else if(SAngle <= scopeSmall)	{SVAngle = 180;	SVFlag = 1;}
				else if(EAngle <= scopeBig)	SVAngle = 90;
				else if(WAngle <= scopeBig)	SVAngle = 270;
				break;
		}
	}

}


void GEPosition::computeNeedData(double ratioW, double ratioH, double focalLength, 
								 double cvTrans[4][4], 
								 double LDLon, double LDLat, double LTLon, double LTLat, 
								 double RDLon, double RDLat)
{
	LeftDownLong = LDLon;
	LeftDownLat = LDLat;
	LeftTopLong = LTLon;
	LeftTopLat = LTLat;
	RightDownLong = RDLon;
	RightDownLat = RDLat;

	camera_focalLength = focalLength;
	width_ratio = ratioW;
	high_ratio = ratioH;

	char        string[256];
	double det = 0;
	D3DXMATRIX d3d_camTrans, matInvYZ, matSwitchYZ;
	D3DXMatrixScaling(&matInvYZ, 1, -1, -1);

	/*matSwitchYZ.m[0][0] = 0; matSwitchYZ.m[0][1] = 0; matSwitchYZ.m[0][2] = 1; matSwitchYZ.m[0][3] = 0; 
	matSwitchYZ.m[1][0] = 1; matSwitchYZ.m[1][1] = 0; matSwitchYZ.m[1][2] = 0; matSwitchYZ.m[1][3] = 0; 
	matSwitchYZ.m[2][0] = 0; matSwitchYZ.m[2][1] = 1; matSwitchYZ.m[2][2] = 0; matSwitchYZ.m[2][3] = 0; 
	matSwitchYZ.m[3][0] = 0; matSwitchYZ.m[3][1] = 0; matSwitchYZ.m[3][2] = 0; matSwitchYZ.m[3][3] = 1; 
*/

	D3DXMatrixIdentity(&d3d_camTrans);

	for (int row = 0; row < 4; row ++)
	{
		for (int col = 0; col < 4; col++)
		{
			d3d_camTrans.m[col][row] = cvTrans[row][col];
		}
	}

	d3d_camTrans = d3d_camTrans * matInvYZ;
	
	camera = d3d_camTrans;
	D3DXMatrixInverse(&cameraInv,NULL,&camera);

	origin_point.x = 0;
	origin_point.y = 0;
	origin_point.z = 0;

	origin_point_LT.x = -1 * (4.0) / (3.0) * width_ratio;
	origin_point_LT.y = 1 * high_ratio;
	origin_point_LT.z = camera_focalLength;

	origin_point_LD.x = -1 * (4.0) / (3.0) * width_ratio;
	origin_point_LD.y = -1 * high_ratio;
	origin_point_LD.z = camera_focalLength;

	origin_point_RT.x = 1 * (4.0) / (3.0) * width_ratio;
	origin_point_RT.y = 1 * high_ratio;
	origin_point_RT.z = camera_focalLength;

	origin_point_RD.x = 1 * (4.0) / (3.0) * width_ratio;
	origin_point_RD.y = -1 * high_ratio;
	origin_point_RD.z = camera_focalLength;

	// cameraInv : 將座標從相機座標系轉到世界座標系
	D3DXVec3TransformCoord(&origin_point,&origin_point,&cameraInv);
	D3DXVec3TransformCoord(&origin_point_LT,&origin_point_LT,&cameraInv);
	D3DXVec3TransformCoord(&origin_point_LD,&origin_point_LD,&cameraInv);
	D3DXVec3TransformCoord(&origin_point_RT,&origin_point_RT,&cameraInv);
	D3DXVec3TransformCoord(&origin_point_RD,&origin_point_RD,&cameraInv);

	/*WCHAR str[MAX_PATH] = {0};
	
	OutputDebugStringW(L"@@@@@@@@@@@@\n");
	swprintf_s(str, MAX_PATH, L"@@@@ google_earth_point = ( %.2f, %.2f, %.2f) \n", 
		google_earth_point.x, google_earth_point.y, google_earth_point.z);
	OutputDebugStringW(str);
	OutputDebugStringW(L"@@@@@@@@@@@@\n");*/
	
	//計算google earth中需要的各個參數
	google_earth_point = countGELoc(origin_point.x, origin_point.y, origin_point.z);
	google_earth_point_LT = countGELoc(origin_point_LT.x, origin_point_LT.y, origin_point_LT.z);
	google_earth_point_LD = countGELoc(origin_point_LD.x, origin_point_LD.y, origin_point_LD.z);
	google_earth_point_RT = countGELoc(origin_point_RT.x, origin_point_RT.y, origin_point_RT.z);
	google_earth_point_RD = countGELoc(origin_point_RD.x, origin_point_RD.y, origin_point_RD.z);

	GEGroundPointLT = countIntersectPointWithGround(origin_point,origin_point_LT);
	GEGroundPointLD = countIntersectPointWithGround(origin_point,origin_point_LD);
	GEGroundPointRT = countIntersectPointWithGround(origin_point,origin_point_RT);
	GEGroundPointRD = countIntersectPointWithGround(origin_point,origin_point_RD);

	countLookat(camera);
	countLookup(camera);
	countTilt();
	countHeading();
	countRoll();
	
	/*WCHAR str[MAX_PATH] = {0};
	
	OutputDebugStringW(L"@@@@@@@@@@@@\n");
	swprintf_s(str, MAX_PATH, L"@@@@ lookat = ( %.2f, %.2f, %.2f) \n", 
		lookat.x, lookat.y, lookat.z);
	OutputDebugStringW(str);
	swprintf_s(str, MAX_PATH, L"@@@@ ViewUp = ( %.2f, %.2f, %.2f) \n", 
		lookup.x, lookup.y, lookup.z);
	OutputDebugStringW(str);
	swprintf_s(str, MAX_PATH, L"@@@@ Tilt, Heading, Roll = ( %.2f, %.2f, %.2f) \n", 
		tilt, heading, roll);
	OutputDebugStringW(str);
	OutputDebugStringW(L"@@@@@@@@@@@@\n");
	*/
	longitude = google_earth_point.x;
	latitude = google_earth_point.y;
	altitude = google_earth_point.z;
	altitude *= 111000;  //一度 = 111000 公尺
	altitude *= altitude_scale;

	//WCHAR str[MAX_PATH] = {0};
	//OutputDebugStringW(str);
	//swprintf_s(str, MAX_PATH, L"@@@@ longitude, latitude, altitude = ( %f, %f, %f) \n", 
	//	longitude, latitude, altitude);
	//OutputDebugStringW(str);

	longitude_LT = google_earth_point_LT.x;
	latitude_LT = google_earth_point_LT.y;
	altitude_LT = google_earth_point_LT.z;
	altitude_LT *= 111000;  //一度 = 111000 公尺

	longitude_LD = google_earth_point_LD.x;
	latitude_LD = google_earth_point_LD.y;
	altitude_LD = google_earth_point_LD.z;
	altitude_LD *= 111000;  //一度 = 111000 公尺

	longitude_RT = google_earth_point_RT.x;
	latitude_RT = google_earth_point_RT.y;
	altitude_RT = google_earth_point_RT.z;
	altitude_RT *= 111000;  //一度 = 111000 公尺

	longitude_RD = google_earth_point_RD.x;
	latitude_RD = google_earth_point_RD.y;
	altitude_RD = google_earth_point_RD.z;
	altitude_RD *= 111000;  //一度 = 111000 公尺

	countSVAngle();

	//WCHAR str[MAX_PATH] = {0};
	//
	//OutputDebugStringW(L"@@@@@@@@@@@@\n");
	//swprintf_s(str, MAX_PATH, L"@@@@ roll = (%f) \n",roll);
	//OutputDebugStringW(str);

	//swprintf_s(str, MAX_PATH, L"@@@@ tilt = (%f) \n", tilt);
	//OutputDebugStringW(str);
	//swprintf_s(str, MAX_PATH, L"@@@@ N = (%f) \n", tilt);
	//OutputDebugStringW(str);
	//swprintf_s(str, MAX_PATH, L"@@@@ S = (%f) \n", tilt);
	//OutputDebugStringW(str);
	//swprintf_s(str, MAX_PATH, L"@@@@ E = (%f) \n", tilt);
	//OutputDebugStringW(str);
	//swprintf_s(str, MAX_PATH, L"@@@@ W = (%f) \n", tilt);
	//OutputDebugStringW(str);

	//OutputDebugStringW(L"@@@@@@@@@@@@\n");

}

// camera center
double GEPosition::getLongitude()
{
	return longitude;
}
double GEPosition::getLatitude()
{
	return latitude;
}
double GEPosition::getAltitude()
{
	return altitude;
}

// camera LT
double GEPosition::getLongitude_LT()
{
	return longitude_LT;
}
double GEPosition::getLatitude_LT()
{
	return latitude_LT;
}
double GEPosition::getAltitude_LT()
{
	return altitude_LT;
}

// camera LD
double GEPosition::getLongitude_LD()
{
	return longitude_LD;
}
double GEPosition::getLatitude_LD()
{
	return latitude_LD;
}
double GEPosition::getAltitude_LD()
{
	return altitude_LD;
}

// camera RT
double GEPosition::getLongitude_RT()
{
	return longitude_RT;
}
double GEPosition::getLatitude_RT()
{
	return latitude_RT;
}
double GEPosition::getAltitude_RT()
{
	return altitude_RT;
}

// camera RD
double GEPosition::getLongitude_RD()
{
	return longitude_RD;
}
double GEPosition::getLatitude_RD()
{
	return latitude_RD;
}
double GEPosition::getAltitude_RD()
{
	return altitude_RD;
}

double GEPosition::getTilt()
{
	return tilt;
}

double GEPosition::getHeading()
{
	return heading;
}

double GEPosition::getRoll()
{
	return roll;
}

double GEPosition::getAltitude_scale()
{
	return altitude_scale;
}

double GEPosition::getSVAngle()
{
	return SVAngle;
}

D3DXVECTOR3 GEPosition::getIntersect_origin_point()
{
	return intersect_origin_point;
}

D3DXVECTOR3 GEPosition::getIntersect_point()
{
	return intersect_point;
}

D3DXVECTOR3 GEPosition::getGEGroundPointLT()
{
	return GEGroundPointLT;
}

D3DXVECTOR3 GEPosition::getGEGroundPointLD()
{
	return GEGroundPointLD;
}

D3DXVECTOR3 GEPosition::getGEGroundPointRT()
{
	return GEGroundPointRT;
}

D3DXVECTOR3 GEPosition::getGEGroundPointRD()
{
	return GEGroundPointRD;
}

D3DXVECTOR3 GEPosition::getLookat()
{
	return lookat;
}

D3DXVECTOR3 GEPosition::getGEPoint()
{
	return google_earth_point;
}

D3DXVECTOR3 GEPosition::getOriginalPoint()
{
	return origin_point;
}
	