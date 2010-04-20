#pragma once
#ifndef SAFE_ADDREF
#define SAFE_ADDREF(p)      { if (p) { (p)->AddRef(); } }
#endif

#ifndef SAFE_RELEASE
#define SAFE_RELEASE(p)       { if (p) { (p)->Release();  (p) = NULL; } }
#endif

#ifndef SAFE_DELETE_ARRAY
#define SAFE_DELETE_ARRAY(p)  { delete [](p); p = NULL; }
#endif

#ifndef SAFE_DELETE
#define SAFE_DELETE(p)        { delete (p); p = NULL;  }
#endif