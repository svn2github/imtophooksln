#include "StdAfx.h"
#include "ARTagD3DDisplay.h"


MS3DARMarker::MS3DARMarker(IDirect3DDevice9* pDevice) : MS3DPlane(pDevice)
{
	m_markerID = -1;
	m_pIDMesh = NULL;
	m_color = D3DCOLOR_ARGB(255,0,0, 255);
}
MS3DARMarker::~MS3DARMarker()
{
	if (m_pIDMesh != NULL)
	{
		m_pIDMesh->Release();
		m_pIDMesh = NULL;
	}
}
BOOL MS3DARMarker::SetMarkID(int _id)
{
	if (m_markerID != _id )
	{
		if (m_pIDMesh != NULL)
		{
			m_pIDMesh->Release();
			m_pIDMesh = NULL;
		}
		WCHAR str[MAX_PATH];
		swprintf_s(str, MAX_PATH, L"%d\0", _id);
		CreateD3DXTextMesh(m_pDevice, &m_pIDMesh, str, L"Arial", 0, FALSE, FALSE);
		if (m_pIDMesh != NULL)
		{
			class SimpleVertex
			{
			public:
				D3DXVECTOR3 position;
				D3DXVECTOR3 normal;
			};
			SimpleVertex* vData = NULL;
			IDirect3DVertexBuffer9* pVBuffer = NULL;
			D3DVERTEXBUFFER_DESC desc;
			m_pIDMesh->GetVertexBuffer(&pVBuffer);
			pVBuffer->GetDesc(&desc);
			pVBuffer->Lock(0, 0, (void**)&vData, 0);
			for (int i =0; i< desc.Size/sizeof(SimpleVertex); i++)
			{
				vData[i].position.x *= 10;
				vData[i].position.y *= 10;
			}

			pVBuffer->Unlock();
		}
	}
	m_markerID = _id;
	return TRUE;
}

BOOL MS3DARMarker::Render()
{
	HRESULT hr;
	D3DXMATRIX preMatWorld;
	m_pDevice->GetTransform(D3DTS_WORLD, &preMatWorld);
	hr = m_pDevice->SetTransform(D3DTS_WORLD, &this->GetTransform() );
	MSMeshBase::Render();
	
	if (m_pIDMesh != NULL)
	{
		m_pDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
		m_pDevice->SetTextureStageState(0, D3DTSS_CONSTANT, D3DCOLOR_ARGB(255,0,255,0) );
		m_pIDMesh->DrawSubset(0);
		m_pDevice->SetTextureStageState(0, D3DTSS_CONSTANT, 0xffffffff);
		m_pDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	}
	hr = m_pDevice->SetTransform(D3DTS_WORLD, &preMatWorld );
	return TRUE;
}
HRESULT MS3DARMarker::CreateD3DXTextMesh( IDirect3DDevice9* pd3dDevice, 
						   LPD3DXMESH* ppMesh, 
						   WCHAR* txt,
						   WCHAR* pstrFont, DWORD dwSize,
						   BOOL bBold, BOOL bItalic )
{
	HRESULT hr;
	LPD3DXMESH pMeshNew = NULL;
	HDC hdc = CreateCompatibleDC( NULL );
	if( hdc == NULL )
		return E_OUTOFMEMORY;
	INT nHeight = -MulDiv( dwSize, GetDeviceCaps(hdc, LOGPIXELSY), 72 );
	HFONT hFont;
	HFONT hFontOld;

	hFont = CreateFont(nHeight, 0, 0, 0, bBold ? FW_BOLD : FW_NORMAL, bItalic, FALSE, FALSE, DEFAULT_CHARSET, 
		OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, pstrFont);

	hFontOld = (HFONT)SelectObject(hdc, hFont); 

	hr = D3DXCreateText( pd3dDevice, hdc, txt, 
		0.0f, 0.4f, &pMeshNew, NULL, NULL);
	
	SelectObject(hdc, hFontOld);
	DeleteObject( hFont );
	DeleteDC( hdc );

	if( SUCCEEDED( hr ) )
		*ppMesh = pMeshNew;

	return hr;
}
ARTagD3DDisplay::ARTagD3DDisplay(IDirect3DDevice9* pDevice, UINT rtWidth, UINT rtHeight) : 
MS3DDisplay(pDevice, rtWidth, rtHeight)
{
	HRESULT hr = S_FALSE;
	m_pD3DLine = NULL;

	m_pD3DFont = NULL;
	m_pD3DSprite = NULL;
	hr = D3DXCreateSprite(m_pDevice, &m_pD3DSprite);
	hr = D3DXCreateLine(m_pDevice, &m_pD3DLine);
	hr = D3DXCreateFont(m_pDevice, 15, 0, FW_NORMAL, 0, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, 
		DEFAULT_PITCH | FF_DONTCARE, L"System", &m_pD3DFont  );
}
ARTagD3DDisplay::ARTagD3DDisplay(IDirect3D9* pD3D, UINT rtWidth, UINT rtHeight) : 
	MS3DDisplay(pD3D, rtWidth, rtHeight)
{
	HRESULT hr = S_FALSE;
	m_pD3DLine = NULL;

	m_pD3DFont = NULL;
	m_pD3DSprite = NULL;
	hr = D3DXCreateSprite(m_pDevice, &m_pD3DSprite);
	hr = D3DXCreateLine(m_pDevice, &m_pD3DLine);
	hr = D3DXCreateFont(m_pDevice, 15, 0, FW_NORMAL, 0, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, 
		DEFAULT_PITCH | FF_DONTCARE, L"System", &m_pD3DFont  );
}

