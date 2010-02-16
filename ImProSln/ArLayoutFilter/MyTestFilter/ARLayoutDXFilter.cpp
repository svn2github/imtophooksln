#include "stdafx.h"
#include "ARLayoutDXFilter.h"
#include "MyTestFilter.h"
#include "MyMediaSample.h"
#include "ARLayoutDXDisplay.h"
#include "ARLayoutDXProp.h"
#include "MyARTagMediaSample.h"
#include "cv.h"
#include <map>
using namespace std;

ARLayoutDXFilter::ARLayoutDXFilter(IUnknown * pOuter, HRESULT * phr, BOOL ModifiesData)
: CMuxTransformFilter(NAME("ARLayoutDX Filter"), 0, CLSID_ARLayoutFilter)
{
	m_FrameRate = 10;
	m_ARMarkers = NULL;
	m_numMarker = 0;
	m_minMarkerWidth = 1.0;
	m_pARStrategyData = NULL;
	initD3D(800, 600);
	initARMarkers();
}
ARLayoutDXFilter::~ARLayoutDXFilter()
{
	if (m_ARMarkers != NULL)
	{
		delete [] m_ARMarkers;
		m_ARMarkers = NULL;
	}
	m_numMarker = 0;
	if (m_pARStrategyData != NULL)
	{
		delete m_pARStrategyData;
		m_pARStrategyData = NULL;
	}
}

CUnknown *WINAPI ARLayoutDXFilter::CreateInstance(LPUNKNOWN punk, HRESULT *phr)
{
	ASSERT(phr);
	
	ARLayoutDXFilter *pNewObject = new ARLayoutDXFilter(punk, phr, FALSE);

	if(pNewObject == NULL) {
		if (phr)
			*phr = E_OUTOFMEMORY;
	}

	return pNewObject;
}

