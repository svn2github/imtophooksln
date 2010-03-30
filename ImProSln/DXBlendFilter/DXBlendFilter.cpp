#include "stdafx.h"
#include "DXBlendFilter.h"
#include "DXBlendFilterProp.h"
#include "DXBlendFilterApp.h"
#include "cv.h"
#include "MyMediaSample.h"
DXBlendFilter::DXBlendFilter(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData)
: CMuxTransformFilter(NAME("DXBlend Filter"), 0, CLSID_DXBlendFilter)
{ 
	for (int i = 0; i < NUMINPUT; i++)
	{
		m_InputDirty[i] = FALSE;
	}
	memset(m_pInTextureList, 0, sizeof(m_pInTextureList));
	
}
DXBlendFilter::~DXBlendFilter()
{
	for (int i =0; i < NUMINPUT; i++)
	{
		if (m_pInTextureList[i] != NULL)
		{
			m_pInTextureList[i]->Release();
			m_pInTextureList[i] = NULL;
		}
	}
}

CUnknown *WINAPI DXBlendFilter::CreateInstance(LPUNKNOWN punk, HRESULT *phr)
{
	ASSERT(phr);
	// assuming we don't want to modify the data
	DXBlendFilter *pNewObject = new DXBlendFilter(punk, phr, FALSE);

	if(pNewObject == NULL) {
		if (phr)
			*phr = E_OUTOFMEMORY;
	}
	return pNewObject;
}

HRESULT DXBlendFilter::NonDelegatingQueryInterface(REFIID iid, void **ppv)
{
	if (iid == IID_IDXBlendFilter) 
	{
		return GetInterface(static_cast<IDXBlendFilter*>(this), ppv);
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

HRESULT DXBlendFilter::Receive(IMediaSample *pSample, const IPin* pReceivePin)
{
	if (m_pStreamPins.size() < 1 || m_pStreamPins[0]->IsConnected() == FALSE)
	{
		return S_FALSE;
	}
	int idx = -1;
	for (int i =0; i < m_pInputPins.size(); i++)
	{
		if (pReceivePin == m_pInputPins[i])
		{
			idx = i;
		}
	}
	if (idx < 0 )
	{
		return S_FALSE;
	}
	if (GetInputDirty(idx))
	{
		//m_FillBufferEndSignal.Wait(1000);
	}
	//WCHAR str[MAX_PATH] = {0};

	HRESULT hr = S_OK;
	CMediaType mt = ((CMuxTransformInputPin*)pReceivePin)->CurrentMediaType();

	{
		CAutoLock lck0(&m_csInTextureList[idx]);
		//swprintf_s(str, MAX_PATH, L"@@@@@ Receive %d ---->\n", idx);
		//OutputDebugStringW(str);
		hr = CopyInputImage2InputTexture(idx, pSample, &mt);
		if (SUCCEEDED(hr))
		{
			SetInputDirty(idx, TRUE);
		}
		//swprintf_s(str, MAX_PATH, L"@@@@@ Receive %d <----\n", idx);
		//OutputDebugStringW(str);
	}

	return S_OK;


}
HRESULT DXBlendFilter::CreatePins()
{
	HRESULT hr = S_OK;
	if (m_pInputPins.size() < NUMINPUT || m_pStreamPins.size() < 1) {
		for (int c = 0; c< m_pInputPins.size(); c++)
		{
			delete m_pInputPins[c];
			m_pInputPins[c] = NULL;
		}
		m_pInputPins.clear();
		for (int c = 0; c< m_pStreamPins.size(); c++)
		{
			delete m_pStreamPins[c];
			m_pStreamPins[c] = NULL;
		}
		m_pStreamPins.clear();

		WCHAR str[MAX_PATH] = {0};
		for (int i =0; i < NUMINPUT; i++)
		{
			swprintf_s(str, MAX_PATH, L"input%d", i);
			CMuxTransformInputPin* pInput = new CMuxTransformInputPin(NAME("DXBlend input pin"),
				this,              // Owner filter
				&hr,               // Result code
				str);      // Pin name
			m_pInputPins.push_back(pInput);
		
		}

		CMuxTransformStream* pOutput = new CMuxTransformStream(NAME("DXBlend output pin"),
			&hr, 
			this,              
			L"output");   
		
		m_pStreamPins.push_back(pOutput);
	}
	return S_OK;
}

HRESULT DXBlendFilter::CheckInputType( const CMediaType * pmt , const IPin* pPin)
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
	

	return E_FAIL;
}

HRESULT DXBlendFilter::CheckOutputType( const CMediaType * pmt , const IPin* pPin)
{
	if (m_pStreamPins.size() > 0 && m_pStreamPins[0] == pPin)
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
		if (*pmt->Type() == GUID_D3DMEDIATYPE && *pmt->Subtype() == GUID_D3DSHARE_RTTEXTURE_POINTER)
		{
			return NOERROR;
		}
	}
	return E_FAIL;
}

