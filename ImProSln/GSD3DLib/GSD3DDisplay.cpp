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

HRESULT GS3DDisplay::InitDevice(UINT bufW, UINT bufH)
{
	//Create GSWnd
	HRESULT hr = S_OK;
	hr = GSWnd::CreateWnd(bufW, bufH);
	//Create D3DDevice
	hr = GSDXBase::CreateD3DDevice(GetHwnd(), bufW, bufH);

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
	//Create Camera
	m_pCamera = new GSCamera();
	//Create D3DPlane
	m_pDisplayPlane = new GS3DPlane(m_pDevice, m_pDeviceContext, m_pSwapChain);
	
	return S_OK;
}
HRESULT GS3DDisplay::Render()
{
	if (m_pDeviceContext == NULL || m_pEffect == NULL || m_pDisplayPlane == NULL)
		return E_FAIL;
	HRESULT hr = S_OK;
	hr = RenderMesh(m_pDisplayPlane, m_pDeviceContext, m_pEffect);
	return hr;
}
BOOL GS3DDisplay::IsDeviceFromOther()
{
	return m_bDeviceFromOthers;
}

HRESULT GS3DDisplay::LoadEffectFromFile(WCHAR* szFileName, UINT szSize)
{
	if (m_pDevice == NULL || m_pDeviceContext == NULL || m_pSwapChain == NULL)
		return E_FAIL;
	SAFE_RELEASE(m_pEffect);
	HRESULT hr = S_OK;
	
	m_pEffect = new GSEffect(m_pDevice, m_pDeviceContext, m_pSwapChain);
	hr = m_pEffect->LoadFromFile(szFileName);
	
	return hr;
}