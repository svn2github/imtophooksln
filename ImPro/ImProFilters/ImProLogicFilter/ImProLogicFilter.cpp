#include "stdafx.h"
#include "ImProLogicFilter.h"
#include "GSD3DMediaType.h"
#include "GSMacro.h"
#include "cv.h"
#include "MyMediaSample.h"
#include "MyARTagMediaSample.h"
#include "GSMediaType.h"
#include "IGSHomoWarpFilter.h"
#include "IGSMaskFilter.h"
#include "IGSARTagLayoutFilter.h"

#define MARKERALIVETIME 0.8  // second
using namespace GSMaskNS;


ImProLogicFilter::ImProLogicFilter(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData)
: GSMuxFilter(NAME("ImProLogicFilter"), 0, CLSID_ImProLogicFilter)
{ 
	for (int i =0; i < NUMCAM; i++)
	{
		m_dirtyWarpFromAR[i] = FALSE;
		m_matCam2VW[i] = NULL;
		m_matPro2VW[i] = NULL;
		camEnable[i] = 0 ;
		markerDetected[i] = false ;
	}
	m_pMaskSendData = NULL;
	m_dirtyLowResMask = FALSE;
	m_dirtyARStrategy = FALSE;

	m_pARStrategyData = NULL;
	m_pTouchResult = NULL;
	m_RANSIC_Threshold = 0.1;
	m_pOSCSender = OSCSender::GetOSCSender();


	extern HMODULE GetModule();
	WCHAR str[MAX_PATH] = {0};
	HMODULE module = GetModule();
	GetModuleFileName(module, str, MAX_PATH);
	// Gets filename
	WCHAR* pszFile = wcsrchr(str, '\\');
	pszFile++;    // Moves on from \
	// Get path
	WCHAR szPath[MAX_PATH] = L"";
	_tcsncat(szPath, str, pszFile - str);

	char fileDir[100];
	int size= wcslen(szPath);

	wcstombs(fileDir, szPath, size+1);
	// tableW and tableH is the real size of the table in mm 720 * 540
	tableWidth = 720;
	tableHeight = 540;
	W2CMat = cvCreateMat(4, 4, CV_32F);
	projTrans = NULL;
	projTrans = new ProjectorTrans2World[NUMCAM];

	for(int i = 0 ; i < NUMCAM ; i++){
		
		projTrans[i].Init(tableWidth,tableHeight,fileDir,i);
	}
}
ImProLogicFilter::~ImProLogicFilter()
{
	for (int i=0; i < NUMCAM; i++)
	{
		SAFE_DELETE(m_matCam2VW[i]);
	}	
	for (int i=0; i < NUMCAM; i++)
	{
		SAFE_DELETE(m_matPro2VW[i]);
		
	}
	SAFE_DELETE(m_pARStrategyData);
	SAFE_DELETE(m_pTouchResult);
	SAFE_DELETE_ARRAY(projTrans);
	
	SAFE_DELETE(m_pMaskSendData);
	SAFE_RELEASE(m_pOSCSender);
	if (W2CMat != NULL)
	{
		cvReleaseMat(&W2CMat);
		W2CMat = NULL;
	}
}

CUnknown *WINAPI ImProLogicFilter::CreateInstance(LPUNKNOWN punk, HRESULT *phr)
{
	ASSERT(phr);
	// assuming we don't want to modify the data
	ImProLogicFilter *pNewObject = new ImProLogicFilter(punk, phr, FALSE);

	if(pNewObject == NULL) {
		if (phr)
			*phr = E_OUTOFMEMORY;
	}
	return pNewObject;
}

HRESULT ImProLogicFilter::NonDelegatingQueryInterface(REFIID iid, void **ppv)
{
	if (iid == IID_IImProLogicFilter) 
	{
		return GetInterface(static_cast<IImProLogicFilter*>(this), ppv);
	}
	else if (iid == IID_ISpecifyPropertyPages)
	{
		return GetInterface(
			static_cast<ISpecifyPropertyPages*>(this),	ppv);
	}
	else if (iid == IID_IGSPersist)
	{
		return GetInterface(static_cast<IGSPersist*>(this), ppv);
	}
	else
	{
		// Call the parent class.
		return __super::NonDelegatingQueryInterface(iid, ppv);
	}
}

