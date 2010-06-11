#include <InitGuid.h>
#include "MyMediaSample.h"

fRECT::fRECT(float l, float t, float r, float b) : left(l), top(t),
right(r), bottom(b)
{	}
fRECT::fRECT() : left(0), top(0), right(0), bottom(0)
{	 	}

bool fRECT::IsIntersect(const fRECT& rectB)
{
	bool intersectX = false, intersectY = false;
	if ((this->left >= rectB.left && this->left <= rectB.right) ||
		(this->right >= rectB.left && this->right <= rectB.right) ||
		(rectB.left >= this->left && rectB.left <= this->right) ||
		(rectB.right >= this->left && rectB.right <= this->right))
	{
		intersectX = true;
	}
	if (intersectX == false)
	{
		return false;
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


ARLayoutStartegyData::ARLayoutStartegyData() : camViews(NULL), numCamView(0), fingerRects(NULL), numFingers(0)
{
}
ARLayoutStartegyData::~ARLayoutStartegyData()
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
ARLayoutStartegyData& ARLayoutStartegyData::operator = (const ARLayoutStartegyData &rhs)
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


ForegroundRegion::ForegroundRegion() : foregroundRects(NULL), numForeground(0)
{	}
ForegroundRegion::~ForegroundRegion()
{
	if (foregroundRects != NULL)
	{
		delete[] foregroundRects;
		foregroundRects = NULL;
	}
}
ForegroundRegion::ForegroundRegion(const ForegroundRegion& rhs)
{
	if (foregroundRects != NULL)
	{
		delete [] foregroundRects;
		foregroundRects = NULL;
		this->numForeground = 0;
	}
	if (rhs.numForeground == 0)
		return;
	this->numForeground = rhs.numForeground;
	this->foregroundRects = new fRECT[this->numForeground];
	memcpy((void*)this->foregroundRects, rhs.foregroundRects, sizeof(fRECT)*numForeground);

}
ForegroundRegion& ForegroundRegion::operator = (const ForegroundRegion &rhs)
{
	if (foregroundRects != NULL)
	{
		delete [] foregroundRects;
		foregroundRects = NULL;
		this->numForeground = 0;
	}
	if (rhs.numForeground == 0)
		return *this;
	this->numForeground = rhs.numForeground;
	this->foregroundRects = new fRECT[this->numForeground];
	memcpy((void*)this->foregroundRects, rhs.foregroundRects ,sizeof(fRECT)*numForeground);
	return *this;
}
MaskVertexData::MaskVertexData() : m_points(NULL), m_nPoints(0), m_maskflag(2)
{

}
MaskVertexData::~MaskVertexData()
{
	if (m_points != NULL)
	{
		delete [] m_points;
		m_points = NULL;
	}
}

MaskVertexData& MaskVertexData::operator = (const MaskVertexData &rhs)
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
ROIData::ROIData() : m_pRECTs(NULL), m_nRECTs(0) 
{

}
ROIData::~ROIData()
{
	if (m_pRECTs != NULL)
	{
		delete [] m_pRECTs;
		m_pRECTs = NULL;
	}
	m_nRECTs = 0;
}
ROIData& ROIData::operator = (const ROIData &rhs)
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