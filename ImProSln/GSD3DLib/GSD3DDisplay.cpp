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
	m_pEffect = NULL;
	InitDevice(bufW, bufH);
}
GS3DDisplay::GS3DDisplay(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext, IDXGISwapChain* pSwapChain) : GSDXBase(pDevice, pDeviceContext, pSwapChain)
{
	m_bDeviceFromOthers = TRUE;
	InitDevice(pDevice, pDeviceContext, pSwapChain);
}
GS3DDisplay::~GS3DDisplay()
{
	SAFE_RELEASE(m_pDisplayPlane);
	SAFE_RELEASE(m_pCamera);
	SAFE_RELEASE(m_pEffect);
}
HRESULT GS3DDisplay::_GetEffectFileName(WCHAR* szFileName, UINT szSize)
{
	if (szFileName == NULL || szSize <= 0)
		return E_FAIL;
	swprintf_s(szFileName, szSize, L"..\\fx\\GSBasicEffect.fx");
	return S_OK;
}
HRESULT GS3DDisplay::InitDevice(UINT bufW, UINT bufH)
{
	//Create GSWnd
	HRESULT hr = S_OK;
	hr = GSWnd::CreateWnd(bufW, bufH);
	//Create D3DDevice
	hr = GSDXBase::CreateD3DDevice(GetHwnd(), bufW, bufH);
	//Create Effect
	WCHAR fxPath[MAX_PATH] = {0};
	hr = _GetEffectFileName(fxPath, MAX_PATH);
	m_pEffect = new GSEffect(m_pDevice, m_pDeviceContext, m_pSwapChain);
	hr = m_pEffect->LoadFromFile(fxPath);
	//Create Camera
	m_pCamera = new GSCamera();
	//Create D3DPlane
	m_pDisplayPlane = new GS3DPlane(m_pDevice, m_pDeviceContext, m_pSwapChain);
	return S_OK;
}
HRESULT GS3DDisplay::InitDevice(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext, IDXGISwapChain* pSwapChain)
{
	
	HRESULT hr = S_OK;
	//Get GSWnd
	DXGI_SWAP_CHAIN_DESC scDesc;
	m_pSwapChain->GetDesc(&scDesc);
	m_hWnd = scDesc.OutputWindow;
	//Create Effect
	WCHAR fxPath[MAX_PATH] = {0};
	hr = _GetEffectFileName(fxPath, MAX_PATH);
	m_pEffect = new GSEffect(m_pDevice, m_pDeviceContext, m_pSwapChain);
	hr = m_pEffect->LoadFromFile(fxPath);
	//Create Camera
	m_pCamera = new GSCamera();
	//Create D3DPlane
	m_pDisplayPlane = new GS3DPlane(m_pDevice, m_pDeviceContext, m_pSwapChain);
	
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