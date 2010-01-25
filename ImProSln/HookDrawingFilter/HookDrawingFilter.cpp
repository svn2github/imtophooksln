#include "stdafx.h"
#include "HookDrawingFilter.h"
#include "HookDrawingFilterApp.h"
#include "MyMediaSample.h"
#include "HookDrawingDisplay.h"
#include "HookDrawingProp.h"
#include "..\\HookInject\IHookInject.h"

HookDrawingFilter* g_Instance = NULL;

static UINT HOOKED_WNDDESTORY = ::RegisterWindowMessage(HOOKED_WNDDESTORY_MSG);
static UINT HOOKED_BITBLTCALLED = ::RegisterWindowMessage(HOOKED_BITBLTCALLED_MSG);

HookDrawingFilter::HookDrawingFilter(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData)
: CMuxTransformFilter(NAME("HookDrawing Filter"), 0, CLSID_HookDrawingFilter)
{
	m_hHookedWnd = 0;
	HRESULT hr = initD3D();
	if (SUCCEEDED(hr))
	{
		HOOKINJECT::SetHookServer(GetD3DWnd());
		HOOKINJECT::SetHookServerProcID(GetCurrentProcessId());
	}
}
HookDrawingFilter::~HookDrawingFilter()
{
	if (m_hHookedWnd != NULL)
	{
		::PostMessageW(m_hHookedWnd, WM_CLOSE, NULL, NULL);
	}
	g_Instance = NULL;
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
		CMuxTransformStream* pOutput0 = new CMuxTransformStream(NAME("CMuxTransform stream pin"),
			&hr,              // Owner filter
			this,               // Result code
			L"d3dsurf");      // Pin name
		//  Can't fail
		ASSERT(SUCCEEDED(hr));
		if (pOutput0 == NULL) {
			return NULL;
		}
		m_pStreamPins.push_back(pOutput0);
	}
	
	return S_OK;
}
HRESULT HookDrawingFilter::FillBuffer(IMediaSample *pSamp, IPin* pPin)
{
	if (!IsHooked())
	{
		return S_FALSE;
	}
	SetRenderTarget();
	{
		CAutoLock lck(&m_csInTexture);
		m_pD3DDisplay->SetTexture(m_pInTexture);
		m_pD3DDisplay->Render();
	}
	ResetRenderTarget();
	CopyRenderTarget2OutputTexture();	
	CMediaType mt;
	GetMediaType(0, pPin, &mt);
	CopyOutputTexture2OutputData(pSamp, &mt, true);
	return S_OK;
}

HRESULT HookDrawingFilter::GetMediaType(int iPosition, const IPin* pPin, __inout CMediaType *pMediaType)
{
	if (m_pStreamPins.size() >= 1 && m_pStreamPins[0] == pPin)
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
	return S_FALSE;
}
HRESULT HookDrawingFilter::CheckOutputType(const CMediaType* mtOut, const IPin* pPin)
{
	if (m_pStreamPins.size() >= 1 && m_pStreamPins[0] == pPin)
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
	if (m_pStreamPins.size() >= 1 && m_pStreamPins[0] == pOutPin)
	{
		pProp->cBuffers = 1;
		pProp->cbBuffer = sizeof(LPDIRECT3DTEXTURE9);

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

MS3DDisplay* HookDrawingFilter::Create3DDisplay(HWND hWndD3D,IDirect3D9* pD3D, int rtWidth, int rtHeight)
{
	return new HookDrawingDisplay(hWndD3D, pD3D, rtWidth, rtHeight);
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


ATOM HookDrawingFilter::RegisterWndClass(HINSTANCE hInstance)
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
HRESULT HookDrawingFilter::CreateD3DWindow(UINT winW, UINT winH)
{
	if (winW != 0 && winH != 0)
	{
		if (m_hWndD3D == 0)
		{
			m_hWndD3D = CreateWindowExW(NULL, L"HookDrawingWnd", L"HookDrawingWnd", WS_EX_TOPMOST |/* WS_POPUP |*/ WS_OVERLAPPEDWINDOW,
				CW_USEDEFAULT, 0, winW, winH, NULL, NULL, GetModule(), NULL);
		}
	}
	else
	{
		if (m_hWndD3D == 0)
		{
			m_hWndD3D = CreateWindowExW(NULL, L"HookDrawingWnd", L"HookDrawingWnd", WS_EX_TOPMOST |/* WS_POPUP |*/ WS_OVERLAPPEDWINDOW,
				CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, GetModule(), NULL);
		}
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