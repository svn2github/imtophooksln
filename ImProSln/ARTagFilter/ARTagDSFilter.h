#ifndef _ARTAGDSFILTER_H
#define  _ARTAGDSFILTER_H

#include "dshow.h"
#include "Streams.h"
#include <initguid.h>
#include "combase.h"
DEFINE_GUID(CLSID_ARTagDSFilter, 
			0x889c4fa1, 0xfb51, 0x4118, 0x80, 0xb8, 0xc0, 0x3f, 0x51, 0x4a, 0xab, 0x3);

DEFINE_GUID(IID_IARTagDSFilter, 
			0xe47942df, 0xb438, 0x4d85, 0xa9, 0xec, 0x7b, 0x56, 0x55, 0xe6, 0x8d, 0xfd);

MIDL_INTERFACE("E47942DF-B438-4d85-A9EC-7B5655E68DFD")
IARTagFilter: public IUnknown
{
public:

};


class ARTagDSFilter :
	public CTransformFilter, public IARTagFilter
	
{
public:
	static CUnknown *WINAPI CreateInstance(LPUNKNOWN punk, HRESULT *phr);

	//for COM interface 
	
	STDMETHODIMP NonDelegatingQueryInterface(REFIID iid, void **ppv);
	DECLARE_IUNKNOWN;

	//implement DShow Interface
	HRESULT          CheckInputType( const CMediaType * pmt );
	HRESULT          CheckTransform(const CMediaType *pmtIn, const CMediaType *pmtOut);
	HRESULT          CompleteConnect(PIN_DIRECTION direction, IPin *pReceivePin);
	HRESULT          Transform( IMediaSample *pIn, IMediaSample *pOut);
	HRESULT          DecideBufferSize(IMemAllocator *pAllocator, ALLOCATOR_PROPERTIES *pProp);
	HRESULT          GetMediaType(int iPosition, CMediaType *pMediaType);

protected:
	CMediaType       m_InputMT;
	CMediaType       m_OutputMT;
	
	GUID             m_rgSubTypes[6];
	DWORD            m_rgFourCC[6];
	WORD             m_rgBitCnt[6];

	bool             IsAcceptedType(const CMediaType *pMT);



public:
	ARTagDSFilter(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData);
	virtual ~ARTagDSFilter();
};
#endif