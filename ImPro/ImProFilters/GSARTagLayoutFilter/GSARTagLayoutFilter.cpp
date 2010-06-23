#include "stdafx.h"
#include "GSARTagLayoutFilter.h"
#include "GSD3DMediaType.h"
#include "GSMacro.h"
#include "GSMediaType.h"
#include "MyMediaSample.h"
#include "GSARTagLayoutDisplay.h"
#include "highgui.h"
extern HMODULE GetModule();
GSARTagLayoutFilter::GSARTagLayoutFilter(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData)
: GSDXMuxFilter(NAME("GSSimpleDX Filter"), 0, CLSID_GSARTagLayoutFilter)
{ 
	m_bufW = 800;
	m_bufH = 600;
	m_FPSLimit = 60;
	m_pStrategyData = NULL;
	m_bLayoutChange = TRUE;
	m_pROIImg = NULL;
}
GSARTagLayoutFilter::~GSARTagLayoutFilter()
{
	SAFE_DELETE(m_pStrategyData);
	if (m_pROIImg != NULL)
	{
		cvReleaseImage(&m_pROIImg);
		m_pROIImg = NULL;
	}
}

CUnknown *WINAPI GSARTagLayoutFilter::CreateInstance(LPUNKNOWN punk, HRESULT *phr)
{
	ASSERT(phr);
	// assuming we don't want to modify the data
	GSARTagLayoutFilter *pNewObject = new GSARTagLayoutFilter(punk, phr, FALSE);

	if(pNewObject == NULL) {
		if (phr)
			*phr = E_OUTOFMEMORY;
	}
	return pNewObject;
}

HRESULT GSARTagLayoutFilter::NonDelegatingQueryInterface(REFIID iid, void **ppv)
{
	if (iid == IID_IGSARTagLayoutFilter) 
	{
		return GetInterface(static_cast<IGSARTagLayoutFilter*>(this), ppv);
	}
	else if (iid == IID_ISpecifyPropertyPages)
	{
		return GetInterface(
			static_cast<ISpecifyPropertyPages*>(this),	ppv);
	}
	else if (iid == IID_IGSPersist)
	{
		return GetInterface(static_cast<IGSPersist*>(this), ppv);
	}
	else
	{
		// Call the parent class.
		return __super::NonDelegatingQueryInterface(iid, ppv);
	}
}

