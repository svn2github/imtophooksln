#include "stdafx.h"
#include "HookDS.h"
HookDS::HookDS(void)
{
	m_pHookFilter = NULL;
	m_pIHookFilter = NULL;
	for (int i =0; i < NUMHOOKPIN; i++)
	{
		m_pHookOutputPin[i] = NULL;
		m_pIHookOutputPin[i] = NULL;
		m_pWarpFilter[i] = NULL;
		m_pIWarpFilter[i] = NULL;
		m_pWarpInputPin[i] = NULL;
		m_pWarpOutputPin[i] = NULL;
		
		/*
		m_pH264Encoder[i] = NULL;
		m_pH264EncoderInputPin[i] = NULL;
		m_pH264EncoderOutputPin[i] = NULL;
		*/

		m_pSampleGrabber[i] = NULL;
		m_pISampleGrabber[i] = NULL;
		m_pSampleGrabberInputPin[i] = NULL;
		m_pSampleGrabberOutputPin[i];

		m_pDXRenderFilter[i] = NULL;
		m_pIDXRenderFilter[i] = NULL;
		m_pDXRenderInputPin[i] = NULL;
	}
}
HookDS::~HookDS(void)
{
	UnInitDS();
}
HRESULT HookDS::UnInitDS()
{
	m_pHookFilter = NULL;
	m_pIHookFilter = NULL;
	for (int i =0; i < NUMHOOKPIN; i++)
	{
		m_pHookOutputPin[i] = NULL;
		m_pIHookOutputPin[i] = NULL;

		m_pWarpFilter[i] = NULL;
		m_pIWarpFilter[i] = NULL;
		m_pWarpInputPin[i] = NULL;
		m_pWarpOutputPin[i] = NULL;

		/*m_pH264Encoder[i] = NULL;
		m_pH264EncoderInputPin[i] = NULL;
		m_pH264EncoderOutputPin[i] = NULL;
		*/
		m_pSampleGrabber[i] = NULL;
		m_pISampleGrabber[i] = NULL;
		m_pSampleGrabberInputPin[i] = NULL;
		m_pSampleGrabberOutputPin[i];

		m_pDXRenderFilter[i] = NULL;
		m_pIDXRenderFilter[i] = NULL;
		m_pDXRenderInputPin[i] = NULL;
	}
	return S_OK;
}


