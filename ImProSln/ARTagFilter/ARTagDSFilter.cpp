
#include "stdafx.h"
#include "ARTagDSFilter.h"
#include <initguid.h>
#include "wxdebug.h"
#include <wtypes.h>
#include <ocidl.h>
#include "resource.h"
#include "ARToolKitPlus/TrackerMultiMarkerImpl.h"
#include "ARTagFilter.h"
#include "cv.h"
#include "highgui.h"
#include "ARTagD3DDisplay.h"
using namespace ARToolKitPlus;
extern CARTagFilterApp theApp;
ARTagDSFilter::ARTagDSFilter(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData)
: CTransformFilter(NAME("ARTag Filter"), 0, CLSID_ARTagDSFilter)
{ 
	/* Initialize any private variables here. */
	m_ARTracker = NULL;
	m_pCallback = NULL;
	m_hWndD3D = NULL;
	m_pD3D = NULL;
	m_pD3DDisplay = NULL;
	m_pOutTexture = NULL;
	m_pInTexture = NULL;
}
ARTagDSFilter::~ARTagDSFilter()
{
	if (m_ARTracker != NULL)
	{
		delete m_ARTracker;
		m_ARTracker = NULL;
	}
	ReleaseD3D();
}
CUnknown *WINAPI ARTagDSFilter::CreateInstance(LPUNKNOWN punk, HRESULT *phr)
{
	ASSERT(phr);
	// assuming we don't want to modify the data
	ARTagDSFilter *pNewObject = new ARTagDSFilter(punk, phr, FALSE);

	if(pNewObject == NULL) {
		if (phr)
			*phr = E_OUTOFMEMORY;
	}

	return pNewObject;
}


