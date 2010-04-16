#pragma once
#include "dshow.h"
#include "Streams.h"
#include <initguid.h>
#include "combase.h"

enum GSPIN_TYPE
{
	GSINPUT_PIN = 0,
	GSOUTPUT_PIN = 1,
	GSSTREAM_PIN = 2
};
enum GSPIN_MEDIASAMPLE_REF
{
	GSREF_INPUT_PIN = 0,
	GSREF_ACCEPT_MEDIATYPE = 1,
	GSREF_RENDERTARGET = 2
};
struct GSPIN_ACCEPT_MEDIATYPE
{
	GUID* pMainType;
	GUID* pSubType;
	GUID* pFormatType;
	BOOL bCompression;
	GSPIN_ACCEPT_MEDIATYPE();
	GSPIN_ACCEPT_MEDIATYPE(GUID mainType, GUID subType, BOOL bCompress);
	GSPIN_ACCEPT_MEDIATYPE(GUID mainType, GUID subType, GUID formatType, BOOL bCompress);
	virtual ~GSPIN_ACCEPT_MEDIATYPE();

	GSPIN_ACCEPT_MEDIATYPE& operator = (const GSPIN_ACCEPT_MEDIATYPE &rhs);
};

struct GSOUTPIN_ACCEPT_MEDIATYPE : GSPIN_ACCEPT_MEDIATYPE
{
	GSPIN_MEDIASAMPLE_REF refFlag;
	ULONG nSampleSize;
	UINT bufW, bufH;
	GSOUTPIN_ACCEPT_MEDIATYPE();
	GSOUTPIN_ACCEPT_MEDIATYPE(GUID mainType, GUID subType, BOOL bCompress, GSPIN_MEDIASAMPLE_REF refFlag, ULONG nSampleSize, UINT bufW, UINT bufH);
	GSOUTPIN_ACCEPT_MEDIATYPE(GUID mainType, GUID subType, GUID formatType, BOOL bCompress, GSPIN_MEDIASAMPLE_REF refFlag, ULONG nSampleSize, UINT bufW, UINT bufH);
	virtual ~GSOUTPIN_ACCEPT_MEDIATYPE();

	GSOUTPIN_ACCEPT_MEDIATYPE& operator = (const GSOUTPIN_ACCEPT_MEDIATYPE &rhs);
};


struct GSPIN_ACCEPT_MEDIATYPE_GROUP
{
	UINT nAcceptType;
	GSPIN_ACCEPT_MEDIATYPE* pAcceptTypes;

	GSPIN_ACCEPT_MEDIATYPE_GROUP();
	GSPIN_ACCEPT_MEDIATYPE_GROUP(GSPIN_ACCEPT_MEDIATYPE* _pAcceptTypes, UINT _AcceptType);
	~GSPIN_ACCEPT_MEDIATYPE_GROUP();

	GSPIN_ACCEPT_MEDIATYPE_GROUP& operator = (const GSPIN_ACCEPT_MEDIATYPE_GROUP &rhs);
};

struct GSOUTPIN_ACCEPT_MEDIATYPE_GROUP
{
	UINT nAcceptType;
	GSOUTPIN_ACCEPT_MEDIATYPE* pAcceptTypes;

	GSOUTPIN_ACCEPT_MEDIATYPE_GROUP();
	GSOUTPIN_ACCEPT_MEDIATYPE_GROUP(GSOUTPIN_ACCEPT_MEDIATYPE* _pAcceptTypes, UINT _AcceptType);
	~GSOUTPIN_ACCEPT_MEDIATYPE_GROUP();

	GSOUTPIN_ACCEPT_MEDIATYPE_GROUP& operator = (const GSOUTPIN_ACCEPT_MEDIATYPE_GROUP &rhs);
};
struct GSFILTER_INPUTPIN_FUNCS
{
	typedef HRESULT (__stdcall *PreReceiveFuncPtr)(void* self, IMediaSample *pSample, const IPin* pReceivePin, IMediaSample*& pOutSample);
	typedef HRESULT (__stdcall *TransformFuncPtr)(void* self, IMediaSample *pInSample, IMediaSample *pOutSample);
	typedef HRESULT (__stdcall *PostReceiveFuncPtr)(void* self, IMediaSample *pOutSample, const IPin* pOutputPin);
	typedef HRESULT (__stdcall *CompleteConnectFuncPtr)(void* self, PIN_DIRECTION direction, const IPin* pMyPin, const IPin* pOtherPin);
	typedef HRESULT (__stdcall *BreakConnectFuncPtr)(void* self, PIN_DIRECTION dir, const IPin* pPin);
	
	PreReceiveFuncPtr pFuncPreReceive;
	TransformFuncPtr pFuncTransform;
	PostReceiveFuncPtr pFuncPostReceive;
	CompleteConnectFuncPtr pFuncCompleteConnect;
	BreakConnectFuncPtr pFuncBreakConnect;

	GSFILTER_INPUTPIN_FUNCS() :	pFuncPreReceive(NULL), pFuncTransform(NULL), pFuncPostReceive(NULL), 
		pFuncCompleteConnect(NULL), pFuncBreakConnect(NULL)
	{	}
	GSFILTER_INPUTPIN_FUNCS(PreReceiveFuncPtr _pFuncPreReceive, TransformFuncPtr _pFuncTransform, PostReceiveFuncPtr _pFuncPostReceive,
		CompleteConnectFuncPtr _pFuncCompleteConnect, BreakConnectFuncPtr _pFuncBreakConnect) 
		: pFuncPreReceive(_pFuncPreReceive), pFuncTransform(_pFuncTransform), pFuncPostReceive(_pFuncPostReceive), 
		pFuncCompleteConnect(_pFuncCompleteConnect), pFuncBreakConnect(_pFuncBreakConnect)
	{	}

};


