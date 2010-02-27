#include "MSSD3DClass.h"
#include <math.h>
#include <algorithm>

extern HMODULE GetModule();

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

HRESULT MS3DObj::SetTransform(const D3DXMATRIX* mat)
{
	return m_pMatrixStack->LoadMatrix(mat);
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
	if (m_pDevice == NULL || m_pMesh == NULL) 
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
	hr = D3DXCreateMeshFVF(4,4, D3DXMESH_32BIT | D3DXMESH_VB_MANAGED | D3DXMESH_IB_MANAGED, 
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
	HRESULT hr;
	D3DXMATRIX preMatWorld;
	
	m_pDevice->GetTransform(D3DTS_WORLD, &preMatWorld);
	hr = m_pDevice->SetTransform(D3DTS_WORLD, &this->GetTransform() );
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

	m_fovy = D3DX_PI/2;
	m_aspect = 4.0/3.0;

	m_zn = 1;//		[in] Minimum z-value of the view volume. 
	m_zf = 1000;//		[in] Maximum z-value of the view volume. 

	m_projType = Ortho;
	m_coordType = LEFTHAND;
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
	if (m_coordType == LEFTHAND)
		D3DXMatrixLookAtLH( &matView, &m_vEyePt, &m_vLookatPt, &m_vUpVec );
	else
		D3DXMatrixLookAtRH( &matView, &m_vEyePt, &m_vLookatPt, &m_vUpVec );
	return matView;
}

D3DXMATRIX MSCamera::GetProjMatrix()
{
	D3DXMATRIX matProj;
	if (m_projType == Ortho)
	{
		if (m_coordType == LEFTHAND)
			D3DXMatrixOrthoOffCenterLH( &matProj, m_l, m_r, m_b, m_t, m_zn, m_zf );
		else
			D3DXMatrixOrthoOffCenterRH( &matProj, m_l, m_r, m_b, m_t, m_zn, m_zf );
	}
	else
	{
		if (m_coordType == LEFTHAND)
			D3DXMatrixPerspectiveFovLH( &matProj, m_fovy, m_aspect, m_zn, m_zf );
		else
			D3DXMatrixPerspectiveFovRH( &matProj, m_fovy, m_aspect, m_zn, m_zf );
	}
	return matProj;
}
BOOL MSCamera::SetProjType(ProjType t)
{
	m_projType = t;
	return TRUE;
}
BOOL MSCamera::SetCoordType(CoordType t)
{
	m_coordType = t;
	return TRUE;
}
BOOL MSCamera::SetOrthoPara(float l, float t, float r, float b)
{
	m_l = l;
	m_t = t;
	m_r = r;
	m_b = b;
	return TRUE;
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

vector<MS3DDisplay*> MS3DDisplay::m_pAllInstances;
int MS3DDisplay::D3DDEVICELOST = 0;
MS3DDisplay::MS3DDisplay(IDirect3D9* pD3D, UINT rtWidth, UINT rtHeight) : MSEventManager(NULL), MSDXBase(NULL)
{
	ZeroMemory(&m_d3dpp, sizeof(m_d3dpp));
	m_pAllInstances.push_back(this);
	m_hDisplayWnd = NULL;
	m_hRenderThread = 0;
	m_pEffect = NULL;
	m_texW = 0; m_texH = 0; 
	RegisterWndClass(GetModule());
	
	CreateD3DWindow(rtWidth, rtHeight);
	InitDevice(pD3D, rtWidth, rtHeight);
	CreateTexture(rtWidth, rtHeight);
	if (D3DDEVICELOST == 0)
		D3DDEVICELOST = RegisterWindowMessage(D3DDEVICELOST_MSG);
}
MS3DDisplay::MS3DDisplay(IDirect3DDevice9* pDevice, UINT rtWidth, UINT rtHeight) : MSEventManager(NULL), MSDXBase(pDevice)
{
	ZeroMemory(&m_d3dpp, sizeof(m_d3dpp));
	m_texW = 0; m_texH = 0; 
	m_pAllInstances.push_back(this);
	m_hDisplayWnd = NULL;
	m_hRenderThread = 0;
	m_pEffect = NULL;
	CreateTexture(rtWidth, rtHeight);
}
HRESULT	MS3DDisplay::ShowDisplayWnd(BOOL bShow)
{
	if (m_hDisplayWnd == 0)
	{
		return S_FALSE;
	}
	ShowWindow(m_hDisplayWnd, bShow);
	return S_OK;
}
ATOM MS3DDisplay::RegisterWndClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW | CS_NOCLOSE;
	wcex.lpfnWndProc	= D3DDisplayWndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= NULL;
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= NULL;
	wcex.lpszClassName	= L"D3DDisplayWnd";
	wcex.hIconSm		= NULL;
	ATOM ret = RegisterClassEx(&wcex);
	
	return ret;
}
HRESULT MS3DDisplay::SetDeviceLostCallback(DeviceLostCallBack pBeforeReset, 
										   DeviceLostCallBack pAfterReset, void* pUsetContext)
{
	if (pBeforeReset == NULL || pAfterReset == NULL)
		return S_FALSE;
	m_pBeforeReset.push_back(pBeforeReset);
	m_pAfterReset.push_back(pAfterReset);
	m_pUserContext.push_back(pUsetContext);
	return S_OK;
}
HRESULT MS3DDisplay::OnActivateApp()
{
	HRESULT hr = S_OK;
	HRESULT err = S_OK;
	if (m_pDevice != NULL)
	{
		HRESULT state = m_pDevice->TestCooperativeLevel();
		if (state == D3DERR_DEVICENOTRESET)
		{
			for (int i =0; i < m_pAllInstances.size(); i++)
			{
				if (m_pAllInstances[i] == NULL)
					continue;

				hr = m_pAllInstances[i]->OnDeviceLost(m_pDevice, NULL);
				if (FAILED(hr))
					err = hr;
			}
		}
	}
	return err;
}
LRESULT MS3DDisplay::D3DDisplayWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HRESULT hr = S_OK;
	
	if (message == D3DDEVICELOST)
	{
		HRESULT err = S_OK;
		for (int i =0 ;i < m_pAllInstances.size(); i++)
		{
			if (m_pAllInstances[i]->GetD3DWnd() == hWnd)
			{
				 hr = m_pAllInstances[i]->OnActivateApp();
				 if (FAILED(hr))
					 err = S_FALSE;
			}
		}
		return err;
	}

	switch (message)
	{
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
HRESULT MS3DDisplay::CreateD3DWindow(UINT winW, UINT winH)
{
	if (winW != 0 && winH != 0)
	{
		if (m_hDisplayWnd == 0)
		{
			m_hDisplayWnd  = CreateWindowExW(WS_EX_APPWINDOW, L"D3DDisplayWnd", L"D3DDisplayWnd", WS_MINIMIZEBOX| WS_MAXIMIZEBOX |WS_OVERLAPPEDWINDOW,
				CW_USEDEFAULT, 0, winW, winH, NULL, NULL, GetModule(), NULL);
			ShowWindow(m_hDisplayWnd, FALSE);
		}
	}
	else
	{
		if (m_hDisplayWnd  == 0)
		{
			m_hDisplayWnd  = CreateWindowExW(WS_EX_APPWINDOW, L"D3DWnd", L"D3DWnd", WS_MINIMIZEBOX| WS_MAXIMIZEBOX | WS_OVERLAPPEDWINDOW,
				CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, GetModule(), NULL);
			ShowWindow(m_hDisplayWnd , FALSE);
		}
	}
	return S_OK;
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
	
	if (m_pCamera != NULL)
	{
		delete m_pCamera;
		m_pCamera = NULL;
	}
	if (m_hDisplayWnd != 0)
	{
		::DestroyWindow(m_hDisplayWnd);
		m_hDisplayWnd = 0;
	}
	vector<MS3DDisplay*>::iterator thisIter = ::find(m_pAllInstances.begin(), m_pAllInstances.end(), this);
	if (thisIter != m_pAllInstances.end())
	{
		m_pAllInstances.erase(thisIter);
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

BOOL MS3DDisplay::InitDevice(IDirect3D9* pD3D, UINT rtWidth, UINT rtHeight)
{
	if (pD3D == NULL)
	{
		return FALSE;
	}
	// Set up the structure used to create the D3DDevice. Since we are now
	// using more complex geometry, we will create a device with a zbuffer.

	ZeroMemory( &m_d3dpp, sizeof(m_d3dpp) );
	m_d3dpp.Windowed = TRUE;
	m_d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	m_d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	int screenW, screenH;
	if (rtWidth == 0 || rtHeight == 0)
	{
		HDC dc = GetDC(m_hDisplayWnd);
		screenW = GetDeviceCaps(dc, HORZRES);
		screenH = GetDeviceCaps(dc, VERTRES);
	}
	else
	{
		screenW = rtWidth;
		screenH = rtHeight;
	}
	m_d3dpp.BackBufferWidth = screenW;
	m_d3dpp.BackBufferHeight = screenH;

	m_d3dpp.EnableAutoDepthStencil = TRUE;
	m_d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
	m_d3dpp.Flags |= D3DPRESENTFLAG_LOCKABLE_BACKBUFFER;
	m_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;
	// Create the D3DDevice
	if( FAILED( pD3D->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, m_hDisplayWnd,
		D3DCREATE_HARDWARE_VERTEXPROCESSING | D3DCREATE_DISABLE_DRIVER_MANAGEMENT_EX, &m_d3dpp, &m_pDevice )))
	{
		OutputDebugStringW(L"@@@@ CreateDevice Failed!! in MS3DDisplay::InitDevice() \n");
		return FALSE;
	}
	D3DCAPS9 caps;
	m_pDevice->GetDeviceCaps(&caps);
	if (caps.TextureCaps & D3DPTEXTURECAPS_NONPOW2CONDITIONAL)
	{
		int powerof2Width = 1;
		int powerof2Height = 1;
		while (powerof2Width < screenW)
		{
			powerof2Width *= 2;
		}
		while (powerof2Height < screenH)
		{
			powerof2Height *= 2;
		}
		m_d3dpp.BackBufferWidth = powerof2Width;
		m_d3dpp.BackBufferHeight = powerof2Height;
		m_pDevice->Release();
		m_pDevice = NULL;
		if( FAILED( pD3D->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, m_hDisplayWnd,
			D3DCREATE_HARDWARE_VERTEXPROCESSING, &m_d3dpp, &m_pDevice )))
		{
			OutputDebugStringW(L"@@@@ CreateDevice Failed!! in MS3DDisplay::InitDevice() \n");
			return FALSE;
		}
	}
	HRESULT hr = S_OK;
	// Turn on the zbuffer
	hr = m_pDevice->SetRenderState( D3DRS_ZENABLE, TRUE );
	// Turn on ambient lighting 
	hr = m_pDevice->SetRenderState( D3DRS_AMBIENT, 0xffffffff );
	hr = m_pDevice->SetRenderState( D3DRS_CULLMODE, D3DCULL_CW);

	hr = m_pDevice->SetTextureStageState(0, D3DTSS_CONSTANT, 0xfffffffff );
	hr = m_pDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);
	hr = m_pDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_CONSTANT);
	hr = m_pDevice->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_TEXTURE);
	hr = m_pDevice->SetTextureStageState(1, D3DTSS_COLOROP, D3DTOP_DISABLE);

	m_pDisplayPlane = new MS3DPlane(m_pDevice);
	m_pCamera = new MSCamera(m_pDevice);
	
	return TRUE;
}

