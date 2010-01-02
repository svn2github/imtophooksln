#include "stdafx.h"
#include "HomoWarpFilter.h"
#include "HomoWarpFilterProp.h"
#include "HomoWarpFilterApp.h"
#include "cv.h"
HomoWarpFilter::HomoWarpFilter(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData)
: CTransformFilter(NAME("HomoWarp Filter"), 0, CLSID_HomoWarpFilter)
{ 
	D3DXMatrixIdentity(&m_matTTS);
}
HomoWarpFilter::~HomoWarpFilter()
{

}

CUnknown *WINAPI HomoWarpFilter::CreateInstance(LPUNKNOWN punk, HRESULT *phr)
{
	ASSERT(phr);
	// assuming we don't want to modify the data
	HomoWarpFilter *pNewObject = new HomoWarpFilter(punk, phr, FALSE);

	if(pNewObject == NULL) {
		if (phr)
			*phr = E_OUTOFMEMORY;
	}
	return pNewObject;
}

HRESULT HomoWarpFilter::NonDelegatingQueryInterface(REFIID iid, void **ppv)
{
	if (iid == IID_IHomoWarpFilter) 
	{
		return GetInterface(static_cast<IHomoWarpFilter*>(this), ppv);
	}
	if (iid == IID_ISpecifyPropertyPages)
	{
		return GetInterface(
			static_cast<ISpecifyPropertyPages*>(this),	ppv);
	}
	else
	{
		// Call the parent class.
		return CBaseFilter::NonDelegatingQueryInterface(iid, ppv);
	}
}

HRESULT HomoWarpFilter::CheckInputType( const CMediaType * pmt )
{
	CheckPointer(pmt, E_POINTER);
	if (*pmt->FormatType() != FORMAT_VideoInfo) {
		return E_INVALIDARG;
	}

	// Can we transform this type
	if(IsAcceptedType(pmt)){
		m_InputMT = *pmt;
		return NOERROR;
	}
	return E_FAIL;
}
HRESULT HomoWarpFilter::CheckTransform(const CMediaType *pmtIn, const CMediaType *pmtOut)
{
	if(!IsAcceptedType(pmtIn))
		return E_FAIL;

	if(!IsAcceptedType(pmtOut))
		return E_FAIL;

	VIDEOINFOHEADER *pviIn = (VIDEOINFOHEADER *) pmtIn->pbFormat;
	VIDEOINFOHEADER *pviOut = (VIDEOINFOHEADER *) pmtOut->pbFormat;
	BITMAPINFOHEADER bitHeaderIn = pviIn->bmiHeader;
	BITMAPINFOHEADER bitHeaderOut = pviOut->bmiHeader;

	ASSERT(pmtIn->formattype == FORMAT_VideoInfo);
	BITMAPINFOHEADER *pBmiOut = HEADER(pmtOut->pbFormat);
	BITMAPINFOHEADER *pBmiIn = HEADER(pmtIn->pbFormat);
	if ((pBmiOut->biPlanes != 1) ||
		(pBmiOut->biWidth != pBmiIn->biWidth) ||
		(pBmiOut->biHeight != pBmiIn->biHeight) ||
		(pBmiOut->biBitCount != pBmiIn->biBitCount))
	{
		return VFW_E_TYPE_NOT_ACCEPTED;
	}
	m_InputMT  = *pmtIn;
	m_OutputMT = *pmtOut;
	return NOERROR;
}
HRESULT HomoWarpFilter::CompleteConnect(PIN_DIRECTION direction, IPin *pReceivePin)
{
	HRESULT hr = S_OK;
	if (direction == PINDIR_INPUT)
	{
		if (m_pInTexture != NULL)
		{
			m_pInTexture->Release();
			m_pInTexture = NULL;
		}
		if (m_pOutTexture != NULL)
		{
			m_pOutTexture->Release();
			m_pOutTexture = NULL;
		}
		VIDEOINFOHEADER *pvi = (VIDEOINFOHEADER *) m_InputMT.pbFormat;
		BITMAPINFOHEADER bitHeader = pvi->bmiHeader;
		initD3D(bitHeader.biWidth, bitHeader.biHeight);
	
	}
	return S_OK;
}
HRESULT HomoWarpFilter::Transform( IMediaSample *pIn, IMediaSample *pOut)
{
	HRESULT hr = S_OK;
	if (m_pD3DDisplay != NULL)
	{
		((HomoD3DDisplay*)m_pD3DDisplay)->SetMatTTS(&m_matTTS);
		DoTransform(pIn, pOut, &m_InputMT);
	}
	return S_OK;
}


