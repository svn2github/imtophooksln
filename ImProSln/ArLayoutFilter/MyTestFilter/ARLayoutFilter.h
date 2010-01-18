#ifndef _ARLAYOUTFILTER_H
#define _ARLAYOUTFILTER_H

#include "dshow.h"
#include "Streams.h"
#include <initguid.h>
#include "combase.h"
#include "ARLayoutSource.h"
#include "ARTagLayout.h"
#include "IARLayoutFilter.h"

// {6B6AFF82-D374-40f5-9F77-C1652EB512CF}
DEFINE_GUID(CLSID_ARLayoutFilter, 
			0x6b6aff82, 0xd374, 0x40f5, 0x9f, 0x77, 0xc1, 0x65, 0x2e, 0xb5, 0x12, 0xcf);



class ARLayoutFilter :
	public CSourceStream, public IARLayoutFilter, ISpecifyPropertyPages
{
public:
	STDMETHODIMP NonDelegatingQueryInterface(REFIID iid, void **ppv);
	DECLARE_IUNKNOWN;
	//implement DShow Interface
	virtual HRESULT          GetMediaType(CMediaType *pMediaType);
	virtual HRESULT          DecideBufferSize(IMemAllocator *pAllocator, ALLOCATOR_PROPERTIES *pProp);
	virtual HRESULT          FillBuffer(IMediaSample *pSample) ;
    STDMETHODIMP Notify (IBaseFilter *pSender, Quality q);
public:

	ARLayoutFilter(HRESULT *phr, ARLayoutSource *pParent, LPCWSTR pPinName);
	virtual ~ARLayoutFilter();
	HRESULT WriteToLayout(LPWSTR wszText,BYTE* pData, VIDEOINFOHEADER* pVih );
	HRESULT WriteToMask(LPWSTR wszText,BYTE* pData, VIDEOINFOHEADER* pVih );
	HRESULT LoadnewBitmap();
	STDMETHODIMP     GetPages(CAUUID *pPages);

public:

    LPCWSTR			PinName;
	LPCWSTR			LayoutPin;
	LPCWSTR			MaskPin;
	BITMAPINFO		m_bmpInfo;
	void			*m_pPaintBuffer;
	//////////////////////////////////////////////////////////////////////////
	HDC				m_dcPaint;
	int				m_iImageHeight;                 // The current image height
	int				m_iImageWidth;                  // And current image width
	LONGLONG		m_llFrameCount;
protected:

	int m_FramesWritten;				// To track where we are in the file
	BOOL m_bZeroMemory;                 // Do we need to clear the buffer?
	CRefTime m_rtSampleTime;	        // The time stamp for each sample

	BITMAPINFO *m_pBmi;                 // Pointer to the bitmap header
	DWORD       m_cbBitmapInfo;         // Size of the bitmap header

	// File opening variables 
	HANDLE m_hFile;                     // Handle returned from CreateFile
	BYTE * m_pFile;                     // Points to beginning of file buffer
	BYTE * m_pImage;                    // Points to pixel bits           
	BYTE * m_tagImageData;                    // Points to pixel bits    
	int cbFileHeader ;
	IplImage* layoutIplImage ;
	ARLayout *layout;
	bool changeLayout ;

	int m_iFrameNumber;
	const REFERENCE_TIME m_rtFrameLength;

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