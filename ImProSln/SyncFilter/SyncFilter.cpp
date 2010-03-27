#include "stdafx.h"
#include "SyncFilter.h"
#include "SyncFilterApp.h"
#include "MyMediaSample.h"
#include "MyARTagMediaSample.h"



SyncFilter::SyncFilter(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData)
: CMuxTransformFilter(NAME("Sync Filter"), 0, CLSID_SyncFilter)
{ 
	setDirty(false);
	setBlock(false);
	
}
SyncFilter::~SyncFilter()
{
}


CUnknown *WINAPI SyncFilter::CreateInstance(LPUNKNOWN punk, HRESULT *phr)
{
	ASSERT(phr);
	// assuming we don't want to modify the data
	SyncFilter *pNewObject = new SyncFilter(punk, phr, FALSE);

	if(pNewObject == NULL) {
		if (phr)
			*phr = E_OUTOFMEMORY;
	}
	return pNewObject;
}

HRESULT SyncFilter::NonDelegatingQueryInterface(REFIID iid, void **ppv)
{
	if (iid == IID_ISyncFilter) 
	{
		return GetInterface(static_cast<ISyncFilter*>(this), ppv);
	}
	else
	{
		// Call the parent class.
		return CBaseFilter::NonDelegatingQueryInterface(iid, ppv);
	}
}

