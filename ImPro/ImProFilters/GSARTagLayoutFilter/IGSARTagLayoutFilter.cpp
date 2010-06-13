#include "stdafx.h"
#include "IGSARTagLayoutFilter.h"
#include "GSMacro.h"
#include <D3DX10Math.h>
#include <math.h>
namespace GSARLayoutNS
{
	GSARTagLayout::GSARTagLayout() : m_pARTag(NULL), m_nARTag(0)
	{
		
	};
	GSARTagLayout::GSARTagLayout(const GSARTagLayout& rhs)
	{
		if (rhs.m_nARTag == 0)
		{
			m_pARTag = NULL;
			m_nARTag = 0;
		}
		else
		{
			m_nARTag = rhs.m_nARTag;
			m_pARTag = new GSARTag[m_nARTag];
			memcpy(m_pARTag, rhs.m_pARTag, sizeof(GSARTag)*m_nARTag);
		}
	};
	GSARTagLayout::~GSARTagLayout()
	{
		SAFE_DELETE_ARRAY(m_pARTag);
	};
	GSARTagLayout& GSARTagLayout::operator = (const GSARTagLayout &rhs)
	{
		SAFE_DELETE_ARRAY(m_pARTag);
		m_nARTag = 0;
		if (rhs.m_nARTag == 0)
		{
			m_pARTag = NULL;
			m_nARTag = 0;
		}
		else
		{
			m_nARTag = rhs.m_nARTag;
			m_pARTag = new GSARTag[m_nARTag];
			memcpy(m_pARTag, rhs.m_pARTag, sizeof(GSARTag)*m_nARTag);
		}
		return *this;
	};

	HRESULT GSARTag::GetBoundingBox(GSBoundingBox& bbox)
	{
		HRESULT hr = S_OK;
		D3DXMATRIX matTran;
		for (int row = 0; row <4; row++)
		{
			for(int col =0; col<4; col++)
			{
				matTran.m[row][col] = m_matTran[row*4 + col];
			}
		}
		D3DXVECTOR3 LT(m_tagRect.LT.x, m_tagRect.LT.y, m_tagRect.LT.z);
		D3DXVECTOR3 LB(m_tagRect.LB.x, m_tagRect.LB.y, m_tagRect.LB.z);
		D3DXVECTOR3 RB(m_tagRect.RB.x, m_tagRect.RB.y, m_tagRect.RB.z);
		D3DXVECTOR3 RT(m_tagRect.RT.x, m_tagRect.RT.y, m_tagRect.RT.z);

		D3DXVec3TransformCoord(&LT, &LT, &matTran);
		D3DXVec3TransformCoord(&LB, &LB, &matTran);
		D3DXVec3TransformCoord(&RB, &RB, &matTran);
		D3DXVec3TransformCoord(&RT, &RT, &matTran);
		
		bbox.LT.x = min(RT.x, min(RB.x, min(LB.x, LT.x)));
		bbox.LT.y = min(RT.y, min(RB.y, min(LB.y, LT.y)));
		bbox.LT.z = min(RT.z, min(RB.z, min(LB.z, LT.z)));

		bbox.RB.x = max(RT.x, max(RB.x, max(LB.x, LT.x)));
		bbox.RB.y = max(RT.y, max(RB.y, max(LB.y, LT.y)));
		bbox.RB.z = max(RT.z, max(RB.z, max(LB.z, LT.z)));

		return S_OK;
	};

	HRESULT GSARTag::GetBoundingBox2D(GSBoundingBox2D& bbox2D, BOOL invY)
	{
		HRESULT hr = S_OK;
		GSBoundingBox bbox;
		hr = GetBoundingBox(bbox);
		if (FAILED(hr))
			return hr;
		if (invY)
		{
			bbox2D.LT.x = bbox.LT.x; bbox2D.LT.y = -bbox.RB.y;
			bbox2D.RB.x = bbox.RB.x; bbox2D.RB.y = -bbox.LT.y;
		}
		else
		{
			bbox2D.LT.x = bbox.LT.x; bbox2D.LT.y = bbox.LT.y;
			bbox2D.RB.x = bbox.RB.x; bbox2D.RB.y = bbox.RB.y;
		}

		return S_OK;
	};

