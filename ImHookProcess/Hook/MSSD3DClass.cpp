#include "MSSD3DClass.h"
#include <cv.h>

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
BOOL MS3DObj::SetPosition(D3DXVECTOR3 pos)
{
	D3DXMATRIX mat = GetTransform();
	mat.m[3][0] = pos.x;
	mat.m[3][1] = pos.y;
	mat.m[3][2] = pos.z;
	m_pMatrixStack->LoadMatrix(&mat);
	
	return TRUE;
}

D3DXVECTOR3 MS3DObj::GetPosition()
{
	D3DXMATRIX mat = GetTransform();
	D3DXVECTOR3 ret(0,0,0);
	ret.x = mat.m[3][0];
	ret.y = mat.m[3][1];
	ret.z = mat.m[3][2];
	return ret;
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

BOOL MSMeshBase::GetVertex(UINT idx, MSMeshBase::CUSTOMVERTEX& vertex)
{
	IDirect3DVertexBuffer9* pVertexBuffer = GetVertexBuffer();
	if (pVertexBuffer == NULL)
		return FALSE;
	if (idx >= m_pMesh->GetNumVertices())
		return FALSE;

	CUSTOMVERTEX* pData = NULL;
	pVertexBuffer->Lock(0, 0, (void**)&pData, D3DLOCK_READONLY);
	vertex = pData[idx];
	pVertexBuffer->Unlock();
	return TRUE;
}

BOOL MSMeshBase::SetVertex(UINT idx, MSMeshBase::CUSTOMVERTEX& vertex)
{
	IDirect3DVertexBuffer9* pVertexBuffer = GetVertexBuffer();
	if (pVertexBuffer == NULL)
		return FALSE;
	if (idx >= m_pMesh->GetNumVertices())
		return FALSE;

	CUSTOMVERTEX* pData = NULL;
	pVertexBuffer->Lock(0, 0, (void**)&pData, 0);
	pData[idx] = vertex;
	pVertexBuffer->Unlock();
	return TRUE;
}

LPD3DXMESH MSMeshBase::GetMesh()
{
	return m_pMesh;
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
	hr = D3DXCreateMeshFVF(4,5, D3DXMESH_32BIT | D3DXMESH_VB_MANAGED | D3DXMESH_IB_MANAGED, 
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
	pVertices[0].position = D3DXVECTOR3(-1, 1, 0);
	pVertices[1].position = D3DXVECTOR3(-1, -1, 0);
	pVertices[2].position = D3DXVECTOR3(1, -1, 0);
	pVertices[3].position = D3DXVECTOR3(1, 1, 0);
	pVertices[4].position = D3DXVECTOR3(0, 0, 0);

	pVertices[0].normal = D3DXVECTOR3(0, 0, -1);
	pVertices[1].normal = D3DXVECTOR3(0, 0, -1);
	pVertices[2].normal = D3DXVECTOR3(0, 0, -1);
	pVertices[3].normal = D3DXVECTOR3(0, 0, -1);
	pVertices[4].normal = D3DXVECTOR3(0, 0, -1);

	pVertices[0].tu = 0;	pVertices[0].tv = 0;
	pVertices[1].tu = 0;    pVertices[1].tv = 1;
	pVertices[2].tu = 1;	pVertices[2].tv = 1;
	pVertices[3].tu = 1;    pVertices[3].tv = 0;
	pVertices[4].tu = 0.5;    pVertices[4].tv = 0.5;
	pVertexBuffer->Unlock();

	IDirect3DIndexBuffer9* pIndexBuffer = NULL;
	m_pMesh->GetIndexBuffer(&pIndexBuffer);

	UINT* pIndex = NULL;
	if (FAILED(pIndexBuffer->Lock(0, 0, (void**)&pIndex, 0)))
		return FALSE;

	pIndex[0] = 0;	pIndex[1] = 1;  pIndex[2] = 4;
	pIndex[3] = 1;  pIndex[4] = 2;  pIndex[5] = 4;
	pIndex[6] = 2;  pIndex[7] = 3;  pIndex[8] = 4;
	pIndex[9] = 3;  pIndex[10] = 0;  pIndex[11] = 4;
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
	matView = GetViewMatrix();
	m_pDevice->GetTransform(D3DTS_VIEW, &m_BackupMatView);
	m_pDevice->SetTransform(D3DTS_VIEW, &matView);
	
	D3DXMATRIXA16 matProj;
	matProj = GetProjMatrix();
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

D3DXMATRIX MSCamera::GetViewMatrix()
{
	D3DXMATRIX matView;
	D3DXMatrixLookAtLH( &matView, &m_vEyePt, &m_vLookatPt, &m_vUpVec );
	return matView;
}

D3DXMATRIX MSCamera::GetProjMatrix()
{
	D3DVIEWPORT9 viewport;
	m_pDevice->GetViewport(&viewport);

	D3DXMATRIX matProj;
	D3DXMatrixOrthoOffCenterLH( &matProj, m_l, m_r, m_b, m_t, m_zn, m_zf );
	return matProj;
}
BOOL MSCamera::Screen2World(HWND hwnd, int x, int y, D3DXVECTOR3& vPos, D3DXVECTOR3& vDir)
{
	D3DXMATRIX matView, matInvView;
	matView = GetViewMatrix();
	D3DXMATRIX matProj, matInvProj;
	matProj = GetProjMatrix();

	D3DXMatrixInverse(&matInvView,NULL, &matView);
	D3DXMatrixInverse(&matInvProj,NULL, &matProj);
	
	D3DVIEWPORT9 viewport;
	m_pDevice->GetViewport(&viewport);
	D3DXVECTOR4 screenPt(x, y, 0, 1);
	D3DXVECTOR4 projPt(0,0,0,1);
	RECT wrect;
	GetClientRect(hwnd, &wrect);
	projPt.x = (screenPt.x/(wrect.right - wrect.left) - 0.5) * (m_r - m_l);
	projPt.y = -(screenPt.y/(wrect.bottom - wrect.top) - 0.5) * (m_t - m_b);
	
	
	D3DXVECTOR4 viewPt(0,0,0,0);
	D3DXVECTOR4 worldPt(0,0,0,0);
	D3DXVec4Transform(&viewPt, &projPt, &matInvProj );
	D3DXVec4Transform(&worldPt, &viewPt, &matInvView);
	
	vPos = D3DXVECTOR3(worldPt.x, worldPt.y, worldPt.z);
	D3DXVec3Normalize(&vDir , &(m_vLookatPt - m_vEyePt));
	
	//swprintf_s(str, MAX_PATH, L"@@@@ Screen2World: x = %d, y = %d, \n@@@@ vPos = %.2f, %.2f, %.2f, vDir = %.2f, %.2f, %.2f \n", 
	//	x, y, vPos.x, vPos.y, vPos.z, vDir.x, vDir.y, vDir.z);
	//OutputDebugStringW(str);
    
	return TRUE;
}


MS3DDisplay::MS3DDisplay(HWND hWnd, IDirect3D9* pD3D) : MSEventManager(NULL), MSDXBase(NULL)
{
	m_hDisplayWnd = hWnd;
	m_pD3D = pD3D;
	m_pD3D->AddRef();
	m_hRenderThread = 0;
	m_pRenderTarget = NULL;
	m_pMaskTexture = NULL;
	m_bEditWarp = FALSE;
	m_bEditTTS = FALSE;
	m_bStartDrag = FALSE;
	m_pRenderTarget = NULL;
	m_pEffect = NULL;
	m_captureRect[0] = D3DXVECTOR2(0,0);
	m_captureRect[1] = D3DXVECTOR2(1,1);
	D3DXMatrixIdentity(&m_matTTS);
	D3DXMatrixIdentity(&m_matMaskTransform);
	InitializeCriticalSection(&m_CS);
	InitDevice();
	CreateTexture();
	//SetEditWarpEnable(TRUE);
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
	ClearTTSButtons();
	if (m_pRenderTarget != NULL)
	{
		m_pRenderTarget->Release();
		m_pRenderTarget = NULL;
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
	DeleteCriticalSection(&m_CS);


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
			//EnterCriticalSection(&(((MS3DDisplay*)_THIS)->m_CS));
			((MS3DDisplay*)_THIS)->Render();
			//LeaveCriticalSection(&(((MS3DDisplay*)_THIS)->m_CS));
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
	HDC dc = GetDC(m_hDisplayWnd);
	int screenW = GetDeviceCaps(dc, HORZRES);
	int screenH = GetDeviceCaps(dc, VERTRES);
	d3dpp.BackBufferWidth = screenW;
	d3dpp.BackBufferHeight = screenH;


	d3dpp.EnableAutoDepthStencil = TRUE;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
	d3dpp.Flags |= D3DPRESENTFLAG_LOCKABLE_BACKBUFFER;

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
	
	return TRUE;
}

BOOL MS3DDisplay::CreateTexture()
{
	if (m_hDisplayWnd == NULL || m_pDevice == NULL)
	{
		return FALSE;
	}
	if (m_pRenderTarget != NULL)
	{
		m_pRenderTarget->Release();
		m_pRenderTarget = NULL;
	}
	HRESULT hr;
	HDC dc = GetDC(m_hDisplayWnd);
	int screenW = GetDeviceCaps(dc, HORZRES);
	int screenH = GetDeviceCaps(dc, VERTRES);

	hr = D3DXCreateTexture(m_pDevice, screenW, screenH, 0, D3DUSAGE_DYNAMIC,
		D3DFMT_X8R8G8B8, D3DPOOL_DEFAULT, &m_pRenderTarget);
	
	if (FAILED(hr))
	{
		OutputDebugStringW(L"@@@@@ D3DXCreateTexture Failed in MS3DDisplay::CreateTexture()!! \n");
		return FALSE;
	}
	

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
		btn->Bind(L"WM_MOUSEDRAGMOVE\0", (IEventManager::TaskFuncPtr)MS3DDisplay::onWarpButtonDragMove, this);
	}
	pBuffer->Unlock();
	return TRUE;
}
BOOL MS3DDisplay::CreateTTSButtons()
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

		btn->Bind(L"WM_LBUTTONDOWN\0", (IEventManager::TaskFuncPtr)MS3DDisplay::onTTSButtonLDown, this);
		btn->Bind(L"WM_LBUTTONUP\0", (IEventManager::TaskFuncPtr)MS3DDisplay::onTTSButtonLUp, this);
		btn->Bind(L"WM_MOUSEDRAGMOVE\0", (IEventManager::TaskFuncPtr)MS3DDisplay::onTTSButtonDragMove, this);
	}
	return TRUE;
}
BOOL MS3DDisplay::ClearTTSButtons()
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

BOOL MS3DDisplay::Render()
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
			hr = m_pDisplayPlane->Render(m_pRenderTarget);

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
BOOL MS3DDisplay::Render(IDirect3DBaseTexture9* pTexture, ID3DXEffect* pEffect)
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
BOOL MS3DDisplay::SetEditTTSEnable(BOOL enable)
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
BOOL MS3DDisplay::SetCaptureRegion(float l, float t, float r, float b)
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
BOOL MS3DDisplay::GetCaptureRegion(float& l, float& t, float& r, float &b)
{
	l = m_captureRect[0].x;
	t = m_captureRect[0].y;
	r = m_captureRect[1].x;
	b = m_captureRect[1].y;
	return TRUE;
}


BOOL MS3DDisplay::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
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
			Render(this->m_pRenderTarget, pEffect);
		else
			Render(this->m_pRenderTarget );
	}
	return ret;
}