HRESULT DXBlendFilter::CompleteConnect(PIN_DIRECTION direction, const IPin* pMyPin, const IPin* pOtherPin)
{
	HRESULT hr = S_OK;
	int w =0, h = 0;
	if (direction == PINDIR_INPUT && m_pInputPins.size() > 0 && m_pInputPins[0] == pMyPin)
	{
		CMediaType inputMT = ((CMuxTransformInputPin*)pMyPin)->CurrentMediaType();
		if (IsEqualGUID(*inputMT.Type(), GUID_D3DMEDIATYPE) && 
			IsEqualGUID(*inputMT.Subtype(), GUID_D3DXTEXTURE9_POINTER))
		{
			D3DSURFACE_DESC* desc = (D3DSURFACE_DESC*)inputMT.pbFormat;
			w = desc->Width; h = desc->Height;
			initD3D(desc->Width, desc->Height);	
		}
		else if (IsEqualGUID(*inputMT.Type(), GUID_D3DMEDIATYPE) && 
			IsEqualGUID(*inputMT.Subtype(), GUID_D3DSHARE_RTTEXTURE_POINTER))
		{
			D3DSURFACE_DESC* desc = (D3DSURFACE_DESC*)inputMT.pbFormat;
			IDirect3DDevice9* pDevice = NULL;
			m_pInputPins[0]->QueryD3DDevice(pDevice);
			if (pDevice == NULL)
				return S_FALSE;
			w = desc->Width; h = desc->Height;
			initD3D(desc->Width, desc->Height, pDevice);
			pDevice->Release();
			pDevice = NULL;	
		}
		else
		{
			VIDEOINFOHEADER *pvi = (VIDEOINFOHEADER *) inputMT.pbFormat;
			BITMAPINFOHEADER bitHeader = pvi->bmiHeader;
			w = bitHeader.biWidth; h = bitHeader.biHeight;
			initD3D(bitHeader.biWidth, bitHeader.biHeight);
		}
	}
	if (direction == PINDIR_INPUT)
	{
		if (m_pD3DDisplay == NULL)
		{
			return E_FAIL;
		}
		int idx = -1;
		for (int i =0; i < m_pInputPins.size(); i++)
		{
			if (m_pInputPins[i] == pMyPin)
			{
				idx = i;
				break;
			}
		}
		if (idx < 0 )
		{
			return E_FAIL;
		}
		CreateInTexture(idx, w, h);
	}
	return S_OK;
}

HRESULT DXBlendFilter::BreakConnect(PIN_DIRECTION dir, const IPin* pPin)
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

