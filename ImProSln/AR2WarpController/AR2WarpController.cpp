#include "stdafx.h"
#include "AR2WarpController.h"
#include "AR2WarpControllerProp.h"
#include "MyMediaSample.h"
#include <d3dx9math.h>
#include "cv.h"
#include "MyARTagMediaSample.h"
AR2WarpController::AR2WarpController(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData)
: CMuxTransformFilter(NAME("AR2WarpController"), 0, CLSID_AR2WarpController)
{ 
	m_RANSIC_Threshold = 5;
	for (int i=0; i < NUMCAM; i++)
	{
		m_matCam2VW[i] = NULL;
	}
	m_pFGList = NULL;
}
AR2WarpController::~AR2WarpController()
{
	for (int i=0; i < NUMCAM; i++)
	{
		if (m_matCam2VW[i] != NULL)
		{
			delete m_matCam2VW[i];
			m_matCam2VW[i] = NULL;
		}
	}
	if (m_pFGList != NULL)
	{
		delete m_pFGList;
		m_pFGList = NULL;
	}
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
	HRESULT hr;
	if ((m_pInputPins.size() >= 1 && m_pInputPins[0] == pReceivePin) || 
		(m_pInputPins.size() >= 2 && m_pInputPins[1] == pReceivePin) || 
		(m_pInputPins.size() >= 3 && m_pInputPins[2] == pReceivePin) )
	{
		hr = ReceiveARResult(pSample, pReceivePin);
		if (SUCCEEDED(hr))
		{
			if ( m_pInputPins[0] == pReceivePin && m_pOutputPins[0]->IsConnected())
			{
				SendWarpConfig(0);
			}
			if ( m_pInputPins[1] == pReceivePin && m_pOutputPins[1]->IsConnected())
			{
				SendWarpConfig(1);
			}
			if ( m_pInputPins[2] == pReceivePin && m_pOutputPins[2]->IsConnected())
			{
				SendWarpConfig(2);
			}
			if (m_pOutputPins[NUMCAM]->IsConnected())
			{
				SendARLayoutStartegyData();
			}
		}
	}
	else if (m_pInputPins.size() >= NUMCAM+1 && m_pInputPins[NUMCAM] == pReceivePin)
	{
		hr = ReceiveTouchResult(pSample, pReceivePin);
		SendARLayoutStartegyData();
	}
	return S_OK;
}

