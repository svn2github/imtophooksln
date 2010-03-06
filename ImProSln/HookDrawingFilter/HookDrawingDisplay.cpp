#include "StdAfx.h"
#include "HookDrawingDisplay.h"
#define MASKSIZE 256
extern HMODULE GetModule();
HookDrawingDisplay::HookDrawingDisplay(IDirect3D9* pD3D, UINT rtWidth, UINT rtHeight) : 
MS3DDisplay(pD3D, rtWidth, rtHeight)
{
	HRESULT hr = S_OK;
	m_maskFlag = BlendMask;
	m_pMaskTexture = NULL;
	m_pMaskRectTexture = NULL;
	m_bMaskFlipY = false;
	m_pWarpMesh = NULL;
	m_pMaskCamera = NULL;
	m_sampleType = SampleType::LINEAR;
	m_pMaskEffect = NULL;

	m_bFlipX = false;
	m_bFlipY = false;
	m_bDrawFPS = false;

	CreateWarpMesh();
	CreateMaskTexture();
	ClearMask();
	m_pMaskCamera = new MSCamera(m_pDevice);
	m_pMaskCamera->SetOrthoPara(-0.5, 0.5, 0.5, -0.5);
	m_pMaskCamera->SetEyePos(D3DXVECTOR3(0.5, -0.5, -5));
	m_pMaskCamera->SetLookAt(D3DXVECTOR3(0.5, -0.5, 0));

	D3DXMatrixIdentity(&m_matTTS);
	
	lasttime = timeGetTime();
	currtime = timeGetTime();
	count = 0;
	fps = 0; 
	imgW = 0;
	imgH = 0;
	m_pD3DFont = NULL;
	hr = D3DXCreateFont(m_pDevice, 50, 0, FW_NORMAL, 0, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, 
		DEFAULT_PITCH | FF_DONTCARE, L"System", &m_pD3DFont  );

}
HookDrawingDisplay::HookDrawingDisplay(IDirect3DDevice9* pDevice, UINT rtWidth, UINT rtHeight) : 
MS3DDisplay(pDevice, rtWidth, rtHeight)
{
	HRESULT hr = S_OK;
	m_maskFlag = BlendMask;
	m_pMaskTexture = NULL;
	m_pMaskRectTexture = NULL;
	m_bMaskFlipY = false;
	m_pWarpMesh = NULL;
	m_pMaskCamera = NULL;
	m_pMaskEffect = NULL;

	CreateWarpMesh();
	CreateMaskTexture();
	ClearMask();
	m_pMaskCamera = new MSCamera(m_pDevice);
	m_pMaskCamera->SetOrthoPara(-0.5, 0.5, 0.5, -0.5);
	m_pMaskCamera->SetEyePos(D3DXVECTOR3(0.5, -0.5, -5));
	m_pMaskCamera->SetLookAt(D3DXVECTOR3(0.5, -0.5, 0));

	D3DXMatrixIdentity(&m_matTTS);
	m_pMaskEffect = NULL;

	lasttime = timeGetTime();
	currtime = timeGetTime();
	count = 0;
	fps = 0; 
	imgW = 0;
	imgH = 0;
	m_pD3DFont = NULL;
	hr = D3DXCreateFont(m_pDevice, 50, 0, FW_NORMAL, 0, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, 
		DEFAULT_PITCH | FF_DONTCARE, L"System", &m_pD3DFont  );
}
HookDrawingDisplay::~HookDrawingDisplay(void)
{
	if (m_pMaskTexture != NULL)
	{
		m_pMaskTexture->Release();
		m_pMaskTexture = NULL;
	}
	
	if (m_pWarpMesh != NULL)
	{
		delete m_pWarpMesh;
		m_pWarpMesh = NULL;
	}
	if (m_pMaskCamera != NULL)
	{
		delete m_pMaskCamera;
		m_pMaskCamera = NULL;
	}
	if (m_pMaskRectTexture != NULL)
	{
		m_pMaskRectTexture->Release();
		m_pMaskRectTexture = NULL;
	}
	if (m_pMaskEffect != NULL)
	{
		m_pMaskEffect->Release();
		m_pMaskEffect = NULL;
	}
	if (m_pD3DFont != NULL)
	{
		m_pD3DFont->Release();
		m_pD3DFont = NULL;
	}
}
BOOL HookDrawingDisplay::SetMatTTS(const D3DXMATRIX* mat)
{
	m_matTTS = *mat;
	return TRUE;
}

BOOL HookDrawingDisplay::Render()
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
		hr = pEffect->SetInt("g_sampleType", m_sampleType);
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
	return S_OK;
}


