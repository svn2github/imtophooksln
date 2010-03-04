#pragma once
#include "ISyncFilter.h"
#include "dshow.h"
#include "Streams.h"
#include <initguid.h>
#include "combase.h"
#include "CMuxTransformFilter.h"
#include "cv.h"

// {E1C813B2-CD41-43e1-985A-EF40CE6EC88D}
DEFINE_GUID(CLSID_SyncFilter, 
			0xe1c813b2, 0xcd41, 0x43e1, 0x98, 0x5a, 0xef, 0x40, 0xce, 0x6e, 0xc8, 0x8d);

class SyncFilter :
	public CMuxTransformFilter, public ISyncFilter
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
	//STDMETHODIMP     GetPages(CAUUID *pPages);

protected:
	HRESULT CamTransform( IMediaSample *pIn, IMediaSample *pOut);
	HRESULT LayoutTransform( IMediaSample *pIn, IMediaSample *pOut);
protected:
	virtual bool  IsAcceptedType(const CMediaType *pMT);
	BYTE* InData;
	BYTE* LayoutData;
	BYTE* CamData;
	bool Dirty;
	bool Block;

private:
	virtual HRESULT ReceiveCameraImg(IMediaSample *pSample, const IPin* pReceivePin);
	virtual HRESULT ReceiveDirty();
	virtual HRESULT ReceiveLayoutImg(IMediaSample *pSample, const IPin* pReceivePin);
	bool getDirty();
	HRESULT setDirty(bool isDirty);
	bool getBlock();
	HRESULT setBlock(bool isBlock);


	virtual CMuxTransformOutputPin* GetConnectedOutputPin(int index);
public:
	SyncFilter(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData);
	virtual ~SyncFilter();
private:


	CCritSec m_cSharedState;            // Protects our internal state
	CCritSec locDirty;
	CCritSec locBlock;
	IplImage* backgroundIplImg;
	IplImage* foregroundIplImg;
	IplImage* cameraInputIplImg;

};
