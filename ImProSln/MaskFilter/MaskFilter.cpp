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
	m_pARLayoutConfig = NULL;
	m_pMaskVertexData = NULL;
	m_fMaskScale = 0.8; 
}
MaskFilter::~MaskFilter()
{
	if (m_pARLayoutConfig != NULL)
	{
		delete m_pARLayoutConfig;
		m_pARLayoutConfig = NULL;
	}
	if (m_pMaskVertexData != NULL)
	{
		delete m_pMaskVertexData;
		m_pMaskVertexData = NULL;
	}
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
	else if (iid == IID_ISpecifyPropertyPages)
	{
		return GetInterface(
			static_cast<ISpecifyPropertyPages*>(this),	ppv);
	}
	else if (iid == IID_IMSPersist)
	{
		return GetInterface(
			static_cast<IMSPersist*>(this),	ppv);
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
	if (pSample == NULL)
		return S_FALSE;
	if (m_pD3DDisplay == NULL)
		return S_FALSE;

	ARLayoutConfigData* pARConfig = NULL;
	pSample->GetPointer((BYTE**)&pARConfig);
	if (pARConfig == NULL)
		return S_FALSE;
	{
		CAutoLock lck(&m_csARLayoutConfig);
		if (m_pARLayoutConfig == NULL)
		{
			m_pARLayoutConfig = new ARLayoutConfigData();
		}
		*m_pARLayoutConfig = *pARConfig;
	}
	return S_OK;
}

HRESULT MaskFilter::ReceiveInput2(IMediaSample *pSample, const IPin* pReceivePin)
{
	if (pSample == NULL)
		return S_FALSE;
	if (m_pD3DDisplay == NULL)
		return S_FALSE;


	MaskVertexData* pMaskVertexData = NULL;
	pSample->GetPointer((BYTE**)&pMaskVertexData);
	if (pMaskVertexData == NULL)
		return S_FALSE;
	if (pMaskVertexData->m_nPoints % 4 != 0)
	{
		return S_FALSE;
	}
	{
		CAutoLock lck(&m_csMaskVertexData);
		if (m_pMaskVertexData == NULL)
		{
			m_pMaskVertexData = new MaskVertexData();
		}
		*m_pMaskVertexData = *pMaskVertexData;
	}
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
	if (m_pInputPins.size() >= 3 && pReceivePin == m_pInputPins[2])
	{
		return ReceiveInput2(pSample, pReceivePin);
	}
	return S_OK;
}

HRESULT MaskFilter::CreatePins()
{
	HRESULT hr = S_OK;
	if (m_pInputPins.size() < 3 || m_pOutputPins.size() < 1) {
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

		CMuxTransformInputPin* pInput2 = new CMuxTransformInputPin(NAME("CMuxTransform input pin"),
			this,              // Owner filter
			&hr,               // Result code
			L"vtx conf");      // Pin name
		
		CMuxTransformOutputPin* pOutput = new CMuxTransformOutputPin(NAME("Transform output pin"),
			this,         // Owner filter
			&hr,          // Result code
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
		m_pInputPins.push_back(pInput2);
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
		if ( !IsEqualGUID(*pmt->Type(), GUID_MyMediaSample) || ! IsEqualGUID(*pmt->Subtype(), GUID_ARLayoutConfigData))
		{
			return E_INVALIDARG;
		}
		return NOERROR;
	}
	else if (m_pInputPins.size() >= 3 && m_pInputPins[2] == pPin)
	{
		if ( !IsEqualGUID(*pmt->Type(), GUID_MyMediaSample) || ! IsEqualGUID(*pmt->Subtype(), GUID_MaskVertexData))
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
		if (*pmt->FormatType() != FORMAT_VideoInfo && *pmt->FormatType() != GUID_FORMATTYPE_D3DXTEXTURE9DESC) {
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
	if ((m_pInputPins.size() > 1 && m_pInputPins[1] == pMyPin) || 
		(m_pInputPins.size() > 2 && m_pInputPins[2] == pMyPin))
	{
		m_pInputPins[1]->m_bVisible = (pMyPin == m_pInputPins[1]);
		m_pInputPins[2]->m_bVisible = (pMyPin == m_pInputPins[2]);
	}
	return hr;
}

HRESULT MaskFilter::BreakConnect(PIN_DIRECTION dir, const IPin* pPin)
{
	if (dir == PINDIR_INPUT && (pPin == m_pInputPins[1] || pPin == m_pInputPins[2]))
	{
		m_pInputPins[1]->m_bVisible = true;
		m_pInputPins[2]->m_bVisible = true;
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
		{
			UpdateMask();
			CAutoLock lck(&m_csDisplayState);
			DoTransform(pIn, pOut, &m_pInputPins[0]->CurrentMediaType(), &m_pOutputPins[0]->CurrentMediaType(), false);
		}
	}
	return S_OK;
}

HRESULT MaskFilter::UpdateMask()
{
	{
		CAutoLock lck(&m_csMaskVertexData);
		if (m_pMaskVertexData != NULL)
		{
			int nCol = m_pMaskVertexData->m_nPoints/4;
			D3DXVECTOR2** pt = new D3DXVECTOR2*[nCol];
			for (int i =0; i < nCol; i++)
			{
				pt[i] = new D3DXVECTOR2[4];
			}
			for (int i =0; i < nCol; i++)
			{
				for (int j = 0 ; j< 4; j++)
				{
					pt[i][j].x = m_pMaskVertexData->m_points[i*4*2 + j*2 + 0];
					pt[i][j].y = m_pMaskVertexData->m_points[i*4*2 + j*2 + 1];
				}
			}
			SetMaskFlag(m_pMaskVertexData->m_maskflag);
			GenerateMaskFromVertices(pt, nCol, m_fMaskScale);
			for (int i =0; i < nCol; i++)
			{
				delete[] pt[i];
				pt[i] = NULL;
			}
			delete pt;
			pt = NULL;
			delete m_pMaskVertexData;
			m_pMaskVertexData = NULL;
		}
	}
	{
		CAutoLock lck(&m_csARLayoutConfig);
		if (m_pARLayoutConfig != NULL)
		{
			ARMultiMarkerInfoT* config = NULL;
			((MaskFilterDisplay*)m_pD3DDisplay)->GenerateARMarkinfo(m_pARLayoutConfig->m_ARMarkers,
				m_pARLayoutConfig->m_numMarker, config);
			if (config == NULL)
				return S_FALSE;
			GenerateMaskFromARLayout(config, m_fMaskScale);
			delete config;
			config = NULL;
		}
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

BOOL MaskFilter::SetMaskFlag(int flag)
{
	CAutoLock lck(&m_csDisplayState);
	if (m_pD3DDisplay == NULL)
	{
		return FALSE;
	}
	return ((MaskFilterDisplay*)m_pD3DDisplay)->SetMaskFlag(flag);
}
int MaskFilter::GetMaskFlag()
{
	CAutoLock lck(&m_csDisplayState);
	if (m_pD3DDisplay == NULL)
	{
		return -1;
	}
	return ((MaskFilterDisplay*)m_pD3DDisplay)->GetMaskFlag();
}

BOOL MaskFilter::LoadMaskFromFile(WCHAR* path)
{
	CAutoLock lck(&m_csDisplayState);
	if (m_pD3DDisplay == NULL)
		return FALSE;
	return ((MaskFilterDisplay*)m_pD3DDisplay)->LoadMaskFromFile(path);
}

BOOL MaskFilter::GenerateMaskFromARLayout(const ARMultiMarkerInfoT* pMarkerConfig, float fMaskScale)
{
	if (m_pD3DDisplay == NULL)
		return FALSE;
	CAutoLock lck(&m_csDisplayState);
	return ((MaskFilterDisplay*)m_pD3DDisplay)->GenerateMaskFromARLauout(pMarkerConfig, fMaskScale);
}
BOOL MaskFilter::GenerateMaskFromARLayoutFile(WCHAR* path, float fMaskScale )
{
	if (m_pD3DDisplay == NULL)
		return FALSE;
	CAutoLock lck(&m_csDisplayState);
	return ((MaskFilterDisplay*)m_pD3DDisplay)->GenerateMaskFromARLayoutFile(path, fMaskScale);
}
BOOL MaskFilter::GenerateMaskFromWarpMatrix(D3DXMATRIX warpMat[], int numMatrix)
{
	if (m_pD3DDisplay == NULL)
		return FALSE;
	CAutoLock lck(&m_csDisplayState);
	return ((MaskFilterDisplay*)m_pD3DDisplay)->GenerateMaskFromWarpMatrix(warpMat, numMatrix);
}
BOOL MaskFilter::GenerateMaskFromWarpConfigFile(WCHAR* path)
{
	try
	{
		D3DXMATRIX matTTS;
		FILE* filestream = NULL;
		_wfopen_s(&filestream, path, L"r");
		if (filestream == NULL)
		{
			return false;
		}
		double mat[16] = {0};
		int isFlipY = 0;
		int isInvWarp = 0;
		fwscanf_s(filestream, L"%lf %lf %lf %lf \n \
							   %lf %lf %lf %lf \n \
							   %lf %lf %lf %lf \n \
							   %lf %lf %lf %lf \n",
							   &(mat[0]), &(mat[1]), &(mat[2]), &(mat[3]),
							   &(mat[4]), &(mat[5]), &(mat[6]), &(mat[7]),
							   &(mat[8]), &(mat[9]), &(mat[10]), &(mat[11]),
							   &(mat[12]), &(mat[13]), &(mat[14]), &(mat[15])
							   );
		fwscanf_s(filestream, L"%d %d \n", &isFlipY, &isInvWarp);
		
			
		for (int row=0; row < 4; row++)
		{
			for (int col = 0; col < 4; col++)
			{
				matTTS.m[row][col] = mat[row*4 + col];
			}
		}
		fclose(filestream);

		GenerateMaskFromWarpMatrix(&matTTS, 1);
	}
	catch (exception e)
	{
		return false;
	}
	return TRUE;
}
BOOL MaskFilter::GenerateMaskFromVertices(D3DXVECTOR2* pts[], int numRects, float fMaskScale)
{
	if (m_pD3DDisplay == NULL)
		return FALSE;
	CAutoLock lck(&m_csDisplayState);
	return ((MaskFilterDisplay*)m_pD3DDisplay)->GenerateMaskFromVertices(pts, numRects, fMaskScale);
}
BOOL MaskFilter::ClearMask()
{
	if (m_pD3DDisplay == NULL)
		return FALSE;
	CAutoLock lck(&m_csDisplayState);
	return ((MaskFilterDisplay*)m_pD3DDisplay)->ClearMask();
}


BOOL MaskFilter::GetMaskFlipY()
{
	if (m_pD3DDisplay == NULL)
		return FALSE;
	CAutoLock lck(&m_csDisplayState);
	return ((MaskFilterDisplay*)m_pD3DDisplay)->GetMaskFlipY();
}
BOOL MaskFilter::SetMaskFlipY(bool bFlipY)
{
	if (m_pD3DDisplay == NULL)
		return FALSE;
	CAutoLock lck(&m_csDisplayState);
    return ((MaskFilterDisplay*)m_pD3DDisplay)->SetMaskFlipY(bFlipY);
}
float MaskFilter::GetMaskScale()
{
	CAutoLock lck(&m_csMaskScale);
	return m_fMaskScale;
}
BOOL MaskFilter::SetMaskScale(float fScale)
{
	CAutoLock lck(&m_csMaskScale);
	m_fMaskScale = fScale;
	return TRUE;
}

HRESULT MaskFilter::SaveToFile(WCHAR* path)
{
	FILE* filestream = NULL;
	_wfopen_s(&filestream, path, L"w");
	if (filestream == NULL)
	{
		return false;
	}
	int maskflag = GetMaskFlag();
	float fMaskScale = GetMaskScale();
	BOOL bMaskFlipY = GetMaskFlipY();

	fwprintf_s(filestream, L"%f %d %d\n", fMaskScale, bMaskFlipY, maskflag);
	
	fclose(filestream);

	return S_OK;
}
HRESULT MaskFilter::LoadFromFile(WCHAR* path)
{
	FILE* filestream = NULL;
	_wfopen_s(&filestream, path, L"r");
	if (filestream == NULL)
	{
		return false;
	}
	int maskflag = 2;
	double fMaskScale = 1.0;
	BOOL bMaskFlipY = FALSE;

	fwscanf_s(filestream, L"%lf %d %d\n", &fMaskScale, &bMaskFlipY, &maskflag);
	
	SetMaskScale(fMaskScale);
	SetMaskFlipY(bMaskFlipY);
	SetMaskFlag(maskflag);
	fclose(filestream);

	return S_OK;
}
HRESULT MaskFilter::GetName(WCHAR* name, UINT szName)
{
	if (name == NULL)
	{
		return S_FALSE;
	}
	FILTER_INFO filterInfo;
	this->QueryFilterInfo(&filterInfo);
	wcscpy_s(name, szName, filterInfo.achName);
	if (filterInfo.pGraph != NULL)
	{
		filterInfo.pGraph->Release();
		filterInfo.pGraph = NULL;
	}
	return S_OK;
}