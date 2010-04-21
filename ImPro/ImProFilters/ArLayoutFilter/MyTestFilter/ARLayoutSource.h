
#ifndef _ARLAYOUTSOURCE_H
#define _ARLAYOUTSOURCE_H

#include "dshow.h"
#include "Streams.h"
#include <initguid.h>
#include "combase.h"

// {3A5FCA44-5DDB-44d7-B54F-1316F323E9DD}
DEFINE_GUID(CLSID_ARLayoutSource, 
			0x3a5fca44, 0x5ddb, 0x44d7, 0xb5, 0x4f, 0x13, 0x16, 0xf3, 0x23, 0xe9, 0xdd);

class ARLayoutSource : public CSource{

public:
	ARLayoutSource( LPUNKNOWN pUnk, HRESULT *phr ) ;
	
	static CUnknown * WINAPI CreateInstance(LPUNKNOWN pUnk, HRESULT * phr); 
protected:
	////for COM interface 
	DECLARE_IUNKNOWN;
	
	STDMETHODIMP NonDelegatingQueryInterface(REFIID riid, void **ppv)
	{
		return CSource::NonDelegatingQueryInterface(riid, ppv);
	}

};

#endif