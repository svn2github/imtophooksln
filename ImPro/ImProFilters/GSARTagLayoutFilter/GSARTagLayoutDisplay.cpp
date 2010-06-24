#include "stdafx.h"
#include "GSARTagLayoutDisplay.h"
#include <string.h>
#include "cv.h"
extern HMODULE GetModule();
using namespace GSARLayoutNS;

GSARTagLayoutDisplay::GSARTagLayoutDisplay(UINT bufW, UINT bufH) : GS3DDisplay(bufW, bufH)
{
	m_pCamera->SetOrthoPara(-0.5, 0.5, 0.5, -0.5);
	m_pCamera->SetEyePos(D3DXVECTOR3(0.5, -0.5, -5));
	m_pCamera->SetLookAt(D3DXVECTOR3(0.5, -0.5, 0));

	m_pLayout = NULL;
	m_minMarkerWidth = 1.0;

	memset(m_pARTagMesh, 0, sizeof(m_pARTagMesh));
	memset(m_pARTagTexture, 0, sizeof(m_pARTagTexture));
	memset(m_allMarkerRects, 0, sizeof(m_allMarkerRects));

	m_pTmpSView = NULL;
	m_pTmpPlane = NULL;
	
	LoadARTagTexture();

	m_blackLevel = 0.5;
}

GSARTagLayoutDisplay::GSARTagLayoutDisplay(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext, IDXGISwapChain* pSwapChain) 
: GS3DDisplay(pDevice, pDeviceContext, pSwapChain)
{
	m_pCamera->SetOrthoPara(-0.5, 0.5, 0.5, -0.5);
	m_pCamera->SetEyePos(D3DXVECTOR3(0.5, -0.5, -5));
	m_pCamera->SetLookAt(D3DXVECTOR3(0.5, -0.5, 0));

	m_pLayout = NULL;
	m_minMarkerWidth = 1.0;
	memset(m_pARTagMesh, 0, sizeof(m_pARTagMesh));
	memset(m_pARTagTexture, 0, sizeof(m_pARTagTexture));
	memset(m_allMarkerRects, 0, sizeof(m_allMarkerRects));
	m_pTmpSView = NULL;
	m_pTmpPlane = NULL;
	LoadARTagTexture();

	m_blackLevel = 0.5;
}

GSARTagLayoutDisplay::~GSARTagLayoutDisplay()
{
	SAFE_DELETE(m_pLayout);
	for (int i =0; i < NUMARTAG; i++)
	{
		SAFE_RELEASE(m_pARTagMesh[i]);
	}
	for (int i =0; i < NUMARTAG; i++)
	{
		SAFE_RELEASE(m_pARTagTexture[i]);
	}

	for (int i =0; i < NUMARTAG; i++)
	{
		SAFE_DELETE(m_allMarkerRects[i]);
	}
	SAFE_RELEASE(m_pTmpSView);
	SAFE_RELEASE(m_pTmpPlane);
}

