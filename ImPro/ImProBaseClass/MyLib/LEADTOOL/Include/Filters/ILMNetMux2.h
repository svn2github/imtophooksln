

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Nov 05 12:54:48 2009
 */
/* Compiler settings for .\LMNetMux.idl:
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


#ifndef __ILMNetMux2_h__
#define __ILMNetMux2_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILMNetMux1_FWD_DEFINED__
#define __ILMNetMux1_FWD_DEFINED__
typedef interface ILMNetMux1 ILMNetMux1;
#endif 	/* __ILMNetMux1_FWD_DEFINED__ */


#ifndef __ILMNetMux_FWD_DEFINED__
#define __ILMNetMux_FWD_DEFINED__
typedef interface ILMNetMux ILMNetMux;
#endif 	/* __ILMNetMux_FWD_DEFINED__ */


#ifndef __LMNetMux_FWD_DEFINED__
#define __LMNetMux_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMNetMux LMNetMux;
#else
typedef struct LMNetMux LMNetMux;
#endif /* __cplusplus */

#endif 	/* __LMNetMux_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LMNetMuxLib_LIBRARY_DEFINED__
#define __LMNetMuxLib_LIBRARY_DEFINED__

/* library LMNetMuxLib */
/* [helpstring][helpfile][version][uuid] */ 

#ifndef __LMNetMux2_GUID__
#define __LMNetMux2_GUID__
static const IID LIBID_LMNetMuxLib   = {0xe2b7de00,0x38c5,0x11d5,{0x91,0xf6,0x00,0x10,0x4b,0xdb,0x8f,0xf9}};
static const CLSID CLSID_LMNetMux    = {0xe2b7de01,0x38c5,0x11d5,{0x91,0xf6,0x00,0x10,0x4b,0xdb,0x8f,0xf9}};
static const IID IID_ILMNetMux1      = {0xe2b7de02,0x38c5,0x11d5,{0x91,0xf6,0x00,0x10,0x4b,0xdb,0x8f,0xf9}};
static const IID IID_ILMNetMux       = {0xe2b7db80,0x38c5,0x11d5,{0x91,0xf6,0x00,0x10,0x4b,0xdb,0x8f,0xf9}};
#endif 

DEFINE_GUID(LIBID_LMNetMuxLib,0xE2B7DE00,0x38C5,0x11D5,0x91,0xF6,0x00,0x10,0x4B,0xDB,0x8F,0xF9);

#ifndef __ILMNetMux1_INTERFACE_DEFINED__
#define __ILMNetMux1_INTERFACE_DEFINED__

/* interface ILMNetMux1 */
/* [unique][helpstring][dual][uuid][object] */ 


