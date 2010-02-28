

#ifndef __TOUCHSCREEN_FILTER_INVERT__
#define __TOUCHSCREEN_FILTER_INVERT__

#include <TouchlibFilter.h>

class  InvertFilter : public Filter
{

public:

    InvertFilter(char*);
    virtual ~InvertFilter();
    void kernel();
	void kernelWithROI();
	
private:




};

#endif // __TOUCHSCREEN_FILTER_INVERT__
