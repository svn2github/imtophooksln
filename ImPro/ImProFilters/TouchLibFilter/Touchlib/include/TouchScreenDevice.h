#ifndef __TOUCHLIB_TOUCHSCREENDEVICE__
#define __TOUCHLIB_TOUCHSCREENDEVICE__

#include <touchlib_platform.h>
#include <ITouchScreen.h>

namespace touchlib
{
	class CTouchScreen;

	class  TouchScreenDevice 
	{
	public:
		static ITouchScreen *getTouchScreen(int cw = 640, int ch = 480.0);
		static void destroy();
	private:
		static CTouchScreen *tscreen;
	};
}

#endif