HRESULT GSARTagLayoutFilter::InitFilter()
{
	HRESULT hr = S_OK;
	hr = __super::InitFilter();
	if (FAILED(hr))
		return hr;
	WCHAR effectPath[MAX_PATH] = {0};

	hr = GetEffectFilePath(effectPath, MAX_PATH);
	if (FAILED(hr))
		return hr;
	hr = initD3D(effectPath, MAX_PATH, m_bufW, m_bufH, 0, 1, 1);
	if (FAILED(hr))
		return hr;

	return hr;
}
float GSARTagLayoutFilter::GetFrameRateLimit(IPin* pPin)
{
	CAutoLock lck(&m_csRenderPara);
	return m_FPSLimit;
}
HRESULT GSARTagLayoutFilter::CreatePins()
{
	HRESULT hr = S_OK;

	GSPIN_ACCEPT_MEDIATYPE cfgAccType[] =
	{
		GSPIN_ACCEPT_MEDIATYPE(GSMEDIATYPE_FILTER_CONFIG, GSMEDIASUBTYPE_GSARTagLayoutStrategy_CONFIG_PTR, FALSE)
	};
	GSOUTPIN_ACCEPT_MEDIATYPE outcfgAccType[] =
	{
		GSOUTPIN_ACCEPT_MEDIATYPE(GSMEDIATYPE_FILTER_CONFIG, GSMEDIASUBTYPE_GSARTagLayout_CONFIG, FALSE, GSREF_ACCEPT_MEDIATYPE, sizeof(GSARTagLayout), 0, 0),
		GSOUTPIN_ACCEPT_MEDIATYPE(GUID_IMPRO_FeedbackTYPE, GUID_ARLayoutConfigData, FALSE, GSREF_ACCEPT_MEDIATYPE, sizeof(ARLayoutConfigData), 0, 0)
	};
	GSOUTPIN_ACCEPT_MEDIATYPE roiAccType[] =
	{
		GSOUTPIN_ACCEPT_MEDIATYPE(GUID_IMPRO_FeedbackTYPE, GUID_ROIData, FALSE, GSREF_ACCEPT_MEDIATYPE, sizeof(ROIData), 0, 0)
		
	};
	GSOUTPIN_ACCEPT_MEDIATYPE outAccType[] =
	{
		GSOUTPIN_ACCEPT_MEDIATYPE(GSMEDIATYPE_GSDX11_SHAREDEVICE_MEDIATYPE, GSMEDIASUBTYPE_GSTEX2D_POINTER, GSFORMAT_DX11TEX2D_DESC, FALSE, GSREF_RENDERTARGET, 0, 0, 0),
		GSOUTPIN_ACCEPT_MEDIATYPE(GSMEDIATYPE_GSDX11_MEDIATYPE, GSMEDIASUBTYPE_GSTEX2D_POINTER, GSFORMAT_DX11TEX2D_DESC, FALSE, GSREF_RENDERTARGET, 0, 0, 0),
		GSOUTPIN_ACCEPT_MEDIATYPE(MEDIATYPE_Video, MEDIASUBTYPE_RGB32, FORMAT_VideoInfo, FALSE, GSREF_RENDERTARGET, 0, 0, 0),
		GSOUTPIN_ACCEPT_MEDIATYPE(MEDIATYPE_Video, MEDIASUBTYPE_RGB32, GUID_NULL, FALSE, GSREF_RENDERTARGET, 0, 0, 0),
		GSOUTPIN_ACCEPT_MEDIATYPE(MEDIATYPE_Video, MEDIASUBTYPE_ARGB32, FORMAT_VideoInfo, FALSE, GSREF_RENDERTARGET, 0, 0, 0),
		GSOUTPIN_ACCEPT_MEDIATYPE(MEDIATYPE_Video, MEDIASUBTYPE_ARGB32, GUID_NULL, FALSE, GSREF_RENDERTARGET, 0, 0, 0)
	};

	GSFILTER_INPUTPIN_DESC inputPinDesc[] = {
		GSFILTER_INPUTPIN_DESC(L"config", 0, GSINPUT_PIN, GSPIN_ACCEPT_MEDIATYPE_GROUP(cfgAccType, ARRAYSIZE(cfgAccType)), 
			GSFILTER_INPUTPIN_FUNCS(GSARTagLayoutFilter::PreReceive_ReceiveConfig, NULL, NULL, NULL, NULL))
	};		

	GSFILTER_OUTPUTPIN_DESC outputPinDesc[] = {
		GSFILTER_OUTPUTPIN_DESC(L"layout", 0, GSOUTPUT_PIN, GSOUTPIN_ACCEPT_MEDIATYPE_GROUP(outcfgAccType, ARRAYSIZE(outcfgAccType)), 
			GSFILTER_OUTPUTPIN_FUNCS(NULL, NULL)),
		GSFILTER_OUTPUTPIN_DESC(L"ROI", 0, GSOUTPUT_PIN, GSOUTPIN_ACCEPT_MEDIATYPE_GROUP(roiAccType, ARRAYSIZE(roiAccType)), 
			GSFILTER_OUTPUTPIN_FUNCS(NULL, NULL))
	};		


	GSFILTER_STREAMPIN_DESC streamPinDesc[] = {
		GSFILTER_STREAMPIN_DESC(L"output", 0, GSSTREAM_PIN, GSOUTPIN_ACCEPT_MEDIATYPE_GROUP(outAccType, ARRAYSIZE(outAccType)), GSFILTER_STREAMPIN_FUNCS(OnFillBuffer, NULL, NULL))
	};

	hr = _CreatePins(inputPinDesc, ARRAYSIZE(inputPinDesc),outputPinDesc, ARRAYSIZE(outputPinDesc), streamPinDesc, ARRAYSIZE(streamPinDesc));

	return hr;
}
HRESULT GSARTagLayoutFilter::_CreatePins(GSFILTER_INPUTPIN_DESC* inDesc, UINT szIn, 
								   GSFILTER_OUTPUTPIN_DESC* outDesc, UINT szOut, GSFILTER_STREAMPIN_DESC* streamDesc, UINT szStream )
{
	_ClearPins();
	HRESULT hr = S_OK;
	for (int i =0; i < szIn; i++)
	{
		GSMuxInputPin* pInputPin = new GSDXMuxInputPin(NAME("GSMuxInputPin"), this, &hr, inDesc[i].pinName);
		m_pInputPins.push_back(pInputPin);
		GSFILTER_INPUTPIN_DESC* pInputPinDesc = new GSFILTER_INPUTPIN_DESC();
		*pInputPinDesc = inDesc[i];
		m_pInputPinDesc.push_back(pInputPinDesc);
	}
	for (int i =0; i < szOut; i++)
	{
		GSMuxOutputPin* pOutputPin = new GSSourceOutputPin(NAME("GSSourceOutputPin"), this, &hr, outDesc[i].pinName);
		m_pOutputPins.push_back(pOutputPin);
		GSFILTER_OUTPUTPIN_DESC* pOutputPinDesc = new GSFILTER_OUTPUTPIN_DESC();
		*pOutputPinDesc = outDesc[i];
		m_pOutputPinDesc.push_back(pOutputPinDesc);
	}
	for (int i =0; i < szStream; i++)
	{
		GSMuxStream* pStreamPin = new GSDXMuxStream(NAME("GSMuxStream"), this, &hr, streamDesc[i].pinName);
		m_pStreamPins.push_back(pStreamPin);
		GSFILTER_STREAMPIN_DESC* pStreamPinDesc = new GSFILTER_STREAMPIN_DESC();
		*pStreamPinDesc = streamDesc[i];
		m_pStreamPinDesc.push_back(pStreamPinDesc);
	}
	return S_OK;
}

