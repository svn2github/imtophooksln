#include "StdAfx.h"
#include "BoardCastOutputPin.h"

CBoardCastOutputPin::CBoardCastOutputPin(
	__in_opt LPCTSTR pObjectName,
	__inout CMuxTransformFilter *pTransformFilter,
	__inout HRESULT * phr,
	__in_opt LPCWSTR pPinName)
	: CMuxTransformOutputPin(pObjectName, pTransformFilter, phr, pPinName)
{

}

#ifdef UNICODE
CBoardCastOutputPin::CBoardCastOutputPin(
	__in_opt LPCSTR pObjectName,
	__inout CMuxTransformFilter *pTransformFilter,
	__inout HRESULT * phr,
	__in_opt LPCWSTR pPinName)
	: CMuxTransformOutputPin(pObjectName, pTransformFilter, phr, pPinName)
{
}
#endif

// destructor

CBoardCastOutputPin::~CBoardCastOutputPin()
{

}


HRESULT
CBoardCastOutputPin::CheckConnect(IPin *pPin)
{
	HRESULT hr = m_pTransformFilter->CheckConnect(PINDIR_OUTPUT,this, pPin);
	if (FAILED(hr)) {
		return hr;
	}
	return CBaseOutputPin::CheckConnect(pPin);
}



// check a given transform - must have selected input type first

HRESULT
CBoardCastOutputPin::CheckMediaType(const CMediaType* pmtOut)
{
	// must have selected input first
	return m_pTransformFilter->CheckOutputType(pmtOut, this);
}

// return a specific media type indexed by iPosition

HRESULT
CBoardCastOutputPin::GetMediaType(
									 int iPosition,
									 __inout CMediaType *pMediaType)
{	
	return m_pTransformFilter->GetMediaType(iPosition,this, pMediaType);
}

HRESULT
CBoardCastOutputPin::CompleteConnect(IPin *pReceivePin)
{
	HRESULT hr = m_pTransformFilter->CompleteConnect(PINDIR_OUTPUT, this, pReceivePin);
	if (FAILED(hr)) {
		return hr;
	}
	//for (int i=0; i< m_pOu
	return DecideAllocator(m_pInputPin, &m_pAllocator);
}