#include "stdafx.h"
#include "ARLayoutFilter.h"
#include "ARLayoutDXProp.h"

#define BITMAP_NAME TEXT("sample_800.bmp")
#define WIDTH 800
#define HEIGHT 600 
ARLayoutFilter::ARLayoutFilter(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData) 
: CMuxTransformFilter(NAME("AR_LAYOUT"), 0, CLSID_ARLayoutFilter),
m_pBmi(0),
m_cbBitmapInfo(0),
m_hFile(INVALID_HANDLE_VALUE),
m_pFile(NULL),
m_pImage(NULL),
m_tagImageData(NULL)
{
	//////////////////////////////////////////////////////////////////////////
	TCHAR szCurrentDir[MAX_PATH], szFileCurrent[MAX_PATH], szFileMedia[MAX_PATH];

	// First look for the bitmap in the current directory
    
	extern HMODULE GetModule();
	WCHAR str[MAX_PATH] = {0};
	HMODULE module = GetModule();
	GetModuleFileName(module, str, MAX_PATH);
	// Gets filename
	WCHAR* pszFile = wcsrchr(str, '\\');
	pszFile++;    // Moves on from \
	// Get path
	WCHAR szPath[MAX_PATH] = L"";
	_tcsncat(szPath, str, pszFile - str);

	changeLayout = false; 
	char fileDir[100];

	int size= wcslen(szCurrentDir);
	wcstombs(fileDir, szPath, size+1);

	wsprintf(szFileCurrent, TEXT("%s\\ARToolKitPlus_AllMarkers\\%s\0"), szPath, BITMAP_NAME);

	layout = new ARLayout(WIDTH,HEIGHT,8,6,10,fileDir) ;
	m_iImageHeight = HEIGHT;
	m_iImageWidth = WIDTH;
    
	m_hFile = CreateFile(szFileCurrent, GENERIC_READ, 0, NULL, OPEN_EXISTING, 
		FILE_ATTRIBUTE_NORMAL, NULL);


	DWORD dwFileSize = GetFileSize(m_hFile, NULL);
	if (dwFileSize == INVALID_FILE_SIZE)
	{
		DbgLog((LOG_TRACE, 1, TEXT("Invalid file size")));
		*phr = HRESULT_FROM_WIN32(GetLastError());
		return;
	}

	m_pFile = new BYTE[WIDTH * HEIGHT];
	//m_tagImageData = new BYTE[WIDTH * HEIGHT];
	
	if(!m_pFile)
	{
		OutputDebugString(TEXT("Could not allocate m_pImage\n"));
		*phr = E_OUTOFMEMORY;
		return;
	}

	DWORD nBytesRead = 0;
	if(!ReadFile(m_hFile, m_pFile, dwFileSize, &nBytesRead, NULL))
	{
		*phr = HRESULT_FROM_WIN32(GetLastError());
		OutputDebugString(TEXT("ReadFile failed\n"));
		return;
	}

	cbFileHeader = sizeof(BITMAPFILEHEADER);

	// Store the size of the BITMAPINFO 
	BITMAPFILEHEADER *pBm = (BITMAPFILEHEADER*)m_pFile;
	m_cbBitmapInfo = pBm->bfOffBits - cbFileHeader;

	// Store a pointer to the BITMAPINFO
	m_pBmi = (BITMAPINFO*)(m_pFile + cbFileHeader);

	// Store a pointer to the starting address of the pixel bits
	m_pImage = m_pFile + cbFileHeader + m_cbBitmapInfo;

    LoadnewBitmap() ;

	// Close and invalidate the file handle, since we have copied its bitmap data
	CloseHandle(m_hFile);
	m_pFile = NULL;
	
}
ARLayoutFilter::~ARLayoutFilter(void)
{
}

STDMETHODIMP ARLayoutFilter::Notify(IBaseFilter *pSender, Quality q)

{
	return S_OK;

}

