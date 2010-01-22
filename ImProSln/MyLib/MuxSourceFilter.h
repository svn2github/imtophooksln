#pragma once

#include "dshow.h"
#include "Streams.h"
#include <initguid.h>
#include "combase.h"
#include <vector>
using namespace std;

class CMuxSourceOutputPin;

class CMuxSourceFilter : public CSource
{
	friend class CMuxSourceOutputPin;
protected:
	//PURE function have to be implemented by Derived class
	virtual HRESULT CreatePins() = 0;
	virtual HRESULT FillBuffer(IMediaSample *pSamp, IPin* pPin) = 0;
	virtual HRESULT GetMediaType(int iPosition, __inout CMediaType *pMediaType, IPin* pPin) = 0; 
	// Called as the thread is created/destroyed - use to perform
	// jobs such as start/stop streaming mode
	// If OnThreadCreate returns an error the thread will exit.
	virtual HRESULT OnThreadCreate(IPin* pPin){return NOERROR;};
	virtual HRESULT OnThreadDestroy(IPin* pPin){return NOERROR;};
	virtual HRESULT OnThreadStartPlay(IPin* pPin){return NOERROR;};
	
public:
	CMuxSourceFilter(__in_opt LPCTSTR pName, __inout_opt LPUNKNOWN lpunk, CLSID clsid, __inout HRESULT *phr);
	CMuxSourceFilter(__in_opt LPCTSTR pName, __inout_opt LPUNKNOWN lpunk, CLSID clsid);
#ifdef UNICODE
	CMuxSourceFilter(__in_opt LPCSTR pName, __inout_opt LPUNKNOWN lpunk, CLSID clsid, __inout HRESULT *phr);
	CMuxSourceFilter(__in_opt LPCSTR pName, __inout_opt LPUNKNOWN lpunk, CLSID clsid);
#endif
	virtual ~CMuxSourceFilter(void);
};




class CMuxSourceOutputPin : public CSourceStream
{
	friend class CMuxSourceFilter;
public:
	CMuxSourceOutputPin(__in_opt LPCSTR pObjectName,
		__inout HRESULT *phr,__inout CMuxSourceFilter *pms,__in_opt LPCWSTR pName);

	virtual ~CMuxSourceOutputPin();

	virtual HRESULT FillBuffer(IMediaSample *pSamp);

	// Called as the thread is created/destroyed - use to perform
	// jobs such as start/stop streaming mode
	// If OnThreadCreate returns an error the thread will exit.
	virtual HRESULT OnThreadCreate(void);
	virtual HRESULT OnThreadDestroy(void);
	virtual HRESULT OnThreadStartPlay(void);

	// *
	// * AM_MEDIA_TYPE support
	// *

    virtual HRESULT GetMediaType(int iPosition, __inout CMediaType *pMediaType);  // List pos. 0-n

	
};


