
#include <InvertFilter.h>


InvertFilter::InvertFilter(char* s) : Filter(s)
{

}


InvertFilter::~InvertFilter()
{
}

// The smooth filter really needs the blur size as a param
void InvertFilter::kernel()
{
    // derived class responsible for allocating storage for filtered image
    if( !destination )
    {
        destination = cvCreateImage(cvSize(source->width,source->height), source->depth, source->nChannels);
        destination->origin = source->origin;  // same vertical flip as source
    }
	cvNot(source, destination);
}
// The smooth filter really needs the blur size as a param
void InvertFilter::kernelWithROI()
{
	// derived class responsible for allocating storage for filtered image
	if( !destination )
	{
		destination = cvCreateImage(cvSize(source->width,source->height), source->depth, source->nChannels);
		destination->origin = source->origin;  // same vertical flip as source
	}
	cvZero(destination);
	CvRect roiRECT = cvGetImageROI(source);
	cvSetImageROI(destination, roiRECT);

	cvNot(source, destination);


}