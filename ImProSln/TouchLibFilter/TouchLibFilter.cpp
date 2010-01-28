#include "stdafx.h"
#include "TouchLibFilter.h"

#include "stdafx.h"
#include "TouchLibFilter.h"
#include "TouchLibFilterProp.h"
#include "TouchLibFilterApp.h"
#include "cv.h"
#include "MyMediaSample.h"
#include "d3dx9.h"
#include "highgui.h"
TouchLibFilter::TouchLibFilter(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData)
: CMuxTransformFilter(NAME("TouchLib Filter"), 0, CLSID_TouchLibFilter)
{ 
	/*
	m_blurLevel = 13;
	m_noiseLevel = 3;
	m_noiseSmoothType = 3;
	m_levelScale = 70;
	m_levelRectify = 75;
	m_bAutoSet = false;
	m_buffer = NULL;*/
	m_pTouchScreen = NULL;
}
TouchLibFilter::~TouchLibFilter()
{
	/*if (m_buffer != NULL)
	{
		cvReleaseImage(&m_buffer);
		m_buffer = NULL;
	}*/
}

CUnknown *WINAPI TouchLibFilter::CreateInstance(LPUNKNOWN punk, HRESULT *phr)
{
	ASSERT(phr);
	// assuming we don't want to modify the data
	TouchLibFilter *pNewObject = new TouchLibFilter(punk, phr, FALSE);

	if(pNewObject == NULL) {
		if (phr)
			*phr = E_OUTOFMEMORY;
	}
	return pNewObject;
}

HRESULT TouchLibFilter::NonDelegatingQueryInterface(REFIID iid, void **ppv)
{
	if (iid == IID_ITouchLibFilter) 
	{
		return GetInterface(static_cast<ITouchLibFilter*>(this), ppv);
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


HRESULT TouchLibFilter::Receive(IMediaSample *pSample, const IPin* pReceivePin)
{
	if (m_pInputPins.size() >= 0 && pReceivePin == m_pInputPins[0] )
	{
		return ReceiveInput0(pSample, pReceivePin);
	}
	return S_FALSE;
}

HRESULT TouchLibFilter::CreatePins()
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

		CMuxTransformInputPin* pInput0 = new CMuxTransformInputPin(NAME("CMuxTransform input pin"),
			this,              // Owner filter
			&hr,               // Result code
			L"input");      // Pin name
		//  Can't fail
		
		

		CMuxTransformOutputPin* pOutput = new CMuxTransformOutputPin(NAME("Transform output pin"),
			this,            // Owner filter
			&hr,             // Result code
			L"output");   // Pin name
		// Can't fail
	
		m_pInputPins.push_back(pInput0);
		m_pOutputPins.push_back(pOutput);
	}
	return S_OK;
}

HRESULT TouchLibFilter::CheckInputType( const CMediaType * pmt , const IPin* pPin)
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
	return E_FAIL;
}

HRESULT TouchLibFilter::CheckOutputType( const CMediaType * pmt , const IPin* pPin)
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

HRESULT TouchLibFilter::CompleteConnect(PIN_DIRECTION direction, const IPin* pMyPin, const IPin* pOtherPin)
{
	if (m_pInputPins.size() >= 1 && m_pInputPins[0] == pMyPin)
	{
		CMediaType mt = m_pInputPins[0]->CurrentMediaType();
		if (IsEqualGUID(*mt.Type(), GUID_MyMediaSample) && IsEqualGUID(*mt.Subtype(), GUID_D3DXTEXTURE9_POINTER))
		{
			D3DSURFACE_DESC* desc = ((D3DSURFACE_DESC* ) (mt.pbFormat));
			CreateTouchScreen(desc->Width, desc->Height);
		}
		else
		{
			VIDEOINFOHEADER *pvi = (VIDEOINFOHEADER *) mt.pbFormat;
			BITMAPINFOHEADER bitHeader = pvi->bmiHeader;
			CreateTouchScreen(bitHeader.biWidth, bitHeader.biHeight);
		}
		m_pTouchScreen->beginTracking();
	}
	return S_OK;
}

HRESULT TouchLibFilter::BreakConnect(PIN_DIRECTION dir, const IPin* pPin)
{
	if (dir == PINDIR_INPUT)
	{
		DestoryTouchScreen();
	}
	return __super::BreakConnect(dir, pPin);
}


