#include "stdafx.h"
#include "GSPinDesc.h"
#include "GSMacro.h"

GSPIN_ACCEPT_MEDIATYPE::GSPIN_ACCEPT_MEDIATYPE()
{
	pMainType = NULL;
	pSubType = NULL;
	pFormatType = NULL;
	bCompression = FALSE;
	
}
GSPIN_ACCEPT_MEDIATYPE::GSPIN_ACCEPT_MEDIATYPE(GUID mainType, GUID subType, BOOL bCompress)
{
	pMainType = new GUID();
	pSubType = new GUID();
	pFormatType = NULL;
	*pMainType = mainType;
	*pSubType = subType;
	bCompression = bCompress;

}
GSPIN_ACCEPT_MEDIATYPE::GSPIN_ACCEPT_MEDIATYPE(GUID mainType, GUID subType, GUID formatType, BOOL bCompress)
{
	pMainType = new GUID();
	pSubType = new GUID();
	pFormatType = new GUID();
	*pMainType = mainType;
	*pSubType = subType;
	*pFormatType = formatType;
	bCompression = bCompress;
	
}
GSPIN_ACCEPT_MEDIATYPE::~GSPIN_ACCEPT_MEDIATYPE()
{
	SAFE_DELETE(pMainType);
	SAFE_DELETE(pSubType);
	SAFE_DELETE(pFormatType);
}

GSPIN_ACCEPT_MEDIATYPE& GSPIN_ACCEPT_MEDIATYPE::operator = (const GSPIN_ACCEPT_MEDIATYPE &rhs)
{
	SAFE_DELETE(pMainType);
	SAFE_DELETE(pSubType);
	SAFE_DELETE(pFormatType);
	if (rhs.pMainType != NULL)
	{
		pMainType = new GUID();
		*pMainType = *rhs.pMainType;
	}
	if (rhs.pSubType != NULL)
	{
		pSubType = new GUID();
		*pSubType = *rhs.pSubType;
	}
	if (rhs.pFormatType != NULL)
	{
		pFormatType = new GUID();
		*pFormatType = *rhs.pFormatType;
	}
	bCompression = rhs.bCompression;
	
	return *this;
}

GSOUTPIN_ACCEPT_MEDIATYPE::GSOUTPIN_ACCEPT_MEDIATYPE() : GSPIN_ACCEPT_MEDIATYPE(),
	nSampleSize(0), bufW(0), bufH(0), refFlag(GSREF_ACCEPT_MEDIATYPE)
{
	
}
GSOUTPIN_ACCEPT_MEDIATYPE::GSOUTPIN_ACCEPT_MEDIATYPE(GUID mainType, GUID subType, BOOL bCompress,GSPIN_MEDIASAMPLE_REF _refFlag, ULONG _nSampleSize, UINT _bufW, UINT _bufH)
: GSPIN_ACCEPT_MEDIATYPE(mainType, subType, bCompress), refFlag(refFlag), nSampleSize(_nSampleSize), bufW(_bufW), bufH(_bufH)
{

}

GSOUTPIN_ACCEPT_MEDIATYPE::GSOUTPIN_ACCEPT_MEDIATYPE(GUID mainType, GUID subType, GUID formatType, BOOL bCompress, GSPIN_MEDIASAMPLE_REF _regFlag, ULONG _nSampleSize, UINT _bufW, UINT _bufH)
: GSPIN_ACCEPT_MEDIATYPE(mainType, subType, formatType, bCompress), refFlag(refFlag), nSampleSize(_nSampleSize), bufW(_bufW), bufH(_bufH)
{

}
GSOUTPIN_ACCEPT_MEDIATYPE::~GSOUTPIN_ACCEPT_MEDIATYPE()
{

}

GSOUTPIN_ACCEPT_MEDIATYPE& GSOUTPIN_ACCEPT_MEDIATYPE::operator = (const GSOUTPIN_ACCEPT_MEDIATYPE &rhs)
{
	SAFE_DELETE(pMainType);
	SAFE_DELETE(pSubType);
	SAFE_DELETE(pFormatType);
	if (rhs.pMainType != NULL)
	{
		pMainType = new GUID();
		*pMainType = *rhs.pMainType;
	}
	if (rhs.pSubType != NULL)
	{
		pSubType = new GUID();
		*pSubType = *rhs.pSubType;
	}
	if (rhs.pFormatType != NULL)
	{
		pFormatType = new GUID();
		*pFormatType = *rhs.pFormatType;
	}
	bCompression = rhs.bCompression;
	nSampleSize = rhs.nSampleSize;
	bufW = rhs.bufW;
	bufH = rhs.bufH;
	refFlag = rhs.refFlag;
	return *this;
}





