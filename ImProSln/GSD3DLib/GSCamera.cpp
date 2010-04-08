#include "stdafx.h"
#include "GSD3DBaseClass.h"
#include "GSCamera.h"

GSCamera::GSCamera() : GSDXBase()
{
	init();
}
GSCamera::GSCamera(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext) : GSDXBase(pDevice, pDeviceContext)
{
	init();
}
GSCamera::~GSCamera()
{

}
HRESULT GSCamera::init()
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
	return S_OK;
}
HRESULT GSCamera::SetEyePos(D3DXVECTOR3& vEyePt)
{
	m_vEyePt = vEyePt;
	return S_OK;
}
HRESULT GSCamera::SetLookAt(D3DXVECTOR3& vLookPt)
{
	m_vLookatPt = vLookPt;
	return S_OK;
}
HRESULT GSCamera::SetUpVec(D3DXVECTOR3& vUpVec)
{
	m_vUpVec = vUpVec;
	return S_OK;
}

D3DXVECTOR3 GSCamera::GetEyePos() 
{ 
	return m_vEyePt;
}
D3DXVECTOR3 GSCamera::GetLookAt() 
{ 
	return m_vLookatPt;
}
D3DXVECTOR3 GSCamera::GetUpVec() 
{ 
	return m_vUpVec; 
}

D3DXMATRIX GSCamera::GetViewMatrix()
{
	D3DXMATRIX matView;
	if (m_coordType == LEFTHAND)
		D3DXMatrixLookAtLH( &matView, &m_vEyePt, &m_vLookatPt, &m_vUpVec );
	else
		D3DXMatrixLookAtRH( &matView, &m_vEyePt, &m_vLookatPt, &m_vUpVec );
	return matView;
}

D3DXMATRIX GSCamera::GetProjMatrix()
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
HRESULT GSCamera::SetProjType(ProjType t)
{
	m_projType = t;
	return S_OK;
}
HRESULT GSCamera::SetCoordType(CoordType t)
{
	m_coordType = t;
	return S_OK;
}
HRESULT GSCamera::SetOrthoPara(float l, float t, float r, float b)
{
	m_l = l;
	m_t = t;
	m_r = r;
	m_b = b;
	return S_OK;
}
