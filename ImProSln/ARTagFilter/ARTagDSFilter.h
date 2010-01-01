#ifndef _ARTAGDSFILTER_H
#define  _ARTAGDSFILTER_H

#include "dshow.h"
#include "Streams.h"
#include <initguid.h>
#include "combase.h"
#include "ARToolKitPlus/TrackerMultiMarker.h"
#include "ARTagD3DDisplay.h"
DEFINE_GUID(CLSID_ARTagDSFilter, 
			0x889c4fa1, 0xfb51, 0x4118, 0x80, 0xb8, 0xc0, 0x3f, 0x51, 0x4a, 0xab, 0x3);

DEFINE_GUID(IID_IARTagDSFilter, 
			0xe47942df, 0xb438, 0x4d85, 0xa9, 0xec, 0x7b, 0x56, 0x55, 0xe6, 0x8d, 0xfd);


// {4AE740F1-4AB8-4436-B346-189DD369B965}
DEFINE_GUID(CLSID_ARTagCameraProperty, 
			0x4ae740f1, 0x4ab8, 0x4436, 0xb3, 0x46, 0x18, 0x9d, 0xd3, 0x69, 0xb9, 0x65);

// {3333AFC9-B73B-440b-85FF-3656E4457958}
DEFINE_GUID(CLSID_ARTagProperty, 
			0x3333afc9, 0xb73b, 0x440b, 0x85, 0xff, 0x36, 0x56, 0xe4, 0x45, 0x79, 0x58);

MIDL_INTERFACE("E47942DF-B438-4d85-A9EC-7B5655E68DFD")
IARTagFilter: public IUnknown
{
public:
	typedef BOOL (__stdcall* CallbackFuncPtr)(int numDetected, const ARMarkerInfo* markinfos, const double* matView, const double* matProj);
	virtual BOOL SetCallback(CallbackFuncPtr pfunc);

	virtual bool IsReady();
	virtual bool setMarkInfo(ARToolKitPlus::ARMultiEachMarkerInfoT *marker, int numMarker);
	virtual bool setCamera(int xsize, int ysize, double* mat, double* dist_factor,double nNearClip, double nFarClip);
	virtual bool getCamera(int& xsize, int &ysize, double* mat, double* dist_factor);
	virtual bool setBorderWidth(double borderWidth);
	virtual double getBorderWidth();
	virtual bool setThreshold(int t);
	virtual int getThreshold();
	virtual bool setUndistortionMode(int mode);
	virtual int getUndistortionMode();
	virtual bool setMarkerMode(int mode);
	virtual int getMarkerMode();
	virtual bool setPoseEstimator(int rpp);
	virtual int getPoseEstimator();
	virtual bool getbDrawTag();
	virtual bool setbDrawTag(bool v);
};



class ARTagDSFilter :
	public CTransformFilter, public IARTagFilter,
	public ISpecifyPropertyPages
{

public:
	static CUnknown *WINAPI CreateInstance(LPUNKNOWN punk, HRESULT *phr);

	//for COM interface 
	
	STDMETHODIMP NonDelegatingQueryInterface(REFIID iid, void **ppv);
	DECLARE_IUNKNOWN;
	//override CTransformFilter Method

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
	virtual bool setCamera(int xsize, int ysize, double* mat, double* dist_factor,ARFloat nNearClip, ARFloat nFarClip);

	virtual bool getCamera(int& xsize, int &ysize, double* mat, double* dist_factor);
	virtual bool setMarkInfo(ARToolKitPlus::ARMultiEachMarkerInfoT *marker, int numMarker);

	virtual bool setBorderWidth(double borderWidth);
	virtual double getBorderWidth();
	virtual bool setThreshold(int t);
	virtual int getThreshold();
	virtual bool setUndistortionMode(int mode);
	virtual int getUndistortionMode();
	virtual bool setMarkerMode(int mode);
	virtual int getMarkerMode();
	virtual bool setPoseEstimator(int rpp);
	virtual int getPoseEstimator();
	virtual bool getbDrawTag();
	virtual bool setbDrawTag(bool v);
	virtual bool IsReady();

	virtual BOOL SetCallback(CallbackFuncPtr pfunc);

protected:

	//
	bool			 m_bDrawTag;
	CMediaType       m_InputMT;
	CMediaType       m_OutputMT;
	CallbackFuncPtr  m_pCallback;
	ARToolKitPlus::TrackerMultiMarker *m_ARTracker;

	bool             IsAcceptedType(const CMediaType *pMT);
	//for D3DDevice
	
	HWND			 m_hWndD3D ;
	IDirect3D9*      m_pD3D ;
	ARTagD3DDisplay* m_pD3DDisplay;

	LPDIRECT3DTEXTURE9 m_pOutTexture;
	LPDIRECT3DTEXTURE9 m_pInTexture;

	HWND GetD3DWnd();
	IDirect3D9* GetD3D();
	HRESULT initD3D(UINT rtWidth = 0, UINT rtHeight = 0);
	BOOL ReleaseD3D();
	static LRESULT CALLBACK D3DWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	static ATOM RegisterWndClass(HINSTANCE hInstance);
	
public:
	ARTagDSFilter(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData);
	virtual ~ARTagDSFilter();
};

#endif