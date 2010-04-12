#pragma once
#ifndef SAFE_ADDREF
#define SAFE_ADDREF(p)      { if (p) { (p)->AddRef(); } }
#endif