HRESULT ImProLogicFilter::CreatePins()
{
	// you may want to overwrite this function.
	HRESULT hr = S_OK;
	GSPIN_ACCEPT_MEDIATYPE arAccType[] =
	{
		GSPIN_ACCEPT_MEDIATYPE(GUID_IMPRO_FeedbackTYPE, GUID_ARResult, FALSE),
	};

	GSPIN_ACCEPT_MEDIATYPE touchAccType[] =
	{
		GSPIN_ACCEPT_MEDIATYPE(GUID_IMPRO_FeedbackTYPE, GUID_ForegroundRegion_Data, FALSE),
	};

	GSFILTER_INPUTPIN_DESC inputPinDesc[] = {
		GSFILTER_INPUTPIN_DESC(L"ARResult0", 0, GSINPUT_PIN, GSPIN_ACCEPT_MEDIATYPE_GROUP(arAccType, ARRAYSIZE(arAccType)), 
			GSFILTER_INPUTPIN_FUNCS(ImProLogicFilter::PreReceive_ARResult, NULL, NULL, NULL, NULL)),
		GSFILTER_INPUTPIN_DESC(L"ARResult1", 0, GSINPUT_PIN, GSPIN_ACCEPT_MEDIATYPE_GROUP(arAccType, ARRAYSIZE(arAccType)), 
			GSFILTER_INPUTPIN_FUNCS(ImProLogicFilter::PreReceive_ARResult, NULL, NULL, NULL, NULL)),
		GSFILTER_INPUTPIN_DESC(L"ARResult2", 0, GSINPUT_PIN, GSPIN_ACCEPT_MEDIATYPE_GROUP(arAccType, ARRAYSIZE(arAccType)), 
			GSFILTER_INPUTPIN_FUNCS(ImProLogicFilter::PreReceive_ARResult, NULL, NULL, NULL, NULL)),
		GSFILTER_INPUTPIN_DESC(L"ARResult3", 0, GSINPUT_PIN, GSPIN_ACCEPT_MEDIATYPE_GROUP(arAccType, ARRAYSIZE(arAccType)), 
			GSFILTER_INPUTPIN_FUNCS(ImProLogicFilter::PreReceive_ARResult, NULL, NULL, NULL, NULL)),
		
		GSFILTER_INPUTPIN_DESC(L"ARResult from Table", 0, GSINPUT_PIN, GSPIN_ACCEPT_MEDIATYPE_GROUP(arAccType, ARRAYSIZE(arAccType)), 
			GSFILTER_INPUTPIN_FUNCS(ImProLogicFilter::PreReceive_ARResultFromTable, NULL, NULL, NULL, NULL)),
		GSFILTER_INPUTPIN_DESC(L"TouchResult", 0, GSINPUT_PIN, GSPIN_ACCEPT_MEDIATYPE_GROUP(touchAccType, ARRAYSIZE(touchAccType)), 
			GSFILTER_INPUTPIN_FUNCS(ImProLogicFilter::PreReceive_TouchResult, NULL, NULL, NULL, NULL)),


	};		

	GSOUTPIN_ACCEPT_MEDIATYPE outAccType[] =
	{
		GSOUTPIN_ACCEPT_MEDIATYPE(GSMEDIATYPE_FILTER_CONFIG, GSMEDIASUBTYPE_GSHOMOWARP_CONFIG, FALSE, GSREF_ACCEPT_MEDIATYPE, sizeof(GSHomoWarpConfigData), 0, 0)
	};
	GSOUTPIN_ACCEPT_MEDIATYPE maskAccType[] =
	{
		GSOUTPIN_ACCEPT_MEDIATYPE(GSMEDIATYPE_FILTER_CONFIG, GSMEDIASUBTYPE_GSMASK_CONFIG_PTR, FALSE, GSREF_ACCEPT_MEDIATYPE, sizeof(GSMaskConfigData), 0, 0)
	};
	GSOUTPIN_ACCEPT_MEDIATYPE stAccType[] =
	{
		GSOUTPIN_ACCEPT_MEDIATYPE(GSMEDIATYPE_FILTER_CONFIG, GSMEDIASUBTYPE_GSARTagLayoutStrategy_CONFIG_PTR, FALSE, GSREF_ACCEPT_MEDIATYPE, sizeof(GSARLayoutStartegyData), 0, 0)
	};
	GSFILTER_STREAMPIN_DESC outPinDesc[] = {
		GSFILTER_STREAMPIN_DESC(L"WarpFromAR0", 0, GSOUTPUT_PIN, GSOUTPIN_ACCEPT_MEDIATYPE_GROUP(outAccType, ARRAYSIZE(outAccType)), GSFILTER_STREAMPIN_FUNCS(FillBuffer_WarpFromAR, NULL, NULL)),
		GSFILTER_STREAMPIN_DESC(L"WarpFromAR1", 0, GSOUTPUT_PIN, GSOUTPIN_ACCEPT_MEDIATYPE_GROUP(outAccType, ARRAYSIZE(outAccType)), GSFILTER_STREAMPIN_FUNCS(FillBuffer_WarpFromAR, NULL, NULL)),
		GSFILTER_STREAMPIN_DESC(L"WarpFromAR2", 0, GSOUTPUT_PIN, GSOUTPIN_ACCEPT_MEDIATYPE_GROUP(outAccType, ARRAYSIZE(outAccType)), GSFILTER_STREAMPIN_FUNCS(FillBuffer_WarpFromAR, NULL, NULL)),
		GSFILTER_STREAMPIN_DESC(L"WarpFromAR3", 0, GSOUTPUT_PIN, GSOUTPIN_ACCEPT_MEDIATYPE_GROUP(outAccType, ARRAYSIZE(outAccType)), GSFILTER_STREAMPIN_FUNCS(FillBuffer_WarpFromAR, NULL, NULL)),

		GSFILTER_STREAMPIN_DESC(L"LowResMask", 0, GSOUTPUT_PIN, GSOUTPIN_ACCEPT_MEDIATYPE_GROUP(maskAccType, ARRAYSIZE(maskAccType)), GSFILTER_STREAMPIN_FUNCS(FillBuffer_LowResMask, NULL, NULL)),
	
		GSFILTER_STREAMPIN_DESC(L"ARStrategy", 0, GSOUTPUT_PIN, GSOUTPIN_ACCEPT_MEDIATYPE_GROUP(stAccType, ARRAYSIZE(stAccType)), GSFILTER_STREAMPIN_FUNCS(FillBuffer_ARStrategy, NULL, NULL)) 
	};


	hr = _CreatePins(inputPinDesc, ARRAYSIZE(inputPinDesc),NULL, 0, outPinDesc, ARRAYSIZE(outPinDesc) );
	
	return hr;
}
HRESULT ImProLogicFilter::PreReceive_ARResult(void* self, IMediaSample *pSample, const IPin* pReceivePin, IMediaSample*& pOutSample)
{
	if (self == NULL || pSample == NULL || pReceivePin == NULL)
	{
		return E_FAIL;
	}
	ImProLogicFilter* pSelf = (ImProLogicFilter*)(GSMuxFilter*)self;
	CAutoLock lckState(&pSelf->m_csState);
	HRESULT hr = S_OK;
	UINT idx = 0;
	hr = pSelf->GetARResult_PinIndex(pReceivePin, idx);
	if (FAILED(hr))
		return E_FAIL;
	
	CMediaSample* pCSample = (CMediaSample*)pSample;
	ARTagResultData* pARResult = NULL;
	pCSample->GetPointer((BYTE**)&pARResult);
	if (pARResult == NULL)
	{
		return E_FAIL;
	}
	if (pARResult->m_pMarkerConfig == NULL)
		return E_FAIL;
	

	if (pARResult->m_nDetected <= 0)
	{
		return S_FALSE;
	}

	pSelf->markerDetected[idx] = true;

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
		pSelf->ARTag2VW(pcfgMarker, ov);
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
		//do nothing
		free(t);
		free(d);
		return S_FALSE;
	}
	CvMat cvPt;
	CvMat dstPt;


	cvPt = cvMat(nValidDetected*4, 2, CV_32F, d); //t: virtual space, d: camera space
	dstPt = cvMat(nValidDetected*4, 2, CV_32F, t);

	for(int row = 0 ; row < 4 ; row ++){
		for(int col = 0 ; col <4 ; col ++){
			cvmSet(pSelf->projTrans[idx].world2CamExtrinsic,row,col,(float)pARResult->m_pMarkerConfig->cvTrans[row][col]);
		}
	}
	for(int i = 0 ; i < 3 ; i ++){
		cvmSet(pSelf->projTrans[idx].world2CamExtrinsic,i,3 , (float)(cvmGet(pSelf->projTrans[idx].world2CamExtrinsic,i,3)*pSelf->tableHeight)) ; 
		cvmSet(pSelf->projTrans[idx].world2CamExtrinsic,i,1 , (float)-cvmGet(pSelf->projTrans[idx].world2CamExtrinsic,i,1)) ; 
		cvmSet(pSelf->projTrans[idx].world2CamExtrinsic,i,2 , (float)-cvmGet(pSelf->projTrans[idx].world2CamExtrinsic,i,2)) ; 
	}	

	pSelf->projTrans[idx].getProjHomo();	
	{
		if (pSelf->m_matPro2VW[idx] == NULL)
		{
			pSelf->m_matPro2VW[idx] = new D3DXMATRIX();
		}
		D3DXMatrixIdentity(pSelf->m_matPro2VW[idx]);
		pSelf->m_matPro2VW[idx]->_11 = pSelf->projTrans[idx].proHomoMat->data.fl[0*3 + 0];
		pSelf->m_matPro2VW[idx]->_21 = pSelf->projTrans[idx].proHomoMat->data.fl[0*3 + 1];
		pSelf->m_matPro2VW[idx]->_31 = pSelf->projTrans[idx].proHomoMat->data.fl[0*3 + 2];

		pSelf->m_matPro2VW[idx]->_12 = pSelf->projTrans[idx].proHomoMat->data.fl[1*3 + 0];
		pSelf->m_matPro2VW[idx]->_22 = pSelf->projTrans[idx].proHomoMat->data.fl[1*3 + 1];
		pSelf->m_matPro2VW[idx]->_32 = pSelf->projTrans[idx].proHomoMat->data.fl[1*3 + 2];

		pSelf->m_matPro2VW[idx]->_13 = pSelf->projTrans[idx].proHomoMat->data.fl[2*3 + 0];
		pSelf->m_matPro2VW[idx]->_23 = pSelf->projTrans[idx].proHomoMat->data.fl[2*3 + 1];
		pSelf->m_matPro2VW[idx]->_33 = pSelf->projTrans[idx].proHomoMat->data.fl[2*3 + 2];

	}

	cvFindHomography(&cvPt, &dstPt, &mat, CV_RANSAC, pSelf->m_RANSIC_Threshold); // camera to virtual space
	{
		if (pSelf->m_matCam2VW[idx] == NULL)
		{
			pSelf->m_matCam2VW[idx] = new D3DXMATRIX();
		}
		D3DXMatrixIdentity(pSelf->m_matCam2VW[idx]);
		pSelf->m_matCam2VW[idx]->_11 = mat.data.fl[0*3 + 0];
		pSelf->m_matCam2VW[idx]->_21 = mat.data.fl[0*3 + 1];
		pSelf->m_matCam2VW[idx]->_31 = mat.data.fl[0*3 + 2];

		pSelf->m_matCam2VW[idx]->_12 = mat.data.fl[1*3 + 0];
		pSelf->m_matCam2VW[idx]->_22 = mat.data.fl[1*3 + 1];
		pSelf->m_matCam2VW[idx]->_32 = mat.data.fl[1*3 + 2];

		pSelf->m_matCam2VW[idx]->_13 = mat.data.fl[2*3 + 0];
		pSelf->m_matCam2VW[idx]->_23 = mat.data.fl[2*3 + 1];
		pSelf->m_matCam2VW[idx]->_33 = mat.data.fl[2*3 + 2];
		hr = pSelf->SetDirty_WarpFromAR(idx, TRUE);
		if (FAILED(hr))
		{
			free(t);
			free(d);
			return hr;
		}
		hr = pSelf->SetDirty_LowResMask(TRUE);
		if (FAILED(hr))
		{
			free(t);
			free(d);
			return hr;
		}
		hr = pSelf->SetDirty_ARStrategy(TRUE);
		if (FAILED(hr))
		{
			free(t);
			free(d);
			return hr;
		}
	}
	free(t);
	free(d);

	pSelf->SendBoundingBox2OSCSender();


	return S_OK;
}
HRESULT ImProLogicFilter::PreReceive_ARResultFromTable(void* self, IMediaSample *pSample, const IPin* pReceivePin, IMediaSample*& pOutSample)
{
	if (self == NULL || pSample == NULL || pReceivePin == NULL)
	{
		return E_FAIL;
	}
	ImProLogicFilter* pSelf = (ImProLogicFilter*)(GSMuxFilter*)self;
	HRESULT hr = S_OK;

	CMediaSample* pCSample = (CMediaSample*)pSample;
	ARTagResultData* pARResult = NULL;
	pCSample->GetPointer((BYTE**)&pARResult);
	if (pARResult == NULL)
	{
		return E_FAIL;
	}
	if (pARResult->m_pMarkerConfig == NULL)
		return E_FAIL;

	if (pARResult->m_nDetected <= 0)
	{
		return S_FALSE;
	}

	float w = pARResult->m_screenW;
	float h = pARResult->m_screenH;
	if (w <= 0 || h <= 0)
		return E_FAIL;
	WCHAR str[MAX_PATH];

	float* detectedTagRect = new float[8*pARResult->m_nDetected];
	int* detectedTagID = new int[pARResult->m_nDetected];
	memset(detectedTagID, 0, sizeof(int)*pARResult->m_nDetected);

	for (int i = 0; i< pARResult->m_nDetected; i++)
	{
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
		detectedTagRect[8*i + 0] = arV[0][0]/w;  detectedTagRect[8*i + 1] = arV[0][1]/h;
		detectedTagRect[8*i + 2] = arV[1][0]/w;  detectedTagRect[8*i + 3] = arV[1][1]/h;
		detectedTagRect[8*i + 4] = arV[2][0]/w;  detectedTagRect[8*i + 5] = arV[2][1]/h;
		detectedTagRect[8*i + 6] = arV[3][0]/w;  detectedTagRect[8*i + 7] = arV[3][1]/h;

	}
	hr = pSelf->SendDetectedARFromTable2OSCSender(detectedTagRect, detectedTagID, pARResult->m_nDetected);
	SAFE_DELETE_ARRAY(detectedTagRect);
	SAFE_DELETE_ARRAY(detectedTagID);
	
	return hr;
}
HRESULT ImProLogicFilter::PreReceive_TouchResult(void* self, IMediaSample *pSample, const IPin* pReceivePin, IMediaSample*& pOutSample)
{
		
	if (self == NULL || pSample == NULL || pReceivePin == NULL)
	{
		return E_FAIL;
	}
	ImProLogicFilter* pSelf = (ImProLogicFilter*)(GSMuxFilter*)self;
	//OutputDebugStringW(L"@@@@@  ImProLogicFilter::PreReceive_TouchResult before lck ---->\n");
	CAutoLock lckState(&pSelf->m_csState);
	//OutputDebugStringW(L"@@@@@  ImProLogicFilter::PreReceive_TouchResult after lck ---->\n");
	CMediaSample* pCSample = (CMediaSample*)pSample;
	ForegroundRegion* pTouchResult = NULL;
	pCSample->GetPointer((BYTE**)&pTouchResult);
	if (pTouchResult == NULL)
		return E_FAIL;
	if (pSelf->m_pTouchResult == NULL)
	{
		pSelf->m_pTouchResult = new ForegroundRegion();
	}
	*pSelf->m_pTouchResult = *pTouchResult;

	pSelf->SetDirty_ARStrategy(TRUE);
	//OutputDebugStringW(L"@@@@@  ImProLogicFilter::PreReceive_TouchResult <----\n");
	return S_OK;
}
HRESULT ImProLogicFilter::GetPages(CAUUID *pPages)
{
	pPages->cElems = 1;
	pPages->pElems = (GUID*)CoTaskMemAlloc(sizeof(GUID));
	if (pPages->pElems == NULL) 
	{
		return E_OUTOFMEMORY;
	}
	pPages->pElems[0] = CLSID_ImProLogicFilterProp;
	return S_OK;
}

