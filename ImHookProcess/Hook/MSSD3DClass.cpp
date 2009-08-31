#include "MSSD3DClass.h"


MS3DObj::MS3DObj()
{
	D3DXCreateMatrixStack(0, &m_pMatrixStack);
	m_pMatrixStack->LoadIdentity();
}
MS3DObj::~MS3DObj()
{
	if (m_pMatrixStack != NULL)
	{
		m_pMatrixStack->Release();
		m_pMatrixStack = NULL;
	}
}
D3DXMATRIX MS3DObj::GetTransform()
{
	return *m_pMatrixStack->GetTop();
}
BOOL MS3DObj::Translate(D3DXVECTOR3& t)
{
	m_pMatrixStack->Translate(t.x, t.y, t.z);
	return TRUE;
}
BOOL MS3DObj::RotateAxis(CONST D3DXVECTOR3 * pV, FLOAT angle)
{
	m_pMatrixStack->RotateAxis(pV, angle);
	return TRUE;
}
BOOL MS3DObj::Scale(D3DXVECTOR3& s)
{
	m_pMatrixStack->Scale(s.x, s.y, s.z);
	return TRUE;
}
BOOL MS3DObj::ResetTransform()
{
	m_pMatrixStack->LoadIdentity();
	return TRUE;
}
BOOL MS3DObj::PushMatrix()
{
	m_pMatrixStack->Push();
	return TRUE;
}
BOOL MS3DObj::PopMatrix()
{
	m_pMatrixStack->Pop();
	return TRUE;
}

//////////MSMeshBase//////////////
MSMeshBase::MSMeshBase()
{
	m_pDevice = NULL;
	m_pMesh = NULL;
	m_color = D3DCOLOR_ARGB(255,255,255,255);
}
MSMeshBase::MSMeshBase(IDirect3DDevice9* pDevice) : MSDXBase(pDevice)
{
	m_pMesh = NULL;
	m_color = D3DCOLOR_ARGB(255,255,255,255);
}

MSMeshBase::~MSMeshBase()
{
	if (m_pMesh != NULL)
	{
		m_pMesh->Release();
		m_pMesh = NULL;
	}
}

IDirect3DVertexBuffer9* MSMeshBase::GetVertexBuffer()
{
	if (m_pMesh == NULL)
		return NULL;
	IDirect3DVertexBuffer9* ret = NULL;
	if (FAILED(m_pMesh->GetVertexBuffer(&ret)))
		return NULL;
	return ret;
}
IDirect3DIndexBuffer9* MSMeshBase::GetIndexBuffer()
{
	if (m_pMesh == NULL)
		return NULL;
	IDirect3DIndexBuffer9* ret = NULL;
	if (FAILED(m_pMesh->GetIndexBuffer(&ret)))
		return NULL;
	return ret;
}
UINT MSMeshBase::GetVertexNumber()
{	
	if (m_pMesh == NULL)
	{
		return 0;
	}
	return m_pMesh->GetNumVertices();
}

UINT MSMeshBase::GetPrimitiveNumber()
{
	if (m_pMesh == NULL)
	{
		return 0;
	}
	return m_pMesh->GetNumFaces();
}

BOOL MSMeshBase::Render(IDirect3DBaseTexture9* pTexture)
{
	if (m_pDevice == NULL) 
		return FALSE;
	HRESULT hr;
	hr = m_pDevice->SetTextureStageState(0, D3DTSS_CONSTANT, m_color );
	hr = m_pDevice->SetTexture(0, pTexture);
	hr = m_pMesh->DrawSubset(0);
	hr = m_pDevice->SetTexture(0, NULL);
	hr = m_pDevice->SetTextureStageState(0, D3DTSS_CONSTANT, 0xffffffff);
	return TRUE;
}
BOOL MSMeshBase::Render()
{
	if (m_pDevice == NULL) 
		return FALSE;
	HRESULT hr;
	hr = m_pDevice->SetTextureStageState(0, D3DTSS_CONSTANT, m_color );
	hr = m_pMesh->DrawSubset(0);
	hr = m_pDevice->SetTextureStageState(0, D3DTSS_CONSTANT, 0xffffffff);
	return TRUE;
}