BOOL MS3DDisplay::IntersectWithPlane(D3DXVECTOR3 vPos, D3DXVECTOR3 vDir, BOOL& bHit, float& tU, float& tV)
{
	bHit = FALSE;
	DWORD faceIdx = 0;
	float pU, pV = 0;
	float dist = 0;
	DWORD countOfHits = 0;

	LPD3DXBUFFER pBuffer = NULL;
	HRESULT hr;
	
	hr = D3DXIntersect(m_pDisplayPlane->GetMesh(), &vPos, &vDir, &bHit, &faceIdx, &pU, &pV, &dist, &pBuffer,
		&countOfHits);


	if (FAILED(hr))
	{
		return FALSE;
	}
	if (bHit)
	{
		IDirect3DIndexBuffer9* pIndices = m_pDisplayPlane->GetIndexBuffer();
		UINT* pIndex = NULL;
		MSMeshBase::CUSTOMVERTEX pVtx[3];
		pIndices->Lock(0, NULL, (void**)&pIndex, D3DLOCK_READONLY);
		m_pDisplayPlane->GetVertex(pIndex[faceIdx*3], pVtx[0]);
		m_pDisplayPlane->GetVertex(pIndex[faceIdx*3+1], pVtx[1]);
		m_pDisplayPlane->GetVertex(pIndex[faceIdx*3+2], pVtx[2]);
		pIndices->Unlock();
		tU = pVtx[0].tu + pU*(pVtx[1].tu - pVtx[0].tu) + pV*(pVtx[2].tu - pVtx[0].tu);
		tV = pVtx[0].tv + pU*(pVtx[1].tv - pVtx[0].tv) + pV*(pVtx[2].tv - pVtx[0].tv);

	}
	return TRUE;
}							 
ID3DXEffect* MS3DDisplay::GetEffect()
{
	if (m_pEffect == NULL)
	{
		DWORD dwShaderFlags = D3DXFX_NOT_CLONEABLE ;

		WCHAR str[MAX_PATH] = {0};
		GetCurrentDirectory(MAX_PATH,str);
		swprintf_s(str, MAX_PATH, L"%s\\..\\fx\\ImHookRender.fx", str);
		HRESULT hr = D3DXCreateEffectFromFileW( m_pDevice, str, NULL, NULL, dwShaderFlags, NULL, &m_pEffect, NULL );
		if (FAILED(hr))
		{
			OutputDebugStringW(L"@@@@ D3DXCreateEffectFromFileW Failed in MS3DDisplay::GetEffect()\n");
			return NULL;
		}
	}
	return m_pEffect;
}
BOOL MS3DDisplay::HitTest(D3DXVECTOR3& vPos, D3DXVECTOR3& vDir)
{
	return TRUE;
}

