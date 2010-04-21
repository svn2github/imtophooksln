

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Nov 05 12:45:00 2009
 */
/* Compiler settings for .\DVRSink.idl:
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


#ifndef __ILMDVRSink_h__
#define __ILMDVRSink_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILMDVRSink_FWD_DEFINED__
#define __ILMDVRSink_FWD_DEFINED__
typedef interface ILMDVRSink ILMDVRSink;
#endif 	/* __ILMDVRSink_FWD_DEFINED__ */


#ifndef __LMDVRSink_FWD_DEFINED__
#define __LMDVRSink_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMDVRSink LMDVRSink;
#else
typedef struct LMDVRSink LMDVRSink;
#endif /* __cplusplus */

#endif 	/* __LMDVRSink_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LMDVRSinkLib_LIBRARY_DEFINED__
#define __LMDVRSinkLib_LIBRARY_DEFINED__

/* library LMDVRSinkLib */
/* [helpstring][uuid][version] */ 

#ifndef __LMDVRSink_H__
#define __LMDVRSink_H__
static const CLSID CLSID_LMDVRSink = { 0xE2B7DDE5, 0x38C5, 0x11d5, { 0x91, 0xF6, 0x00, 0x10, 0x4B, 0xDB, 0x8F, 0xF9 } };
static const IID LIBID_LMDVRSinkLib = { 0xE2B7DDE6, 0x38C5, 0x11d5, { 0x91, 0xF6, 0x00, 0x10, 0x4B, 0xDB, 0x8F, 0xF9 } };
static const IID IID_ILMDVRSink = {0xE2B7DDE7, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
#endif // #ifndef __LMDVRSink_H__

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
enum __MIDL___MIDL_itf_DVRSink_0000_0000_0001
    {	DVRStatus_Writing	= 0,
	DVRStatus_Paused	= 1,
	DVRStatus_Stopped	= 2
    } 	DVRStatusConstants;

typedef /* [public][public] */ 
enum __MIDL___MIDL_itf_DVRSink_0000_0000_0002
    {	LMDVRSink_APILEVEL_1	= 0
    } 	LMDVRSink_APILEVEL;

typedef /* [public] */ 
enum __MIDL___MIDL_itf_DVRSink_0000_0000_0003
    {	LMDVRSink_EC_ERROR_RECORDING_TO_FILE	= 0x400
    } 	LMDVRSink_EVENT_NOTIFICATIONS;


EXTERN_C const IID LIBID_LMDVRSinkLib;

#ifndef __ILMDVRSink_INTERFACE_DEFINED__
#define __ILMDVRSink_INTERFACE_DEFINED__

/* interface ILMDVRSink */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILMDVRSink;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DDE7-38C5-11D5-91F6-00104BDB8FF9")
    ILMDVRSink : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAvailabilityInfo( 
            /* [out] */ double *pStartOffset,
            /* [out] */ double *pEndOffset,
            /* [out] */ double *pTotalSize) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FolderCount( 
            /* [in] */ long nFolderCount) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FolderCount( 
            /* [retval][out] */ long *pnFolderCount) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FolderName( 
            /* [in] */ long nFolderIndex,
            /* [in] */ BSTR pszBufferPath) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FolderName( 
            /* [in] */ long nFolderIndex,
            /* [retval][out] */ BSTR *pszBufferPath) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_BaseName( 
            /* [in] */ BSTR pszFileName) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BaseName( 
            /* [retval][out] */ BSTR *ppszFileName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetBufferSize( 
            /* [in] */ long nFolderIndex,
            /* [in] */ long nFiles,
            /* [in] */ double fileSize) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetBufferTotalSize( 
            /* [in] */ long nFolderIndex,
            /* [in] */ long uFlags,
            /* [out] */ long *pnFiles,
            /* [out] */ double *pnTotalFileSize) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CopyBufferToFile( 
            /* [in] */ BSTR pszTargetFile,
            /* [in] */ double startOffset,
            /* [in] */ double endOffset) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetStatus( 
            /* [out] */ DVRStatusConstants *pStatus,
            /* [out] */ long *pnCurrentFolderIndex,
            /* [out] */ long *pnCurrentRecordingIndex,
            /* [out] */ double *pnCurrentRecordingSize) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateEvents( 
            /* [in] */ long nRegistrationID,
            /* [in] */ long TargetProcessID,
            /* [out] */ OLE_HANDLE *pDataWrittenEvent,
            /* [out] */ OLE_HANDLE *pRecordingListChangedEvent) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FreeEvents( 
            /* [in] */ long nRegistrationID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ResetToDefaultsEx( 
            /* [in] */ LMDVRSink_APILEVEL ApiLevel) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetBufferInfo( 
            /* [in] */ long nBufferIndex,
            /* [out] */ BSTR *pszFileName,
            /* [out] */ double *pnUsefulSize,
            /* [out] */ double *pnFileSize,
            /* [out] */ long *pnPlayIndex,
            /* [out] */ long *pnFlags) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StartChangingAttributes( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StopChangingAttributes( 
            /* [in] */ VARIANT_BOOL bCancelChanges) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StartBackupToFile( 
            /* [in] */ BSTR pszFileName,
            /* [in] */ long Flags) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StopBackupToFile( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMDVRSinkVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMDVRSink * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMDVRSink * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMDVRSink * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetAvailabilityInfo )( 
            ILMDVRSink * This,
            /* [out] */ double *pStartOffset,
            /* [out] */ double *pEndOffset,
            /* [out] */ double *pTotalSize);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FolderCount )( 
            ILMDVRSink * This,
            /* [in] */ long nFolderCount);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FolderCount )( 
            ILMDVRSink * This,
            /* [retval][out] */ long *pnFolderCount);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FolderName )( 
            ILMDVRSink * This,
            /* [in] */ long nFolderIndex,
            /* [in] */ BSTR pszBufferPath);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FolderName )( 
            ILMDVRSink * This,
            /* [in] */ long nFolderIndex,
            /* [retval][out] */ BSTR *pszBufferPath);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BaseName )( 
            ILMDVRSink * This,
            /* [in] */ BSTR pszFileName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BaseName )( 
            ILMDVRSink * This,
            /* [retval][out] */ BSTR *ppszFileName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetBufferSize )( 
            ILMDVRSink * This,
            /* [in] */ long nFolderIndex,
            /* [in] */ long nFiles,
            /* [in] */ double fileSize);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetBufferTotalSize )( 
            ILMDVRSink * This,
            /* [in] */ long nFolderIndex,
            /* [in] */ long uFlags,
            /* [out] */ long *pnFiles,
            /* [out] */ double *pnTotalFileSize);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CopyBufferToFile )( 
            ILMDVRSink * This,
            /* [in] */ BSTR pszTargetFile,
            /* [in] */ double startOffset,
            /* [in] */ double endOffset);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetStatus )( 
            ILMDVRSink * This,
            /* [out] */ DVRStatusConstants *pStatus,
            /* [out] */ long *pnCurrentFolderIndex,
            /* [out] */ long *pnCurrentRecordingIndex,
            /* [out] */ double *pnCurrentRecordingSize);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateEvents )( 
            ILMDVRSink * This,
            /* [in] */ long nRegistrationID,
            /* [in] */ long TargetProcessID,
            /* [out] */ OLE_HANDLE *pDataWrittenEvent,
            /* [out] */ OLE_HANDLE *pRecordingListChangedEvent);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FreeEvents )( 
            ILMDVRSink * This,
            /* [in] */ long nRegistrationID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetToDefaultsEx )( 
            ILMDVRSink * This,
            /* [in] */ LMDVRSink_APILEVEL ApiLevel);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetBufferInfo )( 
            ILMDVRSink * This,
            /* [in] */ long nBufferIndex,
            /* [out] */ BSTR *pszFileName,
            /* [out] */ double *pnUsefulSize,
            /* [out] */ double *pnFileSize,
            /* [out] */ long *pnPlayIndex,
            /* [out] */ long *pnFlags);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StartChangingAttributes )( 
            ILMDVRSink * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StopChangingAttributes )( 
            ILMDVRSink * This,
            /* [in] */ VARIANT_BOOL bCancelChanges);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StartBackupToFile )( 
            ILMDVRSink * This,
            /* [in] */ BSTR pszFileName,
            /* [in] */ long Flags);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StopBackupToFile )( 
            ILMDVRSink * This);
        
        END_INTERFACE
    } ILMDVRSinkVtbl;

    interface ILMDVRSink
    {
        CONST_VTBL struct ILMDVRSinkVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMDVRSink_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMDVRSink_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMDVRSink_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMDVRSink_GetAvailabilityInfo(This,pStartOffset,pEndOffset,pTotalSize)	\
    ( (This)->lpVtbl -> GetAvailabilityInfo(This,pStartOffset,pEndOffset,pTotalSize) ) 

#define ILMDVRSink_put_FolderCount(This,nFolderCount)	\
    ( (This)->lpVtbl -> put_FolderCount(This,nFolderCount) ) 

#define ILMDVRSink_get_FolderCount(This,pnFolderCount)	\
    ( (This)->lpVtbl -> get_FolderCount(This,pnFolderCount) ) 

#define ILMDVRSink_put_FolderName(This,nFolderIndex,pszBufferPath)	\
    ( (This)->lpVtbl -> put_FolderName(This,nFolderIndex,pszBufferPath) ) 

#define ILMDVRSink_get_FolderName(This,nFolderIndex,pszBufferPath)	\
    ( (This)->lpVtbl -> get_FolderName(This,nFolderIndex,pszBufferPath) ) 

#define ILMDVRSink_put_BaseName(This,pszFileName)	\
    ( (This)->lpVtbl -> put_BaseName(This,pszFileName) ) 

#define ILMDVRSink_get_BaseName(This,ppszFileName)	\
    ( (This)->lpVtbl -> get_BaseName(This,ppszFileName) ) 

#define ILMDVRSink_SetBufferSize(This,nFolderIndex,nFiles,fileSize)	\
    ( (This)->lpVtbl -> SetBufferSize(This,nFolderIndex,nFiles,fileSize) ) 

#define ILMDVRSink_GetBufferTotalSize(This,nFolderIndex,uFlags,pnFiles,pnTotalFileSize)	\
    ( (This)->lpVtbl -> GetBufferTotalSize(This,nFolderIndex,uFlags,pnFiles,pnTotalFileSize) ) 

#define ILMDVRSink_CopyBufferToFile(This,pszTargetFile,startOffset,endOffset)	\
    ( (This)->lpVtbl -> CopyBufferToFile(This,pszTargetFile,startOffset,endOffset) ) 

#define ILMDVRSink_GetStatus(This,pStatus,pnCurrentFolderIndex,pnCurrentRecordingIndex,pnCurrentRecordingSize)	\
    ( (This)->lpVtbl -> GetStatus(This,pStatus,pnCurrentFolderIndex,pnCurrentRecordingIndex,pnCurrentRecordingSize) ) 

#define ILMDVRSink_CreateEvents(This,nRegistrationID,TargetProcessID,pDataWrittenEvent,pRecordingListChangedEvent)	\
    ( (This)->lpVtbl -> CreateEvents(This,nRegistrationID,TargetProcessID,pDataWrittenEvent,pRecordingListChangedEvent) ) 

#define ILMDVRSink_FreeEvents(This,nRegistrationID)	\
    ( (This)->lpVtbl -> FreeEvents(This,nRegistrationID) ) 

#define ILMDVRSink_ResetToDefaultsEx(This,ApiLevel)	\
    ( (This)->lpVtbl -> ResetToDefaultsEx(This,ApiLevel) ) 

#define ILMDVRSink_GetBufferInfo(This,nBufferIndex,pszFileName,pnUsefulSize,pnFileSize,pnPlayIndex,pnFlags)	\
    ( (This)->lpVtbl -> GetBufferInfo(This,nBufferIndex,pszFileName,pnUsefulSize,pnFileSize,pnPlayIndex,pnFlags) ) 

#define ILMDVRSink_StartChangingAttributes(This)	\
    ( (This)->lpVtbl -> StartChangingAttributes(This) ) 

#define ILMDVRSink_StopChangingAttributes(This,bCancelChanges)	\
    ( (This)->lpVtbl -> StopChangingAttributes(This,bCancelChanges) ) 

#define ILMDVRSink_StartBackupToFile(This,pszFileName,Flags)	\
    ( (This)->lpVtbl -> StartBackupToFile(This,pszFileName,Flags) ) 

#define ILMDVRSink_StopBackupToFile(This)	\
    ( (This)->lpVtbl -> StopBackupToFile(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMDVRSink_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LMDVRSink;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DDE5-38C5-11D5-91F6-00104BDB8FF9")
LMDVRSink;
#endif
#endif /* __LMDVRSinkLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


