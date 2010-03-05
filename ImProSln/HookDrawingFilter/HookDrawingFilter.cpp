#include "stdafx.h"
#include "HookDrawingFilter.h"
#include "HookDrawingFilterApp.h"
#include "MyMediaSample.h"
#include "HookDrawingDisplay.h"
#include "HookDrawingProp.h"
#include "..\\HookInject\IHookInject.h"
#include "cv.h"
#include "IHookDrawingStream.h"
#include "HookDrawingStreamProp.h"
HookDrawingFilter* g_Instance = NULL;

static UINT HOOKED_WNDDESTORY = ::RegisterWindowMessage(HOOKED_WNDDESTORY_MSG);
static UINT HOOKED_BITBLTCALLED = ::RegisterWindowMessage(HOOKED_BITBLTCALLED_MSG);

HookDrawingStream::HookDrawingStream(LPCTSTR pObjectName, HRESULT *phr,
									 CMuxTransformFilter *pms, LPCWSTR pName) :
CMuxTransformStream(pObjectName, phr, pms, pName)
{
	D3DXMatrixIdentity(&m_matTTS);
}
#ifdef UNICODE
HookDrawingStream::HookDrawingStream( LPCSTR pObjectName, HRESULT *phr,
									 CMuxTransformFilter *pms, LPCWSTR pName) :
				  CMuxTransformStream(pObjectName, phr, pms, pName)
{
	D3DXMatrixIdentity(&m_matTTS);
}
#endif
HookDrawingStream::~HookDrawingStream(void)
{

}

const D3DXMATRIX* HookDrawingStream::GetWarpMatrix()
{
	CAutoLock lck(&m_csMatTTS);
	return &m_matTTS;
}
BOOL HookDrawingStream::SetWarpMatrix(const D3DXMATRIX& mat)
{
	CAutoLock lck(&m_csMatTTS);
	m_matTTS = mat;
	return TRUE;
}
BOOL HookDrawingStream::SetWarpByPts(const D3DXVECTOR2& lt, const D3DXVECTOR2& lb,
				  const D3DXVECTOR2& rb, const D3DXVECTOR2& rt)
{
	
	WCHAR str[MAX_PATH];
	D3DXMatrixIdentity(&m_matTTS);
	CvMat cvPt;
	CvMat dstPt;
	float t[] = {0,0,
		0,1,
		1,1,
		1,0};
	float d[] = {lt.x, lt.y,
		lb.x, lb.y,
		rb.x, rb.y,
		rt.x, rt.y};
	float s[] = {0,0,0,
		0,0,0,
		0,0,0};

	cvPt = cvMat( 4, 2, CV_32F, &t);
	dstPt = cvMat(4, 2, CV_32F, &d);
	CvMat mat = cvMat(3,3, CV_32F, &s);
	cvFindHomography(&cvPt, &dstPt, &mat);
	CAutoLock lck(&m_csMatTTS);
	m_matTTS._11 = mat.data.fl[0*3 + 0];
	m_matTTS._21 = mat.data.fl[0*3 + 1];
	m_matTTS._31 = mat.data.fl[0*3 + 2];

	m_matTTS._12 = mat.data.fl[1*3 + 0];
	m_matTTS._22 = mat.data.fl[1*3 + 1];
	m_matTTS._32 = mat.data.fl[1*3 + 2];

	m_matTTS._13 = mat.data.fl[2*3 + 0];
	m_matTTS._23 = mat.data.fl[2*3 + 1];
	m_matTTS._33 = mat.data.fl[2*3 + 2];

	return TRUE;
}
BOOL HookDrawingStream::GetWarpPts(D3DXVECTOR2& lt, D3DXVECTOR2& lb, D3DXVECTOR2& rb, 
				D3DXVECTOR2& rt)
{
	CAutoLock lck(&m_csMatTTS);
	D3DXVECTOR4 v1(0,0,1,1);
	D3DXVECTOR4 v2(0,1,1,1);
	D3DXVECTOR4 v3(1,1,1,1);
	D3DXVECTOR4 v4(1,0,1,1);

	D3DXVec4Transform(&v1, &v1, &m_matTTS);
	D3DXVec4Transform(&v2, &v2, &m_matTTS);
	D3DXVec4Transform(&v3, &v3, &m_matTTS);
	D3DXVec4Transform(&v4, &v4, &m_matTTS);
	v1 /= v1.z; v2 /= v2.z; v3 /= v3.z; v4 /= v4.z;
	lt.x = v1.x; lt.y = v1.y;
	lb.x = v2.x; lb.y = v2.y;
	rb.x = v3.x; rb.y = v3.y;
	rt.x = v4.x; rt.y = v4.y;

	return TRUE;
}
BOOL HookDrawingStream::GetResolution(UINT& resW, UINT& resH)
{
	if (m_pFilter == NULL)
		return FALSE;
	return ((HookDrawingFilter*)m_pFilter)->GetResolution(this, resW, resH);
}
BOOL HookDrawingStream::SetResolution(UINT resW, UINT resH)
{
	if (m_pFilter == NULL)
		return FALSE;
	return ((HookDrawingFilter*)m_pFilter)->SetResolution(this, resW, resH);
}

STDMETHODIMP HookDrawingStream::GetPages(CAUUID *pPages)
{
	pPages->cElems = 1;
	pPages->pElems = (GUID*)CoTaskMemAlloc(sizeof(GUID));
	if (pPages->pElems == NULL) 
	{
		return E_OUTOFMEMORY;
	}
	pPages->pElems[0] = CLSID_HookDrawingStreamPropPage;
	return S_OK;
}

HRESULT HookDrawingStream::NonDelegatingQueryInterface(REFIID iid, void **ppv)
{
	if (iid == IID_IHookDrawingStream) 
	{
		return GetInterface(static_cast<IHookDrawingStream*>(this), ppv);
	}
	else if (iid == IID_ISpecifyPropertyPages)
	{
		return GetInterface(
			static_cast<ISpecifyPropertyPages*>(this),	ppv);
	}
	else
	{
		// Call the parent class.
		return __super::NonDelegatingQueryInterface(iid, ppv);
	}
}




