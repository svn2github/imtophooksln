
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
using namespace ARToolKitPlus;
extern CARTagFilterApp theApp;
ARTagDSFilter::ARTagDSFilter(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData)
: CTransformFilter(NAME("ARTag Filter"), 0, CLSID_ARTagDSFilter)
{ 
	/* Initialize any private variables here. */
	m_ARTracker = NULL;
	m_pCallback = NULL;
}
ARTagDSFilter::~ARTagDSFilter()
{
	if (m_ARTracker != NULL)
	{
		delete m_ARTracker;
		m_ARTracker = NULL;
	}
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
	if (direction == PINDIR_INPUT)
	{
		if (m_ARTracker != NULL)
		{
			delete m_ARTracker;
			m_ARTracker = NULL;
		}
		VIDEOINFOHEADER *pvi = (VIDEOINFOHEADER *) m_InputMT.pbFormat;
		BITMAPINFOHEADER bitHeader = pvi->bmiHeader;
		
		m_ARTracker = new ARToolKitPlus::TrackerMultiMarkerImpl<6,6,6, 1, 16>(bitHeader.biWidth, bitHeader.biHeight);
		GUID guidSubType = *m_InputMT.Subtype();
		if (IsEqualGUID(guidSubType, MEDIASUBTYPE_RGB24))
		{
			m_ARTracker->setPixelFormat(ARToolKitPlus::PIXEL_FORMAT_RGB);
			
		}
		else if (IsEqualGUID(guidSubType, MEDIASUBTYPE_RGB32) || IsEqualGUID(guidSubType, MEDIASUBTYPE_ARGB32))
		{
			m_ARTracker->setPixelFormat(ARToolKitPlus::PIXEL_FORMAT_RGBA);
		}
		CString strDistFactor = theApp.GetProfileString(L"Camera Setting", L"dist_Factor", L"159.0 139.0 -84.9 0.97932");
		double distfactor[4] = {0};
		swscanf_s(strDistFactor,L"%lf %lf %lf %lf", &(distfactor[0]), &(distfactor[1]), &(distfactor[2]), &(distfactor[3]));

		CString strMat = theApp.GetProfileString(L"Camera Setting", L"mat", 
			L"406.04    0.0      154.0    0.0 \
              0.0       404.38   115.0    0.0 \
			  0.0       0.0      1.0      0.0 \
			  0.0       0.0      0.0      1.0 ");
		double mat[16] = {0};
		swscanf_s(strMat,L"%lf %lf %lf %lf \
			%lf %lf %lf %lf \
			%lf %lf %lf %lf \
			%lf %lf %lf %lf",
			&(mat[0]), &(mat[1]), &(mat[2]), &(mat[3]), 
			&(mat[4]), &(mat[5]), &(mat[6]), &(mat[7]),
			&(mat[8]), &(mat[9]), &(mat[10]), &(mat[11]),
			&(mat[12]), &(mat[13]), &(mat[14]), &(mat[15]));
		m_ARTracker->setCamera(bitHeader.biWidth, bitHeader.biHeight, mat, distfactor, 1.0, 1000);


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
				pMarkers[idx].trans[2][0] = 0.0; pMarkers[idx].trans[2][1] = 0.0; pMarkers[idx].trans[2][2] = 1.0; pMarkers[idx].trans[0][3] = 0;
		
			}
		}
		m_ARTracker->setMarkInfo(pMarkers, 20);
	}
	return S_OK;
}
HRESULT ARTagDSFilter::Transform( IMediaSample *pIn, IMediaSample *pOut)
{
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
	memcpy(pOutData, pInData, pIn->GetSize());
	VIDEOINFOHEADER *pvi = (VIDEOINFOHEADER *) m_InputMT.pbFormat;
	BITMAPINFOHEADER bitHeader = pvi->bmiHeader;
	IplImage* img = cvCreateImageHeader(cvSize(bitHeader.biWidth, bitHeader.biHeight), 8, 3);
	img->imageData = (char*)pInData;
	cvFlip(img, NULL, 0);
	
	
	
	if (m_ARTracker != NULL)
	{
		int numDetected = m_ARTracker->calc(pInData);
		if (numDetected > 0)
		{
			const ARFloat* mat = m_ARTracker->getModelViewMatrix();
			
			if (mat)
			{
				if (m_pCallback)
				{
					m_pCallback(mat);
				}
				WCHAR str[MAX_PATH];
				swprintf_s(str, MAX_PATH, L"@@@@ GetModelView : \n@@@@ %.2f  %.2f  %.2f  %.2f \n\
										   @@@@ %.2f  %.2f  %.2f  %.2f\n\
										   @@@@ %.2f  %.2f  %.2f  %.2f\n\
										   @@@@ %.2f  %.2f  %.2f  %.2f\n", 
										   mat[0], mat[1],mat[2],mat[3],
										   mat[4],mat[5],mat[6],mat[7],
										   mat[8],mat[9],mat[10],mat[11],
										   mat[12],mat[13],mat[14],mat[15]);
				OutputDebugStringW(str);
			}
		}
		
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
	VIDEOINFOHEADER *pvi = (VIDEOINFOHEADER *) pMediaType->pbFormat;

	BITMAPINFOHEADER bitHeader = pvi->bmiHeader;

	
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
