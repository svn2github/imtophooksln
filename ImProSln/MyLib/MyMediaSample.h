#pragma once
#include <initguid.h>

//#include "ARToolKitPlus/arMulti.h"
// {CCBA1F17-0B65-4b88-AE98-CF864D4EB425}
DEFINE_GUID(GUID_MyMediaSample, 
			0xccba1f17, 0xb65, 0x4b88, 0xae, 0x98, 0xcf, 0x86, 0x4d, 0x4e, 0xb4, 0x25);

// {547D0928-D9CE-4064-9D87-3ABE57333711}
DEFINE_GUID(GUID_WarpConfig, 
			0x547d0928, 0xd9ce, 0x4064, 0x9d, 0x87, 0x3a, 0xbe, 0x57, 0x33, 0x37, 0x11);

// {619A00B3-63BF-430c-93A5-01A73235BDCA}
DEFINE_GUID(GUID_D3DXTEXTURE9_POINTER, 
			0x619a00b3, 0x63bf, 0x430c, 0x93, 0xa5, 0x1, 0xa7, 0x32, 0x35, 0xbd, 0xca);

// {F6DE4088-A0E1-49f9-9401-34576F948052}
DEFINE_GUID(GUID_FORMATTYPE_D3DXTEXTURE9DESC, 
			0xf6de4088, 0xa0e1, 0x49f9, 0x94, 0x1, 0x34, 0x57, 0x6f, 0x94, 0x80, 0x52);

// {7B95C432-C7CE-48a1-9167-94E687A2820B}
DEFINE_GUID(GUID_ARLayoutStartegyData, 
			0x7b95c432, 0xc7ce, 0x48a1, 0x91, 0x67, 0x94, 0xe6, 0x87, 0xa2, 0x82, 0xb);

// {DE2F3A15-A44B-4729-B6CF-90131D4F14A2}
DEFINE_GUID(GUID_ForegroundRegion_Data, 
			0xde2f3a15, 0xa44b, 0x4729, 0xb6, 0xcf, 0x90, 0x13, 0x1d, 0x4f, 0x14, 0xa2);

// {4E716891-B2F5-4d4c-9A73-1F33971A88DE}
DEFINE_GUID(GUID_MaskVertexData, 
			0x4e716891, 0xb2f5, 0x4d4c, 0x9a, 0x73, 0x1f, 0x33, 0x97, 0x1a, 0x88, 0xde);

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
		
		if (rhs.m_nPoints != 0)
		{
			this->m_points = new float[rhs.m_nPoints];
			memcpy(this->m_points, rhs.m_points, sizeof(float)*rhs.m_nPoints);
		}
		return *this;
	}

};