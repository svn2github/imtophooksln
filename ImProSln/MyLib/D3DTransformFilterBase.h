#pragma once
#include "dshow.h"
#include "Streams.h"
#include "D3DEnv.h"
#include "MSSD3DClass.h"
#include "MSD3DLib.h"

class MSD3DLIB_API D3DTransformFilterBase : public D3DEnv
{
protected:
	MS3DDisplay*  m_pD3DDisplay;
	int m_texW, m_texH; // User for reCreateTexture after device lost
	LPDIRECT3DTEXTURE9 m_pOutTexture;
	LPDIRECT3DTEXTURE9 m_pInTexture;
	LPDIRECT3DTEXTURE9 m_pRenderTarget;

	LPDIRECT3DSURFACE9 m_pBackupRenderTarget;
	CCritSec m_csD3DDisplay;
	CCritSec m_csInTexture; // Use Multi CS have to depend on this order to avoid deadlock.
	CCritSec m_csOutTexture;
	CCritSec m_csRenderTarget;
	

	virtual HRESULT SetRenderTarget();
	virtual HRESULT ResetRenderTarget();

	virtual HRESULT CopyOutputTexture2OutputData(IMediaSample *pOut, const CMediaType* pOutMediaType, bool bFlipY);
	virtual HRESULT CopyRenderTarget2OutputTexture();
	virtual HRESULT CopyInputImage2InputTexture(IMediaSample *pIn, const CMediaType* pInType, bool bFlipY);
	virtual HRESULT DoTransform(IMediaSample *pIn, IMediaSample *pOut, const CMediaType* pInType, const CMediaType* pOutType, bool bFlipY);
	virtual HRESULT CreateTextures(UINT w, UINT h);
	virtual MS3DDisplay* Create3DDisplay(IDirect3D9* pD3D, int rtWidth, int rtHeight) = 0;
	virtual MS3DDisplay* Create3DDisplay(IDirect3DDevice9* pDevice, int rtWidth, int rtHeight) = 0;
	virtual HRESULT initD3D(UINT rtWidth = 0, UINT rtHeight = 0);
	virtual HRESULT ReleaseD3D();
	virtual HRESULT OnBeforeResetDevice(IDirect3DDevice9 * pd3dDevice, 
		void* pUserContext);
	virtual HRESULT OnAfterResetDevice(IDirect3DDevice9 * pd3dDevice, 
		void* pUserContext);
	
	static HRESULT CALLBACK OnBeforeDisplayResetDevice(IDirect3DDevice9 * pd3dDevice, 
		void* pUserContext);
	static HRESULT CALLBACK OnAfterDisplayResetDevice(IDirect3DDevice9 * pd3dDevice, 
		void* pUserContext);

	D3DTransformFilterBase();
	virtual ~D3DTransformFilterBase();
};