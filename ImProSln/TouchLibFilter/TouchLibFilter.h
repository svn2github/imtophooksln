#pragma once
#include "ITouchLibFilter.h"
#include "dshow.h"
#include "Streams.h"
#include <initguid.h>
#include "combase.h"
#include "CMuxTransformFilter.h"
#include "TouchScreenDevice.h"
#include "..\OSCSender\OSCSender.h"
using namespace touchlib;

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

	bool CreateTouchScreen(float cw, float ch, bool bSkipbackgroundRemove = false);
	bool DestoryTouchScreen();
	virtual bool ShowConfigWindow(bool bShow);
	HRESULT ReceiveInput0(IMediaSample *pSample, const IPin* pReceivePin);
	HRESULT TransformInput0(IMediaSample *pIn, IMediaSample *pOut);
	HRESULT SendForegroundSample();


	CMuxTransformInputPin* GetConnectedInputPin();
	vector<ITouchListener*> m_listenerList;
	CCritSec m_csListenerList;
	CCritSec m_csTouchScreen;
	OSCSender* m_oscSender;
protected:
	bool IsAcceptedType(const CMediaType *pmt);
public:
	TouchLibFilter(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData);
	virtual ~TouchLibFilter();
	virtual void registerListener(ITouchListener *listener);
	virtual void unregisterListener(ITouchListener *listener);
	virtual bool IsOSCConnected();
	virtual bool ConnectOSC(string ipaddress, int port);
	virtual bool DisConnectOSC();
	virtual bool GetIPAddress(string& outIpAddress);
	virtual int GetPort();
	virtual bool IsTouchReady();

	virtual bool ClearBackground();
	virtual bool setStartTracking(bool bStart);
	virtual bool getStartTracking(bool& bStart);

	virtual bool getDrawFingers();
	virtual bool setDrawFingers(bool drawing);
};
