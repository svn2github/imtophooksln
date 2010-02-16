#include "stdafx.h"
#include "HomoWarpFilter.h"
#include "HomoWarpMFCPropertyPage.h"
#include "HomoWarpFilterApp.h"
#include "cv.h"
#include "MyMediaSample.h"
HomoWarpFilter::HomoWarpFilter(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData)
: CMuxTransformFilter(NAME("HomoWarp Filter"), 0, CLSID_HomoWarpFilter)
{ 
	D3DXMatrixIdentity(&m_matTTS);
	D3DXMatrixIdentity(&m_InvmatTTS);
	m_bFlipY = true;
	m_bInvTTS = false;
}
HomoWarpFilter::~HomoWarpFilter()
{

}

CUnknown *WINAPI HomoWarpFilter::CreateInstance(LPUNKNOWN punk, HRESULT *phr)
{
	ASSERT(phr);
	// assuming we don't want to modify the data
	HomoWarpFilter *pNewObject = new HomoWarpFilter(punk, phr, FALSE);

	if(pNewObject == NULL) {
		if (phr)
			*phr = E_OUTOFMEMORY;
	}
	return pNewObject;
}

HRESULT HomoWarpFilter::NonDelegatingQueryInterface(REFIID iid, void **ppv)
{
	if (iid == IID_IHomoWarpFilter) 
	{
		return GetInterface(static_cast<IHomoWarpFilter*>(this), ppv);
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

HRESULT HomoWarpFilter::ReceiveInput0(IMediaSample *pSample, const IPin* pReceivePin)
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

	hr = InitializeOutputSample(pSample, pReceivePin, GetConnectedOutputPin(), &pOutSample);

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
			hr = GetConnectedOutputPin()->Deliver(pOutSample);// m_pInputPin->Receive(pOutSample);
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

HRESULT HomoWarpFilter::ReceiveInput1(IMediaSample *pSample, const IPin* pReceivePin)
{
	WarpConfigData* pWarpData = NULL;
	pSample->GetPointer((BYTE**)&pWarpData);
	D3DXMATRIX mat;
	for (int row = 0 ; row < 4; row++)
		for (int col =0; col < 4; col++)
			mat.m[row][col] =  pWarpData->warpMat[row][col];

	this->SetWarpMatrix(mat);	
	return S_OK;
}

CMuxTransformOutputPin* HomoWarpFilter::GetConnectedOutputPin()
{
	for (int i =0; i< m_pOutputPins.size(); i++)
	{
		if (m_pOutputPins[i]->IsConnected())
		{
			return m_pOutputPins[i];
		}
	}
	return NULL;
}



HRESULT HomoWarpFilter::Receive(IMediaSample *pSample, const IPin* pReceivePin)
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
HRESULT HomoWarpFilter::CreatePins()
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
			L"config");      // Pin name
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
		CMuxTransformOutputPin* pOutput2 = new CMuxTransformOutputPin(NAME("Transform output pin"),
			this,            // Owner filter
			&hr,             // Result code
			L"d3dsurf");   // Pin name
		if (pOutput2 == NULL) {
			delete pInput0;
			pInput0 = NULL;
			delete pInput1;
			pInput1 = NULL;
			delete pOutput;
			pOutput = NULL;
			return NULL;
		}
		m_pInputPins.push_back(pInput0);
		m_pInputPins.push_back(pInput1);
		m_pOutputPins.push_back(pOutput);
		m_pOutputPins.push_back(pOutput2);
	}
	return S_OK;
}

HRESULT HomoWarpFilter::CheckInputType( const CMediaType * pmt , const IPin* pPin)
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
		if ( !IsEqualGUID(*pmt->Type(), GUID_MyMediaSample) || ! IsEqualGUID(*pmt->Subtype(), GUID_WarpConfig))
		{
			return E_INVALIDARG;
		}
		return NOERROR;
	}
	return E_FAIL;
}

HRESULT HomoWarpFilter::CheckOutputType( const CMediaType * pmt , const IPin* pPin)
{
	if (m_pOutputPins.size() > 0 && m_pOutputPins[0] == pPin)
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
	else if (m_pOutputPins.size() > 1 && m_pOutputPins[1] == pPin)
	{
		CheckPointer(pmt, E_POINTER);
		return NOERROR;
	}
	return E_FAIL;
}

HRESULT HomoWarpFilter::CompleteConnect(PIN_DIRECTION direction, const IPin* pMyPin, const IPin* pOtherPin)
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
	if (direction == PINDIR_OUTPUT && m_pOutputPins.size() > 1)
	{
		for (vector<CMuxTransformOutputPin*>::iterator iter = m_pOutputPins.begin(); iter != m_pOutputPins.end(); iter++)
		{
			if (*iter != pMyPin)
			{
				(*iter)->m_bVisible = false;
			}
		}
		return S_OK;
	}
}

