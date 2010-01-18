#include "stdafx.h"
#include "ARLayoutFilter.h"
#include "ARLayoutProp.h"

#define BITMAP_NAME TEXT("sample_800.bmp")
#define WIDTH 800
#define HEIGHT 600 
const TCHAR* DXUtil_GetDXSDKMediaPath();

ARLayoutFilter::ARLayoutFilter(HRESULT *phr, ARLayoutSource *pParent, LPCWSTR pPinName) : 
CSourceStream(NAME("AR_LAYOUT"), phr, pParent, pPinName) ,
m_FramesWritten(0),
m_bZeroMemory(0),
m_pBmi(0),
m_cbBitmapInfo(0),
m_hFile(INVALID_HANDLE_VALUE),
m_pFile(NULL),
m_pImage(NULL),
m_iFrameNumber(0),
m_tagImageData(NULL),
m_rtFrameLength(UNITS / 5) // Display 5 bitmap frames per second
{
	PinName = pPinName ;

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

	//swprintf_s(str, MAX_PATH, L"%s\\..\\fx\\HomoWarp.fx", szPath);
	//swprintf_s(str, MAX_PATH, szPath);

	changeLayout = false; 
	char fileDir[100];

	int size= wcslen(szCurrentDir);
	wcstombs(fileDir, szPath, size+1);

	wsprintf(szFileCurrent, TEXT("%s\\bch\\%s\0"), szPath, BITMAP_NAME);

	layout = new ARLayout(WIDTH,HEIGHT,8,6,10,fileDir) ;
	m_iImageHeight = HEIGHT;
	m_iImageWidth = WIDTH;
    
	m_hFile = CreateFile(szFileCurrent, GENERIC_READ, 0, NULL, OPEN_EXISTING, 
		FILE_ATTRIBUTE_NORMAL, NULL);

	//if (m_hFile == INVALID_HANDLE_VALUE)
	//{
	//	// File was not in the application's current directory,
	//	// so look in the DirectX SDK media path instead.
	//	lstrcpyn(szFileMedia, DXUtil_GetDXSDKMediaPath(), MAX_PATH-1);
	//	lstrcat(szFileMedia, BITMAP_NAME);

	//	m_hFile = CreateFile(szFileMedia, GENERIC_READ, 0, NULL, OPEN_EXISTING, 
	//		FILE_ATTRIBUTE_NORMAL, NULL);

	//	if (m_hFile == INVALID_HANDLE_VALUE)
	//	{
	//		TCHAR szMsg[MAX_PATH + MAX_PATH + 100];

	//		wsprintf(szMsg, TEXT("Could not open bitmap source file in the application directory:\r\n\r\n\t[%s]\n\n")
	//			TEXT("or in the DirectX SDK Media folder:\r\n\r\n\t[%s]\n\n")
	//			TEXT("Please copy this file either to the application's folder\r\n")
	//			TEXT("or to the DirectX SDK Media folder, then recreate this filter.\r\n")
	//			TEXT("Otherwise, you will not be able to render the output pin.\0"),
	//			szFileCurrent, szFileMedia);

	//		OutputDebugString(szMsg);
	//		MessageBox(NULL, szMsg, TEXT("PushSource filter error"), MB_ICONERROR | MB_OK);
	//		*phr = HRESULT_FROM_WIN32(GetLastError());
	//		return;
	//	}
	//}

	DWORD dwFileSize = GetFileSize(m_hFile, NULL);
	if (dwFileSize == INVALID_FILE_SIZE)
	{
		DbgLog((LOG_TRACE, 1, TEXT("Invalid file size")));
		*phr = HRESULT_FROM_WIN32(GetLastError());
		return;
	}

	m_pFile = new BYTE[WIDTH * HEIGHT];
	m_tagImageData = new BYTE[WIDTH * HEIGHT];

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

	// WARNING - This code does not verify that the file is a valid bitmap file.
	// In your own filter, you would check this or else generate the bitmaps 
	// yourself in memory.

	 cbFileHeader = sizeof(BITMAPFILEHEADER);

	// Store the size of the BITMAPINFO 
	BITMAPFILEHEADER *pBm = (BITMAPFILEHEADER*)m_pFile;
	m_cbBitmapInfo = pBm->bfOffBits - cbFileHeader;

	// Store a pointer to the BITMAPINFO
	m_pBmi = (BITMAPINFO*)(m_pFile + cbFileHeader);

	// Store a pointer to the starting address of the pixel bits
	m_pImage = m_pFile + cbFileHeader + m_cbBitmapInfo;

	// Close and invalidate the file handle, since we have copied its bitmap data
	CloseHandle(m_hFile);
	m_hFile = INVALID_HANDLE_VALUE;

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
		return CSourceStream::NonDelegatingQueryInterface(iid, ppv);
	}
}
HRESULT ARLayoutFilter::GetMediaType(CMediaType *pMediaType)
{

	CAutoLock cAutoLock(m_pFilter->pStateLock());

	CheckPointer(pMediaType, E_POINTER);

	// If the bitmap file was not loaded, just fail here.
	if (!m_pImage)
		return E_FAIL;

	// Allocate enough room for the VIDEOINFOHEADER and the color tables
	VIDEOINFOHEADER *pvi = (VIDEOINFOHEADER*)pMediaType->AllocFormatBuffer(SIZE_PREHEADER + m_cbBitmapInfo);
	if (pvi == 0) 
		return(E_OUTOFMEMORY);

	ZeroMemory(pvi, pMediaType->cbFormat);   
	pvi->AvgTimePerFrame = m_rtFrameLength;

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


HRESULT ARLayoutFilter::DecideBufferSize(IMemAllocator *pAlloc, ALLOCATOR_PROPERTIES *pRequest)
{
	HRESULT hr;
	CAutoLock cAutoLock(m_pFilter->pStateLock());

	CheckPointer(pAlloc, E_POINTER);
	CheckPointer(pRequest, E_POINTER);

	// If the bitmap file was not loaded, just fail here.
	if (!m_pImage)
		return E_FAIL;

	VIDEOINFOHEADER *pvi = (VIDEOINFOHEADER*) m_mt.Format();

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

int count =0 ;
HRESULT ARLayoutFilter::LoadnewBitmap(){
	
	layout->changeLayout();

	for (int i=0; i < HEIGHT ; i++){
		for(int j = 0 ; j < WIDTH ; j ++){
			m_tagImageData[i*WIDTH+j] =  layout->getLayout()->imageData[ i*WIDTH+j]; 
		}
	}
	
	m_pImage = m_tagImageData;
	return S_OK;
}
int nFrameRate = 0;

HRESULT ARLayoutFilter::FillBuffer(IMediaSample *pSample)
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

	// Check that we're still using video
	ASSERT(m_mt.formattype == FORMAT_VideoInfo);

	VIDEOINFOHEADER *pVih = (VIDEOINFOHEADER*)m_mt.pbFormat;

	// If we want to change the contents of our source buffer (m_pImage)
	// at some interval or based on some condition, this is where to do it.
	// Remember that the new data has the same format that we specified in GetMediaType.
	// For example: 
	// if(m_iFrameNumber > SomeValue)
	//    LoadNewBitsIntoBuffer(m_pImage)

	// Copy the DIB bits over into our filter's output buffer.
	// Since sample size may be larger than the image size, bound the copy size.
	memcpy(pData, m_pImage, min(pVih->bmiHeader.biSizeImage, (DWORD) cbData));

	// Set the timestamps that will govern playback frame rate.
	// If this file is getting written out as an AVI,
	// then you'll also need to configure the AVI Mux filter to 
	// set the Average Time Per Frame for the AVI Header.
	// The current time is the sample's start
	REFERENCE_TIME rtStart = m_iFrameNumber * m_rtFrameLength;
	REFERENCE_TIME rtStop  = rtStart + m_rtFrameLength;

	pSample->SetTime(&rtStart, &rtStop);
	m_iFrameNumber++;

	// Set TRUE on every sample for uncompressed frames
	pSample->SetSyncPoint(TRUE);
	return S_OK;
}



//HRESULT ARLayoutFilter::FillBuffer(IMediaSample *pSample){
//
//	HRESULT hr;
//	BYTE *pData;
//	long cbData;
//
//	WCHAR msg[256];
//
//	pSample->GetPointer(&pData);
//	cbData = pSample->GetSize();
//
//	CMediaType *pmt;
//	hr = pSample->GetMediaType((AM_MEDIA_TYPE**)&pmt);
//	if(hr == S_OK)
//	{
//		SetMediaType(pmt);
//		DeleteMediaType(pmt);
//	}
//	ASSERT(m_mt.formattype == FORMAT_VideoInfo);
//	ASSERT(m_mt.cbFormat >= sizeof(VIDEOINFOHEADER));
//	VIDEOINFOHEADER *pVih = (VIDEOINFOHEADER*)m_mt.pbFormat;
//
//	//if (wcscmp(PinName,"Layout")== 1)
//	{	
//		hr = WriteToLayout(msg,pData,pVih);
//
//	}
//	//else
//		hr = WriteToMask(msg,pData,pVih);
//		
//	return S_OK;
//}
//
//HRESULT ARLayoutFilter::WriteToLayout(LPWSTR wszText,BYTE* pData, VIDEOINFOHEADER* pVih){
//
//	
//	return S_OK;
//}
//
//HRESULT ARLayoutFilter::WriteToMask(LPWSTR wszText,BYTE* pData, VIDEOINFOHEADER* pVih){
//
//	return S_OK;
//}

const TCHAR* DXUtil_GetDXSDKMediaPath()
{
	static TCHAR strNull[2] = {0};
	static TCHAR strPath[MAX_PATH + 10];
	HKEY  hKey=0;
	DWORD type=0, size=MAX_PATH;

	strPath[0] = 0;     // Initialize to NULL

	// Open the appropriate registry key
	LONG result = RegOpenKeyEx( HKEY_LOCAL_MACHINE,
		TEXT("Software\\Microsoft\\DirectX SDK"),
		0, KEY_READ, &hKey );
	if( ERROR_SUCCESS != result )
		return strNull;

	result = RegQueryValueEx( hKey, TEXT("DX9O4SDK Samples Path"), NULL,
		&type, (BYTE*)strPath, &size );

	if( ERROR_SUCCESS != result )
	{
		size = MAX_PATH;    // Reset size field
		result = RegQueryValueEx( hKey, TEXT("DX81SDK Samples Path"), NULL,
			&type, (BYTE*)strPath, &size );

		if( ERROR_SUCCESS != result )
		{
			size = MAX_PATH;    // Reset size field
			result = RegQueryValueEx( hKey, TEXT("DX8SDK Samples Path"), NULL,
				&type, (BYTE*)strPath, &size );

			if( ERROR_SUCCESS != result )
			{
				RegCloseKey( hKey );
				return strNull;
			}
		}
	}

	RegCloseKey( hKey );
	lstrcat( strPath, TEXT("\\Media\\Misc\\\0") );

	return strPath;
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