HRESULT GSARTagLayoutFilter::GetPages(CAUUID *pPages)
{
	pPages->cElems = 1;
	pPages->pElems = (GUID*)CoTaskMemAlloc(sizeof(GUID));
	if (pPages->pElems == NULL) 
	{
		return E_OUTOFMEMORY;
	}
	pPages->pElems[0] = CLSID_GSARTagLayoutFilterProp;
	return S_OK;
}

HRESULT GSARTagLayoutFilter::GetName(WCHAR* name, UINT szName)
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

HRESULT GSARTagLayoutFilter::SaveToFile(WCHAR* path)
{
	CAutoLock lck(&m_csRenderPara);
	FILE* filestream = NULL;
	_wfopen_s(&filestream, path, L"w");
	if (filestream == NULL)
	{
		return E_FAIL;
	}
	float fps = GetFrameRate();
	fwprintf_s(filestream, L"%.0f \n", fps);
	float blackLevel = GetBlackLevel();
	fwprintf_s(filestream, L"%.2f \n", blackLevel);
	fclose(filestream);

	return S_OK;
}

HRESULT GSARTagLayoutFilter::LoadFromFile(WCHAR* path)
{
	CAutoLock lck(&m_csRenderPara);
	HRESULT hr = S_OK;
	FILE* filestream = NULL;
	_wfopen_s(&filestream, path, L"r");
	if (filestream == NULL)
	{
		return E_FAIL;
	}
	double fps = 60;
	fwscanf_s(filestream, L"%lf \n", &fps);
	double blacklevel = 0.5;
	fwscanf_s(filestream, L"%lf \n", &blacklevel);
	
	fclose(filestream);
	hr = SetFrameRate(fps);
	hr = SetBlackLevel(blacklevel);
	return S_OK;
}

