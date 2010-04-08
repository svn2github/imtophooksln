#pragma once
#include "GSD3DBaseClass.h"

class GSD3DLIB_API GSCamera : public GSDXBase, public IGSCamera, public GSRefCount
{
public:
	enum ProjType
	{
		Ortho,
		Persp
	};
	enum CoordType
	{
		LEFTHAND,
		RIGHTHAND
	};
private:
	HRESULT init();

private:
	//for Ortho
	float m_l ;//		[in] Minimum x-value of view volume. 
	float m_r ;//		[in] Maximum x-value of view volume. 
	float m_b ;//		[in] Minimum y-value of view volume. 
	float m_t ;//   	[in] Maximum y-value of view volume. 
	//
	float m_fovy;
	float m_aspect;
	ProjType m_projType;
	CoordType m_coordType;

protected:
	D3DXVECTOR3 m_vEyePt;
	D3DXVECTOR3 m_vLookatPt;
	D3DXVECTOR3 m_vUpVec;
	float m_zn;//		[in] Minimum z-value of the view volume. 
	float m_zf;//		[in] Maximum z-value of the view volume. 

public:
	GSCamera();
	GSCamera(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext);
	virtual ~GSCamera();
	virtual HRESULT SetEyePos(D3DXVECTOR3& vEyePt);
	virtual HRESULT SetLookAt(D3DXVECTOR3& vLookPt);
	virtual HRESULT SetUpVec(D3DXVECTOR3& vUpVec);
	virtual D3DXVECTOR3 GetEyePos();
	virtual D3DXVECTOR3 GetLookAt();
	virtual D3DXVECTOR3 GetUpVec();
	virtual D3DXMATRIX GetViewMatrix();
	virtual D3DXMATRIX GetProjMatrix();
	virtual HRESULT SetProjType(ProjType t);
	virtual HRESULT SetCoordType(CoordType t);
	virtual HRESULT SetOrthoPara(float l, float t, float r, float b);

};
