#include "stdafx.h"
#include "ARLayoutSource.h"
#include "ARLayoutFilter.h"

ARLayoutSource::ARLayoutSource( LPUNKNOWN pUnk, HRESULT *phr ) : 
CSource(NAME("AR_LAYOUT"), pUnk, CLSID_ARLayoutSource) 
{
	ARLayoutFilter *LayoutPin = new ARLayoutFilter(phr, this, L"Layout");	  
	ARLayoutFilter *MaskPin = new ARLayoutFilter(phr, this, L"Mask");
}