#include "ImTopDisplay.h"
#include "cv.h"

ImTopDisplay::ImTopDisplay(HWND hWnd, IDirect3D9* pD3D) : MS3DDisplay(hWnd, pD3D, 0, 0)
{
	m_pMaskTexture = NULL;
	m_bEditWarp = FALSE;
	m_bEditTTS = FALSE;
	m_bMaskEnable = FALSE;
	m_bStartDrag = FALSE;

	m_captureRect[0] = D3DXVECTOR2(0,0);
	m_captureRect[1] = D3DXVECTOR2(1,1);
	D3DXMatrixIdentity(&m_matTTS);
	D3DXMatrixIdentity(&m_matMaskTransform);

}
ImTopDisplay::~ImTopDisplay()
{
	ClearWarpButtons();
	ClearTTSButtons();
}


BOOL ImTopDisplay::ClearWarpButtons()
{
	if (m_pWarpButtons.size() > 0)
	{
		for (vector<MS3DButton*>::iterator it = m_pWarpButtons.begin(); it!=m_pWarpButtons.end(); ++it)
		{
			if ((*it) != NULL)
			{
				delete (*it);
				(*it) = NULL;
			}
		}
		m_pWarpButtons.clear();
	}
	return TRUE;
}
BOOL ImTopDisplay::CreateWarpButtons()
{
	ClearWarpButtons();
	if (m_pDisplayPlane == NULL)
	{
		return FALSE;
	}
	IDirect3DVertexBuffer9* pBuffer = m_pDisplayPlane->GetVertexBuffer();
	if (pBuffer == NULL)
	{
		return FALSE;
	}
	HRESULT hr;
	D3DVERTEXBUFFER_DESC desc;

	hr = pBuffer->GetDesc(&desc);
	UINT numVertex = desc.Size/sizeof(MSMeshBase::CUSTOMVERTEX);
	MSMeshBase::CUSTOMVERTEX* pVertices = NULL;
	hr = pBuffer->Lock(0,desc.Size, (void**)&pVertices, D3DLOCK_READONLY);
	for (int i =0; i < numVertex; i++ )
	{
		MS3DButton* btn = new MS3DButton(m_pDevice, this);

		btn->Scale(D3DXVECTOR3(0.05, 0.05, 1));
		btn->Translate(pVertices[i].position);

		m_pWarpButtons.push_back(btn);

		btn->Bind(L"WM_LBUTTONDOWN\0", (IEventManager::TaskFuncPtr)ImTopDisplay::onWarpButtonLDown, this);
		btn->Bind(L"WM_LBUTTONUP\0", (IEventManager::TaskFuncPtr)ImTopDisplay::onWarpButtonLUp, this);
		btn->Bind(L"WM_MOUSEDRAGMOVE\0", (IEventManager::TaskFuncPtr)ImTopDisplay::onWarpButtonDragMove, this);
	}
	pBuffer->Unlock();
	return TRUE;
}
BOOL ImTopDisplay::CreateTTSButtons()
{
	ClearTTSButtons();


	IDirect3DVertexBuffer9* pBuffer = m_pDisplayPlane->GetVertexBuffer();
	if (pBuffer == NULL)
	{
		return FALSE;
	}
	D3DXVECTOR4 initPos[4] = { D3DXVECTOR4(0,0,1,1), D3DXVECTOR4(0,1,1,1), D3DXVECTOR4(1,0,1,1), D3DXVECTOR4(1,1,1,1)};
	D3DXVECTOR3 btnPos[4] = {D3DXVECTOR3(0,0,0)};
	D3DXVECTOR3 cornerPos[4] = { D3DXVECTOR3(0,0,0)};

	HRESULT hr;
	D3DVERTEXBUFFER_DESC desc;
	hr = pBuffer->GetDesc(&desc);
	UINT numVertex = desc.Size/sizeof(MSMeshBase::CUSTOMVERTEX);
	MSMeshBase::CUSTOMVERTEX* pVertices = NULL;
	hr = pBuffer->Lock(0,desc.Size, (void**)&pVertices, D3DLOCK_READONLY);

	for (int i =0; i < numVertex; i++ )
	{
		if (pVertices[i].tu == 0 && pVertices[i].tv == 0)
		{
			cornerPos[0] = pVertices[i].position;
		}
		else if (pVertices[i].tu == 0 && pVertices[i].tv == 1)
		{
			cornerPos[1] = pVertices[i].position;
		}
		else if (pVertices[i].tu == 1 && pVertices[i].tv == 0)
		{
			cornerPos[2] = pVertices[i].position;
		}
		else if (pVertices[i].tu == 1 && pVertices[i].tv == 1)
		{
			cornerPos[3] = pVertices[i].position;
		}
	}

	D3DXMATRIX invTTS;
	D3DXMatrixInverse(&invTTS, NULL, &m_matTTS);

	WCHAR str[MAX_PATH];

	for (int i=0; i< 4; i++)
	{
		D3DXVec4Transform(&(initPos[i]), &(initPos[i]), &invTTS);
		initPos[i].x /= initPos[i].z;
		initPos[i].y /= initPos[i].z;
		initPos[i].z = 1;

		swprintf_s(str, MAX_PATH, L"@@@@ initPos[i] = (%.2f, %.2f)", initPos[i].x, initPos[i].y);
		OutputDebugStringW(str);
		D3DXVECTOR3 iV1 = (1- initPos[i].x) * cornerPos[0] + initPos[i].x * cornerPos[2];
		D3DXVECTOR3 iV2 = (1- initPos[i].x) * cornerPos[1] + initPos[i].x * cornerPos[3];
		btnPos[i] = (1- initPos[i].y) * iV1 + initPos[i].y * iV2; 

		MS3DButton* btn = new MS3DButton(m_pDevice, this);
		btn->Scale(D3DXVECTOR3(0.05, 0.05, 1));
		btn->Translate(btnPos[i]);

		m_pTTSButtons.push_back(btn);

		btn->Bind(L"WM_LBUTTONDOWN\0", (IEventManager::TaskFuncPtr)ImTopDisplay::onTTSButtonLDown, this);
		btn->Bind(L"WM_LBUTTONUP\0", (IEventManager::TaskFuncPtr)ImTopDisplay::onTTSButtonLUp, this);
		btn->Bind(L"WM_MOUSEDRAGMOVE\0", (IEventManager::TaskFuncPtr)ImTopDisplay::onTTSButtonDragMove, this);
	}
	return TRUE;
}