HRESULT ImProLogicFilter::GetName(WCHAR* name, UINT szName)
{
	if (name == NULL)
		return S_FALSE;
	FILTER_INFO filterInfo;
	this->QueryFilterInfo(&filterInfo);
	wcscpy_s(name, szName, filterInfo.achName);
	if (filterInfo.pGraph != NULL)
	{
		filterInfo.pGraph->Release();
		filterInfo.pGraph = NULL;
	}
	return S_OK;
}

HRESULT ImProLogicFilter::SaveToFile(WCHAR* path)
{
	return S_OK;
}

HRESULT ImProLogicFilter::LoadFromFile(WCHAR* path)
{

	return S_OK;
}

bool ImProLogicFilter::GetARTag2DRect(fRECT* retRect, const ARMultiEachMarkerInfoT* pMarker)
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
bool ImProLogicFilter::ARTag2VW(const ARMultiEachMarkerInfoT* pMarker, D3DXVECTOR3*& vts)
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
IPin* ImProLogicFilter::GetWarpFromARPin(UINT idx)
{
	if (idx >= NUMCAM)
		return NULL;
	return m_pStreamPins.at(idx);
}
IPin* ImProLogicFilter::GetARStrategyPin()
{
	if (m_pStreamPins.size() <= NUMCAM + 2 -1)
		return NULL;
	return m_pStreamPins.at(NUMCAM + 2 -1);
}
HRESULT ImProLogicFilter::GetWarpFromAR_PinIndex(const IPin* pPin, UINT& idx)
{
	if (pPin == NULL || m_pStreamPins.size() < NUMCAM)
		return E_FAIL;
	for (int i =0; i < NUMCAM; i++)
	{
		if (m_pStreamPins.at(i) == pPin)
		{
			idx = i;
			return S_OK;
		}
	}
	return E_INVALIDARG;
}


