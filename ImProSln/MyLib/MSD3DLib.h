// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the MSD3DLIB_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// MSD3DLIB_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef MSD3DLIB_EXPORTS
#define MSD3DLIB_API __declspec(dllexport)
#else
#define MSD3DLIB_API __declspec(dllimport)
#endif

// This class is exported from the MSD3DLib.dll

