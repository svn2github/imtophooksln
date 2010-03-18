#include "stdafx.h"
#include "ARLayoutDXFilter.h"
#include "MyTestFilter.h"
#include "MyMediaSample.h"
#include "ARLayoutDXDisplay.h"
#include "ARLayoutDXProp.h"
#include "MyARTagMediaSample.h"
#include "cv.h"
#include <map>
using namespace std;

ARLayoutDXFilter::ARLayoutDXFilter(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData)
: CMuxTransformFilter(NAME("ARLayoutDX Filter"), 0, CLSID_ARLayoutFilter)
{
	m_FrameRate = 30;
	m_ARMarkers = NULL;
	m_numMarker = 0;
	m_minMarkerWidth = 1.0;
	m_pARStrategyData = NULL;
	m_pROIImage = NULL;
	m_bLayoutChange = true;
}
ARLayoutDXFilter::~ARLayoutDXFilter()
{
	if (m_ARMarkers != NULL)
	{
		delete [] m_ARMarkers;
		m_ARMarkers = NULL;
	}
	m_numMarker = 0;
	if (m_pARStrategyData != NULL)
	{
		delete m_pARStrategyData;
		m_pARStrategyData = NULL;
	}
	if (m_pROIImage != NULL)
	{
		cvReleaseImage(&m_pROIImage);
		m_pROIImage = NULL;
	}
}

CUnknown *WINAPI ARLayoutDXFilter::CreateInstance(LPUNKNOWN punk, HRESULT *phr)
{
	ASSERT(phr);
	
	ARLayoutDXFilter *pNewObject = new ARLayoutDXFilter(punk, phr, FALSE);

	if(pNewObject == NULL) {
		if (phr)
			*phr = E_OUTOFMEMORY;
	}

	return pNewObject;
}

