#include <ShapeFilter.h>
#include <highgui.h>


// ----  initialization of non-integral constants  ----------------------------


const char *ShapeFilter::TRACKBAR_LABEL_BLUR 		= "blur";
const char *ShapeFilter::PARAMETER_BLUR		= "blur";

const char *ShapeFilter::TRACKBAR_LABEL_LEVEL 		= "level";
const char *ShapeFilter::PARAMETER_LEVEL		= "level";


// ----  implementations  -----------------------------------------------------


ShapeFilter::ShapeFilter(char *s) : Filter(s)
{
	blurLevel = DEFAULT_BLUR_LEVEL;
	blurLevelSlider = blurLevel;

	levelLevel = DEFAULT_LEVEL_LEVEL;
	levelSlider = levelLevel;

	buffer = NULL;
}


ShapeFilter::~ShapeFilter()
{
	if (buffer != NULL)
		cvReleaseImage(&buffer);
}

void ShapeFilter::getParameters(ParameterMap &pMap)
{
	pMap[std::string(PARAMETER_BLUR)] = toString(blurLevel);
	pMap[std::string(PARAMETER_LEVEL)] = toString(levelLevel);
}

void ShapeFilter::setParameter(const char *name, const char *value)
{
	if (strcmp(name, PARAMETER_BLUR) == 0) {
		blurLevel = (int) atof(value);
		blurLevelSlider = blurLevel;
		if (show)
			cvSetTrackbarPos(TRACKBAR_LABEL_BLUR, this->name.c_str(), blurLevel);
	} if (strcmp(name, PARAMETER_LEVEL) == 0) {
		levelLevel = (int) atof(value);
		levelSlider = levelLevel;
		if (show)
			cvSetTrackbarPos(TRACKBAR_LABEL_LEVEL, this->name.c_str(), levelLevel);
	}
}



void ShapeFilter::showOutput(bool value, int windowx, int windowy)
{
	Filter::showOutput(value, windowx, windowy);

	if (value) {
		cvCreateTrackbar(TRACKBAR_LABEL_BLUR, name.c_str(), &blurLevelSlider, 255, NULL);
		cvCreateTrackbar(TRACKBAR_LABEL_LEVEL, name.c_str(), &levelSlider, 255, NULL);
		
	}

}

void ShapeFilter::kernel()
{
	if (show) {
		blurLevel = blurLevelSlider;
		levelLevel = levelSlider;
	}


	
	if (destination == NULL) {
		destination = cvCreateImage(cvGetSize(source), source->depth, source->nChannels);
		destination->origin = source->origin;  // same vertical flip as source
	}
	if (buffer == NULL) {
		buffer = cvCreateImage(cvGetSize(source), source->depth, source->nChannels);
		buffer->origin = source->origin;
	}

	// create the unsharp mask using a linear average filter
	int blurParameter = blurLevel*2+1;
	cvSmooth(source, buffer, CV_BLUR, blurParameter, blurParameter);

	cvThreshold(source, source, levelLevel, 255, CV_THRESH_TOZERO);		//CV_THRESH_BINARY
    cvCanny(source, destination, (float)blurParameter, (float)blurParameter*3, 3);
	

}


void ShapeFilter::kernelWithROI()
{
	if (show) {
		blurLevel = blurLevelSlider;
		levelLevel = levelSlider;
	}



	if (destination == NULL) {
		destination = cvCreateImage(cvGetSize(source), source->depth, source->nChannels);
		destination->origin = source->origin;  // same vertical flip as source
	}
	if (buffer == NULL) {
		buffer = cvCreateImage(cvGetSize(source), source->depth, source->nChannels);
		buffer->origin = source->origin;
	}


	cvZero(destination);
	CvRect roiRECT = cvGetImageROI(source);
	cvSetImageROI(destination, roiRECT);
	cvSetImageROI(buffer, roiRECT);
	// create the unsharp mask using a linear average filter
	int blurParameter = blurLevel*2+1;
	cvSmooth(source, buffer, CV_BLUR, blurParameter, blurParameter);

	cvThreshold(source, source, levelLevel, 255, CV_THRESH_TOZERO);		//CV_THRESH_BINARY
	cvCanny(source, destination, (float)blurParameter, (float)blurParameter*3, 3);

	cvResetImageROI(buffer);
}

