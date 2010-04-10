#pragma once
#include "GSD3DBaseClass.h"
#include "d3dx11effect.h"
#include <map>
#include <string>
using namespace std;
class GSD3DLIB_API GSEffectBase : public IGSEffectBase
{
protected:
	ID3DBlob* m_pEffectBuffer;
	ID3DX11Effect* m_pEffect;
	
protected:
	HRESULT _CompileShaderFromFile(LPCWSTR szFileName, LPCSTR szEntryPoint, LPCSTR szShaderModel, ID3DBlob** ppBlobOut );
	HRESULT _LoadEffectFromFile(ID3D11Device* pDevice, LPCWSTR szFileName, ID3DBlob*& pEffectBuffer, ID3DX11Effect*& pEffect);
public:
	GSEffectBase();
	~GSEffectBase();
	virtual ID3DX11Effect* GetEffect();
	virtual ID3DBlob* GetEffectBuffer();

};

