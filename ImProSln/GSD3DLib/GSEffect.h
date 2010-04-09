#pragma once
#include "GSD3DBaseClass.h"

class GSD3DLIB_API GSBasicEffect : public IGSEffectBase, public GSRefCount, public GSDXBase
{
protected:
	ID3DBlob* m_pPSShaderBuffer;
	ID3DBlob* m_pVSShaderBuffer;
	ID3D11PixelShader* m_pPSShader;
	ID3D11VertexShader* m_pVSShader;
protected:
	HRESULT CompileShaderFromFile(LPCWSTR szFileName, LPCSTR szEntryPoint, LPCSTR szShaderModel, ID3DBlob** ppBlobOut );
	HRESULT LoadPixelShaderFromFile(LPCWSTR szFileName, LPCSTR szEntryPoint, ID3D11PixelShader*& pPSShader);
	HRESULT LoadVertexShaderFromFile(LPCWSTR szFileName, LPCSTR szEntryPoint, ID3D11PixelShader*& pVPSShader);
public:
	GSBasicEffect(ID3D11Device* pDevice, ID3D11DeviceContext* pContext);
	~GSBasicEffect();
	virtual ID3DBlob* GetVSShaderBuffer();
	virtual ID3DBlob* GetPSShaderBuffer();
	virtual ID3D11PixelShader* GetPSShader();
	virtual ID3D11VertexShader* GetVSShader();
};

