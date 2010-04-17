#pragma once
#include "dshow.h"
#include "Streams.h"
#include "GSD3DDisplay.h"
#include <vector>
using namespace std;

class GSD3DLIB_API GSDXFilterBase 
{
protected:
	GS3DDisplay*  m_pD3DDisplay;
	vector<GSTexture2D*> m_pOutTextureList;
	vector<GSTexture2D*> m_pInTextureList;
	vector<GSTexture2D*> m_pRenderTargetList; 

	virtual HRESULT CopyGSTexture2Sample(GSTexture2D* pGSTexture, IMediaSample *pSample, const CMediaType* pMediaType);
	virtual HRESULT CopySample2GSTexture(GSTexture2D*& pGSTexture, IMediaSample *pSample, const CMediaType* pMediaType);
	virtual HRESULT CopyGSTexture(GSTexture2D* pSrc, GSTexture2D* pDest);
	virtual HRESULT initD3D(LPCWSTR szEffectPath, UINT szSize, UINT bufW, UINT bufH, UINT nInTex = 1, UINT nOutTex = 1, UINT nRT = 1,  ID3D11Device* pDevice = NULL, ID3D11DeviceContext* pDeviceContext = NULL, IDXGISwapChain* pSwapChain = NULL);
	virtual HRESULT ReleaseD3D();
	virtual HRESULT ReleaseAllTextures();
	///May will be overwritten by inherited class 
	virtual HRESULT DoTransform(IMediaSample *pInSample, IMediaSample *pOutSample, const CMediaType* pInType, const CMediaType* pOutType);
	virtual HRESULT DoTransformEx(IMediaSample *pInSample, IMediaSample *pOutSample, const CMediaType* pInType, const CMediaType* pOutType,
		GSTexture2D* pGSInTexture, GSTexture2D* pGSRTTexture, GSTexture2D* pGSOutTexture);
	virtual HRESULT CreateTextures(UINT bufW, UINT bufH, UINT nIn = 1, UINT nRT = 1, UINT nOut =1);
	virtual GS3DDisplay* Create3DDisplay(UINT bufW, UINT bufH);
	virtual GS3DDisplay* Create3DDisplay(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext, IDXGISwapChain* pSwapChain);
	virtual GSRenderBase::CBEffectSetting GetCBEffectSetting();
	static HRESULT __stdcall OnEffectSetting(ID3DX11Effect* pEffect, void* self);
public:
	GSDXFilterBase();
	virtual ~GSDXFilterBase();
};