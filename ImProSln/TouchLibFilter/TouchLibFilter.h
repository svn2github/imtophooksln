#pragma once
#include "ITouchLibFilter.h"
#include "dshow.h"
#include "Streams.h"
#include <initguid.h>
#include "combase.h"
#include "CMuxTransformFilter.h"
#include "TouchScreenDevice.h"

using namespace touchlib;

// {F982AA58-0213-4235-B342-314D853D5CEE}
DEFINE_GUID(CLSID_TouchLibFilter, 
			0xf982aa58, 0x213, 0x4235, 0xb3, 0x42, 0x31, 0x4d, 0x85, 0x3d, 0x5c, 0xee);


class TouchLibFilter :
	public CMuxTransformFilter, public ITouchLibFilter,
	public ISpecifyPropertyPages, public ITouchListener
{

public:
	static CUnknown *WINAPI CreateInstance(LPUNKNOWN punk, HRESULT *phr);

	//for COM interface 
	STDMETHODIMP NonDelegatingQueryInterface(REFIID iid, void **ppv);
	DECLARE_IUNKNOWN;

	//implement CMuxTransformFilter Interface
	virtual HRESULT Receive(IMediaSample *pSample, const IPin* pReceivePin);
	virtual HRESULT CreatePins();
	virtual HRESULT CheckInputType(const CMediaType* mtIn, const IPin* pPin);
	virtual HRESULT CheckOutputType(const CMediaType* mtOut, const IPin* pPin);
	virtual HRESULT DecideBufferSize(IMemAllocator * pAllocator, const IPin* pOutPin,
		__inout ALLOCATOR_PROPERTIES *pprop);
	virtual HRESULT GetMediaType(int iPosition, const IPin* pOutPin, __inout CMediaType *pMediaType);
	virtual HRESULT CompleteConnect(PIN_DIRECTION direction, const IPin* pMyPin, const IPin* pOtherPin);
	virtual HRESULT BreakConnect(PIN_DIRECTION dir, const IPin* pPin);
	//implement DShow Property Page
	STDMETHODIMP     GetPages(CAUUID *pPages);
	//implement ITouchLibFilterProperty

	//ITouchListener
	virtual void fingerDown(TouchData data);
	//! Notify that a finger has just been made active. 
	virtual void fingerUpdate(TouchData data);
	//! A finger is no longer active..
	virtual void fingerUp(TouchData data);
protected:
	ITouchScreen* m_pTouchScreen;
	string m_monolabel, m_bgLabel, m_shpLabel, 
		m_scalerLabel, m_rectifyLabel;

	/*float m_blurLevel;
	float m_noiseLevel;
	int m_noiseSmoothType;
	unsigned int m_levelScale;
	unsigned int m_levelRectify;
	bool m_bAutoSet;
	IplImage* m_buffer;

	
	bool SimpleHighpassFilter(IplImage* srcImage, IplImage* dstImage);
	bool ScaleFilter(IplImage* srcImage, IplImage* dstImage);
	bool RectifyFilter(IplImage* srcImage, IplImage* dstImage);
	*/
	bool CreateTouchScreen();
	bool DestoryTouchScreen();
	HRESULT ReceiveInput0(IMediaSample *pSample, const IPin* pReceivePin);
	HRESULT TransformInput0(IMediaSample *pIn, IMediaSample *pOut);
protected:
	bool IsAcceptedType(const CMediaType *pmt);
public:
	TouchLibFilter(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData);
	virtual ~TouchLibFilter();
};
