#include "StdAfx.h"
#include "MaskFilterDisplay.h"


MaskFilterDisplay::MaskFilterDisplay(IDirect3D9* pD3D, UINT rtWidth, UINT rtHeight) : 
MS3DDisplay(pD3D, rtWidth, rtHeight)
{
	m_pMaskTexture = NULL;
	m_maskFlag = BlendMask;
}
MaskFilterDisplay::MaskFilterDisplay(IDirect3DDevice9* pDevice, UINT rtWidth, UINT rtHeight) : 
MS3DDisplay(pDevice, rtWidth, rtHeight)
{
	m_pMaskTexture = NULL;
	m_maskFlag = BlendMask;
}
MaskFilterDisplay::~MaskFilterDisplay(void)
{
	if (m_pMaskTexture != NULL)
	{
		m_pMaskTexture->Release();
		m_pMaskTexture = NULL;
	}
}

BOOL MaskFilterDisplay::Render()
{
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
		hr = pEffect->SetTexture("g_Texture", m_pTexture);
		hr = pEffect->SetTexture("g_MaskTexture", m_pMaskTexture);
		hr = pEffect->SetInt("maskFlag", m_maskFlag);
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

BOOL MaskFilterDisplay::Render(IDirect3DBaseTexture9* pTexture)
{
	return FALSE;
}
BOOL MaskFilterDisplay::Render(IDirect3DBaseTexture9* pTexture, ID3DXEffect* pEffect)
{			
	return FALSE;
}

ID3DXEffect* MaskFilterDisplay::GetEffect()
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

		swprintf_s(str, MAX_PATH, L"%s\\..\\fx\\MaskFilter.fx", szPath);
		HRESULT hr = D3DXCreateEffectFromFileW( m_pDevice, str, NULL, NULL, dwShaderFlags, NULL, &m_pEffect, NULL );
		if (FAILED(hr))
		{
			OutputDebugStringW(L"@@@@ D3DXCreateEffectFromFileW Failed in MaskFilterDisplay::GetEffect()\n");
			return NULL;
		}
	}
	return m_pEffect;
}


BOOL MaskFilterDisplay::CreateTexture(UINT rtWidth = 0, UINT rtHeight = 0)
{
	if (m_pDevice == NULL)
	{
		return FALSE;
	}
	if (m_pMaskTexture != NULL)
	{
		m_pMaskTexture->Release();
		m_pMaskTexture = NULL;
	}
	HRESULT hr;
	HWND desktop = GetDesktopWindow();
	HDC dc = GetDC(desktop);
	int screenW = GetDeviceCaps(dc, HORZRES);
	int screenH = GetDeviceCaps(dc, VERTRES);
	if (rtWidth == 0 || rtHeight == 0)
	{
		hr = D3DXCreateTexture(m_pDevice, screenW, screenH, 0, D3DUSAGE_RENDERTARGET ,
			D3DFMT_X8R8G8B8, D3DPOOL_DEFAULT, &m_pMaskTexture);
	}
	else
	{
		hr = D3DXCreateTexture(m_pDevice, rtWidth, rtHeight, 0, D3DUSAGE_RENDERTARGET,
			D3DFMT_X8R8G8B8, D3DPOOL_DEFAULT, &m_pMaskTexture);
	}

	if (FAILED(hr))
	{
		OutputDebugStringW(L"@@@@@ D3DXCreateTexture Failed in MaskFilterDisplay::CreateTexture()!! \n");
		return FALSE;
	}
	return __super::CreateTexture(rtWidth, rtHeight);
}

BOOL MaskFilterDisplay::SetMaskFlag(int flag)
{
	if (flag < 0 || flag > MaskFlag::BlendMask)
	{
		return FALSE;
	}
	m_maskFlag = (MaskFlag)flag;
	return TRUE;
}

int MaskFilterDisplay::GetMaskFlag()
{
	return m_maskFlag;
}
BOOL MaskFilterDisplay::LoadMaskFromFile(WCHAR* path)
{
	if (m_pDevice == NULL)
		return FALSE;
	if (m_pMaskTexture != NULL)
	{
		m_pMaskTexture->Release();
		m_pMaskTexture = NULL;
	}
	HRESULT hr;
	hr = D3DXCreateTextureFromFileEx(m_pDevice, path, D3DX_DEFAULT, D3DX_DEFAULT, 0,
		D3DUSAGE_RENDERTARGET, D3DFMT_A8R8G8B8, D3DPOOL_DEFAULT, 
		D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &m_pMaskTexture);
	
	return SUCCEEDED(hr);
	
}