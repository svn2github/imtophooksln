#include "stdafx.h"
#include "GSD3DDisplay.h"
#include <DXUT.h>
#include <vector>
using namespace std;

GS3DDisplay::GS3DDisplay(UINT bufW, UINT bufH)
{
	m_bDeviceFromOthers = FALSE;
	m_pDisplayPlane = NULL;
	m_pCamera = NULL;
}
GS3DDisplay::GS3DDisplay(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext, IDXGISwapChain* pSwapChain) : GSDXBase(pDevice, pDeviceContext, pSwapChain)
{
	m_bDeviceFromOthers = TRUE;
}
GS3DDisplay::~GS3DDisplay()
{
	SAFE_RELEASE(m_pDisplayPlane);
	SAFE_RELEASE(m_pCamera);
}
HRESULT GS3DDisplay::InitDevice(UINT bufW, UINT bufH)
{
	//Create GSWnd
	GSWnd::CreateWnd(bufW, bufH);
	//Create D3DDevice
	GSDXBase::CreateD3DDevice(GetHwnd(), bufW, bufH);

	return S_OK;
}
HRESULT GS3DDisplay::InitDevice(ID3D11Device* pDevice)
{
	return S_OK;
}
HRESULT GS3DDisplay::Render()
{
	return S_OK;
}
BOOL GS3DDisplay::IsDeviceFromOther()
{
	return m_bDeviceFromOthers;
}
HRESULT GS3DDisplay::SetEffectVariables(IGSEffectBase* pGSEffect)
{
	return S_OK;
}