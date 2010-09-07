#include "d3dx9math.h"

class GEPlaneIntersection
{
public:

	GEPlaneIntersection();

	void IntersectPoint(D3DXPLANE plane, D3DXVECTOR3 start_point, D3DXVECTOR3 end_point);
	
	bool hit(double lonMin, double lonMax, double latMin, double latMax, double altMin, double altMax);

	D3DXVECTOR3 getHitPoint(void);

private:

	D3DXVECTOR3 hit_point;

};