HRESULT HomoWarpFilter::BreakConnect(PIN_DIRECTION dir, const IPin* pPin)
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
HRESULT HomoWarpFilter::Transform( IMediaSample *pIn, IMediaSample *pOut)
{
	HRESULT hr = S_OK;
	if (m_pD3DDisplay != NULL)
	{
		if (m_pInputPins.size() <= 0 || m_pOutputPins.size() <= 0)
		{
			return S_FALSE;
		}
		
		{
			CAutoLock lck(&m_accessWarpMatCS);
			if (m_bInvTTS)
			{
				((HomoD3DDisplay*)m_pD3DDisplay)->SetMatTTS(&m_InvmatTTS);
			}
			else
			{
				((HomoD3DDisplay*)m_pD3DDisplay)->SetMatTTS(&m_matTTS);
			}
		}
		DoTransform(pIn, pOut, &m_pInputPins[0]->CurrentMediaType(), &GetConnectedOutputPin()->CurrentMediaType(), m_bFlipY);
	}
	return S_OK;
}


HRESULT HomoWarpFilter::DecideBufferSize(IMemAllocator *pAlloc, const IPin* pOutPin, ALLOCATOR_PROPERTIES *pProp)
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

	else if (m_pOutputPins.size() >= 2 && m_pOutputPins[1] == pOutPin)
	{
		CMediaType mt = m_pOutputPins[1]->CurrentMediaType();
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


HRESULT HomoWarpFilter::GetMediaType(int iPosition, const IPin* pOutPin, __inout CMediaType *pMediaType)
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
	if (m_pOutputPins.size() > 1 && m_pOutputPins[1] == pOutPin)
	{
		CMediaType mt;
		mt.SetType(&GUID_MyMediaSample);
		mt.SetSubtype(&GUID_D3DXTEXTURE9_POINTER);
		mt.SetSampleSize(sizeof(LPDIRECT3DTEXTURE9));
		D3DSURFACE_DESC desc;
		m_pOutTexture->GetLevelDesc(0, &desc);
		mt.SetFormat((BYTE*)&desc, sizeof(D3DSURFACE_DESC));
		mt.SetFormatType(&GUID_FORMATTYPE_D3DXTEXTURE9DESC);
		*pMediaType = mt;
		return S_OK;
	}
	return VFW_S_NO_MORE_ITEMS;
}


bool HomoWarpFilter::IsAcceptedType(const CMediaType *pmt)
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

HRESULT HomoWarpFilter::GetPages(CAUUID *pPages)
{
	pPages->cElems = 1;
	pPages->pElems = (GUID*)CoTaskMemAlloc(sizeof(GUID));
	if (pPages->pElems == NULL) 
	{
		return E_OUTOFMEMORY;
	}
	pPages->pElems[0] = CLSID_HomoWarpFilterPropertyPage;
	return S_OK;
}

MS3DDisplay* HomoWarpFilter::Create3DDisplay(IDirect3D9* pD3D, int rtWidth, int rtHeight)
{
	return new HomoD3DDisplay(pD3D, rtWidth, rtHeight);
}