HRESULT GSARTagLayoutFilter::PreReceive_ReceiveConfig(void* self, IMediaSample *pSample, const IPin* pReceivePin, IMediaSample*& pOutSample)
{
	if (self == NULL || pSample == NULL || pReceivePin == NULL)
	{
		return E_FAIL;
	}
	GSARTagLayoutFilter* pSelf = (GSARTagLayoutFilter*)(GSMuxFilter*)self;

	CAutoLock lck(&pSelf->m_csStrategyData);

	BYTE* pSampleBuf = NULL;
	pSample->GetPointer(&pSampleBuf);
	if (pSampleBuf == NULL)
		return E_FAIL;
	SAFE_DELETE(pSelf->m_pStrategyData);
	pSelf->m_pStrategyData = new GSARLayoutStartegyData();
	GSARLayoutStartegyData* pSampleData = *(GSARLayoutStartegyData**)pSampleBuf;
	*pSelf->m_pStrategyData = *pSampleData;
	return S_OK;
}
HRESULT GSARTagLayoutFilter::OnFillBuffer(void* self, IMediaSample *pSample, IPin* pPin)
{
	if (self == NULL ||pSample == NULL || pPin == NULL)
		return E_FAIL;
	
	GSARTagLayoutFilter* pSelf = (GSARTagLayoutFilter*)(GSMuxFilter*)self;

	if (pSelf->m_pD3DDisplay == NULL || pSelf->m_pRenderTargetList.size() <= 0)
		return E_FAIL;
	if (pSelf->m_pStreamPins.size() <= 0)
		return E_FAIL;

	HRESULT hr = S_OK;
	{
		CAutoLock lck(&pSelf->m_csStrategyData);
		if (pSelf->m_pStrategyData != NULL)
		{
			CAutoLock lck4(&pSelf->m_csLayoutChange);
			BOOL bLayoutChanged = TRUE;
			hr = ((GSARTagLayoutDisplay*)pSelf->m_pD3DDisplay)->DecideLayout(pSelf->m_pStrategyData->camViews, 
				pSelf->m_pStrategyData->numCamView, pSelf->m_pStrategyData->fingerRects, 
				pSelf->m_pStrategyData->numFingers, bLayoutChanged);
			pSelf->m_bLayoutChange = pSelf->m_bLayoutChange || bLayoutChanged;
			SAFE_DELETE(pSelf->m_pStrategyData);
			if (FAILED(hr))
				return hr;
		}
	}

	CAutoLock lck3(&pSelf->m_csRenderPara);
	GSAutoLock lck0(pSelf->m_pD3DDisplay->GetGSCritSec());
	GSAutoLock lck2(pSelf->m_pRenderTargetList.at(0)->GetGSCritSec());


	ID3D11RenderTargetView* pRTView = NULL;
	ID3D11DeviceContext* pDeviceContext = NULL;
	pDeviceContext = pSelf->m_pD3DDisplay->GetDeviceContext();
	hr = pSelf->m_pRenderTargetList.at(0)->GetRenderTargetView(pRTView);

	if (pRTView == NULL || pDeviceContext == NULL)
	{
		return E_FAIL;
	}
	hr = pSelf->m_pD3DDisplay->SetRenderTarget(pDeviceContext, pRTView);
	hr = pSelf->m_pD3DDisplay->Render();
	hr = pSelf->m_pD3DDisplay->ResetRenderTarget(pDeviceContext);	
	if (FAILED(hr))
		return S_FALSE;
	CMediaType mt = pSelf->m_pStreamPins.at(0)->CurrentMediaType();
	if (IsEqualGUID(*mt.Subtype(), MEDIASUBTYPE_RGB32) || IsEqualGUID(*mt.Subtype(), MEDIASUBTYPE_RGB32))
	{
		hr = pSelf->CopyGSTexture(pSelf->m_pRenderTargetList.at(0), pSelf->m_pOutTextureList.at(0));
		if (FAILED(hr))
			return hr;
		hr = pSelf->CopyGSTexture2Sample(pSelf->m_pOutTextureList.at(0), pSample, &mt);
	}
	else 
	{
		hr = pSelf->CopyGSTexture2Sample(pSelf->m_pRenderTargetList.at(0), pSample, &mt);
	}

	{
		CAutoLock lck(&pSelf->m_csStrategyData);
		if (pSelf->GetLayoutChanged())
		{
			hr = pSelf->SendLayoutData();
			if (FAILED(hr))
			{
				return E_FAIL;
			}
			pSelf->ComputeROIs();
			pSelf->sendROIData();
			pSelf->SetLayoutChanged(FALSE);
		}
	}
	return hr;

}

