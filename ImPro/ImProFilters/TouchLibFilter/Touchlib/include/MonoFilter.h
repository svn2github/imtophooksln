
#ifndef __TOUCHLIB_FILTER_MONO__
#define __TOUCHLIB_FILTER_MONO__

#include <TouchlibFilter.h>


class  MonoFilter : public Filter
{

public:

    MonoFilter(char* name);
    void kernel();
	void kernelWithROI();

    virtual ~MonoFilter();
private:


};

#endif // __TOUCHLIB_FILTER_MONO__