MS3DPlane::MS3DPlane(IDirect3DDevice9* pDevice) : MSMeshBase(pDevice)
{
	InitGeometry();
}
MS3DPlane::~MS3DPlane()
{
	
}
BOOL MS3DPlane::InitGeometry()
{
	HRESULT hr;
	if (m_pMesh != NULL)
	{
		m_pMesh->Release();
		m_pMesh = NULL;
	}
	hr = D3DXCreateMeshFVF(2,4, D3DXMESH_32BIT | D3DXMESH_VB_MANAGED | D3DXMESH_IB_MANAGED, 
		D3DFVF_XYZ|D3DFVF_NORMAL|D3DFVF_TEX1, m_pDevice, &m_pMesh);
	if (FAILED(hr))
	{
		OutputDebugStringW(L"@@@@ InitGeometry D3DXCreateMeshFVF Failed in MS3DPlane!!\n");
		return FALSE;
	}
	IDirect3DVertexBuffer9* pVertexBuffer = NULL;
	m_pMesh->GetVertexBuffer(&pVertexBuffer);
	CUSTOMVERTEX* pVertices = NULL;

	if( FAILED( pVertexBuffer->Lock( 0, 0, (void**)&pVertices, 0 ) ) )
		return FALSE;
	pVertices[0].position = D3DXVECTOR3(-0.5, 0.5, 0);
	pVertices[1].position = D3DXVECTOR3(-0.5, -0.5, 0);
	pVertices[2].position = D3DXVECTOR3(0.5, -0.5, 0);
	pVertices[3].position = D3DXVECTOR3(0.5, 0.5, 0);

	pVertices[0].normal = D3DXVECTOR3(0, 0, -1);
	pVertices[1].normal = D3DXVECTOR3(0, 0, -1);
	pVertices[2].normal = D3DXVECTOR3(0, 0, -1);
	pVertices[3].normal = D3DXVECTOR3(0, 0, -1);

	pVertices[0].tu = 0;	pVertices[0].tv = 0;
	pVertices[1].tu = 0;    pVertices[1].tv = 1;
	pVertices[2].tu = 1;	pVertices[2].tv = 1;
	pVertices[3].tu = 1;    pVertices[3].tv = 0;
	pVertexBuffer->Unlock();

	IDirect3DIndexBuffer9* pIndexBuffer = NULL;
	m_pMesh->GetIndexBuffer(&pIndexBuffer);

	UINT* pIndex = NULL;
	if (FAILED(pIndexBuffer->Lock(0, 0, (void**)&pIndex, 0)))
		return FALSE;

	pIndex[0] = 0;	pIndex[1] = 1;  pIndex[2] = 3;
	pIndex[3] = 3;  pIndex[4] = 1;  pIndex[5] = 2;

	pIndexBuffer->Unlock();
	return TRUE;

}

BOOL MS3DPlane::Render()
{
	D3DXMATRIX preMatWorld;
	m_pDevice->GetTransform(D3DTS_WORLD, &preMatWorld);
	m_pDevice->SetTransform(D3DTS_WORLD, &this->GetTransform());
	MSMeshBase::Render();
	m_pDevice->SetTransform(D3DTS_WORLD, &preMatWorld);
	return TRUE;
}
BOOL MS3DPlane::Render(IDirect3DBaseTexture9* pTexture)
{
	HRESULT hr;
	D3DXMATRIX preMatWorld;
	hr = m_pDevice->GetTransform(D3DTS_WORLD, &preMatWorld);
	hr = m_pDevice->SetTransform(D3DTS_WORLD, &this->GetTransform());
	MSMeshBase::Render(pTexture);
	hr = m_pDevice->SetTransform(D3DTS_WORLD, &preMatWorld);
	return TRUE;
}

