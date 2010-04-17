#include "stdafx.h"
#include "GSHomoWarpFilter.h"
#include "cv.h"
//#include "MyMediaSample.h"

GSHomoWarpFilter::GSHomoWarpFilter(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData)
: GSDXMuxFilter(NAME("GSHomoWarp Filter"), 0, CLSID_GSHomoWarpFilter)
{ 
	D3DXMatrixIdentity(&m_matTTS);
	D3DXMatrixIdentity(&m_InvmatTTS);
	m_bFlipY = true;
	m_bInvTTS = false;
}
GSHomoWarpFilter::~GSHomoWarpFilter()
{

}

CUnknown *WINAPI GSHomoWarpFilter::CreateInstance(LPUNKNOWN punk, HRESULT *phr)
{
	ASSERT(phr);
	// assuming we don't want to modify the data
	GSHomoWarpFilter *pNewObject = new GSHomoWarpFilter(punk, phr, FALSE);

	if(pNewObject == NULL) {
		if (phr)
			*phr = E_OUTOFMEMORY;
	}
	return pNewObject;
}

HRESULT GSHomoWarpFilter::NonDelegatingQueryInterface(REFIID iid, void **ppv)
{
	if (iid == IID_IGSHomoWarpFilter) 
	{
		return GetInterface(static_cast<IGSHomoWarpFilter*>(this), ppv);
	}
	else
	{
		// Call the parent class.
		return __super::NonDelegatingQueryInterface(iid, ppv);
	}
}

HRESULT GSHomoWarpFilter::CreatePins()
{
	return S_OK;
}

D3DXMATRIX GSHomoWarpFilter::ComputeTTS(const D3DXVECTOR2& v1, const D3DXVECTOR2& v2, const D3DXVECTOR2& v3, const D3DXVECTOR2& v4)
{
	D3DXMATRIX ret;
	D3DXMatrixIdentity(&ret);
	CvMat cvPt;
	CvMat dstPt;

	float t[] = {0,0,
		0,1,
		1,0,
		1,1};
	float d[] = {v1.x, v1.y,
		v2.x, v2.y,
		v3.x, v3.y,
		v4.x, v4.y};
	float s[] = {0,0,0,
		0,0,0,
		0,0,0};

	cvPt = cvMat( 4, 2, CV_32F, &t);
	dstPt = cvMat(4, 2, CV_32F, &d);
	CvMat mat = cvMat(3,3, CV_32F, &s);
	cvFindHomography(&dstPt, &cvPt, &mat);

	ret._11 = mat.data.fl[0*3 + 0];
	ret._21 = mat.data.fl[0*3 + 1];
	ret._31 = mat.data.fl[0*3 + 2];

	ret._12 = mat.data.fl[1*3 + 0];
	ret._22 = mat.data.fl[1*3 + 1];
	ret._32 = mat.data.fl[1*3 + 2];

	ret._13 = mat.data.fl[2*3 + 0];
	ret._23 = mat.data.fl[2*3 + 1];
	ret._33 = mat.data.fl[2*3 + 2];
	return ret;
}
HRESULT GSHomoWarpFilter::SetWarpVertex(float LTx, float LTy, float LBx, float LBy, 
									  float RBx, float RBy, float RTx, float RTy)
{
	D3DXVECTOR2 v1(LTx, LTy);
	D3DXVECTOR2 v2(LBx, LBy);
	D3DXVECTOR2 v3(RTx, RTy);
	D3DXVECTOR2 v4(RBx, RBy);
	CAutoLock autolock(&m_csRenderPara);
	m_matTTS = ComputeTTS(v1, v2, v3, v4);
	D3DXMatrixInverse(&m_InvmatTTS, NULL, &m_matTTS);
	return S_OK;
}
HRESULT GSHomoWarpFilter::GetWarpVertex(float& LTx, float& LTy, float& LBx, float& LBy, 
									  float& RBx, float& RBy, float& RTx, float& RTy)
{
	D3DXVECTOR4 v1(0,0,1,1);
	D3DXVECTOR4 v2(0,1,1,1);
	D3DXVECTOR4 v3(1,0,1,1);
	D3DXVECTOR4 v4(1,1,1,1);
	D3DXMATRIX matInvTTS;
	{
		CAutoLock lck(&m_csRenderPara);
		D3DXMatrixInverse(&matInvTTS, NULL, &m_matTTS);
	}
	D3DXVec4Transform(&v1, &v1, &matInvTTS);
	D3DXVec4Transform(&v2, &v2, &matInvTTS);
	D3DXVec4Transform(&v3, &v3, &matInvTTS);
	D3DXVec4Transform(&v4, &v4, &matInvTTS);
	v1 /= v1.z; v2 /= v2.z; v3 /= v3.z; v4 /= v4.z;

	LTx = v1.x; LTy = v1.y;
	LBx = v2.x; LBy = v2.y;
	RBx = v4.x; RBy = v4.y;
	RTx = v3.x; RTy = v3.y;
	return S_OK;
}

HRESULT GSHomoWarpFilter::SetWarpMatrix(const D3DXMATRIX& mat)
{
	CAutoLock lck(&m_csRenderPara);
	m_matTTS = mat;
	D3DXMatrixInverse(&m_InvmatTTS, NULL, &m_matTTS);
	return S_OK;
}
HRESULT GSHomoWarpFilter::GetWarpMatrix(D3DXMATRIX& mat)
{
	CAutoLock lck(&m_csRenderPara);
	mat = m_matTTS;
	D3DXMatrixInverse(&m_InvmatTTS, NULL, &m_matTTS);
	return S_OK;
}

bool GSHomoWarpFilter::GetIsInvWarp()
{
	CAutoLock lck(&m_csRenderPara);
	return m_bInvTTS;
}
bool GSHomoWarpFilter::SetIsInvWarp(bool bInv)
{
	CAutoLock lck(&m_csRenderPara);
	m_bInvTTS = bInv;
	return true;
}

bool GSHomoWarpFilter::GetIsFlipY()
{
	CAutoLock lck(&m_csRenderPara);
	return m_bFlipY;
}
bool GSHomoWarpFilter::SetIsFlipY(bool bFlipY)
{
	CAutoLock lck(&m_csRenderPara);
	m_bFlipY = bFlipY;
	return true;
}