HRESULT ImProLogicFilter::GetARResult_PinIndex(const IPin* pPin, UINT& idx)
{
	if (pPin == NULL || m_pInputPins.size() < NUMCAM)
		return E_FAIL;
	for (int i =0; i < NUMCAM; i++)
	{
		if (m_pInputPins.at(i) == pPin)
		{
			idx = i;
			return S_OK;
		}
	}
	return E_INVALIDARG;
}
HRESULT ImProLogicFilter::FillBuffer_WarpFromAR(void* self, IMediaSample *pSample, IPin* pPin)
{
	if (self == NULL ||pSample == NULL || pPin == NULL)
		return E_FAIL;

	ImProLogicFilter* pSelf = (ImProLogicFilter*)(GSMuxFilter*)self;
	CAutoLock lckState(&pSelf->m_csState);
	HRESULT hr = S_OK;
	UINT idx = 0;
	hr = pSelf->GetWarpFromAR_PinIndex(pPin, idx);
	if (FAILED(hr))
		return hr;
	
	

	if (pSelf->m_dirtyWarpFromAR[idx] == FALSE)
	{
		return S_FALSE;
	}
	
	GSHomoWarpConfigData *pSendData = NULL;
	hr = pSample->GetPointer((BYTE**)&pSendData);
	if (FAILED(hr))
	{
		return E_FAIL;
	}
	{

		if (pSelf->m_matPro2VW[idx] == NULL)
		{
			return E_FAIL;
		}
		for (int row =0; row < 4; row++)
		{
			for (int col =0; col < 4; col++)
			{
				pSendData->fWarpMat[row*4 + col] = pSelf->m_matPro2VW[idx]->m[row][col];
			}
		}
	}
	pSelf->SetDirty_WarpFromAR(idx, FALSE);
	return S_OK;
}
HRESULT ImProLogicFilter::FillBuffer_LowResMask(void* self, IMediaSample *pSample, IPin* pPin)
{
	if (self == NULL ||pSample == NULL || pPin == NULL)
		return E_FAIL;

	ImProLogicFilter* pSelf = (ImProLogicFilter*)(GSMuxFilter*)self;
	HRESULT hr = S_OK;
	CAutoLock lckState(&pSelf->m_csState);

	pSelf->checkTimestamp();

	if (pSelf->m_dirtyLowResMask == FALSE )
	{
		return S_FALSE;
	}
	BYTE* pSendData = NULL;
	hr = pSample->GetPointer((BYTE**)&pSendData);
	if (FAILED(hr))
		return hr;

	int nWorkingCam = 0;
	for (int i =0; i < NUMCAM; i++)
	{
		if (pSelf->m_matPro2VW[i] != NULL && pSelf->m_matCam2VW != NULL)
		{
			nWorkingCam++;
		}
	}
	if (pSelf->m_pMaskSendData == NULL)
	{
		pSelf->m_pMaskSendData = new GSMaskConfigData();
	}
	GSMaskConfigData tmpData;
	tmpData.m_nFlag = BlendMask;
	tmpData.m_nfRects = nWorkingCam;
	tmpData.m_pfRects = new GSFRect[nWorkingCam];

	{
		
		for (int i = 0; i < nWorkingCam; i++)
		{
			tmpData.m_pfRects[i].LT.x = pSelf->projTrans[pSelf->camEnable[i]].proj3DPoints[0][0];  
			tmpData.m_pfRects[i].LT.y = pSelf->projTrans[pSelf->camEnable[i]].proj3DPoints[0][1];

			tmpData.m_pfRects[i].LB.x = pSelf->projTrans[pSelf->camEnable[i]].proj3DPoints[1][0];  
			tmpData.m_pfRects[i].LB.y = pSelf->projTrans[pSelf->camEnable[i]].proj3DPoints[1][1];
			
			tmpData.m_pfRects[i].RB.x = pSelf->projTrans[pSelf->camEnable[i]].proj3DPoints[2][0];
			tmpData.m_pfRects[i].RB.y = pSelf->projTrans[pSelf->camEnable[i]].proj3DPoints[2][1];

			tmpData.m_pfRects[i].RT.x = pSelf->projTrans[pSelf->camEnable[i]].proj3DPoints[3][0];
			tmpData.m_pfRects[i].RT.y = pSelf->projTrans[pSelf->camEnable[i]].proj3DPoints[3][1];		
		}
		
		*pSelf->m_pMaskSendData = tmpData;
		*(GSMaskConfigData**)pSendData = pSelf->m_pMaskSendData;
		SAFE_DELETE_ARRAY(tmpData.m_pfRects);
		tmpData.m_nfRects = 0;

	}
	
	pSelf->SetDirty_LowResMask(FALSE);
	return S_OK;
}

