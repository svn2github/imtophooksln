#include "TouchScreenDevice.h"
#include <CTouchScreen.h>

using namespace touchlib;

CTouchScreen *TouchScreenDevice::tscreen = 0;

ITouchScreen *TouchScreenDevice::getTouchScreen(float cw, float ch)
{
	if(!tscreen)
	{
		tscreen = new CTouchScreen(cw, ch);	
	}
	return tscreen;
}

void TouchScreenDevice::destroy()
{
	if(tscreen)
	{
		delete tscreen;
		tscreen = NULL;
	}
}