BOOL ImTopDisplay::ClearTTSButtons()
{
	if (m_pTTSButtons.size() > 0)
	{
		for (vector<MS3DButton*>::iterator it = m_pTTSButtons.begin(); it!=m_pTTSButtons.end(); ++it)
		{
			if ((*it) != NULL)
			{
				delete (*it);
				(*it) = NULL;
			}
		}
		m_pTTSButtons.clear();
	}
	return TRUE;
}

BOOL ImTopDisplay::Render()
{
	m_pDevice->Clear( 0, NULL, D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER, 
		D3DCOLOR_XRGB(50,50,50), 1.0f, 0 );
	m_pCamera->CameraOn();
	HRESULT hr;
	if( SUCCEEDED( m_pDevice->BeginScene() ) )
	{

		if (m_pDisplayPlane != NULL)
		{	
			D3DXMATRIX backupMat;
			hr = m_pDisplayPlane->Render(m_pTexture);
		}
		if (m_bEditWarp || m_bEditTTS)
		{
			m_pDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_SELECTARG1);
			m_pDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
			m_pDisplayPlane->Render();
			if (m_bEditWarp)
			{
				for (vector<MS3DButton*>::iterator it = m_pWarpButtons.begin(); it!=m_pWarpButtons.end(); ++it)
				{
					(*it)->Render();
				}
			}
			if (m_bEditTTS)
			{
				for (vector<MS3DButton*>::iterator it = m_pTTSButtons.begin(); it!=m_pTTSButtons.end(); ++it)
				{
					(*it)->Render();
				}
			}
			m_pDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
			m_pDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);
		}

		m_pDevice->EndScene();
	}

	m_pDevice->Present(NULL,NULL,NULL,NULL);
	m_pCamera->CameraOff();
	return TRUE;
}

BOOL ImTopDisplay::Render(IDirect3DBaseTexture9* pTexture)
{
	m_pDevice->Clear( 0, NULL, D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER, 
		D3DCOLOR_XRGB(50,50,50), 1.0f, 0 );


	m_pCamera->CameraOn();
	if( SUCCEEDED( m_pDevice->BeginScene() ) )
	{
		if (m_pDisplayPlane != NULL)
		{
			m_pDisplayPlane->Render(pTexture);
		}
		if (m_bEditWarp || m_bEditTTS)
		{
			m_pDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_SELECTARG1);
			m_pDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
			m_pDisplayPlane->Render();
			if (m_bEditWarp)
			{
				for (vector<MS3DButton*>::iterator it = m_pWarpButtons.begin(); it!=m_pWarpButtons.end(); ++it)
				{
					(*it)->Render();
				}
			}
			if (m_bEditTTS)
			{
				for (vector<MS3DButton*>::iterator it = m_pTTSButtons.begin(); it!=m_pTTSButtons.end(); ++it)
				{
					(*it)->Render();
				}
			}
			m_pDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
			m_pDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);
		}
		m_pDevice->EndScene();
	}
	m_pDevice->Present(NULL,NULL,NULL,NULL);
	m_pCamera->CameraOff();
	return TRUE;
}

