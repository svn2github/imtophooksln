#ifndef __TOUCHLIB_CBLOBTRACKER__
#define __TOUCHLIB_CBLOBTRACKER__

#include <vector>
#include <math.h>
#include <vector2d.h>
#include <rect2d.h>

#include <Image.h>
#include <touchlib_platform.h>
#include "ITouchListener.h"
#include "TouchData.h"

#include "IBlobTracker.h"
#include "cv.h"

#define HISTORY_FRAMES	10
#define MAX_NUMFINGER 12
// a finger is a blob with an ID and prediction info
// CFinger should be able to accept a CBlob as a constructor

namespace touchlib
{

	class CBlob
	{
    public:
		CBlob()
		{
			area = 0.0f;
			weight = 0.0f;
			tagID = 0;
		}
		vector2df center;
		float area;
		rect2df box;
		float angle;
		float weight;

		int tagID;		// for fiducal markers. 0 = regular touchpoint.
	};


	struct BlobEquiv
	{
		unsigned char from;
		unsigned char to;
		int x;
		int y;
	};

    //////////////

	class CFinger : public CBlob
	{
	public:
		int ID;
		vector2df delta;
		vector2df predictedPos;
		vector2df displacement;
		float deltaArea;
		bool markedForDeletion;
		int framesLeft;
		bool bGeneratedByKalman;

		std::vector<float> error;
		std::vector<int> closest;		// ID's of the closest points, sorted..
	public:
		CFinger() 
		{
			ID = -1;
			markedForDeletion = false;
			framesLeft = 0;
			
			delta.X = 0;
			delta.Y = 0;
			predictedPos.X = 0;
			predictedPos.Y = 0;
			displacement.X = 0;
			displacement.Y = 0;
			deltaArea = 0;
			bGeneratedByKalman = false;
		}

		CFinger(const CBlob &b)
		{
			ID = -1;
			center = b.center;
			area = b.area;
			box = b.box;
			angle = b.angle;
			weight = b.weight;
			tagID = b.tagID;

			delta.X = 0;
			delta.Y = 0;
			predictedPos.X = 0;
			predictedPos.Y = 0;
			displacement.X = 0;
			displacement.Y = 0;
			deltaArea = 0;
			bGeneratedByKalman = false;

		}

		int getLowestError()
		{
			int best=-1;
			float best_v=99999.0f;

			for(unsigned int i=0; i<error.size(); i++)
			{
				if(error[i] < best_v)
				{
					best = i;
					best_v = error[i];
				}
			}

			return best;
		};

		TouchData getTouchData()
		{
			TouchData data;
			data.ID = ID;
			data.X = center.X;
			data.Y = center.Y;

			data.angle = angle;
			data.width = box.getWidth();
			data.height = box.getHeight();

			data.dX = delta.X;
			data.dY = delta.Y;

			data.weight = weight;
			
			data.tagID = tagID;

			return data;
		};


	};


	class FingerKalman
	{
	private:
		CvKalman* generateKalman();
		
	protected:
		CvKalman* m_kalman;
		
		CFinger m_lastFinger;
		//float m_lastVx;
		//float m_lastVy;
	public:
		int m_lostTimes;
	public:
		FingerKalman();
		~FingerKalman();
		BOOL init(const CFinger* curFinger);
		BOOL update(const CFinger* curFinger);
		BOOL predict(int dt, float* posX, float* posY, float* vX = NULL, float* vY = NULL, float* aX = NULL, float* aY = NULL);
		BOOL GetLastFinger(CFinger* finger);
		
	};
	class  CBlobTracker : public IBlobTracker
	{
	public:
		CBlobTracker();
		~CBlobTracker();
		virtual bool getUseKalmanFilter();
		virtual bool setUseKalmanFilter(bool bUse);
		virtual int getNumFrameFix() { return m_nKalmanFix;}
		virtual bool setNumFrameFix(int nFrame) { m_nKalmanFix = nFrame; return true;};
		bool findBlobs(BwImage &img);
		void trackBlobs();
		void gatherEvents();
		std::vector<CvRect>* GetForeground()
		{	return &foregroundLists;	};
		bool drawFingers(IplImage* img);
		
	private:
		inline void permute2(int k);
		inline bool checkValid(int start);
		inline bool checkValidNew(int start);
		
	

		int level;
		float getError(CFinger &old, CFinger &cur);
		//Kalman filter tracking & predict
		bool m_bUseKalmanFilter;
		int m_nKalmanFix;
		std::map<int, FingerKalman*> m_fKalman; //ID, kalman, missing times		
		BOOL updateFingerKalman(const CFinger* curFinger);
		BOOL updateAllFingerKalman();
		BOOL correctLostFingerByKalman();
		BOOL replaceFingerPosByKalman();
		BOOL findOldFinger(int _id, CFinger& finger);
		BOOL findCurFinger(int _id, CFinger& finger);
#ifdef WIN32
#pragma warning( disable : 4251 )  // http://www.unknownroad.com/rtfm/VisualStudio/warningC4251.html
#endif

		int currentID;
		int extraIDs;
		int numcheck;

		std::vector<std::vector<int> > matrix;
		std::vector<int> ids;
		std::vector<std::vector<CFinger> > history;
		std::vector<CBlob> blobList;
		std::vector<CFinger> current;

		std::vector<CvRect> foregroundLists;
#ifdef WIN32
#pragma warning( default : 4251 )
#endif

	};

}

#endif // __TOUCHLIB_CBLOBTRACKER__