ARTagD3DDisplay::~ARTagD3DDisplay(void)
{
	
	if (m_pD3DLine != NULL)
	{
		m_pD3DLine->Release();
		m_pD3DLine = NULL;
	}
	if (m_pD3DFont != NULL)
	{
		m_pD3DFont->Release();
		m_pD3DFont = NULL;
	}
	if (m_pD3DSprite != NULL)
	{
		m_pD3DSprite->Release();
		m_pD3DSprite = NULL;
	}
}

BOOL ARTagD3DDisplay::Render(ARMarkerInfo* markinfos, int numMarkinfo)
{
	m_pDevice->Clear( 0, NULL, D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER, 
		D3DCOLOR_XRGB(50,50,50), 1.0f, 0 );
	m_pDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
	HRESULT hr;
	
	if( SUCCEEDED( m_pDevice->BeginScene() ) )
	{
		/*m_pCamera->CameraOn();
		
		if (m_pDisplayPlane != NULL)
		{
			m_pDisplayPlane->Render(m_pTexture);
		}
		*/
		m_pD3DSprite->Begin(0);
		m_pD3DSprite->Draw(m_pTexture,NULL,NULL,NULL,0xFFFFFFFF);
		m_pD3DSprite->End();
		m_pCamera->CameraOff();
		D3DXVECTOR2* pts = new D3DXVECTOR2[5];
		WCHAR str[MAX_PATH];
		for (int i=0; i < numMarkinfo; i++)
		{
			RECT rect; rect.left = 100000; rect.right = 0; rect.top = 100000; rect.bottom = 0;
			for (int j =0; j < 4; j++)
			{
				pts[j].x = markinfos[i].vertex[j][0];
				pts[j].y = markinfos[i].vertex[j][1];
				rect.left = min(rect.left, pts[j].x);
				rect.right = max(rect.right, pts[j].x);
				rect.top = min(rect.top, pts[j].y);
				rect.bottom = max(rect.bottom, pts[j].y);
			}
			pts[4].x = markinfos[i].vertex[0][0];
			pts[4].y = markinfos[i].vertex[0][1];
			
			m_pD3DLine->Draw(pts, 5, D3DCOLOR_ARGB(255, 255,0,0));
			swprintf_s(str, MAX_PATH, L"%d\0", markinfos[i].id);
			if (m_pD3DFont != NULL)
			{
				hr = m_pD3DFont->DrawTextW(NULL, str, -1, &rect, DT_NOCLIP | DT_CENTER | DT_VCENTER, D3DXCOLOR( 1.0f, 0.0f, 0.0f, 1.0f ));	
			}
		}
		delete[] pts;

		m_pDevice->EndScene();
	}
	m_pDevice->Present(NULL,NULL,NULL,NULL);
	m_pDevice->SetRenderState(D3DRS_ZENABLE, TRUE);

	return TRUE;
}


BOOL ARTagD3DDisplay::Render()
{
	return FALSE;
}

BOOL ARTagD3DDisplay::Render(IDirect3DBaseTexture9* pTexture)
{
	return FALSE;
}
BOOL ARTagD3DDisplay::Render(IDirect3DBaseTexture9* pTexture, ID3DXEffect* pEffect)
{			
	return FALSE;
}