DEFINE_GUID(IID_ILMNetMux1,0xE2B7DE02,0x38C5,0x11D5,0x91,0xF6,0x00,0x10,0x4B,0xDB,0x8F,0xF9);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DE02-38C5-11D5-91F6-00104BDB8FF9")
    ILMNetMux1 : public IDispatch
    {
    public:
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_BitRate( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_BitRateLimit( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_BitRateLimit( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_LiveSource( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_LiveSource( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][helpcontext][id] */ HRESULT STDMETHODCALLTYPE WriteMessage( 
            /* [in] */ BSTR Message) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMNetMux1Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMNetMux1 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMNetMux1 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMNetMux1 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMNetMux1 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMNetMux1 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMNetMux1 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMNetMux1 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BitRate )( 
            ILMNetMux1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BitRateLimit )( 
            ILMNetMux1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][helpcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BitRateLimit )( 
            ILMNetMux1 * This,
            /* [in] */ long newVal);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LiveSource )( 
            ILMNetMux1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][helpcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LiveSource )( 
            ILMNetMux1 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][helpcontext][id] */ HRESULT ( STDMETHODCALLTYPE *WriteMessage )( 
            ILMNetMux1 * This,
            /* [in] */ BSTR Message);
        
        END_INTERFACE
    } ILMNetMux1Vtbl;

    interface ILMNetMux1
    {
        CONST_VTBL struct ILMNetMux1Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMNetMux1_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMNetMux1_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMNetMux1_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMNetMux1_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMNetMux1_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMNetMux1_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMNetMux1_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMNetMux1_get_BitRate(This,pVal)	\
    ( (This)->lpVtbl -> get_BitRate(This,pVal) ) 

#define ILMNetMux1_get_BitRateLimit(This,pVal)	\
    ( (This)->lpVtbl -> get_BitRateLimit(This,pVal) ) 

#define ILMNetMux1_put_BitRateLimit(This,newVal)	\
    ( (This)->lpVtbl -> put_BitRateLimit(This,newVal) ) 

#define ILMNetMux1_get_LiveSource(This,pVal)	\
    ( (This)->lpVtbl -> get_LiveSource(This,pVal) ) 

#define ILMNetMux1_put_LiveSource(This,newVal)	\
    ( (This)->lpVtbl -> put_LiveSource(This,newVal) ) 

#define ILMNetMux1_WriteMessage(This,Message)	\
    ( (This)->lpVtbl -> WriteMessage(This,Message) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMNetMux1_INTERFACE_DEFINED__ */


#ifndef __ILMNetMux_INTERFACE_DEFINED__
#define __ILMNetMux_INTERFACE_DEFINED__

/* interface ILMNetMux */
/* [unique][helpstring][dual][uuid][object] */ 


DEFINE_GUID(IID_ILMNetMux,0xE2B7DB80,0x38C5,0x11D5,0x91,0xF6,0x00,0x10,0x4B,0xDB,0x8F,0xF9);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DB80-38C5-11D5-91F6-00104BDB8FF9")
    ILMNetMux : public ILMNetMux1
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MaxQueueDuration( 
            /* [retval][out] */ double *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MaxQueueDuration( 
            /* [in] */ double newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMNetMuxVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMNetMux * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMNetMux * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMNetMux * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMNetMux * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMNetMux * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMNetMux * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMNetMux * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BitRate )( 
            ILMNetMux * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BitRateLimit )( 
            ILMNetMux * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][helpcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BitRateLimit )( 
            ILMNetMux * This,
            /* [in] */ long newVal);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LiveSource )( 
            ILMNetMux * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][helpcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LiveSource )( 
            ILMNetMux * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][helpcontext][id] */ HRESULT ( STDMETHODCALLTYPE *WriteMessage )( 
            ILMNetMux * This,
            /* [in] */ BSTR Message);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MaxQueueDuration )( 
            ILMNetMux * This,
            /* [retval][out] */ double *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MaxQueueDuration )( 
            ILMNetMux * This,
            /* [in] */ double newVal);
        
        END_INTERFACE
    } ILMNetMuxVtbl;

    interface ILMNetMux
    {
        CONST_VTBL struct ILMNetMuxVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMNetMux_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMNetMux_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMNetMux_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMNetMux_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMNetMux_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMNetMux_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMNetMux_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMNetMux_get_BitRate(This,pVal)	\
    ( (This)->lpVtbl -> get_BitRate(This,pVal) ) 

#define ILMNetMux_get_BitRateLimit(This,pVal)	\
    ( (This)->lpVtbl -> get_BitRateLimit(This,pVal) ) 

#define ILMNetMux_put_BitRateLimit(This,newVal)	\
    ( (This)->lpVtbl -> put_BitRateLimit(This,newVal) ) 

#define ILMNetMux_get_LiveSource(This,pVal)	\
    ( (This)->lpVtbl -> get_LiveSource(This,pVal) ) 

#define ILMNetMux_put_LiveSource(This,newVal)	\
    ( (This)->lpVtbl -> put_LiveSource(This,newVal) ) 

#define ILMNetMux_WriteMessage(This,Message)	\
    ( (This)->lpVtbl -> WriteMessage(This,Message) ) 


#define ILMNetMux_get_MaxQueueDuration(This,pVal)	\
    ( (This)->lpVtbl -> get_MaxQueueDuration(This,pVal) ) 

#define ILMNetMux_put_MaxQueueDuration(This,newVal)	\
    ( (This)->lpVtbl -> put_MaxQueueDuration(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMNetMux_INTERFACE_DEFINED__ */


DEFINE_GUID(CLSID_LMNetMux,0xE2B7DE01,0x38C5,0x11D5,0x91,0xF6,0x00,0x10,0x4B,0xDB,0x8F,0xF9);

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DE01-38C5-11D5-91F6-00104BDB8FF9")
LMNetMux;
#endif
#endif /* __LMNetMuxLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


