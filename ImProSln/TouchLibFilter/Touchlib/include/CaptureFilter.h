

#ifndef __TOUCHSCREEN_FILTER_CAPTURE__
#define __TOUCHSCREEN_FILTER_CAPTURE__

#include <Filter.h>
#include "TouchLibFilter.h"
#include <cv.h>
#include <cxcore.h>
#include <highgui.h>

// FIXME: we should put this in a namespace

class CaptureFilter : public Filter
{
	private:
		static CvCapture* capture;
		static void acquireImage(void *param);
		static IplImage* acquiredImage;
		static HANDLE hThread;
		char source[255];
	public:
		CaptureFilter(char*);
		~CaptureFilter();
		bool isRunning();
		void kernel();
		void kernelWithROI();
		virtual void process(IplImage* frame);

		virtual void getParameters(ParameterMap& pMap);
		virtual void setParameter(const char *name, const char *value);

};

#endif // __TOUCHSCREEN_FILTER_CAPTURE__