GS3DDisplay* GSARTagLayoutFilter::Create3DDisplay(UINT bufW, UINT bufH)
{
	HRESULT hr = S_OK;
	GSARTagLayoutDisplay* pDisplay = new GSARTagLayoutDisplay(bufW, bufH);
	hr = pDisplay->initARLayout(2, 8, 2, 80);
	return pDisplay;
}
GS3DDisplay* GSARTagLayoutFilter::Create3DDisplay(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext, IDXGISwapChain* pSwapChain)
{
	HRESULT hr = S_OK;
	GSARTagLayoutDisplay* pDisplay = new GSARTagLayoutDisplay(pDevice, pDeviceContext, pSwapChain);
	hr = pDisplay->initARLayout(2, 8, 2, 80);
	return pDisplay;
}


HRESULT GSARTagLayoutFilter::GetEffectFilePath(WCHAR* szPath, UINT szSize)
{
	if (szPath == NULL || szSize == 0)
		return E_FAIL;
	swprintf_s(szPath, szSize, L"../../fx/GSARTagLayout.fx");
	return S_OK;
}
HRESULT GSARTagLayoutFilter::SetFrameRate(float fps)
{
	if (fps <= 0)
		return E_FAIL;
	CAutoLock lck(&m_csRenderPara);
	m_FPSLimit = fps;
	return S_OK;	
}
float GSARTagLayoutFilter::GetFrameRate()
{
	return GetFrameRateLimit(NULL);
}

HRESULT GSARTagLayoutFilter::DecideLayout(GSBoundingBox2D* camRects, UINT numCamRect,
						  GSBoundingBox2D* fingerRects, UINT numFingerRects, BOOL& bLayoutChanged, float fingerExtend)
{
	if (m_pD3DDisplay == NULL)
		return E_FAIL;
	GSAutoLock lck(m_pD3DDisplay->GetGSCritSec());

	return ((GSARTagLayoutDisplay*)m_pD3DDisplay)->DecideLayout(camRects, numCamRect,
		fingerRects, numFingerRects, bLayoutChanged, fingerExtend);
}
HRESULT GSARTagLayoutFilter::initARLayout(UINT numLevel, UINT intMarkerBits, UINT intBorderBits, float intWidthBits)
{
	if (m_pD3DDisplay == NULL)
		return E_FAIL;
	GSAutoLock lck(m_pD3DDisplay->GetGSCritSec());
	return ((GSARTagLayoutDisplay*)m_pD3DDisplay)->initARLayout(numLevel, intMarkerBits, intBorderBits, intWidthBits);
}
int GSARTagLayoutFilter::GetNumMarker()
{
	if (m_pD3DDisplay == NULL)
		return E_FAIL;
	GSAutoLock lck(m_pD3DDisplay->GetGSCritSec());
	return ((GSARTagLayoutDisplay*)m_pD3DDisplay)->GetNumMarker();
}
HRESULT GSARTagLayoutFilter::SetMarkerVisible(int idx, BOOL bVisible)
{
	if (m_pD3DDisplay == NULL)
		return E_FAIL;
	GSAutoLock lck(m_pD3DDisplay->GetGSCritSec());
	
	return ((GSARTagLayoutDisplay*)m_pD3DDisplay)->SetMarkerVisible(idx, bVisible);
}
HRESULT GSARTagLayoutFilter::SetMarkerVisibleByID(int id, BOOL bVisible)
{
	if (m_pD3DDisplay == NULL)
		return E_FAIL;
	GSAutoLock lck(m_pD3DDisplay->GetGSCritSec());
	return ((GSARTagLayoutDisplay*)m_pD3DDisplay)->SetMarkerVisibleByID(id, bVisible);
}
int GSARTagLayoutFilter::GetMarkerID(int idx)
{
	if (m_pD3DDisplay == NULL)
		return E_FAIL;
	GSAutoLock lck(m_pD3DDisplay->GetGSCritSec());
	return ((GSARTagLayoutDisplay*)m_pD3DDisplay)->GetMarkerID(idx);
}
float GSARTagLayoutFilter::GetBlackLevel()
{
	if (m_pD3DDisplay == NULL)
		return E_FAIL;
	GSAutoLock lck(m_pD3DDisplay->GetGSCritSec());
	return ((GSARTagLayoutDisplay*)m_pD3DDisplay)->GetBlackLevel();
}
HRESULT GSARTagLayoutFilter::SetBlackLevel(float level)
{
	if (m_pD3DDisplay == NULL)
		return E_FAIL;
	GSAutoLock lck(m_pD3DDisplay->GetGSCritSec());
	return ((GSARTagLayoutDisplay*)m_pD3DDisplay)->SetBlackLevel(level);
}