GSPIN_ACCEPT_MEDIATYPE_GROUP::GSPIN_ACCEPT_MEDIATYPE_GROUP()
{
	nAcceptType = 0;
	pAcceptTypes = NULL;
}

GSPIN_ACCEPT_MEDIATYPE_GROUP::GSPIN_ACCEPT_MEDIATYPE_GROUP(GSPIN_ACCEPT_MEDIATYPE* _pAcceptTypes, UINT _nAcceptType)
{
	pAcceptTypes = NULL;
	nAcceptType = _nAcceptType;
	if (_nAcceptType > 0)
	{
		pAcceptTypes = new GSPIN_ACCEPT_MEDIATYPE[_nAcceptType];
		for (int i =0; i < _nAcceptType; i++)
		{
			pAcceptTypes[i] = _pAcceptTypes[i];
		}
	}
}

GSPIN_ACCEPT_MEDIATYPE_GROUP::~GSPIN_ACCEPT_MEDIATYPE_GROUP()
{
	SAFE_DELETE_ARRAY(pAcceptTypes);
}

GSPIN_ACCEPT_MEDIATYPE_GROUP& GSPIN_ACCEPT_MEDIATYPE_GROUP::operator = (const GSPIN_ACCEPT_MEDIATYPE_GROUP &rhs)
{
	nAcceptType = 0;
	SAFE_DELETE_ARRAY(pAcceptTypes);
	nAcceptType = rhs.nAcceptType;
	if (rhs.nAcceptType > 0)
	{
		pAcceptTypes = new GSPIN_ACCEPT_MEDIATYPE[rhs.nAcceptType];
		for (int i =0; i < rhs.nAcceptType; i++)
		{
			pAcceptTypes[i] = rhs.pAcceptTypes[i];
		}
	}
	return *this;
}
///////////////////////////

GSOUTPIN_ACCEPT_MEDIATYPE_GROUP::GSOUTPIN_ACCEPT_MEDIATYPE_GROUP()
{
	nAcceptType = 0;
	pAcceptTypes = NULL;
}

GSOUTPIN_ACCEPT_MEDIATYPE_GROUP::GSOUTPIN_ACCEPT_MEDIATYPE_GROUP(GSOUTPIN_ACCEPT_MEDIATYPE* _pAcceptTypes, UINT _nAcceptType)
{
	pAcceptTypes = NULL;
	nAcceptType = _nAcceptType;
	if (_nAcceptType > 0)
	{
		pAcceptTypes = new GSOUTPIN_ACCEPT_MEDIATYPE[_nAcceptType];
		for (int i =0; i < _nAcceptType; i++)
		{
			pAcceptTypes[i] = _pAcceptTypes[i];
		}
	}
}

GSOUTPIN_ACCEPT_MEDIATYPE_GROUP::~GSOUTPIN_ACCEPT_MEDIATYPE_GROUP()
{
	SAFE_DELETE_ARRAY(pAcceptTypes);
}

GSOUTPIN_ACCEPT_MEDIATYPE_GROUP& GSOUTPIN_ACCEPT_MEDIATYPE_GROUP::operator = (const GSOUTPIN_ACCEPT_MEDIATYPE_GROUP &rhs)
{
	nAcceptType = 0;
	SAFE_DELETE_ARRAY(pAcceptTypes);
	nAcceptType = rhs.nAcceptType;
	if (rhs.nAcceptType > 0)
	{
		pAcceptTypes = new GSOUTPIN_ACCEPT_MEDIATYPE[rhs.nAcceptType];
		for (int i =0; i < rhs.nAcceptType; i++)
		{
			pAcceptTypes[i] = rhs.pAcceptTypes[i];
		}
	}
	return *this;
}

