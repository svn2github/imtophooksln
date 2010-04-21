#include "ImTubeDisplay.h"
#include "cv.h"

ImTubeDisplay::ImTubeDisplay(HWND hWnd, IDirect3D9* pD3D) : ImTopDisplay(hWnd, pD3D)
{
	cofA1 = 0.0; cofB1 = 0.0; cofC1 = 0.0; cofD1 = 0.0; cofE1 = 0.0; 
	cofA2 = 0.0; cofB2 = 0.0; cofC2 = 0.0; cofD2 = 0.0; cofE2 = 1.0; 
	cofAx = 0.0; cofBx = 0.0; cofCx = 0.0; cofDx = 1.0; cofEx = 0.0; 
}

ImTubeDisplay::~ImTubeDisplay()
{

}

BOOL ImTubeDisplay::CreateTTSButtons()
{
	ClearTTSButtons();
	IDirect3DVertexBuffer9* pBuffer = m_pDisplayPlane->GetVertexBuffer();
	if (pBuffer == NULL)
	{
		return FALSE;
	}
	D3DXVECTOR2 initPos[15] = { D3DXVECTOR2(0, 0), D3DXVECTOR2(0.25,0),D3DXVECTOR2(0.5,0),D3DXVECTOR2(0.75,0),D3DXVECTOR2(1.0, 0),
		D3DXVECTOR2(0, 1), D3DXVECTOR2(0.25,1),D3DXVECTOR2(0.5,1),D3DXVECTOR2(0.75,1),D3DXVECTOR2(1.0, 1) ,
		D3DXVECTOR2(0, 0.5), D3DXVECTOR2(0.25,0.5),D3DXVECTOR2(0.5,0.5),D3DXVECTOR2(0.75,0.5),D3DXVECTOR2(1.0, 0.5) };
	D3DXVECTOR3 btnPos[15] = {D3DXVECTOR3(0,0,0)};
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

	WCHAR str[MAX_PATH];

	for (int i=0; i< 5; i++)
	{
		initPos[i].y = CurveFunc(initPos[i].x, cofA1, cofB1, cofC1, cofD1, cofE1);

		D3DXVECTOR3 iV1 = (1- initPos[i].x) * cornerPos[0] + initPos[i].x * cornerPos[2];
		D3DXVECTOR3 iV2 = (1- initPos[i].x) * cornerPos[1] + initPos[i].x * cornerPos[3];
		btnPos[i] = (1- initPos[i].y) * iV1 + initPos[i].y * iV2; 

		MS3DButton* btn = new MS3DButton(m_pDevice, this);
		btn->Scale(D3DXVECTOR3(0.05, 0.05, 1));
		btn->Translate(btnPos[i]);

		m_pTTSButtons.push_back(btn);

		btn->Bind(L"WM_LBUTTONDOWN\0", (IEventManager::TaskFuncPtr)ImTubeDisplay::onTTSButtonLDown, this);
		btn->Bind(L"WM_LBUTTONUP\0", (IEventManager::TaskFuncPtr)ImTubeDisplay::onTTSButtonLUp, this);
		btn->Bind(L"WM_MOUSEDRAGMOVE\0", (IEventManager::TaskFuncPtr)ImTubeDisplay::onTTSButtonDragMove, this);
	}

	for (int i=5; i< 10; i++)
	{
		initPos[i].y = CurveFunc(initPos[i].x, cofA2, cofB2, cofC2, cofD2, cofE2);

		D3DXVECTOR3 iV1 = (1- initPos[i].x) * cornerPos[0] + initPos[i].x * cornerPos[2];
		D3DXVECTOR3 iV2 = (1- initPos[i].x) * cornerPos[1] + initPos[i].x * cornerPos[3];
		btnPos[i] = (1- initPos[i].y) * iV1 + initPos[i].y * iV2; 

		MS3DButton* btn = new MS3DButton(m_pDevice, this);
		btn->Scale(D3DXVECTOR3(0.05, 0.05, 1));
		btn->Translate(btnPos[i]);

		m_pTTSButtons.push_back(btn);

		btn->Bind(L"WM_LBUTTONDOWN\0", (IEventManager::TaskFuncPtr)ImTubeDisplay::onTTSButtonLDown, this);
		btn->Bind(L"WM_LBUTTONUP\0", (IEventManager::TaskFuncPtr)ImTubeDisplay::onTTSButtonLUp, this);
		btn->Bind(L"WM_MOUSEDRAGMOVE\0", (IEventManager::TaskFuncPtr)ImTubeDisplay::onTTSButtonDragMove, this);
	}

	for (int i=10; i< 15; i++)
	{
		initPos[i].x = CurveFunc(initPos[i].x, cofAx, cofBx, cofCx, cofDx, cofEx);

		D3DXVECTOR3 iV1 = (1- initPos[i].x) * cornerPos[0] + initPos[i].x * cornerPos[2];
		D3DXVECTOR3 iV2 = (1- initPos[i].x) * cornerPos[1] + initPos[i].x * cornerPos[3];
		btnPos[i] = (1- initPos[i].y) * iV1 + initPos[i].y * iV2; 

		MS3DButton* btn = new MS3DButton(m_pDevice, this);
		btn->Scale(D3DXVECTOR3(0.05, 0.05, 1));
		btn->Translate(btnPos[i]);

		m_pTTSButtons.push_back(btn);

		btn->Bind(L"WM_LBUTTONDOWN\0", (IEventManager::TaskFuncPtr)ImTubeDisplay::onTTSButtonLDown, this);
		btn->Bind(L"WM_LBUTTONUP\0", (IEventManager::TaskFuncPtr)ImTubeDisplay::onTTSButtonLUp, this);
		btn->Bind(L"WM_MOUSEDRAGMOVE\0", (IEventManager::TaskFuncPtr)ImTubeDisplay::onTTSButtonDragMove, this);
	}
	return TRUE;
}


