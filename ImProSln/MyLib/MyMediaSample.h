#pragma once
#include <initguid.h>

//#include "ARToolKitPlus/arMulti.h"
// {CCBA1F17-0B65-4b88-AE98-CF864D4EB425}
DEFINE_GUID(GUID_IMPRO_FeedbackTYPE, 
			0xccba1f17, 0xb65, 0x4b88, 0xae, 0x98, 0xcf, 0x86, 0x4d, 0x4e, 0xb4, 0x25);

// {547D0928-D9CE-4064-9D87-3ABE57333711}
DEFINE_GUID(GUID_WarpConfig, 
			0x547d0928, 0xd9ce, 0x4064, 0x9d, 0x87, 0x3a, 0xbe, 0x57, 0x33, 0x37, 0x11);

// {7B95C432-C7CE-48a1-9167-94E687A2820B}
DEFINE_GUID(GUID_ARLayoutStartegyData, 
			0x7b95c432, 0xc7ce, 0x48a1, 0x91, 0x67, 0x94, 0xe6, 0x87, 0xa2, 0x82, 0xb);

// {DE2F3A15-A44B-4729-B6CF-90131D4F14A2}
DEFINE_GUID(GUID_ForegroundRegion_Data, 
			0xde2f3a15, 0xa44b, 0x4729, 0xb6, 0xcf, 0x90, 0x13, 0x1d, 0x4f, 0x14, 0xa2);

// {4E716891-B2F5-4d4c-9A73-1F33971A88DE}
DEFINE_GUID(GUID_MaskVertexData, 
			0x4e716891, 0xb2f5, 0x4d4c, 0x9a, 0x73, 0x1f, 0x33, 0x97, 0x1a, 0x88, 0xde);

// {C63A727A-46DE-48c9-B588-B11EE298CDAC}
DEFINE_GUID(GUID_ROIData, 
			0xc63a727a, 0x46de, 0x48c9, 0xb5, 0x88, 0xb1, 0x1e, 0xe2, 0x98, 0xcd, 0xac);

class WarpConfigData
{
public:
	float warpMat[4][4];
};

#ifndef _fRECT_
#define _fRECT_
class fRECT
{
public:
	float left, top, right, bottom;
	fRECT(float l, float t, float r, float b) : left(l), top(t),
		right(r), bottom(b)
	{	}
	fRECT() : left(0), top(0), right(0), bottom(0)
	{	 	}
	bool IsIntersect(const fRECT& rectB)
	{
		bool intersectX = false, intersectY = false;
		if ((this->left >= rectB.left && this->left <= rectB.right) ||
			(this->right >= rectB.left && this->right <= rectB.right) ||
			(rectB.left >= this->left && rectB.left <= this->right) ||
			(rectB.right >= this->left && rectB.right <= this->right))
		{
			intersectX = true;
		}
		if ((this->top >= rectB.top && this->top <= rectB.bottom) ||
			(this->bottom >= rectB.top && this->bottom <= rectB.bottom) ||
			(rectB.top >= this->top && rectB.top <= this->bottom) ||
			(rectB.bottom >= this->top && rectB.bottom <= this->bottom))
		{
			intersectY = true;
		}
		return (intersectX && intersectY);
	}
};
#endif
class ARLayoutStartegyData
{
public:
	fRECT* camViews;
	unsigned int numCamView;
	fRECT* fingerRects;
	unsigned int numFingers;
	ARLayoutStartegyData() : camViews(NULL), numCamView(0), fingerRects(NULL), numFingers(0)
	{
	}
	~ARLayoutStartegyData()
	{
		if (camViews != NULL)
		{
			delete [] camViews;
			camViews = NULL;
		}
		if (fingerRects != NULL)
		{
			delete[] fingerRects;
			fingerRects = NULL;
		}
	}
	 ARLayoutStartegyData& operator = (const ARLayoutStartegyData &rhs)
	 {
		 if (camViews != NULL)
		 {
			 delete [] camViews;
			 camViews = NULL;
			 this->numCamView = 0;

		 }
		 if (fingerRects != NULL)
		 {
			 delete[] fingerRects;
			 fingerRects = NULL;
			 this->numFingers = 0;
		 }
		 this->numCamView = rhs.numCamView;
		 this->numFingers = rhs.numFingers;
		 if (rhs.numCamView != 0)
		 {
			 this->camViews = new fRECT[this->numCamView];
			 memcpy(this->camViews, rhs.camViews, sizeof(fRECT)*rhs.numCamView);
		 }
		 if (rhs.numFingers != 0)
		 {
			 this->fingerRects = new fRECT[rhs.numFingers];
			 memcpy(this->fingerRects, rhs.fingerRects, sizeof(fRECT)*rhs.numFingers);
		 }
		 return *this;
	 }
};

class ForegroundRegion
{
public:
	fRECT* foregroundRects;
	unsigned int numForeground;
	ForegroundRegion() : foregroundRects(NULL), numForeground(0)
	{	}
	~ForegroundRegion()
	{
		if (foregroundRects != NULL)
		{
			delete[] foregroundRects;
			foregroundRects = NULL;
		}
	}
};

class MaskVertexData
{
public:
	float* m_points;
	int m_nPoints;
	int m_maskflag;
	MaskVertexData() : m_points(NULL), m_nPoints(0), m_maskflag(2)
	{
		
	}
	~MaskVertexData()
	{
		if (m_points != NULL)
		{
			delete [] m_points;
			m_points = NULL;
		}
	}

	MaskVertexData& operator = (const MaskVertexData &rhs)
	{
		if (m_points != NULL)
		{
			delete [] m_points;
			m_points = NULL;
			this->m_points = 0;
		}
		this->m_nPoints = rhs.m_nPoints;
		this->m_maskflag = rhs.m_maskflag;
		if (rhs.m_nPoints != 0)
		{
			this->m_points = new float[rhs.m_nPoints*2];
			memcpy(this->m_points, rhs.m_points, sizeof(float)*rhs.m_nPoints*2);
		}
		return *this;
	}

};

class ROIData
{
public:
	fRECT* m_pRECTs;
	int m_nRECTs;
	ROIData() : m_pRECTs(NULL), m_nRECTs(0) 
	{

	}
	~ROIData()
	{
		if (m_pRECTs != NULL)
		{
			delete [] m_pRECTs;
			m_pRECTs = NULL;
		}
		m_nRECTs = 0;
	}
	ROIData& operator = (const ROIData &rhs)
	{
		if (m_pRECTs != NULL)
		{
			delete [] m_pRECTs;
			m_pRECTs = NULL;
			m_nRECTs = 0;
		}
		this->m_nRECTs = rhs.m_nRECTs;
		if (rhs.m_nRECTs != 0)
		{
			this->m_pRECTs = new fRECT[rhs.m_nRECTs];
			memcpy(this->m_pRECTs, rhs.m_pRECTs, sizeof(fRECT)*rhs.m_nRECTs);
		}
		return *this;
	}
};