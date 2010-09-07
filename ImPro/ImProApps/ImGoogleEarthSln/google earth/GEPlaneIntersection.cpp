#include "stdafx.h"
#include "d3dx9math.h"
#include "GEPlaneIntersection.h"

GEPlaneIntersection::GEPlaneIntersection()
{
	hit_point.x = 0;
	hit_point.y = 0;
	hit_point.z = 0;
}

void GEPlaneIntersection::IntersectPoint(D3DXPLANE plane, D3DXVECTOR3 start_point, D3DXVECTOR3 end_point)
{
	D3DXPlaneIntersectLine(&hit_point,&plane,&start_point,&end_point); 	
}

bool GEPlaneIntersection::hit(double lonMin, double lonMax, double latMin, double latMax, double altMin, double altMax)
{
	int count = 0;

	if(hit_point.x >= lonMin && hit_point.x <= lonMax)	count++;
	if(hit_point.y >= latMin && hit_point.y <= latMax)	count++;
	if(hit_point.z >= altMin && hit_point.z <= altMax)	count++;

	if(count >= 2)	return true;
	else	return false;
}

D3DXVECTOR3 GEPlaneIntersection::getHitPoint()
{
	return hit_point;
}