BOOL ImTubeDisplay::ClearTTSButtons()
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

BOOL ImTubeDisplay::Render()
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

			//hr = m_pDevice->SetTextureStageState( 0, D3DTSS_TEXTURETRANSFORMFLAGS, 
			//	D3DTTFF_COUNT3 | D3DTTFF_PROJECTED );
			//hr = m_pDevice->GetTransform(D3DTS_TEXTURE0, &backupMat);
			//hr = m_pDevice->SetTransform(D3DTS_TEXTURE0, &m_matTTS);
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


BOOL ImTubeDisplay::Render(IDirect3DBaseTexture9* pTexture)
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

BOOL ImTubeDisplay::Render(IDirect3DBaseTexture9* pTexture, ID3DXEffect* pEffect)
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
		hr = pEffect->SetFloat("g_tCurveCofA", cofA1);
		hr = pEffect->SetFloat("g_tCurveCofB", cofB1);
		hr = pEffect->SetFloat("g_tCurveCofC", cofC1);
		hr = pEffect->SetFloat("g_tCurveCofD", cofD1);
		hr = pEffect->SetFloat("g_tCurveCofE", cofE1);

		hr = pEffect->SetFloat("g_bCurveCofA", cofA2);
		hr = pEffect->SetFloat("g_bCurveCofB", cofB2);
		hr = pEffect->SetFloat("g_bCurveCofC", cofC2);
		hr = pEffect->SetFloat("g_bCurveCofD", cofD2);
		hr = pEffect->SetFloat("g_bCurveCofE", cofE2);

		hr = pEffect->SetFloat("g_xCurveCofA", cofAx);
		hr = pEffect->SetFloat("g_xCurveCofB", cofBx);
		hr = pEffect->SetFloat("g_xCurveCofC", cofCx);
		hr = pEffect->SetFloat("g_xCurveCofD", cofDx);
		hr = pEffect->SetFloat("g_xCurveCofE", cofEx);

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


BOOL ImTubeDisplay::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
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

ID3DXEffect* ImTubeDisplay::GetEffect()
{
	if (m_pEffect == NULL)
	{
		DWORD dwShaderFlags = D3DXFX_NOT_CLONEABLE ;

		WCHAR str[MAX_PATH] = {0};
		GetCurrentDirectory(MAX_PATH,str);
		swprintf_s(str, MAX_PATH, L"%s\\..\\fx\\ImHookRenderforTubeWarp.fx", str);
		HRESULT hr = D3DXCreateEffectFromFileW( m_pDevice, str, NULL, NULL, dwShaderFlags, NULL, &m_pEffect, NULL );
		if (FAILED(hr))
		{
			OutputDebugStringW(L"@@@@ D3DXCreateEffectFromFileW Failed in MS3DDisplay::GetEffect()\n");
			return NULL;
		}
	}
	return m_pEffect;
}

BOOL ImTubeDisplay::onTTSButtonLDown(void* _THIS, WPARAM wParam, LPARAM lParam, void* pData)
{
	OutputDebugStringW(L"@@@@ onTTSButtonLDown \n");
	((ImTubeDisplay*)_THIS)->m_bStartDrag = TRUE;

	return TRUE;
}

BOOL ImTubeDisplay::onTTSButtonLUp(void* _THIS, WPARAM wParam, LPARAM lParam, void* pData)
{
	OutputDebugStringW(L"@@@@ onTTSButtonLUp \n");
	((ImTubeDisplay*)_THIS)->m_bStartDrag = FALSE;
	return TRUE;
}

