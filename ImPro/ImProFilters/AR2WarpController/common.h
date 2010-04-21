#pragma once
#ifndef _IMTOP_COMMON_H_
#define _IMTOP_COMMON_H_
#include <wtypes.h>
#include <tchar.h>

#define _DBG_MSG_PREFIX_TAG L"[Calibration]"

#ifndef _DPRINTF

#if defined(_DEBUG) || defined(_DBG_MSG) || defined(_DBG_REL)
#if defined(_DBG_MSG) || defined(_DBG_REL)
#pragma message("Warning! _DPRINTF defined in release mode!") 
#endif
#define _DPRINTF(argument)    _dprintf##argument
#else
#define _DPRINTF(argument)
#endif
int _dprintf(LPCTSTR fmt, ...);

#endif
#endif