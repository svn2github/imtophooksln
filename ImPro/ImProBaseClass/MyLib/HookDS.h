#pragma once

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
#include "dshow.h"
#include "qedit.h"
#include "DSBase.h"
#include <InitGuid.h>
#include "IDXRenderer.h"
#include "IHomoWarpFilter.h"
#include "IHookDrawingFilter.h"
#include "IHookDrawingStream.h"
#include "Filters\ILEncH2644.h"
#include "DSBaseClass.h"

#define NUMHOOKPIN 4

class DSBASECLASSES_API HookDS :
	public CDSBase
{
protected:
	CComPtr<IBaseFilter> m_pHookFilter;
	CComPtr<IHookDrawingFilter> m_pIHookFilter;	
	CComPtr<IPin> m_pHookOutputPin[NUMHOOKPIN];
	CComPtr<IHookDrawingStream> m_pIHookOutputPin[NUMHOOKPIN];

	CComPtr<IBaseFilter> m_pWarpFilter[NUMHOOKPIN];
	CComPtr<IHomoWarpFilter> m_pIWarpFilter[NUMHOOKPIN];
	CComPtr<IPin> m_pWarpInputPin[NUMHOOKPIN];
	CComPtr<IPin> m_pWarpOutputPin[NUMHOOKPIN];
	/*
	CComPtr<IBaseFilter> m_pH264Encoder[NUMHOOKPIN];
	CComPtr<IPin> m_pH264EncoderInputPin[NUMHOOKPIN];
	CComPtr<IPin> m_pH264EncoderOutputPin[NUMHOOKPIN];
	*/

	CComPtr<IBaseFilter> m_pSampleGrabber[NUMHOOKPIN];
	CComPtr<ISampleGrabber> m_pISampleGrabber[NUMHOOKPIN];
	CComPtr<IPin> m_pSampleGrabberInputPin[NUMHOOKPIN];
	CComPtr<IPin> m_pSampleGrabberOutputPin[NUMHOOKPIN];

	CComPtr<IBaseFilter> m_pDXRenderFilter[NUMHOOKPIN];
	CComPtr<IDXRenderer> m_pIDXRenderFilter[NUMHOOKPIN];
	CComPtr<IPin> m_pDXRenderInputPin[NUMHOOKPIN];

	//overwrite DSBase function
	virtual HRESULT ConnectGraph();
	virtual HRESULT CreateFilters();
	virtual HRESULT ConfigFilters();
public:
	virtual HRESULT UnInitDS();
	virtual HRESULT ShowHookFilterProp();
	virtual HRESULT ShowHookPinProp(int idx);
	virtual HRESULT ShowDXRenderProp(int idx);
	virtual HRESULT ShowWarpProp(int idx);

	//Hook APIs
	virtual const D3DXMATRIX* GetHookPinWarpMatrix(int idx);
	virtual BOOL SetHookPinWarpMatrix(int idx, const D3DXMATRIX& mat);
	virtual BOOL SetHookPinWarpByPts(int idx, const D3DXVECTOR2& lt, const D3DXVECTOR2& lb,
		const D3DXVECTOR2& rb, const D3DXVECTOR2& rt);
	virtual BOOL GetHookPinWarpPts(int idx, D3DXVECTOR2& lt, D3DXVECTOR2& lb, D3DXVECTOR2& rb, 
		D3DXVECTOR2& rt);

	virtual BOOL GetHookPinResolution(int idx, UINT& resW, UINT& resH);
	virtual BOOL SetHookPinResolution(int idx, UINT resW, UINT resH);
	virtual float GetHookPinFrameRate(int idx);
	virtual BOOL SetHookPinFrameRate(int idx, float fps);
	virtual BOOL GetHookSourceResolution(UINT& w, UINT& h);
	virtual BOOL SetHookSourceResolution(UINT w, UINT h);
	//Warp APIs

	virtual HRESULT SetWarpVertex(int idx, float LTx, float LTy, float LBx, float LBy, 
		float RBx, float RBy, float RTx, float RTy);
	virtual HRESULT GetWarpVertex(int idx, float& LTx, float& LTy, float& LBx, float& LBy, 
		float& RBx, float& RBy, float& RTx, float& RTy);
	virtual HRESULT SetWarpMatrix(int idx, const D3DXMATRIX& mat);
	virtual HRESULT GetWarpMatrix(int idx, D3DXMATRIX& mat);
	virtual bool GetWarpIsFlipY(int idx);
	virtual bool SetWarpIsFlipY(int idx, bool bFlipY);
	virtual bool GetIsInvWarp(int idx);
	virtual bool SetIsInvWarp(int idx, bool bInv);
	
	//SampleGrabber API
	virtual HRESULT SetCallback(int idx, ISampleGrabberCB *pCallback,
		long WhichMethodToCallback);
	virtual HRESULT SetOneShot(int idx, BOOL OneShot);
	virtual HRESULT GetConnectedMediaType( int idx,	AM_MEDIA_TYPE *pType);
	virtual HRESULT SetBufferSamples(int idx, BOOL BufferThem);
	virtual HRESULT GetCurrentBuffer( int idx, /* [out][in] */ long *pBufferSize,
		/* [out] */ long *pBuffer);
	virtual HRESULT GetCurrentSample( int idx,  IMediaSample **ppSample);
public:
	HookDS(void);
	~HookDS(void);
};
