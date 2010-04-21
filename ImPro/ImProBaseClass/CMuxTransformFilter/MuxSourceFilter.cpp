#include "StdAfx.h"
#include "MuxSourceFilter.h"

CMuxSourceFilter::CMuxSourceFilter(__in_opt LPCTSTR pName, __inout_opt LPUNKNOWN lpunk, CLSID clsid, __inout HRESULT *phr) :
CSource(pName, lpunk, clsid, phr)
{

}
CMuxSourceFilter::CMuxSourceFilter(__in_opt LPCTSTR pName, __inout_opt LPUNKNOWN lpunk, CLSID clsid) :
CSource(pName, lpunk, clsid)
{

}
#ifdef UNICODE
CMuxSourceFilter::CMuxSourceFilter(__in_opt LPCSTR pName, __inout_opt LPUNKNOWN lpunk, CLSID clsid, __inout HRESULT *phr) :
CSource(pName, lpunk, clsid, phr)
{

}
CMuxSourceFilter::CMuxSourceFilter(__in_opt LPCSTR pName, __inout_opt LPUNKNOWN lpunk, CLSID clsid) :
CSource(pName, lpunk, clsid)
{

}
#endif

CMuxSourceFilter::~CMuxSourceFilter(void)
{
}



CMuxSourceOutputPin::CMuxSourceOutputPin(LPCSTR pObjectName,
										 HRESULT *phr, CMuxSourceFilter *pms, LPCWSTR pName) : 
CSourceStream(pObjectName, phr, pms, pName)
{

}
CMuxSourceOutputPin::~CMuxSourceOutputPin()
{

}
HRESULT CMuxSourceOutputPin::FillBuffer(IMediaSample *pSamp)
{
	if (m_pFilter == NULL)
	{
		return S_FALSE;
	}
	return ((CMuxSourceFilter*)m_pFilter)->FillBuffer(pSamp, this);
}

HRESULT CMuxSourceOutputPin::OnThreadCreate(void)
{
	if (m_pFilter == NULL)
	{
		return S_FALSE;
	}
	return ((CMuxSourceFilter*)m_pFilter)->OnThreadCreate(this);
}
HRESULT CMuxSourceOutputPin::OnThreadDestroy(void)
{
	if (m_pFilter == NULL)
	{
		return S_FALSE;
	}
	return ((CMuxSourceFilter*)m_pFilter)->OnThreadDestroy(this);
}
HRESULT CMuxSourceOutputPin::OnThreadStartPlay(void)
{
	if (m_pFilter == NULL)
	{
		return S_FALSE;
	}
	return ((CMuxSourceFilter*)m_pFilter)->OnThreadStartPlay(this);
}

HRESULT CMuxSourceOutputPin::GetMediaType(int iPosition, CMediaType *pMediaType)
{
	if (m_pFilter == NULL)
	{
		return S_FALSE;
	}
	return ((CMuxSourceFilter*)m_pFilter)->GetMediaType(iPosition, pMediaType, this);
}