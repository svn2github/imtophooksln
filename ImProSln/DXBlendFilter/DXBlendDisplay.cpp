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
	return __super::Render();
}

BOOL DXBlendDisplay::Render(IDirect3DBaseTexture9* pTexture)
{
	return FALSE;
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

		swprintf_s(str, MAX_PATH, L"%s\\..\\fx\\DXBlender.fx", szPath);
		HRESULT hr = D3DXCreateEffectFromFileW( m_pDevice, str, NULL, NULL, dwShaderFlags, NULL, &m_pEffect, NULL );
		if (FAILED(hr))
		{
			OutputDebugStringW(L"@@@@ D3DXCreateEffectFromFileW Failed in DXBlendDisplay::GetEffect()\n");
			return NULL;
		}
	}
	return m_pEffect;
}