BOOL ImTubeDisplay::onTTSButtonDragMove(void* _THIS, WPARAM wParam, LPARAM lParam, void* pData)
{
	//OutputDebugStringW(L"@@@@ onTTSButtonDragMove \n");

	if (((ImTubeDisplay*)_THIS)->m_bStartDrag)
	{
		MS3DButton* pbutton =((MS3DButton*)((MSEventManager*)pData));
		int index = -1;
		for (int i =0; i < ((ImTubeDisplay*)_THIS)->m_pTTSButtons.size(); i++)
		{
			if (pbutton == ((ImTubeDisplay*)_THIS)->m_pTTSButtons.at(i))
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

		((ImTubeDisplay*)_THIS)->m_pCamera->Screen2World(((ImTubeDisplay*)_THIS)->m_hDisplayWnd, xPos, yPos, vPos, vDir);

		D3DXVECTOR3 prePos = pbutton->GetPosition();
		D3DXVECTOR3 newPos(vPos.x, vPos.y, prePos.z);

		BOOL bHit = FALSE;
		float tU, tV = 0;
		((ImTubeDisplay*)_THIS)->IntersectWithPlane(vPos, vDir, bHit, tU, tV);
		if (bHit)
		{
			pbutton->SetPosition(newPos);
			((ImTubeDisplay*)_THIS)->UpdateTTSByTTSButtons();
		}
	}
	return TRUE;
}


float ImTubeDisplay::CurveFunc(float Xin, float cofA, float cofB, float cofC, 
							   float cofD, float cofE)
{
	return cofA*Xin*Xin*Xin*Xin + cofB*Xin*Xin*Xin + cofC*Xin*Xin + 
		cofD*Xin + cofE;
}
void ImTubeDisplay::SolveCurve(D3DXVECTOR2 v1, D3DXVECTOR2 v2,D3DXVECTOR2 v3,D3DXVECTOR2 v4, D3DXVECTOR2 v5,
							   float& cofA, float& cofB, float& cofC, float& cofD, float& cofE) 
{

	CvMat* matA = cvCreateMat(5, 5, CV_32FC1);
	CvMat* matX = cvCreateMat(5, 1, CV_32FC1);
	CvMat* matB = cvCreateMat(5, 1, CV_32FC1);
	D3DXVECTOR2 pt[5] = {v1, v2, v3, v4, v5};
	for (int row = 0 ; row < 5; row++)
	{
		matB->data.fl[row] = pt[row].y;
		matX->data.fl[row] = 0;
		for (int col = 0; col < 5; col ++)
		{
			matA->data.fl[row*5 + col] = pow(pt[row].x, 5-col-1);
		}
	}
	if (cvSolve(matA, matB, matX, CV_LU))
	{
		cofA = matX->data.fl[0];
		cofB = matX->data.fl[1];
		cofC = matX->data.fl[2];
		cofD = matX->data.fl[3];
		cofE = matX->data.fl[4];
	}
	cvReleaseMat(&matA);
	cvReleaseMat(&matB);
	cvReleaseMat(&matX);
	return;
}
BOOL ImTubeDisplay::ComputeTTSCurve(const D3DXVECTOR2& v1, const D3DXVECTOR2& v2, const D3DXVECTOR2& v3, const D3DXVECTOR2& v4, const D3DXVECTOR2& v5,
									float& cofA,float& cofB, float& cofC, float& cofD, float& cofE)
{

	SolveCurve(v1,v2,v3,v4,v5, cofA, cofB, cofC, cofD, cofE);

	return TRUE;
}

BOOL ImTubeDisplay::UpdateTTSByTTSButtons()
{
	if (m_pTTSButtons.size() != 15)
		return FALSE;
	D3DXVECTOR2 pt[15] = {D3DXVECTOR2(0,0)};
	float tmp[5] = { 0, 0.25, 0.5, 0.75, 1}; 
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
		if (i >= 10)
		{
			pt[i] = D3DXVECTOR2( pt[i].x, tmp[i-10]);
		}
	}
	WCHAR str[MAX_PATH];
	ComputeTTSCurve(pt[0], pt[1], pt[2], pt[3], pt[4], cofA1, cofB1, cofC1, cofD1, cofE1);
	ComputeTTSCurve(pt[5], pt[6], pt[7], pt[8], pt[9], cofA2, cofB2, cofC2, cofD2, cofE2);

	ComputeTTSCurve(pt[10], pt[11], pt[12], pt[13], pt[14], cofAx, cofBx, cofCx, cofDx, cofEx);

	return TRUE;
}
