#pragma once
#include "IBGMappingFilter.h"
#include "dshow.h"
#include "Streams.h"
#include <initguid.h>
#include "combase.h"
#include "CMuxTransformFilter.h"
#include "BGMapping.h"

// {D9CC776C-18CC-41f3-98EE-4F897B7350E3}
DEFINE_GUID(CLSID_BGMappingFilter, 
			0xd9cc776c, 0x18cc, 0x41f3, 0x98, 0xee, 0x4f, 0x89, 0x7b, 0x73, 0x50, 0xe3);


class BGMappingFilter :
	public CMuxTransformFilter, public IBGMappingFilter
	,public ISpecifyPropertyPages
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

protected:
	HRESULT Transform( IMediaSample *pIn, IMediaSample *pOut);
	HRESULT ChangeBG();
protected:
	virtual bool  IsAcceptedType(const CMediaType *pMT);
private:
	virtual HRESULT ReceiveCameraImg(IMediaSample *pSample, const IPin* pReceivePin);
	virtual HRESULT ReceiveBackground(IMediaSample *pSample, const IPin* pReceivePin);
	virtual CMuxTransformOutputPin* GetConnectedOutputPin();
public:
	BGMappingFilter(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData);
	virtual ~BGMappingFilter();

public:
	virtual HRESULT setBGThreshold(int BGthres) ;
	virtual int getBGThreshold();
	virtual HRESULT setBlackValue(int bValue) ;
	virtual int getBlackValue();
	virtual HRESULT setWhiteValue(int wValue) ;
	virtual int getWhiteValue();
	virtual HRESULT setCamFlip(bool value) ;
	virtual bool getCamFlip();
	virtual HRESULT setLayoutFlip(bool value) ;
	virtual bool getLayoutFlip();
	virtual HRESULT setOutputFlip(bool value) ;
	virtual bool getOutputFlip();

	HRESULT SendForegroundRect();



private:

	BackGroundMapping* BG ;
	CCritSec m_cSharedState;            // Protects our internal state
	IplImage* backgroundIplImg;
	IplImage* foregroundIplImg;
	IplImage* cameraInputIplImg;
	int cameraW ;
	int cameraH ;
	int layoutW ;
	int layoutH ;
	int camChannel;
	int layoutChannel;
	bool isReceiveCam ; 


};
