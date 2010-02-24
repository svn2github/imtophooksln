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
: CMuxTransformFilter(NAME("HookDrawing Filter"), 0, CLSID_HookDrawingFilter), m_numPins(4)
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
		for ( int i =0; i < m_numPins; i++)
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
	if (!IsHooked())
	{
		return S_FALSE;
	}
	CAutoLock lck2(&m_csFillBuffer);
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
	SwitchRenderTarget(idx);
	SwitchOutTexture(idx);
	SetRenderTarget();
	{
		CAutoLock lck(&m_csInTexture);
		const D3DXMATRIX* matTTS = ((HookDrawingStream*)pPin)->GetWarpMatrix();
		((HookDrawingDisplay*)m_pD3DDisplay)->SetMatTTS(matTTS);
			
		m_pD3DDisplay->SetTexture(m_pInTexture);
		m_pD3DDisplay->Render();
	}
	ResetRenderTarget();
	CopyRenderTarget2OutputTexture();	
	CMediaType mt;
	mt = ((CMuxTransformStream*)pPin)->CurrentMediaType();
	CopyOutputTexture2OutputData(pSamp, &mt, true);
	return S_OK;
}

HRESULT HookDrawingFilter::GetMediaType(int iPosition, const IPin* pPin, __inout CMediaType *pMediaType)
{
	bool isStreamPin = false;
	for (int i =0; i <m_pStreamPins.size(); i++)
	{
		if (m_pStreamPins[i] == pPin)
		{
			CAutoLock lck(&m_csAddTextures);
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
	CAutoLock lck(&m_csAddTextures);
	if (idx < 0 || idx >= m_numPins || m_pAddOutTexture.size() < m_numPins || 
		m_pAddRenderTarget.size() < m_numPins)
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
	hr = D3DXCreateTexture(m_pD3DDisplay->GetD3DDevice(), w, h, 
		0,  0, D3DFMT_X8R8G8B8, D3DPOOL_SYSTEMMEM, &(m_pAddOutTexture[idx]));
	if (FAILED(hr))
	{
		OutputDebugStringW(L"@@@@@@ CreateAdditionalTexture Failed!! in HookDrawingFilter\n");
	}
	hr=	D3DXCreateTexture(m_pD3DDisplay->GetD3DDevice(), w, h, 
		0,  D3DUSAGE_RENDERTARGET, D3DFMT_X8R8G8B8, D3DPOOL_DEFAULT , &(m_pAddRenderTarget[idx]));
	if (FAILED(hr))
	{
		OutputDebugStringW(L"@@@@@@ CreateAdditionalTexture Failed!! in HookDrawingFilter\n");
	}
	return hr;
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
	CAutoLock lck(&m_csAddTextures);
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
	for (int i =0 ;i< m_numPins; i++)
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
		hr=	D3DXCreateTexture(m_pD3DDisplay->GetD3DDevice(), w, h, 
			0,  D3DUSAGE_RENDERTARGET, D3DFMT_X8R8G8B8, D3DPOOL_DEFAULT , &pAddRenderTarget);
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
	for (int i =0; i< m_numPins; i++)
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
		CAutoLock lck(&m_csAddTextures);
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
	for (int i =0; i< m_numPins; i++)
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
		CAutoLock lck(&m_csAddTextures);
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
BOOL HookDrawingFilter::SwitchOutTexture(int idx)
{
	CAutoLock lck(&m_csAddTextures);
	if (idx < 0 || idx >= m_pAddOutTexture.size())
	{
		return FALSE;
	}
	if (m_pOutTexture != NULL)
		m_pOutTexture->Release();
	m_pOutTexture = m_pAddOutTexture[idx];
	m_pAddOutTexture[idx]->AddRef();
	return TRUE;
}
BOOL HookDrawingFilter::SwitchRenderTarget(int idx)
{
	CAutoLock lck(&m_csAddTextures);
	if (idx < 0 || idx >= m_pAddRenderTarget.size())
	{
		return FALSE;
	}
	if (m_pRenderTarget != NULL)
		m_pRenderTarget->Release();
	m_pRenderTarget = m_pAddRenderTarget[idx];
	m_pAddRenderTarget[idx]->AddRef();
	return TRUE;
}


HRESULT HookDrawingFilter::OnBeforeDisplayResetDevice(IDirect3DDevice9 * pd3dDevice, 
												   void* pUserContext)
{
	HookDrawingFilter* pThis = (HookDrawingFilter*)pUserContext;
	if (pThis == NULL)
		return S_FALSE;
	CAutoLock lck(&pThis->m_csAddTextures);
	for (int i =0; i< pThis->m_pAddOutTexture.size(); i++)
	{
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
	UINT* pinResW = new UINT[m_numPins];
	UINT* pinResH = new UINT[m_numPins];
	D3DXMATRIX* matWarp = new D3DXMATRIX[m_numPins];
	memset(pinResW, 0, sizeof(UINT)*m_numPins);
	memset(pinResH, 0, sizeof(UINT)*m_numPins);
	memset(matWarp, 0, sizeof(D3DXMATRIX)*m_numPins);

	for (int i =0; i < m_numPins; i++)
	{
		GetResolution(m_pStreamPins[i], pinResW[i], pinResH[i]);
		GetWarpMatrix(i, matWarp[i]);
	}
	fwprintf_s(filestream, L"%d\n", m_numPins);
	fwprintf_s(filestream, L"%d %d \n", srcResW, srcResH);
	for (int i = 0; i < m_numPins; i++)
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