BOOL MS3DDisplay::onWarpButtonLDown(void* _THIS, WPARAM wParam, LPARAM lParam, void* pData)
{
	OutputDebugStringW(L"@@@@ onWarpButtonLDown \n");
	((MS3DDisplay*)_THIS)->m_bStartDrag = TRUE;
	
	return TRUE;
}

BOOL MS3DDisplay::onWarpButtonLUp(void* _THIS, WPARAM wParam, LPARAM lParam, void* pData)
{
	OutputDebugStringW(L"@@@@ onWarpButtonLUp \n");
	((MS3DDisplay*)_THIS)->m_bStartDrag = FALSE;
	return TRUE;
}
BOOL MS3DDisplay::onWarpButtonDragMove(void* _THIS, WPARAM wParam, LPARAM lParam, void* pData)
{
	//OutputDebugStringW(L"@@@@ onWarpButtonDragMove \n");
	
	if (((MS3DDisplay*)_THIS)->m_bStartDrag)
	{
		MS3DButton* pbutton =((MS3DButton*)((MSEventManager*)pData));
		int index = -1;
		for (int i =0; i < ((MS3DDisplay*)_THIS)->m_pWarpButtons.size(); i++)
		{
			if (pbutton == ((MS3DDisplay*)_THIS)->m_pWarpButtons.at(i))
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
		
		((MS3DDisplay*)_THIS)->m_pCamera->Screen2World(((MS3DDisplay*)_THIS)->m_hDisplayWnd, xPos, yPos, pos, dir);
		D3DXVECTOR3 prePos = pbutton->GetPosition();
		D3DXVECTOR3 newPos(pos.x, pos.y, prePos.z);
		MSMeshBase::CUSTOMVERTEX vertex;
		((MS3DDisplay*)_THIS)->m_pDisplayPlane->GetVertex(index, vertex);
		vertex.position.x = newPos.x;
		vertex.position.y = newPos.y;
		((MS3DDisplay*)_THIS)->m_pDisplayPlane->SetVertex(index, vertex);
		pbutton->SetPosition(newPos);
	}
	return TRUE;
}


BOOL MS3DDisplay::onTTSButtonLDown(void* _THIS, WPARAM wParam, LPARAM lParam, void* pData)
{
	OutputDebugStringW(L"@@@@ onTTSButtonLDown \n");
	((MS3DDisplay*)_THIS)->m_bStartDrag = TRUE;

	return TRUE;
}

BOOL MS3DDisplay::onTTSButtonLUp(void* _THIS, WPARAM wParam, LPARAM lParam, void* pData)
{
	OutputDebugStringW(L"@@@@ onTTSButtonLUp \n");
	((MS3DDisplay*)_THIS)->m_bStartDrag = FALSE;
	return TRUE;
}
BOOL MS3DDisplay::onTTSButtonDragMove(void* _THIS, WPARAM wParam, LPARAM lParam, void* pData)
{
	//OutputDebugStringW(L"@@@@ onTTSButtonDragMove \n");

	if (((MS3DDisplay*)_THIS)->m_bStartDrag)
	{
		MS3DButton* pbutton =((MS3DButton*)((MSEventManager*)pData));
		int index = -1;
		for (int i =0; i < ((MS3DDisplay*)_THIS)->m_pTTSButtons.size(); i++)
		{
			if (pbutton == ((MS3DDisplay*)_THIS)->m_pTTSButtons.at(i))
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

		((MS3DDisplay*)_THIS)->m_pCamera->Screen2World(((MS3DDisplay*)_THIS)->m_hDisplayWnd, xPos, yPos, vPos, vDir);

		D3DXVECTOR3 prePos = pbutton->GetPosition();
		D3DXVECTOR3 newPos(vPos.x, vPos.y, prePos.z);

		BOOL bHit = FALSE;
		float tU, tV = 0;
		((MS3DDisplay*)_THIS)->IntersectWithPlane(vPos, vDir, bHit, tU, tV);
		if (bHit)
		{
			pbutton->SetPosition(newPos);
			((MS3DDisplay*)_THIS)->UpdateTTSByTTSButtons();
		}
	}
	return TRUE;
}
BOOL MS3DDisplay::SetTTS(const D3DXVECTOR2 v1, const D3DXVECTOR2 v2, const D3DXVECTOR2 v3, const D3DXVECTOR2 v4)
{
	m_matTTS = ComputeTTS(v1, v2, v3, v4);
	return TRUE;
}
D3DXMATRIX MS3DDisplay::ComputeTTS(const D3DXVECTOR2& v1, const D3DXVECTOR2& v2, const D3DXVECTOR2& v3, const D3DXVECTOR2& v4)
{
	WCHAR str[MAX_PATH];
	D3DXMATRIX ret;
	D3DXMatrixIdentity(&ret);
	CvMat cvPt;
	CvMat dstPt;
	swprintf_s(str, MAX_PATH, L"@@@@ v1 = (%.2f, %.2f), v2 = (%.2f, %.2f), v3 = (%.2f, %.2f), v4 = (%.2f, %.2f) \n"
			, v1.x, v1.y, v2.x, v2.y, v3.x, v3.y, v4.x, v4.y);
	OutputDebugStringW(str);
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

	D3DXVECTOR3 testPt[4] ;
	testPt[0] = D3DXVECTOR3(v1.x,v1.y,1);
	testPt[1] = D3DXVECTOR3(v2.x,v2.y,1);
	testPt[2] = D3DXVECTOR3(v3.x,v3.y,1);
	testPt[3] = D3DXVECTOR3(v4.x,v4.y,1);
	D3DXVECTOR4 testout[4] = {D3DXVECTOR4(0,0,0,0)};
	for (int i = 0; i < 4; i++)
	{
		D3DXVec3Transform(&(testout[i]), &(testPt[i]), &m_matTTS); 
		testout[i].x /= testout[i].z;
		testout[i].y /= testout[i].z;
		testout[i].z /= testout[i].z;
		swprintf_s(str, MAX_PATH, L"@@@@ testPt[%d]: (%.2f, %.2f)\n", i,
			testout[i].x, testout[i].y);
		OutputDebugStringW(str);
	}

	swprintf_s(str, MAX_PATH, L"@@@@ %.2f, %.2f, %.2f, %.2f \n@@@@ %.2f, %.2f, %.2f, %.2f \n@@@@ %.2f, %.2f, %.2f, %.2f \n@@@@ %.2f, %.2f, %.2f, %.2f \n",
				ret._11,ret._12,ret._13, ret._14, ret._21, ret._22, ret._23, ret._24, ret._31, ret._32, ret._33, ret._34, 
				ret._41, ret._42, ret._43, ret._44);
	
	OutputDebugStringW(str);
	OutputDebugStringW(L"@@@@@@@@@@@@@@@@@@@@@@");
	return ret;
}
BOOL MS3DDisplay::UpdateTTSByTTSButtons()
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

	if (m_bStargDrag)
	{
		switch (message)
		{
		case WM_LBUTTONUP:
			m_bStargDrag = FALSE;
			break;
		case WM_MOUSEMOVE:
			this->Invoke(L"WM_MOUSEDRAGMOVE\0", wParam, lParam, (void*)this);
			break;
		}
	}

	if (!HitTest(vPos, vDir))
	{
		if (m_bMouseOver)
		{
			m_bMouseOver = FALSE;
			Invoke(L"WM_MOUSELEAVE", NULL, NULL, (void*)this);
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
				Invoke(L"WM_MOUSELEAVE", NULL, NULL, (void*)this);
			}
			
			return TRUE;
		}	
	}
	if (!m_bMouseOver)
	{
		m_bMouseOver = TRUE;
		Invoke(L"WM_MOUSEENTER", NULL, NULL, (void*)this);
	}
	UINT test1, test2, test3, test4;
	switch (message)
	{
		case WM_LBUTTONDOWN:
			this->Invoke(L"WM_LBUTTONDOWN\0", wParam, lParam, (void*)this);
			break;
		case WM_LBUTTONUP:
			this->Invoke(L"WM_LBUTTONUP\0", wParam, lParam, (void*)this);
			break;
		case WM_MOUSEMOVE:
			this->Invoke(L"WM_MOUSEMOVE\0", wParam, lParam, (void*)this);
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
BOOL MSEventManager::Invoke(WCHAR* msg, WPARAM wParam, LPARAM lParam, void* pData)
{
	map<WCHAR*, vector<EventTask>, cmp_wstr>::iterator it = m_EventTable.find(msg);
	if (it == m_EventTable.end())
	{
		return FALSE;
	}
	for (vector<EventTask>::iterator it2 = m_EventTable[msg].begin(); it2 != m_EventTable[msg].end(); ++it2)
	{
		BOOL (__stdcall* pTask)(void*, WPARAM, LPARAM, void*) = (*it2).funcPtr;
		pTask((*it2)._THIS, wParam, lParam, pData);
		
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

	hr = D3DXIntersect(m_pMesh, &(D3DXVECTOR3(tranPos.x, tranPos.y, tranPos.z)),
		&(D3DXVECTOR3(tranDir.x, tranDir.y, tranDir.z)), &hit,
		&FaceIndex, &U, &V, &Dist, &pAllHits, &CountOfHits);

	return hit;
}

BOOL MS3DButton::OnMouseLDown(void* _THIS, WPARAM wParam, LPARAM lParam, void* pData)
{
	((MS3DButton*)_THIS)->m_color = D3DCOLOR_ARGB(255,128,0,0);
	((MS3DButton*)_THIS)->m_bStargDrag = TRUE;
	return TRUE;
}
BOOL MS3DButton::OnMouseLUp(void* _THIS, WPARAM wParam, LPARAM lParam, void* pData)
{
	((MS3DButton*)_THIS)->m_color = D3DCOLOR_ARGB(255,255,0,0);
	return TRUE;
}
BOOL MS3DButton::OnMouseMove(void* _THIS, WPARAM wParam, LPARAM lParam, void* pData)
{
	return TRUE;
}
BOOL MS3DButton::OnMouseEnter(void* _THIS, WPARAM wParam, LPARAM lParam, void* pData)
{
	((MS3DButton*)_THIS)->m_color = D3DCOLOR_ARGB(255,255,0,0);
	return TRUE;
}
BOOL MS3DButton::OnMouseLeave(void* _THIS, WPARAM wParam, LPARAM lParam, void* pData)
{
	((MS3DButton*)_THIS)->m_color = D3DCOLOR_ARGB(255,255,255,255);
	return TRUE;
}

BOOL MS3DButton::OnMouseDragMove(void* _THIS, WPARAM wParam, LPARAM lParam, void* pData)
{
	
	return TRUE;
}

BOOL MS3DDisplay::DrawBitBlt(HDC hdc, int x, int y, int width, int height, int dcW, int dcH, HDC hdcSrc, int x1, int y1, int srcW, int srcH, DWORD rop)
{
	//return TRUE;
	if (m_pRenderTarget == NULL)
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
	m_pRenderTarget->GetSurfaceLevel(0, &pSurface);
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
		Render(this->m_pRenderTarget, pEffect);
	else
		Render(this->m_pRenderTarget );
	
	return TRUE;
}
BOOL MS3DDisplay::LoadMaskTextureFromFile(WCHAR* path)
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
BOOL MS3DDisplay::SetMaskPos(float tx, float ty, float sx, float sy)
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