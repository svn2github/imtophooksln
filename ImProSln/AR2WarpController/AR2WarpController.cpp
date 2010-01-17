#include "stdafx.h"
#include "AR2WarpController.h"
#include "AR2WarpControllerProp.h"
#include "MyMediaSample.h"
#include <d3dx9math.h>
#include "cv.h"
AR2WarpController::AR2WarpController(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData)
: CMuxTransformFilter(NAME("AR2WarpController"), 0, CLSID_AR2WarpController)
{ 
	
}
AR2WarpController::~AR2WarpController()
{

}

CUnknown *WINAPI AR2WarpController::CreateInstance(LPUNKNOWN punk, HRESULT *phr)
{
	ASSERT(phr);
	// assuming we don't want to modify the data
	AR2WarpController *pNewObject = new AR2WarpController(punk, phr, FALSE);

	if(pNewObject == NULL) {
		if (phr)
			*phr = E_OUTOFMEMORY;
	}
	return pNewObject;
}


HRESULT AR2WarpController::NonDelegatingQueryInterface(REFIID iid, void **ppv)
{
	if (iid == IID_IAR2WarpController) 
	{
		return GetInterface(static_cast<IAR2WarpController*>(this), ppv);
	}
	if (iid == IID_ISpecifyPropertyPages)
	{
		return GetInterface(
			static_cast<ISpecifyPropertyPages*>(this),	ppv);
	}
	else
	{
		// Call the parent class.
		return CBaseFilter::NonDelegatingQueryInterface(iid, ppv);
	}
}

