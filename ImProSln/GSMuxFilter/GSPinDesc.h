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

struct GSPIN_ACCEPT_MEDIATYPE
{
	GUID* pMainType;
	GUID* pSubType;
	GUID* pFormatType;
	
	GSPIN_ACCEPT_MEDIATYPE();
	GSPIN_ACCEPT_MEDIATYPE(GUID mainType, GUID subType);
	GSPIN_ACCEPT_MEDIATYPE(GUID mainType, GUID subType, GUID formatType);
	~GSPIN_ACCEPT_MEDIATYPE();

	GSPIN_ACCEPT_MEDIATYPE& operator = (const GSPIN_ACCEPT_MEDIATYPE &rhs);
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

struct GSFILTER_INPUTPIN_FUNCS
{
	typedef HRESULT (__stdcall *PreReceiveFuncPtr)(IMediaSample *pSample, const IPin* pReceivePin, void* self);
	typedef HRESULT (__stdcall *TransformFuncPtr)(IMediaSample *pInSample, IMediaSample *pOutSample, void* self);
	typedef HRESULT (__stdcall *PostReceiveFuncPtr)(IMediaSample *pOutSample, const IPin* pOutputPin, void* self);
	typedef HRESULT (__stdcall *CompleteConnectFuncPtr)(PIN_DIRECTION direction, const IPin* pMyPin, const IPin* pOtherPin, void* self);
	typedef HRESULT (__stdcall *BreakConnectFuncPtr)(PIN_DIRECTION dir, const IPin* pPin, void* self);
	
	PreReceiveFuncPtr pFuncPreReceive;
	TransformFuncPtr pFuncTransform;
	PostReceiveFuncPtr pFuncPostReceive;
	CompleteConnectFuncPtr pFuncCompleteConnect;
	BreakConnectFuncPtr pFuncBreakConnect;

	GSFILTER_INPUTPIN_FUNCS();
	GSFILTER_INPUTPIN_FUNCS(PreReceiveFuncPtr _pFuncPreReceive, TransformFuncPtr _pFuncTransform, PostReceiveFuncPtr _pFuncPostReceive,
		CompleteConnectFuncPtr _pFuncCompleteConnect, BreakConnectFuncPtr _pFuncBreakConnect);
	~GSFILTER_INPUTPIN_FUNCS();
};


struct GSFILTER_OUTPUTPIN_FUNCS
{
	typedef HRESULT (__stdcall *CompleteConnectFuncPtr)(PIN_DIRECTION direction, const IPin* pMyPin, const IPin* pOtherPin, void* self);
	typedef HRESULT (__stdcall *BreakConnectFuncPtr)(PIN_DIRECTION dir, const IPin* pPin, void* self);

	CompleteConnectFuncPtr pFuncCompleteConnect;
	BreakConnectFuncPtr pFuncBreakConnect;

	GSFILTER_OUTPUTPIN_FUNCS();
	GSFILTER_OUTPUTPIN_FUNCS(CompleteConnectFuncPtr _pFuncCompleteConnect, BreakConnectFuncPtr _pFuncBreakConnect);
	~GSFILTER_OUTPUTPIN_FUNCS();
};

struct GSFILTER_STREAMPIN_FUNCS
{
	typedef HRESULT (__stdcall *FillBufferFuncPtr)(IMediaSample *pSamp, IPin* pPin, void* self);

	FillBufferFuncPtr pFuncFillBuffer;

	GSFILTER_STREAMPIN_FUNCS();
	GSFILTER_STREAMPIN_FUNCS(FillBufferFuncPtr _pFuncFillBuffer);
	~GSFILTER_STREAMPIN_FUNCS();
};
struct GSFILTER_PIN_DESC
{
	WCHAR pinName[MAX_PATH];
	//////////////////
	GSPIN_TYPE pinType;
	GSPIN_ACCEPT_MEDIATYPE_GROUP acceptTypes;

	GSFILTER_PIN_DESC();
	GSFILTER_PIN_DESC(LPCWSTR _pinName, GSPIN_TYPE _pinType, GSPIN_ACCEPT_MEDIATYPE_GROUP _acceptTypes);
	

	GSFILTER_PIN_DESC& operator = (const GSFILTER_PIN_DESC &rhs);
};

struct GSFILTER_INPUTPIN_DESC : public GSFILTER_PIN_DESC
{
	// in InputPin, this idx decide which output Pin to deliver it's sample, assign -1 to skip this operation  
	UINT nMatchIdx;
	GSFILTER_INPUTPIN_FUNCS pFunc;

	GSFILTER_INPUTPIN_DESC();
	GSFILTER_INPUTPIN_DESC(LPCWSTR _pinName, UINT nMatchIdx, GSPIN_TYPE _pinType, GSPIN_ACCEPT_MEDIATYPE_GROUP _acceptTypes, GSFILTER_INPUTPIN_FUNCS _pFunc);
	GSFILTER_INPUTPIN_DESC& operator = (const GSFILTER_INPUTPIN_DESC &rhs);
};

struct GSFILTER_OUTPUTPIN_DESC : public GSFILTER_PIN_DESC
{
	// in OutPin, this idx decide which input Pin to decide it's sample size to fill the formatType in GetMediaType
	UINT nMatchIdx;
	GSFILTER_OUTPUTPIN_FUNCS pFunc;

	GSFILTER_OUTPUTPIN_DESC();
	GSFILTER_OUTPUTPIN_DESC(LPCWSTR _pinName, UINT nMatchIdx, GSPIN_TYPE _pinType, GSPIN_ACCEPT_MEDIATYPE_GROUP _acceptTypes, GSFILTER_OUTPUTPIN_FUNCS _pFunc);
	GSFILTER_OUTPUTPIN_DESC& operator = (const GSFILTER_OUTPUTPIN_DESC &rhs);
};

struct GSFILTER_STREAMPIN_DESC : public GSFILTER_PIN_DESC
{
	UINT bufW;
	UINT bufH;
	GSFILTER_STREAMPIN_FUNCS pFunc;

	GSFILTER_STREAMPIN_DESC();
	GSFILTER_STREAMPIN_DESC(LPCWSTR _pinName, UINT _bufW, UINT _bufH, GSPIN_TYPE _pinType, GSPIN_ACCEPT_MEDIATYPE_GROUP _acceptTypes, GSFILTER_STREAMPIN_FUNCS _pFunc);
	GSFILTER_STREAMPIN_DESC& operator = (const GSFILTER_STREAMPIN_DESC &rhs);
};