HRESULT ARTagDSFilter::NonDelegatingQueryInterface(REFIID iid, void **ppv)
{
	if (iid == IID_IARTagDSFilter) 
	{
		return GetInterface(static_cast<IARTagFilter*>(this), ppv);
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

HRESULT ARTagDSFilter::CheckInputType( const CMediaType * pmt )
{
	CheckPointer(pmt, E_POINTER);
	if (*pmt->FormatType() != FORMAT_VideoInfo) {
		return E_INVALIDARG;
	}

	// Can we transform this type
	if(IsAcceptedType(pmt)){
		m_InputMT = *pmt;
		return NOERROR;
	}

	return E_FAIL;
}



HRESULT ARTagDSFilter::CheckTransform(const CMediaType *pmtIn, const CMediaType *pmtOut)
{
	if(!IsAcceptedType(pmtIn))
		return E_FAIL;

	if(!IsAcceptedType(pmtOut))
		return E_FAIL;

	VIDEOINFOHEADER *pviIn = (VIDEOINFOHEADER *) pmtIn->pbFormat;
	VIDEOINFOHEADER *pviOut = (VIDEOINFOHEADER *) pmtOut->pbFormat;
	BITMAPINFOHEADER bitHeaderIn = pviIn->bmiHeader;
	BITMAPINFOHEADER bitHeaderOut = pviOut->bmiHeader;

	ASSERT(pmtIn->formattype == FORMAT_VideoInfo);
	BITMAPINFOHEADER *pBmiOut = HEADER(pmtOut->pbFormat);
	BITMAPINFOHEADER *pBmiIn = HEADER(pmtIn->pbFormat);
	if ((pBmiOut->biPlanes != 1) ||
		(pBmiOut->biWidth != pBmiIn->biWidth) ||
		(pBmiOut->biHeight != pBmiIn->biHeight) ||
		(pBmiOut->biBitCount != pBmiIn->biBitCount))
	{
		return VFW_E_TYPE_NOT_ACCEPTED;
	}

	
	m_InputMT  = *pmtIn;
	m_OutputMT = *pmtOut;

	return NOERROR;
}
HRESULT ARTagDSFilter::CompleteConnect(PIN_DIRECTION direction, IPin *pReceivePin)
{
	HRESULT hr = S_OK;
	
	if (direction == PINDIR_INPUT)
	{
		if (m_ARTracker != NULL)
		{
			delete m_ARTracker;
			m_ARTracker = NULL;
		}
		if (m_pInTexture != NULL)
		{
			m_pInTexture->Release();
			m_pInTexture = NULL;
		}
		if (m_pOutTexture != NULL)
		{
			m_pOutTexture->Release();
			m_pOutTexture = NULL;
		}
		VIDEOINFOHEADER *pvi = (VIDEOINFOHEADER *) m_InputMT.pbFormat;
		BITMAPINFOHEADER bitHeader = pvi->bmiHeader;
		initD3D(bitHeader.biWidth, bitHeader.biHeight);
		
		m_ARTracker = new ARToolKitPlus::TrackerMultiMarkerImpl<6,6,6, 1, 16>(bitHeader.biWidth, bitHeader.biHeight);
		GUID guidSubType = *m_InputMT.Subtype();
		if (IsEqualGUID(guidSubType, MEDIASUBTYPE_RGB24))
		{
			m_ARTracker->setPixelFormat(ARToolKitPlus::PIXEL_FORMAT_RGB);
			hr = D3DXCreateTexture(m_pD3DDisplay->GetD3DDevice(), bitHeader.biWidth, bitHeader.biHeight, 
				0,  D3DUSAGE_DYNAMIC, D3DFMT_R8G8B8, D3DPOOL_SYSTEMMEM , &m_pOutTexture);
			//D3DSURFACE_DESC desc;
			//m_pOutTexture->GetLevelDesc(0, &desc);
			
			hr=	D3DXCreateTexture(m_pD3DDisplay->GetD3DDevice(), bitHeader.biWidth, bitHeader.biHeight, 
				0,  D3DUSAGE_DYNAMIC, D3DFMT_R8G8B8, D3DPOOL_DEFAULT , &m_pInTexture);
		}
		else if (IsEqualGUID(guidSubType, MEDIASUBTYPE_RGB32) || IsEqualGUID(guidSubType, MEDIASUBTYPE_ARGB32))
		{
			m_ARTracker->setPixelFormat(ARToolKitPlus::PIXEL_FORMAT_RGBA);
			hr = D3DXCreateTexture(m_pD3DDisplay->GetD3DDevice(), bitHeader.biWidth, bitHeader.biHeight, 
				0,  D3DUSAGE_DYNAMIC, D3DFMT_A8R8G8B8, D3DPOOL_SYSTEMMEM , &m_pOutTexture);
			hr=	D3DXCreateTexture(m_pD3DDisplay->GetD3DDevice(), bitHeader.biWidth, bitHeader.biHeight, 
				0,  D3DUSAGE_DYNAMIC, D3DFMT_A8R8G8B8, D3DPOOL_DEFAULT , &m_pInTexture);
		}
		CString strDistFactor = L"159.0 139.0 -84.9 0.97932";//theApp.GetProfileString(L"Camera Setting", L"dist_Factor", L"159.0 139.0 -84.9 0.97932");
		double distfactor[4] = {0};
		swscanf_s(strDistFactor,L"%lf %lf %lf %lf", &(distfactor[0]), &(distfactor[1]), &(distfactor[2]), &(distfactor[3]));

		CString strMat = L"406.04    0.0      154.0    0.0 \
						  0.0       404.38   115.0    0.0 \
						  0.0       0.0      1.0      0.0 \
						  0.0       0.0      0.0      1.0 ";
		/*theApp.GetProfileString(L"Camera Setting", L"mat", 
			L"406.04    0.0      154.0    0.0 \
              0.0       404.38   115.0    0.0 \
			  0.0       0.0      1.0      0.0 \
			  0.0       0.0      0.0      1.0 ");*/
		double mat[16] = {0};
		swscanf_s(strMat,L"%lf %lf %lf %lf \
			%lf %lf %lf %lf \
			%lf %lf %lf %lf \
			%lf %lf %lf %lf",
			&(mat[0]), &(mat[1]), &(mat[2]), &(mat[3]), 
			&(mat[4]), &(mat[5]), &(mat[6]), &(mat[7]),
			&(mat[8]), &(mat[9]), &(mat[10]), &(mat[11]),
			&(mat[12]), &(mat[13]), &(mat[14]), &(mat[15]));
		
		m_ARTracker->setCamera(bitHeader.biWidth, bitHeader.biHeight, mat, distfactor, 1, 1000);
		m_ARTracker->setBorderWidth(0.125f);
		m_ARTracker->setThreshold(100);
		m_ARTracker->setUndistortionMode(ARToolKitPlus::UNDIST_LUT);
		m_ARTracker->setMarkerMode(ARToolKitPlus::MARKER_ID_SIMPLE);
		ARMultiEachMarkerInfoT* pMarkers = new ARMultiEachMarkerInfoT[20];
		//malloc((void*)pMarkers, sizeof(ARMultiEachMarkerInfoT)*20); 
		memset((void*)pMarkers, 0, sizeof(ARMultiEachMarkerInfoT)*20);

		for (int i = 0; i < 4; i++)
		{
			for ( int j = 0; j < 5; j++ )
			{
				int idx = i*5 + j;
				pMarkers[idx].patt_id = 480 + idx;
				pMarkers[idx].visible = 1;
				pMarkers[idx].width = 40;
				pMarkers[idx].trans[0][0] = 1.0; pMarkers[idx].trans[0][1] = 0.0; pMarkers[idx].trans[0][2] = 0.0; pMarkers[idx].trans[0][3] = -100.0 + 50*j;
				pMarkers[idx].trans[1][0] = 0.0; pMarkers[idx].trans[1][1] = 1.0; pMarkers[idx].trans[1][2] = 0.0; pMarkers[idx].trans[1][3] = 75 - 50*i;
				pMarkers[idx].trans[2][0] = 0.0; pMarkers[idx].trans[2][1] = 0.0; pMarkers[idx].trans[2][2] = 1.0; pMarkers[idx].trans[2][3] = 0;
		
			}
		}
		m_ARTracker->setMarkInfo(pMarkers, 20);
		
	}
	return S_OK;
}
HRESULT ARTagDSFilter::Transform( IMediaSample *pIn, IMediaSample *pOut)
{
	/*if (!IsWindowVisible(m_hWndD3D))
	{
		ShowWindow(m_hWndD3D, TRUE);
	}*/
	HRESULT hr = S_OK;
	BYTE* pInData = NULL;
	BYTE* pOutData = NULL;
	
	if (pIn->GetSize() < pOut->GetSize())
	{
		return S_FALSE;
	}
	hr = pIn->GetPointer(&pInData);
	if (FAILED(hr))
		return hr;
	hr = pOut->GetPointer(&pOutData);
	if (FAILED(hr))
		return hr;
	
	VIDEOINFOHEADER *pvi = (VIDEOINFOHEADER *) m_InputMT.pbFormat;
	BITMAPINFOHEADER bitHeader = pvi->bmiHeader;

	IplImage* img = cvCreateImageHeader(cvSize(bitHeader.biWidth, bitHeader.biHeight), 8, 3);
	img->imageData = (char*)pInData;
	cvFlip(img, NULL, 0);
	D3DXMATRIX* d3dmatView = NULL;
	D3DXMATRIX* d3dmatProj = NULL;
	if (m_ARTracker != NULL)
	{
		int numDetected = m_ARTracker->calc(pInData);
		
		if (numDetected > 0)
		{
			const ARMultiMarkerInfoT* multiMarker = m_ARTracker->getMultiMarkerConfig();
			/*if (multiMarker != NULL)
			{
				m_pD3DDisplay->SetMarkers(multiMarker);
			}*/

			int* detectedIDs = NULL;
			m_ARTracker->getDetectedMarkers(detectedIDs);
			if (detectedIDs == NULL)
			{
				return S_FALSE;
			}
			m_pD3DDisplay->SetDetectedMarkerIDs(numDetected, detectedIDs);			
			const ARFloat* matView = m_ARTracker->getModelViewMatrix();
			const ARFloat* matProj = m_ARTracker->getProjectionMatrix();
			
			if (matView != NULL && matProj != NULL)
			{
				if (m_pCallback)
				{
					m_pCallback(matView, matProj);
				}
				d3dmatView = new D3DXMATRIX(matView[0], matView[4],matView[8],matView[3],
											matView[1], matView[5],matView[9],matView[7],
											matView[2],matView[6],matView[10],matView[11],
											matView[12],matView[13],matView[14],matView[15]);
				//float zFar = 1000;
				//float zNear = 1.0;
				//float tmp = zFar / (zFar - zNear);
				d3dmatProj = new D3DXMATRIX(matProj[0], matProj[1], matProj[2], matProj[3],
											matProj[4], matProj[5], matProj[6], matProj[7],
											matProj[8], matProj[9], matProj[10] ,matProj[11],
											matProj[12],matProj[13],matProj[14],matProj[15]);
				//d3dmatProj->m[3][2] *= 0.5;
				//d3dmatProj->m[2][2] = 1000.0/(1000.0 - 1.0);
			}
		}	
	}
	if (d3dmatProj != NULL && d3dmatView != NULL)
	{
		LPDIRECT3DSURFACE9 pInSurface = NULL;
		D3DSURFACE_DESC surInDesc;
		m_pInTexture->GetSurfaceLevel(0, &pInSurface);
		pInSurface->GetDesc(&surInDesc);

		GUID guidSubType = *m_InputMT.Subtype();
		RECT rect;
		rect.left = 0;
		rect.right = bitHeader.biWidth;
		rect.top = 0;
		rect.bottom = bitHeader.biHeight;
		if (IsEqualGUID(guidSubType, MEDIASUBTYPE_RGB24))
		{
			hr = D3DXLoadSurfaceFromMemory(pInSurface, NULL, NULL, pInData, D3DFMT_R8G8B8, bitHeader.biWidth * 3, NULL, &rect, D3DX_DEFAULT, NULL);
		}
		else if (IsEqualGUID(guidSubType, MEDIASUBTYPE_ARGB32))
		{
			hr = D3DXLoadSurfaceFromMemory(pInSurface, NULL, NULL, pInData, D3DFMT_A8R8G8B8, bitHeader.biWidth * 4, NULL, &rect, D3DX_DEFAULT, NULL);
		}
		else
		{
			hr = E_FAIL;
		}
		if (FAILED(hr))
		{
			return S_FALSE;
		}

		m_pD3DDisplay->SetARViewMatrix(d3dmatView);
		m_pD3DDisplay->SetARProjMatrix(d3dmatProj);
		m_pD3DDisplay->SetTexture(m_pInTexture);

		//m_pD3DDisplay->Render();
		
		int numDetected = m_ARTracker->getNumDetectedMarkers();
		ARMarkerInfo* markinfos = new ARMarkerInfo[numDetected];
		for (int k = 0; k< numDetected; k++)
		{
			const ARMarkerInfo markinfo = m_ARTracker->getDetectedMarker(k);
			markinfos[k] = markinfo;
		}
		m_pD3DDisplay->Render(markinfos, numDetected);
		delete[] markinfos;
		
	}
	else
	{
		LPDIRECT3DSURFACE9 pInSurface = NULL;
		D3DSURFACE_DESC surInDesc;
		m_pInTexture->GetSurfaceLevel(0, &pInSurface);
		pInSurface->GetDesc(&surInDesc);

		GUID guidSubType = *m_InputMT.Subtype();
		RECT rect;
		rect.left = 0;
		rect.right = bitHeader.biWidth;
		rect.top = 0;
		rect.bottom = bitHeader.biHeight;
		if (IsEqualGUID(guidSubType, MEDIASUBTYPE_RGB24))
		{
			hr = D3DXLoadSurfaceFromMemory(pInSurface, NULL, NULL, pInData, D3DFMT_R8G8B8, bitHeader.biWidth * 3, NULL, &rect, D3DX_DEFAULT, NULL);
		}
		else if (IsEqualGUID(guidSubType, MEDIASUBTYPE_ARGB32))
		{
			hr = D3DXLoadSurfaceFromMemory(pInSurface, NULL, NULL, pInData, D3DFMT_A8R8G8B8, bitHeader.biWidth * 4, NULL, &rect, D3DX_DEFAULT, NULL);
		}
		else
		{
			hr = E_FAIL;
		}
		if (FAILED(hr))
		{
			return S_FALSE;
		}
		m_pD3DDisplay->SetTexture(m_pInTexture);
		m_pD3DDisplay->Render(NULL, 0);

	}
	if (d3dmatView != NULL)
	{
		delete d3dmatView;
		d3dmatView = NULL;
	}
	if (d3dmatProj != NULL)
	{
		delete d3dmatProj;
		d3dmatProj = NULL;
	}
	//copy render target to outData
	IDirect3DDevice9 * pDevice = m_pD3DDisplay->GetD3DDevice();

	LPDIRECT3DSURFACE9 pOutSurface = NULL;
	LPDIRECT3DSURFACE9 pRenderTarget = NULL;
	D3DSURFACE_DESC surRenderDesc, surOutDesc;
	m_pOutTexture->GetSurfaceLevel(0, &pOutSurface);
	hr = pDevice->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &pRenderTarget );
	pRenderTarget->GetDesc(&surRenderDesc);
	pOutSurface->GetDesc(&surOutDesc);
	hr = pDevice->GetRenderTargetData(pRenderTarget, pOutSurface);
	if (SUCCEEDED(hr))
	{
		GUID guidSubType = *m_InputMT.Subtype();
		int channel = 4;
		if (IsEqualGUID(guidSubType, MEDIASUBTYPE_RGB24))
		{
			channel = 3;
		}
		else if(IsEqualGUID(guidSubType, MEDIASUBTYPE_RGB32) || IsEqualGUID(guidSubType, MEDIASUBTYPE_ARGB32))
		{
			channel = 4;
		}
		D3DLOCKED_RECT rect;
		pOutSurface->LockRect(&rect, NULL, D3DLOCK_READONLY);
		int height = surOutDesc.Height;
		int width = surOutDesc.Width;
		for(int y = 0; y < height; y++ )
		{
			for (int x = 0; x< width; x++)
			{
				pOutData[(height - y - 1)*width*channel + x*channel] = ((BYTE*)rect.pBits)[y*rect.Pitch + x*4];
				pOutData[(height - y - 1)*width*channel + x*channel + 1] = ((BYTE*)rect.pBits)[y*rect.Pitch + x*4 + 1];
				pOutData[(height - y - 1)*width*channel + x*channel + 2] = ((BYTE*)rect.pBits)[y*rect.Pitch + x*4 + 2];
			}
		}
		//memcpy(pOutData, rect.pBits, pOut->GetSize());
		pOutSurface->UnlockRect();
	}
	if (pOutSurface != NULL)
	{
		pOutSurface->Release();
		pOutSurface = NULL;
	}
	if (pRenderTarget != NULL)
	{
		pRenderTarget->Release();
		pRenderTarget = NULL;
	}
	return S_OK;
}

HRESULT ARTagDSFilter::DecideBufferSize(IMemAllocator *pAlloc, ALLOCATOR_PROPERTIES *pProp)
{
	HRESULT hr = NOERROR;

	pProp->cBuffers = 1;
	pProp->cbBuffer = m_OutputMT.GetSampleSize();
	//ASSERT(pProperties->cbBuffer);

	// Ask the allocator to reserve us some sample memory, NOTE the function
	// can succeed (that is return NOERROR) but still not have allocated the
	// memory that we requested, so we must check we got whatever we wanted

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
	return NOERROR;
}

HRESULT ARTagDSFilter::GetMediaType(int iPosition, CMediaType *pMediaType)
{
	if (iPosition < 0) {
		return E_INVALIDARG;
	}
	// Do we have more items to offer

	if (iPosition >= 1) { // WATCH OUT !!
		return VFW_S_NO_MORE_ITEMS;
	}
    
	*pMediaType = m_InputMT;
	/*pMediaType->subtype = MEDIASUBTYPE_ARGB32;
	VIDEOINFOHEADER *pvi = (VIDEOINFOHEADER *) pMediaType->pbFormat;
	BITMAPINFOHEADER bitHeader = pvi->bmiHeader;
	bitHeader.biBitCount = 32;
	*/
	return S_OK;
}


bool ARTagDSFilter::IsAcceptedType(const CMediaType *pmt)
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

HRESULT ARTagDSFilter::GetPages(CAUUID *pPages)
{
	pPages->cElems = 1;
	pPages->pElems = (GUID*)CoTaskMemAlloc(sizeof(GUID));
	if (pPages->pElems == NULL) 
	{
		return E_OUTOFMEMORY;
	}
	pPages->pElems[0] = CLSID_ARTagProperty;
	return S_OK;
}


bool ARTagDSFilter::setCamera(int xsize, int ysize, double* mat, double* dist_factor,ARFloat nNearClip, ARFloat nFarClip)
{
	if (m_ARTracker == NULL)
	{
		return false;
	}
	return m_ARTracker->setCamera(xsize, ysize, mat, dist_factor, nNearClip, nFarClip);
}

bool ARTagDSFilter::getCamera(int& xsize, int &ysize, double* mat, double* dist_factor)
{
	ARToolKitPlus::Camera* cam = m_ARTracker->getCamera();
	if (cam == NULL)
	{
		return false;
	}
	xsize = cam->xsize;   ysize = cam->ysize;
	for (int i =0; i<3; i++)
	{
		for (int j =0; j<4; j++)
		{
			mat[4*i + j] = cam->mat[i][j];
		}
	}
	mat[3*4 + 0] = 0; mat[3*4 + 1] = 0; mat[3*4 + 2] = 0; mat[3*4 + 3] = 1;
	for (int i =0; i< 4; i++)
	{
		dist_factor[i] = cam->dist_factor[i];
	}
	
	return true;
}
bool ARTagDSFilter::setMarkInfo(ARToolKitPlus::ARMultiEachMarkerInfoT *marker, int numMarker)
{
	if (m_ARTracker == NULL)
	{
		return false;
	}
	return m_ARTracker->setMarkInfo(marker, numMarker);
}
bool ARTagDSFilter::setBorderWidth(double borderWidth)
{
	if (m_ARTracker == NULL)
	{
		return false;
	}
	m_ARTracker->setBorderWidth(borderWidth);
	return true;
}
double ARTagDSFilter::getBorderWidth()
{
	if (m_ARTracker == NULL)
	{
		return false;
	}
	return m_ARTracker->getBorderWidth();
}
bool ARTagDSFilter::setThreshold(int t)
{
	if (m_ARTracker == NULL)
	{
		return false;
	}
	m_ARTracker->setThreshold(t);
	return true;
}
int ARTagDSFilter::getThreshold()
{
	if (m_ARTracker == NULL)
	{
		return false;
	}
	return m_ARTracker->getThreshold();
}
bool ARTagDSFilter::setUndistortionMode(int mode)
{
	if (m_ARTracker == NULL)
	{
		return false;
	}
	m_ARTracker->setUndistortionMode((ARToolKitPlus::UNDIST_MODE)mode);
	return true;
}
int ARTagDSFilter::getUndistortionMode()
{
	if (m_ARTracker == NULL)
	{
		return false;
	}
	return m_ARTracker->getUndistortionMode();
}
bool ARTagDSFilter::setMarkerMode(int mode)
{
	if (m_ARTracker == NULL)
	{
		return false;
	}
	m_ARTracker->setMarkerMode((ARToolKitPlus::MARKER_MODE)mode);
	return true;
}
int ARTagDSFilter::getMarkerMode()
{
	if (m_ARTracker == NULL)
	{
		return false;
	}
	return m_ARTracker->getMarkerMode();
}
bool ARTagDSFilter::setPoseEstimator(int rpp)
{
	if (m_ARTracker == NULL)
	{
		return false;
	}
	m_ARTracker->setPoseEstimator((ARToolKitPlus::POSE_ESTIMATOR)rpp);
	return true;
}
int ARTagDSFilter::getPosEstimator()
{
	if (m_ARTracker == NULL)
	{
		return false;
	}
	return m_ARTracker->getPoseEstimator();
}
bool ARTagDSFilter::IsReady()
{
	if (m_ARTracker == NULL)
	{
		return false;
	}
	return true;
}

BOOL ARTagDSFilter::SetCallback(CallbackFuncPtr pfunc)
{
	m_pCallback = pfunc;
	return TRUE;
}


LRESULT ARTagDSFilter::D3DWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

ATOM ARTagDSFilter::RegisterWndClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= D3DWndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= NULL;
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= NULL;
	wcex.lpszClassName	= L"ARTag D3DWnd";
	wcex.hIconSm		= NULL;
	ATOM ret = RegisterClassEx(&wcex);

	return ret;
}

