#ifndef _ARTAGDSFILTER_H
#define  _ARTAGDSFILTER_H

#include "dshow.h"
#include "Streams.h"
#include <initguid.h>
#include "combase.h"
#include "ARToolKitPlus/arMulti.h"
#include "ARToolKitPlus/TrackerMultiMarker.h"
DEFINE_GUID(CLSID_ARTagDSFilter, 
			0x889c4fa1, 0xfb51, 0x4118, 0x80, 0xb8, 0xc0, 0x3f, 0x51, 0x4a, 0xab, 0x3);

DEFINE_GUID(IID_IARTagDSFilter, 
			0xe47942df, 0xb438, 0x4d85, 0xa9, 0xec, 0x7b, 0x56, 0x55, 0xe6, 0x8d, 0xfd);

DEFINE_GUID(IID_IARTagProperty, 
			0xfcddbd27, 0x1734, 0x46d3, 0x88, 0xe7, 0x5e, 0x3a, 0xb6, 0x56, 0x21, 0x2c);


// {3333AFC9-B73B-440b-85FF-3656E4457958}
DEFINE_GUID(CLSID_ARTagProperty, 
			0x3333afc9, 0xb73b, 0x440b, 0x85, 0xff, 0x36, 0x56, 0xe4, 0x45, 0x79, 0x58);

MIDL_INTERFACE("E47942DF-B438-4d85-A9EC-7B5655E68DFD")
IARTagFilter: public IUnknown
{
public:

};
MIDL_INTERFACE("FCDDBD27-1734-46d3-88E7-5E3AB656212C")
IARTagProperty : public IUnknown
{
public:
	bool setCamera(int xsize, int ysize, double** mat, double* dist_factor,ARFloat nNearClip, ARFloat nFarClip);
	bool setMarkInfo(ARToolKitPlus::ARMultiEachMarkerInfoT *marker, int numMarker);

	bool setBorderWidth(double borderWidth);
	double getBorderWidth();
	bool setThreshold(int t);
	int getThreshold();
	bool setUndistortionMode(int mode);
	int getUndistortionMode();
	bool setMarkerMode(int mode);
	int getMarkerMode();
	bool setPoseEstimator(int rpp);
    int getPosEstimator();
};

class ARTagDSFilter :
	public CTransformFilter, public IARTagFilter, public IARTagProperty, 
	public ISpecifyPropertyPages
	
{
public:
	static CUnknown *WINAPI CreateInstance(LPUNKNOWN punk, HRESULT *phr);

	//for COM interface 
	
	STDMETHODIMP NonDelegatingQueryInterface(REFIID iid, void **ppv);
	DECLARE_IUNKNOWN;

	//implement DShow Interface
	HRESULT          CheckInputType( const CMediaType * pmt );
	HRESULT          CheckTransform(const CMediaType *pmtIn, const CMediaType *pmtOut);
	HRESULT          CompleteConnect(PIN_DIRECTION direction, IPin *pReceivePin);
	HRESULT          Transform( IMediaSample *pIn, IMediaSample *pOut);
	HRESULT          DecideBufferSize(IMemAllocator *pAllocator, ALLOCATOR_PROPERTIES *pProp);
	HRESULT          GetMediaType(int iPosition, CMediaType *pMediaType);
	//implement DShow Property Page
	STDMETHODIMP     GetPages(CAUUID *pPages);
	//implement IARTagProperty
	bool setCamera(int xsize, int ysize, double** mat, double* dist_factor,ARFloat nNearClip, ARFloat nFarClip);
	bool setMarkInfo(ARToolKitPlus::ARMultiEachMarkerInfoT *marker, int numMarker);

	bool setBorderWidth(double borderWidth);
	double getBorderWidth();
	bool setThreshold(int t);
	int getThreshold();
	bool setUndistortionMode(int mode);
	int getUndistortionMode();
	bool setMarkerMode(int mode);
	int getMarkerMode();
	bool setPoseEstimator(int rpp);
	int getPosEstimator();

protected:
	CMediaType       m_InputMT;
	CMediaType       m_OutputMT;
	
	ARToolKitPlus::TrackerMultiMarker *m_ARTracker;

	bool             IsAcceptedType(const CMediaType *pMT);



public:
	ARTagDSFilter(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData);
	virtual ~ARTagDSFilter();
};

class ARTagPropertyPage : public CBasePropertyPage
{
protected:
	IARTagProperty *m_pARProperty;    // Pointer to the filter's custom interface.
	BOOL m_bDirty;
	void SetDirty();
public:
	ARTagPropertyPage(IUnknown *pUnk);
	~ARTagPropertyPage();


	//override CBasePropertyPage Method
	virtual HRESULT OnConnect(IUnknown *pUnk);
	virtual HRESULT OnDisconnect(void);
	virtual BOOL OnReceiveMessage(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	virtual HRESULT OnActivate(void);
	virtual HRESULT OnApplyChanges(void);
	

	//
	static CUnknown *WINAPI CreateInstance(LPUNKNOWN punk, HRESULT *phr);
};
#endif