
#include "StdAfx.h"
#include "ARTagDSFilter.h"
#include <initguid.h>
#include "wxdebug.h"


//For DLL Register
static WCHAR g_wszName[] = L"ARTagFilter";
const AMOVIESETUP_PIN psudARTagFilterPins[] =
{ { L"Input"            // strName
, FALSE               // bRendered
, FALSE               // bOutput
, FALSE               // bZero
, FALSE               // bMany
, &CLSID_NULL         // clsConnectsToFilter
, L""                 // strConnectsToPin
, 0                   // nTypes
, NULL                // lpTypes
}
, { L"Output"           // strName
, FALSE               // bRendered
, TRUE                // bOutput
, FALSE               // bZero
, FALSE               // bMany
, &CLSID_NULL         // clsConnectsToFilter
, L""                 // strConnectsToPin
, 0                   // nTypes
, NULL                // lpTypes
}
};

const REGFILTER2 sudARTagFilter =
{ 	1,                // Version number.
MERIT_DO_NOT_USE, // Merit.
2,                // Number of pins.
 psudARTagFilterPins };         // lpPin

STDAPI DllRegisterServer(void)
{
	HRESULT hr = AMovieDllRegisterServer2(TRUE);
	if (FAILED(hr))
	{
		return hr;
	}
	IFilterMapper2 *pFM2 = NULL;
	hr = CoCreateInstance(CLSID_FilterMapper2, NULL, CLSCTX_INPROC_SERVER,
		IID_IFilterMapper2, (void **)&pFM2);
	if (SUCCEEDED(hr))
	{
		hr = pFM2->RegisterFilter(
			CLSID_ARTagDSFilter,              // Filter CLSID. 
			g_wszName,                       // Filter name.
			NULL ,                            // Device moniker. 
			&CLSID_LegacyAmFilterCategory,  // Video compressor category.
			g_wszName,                       // Instance data.
			&sudARTagFilter                   // Filter information.
			);
		pFM2->Release();
	}
	return hr;
}

STDAPI DllUnregisterServer()
{
	HRESULT hr = AMovieDllRegisterServer2(FALSE);
	if (FAILED(hr))
	{
		return hr;
	}
	IFilterMapper2 *pFM2 = NULL;
	hr = CoCreateInstance(CLSID_FilterMapper2, NULL, CLSCTX_INPROC_SERVER,
		IID_IFilterMapper2, (void **)&pFM2);
	if (SUCCEEDED(hr))
	{
		hr = pFM2->UnregisterFilter(&CLSID_VideoCompressorCategory, 
			g_wszName, CLSID_ARTagDSFilter);
		pFM2->Release();
	}
	return hr;
}




CFactoryTemplate g_Templates[] = 
{
	{ 
		g_wszName,
			&CLSID_ARTagDSFilter,
			ARTagDSFilter::CreateInstance,
			NULL,
			NULL
	}
};

int g_cTemplates = sizeof(g_Templates) / sizeof(g_Templates[0]);  


//
// DllEntryPoint
//
extern "C" BOOL WINAPI DllEntryPoint(HINSTANCE, ULONG, LPVOID);

BOOL APIENTRY DllMain(HANDLE hModule, 
					  DWORD  dwReason, 
					  LPVOID lpReserved)
{
	return DllEntryPoint((HINSTANCE)(hModule), dwReason, lpReserved);
}



ARTagDSFilter::ARTagDSFilter(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData)
: CTransformFilter(NAME("ARTag Filter"), 0, CLSID_ARTagDSFilter)
{ 
	/* Initialize any private variables here. */
	m_rgSubTypes[0] = MEDIASUBTYPE_YV12;
	m_rgSubTypes[1] = MEDIASUBTYPE_YUY2;
	m_rgSubTypes[2] = MEDIASUBTYPE_RGB24;
	m_rgSubTypes[3] = MEDIASUBTYPE_RGB32;
	m_rgSubTypes[4] = MEDIASUBTYPE_ARGB32;

	m_rgFourCC[0]   = '21VY'; // FCC("YV12");
	m_rgFourCC[1]   = '2YUY'; // FCC("YUY2");
	m_rgFourCC[2]   = BI_RGB;
	m_rgFourCC[3]   = BI_BITFIELDS;
	m_rgFourCC[4]   = BI_BITFIELDS;

	m_rgBitCnt[0]   = 12;
	m_rgBitCnt[1]   = 16;
	m_rgBitCnt[2]   = 24;
	m_rgBitCnt[3]   = 32;
	m_rgBitCnt[4]   = 32;
}
ARTagDSFilter::~ARTagDSFilter()
{

}
CUnknown *WINAPI ARTagDSFilter::CreateInstance(LPUNKNOWN punk, HRESULT *phr)
{
	ASSERT(phr);
	// assuming we don't want to modify the data
	ARTagDSFilter *pNewObject = new ARTagDSFilter(punk, phr, FALSE);

	if(pNewObject == NULL) {
		if (phr)
			*phr = E_OUTOFMEMORY;
	}

	return pNewObject;
}