HRESULT ImProLogicFilter::FillBuffer_ARStrategy(void* self, IMediaSample *pSample, IPin* pPin)
{
	if (self == NULL ||pSample == NULL || pPin == NULL)
		return E_FAIL;

	ImProLogicFilter* pSelf = (ImProLogicFilter*)(GSMuxFilter*)self;
	HRESULT hr = S_OK;
	CAutoLock lckState(&pSelf->m_csState);
	if (pSelf->m_dirtyARStrategy == FALSE )
	{
		return S_FALSE;
	}
	BYTE* pSendData = NULL;
	hr = pSample->GetPointer((BYTE**)&pSendData);
	if (FAILED(hr))
		return hr;

	GSARLayoutStartegyData tmpData;
	//////Camera looking Area///////////
	for (int i =0; i < NUMCAM; i++)
	{
		if (pSelf->m_matCam2VW[i] == NULL)
			continue;
		tmpData.numCamView++;
	}
	tmpData.camViews = new GSBoundingBox2D[tmpData.numCamView];
	int j =0;
	for (int i =0; i < NUMCAM; i++)
	{
		
		if (pSelf->m_matCam2VW[i] == NULL)
			continue;
		D3DXVECTOR4 lt(0,0,1,1), lb(0,1,1,1), rb(1,1,1,1), rt(1,0,1,1);

		D3DXVec4Transform(&lt, &lt, pSelf->m_matCam2VW[i]);
		D3DXVec4Transform(&lb, &lb, pSelf->m_matCam2VW[i]);
		D3DXVec4Transform(&rb, &rb, pSelf->m_matCam2VW[i]);
		D3DXVec4Transform(&rt, &rt, pSelf->m_matCam2VW[i]);

		lt /= lt.z;
		lb /= lb.z;
		rb /= rb.z;
		rt /= rt.z;

		tmpData.camViews[j].LT.x = min(min(min(lt.x, lb.x), rb.x), rt.x); 
		tmpData.camViews[j].RB.x = max(max(max(lt.x, lb.x), rb.x), rt.x);
		tmpData.camViews[j].LT.y = min(min(min(lt.y, lb.y), rb.y), rt.y); 
		tmpData.camViews[j].RB.y = max(max(max(lt.y, lb.y), rb.y), rt.y); 

		j++;
	}
	//////ForeGround Area///////////////
	{
		
		if (pSelf->m_pTouchResult != NULL && pSelf->m_pTouchResult->numForeground > 0)
		{
			tmpData.numFingers = pSelf->m_pTouchResult->numForeground;
			SAFE_DELETE_ARRAY(tmpData.fingerRects);
			tmpData.fingerRects = new GSBoundingBox2D[tmpData.numFingers];
			for (int i =0; i< tmpData.numFingers; i++)
			{
				tmpData.fingerRects[i].LT.x = pSelf->m_pTouchResult->foregroundRects[i].left;
				tmpData.fingerRects[i].LT.y = pSelf->m_pTouchResult->foregroundRects[i].top;

				tmpData.fingerRects[i].RB.x = pSelf->m_pTouchResult->foregroundRects[i].right;
				tmpData.fingerRects[i].RB.y = pSelf->m_pTouchResult->foregroundRects[i].bottom;
			}
		}
	}

	if (pSelf->m_pARStrategyData == NULL)
	{
		pSelf->m_pARStrategyData = new GSARLayoutStartegyData();
	}
	*pSelf->m_pARStrategyData = tmpData;
	*(GSARLayoutStartegyData**)pSendData = pSelf->m_pARStrategyData;
	SAFE_DELETE_ARRAY(tmpData.camViews);
	SAFE_DELETE_ARRAY(tmpData.fingerRects);
	hr = pSelf->SetDirty_ARStrategy(FALSE);
	return S_OK;
}


