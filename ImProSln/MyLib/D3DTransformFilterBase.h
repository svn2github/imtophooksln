#pragma once
#include "dshow.h"
#include "Streams.h"
#include "D3DEnv.h"
#include "MSSD3DClass.h"

class D3DTransformFilterBase : public D3DEnv
{
protected:
	MS3DDisplay*  m_pD3DDisplay;

	LPDIRECT3DTEXTURE9 m_pOutTexture;
	LPDIRECT3DTEXTURE9 m_pInTexture;
	virtual HRESULT CopyOutputTexture2OutputData(IMediaSample *pOut, const CMediaType* pOutMediaType, bool bFlipY);
	virtual HRESULT CopyRenderTarget2OutputTexture();
	virtual HRESULT CopyInputImage2InputTexture(IMediaSample *pIn, const CMediaType* pInType, bool bFlipY);
	virtual HRESULT DoTransform(IMediaSample *pIn, IMediaSample *pOut, const CMediaType* pInType, const CMediaType* pOutType, bool bFlipY);
	virtual HRESULT CreateInOutTextures(UINT w, UINT h);
	virtual MS3DDisplay* Create3DDisplay(HWND hWndD3D,IDirect3D9* pD3D, int rtWidth, int rtHeight) = 0;

	virtual HRESULT initD3D(UINT rtWidth = 0, UINT rtHeight = 0);
	virtual HRESULT ReleaseD3D();

public:
	D3DTransformFilterBase();
	virtual ~D3DTransformFilterBase();
};