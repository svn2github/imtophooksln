
#ifndef __TOUCHSCREEN_FILTER_RECTIFY__
#define __TOUCHSCREEN_FILTER_RECTIFY__

#include <TouchlibFilter.h>

#define DEFAULT_RECTIFYLEVEL 20

class  RectifyFilter : public Filter
{

public:

    RectifyFilter(char* name);
    void kernel();
	void kernelWithROI();

    virtual ~RectifyFilter();

	virtual void getParameters(ParameterMap& pMap);
	virtual void setParameter(const char *name, const char *value);

    void setLevel(unsigned int value) {level = value; level_slider = level;}
    unsigned int getLevel(void) {return level;}


	virtual void showOutput(bool value, int windowx, int windowy);

private:
	bool bAutoSet;
	int level_slider;
    unsigned int level;

};

#endif // __TOUCHSCREEN_FILTER_RECTIFY__