HRESULT ARLayoutFilter::NonDelegatingQueryInterface(REFIID iid, void **ppv)
{
	if (iid == IID_IARLayoutFilter) 
	{
		return GetInterface(static_cast<IARLayoutFilter*>(this), ppv);
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
HRESULT ARLayoutFilter::GetMediaType(int iPosition, const IPin* pOutPin, __inout CMediaType *pMediaType)
{
	CheckPointer(pMediaType, E_POINTER);

	// Allocate enough room for the VIDEOINFOHEADER and the color tables
	if ( m_pStreamPins.size() > 0 && pOutPin == m_pStreamPins[0] )
	{
		if (iPosition == 0 )
		{
			if (m_pImage == NULL)
			{
				return S_FALSE;
			}
			VIDEOINFOHEADER *pvi = (VIDEOINFOHEADER*)pMediaType->AllocFormatBuffer(SIZE_PREHEADER + m_cbBitmapInfo);
			if (pvi == 0) 
				return(E_OUTOFMEMORY);

			ZeroMemory(pvi, pMediaType->cbFormat);   

			// Copy the header info
			memcpy(&(pvi->bmiHeader), m_pBmi, m_cbBitmapInfo);

			// Set image size for use in FillBuffer
			pvi->bmiHeader.biSizeImage  = GetBitmapSize(&pvi->bmiHeader);

			// Clear source and target rectangles
			SetRectEmpty(&(pvi->rcSource)); // we want the whole image area rendered
			SetRectEmpty(&(pvi->rcTarget)); // no particular destination rectangle

			pMediaType->SetType(&MEDIATYPE_Video);
			pMediaType->SetFormatType(&FORMAT_VideoInfo);
			pMediaType->SetTemporalCompression(FALSE);

			// Work out the GUID for the subtype from the header info.
			const GUID SubTypeGUID = GetBitmapSubtype(&pvi->bmiHeader);
			pMediaType->SetSubtype(&SubTypeGUID);
			pMediaType->SetSampleSize(pvi->bmiHeader.biSizeImage);
			return S_OK;
		}

	}

	return S_FALSE;
}


HRESULT ARLayoutFilter::DecideBufferSize(
	IMemAllocator * pAlloc, const IPin* pOutPin,
	__inout ALLOCATOR_PROPERTIES *pRequest)
{
	HRESULT hr;

	CheckPointer(pAlloc, E_POINTER);
	CheckPointer(pRequest, E_POINTER);
	if (m_pStreamPins.size() > 0 && m_pStreamPins[0] == pOutPin)
	{
		// If the bitmap file was not loaded, just fail here.
		if (!m_pImage)
			return E_FAIL;
		
		CMediaType mt = ((CMuxTransformStream*)pOutPin)->CurrentMediaType();
		
		VIDEOINFOHEADER *pvi = (VIDEOINFOHEADER*)mt.Format();
		
		// Ensure a minimum number of buffers
		if (pRequest->cBuffers == 0)
		{
			pRequest->cBuffers = 2;
		}
		pRequest->cbBuffer = pvi->bmiHeader.biSizeImage;

		ALLOCATOR_PROPERTIES Actual;
		hr = pAlloc->SetProperties(pRequest, &Actual);
		if (FAILED(hr)) 
		{
			return hr;
		}

		// Is this allocator unsuitable?
		if (Actual.cbBuffer < pRequest->cbBuffer) 
		{
			return E_FAIL;
		}
		return S_OK;
	}
	return S_FALSE;
}

int count =0 ;
HRESULT ARLayoutFilter::LoadnewBitmap(){
	
	layout->changeLayout();

	for (int i=0; i < HEIGHT ; i++){
		for(int j = 0 ; j < WIDTH ; j ++){
			m_pImage[i*WIDTH+j] =  layout->getLayout()->imageData[ i*WIDTH+j]; 
		}
	}
	
	return S_OK;
}

HRESULT ARLayoutFilter::FillBuffer(IMediaSample *pSample, IPin* pPin)
{
	if (m_pStreamPins.size() > 0 && m_pStreamPins[0] == pPin)
	{
		BYTE *pData;
		long cbData;
		
		if(changeLayout == true){
			LoadnewBitmap() ;
			changeLayout = false ;
		}
		
		CheckPointer(pSample, E_POINTER);

		// If the bitmap file was not loaded, just fail here.
		if (!m_pImage)
			return E_FAIL;
		CAutoLock cAutoLockShared(&m_cSharedState);
		
		// Access the sample's data buffer
		pSample->GetPointer(&pData);
		cbData = pSample->GetSize();

		CMediaType mt = ((CMuxTransformStream*)pPin)->CurrentMediaType();
		// Check that we're still using video
		ASSERT(mt.formattype == FORMAT_VideoInfo);

		VIDEOINFOHEADER *pVih = (VIDEOINFOHEADER*)mt.pbFormat;

		memcpy(pData, m_pImage, min(pVih->bmiHeader.biSizeImage, (DWORD) cbData));
		return S_OK;
	}
	return S_FALSE;
}
CUnknown *WINAPI ARLayoutFilter::CreateInstance(LPUNKNOWN punk, HRESULT *phr)
{
	ASSERT(phr);
	//only allow one instance;

	ARLayoutFilter *pNewObject = new ARLayoutFilter(punk, phr, FALSE);

	if(pNewObject == NULL) {
		if (phr)
			*phr = E_OUTOFMEMORY;
	}
	return pNewObject;
}

HRESULT ARLayoutFilter::CreatePins()
{
	HRESULT hr;
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
	
		CMuxTransformStream* pOutput0 = new CMuxTransformStream(NAME("CMuxTransform stream pin"),
				&hr,              // Owner filter
				this,               // Result code
				L"Layout");      // Pin name
		
		CMuxTransformStream* pOutput1 = new CMuxTransformStream(NAME("CMuxTransform stream pin"),
			&hr,              // Owner filter
			this,               // Result code
			L"markinfo");      // Pin name

		m_pStreamPins.push_back(pOutput0);
		m_pStreamPins.push_back(pOutput1);
	}
	return S_OK;
}
HRESULT ARLayoutFilter::CheckOutputType(const CMediaType* mtOut, const IPin* pPin)
{

	if (m_pStreamPins.size() > 0 && m_pStreamPins[0] == pPin )
	{
		CheckPointer(mtOut, E_POINTER);
		if (IsEqualGUID(*mtOut->Type(),MEDIATYPE_Video))
		{
			return NOERROR;
		}
	}
	return S_OK;
}
HRESULT ARLayoutFilter::GetPages(CAUUID *pPages)
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

HRESULT ARLayoutFilter::setNumOfX(int numX){

	layout->setNumTagX(numX);
	changeLayout = true ;
	return S_OK;
}

HRESULT ARLayoutFilter::setNumOfY(int numY){

	layout->setNumTagY(numY);
	changeLayout = true ;
	return S_OK;

}

int ARLayoutFilter::getNumOfX(){
    return layout->numTagX;
}

int ARLayoutFilter::getNumOfY(){
	return layout->numTagY;
}