HRESULT ARTagDSFilter::initD3D(UINT rtWidth, UINT rtHeight)
{
	RegisterWndClass(GetModule());
	if (rtWidth != 0 && rtHeight != 0)
	{
		if (m_hWndD3D == 0)
		{
			m_hWndD3D = CreateWindowExW(NULL, L"ARTag D3DWnd", L"ARTag D3DWnd", WS_EX_TOPMOST |/* WS_POPUP |*/ WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT, 0, rtWidth, rtHeight, NULL, NULL, GetModule(), NULL);
		}
	}
	else
	{
		if (m_hWndD3D == 0)
		{
			m_hWndD3D = CreateWindowExW(NULL, L"ARTag D3DWnd", L"ARTag D3DWnd", WS_EX_TOPMOST |/* WS_POPUP |*/ WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, GetModule(), NULL);
		}
	}
	if (m_hWndD3D == NULL)
	{
		DWORD err = GetLastError();
		WCHAR str[MAX_PATH];
		swprintf_s(str, MAX_PATH, L"@@@@@ CreateWindow Failed!! in CreateLowDisplay, Error code = %h \n", err);
		OutputDebugStringW(str);

	}
	ShowWindow(m_hWndD3D, FALSE);

	if (m_pD3D == NULL)
	{
		if( NULL == ( m_pD3D = Direct3DCreate9( D3D_SDK_VERSION ) ) )
		{
			OutputDebugStringW(L"@@@@@ Direct3DCreate9 Failed!! in CreateLowDisplay\n");
			return FALSE;
		}
	}
	if (m_pD3DDisplay != NULL)
	{
		delete m_pD3DDisplay;
		m_pD3DDisplay = NULL;
	}
	m_pD3DDisplay = new ARTagD3DDisplay(m_hWndD3D, m_pD3D, rtWidth, rtHeight);
	return S_OK;
}


HWND ARTagDSFilter::GetD3DWnd()
{
	return m_hWndD3D;
}
IDirect3D9* ARTagDSFilter::GetD3D()
{
	return m_pD3D;
}

BOOL ARTagDSFilter::ReleaseD3D()
{
	if (m_pD3D != NULL)
	{
		m_pD3D->Release();
		m_pD3D = NULL;
	}
	if (m_hWndD3D != 0)
	{
		::CloseWindow(m_hWndD3D);
		m_hWndD3D = 0;
	}
	if (m_pD3DDisplay != NULL)
	{
		delete m_pD3DDisplay;
		m_pD3DDisplay = NULL;
	}
	return TRUE;
}