BOOL MS3DDisplay::CreateTexture(UINT rtWidth = 0, UINT rtHeight = 0)
{
	if (m_pDevice == NULL)
	{
		return FALSE;
	}
	if (m_pTexture != NULL)
	{
		m_pTexture->Release();
		m_pTexture = NULL;
	}
	HRESULT hr;
	
	HWND desktop = GetDesktopWindow();
	HDC dc = GetDC(desktop);
	int screenW = GetDeviceCaps(dc, HORZRES);
	int screenH = GetDeviceCaps(dc, VERTRES);
	if (rtWidth == 0 || rtHeight == 0)
	{
		m_texW = screenW; m_texH = screenH;
		hr = D3DXCreateTexture(m_pDevice, screenW, screenH, 0, D3DUSAGE_DYNAMIC,
		D3DFMT_X8R8G8B8, D3DPOOL_DEFAULT, &m_pTexture);
	}
	else
	{
		m_texW = rtWidth; m_texH = rtHeight;
		hr = D3DXCreateTexture(m_pDevice, rtWidth, rtHeight, 0, D3DUSAGE_DYNAMIC,
			D3DFMT_X8R8G8B8, D3DPOOL_DEFAULT, &m_pTexture);
	}
	
	if (FAILED(hr))
	{
		OutputDebugStringW(L"@@@@@ D3DXCreateTexture Failed in MS3DDisplay::CreateTexture()!! \n");
		return FALSE;
	}
	
	return TRUE;
}

