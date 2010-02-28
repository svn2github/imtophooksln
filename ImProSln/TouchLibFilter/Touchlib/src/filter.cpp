
#include <TouchlibFilter.h>
#include <highgui.h>


Filter::Filter(char* s)
{

    name = std::string(s);

    // default is to not show filter output
    show = false;

	source = NULL;
	destination = NULL;
	chainedfilter = NULL;
}


Filter::~Filter()
{
    if( show )
        cvDestroyWindow( name.c_str() );

    if( destination )
        cvReleaseImage(&destination);


	
}


void Filter::showOutput(bool value, int windowx, int windowy)
{
    if( value && !show )
    {
        cvNamedWindow( name.c_str(), CV_WINDOW_AUTOSIZE );

		cvMoveWindow(name.c_str(), windowx, windowy);
        show = true;
    }
    else if( !value && show )
    {
        cvDestroyWindow( name.c_str() );
        show = false;
    }
}

void Filter::processWithROI(IplImage* frame)
{
	source = frame;

	// subclasses need to implement this abstract method.
	this->kernelWithROI();

	if( !destination )
		return;

	if( chainedfilter )
		chainedfilter->processWithROI(destination);

	if( show )
	{
		//printf("Show img\n");
		CvRect roi;
		roi = cvGetImageROI(destination);
		cvResetImageROI(destination);
		cvShowImage(name.c_str(), destination); 
		cvSetImageROI(destination, roi);
	}
}
void Filter::process(IplImage* frame)
{
	source = frame;

	// subclasses need to implement this abstract method.
	this->kernel();

	if( !destination )
		return;

	if( chainedfilter )
		chainedfilter->process(destination);

	if( show )
	{
		cvShowImage(name.c_str(), destination); 
	}

}


void Filter::connectTo(Filter* targetfilter)
{
    chainedfilter = targetfilter;
}