HRESULT TouchLibFilter::DecideBufferSize(IMemAllocator *pAlloc, const IPin* pOutPin, ALLOCATOR_PROPERTIES *pProp)
{
	HRESULT hr = NOERROR;
	if (m_pInputPins.size() <= 0)
	{
		return S_FALSE;
	}
	CMediaType inputMT = m_pInputPins[0]->CurrentMediaType();
	if (inputMT.Type() == NULL)
	{
		return S_FALSE;
	}
	if (m_pOutputPins.size() > 0 && m_pOutputPins[0] == pOutPin )
	{
		VIDEOINFOHEADER *pvi = (VIDEOINFOHEADER *) inputMT.pbFormat;
		BITMAPINFOHEADER bitHeader = pvi->bmiHeader;

		pProp->cBuffers = 1;
		pProp->cbBuffer = inputMT.GetSampleSize();


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


HRESULT TouchLibFilter::GetMediaType(int iPosition, const IPin* pOutPin, __inout CMediaType *pMediaType)
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


bool TouchLibFilter::IsAcceptedType(const CMediaType *pmt)
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

HRESULT TouchLibFilter::GetPages(CAUUID *pPages)
{
	pPages->cElems = 1;
	pPages->pElems = (GUID*)CoTaskMemAlloc(sizeof(GUID));
	if (pPages->pElems == NULL) 
	{
		return E_OUTOFMEMORY;
	}
	pPages->pElems[0] = CLSID_TouchLibPropPage;
	return S_OK;
}

bool TouchLibFilter::CreateTouchScreen(float cw, float ch)
{
	if (m_pTouchScreen != NULL)
	{
		TouchScreenDevice::destroy();
		m_pTouchScreen = NULL;
	}
	m_pTouchScreen = TouchScreenDevice::getTouchScreen(cw, ch);
	m_pTouchScreen->setDebugMode(false);

	m_monolabel = m_pTouchScreen->pushFilter("mono");
	m_bgLabel = m_pTouchScreen->pushFilter("backgroundremove");
	m_pTouchScreen->setParameter(m_bgLabel, "threshold", "0");

	m_shpLabel = m_pTouchScreen->pushFilter("simplehighpass");
	m_pTouchScreen->setParameter( m_shpLabel, "blur", "13");
	m_pTouchScreen->setParameter( m_shpLabel, "noise", "3");

	m_scalerLabel = m_pTouchScreen->pushFilter("scaler");
	m_pTouchScreen->setParameter(m_scalerLabel, "level", "70");

	m_rectifyLabel = m_pTouchScreen->pushFilter("rectify");
	m_pTouchScreen->setParameter(m_rectifyLabel, "level", "75");
	
	m_pTouchScreen->setParameter(m_bgLabel, "mask", (char*)m_pTouchScreen->getCameraPoints());
	m_pTouchScreen->setParameter(m_bgLabel, "capture", "");
	m_pTouchScreen->registerListener((ITouchListener*)this);
	return true;
}
bool TouchLibFilter::DestoryTouchScreen()
{
	TouchScreenDevice::destroy();
	m_pTouchScreen = NULL;
	return true;
}
HRESULT TouchLibFilter::TransformInput0(IMediaSample *pSample, IMediaSample *pOut)
{
	if (m_pInputPins.size() < 1)
		return S_FALSE;
	if (m_pTouchScreen == NULL)
	{
		return S_FALSE;
	}
	BYTE* pOutData = NULL;
	pOut->GetPointer(&pOutData);
	IplImage* pSrc = NULL;
	LPDIRECT3DTEXTURE9 pInTexture = NULL;

	int channel = 4;
	CMediaType mt = ((CMuxTransformInputPin*)m_pInputPins[0])->CurrentMediaType();
	if (IsEqualGUID(*mt.Type(), GUID_MyMediaSample) && IsEqualGUID(*mt.Subtype(), GUID_D3DXTEXTURE9_POINTER))
	{
		D3DLOCKED_RECT InRect;
		pSample->GetPointer((BYTE**)&pInTexture);
		pInTexture->LockRect(0, &InRect, NULL, 0);

		D3DSURFACE_DESC* desc = ((D3DSURFACE_DESC* ) (mt.pbFormat));
		pSrc = cvCreateImageHeader(cvSize(desc->Width, desc->Height), 8, 4);
		pSrc->imageData = (char*)InRect.pBits;


	}
	else
	{
		VIDEOINFOHEADER *pvi = (VIDEOINFOHEADER *) mt.pbFormat;
		BITMAPINFOHEADER bitHeader = pvi->bmiHeader;
		
		if (IsEqualGUID(*mt.Subtype(), MEDIASUBTYPE_RGB24)) 
		{
			channel = 3;
		}
		else if (IsEqualGUID(*mt.Subtype(), MEDIASUBTYPE_RGB32) ||
			IsEqualGUID(*mt.Subtype(), MEDIASUBTYPE_ARGB32))
		{
			channel = 4;
		}
		else
		{
			return S_FALSE;
		}
		pSrc = cvCreateImageHeader(cvSize(bitHeader.biWidth, bitHeader.biHeight), 8, channel);
		BYTE* pInData = NULL;
		pSample->GetPointer(&pInData);
		pSrc->imageData = (char*)pInData;

	}
	m_pTouchScreen->processOnce(pSrc);
	m_pTouchScreen->getEvents();
	IplImage* outImage = NULL;
	
	outImage = m_pTouchScreen->getFilterImage(m_rectifyLabel);
	if (outImage == NULL)
		return S_FALSE;
	int width = outImage->height;
	int height = outImage->width;
	for (int y = 0 ; y < width; y++)
	{
		for (int x = 0; x< height; x++)
		{
			for (int i = 0 ; i < channel; i++)
			{
				pOutData[y*width*channel + x*channel + i] = outImage->imageData[y*width + x];
			}
		}
	}
	if (pInTexture != NULL)
	{
		pInTexture->UnlockRect(0);
	}
	if (pSrc != NULL)
	{
		cvReleaseImageHeader(&pSrc);
		pSrc = NULL;
	}
	return S_OK;
}
HRESULT TouchLibFilter::ReceiveInput0(IMediaSample *pSample, const IPin* pReceivePin)
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

	hr = TransformInput0(pSample, pOutSample);

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


//ITouchListener
void TouchLibFilter::fingerDown(TouchData data)
{
	int test = 0;
}
//! Notify that a finger has just been made active. 
void TouchLibFilter::fingerUpdate(TouchData data)
{
	int test = 0;
}
//! A finger is no longer active..
void TouchLibFilter::fingerUp(TouchData data)
{
	int test = 0;
}
/*
bool TouchLibFilter::SimpleHighpassFilter(IplImage* srcImage, IplImage *dstImage)
{
	if (srcImage == NULL || dstImage == NULL)
	{
		return false;
	}
	if (srcImage->width != dstImage->height || srcImage->height != dstImage->width || 
		srcImage->depth != dstImage->depth || srcImage->nChannels != dstImage->nChannels)
	{
		return false;
	}
	

	if (m_buffer == NULL) {
		m_buffer = cvCreateImage(cvGetSize(srcImage), srcImage->depth, srcImage->nChannels);
		m_buffer->origin = srcImage->origin;
	}

	// create the unsharp mask using a linear average filter
	int blurParameter = m_blurLevel*2+1;
	cvSmooth(srcImage, m_buffer, CV_BLUR, blurParameter, blurParameter);
	
	cvSub(srcImage, m_buffer, m_buffer);

	// filter out the noise using a median filter
	int noiseParameter = m_noiseLevel*2+1;
	cvSmooth(m_buffer, dstImage, m_noiseSmoothType, noiseParameter, noiseParameter);
	return true;
}
bool TouchLibFilter::ScaleFilter(IplImage* srcImage, IplImage* dstImage)
{
	if (srcImage == NULL || dstImage == NULL)
	{
		return false;
	}
	if (srcImage->width != dstImage->height || srcImage->height != dstImage->width || 
		srcImage->depth != dstImage->depth || srcImage->nChannels != dstImage->nChannels)
	{
		return false;
	}
	// derived class responsible for allocating storage for filtered image

	cvMul(srcImage, srcImage, dstImage, (float)m_levelScale / 128.0f);
	return true;
}

bool TouchLibFilter::RectifyFilter(IplImage* srcImage, IplImage* dstImage)
{
	if (srcImage == NULL || dstImage == NULL)
	{
		return false;
	}
	if (srcImage->width != dstImage->height || srcImage->height != dstImage->width || 
		srcImage->depth != dstImage->depth || srcImage->nChannels != dstImage->nChannels)
	{
		return false;
	}

	if(m_bAutoSet)
	{
		touchlib::BwImage img(srcImage);

		int h, w;
		h = img.getHeight();
		w = img.getWidth();

		unsigned char highest = 0;

		for(int y=0; y<h; y++)
			for(int x=0; x<w; x++)
			{
				if(img[y][x] > highest)
					highest = img[y][x];
			}

			m_levelRectify = (unsigned int)highest;
			m_bAutoSet = false;
	}

	cvThreshold(srcImage, dstImage, m_levelRectify, 255, CV_THRESH_TOZERO);		//CV_THRESH_BINARY
}
*/