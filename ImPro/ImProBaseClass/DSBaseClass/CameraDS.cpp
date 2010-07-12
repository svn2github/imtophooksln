#include "stdafx.h"
#include "CameraDS.h"

CCameraDS::CCameraDS()
{
	m_pRenderFilter = NULL;
	m_pMediaEvent = NULL;
	m_pSampleGrabberFilter = NULL;

	m_pDeviceFilter = NULL;

	m_pCameraOutput = NULL;
	m_pRenderInputPin = NULL;

	m_pSampleGrabber = NULL;
	m_pGrabberInput = NULL;
	m_pGrabberOutput = NULL;

}

CCameraDS::~CCameraDS()
{
	CloseCamera();
}

void CCameraDS::CloseCamera()
{
	UnInitDS();
	m_pDeviceFilter = NULL;
	m_pSampleGrabberFilter = NULL;

	m_pCameraOutput = NULL;
	m_pRenderFilter = NULL;
	m_pRenderInputPin = NULL;

	m_pSampleGrabber = NULL;
	m_pGrabberInput = NULL;
	m_pGrabberOutput = NULL;
}

bool CCameraDS::OpenCamera(int nCamID, bool bDisplayProperties, int nWidth, int nHeight)
{
	HRESULT hr = S_OK;
	// Create the Filter Graph Manager.
	hr = CreateGraph((IGraphBuilder**)&m_pGraph);
	hr = CreateFilters(nCamID, bDisplayProperties, nWidth, nHeight);
	hr = ConnectGraph();
	hr = ConfigFilters();
	return true;
}
HRESULT CCameraDS::ConfigFilters()
{
	m_pSampleGrabber->SetBufferSamples(TRUE);
	return S_OK;
}
HRESULT CCameraDS::ConnectGraph()
{
	HRESULT hr;
	hr = m_pGraph->Connect(m_pCameraOutput, m_pGrabberInput);
	if (FAILED(hr))
		return hr;

	hr = m_pGraph->Connect(m_pGrabberOutput, m_pRenderInputPin);
	return hr;
}

HRESULT CCameraDS::CreateFilters(int nCamID, bool bDisplayProperties, int nWidth, int nHeight)
{
	HRESULT hr;

	hr = CoCreateInstance(CLSID_VideoRenderer, NULL, CLSCTX_INPROC_SERVER,
		IID_IBaseFilter, (LPVOID*) &m_pRenderFilter);
	hr = CoCreateInstance(CLSID_SampleGrabber, NULL, CLSCTX_INPROC_SERVER, 
		IID_IBaseFilter, (LPVOID *)&m_pSampleGrabberFilter);

	hr = m_pGraph->AddFilter(m_pRenderFilter, L"Video Renderer");
	hr = m_pSampleGrabberFilter->QueryInterface(IID_ISampleGrabber, (void**)&m_pSampleGrabber);

//	m_pGraph->AddFilter(m_pSampleGrabberFilter, L"Sample Grabber");

	// Bind Device Filter.  We know the device because the id was passed in
	BindFilter(nCamID, &m_pDeviceFilter);
	m_pGraph->AddFilter(m_pDeviceFilter, L"Camera");

	CComPtr<IEnumPins> pEnum;
	m_pDeviceFilter->EnumPins(&pEnum);
	hr = pEnum->Reset();
	hr = pEnum->Next(1, &m_pCameraOutput, NULL); 
	pEnum = NULL;
	m_pSampleGrabberFilter->EnumPins(&pEnum);
	pEnum->Reset();
	hr = pEnum->Next(1, &m_pGrabberInput, NULL); 

	pEnum = NULL;
	m_pSampleGrabberFilter->EnumPins(&pEnum);
	pEnum->Reset();
	pEnum->Skip(1);
	hr = pEnum->Next(1, &m_pGrabberOutput, NULL); 



	pEnum = NULL;
	m_pRenderFilter->EnumPins(&pEnum);
	pEnum->Reset();
	hr = pEnum->Next(1, &m_pRenderInputPin, NULL);
	
	//SetCrossBar();

	if (bDisplayProperties) 
	{
		CComPtr<ISpecifyPropertyPages> pPages;

		HRESULT hr = m_pCameraOutput->QueryInterface(IID_ISpecifyPropertyPages, (void**)&pPages);
		if (SUCCEEDED(hr))
		{
			PIN_INFO PinInfo;
			m_pCameraOutput->QueryPinInfo(&PinInfo);

			CAUUID caGUID;
			pPages->GetPages(&caGUID);

			OleCreatePropertyFrame(NULL, 0, 0,
				L"Property Sheet", 1,
				(IUnknown **)&(m_pCameraOutput.p),
				caGUID.cElems,
				caGUID.pElems,
				0, 0, NULL);
			CoTaskMemFree(caGUID.pElems);
			PinInfo.pFilter->Release();
		}
		pPages = NULL;
	}
	else 
	{
		//////////////////////////////////////////////////////////////////////////////
		// 加入由 lWidth和lHeight设置的摄像头的宽和高 的功能，默认320*240
		// by flymanbox @2009-01-24
		//////////////////////////////////////////////////////////////////////////////
		int _Width = nWidth, _Height = nHeight;
		IAMStreamConfig*   iconfig; 
		iconfig = NULL;
		hr = m_pCameraOutput->QueryInterface(IID_IAMStreamConfig,   (void**)&iconfig);   

		AM_MEDIA_TYPE* pmt;    
		if(iconfig->GetFormat(&pmt) !=S_OK) 
		{
			//printf("GetFormat Failed ! \n");
			return   false;   
		}

		VIDEOINFOHEADER*   phead;
		if ( pmt->formattype == FORMAT_VideoInfo)   
		{   
			phead=( VIDEOINFOHEADER*)pmt->pbFormat;   
			phead->bmiHeader.biWidth = _Width;   
			phead->bmiHeader.biHeight = _Height;   
			if(( hr=iconfig->SetFormat(pmt)) != S_OK )   
			{
				return   false;
			}

		}   

		iconfig->Release();   
		iconfig=NULL;   
		MYFREEMEDIATYPE(*pmt);
	}
	return S_OK;
}