//////////////////////////////
GSFILTER_PIN_DESC::GSFILTER_PIN_DESC()
{
	swprintf_s(pinName,MAX_PATH, L"");
	pinType = GSINPUT_PIN;
}

GSFILTER_PIN_DESC::GSFILTER_PIN_DESC(LPCWSTR _pinName, GSPIN_TYPE _pinType) 
: pinType(_pinType)
{
	wcscpy_s(pinName, MAX_PATH, _pinName);
}
GSFILTER_PIN_DESC& GSFILTER_PIN_DESC::operator = (const GSFILTER_PIN_DESC &rhs)
{
	wcscpy_s(pinName, MAX_PATH, rhs.pinName);
	pinType = rhs.pinType;
	
	return *this;
}

GSFILTER_INPUTPIN_DESC::GSFILTER_INPUTPIN_DESC() : GSFILTER_PIN_DESC(), nMatchIdx(-1)
{

}
GSFILTER_INPUTPIN_DESC::GSFILTER_INPUTPIN_DESC(LPCWSTR _pinName, UINT _nMatchIdx, GSPIN_TYPE _pinType, GSPIN_ACCEPT_MEDIATYPE_GROUP _acceptTypes, GSFILTER_INPUTPIN_FUNCS _pFunc) 
: GSFILTER_PIN_DESC(_pinName, _pinType), nMatchIdx(_nMatchIdx), pFunc(_pFunc), acceptTypes(_acceptTypes)
{
	
}

GSFILTER_INPUTPIN_DESC& GSFILTER_INPUTPIN_DESC::operator = (const GSFILTER_INPUTPIN_DESC &rhs)
{
	wcscpy_s(pinName, MAX_PATH, rhs.pinName);
	pinType = rhs.pinType;
	acceptTypes = rhs.acceptTypes;
	nMatchIdx = rhs.nMatchIdx;
	pFunc = rhs.pFunc;
	return *this;
}


GSFILTER_OUTPUTPIN_DESC::GSFILTER_OUTPUTPIN_DESC() : GSFILTER_PIN_DESC(), nMatchIdx(-1)
{

}
GSFILTER_OUTPUTPIN_DESC::GSFILTER_OUTPUTPIN_DESC(LPCWSTR _pinName, UINT _nMatchIdx, GSPIN_TYPE _pinType, GSOUTPIN_ACCEPT_MEDIATYPE_GROUP _acceptTypes, GSFILTER_OUTPUTPIN_FUNCS _pFunc) 
: GSFILTER_PIN_DESC(_pinName, _pinType), nMatchIdx(_nMatchIdx), pFunc(_pFunc), acceptTypes(_acceptTypes)
{

}

GSFILTER_OUTPUTPIN_DESC& GSFILTER_OUTPUTPIN_DESC::operator = (const GSFILTER_OUTPUTPIN_DESC &rhs)
{
	wcscpy_s(pinName, MAX_PATH, rhs.pinName);
	pinType = rhs.pinType;
	acceptTypes = rhs.acceptTypes;
	nMatchIdx = rhs.nMatchIdx;
	pFunc = rhs.pFunc;
	return *this;
}


GSFILTER_STREAMPIN_DESC::GSFILTER_STREAMPIN_DESC() : GSFILTER_PIN_DESC(), nMatchIdx(0)
{
	
}
GSFILTER_STREAMPIN_DESC::GSFILTER_STREAMPIN_DESC(LPCWSTR _pinName, UINT _nMatchIdx, GSPIN_TYPE _pinType, GSOUTPIN_ACCEPT_MEDIATYPE_GROUP _acceptTypes, GSFILTER_STREAMPIN_FUNCS _pFunc) 
: GSFILTER_PIN_DESC(_pinName, _pinType), nMatchIdx(_nMatchIdx), pFunc(_pFunc), acceptTypes(_acceptTypes)
{

}

GSFILTER_STREAMPIN_DESC& GSFILTER_STREAMPIN_DESC::operator = (const GSFILTER_STREAMPIN_DESC &rhs)
{
	wcscpy_s(pinName, MAX_PATH, rhs.pinName);
	nMatchIdx = rhs.nMatchIdx;
	pinType = rhs.pinType;
	acceptTypes = rhs.acceptTypes;
	pFunc = rhs.pFunc;
	return *this;
}