BOOL HookDrawingDisplay::RenderMask()
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
	ID3DXEffect* pEffect = GetMaskEffect();
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
		hr = pEffect->SetBool("bMaskFlipY", m_bMaskFlipY);
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

ID3DXEffect* HookDrawingDisplay::GetMaskEffect()
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
		HRESULT hr = D3DXCreateEffectFromFileW( m_pDevice, str, NULL, NULL, dwShaderFlags, NULL, &m_pMaskEffect, NULL );
		if (FAILED(hr))
		{
			OutputDebugStringW(L"@@@@ D3DXCreateEffectFromFileW Failed in HookDrawingDisplay::GetEffect()\n");
			return NULL;
		}
	}
	return m_pMaskEffect;
}
bool HookDrawingDisplay::CreateWarpMesh()
{
	m_pWarpMesh = new MS3DPlane(m_pDevice);
	MSMeshBase::CUSTOMVERTEX* pVertices = new MSMeshBase::CUSTOMVERTEX[4];

	pVertices[0].position = D3DXVECTOR3(0, 0, 0);
	pVertices[1].position = D3DXVECTOR3(0, -1, 0);
	pVertices[2].position = D3DXVECTOR3(1, -1, 0);
	pVertices[3].position = D3DXVECTOR3(1, 0, 0);

	pVertices[0].normal = D3DXVECTOR3(0, 0, -1);
	pVertices[1].normal = D3DXVECTOR3(0, 0, -1);
	pVertices[2].normal = D3DXVECTOR3(0, 0, -1);
	pVertices[3].normal = D3DXVECTOR3(0, 0, -1);

	pVertices[0].tu = 0;	pVertices[0].tv = 0;
	pVertices[1].tu = 0;    pVertices[1].tv = 1;
	pVertices[2].tu = 1;	pVertices[2].tv = 1;
	pVertices[3].tu = 1;    pVertices[3].tv = 0;

	for (int i=0; i < 4; i++)
	{
		m_pWarpMesh->SetVertex(i, pVertices[i]);
	}

	delete [] pVertices;
	pVertices = NULL;
	return true;
}


BOOL HookDrawingDisplay::CreateMaskTexture()
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

	hr = D3DXCreateTexture(m_pDevice, MASKSIZE, MASKSIZE, 0, D3DUSAGE_RENDERTARGET ,
		D3DFMT_A8R8G8B8, D3DPOOL_DEFAULT, &m_pMaskTexture);

	if (FAILED(hr))
	{
		OutputDebugStringW(L"@@@@@ D3DXCreateTexture Failed in MaskFilterDisplay::CreateTexture()!! \n");
		return FALSE;
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

	swprintf_s(str, MAX_PATH, L"%s\\..\\fx\\MaskRect.png", szPath);

	hr = D3DXCreateTextureFromFile(m_pDevice, str, &m_pMaskRectTexture);

	return S_OK;
}


BOOL HookDrawingDisplay::ClearMask()
{
	if (m_pDevice == NULL)
		return FALSE;
	HRESULT hr;
	IDirect3DSurface9* pBackBuffer = NULL;
	m_pDevice->GetRenderTarget(0,&pBackBuffer);
	if ( pBackBuffer == NULL)
	{
		return FALSE;
	}
	IDirect3DSurface9* pMaskSurface = NULL;
	m_pMaskTexture->GetSurfaceLevel(0, &pMaskSurface);
	if (pMaskSurface == NULL)
	{
		pBackBuffer->Release();
		pBackBuffer = NULL;
		return FALSE;
	}
	m_pDevice->SetRenderTarget(0, pMaskSurface);
	m_pDevice->Clear( 0, NULL, D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER, 
		D3DCOLOR_ARGB(0, 255,255,255), 1.0f, 0);

	m_pDevice->SetRenderTarget(0, pBackBuffer);
	pBackBuffer->Release();
	pBackBuffer = NULL;
	pMaskSurface->Release();
	pMaskSurface = NULL;

	return TRUE;
}


