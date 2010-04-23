
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
#include <qedit.h>
#include "dshow.h"
#include "cv.h"
#include "DSBase.h"
#include "DSBaseClass.h"

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


class DSBASECLASSES_API CCameraDS : public CDSBase
{
protected:
	CComPtr<IBaseFilter> m_pDeviceFilter;
	CComPtr<IBaseFilter> m_pSampleGrabberFilter;

	CComPtr<ISampleGrabber> m_pSampleGrabber;
	CComPtr<IPin> m_pGrabberInput;
	CComPtr<IPin> m_pGrabberOutput;

	CComPtr<IPin> m_pCameraOutput;
	CComPtr<IBaseFilter> m_pRenderFilter;
	CComPtr<IPin> m_pRenderInputPin;


private:
	void SetCrossBar();

protected:
	bool BindFilter(int nCamIDX, IBaseFilter **pFilter);
	virtual HRESULT ConfigFilters();
	virtual HRESULT ConnectGraph();
	virtual HRESULT CreateFilters(int nCamID, bool bDisplayProperties, int nWidth, int nHeight);

public:
	CCameraDS();
	virtual ~CCameraDS();

	virtual bool OpenCamera(int nCamID, bool bDisplayProperties=true, int nWidth=320, int nHeight=240);
	virtual void CloseCamera();

	virtual HRESULT ShowCamProp();
	virtual HRESULT ShowCamPinProp();

	HRESULT QueryFrame(IplImage*& pFrame);
	static int CameraCount(); 
	static int CCameraDS::CameraName(int nCamID, WCHAR* sName, int nBufferSize);

};

#endif 