BOOL ImTopDisplay::Render(IDirect3DBaseTexture9* pTexture, ID3DXEffect* pEffect)
{
	if (pEffect == NULL)
		return FALSE;
	UINT iPass, cPasses = 0;
	m_pDevice->Clear( 0, NULL, D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER, 
		D3DCOLOR_XRGB(50,50,50), 1.0f, 0 );

	HRESULT hr;
	m_pCamera->CameraOn();
	static float t = 0.0;
	t += 0.01;
	if (t > 1)
		t -= 1;
	if( SUCCEEDED( m_pDevice->BeginScene() ) )
	{
		hr = pEffect->SetMatrix("g_matTexTransform", &m_matTTS);
		if FAILED(hr)
		{
			OutputDebugStringW(L"@@@@ pEffect->SetMatrix Failed!!");
		}
		hr = pEffect->SetTexture("g_Texture", pTexture);
		if FAILED(hr)
		{
			OutputDebugStringW(L"@@@@ pEffect->SetTexture Failed!!");
		}
		D3DXMATRIX invmatMask;
		D3DXMatrixInverse(&invmatMask, NULL, &m_matMaskTransform);

		hr = pEffect->SetMatrix("g_invMatMaskTransform", &invmatMask);
		if (m_pMaskTexture != NULL)
		{
			pEffect->SetTexture("g_MaskTexture", m_pMaskTexture);
		}
		pEffect->SetBool("g_bMaskEnable", m_bMaskEnable);


		D3DXMATRIX mWorld = m_pDisplayPlane->GetTransform();
		D3DXMATRIX mProj = m_pCamera->GetProjMatrix();
		D3DXMATRIX mView = m_pCamera->GetViewMatrix();
		D3DXMATRIX mWorldViewProjection = mWorld * mView * mProj;
		hr = pEffect->SetMatrix("WorldViewProj", &mWorldViewProjection);

		if FAILED(hr)
		{
			OutputDebugStringW(L"@@@@ pEffect->SetMatrix Failed!!");
		}
		hr = pEffect->SetTechnique("technique0");

		if FAILED(hr)
		{
			OutputDebugStringW(L"@@@@ pEffect->SetTechnique Failed!!");
		}

		pEffect->Begin(&cPasses, 0);
		for (iPass = 0; iPass < cPasses; iPass++)
		{
			pEffect->BeginPass(iPass);

			if (m_pDisplayPlane != NULL)
			{
				m_pDisplayPlane->Render(pTexture);
			}
			pEffect->EndPass();
		}
		pEffect->End();


		if (m_bEditWarp || m_bEditTTS)
		{
			m_pDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_SELECTARG1);
			m_pDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
			m_pDisplayPlane->Render();
			if (m_bEditWarp)
			{
				for (vector<MS3DButton*>::iterator it = m_pWarpButtons.begin(); it!=m_pWarpButtons.end(); ++it)
				{
					(*it)->Render();
				}
			}
			if (m_bEditTTS)
			{
				for (vector<MS3DButton*>::iterator it = m_pTTSButtons.begin(); it!=m_pTTSButtons.end(); ++it)
				{
					(*it)->Render();
				}
			}
			m_pDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
			m_pDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);
		}

		m_pDevice->EndScene();
	}
	m_pDevice->Present(NULL,NULL,NULL,NULL);
	m_pCamera->CameraOff();

	return TRUE;
}


BOOL ImTopDisplay::SetEditWarpEnable(BOOL enable)
{
	m_bEditWarp = enable;
	if (enable)
	{
		CreateWarpButtons();
	}
	else
	{
		ClearWarpButtons();
	}
	return TRUE;
}

BOOL ImTopDisplay::SetEditTTSEnable(BOOL enable)
{
	m_bEditTTS = enable;
	if (enable)
	{
		CreateTTSButtons();
	}
	else
	{
		ClearTTSButtons();
	}
	return TRUE;
}

