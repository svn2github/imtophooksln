#include <string>

using namespace std;

class GEUser
{
public:

	GEUser();

	double longitude;
	double latitude;
	double altitude;
	double tilt;
	double heading;
	double roll;

	string ID;

	bool initialized;
	bool moved;

};