BOOL MS3DDisplay::Render()
{
	CAutoLock lck(&m_csResetDevice);
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
		m_pDevice->EndScene();
	}

	m_pDevice->Present(NULL,NULL,NULL,NULL);
	m_pCamera->CameraOff();
	return TRUE;
}

BOOL MS3DDisplay::Render(IDirect3DBaseTexture9* pTexture)
{
	CAutoLock lck(&m_csResetDevice);
	m_pDevice->Clear( 0, NULL, D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER, 
		D3DCOLOR_XRGB(50,50,50), 1.0f, 0 );

	m_pCamera->CameraOn();
	if( SUCCEEDED( m_pDevice->BeginScene() ) )
	{
		if (m_pDisplayPlane != NULL)
		{
			m_pDisplayPlane->Render(pTexture);
		}
		m_pDevice->EndScene();
	}
	m_pDevice->Present(NULL,NULL,NULL,NULL);
	m_pCamera->CameraOff();
	return TRUE;
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

HRESULT MS3DDisplay::OnDeviceLost(IDirect3DDevice9 * pd3dDevice,
							  void* pUserContext)
{
	HRESULT hr = S_OK;
	CAutoLock lck(&m_csResetDevice);
	if (m_pDevice == NULL)
	{
		return S_FALSE;
	}
	OnBeforeResetDevice(pd3dDevice, pUserContext);
	for (int i =0; i< m_pBeforeReset.size(); i++)
	{
		m_pBeforeReset[i](pd3dDevice, m_pUserContext[i]);
	}
	hr = m_pDevice->Reset(&m_d3dpp);
	if (FAILED(hr))
	{
		return S_FALSE;
	}
	OnAfterResetDevice(pd3dDevice, pUserContext);

	for (int i =0; i< m_pAfterReset.size(); i++)
	{
		m_pAfterReset[i](pd3dDevice, m_pUserContext[i]);
	}

	return S_OK;
}

HRESULT MS3DDisplay::OnBeforeResetDevice(IDirect3DDevice9 * pd3dDevice,	
									void* pUserContext)
{
	HRESULT hr = S_OK;
	if (m_pEffect != NULL)
	{
		hr = m_pEffect->OnLostDevice();
	}
	if (m_pDisplayPlane != NULL)
	{
		delete m_pDisplayPlane;
		m_pDisplayPlane = NULL;
	}
	if (m_pTexture != NULL)
	{
		m_pTexture->Release();
		m_pTexture = NULL;
	}
	return S_OK;
}
HRESULT MS3DDisplay::OnAfterResetDevice(IDirect3DDevice9 * pd3dDevice,	
								    void* pUserContext)
{
	HRESULT hr = S_OK;
	// Turn on the zbuffer
	if (pd3dDevice == NULL)
	{
		return S_FALSE;
	}
	hr = pd3dDevice->SetRenderState( D3DRS_ZENABLE, TRUE );
	// Turn on ambient lighting 
	hr = pd3dDevice->SetRenderState( D3DRS_AMBIENT, 0xffffffff );
	hr = pd3dDevice->SetRenderState( D3DRS_CULLMODE, D3DCULL_CW);

	hr = pd3dDevice->SetTextureStageState(0, D3DTSS_CONSTANT, 0xfffffffff );
	hr = pd3dDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);
	hr = pd3dDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_CONSTANT);
	hr = pd3dDevice->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_TEXTURE);
	hr = pd3dDevice->SetTextureStageState(1, D3DTSS_COLOROP, D3DTOP_DISABLE);
	if (m_pEffect != NULL)
	{
		hr = m_pEffect->OnResetDevice();
	}

	if (m_pDisplayPlane != NULL)
	{
		delete m_pDisplayPlane;
		m_pDisplayPlane = NULL;
	}
	m_pDisplayPlane = new MS3DPlane(pd3dDevice);
	CreateTexture(m_texW, m_texH);
	return S_OK;
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

