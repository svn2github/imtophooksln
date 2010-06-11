#pragma once

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


class fRECT
{
public:
	float left, top, right, bottom;
	fRECT(float l, float t, float r, float b);
	fRECT();
	bool IsIntersect(const fRECT& rectB);
};

class ARLayoutStartegyData
{
public:
	fRECT* camViews;
	unsigned int numCamView;
	fRECT* fingerRects;
	unsigned int numFingers;
	ARLayoutStartegyData();
	~ARLayoutStartegyData();
	ARLayoutStartegyData& operator = (const ARLayoutStartegyData &rhs);
};

class ForegroundRegion
{
public:
	fRECT* foregroundRects;
	unsigned int numForeground;
	ForegroundRegion();
	~ForegroundRegion();
	ForegroundRegion(const ForegroundRegion& rhs);
	ForegroundRegion& operator = (const ForegroundRegion &rhs);
};

class MaskVertexData
{
public:
	float* m_points;
	int m_nPoints;
	int m_maskflag;
	MaskVertexData();
	~MaskVertexData();
	MaskVertexData& operator = (const MaskVertexData &rhs);
};

class ROIData
{
public:
	fRECT* m_pRECTs;
	int m_nRECTs;
	ROIData();
	~ROIData();
	ROIData& operator = (const ROIData &rhs);
};