HRESULT ARLayoutDXFilter::NonDelegatingQueryInterface(REFIID iid, void **ppv)
{
	if (iid == IID_IARLayoutDXFilter) 
	{
		return GetInterface(static_cast<IARLayoutDXFilter*>(this), ppv);
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

HRESULT ARLayoutDXFilter::CreatePins()
{
	HRESULT hr;
	if (m_pStreamPins.size() < 1 || m_pOutputPins.size() < 2) {
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


		CMuxTransformInputPin* pInput0 = new CMuxTransformInputPin(NAME("CMuxTransform input pin"),
			this,              // Owner filter
			&hr,               // Result code
			L"config");      // Pin name

		CMuxTransformStream* pOutput0 = new CMuxTransformStream(NAME("CMuxTransform stream pin"),
			&hr,              
			this,               
			L"Layout");      

		CMuxTransformOutputPin* pOutput1 = new CSourceOutputPin(NAME("ARLayout Markinfo pin"),
			this,
			&hr,                             
			L"markinfo");     

		CMuxTransformOutputPin* pOutput2 = new CSourceOutputPin(NAME("ARLayout ROI pin"),
			this,
			&hr,                             
			L"ROI");     
		m_pInputPins.push_back(pInput0);
		m_pStreamPins.push_back(pOutput0);
		m_pOutputPins.push_back(pOutput1);
		m_pOutputPins.push_back(pOutput2);

		if (m_pD3DDisplay == NULL)
		{
			initD3D(800, 600);
			initARMarkers();
			CreateROIImage(800, 600);
		}
	}
	return S_OK;
}
HRESULT ARLayoutDXFilter::Receive(IMediaSample *pSample, const IPin* pReceivePin)
{
	if (m_pInputPins.size() > 0 && pReceivePin == m_pInputPins[0])
	{
		ReceiveConfig(pSample, pReceivePin);
	}
	return S_OK;
}
HRESULT ARLayoutDXFilter::ReceiveConfig(IMediaSample *pSample, const IPin* pReceivePin)
{
	ARLayoutStartegyData* sData = NULL;
	pSample->GetPointer((BYTE**)&sData);
	if (sData == NULL)
	{
		return S_FALSE;
	}
	CAutoLock lck(&m_csARStrategyData);
	if (m_pARStrategyData == NULL)
	{
		m_pARStrategyData = new ARLayoutStartegyData();
	}
	*m_pARStrategyData = *sData;

	return S_OK;
}
HRESULT ARLayoutDXFilter::ComputeROIs(const ARMultiMarkerInfoT* pMarkerConfig)
{
	HRESULT hr = S_OK;
	hr = SetRenderTarget();
	((ARLayoutDXDisplay*)m_pD3DDisplay)->RenderMask(pMarkerConfig, 1.25);
	hr = ResetRenderTarget();
	hr = CopyRenderTarget2OutputTexture();
	if (m_pOutTexture == NULL || m_pROIImage == NULL)
		return S_FALSE;
	LPDIRECT3DSURFACE9 pSurface = NULL;
	D3DSURFACE_DESC outDesc;
	D3DLOCKED_RECT d3dRect;
	m_pOutTexture->GetLevelDesc(0, &outDesc);
	m_pOutTexture->GetSurfaceLevel(0, &pSurface);
	pSurface->LockRect(&d3dRect, NULL, 0);
	
	IplImage* pcvImage = cvCreateImageHeader(
		cvSize(outDesc.Width, outDesc.Height), 8, 4);	
	pcvImage->imageData = (char*)d3dRect.pBits;
	cvCvtColor(pcvImage, m_pROIImage, CV_RGBA2GRAY);
	cvThreshold(m_pROIImage, m_pROIImage, 128, 255, CV_THRESH_BINARY);
	CvMemStorage* storage = cvCreateMemStorage(0);
	CvSeq* cont = 0; 
	
	
	cvFindContours(m_pROIImage, storage, &cont, sizeof(CvContour), CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE );

	m_ROIRects.clear();
	CvRect cvROIRect;
	fRECT fROIRect;
	int imgW = m_pROIImage->width; int imgH = m_pROIImage->height;
	if (imgW -1 <= 0 || imgH -1 <= 0 )
	{
		return E_FAIL;
	}
	for( ; cont != 0; cont = cont->h_next )	{
		int count = cont->total; // This is number point in contour
		cvROIRect = cvContourBoundingRect(cont);
		fROIRect.left = cvROIRect.x /(float)(imgW-1) ;
		fROIRect.top = cvROIRect.y /(float)(imgH -1);
		fROIRect.right = (cvROIRect.x + cvROIRect.width) / (float)(imgW-1);
		fROIRect.bottom = (cvROIRect.y + cvROIRect.height) / (float)(imgH-1);
		m_ROIRects.push_back(fROIRect);
	}

	cvReleaseImageHeader(&pcvImage);
	cvReleaseMemStorage(&storage);
	storage = NULL;
	pcvImage = NULL;
	pSurface->UnlockRect();
	pSurface->Release();
	pSurface = NULL;
	return S_OK;
}
HRESULT ARLayoutDXFilter::CreateROIImage(int width, int height)
{
	if (m_pROIImage != NULL)
	{
		cvReleaseImage(&m_pROIImage);
		m_pROIImage = NULL;
	}
	m_pROIImage = cvCreateImage(cvSize(800, 600), 8, 1);
	return S_OK;
}
HRESULT ARLayoutDXFilter::GetROIData(ROIData*& roiData)
{
	if (roiData != NULL)
	{
		delete roiData;
		roiData = NULL;
	}
	roiData = new ROIData();

	if (m_ROIRects.size() <= 0)
	{
		roiData->m_pRECTs = NULL;
		roiData->m_nRECTs = 0;
	}
	else
	{
		roiData->m_pRECTs = new fRECT[m_ROIRects.size()];
		roiData->m_nRECTs = m_ROIRects.size();
		for (int i=0; i < m_ROIRects.size(); i++)
		{
			memcpy((void*)&(roiData->m_pRECTs[i]),  (void*)&(m_ROIRects.at(i)), sizeof(fRECT));
		}
	}
	return S_OK;
}

HRESULT ARLayoutDXFilter::FillBuffer(IMediaSample *pSamp, IPin* pPin)
{
	HRESULT hr = S_OK;
	if (m_pStreamPins.size() > 0 && m_pStreamPins[0] == pPin)
	{
		{
			ARLayoutStartegyData* strategyData = NULL;
			{
				CAutoLock lck(&m_csARStrategyData);
				if (m_pARStrategyData != NULL)
				{
					strategyData = new ARLayoutStartegyData();
					*strategyData = *m_pARStrategyData;
					delete m_pARStrategyData;
					m_pARStrategyData = NULL;
				}
			}
			if (strategyData != NULL)
			{
				bool bLayoutChange = false;
				DecideLayout(strategyData->camViews, strategyData->numCamView,
					strategyData->fingerRects, strategyData->numFingers, bLayoutChange);
				m_bLayoutChange = bLayoutChange || m_bLayoutChange;
			}
			if (m_bLayoutChange)
			{
				sendConfigData();
				delete strategyData;
				strategyData = NULL;
				if (!(m_pOutputPins.size() < 2 || m_pOutputPins[1] == NULL ||
					!m_pOutputPins[1]->IsConnected()))
				{
					CAutoLock lck(&m_csARMarker);
					ARMultiMarkerInfoT markerConfig;
					memset((void*)&markerConfig, 0 ,sizeof(ARMultiMarkerInfoT));
					markerConfig.marker = m_ARMarkers;
					markerConfig.marker_num = m_numMarker;
					ComputeROIs(&markerConfig);
					sendROIData();
				}
				m_bLayoutChange = false;
			}
		}
		hr = SetRenderTarget();
		if (FAILED(hr))
			return S_FALSE;
		{
			CAutoLock lck0(&m_csD3DDisplay);
			CAutoLock lck(&m_csARMarker);
			ARMultiMarkerInfoT markerConfig;
			memset((void*)&markerConfig, 0 ,sizeof(ARMultiMarkerInfoT));
			markerConfig.marker = m_ARMarkers;
			markerConfig.marker_num = m_numMarker;
			((ARLayoutDXDisplay*)m_pD3DDisplay)->Render(&markerConfig);
			
		}
		hr = ResetRenderTarget();
		if (FAILED(hr))
			return S_FALSE;

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
	}
	
	return hr;
}

HRESULT ARLayoutDXFilter::GetMediaType(int iPosition, const IPin* pPin, __inout CMediaType *pMediaType)
{
	if (m_pStreamPins.size() > 0 && m_pStreamPins[0] == pPin)
	{
		if (iPosition == 0 )
		{	
			if (m_pRenderTarget == NULL)
				return S_FALSE;
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
		if (iPosition == 1 )
		{	
			if (m_pOutTexture == NULL)
				return S_FALSE;
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
		else if (iPosition == 2)
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
	}
	if (m_pOutputPins.size() > 0 && m_pOutputPins[0] == pPin)
	{
		if (iPosition < 0  || iPosition > 0)
		{	
			return VFW_S_NO_MORE_ITEMS;
		}
		CMediaType mt;
		mt.SetType(&GUID_IMPRO_FeedbackTYPE);
		mt.SetSubtype(&GUID_ARLayoutConfigData);
		mt.SetSampleSize(sizeof(ARLayoutConfigData));
		*pMediaType = mt;
		return S_OK;
	}
	if (m_pOutputPins.size() > 1 && m_pOutputPins[1] == pPin)
	{
		if (iPosition < 0  || iPosition > 0)
		{	
			return VFW_S_NO_MORE_ITEMS;
		}
		CMediaType mt;
		mt.SetType(&GUID_IMPRO_FeedbackTYPE);
		mt.SetSubtype(&GUID_ROIData);
		mt.SetSampleSize(sizeof(ROIData));
		*pMediaType = mt;
		return S_OK;
	}
	return S_FALSE;
}
HRESULT ARLayoutDXFilter::CheckOutputType(const CMediaType* mtOut, const IPin* pPin)
{
	if (m_pStreamPins.size() > 0 && m_pStreamPins[0] == pPin)
	{
		CheckPointer(mtOut, E_POINTER);
		if (IsEqualGUID(*mtOut->Type(), GUID_D3DMEDIATYPE) && 
			IsEqualGUID(*mtOut->Subtype(), GUID_D3DXTEXTURE9_POINTER))
		{
			return NOERROR;
		}
		else if (IsEqualGUID(*mtOut->Type(), GUID_D3DMEDIATYPE) && 
			IsEqualGUID(*mtOut->Subtype(), GUID_D3DSHARE_RTTEXTURE_POINTER))
		{
			return NOERROR;
		}
		else if (IsEqualGUID(*mtOut->Type(), MEDIATYPE_Video) && 
			IsEqualGUID(*mtOut->Subtype(), MEDIASUBTYPE_RGB32))
		{
			return NOERROR;
		}
	}
	else if (m_pOutputPins.size() > 0 && m_pOutputPins[0] == pPin)
	{
		CMediaType mt;
		if (IsEqualGUID(*mtOut->Type(), GUID_IMPRO_FeedbackTYPE) && 
			IsEqualGUID(*mtOut->Subtype(), GUID_ARLayoutConfigData))
		{
			return NOERROR;
		}
	}
	else if (m_pOutputPins.size() > 1 && m_pOutputPins[1] == pPin)
	{
		CMediaType mt;
		if (IsEqualGUID(*mtOut->Type(), GUID_IMPRO_FeedbackTYPE) && 
			IsEqualGUID(*mtOut->Subtype(), GUID_ROIData))
		{
			return NOERROR;
		}
	}
	return E_FAIL;
}

HRESULT ARLayoutDXFilter::CheckInputType(const CMediaType* mtIn, const IPin* pPin)
{
	if (m_pInputPins.size() > 0 && m_pInputPins[0] == pPin)
	{
		CheckPointer(mtIn, E_POINTER);
		if (IsEqualGUID(*mtIn->Type(), GUID_IMPRO_FeedbackTYPE) && 
			IsEqualGUID(*mtIn->Subtype(), GUID_ARLayoutStartegyData))
		{
			return NOERROR;
		}
	}
	return E_FAIL;
}

HRESULT ARLayoutDXFilter::DecideBufferSize(
	IMemAllocator * pAlloc, const IPin* pOutPin,
	__inout ALLOCATOR_PROPERTIES *pProp)
{
	HRESULT hr;
	if (m_pStreamPins.size() > 0 && pOutPin == m_pStreamPins[0])
	{
		CMediaType mt = ((CMuxTransformStream*)pOutPin)->CurrentMediaType();
		if ((IsEqualGUID(*mt.Type(), GUID_D3DMEDIATYPE) && 
			(IsEqualGUID(*mt.Subtype(), GUID_D3DXTEXTURE9_POINTER) || 
			IsEqualGUID(*mt.Subtype(), GUID_D3DSHARE_RTTEXTURE_POINTER))) ||
			((IsEqualGUID(*mt.Type(), MEDIATYPE_Video) && 
			(IsEqualGUID(*mt.Subtype(), MEDIASUBTYPE_RGB32)))))
		{
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
			return S_OK;
		}
	}

	if ((m_pOutputPins.size() > 0 && pOutPin == m_pOutputPins[0]) || 
		(m_pOutputPins.size() > 1 && pOutPin == m_pOutputPins[1]))
	{
		CMediaType mt = ((CMuxTransformOutputPin*)pOutPin)->CurrentMediaType();
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
		return S_OK;
		
	}
	return E_FAIL;
}
HRESULT ARLayoutDXFilter::StartStreaming()
{	
	sendConfigData();
	return __super::StartStreaming();
}
MS3DDisplay* ARLayoutDXFilter::Create3DDisplay(IDirect3D9* pD3D, int rtWidth, int rtHeight)
{
	return new ARLayoutDXDisplay(pD3D, rtWidth, rtHeight);
}

MS3DDisplay* ARLayoutDXFilter::Create3DDisplay(IDirect3DDevice9* pDevice, int rtWidth, int rtHeight)
{
	return new ARLayoutDXDisplay(pDevice, rtWidth, rtHeight);
}
HRESULT ARLayoutDXFilter::QueryD3DDevice(IDXBasePin* pPin, IDirect3DDevice9*& outDevice)
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

HRESULT ARLayoutDXFilter::QueryD3DDeviceCS(IDXBasePin* pPin, CCritSec*& cs)
{
	cs = &m_csD3DDisplay;
	return S_OK;
}
HRESULT ARLayoutDXFilter::GetPages(CAUUID *pPages)
{
	pPages->cElems = 1;
	pPages->pElems = (GUID*)CoTaskMemAlloc(sizeof(GUID));
	if (pPages->pElems == NULL) 
	{
		return E_OUTOFMEMORY;
	}
	pPages->pElems[0] = CLSID_ARLayoutPropPage;
	return S_OK;
}

bool ARLayoutDXFilter::initARMarkers(UINT numLevel, UINT intMarkerBits, UINT intBorderBits, float intWidthBits)
{
	CAutoLock lck(&m_csARMarker);

	float markerBits = intMarkerBits;
	float borderBits = intBorderBits;
	float WidthBits = intWidthBits;
	int numMarker = 0;
	for (int level = 1; level <= numLevel; level++)
	{
		float markerWidth = markerBits/WidthBits/level;
		int numX = cvRound( 1.0  / (markerWidth + borderBits/WidthBits/level));
		int numY = numX;
		numMarker += numX * numY;
	}
	if (numMarker > NUMMARKER)
	{
		return false;
	}
	m_numMarker = numMarker;
	m_minMarkerWidth = 1.0;

	if (m_ARMarkers != NULL)
	{
		delete [] m_ARMarkers;
		m_ARMarkers = NULL;
	}

	m_numMarker = numMarker;
	m_ARMarkers = new ARMultiEachMarkerInfoT[m_numMarker];
	
	memset((void*)m_ARMarkers, 0, sizeof(ARMultiEachMarkerInfoT)*m_numMarker);
	int idx = -1;
	for (int level = 1; level <= numLevel; level++)
	{
		float markerWidth = markerBits/WidthBits/level;
		if (markerWidth < m_minMarkerWidth)
		{
			m_minMarkerWidth = markerWidth;
		}
		int numX = cvRound( 1.0  / (markerWidth + borderBits/WidthBits/level));
		int numY = numX;
		for (int i = 0; i < numY; i++)
		{
			for ( int j = 0; j < numX; j++ )
			{		
				idx++;
				m_ARMarkers[idx].patt_id = idx;
				m_ARMarkers[idx].visible = (level == 1);
				m_ARMarkers[idx].width = markerWidth;	
				m_ARMarkers[idx].center[0] = markerWidth*0.5;
				m_ARMarkers[idx].center[1] = -markerWidth*0.5;
				m_ARMarkers[idx].trans[0][0] = 1.0; m_ARMarkers[idx].trans[0][1] = 0.0; m_ARMarkers[idx].trans[0][2] = 0.0; m_ARMarkers[idx].trans[0][3] = 0 + m_ARMarkers[idx].width*j + markerWidth/markerBits*(2*j+1);
				m_ARMarkers[idx].trans[1][0] = 0.0; m_ARMarkers[idx].trans[1][1] = 1.0; m_ARMarkers[idx].trans[1][2] = 0.0; m_ARMarkers[idx].trans[1][3] = 0 - m_ARMarkers[idx].width*i - markerWidth/markerBits*(2*i+1);
				m_ARMarkers[idx].trans[2][0] = 0.0; m_ARMarkers[idx].trans[2][1] = 0.0; m_ARMarkers[idx].trans[2][2] = 1.0; m_ARMarkers[idx].trans[2][3] = 0;	
			}
		}
	}
	generateAllMarkerRect(m_ARMarkers, m_numMarker, m_allMarkerRects);
	generateIntersectTable(m_ARMarkers, m_numMarker, m_TagIntersectTable);
	sendConfigData();
	return true;
}
bool ARLayoutDXFilter::generateAllMarkerRect(ARMultiEachMarkerInfoT* ARMarkers, int numMarker, 
						   vector<fRECT>& allMarkerRects)
{
	allMarkerRects.clear();
	for (int idx = 0; idx < numMarker; idx++)
	{
		fRECT markerRect;
		GetARTag2DRect(&markerRect, &(ARMarkers[idx]));
		allMarkerRects.push_back(markerRect);
	}
	return true;
}
bool ARLayoutDXFilter::generateIntersectTable(ARMultiEachMarkerInfoT* ARMarkers, int numMarker,
							vector<vector<int>>& table)
{
	m_TagIntersectTable.clear();
	for (int idx =0; idx < numMarker; idx++)
	{
		vector<int> intersectList;
		ARMultiEachMarkerInfoT* curMarker = &(ARMarkers[idx]);
		fRECT curRect;
		GetARTag2DRect(&curRect, &(ARMarkers[idx]));
		for (int intersectIdx = 0 ; intersectIdx < numMarker; intersectIdx++)
		{
			if (intersectIdx == idx)
				continue;
			fRECT intersectRECT;
			GetARTag2DRect(&intersectRECT, &(ARMarkers[intersectIdx]));
			if (curRect.IsIntersect(intersectRECT))
			{
				intersectList.push_back(intersectIdx);
			}
		}
		m_TagIntersectTable.push_back(intersectList);
	}
	return true;
}

bool ARLayoutDXFilter::LoadConfigFromFile(WCHAR* path)
{
	CAutoLock lck(&m_csARMarker);
	try
	{
		if (m_ARMarkers != NULL)
		{
			delete [] m_ARMarkers;
			m_ARMarkers = NULL;
		}
		m_numMarker = 0;
		m_minMarkerWidth = 1.0;

		FILE* filestream = NULL;
		_wfopen_s(&filestream, path, L"r");
		if (filestream == NULL)
		{
			return false;
		}
		fwscanf_s(filestream, L"%d\n", &m_numMarker);
		m_ARMarkers = new ARMultiEachMarkerInfoT[m_numMarker];
		memset((void*)m_ARMarkers, 0, sizeof(ARMultiEachMarkerInfoT)* m_numMarker);
		for (int i = 0; i < m_numMarker; i++ )
		{
			double mat[3][4] = {0};
			double width = 0;
			double centerX = 0, centerY =0;
			fwscanf_s(filestream, L"%d\n", &(m_ARMarkers[i].patt_id));
			fwscanf_s(filestream, L"%d %lf \n", &(m_ARMarkers[i].visible), &width);
			fwscanf_s(filestream, L"%lf %lf \n", &centerX, &centerY);
			fwscanf_s(filestream, L"%lf %lf %lf %lf \n \
									%lf %lf %lf %lf \n \
									%lf %lf %lf %lf \n",
									&(mat[0][0]), &(mat[0][1]), &(mat[0][2]), &(mat[0][3]),
									&(mat[1][0]), &(mat[1][1]), &(mat[1][2]), &(mat[1][3]),
									&(mat[2][0]), &(mat[2][1]), &(mat[2][2]), &(mat[2][3])
			);
			m_ARMarkers[i].width = width;
			m_ARMarkers[i].center[0] = centerX;
			m_ARMarkers[i].center[1] = centerY;
			if (width < m_minMarkerWidth)
			{
				m_minMarkerWidth = width;
			}
			for (int row = 0; row < 3; row ++)
			{
				for (int col = 0; col < 4; col++)
				{
					m_ARMarkers[i].trans[row][col] = mat[row][col];
				}
			}
		}
		fclose(filestream);
	}
	catch (exception e)
	{
		initARMarkers(); //reinit Markers
		return false;
	}
	generateAllMarkerRect(m_ARMarkers, m_numMarker, m_allMarkerRects);
	generateIntersectTable(m_ARMarkers, m_numMarker, m_TagIntersectTable);
	return true;
}
bool ARLayoutDXFilter::SaveConfigToFile(WCHAR* path)
{
	CAutoLock lck(&m_csARMarker);
	FILE* filestream = NULL;
	_wfopen_s(&filestream, path, L"w");
	if (filestream == NULL)
	{
		return false;
	}
	fwprintf_s(filestream, L"%d\n", m_numMarker);
	for (int i = 0; i < m_numMarker; i++ )
	{
		fwprintf_s(filestream, L"%d\n", m_ARMarkers[i].patt_id);
		fwprintf_s(filestream, L"%d %f \n", m_ARMarkers[i].visible, m_ARMarkers[i].width);
		fwprintf_s(filestream, L"%f %f \n", m_ARMarkers[i].center[0], m_ARMarkers[i].center[1]);
		fwprintf_s(filestream, L"%f %f %f %f \n \
					%f %f %f %f \n \
					%f %f %f %f \n",
					m_ARMarkers[i].trans[0][0], m_ARMarkers[i].trans[0][1], m_ARMarkers[i].trans[0][2], m_ARMarkers[i].trans[0][3],
					m_ARMarkers[i].trans[1][0], m_ARMarkers[i].trans[1][1], m_ARMarkers[i].trans[1][2], m_ARMarkers[i].trans[1][3],
					m_ARMarkers[i].trans[2][0], m_ARMarkers[i].trans[2][1], m_ARMarkers[i].trans[2][2], m_ARMarkers[i].trans[2][3]
					);
	}
	fclose(filestream);
	return true;
}

bool ARLayoutDXFilter::DecideLayout(fRECT* camRects, UINT numCamRect, fRECT* fingerRects, 
									UINT numFingerRects,bool& bChanged, float fingerExtend)
{
	CAutoLock lck(&m_csARMarker);
	map<int, bool> decisionMap; // idx, visible, have decided?
	vector<int> undecideIdx;
	bChanged = false;
	for (int idx = 0; idx < m_numMarker; idx++)
	{
		undecideIdx.push_back(idx);
	}
	//Extenr Finger Rectangle

	for (int i=0; i< numFingerRects; i++)
	{
		fingerRects[i].left -= fingerExtend;
		fingerRects[i].right += fingerExtend;
		fingerRects[i].top -= fingerExtend;
		fingerRects[i].bottom += fingerExtend;
	}

	if (numFingerRects > 0 && fingerRects != NULL)
	{
		fRECT markerRect;
		for (int i = 0; i < numFingerRects; i++)
		{
			for (int iterIdx = 0; iterIdx < undecideIdx.size(); iterIdx++)
			{	
				int idx = undecideIdx.at(iterIdx);		
				markerRect = m_allMarkerRects[idx];
				if (markerRect.IsIntersect(fingerRects[i]))
				{
					decisionMap[idx] = false;
					undecideIdx.erase(undecideIdx.begin() + iterIdx);
					iterIdx--;
				}
			}
		
		}
	}
	/*
	if (numCamRect > 0 && camRects != NULL)
	{
		for (int i = 0 ; i < numCamRect; i++) //Clip out of boundary part
		{
			camRects[i].left = min((float)1.0, max((float)0.0, camRects[i].left));
			camRects[i].right = min((float)1.0, max((float)0.0, camRects[i].right));
			camRects[i].top = min((float)1.0, max((float)0.0, camRects[i].top));
			camRects[i].bottom = min((float)1.0, max((float)0.0, camRects[i].bottom));
		}
		
		for (int i = 0; i < numCamRect; i++) // for each cam view
		{
			float camViewWidth = abs(camRects->right - camRects->left);
			float camViewHeight = abs(camRects->bottom - camRects->top);
			if (camViewHeight <= 0 || camViewWidth <= 0)
			{
				continue;
			}
			float idealArea = max((float)(m_minMarkerWidth*m_minMarkerWidth*0.95), (float)(camViewWidth/3 * camViewHeight/3));
			for (int iterIdx = 0; iterIdx < undecideIdx.size(); iterIdx++)
			{
				int idx = undecideIdx.at(iterIdx);
				fRECT myRECT;
				myRECT = m_allMarkerRects[idx];
				float myArea = abs((myRECT.right - myRECT.left) * (myRECT.bottom - myRECT.top));
				if ((myArea < idealArea) && myRECT.IsIntersect(camRects[i]))  // in camview && area < ideaArea && not decided yet
				{
					bool bPlaceTaken = false;
					
					for (map<int, bool>::iterator iter = decisionMap.begin(); 
						iter != decisionMap.end(); iter++) // check if this place have be taken by other Tag
					{
						if (iter->second == false)
							continue;

						fRECT decidedRECT;
						decidedRECT = m_allMarkerRects[iter->first];
						if ( decidedRECT.IsIntersect(myRECT))
						{
							bPlaceTaken = true;
							break;
						}
					}
					if (bPlaceTaken)
					{
						decisionMap[idx] = false;
						undecideIdx.erase(undecideIdx.begin() + iterIdx);
						iterIdx--;
					}
					else
					{
						decisionMap[idx] = true;
						undecideIdx.erase(undecideIdx.begin() + iterIdx);
						iterIdx--;
					}
				}
			}
			
		}
	}
	*/
	for (int iterIdx = 0; iterIdx < undecideIdx.size(); iterIdx++)
	{
		int idx = undecideIdx.at(iterIdx);
		bool bPlaceTaken = false;
		for (int i = 0; i < m_TagIntersectTable[idx].size(); i++)
		{
			int intersectIdx = m_TagIntersectTable[idx][i];
			if (decisionMap.find(intersectIdx) != decisionMap.end())
			{
				if (decisionMap[m_TagIntersectTable[idx][i]] == true)
				{
					bPlaceTaken = true;
					break;
				}
			}
		}
		if (bPlaceTaken)
		{
			decisionMap[idx] = false;
			undecideIdx.erase(undecideIdx.begin() + iterIdx);
			iterIdx--;
		}
		else
		{
			decisionMap[idx] = true;
			undecideIdx.erase(undecideIdx.begin() + iterIdx);
			iterIdx--;
		}
	}
	
	for (map<int, bool>::iterator iter = decisionMap.begin(); 
		iter != decisionMap.end(); iter++)
	{
		if (m_ARMarkers[iter->first].visible != iter->second)
		{
			bChanged = true;
		}
		m_ARMarkers[iter->first].visible = iter->second;
	}
	return true;
}

bool ARLayoutDXFilter::GetARTag2DRect(fRECT* retRect, const ARMultiEachMarkerInfoT* pMarker, float fScale)
{
	if (retRect == NULL || pMarker == NULL)
	{
		return false;
	}
	D3DXMATRIX matMark, matT, matInvT, matS;
	D3DXMatrixIdentity(&matT);
	D3DXMatrixIdentity(&matInvT);
	D3DXMatrixScaling(&matS, fScale, fScale, fScale);
	D3DXMatrixIdentity(&matMark);
	for(int row=0; row < 3; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			matMark.m[col][row] = pMarker->trans[row][col];
		}
	}
	D3DXVECTOR3 v[4] = { D3DXVECTOR3(0,0,0), D3DXVECTOR3(0, -pMarker->width, 0),
		D3DXVECTOR3(pMarker->width, -pMarker->width, 0), D3DXVECTOR3(pMarker->width, 0, 0)};
	D3DXVECTOR3 center = (v[0] + v[1] + v[2] + v[3]) / 4.0;
	D3DXMatrixTranslation(&matT, - center.x, -center.y, -center.z);
	D3DXMatrixTranslation(&matInvT, center.x, center.y, center.z);
	matMark = matT * matS * matInvT * matMark;
	for (int i =0; i < 4; i++)
	{
		D3DXVec3TransformCoord(&v[i], &v[i], &matMark);
	}
	
	float minX = v[0].x; float maxX = v[0].x;
	float minY = v[0].y; float maxY = v[0].y;
	
	for (int i = 0; i < 4; i++)
	{
		if(v[i].x < minX)
		{
			minX = v[i].x;
		}
		if (v[i].x > maxX)
		{
			maxX = v[i].x;
		}
		if (v[i].y < minY)
		{
			minY = v[i].y;
		}
		if (v[i].y > maxY)
		{
			maxY = v[i].y;
		}
	}
	retRect->left = minX; retRect->right = maxX;
	retRect->top = -maxY; retRect->bottom = -minY;
	return true;
}

/*
bool fRECT::IsIntersect(const D3DXVECTOR2& pt)
{
	bool intersectX = false, intersectY = false;
	if ( pt.x > left && pt.x < right)
	{
		intersectX = true;
	}
	if ( pt.y > top && pt.y < bottom)
	{
		intersectY = true;
	}
	return (intersectX && intersectY);
}*/

ARMultiEachMarkerInfoT* ARLayoutDXFilter::GetARMarker(int id)
{
	ARMultiEachMarkerInfoT* ret = NULL;
	for (int i = 0 ; i < m_numMarker; i++)
	{
		if (m_ARMarkers[i].patt_id == id)
		{
			ret = &(m_ARMarkers[i]);
			break;
		}
	}
	return ret;
}

bool ARLayoutDXFilter::sendConfigData()
{
	if (m_pOutputPins.size() <= 0 || !m_pOutputPins[0]->IsConnected()) 
	{
		return false;
	}
	ARLayoutConfigData sendData;
	{
		CAutoLock lck(&m_csARMarker);
		sendData.m_ARMarkers = m_ARMarkers;
		sendData.m_numMarker = m_numMarker;

		IMemAllocator* pAllocator = m_pOutputPins[0]->Allocator();
		CMediaSample* pSendSample = NULL;
		pAllocator->GetBuffer((IMediaSample**)&pSendSample, NULL, NULL, 0);
		if (pSendSample == NULL)
		{
			sendData.m_ARMarkers = NULL;
			sendData.m_numMarker = 0;
			return S_FALSE;
		}
		pSendSample->SetPointer((BYTE*)&sendData, sizeof(ARLayoutConfigData));
		m_pOutputPins[0]->Deliver(pSendSample);
		sendData.m_ARMarkers = NULL;
		sendData.m_numMarker = 0;
		if (pSendSample != NULL)
		{
			pSendSample->Release();
			pSendSample = NULL;
		}
	}

	return true;
}
bool ARLayoutDXFilter::sendROIData()
{
	if (m_pOutputPins.size() <= 1 || !m_pOutputPins[1]->IsConnected()) 
	{
		return false;
	}
	ROIData* sendData = NULL;
	{
		CAutoLock lck(&m_csROIRects);
		GetROIData(sendData);
		if (sendData == NULL)
			return false;

		IMemAllocator* pAllocator = m_pOutputPins[1]->Allocator();
		CMediaSample* pSendSample = NULL;
		pAllocator->GetBuffer((IMediaSample**)&pSendSample, NULL, NULL, 0);
		if (pSendSample == NULL)
		{
			delete sendData;
			sendData = NULL;
			return S_FALSE;
		}

		pSendSample->SetPointer((BYTE*)sendData, sizeof(ROIData));
		m_pOutputPins[1]->Deliver(pSendSample);
		delete sendData;
		sendData = NULL;
		if (pSendSample != NULL)
		{
			pSendSample->Release();
			pSendSample = NULL;
		}
	}
	return true;
}
float ARLayoutDXFilter::GetFrameRateLimit(IPin* pPin)
{
	return GetFrameRate();
}
BOOL ARLayoutDXFilter::SetFrameRate(float fps)
{
	CAutoLock lck(&m_csFrameRate);
	if (fps <= 0)
	{
		return FALSE;
	}
	m_FrameRate = fps;
	return TRUE;
}
float ARLayoutDXFilter::GetFrameRate()
{
	CAutoLock lck(&m_csFrameRate);
	return m_FrameRate;
}

int ARLayoutDXFilter::GetNumMarker()
{	
	CAutoLock lck(&m_csARMarker);	
	return m_numMarker;
}

bool ARLayoutDXFilter::SetMarkerVisible(int idx, bool bVisible)
{	
	CAutoLock lck(&m_csARMarker);
	if (idx < 0 || idx >= m_numMarker)	
	{		
		return false;
	}	
	m_ARMarkers[idx].visible = bVisible;	
	return true;
}

bool ARLayoutDXFilter::SetMarkerVisibleByID(int id, bool bVisible)
{	
	CAutoLock lck(&m_csARMarker);
	for (int i =0 ; i < m_numMarker; i++)
	{
		if (m_ARMarkers[i].patt_id == id)
		{
			m_ARMarkers[i].visible = bVisible;
			return true;
		}
	}
	return false;
}
int ARLayoutDXFilter::GetMarkerID(int idx)
{
	CAutoLock lck(&m_csARMarker);
	if (idx < 0 || idx >= m_numMarker)	
	{		
		return -1;
	}	
	return m_ARMarkers[idx].patt_id;
}