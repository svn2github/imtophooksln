#include "StdAfx.h"
#include "DXBlendDisplay.h"

DXBlendDisplay::DXBlendDisplay(IDirect3D9* pD3D, UINT rtWidth, UINT rtHeight)
: MS3DDisplay(pD3D, rtWidth, rtHeight)
{
	HRESULT hr = S_OK;

}
DXBlendDisplay::DXBlendDisplay(IDirect3DDevice9* pDevice, UINT rtWidth, UINT rtHeight)
: MS3DDisplay(pDevice, rtWidth, rtHeight)
{
}


DXBlendDisplay::~DXBlendDisplay(void)
{

}

BOOL DXBlendDisplay::Render()
{
	return Render(m_pTexture);
}

BOOL DXBlendDisplay::Render(LPDIRECT3DTEXTURE9 pTexture)
{
	CAutoLock lck(&m_csResetDevice);
	if (m_pDisplayPlane == NULL || pTexture == NULL)
	{
		return FALSE;
	}
	HRESULT hr = S_OK;
	hr = m_pDevice->Clear( 0, NULL, D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER, 
		D3DCOLOR_XRGB(50,50,50), 1.0f, 0 );
	m_pDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
	ID3DXEffect* pEffect = GetEffect();
	if (pEffect == NULL)
	{
		return FALSE;
	}
	m_pCamera->CameraOn();
	UINT iPass, cPasses = 0;

	if( SUCCEEDED( m_pDevice->BeginScene() ) )
	{
		hr = pEffect->SetTexture("g_SrcTexture", pTexture);

		hr = pEffect->SetTechnique("technique1");

		hr = pEffect->Begin(&cPasses, 0);
		for (iPass = 0; iPass < cPasses; iPass++)
		{
			hr = pEffect->BeginPass(iPass);	
			m_pDisplayPlane->Render();			
			hr = pEffect->EndPass();
		}
		hr = pEffect->End();
		hr = m_pDevice->EndScene();
	}
	m_pDevice->Present(NULL,NULL,NULL,NULL);
	m_pCamera->CameraOff();
	m_pDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
}
BOOL DXBlendDisplay::Render(IDirect3DBaseTexture9* pTexture, ID3DXEffect* pEffect)
{			
	return FALSE;
}
ID3DXEffect* DXBlendDisplay::GetEffect()
{
	if (m_pEffect == NULL)
	{
		extern HMODULE GetModule();
		DWORD dwShaderFlags = D3DXFX_NOT_CLONEABLE ;
		D3DCAPS9 cap;
		m_pDevice->GetDeviceCaps(&cap);
		if (cap.PixelShaderVersion < D3DPS_VERSION(2,0))
		{
			dwShaderFlags |= D3DXSHADER_FORCE_PS_SOFTWARE_NOOPT;
		}
		if (cap.VertexShaderVersion < D3DVS_VERSION(2,0))
		{
			dwShaderFlags |= D3DXSHADER_FORCE_VS_SOFTWARE_NOOPT;
		}
		WCHAR str[MAX_PATH] = {0};
		HMODULE module = GetModule();
		GetModuleFileName(module, str, MAX_PATH);
		// Gets filename
		WCHAR* pszFile = wcsrchr(str, '\\');
		pszFile++;    // Moves on from \
		// Get path
		WCHAR szPath[MAX_PATH] = L"";
		_tcsncat(szPath, str, pszFile - str);

		swprintf_s(str, MAX_PATH, L"%s\\..\\fx\\DXBlend.fx", szPath);
		HRESULT hr = D3DXCreateEffectFromFileW( m_pDevice, str, NULL, NULL, dwShaderFlags, NULL, &m_pEffect, NULL );
		if (FAILED(hr))
		{
			OutputDebugStringW(L"@@@@ D3DXCreateEffectFromFileW Failed in DXBlendDisplay::GetEffect()\n");
			return NULL;
		}
	}
	return m_pEffect;
}


BOOL DXBlendDisplay::Render(LPDIRECT3DTEXTURE9 pSrc1, LPDIRECT3DTEXTURE9 pSrc2, 
					LPDIRECT3DTEXTURE9 pWeight1)
{
	CAutoLock lck(&m_csResetDevice);
	if (m_pDisplayPlane == NULL || pSrc2 == NULL || pSrc2 == NULL || pWeight1 == NULL)
	{
		return FALSE;
	}
	HRESULT hr = S_OK;
	hr = m_pDevice->Clear( 0, NULL, D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER, 
		D3DCOLOR_XRGB(50,50,50), 1.0f, 0 );
	m_pDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
	ID3DXEffect* pEffect = GetEffect();
	if (pEffect == NULL)
	{
		return FALSE;
	}
	m_pCamera->CameraOn();
	UINT iPass, cPasses = 0;

	if( SUCCEEDED( m_pDevice->BeginScene() ) )
	{
		hr = pEffect->SetTexture("g_SrcTexture", pSrc1);
		hr = pEffect->SetTexture("g_DestTexture", pSrc1);
		hr = pEffect->SetTexture("g_WeightMap", pWeight1);
		hr = pEffect->SetTechnique("technique0");

		hr = pEffect->Begin(&cPasses, 0);
		for (iPass = 0; iPass < cPasses; iPass++)
		{
			hr = pEffect->BeginPass(iPass);	
			m_pDisplayPlane->Render();			
			hr = pEffect->EndPass();
		}
		hr = pEffect->End();
		hr = m_pDevice->EndScene();
	}
	m_pDevice->Present(NULL,NULL,NULL,NULL);
	m_pCamera->CameraOff();
	m_pDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	return TRUE;
}