HookDrawingFilter::HookDrawingFilter(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData)
: CMuxTransformFilter(NAME("HookDrawing Filter"), 0, CLSID_HookDrawingFilter)
{
	m_hHookedWnd = 0;
	m_hHookRecMsgWnd = 0;
	RegisterHookWndClass(GetModule());

}
HookDrawingFilter::~HookDrawingFilter()
{
	if (m_hHookedWnd != NULL)
	{
		::PostMessageW(m_hHookedWnd, WM_CLOSE, NULL, NULL);
	}
	if (m_hHookRecMsgWnd != 0)
	{
		::DestroyWindow(m_hHookRecMsgWnd);
		m_hHookRecMsgWnd = 0;
	}
	g_Instance = NULL;
	for (int i =0; i< m_pAddOutTexture.size(); i++)
	{
		m_pAddOutTexture[i]->Release();
		m_pAddOutTexture[i] = NULL;
	}
	m_pAddOutTexture.clear();
	for (int i =0; i < m_pAddRenderTarget.size(); i++)
	{
		m_pAddRenderTarget[i]->Release();
		m_pAddRenderTarget[i] = NULL;
	}
	m_pAddRenderTarget.clear();
}

CUnknown *WINAPI HookDrawingFilter::CreateInstance(LPUNKNOWN punk, HRESULT *phr)
{
	ASSERT(phr);
	//only allow one instance;
	if (g_Instance != NULL)
	{
		*phr = S_FALSE;
		return NULL;
	}
	HookDrawingFilter *pNewObject = new HookDrawingFilter(punk, phr, FALSE);

	if(pNewObject == NULL) {
		if (phr)
			*phr = E_OUTOFMEMORY;
	}
	g_Instance = pNewObject;
	return pNewObject;
}

