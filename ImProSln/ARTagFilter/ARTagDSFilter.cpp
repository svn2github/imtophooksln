
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
#include "ARTagProp.h"
#include "MyMediaSample.h"
#include "msxml2.h"
#include <string.h>

using namespace ARToolKitPlus;
extern CARTagFilterApp theApp;
ARTagDSFilter::ARTagDSFilter(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData)
: CMuxTransformFilter(NAME("ARTag Filter"), 0, CLSID_ARTagDSFilter)
{ 
	/* Initialize any private variables here. */
	m_ARTracker = NULL;
	m_pCallback = NULL;
	m_hWndD3D = NULL;
	m_pD3D = NULL;
	m_pD3DDisplay = NULL;
	m_pOutTexture = NULL;
	m_pInTexture = NULL;
	m_bDrawTag = true;

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

HRESULT ARTagDSFilter::Receive(IMediaSample *pSample, const IPin* pReceivePin)
{
	HRESULT hr;
	if (m_pInputPins.size() >= 1 && pReceivePin == m_pInputPins[0])
	{

		AM_SAMPLE2_PROPERTIES * const pProps = ((CMuxTransformInputPin*)pReceivePin)->SampleProps();
		if (pProps->dwStreamId != AM_STREAM_MEDIA) {
			return S_OK;
		}
		ASSERT(pSample);
		// If no output to deliver to then no point sending us data
		ASSERT (m_pOutputPins.size() != 0);
		HRESULT hr;
		// Set up the output sample

		// Start timing the transform (if PERF is defined)
		MSR_START(m_idTransform);

		hr = Transform(pSample);

		// Stop the clock and log it (if PERF is defined)
		MSR_STOP(m_idTransform);

		if (FAILED(hr)) {
			DbgLog((LOG_TRACE,1,TEXT("Error from transform")));
		} else {
			// the Transform() function can return S_FALSE to indicate that the
			// sample should not be delivered; we only deliver the sample if it's
			// really S_OK (same as NOERROR, of course.)
			if (hr == NOERROR) {
				hr = m_pOutputPins[0]->Deliver(pSample);
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
	
	}
	return S_OK;
}
HRESULT ARTagDSFilter::CreatePins()
{
	HRESULT hr = S_OK;
	if (m_pInputPins.size() < 2 && m_pOutputPins.size() < 2) {
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

		CMuxTransformInputPin* pInput1 = new CMuxTransformInputPin(NAME("CMuxTransform input pin"),
			this,              // Owner filter
			&hr,               // Result code
			L"AR config");      // Pin name
		//  Can't fail

		CMuxTransformOutputPin* pOutput0 = new CMuxTransformOutputPin(NAME("CMuxTransform output pin"),
			this,              // Owner filter
			&hr,               // Result code
			L"output");      // Pin name
		//  Can't fail

		CMuxTransformOutputPin* pOutput1 = new CMuxTransformOutputPin(NAME("CMuxTransform output pin"),
			this,            // Owner filter
			&hr,             // Result code
			L"AR Result");   // Pin name
		// Can't fail

		m_pInputPins.push_back(pInput0);
		m_pInputPins.push_back(pInput1);
		m_pOutputPins.push_back(pOutput0);
		m_pOutputPins.push_back(pOutput1);
	}
	return S_OK;
}
HRESULT ARTagDSFilter::CheckInputType( const CMediaType * pmt, const IPin* pPin)
{
	CheckPointer(pmt, E_POINTER);
	if ( m_pInputPins.size() >= 1 && pPin == m_pInputPins[0])
	{
		if (*pmt->FormatType() != FORMAT_VideoInfo) {
		return E_INVALIDARG;
		}
		// Can we transform this type
		if(IsAcceptedType(pmt)){
			return NOERROR;
		}
	}
	else if (m_pInputPins.size() >= 2 && pPin == m_pInputPins[1])
	{
		return E_NOTIMPL;
	}
	return E_INVALIDARG;
}

HRESULT ARTagDSFilter::CheckOutputType(const CMediaType* pmt, const IPin* pPin)
{
	CheckPointer(pmt, E_POINTER);
	if (m_pOutputPins.size() >= 0 && m_pOutputPins[0] == pPin)
	{
		if (*pmt->FormatType() != FORMAT_VideoInfo) {
			return E_INVALIDARG;
		}
		// Can we transform this type
		if(IsAcceptedType(pmt)){
			return NOERROR;
		}
	}
	else if (m_pOutputPins.size() >= 1 && m_pOutputPins[1] == pPin)
	{
		if (!IsEqualGUID(*pmt->Type(), GUID_MyMediaSample) || !IsEqualGUID(*pmt->Subtype(), GUID_ARResult)) {
			return E_INVALIDARG;
		}
		// Can we transform this type
		return S_OK;
	}
	return E_FAIL;
}

HRESULT ARTagDSFilter::CompleteConnect(PIN_DIRECTION direction, const IPin* pMyPin, const IPin* pOtherPin)
{
	HRESULT hr = S_OK;
	
	if (direction == PINDIR_INPUT && m_pInputPins.size() > 0 && pMyPin == m_pInputPins[0])
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
		CMediaType inputMT = m_pInputPins[0]->GetCurMediaType();
		VIDEOINFOHEADER *pvi = (VIDEOINFOHEADER *) inputMT.pbFormat;
		BITMAPINFOHEADER bitHeader = pvi->bmiHeader;
		initD3D(bitHeader.biWidth, bitHeader.biHeight);
		
		m_ARTracker = new ARToolKitPlus::TrackerMultiMarkerImpl<6,6,12, 1, 64>(bitHeader.biWidth, bitHeader.biHeight);
		GUID guidSubType = *inputMT.Subtype();
		if (IsEqualGUID(guidSubType, MEDIASUBTYPE_RGB24))
		{
			m_ARTracker->setPixelFormat(ARToolKitPlus::PIXEL_FORMAT_RGB);

		}
		else if (IsEqualGUID(guidSubType, MEDIASUBTYPE_RGB32) || IsEqualGUID(guidSubType, MEDIASUBTYPE_ARGB32))
		{
			m_ARTracker->setPixelFormat(ARToolKitPlus::PIXEL_FORMAT_RGBA);
		}
		CreateInOutTextures(bitHeader.biWidth, bitHeader.biHeight);
		CString strDistFactor = L"0.245073 -0.759911 0.001721 0.008927";//theApp.GetProfileString(L"Camera Setting", L"dist_Factor", L"159.0 139.0 -84.9 0.97932");
		double distfactor[4] = {0};
		swscanf_s(strDistFactor,L"%lf %lf %lf %lf", &(distfactor[0]), &(distfactor[1]), &(distfactor[2]), &(distfactor[3]));

		CString strMat = L"680.20544     0.0      315.158539    0.0 \
						  0.0       679.564148   253.423645    0.0 \
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
		m_ARTracker->setBorderWidth(0.2f);
		m_ARTracker->setThreshold(100);
		m_ARTracker->setUndistortionMode(ARToolKitPlus::UNDIST_NONE);
		m_ARTracker->setMarkerMode(ARToolKitPlus::MARKER_ID_SIMPLE);
		ARMultiEachMarkerInfoT* pMarkers = new ARMultiEachMarkerInfoT[16];
		memset((void*)pMarkers, 0, sizeof(ARMultiEachMarkerInfoT)*16);

		for (int i = 0; i < 4; i++)
		{
			for ( int j = 0; j < 4; j++ )
			{
				int idx = i*4 + j;
				pMarkers[idx].patt_id = idx;
				pMarkers[idx].visible = 1;
				pMarkers[idx].width = 10.0/48.0;
				pMarkers[idx].trans[0][0] = 1.0; pMarkers[idx].trans[0][1] = 0.0; pMarkers[idx].trans[0][2] = 0.0; pMarkers[idx].trans[0][3] = 0 + pMarkers[idx].width*j + (1.0/48.0)*(2*j+1);
				pMarkers[idx].trans[1][0] = 0.0; pMarkers[idx].trans[1][1] = 1.0; pMarkers[idx].trans[1][2] = 0.0; pMarkers[idx].trans[1][3] = 0 - pMarkers[idx].width*i - (1.0/48.0)*(2*i+1);
				pMarkers[idx].trans[2][0] = 0.0; pMarkers[idx].trans[2][1] = 0.0; pMarkers[idx].trans[2][2] = 1.0; pMarkers[idx].trans[2][3] = 0;
		
			}
		}
		m_ARTracker->setMarkInfo(pMarkers, 16);
		
	}
	return S_OK;
}
HRESULT ARTagDSFilter::Transform( IMediaSample *pIn)
{
	HRESULT hr = S_OK;
	if (m_pD3DDisplay != NULL)
	{
		CMediaType inputMT = m_pInputPins[0]->GetCurMediaType();
		
		return DoTransform(pIn, &inputMT);
	}
	return S_OK;
}


HRESULT ARTagDSFilter::DoTransform(IMediaSample *pIn, const CMediaType* pInType )
{

	HRESULT hr = S_OK;
	BYTE* pInData = NULL;
	
	int numDetected = 0;
	ARMarkerInfo* markinfos = NULL;

	hr = pIn->GetPointer(&pInData);
	if (FAILED(hr))
		return hr;


	GUID guidSubType = *pInType->Subtype();
	VIDEOINFOHEADER *pvi = (VIDEOINFOHEADER *) pInType->pbFormat;
	BITMAPINFOHEADER bitHeader = pvi->bmiHeader;
	IplImage* img = NULL;
	if (IsEqualGUID(guidSubType, MEDIASUBTYPE_RGB24))
	{
		img = cvCreateImageHeader(cvSize(bitHeader.biWidth, bitHeader.biHeight), 8, 3);
	}
	else if (IsEqualGUID(guidSubType, MEDIASUBTYPE_ARGB32) || IsEqualGUID(guidSubType, MEDIASUBTYPE_RGB32))
	{
		img = cvCreateImageHeader(cvSize(bitHeader.biWidth, bitHeader.biHeight), 8, 4);
	}

	img->imageData = (char*)pInData;
	cvFlip(img, NULL, 0);
	if (m_ARTracker != NULL)
	{
		numDetected = m_ARTracker->calc(pInData);

		if (numDetected > 0)
		{
			markinfos = new ARMarkerInfo[numDetected];
			for (int k = 0; k < numDetected; k++)
			{
				const ARMarkerInfo markinfo = m_ARTracker->getDetectedMarker(k);
				markinfos[k] = markinfo;
			}
			const ARFloat* matARView = m_ARTracker->getModelViewMatrix();
			const ARFloat* matARProj = m_ARTracker->getProjectionMatrix();
			const ARMultiMarkerInfoT* markerConfig = m_ARTracker->getMultiMarkerConfig();
			
			if (m_pCallback != NULL)
			{
				m_pCallback(numDetected, markinfos, matARView, matARProj);
			}
			if (m_pOutputPins.size() >= 2 && m_pOutputPins[1]->IsConnected())
			{
				ARTagResultData* pARTagResult = new ARTagResultData(markerConfig, numDetected, markinfos, 
					matARView, matARProj);
				pARTagResult->m_screenW = bitHeader.biWidth;
				pARTagResult->m_screenH = bitHeader.biHeight;

				IMemAllocator* pAllocator = m_pOutputPins[1]->GetAllocator();
				CMediaSample* pSample = NULL;
				
				pAllocator->GetBuffer((IMediaSample**)&pSample, NULL, NULL, 0);
				pSample->SetPointer((BYTE*)pARTagResult, sizeof(ARTagResultData));
				ARTagResultData* test = NULL;
				pSample->GetPointer((BYTE**)&test);
				

				m_pOutputPins[1]->Deliver(pSample);
				if (pSample != NULL)
				{
					pSample->Release();
					pSample = NULL;
				}
				if (pARTagResult != NULL)
				{
					delete pARTagResult;
					pARTagResult = NULL;
				}
			}


		}	
	}
	if (m_bDrawTag)
	{
		CopyInputImage2InputTexture(pIn, pInType, false);
		m_pD3DDisplay->SetTexture(m_pInTexture);
		((ARTagD3DDisplay*)m_pD3DDisplay)->Render(markinfos, numDetected);
		CopyRenderTarget2OutputTexture();
		CopyOutputTexture2OutputData(pIn, pInType, true);
	}
	else
	{
		cvFlip(img, NULL, 0);
		
	}
	if (img != NULL)
	{
		cvReleaseImageHeader(&img);
		img = NULL;
	}
	if (markinfos != NULL)
	{
		delete[] markinfos;
		markinfos = NULL;
	}
	return S_OK;
}


HRESULT ARTagDSFilter::DecideBufferSize(IMemAllocator *pAlloc,const IPin* pOutPin, ALLOCATOR_PROPERTIES *pProp)
{
	HRESULT hr = NOERROR;
	if (m_pInputPins.size() <= 0)
	{
		return S_FALSE;
	}
	CMediaType inputMT = m_pInputPins[0]->GetCurMediaType();

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
	else if (m_pOutputPins.size() > 1 && m_pOutputPins[1] == pOutPin)
	{
		pProp->cBuffers = 1;
		pProp->cbBuffer = sizeof(ARTagResultData);
		ALLOCATOR_PROPERTIES Actual;
		hr = pAlloc->SetProperties(pProp,&Actual);
		ASSERT( Actual.cBuffers == 1 );
		if (pProp->cBuffers > Actual.cBuffers ||
			pProp->cbBuffer > Actual.cbBuffer) {
				return E_FAIL;
		}
	}
	return NOERROR;
}

HRESULT ARTagDSFilter::GetMediaType(int iPosition, const IPin* pOutPin, __inout CMediaType *pMediaType)
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
		CMediaType inputMT = m_pInputPins[0]->GetCurMediaType();
		*pMediaType = inputMT;
		return S_OK;
	}
	if (m_pOutputPins.size() > 1 && m_pOutputPins[1] == pOutPin)
	{
		CMediaType myMediaType;
		myMediaType.SetType(&GUID_MyMediaSample);
		myMediaType.SetSubtype(&GUID_ARResult);
		myMediaType.SetSampleSize(sizeof(ARTagResultData));
		*pMediaType = myMediaType;
		return S_OK;
	}
	return VFW_S_NO_MORE_ITEMS;
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
	pPages->cElems = 2;
	pPages->pElems = (GUID*)CoTaskMemAlloc(sizeof(GUID)*2);
	if (pPages->pElems == NULL) 
	{
		return E_OUTOFMEMORY;
	}
	pPages->pElems[0] = CLSID_ARTagProperty;
	pPages->pElems[1] = CLSID_ARTagCameraProperty;

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
HRESULT ARTagDSFilter::VariantFromString(PCWSTR wszValue, VARIANT &Variant)
{
	HRESULT hr = S_OK;
	BSTR bstr = SysAllocString(wszValue);

	V_VT(&Variant)   = VT_BSTR;
	V_BSTR(&Variant) = bstr;
	return hr;
}
HRESULT ARTagDSFilter::loadCameraFromXMLFile(WCHAR* filename)
{
	IXMLDOMDocument* pXmlDom = NULL;
	HRESULT hr = CoCreateInstance(__uuidof(DOMDocument60), NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&pXmlDom));

	if (FAILED(hr))
	{
		return hr;
	}
	pXmlDom->put_async(VARIANT_FALSE);  
	pXmlDom->put_validateOnParse(VARIANT_FALSE);
	pXmlDom->put_resolveExternals(VARIANT_FALSE);

	VARIANT varFileName;
	VariantInit(&varFileName);
	VariantFromString(filename, varFileName);

	BSTR bstrXML = NULL;
	BSTR bstrErr = NULL;
	VARIANT_BOOL varStatus;
	hr = pXmlDom->load(varFileName, &varStatus);
	if (FAILED(hr))
	{
		return S_FALSE;
	}
	if (varStatus != VARIANT_TRUE)
	{
		return S_FALSE;
	}
	pXmlDom->get_xml(&bstrXML);
	IXMLDOMNodeList* nodeList = NULL;
	IXMLDOMNode* nodeRoot = NULL;
	IXMLDOMNode* node = NULL;
	IXMLDOMNode* nodeNext = NULL;
	IXMLDOMAttribute * attr = NULL;
	IXMLDOMNamedNodeMap* pNameNodeMap = NULL;
	long length = 0;

	int* xsize = NULL;
	int* ysize = NULL;
	double mat[16] = {0};
	double* dist_factor[4] = {NULL, NULL, NULL, NULL};
	double* focal_length_x = NULL;
	double* focal_length_y = NULL;
	double* center_x = NULL;
	double* center_y = NULL;
	pXmlDom->getElementsByTagName(L"CAMERADATACAMERADATA", &nodeList);
	
	nodeList->get_length(&length);
	if (length <=0 )
	{
		return S_FALSE;
	}
	
	nodeList->get_item(0, &nodeRoot);
	nodeRoot->get_firstChild(&node);
	do {	
		node->get_attributes(&pNameNodeMap);
		pNameNodeMap->get_length(&length);
		for (long i =0; i<length; i++)
		{
			IXMLDOMNode* pNodeAttr = NULL;
			CComVariant           varValue;
			CComBSTR              bstrName;

			pNameNodeMap->get_item(i, &pNodeAttr );
			pNodeAttr->get_nodeName(&bstrName);
			pNodeAttr->get_nodeValue(&varValue);
			if (wcscmp(bstrName, L"screen_width") == 0)
			{
				xsize = new int();
				swscanf(varValue.bstrVal, L"%d", xsize);
			}
			else if (wcscmp(bstrName, L"screen_height") == 0)
			{
				ysize = new int();
				swscanf(varValue.bstrVal, L"%d", ysize);
			}
			else if (wcscmp(bstrName, L"dist_1") == 0)
			{
				dist_factor[0] = new double();
				swscanf(varValue.bstrVal, L"%lf", dist_factor[0]);
			}
			else if (wcscmp(bstrName, L"dist_2") == 0)
			{
				dist_factor[1] = new double();
				swscanf(varValue.bstrVal, L"%lf", dist_factor[1]);
			}
			else if (wcscmp(bstrName, L"dist_3") == 0)
			{
				dist_factor[2] = new double();
				swscanf(varValue.bstrVal, L"%lf", dist_factor[2]);
			}
			else if (wcscmp(bstrName, L"dist_4") == 0)
			{
				dist_factor[3] = new double();
				swscanf(varValue.bstrVal, L"%lf", dist_factor[3]);
			}
			else if (wcscmp(bstrName, L"len_1") == 0)
			{
				focal_length_x = new double();
				swscanf(varValue.bstrVal, L"%lf", focal_length_x);
			}
			else if (wcscmp(bstrName, L"len_2") == 0)
			{
				focal_length_y = new double();
				swscanf(varValue.bstrVal, L"%lf", focal_length_y);
			}
			else if (wcscmp(bstrName, L"point_1") == 0)
			{
				center_x = new double();
				swscanf(varValue.bstrVal, L"%lf", center_x);
			}
			else if (wcscmp(bstrName, L"point_2") == 0)
			{
				center_y = new double();
				swscanf(varValue.bstrVal, L"%lf", center_y);
			}

			pNodeAttr->Release();
			pNodeAttr = NULL;
		}

		hr = node->get_nextSibling(&nodeNext);
		node->Release();
		node = nodeNext;
		nodeNext = NULL;
		if (FAILED(hr) || node == NULL)
		{
			break;
		}
	} while(1);

	HRESULT ret = S_FALSE;
	if (!(xsize == NULL || ysize == NULL || dist_factor[0] == NULL || dist_factor[1] == NULL ||
		dist_factor[2] == NULL || dist_factor[3] == NULL || focal_length_x == NULL || focal_length_y == NULL ||
		center_x == NULL || center_y == NULL))
	{
		ret = S_OK;
		mat[4*0 + 0] = *focal_length_x;
		mat[4*1 + 1] = *focal_length_y;
		mat[4*2 + 2] = 1;
		mat[4*3 + 3] = 1;
		mat[4*0 + 2] = *center_x;
		mat[4*1 + 2] = *center_x;
		double distfactor[4] = { *dist_factor[0], *dist_factor[1], 
			*dist_factor[2], *dist_factor[3]};

		this->setCamera(*xsize, *ysize, mat, distfactor, 1.0, 1000);
	}
	
	if (pXmlDom != NULL)
	{
		pXmlDom->Release();
		pXmlDom = NULL;
	}
	if (nodeList != NULL)
	{
		nodeList->Release();
		nodeList = NULL;
	}
	
	if ( nodeRoot != NULL)
	{
		nodeRoot->Release();
		nodeRoot = NULL;
	}
	if (node != NULL)
	{
		node->Release();
		node = NULL;
	}
	if (nodeNext != NULL)
	{
		nodeNext->Release();
		nodeNext = NULL;
	}
	if (attr != NULL)
	{
		attr->Release();
		attr = NULL;
	}
	if (pNameNodeMap != NULL)
	{
		pNameNodeMap->Release();
		pNameNodeMap = NULL;
	}
	if ( xsize != NULL)
	{
		delete xsize;
		xsize = NULL;
	}
	if ( ysize != NULL)
	{
		delete ysize;
		ysize = NULL;
	}
	for (int i =0; i<4; i++)
	{
		if (dist_factor[i] != NULL)
		{
			delete dist_factor[i];
			dist_factor[i] = NULL;
		}
	}
	if (center_x != NULL)
	{
		delete center_x;
		center_x = NULL;
	}
	if (center_y != NULL)
	{
		delete center_y;
		center_y = NULL;
	}
	if (focal_length_x != NULL)
	{
		delete focal_length_x;
		focal_length_x = NULL;
	}
	if (focal_length_y != NULL)
	{
		delete focal_length_y;
		focal_length_y = NULL;
	}
	SysFreeString(bstrXML);
	SysFreeString(bstrErr);
	VariantClear(&varFileName);

	return ret;
}
bool ARTagDSFilter::setMarkInfo(ARMultiEachMarkerInfoT *marker, int numMarker)
{
	if (m_ARTracker == NULL)
	{
		return false;
	}
	return m_ARTracker->setMarkInfo((ARToolKitPlus::ARMultiEachMarkerInfoT*) marker, numMarker);
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

bool ARTagDSFilter::setConfThreshold(float v)
{
	if (m_ARTracker == NULL)
	{
		return false;
	}
	return m_ARTracker->setConfThreshold(v);
}
float ARTagDSFilter::getConfThreshold()
{
	if (m_ARTracker == NULL)
	{
		return 0;
	}
	return m_ARTracker->getConfThreshold();
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
int ARTagDSFilter::getPoseEstimator()
{
	if (m_ARTracker == NULL)
	{
		return false;
	}
	return m_ARTracker->getPoseEstimator();
}
bool ARTagDSFilter::getbDrawTag()
{
	return m_bDrawTag;
}
bool ARTagDSFilter::setbDrawTag(bool v)
{
	m_bDrawTag = v; return true;
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
MS3DDisplay* ARTagDSFilter::Create3DDisplay(HWND hWndD3D,IDirect3D9* pD3D, int rtWidth, int rtHeight)
{
	return new ARTagD3DDisplay(hWndD3D, pD3D, rtWidth, rtHeight);
}