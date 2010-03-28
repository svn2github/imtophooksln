#pragma once
#include "ITouchLibFilter.h"
#include "dshow.h"
#include "Streams.h"
#include <initguid.h>
#include "combase.h"
#include "CMuxTransformFilter.h"
#include "TouchScreenDevice.h"
#include "CTouchScreen.h"
#include "..\OSCSender\OSCSender.h"
#include "MSPersist.h"

using namespace touchlib;

class TouchLibFilter :
	public CMuxTransformFilter, public ITouchLibFilter,
	public ISpecifyPropertyPages, public ITouchListener,
	public CMSPersist
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
	//implement IMSPersist
	virtual HRESULT SaveToFile(WCHAR* filename);
	virtual HRESULT LoadFromFile(WCHAR* filename);
	virtual HRESULT GetName(WCHAR* name, UINT szName);
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
	CCritSec m_csROIData;
	ROIData m_ROIData;
	bool m_bFingerFlipY;
	bool m_bSkipBGRemove;
	
	bool DestoryTouchScreen();
	virtual bool ShowConfigWindow(bool bShow);
	HRESULT ReceiveInput0(IMediaSample *pSample, const IPin* pReceivePin);
	HRESULT ReceiveROI(IMediaSample *pSample, const IPin* pReceivePin);
	HRESULT TransformInput0(IMediaSample *pIn, IMediaSample *pOut);
	HRESULT SendForegroundSample();
	

	CMuxTransformInputPin* GetConnectedInputPin();
	vector<ITouchListener*> m_listenerList;
	CCritSec m_csListenerList;
	CCritSec m_csTouchScreen;
	OSCSender* m_oscSender;
	CCritSec m_csFilterState;
protected:
	bool CreateTouchScreen(int cw, int ch, bool bSkipbackgroundRemove = false);
	bool IsAcceptedType(const CMediaType *pmt);
public:
	TouchLibFilter(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData);
	virtual ~TouchLibFilter();
	virtual void registerListener(ITouchListener *listener);
	virtual void unregisterListener(ITouchListener *listener);
	virtual bool IsOSCConnected();
	virtual bool ConnectOSC(char* ipaddress, int port);
	virtual bool DisConnectOSC();
	virtual bool GetIPAddress(char* outIpAddress);
	virtual int GetPort();
	virtual bool IsTouchReady();

	virtual bool ClearBackground();
	virtual bool setStartTracking(bool bStart);
	virtual bool getStartTracking(bool& bStart);

	virtual bool getDrawFingers();
	virtual bool setDrawFingers(bool drawing);
	virtual bool getDrawROI();
	virtual bool setDrawROI(bool drawing);
	virtual int getNumFrameFix();
	virtual bool setNumFrameFix(int nFrame);
	virtual bool getUseKalmanFilter();
	virtual bool setUseKalmanFilter(bool bUse);
	virtual bool getKalmanMNoise(float& fMNoise);
	virtual bool setKalmanMNoise(float fMNoise);

	virtual bool SetBGThreshold(int threshold);
	virtual bool GetBGThreshold(int& threshold);
	virtual bool SetSimpleHighPassBlur(int blur);
	virtual bool GetSimpleHighPassBlur(int& blur);
	virtual	bool SetSimpleHighPassDeNoise(int deNoise);
	virtual bool GetSimpleHighPassDeNoise(int& deNoise);
	virtual bool SetScaleLevel(int level);
	virtual bool GetScaleLevel(int& level);
	virtual bool SetRectifyLevel(int level);
	virtual bool GetRectifyLevel(int& level);

	virtual bool GetbFlipY();
	virtual bool SetbFlipY(bool v);

	virtual bool GetIsSkipBGRemove();
	virtual bool SetIsSKipBGRemove(bool isSkipBG);
};