HRESULT HookDrawingFilter::NonDelegatingQueryInterface(REFIID iid, void **ppv)
{
	if (iid == IID_IHookDrawingFilter) 
	{
		return GetInterface(static_cast<IHookDrawingFilter*>(this), ppv);
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

HRESULT HookDrawingFilter::CreatePins()
{
	HRESULT hr = S_OK;
	if (m_pStreamPins.size() < 1) {
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
		for (int c = 0; c< m_pStreamPins.size(); c++)
		{
			delete m_pStreamPins[c];
			m_pStreamPins[c] = NULL;
		}
		m_pStreamPins.clear();
		for ( int i =0; i < NUMHOOKPIN; i++)
		{
			WCHAR strPinName[MAX_PATH];
			swprintf_s(strPinName, MAX_PATH, L"d3dsurf%d", i);
			CMuxTransformStream* pOutput0 = new HookDrawingStream(NAME("CMuxTransform stream pin"),
				&hr,              // Owner filter
				this,               // Result code
				strPinName);      // Pin name
		
			m_pStreamPins.push_back(pOutput0);
		}
		if (m_pD3DDisplay == NULL)
		{
			CreateHookWindow(320, 240); // size doesn't matter
			HRESULT hr = initD3D(2048, 768);
			if (SUCCEEDED(hr))
			{
				HOOKINJECT::SetHookServer(m_hHookRecMsgWnd);
				HOOKINJECT::SetHookServerProcID(GetCurrentProcessId());
			}
		}
	}
	
	return S_OK;
}
HRESULT HookDrawingFilter::FillBuffer(IMediaSample *pSamp, IPin* pPin)
{
	int idx = -1;
	for(int i =0; i< m_pStreamPins.size(); i++)
	{
		if (pPin == m_pStreamPins[i])
		{
			idx = i;
			break;
		}
	}
	if (idx < 0 || idx >= m_pStreamPins.size())
	{
		return S_FALSE;
	}
	HRESULT hr = S_OK;
	
	CAutoLock lck(&m_csFillBuffer);
	
	WCHAR str[MAX_PATH] = {0};
	swprintf_s(str, MAX_PATH, L"@@@@@@ FillBuffer %d  ---> \n", idx);
	OutputDebugStringW(str);
	if (GetHookDirty(idx))
	{
		{
			CAutoLock lck0(&m_csD3DDisplay);
			CAutoLock lck(&m_csInTexture);
			SetRenderTarget(idx);
			const D3DXMATRIX* matTTS = ((HookDrawingStream*)pPin)->GetWarpMatrix();
			((HookDrawingDisplay*)m_pD3DDisplay)->SetMatTTS(matTTS);

			m_pD3DDisplay->SetTexture(m_pInTexture);
			m_pD3DDisplay->Render();
			ResetRenderTarget();
		}
		//swprintf_s(str, MAX_PATH, L"@@@@@@ CopyRenderTarget2OutputTexture %d--->\n", idx);
		//OutputDebugStringW(str);
		CopyRenderTarget2OutputTexture(idx);	
		//swprintf_s(str, MAX_PATH, L"@@@@@@ CopyRenderTarget2OutputTexture %d--->\n", idx);
		//OutputDebugStringW(str);
		/*
		//swprintf_s(str, MAX_PATH, L"@@@@@@ CopyInTexture2OutTexture %d--->\n", idx);
		//OutputDebugStringW(str);
		CopyInTexture2OutTexture(idx);
		//swprintf_s(str, MAX_PATH, L"@@@@@@ CopyInTexture2OutTexture %d<---\n", idx);
		//OutputDebugStringW(str);
		*/
		SetHookDirty(idx, FALSE);
	}
	CMediaType mt;
	mt = ((CMuxTransformStream*)pPin)->CurrentMediaType();

	//swprintf_s(str, MAX_PATH, L"@@@@@@  CopyOutputTexture2OutputData %d --->\n", idx);
	//OutputDebugStringW(str);
	CopyOutputTexture2OutputData(idx, pSamp, &mt, true);
	//swprintf_s(str, MAX_PATH, L"@@@@@@  CopyOutputTexture2OutputData %d <---\n", idx);
	//OutputDebugStringW(str);
	//swprintf_s(str, MAX_PATH, L"@@@@@@ FillBuffer %d  <--- \n", idx);
	//OutputDebugStringW(str);
	
	return S_OK;
}

HRESULT HookDrawingFilter::CopyRenderTarget2OutputTexture(int idx)
{
	HRESULT hr;
	if (m_pD3DDisplay == NULL || m_pAddOutTexture.size() <= idx || m_pAddRenderTarget.size() <= idx ||
		m_pAddOutTexture[idx] == NULL || m_pAddRenderTarget[idx] == NULL)
		return S_FALSE;
	if (FAILED(TestDisplayDeviceLost()))
		return S_FALSE;
	CAutoLock lck1(&m_csAddTextures[idx]);
	IDirect3DDevice9* pDevice = m_pD3DDisplay->GetD3DDevice();

	LPDIRECT3DSURFACE9 pOutSurface = NULL;
	LPDIRECT3DSURFACE9 pRenderTarget = NULL;
	D3DSURFACE_DESC surRenderDesc, surOutDesc;
	m_pAddOutTexture[idx]->GetSurfaceLevel(0, &pOutSurface);
	m_pAddRenderTarget[idx]->GetSurfaceLevel(0, &pRenderTarget);
	pRenderTarget->AddRef();
	pRenderTarget->GetDesc(&surRenderDesc);
	pOutSurface->GetDesc(&surOutDesc);

	hr = pDevice->GetRenderTargetData(pRenderTarget, pOutSurface);
	//D3DCAPS9 cap;
	//pDevice->GetDeviceCaps(&cap);
	/*if (cap.DevCaps2 & D3DDEVCAPS2_STREAMOFFSET)
	{
		hr = pDevice->StretchRect(pRenderTarget, NULL, pOutSurface, NULL, D3DTEXF_NONE);
	}*/
	/*HDC rtDC = 0, outDC = 0;
	hr = pRenderTarget->GetDC(&rtDC);
	hr = pOutSurface->GetDC(&outDC);
	StretchBlt(outDC, 0, 0, surOutDesc.Width, surOutDesc.Height, 
		rtDC, 0, 0, surRenderDesc.Width, surRenderDesc.Height, SRCCOPY);*/
	

	if (pOutSurface != NULL)
	{
		//pOutSurface->ReleaseDC(outDC);
		pOutSurface->Release();
		pOutSurface = NULL;
	}
	if (pRenderTarget != NULL)
	{
		//pRenderTarget->ReleaseDC(rtDC);
		pRenderTarget->Release();
		pRenderTarget = NULL;
	}
	
	return S_OK;
}
HRESULT HookDrawingFilter::GetMediaType(int iPosition, const IPin* pPin, __inout CMediaType *pMediaType)
{
	bool isStreamPin = false;
	for (int i =0; i <m_pStreamPins.size(); i++)
	{
		if (m_pStreamPins[i] == pPin)
		{
			if (iPosition == 1)
			{
				if (m_pOutTexture == NULL)
					return S_FALSE;
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
			else if (iPosition == 0)
			{
				CAutoLock lck(&m_csAddTextures[i]);
				CMediaType mt;
				mt.SetType(&GUID_MyMediaSample);
				mt.SetSubtype(&GUID_D3DXTEXTURE9_POINTER);
				mt.SetSampleSize(sizeof(LPDIRECT3DTEXTURE9));
				D3DSURFACE_DESC desc;
				m_pAddOutTexture[i]->GetLevelDesc(0, &desc);
				mt.SetFormat((BYTE*)&desc, sizeof(D3DSURFACE_DESC));
				mt.SetFormatType(&GUID_FORMATTYPE_D3DXTEXTURE9DESC);
				*pMediaType = mt;
				return S_OK;
			}
		}
		
	}

	return S_FALSE;
}
HRESULT HookDrawingFilter::CheckOutputType(const CMediaType* mtOut, const IPin* pPin)
{
	bool isStreamPin = false;
	for (int i =0; i <m_pStreamPins.size(); i++)
	{
		if (m_pStreamPins[i] == pPin)
		{
			isStreamPin = true;
			break;
		}
	}
	if (isStreamPin)
	{
		CheckPointer(mtOut, E_POINTER);
		if (IsEqualGUID(*mtOut->Type(), GUID_MyMediaSample) && 
			IsEqualGUID(*mtOut->Subtype(), GUID_D3DXTEXTURE9_POINTER))
		{
			return NOERROR;
		}
		else if (IsEqualGUID(*mtOut->Type(), MEDIATYPE_Video) && 
			IsEqualGUID(*mtOut->Subtype(), MEDIASUBTYPE_RGB32))
		{
			return NOERROR;
		}
	}
	return E_FAIL;
}
HRESULT HookDrawingFilter::DecideBufferSize(
								 IMemAllocator * pAlloc, const IPin* pOutPin,
								 __inout ALLOCATOR_PROPERTIES *pProp)
{
	HRESULT hr;
	bool isStreamPin = false;
	for (int i =0; i <m_pStreamPins.size(); i++)
	{
		if (m_pStreamPins[i] == pOutPin)
		{
			isStreamPin = true;
			break;
		}
	}
	if (isStreamPin)
	{
		CMediaType mt = ((CMuxTransformStream*)pOutPin)->CurrentMediaType();
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
}

MS3DDisplay* HookDrawingFilter::Create3DDisplay(IDirect3D9* pD3D, int rtWidth, int rtHeight)
{
	MS3DDisplay* ret = new HookDrawingDisplay(pD3D, rtWidth, rtHeight);
	ret->SetDeviceLostCallback((MS3DDisplay::DeviceLostCallBack)OnBeforeDisplayResetDevice,
		(MS3DDisplay::DeviceLostCallBack)OnAfterDisplayResetDevice, (void*)this);
	return ret;
}

MS3DDisplay* HookDrawingFilter::Create3DDisplay(IDirect3DDevice9* pDevice, int rtWidth, int rtHeight)
{
	return new HookDrawingDisplay(pDevice, rtWidth, rtHeight);
}
HRESULT HookDrawingFilter::CreateAdditionalTexture(UINT idx, UINT w, UINT h)
{
	CAutoLock lck(&m_csAddTextures[idx]);
	if (idx < 0 || idx >= NUMHOOKPIN || m_pAddOutTexture.size() < NUMHOOKPIN || 
		m_pAddRenderTarget.size() < NUMHOOKPIN)
	{
		return S_FALSE;
	}
	if ( m_pAddOutTexture[idx] != NULL)
	{
		m_pAddOutTexture[idx]->Release();
		m_pAddOutTexture[idx] = NULL;
	}
	if (m_pAddRenderTarget[idx] != NULL)
	{
		m_pAddRenderTarget[idx]->Release();
		m_pAddRenderTarget[idx] = NULL;
	}
	HRESULT hr;
	IDirect3DDevice9* pDevice = m_pD3DDisplay->GetD3DDevice();
	hr = D3DXCreateTexture(pDevice, w, h, 
		0,  0, D3DFMT_X8R8G8B8, D3DPOOL_SYSTEMMEM, &(m_pAddOutTexture[idx]));
	if (FAILED(hr))
	{
		OutputDebugStringW(L"@@@@@@ CreateAdditionalTexture Failed!! in HookDrawingFilter\n");
	}
	hr = D3DXCreateTexture(pDevice, w, h, 
		0, D3DUSAGE_RENDERTARGET, D3DFMT_X8R8G8B8, D3DPOOL_DEFAULT, &(m_pAddOutTexture[idx]));

	if (FAILED(hr))
	{
		OutputDebugStringW(L"@@@@@@ CreateAdditionalTexture Failed!! in HookDrawingFilter\n");
	}
	return hr;
}
HRESULT HookDrawingFilter::SetRenderTarget(int idx)
{
	HRESULT hr;
	if (FAILED(TestDisplayDeviceLost()))
	{
		return S_FALSE;
	}
	if (m_pAddRenderTarget.size() <= idx || m_pAddRenderTarget[idx] == NULL || m_pD3DDisplay == NULL)
	{
		return S_FALSE;
	}
	IDirect3DDevice9* pDevice = m_pD3DDisplay->GetD3DDevice();
	LPDIRECT3DSURFACE9 pRTSurface = NULL;
	m_pAddRenderTarget[idx]->GetSurfaceLevel(0, &pRTSurface);
	pRTSurface->AddRef();

	hr = pDevice->GetRenderTarget(0, &m_pBackupRenderTarget);
	hr = pDevice->SetRenderTarget(0, pRTSurface);

	if (pRTSurface != NULL)
	{
		pRTSurface->Release();
		pRTSurface = NULL;
	}
	return S_OK;
}
HRESULT HookDrawingFilter::ResetRenderTarget()
{
	
	if (FAILED(TestDisplayDeviceLost()))
		return S_FALSE;
	HRESULT hr = S_OK;
	if (m_pBackupRenderTarget == NULL || m_pD3DDisplay == NULL)
	{
		return S_FALSE;
	}
	IDirect3DDevice9* pDevice = m_pD3DDisplay->GetD3DDevice();
	pDevice->SetRenderTarget(0, m_pBackupRenderTarget);

	m_pBackupRenderTarget->Release();
	m_pBackupRenderTarget = NULL;
	return S_OK;
	
}
HRESULT HookDrawingFilter::initD3D(UINT rtWidth, UINT rtHeight )
{
	HRESULT hr;
	hr = __super::initD3D(rtWidth, rtHeight);
	hr = initAddTextures(1024, 768);
	return hr;
	
}
HRESULT HookDrawingFilter::initAddTextures(UINT w, UINT h)
{
	HRESULT hr = S_FALSE;
	
	for (int i =0; i< m_pAddOutTexture.size(); i++)
	{
		m_pAddOutTexture[i]->Release();
		m_pAddOutTexture[i] = NULL;
	}
	m_pAddOutTexture.clear();
	for (int i =0; i< m_pAddRenderTarget.size(); i++)
	{
		m_pAddRenderTarget[i]->Release();
		m_pAddRenderTarget[i] = NULL;
	}
	m_pAddRenderTarget.clear();
	if (w == 0 || h == 0)
	{
		HDC dc = GetDC(GetDesktopWindow());
		w = GetDeviceCaps(dc, HORZRES);
		h = GetDeviceCaps(dc, VERTRES);
	}
	for (int i =0 ;i< NUMHOOKPIN; i++)
	{
		LPDIRECT3DTEXTURE9 pAddTexture = NULL;
		LPDIRECT3DTEXTURE9 pAddRenderTarget = NULL;
		hr = D3DXCreateTexture(m_pD3DDisplay->GetD3DDevice(), w, h, 
			0,  0, D3DFMT_X8R8G8B8, D3DPOOL_SYSTEMMEM, &pAddTexture);
		if (FAILED(hr))
		{
			return hr;
		}
		m_pAddOutTexture.push_back(pAddTexture);
		hr = D3DXCreateTexture(m_pD3DDisplay->GetD3DDevice(), w, h, 
			0,  D3DUSAGE_RENDERTARGET, D3DFMT_X8R8G8B8, D3DPOOL_DEFAULT, &pAddRenderTarget);

		if (FAILED(hr))
		{
			return hr;
		}
		m_pAddRenderTarget.push_back(pAddRenderTarget);
		
	}

	return S_OK;
}
HRESULT HookDrawingFilter::CreateInTexture(UINT w, UINT h)
{
	CAutoLock lck(&m_csInTexture);
	if (m_pD3DDisplay == NULL)
		return S_FALSE;
	HRESULT hr = S_OK;
	LPDIRECT3DTEXTURE9 pTexture = NULL;
	hr=	D3DXCreateTexture(m_pD3DDisplay->GetD3DDevice(), w, h, 
		0,  0, D3DFMT_X8R8G8B8, D3DPOOL_MANAGED, &pTexture);
	if (FAILED(hr))
	{
		return hr;
	}
	if (m_pInTexture != NULL)
	{
		m_pInTexture->Release();
		m_pInTexture = NULL;
	}
	m_pInTexture = pTexture;
	return S_OK;
}
HRESULT HookDrawingFilter::GetPages(CAUUID *pPages)
{
	pPages->cElems = 1;
	pPages->pElems = (GUID*)CoTaskMemAlloc(sizeof(GUID));
	if (pPages->pElems == NULL) 
	{
		return E_OUTOFMEMORY;
	}
	pPages->pElems[0] = CLSID_HookDrawingPropPage;
	return S_OK;
}


ATOM HookDrawingFilter::RegisterHookWndClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW | CS_NOCLOSE;
	wcex.lpfnWndProc	= HookDrawingWndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= NULL;
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= NULL;
	wcex.lpszClassName	= L"HookDrawingWnd";
	wcex.hIconSm		= NULL;
	ATOM ret = RegisterClassEx(&wcex);

	return ret;
}
HRESULT HookDrawingFilter::CreateHookWindow(UINT winW, UINT winH)
{
	if (winW != 0 && winH != 0)
	{
		if (m_hHookRecMsgWnd == 0)
		{
			m_hHookRecMsgWnd = CreateWindowExW(NULL, L"HookDrawingWnd", L"HookDrawingWnd", WS_EX_TOPMOST |/* WS_POPUP |*/ WS_OVERLAPPEDWINDOW,
				CW_USEDEFAULT, 0, winW, winH, NULL, NULL, GetModule(), NULL);
		}
		::ShowWindow(m_hHookRecMsgWnd, FALSE);
	}
	else
	{
		if (m_hHookRecMsgWnd == 0)
		{
			m_hHookRecMsgWnd = CreateWindowExW(NULL, L"HookDrawingWnd", L"HookDrawingWnd", WS_EX_TOPMOST |/* WS_POPUP |*/ WS_OVERLAPPEDWINDOW,
				CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, GetModule(), NULL);
		}
		::ShowWindow(m_hHookRecMsgWnd, FALSE);
	}
	return S_OK;
}

LRESULT HookDrawingFilter::HookDrawingWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int i = 0;
	if (message == HOOKED_WNDDESTORY)
	{
		if (g_Instance != NULL)
			g_Instance->onHookedWindowDestory();
	}
	if (message == HOOKED_BITBLTCALLED)
	{
		if (g_Instance != NULL)
		{
			g_Instance->onBitBltCalled();
		}
	}
	if (message == WM_SHOWWINDOW)
	{
		if (g_Instance != NULL)
		{
			g_Instance->CaptureHookWnd();
		}
	}
	switch (message)
	{
	
	default:
		return D3DEnv::D3DWndProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

HRESULT HookDrawingFilter::CompleteConnect(PIN_DIRECTION direction, const IPin* pMyPin, const IPin* pOtherPin)
{
	return __super::CompleteConnect(direction, pMyPin, pOtherPin);
}
HRESULT HookDrawingFilter::BreakConnect(PIN_DIRECTION dir, const IPin* pPin)
{
	return __super::BreakConnect(dir, pPin);
}

BOOL HookDrawingFilter::IsHooked()
{
	if (m_hHookedWnd == 0)
	{
		return FALSE;
	}
	return TRUE;
}

HWND HookDrawingFilter::GetHookedWindow()
{
	return m_hHookedWnd;
}
BOOL HookDrawingFilter::SetHookedWindow(HWND hwnd)
{
	m_hHookedWnd = hwnd;
	return TRUE;
}
BOOL HookDrawingFilter::GetWarpMatrix(UINT idx, D3DXMATRIX& matWarp)
{
	if (idx >= m_pStreamPins.size())
		return FALSE;
	const D3DXMATRIX* mat = ((HookDrawingStream*)m_pStreamPins[idx])->GetWarpMatrix();
	matWarp = *mat;
	return TRUE;
}
BOOL HookDrawingFilter::SetWarpMatrix(UINT idx, const D3DXMATRIX& matWarp)
{
	if (idx >= m_pStreamPins.size())
		return FALSE;
	((HookDrawingStream*)m_pStreamPins[idx])->SetWarpMatrix(matWarp);
	return TRUE;
}
BOOL HookDrawingFilter::GetResolution(IPin* pPin, UINT& resW, UINT& resH)
{
	int idx = -1;
	for (int i =0; i< NUMHOOKPIN; i++)
	{
		if (pPin == m_pStreamPins[i])
		{
			idx = i;
			break;
		}
	}
	if (idx < 0 )
	{
		return FALSE;
	}
	{
		CAutoLock lck(&m_csAddTextures[idx]);
		if (m_pAddOutTexture.size() <= idx || m_pAddOutTexture[idx] == NULL)
		{
			return FALSE;
		}

		D3DSURFACE_DESC desc;
		m_pAddOutTexture[idx]->GetLevelDesc(0, &desc);
		resW = desc.Width;
		resH = desc.Height;
	}
	return TRUE;
}
BOOL HookDrawingFilter::SetResolution(IPin* pPin, UINT resW, UINT resH)
{
	int idx = -1;
	for (int i =0; i< NUMHOOKPIN; i++)
	{
		if (pPin == m_pStreamPins[i])
		{
			idx = i;
			break;
		}
	}
	if (idx < 0 )
		return FALSE;
	if (m_pStreamPins.size() <= idx || m_pStreamPins[idx]->IsConnected())
	{
		return FALSE;
	}
	{
		CAutoLock lck(&m_csAddTextures[idx]);
		if (m_pAddOutTexture.size() <= idx || m_pAddOutTexture[idx] == FALSE)
		{
			return FALSE;
		}
	}
	
	return CreateAdditionalTexture(idx, resW, resH);
}

BOOL HookDrawingFilter::GetSourceResolution( UINT& resW, UINT& resH)
{
	CAutoLock lck(&m_csInTexture);

	D3DSURFACE_DESC desc;
	m_pInTexture->GetLevelDesc(0, &desc);
	resW = desc.Width;
	resH = desc.Height;

	return TRUE;
}
BOOL HookDrawingFilter::SetSourceResolution(UINT resW, UINT resH)
{
	return CreateInTexture(resW, resH);
}


void HookDrawingFilter::onHookedWindowDestory()
{
	m_hHookedWnd = NULL;
	HOOKINJECT::ClearBitBltCmd();
}
void HookDrawingFilter::onBitBltCalled()
{
	HOOKINJECT::DrawBitBltCommand bltCmd;
	if (HOOKINJECT::PopBitBltCmd(bltCmd))
	{
		HWND hClientWnd = 0;
		
		if (!HOOKINJECT::GetHookClient(hClientWnd))
		{
			return ;
		}
		HDC myhdc = GetDC(hClientWnd);
		HDC hdc = bltCmd.m_hdc; 
		HDC hdcSrc = bltCmd.m_hdcSrc;
		int height = bltCmd.m_height;
		int width = bltCmd.m_width;
		DWORD rop = bltCmd.m_rop;
		int x = bltCmd.m_x;
		int y = bltCmd.m_y;
		int x1 = bltCmd.m_x1;
		int y1 = bltCmd.m_y1;


		HWND hwnd = WindowFromDC(hdc);
		
		if (hwnd != hClientWnd)
		{
			return ;
		}

		RECT rect;
		GetClientRect(hwnd, &rect);
	
		int dcW = rect.right - rect.left;
		int dcH = rect.bottom - rect.top;

		DrawBitBlt(myhdc, x, y, width, height, dcW, dcH, hdcSrc, x1, y1, width, height, rop);
		for (int i =0; i < NUMHOOKPIN; i++)
			SetHookDirty(i, true);
		ReleaseDC(hClientWnd, myhdc);
		return;
	}
	
}

BOOL HookDrawingFilter::DrawBitBlt(HDC hdc, int x, int y, int width, int height, int dcW, int dcH, HDC hdcSrc, int x1, int y1, int srcW, int srcH, DWORD rop)
{
	CAutoLock lck(&m_csInTexture);
	if (m_pInTexture == NULL)
		return FALSE;
	if (dcW <= 0 || dcH <= 0 )
	{
		return FALSE;
	}
	HRESULT hr;
	IDirect3DSurface9* pSurface = NULL;
	hr = m_pInTexture->GetSurfaceLevel(0, &pSurface);
	HDC textureDC;
	hr = pSurface->GetDC(&textureDC);
	if (FAILED(hr))
	{
		WCHAR str[MAX_PATH];
		swprintf_s(str, MAX_PATH, L"@@@@ pSurface->GetDC Failed in DrawBitBlt, hr = %Xh \n", hr);
		OutputDebugStringW(str);
	}
	D3DSURFACE_DESC desc;
	pSurface->GetDesc(&desc);

	float rX = ((float)desc.Width / dcW);
	float rY = ((float)desc.Height / dcH);
	WCHAR str[MAX_PATH];
	
	BOOL ret = StretchBlt(textureDC, rX*x, rY*y, rX*width, rY*height, hdc, x, y, width, height, rop);
	
	pSurface->ReleaseDC(textureDC);
	pSurface->Release();
	pSurface = NULL;
	
	return TRUE;
}

BOOL HookDrawingFilter::CaptureHookWnd()
{
	if (!IsD3DReady())
	{
		return FALSE;
	}
	HWND hClientWnd = 0;
	if (!HOOKINJECT::GetHookClient(hClientWnd))
	{
		return FALSE;
	}
	CAutoLock lck(&m_csInTexture);
	HDC myhdc = GetDC(hClientWnd);
	RECT rect;
	GetClientRect(hClientWnd, &rect);

	int dcW = rect.right - rect.left;
	int dcH = rect.bottom - rect.top;

	HRESULT hr;
	IDirect3DSurface9* pSurface = NULL;
	hr = m_pInTexture->GetSurfaceLevel(0, &pSurface);
	HDC textureDC;
	hr = pSurface->GetDC(&textureDC);
	if (FAILED(hr))
	{
		ReleaseDC(hClientWnd, myhdc);
		pSurface->ReleaseDC(textureDC);
		pSurface->Release();
		return FALSE;
	}
	D3DSURFACE_DESC desc;
	pSurface->GetDesc(&desc);

	BOOL ret = StretchBlt(textureDC, 0, 0, desc.Width, desc.Height, myhdc, 0, 0, dcW, dcH, 0);
	ReleaseDC(hClientWnd, myhdc);
	pSurface->ReleaseDC(textureDC);
	pSurface->Release();
	pSurface = NULL;
	return TRUE;
}
BOOL HookDrawingFilter::CopyOutputTexture2OutputData(int idx, IMediaSample *pOut, const CMediaType* pOutMediaType, bool bFlipY)
{
	if (pOut == NULL || m_pAddOutTexture.size() <= idx || m_pAddOutTexture[idx] == NULL)
	{
		return S_FALSE;
	}
	HRESULT hr = S_OK;
	if (FAILED(TestDisplayDeviceLost()))
	{
		return S_FALSE;
	}
	CAutoLock lck(&m_csAddTextures[idx]);
	IDirect3DDevice9* pDevice = m_pD3DDisplay->GetD3DDevice();
	GUID guidSubType = pOutMediaType->subtype;

	LPDIRECT3DSURFACE9 pOutSurface = NULL;
	D3DSURFACE_DESC surOutDesc;
	m_pAddOutTexture[idx]->GetSurfaceLevel(0, &pOutSurface);
	pOutSurface->GetDesc(&surOutDesc);
	D3DLOCKED_RECT rect;

	if (IsEqualGUID(*pOutMediaType->Type(), GUID_MyMediaSample) && IsEqualGUID(*pOutMediaType->Subtype(), GUID_D3DXTEXTURE9_POINTER))
	{	
		((CMediaSample*)pOut)->SetPointer((BYTE*)m_pAddOutTexture[idx], sizeof(LPDIRECT3DTEXTURE9));
	}
	else
	{
		BYTE* pOutData = NULL;
		pOut->GetPointer(&pOutData);
		int channel = 4;
		VIDEOINFOHEADER *pvi = (VIDEOINFOHEADER *) pOutMediaType->pbFormat;
		BITMAPINFOHEADER bitHeader = pvi->bmiHeader;
		int surHeight = surOutDesc.Height;
		int surWidth = surOutDesc.Width;
		int height = bitHeader.biHeight;
		int width = bitHeader.biWidth;
		if (IsEqualGUID(guidSubType, MEDIASUBTYPE_RGB24))
		{
			channel = 3;
		}
		else if(IsEqualGUID(guidSubType, MEDIASUBTYPE_RGB32) || IsEqualGUID(guidSubType, MEDIASUBTYPE_ARGB32))
		{
			channel = 4;
		}
		pOutSurface->LockRect(&rect, NULL, D3DLOCK_READONLY);
		if (bFlipY)
		{	
			int x = 0; int y = 0; int dstX = 0; int dstY = 0;
			float tmpW = ((float)surWidth) / width;
			float tmpH = ((float)surHeight) / height;
			for( y = 0; y < height; y++ )
			{
				for ( x = 0; x< width; x++)
				{
					dstX = x * tmpW;  dstY = y * tmpH;
					pOutData[(height - y -1)*width*channel + x*channel] = ((BYTE*)rect.pBits)[(int)(dstY*rect.Pitch + dstX*4)];
					pOutData[(height - y -1)*width*channel + x*channel + 1] = ((BYTE*)rect.pBits)[(int)(dstY*rect.Pitch + dstX*4 + 1)];
					pOutData[(height - y -1)*width*channel + x*channel + 2] = ((BYTE*)rect.pBits)[(int)(dstY*rect.Pitch + dstX*4 + 2)];
				}
			}
		}
		else
		{
			int x = 0; int y = 0; int dstX = 0; int dstY = 0;
			float tmpW = ((float)surWidth) / width;
			float tmpH = ((float)surHeight) / height;
			for( y = 0; y < height; y++ )
			{
				for ( x = 0; x< width; x++)
				{
					dstX = x * tmpW;  dstY = y * tmpH;
					pOutData[y*width*channel + x*channel] = ((BYTE*)rect.pBits)[(int)(dstY*rect.Pitch + dstX*4)];
					pOutData[y*width*channel + x*channel + 1] = ((BYTE*)rect.pBits)[(int)(dstY*rect.Pitch + dstX*4 + 1)];
					pOutData[y*width*channel + x*channel + 2] = ((BYTE*)rect.pBits)[(int)(dstY*rect.Pitch + dstX*4 + 2)];
				}
			}

		}
		pOutSurface->UnlockRect();
	}
	if (pOutSurface != NULL)
	{
		pOutSurface->Release();
		pOutSurface = NULL;
	}
}
BOOL HookDrawingFilter::CopyInTexture2OutTexture(int idx)
{
	CAutoLock lck0(&m_csInTexture);
	CAutoLock lck1(&m_csAddTextures[idx]);
	if (m_pInTexture == NULL || m_pAddOutTexture.size() < idx || 
		m_pAddOutTexture[idx] == NULL )
	{
		return FALSE;
	}
	HRESULT hr = S_OK;
	D3DXVECTOR2 lt, lb, rt, rb;
	IDirect3DSurface9* pOutSurface = NULL, *pInSurface = NULL;
	D3DSURFACE_DESC inDesc, outDesc;
	RECT srcRECT;
	((HookDrawingStream*)m_pStreamPins[idx])->GetWarpPts(lt, lb, rt, rb);

	hr = m_pAddOutTexture[idx]->GetSurfaceLevel(0, &pOutSurface);
	hr = m_pInTexture->GetSurfaceLevel(0, &pInSurface);
	pInSurface->GetDesc(&inDesc);
	pOutSurface->GetDesc(&outDesc);
	srcRECT.left = min((int)(inDesc.Width-1), (int)(lt.x * inDesc.Width));
	srcRECT.right = min((int)(inDesc.Width -1), (int)(rb.x * inDesc.Width));
	srcRECT.top = min((int)(inDesc.Height -1), (int)(lt.y * inDesc.Height));
	srcRECT.bottom = min((int)(inDesc.Height -1), (int)(lb.y * inDesc.Height));
	//hr = D3DXLoadSurfaceFromSurface(pOutSurface, NULL, NULL , pInSurface,
	//	NULL, &srcRECT, D3DX_FILTER_POINT, 0);
	
	HDC InDC = 0, OutDC = 0;
	pInSurface->GetDC(&InDC);
	pOutSurface->GetDC(&OutDC);
	StretchBlt(OutDC, 0, 0, outDesc.Width, outDesc.Height, InDC, 
		srcRECT.left, srcRECT.top, srcRECT.right - srcRECT.left, 
		srcRECT.bottom - srcRECT.top, SRCCOPY);

	pInSurface->ReleaseDC(InDC);
	pOutSurface->ReleaseDC(OutDC);
	pOutSurface->Release();
	pInSurface->Release();
	return TRUE;
}


HRESULT HookDrawingFilter::OnBeforeDisplayResetDevice(IDirect3DDevice9 * pd3dDevice, 
												   void* pUserContext)
{
	HookDrawingFilter* pThis = (HookDrawingFilter*)pUserContext;
	if (pThis == NULL)
		return S_FALSE;
	
	for (int i =0; i< pThis->m_pAddOutTexture.size(); i++)
	{
		CAutoLock lck(&pThis->m_csAddTextures[i]);
		pThis->m_pAddOutTexture[i]->Release();
		pThis->m_pAddOutTexture[i] = NULL;
	}
	pThis->m_pAddOutTexture.clear();
	for (int i =0; i< pThis->m_pAddRenderTarget.size(); i++)
	{
		pThis->m_pAddRenderTarget[i]->Release();
		pThis->m_pAddRenderTarget[i] = NULL;
	}
	pThis->m_pAddRenderTarget.clear();
	return S_OK;
}
HRESULT HookDrawingFilter::OnAfterDisplayResetDevice(IDirect3DDevice9 * pd3dDevice, 
												  void* pUserContext)
{
	HookDrawingFilter* pThis = (HookDrawingFilter*)pUserContext;
	if (pThis == NULL)
		return S_FALSE;
	pThis->initAddTextures(1024, 768);
	return S_OK;
}

HRESULT HookDrawingFilter::SaveToFile(WCHAR* path)
{
	FILE* filestream = NULL;
	_wfopen_s(&filestream, path, L"w");
	if (filestream == NULL)
	{
		return false;
	}

	UINT srcResW = 0, srcResH = 0;
	GetSourceResolution(srcResW, srcResH);
	UINT* pinResW = new UINT[NUMHOOKPIN];
	UINT* pinResH = new UINT[NUMHOOKPIN];
	D3DXMATRIX* matWarp = new D3DXMATRIX[NUMHOOKPIN];
	memset(pinResW, 0, sizeof(UINT)*NUMHOOKPIN);
	memset(pinResH, 0, sizeof(UINT)*NUMHOOKPIN);
	memset(matWarp, 0, sizeof(D3DXMATRIX)*NUMHOOKPIN);

	for (int i =0; i < NUMHOOKPIN; i++)
	{
		GetResolution(m_pStreamPins[i], pinResW[i], pinResH[i]);
		GetWarpMatrix(i, matWarp[i]);
	}
	fwprintf_s(filestream, L"%d\n", NUMHOOKPIN);
	fwprintf_s(filestream, L"%d %d \n", srcResW, srcResH);
	for (int i = 0; i < NUMHOOKPIN; i++)
	{
		fwprintf_s(filestream, L"%d %d \n", pinResW[i], pinResH[i]);
		fwprintf_s(filestream, L"%f %f %f %f\n", 
			matWarp[i].m[0][0], matWarp[i].m[0][1], matWarp[i].m[0][2], matWarp[i].m[0][3]);
		fwprintf_s(filestream, L"%f %f %f %f\n", 
			matWarp[i].m[1][0], matWarp[i].m[1][1], matWarp[i].m[1][2], matWarp[i].m[1][3]);
		fwprintf_s(filestream, L"%f %f %f %f\n", 
			matWarp[i].m[2][0], matWarp[i].m[2][1], matWarp[i].m[2][2], matWarp[i].m[2][3]);
		fwprintf_s(filestream, L"%f %f %f %f\n", 
			matWarp[i].m[3][0], matWarp[i].m[3][1], matWarp[i].m[3][2], matWarp[i].m[3][3]);
	}

	fclose(filestream);
	delete [] pinResW; 
	delete [] pinResH;
	delete [] matWarp;
	return S_OK;
}
HRESULT HookDrawingFilter::LoadFromFile(WCHAR* path)
{
	FILE* filestream = NULL;
	_wfopen_s(&filestream, path, L"r");
	if (filestream == NULL)
	{
		return false;
	}

	int numPins = 0; 
	int srcResW=0, srcResH = 0;
	int* pinResW = NULL, *pinResH = NULL;
	D3DXMATRIX* matWarp = NULL;

	fwscanf_s(filestream, L"%d\n", &numPins);
	if (numPins <= 0 || numPins > m_pStreamPins.size())
	{
		fclose(filestream);
		return S_FALSE;
	}
	pinResW = new int[numPins];
	pinResH = new int[numPins];
	matWarp = new D3DXMATRIX[numPins];
	
	fwscanf_s(filestream, L"%d %d \n", &srcResW, &srcResH);
	for (int i = 0; i < numPins; i++)
	{
		fwscanf_s(filestream, L"%d %d \n", &(pinResW[i]), &(pinResH[i]));
		fwscanf_s(filestream, L"%f %f %f %f\n", 
			&(matWarp[i].m[0][0]), &(matWarp[i].m[0][1]), &(matWarp[i].m[0][2]), &(matWarp[i].m[0][3]));
		fwscanf_s(filestream, L"%f %f %f %f\n", 
			&(matWarp[i].m[1][0]), &(matWarp[i].m[1][1]), &(matWarp[i].m[1][2]), &(matWarp[i].m[1][3]));
		fwscanf_s(filestream, L"%f %f %f %f\n", 
			&(matWarp[i].m[2][0]), &(matWarp[i].m[2][1]), &(matWarp[i].m[2][2]), &(matWarp[i].m[2][3]));
		fwscanf_s(filestream, L"%f %f %f %f\n", 
			&(matWarp[i].m[3][0]), &(matWarp[i].m[3][1]), &(matWarp[i].m[3][2]), &(matWarp[i].m[3][3]));
	}
	fclose(filestream);

	this->SetSourceResolution(srcResW, srcResH);
	for (int i =0; i<numPins; i++)
	{
		this->SetResolution(m_pStreamPins[i], pinResW[i], pinResH[i] );
		this->SetWarpMatrix(i, matWarp[i]);
	}

	if (pinResW != NULL)
	{	
		delete [] pinResW; 
		pinResW = NULL;
	}
	if (pinResH != NULL)
	{
		delete [] pinResH;
		pinResH = NULL;
	}
	if (matWarp != NULL)
	{
		delete [] matWarp;
		matWarp = NULL;
	}
	return S_OK;
}
HRESULT HookDrawingFilter::GetName(WCHAR* name, UINT szName)
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

BOOL HookDrawingFilter::GetHookDirty(int idx)
{
	if (idx < 0 || idx >= NUMHOOKPIN)
		return FALSE;
	CAutoLock lck(&m_csHookDirty[idx]);
	return m_bHookDirty[idx];
}
BOOL HookDrawingFilter::SetHookDirty(int idx, BOOL v)
{
	if (idx <0 || idx >= NUMHOOKPIN)
		return FALSE;
	CAutoLock lck(&m_csHookDirty[idx]);
	m_bHookDirty[idx] = v;
	return TRUE;
}