HRESULT AR2WarpController::ReceiveARResult(IMediaSample *pSample, const IPin* pReceivePin)
{
	int idx = -1;
	for (int i = 0; i < m_pInputPins.size(); i++)
	{
		if (m_pInputPins[i] == pReceivePin)
		{
			idx = i;
		}
	}
	if (idx == -1 || idx >= NUMCAM)
	{
		return S_FALSE;
	}

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
		D3DXVECTOR3* ov = NULL;
		ARTag2VW(pcfgMarker, ov);
		if (ov == NULL)
		{
			continue;
		}
		D3DXVECTOR3 ov_rev[4];
		ov_rev[0] = ov[0];
		ov_rev[1] = ov[3];
		ov_rev[2] = ov[2];
		ov_rev[3] = ov[1];
		nValidDetected++;

		t[4*2*(nValidDetected-1) + 0] = ov_rev[0].x;  t[4*2*(nValidDetected-1) + 1] = ov_rev[0].y;
		t[4*2*(nValidDetected-1) + 2] = ov_rev[1].x;  t[4*2*(nValidDetected-1) + 3] = ov_rev[1].y;
		t[4*2*(nValidDetected-1) + 4] = ov_rev[2].x;  t[4*2*(nValidDetected-1) + 5] = ov_rev[2].y;
		t[4*2*(nValidDetected-1) + 6] = ov_rev[3].x;  t[4*2*(nValidDetected-1) + 7] = ov_rev[3].y;

		d[4*2*(nValidDetected-1) + 0] = arV[0][0]/w;  d[4*2*(nValidDetected-1) + 1] = arV[0][1]/h;
		d[4*2*(nValidDetected-1) + 2] = arV[1][0]/w;  d[4*2*(nValidDetected-1) + 3] = arV[1][1]/h;
		d[4*2*(nValidDetected-1) + 4] = arV[2][0]/w;  d[4*2*(nValidDetected-1) + 5] = arV[2][1]/h;
		d[4*2*(nValidDetected-1) + 6] = arV[3][0]/w;  d[4*2*(nValidDetected-1) + 7] = arV[3][1]/h;
		delete [] ov;
		ov = NULL;
	}
	if (nValidDetected < 1)
	{
		CAutoLock lck(&m_csMatCam2VW[idx]); // there is no marker detected.
		if (m_matCam2VW[idx] != NULL)
		{
			delete m_matCam2VW[idx];
			m_matCam2VW[idx] = NULL;
		}
		free(t);
		free(d);
		return S_FALSE;
	}
	CvMat cvPt;
	CvMat dstPt;

	cvPt = cvMat(nValidDetected*4, 2, CV_32F, d); //t: virtual space, d: camera space
	dstPt = cvMat(nValidDetected*4, 2, CV_32F, t);
	cvFindHomography(&cvPt, &dstPt, &mat, CV_RANSAC, m_RANSIC_Threshold); // camera to virtual space
	{
		CAutoLock lck(&m_csMatCam2VW[idx]);
		if (m_matCam2VW[idx] == NULL)
		{
			m_matCam2VW[idx] = new D3DXMATRIX();
		}
		D3DXMatrixIdentity(m_matCam2VW[idx]);
		m_matCam2VW[idx]->_11 = mat.data.fl[0*3 + 0];
		m_matCam2VW[idx]->_21 = mat.data.fl[0*3 + 1];
		m_matCam2VW[idx]->_31 = mat.data.fl[0*3 + 2];

		m_matCam2VW[idx]->_12 = mat.data.fl[1*3 + 0];
		m_matCam2VW[idx]->_22 = mat.data.fl[1*3 + 1];
		m_matCam2VW[idx]->_32 = mat.data.fl[1*3 + 2];

		m_matCam2VW[idx]->_13 = mat.data.fl[2*3 + 0];
		m_matCam2VW[idx]->_23 = mat.data.fl[2*3 + 1];
		m_matCam2VW[idx]->_33 = mat.data.fl[2*3 + 2];
	}
	free(t);
	free(d);
	return S_OK;
}

HRESULT AR2WarpController::ReceiveTouchResult(IMediaSample *pSample, const IPin* pReceivePin)
{
	CAutoLock lck(&m_csFGList);
	CMediaSample* pCSample = (CMediaSample*)pSample;
	ForegroundRegion* pTouchResult = NULL;
	pCSample->GetPointer((BYTE**)&pTouchResult);
	if (m_pFGList != NULL)
	{
		delete m_pFGList;
		m_pFGList = NULL;
	}
	m_pFGList = new ForegroundRegion();
	if (pTouchResult->numForeground <= 0)
	{
		m_pFGList->foregroundRects = NULL;
		m_pFGList->numForeground = 0;
	}
	else
	{
		m_pFGList->foregroundRects = new fRECT[pTouchResult->numForeground];
		m_pFGList->numForeground = pTouchResult->numForeground;
		memcpy((void*)m_pFGList->foregroundRects, (void*)pTouchResult->foregroundRects, 
			sizeof(fRECT)* pTouchResult->numForeground);

	}
	return S_OK;
}

