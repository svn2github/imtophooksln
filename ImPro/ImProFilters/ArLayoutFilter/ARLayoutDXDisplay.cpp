#include "StdAfx.h"
#include "ARLayoutDXDisplay.h"
extern HMODULE GetModule();

ARLayoutDXDisplay::ARLayoutDXDisplay(IDirect3D9* pD3D, UINT rtWidth, UINT rtHeight)
: MS3DDisplay(pD3D, rtWidth, rtHeight)
{
	HRESULT hr = S_OK;
	m_pMarkerMesh = NULL;
	LoadARMarkTexture();
	CreateMarkerMesh();
	m_pCamera->SetOrthoPara(-0.5, 0.5, 0.5, -0.5);
	m_pCamera->SetEyePos(D3DXVECTOR3(0.5, -0.5, -5));
	m_pCamera->SetLookAt(D3DXVECTOR3(0.5, -0.5, 0));
}
ARLayoutDXDisplay::ARLayoutDXDisplay(IDirect3DDevice9* pDevice, UINT rtWidth, UINT rtHeight)
: MS3DDisplay(pDevice, rtWidth, rtHeight)
{
	HRESULT hr = S_OK;
	m_pMarkerMesh = NULL;
	LoadARMarkTexture();
	CreateMarkerMesh();
	m_pCamera->SetOrthoPara(-0.5, 0.5, 0.5, -0.5);
	m_pCamera->SetEyePos(D3DXVECTOR3(0.5, -0.5, -5));
	m_pCamera->SetLookAt(D3DXVECTOR3(0.5, -0.5, 0));
}


ARLayoutDXDisplay::~ARLayoutDXDisplay(void)
{
	for (map<int, LPDIRECT3DTEXTURE9>::iterator iter = m_pMarkerTextures.begin();
		iter != m_pMarkerTextures.end(); iter++)
	{
		if (iter->second != NULL)
		{
			iter->second->Release();
			iter->second = NULL;
		}
	}
	m_pMarkerTextures.clear();

	if (m_pMarkerMesh != NULL)
	{
		delete m_pMarkerMesh;
		m_pMarkerMesh = NULL;
	}
}
bool ARLayoutDXDisplay::CreateMarkerMesh()
{
	if (m_pMarkerMesh != NULL)
	{
		delete m_pMarkerMesh;
		m_pMarkerMesh = NULL;
	}
	m_pMarkerMesh = new MS3DPlane(m_pDevice);
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
		m_pMarkerMesh->SetVertex(i, pVertices[i]);
	}

	delete [] pVertices;
	pVertices = NULL;
	return true;
}
ID3DXEffect* ARLayoutDXDisplay::GetEffect()
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

		swprintf_s(str, MAX_PATH, L"%s\\..\\..\\fx\\ARLayout.fx", szPath);
		HRESULT hr = D3DXCreateEffectFromFileW( m_pDevice, str, NULL, NULL, dwShaderFlags, NULL, &m_pEffect, NULL );
		if (FAILED(hr))
		{
			OutputDebugStringW(L"@@@@ D3DXCreateEffectFromFileW Failed in ARLayoutDXDisplay::GetEffect()\n");
			return NULL;
		}
	}
	return m_pEffect;
}

