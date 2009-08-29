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
	m_pVertices = NULL;
	m_pIndices = NULL;
	m_vertexFMT = D3DFVF_XYZ|D3DFVF_NORMAL|D3DFVF_TEX1;
	m_indexFMT = D3DFMT_INDEX16;
}
MSMeshBase::MSMeshBase(IDirect3DDevice9* pDevice) : MSDXBase(pDevice)
{
	m_pVertices = NULL;
	m_pIndices = NULL;
	m_vertexFMT = D3DFVF_XYZ|D3DFVF_NORMAL|D3DFVF_TEX1;
	m_indexFMT = D3DFMT_INDEX16;
}

MSMeshBase::~MSMeshBase()
{
	if (m_pVertices != NULL)
	{
		m_pVertices->Release();
		m_pVertices = NULL;
	}
	if (m_pIndices != NULL)
	{
		m_pIndices ->Release();
		m_pIndices = NULL;
	}
}

IDirect3DVertexBuffer9* MSMeshBase::GetVertexBuffer()
{
	return m_pVertices;
}
IDirect3DIndexBuffer9* MSMeshBase::GetIndexBuffer()
{
	return m_pIndices;
}
UINT MSMeshBase::GetVertexNumber()
{	
	if (m_pVertices == NULL)
	{
		return 0;
	}
	D3DVERTEXBUFFER_DESC desc;
	if (FAILED(m_pVertices->GetDesc(&desc)))
		return 0;
	return desc.Size/sizeof(MSMeshBase::CUSTOMVERTEX);
}

UINT MSMeshBase::GetPrimitiveNumber()
{
	if (m_pIndices == NULL)
	{
		return 0;
	}
	D3DINDEXBUFFER_DESC desc;
	if (FAILED(m_pIndices->GetDesc(&desc)))
		return 0;
	if (m_indexFMT == D3DFMT_INDEX16)
		return (desc.Size/sizeof(unsigned short))/3;
	else
		return (desc.Size/sizeof(unsigned int))/3;
}
DWORD MSMeshBase::GetVertexFMT()
{
	return m_vertexFMT;
}

D3DFORMAT MSMeshBase::GetIndexFMT()
{
	return m_indexFMT;
}


BOOL MSMeshBase::Render(IDirect3DBaseTexture9* pTexture)
{
	if (m_pDevice == NULL) 
		return FALSE;
	HRESULT hr;
	hr = m_pDevice->SetTexture(0, pTexture);
	hr = m_pDevice->SetStreamSource(0, GetVertexBuffer(), 0, sizeof(MS3DPlane::CUSTOMVERTEX));
	hr = m_pDevice->SetIndices(GetIndexBuffer());
	hr = m_pDevice->SetFVF(GetVertexFMT());
	hr = m_pDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST,0,0, GetVertexNumber(),
		0, GetPrimitiveNumber());
	hr = m_pDevice->SetTexture(0, NULL);

	return TRUE;
}
BOOL MSMeshBase::Render()
{
	if (m_pDevice == NULL) 
		return FALSE;
	HRESULT hr;
	hr = m_pDevice->SetStreamSource(0, GetVertexBuffer(), 0, sizeof(MS3DPlane::CUSTOMVERTEX));
	hr = m_pDevice->SetIndices(GetIndexBuffer());
	hr = m_pDevice->SetFVF(GetVertexFMT());
	hr = m_pDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST,0,0, GetVertexNumber(),
		0, GetPrimitiveNumber());

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
	if (m_pVertices != NULL)
	{
		m_pVertices->Release();
		m_pVertices = NULL;
	}
	if (m_pIndices != NULL)
	{
		m_pIndices ->Release();
		m_pIndices = NULL;
	}

	hr = m_pDevice->CreateVertexBuffer(sizeof(MS3DPlane::CUSTOMVERTEX)*4, 0, m_vertexFMT,
		D3DPOOL_MANAGED, &m_pVertices, NULL);
	if (FAILED(hr))
	{
		OutputDebugStringW(L"@@@@ InitGeometry CreateVertexBuffer Failed in MSMeshBase!!\n");
		return FALSE;
	}
	CUSTOMVERTEX* pVertices = NULL;

	if( FAILED( m_pVertices->Lock( 0, 0, (void**)&pVertices, 0 ) ) )
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
	m_pVertices->Unlock();

	hr = m_pDevice->CreateIndexBuffer( sizeof(unsigned short)*6, 0, m_indexFMT, D3DPOOL_MANAGED, &m_pIndices, NULL);
	if (FAILED(hr))
	{
		OutputDebugStringW(L"@@@@ InitGeometry CreateIndexBuffer Failed in MSMeshBase!!\n");
		return FALSE;
	}

	unsigned short* pIndex = NULL;
	if (FAILED(m_pIndices->Lock(0, 0, (void**)&pIndex, 0)))
		return FALSE;

	pIndex[0] = 0;	pIndex[1] = 1;  pIndex[2] = 3;
	pIndex[3] = 3;  pIndex[4] = 1;  pIndex[5] = 2;

	m_pIndices->Unlock();
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
	D3DXMatrixLookAtRH( &matView, &m_vEyePt, &m_vLookatPt, &m_vUpVec );
	m_pDevice->GetTransform(D3DTS_VIEW, &m_BackupMatView);
	m_pDevice->SetTransform(D3DTS_VIEW, &matView);

	D3DXMATRIXA16 matProj;
	D3DXMatrixOrthoOffCenterRH( &matProj, m_l, m_r, m_b, m_t, m_zn, m_zf );
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
MS3DDisplay::MS3DDisplay(HWND hWnd, IDirect3D9* pD3D)
{
	m_hDisplayWnd = hWnd;
	m_pD3D = pD3D;
	m_pD3D->AddRef();
	m_hRenderThread = 0;
	m_pTexture = NULL;
	InitDevice();
}
MS3DDisplay::~MS3DDisplay()
{
	if (m_hRenderThread != 0)
	{
		CloseHandle(m_hRenderThread);
		m_hRenderThread = 0;
	}
	if (m_pDisplayPlane != NULL)
	{
		delete m_pDisplayPlane;
		m_pDisplayPlane == NULL;
	}
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
	while(1)
	{
		OutputDebugStringW(L"@@@@@ MS3DDisplay::_Run running!! \n");
		((MS3DDisplay*)_THIS)->Render();
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
	m_pDevice->SetRenderState( D3DRS_CULLMODE, D3DCULL_CCW);
	m_pDevice->SetTextureStageState(0, D3DTSS_COLOROP,D3DTOP_SELECTARG1);
	m_pDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	m_pDevice->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_CONSTANT);
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

BOOL MS3DDisplay::Render()
{
	OutputDebugStringW(L"@@@@@ MS3DDisplay::Render Called!! \n");
	m_pDevice->Clear( 0, NULL, D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER, 
		D3DCOLOR_XRGB(50,50,50), 1.0f, 0 );
	m_pCamera->CameraOn();
	if( SUCCEEDED( m_pDevice->BeginScene() ) )
	{
			
		if (m_pDisplayPlane != NULL)
		{	
			m_pDisplayPlane->Render(m_pTexture);
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
			m_pDisplayPlane->Render(pTexture);
		m_pDevice->EndScene();
	}
	m_pDevice->Present(NULL,NULL,NULL,NULL);
	m_pCamera->CameraOff();
	return TRUE;
}