HRESULT ARTagDSFilter::NonDelegatingQueryInterface(REFIID iid, void **ppv)
{
	if (iid == IID_IARTagDSFilter) 
	{
		return GetInterface(static_cast<IARTagFilter*>(this), ppv);
	}
	return CBaseFilter::NonDelegatingQueryInterface(iid,ppv);
}

HRESULT ARTagDSFilter::CheckInputType( const CMediaType * pmt )
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



HRESULT ARTagDSFilter::CheckTransform(const CMediaType *pmtIn, const CMediaType *pmtOut)
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
HRESULT ARTagDSFilter::CompleteConnect(PIN_DIRECTION direction, IPin *pReceivePin)
{
	return S_OK;
}
HRESULT ARTagDSFilter::Transform( IMediaSample *pIn, IMediaSample *pOut)
{
	HRESULT hr = S_OK;
	BYTE* pInData = NULL;
	BYTE* pOutData = NULL;
	if (pIn->GetSize() < pOut->GetSize())
	{
		return S_FALSE;
	}
	hr = pIn->GetPointer(&pInData);
	if (FAILED(hr))
		return hr;
	hr = pOut->GetPointer(&pOutData);
	if (FAILED(hr))
		return hr;
	long test = pIn->GetSize();
	memcpy(pOutData, pInData, pIn->GetSize());
	return S_OK;
}

HRESULT ARTagDSFilter::DecideBufferSize(IMemAllocator *pAlloc, ALLOCATOR_PROPERTIES *pProp)
{
	HRESULT hr = NOERROR;

	pProp->cBuffers = 1;
	pProp->cbBuffer = m_OutputMT.GetSampleSize();
	//ASSERT(pProperties->cbBuffer);

	// Ask the allocator to reserve us some sample memory, NOTE the function
	// can succeed (that is return NOERROR) but still not have allocated the
	// memory that we requested, so we must check we got whatever we wanted

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
HRESULT ARTagDSFilter::GetMediaType(int iPosition, CMediaType *pMediaType)
{
	if (iPosition < 0) {
		return E_INVALIDARG;
	}
	// Do we have more items to offer

	if (iPosition >= 1) { // WATCH OUT !!
		return VFW_S_NO_MORE_ITEMS;
	}
    
	*pMediaType = m_InputMT;
	VIDEOINFOHEADER *pvi = (VIDEOINFOHEADER *) pMediaType->pbFormat;

	BITMAPINFOHEADER bitHeader = pvi->bmiHeader;

	
	return S_OK;
}


bool ARTagDSFilter::IsAcceptedType(const CMediaType *pmt)
{
	GUID guidSubType = *pmt->Subtype();

	if (IsEqualGUID(*pmt->Type(), MEDIATYPE_Video)) {
		if(IsEqualGUID(guidSubType, MEDIASUBTYPE_YUY2)){
			return true;
		}else if(IsEqualGUID(guidSubType, MEDIASUBTYPE_RGB24)){
			return true;
		}else if(IsEqualGUID(guidSubType, MEDIASUBTYPE_RGB32) ||
			IsEqualGUID(guidSubType, MEDIASUBTYPE_ARGB32)){
				return true;
		}else if(IsEqualGUID(guidSubType, MEDIASUBTYPE_YV12)){
			return true;
		}else if(IsEqualGUID(guidSubType, MEDIASUBTYPE_Y41P)){
			return false;
		}
	}
	return false;
}
