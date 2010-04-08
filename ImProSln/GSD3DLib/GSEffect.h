#pragma once
#include "GSD3DBaseClass.h"

class GSD3DLIB_API GSBasicEffect : public IGSEffectBase, public GSRefCount
{
protected:
	ID3DBlob* m_pPSShaderBuffer;
	ID3DBlob* m_pVSShaderBuffer;
	ID3D11PixelShader* m_pPSShader;
	ID3D11VertexShader* m_pVSShader;
protected:
	HRESULT LoadPixelShaderFromFile(WCHAR* path, ID3D11PixelShader*& pPSShader);
	HRESULT LoadVertexShaderFromFile(WCHAR* path, ID3D11PixelShader*& pVSShader);
public:
	GSBasicEffect();
	~GSBasicEffect();
	virtual ID3DBlob* GetVSShaderBuffer();
	virtual ID3DBlob* GetPSShaderBuffer();
	virtual ID3D11PixelShader* GetPSShader();
	virtual ID3D11VertexShader* GetVSShader();
};