HRESULT ImProLogicFilter::SetDirty_WarpFromAR(UINT idx, BOOL bDirty)
{
	if (idx >= NUMCAM)
		return E_FAIL;
	CAutoLock lckState(&m_csState);
	m_dirtyWarpFromAR[idx] = bDirty;
	return S_OK;
}
HRESULT ImProLogicFilter::SetDirty_LowResMask(BOOL bDirty)
{
	CAutoLock lckState(&m_csState);
	m_dirtyLowResMask = bDirty;
	return S_OK;
}
HRESULT ImProLogicFilter::SetDirty_ARStrategy(BOOL bDirty)
{
	CAutoLock lckState(&m_csState);
	m_dirtyARStrategy = bDirty;
	return S_OK;
}

HRESULT ImProLogicFilter::SendBoundingBox2OSCSender()
{
	if (m_pOSCSender == NULL || m_pOSCSender->isConnected() == false)
	{
		return S_FALSE;
	}
	//for testing
	for (int i=0; i< NUMCAM; i++)
	{
		if (m_matPro2VW[i] == NULL)
		{
			continue;
		}			
		m_pOSCSender->sendHighResBoundingBox(i, projTrans[i].projBox,projTrans[i].proj3DPoints);
	}
	return S_OK;
}
HRESULT ImProLogicFilter::SendDetectedARFromTable2OSCSender(float* tagRects, INT* tagIDs, UINT nTagRect)
{
	if (m_pOSCSender == NULL || m_pOSCSender->isConnected() == false)
	{
		return S_FALSE;
	}
	if (tagRects == NULL || tagIDs == NULL || nTagRect == 0)
		return E_INVALIDARG;

	m_pOSCSender->sendDetectedARTag(tagRects, tagIDs, nTagRect);

	return S_OK;
}


