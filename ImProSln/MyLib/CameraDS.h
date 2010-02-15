
#ifndef CCAMERA_H
#define CCAMERA_H

#define WIN32_LEAN_AND_MEAN

#define __IDxtCompositor_INTERFACE_DEFINED__ 

#define __IDxtAlphaSetter_INTERFACE_DEFINED__ 

#define __IDxtJpeg_INTERFACE_DEFINED__ 

#define __IDxtKey_INTERFACE_DEFINED__ 



#include "oaidl.h"
#include "ocidl.h"
#include "amstream.h"
#include <BaseTsd.h>
#include <windows.h>
#include <atlbase.h>
#include "qedit.h"
#include "dshow.h"
#include "cv.h"
#define MYFREEMEDIATYPE(mt)	{if ((mt).cbFormat != 0)		\
					{CoTaskMemFree((PVOID)(mt).pbFormat);	\
					(mt).cbFormat = 0;						\
					(mt).pbFormat = NULL;					\
				}											\
				if ((mt).pUnk != NULL)						\
				{											\
					(mt).pUnk->Release();					\
					(mt).pUnk = NULL;						\
				}}									


class CCameraDS  
{
protected:
	IplImage * m_pFrame;
	bool m_bConnected;
	int m_nWidth;
	int m_nHeight;
	bool m_bLock;
	bool m_bChanged;
	long m_nBufferSize;
	
	CComPtr<IGraphBuilder> m_pGraph;
	CComPtr<IBaseFilter> m_pDeviceFilter;
	CComPtr<IMediaControl> m_pMediaControl;
	CComPtr<IBaseFilter> m_pSampleGrabberFilter;
	CComPtr<ISampleGrabber> m_pSampleGrabber;
	CComPtr<IPin> m_pGrabberInput;
	CComPtr<IPin> m_pGrabberOutput;
	CComPtr<IPin> m_pCameraOutput;
	CComPtr<IMediaEvent> m_pMediaEvent;
	CComPtr<IBaseFilter> m_pRenderFilter;
	CComPtr<IPin> m_pRenderInputPin;
	CComPtr<IVideoWindow> m_pVideoWindow;

private:
	bool BindFilter(int nCamIDX, IBaseFilter **pFilter);
	void SetCrossBar();
protected:
	
	virtual HRESULT ConnectGraph();
	virtual HRESULT CreateGraph(IGraphBuilder** ppGraph);
	virtual HRESULT CreateFilters(int nCamID, bool bDisplayProperties, int nWidth, int nHeight);
public:
	CCameraDS();
	virtual ~CCameraDS();

	virtual bool OpenCamera(int nCamID, bool bDisplayProperties=true, int nWidth=320, int nHeight=240);
	virtual void CloseCamera();
	virtual HRESULT Play();
	virtual HRESULT Stop();
	virtual HRESULT Pause();
	virtual HRESULT ShowCamProp();
	virtual HRESULT ShowCamPinProp();


	virtual bool SetVideoWindow(HWND hwnd);
	virtual HRESULT SaveGraphFile(WCHAR *wszPath);
	static int CameraCount(); 
	static int CCameraDS::CameraName(int nCamID, char* sName, int nBufferSize);
	int GetWidth(){return m_nWidth;} 
	int GetHeight(){return m_nHeight;}
	IplImage * QueryFrame();
};

#endif 
