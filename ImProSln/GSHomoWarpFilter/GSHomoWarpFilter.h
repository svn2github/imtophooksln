#pragma once

#include "IGSHomoWarpFilter.h"
#include "dshow.h"
#include "Streams.h"
#include <initguid.h>
#include "combase.h"
#include "GSDXFilterBase.h"
#include "GSDXMuxFilter.h"

class GSHomoWarpFilter :
	public GSDXMuxFilter, public IGSHomoWarpFilter
{
public:
	static CUnknown *WINAPI CreateInstance(LPUNKNOWN punk, HRESULT *phr);

	//for COM interface 
	STDMETHODIMP NonDelegatingQueryInterface(REFIID iid, void **ppv);
	DECLARE_IUNKNOWN;
	//from GSDXMuxFilter Interface
	virtual HRESULT CreatePins();
	
	//implement IGSHomoWarpFilter
	virtual HRESULT SetWarpVertex(float LTx, float LTy, float LBx, float LBy, 
		float RBx, float RBy, float RTx, float RTy);
	virtual HRESULT GetWarpVertex(float& LTx, float& LTy, float& LBx, float& LBy, 
		float& RBx, float& RBy, float& RTx, float& RTy);
	virtual HRESULT SetWarpMatrix(const D3DXMATRIX& mat);
	virtual HRESULT GetWarpMatrix(D3DXMATRIX& mat);
	virtual bool GetIsFlipY();
	virtual bool SetIsFlipY(bool bFlipY);
	virtual bool GetIsInvWarp();
	virtual bool SetIsInvWarp(bool bInv);

protected:

	bool m_bFlipY;
	bool m_bInvTTS;
	CCritSec m_csRenderPara;
	D3DXMATRIX m_matTTS;
	D3DXMATRIX m_InvmatTTS;
	D3DXMATRIX ComputeTTS(const D3DXVECTOR2& v1, const D3DXVECTOR2& v2, const D3DXVECTOR2& v3, const D3DXVECTOR2& v4);

public:
	GSHomoWarpFilter(IUnknown * pOuter, HRESULT *phr, BOOL ModifiesData);
	virtual ~GSHomoWarpFilter();
};
