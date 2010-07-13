#include "stdafx.h"
#include "ImProSyncFilter.h"
#include "GSD3DMediaType.h"
#include "GSMacro.h"
#include "cv.h"
#include "MyMediaSample.h"
#include "MyARTagMediaSample.h"

ImProSyncFilter::ImProSyncFilter(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData)
: GSDXMuxFilter(NAME("ImProSyncFilter"), 0, CLSID_ImProSyncFilter), CPersistStream(pOuter, phr)
{ 
	setDirty(false);
	setBlock(false);

}
ImProSyncFilter::~ImProSyncFilter()
{

}

CUnknown *WINAPI ImProSyncFilter::CreateInstance(LPUNKNOWN punk, HRESULT *phr)
{
	ASSERT(phr);
	// assuming we don't want to modify the data
	ImProSyncFilter *pNewObject = new ImProSyncFilter(punk, phr, FALSE);

	if(pNewObject == NULL) {
		if (phr)
			*phr = E_OUTOFMEMORY;
	}
	return pNewObject;
}

HRESULT ImProSyncFilter::NonDelegatingQueryInterface(REFIID iid, void **ppv)
{
	if (iid == IID_IImProSyncFilter) 
	{
		return GetInterface(static_cast<IImProSyncFilter*>(this), ppv);
	}
	else if (iid == IID_ISpecifyPropertyPages)
	{
		return GetInterface(
			static_cast<ISpecifyPropertyPages*>(this),	ppv);
	}
	else if (iid == IID_IPersistStream)
	{
		return GetInterface(static_cast<IPersistStream*>(this), ppv);
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

HRESULT ImProSyncFilter::CreatePins()
{
	HRESULT hr = S_OK;
	GSPIN_ACCEPT_MEDIATYPE camAccType[] =
	{
		GSPIN_ACCEPT_MEDIATYPE(MEDIATYPE_Video, MEDIASUBTYPE_RGB32, FORMAT_VideoInfo, FALSE),
		GSPIN_ACCEPT_MEDIATYPE(MEDIATYPE_Video, MEDIASUBTYPE_ARGB32, FORMAT_VideoInfo, FALSE)
	};
	GSPIN_ACCEPT_MEDIATYPE layoutDirtyAccType[] =
	{
		GSPIN_ACCEPT_MEDIATYPE(GUID_IMPRO_FeedbackTYPE, GUID_ARLayoutConfigData, FALSE)
	};
	GSPIN_ACCEPT_MEDIATYPE arlayoutAccType[] =
	{
		GSPIN_ACCEPT_MEDIATYPE(GSMEDIATYPE_GSDX11_SHAREDEVICE_MEDIATYPE, GSMEDIASUBTYPE_GSTEX2D_POINTER, GSFORMAT_DX11TEX2D_DESC, FALSE),
		GSPIN_ACCEPT_MEDIATYPE(GSMEDIATYPE_GSDX11_MEDIATYPE, GSMEDIASUBTYPE_GSTEX2D_POINTER, GSFORMAT_DX11TEX2D_DESC, FALSE),
		GSPIN_ACCEPT_MEDIATYPE(MEDIATYPE_Video, MEDIASUBTYPE_RGB32, FORMAT_VideoInfo, FALSE),
		GSPIN_ACCEPT_MEDIATYPE(MEDIATYPE_Video, MEDIASUBTYPE_ARGB32, FORMAT_VideoInfo, FALSE)
	};

	GSFILTER_INPUTPIN_DESC inputPinDesc[] = {
		GSFILTER_INPUTPIN_DESC(L"camInput", 0, GSINPUT_PIN, GSPIN_ACCEPT_MEDIATYPE_GROUP(camAccType, ARRAYSIZE(camAccType)), 
			GSFILTER_INPUTPIN_FUNCS(GSDXMuxFilter::PreReceive_InitSample, OnCamTransform, PostReceiveCamImg, 
			GSDXMuxFilter::CompleteConnect_ReconnectOutput, NULL)),
		GSFILTER_INPUTPIN_DESC(L"layoutDirty", 0, GSINPUT_PIN, GSPIN_ACCEPT_MEDIATYPE_GROUP(layoutDirtyAccType, ARRAYSIZE(layoutDirtyAccType)), 
			GSFILTER_INPUTPIN_FUNCS(ReceiveLayoutDirty, NULL, NULL,	NULL, NULL)),
		
		GSFILTER_INPUTPIN_DESC(L"layoutInput", 2, GSINPUT_PIN, GSPIN_ACCEPT_MEDIATYPE_GROUP(arlayoutAccType, ARRAYSIZE(arlayoutAccType)), 
			GSFILTER_INPUTPIN_FUNCS(GSDXMuxFilter::PreReceive_InitSample, GSDXMuxFilter::Transform_D3DRender, PostReceiveARLayout, 
			GSDXMuxFilter::CompleteConnect_InitD3D, GSDXMuxFilter::BreakConnect_ReleaseD3D)),
	};		

	GSOUTPIN_ACCEPT_MEDIATYPE camoutAccType[] =
	{
		GSOUTPIN_ACCEPT_MEDIATYPE(MEDIATYPE_Video, MEDIASUBTYPE_RGB32, FORMAT_VideoInfo, FALSE, GSREF_INPUT_PIN, 0, 0, 0)
	};

	GSOUTPIN_ACCEPT_MEDIATYPE layoutCfgAccType[] =
	{
		GSOUTPIN_ACCEPT_MEDIATYPE(GUID_IMPRO_FeedbackTYPE, GUID_ARLayoutConfigData, FALSE, GSREF_ACCEPT_MEDIATYPE, sizeof(ARLayoutConfigData), 0, 0)
	};

	GSOUTPIN_ACCEPT_MEDIATYPE layoutRenderAccType[] =
	{
		GSOUTPIN_ACCEPT_MEDIATYPE(GSMEDIATYPE_GSDX11_SHAREDEVICE_MEDIATYPE, GSMEDIASUBTYPE_GSTEX2D_POINTER, GSFORMAT_DX11TEX2D_DESC, FALSE, GSREF_RENDERTARGET, 0, 0, 0),
		GSOUTPIN_ACCEPT_MEDIATYPE(GSMEDIATYPE_GSDX11_MEDIATYPE, GSMEDIASUBTYPE_GSTEX2D_POINTER, GSFORMAT_DX11TEX2D_DESC, FALSE, GSREF_RENDERTARGET, 0, 0, 0),
		GSOUTPIN_ACCEPT_MEDIATYPE(MEDIATYPE_Video, MEDIASUBTYPE_RGB32, FORMAT_VideoInfo, FALSE, GSREF_RENDERTARGET, 0, 0, 0)
	};

	GSFILTER_OUTPUTPIN_DESC outPinDesc[] = {
		GSFILTER_OUTPUTPIN_DESC(L"camOut", 0, GSOUTPUT_PIN, GSOUTPIN_ACCEPT_MEDIATYPE_GROUP(camoutAccType, ARRAYSIZE(camoutAccType)), GSFILTER_OUTPUTPIN_FUNCS(NULL, NULL)),
		GSFILTER_OUTPUTPIN_DESC(L"layoutCfg", 1, GSOUTPUT_PIN, GSOUTPIN_ACCEPT_MEDIATYPE_GROUP(layoutCfgAccType, ARRAYSIZE(layoutCfgAccType)), GSFILTER_OUTPUTPIN_FUNCS(NULL, NULL)),
		GSFILTER_OUTPUTPIN_DESC(L"layoutRender", 0, GSOUTPUT_PIN, GSOUTPIN_ACCEPT_MEDIATYPE_GROUP(layoutRenderAccType, ARRAYSIZE(layoutRenderAccType)), GSFILTER_OUTPUTPIN_FUNCS(NULL, NULL)),

	};
	hr = _CreatePins(inputPinDesc, ARRAYSIZE(inputPinDesc), outPinDesc, ARRAYSIZE(outPinDesc), NULL, 0);
	return hr;
}

HRESULT ImProSyncFilter::GetPages(CAUUID *pPages)
{
	pPages->cElems = 1;
	pPages->pElems = (GUID*)CoTaskMemAlloc(sizeof(GUID));
	if (pPages->pElems == NULL) 
	{
		return E_OUTOFMEMORY;
	}
	pPages->pElems[0] = CLSID_ImProSyncFilterProp;
	return S_OK;
}

HRESULT ImProSyncFilter::GetName(WCHAR* name, UINT szName)
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

HRESULT ImProSyncFilter::SaveToFile(WCHAR* path)
{
	return S_OK;
}

HRESULT ImProSyncFilter::LoadFromFile(WCHAR* path)
{
	return S_OK;
}

HRESULT ImProSyncFilter::GetClassID(__out CLSID *pClsID)
{
	if (pClsID == NULL)
		return E_INVALIDARG;
	*pClsID = CLSID_ImProSyncFilter;
	return S_OK;
}

HRESULT ImProSyncFilter::WriteToStream(IStream *pStream)
{
	if (pStream == NULL)
		return E_INVALIDARG;
	return S_OK;
}

HRESULT ImProSyncFilter::ReadFromStream(IStream *pStream)
{
	if (pStream == NULL)
		return E_INVALIDARG;
	return S_OK;
}

int ImProSyncFilter::SizeMax()
{
	return 0;
}

HRESULT ImProSyncFilter::OnCamTransform(void* self, IMediaSample *pInSample, CMediaType* inMT, 
										   IMediaSample *pOutSample, CMediaType* outMT)
{
	if (self == NULL || pInSample == NULL || pOutSample == NULL || inMT == NULL || outMT == NULL)
	{
		return E_FAIL;
	}
	HRESULT hr = S_OK;
	ImProSyncFilter* pSelf = (ImProSyncFilter*)(GSDXMuxFilter*)self;
	
	hr = GSMuxFilter::Transform_MediaSampleCopy(self, pInSample, inMT, pOutSample, outMT);
	return hr;
}


HRESULT ImProSyncFilter::ReceiveLayoutDirty(void* self, IMediaSample *pSample, const IPin* pReceivePin, IMediaSample*& pOutSample)
{
	if (self == NULL || pSample == NULL || pReceivePin == NULL)
	{
		return E_FAIL;
	}
	ImProSyncFilter* pSelf = (ImProSyncFilter*)(GSMuxFilter*)self;
	HRESULT hr = S_OK;
	UINT pinIdx = 0;
	GSPIN_TYPE pinType = GSINPUT_PIN;
	hr = pSelf->_GetPinIdx(pReceivePin, pinIdx, pinType);
	if (FAILED(hr) || pinType != GSINPUT_PIN)
		return E_FAIL;
	if (pinIdx >= pSelf->m_pInputPinDesc.size())
		return E_FAIL;

	CAutoLock lck(&pSelf->locMarkerInfo);
	ARLayoutConfigData* pARTagResult = NULL;
	pSample->GetPointer((BYTE**)&pARTagResult);
	if (pARTagResult == NULL)
	{
		return S_FALSE;
	}
	pSelf->tagConfig = *pARTagResult;

	pSelf->setDirty(true);

	return S_OK;
}

HRESULT ImProSyncFilter::PostReceiveCamImg(void* self, IMediaSample *pOutSample, const IPin* pOutputPin, HRESULT preHr)
{
	if (self == NULL || pOutSample == NULL || pOutputPin == NULL)
	{
		return E_FAIL;
	}
	
	ImProSyncFilter* pSelf = (ImProSyncFilter*)(GSMuxFilter*)self;
	HRESULT hr = S_OK;
	
	if(pSelf->getBlock() == true){   // if block not to send Camera image
 		return hr;
	}

	if (FAILED(preHr)) {
		DbgLog((LOG_TRACE,1,TEXT("Error from transform")));
	} 
	else
	{
		
		if (preHr == NOERROR) {
			hr = ((GSMuxOutputPin*)pOutputPin)->Deliver(pOutSample);// m_pInputPin->Receive(pOutSample);
			pSelf->m_bSampleSkipped = FALSE;	// last thing no longer dropped
		}
		else
		{
			if (S_FALSE == preHr)
			{
				SAFE_RELEASE(pOutSample);
				pSelf->m_bSampleSkipped = TRUE;
				if (!pSelf->m_bQualityChanged) {
					pSelf->NotifyEvent(EC_QUALITY_CHANGE,0,0);
					pSelf->m_bQualityChanged = TRUE;
				}
				return NOERROR;
			}
		}
	}
	return hr;
}

HRESULT ImProSyncFilter::PostReceiveARLayout(void* self, IMediaSample *pOutSample, const IPin* pOutputPin, HRESULT preHr)
{
	if (self == NULL || pOutSample == NULL || pOutputPin == NULL)
	{
		return E_FAIL;
	}
	
	ImProSyncFilter* pSelf = (ImProSyncFilter*)(GSMuxFilter*)self;
	CMediaSample* pOutSampleConfig = NULL ;
	ARLayoutConfigData sendData ;
	GSMuxOutputPin* pConfigOutputPin = pSelf->m_pOutputPins[1];   // get the Dirty output Pin

	HRESULT hr = S_OK;
	
	if (pSelf->getDirty() == true){
		pSelf->setBlock(true);
		
		CAutoLock lck(&pSelf->locMarkerInfo);
		sendData.m_ARMarkers = pSelf->tagConfig.m_ARMarkers;
		sendData.m_numMarker = pSelf->tagConfig.m_numMarker;

		IMemAllocator* pAllocator = pSelf->m_pOutputPins[1]->Allocator();

		pAllocator->GetBuffer((IMediaSample**)&pOutSampleConfig, NULL, NULL, 0);
		if (pOutSampleConfig == NULL)
		{
			sendData.m_ARMarkers = NULL;
			sendData.m_numMarker = 0;
			return S_FALSE;
		}

		pOutSampleConfig->SetPointer((BYTE*)&sendData, sizeof(ARLayoutConfigData));		
	}

	if (FAILED(preHr)) {
		DbgLog((LOG_TRACE,1,TEXT("Error from transform")));
	} 

	else
	{

		if (preHr == NOERROR) {
			if(pSelf->getDirty() == true){
				hr =pConfigOutputPin->Deliver(pOutSampleConfig);// m_pInputPin->Receive(pOutSample);
				pSelf->setDirty(false);
			}

			hr = ((GSMuxOutputPin*)pOutputPin)->Deliver(pOutSample);// m_pInputPin->Receive(pOutSample);
			pSelf->m_bSampleSkipped = FALSE;	// last thing no longer dropped
			pSelf->setBlock(false);
		
		}
		else
		{
			if (S_FALSE == preHr)
			{
				SAFE_RELEASE(pOutSample);
				pSelf->m_bSampleSkipped = TRUE;
				if (!pSelf->m_bQualityChanged) {
					pSelf->NotifyEvent(EC_QUALITY_CHANGE,0,0);
					pSelf->m_bQualityChanged = TRUE;
				}
				return NOERROR;
			}
		}
		
		
	}

	sendData.m_ARMarkers = NULL;
	sendData.m_numMarker = 0;

	if (pOutSampleConfig != NULL)
	{
		pOutSampleConfig->Release();
		pOutSampleConfig = NULL;
	}
	return hr;
}

bool ImProSyncFilter::getDirty(){
	CAutoLock lck(&locDirty);
	return Dirty;
}

HRESULT ImProSyncFilter::setDirty(bool isDirty){
	CAutoLock lck(&locDirty);
	Dirty = isDirty;
	return S_OK;
}

bool ImProSyncFilter::getBlock(){
	CAutoLock lck(&locBlock);
	return Block;
}

HRESULT ImProSyncFilter::setBlock(bool isBlock){
	CAutoLock lck(&locBlock);
	Block = isBlock;
	return S_OK;
}