HRESULT HookDS::ConnectGraph()
{
	HRESULT hr = S_OK;
	WCHAR str[MAX_PATH] = {0};
	m_pGraph->AddFilter(m_pHookFilter, L"Hook");
	ShowFilterProp(m_pHookFilter);
	for (int i = 0; i < NUMHOOKPIN; i++)
	{
		ShowFilterProp(m_pHookOutputPin[i]);
		swprintf_s(str, MAX_PATH, L"HomoWarp%d", i);
		hr = m_pGraph->AddFilter(m_pWarpFilter[i], str);
		hr = m_pGraph->Connect(m_pHookOutputPin[i], m_pWarpInputPin[i]);
		/*
		swprintf_s(str, MAX_PATH, L"H264 Encoder %d", i);
		hr = m_pGraph->AddFilter(m_pH264Encoder[i], str);
		hr = m_pGraph->Connect(m_pWarpOutputPin[i], m_pH264EncoderInputPin[i]);
		*/
		swprintf_s(str, MAX_PATH, L"SampleGrabber %d", i);
		hr = m_pGraph->AddFilter(m_pSampleGrabber[i], str);
		hr = m_pGraph->Connect(m_pWarpOutputPin[i], m_pSampleGrabberInputPin[i]);

		swprintf_s(str, MAX_PATH, L"DXRender %d", i);
		hr = m_pGraph->AddFilter(m_pDXRenderFilter[i], str);
		hr = m_pGraph->Connect(m_pSampleGrabberOutputPin[i], m_pDXRenderInputPin[i]);
	}

	return S_OK;
}
HRESULT HookDS::CreateFilters()
{
	HRESULT hr = __super::CreateFilters();
	WCHAR str[MAX_PATH] = {0};
	hr = CoCreateInstance(CLSID_HookDrawingFilter, NULL, CLSCTX_INPROC_SERVER, 
		IID_IBaseFilter, (LPVOID *)&m_pHookFilter);
	hr = m_pHookFilter->QueryInterface(IID_IHookDrawingFilter,(LPVOID *) &m_pIHookFilter);
	for (int i =0; i < NUMHOOKPIN; i++)
	{
		swprintf_s(str, MAX_PATH, L"d3dsurf%d", i);
		hr = m_pHookFilter->FindPin(str, &m_pHookOutputPin[i]);
		hr = m_pHookOutputPin[i]->QueryInterface(IID_IHookDrawingStream, (LPVOID*)&(m_pIHookOutputPin[i]));

	}
	for (int i =0; i < NUMHOOKPIN; i++)
	{
		hr = CoCreateInstance(CLSID_HomoWarpFilter, NULL, CLSCTX_INPROC_SERVER, 
			IID_IBaseFilter, (LPVOID *)&m_pWarpFilter[i]);
		hr = m_pWarpFilter[i]->QueryInterface(IID_IHomoWarpFilter, (LPVOID *)&m_pIWarpFilter[i]);
		hr = m_pWarpFilter[i]->FindPin(L"input", &m_pWarpInputPin[i]);
		hr = m_pWarpFilter[i]->FindPin(L"output", &m_pWarpOutputPin[i]);
	}
	///*
	//for (int i =0; i < NUMHOOKPIN; i++)
	//{
	//	hr = CoCreateInstance(CLSID_LMH264Encoder, NULL, CLSCTX_INPROC_SERVER, 
	//		IID_IBaseFilter, (LPVOID *)&m_pH264Encoder[i]);
	//	IEnumPins* pEnumPin = NULL; IPin* pPin = NULL;
	//	hr = m_pH264Encoder[i]->EnumPins(&pEnumPin);
	//	for ( int c = 0; c < 2; c++ )
	//	{
	//		PIN_INFO pinInfo;
	//		pEnumPin->Next(1, &pPin, NULL);
	//		pPin->QueryPinInfo(&pinInfo);
	//		if (pinInfo.dir ==  PINDIR_INPUT)
	//		{
	//			m_pH264EncoderInputPin[i] = pPin;
	//		}
	//		else
	//		{
	//			m_pH264EncoderOutputPin[i] = pPin;
	//		}
	//		if (pinInfo.pFilter != NULL)
	//		{
	//			pinInfo.pFilter->Release();
	//			pinInfo.pFilter = NULL;
	//		}
	//	}
	//	if (pEnumPin != NULL)
	//	{
	//		pEnumPin->Release();
	//		pEnumPin = NULL;
	//	}
	//	
	//}
	//*/
	for (int i =0; i < NUMHOOKPIN; i++)
	{
		hr = CoCreateInstance(CLSID_SampleGrabber, NULL, CLSCTX_INPROC_SERVER, 
			IID_IBaseFilter, (LPVOID *)&m_pSampleGrabber[i]);
		hr = m_pSampleGrabber[i]->QueryInterface(IID_ISampleGrabber, (void**)&(m_pISampleGrabber[i]));
		IEnumPins* pEnumPin = NULL; IPin* pPin = NULL;
		hr = m_pSampleGrabber[i]->EnumPins(&pEnumPin);
		for ( int c = 0; c < 2; c++ )
		{
			PIN_INFO pinInfo;
			pEnumPin->Next(1, &pPin, NULL);
			pPin->QueryPinInfo(&pinInfo);
			if (pinInfo.dir ==  PINDIR_INPUT)
			{
				m_pSampleGrabberInputPin[i] = pPin;
			}
			else
			{
				m_pSampleGrabberOutputPin[i] = pPin;
			}
			if (pinInfo.pFilter != NULL)
			{
				pinInfo.pFilter->Release();
				pinInfo.pFilter = NULL;
			}
		}
		if (pEnumPin != NULL)
		{
			pEnumPin->Release();
			pEnumPin = NULL;
		}
	}
	for (int i =0; i < NUMHOOKPIN; i++)
	{
		hr = CoCreateInstance(CLSID_DXRenderFilter, NULL, CLSCTX_INPROC_SERVER, 
			IID_IBaseFilter, (LPVOID *)&m_pDXRenderFilter[i]);
		hr = m_pDXRenderFilter[i]->QueryInterface(IID_IDXRenderer,(LPVOID *)&m_pIDXRenderFilter[i]);
		hr = m_pDXRenderFilter[i]->FindPin(L"In", &m_pDXRenderInputPin[i]);	
	}

	return S_OK;
}
HRESULT HookDS::ConfigFilters()
{
	for (int i =0; i < NUMHOOKPIN; i++)
	{
		m_pIWarpFilter[i]->SetIsFlipY(false);
		m_pISampleGrabber[i]->SetBufferSamples(TRUE);
	}
	return S_OK;
}

HRESULT HookDS::ShowHookFilterProp()
{
	if (m_pHookFilter == NULL)
		return E_FAIL;
	return ShowFilterProp(m_pHookFilter);
}
HRESULT HookDS::ShowHookPinProp(int idx)
{
	if ( idx < 0 || idx >= NUMHOOKPIN || m_pHookOutputPin[idx] == NULL)
		return E_FAIL;
	return ShowFilterProp(m_pHookOutputPin[idx]);
}
HRESULT HookDS::ShowDXRenderProp(int idx)
{
	if ( idx < 0 || idx >= NUMHOOKPIN || m_pDXRenderFilter[idx] == NULL)
		return E_FAIL;
	return ShowFilterProp(m_pDXRenderFilter[idx]);
}
HRESULT HookDS::ShowWarpProp(int idx)
{
	if ( idx < 0 || idx >= NUMHOOKPIN || m_pWarpFilter[idx] == NULL)
		return E_FAIL;
	return ShowFilterProp(m_pWarpFilter[idx]);
}


