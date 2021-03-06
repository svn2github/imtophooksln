#include "stdafx.h"
#include "GSFrameCaptureFilter.h"
#include "GSD3DMediaType.h"
#include "GSMacro.h"
#include "cv.h"
#include "highgui.h"
//#include "MyMediaSample.h"

GSFrameCaptureFilter::GSFrameCaptureFilter(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData)
: GSMuxFilter(NAME("GSFrameCaptureFilter"), 0, CLSID_GSFrameCaptureFilter)
{ 
	isSaveImg = FALSE;
	ImgCount = 0 ;
	GetCurrentDirectoryW(_MAX_PATH, wszCur);

}
GSFrameCaptureFilter::~GSFrameCaptureFilter()
{

}

CUnknown *WINAPI GSFrameCaptureFilter::CreateInstance(LPUNKNOWN punk, HRESULT *phr)
{
	ASSERT(phr);
	// assuming we don't want to modify the data
	GSFrameCaptureFilter *pNewObject = new GSFrameCaptureFilter(punk, phr, FALSE);

	if(pNewObject == NULL) {
		if (phr)
			*phr = E_OUTOFMEMORY;
	}
	return pNewObject;
}

HRESULT GSFrameCaptureFilter::NonDelegatingQueryInterface(REFIID iid, void **ppv)
{
	if (iid == IID_IGSFrameCaptureFilter) 
	{
		return GetInterface(static_cast<IGSFrameCaptureFilter*>(this), ppv);
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

HRESULT GSFrameCaptureFilter::CreatePins()
{
	HRESULT hr = S_OK;
	GSPIN_ACCEPT_MEDIATYPE inAccType[] =
	{
		GSPIN_ACCEPT_MEDIATYPE(MEDIATYPE_Video, MEDIASUBTYPE_RGB32, FORMAT_VideoInfo, FALSE),
		GSPIN_ACCEPT_MEDIATYPE(MEDIATYPE_Video, MEDIASUBTYPE_ARGB32, FORMAT_VideoInfo, FALSE)
	};

	GSFILTER_INPUTPIN_DESC inputPinDesc[] = {
		GSFILTER_INPUTPIN_DESC(L"input", 0, GSINPUT_PIN, GSPIN_ACCEPT_MEDIATYPE_GROUP(inAccType, ARRAYSIZE(inAccType)), 
		GSFILTER_INPUTPIN_FUNCS(GSMuxFilter::PreReceive_InitSample, GSFrameCaptureFilter::OnTransform, GSMuxFilter::PostReceive_DeliverSample, 
		GSMuxFilter::CompleteConnect_ReconnectOutput, NULL))
	};		

	GSOUTPIN_ACCEPT_MEDIATYPE outAccType[] =
	{
		GSOUTPIN_ACCEPT_MEDIATYPE(MEDIATYPE_Video, MEDIASUBTYPE_RGB32, FORMAT_VideoInfo, FALSE, GSREF_INPUT_PIN, 0, 0, 0)
	};

	GSFILTER_OUTPUTPIN_DESC outPinDesc[] = {
		GSFILTER_OUTPUTPIN_DESC(L"output", 0, GSOUTPUT_PIN, GSOUTPIN_ACCEPT_MEDIATYPE_GROUP(outAccType, ARRAYSIZE(outAccType)), GSFILTER_OUTPUTPIN_FUNCS(NULL, NULL))
	};
	hr = _CreatePins(inputPinDesc, ARRAYSIZE(inputPinDesc), outPinDesc, ARRAYSIZE(outPinDesc), NULL, 0);
	return hr;
}

HRESULT GSFrameCaptureFilter::GetPages(CAUUID *pPages)
{
	pPages->cElems = 1;
	pPages->pElems = (GUID*)CoTaskMemAlloc(sizeof(GUID));
	if (pPages->pElems == NULL) 
	{
		return E_OUTOFMEMORY;
	}
	pPages->pElems[0] = CLSID_GSFrameCaptureFilterProp;
	return S_OK;
}

HRESULT GSFrameCaptureFilter::GetName(WCHAR* name, UINT szName)
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

HRESULT GSFrameCaptureFilter::SaveToFile(WCHAR* path)
{
	return S_OK;
}

HRESULT GSFrameCaptureFilter::LoadFromFile(WCHAR* path)
{
	return S_OK;
}

HRESULT GSFrameCaptureFilter::OnTransform(void* self, IMediaSample *pInSample, CMediaType* pInMT, 
									 IMediaSample *pOutSample, CMediaType* pOutMT)
{
	if (self == NULL || pInSample == NULL || pInMT == NULL || pOutSample == NULL || pOutMT == NULL)
	{
		return E_FAIL;
	}
	GSFrameCaptureFilter* pSelf = (GSFrameCaptureFilter*)(GSMuxFilter*)self;
	BYTE* pInBuffer = NULL;
	BYTE* pOutBuffer = NULL;
	pInSample->GetPointer(&pInBuffer);
	pOutSample->GetPointer(&pOutBuffer);
	if (pInBuffer == NULL || pOutBuffer == NULL)
		return E_FAIL;

	int cameraW = 640 ;
	int cameraH = 480 ;
	int camChannel = 3 ;

	VIDEOINFOHEADER *pvi = (VIDEOINFOHEADER *) pInMT->pbFormat;
	BITMAPINFOHEADER bitHeader = pvi->bmiHeader;
	cameraW = bitHeader.biWidth;
	cameraH = bitHeader.biHeight;
	GUID guidSubType = pInMT->subtype;
	if (IsEqualGUID(guidSubType, MEDIASUBTYPE_RGB24))
	{
		camChannel = 3;
	}
	else if(IsEqualGUID(guidSubType, MEDIASUBTYPE_RGB32) || IsEqualGUID(guidSubType, MEDIASUBTYPE_ARGB32))
	{
		camChannel = 4;
	}

	if(pSelf->isSaveImg == TRUE){
		IplImage* camtmp = cvCreateImageHeader(cvSize(cameraW, cameraH), 8, camChannel);
		camtmp->imageData = (char*)pInBuffer;
		char saveName[MAX_PATH] ;
		WCHAR imgPath[MAX_PATH] ;

		swprintf_s(imgPath, MAX_PATH, L"%s\\saveImg\\%d.jpg", pSelf->wszCur, pSelf->ImgCount);
		wcstombs(saveName, imgPath, MAX_PATH);
		
		cvSaveImage(saveName,camtmp);
		cvReleaseImageHeader(&camtmp);
		camtmp = NULL;
		pSelf->ImgCount ++ ;
		pSelf->isSaveImg = FALSE ;
	}
	memcpy((void*)pOutBuffer, (void*)pInBuffer, pOutSample->GetSize());
	return S_OK;
}


void GSFrameCaptureFilter::setIsSaveImg(){
	isSaveImg = !isSaveImg ;
}

void GSFrameCaptureFilter::resetSavingCount(){

	ImgCount = 0 ;
}
void GSFrameCaptureFilter::setImgName(WCHAR* name){
	for(int i = 0 ; i < _MAX_PATH ; i ++){
		saveName[i] = name[i];
	}

}
