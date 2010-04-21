
#ifndef __TOUCHLIB_FILTERFACTORY__
#define __TOUCHLIB_FILTERFACTORY__

#include <cv.h>
#include <string>
#include <touchlib_platform.h>

#include "TouchlibFilter.h"

class  FilterFactory
{
public:
	FilterFactory();
	static Filter *createFilter(const char *type, const char *label);
};

#endif
