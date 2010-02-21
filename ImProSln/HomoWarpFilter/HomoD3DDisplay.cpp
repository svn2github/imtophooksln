#include "StdAfx.h"
#include "HomoD3DDisplay.h"

HomoD3DDisplay::HomoD3DDisplay(IDirect3D9* pD3D, UINT rtWidth, UINT rtHeight) : 
MS3DDisplay(pD3D, rtWidth, rtHeight)
{
	D3DXMatrixIdentity(&m_matTTS);
	GetEffect();
}
HomoD3DDisplay::HomoD3DDisplay(IDirect3DDevice9* pDevice, UINT rtWidth, UINT rtHeight) :
MS3DDisplay(pDevice, rtWidth, rtHeight)
{
	D3DXMatrixIdentity(&m_matTTS);
	GetEffect();
}
HomoD3DDisplay::~HomoD3DDisplay(void)
{
}


BOOL HomoD3DDisplay::Render()
{
	CAutoLock lck(&m_csResetDevice);
	if (m_pDisplayPlane == NULL)
	{
		return FALSE;
	}
	m_pDevice->Clear( 0, NULL, D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER, 
		D3DCOLOR_XRGB(50,50,50), 1.0f, 0 );
	m_pDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
	HRESULT hr;
	ID3DXEffect* pEffect = GetEffect();
	if (pEffect == NULL)
	{
		return FALSE;
	}
	m_pCamera->CameraOn();
	UINT iPass, cPasses = 0;
	if( SUCCEEDED( m_pDevice->BeginScene() ) )
	{
		
		hr = pEffect->SetMatrix("g_matTexTransform", &m_matTTS);
		hr = pEffect->SetTexture("g_Texture", m_pTexture);
		hr = pEffect->SetTechnique("technique0");
		
		hr = pEffect->Begin(&cPasses, 0);
		for (iPass = 0; iPass < cPasses; iPass++)
		{
			pEffect->BeginPass(iPass);	
			m_pDisplayPlane->Render();			
			pEffect->EndPass();
		}
	    
		hr = pEffect->End();
		
		m_pDevice->EndScene();
	}
	m_pDevice->Present(NULL,NULL,NULL,NULL);
	m_pCamera->CameraOff();
	m_pDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	return S_OK;
}

BOOL HomoD3DDisplay::Render(IDirect3DBaseTexture9* pTexture)
{
	return FALSE;
}
BOOL HomoD3DDisplay::Render(IDirect3DBaseTexture9* pTexture, ID3DXEffect* pEffect)
{			
	return FALSE;
}
BOOL HomoD3DDisplay::SetMatTTS(const D3DXMATRIX* mat)
{
	m_matTTS = *mat;
	return TRUE;
}
ID3DXEffect* HomoD3DDisplay::GetEffect()
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

		swprintf_s(str, MAX_PATH, L"%s\\..\\fx\\HomoWarp.fx", szPath);
		HRESULT hr = D3DXCreateEffectFromFileW( m_pDevice, str, NULL, NULL, dwShaderFlags, NULL, &m_pEffect, NULL );
		if (FAILED(hr))
		{
			OutputDebugStringW(L"@@@@ D3DXCreateEffectFromFileW Failed in MS3DDisplay::GetEffect()\n");
			return NULL;
		}
	}
	return m_pEffect;
}