struct GSFILTER_OUTPUTPIN_FUNCS
{
	typedef HRESULT (__stdcall *CompleteConnectFuncPtr)(void* self, PIN_DIRECTION direction, const IPin* pMyPin, const IPin* pOtherPin);
	typedef HRESULT (__stdcall *BreakConnectFuncPtr)(void* self, PIN_DIRECTION dir, const IPin* pPin);

	CompleteConnectFuncPtr pFuncCompleteConnect;
	BreakConnectFuncPtr pFuncBreakConnect;

	GSFILTER_OUTPUTPIN_FUNCS() : pFuncCompleteConnect(NULL), pFuncBreakConnect(NULL)
	{	}
	GSFILTER_OUTPUTPIN_FUNCS(CompleteConnectFuncPtr _pFuncCompleteConnect, BreakConnectFuncPtr _pFuncBreakConnect) 
		: pFuncCompleteConnect(_pFuncCompleteConnect), pFuncBreakConnect(_pFuncBreakConnect)
	{	}

};

struct GSFILTER_STREAMPIN_FUNCS
{
	typedef HRESULT (__stdcall *CompleteConnectFuncPtr)(void* self, PIN_DIRECTION direction, const IPin* pMyPin, const IPin* pOtherPin);
	typedef HRESULT (__stdcall *BreakConnectFuncPtr)(void* self, PIN_DIRECTION dir, const IPin* pPin);
	typedef HRESULT (__stdcall *FillBufferFuncPtr)(void* self, IMediaSample *pSample, IPin* pPin);
	
	CompleteConnectFuncPtr pFuncCompleteConnect;
	BreakConnectFuncPtr pFuncBreakConnect;
	FillBufferFuncPtr pFuncFillBuffer;

	GSFILTER_STREAMPIN_FUNCS() : pFuncCompleteConnect(NULL), pFuncBreakConnect(NULL), pFuncFillBuffer(NULL) 
	{}
	GSFILTER_STREAMPIN_FUNCS(FillBufferFuncPtr _pFuncFillBuffer, CompleteConnectFuncPtr _pFuncCompleteConnect, BreakConnectFuncPtr _pFuncBreakConnect)
		: pFuncCompleteConnect(_pFuncCompleteConnect), pFuncBreakConnect(_pFuncBreakConnect), pFuncFillBuffer(_pFuncFillBuffer) 
	{}

};
struct GSFILTER_PIN_DESC
{
	WCHAR pinName[MAX_PATH];
	//////////////////
	GSPIN_TYPE pinType;
	
	GSFILTER_PIN_DESC();
	GSFILTER_PIN_DESC(LPCWSTR _pinName, GSPIN_TYPE _pinType, GSPIN_ACCEPT_MEDIATYPE_GROUP _acceptTypes);
	GSFILTER_PIN_DESC& operator = (const GSFILTER_PIN_DESC &rhs);
};

struct GSFILTER_INPUTPIN_DESC : public GSFILTER_PIN_DESC
{
	// in InputPin, this idx decide which output Pin to deliver it's sample, assign -1 to skip this operation  
	UINT nMatchIdx;

	GSPIN_ACCEPT_MEDIATYPE_GROUP acceptTypes;
	GSFILTER_INPUTPIN_FUNCS pFunc;

	GSFILTER_INPUTPIN_DESC();
	GSFILTER_INPUTPIN_DESC(LPCWSTR _pinName, UINT nMatchIdx, GSPIN_TYPE _pinType, GSPIN_ACCEPT_MEDIATYPE_GROUP _acceptTypes, GSFILTER_INPUTPIN_FUNCS _pFunc);
	GSFILTER_INPUTPIN_DESC& operator = (const GSFILTER_INPUTPIN_DESC &rhs);
};

struct GSFILTER_OUTPUTPIN_DESC : public GSFILTER_PIN_DESC
{
	// in OutPin, this idx decide which input Pin to decide it's sample size to fill the formatType in GetMediaType
	UINT nMatchIdx;

	GSOUTPIN_ACCEPT_MEDIATYPE_GROUP acceptTypes;
	GSFILTER_OUTPUTPIN_FUNCS pFunc;

	GSFILTER_OUTPUTPIN_DESC();
	GSFILTER_OUTPUTPIN_DESC(LPCWSTR _pinName, UINT nMatchIdx, GSPIN_TYPE _pinType, GSPIN_ACCEPT_MEDIATYPE_GROUP _acceptTypes, GSFILTER_OUTPUTPIN_FUNCS _pFunc);
	GSFILTER_OUTPUTPIN_DESC& operator = (const GSFILTER_OUTPUTPIN_DESC &rhs);
};

struct GSFILTER_STREAMPIN_DESC : public GSFILTER_PIN_DESC
{
	UINT nMatchIdx;

	GSOUTPIN_ACCEPT_MEDIATYPE_GROUP acceptTypes;
	GSFILTER_STREAMPIN_FUNCS pFunc;

	GSFILTER_STREAMPIN_DESC();
	GSFILTER_STREAMPIN_DESC(LPCWSTR _pinName,  UINT nMatchIdx, GSPIN_TYPE _pinType, GSPIN_ACCEPT_MEDIATYPE_GROUP _acceptTypes, GSFILTER_STREAMPIN_FUNCS _pFunc);
	GSFILTER_STREAMPIN_DESC& operator = (const GSFILTER_STREAMPIN_DESC &rhs);
};