HRESULT DXBlendFilter::DecideBufferSize(IMemAllocator *pAlloc, const IPin* pOutPin, ALLOCATOR_PROPERTIES *pProp)
{
	HRESULT hr = NOERROR;
	if (m_pInputPins.size() <= 0)
	{
		return S_FALSE;
	}

	if (m_pStreamPins.size() > 0 && m_pStreamPins[0] == pOutPin )
	{
		CMediaType mt =m_pStreamPins[0]->CurrentMediaType();

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


HRESULT DXBlendFilter::GetMediaType(int iPosition, const IPin* pOutPin, __inout CMediaType *pMediaType)
{
	if (m_pInputPins.size() <= 0)
	{
		return S_FALSE;
	}
	if (m_pStreamPins.size() > 0 && m_pStreamPins[0] == pOutPin)
	{
		if (m_pOutTexture == NULL)
			return S_FALSE;
		if (iPosition == 0)
		{
			CMediaType mt;
			mt.SetType(&GUID_D3DMEDIATYPE);
			mt.SetSubtype(&GUID_D3DSHARE_RTTEXTURE_POINTER);
			mt.SetSampleSize(sizeof(LPDIRECT3DTEXTURE9));
			D3DSURFACE_DESC desc;
			if (m_pRenderTarget == NULL)
				return S_FALSE;
			m_pRenderTarget->GetLevelDesc(0, &desc);
			mt.SetFormat((BYTE*)&desc, sizeof(D3DSURFACE_DESC));
			mt.SetFormatType(&GUID_FORMATTYPE_D3DXTEXTURE9DESC);
			*pMediaType = mt;
			return S_OK;
		}
		else if (iPosition == 1)
		{
			CMediaType mt;
			mt.SetType(&GUID_D3DMEDIATYPE);
			mt.SetSubtype(&GUID_D3DXTEXTURE9_POINTER);
			mt.SetSampleSize(sizeof(LPDIRECT3DTEXTURE9));
			D3DSURFACE_DESC desc;
			if (m_pOutTexture == NULL)
				return S_FALSE;
			m_pOutTexture->GetLevelDesc(0, &desc);
			mt.SetFormat((BYTE*)&desc, sizeof(D3DSURFACE_DESC));
			mt.SetFormatType(&GUID_FORMATTYPE_D3DXTEXTURE9DESC);
			*pMediaType = mt;
			return S_OK;
		}
		else if (iPosition == 2)
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
		
	}
	
	return VFW_S_NO_MORE_ITEMS;
}


bool DXBlendFilter::IsAcceptedType(const CMediaType *pmt)
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
	else if (IsEqualGUID(*pmt->Type(), GUID_D3DMEDIATYPE) && 
		IsEqualGUID(guidSubType, GUID_D3DXTEXTURE9_POINTER))
	{
		return true;
	}

	return false;
}

HRESULT DXBlendFilter::GetPages(CAUUID *pPages)
{
	pPages->cElems = 1;
	pPages->pElems = (GUID*)CoTaskMemAlloc(sizeof(GUID));
	if (pPages->pElems == NULL) 
	{
		return E_OUTOFMEMORY;
	}
	pPages->pElems[0] = CLSID_DXBlendFilterProp;
	return S_OK;
}

MS3DDisplay* DXBlendFilter::Create3DDisplay(IDirect3D9* pD3D, int rtWidth, int rtHeight)
{
	return new DXBlendDisplay(pD3D, rtWidth, rtHeight);
}

MS3DDisplay* DXBlendFilter::Create3DDisplay(IDirect3DDevice9* pDevice, int rtWidth, int rtHeight)
{
	return new DXBlendDisplay(pDevice, rtWidth, rtHeight);
}
HRESULT DXBlendFilter::SaveToFile(WCHAR* path)
{
	return S_OK;
}
HRESULT DXBlendFilter::LoadFromFile(WCHAR* path)
{
	return S_OK;
}

HRESULT DXBlendFilter::GetName(WCHAR* name, UINT szName)
{
	if (name == NULL)
		return S_FALSE;
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

HRESULT DXBlendFilter::QueryD3DDevice(IDXBasePin* pPin, IDirect3DDevice9*& outDevice)
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

HRESULT DXBlendFilter::QueryD3DDeviceCS(IDXBasePin* pPin, CCritSec*& cs)
{
	if (m_pD3DDisplay == NULL || m_pInputPins.size() <= 0 || m_pInputPins[0] == NULL)
		return S_FALSE;
	if (m_pD3DDisplay->IsDeviceFromOther())
	{
		IDXBasePin* pDXInPin = NULL;
		m_pInputPins[0]->QueryInterface(IID_IDXBasePin, (void**)&pDXInPin);
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

HRESULT DXBlendFilter::CreateInTexture(int idx, UINT w, UINT h)
{
	if (idx < 0 || idx >= NUMINPUT || m_pD3DDisplay == NULL)
	{
		return E_FAIL;
	}
	if ( w <= 0 || h <= 0)
	{
		return E_FAIL;
	}
	HRESULT hr = S_FALSE;
	CAutoLock lck(&m_csInTextureList[idx]);
	if (m_pInTextureList[idx] != NULL)
	{
		m_pInTextureList[idx]->Release();
		m_pInTextureList[idx] = NULL;
	}
	hr=	D3DXCreateTexture(m_pD3DDisplay->GetD3DDevice(), w, h, 
		0,  0, D3DFMT_X8R8G8B8, D3DPOOL_MANAGED, &m_pInTextureList[idx]);
	return hr;
}	

HRESULT DXBlendFilter::CopyInputImage2InputTexture(int idx, IMediaSample *pIn, const CMediaType* pInMediaType, bool bFlipY)
{
	if (idx < 0 || idx >= NUMINPUT)
	{
		return E_FAIL;
	}
	CAutoLock lck(&m_csInTextureList[idx]);

	LPDIRECT3DTEXTURE9 pInTexture = m_pInTextureList[idx];
	if (pIn == NULL || pInMediaType == NULL || pInTexture == NULL)
	{
		return S_FALSE;
	}
	HRESULT hr = S_OK;

	IDirect3DDevice9* pDevice = m_pD3DDisplay->GetD3DDevice();
	GUID guidSubType = pInMediaType->subtype;

	LPDIRECT3DSURFACE9 pInSurface = NULL;
	D3DSURFACE_DESC surInDesc;
	pInTexture->GetLevelDesc(0, &surInDesc);

	IplImage* pImg = NULL;
	if (IsEqualGUID(*pInMediaType->Type(), GUID_D3DMEDIATYPE) && IsEqualGUID(guidSubType, GUID_D3DSHARE_RTTEXTURE_POINTER))
	{
		LPDIRECT3DTEXTURE9 pInputTexture = NULL;
		pIn->GetPointer((BYTE**)&pInputTexture);
		if (pInputTexture == NULL)
		{
			return E_FAIL;
		}
		if (pInTexture != NULL)
		{
			pInTexture->Release();
			pInTexture = NULL;
		}
		pInTexture = pInputTexture;
		pInTexture->AddRef();
	}
	else if (IsEqualGUID(*pInMediaType->Type(), GUID_D3DMEDIATYPE) && IsEqualGUID(guidSubType, GUID_D3DXTEXTURE9_POINTER))
	{
		pInTexture->GetSurfaceLevel(0, &pInSurface);
		LPDIRECT3DTEXTURE9 pInputTexture = NULL;
		LPDIRECT3DSURFACE9 pInputSurface = NULL;
		D3DSURFACE_DESC inputDesc;
		pIn->GetPointer((BYTE**)&pInputTexture);
		if (pInputTexture == NULL)
		{
			return E_FAIL;
		}
		hr = pInputTexture->GetSurfaceLevel(0, &pInputSurface);
		pInputSurface->GetDesc(&inputDesc);

		DWORD filterFlag = D3DX_FILTER_POINT;

		hr = D3DXLoadSurfaceFromSurface(pInSurface, NULL, NULL, pInputSurface, NULL, NULL,
			filterFlag, 0);

		if (pInputSurface != NULL)
		{
			pInputSurface->Release();
			pInputSurface = NULL;
		}
	}
	else
	{
		pInTexture->GetSurfaceLevel(0, &pInSurface);
		BYTE* pInData = NULL;
		hr = pIn->GetPointer(&pInData);
		if (FAILED(hr))
			return hr;
		VIDEOINFOHEADER *pvi = (VIDEOINFOHEADER *) pInMediaType->pbFormat;
		BITMAPINFOHEADER bitHeader = pvi->bmiHeader;
		RECT rect;
		rect.left = 0;
		rect.right = bitHeader.biWidth;
		rect.top = 0;
		rect.bottom = bitHeader.biHeight;
		if (IsEqualGUID(guidSubType, MEDIASUBTYPE_RGB24))
		{
			hr = D3DXLoadSurfaceFromMemory(pInSurface, NULL, NULL, pInData, D3DFMT_R8G8B8, bitHeader.biWidth * 3, NULL, &rect, D3DX_FILTER_POINT, NULL);
		}
		else if (IsEqualGUID(guidSubType, MEDIASUBTYPE_ARGB32) || IsEqualGUID(guidSubType, MEDIASUBTYPE_RGB32) )
		{
			hr = D3DXLoadSurfaceFromMemory(pInSurface, NULL, NULL, pInData, D3DFMT_A8R8G8B8, bitHeader.biWidth * 4, NULL, &rect, D3DX_FILTER_POINT, NULL);
		}
		else
		{
			hr = E_FAIL;
		}
	}
	if (bFlipY && !IsEqualGUID(guidSubType, GUID_D3DSHARE_RTTEXTURE_POINTER))
	{
		D3DLOCKED_RECT surRect;
		pInSurface->LockRect(&surRect, NULL, 0);
		pImg = cvCreateImageHeader(cvSize(surInDesc.Width, surInDesc.Height), 8, 4);
		pImg->imageData = (char*)surRect.pBits;
		cvFlip(pImg, NULL, 0);
		pInSurface->UnlockRect();
	}
	if ( pInSurface != NULL)
	{
		pInSurface->Release();
		pInSurface = NULL;
	}
	if (pImg != NULL)
	{
		cvReleaseImageHeader(&pImg);
	}
	return S_OK;
}

BOOL DXBlendFilter::GetInputDirty(int idx)
{
	if (idx < 0 || idx >= NUMINPUT)
		return FALSE;
	CAutoLock lck(&m_csInputDirty[idx]);
	return m_InputDirty[idx];
}
BOOL DXBlendFilter::SetInputDirty(int idx, BOOL v)
{
	if (idx < 0 || idx >= NUMINPUT)
		return FALSE;
	CAutoLock lck(&m_csInputDirty[idx]);
	m_InputDirty[idx] = v; 
	return TRUE;
}

HRESULT DXBlendFilter::FillBuffer(IMediaSample *pSamp, IPin* pPin)
{
	BOOL isDirty = FALSE;
	CAutoLock lck0(&m_csInTextureList[0]);
	CAutoLock lck1(&m_csInTextureList[1]);
	CAutoLock lck2(&m_csInTextureList[2]);
	CAutoLock lck3(&m_csInTextureList[3]);
	/*for (int i =0; i < NUMINPUT; i++)
	{
		if (m_pInputPins[i]->IsConnected() && GetInputDirty(i))
		{
			isDirty = TRUE;
			break;
		}
	}
	if (isDirty == FALSE)
	{	
		//return S_FALSE;
	}*/


	//WCHAR str[MAX_PATH] = {0};
	//swprintf_s(str, MAX_PATH, L"@@@@@ FillBuffer ---->\n");
	//OutputDebugStringW(str);

	HRESULT hr = S_OK;
	{
		CCritSec* pD3DCS = NULL;
		QueryD3DDeviceCS(NULL, pD3DCS);
		if (pD3DCS == NULL)
			return S_FALSE;
		CAutoLock lck(pD3DCS);

		hr = SetRenderTarget();
		if (FAILED(hr))
			return S_FALSE;
		m_pD3DDisplay->SetTexture(m_pInTextureList[0]);
		((DXBlendDisplay*)m_pD3DDisplay)->Render();
		m_pD3DDisplay->SetTexture(NULL);
		hr = ResetRenderTarget();
	}

	CMediaType mt = ((CMuxTransformStream*)pPin)->CurrentMediaType();
	if (IsEqualGUID(*mt.Subtype(), GUID_D3DSHARE_RTTEXTURE_POINTER))
	{
		hr = CopyRenderTarget2OutputData(pSamp, &mt);	
	}
	else
	{
		hr = CopyRenderTarget2OutputTexture();	
		if (FAILED(hr))
			return S_FALSE;
		hr = CopyOutputTexture2OutputData(pSamp, &mt, true);
	}
	/*for (int i =0; i < NUMINPUT; i++)
	{
		SetInputDirty(i, FALSE);
	}
	swprintf_s(str, MAX_PATH, L"@@@@@ FillBuffer <----\n");
	OutputDebugStringW(str);
	*/
	m_FillBufferEndSignal.Set();
	return S_OK;
}
