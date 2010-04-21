

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Nov 05 12:42:12 2009
 */
/* Compiler settings for .\ILMAudCalbk.idl:
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


#ifndef __ILMACallback_h__
#define __ILMACallback_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILMAUserCallback_FWD_DEFINED__
#define __ILMAUserCallback_FWD_DEFINED__
typedef interface ILMAUserCallback ILMAUserCallback;
#endif 	/* __ILMAUserCallback_FWD_DEFINED__ */


#ifndef __ILMAUserCallback2_FWD_DEFINED__
#define __ILMAUserCallback2_FWD_DEFINED__
typedef interface ILMAUserCallback2 ILMAUserCallback2;
#endif 	/* __ILMAUserCallback2_FWD_DEFINED__ */


#ifndef __ILMACallback1_FWD_DEFINED__
#define __ILMACallback1_FWD_DEFINED__
typedef interface ILMACallback1 ILMACallback1;
#endif 	/* __ILMACallback1_FWD_DEFINED__ */


#ifndef __ILMACallback_FWD_DEFINED__
#define __ILMACallback_FWD_DEFINED__
typedef interface ILMACallback ILMACallback;
#endif 	/* __ILMACallback_FWD_DEFINED__ */


#ifndef __LMACallback_FWD_DEFINED__
#define __LMACallback_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMACallback LMACallback;
#else
typedef struct LMACallback LMACallback;
#endif /* __cplusplus */

#endif 	/* __LMACallback_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LMACallbackLib_LIBRARY_DEFINED__
#define __LMACallbackLib_LIBRARY_DEFINED__

/* library LMACallbackLib */
/* [helpstring][version][uuid] */ 

