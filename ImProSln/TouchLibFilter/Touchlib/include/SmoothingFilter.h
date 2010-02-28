

#ifndef __TOUCHSCREEN_FILTER_SMOOTHING__
#define __TOUCHSCREEN_FILTER_SMOOTHING__

#include <TouchlibFilter.h>

class  SmoothingFilter : public Filter
{

public:

    SmoothingFilter(char*);
    virtual ~SmoothingFilter();
    void kernel();
	void kernelWithROI();
	
};

#endif // __TOUCHSCREEN_FILTER_SMOOTHING__
