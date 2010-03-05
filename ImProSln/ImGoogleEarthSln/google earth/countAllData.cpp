#include "stdafx.h"
#include "countAllData.h"
#include "d3dx9math.h"
#include "math.h"

#define PI 3.1416

countAllData::countAllData() 
{
	altitude = 0;  
	heading = 0;
	latitude = 0;
	longitude = 0;
	roll = 0;
	tilt = 0;

	altitude_scale = 1.0;

}

void countAllData::countLoc(double x, double y, double z, double LeftDownLong, double LeftDownLat, double LeftTopLong, double LeftTopLat, double RightDownLong, double RightDownLat)
{
	google_earth_point.x = LeftTopLong + abs(RightDownLong - LeftDownLong) * x;
	google_earth_point.y = LeftTopLat + abs(LeftDownLat - LeftTopLat) * y;
	google_earth_point.z = abs(LeftDownLat - LeftTopLat) * z;

	//D3DXMATRIX Transform;

	//D3DXVECTOR3 eye;
	//D3DXVECTOR3 X;
	//D3DXVECTOR3 Y;
	//D3DXVECTOR3 Z;
	//D3DXVECTOR3 marker_point;

	//marker_point.x = x;
	//marker_point.y = y;
	//marker_point.z = z;
	//
	//eye.x = LeftDownLong;
	//eye.y = 0;
	//eye.z = LeftDownLat;
	//
	//X.x = (RightDownLong - LeftDownLong) * (3/4);
	//X.y = 0;
	//X.z = (RightDownLat - LeftDownLat) * (3/4);

	////D3DXVec3Cross(&Y,&X,&Z);

	///*Y.x = 0;
	//Y.y = RightDownLong - LeftDownLong;
	//Y.z = 0;*/

	//Y.x = 0;
	//Y.y = LeftTopLat - LeftDownLat;
	//Y.z = 0;

	//Z.x = LeftTopLong - LeftDownLong;
	//Z.y = 0;
	//Z.z = LeftTopLat - LeftDownLat;

	//Transform._11 = X.x;
	//Transform._12 = Y.x;
	//Transform._13 = Z.x;
	//Transform._14 = 0;

	//Transform._21 = X.y;
	//Transform._22 = Y.y;
	//Transform._23 = Z.y;
	//Transform._24 = 0;

	//Transform._31 = X.z;
	//Transform._32 = Y.z;
	//Transform._33 = Z.z;
	//Transform._34 = 0;

	//Transform._41 = eye.x;
	//Transform._42 = eye.y;
	//Transform._43 = eye.z;
	//Transform._44 = 1;

	//D3DXVec3TransformCoord(&google_earth_point,&marker_point,&Transform);	

}

void countAllData::countLookat(D3DXMATRIX camera)
{
	lookat.x = -camera.m[0][2];
	lookat.y = -camera.m[1][2];
	lookat.z = -camera.m[2][2];
	D3DXVec3Normalize(&lookat, &lookat);
	int test = 0;
}

void countAllData::countLookup(D3DXMATRIX camera)
{
	lookup.x = camera.m[0][1];
	lookup.y = camera.m[1][1];
	lookup.z = camera.m[2][1];
	D3DXVec3Normalize(&lookup,&lookup);
}

void countAllData::countTilt()
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

void countAllData::countHeading()
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

void countAllData::countRoll()
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

void countAllData::countIntersectPoint(D3DXVECTOR3 origin_point,D3DXVECTOR3 lookat,double LeftDownLong, double LeftDownLat, double LeftTopLong, double LeftTopLat, double RightDownLong, double RightDownLat)
{

	D3DXPLANE ground;
	ground.a = 0;
	ground.b = 0;
	ground.c = 1;
	ground.d = 0;

	D3DXVECTOR3 ending_point;
	ending_point.x = origin_point.x + lookat.x;
	ending_point.y = origin_point.y + lookat.y;
	ending_point.z = origin_point.z + lookat.z;

	D3DXPlaneIntersectLine(&intersect_origin_point,&ground,&origin_point,&ending_point);
	
	intersect_point.x = LeftTopLong + abs(RightDownLong - LeftDownLong) * intersect_origin_point.x;
	intersect_point.y = LeftTopLat + abs(LeftDownLat - LeftTopLat) * intersect_origin_point.y;
	intersect_point.z = 0;

}

void countAllData::computeNeedData(double cvTrans[4][4],double LeftDownLong, double LeftDownLat, double LeftTopLong, double LeftTopLat, double RightDownLong, double RightDownLat)
{
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
	//from right hand to left hand

	origin_point.x = -camera.m[3][0];
	origin_point.y = -camera.m[3][1];
	origin_point.z = -camera.m[3][2];
	
	//計算google earth中需要的各個參數
	countLoc(-camera.m[3][0], -camera.m[3][1], -camera.m[3][2], LeftDownLong, LeftDownLat, LeftTopLong, LeftTopLat, RightDownLong, RightDownLat);
	countLookat(camera);
	countLookup(camera);
	countTilt();
	countHeading();
	countRoll();
	countIntersectPoint(origin_point, lookat, LeftDownLong, LeftDownLat, LeftTopLong, LeftTopLat, RightDownLong, RightDownLat);
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

}

double countAllData::getLongitude()
{
	return longitude;
}

double countAllData::getLatitude()
{
	return latitude;
}

double countAllData::getAltitude()
{
	return altitude;
}

double countAllData::getTilt()
{
	return tilt;
}

double countAllData::getHeading()
{
	return heading;
}

double countAllData::getRoll()
{
	return roll;
}

double countAllData::getAltitude_scale()
{
	return altitude_scale;
}

D3DXVECTOR3 countAllData::getIntersect_origin_point()
{
	return intersect_origin_point;
}

D3DXVECTOR3 countAllData::getIntersect_point()
{
	return intersect_point;
}
	
	