	BOOL GSBoundingBox::IsIntersect(const GSBoundingBox& rhs)
	{
		bool intersectX = FALSE, intersectY = FALSE, intersectZ = FALSE;
		if ((this->LT.x >= rhs.LT.x && this->LT.x <= RB.x) ||
			(this->RB.x >= rhs.LT.x && this->RB.x <= rhs.RB.x) ||
			(rhs.RB.x >= this->LT.x && rhs.LT.x <= this->RB.x) ||
			(rhs.RB.x >= this->LT.x && rhs.RB.x <= this->RB.x))
		{
			intersectX = true;
		}
		if (intersectX == FALSE)
		{
			return FALSE;
		}

		if ((this->LT.y >= rhs.LT.y && this->LT.y <= RB.y) ||
			(this->RB.y >= rhs.LT.y && this->RB.y <= rhs.RB.y) ||
			(rhs.RB.y >= this->LT.y && rhs.LT.y <= this->RB.y) ||
			(rhs.RB.y >= this->LT.y && rhs.RB.y <= this->RB.y))
		{
			intersectY = TRUE;
		}
		if (intersectY == FALSE)
		{
			return FALSE;
		}

		if ((this->LT.z >= rhs.LT.z && this->LT.z <= RB.z) ||
			(this->RB.z >= rhs.LT.z && this->RB.z <= rhs.RB.z) ||
			(rhs.RB.z >= this->LT.z && rhs.LT.z <= this->RB.z) ||
			(rhs.RB.z >= this->LT.z && rhs.RB.z <= this->RB.z))
		{
			intersectZ = TRUE;
		}
		return (intersectX && intersectY && intersectZ);
	};
	float GSBoundingBox2D::GetArea()
	{
		return abs((this->RB.x - this->LT.x)*(this->RB.y - this->LT.y));
	}
	BOOL GSBoundingBox2D::IsIntersect(const GSBoundingBox2D& rhs)
	{
		bool intersectX = FALSE, intersectY = FALSE;
		if ((this->LT.x >= rhs.LT.x && this->LT.x <= rhs.RB.x) ||
			(this->RB.x >= rhs.LT.x && this->RB.x <= rhs.RB.x) ||
			(rhs.RB.x >= this->LT.x && rhs.LT.x <= this->RB.x) ||
			(rhs.RB.x >= this->LT.x && rhs.RB.x <= this->RB.x))
		{
			intersectX = true;
		}
		if (intersectX == FALSE)
		{
			return FALSE;
		}

		if ((this->LT.y >= rhs.LT.y && this->LT.y <= rhs.RB.y) ||
			(this->RB.y >= rhs.LT.y && this->RB.y <= rhs.RB.y) ||
			(rhs.RB.y >= this->LT.y && rhs.LT.y <= this->RB.y) ||
			(rhs.RB.y >= this->LT.y && rhs.RB.y <= this->RB.y))
		{
			intersectY = TRUE;
		}

		return (intersectX && intersectY);
	};

	GSARLayoutStartegyData::GSARLayoutStartegyData()
	{
		camViews = NULL;
		numCamView = 0;
		fingerRects = NULL;
		numFingers = 0;
	}
	GSARLayoutStartegyData::GSARLayoutStartegyData(const GSARLayoutStartegyData &rhs)
	{
		SAFE_DELETE_ARRAY(camViews);
		SAFE_DELETE_ARRAY(fingerRects);
		numCamView = 0;
		numFingers = 0;
		if (rhs.numCamView > 0)
		{
			this->numCamView = rhs.numCamView;
			this->camViews = new GSBoundingBox2D[rhs.numCamView];
			memcpy(this->camViews, rhs.camViews, sizeof(GSBoundingBox2D)*rhs.numCamView );
		}

		if (rhs.numFingers > 0)
		{
			this->numFingers = rhs.numFingers;
			this->fingerRects = new GSBoundingBox2D[rhs.numFingers];
			memcpy(this->fingerRects, rhs.fingerRects, sizeof(GSBoundingBox2D)*rhs.numFingers );
		}
	}
	GSARLayoutStartegyData::~GSARLayoutStartegyData()
	{
		SAFE_DELETE_ARRAY(camViews);
		SAFE_DELETE_ARRAY(fingerRects);
	}
	GSARLayoutStartegyData& GSARLayoutStartegyData::operator = (const GSARLayoutStartegyData &rhs)
	{
		SAFE_DELETE_ARRAY(camViews);
		SAFE_DELETE_ARRAY(fingerRects);
		numCamView = 0;
		numFingers = 0;
		if (rhs.numCamView > 0)
		{
			this->numCamView = rhs.numCamView;
			this->camViews = new GSBoundingBox2D[rhs.numCamView];
			memcpy(this->camViews, rhs.camViews, sizeof(GSBoundingBox2D)*rhs.numCamView );
		}

		if (rhs.numFingers > 0)
		{
			this->numFingers = rhs.numFingers;
			this->fingerRects = new GSBoundingBox2D[rhs.numFingers];
			memcpy(this->fingerRects, rhs.fingerRects, sizeof(GSBoundingBox2D)*rhs.numFingers );
		}
		return *this;
	}
};