HRESULT HomoWarpFilter::DecideBufferSize(IMemAllocator *pAlloc, ALLOCATOR_PROPERTIES *pProp)
{
	HRESULT hr = NOERROR;

	pProp->cBuffers = 1;
	pProp->cbBuffer = m_OutputMT.GetSampleSize();


	ALLOCATOR_PROPERTIES Actual;
	hr = pAlloc->SetProperties(pProp,&Actual);
	if (FAILED(hr)) {
		return hr;
	}
	ASSERT( Actual.cBuffers == 1 );
	if (pProp->cBuffers > Actual.cBuffers ||
		pProp->cbBuffer > Actual.cbBuffer) {
			return E_FAIL;
	}
	return NOERROR;
}


HRESULT HomoWarpFilter::GetMediaType(int iPosition, CMediaType *pMediaType)
{
	if (iPosition < 0) {
		return E_INVALIDARG;
	}
	if (iPosition >= 1) { // WATCH OUT !!
		return VFW_S_NO_MORE_ITEMS;
	}
	*pMediaType = m_InputMT;

	return S_OK;
}


bool HomoWarpFilter::IsAcceptedType(const CMediaType *pmt)
{
	GUID guidSubType = *pmt->Subtype();

	if (IsEqualGUID(*pmt->Type(), MEDIATYPE_Video)) 
	{
		if(IsEqualGUID(guidSubType, MEDIASUBTYPE_RGB24))
		{
			return true;
		}
		else if(IsEqualGUID(guidSubType, MEDIASUBTYPE_RGB32) ||
			IsEqualGUID(guidSubType, MEDIASUBTYPE_ARGB32))
		{
			return true;
		}
	}
	return false;
}

HRESULT HomoWarpFilter::GetPages(CAUUID *pPages)
{
	pPages->cElems = 1;
	pPages->pElems = (GUID*)CoTaskMemAlloc(sizeof(GUID));
	if (pPages->pElems == NULL) 
	{
		return E_OUTOFMEMORY;
	}
	pPages->pElems[0] = CLSID_HomoWarpFilterPropertyPage;
	return S_OK;
}

MS3DDisplay* HomoWarpFilter::Create3DDisplay(HWND hWndD3D,IDirect3D9* pD3D, int rtWidth, int rtHeight)
{
	return new HomoD3DDisplay(hWndD3D, pD3D, rtWidth, rtHeight);
}

D3DXMATRIX HomoWarpFilter::ComputeTTS(const D3DXVECTOR2& v1, const D3DXVECTOR2& v2, const D3DXVECTOR2& v3, const D3DXVECTOR2& v4)
{
	WCHAR str[MAX_PATH];
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
HRESULT HomoWarpFilter::SetWarpVertex(float LTx, float LTy, float LBx, float LBy, 
							  float RBx, float RBy, float RTx, float RTy)
{
	D3DXVECTOR2 v1(LTx, LTy);
	D3DXVECTOR2 v2(LBx, LBy);
	D3DXVECTOR2 v3(RTx, RTy);
	D3DXVECTOR2 v4(RBx, RBy);
	m_matTTS = ComputeTTS(v1, v2, v3, v4);
	return S_OK;
}
HRESULT HomoWarpFilter::GetWarpVertex(float& LTx, float& LTy, float& LBx, float& LBy, 
							  float& RBx, float& RBy, float& RTx, float& RTy)
{
	D3DXVECTOR2 v1(0,0);
	D3DXVECTOR2 v2(0,1);
	D3DXVECTOR2 v3(1,0);
	D3DXVECTOR2 v4(1,1);
	D3DXVec2TransformCoord(&v1, &v1, &m_matTTS);
	D3DXVec2TransformCoord(&v2, &v2, &m_matTTS);
	D3DXVec2TransformCoord(&v3, &v3, &m_matTTS);
	D3DXVec2TransformCoord(&v4, &v4, &m_matTTS);

	LTx = v1.x; LTy = v1.y;
	LBx = v2.x; LBy = v2.y;
	RBx = v4.x; RBy = v4.y;
	RTx = v3.x; RTy = v3.y;
	return S_OK;
}