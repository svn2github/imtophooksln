#include "StdAfx.h"
#include "DXRenderDisplay.h"

DXRenderDisplay::DXRenderDisplay(HWND hWnd, IDirect3D9* pD3D, UINT rtWidth, UINT rtHeight) : 
MS3DDisplay(hWnd, pD3D, rtWidth, rtHeight)
{
	
}

DXRenderDisplay::~DXRenderDisplay(void)
{
}

BOOL DXRenderDisplay::Render()
{
	return __super::Render();
}

BOOL DXRenderDisplay::Render(IDirect3DBaseTexture9* pTexture)
{
	m_pDevice->SetSamplerState(0,D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
	m_pDevice->SetSamplerState(0,D3DSAMP_MIPFILTER, D3DTEXF_LINEAR);
	return __super::Render(pTexture);
}
BOOL DXRenderDisplay::Render(IDirect3DBaseTexture9* pTexture, ID3DXEffect* pEffect)
{			
	return FALSE;
}
