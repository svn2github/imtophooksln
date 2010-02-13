#pragma once
#include "cmuxtransformfilter.h"

class CBoardCastOutputPin : public CMuxTransformOutputPin
{
	friend class CMuxTransformFilter;
public:
	CBoardCastOutputPin(
		__in_opt LPCTSTR pObjectName,
		__inout CMuxTransformFilter *pTransformFilter,
		__inout HRESULT * phr,
		__in_opt LPCWSTR pName);
#ifdef UNICODE
	CBoardCastOutputPin(
		__in_opt LPCSTR pObjectName,
		__inout CMuxTransformFilter *pTransformFilter,
		__inout HRESULT * phr,
		__in_opt LPCWSTR pName);
#endif
	virtual ~CBoardCastOutputPin();
	virtual HRESULT CheckConnect(IPin *pPin);
	virtual HRESULT CheckMediaType(const CMediaType* mtOut);
	virtual HRESULT GetMediaType(int iPosition, __inout CMediaType *pMediaType);
	virtual HRESULT CompleteConnect(IPin *pReceivePin);
};