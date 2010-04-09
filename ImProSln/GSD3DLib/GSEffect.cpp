#include "stdafx.h"
#include "GSEffect.h"
#include <DXUT.h>


GSBasicEffect::GSBasicEffect(ID3D11Device* pDevice, ID3D11DeviceContext* pContext) : GSDXBase(pDevice, pContext)
{
	m_pPSShader = NULL;
	m_pVSShader = NULL;
}
GSBasicEffect::~GSBasicEffect()
{
	SAFE_RELEASE(m_pPSShader);
	SAFE_RELEASE(m_pVSShader);
}
HRESULT GSBasicEffect::CompileShaderFromFile(LPCWSTR szFileName, LPCSTR szEntryPoint, LPCSTR szShaderModel, ID3DBlob** ppBlobOut )
{
	if (szFileName == NULL || szEntryPoint == NULL || szShaderModel == NULL || ppBlobOut == NULL)
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
			return E_FAIL;
			/*
			WCHAR modulePath[MAX_PATH] = {0};
			HMODULE module = GetModule();
			GetModuleFileName(module, modulePath, MAX_PATH);
			// Gets filename
			WCHAR* pszFile = wcsrchr(modulePath, '\\');
			pszFile++;    // Moves on from \
			// Get path
			WCHAR szPath[MAX_PATH] = L"";
			_tcsncat(szPath, modulePath, pszFile - modulePath);
			swprintf_s(path, MAX_PATH, L"%s%s", szPath, szFileName);
			if (GetFileAttributes( path ) == 0xFFFFFFFF)
			{
				//can't find file
				return E_FAIL;
			}
			*/
		}
	}

	DWORD dwShaderFlags = D3D10_SHADER_ENABLE_STRICTNESS;
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
HRESULT GSBasicEffect::LoadPixelShaderFromFile(LPCWSTR szFileName, LPCSTR szEntryPoint, ID3D11PixelShader*& pPSShader)
{
	if (m_pDevice == NULL)
		return E_FAIL;
	D3D_FEATURE_LEVEL fLevel = m_pDevice->GetFeatureLevel();
	char szShaderModel[MAX_PATH] = {0};
	
	switch(fLevel)
	{
	case D3D_FEATURE_LEVEL_11_0:
		{
			sprintf_s(szShaderModel, MAX_PATH, "ps_5_0");
			break;
		}
	case D3D_FEATURE_LEVEL_10_1:
		{
			sprintf_s(szShaderModel, MAX_PATH, "ps_4_1");
			break;
		}
	case D3D_FEATURE_LEVEL_10_0:
		{
			sprintf_s(szShaderModel, MAX_PATH, "ps_4_0");
			break;
		}
	case D3D_FEATURE_LEVEL_9_3:
		{
			sprintf_s(szShaderModel, MAX_PATH, "ps_4_0_level_9_3");
			
			break;
		}
	case D3D_FEATURE_LEVEL_9_2: // Shader model 2 fits feature level 9_1
	case D3D_FEATURE_LEVEL_9_1:
		{
			sprintf_s(szShaderModel, MAX_PATH, "ps_4_0_level_9_1");
			break;
		}
	default:
		return E_FAIL;
	}
	SAFE_RELEASE(m_pPSShaderBuffer);
	CompileShaderFromFile(szFileName, szEntryPoint, szShaderModel, &m_pPSShaderBuffer);
	if (m_pPSShaderBuffer == NULL)
	{
		return E_FAIL;
	}
	SAFE_RELEASE(m_pPSShader);
	return m_pDevice->CreateVertexShader( m_pPSShaderBuffer->GetBufferPointer(),
		m_pPSShaderBuffer->GetBufferSize(), NULL, &m_pVSShader ) ;
}
HRESULT GSBasicEffect::LoadVertexShaderFromFile(LPCWSTR szFileName, LPCSTR szEntryPoint, ID3D11PixelShader*& pVSShader)
{
	if (m_pDevice == NULL)
		return E_FAIL;
	D3D_FEATURE_LEVEL fLevel = m_pDevice->GetFeatureLevel();
	char szShaderModel[MAX_PATH] = {0};

	switch(fLevel)
	{
	case D3D_FEATURE_LEVEL_11_0:
		{
			sprintf_s(szShaderModel, MAX_PATH, "vs_5_0");
			break;
		}
	case D3D_FEATURE_LEVEL_10_1:
		{
			sprintf_s(szShaderModel, MAX_PATH, "vs_4_1");
			break;
		}
	case D3D_FEATURE_LEVEL_10_0:
		{
			sprintf_s(szShaderModel, MAX_PATH, "vs_4_0");
			break;
		}
	case D3D_FEATURE_LEVEL_9_3:
		{
			sprintf_s(szShaderModel, MAX_PATH, "vs_4_0_level_9_3");

			break;
		}
	case D3D_FEATURE_LEVEL_9_2: // Shader model 2 fits feature level 9_1
	case D3D_FEATURE_LEVEL_9_1:
		{
			sprintf_s(szShaderModel, MAX_PATH, "vs_4_0_level_9_1");
			break;
		}
	default:
		return E_FAIL;
	}
	SAFE_RELEASE(m_pVSShaderBuffer);
	CompileShaderFromFile(szFileName, szEntryPoint, szShaderModel, &m_pVSShaderBuffer);
	if (m_pVSShaderBuffer == NULL)
	{
		return E_FAIL;
	}
	SAFE_RELEASE(m_pVSShader);
	return m_pDevice->CreateVertexShader( m_pVSShaderBuffer->GetBufferPointer(),
		m_pVSShaderBuffer->GetBufferSize(), NULL, &m_pVSShader ) ;
}
ID3DBlob* GSBasicEffect::GetVSShaderBuffer()
{
	return m_pVSShaderBuffer;
}
ID3DBlob* GSBasicEffect::GetPSShaderBuffer()
{
	return m_pPSShaderBuffer;
}


ID3D11PixelShader* GSBasicEffect::GetPSShader()
{
	return m_pPSShader;
}

ID3D11VertexShader* GSBasicEffect::GetVSShader()
{
	return m_pVSShader;
}