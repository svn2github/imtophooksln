

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Nov 05 12:42:35 2009
 */
/* Compiler settings for .\IAudioDet.idl:
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


#ifndef __ILMADet2_h__
#define __ILMADet2_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILMADetUserCallback_FWD_DEFINED__
#define __ILMADetUserCallback_FWD_DEFINED__
typedef interface ILMADetUserCallback ILMADetUserCallback;
#endif 	/* __ILMADetUserCallback_FWD_DEFINED__ */


#ifndef __ILMADet_FWD_DEFINED__
#define __ILMADet_FWD_DEFINED__
typedef interface ILMADet ILMADet;
#endif 	/* __ILMADet_FWD_DEFINED__ */


#ifndef __LMADet_FWD_DEFINED__
#define __LMADet_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMADet LMADet;
#else
typedef struct LMADet LMADet;
#endif /* __cplusplus */

#endif 	/* __LMADet_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LMAAudioDetLib_LIBRARY_DEFINED__
#define __LMAAudioDetLib_LIBRARY_DEFINED__

/* library LMAAudioDetLib */
/* [helpstring][version][uuid] */ 

static const GUID CLSID_LMADet             = {0xe2b7ddaa, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMADetPropertyPage = {0xe2b7ddab, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMAAboutDet        = {0xe2b7ddac, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID LIBID_LMADetLib          = {0xe2b7ddad, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMADet              = {0xe2b7ddae, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMADetUserCallback  = {0xe2b7ddaf, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};

enum AudioLevel
    {	AUDIO_LEVEL_STARTSOUND	= 0,
	AUDIO_LEVEL_SOUND	= ( AUDIO_LEVEL_STARTSOUND + 1 ) ,
	AUDIO_LEVEL_STARTSILENCE	= ( AUDIO_LEVEL_SOUND + 1 ) ,
	AUDIO_LEVEL_SILENCE	= ( AUDIO_LEVEL_STARTSILENCE + 1 ) 
    } ;
typedef /* [v1_enum] */ 
enum AudDetStateConstants
    {	AUDDET_STATE_STOPPED	= 0,
	AUDDET_STATE_RUNNING	= 1
    } 	AudDetStateConstants;


EXTERN_C const IID LIBID_LMAAudioDetLib;

#ifndef __ILMADetUserCallback_INTERFACE_DEFINED__
#define __ILMADetUserCallback_INTERFACE_DEFINED__

/* interface ILMADetUserCallback */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ILMADetUserCallback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DDAF-38C5-11D5-91F6-00104BDB8FF9")
    ILMADetUserCallback : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CallbackProc( 
            /* [in] */ long nEvent,
            /* [in] */ VARIANT *pData,
            /* [in] */ long lDataCount,
            /* [in] */ long lBitsPerSample,
            /* [in] */ long lChannels,
            /* [in] */ long lSamplesPerSec,
            /* [in] */ long lAvgBytesPerSec) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMADetUserCallbackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMADetUserCallback * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMADetUserCallback * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMADetUserCallback * This);
        
        HRESULT ( STDMETHODCALLTYPE *CallbackProc )( 
            ILMADetUserCallback * This,
            /* [in] */ long nEvent,
            /* [in] */ VARIANT *pData,
            /* [in] */ long lDataCount,
            /* [in] */ long lBitsPerSample,
            /* [in] */ long lChannels,
            /* [in] */ long lSamplesPerSec,
            /* [in] */ long lAvgBytesPerSec);
        
        END_INTERFACE
    } ILMADetUserCallbackVtbl;

    interface ILMADetUserCallback
    {
        CONST_VTBL struct ILMADetUserCallbackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMADetUserCallback_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMADetUserCallback_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMADetUserCallback_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMADetUserCallback_CallbackProc(This,nEvent,pData,lDataCount,lBitsPerSample,lChannels,lSamplesPerSec,lAvgBytesPerSec)	\
    ( (This)->lpVtbl -> CallbackProc(This,nEvent,pData,lDataCount,lBitsPerSample,lChannels,lSamplesPerSec,lAvgBytesPerSec) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMADetUserCallback_INTERFACE_DEFINED__ */


#ifndef __ILMADet_INTERFACE_DEFINED__
#define __ILMADet_INTERFACE_DEFINED__

/* interface ILMADet */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILMADet;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DDAE-38C5-11D5-91F6-00104BDB8FF9")
    ILMADet : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CallbackObj( 
            /* [in] */ ILMADetUserCallback *pCallback) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Enable( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Enable( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Threshold( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Threshold( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MinSilenceTime( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MinSilenceTime( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LeftLevel( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RightLevel( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Interval( 
            /* [retval][out] */ long *plInterval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Interval( 
            /* [in] */ long newlInterval) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Delay( 
            /* [retval][out] */ long *plDelay) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Delay( 
            /* [in] */ long newlDelay) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AutoStart( 
            /* [retval][out] */ VARIANT_BOOL *pbAutoStart) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AutoStart( 
            /* [in] */ VARIANT_BOOL newbAutoStart) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StartDetection( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StopDetection( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_State( 
            /* [retval][out] */ AudDetStateConstants *pState) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ResetToDefaults( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMADetVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMADet * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMADet * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMADet * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMADet * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMADet * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMADet * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMADet * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CallbackObj )( 
            ILMADet * This,
            /* [in] */ ILMADetUserCallback *pCallback);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Enable )( 
            ILMADet * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Enable )( 
            ILMADet * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Threshold )( 
            ILMADet * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Threshold )( 
            ILMADet * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MinSilenceTime )( 
            ILMADet * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MinSilenceTime )( 
            ILMADet * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LeftLevel )( 
            ILMADet * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RightLevel )( 
            ILMADet * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Interval )( 
            ILMADet * This,
            /* [retval][out] */ long *plInterval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Interval )( 
            ILMADet * This,
            /* [in] */ long newlInterval);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Delay )( 
            ILMADet * This,
            /* [retval][out] */ long *plDelay);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Delay )( 
            ILMADet * This,
            /* [in] */ long newlDelay);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AutoStart )( 
            ILMADet * This,
            /* [retval][out] */ VARIANT_BOOL *pbAutoStart);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AutoStart )( 
            ILMADet * This,
            /* [in] */ VARIANT_BOOL newbAutoStart);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StartDetection )( 
            ILMADet * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StopDetection )( 
            ILMADet * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_State )( 
            ILMADet * This,
            /* [retval][out] */ AudDetStateConstants *pState);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetToDefaults )( 
            ILMADet * This);
        
        END_INTERFACE
    } ILMADetVtbl;

    interface ILMADet
    {
        CONST_VTBL struct ILMADetVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMADet_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMADet_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMADet_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMADet_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMADet_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMADet_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMADet_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMADet_put_CallbackObj(This,pCallback)	\
    ( (This)->lpVtbl -> put_CallbackObj(This,pCallback) ) 

#define ILMADet_put_Enable(This,newVal)	\
    ( (This)->lpVtbl -> put_Enable(This,newVal) ) 

#define ILMADet_get_Enable(This,pVal)	\
    ( (This)->lpVtbl -> get_Enable(This,pVal) ) 

#define ILMADet_put_Threshold(This,newVal)	\
    ( (This)->lpVtbl -> put_Threshold(This,newVal) ) 

#define ILMADet_get_Threshold(This,pVal)	\
    ( (This)->lpVtbl -> get_Threshold(This,pVal) ) 

#define ILMADet_put_MinSilenceTime(This,newVal)	\
    ( (This)->lpVtbl -> put_MinSilenceTime(This,newVal) ) 

#define ILMADet_get_MinSilenceTime(This,pVal)	\
    ( (This)->lpVtbl -> get_MinSilenceTime(This,pVal) ) 

#define ILMADet_get_LeftLevel(This,pVal)	\
    ( (This)->lpVtbl -> get_LeftLevel(This,pVal) ) 

#define ILMADet_get_RightLevel(This,pVal)	\
    ( (This)->lpVtbl -> get_RightLevel(This,pVal) ) 

#define ILMADet_get_Interval(This,plInterval)	\
    ( (This)->lpVtbl -> get_Interval(This,plInterval) ) 

#define ILMADet_put_Interval(This,newlInterval)	\
    ( (This)->lpVtbl -> put_Interval(This,newlInterval) ) 

#define ILMADet_get_Delay(This,plDelay)	\
    ( (This)->lpVtbl -> get_Delay(This,plDelay) ) 

#define ILMADet_put_Delay(This,newlDelay)	\
    ( (This)->lpVtbl -> put_Delay(This,newlDelay) ) 

#define ILMADet_get_AutoStart(This,pbAutoStart)	\
    ( (This)->lpVtbl -> get_AutoStart(This,pbAutoStart) ) 

#define ILMADet_put_AutoStart(This,newbAutoStart)	\
    ( (This)->lpVtbl -> put_AutoStart(This,newbAutoStart) ) 

#define ILMADet_StartDetection(This)	\
    ( (This)->lpVtbl -> StartDetection(This) ) 

#define ILMADet_StopDetection(This)	\
    ( (This)->lpVtbl -> StopDetection(This) ) 

#define ILMADet_get_State(This,pState)	\
    ( (This)->lpVtbl -> get_State(This,pState) ) 

#define ILMADet_ResetToDefaults(This)	\
    ( (This)->lpVtbl -> ResetToDefaults(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMADet_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LMADet;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DDAA-38C5-11D5-91F6-00104BDB8FF9")
LMADet;
#endif
#endif /* __LMAAudioDetLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