HRESULT AR2WarpController::CreatePins()
{
	HRESULT hr = S_OK;
	if (m_pInputPins.size() < (NUMCAM + 1) || m_pOutputPins.size() < 4) {
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
		
		CMuxTransformInputPin* pInput0 = new CMuxTransformInputPin(NAME("CMuxTransform input pin"),
			this,              // Owner filter
			&hr,               // Result code
			L"AR result0");      // Pin name
		//  Can't fail
		CMuxTransformInputPin* pInput1 = new CMuxTransformInputPin(NAME("CMuxTransform input pin"),
			this,              // Owner filter
			&hr,               // Result code
			L"AR result1");      // Pin name
		//  Can't fail
		CMuxTransformInputPin* pInput2 = new CMuxTransformInputPin(NAME("CMuxTransform input pin"),
			this,              // Owner filter
			&hr,               // Result code
			L"AR result2");      // Pin name
		//  Can't fail
		CMuxTransformInputPin* pInput3 = new CMuxTransformInputPin(NAME("CMuxTransform input pin"),
			this,              // Owner filter
			&hr,               // Result code
			L"touch result");      // Pin name
		//  Can't fail

		CMuxTransformOutputPin* pOutput0 = new CMuxTransformOutputPin(NAME("Transform output pin"),
			this,            // Owner filter
			&hr,             // Result code
			L"Warp config0");   // Pin name

		CMuxTransformOutputPin* pOutput1 = new CMuxTransformOutputPin(NAME("Transform output pin"),
			this,            // Owner filter
			&hr,             // Result code
			L"Warp config1");   // Pin name
		CMuxTransformOutputPin* pOutput2 = new CMuxTransformOutputPin(NAME("Transform output pin"),
			this,            // Owner filter
			&hr,             // Result code
			L"Warp config2");   // Pin name
		// Can't fail
		CMuxTransformOutputPin* pOutput3 = new CMuxTransformOutputPin(NAME("Transform output pin"),
			this,            // Owner filter
			&hr,             // Result code
			L"ARLayout config");   // Pin name
		// Can't fail
		m_pInputPins.push_back(pInput0);
		m_pInputPins.push_back(pInput1);
		m_pInputPins.push_back(pInput2);
		m_pInputPins.push_back(pInput3);

		m_pOutputPins.push_back(pOutput0);
		m_pOutputPins.push_back(pOutput1);
		m_pOutputPins.push_back(pOutput2);
		m_pOutputPins.push_back(pOutput3);

	}
	return S_OK;
}
HRESULT AR2WarpController::CheckInputType(const CMediaType* mtIn, const IPin* pPin)
{
	bool bARResult = false;
	for (int i =0; i < NUMCAM; i++)
	{
		if (pPin == m_pInputPins[i])
		{
			bARResult = true;
			break;
		}
	}
	if (bARResult)
	{
		if (!IsEqualGUID(*mtIn->Type(), GUID_MyMediaSample) || !IsEqualGUID(*mtIn->Subtype(), GUID_ARResult))
		{
			return E_INVALIDARG;
		}
		return S_OK;
	}
	if (((CMuxTransformInputPin*)pPin) == m_pInputPins.at(NUMCAM) )
	{
		if (!IsEqualGUID(*mtIn->Type(), GUID_MyMediaSample) || !IsEqualGUID(*mtIn->Subtype(), GUID_ForegroundRegion_Data))
		{
			return E_INVALIDARG;
		}
		return S_OK;
	}
	return E_FAIL;
}
HRESULT AR2WarpController::CheckOutputType(const CMediaType* mtOut, const IPin* pPin)
{
	bool bWarpConfigPin = false;
	for ( int i =0; i< NUMCAM; i++)
	{
		if (m_pOutputPins[i] == pPin)
		{
			bWarpConfigPin = true;
			break;
		}
	}
	if (bWarpConfigPin)
	{
		if (!IsEqualGUID(*mtOut->Type(), GUID_MyMediaSample) || !IsEqualGUID(*mtOut->Subtype(), GUID_WarpConfig))
		{
			return E_INVALIDARG;
		}
		return S_OK;
	}
	if (pPin == m_pOutputPins[NUMCAM])
	{
		if (!IsEqualGUID(*mtOut->Type(), GUID_MyMediaSample) || !IsEqualGUID(*mtOut->Subtype(), GUID_ARLayoutStartegyData))
		{
			return E_INVALIDARG;
		}
		return S_OK;
	}
	return E_FAIL;
}
HRESULT AR2WarpController::DecideBufferSize(IMemAllocator * pAlloc, const IPin* pOutPin,
								 __inout ALLOCATOR_PROPERTIES *pProp)
{
	HRESULT hr;
	bool bWarpConfigPin = false;
	for ( int i =0; i< NUMCAM; i++)
	{
		if (m_pOutputPins[i] == pOutPin)
		{
			bWarpConfigPin = true;
			break;
		}
	}
	if (bWarpConfigPin)
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
	if (pOutPin == m_pOutputPins[NUMCAM])
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
	bool bWarpConfigPin = false;
	for ( int i =0; i< NUMCAM; i++)
	{
		if (m_pOutputPins[i] == pOutPin)
		{
			bWarpConfigPin = true;
			break;
		}
	}
	if (bWarpConfigPin)
	{
		CMediaType myMediaType;
		myMediaType.SetType(&GUID_MyMediaSample);
		myMediaType.SetSubtype(&GUID_WarpConfig);
		myMediaType.SetSampleSize(sizeof(WarpConfigData));
		*pMediaType = myMediaType;
		return S_OK;
	}
	if (m_pOutputPins[NUMCAM] == pOutPin)// ARLayout Pin
	{
		CMediaType myMediaType;
		myMediaType.SetType(&GUID_MyMediaSample);
		myMediaType.SetSubtype(&GUID_ARLayoutStartegyData);
		myMediaType.SetSampleSize(sizeof(ARLayoutStartegyData));
		*pMediaType = myMediaType;
		return S_OK; // not implement yet.
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

bool AR2WarpController::ARTag2VW(const ARMultiEachMarkerInfoT* pMarker, D3DXVECTOR3*& vts)
{
	if (pMarker == NULL)
	{
		return false;
	}
	if (vts != NULL)
	{
		delete [] vts;
		vts = NULL;
	}
	vts = new D3DXVECTOR3[4];
	vts[0] = D3DXVECTOR3(0,0,0); 
	vts[1] = D3DXVECTOR3(0, -pMarker->width, 0);
	vts[2] = D3DXVECTOR3(pMarker->width, -pMarker->width, 0);
	vts[3] = D3DXVECTOR3(pMarker->width, 0, 0);

	D3DXMATRIX matMark, invMatY;
	D3DXMatrixIdentity(&matMark);
	D3DXMatrixScaling(&invMatY, 1, -1, 1);
	
	for(int row=0; row < 3; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			matMark.m[col][row] = pMarker->trans[row][col];
		}
	}
	matMark = matMark*invMatY;
	for (int i =0; i < 4; i++)
	{
		D3DXVec3TransformCoord(&vts[i], &vts[i], &matMark);
	}
	return true;
}
bool AR2WarpController::GetARTag2DRect(fRECT* retRect, const ARMultiEachMarkerInfoT* pMarker)
{
	if (retRect == NULL || pMarker == NULL)
	{
		return false;
	}
	D3DXMATRIX matMark;
	D3DXMatrixIdentity(&matMark);
	for(int row=0; row < 3; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			matMark.m[col][row] = pMarker->trans[row][col];
		}
	}
	D3DXVECTOR3 v[4] = { D3DXVECTOR3(0,0,0), D3DXVECTOR3(0, -pMarker->width, 0),
		D3DXVECTOR3(pMarker->width, -pMarker->width, 0), D3DXVECTOR3(pMarker->width, 0, 0)};

	for (int i =0; i < 4; i++)
	{
		D3DXVec3TransformCoord(&v[i], &v[i], &matMark);
	}

	float minX = v[0].x; float maxX = v[0].x;
	float minY = v[0].y; float maxY = v[0].y;

	for (int i = 0; i < 4; i++)
	{
		if(v[i].x < minX)
		{
			minX = v[i].x;
		}
		if (v[i].x > maxX)
		{
			maxX = v[i].x;
		}
		if (v[i].y < minY)
		{
			minY = v[i].y;
		}
		if (v[i].y > maxY)
		{
			maxY = v[i].y;
		}
	}
	retRect->left = minX; retRect->right = maxX;
	retRect->top = -maxY; retRect->bottom = -minY;
	return true;
}
bool AR2WarpController::SendWarpConfig(int camIdx)
{
	if (camIdx < 0 || camIdx >= NUMCAM)
	{
		return false;
	}
	WarpConfigData sendData; 
	{
		CAutoLock lck(&m_csMatCam2VW[camIdx]);
		for (int row =0; row < 4; row++)
			for (int col =0; col < 4; col++)
				sendData.warpMat[row][col] = m_matCam2VW[camIdx]->m[row][col];
	}
	IMemAllocator* pAllocator = m_pOutputPins[0]->GetAllocator();
	CMediaSample* pSendSample = NULL;

	pAllocator->GetBuffer((IMediaSample**)&pSendSample, NULL, NULL, 0);
	if (pSendSample == NULL)
	{
		return S_FALSE;
	}
	pSendSample->SetPointer((BYTE*)&sendData, sizeof(WarpConfigData));
	m_pOutputPins[0]->Deliver(pSendSample);
	if (pSendSample != NULL)
	{
		pSendSample->Release();
		pSendSample = NULL;
	}
	return true;
}
bool AR2WarpController::SendARLayoutStartegyData()
{
	IMemAllocator* pAllocator = m_pOutputPins[NUMCAM]->GetAllocator();
	CMediaSample* pSendSample = NULL;

	pAllocator->GetBuffer((IMediaSample**)&pSendSample, NULL, NULL, 0);
	if (pSendSample == NULL)
	{
		return S_FALSE;
	}
	ARLayoutStartegyData* pData = new ARLayoutStartegyData();
	//////ForeGround Area///////////////
	{
		CAutoLock lck(&m_csFGList);
		if (m_pFGList != NULL && m_pFGList->numForeground > 0)
		{
			pData->numFingers = m_pFGList->numForeground;
			pData->fingerRects = new fRECT[pData->numFingers];
			memset((void*)pData->fingerRects, 0, sizeof(fRECT)*pData->numFingers);
			memcpy((void*)pData->fingerRects, (void*)m_pFGList->foregroundRects, 
				sizeof(fRECT)*pData->numFingers);
		}
	}

	//////Camera looking Area///////////
	for (int i =0; i < NUMCAM; i++)
	{
		if (m_matCam2VW[i] == NULL)
			continue;
		pData->numCamView++;
	}
	pData->camViews = new fRECT[NUMCAM];
	memset((void*)pData->camViews, 0, sizeof(fRECT)*pData->numCamView);
	
	for (int i =0; i < NUMCAM; i++)
	{
		CAutoLock lck(&(m_csMatCam2VW[i]));
		if (m_matCam2VW[i] == NULL)
			continue;
		D3DXVECTOR4 lt(0,0,1,1), lb(0,1,1,1), rb(1,1,1,1), rt(1,0,1,1);

		D3DXVec4Transform(&lt, &lt, m_matCam2VW[i]);
		D3DXVec4Transform(&lb, &lb, m_matCam2VW[i]);
		D3DXVec4Transform(&rb, &rb, m_matCam2VW[i]);
		D3DXVec4Transform(&rt, &rt, m_matCam2VW[i]);

		lt /= lt.z;
		lb /= lb.z;
		rb /= rb.z;
		rt /= rt.z;

		pData->camViews[i].left = min(min(min(lt.x, lb.x), rb.x), rt.x); 
		pData->camViews[i].right = max(max(max(lt.x, lb.x), rb.x), rt.x);
		pData->camViews[i].top = min(min(min(lt.y, lb.y), rb.y), rt.y); 
		pData->camViews[i].bottom = max(max(max(lt.y, lb.y), rb.y), rt.y); 
	}
	
	////////////////////////////
	pSendSample->SetPointer((BYTE*)pData, sizeof(ARLayoutStartegyData));
	WCHAR str[MAX_PATH];
	
	m_pOutputPins[NUMCAM]->Deliver(pSendSample);
	if (pSendSample != NULL)
	{
		pSendSample->Release();
		pSendSample = NULL;
	}

	if (pData != NULL)
	{
		delete pData;
		pData = NULL;
	}

	return true;
}
IPin* AR2WarpController::GetARResultPin(int idx)
{
	if (idx < 0 || idx > NUMCAM)
		return NULL;
	return m_pInputPins[idx];
}
IPin* AR2WarpController::GetWarpConfigPin(int idx)
{
	if (idx < 0 || idx > NUMCAM)
		return NULL;
	return m_pInputPins[idx];
}
IPin* AR2WarpController::GetARLayoutPin()
{
	return m_pOutputPins[NUMCAM];
}