BOOL ImTopDisplay::SetCaptureRegion(float l, float t, float r, float b)
{
	if (l < 0 || l > 1 || t < 0 || t > 1 || r <0 || r > 1 || b < 0 || b >1)
		return FALSE;
	if (l > r || t > b)
		return FALSE;

	m_captureRect[0].x = l;
	m_captureRect[0].y = t;
	m_captureRect[1].x = r;
	m_captureRect[1].y = b;

	return TRUE;
}

BOOL ImTopDisplay::GetCaptureRegion(float& l, float& t, float& r, float &b)
{
	l = m_captureRect[0].x;
	t = m_captureRect[0].y;
	r = m_captureRect[1].x;
	b = m_captureRect[1].y;
	return TRUE;
}


BOOL ImTopDisplay::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	MSEventManager::WndProc( hWnd, message, wParam, lParam);
	if (m_pDevice == NULL)
		return FALSE;
	int xPos, yPos = 0;
	WCHAR str[MAX_PATH];
	BOOL ret = FALSE;

	if ( message == WM_LBUTTONDOWN || message == WM_LBUTTONUP || message == WM_RBUTTONDOWN || 
		message == WM_RBUTTONUP || message == WM_MOUSEMOVE)
	{
		xPos = LOWORD(lParam); 
		yPos = HIWORD(lParam);

		D3DXVECTOR3 vPos(0,0,0), vDir(0,0,0);

		if (m_pCamera->Screen2World(hWnd, xPos, yPos, vPos,vDir))
		{
			PassMouseMessage(message, wParam, lParam, vPos, vDir);
			if (!m_bEditWarp)
			{
				BOOL bHit = FALSE;
				float tU, tV = 0;
				IntersectWithPlane(vPos, vDir, bHit, tU, tV);

				if (bHit)
				{
					ret = TRUE;
					struct TData
					{
						UINT msg;
						float tU;
						float tV;
					};
					TData data;
					data.msg = message;
					data.tU = tU;
					data.tV = tV;
					Invoke(L"WM_ReceiveMouseMessage", wParam, lParam, (void*)&data );
				}
			}

		}

	}
	else if(message == WM_PAINT)
	{
		ID3DXEffect* pEffect = GetEffect();
		if (pEffect != NULL)
			Render(this->m_pTexture, pEffect);
		else
			Render(this->m_pTexture );
	}
	return ret;
}


BOOL ImTopDisplay::onWarpButtonLDown(void* _THIS, WPARAM wParam, LPARAM lParam, void* pData)
{
	OutputDebugStringW(L"@@@@ onWarpButtonLDown \n");
	((ImTopDisplay*)_THIS)->m_bStartDrag = TRUE;

	return TRUE;
}

BOOL ImTopDisplay::onWarpButtonLUp(void* _THIS, WPARAM wParam, LPARAM lParam, void* pData)
{
	OutputDebugStringW(L"@@@@ onWarpButtonLUp \n");
	((ImTopDisplay*)_THIS)->m_bStartDrag = FALSE;
	return TRUE;
}



BOOL ImTopDisplay::onWarpButtonDragMove(void* _THIS, WPARAM wParam, LPARAM lParam, void* pData)
{
	//OutputDebugStringW(L"@@@@ onWarpButtonDragMove \n");

	if (((ImTopDisplay*)_THIS)->m_bStartDrag)
	{
		MS3DButton* pbutton =((MS3DButton*)((MSEventManager*)pData));
		int index = -1;
		for (int i =0; i < ((ImTopDisplay*)_THIS)->m_pWarpButtons.size(); i++)
		{
			if (pbutton == ((ImTopDisplay*)_THIS)->m_pWarpButtons.at(i))
			{
				index = i;
				break;
			}
		}
		if (index == -1)
		{
			return FALSE;
		}

		int xPos = LOWORD(lParam); 
		int yPos = HIWORD(lParam);
		D3DXVECTOR3 pos, dir;

		((ImTopDisplay*)_THIS)->m_pCamera->Screen2World(((ImTopDisplay*)_THIS)->m_hDisplayWnd, xPos, yPos, pos, dir);
		D3DXVECTOR3 prePos = pbutton->GetPosition();
		D3DXVECTOR3 newPos(pos.x, pos.y, prePos.z);
		MSMeshBase::CUSTOMVERTEX vertex;
		((ImTopDisplay*)_THIS)->m_pDisplayPlane->GetVertex(index, vertex);
		vertex.position.x = newPos.x;
		vertex.position.y = newPos.y;
		((ImTopDisplay*)_THIS)->m_pDisplayPlane->SetVertex(index, vertex);
		pbutton->SetPosition(newPos);
	}
	return TRUE;
}

