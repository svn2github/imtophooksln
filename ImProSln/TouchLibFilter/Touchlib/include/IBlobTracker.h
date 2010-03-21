#ifndef __TOUCHLIB_IBLOBTRACKER__
#define __TOUCHLIB_IBLOBTRACKER__

#include <vector>

#include "touchlib_platform.h"

#include "ITouchListener.h"
#include "TouchData.h"

#include "Image.h"

namespace touchlib {

class  IBlobTracker 
{
public:
	IBlobTracker();

	// ----  pure virtual functions  -----------------------------------------
	virtual bool getUseKalmanFilter() = 0;
	virtual bool setUseKalmanFilter(bool bUse) = 0;
	virtual int getNumFrameFix() = 0;
	virtual bool setNumFrameFix(int nFrame) = 0;
	virtual bool findBlobs(BwImage& frame) = 0;
	virtual void trackBlobs() = 0;
	virtual void gatherEvents() = 0;
	virtual std::vector<CvRect>* GetForeground() = 0;
	// ----  public members  -------------------------------------------------

	void registerListener(ITouchListener *listener);
	void setup(int r_dist, int r_min_dim, int r_max_dim, int g_frames, float minimumDisplacementThreshold);
	virtual bool drawFingers(IplImage* img) = 0;
public:
	static const float DEFAULT_MINIMUM_DISPLACEMENT_THRESHOLD;

protected:
	void doTouchEvent(const TouchData& data);
	void doUpdateEvent(const TouchData& data);
	void doUntouchEvent(const TouchData& data);

	int reject_distance_threshold;
	int reject_min_dimension;
	int reject_max_dimension;
	int ghost_frames;
	float minimumDisplacementThreshold;

	std::vector<ITouchListener *> listenerList;
};

}

#endif // __TOUCHLIB_IBLOBTRACKER__