HRESULT ARLayoutDXFilter::NonDelegatingQueryInterface(REFIID iid, void **ppv)
{
	if (iid == IID_IARLayoutDXFilter) 
	{
		return GetInterface(static_cast<IARLayoutDXFilter*>(this), ppv);
	}
	else if (iid == IID_ISpecifyPropertyPages)
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

HRESULT ARLayoutDXFilter::CreatePins()
{
	HRESULT hr;
	if (m_pStreamPins.size() < 1) {
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
		for (int c = 0; c< m_pStreamPins.size(); c++)
		{
			delete m_pStreamPins[c];
			m_pStreamPins[c] = NULL;
		}
		m_pStreamPins.clear();


		CMuxTransformInputPin* pInput0 = new CMuxTransformInputPin(NAME("CMuxTransform input pin"),
			this,              // Owner filter
			&hr,               // Result code
			L"config");      // Pin name

		CMuxTransformStream* pOutput0 = new CMuxTransformStream(NAME("CMuxTransform stream pin"),
			&hr,              
			this,               
			L"Layout");      

		CMuxTransformOutputPin* pOutput1 = new CSourceOutputPin(NAME("CMuxTransform stream pin"),
			this,
			&hr,                             
			L"markinfo");     
		m_pInputPins.push_back(pInput0);
		m_pStreamPins.push_back(pOutput0);
		m_pOutputPins.push_back(pOutput1);
	}
	return S_OK;
}
HRESULT ARLayoutDXFilter::Receive(IMediaSample *pSample, const IPin* pReceivePin)
{
	if (m_pInputPins.size() > 0 && pReceivePin == m_pInputPins[0])
	{
		ReceiveConfig(pSample, pReceivePin);
	}
	return S_OK;
}
HRESULT ARLayoutDXFilter::ReceiveConfig(IMediaSample *pSample, const IPin* pReceivePin)
{
	ARLayoutStartegyData* sData = NULL;
	pSample->GetPointer((BYTE**)&sData);
	if (sData == NULL)
	{
		return S_FALSE;
	}
	CAutoLock lck(&m_csARStrategyData);
	if (m_pARStrategyData == NULL)
	{
		m_pARStrategyData = new ARLayoutStartegyData();
	}
	*m_pARStrategyData = *sData;

	return S_OK;
}
HRESULT ARLayoutDXFilter::FillBuffer(IMediaSample *pSamp, IPin* pPin)
{
	
	if (m_pStreamPins.size() > 0 && m_pStreamPins[0] == pPin)
	{
		{
			CAutoLock lck(&m_csARStrategyData);
			if (m_pARStrategyData != NULL)
			{
				DecideLayout(m_pARStrategyData->camViews, m_pARStrategyData->numCamView,
					m_pARStrategyData->fingerRects, m_pARStrategyData->numFingers);
				sendConfigData();
				delete m_pARStrategyData;
				m_pARStrategyData = NULL;
			}
		}
		SetRenderTarget();
		{
			CAutoLock lck(&m_csARMarker);
			ARMultiMarkerInfoT markerConfig;
			memset((void*)&markerConfig, 0 ,sizeof(ARMultiMarkerInfoT));
			markerConfig.marker = m_ARMarkers;
			markerConfig.marker_num = m_numMarker;
			((ARLayoutDXDisplay*)m_pD3DDisplay)->Render(&markerConfig);
		}
		ResetRenderTarget();
		CopyRenderTarget2OutputTexture();	
		CMediaType mt;
		mt = ((CMuxTransformStream*)pPin)->CurrentMediaType();
		CopyOutputTexture2OutputData(pSamp, &mt, true);
	}
	return S_OK;
}

HRESULT ARLayoutDXFilter::GetMediaType(int iPosition, const IPin* pPin, __inout CMediaType *pMediaType)
{
	if (m_pStreamPins.size() > 0 && m_pStreamPins[0] == pPin)
	{
		if (iPosition == 0 )
		{	
			CMediaType mt;
			mt.SetType(&GUID_MyMediaSample);
			mt.SetSubtype(&GUID_D3DXTEXTURE9_POINTER);
			mt.SetSampleSize(sizeof(LPDIRECT3DTEXTURE9));
			D3DSURFACE_DESC desc;
			m_pOutTexture->GetLevelDesc(0, &desc);
			mt.SetFormat((BYTE*)&desc, sizeof(D3DSURFACE_DESC));
			mt.SetFormatType(&GUID_FORMATTYPE_D3DXTEXTURE9DESC);
			*pMediaType = mt;
			return S_OK;
		}
		else if (iPosition == 1)
		{
			CMediaType mt;
			D3DSURFACE_DESC desc;
			m_pOutTexture->GetLevelDesc(0, &desc);
			mt.SetType(&MEDIATYPE_Video);
			mt.SetFormatType(&FORMAT_VideoInfo);
			mt.SetTemporalCompression(FALSE);
			mt.SetSubtype(&MEDIASUBTYPE_RGB32);
			mt.SetSampleSize(desc.Width*desc.Height*4);
			
			VIDEOINFOHEADER pvi;
			memset((void*)&pvi, 0, sizeof(VIDEOINFOHEADER));
			pvi.bmiHeader.biSizeImage = 0; //for uncompressed image
			pvi.bmiHeader.biWidth = desc.Width;
			pvi.bmiHeader.biHeight = desc.Height;
			pvi.bmiHeader.biBitCount = 32;
			SetRectEmpty(&(pvi.rcSource));
			SetRectEmpty(&(pvi.rcTarget));
			mt.SetFormat((BYTE*)&pvi, sizeof(VIDEOINFOHEADER));
			*pMediaType = mt;
			return S_OK;
		}
	}
	if (m_pOutputPins.size() > 0 && m_pOutputPins[0] == pPin)
	{
		if (iPosition < 0  || iPosition > 0)
		{	
			return VFW_S_NO_MORE_ITEMS;
		}
		CMediaType mt;
		mt.SetType(&GUID_MyMediaSample);
		mt.SetSubtype(&GUID_ARLayoutConfigData);
		mt.SetSampleSize(sizeof(ARLayoutConfigData));
		*pMediaType = mt;
		return S_OK;
	}

	return S_FALSE;
}
HRESULT ARLayoutDXFilter::CheckOutputType(const CMediaType* mtOut, const IPin* pPin)
{
	if (m_pStreamPins.size() > 0 && m_pStreamPins[0] == pPin)
	{
		CheckPointer(mtOut, E_POINTER);
		if (IsEqualGUID(*mtOut->Type(), GUID_MyMediaSample) && 
			IsEqualGUID(*mtOut->Subtype(), GUID_D3DXTEXTURE9_POINTER))
		{
			return NOERROR;
		}
		else if (IsEqualGUID(*mtOut->Type(), MEDIATYPE_Video) && 
			IsEqualGUID(*mtOut->Subtype(), MEDIASUBTYPE_RGB32))
		{
			return NOERROR;
		}
	}
	else if (m_pOutputPins.size() > 0 && m_pOutputPins[0] == pPin)
	{
		CMediaType mt;
		if (IsEqualGUID(*mtOut->Type(), GUID_MyMediaSample) && 
			IsEqualGUID(*mtOut->Subtype(), GUID_ARLayoutConfigData))
		{
			return NOERROR;
		}
	}
	return E_FAIL;
}

HRESULT ARLayoutDXFilter::CheckInputType(const CMediaType* mtIn, const IPin* pPin)
{
	if (m_pInputPins.size() > 0 && m_pInputPins[0] == pPin)
	{
		CheckPointer(mtIn, E_POINTER);
		if (IsEqualGUID(*mtIn->Type(), GUID_MyMediaSample) && 
			IsEqualGUID(*mtIn->Subtype(), GUID_ARLayoutStartegyData))
		{
			return NOERROR;
		}
	}
	return E_FAIL;
}

HRESULT ARLayoutDXFilter::DecideBufferSize(
	IMemAllocator * pAlloc, const IPin* pOutPin,
	__inout ALLOCATOR_PROPERTIES *pProp)
{
	HRESULT hr;
	if (m_pStreamPins.size() > 0 && pOutPin == m_pStreamPins[0])
	{
		CMediaType mt = ((CMuxTransformStream*)pOutPin)->CurrentMediaType();
		if ((IsEqualGUID(*mt.Type(), GUID_MyMediaSample) && 
			(IsEqualGUID(*mt.Subtype(), GUID_D3DXTEXTURE9_POINTER))) ||
			((IsEqualGUID(*mt.Type(), MEDIATYPE_Video) && 
			(IsEqualGUID(*mt.Subtype(), MEDIASUBTYPE_RGB32)))))
		{
			pProp->cBuffers = 1;
			pProp->cbBuffer = mt.GetSampleSize();
			if (pProp->cbAlign == 0)
			{
				pProp->cbAlign = 1;
			}
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
			return S_OK;
		}
	}

	if (m_pOutputPins.size() > 0 && pOutPin == m_pOutputPins[0])
	{
		CMediaType mt = ((CMuxTransformOutputPin*)pOutPin)->CurrentMediaType();
		if (IsEqualGUID(*mt.Type(), GUID_MyMediaSample) && 
			IsEqualGUID(*mt.Subtype(), GUID_ARLayoutConfigData))
		{
			pProp->cBuffers = 1;
			pProp->cbBuffer = mt.GetSampleSize();
			if (pProp->cbAlign == 0)
			{
				pProp->cbAlign = 1;
			}
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
			return S_OK;
		}
	}
	return E_FAIL;
}
HRESULT ARLayoutDXFilter::StartStreaming()
{	
	sendConfigData();
	return __super::StartStreaming();
}
MS3DDisplay* ARLayoutDXFilter::Create3DDisplay(IDirect3D9* pD3D, int rtWidth, int rtHeight)
{
	return new ARLayoutDXDisplay(pD3D, rtWidth, rtHeight);
}

MS3DDisplay* ARLayoutDXFilter::Create3DDisplay(IDirect3DDevice9* pDevice, int rtWidth, int rtHeight)
{
	return new ARLayoutDXDisplay(pDevice, rtWidth, rtHeight);
}

HRESULT ARLayoutDXFilter::GetPages(CAUUID *pPages)
{
	pPages->cElems = 1;
	pPages->pElems = (GUID*)CoTaskMemAlloc(sizeof(GUID));
	if (pPages->pElems == NULL) 
	{
		return E_OUTOFMEMORY;
	}
	pPages->pElems[0] = CLSID_ARLayoutPropPage;
	return S_OK;
}

bool ARLayoutDXFilter::initARMarkers(UINT numLevel, UINT intMarkerBits, UINT intBorderBits, float intWidthBits)
{
	CAutoLock lck(&m_csARMarker);

	float markerBits = intMarkerBits;
	float borderBits = intBorderBits;
	float WidthBits = intWidthBits;
	int numMarker = 0;
	for (int level = 1; level <= numLevel; level++)
	{
		float markerWidth = markerBits/WidthBits/level;
		int numX = 1.0  / (markerWidth + borderBits/WidthBits/level);
		int numY = numX;
		numMarker += numX * numY;
	}
	if (numMarker > NUMMARKER)
	{
		return false;
	}
	m_numMarker = numMarker;
	m_minMarkerWidth = 1.0;

	if (m_ARMarkers != NULL)
	{
		delete [] m_ARMarkers;
		m_ARMarkers = NULL;
	}

	m_numMarker = numMarker;
	m_ARMarkers = new ARMultiEachMarkerInfoT[m_numMarker];
	
	memset((void*)m_ARMarkers, 0, sizeof(ARMultiEachMarkerInfoT)*m_numMarker);
	int idx = -1;
	for (int level = 1; level <= numLevel; level++)
	{
		float markerWidth = markerBits/WidthBits/level;
		if (markerWidth < m_minMarkerWidth)
		{
			m_minMarkerWidth = markerWidth;
		}
		int numX = 1.0  / (markerWidth + borderBits/WidthBits/level);
		int numY = numX;
		for (int i = 0; i < numY; i++)
		{
			for ( int j = 0; j < numX; j++ )
			{		
				idx++;
				m_ARMarkers[idx].patt_id = idx;
				m_ARMarkers[idx].visible = (level == 1);
				m_ARMarkers[idx].width = markerWidth;	
				m_ARMarkers[idx].center[0] = markerWidth*0.5;
				m_ARMarkers[idx].center[1] = -markerWidth*0.5;
				m_ARMarkers[idx].trans[0][0] = 1.0; m_ARMarkers[idx].trans[0][1] = 0.0; m_ARMarkers[idx].trans[0][2] = 0.0; m_ARMarkers[idx].trans[0][3] = 0 + m_ARMarkers[idx].width*j + markerWidth/markerBits*(2*j+1);
				m_ARMarkers[idx].trans[1][0] = 0.0; m_ARMarkers[idx].trans[1][1] = 1.0; m_ARMarkers[idx].trans[1][2] = 0.0; m_ARMarkers[idx].trans[1][3] = 0 - m_ARMarkers[idx].width*i - markerWidth/markerBits*(2*i+1);
				m_ARMarkers[idx].trans[2][0] = 0.0; m_ARMarkers[idx].trans[2][1] = 0.0; m_ARMarkers[idx].trans[2][2] = 1.0; m_ARMarkers[idx].trans[2][3] = 0;	
			}
		}
	}
	generateAllMarkerRect(m_ARMarkers, m_numMarker, m_allMarkerRects);
	generateIntersectTable(m_ARMarkers, m_numMarker, m_TagIntersectTable);
	sendConfigData();
	return true;
}
bool ARLayoutDXFilter::generateAllMarkerRect(ARMultiEachMarkerInfoT* ARMarkers, int numMarker, 
						   vector<fRECT>& allMarkerRects)
{
	allMarkerRects.clear();
	for (int idx = 0; idx < numMarker; idx++)
	{
		fRECT markerRect;
		GetARTag2DRect(&markerRect, &(ARMarkers[idx]));
		allMarkerRects.push_back(markerRect);
	}
	return true;
}
bool ARLayoutDXFilter::generateIntersectTable(ARMultiEachMarkerInfoT* ARMarkers, int numMarker,
							vector<vector<int>>& table)
{
	m_TagIntersectTable.clear();
	for (int idx =0; idx < numMarker; idx++)
	{
		vector<int> intersectList;
		ARMultiEachMarkerInfoT* curMarker = &(ARMarkers[idx]);
		fRECT curRect;
		GetARTag2DRect(&curRect, &(ARMarkers[idx]));
		for (int intersectIdx = 0 ; intersectIdx < numMarker; intersectIdx++)
		{
			if (intersectIdx == idx)
				continue;
			fRECT intersectRECT;
			GetARTag2DRect(&intersectRECT, &(ARMarkers[intersectIdx]));
			if (curRect.IsIntersect(intersectRECT))
			{
				intersectList.push_back(intersectIdx);
			}
		}
		m_TagIntersectTable.push_back(intersectList);
	}
	return true;
}

bool ARLayoutDXFilter::LoadConfigFromFile(WCHAR* path)
{
	CAutoLock lck(&m_csARMarker);
	try
	{
		if (m_ARMarkers != NULL)
		{
			delete [] m_ARMarkers;
			m_ARMarkers = NULL;
		}
		m_numMarker = 0;
		m_minMarkerWidth = 1.0;

		FILE* filestream = NULL;
		_wfopen_s(&filestream, path, L"r");
		if (filestream == NULL)
		{
			return false;
		}
		fwscanf_s(filestream, L"%d\n", &m_numMarker);
		m_ARMarkers = new ARMultiEachMarkerInfoT[m_numMarker];
		memset((void*)m_ARMarkers, 0, sizeof(ARMultiEachMarkerInfoT)* m_numMarker);
		for (int i = 0; i < m_numMarker; i++ )
		{
			double mat[3][4] = {0};
			double width = 0;
			double centerX = 0, centerY =0;
			fwscanf_s(filestream, L"%d\n", &(m_ARMarkers[i].patt_id));
			fwscanf_s(filestream, L"%d %lf \n", &(m_ARMarkers[i].visible), &width);
			fwscanf_s(filestream, L"%lf %lf \n", &centerX, &centerY);
			fwscanf_s(filestream, L"%lf %lf %lf %lf \n \
									%lf %lf %lf %lf \n \
									%lf %lf %lf %lf \n",
									&(mat[0][0]), &(mat[0][1]), &(mat[0][2]), &(mat[0][3]),
									&(mat[1][0]), &(mat[1][1]), &(mat[1][2]), &(mat[1][3]),
									&(mat[2][0]), &(mat[2][1]), &(mat[2][2]), &(mat[2][3])
			);
			m_ARMarkers[i].width = width;
			m_ARMarkers[i].center[0] = centerX;
			m_ARMarkers[i].center[1] = centerY;
			if (width < m_minMarkerWidth)
			{
				m_minMarkerWidth = width;
			}
			for (int row = 0; row < 3; row ++)
			{
				for (int col = 0; col < 4; col++)
				{
					m_ARMarkers[i].trans[row][col] = mat[row][col];
				}
			}
		}
		fclose(filestream);
	}
	catch (exception e)
	{
		initARMarkers(); //reinit Markers
		return false;
	}
	generateAllMarkerRect(m_ARMarkers, m_numMarker, m_allMarkerRects);
	generateIntersectTable(m_ARMarkers, m_numMarker, m_TagIntersectTable);
	return true;
}
bool ARLayoutDXFilter::SaveConfigToFile(WCHAR* path)
{
	CAutoLock lck(&m_csARMarker);
	FILE* filestream = NULL;
	_wfopen_s(&filestream, path, L"w");
	if (filestream == NULL)
	{
		return false;
	}
	fwprintf_s(filestream, L"%d\n", m_numMarker);
	for (int i = 0; i < m_numMarker; i++ )
	{
		fwprintf_s(filestream, L"%d\n", m_ARMarkers[i].patt_id);
		fwprintf_s(filestream, L"%d %f \n", m_ARMarkers[i].visible, m_ARMarkers[i].width);
		fwprintf_s(filestream, L"%f %f \n", m_ARMarkers[i].center[0], m_ARMarkers[i].center[1]);
		fwprintf_s(filestream, L"%f %f %f %f \n \
					%f %f %f %f \n \
					%f %f %f %f \n",
					m_ARMarkers[i].trans[0][0], m_ARMarkers[i].trans[0][1], m_ARMarkers[i].trans[0][2], m_ARMarkers[i].trans[0][3],
					m_ARMarkers[i].trans[1][0], m_ARMarkers[i].trans[1][1], m_ARMarkers[i].trans[1][2], m_ARMarkers[i].trans[1][3],
					m_ARMarkers[i].trans[2][0], m_ARMarkers[i].trans[2][1], m_ARMarkers[i].trans[2][2], m_ARMarkers[i].trans[2][3]
					);
	}
	fclose(filestream);
	return true;
}

bool ARLayoutDXFilter::DecideLayout(fRECT* camRects, UINT numCamRect, fRECT* fingerRects, 
									UINT numFingerRects )
{
	CAutoLock lck(&m_csARMarker);
	map<int, bool> decisionMap; // idx, visible, have decided?
	vector<int> undecideIdx;
	
	for (int idx = 0; idx < m_numMarker; idx++)
	{
		undecideIdx.push_back(idx);
	}
	
	if (numFingerRects > 0 && fingerRects != NULL)
	{
		fRECT markerRect;
		for (int i = 0; i < numFingerRects; i++)
		{
			for (int iterIdx = 0; iterIdx < undecideIdx.size(); iterIdx++)
			{	
				int idx = undecideIdx.at(iterIdx);		
				markerRect = m_allMarkerRects[idx];
				if (markerRect.IsIntersect(fingerRects[i]))
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
			camRects[i].left = min((float)1.0, max((float)0.0, camRects[i].left));
			camRects[i].right = min((float)1.0, max((float)0.0, camRects[i].right));
			camRects[i].top = min((float)1.0, max((float)0.0, camRects[i].top));
			camRects[i].bottom = min((float)1.0, max((float)0.0, camRects[i].bottom));
		}

		for (int i = 0; i < numCamRect; i++) // for each cam view
		{
			float camViewWidth = abs(camRects->right - camRects->left);
			float camViewHeight = abs(camRects->bottom - camRects->top);
			if (camViewHeight <= 0 || camViewWidth <= 0)
			{
				continue;
			}
			float idealArea = max((float)(m_minMarkerWidth*m_minMarkerWidth*0.95), (float)camViewWidth/4 * camViewHeight/4);
			for (int iterIdx = 0; iterIdx < undecideIdx.size(); iterIdx++)
			{
				int idx = undecideIdx.at(iterIdx);
				fRECT myRECT;
				myRECT = m_allMarkerRects[idx];
				float myArea = abs((myRECT.right - myRECT.left) * (myRECT.bottom - myRECT.top));
				if ((myArea < idealArea) && myRECT.IsIntersect(camRects[i]))  // in camview && area < ideaArea && not decided yet
				{
					bool bPlaceTaken = false;
					
					for (map<int, bool>::iterator iter = decisionMap.begin(); 
						iter != decisionMap.end(); iter++) // check if this place have be taken by other Tag
					{
						if (iter->second == false)
							continue;

						fRECT decidedRECT;
						decidedRECT = m_allMarkerRects[iter->first];
						if ( decidedRECT.IsIntersect(myRECT))
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
		m_ARMarkers[iter->first].visible = iter->second;
	}
	return true;
}

bool ARLayoutDXFilter::GetARTag2DRect(fRECT* retRect, const ARMultiEachMarkerInfoT* pMarker)
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

/*
bool fRECT::IsIntersect(const D3DXVECTOR2& pt)
{
	bool intersectX = false, intersectY = false;
	if ( pt.x > left && pt.x < right)
	{
		intersectX = true;
	}
	if ( pt.y > top && pt.y < bottom)
	{
		intersectY = true;
	}
	return (intersectX && intersectY);
}*/

ARMultiEachMarkerInfoT* ARLayoutDXFilter::GetARMarker(int id)
{
	ARMultiEachMarkerInfoT* ret = NULL;
	for (int i = 0 ; i < m_numMarker; i++)
	{
		if (m_ARMarkers[i].patt_id == id)
		{
			ret = &(m_ARMarkers[i]);
			break;
		}
	}
	return ret;
}

bool ARLayoutDXFilter::sendConfigData()
{
	if (m_pOutputPins.size() <= 0 || !m_pOutputPins[0]->IsConnected()) 
	{
		return false;
	}
	ARLayoutConfigData sendData;
	{
		CAutoLock lck(&m_csARMarker);
		sendData.m_ARMarkers = m_ARMarkers;
		sendData.m_numMarker = m_numMarker;

		IMemAllocator* pAllocator = m_pOutputPins[0]->Allocator();
		CMediaSample* pSendSample = NULL;
		pAllocator->GetBuffer((IMediaSample**)&pSendSample, NULL, NULL, 0);
		if (pSendSample == NULL)
		{
			sendData.m_ARMarkers = NULL;
			sendData.m_numMarker = 0;
			return S_FALSE;
		}
		pSendSample->SetPointer((BYTE*)&sendData, sizeof(ARLayoutConfigData));
		m_pOutputPins[0]->Deliver(pSendSample);
		sendData.m_ARMarkers = NULL;
		sendData.m_numMarker = 0;
		if (pSendSample != NULL)
		{
			pSendSample->Release();
			pSendSample = NULL;
		}
	}

	return true;
}

float ARLayoutDXFilter::GetFrameRateLimit(IPin* pPin)
{
	return GetFrameRate();
}
BOOL ARLayoutDXFilter::SetFrameRate(float fps)
{
	CAutoLock lck(&m_csFrameRate);
	if (fps <= 0)
	{
		return FALSE;
	}
	m_FrameRate = fps;
	return TRUE;
}
float ARLayoutDXFilter::GetFrameRate()
{
	CAutoLock lck(&m_csFrameRate);
	return m_FrameRate;
}