MSCamera::MSCamera() : MSDXBase()
{
	init();
}
MSCamera::MSCamera(IDirect3DDevice9* pDevice) : MSDXBase(pDevice)
{
	init();
}
MSCamera::~MSCamera()
{

}
BOOL MSCamera::init()
{
	m_vEyePt = D3DXVECTOR3(0,0,-5);
	m_vLookatPt = D3DXVECTOR3(0,0,0);
	m_vUpVec = D3DXVECTOR3(0,1,0);
	m_l = -1;//		[in] Minimum x-value of view volume. 
	m_r = 1;//		[in] Maximum x-value of view volume. 
	m_b = -1;//		[in] Minimum y-value of view volume. 
	m_t = 1;//   	[in] Maximum y-value of view volume. 
	m_zn = 0.01;//		[in] Minimum z-value of the view volume. 
	m_zf = 10;//		[in] Maximum z-value of the view volume. 

	return TRUE;
}
BOOL MSCamera::SetEyePos(D3DXVECTOR3& vEyePt)
{
	m_vEyePt = vEyePt;
	return TRUE;
}
BOOL MSCamera::SetLookAt(D3DXVECTOR3& vLookPt)
{
	m_vLookatPt = vLookPt;
	return TRUE;
}
BOOL MSCamera::SetUpVec(D3DXVECTOR3& vUpVec)
{
	m_vUpVec = vUpVec;
	return TRUE;
}

D3DXVECTOR3 MSCamera::GetEyePos() 
{ 
	return m_vEyePt;
}
D3DXVECTOR3 MSCamera::GetLookAt() 
{ 
	return m_vLookatPt;
}
D3DXVECTOR3 MSCamera::GetUpVec() 
{ 
	return m_vUpVec; 
}

BOOL MSCamera::CameraOn()
{
	D3DXMATRIX matView;
	D3DXMatrixLookAtLH( &matView, &m_vEyePt, &m_vLookatPt, &m_vUpVec );
	m_pDevice->GetTransform(D3DTS_VIEW, &m_BackupMatView);
	m_pDevice->SetTransform(D3DTS_VIEW, &matView);

	D3DXMATRIXA16 matProj;
	D3DXMatrixOrthoOffCenterLH( &matProj, m_l, m_r, m_b, m_t, m_zn, m_zf );
	m_pDevice->GetTransform(D3DTS_PROJECTION, &m_BackupMatProj);
	m_pDevice->SetTransform( D3DTS_PROJECTION, &matProj );
	return TRUE;
}
BOOL MSCamera::CameraOff()
{
	m_pDevice->SetTransform(D3DTS_VIEW, &m_BackupMatView);
	m_pDevice->SetTransform(D3DTS_PROJECTION, &m_BackupMatProj);
	return TRUE;
}
BOOL MSCamera::Screen2World(int x, int y, D3DXVECTOR3& vPos, D3DXVECTOR3& vDir)
{
	D3DXMATRIX matView, matInvView;
	D3DXMatrixLookAtLH( &matView, &m_vEyePt, &m_vLookatPt, &m_vUpVec );
	D3DXMATRIXA16 matProj, matInvProj;
	D3DXMatrixOrthoOffCenterLH( &matProj, m_l, m_r, m_b, m_t, m_zn, m_zf );

	D3DXMatrixInverse(&matInvView,NULL, &matView);
	D3DXMatrixInverse(&matInvProj,NULL, &matProj);
	
	D3DVIEWPORT9 viewport;
	m_pDevice->GetViewport(&viewport);
	D3DXVECTOR4 screenPt(x, y, 0, 1);
	D3DXVECTOR4 projPt(0,0,0,1);
	projPt.x = (screenPt.x/viewport.Width - 0.5) * (m_r - m_l);
	projPt.y = -(screenPt.y/viewport.Height - 0.5) * (m_t - m_b);
	
	D3DXVECTOR4 viewPt(0,0,0,0);
	D3DXVECTOR4 worldPt(0,0,0,0);
	D3DXVec4Transform(&viewPt, &projPt, &matInvProj );
	D3DXVec4Transform(&worldPt, &viewPt, &matInvView);
	
	WCHAR str[MAX_PATH];
	swprintf_s(str, MAX_PATH, L"@@@@@ worldPt: %f, %f, %f \n", worldPt.x, worldPt.y, worldPt.z);
	OutputDebugStringW(str);
	
	vPos = D3DXVECTOR3(worldPt.x, worldPt.y, worldPt.z);
	D3DXVec3Normalize(&vDir , &(m_vLookatPt - m_vEyePt));


	return TRUE;
}


