#pragma once

#include "IImProSyncFilter.h"
#include "dshow.h"
#include "Streams.h"
#include <initguid.h>
#include "combase.h"
#include "GSDXFilterBase.h"
#include "GSDXMuxFilter.h"
#include "IGSPersist.h"
#include "MyMediaSample.h"
#include "MyARTagMediaSample.h"

class ImProSyncFilter :
	public GSDXMuxFilter, public IImProSyncFilter,
	public ISpecifyPropertyPages, public IGSPersist, public CPersistStream
{
public:
	static CUnknown *WINAPI CreateInstance(LPUNKNOWN punk, HRESULT *phr);

	//for COM interface 
	STDMETHODIMP NonDelegatingQueryInterface(REFIID iid, void **ppv);
	DECLARE_IUNKNOWN;

	//implement DShow Property Page
	STDMETHODIMP     GetPages(CAUUID *pPages);
	//from IGSPersist
	virtual HRESULT SaveToFile(WCHAR* path);
	virtual HRESULT LoadFromFile(WCHAR* path);
	virtual HRESULT GetName(WCHAR* name, UINT szName);
	//override CPersistStream
	STDMETHODIMP GetClassID(__out CLSID *pClsID);
	virtual HRESULT WriteToStream(IStream *pStream);
	virtual HRESULT ReadFromStream(IStream *pStream);
	virtual int SizeMax();
protected:

	static HRESULT __stdcall OnCamTransform(void* self, IMediaSample *pInSample, CMediaType* pInMT, 
		IMediaSample *pOutSample, CMediaType* pOutMT);
	static HRESULT __stdcall ReceiveLayoutDirty(void* self, IMediaSample *pSample, const IPin* pReceivePin, IMediaSample*& pOutSample);
	static HRESULT __stdcall PostReceiveARLayout(void* self, IMediaSample *pOutSample, const IPin* pOutputPin, HRESULT preHr);
	static HRESULT __stdcall PostReceiveCamImg(void* self, IMediaSample *pOutSample, const IPin* pOutputPin, HRESULT preHr);


	//from GSDXMuxFilter Interface
	virtual HRESULT CreatePins();

	
public:
	ImProSyncFilter(IUnknown * pOuter, HRESULT *phr, BOOL ModifiesData);
	virtual ~ImProSyncFilter();


private:
	bool Dirty;
	bool Block;
	bool getDirty();
	HRESULT setDirty(bool isDirty);
	bool getBlock();
	HRESULT setBlock(bool isBlock);

private:

	CCritSec locDirty;
	CCritSec locBlock;
	CCritSec locMarkerInfo;
	ARLayoutConfigData tagConfig;

};
