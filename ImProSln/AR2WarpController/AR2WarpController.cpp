#include "stdafx.h"
#include "AR2WarpController.h"
#include "AR2WarpControllerProp.h"
#include "MyMediaSample.h"
AR2WarpController::AR2WarpController(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData)
: CMuxTransformFilter(NAME("AR2WarpController"), 0, CLSID_AR2WarpController)
{ 
	
}
AR2WarpController::~AR2WarpController()
{

}

CUnknown *WINAPI AR2WarpController::CreateInstance(LPUNKNOWN punk, HRESULT *phr)
{
	ASSERT(phr);
	// assuming we don't want to modify the data
	AR2WarpController *pNewObject = new AR2WarpController(punk, phr, FALSE);

	if(pNewObject == NULL) {
		if (phr)
			*phr = E_OUTOFMEMORY;
	}
	return pNewObject;
}


HRESULT AR2WarpController::NonDelegatingQueryInterface(REFIID iid, void **ppv)
{
	if (iid == IID_IAR2WarpController) 
	{
		return GetInterface(static_cast<IAR2WarpController*>(this), ppv);
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

HRESULT AR2WarpController::Receive(IMediaSample *pSample, const IPin* pReceivePin)
{
	return S_OK;
}
HRESULT AR2WarpController::CreatePins()
{
	HRESULT hr = S_OK;
	if (m_pInputPins.size() < 1 || m_pOutputPins.size() < 1) {
		for (int c = 0; c< m_pInputPins.size(); c++)
		{
			delete m_pInputPins[c];
			m_pInputPins[c] = NULL;
		}
		m_pInputPins.clear();
		for (int c = 0; c< m_pOutputPins.size(); c++)
		{
			delete m_pOutputPins[c];
			m_pOutputPins[c] = NULL;
		}
		m_pOutputPins.clear();

		CMuxTransformInputPin* pInput = new CMuxTransformInputPin(NAME("CMuxTransform input pin"),
			this,              // Owner filter
			&hr,               // Result code
			L"AR result");      // Pin name
		//  Can't fail
		
		CMuxTransformOutputPin* pOutput = new CMuxTransformOutputPin(NAME("Transform output pin"),
			this,            // Owner filter
			&hr,             // Result code
			L"Warp config");   // Pin name
		// Can't fail

		m_pInputPins.push_back(pInput);
		m_pOutputPins.push_back(pOutput);
	}
	return S_OK;
}
HRESULT AR2WarpController::CheckInputType(const CMediaType* mtIn, const IPin* pPin)
{
	if (m_pInputPins.size() >= 1 && m_pInputPins[0] == pPin)
	{
		if (!IsEqualGUID(*mtIn->Type(), GUID_MyMediaSample) || !IsEqualGUID(*mtIn->Subtype(), GUID_ARResult))
		{
			return E_INVALIDARG;
		}
		return S_OK;
	}
	return E_FAIL;
}
HRESULT AR2WarpController::CheckOutputType(const CMediaType* mtOut, const IPin* pPin)
{
	if (m_pOutputPins.size() >= 1 && m_pOutputPins[0] == pPin)
	{
		if (!IsEqualGUID(*mtOut->Type(), GUID_MyMediaSample) || !IsEqualGUID(*mtOut->Subtype(), GUID_WarpConfig))
		{
			return E_INVALIDARG;
		}
		return S_OK;
	}
	return S_OK;
}
HRESULT AR2WarpController::DecideBufferSize(IMemAllocator * pAlloc, const IPin* pOutPin,
								 __inout ALLOCATOR_PROPERTIES *pProp)
{
	HRESULT hr;
	if (m_pOutputPins.size() >= 1 && m_pOutputPins[0] == pOutPin)
	{
		pProp->cBuffers = 1;
		pProp->cbBuffer = sizeof(ARTagResultData);

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
	}
	
	return S_OK;
}
HRESULT AR2WarpController::GetMediaType(int iPosition, const IPin* pOutPin, __inout CMediaType *pMediaType)
{
	if (iPosition < 0) {
		return E_INVALIDARG;
	}
	if (iPosition >= 1) { // WATCH OUT !!
		return VFW_S_NO_MORE_ITEMS;
	}

	if (m_pOutputPins.size() > 0 && m_pOutputPins[0] == pOutPin)
	{
		CMediaType myMediaType;
		myMediaType.SetType(&GUID_MyMediaSample);
		myMediaType.SetSubtype(&GUID_WarpConfig);
		myMediaType.SetSampleSize(sizeof(WarpConfigData));
		*pMediaType = myMediaType;
		
		return S_OK;
	}
	return VFW_S_NO_MORE_ITEMS;
}
HRESULT AR2WarpController::CompleteConnect(PIN_DIRECTION direction, const IPin* pMyPin, const IPin* pOtherPin)
{
	return S_OK;
}

HRESULT AR2WarpController::GetPages(CAUUID *pPages)
{
	pPages->cElems = 1;
	pPages->pElems = (GUID*)CoTaskMemAlloc(sizeof(GUID));
	if (pPages->pElems == NULL) 
	{
		return E_OUTOFMEMORY;
	}
	pPages->pElems[0] = CLSID_AR2WarpControllerPropertyPage;
	return S_OK;
	
}