#include "stdafx.h"
#include "common.h"

int _dprintf(LPCTSTR fmt, ...)
{
	_TCHAR buffer[4096];
	_TCHAR buffer2[4096];
	va_list marker;
	va_start(marker, fmt);
	int nArgs = _vstprintf_s(buffer, fmt, marker);
	_stprintf_s(buffer2, L"%s %s", _DBG_MSG_PREFIX_TAG, buffer);
	if(buffer2[_tcslen(buffer2) - 1] != '\n')
		_tcscat_s(buffer2, L"\n");
	OutputDebugString(buffer2);
	va_end (marker);
	return nArgs;
}