BOOL ImProLogicFilter::IsOSCConnected()
{
	if (m_pOSCSender == NULL)
		return false;
	return m_pOSCSender->isConnected();
}
HRESULT ImProLogicFilter::ConnectOSC(char* ipaddress, int port)
{
	if (m_pOSCSender == NULL)
		return E_FAIL;
	if (m_pOSCSender->isConnected())
	{
		return S_FALSE;
	}
	m_pOSCSender->connectSocket(ipaddress, port);
	return S_OK;
}
HRESULT ImProLogicFilter::DisConnectOSC()
{
	if (m_pOSCSender == NULL)
		return E_FAIL;
	m_pOSCSender->disConnectSocket();
	return S_OK;
}
HRESULT ImProLogicFilter::GetIPAddress(char* outIpAddress)
{
	if (m_pOSCSender == NULL)
		return E_FAIL;
	strcpy_s(outIpAddress, MAX_PATH, m_pOSCSender->m_ipAddress);
	return S_OK;
}
int ImProLogicFilter::GetPort()
{
	if (m_pOSCSender == NULL)
		return 0;
	return m_pOSCSender->m_port;
}

void ImProLogicFilter::checkTimestamp(){
	double currentTime = timeGetTime();
	int camNum = 0 ;
	for(int i = 0 ; i < NUMCAM ; i ++){
		if(markerDetected[i] == false){
	
			if(currentTime - markerTime[i] > MARKERALIVETIME *1000){
				m_matCam2VW[i] = NULL;
				m_matPro2VW[i] = NULL;
				m_dirtyLowResMask = true ;		
			}
			else{
				camEnable[camNum] = i ;
				camNum++ ;
			}
		}
		else{
			markerTime[i] = currentTime;
			camEnable[camNum] = i ;
			camNum++ ;
			markerDetected[i] = false ;
		}
	}

}

void ImProLogicFilter::resetProj3DPoint(int index){
	for(int p = 0 ; p < 4 ; p ++){
		projTrans[index].proj3DPoints[p][0] = 0 ;
		projTrans[index].proj3DPoints[p][1] = 0 ;
	}
}