BOOL GSARTagLayoutFilter::GetLayoutChanged()
{
	CAutoLock lck(&m_csLayoutChange);
	return m_bLayoutChange;
}
void GSARTagLayoutFilter::SetLayoutChanged(BOOL bChanged)
{
	CAutoLock lck(&m_csLayoutChange);
	m_bLayoutChange = bChanged;
}

HRESULT GSARTagLayoutFilter::ComputeROIs()
{
	HRESULT hr = S_OK;
	CAutoLock lck0(&m_csRenderPara);
	CAutoLock lck1(&m_csROIRects);
	if (m_pD3DDisplay == NULL)
		return E_FAIL;
	GSBoundingBox2D** pTagRects = ((GSARTagLayoutDisplay*)m_pD3DDisplay)->GetAllMarkerRects();
	if (pTagRects == NULL)
		return E_FAIL;
	GSARTagLayout* pLayout = NULL;
	((GSARTagLayoutDisplay*)m_pD3DDisplay)->GetLayout(pLayout);
	if (pLayout == NULL)
		return E_FAIL;
	if (m_pROIImg == NULL)
	{
		m_pROIImg = cvCreateImage(cvSize(320, 240), 8, 1);
	}
	int imgW = m_pROIImg->width; int imgH = m_pROIImg->height;
	if (imgW -1 <= 0 || imgH -1 <= 0 )
	{
		return E_FAIL;
	}
	cvDrawRect(m_pROIImg, cvPoint(0,0), cvPoint(m_pROIImg->width-1, m_pROIImg->height-1), cvScalar(255, 255, 255), -1);
	for (int i =0; i < pLayout->m_nARTag; i ++)
	{
		if (pLayout->m_pARTag[i].m_visible)
		{
			float w = (pTagRects[i]->RB.x - pTagRects[i]->LT.x);
			float h = (pTagRects[i]->RB.y - pTagRects[i]->LT.y);
			float p0X = max(0.0, pTagRects[i]->LT.x - w*0.13);
			float p0Y = max(0.0, pTagRects[i]->LT.y - h*0.13);
			float p1X = min(1.0, pTagRects[i]->RB.x + w*0.13);
			float p1Y = min(1.0, pTagRects[i]->RB.y + h*0.13);
			CvPoint p0 = cvPoint(p0X*(imgW-1), p0Y*(imgH-1));
			CvPoint p1 = cvPoint(p1X*(imgW-1), p1Y*(imgH-1));
			
			cvDrawRect(m_pROIImg, p0, p1, cvScalar(0,0,0), -1 );
		}
	}
	cvThreshold(m_pROIImg, m_pROIImg, 128, 255, CV_THRESH_BINARY);
	CvMemStorage* storage = cvCreateMemStorage(0);
	CvSeq* cont = 0; 

	cvFindContours(m_pROIImg, storage, &cont, sizeof(CvContour), CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE );
	m_ROIRects.clear();
	CvRect cvROIRect;
	fRECT fROIRect;

	
	for( ; cont != 0; cont = cont->h_next )	{
		int count = cont->total; // This is number point in contour
		cvROIRect = cvContourBoundingRect(cont);
		fROIRect.left = cvROIRect.x /(float)(imgW-1) ;
		fROIRect.top = cvROIRect.y /(float)(imgH -1);
		fROIRect.right = (cvROIRect.x + cvROIRect.width) / (float)(imgW-1);
		fROIRect.bottom = (cvROIRect.y + cvROIRect.height) / (float)(imgH-1);
		m_ROIRects.push_back(fROIRect);
	}

	cvReleaseMemStorage(&storage);
	storage = NULL;

	return S_OK;
}