HRESULT AR2WarpController::Receive(IMediaSample *pSample, const IPin* pReceivePin)
{
	if (m_pOutputPins.size() <= 0 )
	{
		return S_FALSE;
	}
	if (m_pInputPins.size() >= 1 && m_pInputPins[0] == pReceivePin)
	{

		CMediaSample* pCSample = (CMediaSample*)pSample;
		ARTagResultData* pARResult = NULL;
		pCSample->GetPointer((BYTE**)&pARResult);
		if (pARResult == NULL)
		{
			return S_FALSE;
		}
		if (pARResult->m_nDetected <= 0)
		{
			return S_FALSE;
		}

	    CMuxTransformInputPin* pin = (CMuxTransformInputPin*)pReceivePin;
	
		float w = pARResult->m_screenW;
		float h = pARResult->m_screenH;

		WCHAR str[MAX_PATH];

		float s[] = {0,0,0,
			0,0,0,
			0,0,0};
		CvMat mat = cvMat(3,3, CV_32F, &s);
		float* t = (float*)malloc(4*2*pARResult->m_nDetected*sizeof(float));
		float* d = (float*)malloc(4*2*pARResult->m_nDetected*sizeof(float));
		int nValidDetected = 0;
		memset(t,0,4*2*pARResult->m_nDetected*sizeof(float));
		memset(d,0,4*2*pARResult->m_nDetected*sizeof(float));

		for (int i = 0; i< pARResult->m_nDetected; i++)
		{
			ARMultiEachMarkerInfoT* pcfgMarker = NULL;
			for (int j =0; j< pARResult->m_pMarkerConfig->marker_num; j++)
			{
				if (pARResult->m_pMarkerConfig->marker[j].patt_id == pARResult->m_pDetectedMarks[i].id)
				{
					pcfgMarker = &(pARResult->m_pMarkerConfig->marker[j]);
					break;
				}	
			}
			if (pcfgMarker == NULL)
			{
				continue;
			}

			const ARFloat* arV[4]= {NULL};
			
			switch (pARResult->m_pDetectedMarks[i].dir)
			{
			case 0:
				arV[0] = pARResult->m_pDetectedMarks[i].vertex[2];
				arV[1] = pARResult->m_pDetectedMarks[i].vertex[3];
				arV[2] = pARResult->m_pDetectedMarks[i].vertex[0];
				arV[3] = pARResult->m_pDetectedMarks[i].vertex[1];
				break;
			case 1:
				arV[0] = pARResult->m_pDetectedMarks[i].vertex[1];
				arV[1] = pARResult->m_pDetectedMarks[i].vertex[2];
				arV[2] = pARResult->m_pDetectedMarks[i].vertex[3];
				arV[3] = pARResult->m_pDetectedMarks[i].vertex[0];
				break;
			case 2:
				arV[0] = pARResult->m_pDetectedMarks[i].vertex[0];
				arV[1] = pARResult->m_pDetectedMarks[i].vertex[1];
				arV[2] = pARResult->m_pDetectedMarks[i].vertex[2];
				arV[3] = pARResult->m_pDetectedMarks[i].vertex[3];
				break;
			case 3:
				arV[0] = pARResult->m_pDetectedMarks[i].vertex[3];
				arV[1] = pARResult->m_pDetectedMarks[i].vertex[0];
				arV[2] = pARResult->m_pDetectedMarks[i].vertex[1];
				arV[3] = pARResult->m_pDetectedMarks[i].vertex[2];
				break;
			default:

				continue;
				break;
			}
			nValidDetected++;
			D3DXVECTOR2 v[4] = {D3DXVECTOR2(0,0)};
			D3DXVECTOR2 center;
			
			v[0].x = arV[0][0]; v[0].y = arV[0][1];
			v[1].x = arV[1][0]; v[1].y = arV[1][1];
			v[2].x = arV[2][0]; v[2].y = arV[2][1];
			v[3].x = arV[3][0]; v[3].y = arV[3][1];
			center = (v[0] + v[1] + v[2] + v[3]) / 4.0;
	
			D3DXMATRIX matTran;
			D3DXMATRIX matW2VS;
			D3DXMatrixScaling(&matW2VS, 1.0, -1.0, 1.0);
			D3DXMatrixIdentity(&matTran);
			for (int row=0; row < 3; row++)
			{
				for (int col =0; col < 4; col++)
				{
					matTran.m[col][row] = pcfgMarker->trans[row][col];
				}
			}
			
			matTran *= matW2VS;
			D3DXVECTOR3 ov1(0,0,0), ov2(pcfgMarker->width,0,0), ov3(pcfgMarker->width, -pcfgMarker->width,0), ov4(0, -pcfgMarker->width, 0);
			D3DXVec3TransformCoord(&ov1, &ov1, &matTran);
			D3DXVec3TransformCoord(&ov2, &ov2, &matTran);
			D3DXVec3TransformCoord(&ov3, &ov3, &matTran);
			D3DXVec3TransformCoord(&ov4, &ov4, &matTran);

			t[4*2*(nValidDetected-1) + 0] = ov1.x;  t[4*2*(nValidDetected-1) + 1] = ov1.y;
			t[4*2*(nValidDetected-1) + 2] = ov2.x;  t[4*2*(nValidDetected-1) + 3] = ov2.y;
			t[4*2*(nValidDetected-1) + 4] = ov3.x;  t[4*2*(nValidDetected-1) + 5] = ov3.y;
			t[4*2*(nValidDetected-1) + 6] = ov4.x;  t[4*2*(nValidDetected-1) + 7] = ov4.y;

			d[4*2*(nValidDetected-1) + 0] = arV[0][0]/w;  d[4*2*(nValidDetected-1) + 1] = arV[0][1]/h;
			d[4*2*(nValidDetected-1) + 2] = arV[1][0]/w;  d[4*2*(nValidDetected-1) + 3] = arV[1][1]/h;
			d[4*2*(nValidDetected-1) + 4] = arV[2][0]/w;  d[4*2*(nValidDetected-1) + 5] = arV[2][1]/h;
			d[4*2*(nValidDetected-1) + 6] = arV[3][0]/w;  d[4*2*(nValidDetected-1) + 7] = arV[3][1]/h;
		}
		if (nValidDetected < 1)
		{
			free(t);
			free(d);
			return S_FALSE;
		}
		CvMat cvPt;
		CvMat dstPt;

		cvPt = cvMat(nValidDetected*4, 2, CV_32F, t);
		dstPt = cvMat(nValidDetected*4, 2, CV_32F, d);
		cvFindHomography(&dstPt, &cvPt, &mat);

		D3DXMATRIX matHomo;
		D3DXMatrixIdentity(&matHomo);
		matHomo._11 = mat.data.fl[0*3 + 0];
		matHomo._21 = mat.data.fl[0*3 + 1];
		matHomo._31 = mat.data.fl[0*3 + 2];

		matHomo._12 = mat.data.fl[1*3 + 0];
		matHomo._22 = mat.data.fl[1*3 + 1];
		matHomo._32 = mat.data.fl[1*3 + 2];

		matHomo._13 = mat.data.fl[2*3 + 0];
		matHomo._23 = mat.data.fl[2*3 + 1];
		matHomo._33 = mat.data.fl[2*3 + 2];

		WarpConfigData sendData; 
		for (int row =0; row < 4; row++)
			for (int col =0; col < 4; col++)
				sendData.warpMat[row][col] = matHomo.m[row][col];
		
		IMemAllocator* pAllocator = m_pOutputPins[0]->GetAllocator();
		CMediaSample* pSendSample = NULL;

		pAllocator->GetBuffer((IMediaSample**)&pSendSample, NULL, NULL, 0);
		pSendSample->SetPointer((BYTE*)&sendData, sizeof(WarpConfigData));
		m_pOutputPins[0]->Deliver(pSendSample);
		if (pSendSample != NULL)
		{
			pSendSample->Release();
			pSendSample = NULL;
		}
		
		free(t);
		free(d);

	}
	return S_OK;
}
HRESULT AR2WarpController::CreatePins()
{
	HRESULT hr = S_OK;
	if (m_pInputPins.size() < 1 || m_pOutputPins.size() < 1) {
		for (int c = 0; c< m_pInputPins.size(); c++)
		{
			delete m_pInputPins[c];
			m_pInputPins[c] = NULL;
		}
		m_pInputPins.clear();
		for (int c = 0; c< m_pOutputPins.size(); c++)
		{
			delete m_pOutputPins[c];
			m_pOutputPins[c] = NULL;
		}
		m_pOutputPins.clear();

		CMuxTransformInputPin* pInput = new CMuxTransformInputPin(NAME("CMuxTransform input pin"),
			this,              // Owner filter
			&hr,               // Result code
			L"AR result");      // Pin name
		//  Can't fail
		
		CMuxTransformOutputPin* pOutput = new CMuxTransformOutputPin(NAME("Transform output pin"),
			this,            // Owner filter
			&hr,             // Result code
			L"Warp config");   // Pin name
		// Can't fail

		m_pInputPins.push_back(pInput);
		m_pOutputPins.push_back(pOutput);
	}
	return S_OK;
}
HRESULT AR2WarpController::CheckInputType(const CMediaType* mtIn, const IPin* pPin)
{
	if (m_pInputPins.size() >= 1 && m_pInputPins[0] == pPin)
	{
		if (!IsEqualGUID(*mtIn->Type(), GUID_MyMediaSample) || !IsEqualGUID(*mtIn->Subtype(), GUID_ARResult))
		{
			return E_INVALIDARG;
		}
		return S_OK;
	}
	return E_FAIL;
}
HRESULT AR2WarpController::CheckOutputType(const CMediaType* mtOut, const IPin* pPin)
{
	if (m_pOutputPins.size() >= 1 && m_pOutputPins[0] == pPin)
	{
		if (!IsEqualGUID(*mtOut->Type(), GUID_MyMediaSample) || !IsEqualGUID(*mtOut->Subtype(), GUID_WarpConfig))
		{
			return E_INVALIDARG;
		}
		return S_OK;
	}
	return S_OK;
}
HRESULT AR2WarpController::DecideBufferSize(IMemAllocator * pAlloc, const IPin* pOutPin,
								 __inout ALLOCATOR_PROPERTIES *pProp)
{
	HRESULT hr;
	if (m_pOutputPins.size() >= 1 && m_pOutputPins[0] == pOutPin)
	{
		pProp->cBuffers = 1;
		pProp->cbBuffer = sizeof(ARTagResultData);

		ALLOCATOR_PROPERTIES Actual;
		hr = pAlloc->SetProperties(pProp,&Actual);
		if (FAILED(hr)) {
			return hr;
		}
		ASSERT( Actual.cBuffers == 1 );
		if (pProp->cBuffers > Actual.cBuffers ||
			pProp->cbBuffer > Actual.cbBuffer) {
				return E_FAIL;
		}
	}
	
	return S_OK;
}
HRESULT AR2WarpController::GetMediaType(int iPosition, const IPin* pOutPin, __inout CMediaType *pMediaType)
{
	if (iPosition < 0) {
		return E_INVALIDARG;
	}
	if (iPosition >= 1) { // WATCH OUT !!
		return VFW_S_NO_MORE_ITEMS;
	}

	if (m_pOutputPins.size() > 0 && m_pOutputPins[0] == pOutPin)
	{
		CMediaType myMediaType;
		myMediaType.SetType(&GUID_MyMediaSample);
		myMediaType.SetSubtype(&GUID_WarpConfig);
		myMediaType.SetSampleSize(sizeof(WarpConfigData));
		*pMediaType = myMediaType;
		
		return S_OK;
	}
	return VFW_S_NO_MORE_ITEMS;
}
HRESULT AR2WarpController::CompleteConnect(PIN_DIRECTION direction, const IPin* pMyPin, const IPin* pOtherPin)
{
	return S_OK;
}

HRESULT AR2WarpController::GetPages(CAUUID *pPages)
{
	pPages->cElems = 1;
	pPages->pElems = (GUID*)CoTaskMemAlloc(sizeof(GUID));
	if (pPages->pElems == NULL) 
	{
		return E_OUTOFMEMORY;
	}
	pPages->pElems[0] = CLSID_AR2WarpControllerPropertyPage;
	return S_OK;
	
}

CCritSec* AR2WarpController::GetReceiveCS(IPin* pPin)
{
	if (m_pInputPins.size() >= 1 && m_pInputPins[0] == pPin)
	{
		return NULL;
	}
	else
	{
		return __super::GetReceiveCS(pPin);
	}
}