#include "stdafx.h"
#include "GSEffect.h"
#include <DXUT.h>


GSBasicEffect::GSBasicEffect()
{
	m_pPSShader = NULL;
	m_pVSShader = NULL;
}
GSBasicEffect::~GSBasicEffect()
{
	SAFE_RELEASE(m_pPSShader);
	SAFE_RELEASE(m_pVSShader);
}

HRESULT GSBasicEffect::LoadPixelShaderFromFile(WCHAR* path, ID3D11PixelShader*& pPSShader)
{
	return S_OK;
}
HRESULT GSBasicEffect::LoadVertexShaderFromFile(WCHAR* path, ID3D11PixelShader*& pVSShader)
{
	return S_OK;
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
	return NULL;
}

ID3D11VertexShader* GSBasicEffect::GetVSShader()
{
	return NULL;
}