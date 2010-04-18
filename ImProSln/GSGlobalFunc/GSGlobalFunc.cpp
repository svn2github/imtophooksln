#include "stdafx.h"
#include "GSGlobalFunc.h"
#include "cv.h"
#include "highgui.h"
#include "GSMacro.h"
namespace GS_GLOBAL_FUNC
{

	HRESULT GSSaveTextureToFile(LPCSTR str, GSTexture2D* pGSTexture)
	{
		if (pGSTexture == NULL)
			return E_FAIL;
		HRESULT hr = S_OK;
		ID3D11Texture2D* pTexture = pGSTexture->GetTexture();
		ID3D11Device* pDevice = pGSTexture->GetD3DDevice();
		ID3D11DeviceContext* pDeviceContext = pGSTexture->GetDeviceContext();
		if (pTexture == NULL || pDeviceContext == NULL || pDevice == NULL)
			return E_FAIL;
		ID3D11Texture2D* pCloneTexture = NULL;
		D3D11_TEXTURE2D_DESC desc;
		pTexture->GetDesc(&desc);
		desc.BindFlags = 0;
		desc.Usage = D3D11_USAGE_STAGING;
		desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE | D3D11_CPU_ACCESS_READ;
		hr = pDevice->CreateTexture2D(&desc, NULL, &pCloneTexture);
		if (FAILED(hr))
		{
			return E_FAIL;
		}
		pDeviceContext->CopyResource(pCloneTexture, pTexture);
		D3D11_MAPPED_SUBRESOURCE mappedData; 
		hr = pDeviceContext->Map(pCloneTexture, 0, D3D11_MAP_READ_WRITE, 0, &mappedData);
		if (FAILED(hr))
		{
			SAFE_RELEASE(pCloneTexture);
			return E_FAIL;
		}
		IplImage* cvImg = cvCreateImageHeader(cvSize(desc.Width, desc.Height), 8, 4);
		cvImg->imageData = (char*)mappedData.pData;
		cvSaveImage(str, cvImg);
		pDeviceContext->Unmap(pCloneTexture, 0);
		SAFE_RELEASE(pCloneTexture);
		cvReleaseImageHeader(&cvImg);
		cvImg = NULL;

		return S_OK;

	}

};