MS3DDisplay::MS3DDisplay(HWND hWnd, IDirect3D9* pD3D)
{
	m_hDisplayWnd = hWnd;
	m_pD3D = pD3D;
	m_pD3D->AddRef();
	m_hRenderThread = 0;
	m_pTexture = NULL;
	m_bEditWarp = FALSE;
	InitDevice();
	SetEditWarpEnable(TRUE);
}
MS3DDisplay::~MS3DDisplay()
{
	if (m_hRenderThread != 0)
	{
		SuspendThread(m_hRenderThread);
		CloseHandle(m_hRenderThread);
		m_hRenderThread = 0;
	}
	if (m_pDisplayPlane != NULL)
	{
		delete m_pDisplayPlane;
		m_pDisplayPlane == NULL;
	}
	ClearWarpButtons();
	if (m_pTexture != NULL)
	{
		m_pTexture->Release();
		m_pTexture = NULL;
	}
	if (m_pCamera != NULL)
	{
		delete m_pCamera;
		m_pCamera = NULL;
	}
	if (m_pD3D != NULL)
	{
		m_pD3D->Release();
		m_pD3D = NULL;
	}
	

}

BOOL MS3DDisplay::Run()
{
	if (m_hRenderThread != 0)
	{
		OutputDebugStringW(L"@@@@ hRenderThread != 0 in MS3DDisplay::Run \n");
		return FALSE;
	}
	HANDLE hThread = 0;
	DWORD threadID = 0;
	hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)MS3DDisplay::_Run, (void*)this, CREATE_SUSPENDED, &threadID);
	if (hThread == NULL)
	{
		OutputDebugStringW(L"@@@@@ CreateThread Failed in MS3DDisplay::Run()!! \n");
		return FALSE;
	}
	m_hRenderThread = hThread;
	ResumeThread(m_hRenderThread);
	OutputDebugStringW(L"@@@@@ MS3DDisplay::Render Thread Created!! \n");
	return TRUE;
}
BOOL MS3DDisplay::_Run(void* _THIS)
{
	MSG msg; 
	ZeroMemory( &msg, sizeof(msg) );
	while( msg.message!=WM_QUIT )
	{
		if( PeekMessage( &msg, NULL, 0U, 0U, PM_REMOVE ) )
		{
			TranslateMessage( &msg );
			DispatchMessage( &msg );
		}
		else
		{
			((MS3DDisplay*)_THIS)->Render();
		}
	}
	((MS3DDisplay*)_THIS)->m_hRenderThread = 0;
	return TRUE;
}
BOOL MS3DDisplay::Stop()
{
	if (m_hRenderThread)
	{
		CloseHandle(m_hRenderThread);
	}
	m_hRenderThread = 0;
	return TRUE;
}


BOOL MS3DDisplay::InitDevice()
{
	if (m_pD3D == NULL)
	{
		return FALSE;
	}
	// Set up the structure used to create the D3DDevice. Since we are now
	// using more complex geometry, we will create a device with a zbuffer.
	D3DPRESENT_PARAMETERS d3dpp; 
	ZeroMemory( &d3dpp, sizeof(d3dpp) );
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	d3dpp.EnableAutoDepthStencil = TRUE;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;

	// Create the D3DDevice
	if( FAILED( m_pD3D->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, m_hDisplayWnd,
		D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dpp, &m_pDevice )))
	{
		OutputDebugStringW(L"@@@@ CreateDevice Failed!! in MS3DDisplay::InitDevice() \n");
		return FALSE;
	}

	// Turn on the zbuffer
	m_pDevice->SetRenderState( D3DRS_ZENABLE, TRUE );
	// Turn on ambient lighting 
	m_pDevice->SetRenderState( D3DRS_AMBIENT, 0xffffffff );
	m_pDevice->SetRenderState( D3DRS_CULLMODE, D3DCULL_CW);


	m_pDevice->SetTextureStageState(0, D3DTSS_CONSTANT, 0xfffffffff );
	m_pDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);
	m_pDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_CONSTANT);
	m_pDevice->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_TEXTURE);
	m_pDevice->SetTextureStageState(1, D3DTSS_COLOROP, D3DTOP_DISABLE);

	m_pDisplayPlane = new MS3DPlane(m_pDevice);
	m_pCamera = new MSCamera(m_pDevice);
	CreateTexture();
	return TRUE;
}

