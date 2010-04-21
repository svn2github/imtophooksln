#ifndef SHARED_MEM__H__
#define SHARED_MEM__H__

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
    #define	SM_API 
    #define	SM_API_ENTRY __cdecl
    typedef void (* DLL_EP)(void);
    #define	DLL_EP_PTR __cdecl *
#else
#if defined (_WIN32) || defined(WIN32) || defined(__WIN32__)
	#ifdef SM_API_EXPORTS
		#define	SM_API __declspec(dllexport)
	#else
		#define	SM_API __declspec(dllimport)
	#endif
    #define	SM_API_ENTRY __cdecl
    typedef void (* DLL_EP)(void);
    #define	DLL_EP_PTR __cdecl *
#else
    #define	SM_API
    #define	SM_API_ENTRY
    typedef void (* DLL_EP)(void);
    #define	DLL_EP_PTR *
#endif
#endif

// ==========================================================================================

#define	 SHARED_MEM_NAME_LENGTH		64

struct sharedmem{
	char* pName;
	void* hMapFile;
	void* pBuf;
};

struct globalinfo{
	int count;
	char names[SHARED_MEM_NAME_LENGTH][SHARED_MEM_NAME_LENGTH];
};

struct pixelinfo{
	int width;
	int height;
	int depth;
	int format;
	int size;
};

struct readersWriterTripleBufferLock
{
	volatile int spinlock;
	volatile int readersCount;
	volatile int readersIndex;
	volatile int readersReleasing;
	volatile int writerIndex;
	volatile int writerDirty;
	volatile int writerDirtyIndex;
};

struct header{
	struct pixelinfo pi;
	struct readersWriterTripleBufferLock lock;
};

SM_API const char * SM_API_ENTRY getGlobalMemName();
SM_API sharedmem * SM_API_ENTRY getGlobalMem();
SM_API int SM_API_ENTRY connectGlobalMem();
SM_API void SM_API_ENTRY disconnectGlobalMem();

SM_API int SM_API_ENTRY setupSharedMem(const char *name, struct sharedmem * mem, struct pixelinfo pi);
SM_API int SM_API_ENTRY connectSharedMem(const char *name, struct sharedmem * mem, struct pixelinfo * pi);
SM_API void SM_API_ENTRY disconnectSharedMem(struct sharedmem * mem);
SM_API void SM_API_ENTRY closeSharedMem(struct sharedmem * mem);

SM_API void SM_API_ENTRY cleanupSharedMem(const char *name);

SM_API void SM_API_ENTRY acquireReader(struct sharedmem * mem, unsigned char  ** data);
SM_API void SM_API_ENTRY releaseReader(struct sharedmem * mem, unsigned char  ** data);

SM_API void SM_API_ENTRY acquireWriter(struct sharedmem * mem, unsigned char  ** data);
SM_API void SM_API_ENTRY releaseWriter(struct sharedmem * mem, unsigned char  ** data);

#ifdef __cplusplus
}
#endif

#endif
