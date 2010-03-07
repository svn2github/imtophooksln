#include "StdAfx.h"
#include "DXRenderDisplay.h"

DXRenderDisplay::DXRenderDisplay(IDirect3D9* pD3D, UINT rtWidth, UINT rtHeight)
: MS3DDisplay(pD3D, rtWidth, rtHeight)
{
	HRESULT hr = S_OK;
	m_bDrawFPS = false;
	m_bFlipX = false;
	m_bFlipY = false;
	m_sampleType = 1;
	m_pD3DFont = NULL;
	hr = D3DXCreateFont(m_pDevice, 20, 0, FW_NORMAL, 0, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, 
		DEFAULT_PITCH | FF_DONTCARE, L"System", &m_pD3DFont  );
	
	lasttime = timeGetTime();
	currtime = timeGetTime();
	count = 0;
	fps = 0; 
	imgW = 0;
	imgH = 0;
}
DXRenderDisplay::DXRenderDisplay(IDirect3DDevice9* pDevice, UINT rtWidth, UINT rtHeight)
: MS3DDisplay(pDevice, rtWidth, rtHeight)
{
	HRESULT hr = S_OK;
	m_bDrawFPS = false;
	m_bFlipX = false;
	m_bFlipY = false;
	m_sampleType = 1;
	m_pD3DFont = NULL;
	hr = D3DXCreateFont(m_pDevice, 50, 0, FW_NORMAL, 0, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, 
		DEFAULT_PITCH | FF_DONTCARE, L"System", &m_pD3DFont  );
	lasttime = timeGetTime();
	currtime = timeGetTime();
	count = 0;
	fps = 0; 
	imgW = 0;
	imgH = 0;
}


DXRenderDisplay::~DXRenderDisplay(void)
{
	if (m_pD3DFont != NULL)
	{
		m_pD3DFont->Release();
		m_pD3DFont = NULL;
	}
}

BOOL DXRenderDisplay::Render()
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
		hr = pEffect->SetTexture("g_Texture", m_pTexture);
		hr = pEffect->SetTechnique("technique0");
		hr = pEffect->SetBool("bFlipX", m_bFlipX);
		hr = pEffect->SetBool("bFlipY", m_bFlipY);
		hr = pEffect->SetInt("g_sampleType", m_sampleType);
		hr = pEffect->Begin(&cPasses, 0);
		for (iPass = 0; iPass < cPasses; iPass++)
		{
			hr = pEffect->BeginPass(iPass);	
			m_pDisplayPlane->Render();			
			hr = pEffect->EndPass();
		}
		hr = pEffect->End();
		if (m_bDrawFPS)
		{
			if (imgW == 0 && imgH == 0)
			{
				LPDIRECT3DSURFACE9 pBackBuffer = NULL;
				D3DSURFACE_DESC desc;
				m_pDevice->GetRenderTarget(0,&pBackBuffer);
				pBackBuffer->GetDesc(&desc);
				imgW = desc.Width;
				imgH = desc.Height;
				pBackBuffer->Release();
				pBackBuffer = NULL;
			}
			count++;
			if (count%30 == 0)
			{
				
				currtime = timeGetTime();
				float dt = max(1, currtime - lasttime) / 1000.0;
				fps = 30.0 / dt;
				count = 0;
				lasttime = currtime;
			}

			WCHAR str[MAX_PATH] = {0};
			RECT rect; 
			rect.left = 0.05*imgW; rect.right =  rect.left + 0.1*imgW; rect.top = 0.05*imgH; rect.bottom = rect.top + 0.1*imgH;
			swprintf_s(str, MAX_PATH, L"FPS: %.1f", fps);
			if (m_pD3DFont != NULL)
			{
				hr = m_pD3DFont->DrawTextW(NULL, str, -1, &rect, DT_NOCLIP | DT_LEFT | DT_TOP, D3DXCOLOR( 1.0f, 0.0f, 0.0f, 1.0f ));	
			}
		}
		m_pDevice->EndScene();
	}
	m_pDevice->Present(NULL,NULL,NULL,NULL);
	m_pCamera->CameraOff();
	m_pDevice->SetRenderState(D3DRS_ZENABLE, TRUE);

	return TRUE;
}

BOOL DXRenderDisplay::Render(IDirect3DBaseTexture9* pTexture)
{
	return FALSE;
}
BOOL DXRenderDisplay::Render(IDirect3DBaseTexture9* pTexture, ID3DXEffect* pEffect)
{			
	return FALSE;
}
ID3DXEffect* DXRenderDisplay::GetEffect()
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

		swprintf_s(str, MAX_PATH, L"%s\\..\\fx\\DXRenderer.fx", szPath);
		HRESULT hr = D3DXCreateEffectFromFileW( m_pDevice, str, NULL, NULL, dwShaderFlags, NULL, &m_pEffect, NULL );
		if (FAILED(hr))
		{
			OutputDebugStringW(L"@@@@ D3DXCreateEffectFromFileW Failed in DXRenderDisplay::GetEffect()\n");
			return NULL;
		}
	}
	return m_pEffect;
}


HRESULT DXRenderDisplay::OnBeforeResetDevice(IDirect3DDevice9 * pd3dDevice,	
											   void* pUserContext)
{
	HRESULT hr = S_OK;
	if (m_pD3DFont != NULL)
	{
		hr = m_pD3DFont->OnLostDevice();
	}
	return __super::OnBeforeResetDevice(pd3dDevice,	 pUserContext);
}

HRESULT DXRenderDisplay::OnAfterResetDevice(IDirect3DDevice9 * pd3dDevice,	
											  void* pUserContext)
{
	HRESULT hr = S_OK;
	if (m_pD3DFont != NULL)
	{
		hr = m_pD3DFont->OnResetDevice();
	}
	return __super::OnAfterResetDevice(pd3dDevice, pUserContext);
}