BOOL MS3DDisplay::CreateTexture()
{
	if (m_hDisplayWnd == NULL || m_pDevice == NULL)
	{
		return FALSE;
	}
	if (m_pTexture != NULL)
	{
		m_pTexture->Release();
		m_pTexture = NULL;
	}
	HRESULT hr;
	RECT rect;
	GetClientRect(m_hDisplayWnd, &rect);

	hr = D3DXCreateTexture(m_pDevice, rect.right- rect.left, rect.bottom - rect.top, 1, D3DUSAGE_RENDERTARGET,
		D3DFMT_A8R8G8B8, D3DPOOL_DEFAULT, &m_pTexture);
	if (FAILED(hr))
	{
		OutputDebugStringW(L"@@@@@ D3DXCreateTexture Failed in MS3DDisplay::CreateTexture()!! \n");
		return FALSE;
	}

	
	IDirect3DSurface9* pSurface = NULL;
	IDirect3DSurface9* pBackupSurface = NULL;
	m_pTexture->GetSurfaceLevel(0,&pSurface);
	m_pDevice->GetRenderTarget(0, &pBackupSurface );
	m_pDevice->SetRenderTarget(0, pSurface);
	m_pDevice->Clear( 0, NULL, D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER, 
		D3DCOLOR_XRGB(0,0,255), 1.0f, 0 );
	m_pDevice->SetRenderTarget(0, pBackupSurface);
	pSurface->Release();
	pBackupSurface->Release();
	pSurface = NULL;
	
	return TRUE;
}
BOOL MS3DDisplay::ClearWarpButtons()
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
BOOL MS3DDisplay::CreateWarpButtons()
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
		
		btn->Bind(L"WM_LBUTTONDOWN\0", (IEventManager::TaskFuncPtr)MS3DDisplay::onWarpButtonLDown, this);
		btn->Bind(L"WM_LBUTTONUP\0", (IEventManager::TaskFuncPtr)MS3DDisplay::onWarpButtonLUp, this);
		btn->Bind(L"WM_MOUSEMOVE\0", (IEventManager::TaskFuncPtr)MS3DDisplay::onWarpButtonMouseMove, this);
	}
	pBuffer->Unlock();
	return TRUE;
}

BOOL MS3DDisplay::Render()
{
	m_pDevice->Clear( 0, NULL, D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER, 
		D3DCOLOR_XRGB(50,50,50), 1.0f, 0 );
	m_pCamera->CameraOn();
	if( SUCCEEDED( m_pDevice->BeginScene() ) )
	{
			
		if (m_pDisplayPlane != NULL)
		{	
			m_pDisplayPlane->Render(m_pTexture);
		}
		if (m_bEditWarp)
		{
			m_pDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_SELECTARG1);
			m_pDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
			m_pDisplayPlane->Render();

			for (vector<MS3DButton*>::iterator it = m_pWarpButtons.begin(); it!=m_pWarpButtons.end(); ++it)
			{
				(*it)->Render();
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
BOOL MS3DDisplay::Render(IDirect3DBaseTexture9* pTexture)
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
		if (m_bEditWarp)
		{
			
		}
		m_pDevice->EndScene();
	}
	m_pDevice->Present(NULL,NULL,NULL,NULL);
	m_pCamera->CameraOff();
	return TRUE;
}

BOOL MS3DDisplay::SetEditWarpEnable(BOOL enable)
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

BOOL MS3DDisplay::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	MSEventManager::WndProc( hWnd, message, wParam, lParam);
	if (m_pDevice == NULL)
		return FALSE;
	int xPos, yPos = 0;

	switch (message)
	{
	case WM_LBUTTONDOWN:
	case WM_LBUTTONUP:
	case WM_RBUTTONDOWN:
	case WM_RBUTTONUP:
	case WM_MOUSEMOVE:
		xPos = LOWORD(lParam); 
		yPos = HIWORD(lParam);
		D3DXVECTOR3 vPos(0,0,0), vDir(0,0,0);
		
		WCHAR str[MAX_PATH];
		swprintf_s(str, MAX_PATH, L"@@@@@ MousePos: %d, %d \n", xPos, yPos);
		OutputDebugStringW(str);
		
		if (m_pCamera->Screen2World(xPos,yPos,vPos,vDir))
		{
			if ((xPos == 709) && (yPos == 394))
			{
				int test =0 ;
			}
			PassMouseMessage(message, wParam, lParam, vPos, vDir);
		}
		break;
	}

	return TRUE;
}
BOOL MS3DDisplay::HitTest(D3DXVECTOR3& vPos, D3DXVECTOR3& vDir)
{
	return TRUE;
}

