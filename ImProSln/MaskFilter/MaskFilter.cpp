#include "stdafx.h"
#include "MaskFilter.h"
#include "MaskFilterProp.h"
#include "MaskFilterApp.h"
#include "cv.h"
#include "MyMediaSample.h"
#include "MyARTagMediaSample.h"
MaskFilter::MaskFilter(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData)
: CMuxTransformFilter(NAME("Mask Filter"), 0, CLSID_MaskFilter)
{ 
	
}
MaskFilter::~MaskFilter()
{

}

CUnknown *WINAPI MaskFilter::CreateInstance(LPUNKNOWN punk, HRESULT *phr)
{
	ASSERT(phr);
	// assuming we don't want to modify the data
	MaskFilter *pNewObject = new MaskFilter(punk, phr, FALSE);

	if(pNewObject == NULL) {
		if (phr)
			*phr = E_OUTOFMEMORY;
	}
	return pNewObject;
}

HRESULT MaskFilter::NonDelegatingQueryInterface(REFIID iid, void **ppv)
{
	if (iid == IID_IMaskFilter) 
	{
		return GetInterface(static_cast<IMaskFilter*>(this), ppv);
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

HRESULT MaskFilter::ReceiveInput0(IMediaSample *pSample, const IPin* pReceivePin)
{
	if (m_pOutputPins.size() < 1)
	{
		return S_FALSE;
	}

	AM_SAMPLE2_PROPERTIES * const pProps = ((CMuxTransformInputPin*)pReceivePin)->SampleProps();
	if (pProps->dwStreamId != AM_STREAM_MEDIA) {
		return S_OK;
	}
	ASSERT(pSample);
	IMediaSample * pOutSample;
	// If no output to deliver to then no point sending us data
	ASSERT (m_pOutputPins.size() != NULL);
	HRESULT hr;
	// Set up the output sample

	hr = InitializeOutputSample(pSample, pReceivePin, m_pOutputPins[0], &pOutSample);

	if (FAILED(hr)) {
		return hr;
	}

	// Start timing the transform (if PERF is defined)
	MSR_START(m_idTransform);

	hr = Transform(pSample, pOutSample);

	// Stop the clock and log it (if PERF is defined)
	MSR_STOP(m_idTransform);

	if (FAILED(hr)) {
		DbgLog((LOG_TRACE,1,TEXT("Error from transform")));
	} else {
		// the Transform() function can return S_FALSE to indicate that the
		// sample should not be delivered; we only deliver the sample if it's
		// really S_OK (same as NOERROR, of course.)
		if (hr == NOERROR) {
			hr = m_pOutputPins[0]->Deliver(pOutSample);// m_pInputPin->Receive(pOutSample);
			m_bSampleSkipped = FALSE;	// last thing no longer dropped
		} else {
			// S_FALSE returned from Transform is a PRIVATE agreement
			// We should return NOERROR from Receive() in this cause because returning S_FALSE
			// from Receive() means that this is the end of the stream and no more data should
			// be sent.
			if (S_FALSE == hr) {

				//  Release the sample before calling notify to avoid
				//  deadlocks if the sample holds a lock on the system
				//  such as DirectDraw buffers do
				pOutSample->Release();
				m_bSampleSkipped = TRUE;
				if (!m_bQualityChanged) {
					NotifyEvent(EC_QUALITY_CHANGE,0,0);
					m_bQualityChanged = TRUE;
				}
				return NOERROR;
			}
		}
	}

	// release the output buffer. If the connected pin still needs it,
	// it will have addrefed it itself.
	pOutSample->Release();
	return S_OK;
}

HRESULT MaskFilter::ReceiveInput1(IMediaSample *pSample, const IPin* pReceivePin)
{

	return S_OK;
}



HRESULT MaskFilter::Receive(IMediaSample *pSample, const IPin* pReceivePin)
{
	HRESULT hr;
	if (m_pInputPins.size() >= 1 && pReceivePin == m_pInputPins[0])
	{
		return ReceiveInput0(pSample, pReceivePin);
	}
	if (m_pInputPins.size() >= 2 && pReceivePin == m_pInputPins[1])
	{
		return ReceiveInput1(pSample, pReceivePin);
	}
	return S_OK;


}
HRESULT MaskFilter::CreatePins()
{
	HRESULT hr = S_OK;
	if (m_pInputPins.size() < 2 || m_pOutputPins.size() < 1) {
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

		CMuxTransformInputPin* pInput0 = new CMuxTransformInputPin(NAME("CMuxTransform input pin"),
			this,              // Owner filter
			&hr,               // Result code
			L"input");      // Pin name
		//  Can't fail
		ASSERT(SUCCEEDED(hr));
		if (pInput0 == NULL) {
			return NULL;
		}

		CMuxTransformInputPin* pInput1 = new CMuxTransformInputPin(NAME("CMuxTransform input pin"),
			this,              // Owner filter
			&hr,               // Result code
			L"AR conf");      // Pin name
		//  Can't fail
		ASSERT(SUCCEEDED(hr));
		if (pInput1 == NULL) {
			delete pInput0;
			pInput0 = NULL;
			return NULL;
		}

		CMuxTransformOutputPin* pOutput = new CMuxTransformOutputPin(NAME("Transform output pin"),
			this,            // Owner filter
			&hr,             // Result code
			L"output");   // Pin name
		// Can't fail
		ASSERT(SUCCEEDED(hr));
		if (pOutput == NULL) {
			delete pInput0;
			pInput0 = NULL;
			delete pInput1;
			pInput1 = NULL;
			return NULL;
			}

		
		m_pInputPins.push_back(pInput0);
		m_pInputPins.push_back(pInput1);
		m_pOutputPins.push_back(pOutput);
	}
	return S_OK;
}

HRESULT MaskFilter::CheckInputType( const CMediaType * pmt , const IPin* pPin)
{
	CheckPointer(pmt, E_POINTER);
	if (m_pInputPins.size() >= 1 && m_pInputPins[0] == pPin)
	{	
		CheckPointer(pmt, E_POINTER);
		if (!IsEqualGUID(*pmt->FormatType(), FORMAT_VideoInfo) && 
			!IsEqualGUID(*pmt->FormatType(), GUID_FORMATTYPE_D3DXTEXTURE9DESC)) 
		{
			return E_INVALIDARG;
		}
		// Can we transform this type
		if(IsAcceptedType(pmt)){
			return NOERROR;
		}
	}
	else if (m_pInputPins.size() >= 2 && m_pInputPins[1] == pPin)
	{
		if ( !IsEqualGUID(*pmt->Type(), GUID_MyMediaSample) || ! IsEqualGUID(*pmt->Subtype(), GUID_ARLayoutData))
		{
			return E_INVALIDARG;
		}
		return NOERROR;
	}
	return E_FAIL;
}

HRESULT MaskFilter::CheckOutputType( const CMediaType * pmt , const IPin* pPin)
{
	if (m_pOutputPins.size() > 0 && m_pOutputPins[0] == pPin)
	{
		CheckPointer(pmt, E_POINTER);
		if (*pmt->FormatType() != FORMAT_VideoInfo) {
			return E_INVALIDARG;
		}

		// Can we transform this type
		if(IsAcceptedType(pmt)){
			return NOERROR;
		}
	}

	return E_FAIL;
}

HRESULT MaskFilter::CompleteConnect(PIN_DIRECTION direction, const IPin* pMyPin, const IPin* pOtherPin)
{
	HRESULT hr = S_OK;
	if (direction == PINDIR_INPUT && m_pInputPins.size() > 0 && m_pInputPins[0] == pMyPin)
	{
		CMediaType inputMT = ((CMuxTransformInputPin*)pMyPin)->CurrentMediaType();
		if (IsEqualGUID(*inputMT.Type(), GUID_MyMediaSample) && 
			IsEqualGUID(*inputMT.Subtype(), GUID_D3DXTEXTURE9_POINTER))
		{
			D3DSURFACE_DESC* desc = (D3DSURFACE_DESC*)inputMT.pbFormat;
			initD3D(desc->Width, desc->Height);
		}
		else
		{
			VIDEOINFOHEADER *pvi = (VIDEOINFOHEADER *) inputMT.pbFormat;
			BITMAPINFOHEADER bitHeader = pvi->bmiHeader;
			initD3D(bitHeader.biWidth, bitHeader.biHeight);
		}
	}
	return hr;
}

HRESULT MaskFilter::BreakConnect(PIN_DIRECTION dir, const IPin* pPin)
{
	if (dir == PINDIR_OUTPUT)
	{
		for (int i =0; i< m_pOutputPins.size(); i++)
		{
			m_pOutputPins[i]->m_bVisible = true;
		}
	}
	return __super::BreakConnect(dir, pPin);
}
HRESULT MaskFilter::Transform( IMediaSample *pIn, IMediaSample *pOut)
{
	HRESULT hr = S_OK;
	if (m_pD3DDisplay != NULL)
	{
		if (m_pInputPins.size() <= 0 || m_pOutputPins.size() <= 0)
		{
			return S_FALSE;
		}
		DoTransform(pIn, pOut, &m_pInputPins[0]->CurrentMediaType(), &m_pOutputPins[0]->CurrentMediaType(), false);
	}
	return S_OK;
}


HRESULT MaskFilter::DecideBufferSize(IMemAllocator *pAlloc, const IPin* pOutPin, ALLOCATOR_PROPERTIES *pProp)
{
	HRESULT hr = NOERROR;
	if (m_pInputPins.size() <= 0)
	{
		return S_FALSE;
	}
	
	if (m_pOutputPins.size() > 0 && m_pOutputPins[0] == pOutPin )
	{
		CMediaType mt = m_pOutputPins[0]->CurrentMediaType();

		pProp->cBuffers = 1;
		pProp->cbBuffer = mt.GetSampleSize();
		if (pProp->cbAlign == 0)
		{
			pProp->cbAlign = 1;
		}

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

	
	return NOERROR;
}


HRESULT MaskFilter::GetMediaType(int iPosition, const IPin* pOutPin, __inout CMediaType *pMediaType)
{
	if (iPosition < 0) {
		return E_INVALIDARG;
	}
	if (iPosition >= 1) { // WATCH OUT !!
		return VFW_S_NO_MORE_ITEMS;
	}
	if (m_pInputPins.size() <= 0)
	{
		return VFW_S_NO_MORE_ITEMS;
	}
	if (m_pOutputPins.size() > 0 && m_pOutputPins[0] == pOutPin)
	{
		CMediaType inputMT = m_pInputPins[0]->CurrentMediaType();
		*pMediaType = inputMT;
		return S_OK;
	}

	return VFW_S_NO_MORE_ITEMS;
}


bool MaskFilter::IsAcceptedType(const CMediaType *pmt)
{
	GUID guidSubType = *pmt->Subtype();

	if (IsEqualGUID(*pmt->Type(), MEDIATYPE_Video)) 
	{
		VIDEOINFOHEADER* pvi = (VIDEOINFOHEADER*)pmt->Format();
		BITMAPINFOHEADER bitHeader = pvi->bmiHeader;
		if (bitHeader.biCompression)
		{
			return false;
		}

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
	else if (IsEqualGUID(*pmt->Type(), GUID_MyMediaSample) && 
		IsEqualGUID(guidSubType, GUID_D3DXTEXTURE9_POINTER))
	{
		return true;
	}
	return false;
}

HRESULT MaskFilter::GetPages(CAUUID *pPages)
{
	pPages->cElems = 1;
	pPages->pElems = (GUID*)CoTaskMemAlloc(sizeof(GUID));
	if (pPages->pElems == NULL) 
	{
		return E_OUTOFMEMORY;
	}
	pPages->pElems[0] = CLSID_MaskFilterProp;
	return S_OK;
}

MS3DDisplay* MaskFilter::Create3DDisplay(IDirect3D9* pD3D, int rtWidth, int rtHeight)
{
	return new MaskFilterDisplay(pD3D, rtWidth, rtHeight);
}

MS3DDisplay* MaskFilter::Create3DDisplay(IDirect3DDevice9* pDevice, int rtWidth, int rtHeight)
{
	return new MaskFilterDisplay(pDevice, rtWidth, rtHeight);
}

