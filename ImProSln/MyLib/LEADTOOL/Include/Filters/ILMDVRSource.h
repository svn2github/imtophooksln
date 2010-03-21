

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Nov 05 12:45:08 2009
 */
/* Compiler settings for .\DVRSource.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __ILMDVRSource_h__
#define __ILMDVRSource_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILMDVRSource_FWD_DEFINED__
#define __ILMDVRSource_FWD_DEFINED__
typedef interface ILMDVRSource ILMDVRSource;
#endif 	/* __ILMDVRSource_FWD_DEFINED__ */


#ifndef __LMDVRSource_FWD_DEFINED__
#define __LMDVRSource_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMDVRSource LMDVRSource;
#else
typedef struct LMDVRSource LMDVRSource;
#endif /* __cplusplus */

#endif 	/* __LMDVRSource_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LMDVRSourceLib_LIBRARY_DEFINED__
#define __LMDVRSourceLib_LIBRARY_DEFINED__

/* library LMDVRSourceLib */
/* [helpstring][uuid][version] */ 

#ifndef __LMDVRSource_H__
#define __LMDVRSource_H__
static const CLSID CLSID_LMDVRSource = { 0xE2B7DDE9, 0x38C5, 0x11d5, { 0x91, 0xF6, 0x00, 0x10, 0x4B, 0xDB, 0x8F, 0xF9 } };
static const IID LIBID_LMDVRSourceLib = { 0xE2B7DDE8, 0x38C5, 0x11d5, { 0x91, 0xF6, 0x00, 0x10, 0x4B, 0xDB, 0x8F, 0xF9 } };
static const GUID IID_ILMDVRSource = {0xE2B7DDF3, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
#endif // #ifndef __LMDVRSource_H__

#ifndef __DVRGetTotalSizeConstants__
#define __DVRGetTotalSizeConstants__
typedef enum
{
   DVRGetTotalSize_Actual  = 0x0000,
   DVRGetTotalSize_Allowed = 0x0001
} DVRGetTotalSizeConstants;
#endif // #ifndef __DVRGetTotalSizeConstants__

#ifndef __DVRBufferFlagsConstants__
#define __DVRBufferFlagsConstants__
typedef enum
{
   DVRBuffer_Empty  = 0x0001,
   DVRBuffer_Writing = 0x0002,
   DVRBuffer_Finished = 0x0004,
} DVRBufferFlagsConstants;
#endif // #ifndef __DVRBufferFlagsConstants__

typedef /* [public][public] */ 
enum __MIDL___MIDL_itf_DVRSource_0000_0000_0001
    {	LMDVRSource_APILEVEL_1	= 0
    } 	LMDVRSource_APILEVEL;


EXTERN_C const IID LIBID_LMDVRSourceLib;

#ifndef __ILMDVRSource_INTERFACE_DEFINED__
#define __ILMDVRSource_INTERFACE_DEFINED__

/* interface ILMDVRSource */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ILMDVRSource;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DDF3-38C5-11D5-91F6-00104BDB8FF9")
    ILMDVRSource : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAvailabilityInfo( 
            /* [out] */ double *pStartOffset,
            /* [out] */ double *pEndOffset,
            /* [out] */ double *pTotalSize) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FolderCount( 
            /* [retval][out] */ long *pnFolderCount) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FolderName( 
            /* [in] */ long nFolderIndex,
            /* [retval][out] */ BSTR *pszBufferPath) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetBufferTotalSize( 
            /* [in] */ long nFolderIndex,
            /* [in] */ long uFlags,
            /* [out] */ long *pnFiles,
            /* [out] */ double *pnTotalFileSize) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CopyBufferToFile( 
            /* [in] */ BSTR pszTargetFile,
            /* [in] */ double startOffset,
            /* [in] */ double endOffset) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadData( 
            /* [in] */ double startOffset,
            /* [in] */ long minSize,
            /* [in] */ long maxSize,
            /* [in] */ DWORD dwUserData,
            /* [out] */ BYTE *pData,
            /* [out] */ long *pSizeRead) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ResetToDefaultsEx( 
            LMDVRSource_APILEVEL ApiLevel) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetBufferInfo( 
            /* [in] */ long nBufferIndex,
            /* [out] */ BSTR *pszFileName,
            /* [out] */ double *pnUsefulSize,
            /* [out] */ double *pnFileSize,
            /* [out] */ long *pnPlayIndex,
            /* [out] */ long *pnFlags) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMDVRSourceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMDVRSource * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMDVRSource * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMDVRSource * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetAvailabilityInfo )( 
            ILMDVRSource * This,
            /* [out] */ double *pStartOffset,
            /* [out] */ double *pEndOffset,
            /* [out] */ double *pTotalSize);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FolderCount )( 
            ILMDVRSource * This,
            /* [retval][out] */ long *pnFolderCount);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FolderName )( 
            ILMDVRSource * This,
            /* [in] */ long nFolderIndex,
            /* [retval][out] */ BSTR *pszBufferPath);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetBufferTotalSize )( 
            ILMDVRSource * This,
            /* [in] */ long nFolderIndex,
            /* [in] */ long uFlags,
            /* [out] */ long *pnFiles,
            /* [out] */ double *pnTotalFileSize);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CopyBufferToFile )( 
            ILMDVRSource * This,
            /* [in] */ BSTR pszTargetFile,
            /* [in] */ double startOffset,
            /* [in] */ double endOffset);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReadData )( 
            ILMDVRSource * This,
            /* [in] */ double startOffset,
            /* [in] */ long minSize,
            /* [in] */ long maxSize,
            /* [in] */ DWORD dwUserData,
            /* [out] */ BYTE *pData,
            /* [out] */ long *pSizeRead);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetToDefaultsEx )( 
            ILMDVRSource * This,
            LMDVRSource_APILEVEL ApiLevel);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetBufferInfo )( 
            ILMDVRSource * This,
            /* [in] */ long nBufferIndex,
            /* [out] */ BSTR *pszFileName,
            /* [out] */ double *pnUsefulSize,
            /* [out] */ double *pnFileSize,
            /* [out] */ long *pnPlayIndex,
            /* [out] */ long *pnFlags);
        
        END_INTERFACE
    } ILMDVRSourceVtbl;

    interface ILMDVRSource
    {
        CONST_VTBL struct ILMDVRSourceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMDVRSource_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMDVRSource_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMDVRSource_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMDVRSource_GetAvailabilityInfo(This,pStartOffset,pEndOffset,pTotalSize)	\
    ( (This)->lpVtbl -> GetAvailabilityInfo(This,pStartOffset,pEndOffset,pTotalSize) ) 

#define ILMDVRSource_get_FolderCount(This,pnFolderCount)	\
    ( (This)->lpVtbl -> get_FolderCount(This,pnFolderCount) ) 

#define ILMDVRSource_get_FolderName(This,nFolderIndex,pszBufferPath)	\
    ( (This)->lpVtbl -> get_FolderName(This,nFolderIndex,pszBufferPath) ) 

#define ILMDVRSource_GetBufferTotalSize(This,nFolderIndex,uFlags,pnFiles,pnTotalFileSize)	\
    ( (This)->lpVtbl -> GetBufferTotalSize(This,nFolderIndex,uFlags,pnFiles,pnTotalFileSize) ) 

#define ILMDVRSource_CopyBufferToFile(This,pszTargetFile,startOffset,endOffset)	\
    ( (This)->lpVtbl -> CopyBufferToFile(This,pszTargetFile,startOffset,endOffset) ) 

#define ILMDVRSource_ReadData(This,startOffset,minSize,maxSize,dwUserData,pData,pSizeRead)	\
    ( (This)->lpVtbl -> ReadData(This,startOffset,minSize,maxSize,dwUserData,pData,pSizeRead) ) 

#define ILMDVRSource_ResetToDefaultsEx(This,ApiLevel)	\
    ( (This)->lpVtbl -> ResetToDefaultsEx(This,ApiLevel) ) 

#define ILMDVRSource_GetBufferInfo(This,nBufferIndex,pszFileName,pnUsefulSize,pnFileSize,pnPlayIndex,pnFlags)	\
    ( (This)->lpVtbl -> GetBufferInfo(This,nBufferIndex,pszFileName,pnUsefulSize,pnFileSize,pnPlayIndex,pnFlags) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMDVRSource_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LMDVRSource;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DDE9-38C5-11D5-91F6-00104BDB8FF9")
LMDVRSource;
#endif
#endif /* __LMDVRSourceLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