BOOL MS3DDisplay::onWarpButtonLDown(void* _THIS, WPARAM wParam, LPARAM lParam)
{
	OutputDebugStringW(L"@@@@ onWarpButtonLDown \n");
	return TRUE;
}

BOOL MS3DDisplay::onWarpButtonLUp(void* _THIS, WPARAM wParam, LPARAM lParam)
{
	OutputDebugStringW(L"@@@@ onWarpButtonLUp \n");
	return TRUE;
}
BOOL MS3DDisplay::onWarpButtonMouseMove(void* _THIS, WPARAM wParam, LPARAM lParam)
{
	OutputDebugStringW(L"@@@@ onWarpButtonMouseMove \n");
	return TRUE;
}


BOOL IEventManager::SetParent(IEventManager* parent)
{
	if (m_pParent != NULL)
	{
		m_pParent->RemoveChild(this);
	}
	m_pParent = parent;
	if (m_pParent)
		m_pParent->AddChild(this);
	return TRUE;
}

BOOL IEventManager::AddChild(IEventManager* child)
{
	for (vector<IEventManager*>::iterator it =m_Children.begin(); it != m_Children.end(); ++it)
	{
		if ((*it) == child)
		{
			return TRUE;
		}
	}
	m_Children.push_back(child);
	return TRUE;
}

BOOL IEventManager::RemoveChild(IEventManager* child)
{
	for (vector<IEventManager*>::iterator it =m_Children.begin(); it != m_Children.end(); ++it)
	{
		if ((*it) == child)
		{
			m_Children.erase(it);
		}
		return TRUE;
	}
	return FALSE;
}

MSEventManager::MSEventManager(IEventManager* parent)
{
	SetParent(parent);
}

MSEventManager::~MSEventManager()
{

}

BOOL MSEventManager::HitTest(D3DXVECTOR3& vPos, D3DXVECTOR3& vDir) 
{  
	/*need to be overwrite */ 
	return FALSE;
}
BOOL MSEventManager::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	BOOL ret = FALSE;
	for (vector<IEventManager*>::iterator it =m_Children.begin(); it != m_Children.end(); ++it)
	{
		ret = (*it)->WndProc(hWnd, message, wParam, lParam);
	}

	return TRUE;
}
BOOL MSEventManager::PassMouseMessage(UINT message, WPARAM wParam, LPARAM lParam, D3DXVECTOR3& vPos, D3DXVECTOR3& vDir)
{
	BOOL ret = FALSE;
	if (!HitTest(vPos, vDir))
	{
		if (m_bMouseOver)
		{
			m_bMouseOver = FALSE;
			Invoke(L"WM_MOUSELEAVE", NULL, NULL);
		}
		return FALSE;
	}

	for (vector<IEventManager*>::iterator it =m_Children.begin(); it != m_Children.end(); ++it)
	{
		ret = (*it)->PassMouseMessage(message, wParam, lParam, vPos, vDir);
		if (ret)
		{
			if (m_bMouseOver)
			{
				m_bMouseOver = FALSE;
				Invoke(L"WM_MOUSELEAVE", NULL, NULL);
			}
			
			return TRUE;
		}	
	}
	if (!m_bMouseOver)
	{
		m_bMouseOver = TRUE;
		Invoke(L"WM_MOUSEENTER", NULL, NULL);
	}
	switch (message)
	{
		case WM_LBUTTONDOWN:
			this->Invoke(L"WM_LBUTTONDOWN\0", (WPARAM)this, lParam);
			break;
		case WM_LBUTTONUP:
			this->Invoke(L"WM_LBUTTONUP\0", (WPARAM)this, lParam);
			break;
		case WM_MOUSEMOVE:
			this->Invoke(L"WM_MOUSEMOVE\0", (WPARAM)this, lParam);
			break;
	}
	return TRUE;
}
BOOL MSEventManager::Bind( WCHAR* msg, TaskFuncPtr pFunc , void* _THIS)
{
	map<WCHAR*, vector<EventTask>, cmp_wstr>::iterator it = m_EventTable.find(msg);
	if (it == m_EventTable.end())
	{
		vector<EventTask> eventtask;
		m_EventTable[msg] = eventtask;
	}
	EventTask newTask(pFunc, _THIS);
	for (vector<EventTask>::iterator it2 = m_EventTable[msg].begin(); it2 != m_EventTable[msg].end(); ++it2)
	{
		if ((*it2) == newTask)
		{
			return FALSE;
		}
	}
	m_EventTable[msg].push_back(newTask);
	return TRUE;
}
BOOL MSEventManager::UnBind(WCHAR* msg, TaskFuncPtr pFunc, void* _THIS)
{
	map<WCHAR*, vector<EventTask>, cmp_wstr>::iterator it = m_EventTable.find(msg);
	if (it == m_EventTable.end())
	{
		return FALSE;
	}
	EventTask newTask(pFunc, _THIS);
	for (vector<EventTask>::iterator it2 = m_EventTable[msg].begin(); it2 != m_EventTable[msg].end(); ++it2)
	{
		if ((*it2) == newTask)
		{
			m_EventTable[msg].erase(it2);
			return FALSE;
		}
	}
	
	return TRUE;
}
BOOL MSEventManager::Invoke(WCHAR* msg, WPARAM wParam, LPARAM lParam)
{
	map<WCHAR*, vector<EventTask>, cmp_wstr>::iterator it = m_EventTable.find(msg);
	if (it == m_EventTable.end())
	{
		return FALSE;
	}
	for (vector<EventTask>::iterator it2 = m_EventTable[msg].begin(); it2 != m_EventTable[msg].end(); ++it2)
	{
		BOOL (__stdcall* pTask)(void*, WPARAM, LPARAM) = (*it2).funcPtr;
		pTask((*it2)._THIS, wParam, lParam);
		return FALSE;
	}
	return TRUE;
}

