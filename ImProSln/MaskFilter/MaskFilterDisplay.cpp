#include "StdAfx.h"
#include "MaskFilterDisplay.h"


MaskFilterDisplay::MaskFilterDisplay(IDirect3D9* pD3D, UINT rtWidth, UINT rtHeight) : 
MS3DDisplay(pD3D, rtWidth, rtHeight)
{
	m_pMaskTexture = NULL;
	m_maskFlag = BlendMask;
	m_pMarkerMesh = NULL;
	m_bMaskFlipY = false;
	CreateMarkerMesh();
	CreateTexture(0, 0);
	m_pMaskCamera = new MSCamera(m_pDevice);
	m_pMaskCamera->SetOrthoPara(-0.5, 0.5, 0.5, -0.5);
	m_pMaskCamera->SetEyePos(D3DXVECTOR3(0.5, -0.5, -5));
	m_pMaskCamera->SetLookAt(D3DXVECTOR3(0.5, -0.5, 0));
}
MaskFilterDisplay::MaskFilterDisplay(IDirect3DDevice9* pDevice, UINT rtWidth, UINT rtHeight) : 
MS3DDisplay(pDevice, rtWidth, rtHeight)
{
	m_pMaskTexture = NULL;
	m_maskFlag = BlendMask;
	m_pMarkerMesh = NULL;
	m_bMaskFlipY = false;
	CreateMarkerMesh();
	CreateTexture(0, 0);
	m_pMaskCamera = new MSCamera(m_pDevice);
	m_pMaskCamera->SetOrthoPara(-0.5, 0.5, 0.5, -0.5);
	m_pMaskCamera->SetEyePos(D3DXVECTOR3(0.5, -0.5, -5));
	m_pMaskCamera->SetLookAt(D3DXVECTOR3(0.5, -0.5, 0));
}
MaskFilterDisplay::~MaskFilterDisplay(void)
{
	if (m_pMaskTexture != NULL)
	{
		m_pMaskTexture->Release();
		m_pMaskTexture = NULL;
	}
	if (m_pMarkerMesh != NULL)
	{
		delete m_pMarkerMesh;
		m_pMarkerMesh = NULL;
	}
	if (m_pMaskCamera != NULL)
	{
		delete m_pMaskCamera;
		m_pMaskCamera = NULL;
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

	hr = D3DXCreateTexture(m_pDevice, MASKSIZE, MASKSIZE, 0, D3DUSAGE_RENDERTARGET ,
			D3DFMT_A8R8G8B8, D3DPOOL_DEFAULT, &m_pMaskTexture);

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

BOOL MaskFilterDisplay::GenerateMaskFromARLauout(const ARMultiMarkerInfoT* pMarkerConfig)
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
	ID3DXEffect* pEffect = GetEffect();
	if (pEffect == NULL)
	{
		return FALSE;
	}
	UINT iPass, cPasses = 0;
	m_pMaskCamera->CameraOn();
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
			tranMat = matScale * tranMat;
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
	m_pMaskCamera->CameraOff();

	m_pDevice->SetRenderTarget(0, pBackBuffer);
	pBackBuffer->Release();
	pBackBuffer = NULL;
	pMaskSurface->Release();
	pMaskSurface = NULL;
	
	return TRUE;
}

bool MaskFilterDisplay::CreateMarkerMesh()
{
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

BOOL MaskFilterDisplay::GenerateMaskFromARLayoutFile(WCHAR* path)
{
	ARMultiEachMarkerInfoT* ARMarkers = NULL;
	int numMarker = 0;
	try
	{
		FILE* filestream = NULL;
		_wfopen_s(&filestream, path, L"r");
		if (filestream == NULL)
		{
			return false;
		}
		fwscanf_s(filestream, L"%d\n", &numMarker);
		ARMarkers = new ARMultiEachMarkerInfoT[numMarker];
		memset((void*)ARMarkers, 0, sizeof(ARMultiEachMarkerInfoT)* numMarker);
		for (int i = 0; i < numMarker; i++ )
		{
			double mat[3][4] = {0};
			double width = 0;
			double centerX = 0, centerY = 0;
			fwscanf_s(filestream, L"%d\n", &(ARMarkers[i].patt_id));
			fwscanf_s(filestream, L"%d %lf \n", &(ARMarkers[i].visible), &width);
			fwscanf_s(filestream, L"%lf %lf \n", &centerX, &centerY);
			fwscanf_s(filestream, L"%lf %lf %lf %lf \n \
								   %lf %lf %lf %lf \n \
								   %lf %lf %lf %lf \n",
								   &(mat[0][0]), &(mat[0][1]), &(mat[0][2]), &(mat[0][3]),
								   &(mat[1][0]), &(mat[1][1]), &(mat[1][2]), &(mat[1][3]),
								   &(mat[2][0]), &(mat[2][1]), &(mat[2][2]), &(mat[2][3])
								   );
			ARMarkers[i].width = width;
			ARMarkers[i].center[0] = centerX;
			ARMarkers[i].center[1] = centerY;
			for (int row = 0; row < 3; row ++)
			{
				for (int col = 0; col < 4; col++)
				{
					ARMarkers[i].trans[row][col] = mat[row][col];
				}
			}
		}
		fclose(filestream);
		ARMultiMarkerInfoT* config = NULL;
		GenerateARMarkinfo(ARMarkers, numMarker, config);
		if (config != NULL)
		{
			GenerateMaskFromARLauout(config);
		}
		if (config != NULL)
		{
			delete config;
			config = NULL;
		}
		if (ARMarkers != NULL)
		{
			delete[] ARMarkers;
			ARMarkers = NULL;
		}
	}
	catch (exception e)
	{
		return S_FALSE;
	}
	return TRUE;
}

BOOL MaskFilterDisplay::GenerateARMarkinfo(ARMultiEachMarkerInfoT* marker, int numMarker, ARMultiMarkerInfoT*& config)
{
	if (config != NULL)
		return FALSE;

	config = new ARMultiMarkerInfoT();
	config->marker_num = numMarker;
	for (int i = 0; i < 3; i++)
	{
		for (int j =0; j< 4; j++)
		{
			config->trans[i][j] = 0;
			config->transR[i][j] = 0;
		}
	}
	config->prevF = 0;
	config->marker = marker;

	return TRUE;
}

BOOL MaskFilterDisplay::GetMaskFlipY()
{
	return m_bMaskFlipY;
}
BOOL MaskFilterDisplay::SetMaskFlipY(bool bFlipY)
{
	m_bMaskFlipY = bFlipY;
	return TRUE;
}