bool CCameraDS::BindFilter(int nCamID, IBaseFilter **pFilter)
{
	if (nCamID < 0)
		return false;
 
    // enumerate all video capture devices
	CComPtr<ICreateDevEnum> pCreateDevEnum;
	HRESULT hr = CoCreateInstance(CLSID_SystemDeviceEnum, NULL, CLSCTX_INPROC_SERVER,
								IID_ICreateDevEnum, (void**)&pCreateDevEnum);
	if (hr != NOERROR)
	{
		return false;
	}

    CComPtr<IEnumMoniker> pEm;
    hr = pCreateDevEnum->CreateClassEnumerator(CLSID_VideoInputDeviceCategory,
        &pEm, 0);
    if (hr != NOERROR) 
	{
		return false;
    }

    pEm->Reset();
    ULONG cFetched;
    IMoniker *pM;
	int index = 0;
    while(hr = pEm->Next(1, &pM, &cFetched), hr==S_OK, index <= nCamID)
    {
		IPropertyBag *pBag;
		hr = pM->BindToStorage(0, 0, IID_IPropertyBag, (void **)&pBag);
		if(SUCCEEDED(hr)) 
		{
			VARIANT var;
			var.vt = VT_BSTR;
			hr = pBag->Read(L"FriendlyName", &var, NULL);
			if (hr == NOERROR) 
			{
				if (index == nCamID)
				{
					pM->BindToObject(0, 0, IID_IBaseFilter, (void**)pFilter);
				}
				SysFreeString(var.bstrVal);
			}
			pBag->Release();
		}
		pM->Release();
		index++;
    }

	pCreateDevEnum = NULL;
	return true;
}

void CCameraDS::SetCrossBar()
{
	int i;
	IAMCrossbar *pXBar1 = NULL;
	ICaptureGraphBuilder2 *pBuilder = NULL;

 
	HRESULT hr = CoCreateInstance(CLSID_CaptureGraphBuilder2, NULL,
					CLSCTX_INPROC_SERVER, IID_ICaptureGraphBuilder2, 
					(void **)&pBuilder);

	if (SUCCEEDED(hr))
	{
		hr = pBuilder->SetFiltergraph(m_pGraph);
	}


	hr = pBuilder->FindInterface(&LOOK_UPSTREAM_ONLY, NULL, 
								m_pDeviceFilter,IID_IAMCrossbar, (void**)&pXBar1);

	if (SUCCEEDED(hr)) 
	{
  		long OutputPinCount;
		long InputPinCount;
		long PinIndexRelated;
		long PhysicalType;
		long inPort = 0;
		long outPort = 0;

		pXBar1->get_PinCounts(&OutputPinCount,&InputPinCount);
		for( i =0;i<InputPinCount;i++)
		{
			pXBar1->get_CrossbarPinInfo(TRUE,i,&PinIndexRelated,&PhysicalType);
			if(PhysConn_Video_Composite==PhysicalType) 
			{
				inPort = i;
				break;
			}
		}
		for( i =0;i<OutputPinCount;i++)
		{
			pXBar1->get_CrossbarPinInfo(FALSE,i,&PinIndexRelated,&PhysicalType);
			if(PhysConn_Video_VideoDecoder==PhysicalType) 
			{
				outPort = i;
				break;
			}
		}
  
		if(S_OK==pXBar1->CanRoute(outPort,inPort))
		{
			pXBar1->Route(outPort,inPort);
		}
		pXBar1->Release();  
	}
	pBuilder->Release();
}