const D3DXMATRIX* HookDS::GetHookPinWarpMatrix(int idx)
{
	if (idx < 0 || idx >= NUMHOOKPIN)
		return NULL;
	if (m_pIHookOutputPin[idx] == NULL)
	{
		return NULL;
	}
	return m_pIHookOutputPin[idx]->GetWarpMatrix();
}
BOOL HookDS::SetHookPinWarpMatrix(int idx, const D3DXMATRIX& mat)
{
	if (idx < 0 || idx >= NUMHOOKPIN)
		return FALSE;
	if (m_pIHookOutputPin[idx] == NULL)
	{
		return FALSE;
	}
	return m_pIHookOutputPin[idx]->SetWarpMatrix(mat);
}
BOOL HookDS::SetHookPinWarpByPts(int idx, const D3DXVECTOR2& lt, const D3DXVECTOR2& lb,
								 const D3DXVECTOR2& rb, const D3DXVECTOR2& rt)
{
	if (idx < 0 || idx >= NUMHOOKPIN)
		return FALSE;
	if (m_pIHookOutputPin[idx] == NULL)
	{
		return FALSE;
	}
	return m_pIHookOutputPin[idx]->SetWarpByPts(lt, lb, rb, rt);
}
BOOL HookDS::GetHookPinWarpPts(int idx, D3DXVECTOR2& lt, D3DXVECTOR2& lb, D3DXVECTOR2& rb, 
							   D3DXVECTOR2& rt)
{
	if (idx < 0 || idx >= NUMHOOKPIN)
		return FALSE;
	if (m_pIHookOutputPin[idx] == NULL)
	{
		return FALSE;
	}
	return m_pIHookOutputPin[idx]->GetWarpPts(lt, lb, rb, rt);
}
BOOL HookDS::GetHookPinResolution(int idx, UINT& resW, UINT& resH)
{
	if (idx < 0 || idx >= NUMHOOKPIN)
		return FALSE;
	if (m_pIHookOutputPin[idx] == NULL)
	{
		return FALSE;
	}
	return m_pIHookOutputPin[idx]->GetResolution(resW, resH);
}
BOOL HookDS::SetHookPinResolution(int idx, UINT resW, UINT resH)
{
	if (idx < 0 || idx >= NUMHOOKPIN)
		return FALSE;
	if (m_pIHookOutputPin[idx] == NULL)
	{
		return FALSE;
	}
	return m_pIHookOutputPin[idx]->SetResolution(resW, resH);
}
float HookDS::GetHookPinFrameRate(int idx)
{
	if (idx < 0 || idx >= NUMHOOKPIN)
		return 120;
	if (m_pIHookOutputPin[idx] == NULL)
	{
		return 120;
	}
	return m_pIHookOutputPin[idx]->GetFrameRate();
}
BOOL HookDS::SetHookPinFrameRate(int idx, float fps)
{
	if (idx < 0 || idx >= NUMHOOKPIN)
		return FALSE;
	if (m_pIHookOutputPin[idx] == NULL)
	{
		return FALSE;
	}
	return m_pIHookOutputPin[idx]->SetFrameRate(fps);
}
BOOL HookDS::GetHookSourceResolution(UINT& w, UINT& h)
{
	if (m_pIHookFilter == NULL)
		return FALSE;
	return m_pIHookFilter->GetSourceResolution(w, h);
}
BOOL HookDS::SetHookSourceResolution(UINT w, UINT h)
{
	if (m_pIHookFilter == NULL)
		return FALSE;
	return m_pIHookFilter->SetSourceResolution(w, h);
}
//Warp APIs

