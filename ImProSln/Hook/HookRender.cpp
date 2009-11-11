#include "stdafx.h"
#include "HookRender.h"

using namespace HookRender;

namespace HookRender
{
/*
	void SetupViewPort()
	{
		D3DXVECTOR3 vEyePt( 0.0f, 0.0f,-5.0f );
		D3DXVECTOR3 vLookatPt( 0.0f, 0.0f, 0.0f );
		D3DXVECTOR3 vUpVec( 0.0f, 1.0f, 0.0f );
		D3DXMATRIXA16 matView;
		D3DXMatrixLookAtLH( &matView, &vEyePt, &vLookatPt, &vUpVec );
		g_pd3dDevice->SetTransform( D3DTS_VIEW, &matView );
		D3DXMATRIXA16 matProj;
		D3DXMatrixPerspectiveFovLH( &matProj, D3DX_PI/4, 1.0f, 1.0f, 100.0f );
		g_pd3dDevice->SetTransform( D3DTS_PROJECTION, &matProj );
	}

	bool myRender(IDirect3DDevice9* pDevice)
	{
		pDevice->Clear( 0, NULL, D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER, 
			D3DCOLOR_XRGB(128,128,128), 1.0f, 0 );
		if (pDevice == NULL)
		{
			return false;
		}
		if (g_pRenderTarget != NULL)
		{
			if (g_pDisplayPlane == NULL)
			{
				g_pDisplayPlane = new MS3DPlane(g_pd3dDevice);
				g_pDisplayPlane->InitGeometry();
				g_pDisplayPlane->Scale(D3DXVECTOR3(20, 20, 0));
				g_pDisplayPlane->Translate(D3DXVECTOR3(0, 0, 30));
			}
			HRESULT hr2;

			SetupViewPort();
			g_pDisplayPlane->Translate(D3DXVECTOR3(0, 0, -30));
			g_pDisplayPlane->Rotate(D3DXVECTOR3(D3DX_PI/360.0, 0, 0));
			g_pDisplayPlane->Translate(D3DXVECTOR3(0, 0, 30));
			hr2 = pDevice->SetTexture(0, g_pRenderTarget);
			hr2 = pDevice->SetStreamSource(0, g_pDisplayPlane->GetVertexBuffer(), 0, sizeof(MS3DPlane::CUSTOMVERTEX));
			hr2 = pDevice->SetIndices(g_pDisplayPlane->GetIndexBuffer());
			hr2 = pDevice->SetFVF(g_pDisplayPlane->GetVertexFMT());
			hr2 = pDevice->SetTransform(D3DTS_WORLD, &g_pDisplayPlane->GetTransform());
			hr2 = pDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST,0,0, g_pDisplayPlane->GetVertexNumber(),
				0, g_pDisplayPlane->GetPrimitiveNumber());
			hr2 = pDevice->SetTexture(0, NULL);

		}
		return true;
	}
*/
}