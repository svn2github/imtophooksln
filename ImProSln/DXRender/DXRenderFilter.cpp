#include "stdafx.h"
#include "DXRenderFilter.h"
#include "DXRenderProp.h"
#include "DXRenderApp.h"
#include "MyMediaSample.h"
#include "DXRenderDisplay.h"
DXRenderFilter::DXRenderFilter(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData)
: CBaseRenderer(CLSID_DXRenderFilter, NAME("DXRender Filter"), pOuter, phr)
{ 
}
DXRenderFilter::~DXRenderFilter()
{

}

CUnknown *WINAPI DXRenderFilter::CreateInstance(LPUNKNOWN punk, HRESULT *phr)
{
	ASSERT(phr);
	// assuming we don't want to modify the data
	DXRenderFilter *pNewObject = new DXRenderFilter(punk, phr, FALSE);

	if(pNewObject == NULL) {
		if (phr)
			*phr = E_OUTOFMEMORY;
	}
	return pNewObject;
}

HRESULT DXRenderFilter::NonDelegatingQueryInterface(REFIID iid, void **ppv)
{
	if (iid == IID_IDXRenderer) 
	{
		return GetInterface(static_cast<IDXRenderer*>(this), ppv);
	}
	if (iid == IID_ISpecifyPropertyPages)
	{
		return GetInterface(
			static_cast<ISpecifyPropertyPages*>(this),	ppv);
	}
	else
	{
		// Call the parent class.
		return CBaseFilter::NonDelegatingQueryInterface(iid, ppv);
	}
}

HRESULT DXRenderFilter::CheckMediaType(const CMediaType *pmt)
{
	if (( IsEqualGUID(*pmt->Type(), GUID_MyMediaSample) && IsEqualGUID(*pmt->Subtype(), GUID_D3DXTEXTURE9_POINTER)))
	{
		return S_OK;
	}
	return E_FAIL;
}
HRESULT DXRenderFilter::SetMediaType(const CMediaType *pmt)
{
	m_InputMT = *pmt;
	return S_OK;
}
HRESULT DXRenderFilter::CompleteConnect(IPin *pReceivePin)
{
	if (m_pD3DDisplay == NULL)
	{
		D3DSURFACE_DESC *desc = (D3DSURFACE_DESC*) m_InputMT.pbFormat;
		initD3D(desc->Width, desc->Height);
	}
	m_pD3DDisplay->ShowDisplayWnd(TRUE);
	return __super::CompleteConnect(pReceivePin);
}
HRESULT DXRenderFilter::BreakConnect()
{
	ReleaseD3D();
	return __super::BreakConnect();
}
HRESULT DXRenderFilter::GetPages(CAUUID *pPages)
{
	pPages->cElems = 1;
	pPages->pElems = (GUID*)CoTaskMemAlloc(sizeof(GUID));
	if (pPages->pElems == NULL) 
	{
		return E_OUTOFMEMORY;
	}
	pPages->pElems[0] = CLSID_DXRenderPropPage;
	return S_OK;
}

HRESULT DXRenderFilter::DoRenderSample(IMediaSample *pMediaSample)
{
	if (!IsD3DReady())
	{
		D3DSURFACE_DESC *desc = (D3DSURFACE_DESC*) m_InputMT.pbFormat;
		initD3D(desc->Width, desc->Height);
	}
	CopyInputImage2InputTexture(pMediaSample, &m_InputMT, false);
	m_pD3DDisplay->SetTexture(m_pInTexture);
	m_pD3DDisplay->Render();
	return S_OK;
}

void DXRenderFilter::OnReceiveFirstSample(IMediaSample *pMediaSample)
{
	if (!IsWindowVisible(GetD3DWnd()));
	{
		EnableWindow(GetD3DWnd(), TRUE);
	}
	LPDIRECT3DTEXTURE9 pInputTexture = NULL;
	((CMediaSample*)pMediaSample)->GetPointer((BYTE**)&pInputTexture);
	if (pInputTexture != NULL)
	{
		m_pD3DDisplay->Render(pInputTexture);
	}
	return ;
}


MS3DDisplay* DXRenderFilter::Create3DDisplay(IDirect3D9* pD3D, int rtWidth, int rtHeight)
{
	return new DXRenderDisplay(pD3D, rtWidth, rtHeight);
}
MS3DDisplay* DXRenderFilter::Create3DDisplay(IDirect3DDevice9* pDevice, int rtWidth, int rtHeight)
{
	return new DXRenderDisplay(pDevice, rtWidth, rtHeight);
}
BOOL DXRenderFilter::IsReadyCloseWindow()
{
	if (m_State == State_Running)
	{
		return FALSE;
	}
	return TRUE;
}