HRESULT HookDS::SetWarpVertex(int idx, float LTx, float LTy, float LBx, float LBy, 
							  float RBx, float RBy, float RTx, float RTy)
{
	if (idx < 0 || idx >= NUMHOOKPIN)
		return FALSE;
	if (m_pIWarpFilter[idx] == NULL)
	{
		return FALSE;
	}
	return m_pIWarpFilter[idx]->SetWarpVertex(LTx, LTy, LBx, LBy, RBx, RBy, RTx, RTy);
}
HRESULT HookDS::GetWarpVertex(int idx, float& LTx, float& LTy, float& LBx, float& LBy, 
							  float& RBx, float& RBy, float& RTx, float& RTy)
{
	if (idx < 0 || idx >= NUMHOOKPIN)
		return E_FAIL;
	if (m_pIWarpFilter[idx] == NULL)
	{
		return E_FAIL;
	}
	return m_pIWarpFilter[idx]->GetWarpVertex(LTx, LTy, LBx, LBy, RBx, RBy, RTx, RTy);
}
HRESULT HookDS::SetWarpMatrix(int idx, const D3DXMATRIX& mat)
{
	if (idx < 0 || idx >= NUMHOOKPIN)
		return E_FAIL;
	if (m_pIWarpFilter[idx] == NULL)
	{
		return E_FAIL;
	}
	return m_pIWarpFilter[idx]->SetWarpMatrix(mat);
}
HRESULT HookDS::GetWarpMatrix(int idx, D3DXMATRIX& mat)
{
	if (idx < 0 || idx >= NUMHOOKPIN)
		return E_FAIL;
	if (m_pIWarpFilter[idx] == NULL)
	{
		return E_FAIL;
	}
	return m_pIWarpFilter[idx]->GetWarpMatrix(mat);
}
bool HookDS::GetWarpIsFlipY(int idx)
{
	if (idx < 0 || idx >= NUMHOOKPIN)
		return false;
	if (m_pIWarpFilter[idx] == NULL)
	{
		return false;
	}
	return m_pIWarpFilter[idx]->GetIsFlipY();
}
bool HookDS::SetWarpIsFlipY(int idx, bool bFlipY)
{
	if (idx < 0 || idx >= NUMHOOKPIN)
		return false;
	if (m_pIWarpFilter[idx] == NULL)
	{
		return false;
	}
	return m_pIWarpFilter[idx]->SetIsFlipY(bFlipY);
}
bool HookDS::GetIsInvWarp(int idx)
{
	if (idx < 0 || idx >= NUMHOOKPIN)
		return false;
	if (m_pIWarpFilter[idx] == NULL)
	{
		return false;
	}
	return m_pIWarpFilter[idx]->GetIsInvWarp();
}
bool HookDS::SetIsInvWarp(int idx, bool bInv)
{
	if (idx < 0 || idx >= NUMHOOKPIN)
		return false;
	if (m_pIWarpFilter[idx] == NULL)
	{
		return false;
	}
	return m_pIWarpFilter[idx]->SetIsInvWarp(bInv);
}

//SampleGrabber API
HRESULT HookDS::SetCallback(int idx, ISampleGrabberCB *pCallback, long WhichMethodToCallback)
{
	if (idx < 0 || idx >= NUMHOOKPIN)
		return E_FAIL;
	if (m_pISampleGrabber[idx] == NULL)
	{
		return E_FAIL;
	}
	return m_pISampleGrabber[idx]->SetCallback(pCallback, WhichMethodToCallback);
}
HRESULT HookDS::SetOneShot(int idx, BOOL OneShot)
{
	if (idx < 0 || idx >= NUMHOOKPIN)
		return E_FAIL;
	if (m_pISampleGrabber[idx] == NULL)
	{
		return E_FAIL;
	}
	return m_pISampleGrabber[idx]->SetOneShot(OneShot);
}
HRESULT HookDS::GetConnectedMediaType( int idx,	AM_MEDIA_TYPE *pType)
{
	if (idx < 0 || idx >= NUMHOOKPIN)
		return E_FAIL;
	if (m_pISampleGrabber[idx] == NULL)
	{
		return E_FAIL;
	}
	return m_pISampleGrabber[idx]->GetConnectedMediaType(pType);
}
HRESULT HookDS::SetBufferSamples(int idx, BOOL BufferThem)
{
	if (idx < 0 || idx >= NUMHOOKPIN)
		return E_FAIL;
	if (m_pISampleGrabber[idx] == NULL)
	{
		return E_FAIL;
	}
	return m_pISampleGrabber[idx]->SetBufferSamples(BufferThem);
}
HRESULT HookDS::GetCurrentBuffer( int idx, /* [out][in] */ long *pBufferSize,
								 /* [out] */ long *pBuffer)
{
	if (idx < 0 || idx >= NUMHOOKPIN)
		return E_FAIL;
	if (m_pISampleGrabber[idx] == NULL)
	{
		return E_FAIL;
	}
	return m_pISampleGrabber[idx]->GetCurrentBuffer(pBufferSize, pBuffer);
}
HRESULT HookDS::GetCurrentSample(int idx, IMediaSample **ppSample)
{
	if (idx < 0 || idx >= NUMHOOKPIN)
		return E_FAIL;
	if (m_pISampleGrabber[idx] == NULL)
	{
		return E_FAIL;
	}
	return m_pISampleGrabber[idx]->GetCurrentSample(ppSample);
}