BOOL ImTopDisplay::onTTSButtonLDown(void* _THIS, WPARAM wParam, LPARAM lParam, void* pData)
{
	OutputDebugStringW(L"@@@@ onTTSButtonLDown \n");
	((ImTopDisplay*)_THIS)->m_bStartDrag = TRUE;

	return TRUE;
}

BOOL ImTopDisplay::onTTSButtonLUp(void* _THIS, WPARAM wParam, LPARAM lParam, void* pData)
{
	OutputDebugStringW(L"@@@@ onTTSButtonLUp \n");
	((ImTopDisplay*)_THIS)->m_bStartDrag = FALSE;
	return TRUE;
}


BOOL ImTopDisplay::onTTSButtonDragMove(void* _THIS, WPARAM wParam, LPARAM lParam, void* pData)
{
	//OutputDebugStringW(L"@@@@ onTTSButtonDragMove \n");

	if (((ImTopDisplay*)_THIS)->m_bStartDrag)
	{
		MS3DButton* pbutton =((MS3DButton*)((MSEventManager*)pData));
		int index = -1;
		for (int i =0; i < ((ImTopDisplay*)_THIS)->m_pTTSButtons.size(); i++)
		{
			if (pbutton == ((ImTopDisplay*)_THIS)->m_pTTSButtons.at(i))
			{
				index = i;
				break;
			}
		}
		if (index == -1)
		{
			return FALSE;
		}
		int xPos = LOWORD(lParam); 
		int yPos = HIWORD(lParam);

		D3DXVECTOR3 vPos, vDir;

		((ImTopDisplay*)_THIS)->m_pCamera->Screen2World(((ImTopDisplay*)_THIS)->m_hDisplayWnd, xPos, yPos, vPos, vDir);

		D3DXVECTOR3 prePos = pbutton->GetPosition();
		D3DXVECTOR3 newPos(vPos.x, vPos.y, prePos.z);

		BOOL bHit = FALSE;
		float tU, tV = 0;
		((ImTopDisplay*)_THIS)->IntersectWithPlane(vPos, vDir, bHit, tU, tV);
		if (bHit)
		{
			pbutton->SetPosition(newPos);
			((ImTopDisplay*)_THIS)->UpdateTTSByTTSButtons();
		}
	}
	return TRUE;
}

BOOL ImTopDisplay::SetTTS(const D3DXVECTOR2 v1, const D3DXVECTOR2 v2, const D3DXVECTOR2 v3, const D3DXVECTOR2 v4)
{
	m_matTTS = ComputeTTS(v1, v2, v3, v4);
	return TRUE;
}

D3DXMATRIX ImTopDisplay::ComputeTTS(const D3DXVECTOR2& v1, const D3DXVECTOR2& v2, const D3DXVECTOR2& v3, const D3DXVECTOR2& v4)
{
	WCHAR str[MAX_PATH];
	D3DXMATRIX ret;
	D3DXMatrixIdentity(&ret);
	CvMat cvPt;
	CvMat dstPt;

	float t[] = {0,0,
		0,1,
		1,0,
		1,1};
	float d[] = {v1.x, v1.y,
		v2.x, v2.y,
		v3.x, v3.y,
		v4.x, v4.y};
	float s[] = {0,0,0,
		0,0,0,
		0,0,0};

	cvPt = cvMat( 4, 2, CV_32F, &t);
	dstPt = cvMat(4, 2, CV_32F, &d);
	CvMat mat = cvMat(3,3, CV_32F, &s);
	cvFindHomography(&dstPt, &cvPt, &mat);

	ret._11 = mat.data.fl[0*3 + 0];
	ret._21 = mat.data.fl[0*3 + 1];
	ret._31 = mat.data.fl[0*3 + 2];

	ret._12 = mat.data.fl[1*3 + 0];
	ret._22 = mat.data.fl[1*3 + 1];
	ret._32 = mat.data.fl[1*3 + 2];

	ret._13 = mat.data.fl[2*3 + 0];
	ret._23 = mat.data.fl[2*3 + 1];
	ret._33 = mat.data.fl[2*3 + 2];

	
	return ret;
}

