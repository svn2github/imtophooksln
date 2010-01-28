#ifndef __TOUCHLIB_ICAPTURE__
#define __TOUCHLIB_ICAPTURE__

#include <Image.h>
#include <touchlib_platform.h>

namespace touchlib 
{
	class ICapture
	{
	public:
		virtual IBwImage *getFrame() = 0;

	};
}

#endif  // __TOUCHLIB_ICAPTURE__
