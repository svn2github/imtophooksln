#include "StdAfx.h"
#include "HookDrawingDisplay.h"


HookDrawingDisplay::HookDrawingDisplay(HWND hWnd, IDirect3D9* pD3D, UINT rtWidth, UINT rtHeight) : 
MS3DDisplay(hWnd, pD3D, rtWidth, rtHeight)
{
	
}

HookDrawingDisplay::~HookDrawingDisplay(void)
{
}


BOOL HookDrawingDisplay::Render()
{
	
	return FALSE;
}

BOOL HookDrawingDisplay::Render(IDirect3DBaseTexture9* pTexture)
{
	return FALSE;
}
BOOL HookDrawingDisplay::Render(IDirect3DBaseTexture9* pTexture, ID3DXEffect* pEffect)
{			
	return FALSE;
}

ID3DXEffect* HookDrawingDisplay::GetEffect()
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

		swprintf_s(str, MAX_PATH, L"%s\\..\\fx\\HookDrawing.fx", szPath);
		HRESULT hr = D3DXCreateEffectFromFileW( m_pDevice, str, NULL, NULL, dwShaderFlags, NULL, &m_pEffect, NULL );
		if (FAILED(hr))
		{
			OutputDebugStringW(L"@@@@ D3DXCreateEffectFromFileW Failed in HookDrawingDisplay::GetEffect()\n");
			return NULL;
		}
	}
	return m_pEffect;
}