BOOL MS3DButton::HitTest(D3DXVECTOR3& vPos, D3DXVECTOR3& vDir)
{
	BOOL hit = FALSE;
	DWORD FaceIndex = 0;
	FLOAT U = 0;
	FLOAT V = 0;
	FLOAT Dist = 0;
	LPD3DXBUFFER pAllHits = NULL;
	DWORD CountOfHits = 0;
	HRESULT hr;

	D3DXMATRIX matWorld = GetTransform();
	D3DXMATRIX matInvWorld;
	D3DXMatrixInverse(&matInvWorld, NULL, &matWorld);

	D3DXVECTOR3 tranPos(0,0,0);
	D3DXVECTOR3 tranDir(0,0,0);
	
	D3DXVec3TransformCoord(&tranPos, &vPos, &matInvWorld);
	D3DXVec3TransformNormal(&tranDir, &vDir, &matInvWorld);

	WCHAR str[MAX_PATH];
	swprintf_s(str,MAX_PATH, L"@@@@@ tranPos: %f, %f, %f \n", tranPos.x, tranPos.y, tranPos.z);
	OutputDebugStringW(str);

	hr = D3DXIntersect(m_pMesh, &(D3DXVECTOR3(tranPos.x, tranPos.y, tranPos.z)),
		&(D3DXVECTOR3(tranDir.x, tranDir.y, tranDir.z)), &hit,
		&FaceIndex, &U, &V, &Dist, &pAllHits, &CountOfHits);
	if (hit)
		OutputDebugStringW(L"@@@@@ MS3DButton::HitTest  return True!! \n");
	else
		OutputDebugStringW(L"@@@@@ MS3DButton::HitTest  return False!! \n");
	return hit;
}

BOOL MS3DButton::OnMouseLDown(void* _THIS, WPARAM wParam, LPARAM lParam)
{
	return TRUE;
}
BOOL MS3DButton::OnMouseLUp(void* _THIS, WPARAM wParam, LPARAM lParam)
{
	return TRUE;
}
BOOL MS3DButton::OnMouseMove(void* _THIS, WPARAM wParam, LPARAM lParam)
{
	return TRUE;
}
BOOL MS3DButton::OnMouseEnter(void* _THIS, WPARAM wParam, LPARAM lParam)
{
	((MS3DButton*)_THIS)->m_color = D3DCOLOR_ARGB(255,255,0,0);
	return TRUE;
}
BOOL MS3DButton::OnMouseLeave(void* _THIS, WPARAM wParam, LPARAM lParam)
{
	((MS3DButton*)_THIS)->m_color = D3DCOLOR_ARGB(255,255,255,255);
	return FALSE;
}