BOOL ImTopDisplay::UpdateTTSByTTSButtons()
{
	if (m_pTTSButtons.size() != 4)
		return FALSE;
	D3DXVECTOR2 pt[4] = {D3DXVECTOR2(0,0)};
	for (int i =0; i < m_pTTSButtons.size(); i++)
	{
		MS3DButton* pbutton = m_pTTSButtons.at(i);
		D3DXVECTOR3 pos = pbutton->GetPosition();
		D3DXVECTOR3 dir = pos - m_pCamera->GetEyePos();
		BOOL bHit = FALSE;
		float tU, tV = 0;
		IntersectWithPlane(pos, dir, bHit, tU, tV);
		if (!bHit)
		{
			return FALSE;
		}
		pt[i] = D3DXVECTOR2(tU, tV);
	}
	m_matTTS =  ComputeTTS(pt[0], pt[1],pt[2], pt[3]);
	return TRUE;
}

BOOL ImTopDisplay::DrawBitBlt(HDC hdc, int x, int y, int width, int height, int dcW, int dcH, HDC hdcSrc, int x1, int y1, int srcW, int srcH, DWORD rop)
{
	//return TRUE;
	if (m_pTexture == NULL)
		return FALSE;
	if (dcW <= 0 || dcH <= 0 )
	{
		return FALSE;
	}
	//WCHAR str[MAX_PATH];
	//swprintf_s(str, MAX_PATH, L"@@@@@ x = %d, y = %d, width = %d, height = %d\n", x, y, width, height);
	//OutputDebugStringW(str);

	HRESULT hr;
	IDirect3DSurface9* pSurface = NULL;
	m_pTexture->GetSurfaceLevel(0, &pSurface);
	pSurface->UnlockRect();

	HDC textureDC;
	hr = pSurface->GetDC(&textureDC);
	if (FAILED(hr))
	{
		WCHAR str[MAX_PATH];
		swprintf_s(str, MAX_PATH, L"@@@@ pSurface->GetDC Failed in DrawBitBlt, hr = %Xh \n", hr);
		OutputDebugStringW(str);
	}
	D3DSURFACE_DESC desc;
	pSurface->GetDesc(&desc);

	float rX = ((float)desc.Width / dcW);
	float rY = ((float)desc.Height / dcH);
	
	/*
	swprintf_s(str, MAX_PATH, L"@@@@ rX = %.2f, rY = %.2f, desc.Width = %d, desc.Height = %d, \
		dcW = %d, dcH = %d\n",
		rX, rY, desc.Width, desc.Height, dcW, dcH );
	OutputDebugStringW(str);
*/
	StretchBlt(textureDC, rX*x, rY*y, rX*width, rY*height, hdcSrc, x1, y1, srcW, srcH, rop);
/*	swprintf_s(str, MAX_PATH, L"@@@@@ rX*x = %.2f, rY*y = %.2f, rX*width = %.2f, rY*height = %.2f\n",rX*x, rY*y, rX*width, rY*height);
	OutputDebugStringW(str);*/
	pSurface->ReleaseDC(textureDC);
	pSurface->Release();
	pSurface = NULL;
	
	ID3DXEffect* pEffect = GetEffect();
	
	if (pEffect != NULL)
		Render(this->m_pTexture, pEffect);
	else
		Render(this->m_pTexture );
	
	return TRUE;
}


BOOL ImTopDisplay::LoadMaskTextureFromFile(WCHAR* path)
{
	if (m_pMaskTexture != NULL)
	{
		m_pMaskTexture->Release();
		m_pMaskTexture = NULL;
	}
	HRESULT hr;
	hr = D3DXCreateTextureFromFile(m_pDevice, path, &m_pMaskTexture);
	if (FAILED(hr))
	{
		OutputDebugStringW(L"@@@@@ LoadMaskTextureFromFile Failed!!\n");
		return FALSE;
	}

	return TRUE;
}

BOOL ImTopDisplay::SetMaskPos(float tx, float ty, float sx, float sy)
{
	D3DXMATRIX tmp;
	D3DXMatrixIdentity(&m_matMaskTransform);
	D3DXMatrixTranslation(&tmp, -0.5, -0.5, 0);
	m_matMaskTransform = m_matMaskTransform*tmp;
	D3DXMatrixScaling(&tmp, sx, sy, 1);
	m_matMaskTransform = m_matMaskTransform*tmp;
	D3DXMatrixTranslation(&tmp, 0.5, 0.5, 0);
	m_matMaskTransform = m_matMaskTransform*tmp;
	D3DXMatrixTranslation(&tmp, tx - 0.5, ty - 0.5, 0);
	m_matMaskTransform = m_matMaskTransform*tmp;
	return TRUE;
}
