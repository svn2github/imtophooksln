#ifndef COMMON_SUPPORT__H__
#define COMMON_SUPPORT__H__

#ifdef __cplusplus
extern "C"
{
#endif

// ==========================================================================================
// entry point macros
// ==========================================================================================
// This defines the calling conventions of the entry points for
// dynamic libraries. This varies depending upon the operating system.

#ifdef _LIB // static library
    #define	CS_API 
    #define	CS_API_ENTRY __cdecl
    typedef void (* DLL_EP)(void);
    #define	DLL_EP_PTR __cdecl *
#else
#if defined (_WIN32) || defined(WIN32) || defined(__WIN32__)
	#ifdef CS_API_EXPORTS
		#define	CS_API __declspec(dllexport)
	#else
		#define	CS_API __declspec(dllimport)
	#endif
    #define	CS_API_ENTRY __cdecl
    typedef void (* DLL_EP)(void);
    #define	DLL_EP_PTR __cdecl *
#else
    #define	CS_API
    #define	CS_API_ENTRY
    typedef void (* DLL_EP)(void);
    #define	DLL_EP_PTR *
#endif
#endif

// ==========================================================================================

// ==========================================================================================
#ifdef __cplusplus
}
#endif

#endif