MS3DDisplay* HomoWarpFilter::Create3DDisplay(IDirect3DDevice9* pDevice, int rtWidth, int rtHeight)
{
	return new HomoD3DDisplay(pDevice, rtWidth, rtHeight);
}
D3DXMATRIX HomoWarpFilter::ComputeTTS(const D3DXVECTOR2& v1, const D3DXVECTOR2& v2, const D3DXVECTOR2& v3, const D3DXVECTOR2& v4)
{
	WCHAR str[MAX_PATH];
	D3DXMATRIX ret;
	D3DXMatrixIdentity(&ret);
	CvMat cvPt;
	CvMat dstPt;

	float t[] = {0,0,
		0,1,
		1,0,
		1,1};
	float d[] = {v1.x, v1.y,
		v2.x, v2.y,
		v3.x, v3.y,
		v4.x, v4.y};
	float s[] = {0,0,0,
		0,0,0,
		0,0,0};

	cvPt = cvMat( 4, 2, CV_32F, &t);
	dstPt = cvMat(4, 2, CV_32F, &d);
	CvMat mat = cvMat(3,3, CV_32F, &s);
	cvFindHomography(&dstPt, &cvPt, &mat);

	ret._11 = mat.data.fl[0*3 + 0];
	ret._21 = mat.data.fl[0*3 + 1];
	ret._31 = mat.data.fl[0*3 + 2];

	ret._12 = mat.data.fl[1*3 + 0];
	ret._22 = mat.data.fl[1*3 + 1];
	ret._32 = mat.data.fl[1*3 + 2];

	ret._13 = mat.data.fl[2*3 + 0];
	ret._23 = mat.data.fl[2*3 + 1];
	ret._33 = mat.data.fl[2*3 + 2];
	return ret;
}
HRESULT HomoWarpFilter::SetWarpVertex(float LTx, float LTy, float LBx, float LBy, 
							  float RBx, float RBy, float RTx, float RTy)
{
	D3DXVECTOR2 v1(LTx, LTy);
	D3DXVECTOR2 v2(LBx, LBy);
	D3DXVECTOR2 v3(RTx, RTy);
	D3DXVECTOR2 v4(RBx, RBy);
	CAutoLock autolock(&m_accessWarpMatCS);
	m_matTTS = ComputeTTS(v1, v2, v3, v4);
	D3DXMatrixInverse(&m_InvmatTTS, NULL, &m_matTTS);
	return S_OK;
}
HRESULT HomoWarpFilter::GetWarpVertex(float& LTx, float& LTy, float& LBx, float& LBy, 
							  float& RBx, float& RBy, float& RTx, float& RTy)
{
	D3DXVECTOR4 v1(0,0,1,1);
	D3DXVECTOR4 v2(0,1,1,1);
	D3DXVECTOR4 v3(1,0,1,1);
	D3DXVECTOR4 v4(1,1,1,1);
	m_accessWarpMatCS.Lock();
	D3DXMATRIX matInvTTS;
	D3DXMatrixInverse(&matInvTTS, NULL, &m_matTTS);
	m_accessWarpMatCS.Unlock();
	D3DXVec4Transform(&v1, &v1, &matInvTTS);
	D3DXVec4Transform(&v2, &v2, &matInvTTS);
	D3DXVec4Transform(&v3, &v3, &matInvTTS);
	D3DXVec4Transform(&v4, &v4, &matInvTTS);
	v1 /= v1.z; v2 /= v2.z; v3 /= v3.z; v4 /= v4.z;

	LTx = v1.x; LTy = v1.y;
	LBx = v2.x; LBy = v2.y;
	RBx = v4.x; RBy = v4.y;
	RTx = v3.x; RTy = v3.y;
	return S_OK;
}

HRESULT HomoWarpFilter::SetWarpMatrix(const D3DXMATRIX& mat)
{
	CAutoLock autolock(&m_accessWarpMatCS);
	m_matTTS = mat;
	D3DXMatrixInverse(&m_InvmatTTS, NULL, &m_matTTS);
	return S_OK;
}
HRESULT HomoWarpFilter::GetWarpMatrix(D3DXMATRIX& mat)
{
	CAutoLock autolock(&m_accessWarpMatCS);
	mat = m_matTTS;
	D3DXMatrixInverse(&m_InvmatTTS, NULL, &m_matTTS);
	return S_OK;
}

bool HomoWarpFilter::GetIsInvWarp()
{
	return m_bInvTTS;
}
bool HomoWarpFilter::SetIsInvWarp(bool bInv)
{
	m_bInvTTS = bInv;
	return true;
}

bool HomoWarpFilter::SaveConfigToFile(WCHAR* path)
{
	CAutoLock lck(&m_accessWarpMatCS);
	FILE* filestream = NULL;
	_wfopen_s(&filestream, path, L"w");
	if (filestream == NULL)
	{
		return false;
	}
	fwprintf_s(filestream, L"%f %f %f %f \n \
							%f %f %f %f \n \
							%f %f %f %f \n \
							%f %f %f %f \n", 
							m_matTTS.m[0][0], m_matTTS.m[0][1], m_matTTS.m[0][2], m_matTTS.m[0][3],
							m_matTTS.m[1][0], m_matTTS.m[1][1], m_matTTS.m[1][2], m_matTTS.m[1][3],
							m_matTTS.m[2][0], m_matTTS.m[2][1], m_matTTS.m[2][2], m_matTTS.m[2][3],
							m_matTTS.m[3][0], m_matTTS.m[3][1], m_matTTS.m[3][2], m_matTTS.m[3][3]);
	bool isFlipY = this->GetIsFlipY();
	bool isInvWarp = this->GetIsInvWarp();
	
	fwprintf_s(filestream, L"%d %d \n", isFlipY, isInvWarp);
	fclose(filestream);
	return true;
}
bool HomoWarpFilter::LoadConfigFromFile(WCHAR* path)
{
	try
	{
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
		{
			CAutoLock lck(&m_accessWarpMatCS);
			for (int row=0; row < 4; row++)
			{
				for (int col = 0; col < 4; col++)
				{
					m_matTTS.m[row][col] = mat[row*4 + col];
				}
			}
		}
		m_bFlipY = isFlipY;
		m_bInvTTS = isInvWarp;

		fclose(filestream);
		D3DXMatrixInverse(&m_InvmatTTS, NULL, &m_matTTS);
	}
	catch (exception e)
	{
		return false;
	}
	return true;
}
LPDIRECT3DTEXTURE9 HomoWarpFilter::GetInTexture()
{
	return m_pInTexture;
}
CCritSec* HomoWarpFilter::GetCSInTexture()
{
	return &m_csInTexture;
}