BOOL ARLayoutDXDisplay::Render(const ARMultiMarkerInfoT* pMarkerConfig)
{
	CAutoLock lck(&m_csResetDevice);
	HRESULT hr;
	ID3DXEffect* pEffect = GetEffect();
	if (pEffect == NULL)
	{
		return FALSE;
	}
	m_pDevice->Clear( 0, NULL, D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER, 
		D3DCOLOR_XRGB(255,255,255), 1.0f, 0 );
	m_pCamera->CameraOn();
	UINT iPass, cPasses = 0;
	if( SUCCEEDED( m_pDevice->BeginScene() ) )
	{	
		D3DXMATRIX tranMat, matScale;
		for (int i =0; i < pMarkerConfig->marker_num; i++)
		{
			ARMultiEachMarkerInfoT* marker = &pMarkerConfig->marker[i];
			if (!marker->visible)
			{
				continue;
			}
			D3DXMatrixIdentity(&tranMat);
			D3DXMatrixScaling(&matScale, marker->width, marker->width, 1);
			int id = marker->patt_id;
			if (m_pMarkerTextures[id] == NULL)
			{
				continue;
			}
			for (int row = 0; row <3; row++)
			{
				for (int col = 0; col < 4; col ++)
				{
					tranMat.m[col][row] = marker->trans[row][col];
				}
			}
			tranMat = matScale * tranMat;
			m_pMarkerMesh->SetTransform(&tranMat);
			hr = pEffect->SetTexture("g_Texture", m_pMarkerTextures[id]);
			hr = pEffect->SetTechnique("technique0");

			hr = pEffect->Begin(&cPasses, 0);
			for (iPass = 0; iPass < cPasses; iPass++)
			{
				pEffect->BeginPass(iPass);	
				m_pMarkerMesh->Render();
				pEffect->EndPass();
			}
			hr = pEffect->End();
		}

		hr = m_pDevice->EndScene();
	}
	m_pDevice->Present(NULL,NULL,NULL,NULL);
	m_pCamera->CameraOff();
	
	return TRUE;
}
BOOL ARLayoutDXDisplay::RenderMask(const ARMultiMarkerInfoT* pMarkerConfig, float fMaskScale)
{
	CAutoLock lck(&m_csResetDevice);
	if (m_pDevice == NULL)
		return FALSE;
	HRESULT hr;

	m_pDevice->Clear( 0, NULL, D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER, 
		D3DCOLOR_ARGB(0, 255,255,255), 1.0f, 0);
	ID3DXEffect* pEffect = GetEffect();
	if (pEffect == NULL)
	{
		return FALSE;
	}
	UINT iPass, cPasses = 0;
	m_pCamera->CameraOn();

	MSMeshBase::CUSTOMVERTEX Vt[4];
	D3DXMATRIX matTran, matT, matInvT, matS;
	D3DXVECTOR3 center(0,0,0);
	for(int i =0; i< 4; i++)
	{
		m_pMarkerMesh->GetVertex(i, Vt[i]);
		center += Vt[i].position;
	}
	center /= 4;

	D3DXMatrixTranslation(&matT, -center.x, -center.y, -center.z);
	D3DXMatrixTranslation(&matInvT, center.x, center.y, center.z);
	D3DXMatrixScaling(&matS, fMaskScale, fMaskScale, fMaskScale);
	matTran = matT*matS*matInvT;

	if( SUCCEEDED( m_pDevice->BeginScene() ) )
	{	
		D3DXMATRIX tranMat, matScale;
		for (int i =0; i < pMarkerConfig->marker_num; i++)
		{
			ARMultiEachMarkerInfoT* marker = &pMarkerConfig->marker[i];
			if (!marker->visible)
			{
				continue;
			}

			D3DXMatrixIdentity(&tranMat);
			D3DXMatrixScaling(&matScale, marker->width, marker->width, 1);
			int id = marker->patt_id;

			for (int row = 0; row <3; row++)
			{
				for (int col = 0; col < 4; col ++)
				{
					tranMat.m[col][row] = marker->trans[row][col];
				}
			}
			tranMat = matTran * matScale * tranMat;
			m_pMarkerMesh->SetTransform(&tranMat);
			
			hr = pEffect->SetTechnique("techniqueARMask");
			hr = pEffect->Begin(&cPasses, 0);
			for (iPass = 0; iPass < cPasses; iPass++)
			{
				pEffect->BeginPass(iPass);	
				m_pMarkerMesh->Render();			
				pEffect->EndPass();
			}
			hr = pEffect->End();
		}

		hr = m_pDevice->EndScene();
	}
	m_pDevice->Present(NULL,NULL,NULL,NULL);
	m_pCamera->CameraOff();

	return TRUE;
}

BOOL ARLayoutDXDisplay::Render()
{
	return FALSE;
}

BOOL ARLayoutDXDisplay::Render(IDirect3DBaseTexture9* pTexture)
{
	return FALSE;
}
BOOL ARLayoutDXDisplay::Render(IDirect3DBaseTexture9* pTexture, ID3DXEffect* pEffect)
{			
	return FALSE;
}
bool ARLayoutDXDisplay::LoadARMarkTexture()
{
	for (map<int, LPDIRECT3DTEXTURE9>::iterator iter = m_pMarkerTextures.begin();
		iter != m_pMarkerTextures.end(); iter++)
	{
		if (iter->second != NULL)
		{
			iter->second->Release();
			iter->second = NULL;
		}
	}
	m_pMarkerTextures.clear();
	HRESULT hr;
	WCHAR str[MAX_PATH] = {0};
	HMODULE module = GetModule();
	GetModuleFileName(module, str, MAX_PATH);
	// Gets filename
	WCHAR* pszFile = wcsrchr(str, '\\');
	pszFile++;    // Moves on from \
	// Get path
	WCHAR szPath[MAX_PATH] = L"";
	_tcsncat(szPath, str, pszFile - str);
	for (int i =0; i < NUMMARKER; i++)
	{
		LPDIRECT3DTEXTURE9 pTex = NULL;
		swprintf_s(str, MAX_PATH, L"%s\\..\\..\\mediaFiles\\ARTagAllMarkers\\marker_%03d.png", szPath, i);
		hr = D3DXCreateTextureFromFileEx(m_pDevice, str, D3DX_DEFAULT, D3DX_DEFAULT, 1, 0, 
			D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_FILTER_POINT, D3DX_DEFAULT,
			0, NULL, NULL, &pTex);
		if (FAILED(hr))
		{
			return false;
		}
		m_pMarkerTextures[i] = pTex;
	}
	
	return true;
}

HRESULT ARLayoutDXDisplay::OnBeforeResetDevice(IDirect3DDevice9 * pd3dDevice,	
									void* pUserContext)
{
	for (map<int, LPDIRECT3DTEXTURE9>::iterator iter = m_pMarkerTextures.begin();
		iter != m_pMarkerTextures.end(); iter++)
	{
		if (iter->second != NULL)
		{
			iter->second->Release();
			iter->second = NULL;
		}
	}
	m_pMarkerTextures.clear();
	if (m_pMarkerMesh != NULL)
	{
		delete m_pMarkerMesh;
		m_pMarkerMesh = NULL;
	}

	return __super::OnBeforeResetDevice(pd3dDevice,	 pUserContext);
}
HRESULT ARLayoutDXDisplay::OnAfterResetDevice(IDirect3DDevice9 * pd3dDevice,	
								   void* pUserContext)
{
	LoadARMarkTexture();
	CreateMarkerMesh();
	return __super::OnAfterResetDevice(pd3dDevice, pUserContext);
}