int CCameraDS::CameraCount()
{
	int count = 0;
 	CoInitialize(NULL);

   // enumerate all video capture devices
	CComPtr<ICreateDevEnum> pCreateDevEnum;
    HRESULT hr = CoCreateInstance(CLSID_SystemDeviceEnum, NULL, CLSCTX_INPROC_SERVER,
									IID_ICreateDevEnum, (void**)&pCreateDevEnum);

    CComPtr<IEnumMoniker> pEm;
    hr = pCreateDevEnum->CreateClassEnumerator(CLSID_VideoInputDeviceCategory,
        &pEm, 0);
    if (hr != NOERROR) 
	{
		return count;
    }

    pEm->Reset();
    ULONG cFetched;
    IMoniker *pM;
    while(hr = pEm->Next(1, &pM, &cFetched), hr==S_OK)
    {
		count++;
    }

	pCreateDevEnum = NULL;
	pEm = NULL;
	return count;
}

int CCameraDS::CameraName(int nCamID, WCHAR* sName, int nBufferSize)
{
	int count = 0;
 	CoInitialize(NULL);

   // enumerate all video capture devices
	CComPtr<ICreateDevEnum> pCreateDevEnum;
    HRESULT hr = CoCreateInstance(CLSID_SystemDeviceEnum, NULL, CLSCTX_INPROC_SERVER,
									IID_ICreateDevEnum, (void**)&pCreateDevEnum);

    CComPtr<IEnumMoniker> pEm;
    hr = pCreateDevEnum->CreateClassEnumerator(CLSID_VideoInputDeviceCategory,
        &pEm, 0);
    if (hr != NOERROR) return 0;


    pEm->Reset();
    ULONG cFetched;
    IMoniker *pM;
    while(hr = pEm->Next(1, &pM, &cFetched), hr==S_OK)
    {
		if (count != nCamID)
		{
			pM->Release();
			count++;
			continue;
		}
		IPropertyBag *pBag=0;
		hr = pM->BindToStorage(0, 0, IID_IPropertyBag, (void **)&pBag);
		if(SUCCEEDED(hr))
		{
			VARIANT var;
			var.vt = VT_BSTR;
			hr = pBag->Read(L"FriendlyName", &var, NULL); //还有其他属性,像描述信息等等...
            if(hr == NOERROR)
	        {
				wcscpy_s(sName, nBufferSize, (WCHAR*)var.bstrVal);
                SysFreeString(var.bstrVal);				
	        }
		    pBag->Release();
		}
		pM->Release();
		break;
    }

	pCreateDevEnum = NULL;
	pEm = NULL;

	return 1;
}

HRESULT CCameraDS::ShowCamProp()
{
	return ShowFilterProp(m_pDeviceFilter);
}
HRESULT CCameraDS::ShowCamPinProp()
{
	return ShowFilterProp(m_pCameraOutput);
}

HRESULT CCameraDS::QueryFrame(IplImage*& pFrame)
{
	HRESULT hr = S_OK;
	long evCode;
	long size = 0;
	OAFilterState state;
	m_pMediaControl->GetState(INFINITE, &state);
	if (state != State_Running && state != State_Paused)
		return E_FAIL;
	
	AM_MEDIA_TYPE   mt;
	ZeroMemory(&mt, sizeof(AM_MEDIA_TYPE));
	hr = m_pSampleGrabber->GetConnectedMediaType(&mt);
	if(FAILED(hr))
		return E_FAIL;

	VIDEOINFOHEADER *videoHeader;
	videoHeader = reinterpret_cast<VIDEOINFOHEADER*>(mt.pbFormat);
	int nWidth = videoHeader->bmiHeader.biWidth;
	int nHeight = videoHeader->bmiHeader.biHeight;
	long bufferSize = mt.lSampleSize;
	int nChannel = videoHeader->bmiHeader.biBitCount / 8;
	//if the buffer size changed
	if (pFrame == NULL)
	{
		if (IsEqualGUID(mt.subtype, MEDIASUBTYPE_RGB32))
		{
			pFrame = cvCreateImage(cvSize(nWidth, nHeight), IPL_DEPTH_8U, 4);
		}
		else if(IsEqualGUID(mt.subtype, MEDIASUBTYPE_RGB24))
		{
			
			pFrame = cvCreateImage(cvSize(nWidth, nHeight), IPL_DEPTH_8U, 3);
		}
		else
		{
			MYFREEMEDIATYPE(mt);
			return E_FAIL;
		}
	}
	if (pFrame->width != nWidth || pFrame->height != nHeight || 
		pFrame->nChannels != nChannel)
	{
		MYFREEMEDIATYPE(mt);
		return E_FAIL;
	}
	hr = m_pSampleGrabber->GetCurrentBuffer(&bufferSize, (long*)pFrame->imageData);
	cvFlip(pFrame);
	
	MYFREEMEDIATYPE(mt);
	return S_OK;
}