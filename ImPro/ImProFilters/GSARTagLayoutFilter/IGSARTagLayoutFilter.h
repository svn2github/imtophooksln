#pragma once

#ifdef GS_ARTAGLAYOUT_EXPORTS
#define GSARTAGLAYOUT_API __declspec(dllexport)
#else
#define GSARTAGLAYOUT_API __declspec(dllimport)
#endif

// {0BB79E7C-4CF3-C620-7856-ADF1878204B0}
DEFINE_GUID(IID_IGSARTagLayoutFilter, 
			0x0bb79e7c, 0x4cf3, 0xc620, 0x78, 0x56, 0xad, 0xf1, 0x87, 0x82, 0x04, 0xb0);
// {BFE39AD5-FD2E-1992-53A9-CFAAC0C50BA2}
DEFINE_GUID(CLSID_GSARTagLayoutFilter, 
			0xbfe39ad5, 0xfd2e, 0x1992, 0x53, 0xa9, 0xcf, 0xaa, 0xc0, 0xc5, 0x0b, 0xa2B);
// {E47682B9-4477-A34B-2E72-DC361D4751FF}
DEFINE_GUID(CLSID_GSARTagLayoutFilterProp, 
			0xe47682b9, 0x4477, 0xa34b, 0x2e, 0x72, 0xdc, 0x36, 0x1d, 0x47, 0x51, 0xff);

// {51AC9694-738B-4245-872B-99DC73148519}
DEFINE_GUID(GSMEDIASUBTYPE_GSARTagLayoutStrategy_CONFIG_PTR, 
			0x51ac9694, 0x738b, 0x4245, 0x87, 0x2b, 0x99, 0xdc, 0x73, 0x14, 0x85, 0x19);

// {F4DC2644-6823-49a0-A09F-098F1821C395}
DEFINE_GUID(GSMEDIASUBTYPE_GSARTagLayout_CONFIG, 
			0xf4dc2644, 0x6823, 0x49a0, 0xa0, 0x9f, 0x9, 0x8f, 0x18, 0x21, 0xc3, 0x95);

namespace GSARLayoutNS
{

	struct GSARTAGLAYOUT_API GSFPoint3D
	{
		float x;
		float y;
		float z;
		GSFPoint3D() : x(0), y(0), z(0)
		{};
		GSFPoint3D(float _x, float _y, float _z) : x(_x), y(_y), z(_z)
		{};
	};


	struct GSARTAGLAYOUT_API GSBoundingBox
	{
		GSFPoint3D LT;
		GSFPoint3D RB;
		GSBoundingBox() : LT(GSFPoint3D(0,0,0)), RB(GSFPoint3D(1,1,1))
		{	};
		BOOL IsIntersect(const GSBoundingBox& rhs);

	};

	struct GSARTAGLAYOUT_API GSFRect3D
	{
		GSFPoint3D LT;
		GSFPoint3D LB;
		GSFPoint3D RB;
		GSFPoint3D RT;

		GSFRect3D() : LT(GSFPoint3D(0,0,0)),  LB(GSFPoint3D(0,1,0)),  RB(GSFPoint3D(1,1,0)),  RT(GSFPoint3D(1,0,0))
		{};
	};

	struct GSARTAGLAYOUT_API GSFPoint
	{
		float x;
		float y;
		GSFPoint() : x(0), y(0)
		{};
		GSFPoint(float _x, float _y) : x(_x), y(_y)
		{};
	};

	struct GSARTAGLAYOUT_API GSBoundingBox2D
	{
		GSFPoint LT;
		GSFPoint RB;
		GSBoundingBox2D() : LT(GSFPoint(0,0)), RB(GSFPoint(1,1))
		{	};
		GSBoundingBox2D(const GSBoundingBox& rhs) : LT(GSFPoint(rhs.LT.x, rhs.LT.y)), RB(GSFPoint(rhs.RB.x, rhs.RB.y))
		{		};
		GSBoundingBox2D& operator = (const GSBoundingBox& rhs)
		{	
			LT.x = rhs.LT.x;	LT.y = rhs.LT.y;
			RB.x = rhs.RB.x;    RB.y = rhs.RB.y;
			return *this;
		};
		float GetArea();

		BOOL IsIntersect(const GSBoundingBox2D& rhs);
	};

	struct GSARTAGLAYOUT_API GSARTag
	{
		int     m_tagID;
		GSFRect3D m_tagRect;
		BOOL    m_visible;
		float   m_matTran[16];
		GSARTag() : m_tagID(-1), m_visible(TRUE)
		{
			memset(m_matTran, 0, sizeof(m_matTran));
			m_matTran[0] = 1.0;
			m_matTran[5] = 1.0;
			m_matTran[10] = 1.0;
			m_matTran[15] = 1.0;
		}
		HRESULT GetBoundingBox(GSBoundingBox& bbox);
		HRESULT GetBoundingBox2D(GSBoundingBox2D& bbox2D, BOOL invY = FALSE);
	};

	struct GSARTAGLAYOUT_API GSARTagLayout
	{
		GSARTag* m_pARTag;
		UINT m_nARTag;
		GSARTagLayout();
		GSARTagLayout(const GSARTagLayout& rhs);
		~GSARTagLayout();
		GSARTagLayout& operator = (const GSARTagLayout &rhs);
	};

	struct GSARTAGLAYOUT_API GSARLayoutStartegyData
	{
	public:
		GSBoundingBox2D* camViews;
		unsigned int numCamView;
		GSBoundingBox2D* fingerRects;
		unsigned int numFingers;
		GSARLayoutStartegyData();
		GSARLayoutStartegyData(const GSARLayoutStartegyData &rhs);
		~GSARLayoutStartegyData();
		GSARLayoutStartegyData& operator = (const GSARLayoutStartegyData &rhs);
	};
};


using namespace GSARLayoutNS;

MIDL_INTERFACE("0BB79E7C-4CF3-C620-7856-ADF1878204B0")
IGSARTagLayoutFilter: public IUnknown
{
public:
	
	virtual HRESULT DecideLayout(GSBoundingBox2D* camRects, UINT numCamRect,
		GSBoundingBox2D* fingerRects, UINT numFingerRects, BOOL& bLayoutChanged, float fingerExtend = 0.07) = 0;
	virtual HRESULT initARLayout(UINT numLevel = 2, UINT intMarkerBits = 8, UINT intBorderBits = 2, float intWidthBits = 80) = 0;
	virtual int GetNumMarker() = 0;
	virtual HRESULT SetMarkerVisible(int idx, BOOL bVisible) = 0;
	virtual HRESULT SetMarkerVisibleByID(int id, BOOL bVisible) = 0;
	virtual int GetMarkerID(int idx) = 0;

	virtual HRESULT SetFrameRate(float fps) = 0;
	virtual float GetFrameRate() = 0;

	virtual float GetBlackLevel() = 0;
	virtual HRESULT SetBlackLevel(float level) = 0;
};