HRESULT GSARTagLayoutFilter::GetROIData(ROIData*& roiData)
{
	CAutoLock lck(&m_csROIRects);
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


HRESULT GSARTagLayoutFilter::SendLayoutData()
{
	if (m_pD3DDisplay == NULL)
		return E_FAIL;
	GSARTagLayout* pLayout = NULL;
	((GSARTagLayoutDisplay*)m_pD3DDisplay)->GetLayout(pLayout);
	if (pLayout == NULL)
		return E_FAIL;
	
	if (m_pOutputPins.size() <= 0 || !m_pOutputPins[0]->IsConnected()) 
	{
		return S_FALSE;
	}
	CMediaType mt = m_pOutputPins[0]->CurrentMediaType();
	
	GSARTagLayout sendData0;
	ARLayoutConfigData* sendData1 = NULL;
	
	sendData0 = *pLayout;
	IMemAllocator* pAllocator = m_pOutputPins[0]->Allocator();
	CMediaSample* pSendSample = NULL;
	pAllocator->GetBuffer((IMediaSample**)&pSendSample, NULL, NULL, 0);
	if (pSendSample == NULL)
	{
		return E_FAIL;
	}
	

	if (IsEqualGUID(*mt.Type(), GUID_IMPRO_FeedbackTYPE) && IsEqualGUID(*mt.Subtype(), GUID_ARLayoutConfigData))
	{
		sendData1 = GSARTagLayout2ARLayoutConfig(&sendData0);
		pSendSample->SetPointer((BYTE*)sendData1, sizeof(ARLayoutConfigData));
	}
	else
	{
		pSendSample->SetPointer((BYTE*)&sendData0, sizeof(GSARTagLayout));
	}

	m_pOutputPins[0]->Deliver(pSendSample);
	SAFE_RELEASE(pSendSample);
	SAFE_DELETE(sendData1);
	return S_OK;
}

ARLayoutConfigData* GSARTagLayout2ARLayoutConfig(GSARTagLayout* inData)
{
	if (inData == NULL)
		return NULL;
	ARLayoutConfigData* ret = new ARLayoutConfigData();
	ret->m_numMarker = 0;
	ret->m_ARMarkers = NULL;
	if (inData->m_nARTag == 0)
		return ret;
	ret->m_numMarker = inData->m_nARTag;
	ret->m_ARMarkers = new ARMultiEachMarkerInfoT[ret->m_numMarker];

	for (int i =0; i < ret->m_numMarker; i++)
	{
		ret->m_ARMarkers[i].patt_id = inData->m_pARTag[i].m_tagID;
		ret->m_ARMarkers[i].visible = inData->m_pARTag[i].m_visible;
		GSBoundingBox2D bbox;
		inData->m_pARTag[i].GetBoundingBox2D(bbox);
		ret->m_ARMarkers[i].width = abs(bbox.RB.x - bbox.LT.x);
		float markerWidth = ret->m_ARMarkers[i].width;
		ret->m_ARMarkers[i].center[0] = markerWidth*0.5;
		ret->m_ARMarkers[i].center[1] = -markerWidth*0.5;

		for (int row =0; row < 3; row++)
		{
			for (int col = 0; col < 4; col++)
			{
				ret->m_ARMarkers[i].trans[row][col] = inData->m_pARTag[i].m_matTran[col*4 + row];
			}
		}
	}
	return ret;
}

bool GSARTagLayoutFilter::sendROIData()
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