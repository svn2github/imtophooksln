#ifndef _ARLAYOUTFILTER_H
#define _ARLAYOUTFILTER_H

#include "dshow.h"
#include "Streams.h"
#include <initguid.h>
#include "combase.h"
#include "ARTagLayout.h"
#include "IARLayoutFilter.h"
#include "CMuxTransformFilter.h"
// {6B6AFF82-D374-40f5-9F77-C1652EB512CF}
DEFINE_GUID(CLSID_ARLayoutFilter, 
			0x6b6aff82, 0xd374, 0x40f5, 0x9f, 0x77, 0xc1, 0x65, 0x2e, 0xb5, 0x12, 0xcf);

class ARLayoutFilter :
	public CMuxTransformFilter, public IARLayoutFilter, ISpecifyPropertyPages
{
public:
	static CUnknown *WINAPI CreateInstance(LPUNKNOWN punk, HRESULT *phr);
	DECLARE_IUNKNOWN;
	STDMETHODIMP NonDelegatingQueryInterface(REFIID iid, void **ppv);
	STDMETHODIMP Notify (IBaseFilter *pSender, Quality q);
	STDMETHODIMP     GetPages(CAUUID *pPages);
	//implement DShow Interface
	//virtual HRESULT          GetMediaType(CMediaType *pMediaType);
	//virtual HRESULT          DecideBufferSize(IMemAllocator *pAllocator, ALLOCATOR_PROPERTIES *pProp);
	//virtual HRESULT          FillBuffer(IMediaSample *pSample) ;

	//Derive from CMuxTransformFilter
	virtual HRESULT CreatePins();
	virtual HRESULT FillBuffer(IMediaSample *pSamp, IPin* pPin);
	virtual HRESULT GetMediaType(int iPosition, const IPin* pOutPin, __inout CMediaType *pMediaType);
	virtual HRESULT CheckOutputType(const CMediaType* mtOut, const IPin* pPin);
	virtual HRESULT DecideBufferSize(
		IMemAllocator * pAllocator, const IPin* pOutPin,
		__inout ALLOCATOR_PROPERTIES *pprop);
public:
	ARLayoutFilter(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData);
	virtual ~ARLayoutFilter();
	HRESULT WriteToLayout(LPWSTR wszText,BYTE* pData, VIDEOINFOHEADER* pVih );
	HRESULT WriteToMask(LPWSTR wszText,BYTE* pData, VIDEOINFOHEADER* pVih );
	HRESULT LoadnewBitmap();

public:

    LPCWSTR			PinName;
	LPCWSTR			LayoutPin;
	LPCWSTR			MaskPin;
	//////////////////////////////////////////////////////////////////////////
	int				m_iImageHeight;                 // The current image height
	int				m_iImageWidth;                  // And current image width
	LONGLONG		m_llFrameCount;
protected:

	BITMAPINFO  *m_pBmi;                 // Pointer to the bitmap header
	DWORD       m_cbBitmapInfo;         // Size of the bitmap header

	// File opening variables 
	HANDLE m_hFile;                     // Handle returned from CreateFile
	BYTE * m_pFile;                     // Points to beginning of file buffer
	BYTE * m_pImage;                    // Points to pixel bits           
	BYTE * m_tagImageData;                    // Points to pixel bits    
	int cbFileHeader ;
	//IplImage* layoutIplImage ;
	ARLayout *layout;
	bool changeLayout;

	CCritSec m_cSharedState;            // Protects our internal state
	CImageDisplay m_Display;            // Figures out our media type for us

public:
	 virtual int getNumOfX() ;
	 virtual int getNumOfY() ;
	// virtual  void setTagProp(int tagID,int posX, int posY, int width,bool isVisible);
	 virtual HRESULT setNumOfX(int numX) ;
	 virtual  HRESULT setNumOfY(int numY) ;

};
#endif