#ifndef __ILMACALLBACK_H__
#define __ILMACALLBACK_H__
static const GUID CLSID_LMACallback        = {0xe2b7dd01, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMAAboutCallback   = {0xe2b7dd02, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMACallback1        = {0xe2b7dd03, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMACallback         = {0xE2B7DE34, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMAUserCallback     = {0xe2b7dd04, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID LIBID_LMACallbackLib     = {0xe2b7dd05, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMAUserCallback2    = {0xE2B7DE37, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
#endif 
typedef /* [v1_enum] */ 
enum AudCalBkErrConstants
    {	AUDCALBK_ERR_OK	= 0,
	AUDCALBK_ERR_DROP	= 1,
	AUDCALBK_ERR_DELIVERLASTSAMPLE	= 100
    } 	AudCalBkErrConstants;


EXTERN_C const IID LIBID_LMACallbackLib;

#ifndef __ILMAUserCallback_INTERFACE_DEFINED__
#define __ILMAUserCallback_INTERFACE_DEFINED__

/* interface ILMAUserCallback */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ILMAUserCallback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DD04-38C5-11D5-91F6-00104BDB8FF9")
    ILMAUserCallback : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CallbackProc( 
            /* [in] */ VARIANT *pData,
            /* [in] */ long lDataSize,
            /* [in] */ long lBitsPerSample,
            /* [in] */ long lChannels,
            /* [in] */ long lSamplesPerSec,
            /* [in] */ long lAvgBytesPerSec) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMAUserCallbackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMAUserCallback * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMAUserCallback * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMAUserCallback * This);
        
        HRESULT ( STDMETHODCALLTYPE *CallbackProc )( 
            ILMAUserCallback * This,
            /* [in] */ VARIANT *pData,
            /* [in] */ long lDataSize,
            /* [in] */ long lBitsPerSample,
            /* [in] */ long lChannels,
            /* [in] */ long lSamplesPerSec,
            /* [in] */ long lAvgBytesPerSec);
        
        END_INTERFACE
    } ILMAUserCallbackVtbl;

    interface ILMAUserCallback
    {
        CONST_VTBL struct ILMAUserCallbackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMAUserCallback_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMAUserCallback_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMAUserCallback_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMAUserCallback_CallbackProc(This,pData,lDataSize,lBitsPerSample,lChannels,lSamplesPerSec,lAvgBytesPerSec)	\
    ( (This)->lpVtbl -> CallbackProc(This,pData,lDataSize,lBitsPerSample,lChannels,lSamplesPerSec,lAvgBytesPerSec) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMAUserCallback_INTERFACE_DEFINED__ */


#ifndef __ILMAUserCallback2_INTERFACE_DEFINED__
#define __ILMAUserCallback2_INTERFACE_DEFINED__

/* interface ILMAUserCallback2 */
/* [unique][helpstring][uuid][dual][local][object] */ 


EXTERN_C const IID IID_ILMAUserCallback2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DE37-38C5-11D5-91F6-00104BDB8FF9")
    ILMAUserCallback2 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CallbackProc( 
            /* [in] */ long pData,
            /* [in] */ long lDataSize,
            /* [in] */ long lBitsPerSample,
            /* [in] */ long lChannels,
            /* [in] */ long lSamplesPerSec,
            /* [in] */ long lAvgBytesPerSec) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMAUserCallback2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMAUserCallback2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMAUserCallback2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMAUserCallback2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *CallbackProc )( 
            ILMAUserCallback2 * This,
            /* [in] */ long pData,
            /* [in] */ long lDataSize,
            /* [in] */ long lBitsPerSample,
            /* [in] */ long lChannels,
            /* [in] */ long lSamplesPerSec,
            /* [in] */ long lAvgBytesPerSec);
        
        END_INTERFACE
    } ILMAUserCallback2Vtbl;

    interface ILMAUserCallback2
    {
        CONST_VTBL struct ILMAUserCallback2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMAUserCallback2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMAUserCallback2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMAUserCallback2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMAUserCallback2_CallbackProc(This,pData,lDataSize,lBitsPerSample,lChannels,lSamplesPerSec,lAvgBytesPerSec)	\
    ( (This)->lpVtbl -> CallbackProc(This,pData,lDataSize,lBitsPerSample,lChannels,lSamplesPerSec,lAvgBytesPerSec) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMAUserCallback2_INTERFACE_DEFINED__ */


#ifndef __ILMACallback1_INTERFACE_DEFINED__
#define __ILMACallback1_INTERFACE_DEFINED__

/* interface ILMACallback1 */
/* [unique][helpstring][uuid][dual][local][object] */ 


EXTERN_C const IID IID_ILMACallback1;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DD03-38C5-11D5-91F6-00104BDB8FF9")
    ILMACallback1 : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CallbackObj( 
            /* [in] */ ILMAUserCallback *pCallbackObj) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMACallback1Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMACallback1 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMACallback1 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMACallback1 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMACallback1 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMACallback1 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMACallback1 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMACallback1 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CallbackObj )( 
            ILMACallback1 * This,
            /* [in] */ ILMAUserCallback *pCallbackObj);
        
        END_INTERFACE
    } ILMACallback1Vtbl;

    interface ILMACallback1
    {
        CONST_VTBL struct ILMACallback1Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMACallback1_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMACallback1_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMACallback1_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMACallback1_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMACallback1_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMACallback1_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMACallback1_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMACallback1_put_CallbackObj(This,pCallbackObj)	\
    ( (This)->lpVtbl -> put_CallbackObj(This,pCallbackObj) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMACallback1_INTERFACE_DEFINED__ */


#ifndef __ILMACallback_INTERFACE_DEFINED__
#define __ILMACallback_INTERFACE_DEFINED__

/* interface ILMACallback */
/* [unique][helpstring][uuid][dual][local][object] */ 


EXTERN_C const IID IID_ILMACallback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DE34-38C5-11D5-91F6-00104BDB8FF9")
    ILMACallback : public ILMACallback1
    {
    public:
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CallbackObj2( 
            /* [in] */ IUnknown *pCallbackObj) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMACallbackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMACallback * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMACallback * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMACallback * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMACallback * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMACallback * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMACallback * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMACallback * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CallbackObj )( 
            ILMACallback * This,
            /* [in] */ ILMAUserCallback *pCallbackObj);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CallbackObj2 )( 
            ILMACallback * This,
            /* [in] */ IUnknown *pCallbackObj);
        
        END_INTERFACE
    } ILMACallbackVtbl;

    interface ILMACallback
    {
        CONST_VTBL struct ILMACallbackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMACallback_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMACallback_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMACallback_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMACallback_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMACallback_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMACallback_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMACallback_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMACallback_put_CallbackObj(This,pCallbackObj)	\
    ( (This)->lpVtbl -> put_CallbackObj(This,pCallbackObj) ) 


#define ILMACallback_put_CallbackObj2(This,pCallbackObj)	\
    ( (This)->lpVtbl -> put_CallbackObj2(This,pCallbackObj) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMACallback_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LMACallback;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DD01-38C5-11D5-91F6-00104BDB8FF9")
LMACallback;
#endif
#endif /* __LMACallbackLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