BOOL HookDrawingDisplay::GenerateMaskFromVertices(D3DXVECTOR2* pts[], int numRects, float fMaskScale)
{
	if (m_pDevice == NULL || m_pMaskRectTexture == NULL)
	{
		return FALSE;
	}

	ID3DXEffect* pEffect = GetMaskEffect();
	if (pEffect == NULL)
	{
		return FALSE;
	}
	IDirect3DSurface9* pBackBuffer = NULL;
	m_pDevice->GetRenderTarget(0,&pBackBuffer);
	if ( pBackBuffer == NULL)
	{
		return FALSE;
	}

	IDirect3DSurface9* pMaskSurface = NULL;
	m_pMaskTexture->GetSurfaceLevel(0, &pMaskSurface);
	if (pMaskSurface == NULL)
	{
		pBackBuffer->Release();
		pBackBuffer = NULL;
		return FALSE;
	}	

	m_pDevice->SetRenderTarget(0, pMaskSurface);
	m_pDevice->Clear( 0, NULL, D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER, 
		D3DCOLOR_ARGB(0, 255,255,255), 1.0f, 0);

	HRESULT hr;
	MSMeshBase::CUSTOMVERTEX* pVertices = new MSMeshBase::CUSTOMVERTEX[4];
	pVertices[0].normal = D3DXVECTOR3(0, 0, -1);
	pVertices[1].normal = D3DXVECTOR3(0, 0, -1);
	pVertices[2].normal = D3DXVECTOR3(0, 0, -1);
	pVertices[3].normal = D3DXVECTOR3(0, 0, -1);

	pVertices[0].tu = 0;	pVertices[0].tv = 0;
	pVertices[1].tu = 0;    pVertices[1].tv = 1;
	pVertices[2].tu = 1;	pVertices[2].tv = 1;
	pVertices[3].tu = 1;    pVertices[3].tv = 0;

	D3DXMATRIX matIdentity;
	D3DXMatrixIdentity(&matIdentity);
	UINT iPass, cPasses = 0;
	m_pMaskCamera->CameraOn();
	D3DXMATRIX matTran, matT, matS, matInvT;
	if( SUCCEEDED( m_pDevice->BeginScene() ) )
	{	
		for (int i =0; i< numRects; i++)
		{
			pVertices[0].position = D3DXVECTOR3(pts[i][0].x, -pts[i][0].y, 0);
			pVertices[1].position = D3DXVECTOR3(pts[i][1].x, -pts[i][1].y, 0);
			pVertices[2].position = D3DXVECTOR3(pts[i][2].x, -pts[i][2].y, 0);
			pVertices[3].position = D3DXVECTOR3(pts[i][3].x, -pts[i][3].y, 0);


			D3DXVECTOR3 tV = (pVertices[0].position + pVertices[1].position + 
				+ pVertices[2].position + pVertices[3].position) / 4.0;

			D3DXMatrixTranslation(&matT, -tV.x, -tV.y, 0);
			D3DXMatrixScaling(&matS, fMaskScale, fMaskScale, 1);
			D3DXMatrixTranslation(&matInvT, tV.x, tV.y, 0);
			matTran = matT*matS*matInvT;
			D3DXVec3TransformCoord(&(pVertices[0].position), &(pVertices[0].position), &matTran);
			D3DXVec3TransformCoord(&(pVertices[1].position), &(pVertices[1].position), &matTran);
			D3DXVec3TransformCoord(&(pVertices[2].position), &(pVertices[2].position), &matTran);
			D3DXVec3TransformCoord(&(pVertices[3].position), &(pVertices[3].position), &matTran);

			for (int j=0; j < 4; j++)
			{
				m_pWarpMesh->SetVertex(j, pVertices[j]);
			}
			m_pWarpMesh->SetTransform(&matIdentity);
			hr = pEffect->SetTexture("g_Texture", m_pMaskRectTexture);
			hr = pEffect->SetTechnique("techniqueWarpMask");

			hr = pEffect->Begin(&cPasses, 0);
			for (iPass = 0; iPass < cPasses; iPass++)
			{
				pEffect->BeginPass(iPass);	
				m_pWarpMesh->Render();			
				pEffect->EndPass();
			}
			hr = pEffect->End();
		}
		hr = m_pDevice->EndScene();
		m_pDevice->Present(NULL,NULL,NULL,NULL);
	}
	m_pMaskCamera->CameraOff();
	m_pDevice->SetRenderTarget(0, pBackBuffer);
	pBackBuffer->Release();
	pBackBuffer = NULL;
	pMaskSurface->Release();
	pMaskSurface = NULL;

	delete [] pVertices;
	pVertices = NULL;

	return TRUE;
}
BOOL HookDrawingDisplay::SetMaskTexture(LPDIRECT3DTEXTURE9 maskTexture)
{
	if (m_pMaskTexture != NULL)
	{
		m_pMaskTexture->Release();
		m_pMaskTexture = NULL;
	}
	m_pMaskTexture = maskTexture;
	return TRUE;
}
BOOL HookDrawingDisplay::GetMaskTexture(LPDIRECT3DTEXTURE9& outTexture)
{
	if (m_pMaskTexture == NULL)
	{
		return FALSE;
	}
	if (outTexture != NULL)
	{
		outTexture->Release();
		outTexture = NULL;
	}
	outTexture = m_pMaskTexture;
	outTexture->AddRef();
	return TRUE;
}