HRESULT GSARTagLayoutDisplay::Render()
{
	CAutoLock lck(&m_csParaSetting);
	if (m_pDeviceContext == NULL || m_pEffect == NULL || m_pDisplayPlane == NULL || m_pSwapChain == NULL || m_pLayout == NULL)
		return E_FAIL;
	HRESULT hr = S_OK;

	float ClearColor[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
	ID3D11RenderTargetView* pRTView = NULL;
	ID3D11DepthStencilView* pDSView = NULL;
	m_pDeviceContext->OMGetRenderTargets(1, &pRTView, &pDSView);
	if (pRTView == NULL )
		return E_FAIL;
	m_pDeviceContext->ClearRenderTargetView( pRTView, ClearColor );
	if (pDSView != NULL)
		m_pDeviceContext->ClearDepthStencilView( pDSView, D3D11_CLEAR_DEPTH, 1.0, 0 );
	SAFE_RELEASE(pRTView);
	SAFE_RELEASE(pDSView);

	for (int i =0; i < m_pLayout->m_nARTag; i++)
	{
		if (!m_pLayout->m_pARTag[i].m_visible)
			continue;

		GS3DPlane* pARTagPlane = m_pARTagMesh[i];
		if (pARTagPlane == NULL)
			continue;

		if (m_pARTagTexture[i] == NULL)
			return E_FAIL;
		
		GSAutoLock lck(m_pARTagTexture[i]->GetGSCritSec());
		SAFE_RELEASE(m_pTmpSView);

		hr = m_pARTagTexture[i]->GetShaderResourceView(m_pTmpSView);
		SAFE_ADDREF(m_pTmpSView);
		SAFE_RELEASE(m_pTmpPlane);

		m_pTmpPlane = pARTagPlane;
		SAFE_ADDREF(m_pTmpPlane);

		hr = RenderMesh(pARTagPlane, m_pDeviceContext, m_pEffect);
		if (FAILED(hr))
			return hr;
	}
	m_pSwapChain->Present( 0, 0);

	return hr;
}

HRESULT GSARTagLayoutDisplay::RenderMesh(IGSMeshBase* pMesh, ID3D11DeviceContext* pDeviceContext, IGSEffectBase* pGSEffect, UINT idxTech)
{
	CAutoLock lck(&m_csParaSetting);
	if (pMesh == NULL || pGSEffect == NULL || pDeviceContext == NULL || m_pCBEffectSetting == NULL)
	{
		return E_FAIL;
	}
	HRESULT hr = S_OK;
	

	ID3D11Buffer* pVertexBuffer = pMesh->GetVertexBuffer();
	ID3D11Buffer* pIndexBuffer = pMesh->GetIndexBuffer();

	if (pVertexBuffer == NULL || pIndexBuffer == NULL)
		return E_FAIL;

	ID3DX11Effect* pEffect = pGSEffect->GetEffect();
	if (pEffect == NULL)
	{
		return E_FAIL;
	}
	D3DX11_TECHNIQUE_DESC tDesc;
	ID3DX11EffectPass* pPass = NULL;
	ID3DX11EffectTechnique* pTechnique = pEffect->GetTechniqueByIndex(0);
	if (pTechnique == NULL)
		return E_FAIL;
	pTechnique->GetDesc(&tDesc);

	D3D11_BUFFER_DESC indexDesc;

	pIndexBuffer->GetDesc(&indexDesc);
	UINT indexCount = indexDesc.ByteWidth / sizeof(UINT);

	UINT stride = pMesh->GetVertexStride();
	UINT offset = 0;
	ID3D11InputLayout* pLayout = NULL;
	pMesh->GetVertexLayout(pEffect, pLayout);

	pDeviceContext->IASetInputLayout(pLayout);
	pDeviceContext->IASetPrimitiveTopology(pMesh->GetPrimitiveTopology());
	pDeviceContext->IASetVertexBuffers( 0, 1, &pVertexBuffer, &stride, &offset );
	pDeviceContext->IASetIndexBuffer(pIndexBuffer, DXGI_FORMAT_R32_UINT, 0);

	hr = OnEffectSetting();

	for (int iPass = 0; iPass < tDesc.Passes; iPass++)
	{
		pPass = pTechnique->GetPassByIndex(iPass);
		pPass->Apply(0, pDeviceContext);
		pDeviceContext->DrawIndexed( indexCount, 0, 0);
	}
	//need to set the shader resource to NULL, or we will get a warning
	ID3D11ShaderResourceView *const pSRV[D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT] = {NULL};
	pDeviceContext->PSSetShaderResources(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT, pSRV);

	return S_OK;
}
HRESULT GSARTagLayoutDisplay::OnEffectSetting()
{
	CAutoLock lck(&m_csParaSetting);
	if (m_pEffect == NULL || m_pTmpSView == NULL || m_pTmpPlane == NULL)
		return E_FAIL;

	ID3DX11Effect* pEffect = m_pEffect->GetEffect();

	if (pEffect == NULL )
		return E_FAIL;

	HRESULT hr = S_OK;


	IGSCamera* pCamera = GetCamera();
	if (pCamera == NULL)
		return E_FAIL;

	ID3D11ShaderResourceView* pInTex = m_pTmpSView;

	if (pInTex == NULL)
		return E_FAIL;

	BOOL _bFlipY = 0;
	BOOL _bFlipX = 0;
	int _sampleType = 0;
	D3DXMATRIX matWarp;

	D3DXMATRIX matView = pCamera->GetViewMatrix();
	D3DXMATRIX matProj = pCamera->GetProjMatrix();
	D3DXMATRIX matWorld = m_pTmpPlane->GetTransform();
	D3DXMATRIX matWorldViewProj = matWorld * matView * matProj;
	D3DXVECTOR4 blackLevel(m_blackLevel, m_blackLevel, m_blackLevel, 1.0);

	GSEffectSettingEntry fxEntries[] = 
	{
		{"WorldViewProj", MATRIX, (void*)&matWorldViewProj, 0, sizeof(matWorldViewProj)},
		{"g_sampleType", SCALAR, (void*)&_sampleType, 0, sizeof(_sampleType)},
		{"g_bFlipX", SCALAR, (void*)&_bFlipX, 0, sizeof(_bFlipX)},
		{"g_bFlipY", SCALAR, (void*)&_bFlipY, 0, sizeof(_bFlipY)},
		{"g_Texture", RESOURCE, (void*)pInTex, 0, 0},
		{"g_minColor", VECTOR, (void*)&blackLevel, 0, sizeof(blackLevel)},
	};
	hr = _SetEffectPara(pEffect, fxEntries, ARRAYSIZE(fxEntries));

	return S_OK;
}

HRESULT GSARTagLayoutDisplay::_SetEffectPara(ID3DX11Effect* pEffect, GSEffectSettingEntry* pEntries, UINT nEntry)
{
	CAutoLock lck(&m_csParaSetting);
	if (pEffect == NULL || pEntries == NULL || nEntry == 0)
		return E_FAIL;
	for (int i =0; i < nEntry; i++)
	{
		if (pEntries[i].fxVariableType == SCALAR)
		{
			ID3DX11EffectVariable* pfxVariable = pEffect->GetVariableByName(pEntries[i].fxVariableName)->AsScalar();
			if (!pfxVariable->IsValid())
				return E_FAIL;
			pfxVariable->SetRawValue(pEntries[i].pAppVariable, pEntries[i].offsetAppVariable, pEntries[i].szAppVariable);
		}
		else if (pEntries[i].fxVariableType == VECTOR)
		{
			ID3DX11EffectVariable* pfxVariable = pEffect->GetVariableByName(pEntries[i].fxVariableName)->AsVector();
			if (!pfxVariable->IsValid())
				return E_FAIL;
			pfxVariable->SetRawValue(pEntries[i].pAppVariable, pEntries[i].offsetAppVariable, pEntries[i].szAppVariable);
		}
		else if (pEntries[i].fxVariableType == MATRIX)
		{
			ID3DX11EffectVariable* pfxVariable = pEffect->GetVariableByName(pEntries[i].fxVariableName)->AsMatrix();
			//Matrix Need Transpose
			D3DXMATRIX tMat = *(D3DXMATRIX*)pEntries[i].pAppVariable;
			D3DXMatrixTranspose(&tMat, &tMat);
			if (!pfxVariable->IsValid())
				return E_FAIL;
			pfxVariable->SetRawValue((void*)&tMat, pEntries[i].offsetAppVariable, pEntries[i].szAppVariable);
		}
		else if (pEntries[i].fxVariableType == RESOURCE)
		{
			ID3DX11EffectShaderResourceVariable * pfxResource = pEffect->GetVariableByName(pEntries[i].fxVariableName)->AsShaderResource();
			if (!pfxResource->IsValid())
				return E_FAIL;
			pfxResource->SetResource((ID3D11ShaderResourceView*)pEntries[i].pAppVariable);
		}
		else
		{
			return E_FAIL;
		}
	}
	return S_OK;
}

HRESULT GSARTagLayoutDisplay::initARLayout(UINT numLevel, UINT intMarkerBits, UINT intBorderBits, float intWidthBits)
{
	
	GSAutoLock lck(this->GetGSCritSec());
	CAutoLock lck0(&m_csParaSetting);

	float markerBits = intMarkerBits;
	float borderBits = intBorderBits;
	float WidthBits = intWidthBits;
	int numMarker = 0;
	for (int level = 1; level <= numLevel; level++)
	{
		float markerWidth = markerBits/WidthBits/level;
		int numX = cvRound( 1.0  / (markerWidth + borderBits/WidthBits/level));
		int numY = numX;
		numMarker += numX * numY;
	}
	if (numMarker > NUMARTAG)
	{
		return E_FAIL;
	}
	SAFE_DELETE(m_pLayout);
	m_pLayout = new GSARTagLayout();

	m_pLayout->m_nARTag = numMarker;

	m_minMarkerWidth = 1.0;

	m_pLayout->m_pARTag = new GSARTag[numMarker];

	int idx = -1;
	for (int level = 1; level <= numLevel; level++)
	{
		float markerWidth = markerBits/WidthBits/level;
		if (markerWidth < m_minMarkerWidth)
		{
			m_minMarkerWidth = markerWidth;
		}
		int numX = cvRound( 1.0  / (markerWidth + borderBits/WidthBits/level));
		int numY = numX;
		for (int i = 0; i < numY; i++)
		{
			for ( int j = 0; j < numX; j++ )
			{		
				idx++;
				m_pLayout->m_pARTag[idx].m_tagID = idx;
				m_pLayout->m_pARTag[idx].m_visible = (level == 1);
				m_pLayout->m_pARTag[idx].m_tagRect.LT = GSFPoint3D(0, 0, 0);
				m_pLayout->m_pARTag[idx].m_tagRect.LB = GSFPoint3D(0, -markerWidth, 0);
				m_pLayout->m_pARTag[idx].m_tagRect.RB = GSFPoint3D(markerWidth, -markerWidth, 0);
				m_pLayout->m_pARTag[idx].m_tagRect.RT = GSFPoint3D(markerWidth, 0, 0);

				float* matTran = m_pLayout->m_pARTag[idx].m_matTran;
				matTran[0] = 1.0; matTran[1] = 0.0; matTran[2] = 0.0; matTran[3] = 0;
				matTran[4] = 0.0; matTran[5] = 1.0; matTran[6] = 0.0; matTran[7] = 0;
				matTran[8] = 0.0; matTran[9] = 0.0; matTran[10] = 1.0; matTran[11] = 0.0;	
				matTran[12] =  0 + markerWidth*j + markerWidth/markerBits*(2*j+1); 
				matTran[13] =  0 - markerWidth*i - markerWidth/markerBits*(2*i+1); 
				matTran[14] = 0.0; matTran[15] = 1.0;	
			}
		}
	}
	generateAllMarkerRect();
	generateARTagMesh();
	generateIntersectTable();
	return true;
}

HRESULT GSARTagLayoutDisplay::generateARTagMesh()
{
	CAutoLock lck(&m_csParaSetting);
	if (m_pDevice == NULL || m_pDeviceContext == NULL || m_pSwapChain == NULL)
		return E_FAIL;
	if( m_pLayout == NULL)
		return E_FAIL;
	for (int i =0; i < NUMARTAG; i++)
	{
		SAFE_RELEASE(m_pARTagMesh[i]);
	}
	
	HRESULT hr = S_OK;


	for (int i =0; i < m_pLayout->m_nARTag; i++)
	{
		GS3DPlane* pTagMesh = new GS3DPlane(m_pDevice, m_pDeviceContext, m_pSwapChain); 
		GSFRect3D* pTagRect = &m_pLayout->m_pARTag[i].m_tagRect;
		
		D3DXVECTOR3 vLT = D3DXVECTOR3(pTagRect->LT.x, pTagRect->LT.y, pTagRect->LT.z);
		D3DXVECTOR3 vLB = D3DXVECTOR3(pTagRect->LB.x, pTagRect->LB.y, pTagRect->LB.z);
		D3DXVECTOR3 vRB = D3DXVECTOR3(pTagRect->RB.x, pTagRect->RB.y, pTagRect->RB.z);
		D3DXVECTOR3 vRT = D3DXVECTOR3(pTagRect->RT.x, pTagRect->RT.y, pTagRect->RT.z);

		GS3DPlane::CUSTOMVERTEX vertices[] = 
		{
			{vLT, D3DXVECTOR3(0, 0, -1), 0.0, 0.0},
			{vLB, D3DXVECTOR3(0, 0, -1), 0.0, 1.0},
			{vRB, D3DXVECTOR3(0, 0, -1), 1.0, 1.0},
			{vRT, D3DXVECTOR3(0, 0, -1), 1.0, 0.0}
		};
		
		DWORD indices[] =
		{
			0,1,2,
			0,2,3
		};
		hr = pTagMesh->InitGeometry(vertices, sizeof(vertices), indices, sizeof(indices));
		if (FAILED(hr))
		{
			SAFE_DELETE(pTagMesh);
			return hr;
		}
		D3DXMATRIX matTran;
		for (int row = 0; row < 4; row++)
		{
			for(int col =0; col<4; col++)
			{
				matTran.m[row][col] = m_pLayout->m_pARTag[i].m_matTran[row*4 + col];
			}
		}
		pTagMesh->SetTransform(&matTran);
		m_pARTagMesh[i] = pTagMesh;
	}
	
	return S_OK;
}

HRESULT GSARTagLayoutDisplay::generateAllMarkerRect()
{
	if (m_pLayout == NULL)
		return E_FAIL;
	HRESULT hr = S_OK;
	for (int i =0; i < NUMARTAG; i++)
	{
		SAFE_DELETE(m_allMarkerRects[i]);
	}
	for (int i =0; i < m_pLayout->m_nARTag; i++)
	{
		GSBoundingBox2D* bbox = new GSBoundingBox2D();
		hr = m_pLayout->m_pARTag[i].GetBoundingBox2D(*bbox, TRUE);
		if (FAILED(hr))
			return E_FAIL;
		
		m_allMarkerRects[i] = bbox;
	}
	return S_OK;

}

HRESULT GSARTagLayoutDisplay::generateIntersectTable()
{
	CAutoLock lck(&m_csParaSetting);
	if (m_pLayout == NULL)
		return E_FAIL;
	m_TagIntersectTable.clear();
	for (int idx =0; idx < m_pLayout->m_nARTag; idx++)
	{
		vector<int> intersectList;
		GSARTag* curMarker = &m_pLayout->m_pARTag[idx];
		GSBoundingBox2D curRect;
		m_pLayout->m_pARTag[idx].GetBoundingBox2D(curRect, TRUE);
		
		for (int intersectIdx = 0 ; intersectIdx < m_pLayout->m_nARTag; intersectIdx++)
		{
			if (intersectIdx == idx)
				continue;
			GSBoundingBox2D intersectRECT;
			m_pLayout->m_pARTag[intersectIdx].GetBoundingBox2D(intersectRECT, TRUE);
			//avoid miss charge because the float accuracy.
			intersectRECT.LT.x += 0.0001;
			intersectRECT.LT.y -= 0.0001;
			intersectRECT.RB.x -= 0.0001;
			intersectRECT.RB.y += 0.0001;

			if (curRect.IsIntersect(intersectRECT))
			{
				intersectList.push_back(intersectIdx);
			}
		}
		m_TagIntersectTable.push_back(intersectList);
	}
	return S_OK;
}

HRESULT GSARTagLayoutDisplay::LoadARTagTexture()
{
	CAutoLock lck(&m_csParaSetting);
	if (m_pDevice == NULL || m_pDeviceContext == NULL || m_pSwapChain == NULL)
	{
		return E_FAIL;
	}
	
	for (int i =0; i < NUMARTAG; i++)
	{
		SAFE_RELEASE(m_pARTagTexture[i]);
	}

	HRESULT hr = S_OK;
	WCHAR str[MAX_PATH] = {0};
	HMODULE module = GetModule();
	GetModuleFileName(module, str, MAX_PATH);
	// Gets filename
	WCHAR* pszFile = wcsrchr(str, '\\');
	pszFile++;    // Moves on from \
	// Get path
	WCHAR szPath[MAX_PATH] = L"";
	wcsncat(szPath, str, pszFile - str);

	for (int i =0; i < NUMARTAG; i++)
	{
		swprintf_s(str, MAX_PATH, L"%s..\\..\\mediaFiles\\ARTagAllMarkers\\marker_%03d.png", szPath, i);

		D3DX11_IMAGE_INFO imgInfo;
		hr = D3DX11GetImageInfoFromFile(str, NULL, &imgInfo, NULL);
		if (FAILED(hr))
			return hr;
		D3DX11_IMAGE_LOAD_INFO imgLoadInfo;
		imgLoadInfo.Width = imgInfo.Width;
		imgLoadInfo.Height = imgInfo.Height;
		imgLoadInfo.Depth = imgInfo.Depth;
		imgLoadInfo.FirstMipLevel = 0;
		imgLoadInfo.Usage = D3D11_USAGE_DEFAULT;
		imgLoadInfo.BindFlags = D3D11_BIND_SHADER_RESOURCE;
		imgLoadInfo.CpuAccessFlags = 0;
		imgLoadInfo.MiscFlags = 0;
		imgLoadInfo.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
		imgLoadInfo.Filter = D3DX11_FILTER_POINT;
		imgLoadInfo.MipFilter = D3DX11_FILTER_POINT;
		imgLoadInfo.pSrcInfo = &imgInfo;

		GSTexture2D* pTex = new GSTexture2D(m_pDevice, m_pDeviceContext, m_pSwapChain);

		hr = pTex->LoadFromImageFile(str, &imgLoadInfo);
		if (FAILED(hr))
			return hr;
		m_pARTagTexture[i] = pTex;
	}

	return S_OK;
}

int GSARTagLayoutDisplay::GetNumMarker()
{
	CAutoLock lck(&m_csParaSetting);
	if (m_pLayout == NULL)
		return 0;
	return m_pLayout->m_nARTag;
}

HRESULT GSARTagLayoutDisplay::SetMarkerVisible(int idx, BOOL bVisible)
{
	CAutoLock lck(&m_csParaSetting);
	if (m_pLayout == NULL || m_pLayout->m_nARTag <= idx)
		return E_FAIL;

	m_pLayout->m_pARTag[idx].m_visible = bVisible;
	return S_OK;
}
HRESULT GSARTagLayoutDisplay::SetMarkerVisibleByID(int id, BOOL bVisible)
{
	CAutoLock lck(&m_csParaSetting);
	if (m_pLayout == NULL)
		return E_FAIL;

	for (int i = 0; i < m_pLayout->m_nARTag; i++)
	{
		if (m_pLayout->m_pARTag[i].m_tagID == id)
		{
			m_pLayout->m_pARTag[i].m_visible = bVisible;
			return S_OK;
		}
	}
	return S_FALSE;
}
int GSARTagLayoutDisplay::GetMarkerID(int idx)
{
	CAutoLock lck(&m_csParaSetting);
	if (m_pLayout == NULL)
		return -1;
	if (m_pLayout == NULL || m_pLayout->m_nARTag <= idx)
		return -1;

	return m_pLayout->m_pARTag[idx].m_tagID;
}


HRESULT GSARTagLayoutDisplay::DecideLayout(GSBoundingBox2D* camRects, UINT numCamRect,
							 GSBoundingBox2D* fingerRects, UINT numFingerRects, BOOL& bChanged, float fingerExtend)
{
	if (m_pLayout == NULL)
		return E_FAIL;

	CAutoLock lck(&m_csParaSetting);
	map<int, bool> decisionMap; // idx, visible, have decided?
	vector<int> undecideIdx;
	bChanged = FALSE;
	for (int idx = 0; idx < m_pLayout->m_nARTag; idx++)
	{
		undecideIdx.push_back(idx);
	}
	//Extenr Finger Rectangle

	for (int i=0; i< numFingerRects; i++)
	{
		fingerRects[i].LT.x -= fingerExtend;
		fingerRects[i].RB.x += fingerExtend;
		fingerRects[i].LT.y -= fingerExtend;
		fingerRects[i].RB.y += fingerExtend;
	}

	if (numFingerRects > 0 && fingerRects != NULL)
	{
		GSBoundingBox2D* pMarkerRect = NULL;
		for (int i = 0; i < numFingerRects; i++)
		{
			for (int iterIdx = 0; iterIdx < undecideIdx.size(); iterIdx++)
			{	
				int idx = undecideIdx.at(iterIdx);		
				pMarkerRect = m_allMarkerRects[idx];
				if (pMarkerRect->IsIntersect(fingerRects[i]))
				{
					decisionMap[idx] = false;
					undecideIdx.erase(undecideIdx.begin() + iterIdx);
					iterIdx--;
				}
			}
		
		}
	}
	
	if (numCamRect > 0 && camRects != NULL)
	{
		for (int i = 0 ; i < numCamRect; i++) //Clip out of boundary part
		{
			camRects[i].LT.x = min((float)1.0, max((float)0.0, camRects[i].LT.x));
			camRects[i].RB.x = min((float)1.0, max((float)0.0, camRects[i].RB.x));
			camRects[i].LT.y = min((float)1.0, max((float)0.0, camRects[i].LT.y));
			camRects[i].RB.y = min((float)1.0, max((float)0.0, camRects[i].RB.y));
		}
		//sort by area
		for (int i = 0 ; i < numCamRect-1; i++) //Clip out of boundary part
		{
			
			for (int j = 0; j < numCamRect -1 -i; j++)
			{
				GSBoundingBox2D tmpA = camRects[j];
				GSBoundingBox2D tmpB = camRects[j+1];
				if (tmpA.GetArea() > tmpB.GetArea())
				{
					camRects[j] = tmpB;
					camRects[j+1] = tmpA;
				}
			}
		}
		
		for (int i = 0; i < numCamRect; i++) // for each cam view
		{
			float camViewWidth = abs(camRects->RB.x - camRects->LT.x);
			float camViewHeight = abs(camRects->RB.y - camRects->LT.y);
			if (camViewHeight <= 0 || camViewWidth <= 0)
			{
				continue;
			}
			float idealArea = max((float)(m_minMarkerWidth*m_minMarkerWidth*0.95), (float)(camViewWidth/4 * camViewHeight/4));
			for (int iterIdx = 0; iterIdx < undecideIdx.size(); iterIdx++)
			{
				int idx = undecideIdx.at(iterIdx);
				GSBoundingBox2D* myRECT = NULL;
				myRECT = m_allMarkerRects[idx];
				float myArea = abs((myRECT->RB.x - myRECT->LT.x) * (myRECT->RB.y - myRECT->LT.y));
				if ((myArea < idealArea) && myRECT->IsIntersect(camRects[i]))  // in camview && area < ideaArea && not decided yet
				{
					bool bPlaceTaken = false;
					
					for (map<int, bool>::iterator iter = decisionMap.begin(); 
						iter != decisionMap.end(); iter++) // check if this place have be taken by other Tag
					{
						if (iter->second == false)
							continue;

						GSBoundingBox2D* decidedRECT;
						decidedRECT = m_allMarkerRects[iter->first];
						if ( decidedRECT->IsIntersect(*myRECT))
						{
							bPlaceTaken = true;
							break;
						}
					}
					if (bPlaceTaken)
					{
						decisionMap[idx] = false;
						undecideIdx.erase(undecideIdx.begin() + iterIdx);
						iterIdx--;
					}
					else
					{
						decisionMap[idx] = true;
						undecideIdx.erase(undecideIdx.begin() + iterIdx);
						iterIdx--;
					}
				}
			}
			
		}
	}
	
	for (int iterIdx = 0; iterIdx < undecideIdx.size(); iterIdx++)
	{
		int idx = undecideIdx.at(iterIdx);
		bool bPlaceTaken = false;
		for (int i = 0; i < m_TagIntersectTable[idx].size(); i++)
		{
			int intersectIdx = m_TagIntersectTable[idx][i];
			if (decisionMap.find(intersectIdx) != decisionMap.end())
			{
				if (decisionMap[m_TagIntersectTable[idx][i]] == true)
				{
					bPlaceTaken = true;
					break;
				}
			}
		}
		if (bPlaceTaken)
		{
			decisionMap[idx] = false;
			undecideIdx.erase(undecideIdx.begin() + iterIdx);
			iterIdx--;
		}
		else
		{
			decisionMap[idx] = true;
			undecideIdx.erase(undecideIdx.begin() + iterIdx);
			iterIdx--;
		}
	}
	
	for (map<int, bool>::iterator iter = decisionMap.begin(); 
		iter != decisionMap.end(); iter++)
	{
		if (m_pLayout->m_pARTag[iter->first].m_visible != iter->second)
		{
			bChanged = TRUE;
		}
		m_pLayout->m_pARTag[iter->first].m_visible = iter->second;
	}

	return S_OK;
}

HRESULT GSARTagLayoutDisplay::GetLayout(GSARTagLayout*& pLayout)
{
	CAutoLock lck(&m_csParaSetting);
	SAFE_DELETE(pLayout);
	if (m_pLayout == NULL)
		return E_FAIL;
	pLayout = new GSARTagLayout();
	*pLayout = *m_pLayout;
	return S_OK;
}

float GSARTagLayoutDisplay::GetBlackLevel()
{
	CAutoLock lck(&m_csParaSetting);
	return m_blackLevel;
}
HRESULT GSARTagLayoutDisplay::SetBlackLevel(float level)
{
	CAutoLock lck(&m_csParaSetting);
	if (level > 1.0 || level < 0)
		return E_FAIL;
	m_blackLevel = level;
	return S_OK;
}
