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
		static ITouchScreen *getTouchScreen(float cw = 640.0, float ch = 480.0);
		static void destroy();
	private:
		static CTouchScreen *tscreen;
	};
}

#endif