HRESULT SyncFilter::ReceiveCameraImg(IMediaSample *pSample, const IPin* pReceivePin)
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
	IMediaSample * pOutSample = NULL;
	ASSERT (m_pOutputPins.size() != NULL);
	HRESULT hr = S_OK;
	MSR_START(m_idTransform);

	pOutSample = pSample;
	pOutSample->AddRef();

	MSR_STOP(m_idTransform);

	if (FAILED(hr)) {
		DbgLog((LOG_TRACE,1,TEXT("Error from transform")));
	} else {
		if (hr == NOERROR) {
			hr = GetConnectedOutputPin(0)->Deliver(pOutSample);// m_pInputPin->Receive(pOutSample);
			m_bSampleSkipped = FALSE;	// last thing no longer dropped
		} else {
		if (S_FALSE == hr) {
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
	pOutSample->Release();
	return S_OK;
}

HRESULT SyncFilter::ReceiveDirty(IMediaSample *pSample, const IPin* pReceivePin){

	CAutoLock lck(&locMarkerInfo);
	ARLayoutConfigData* pARTagResult = NULL;
	pSample->GetPointer((BYTE**)&pARTagResult);
	if (pARTagResult == NULL)
	{
		return S_FALSE;
	}
	tagConfig = *pARTagResult;

	setDirty(true);
    return S_OK;
}
HRESULT SyncFilter::CopyInRT2OutTexture()
{
	CCritSec* pD3DCS = NULL;
	QueryD3DDeviceCS(NULL, pD3DCS);
	if (pD3DCS == NULL)
		return S_FALSE;
	CAutoLock lck(pD3DCS);

    IDirect3DSurface9* pInSurface = NULL, *pOutSurface = NULL;
	m_pInTexture->GetSurfaceLevel(0, &pInSurface);
	m_pOutTexture->GetSurfaceLevel(0, &pOutSurface);

	IDirect3DDevice9* pDevice = m_pD3DDisplay->GetD3DDevice();
	
	pDevice->GetRenderTargetData(pInSurface, pOutSurface);

	if (pInSurface != NULL)
	{
		pInSurface->Release();
		pInSurface = NULL;
	}
	if (pOutSurface != NULL)
	{
		pOutSurface->Release();
		pOutSurface = NULL;
	}
	return S_OK;

}
HRESULT SyncFilter::ReceiveLayoutImg(IMediaSample *pSample, const IPin* pReceivePin)
{
	
	if (m_pOutputPins.size() < 2)
	{
		return S_FALSE;
	}

	AM_SAMPLE2_PROPERTIES * const pProps = ((CMuxTransformInputPin*)pReceivePin)->SampleProps();
	if (pProps->dwStreamId != AM_STREAM_MEDIA) {
		return S_OK;
	}
	ASSERT(pSample);
	IMediaSample* pOutSampleD3D = NULL;
	IMediaSample* pOutSampleRGB = NULL;
	CMediaSample* pOutSampleConfig = NULL ;

	CMuxTransformOutputPin* pOutBGPin = GetConnectedOutputPin(1);
	CMuxTransformOutputPin* pOutRenderPin = GetConnectedOutputPin(2);

	ARLayoutConfigData sendData ;

	// If no output to deliver to then no point sending us data
	ASSERT (m_pOutputPins.size() != NULL);
	HRESULT hr;
	// Set up the output sample
	MSR_START(m_idTransform);

	if(pOutRenderPin != NULL && pOutRenderPin->IsConnected()){
		hr = InitializeOutputSample(pSample, pReceivePin, pOutRenderPin, &pOutSampleD3D);
		hr = LayoutTransform(pSample, pOutSampleD3D);
	}
	if(pOutBGPin != NULL && pOutBGPin->IsConnected() && getDirty() == true){
		if(layoutType == 0){
			hr = InitializeOutputSample(pSample, pReceivePin, pOutBGPin, &pOutSampleRGB);
			hr = CopyRenderTarget2OutputTexture();	
			hr = CopyOutputTexture2OutputData(pOutSampleRGB,&pOutBGPin->CurrentMediaType(),0);
		}
		else if(layoutType == 1){
			{
				CAutoLock lck(&locMarkerInfo);
				sendData.m_ARMarkers = tagConfig.m_ARMarkers;
				sendData.m_numMarker = tagConfig.m_numMarker;

				IMemAllocator* pAllocator = m_pOutputPins[1]->Allocator();
				
				pAllocator->GetBuffer((IMediaSample**)&pOutSampleConfig, NULL, NULL, 0);
				if (pOutSampleConfig == NULL)
				{
					sendData.m_ARMarkers = NULL;
					sendData.m_numMarker = 0;
					return S_FALSE;
				}
			
				pOutSampleConfig->SetPointer((BYTE*)&sendData, sizeof(ARLayoutConfigData));			
			}

		}
	}

	if (FAILED(hr)) {
		return hr;
	}
	
	if(getDirty() == true){
		setBlock(true);
	}
	//MSR_STOP(m_idTransform);

	if (FAILED(hr)) {
		DbgLog((LOG_TRACE,1,TEXT("Error from transform")));
	} else {
		if (hr == NOERROR) {

			if(pOutSampleRGB != NULL && layoutType == 0 && getDirty()== true){
				hr = GetConnectedOutputPin(1)->Deliver(pOutSampleRGB);// Pin1 :: BG  only deliver in layout change
				setDirty(false);
			}
			if(pOutSampleConfig != NULL && layoutType == 1 && getDirty()== true){
				hr = GetConnectedOutputPin(1)->Deliver(pOutSampleConfig);
				setDirty(false);
			}
			if( pOutSampleD3D != NULL){
				hr = GetConnectedOutputPin(2)->Deliver(pOutSampleD3D);// Pin2 :: Render every frame deliver
			}
			setBlock(false);
			m_bSampleSkipped = FALSE;	// last thing no longer dropped
		} else {
		
			if (S_FALSE == hr) {
				if (pOutSampleRGB != NULL)
				{
					pOutSampleRGB->Release();
					pOutSampleRGB = NULL;
				}
				if (pOutSampleD3D != NULL)
				{
					pOutSampleD3D->Release();
					pOutSampleD3D = NULL;
				}
				m_bSampleSkipped = TRUE;
				if (!m_bQualityChanged) {
					NotifyEvent(EC_QUALITY_CHANGE,0,0);
					m_bQualityChanged = TRUE;
				}
				return NOERROR;
			}
		}
	}
	sendData.m_ARMarkers = NULL;
	sendData.m_numMarker = 0;

	if(pOutSampleRGB != NULL)
	{
		pOutSampleRGB->Release();
		pOutSampleRGB = NULL;
	}
	if(pOutSampleD3D != NULL)
	{
		pOutSampleD3D->Release();
		pOutSampleD3D = NULL;
	}
	if (pOutSampleConfig != NULL)
	{
		pOutSampleConfig->Release();
		pOutSampleConfig = NULL;
	}

	return S_OK;
}



CMuxTransformOutputPin* SyncFilter::GetConnectedOutputPin(int pinNum )
{
	if (m_pOutputPins[pinNum]->IsConnected())
	{
		return m_pOutputPins[pinNum];
	}
	return NULL;
}



HRESULT SyncFilter::Receive(IMediaSample *pSample, const IPin* pReceivePin)
{
	HRESULT hr = S_OK;
	if (m_pInputPins.size() >= 3 && pReceivePin == m_pInputPins[0] && !getBlock())
	{
		hr = ReceiveCameraImg(pSample, pReceivePin);
	}
	if (m_pInputPins.size() >= 3 && pReceivePin == m_pInputPins[1])
	{
		hr = ReceiveDirty(pSample, pReceivePin);
	}
	if (m_pInputPins.size() >= 3 && pReceivePin == m_pInputPins[2])
	{	
		hr = ReceiveLayoutImg(pSample, pReceivePin);
	}
	return hr;
}

HRESULT SyncFilter::CreatePins()
{
	HRESULT hr = S_OK;
	if (m_pInputPins.size() < 3 || m_pOutputPins.size() < 3) {
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

		CMuxTransformInputPin* pInput0 = new CMuxTransformInputPin(NAME("Camera input pin"),
			this,              // Owner filter
			&hr,               // Result code
			L"camInput");      // Pin name
		//  Can't fail
	
		CMuxTransformInputPin* pInput1 = new CMuxTransformInputPin(NAME("Dirty  pin"),
			this,              // Owner filter
			&hr,               // Result code
			L"Dirty");      // Pin name
		//  Can't fail
	
		CMuxTransformInputPin* pInput2 = new CMuxTransformInputPin(NAME("Layout input pin"),
			this,              // Owner filter
			&hr,               // Result code
			L"Layout");      // Pin name
		//  Can't fail

		CMuxTransformOutputPin* pOut0 = new CMuxTransformOutputPin(NAME("camera output pin"),
			this,            // Owner filter
			&hr,             // Result code
			L"CamOut");   // Pin name
		// Can't fail

		CMuxTransformOutputPin* pOut1 = new CMuxTransformOutputPin(NAME("BG output pin"),
			this,            // Owner filter
			&hr,             // Result code
			L"BG");   // Pin name
		// Can't fail

		CMuxTransformOutputPin* pOut2 = new CMuxTransformOutputPin(NAME("Render output pin"),
			this,            // Owner filter
			&hr,             // Result code
			L"Render");   // Pin name
		// Can't fail
		
		m_pInputPins.push_back(pInput0);
		m_pInputPins.push_back(pInput1);
		m_pInputPins.push_back(pInput2);

		m_pOutputPins.push_back(pOut0);
		m_pOutputPins.push_back(pOut1);
		m_pOutputPins.push_back(pOut2);

	}
	return S_OK;
}

HRESULT SyncFilter::CheckInputType( const CMediaType * pmt , const IPin* pPin)
{
	CheckPointer(pmt, E_POINTER);
	if (m_pInputPins.size() >= 1 && m_pInputPins[0] == pPin)   // camera image
	{
		if (*pmt->FormatType() != FORMAT_VideoInfo) {
			return E_INVALIDARG;
		}
		if (IsEqualGUID(*pmt->Type(), MEDIATYPE_Video) && 
			(IsEqualGUID(MEDIASUBTYPE_RGB24, *pmt->Subtype()) || IsEqualGUID(MEDIASUBTYPE_RGB32, *pmt->Subtype())))
			return NOERROR;
	}

	else if (m_pInputPins.size() >= 1 && m_pInputPins[1] == pPin)    // dirty Pin
	{
		if (IsEqualGUID(*pmt->Type(), GUID_IMPRO_FeedbackTYPE) && 
			(IsEqualGUID(GUID_ARLayoutConfigData, *pmt->Subtype()) ))
			return NOERROR;

	}

	else if (m_pInputPins.size() >= 1 && m_pInputPins[2] == pPin)      // layout image
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

bool SyncFilter::IsAcceptedType(const CMediaType *pmt){
	GUID guidSubType = *pmt->Subtype();

	if (IsEqualGUID(*pmt->Type(), MEDIATYPE_Video)) 
	{
		if(IsEqualGUID(guidSubType, MEDIASUBTYPE_RGB24))
		{
			return true;
		}
		else if(IsEqualGUID(guidSubType, MEDIASUBTYPE_RGB32))			
		{
			return true;
		}
	}

	else if (IsEqualGUID(*pmt->Type(), GUID_D3DMEDIATYPE) && 
		IsEqualGUID(guidSubType, GUID_D3DXTEXTURE9_POINTER))
	{
		return true;
	}
	else if (IsEqualGUID(*pmt->Type(), GUID_D3DMEDIATYPE) && 
		IsEqualGUID(guidSubType, GUID_D3DSHARE_RTTEXTURE_POINTER))
	{
		return true;
	}
	return false;
}
HRESULT SyncFilter::CheckOutputType( const CMediaType * pmt , const IPin* pPin)
{
	if (m_pOutputPins.size() > 0 && m_pOutputPins[0] == pPin) // camera Image
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

	if (m_pOutputPins.size() > 1 && m_pOutputPins[1] == pPin)   
	{		
		CheckPointer(pmt, E_POINTER);
		if (*pmt->FormatType() != FORMAT_VideoInfo && *pmt->Subtype() != GUID_ARLayoutConfigData) {
			return E_INVALIDARG;
		}
		if (IsEqualGUID(*pmt->Type(), GUID_IMPRO_FeedbackTYPE) && 
			IsEqualGUID(*pmt->Subtype(), GUID_ARLayoutConfigData))
		{
			layoutType = 1 ;
			return NOERROR;
		}
		// Can we transform this type
		if(IsAcceptedType(pmt)){
			layoutType = 0 ;
			return NOERROR;
		}		
	}

	if (m_pOutputPins.size() > 2 && m_pOutputPins[2] == pPin)   // Render 
	{
		CheckPointer(pmt, E_POINTER);
		if (*pmt->FormatType() != FORMAT_VideoInfo && 
			*pmt->FormatType() != GUID_FORMATTYPE_D3DXTEXTURE9DESC) 
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

HRESULT SyncFilter::CompleteConnect(PIN_DIRECTION direction, const IPin* pMyPin, const IPin* pOtherPin)
{
	HRESULT hr = S_OK;
	if (direction == PINDIR_INPUT && m_pInputPins.size() > 0 && m_pInputPins[0] == pMyPin)
	{
		CMediaType inputMT = ((CMuxTransformInputPin*)pMyPin)->CurrentMediaType();
		VIDEOINFOHEADER *pvi = (VIDEOINFOHEADER *) inputMT.pbFormat;
		BITMAPINFOHEADER bitHeader = pvi->bmiHeader;
		GUID guidSubType = inputMT.subtype;
		return S_OK;

	}

	else if (direction == PINDIR_INPUT && m_pInputPins.size() > 1 && m_pInputPins[2] == pMyPin)  // Layout
	{
		CMediaType inputMT = ((CMuxTransformInputPin*)pMyPin)->CurrentMediaType();
		if (IsEqualGUID(*inputMT.Type(), GUID_D3DMEDIATYPE) && 
			IsEqualGUID(*inputMT.Subtype(), GUID_D3DXTEXTURE9_POINTER))
		{
			D3DSURFACE_DESC* desc = (D3DSURFACE_DESC*)inputMT.pbFormat;
			initD3D(desc->Width, desc->Height);
			return S_OK;
		}
		if (IsEqualGUID(*inputMT.Type(), GUID_D3DMEDIATYPE) && 
			IsEqualGUID(*inputMT.Subtype(), GUID_D3DSHARE_RTTEXTURE_POINTER))
		{
			D3DSURFACE_DESC* desc = (D3DSURFACE_DESC*)inputMT.pbFormat;
			IDirect3DDevice9* pDevice = NULL;
			m_pInputPins[2]->QueryD3DDevice(pDevice);
			if (pDevice == NULL)
				return S_FALSE;
			initD3D(desc->Width, desc->Height, pDevice);
			pDevice->Release();
			pDevice = NULL;
			return S_OK;
		}
		else
		{
			VIDEOINFOHEADER *pvi = (VIDEOINFOHEADER *) inputMT.pbFormat;
			BITMAPINFOHEADER bitHeader = pvi->bmiHeader;
			initD3D(bitHeader.biWidth, bitHeader.biHeight);
			return S_OK;
		}
	}
	return S_OK;
}

HRESULT SyncFilter::BreakConnect(PIN_DIRECTION dir, const IPin* pPin)
{
	return __super::BreakConnect(dir, pPin);
}

HRESULT SyncFilter::CamTransform( IMediaSample *pIn, IMediaSample *pOut)
{
	HRESULT hr = S_OK;
	long cbData;
	BYTE* outByte = NULL;
	// Access the sample's data buffer
	BYTE* CamData = NULL;
	pIn->GetPointer(&CamData);
	pOut->GetPointer(&outByte);
	cbData = pOut->GetSize();
	memcpy (outByte,CamData,cbData);
	return S_OK;
}

HRESULT SyncFilter::LayoutTransform( IMediaSample *pIn, IMediaSample *pOut)
{
	HRESULT hr = S_OK;

	if (m_pD3DDisplay != NULL)
	{
		if (m_pInputPins.size() <= 0 || m_pOutputPins.size() <= 0)
		{
			return S_FALSE;
		}
		CCritSec* pD3DCS = NULL;
		QueryD3DDeviceCS(NULL, pD3DCS);
		if (pD3DCS == NULL)
			return S_FALSE;
		CAutoLock lck(pD3DCS);
		CMuxTransformOutputPin* pOutPin = GetConnectedOutputPin(2);
		if (pOutPin == NULL)
		{
			return S_FALSE;
		}
		CMediaType mt;

		mt = pOutPin->CurrentMediaType();

		DoTransform(pIn, pOut, &m_pInputPins[2]->CurrentMediaType(), &pOutPin->CurrentMediaType());


	}
	return S_OK;
}


HRESULT SyncFilter::DecideBufferSize(IMemAllocator *pAlloc, const IPin* pOutPin, ALLOCATOR_PROPERTIES *pProp)
{
	HRESULT hr = NOERROR;
	if (m_pInputPins.size() <= 2)
	{
		return S_FALSE;
	}
	CMediaType outPin0MT = m_pOutputPins[0]->CurrentMediaType();  
	CMediaType outPin1MT = m_pOutputPins[1]->CurrentMediaType();
	CMediaType outPin2MT = m_pOutputPins[2]->CurrentMediaType();

	if (outPin0MT.Type() == NULL || outPin1MT.Type() == NULL|| outPin2MT.Type() == NULL)
	{
		return S_FALSE;
	}
	if (m_pOutputPins.size() > 0 && m_pOutputPins[0] == pOutPin )
	{
		VIDEOINFOHEADER *pvi = (VIDEOINFOHEADER *) outPin0MT.pbFormat;
		BITMAPINFOHEADER bitHeader = pvi->bmiHeader;

		pProp->cBuffers = 1;
		pProp->cbBuffer = outPin0MT.GetSampleSize();//bitHeader.biWidth*bitHeader.biHeight;

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

	if (m_pOutputPins.size() > 1 && m_pOutputPins[1] == pOutPin )
	{
		pProp->cBuffers = 1;
		pProp->cbBuffer = outPin1MT.GetSampleSize();

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

	if (m_pOutputPins.size() > 0 && m_pOutputPins[2] == pOutPin )
	{
		VIDEOINFOHEADER *pvi = (VIDEOINFOHEADER *) outPin2MT.pbFormat;
		BITMAPINFOHEADER bitHeader = pvi->bmiHeader;

		pProp->cBuffers = 1;
		pProp->cbBuffer = outPin2MT.GetSampleSize();//bitHeader.biWidth*bitHeader.biHeight;

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

HRESULT SyncFilter::GetMediaType(int iPosition, const IPin* pOutPin, __inout CMediaType *pMediaType)
{

	if (m_pInputPins.size() <= 0)
	{
		return S_FALSE;
	}

	if (m_pOutputPins.size() > 0 && m_pOutputPins[0] == pOutPin)    // camera pin output camera Image
	{
		if (iPosition < 0) {
			return E_INVALIDARG;
		}
		if (iPosition >= 1) { 
			return VFW_S_NO_MORE_ITEMS;
		}
		CMediaType inputMT = m_pInputPins[0]->CurrentMediaType(); 
		long size = inputMT.GetSampleSize();
		*pMediaType = inputMT;
		return S_OK;
	}

	// BG pin
	else if (m_pOutputPins.size() > 1 && m_pInputPins[2] != NULL && m_pOutputPins[1] == pOutPin)
	{
		if (m_pOutTexture == NULL)
			return S_FALSE;
		if (iPosition == 0)
		{
			CMediaType mt;
			mt.SetType(&GUID_IMPRO_FeedbackTYPE);
			mt.SetSubtype(&GUID_ARLayoutConfigData);
			mt.SetSampleSize(sizeof(ARLayoutConfigData));
			*pMediaType = mt;
			return S_OK;
		}
		else if (iPosition == 1)
		{
			CMediaType mt;
			D3DSURFACE_DESC desc;
			m_pOutTexture->GetLevelDesc(0, &desc);
			mt.SetType(&MEDIATYPE_Video);
			mt.SetFormatType(&FORMAT_VideoInfo);
			mt.SetTemporalCompression(FALSE);
			mt.SetSubtype(&MEDIASUBTYPE_RGB32);
			mt.SetSampleSize(desc.Width*desc.Height*4);

			VIDEOINFOHEADER pvi;
			memset((void*)&pvi, 0, sizeof(VIDEOINFOHEADER));
			pvi.bmiHeader.biSizeImage = 0; //for uncompressed image
			pvi.bmiHeader.biWidth = desc.Width;
			pvi.bmiHeader.biHeight = desc.Height;
			pvi.bmiHeader.biBitCount = 32;
			SetRectEmpty(&(pvi.rcSource));
			SetRectEmpty(&(pvi.rcTarget));
			mt.SetFormat((BYTE*)&pvi, sizeof(VIDEOINFOHEADER));
			*pMediaType = mt;
			return S_OK;
		}
		else
		{
			return VFW_S_NO_MORE_ITEMS;
		}
	}

	// Render Pin
	else if (m_pOutputPins.size() > 2 && m_pInputPins[2] != NULL && m_pOutputPins[2] == pOutPin)
	{
		if (iPosition == 0)    // share Texture
		{
			CMediaType mt;
			mt.SetType(&GUID_D3DMEDIATYPE);
			mt.SetSubtype(&GUID_D3DSHARE_RTTEXTURE_POINTER);
			mt.SetSampleSize(sizeof(LPDIRECT3DTEXTURE9));
			D3DSURFACE_DESC desc;
			m_pRenderTarget->GetLevelDesc(0, &desc);
			mt.SetFormat((BYTE*)&desc, sizeof(D3DSURFACE_DESC));
			mt.SetFormatType(&GUID_FORMATTYPE_D3DXTEXTURE9DESC);
			*pMediaType = mt;
			return S_OK;
		}
		else if (iPosition == 1)   //d3d texture
		{
			CMediaType mt;
			mt.SetType(&GUID_D3DMEDIATYPE);
			mt.SetSubtype(&GUID_D3DXTEXTURE9_POINTER);
			mt.SetSampleSize(sizeof(LPDIRECT3DTEXTURE9));
			D3DSURFACE_DESC desc;
			m_pOutTexture->GetLevelDesc(0, &desc);
			mt.SetFormat((BYTE*)&desc, sizeof(D3DSURFACE_DESC));
			mt.SetFormatType(&GUID_FORMATTYPE_D3DXTEXTURE9DESC);
			*pMediaType = mt;
			return S_OK;
		}
	}
	return VFW_S_NO_MORE_ITEMS;
}

bool SyncFilter::getDirty(){
	CAutoLock lck(&locDirty);
	return Dirty;
}

HRESULT SyncFilter::setDirty(bool isDirty){
	CAutoLock lck(&locDirty);
	Dirty = isDirty;
	return S_OK;
}

bool SyncFilter::getBlock(){
	CAutoLock lck(&locBlock);
	return Block;
}

HRESULT SyncFilter::setBlock(bool isBlock){
	CAutoLock lck(&locBlock);
	Block = isBlock;
	return S_OK;
}

//for implement D3DTransformFilterBase Method

MS3DDisplay* SyncFilter::Create3DDisplay(IDirect3D9* pD3D, int rtWidth, int rtHeight)
{
	MS3DDisplay* newMS3DDisplay  = new MS3DDisplay(pD3D,rtWidth,rtHeight);
	return newMS3DDisplay;
}

MS3DDisplay* SyncFilter::Create3DDisplay(IDirect3DDevice9* pDevice, int rtWidth, int rtHeight)
{
	MS3DDisplay* newMS3DDisplay  = new MS3DDisplay(pDevice,rtWidth,rtHeight);
	return newMS3DDisplay;
}


HRESULT SyncFilter::QueryD3DDevice(IDXBasePin* pPin, IDirect3DDevice9*& outDevice)
{
	if (m_pD3DDisplay == NULL)
		return S_FALSE;
	outDevice = m_pD3DDisplay->GetD3DDevice();
	if (outDevice != NULL)
	{
		outDevice->AddRef();
	}
	return S_OK;
}

HRESULT SyncFilter::QueryD3DDeviceCS(IDXBasePin* pPin, CCritSec*& cs)
{
	if (m_pD3DDisplay == NULL || m_pInputPins.size() <= 0 || m_pInputPins[0] == NULL)
		return S_FALSE;
	if (m_pD3DDisplay->IsDeviceFromOther())
	{
		IDXBasePin* pDXInPin = NULL;
		m_pInputPins[2]->QueryInterface(IID_IDXBasePin, (void**)&pDXInPin);
		if (pDXInPin == NULL)
			return S_FALSE;
		pDXInPin->QueryD3DDeviceCS(cs);
		pDXInPin->Release();
		pDXInPin = NULL;
		return S_OK;
	}
	else
	{
		cs = &m_csD3DDisplay;
		return S_OK;
	}
	return S_OK;
}