#include "stdafx.h"
#include "GSEffect.h"
#include <DXUT.h>

extern HMODULE GetModule();

GSEffect::GSEffect(ID3D11Device* pDevice, ID3D11DeviceContext* pContext, IDXGISwapChain* pSwapChain) : GSDXBase(pDevice, pContext, pSwapChain)
{
	m_pEffect = NULL;
	m_pEffectBuffer = NULL;
}
GSEffect::~GSEffect()
{
	SAFE_RELEASE(m_pEffect);
	SAFE_RELEASE(m_pEffectBuffer);
}
HRESULT GSEffect::_CompileShaderFromFile(LPCWSTR szFileName, LPCSTR szEntryPoint, LPCSTR szShaderModel, ID3DBlob** ppBlobOut )
{
	if (szFileName == NULL || szShaderModel == NULL || ppBlobOut == NULL)
	{
		return E_FAIL;
	}
	HRESULT hr = S_OK;
	// find the file
	WCHAR path[MAX_PATH] = {0};
	wcscpy_s(path, MAX_PATH, szFileName);
	if (GetFileAttributes( path ) == 0xFFFFFFFF)
	{
		WCHAR curDir[MAX_PATH] = {0};
		GetCurrentDirectoryW(MAX_PATH, curDir);
		swprintf_s(path, MAX_PATH, L"%s%s", curDir, szFileName);
		if (GetFileAttributes( path ) == 0xFFFFFFFF)
		{	
			WCHAR modulePath[MAX_PATH] = {0};
			HMODULE module = GetModule();
			GetModuleFileName(module, modulePath, MAX_PATH);
			// Gets filename
			WCHAR* pszFile = wcsrchr(modulePath, '\\');
			pszFile++;    // Moves on from \
			// Get path
			WCHAR szPath[MAX_PATH] = L"";
			wcsncat(szPath, modulePath, pszFile - modulePath);
			swprintf_s(path, MAX_PATH, L"%s%s", szPath, szFileName);
			if (GetFileAttributes( path ) == 0xFFFFFFFF)
			{
				//can't find file
				return E_FAIL;
			}	
		}
	}

	DWORD dwShaderFlags = 0;
#if defined( DEBUG ) || defined( _DEBUG )
	// Set the D3D10_SHADER_DEBUG flag to embed debug information in the shaders.
	// Setting this flag improves the shader debugging experience, but still allows 
	// the shaders to be optimized and to run exactly the way they will run in 
	// the release configuration of this program.
	dwShaderFlags |= D3D10_SHADER_DEBUG;
#endif

	ID3DBlob* pErrorBlob;
	hr = D3DX11CompileFromFile( path, NULL, NULL, szEntryPoint, szShaderModel, 
		dwShaderFlags, 0, NULL, ppBlobOut, &pErrorBlob, NULL );
	if( FAILED(hr) )
	{
		if( pErrorBlob != NULL )
			OutputDebugStringA( (char*)pErrorBlob->GetBufferPointer() );
		SAFE_RELEASE( pErrorBlob );
		return hr;
	}
	SAFE_RELEASE( pErrorBlob );

	return S_OK;

}
HRESULT GSEffect::_LoadEffectFromFile(ID3D11Device* pDevice, LPCWSTR szFileName, ID3DBlob*& pEffectBuffer, ID3DX11Effect*& pEffect)
{
	if (pDevice == NULL)
		return E_FAIL;
	SAFE_RELEASE(m_pEffectBuffer);
	SAFE_RELEASE(m_pEffect);
	
	HRESULT hr = S_OK;
	char szShaderModel[MAX_PATH] = "fx_5_0";
		
	_CompileShaderFromFile(szFileName, NULL, szShaderModel, &pEffectBuffer);
	if (pEffectBuffer == NULL)
	{
		return E_FAIL;
	}
	
	hr = D3DX11CreateEffectFromMemory( pEffectBuffer->GetBufferPointer(),
		pEffectBuffer->GetBufferSize(), NULL, pDevice, &pEffect ) ;
	if (FAILED(hr))
		return hr;

	return hr;
}

ID3DX11Effect* GSEffect::GetEffect()
{
	return m_pEffect;
}
ID3DBlob* GSEffect::GetEffectBuffer()
{
	return m_pEffectBuffer;
}
HRESULT GSEffect::LoadFromFile(LPCWSTR szFileName)
{
	if (m_pDevice == NULL)
		return E_FAIL;
	SAFE_RELEASE(m_pEffect);
	SAFE_RELEASE(m_pEffectBuffer);
	return _LoadEffectFromFile(m_pDevice, szFileName, m_pEffectBuffer, m_pEffect);
}