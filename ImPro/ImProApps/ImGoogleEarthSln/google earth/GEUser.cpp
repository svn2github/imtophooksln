#include "stdafx.h"
#include <string>
#include "GEUser.h"

using namespace std;

GEUser::GEUser()
{
	longitude = 0;
	latitude = 0;
	altitude = 0;
	tilt = 0;
	heading = 0;
	roll = 0;;

	initialized = false;
	moved = false;
}