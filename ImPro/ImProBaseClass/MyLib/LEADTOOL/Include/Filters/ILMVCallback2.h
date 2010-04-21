

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Nov 05 12:37:16 2009
 */
/* Compiler settings for .\ILMVCallback.idl:
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


#ifndef __ILMVCallback2_h__
#define __ILMVCallback2_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILMVUserCallback_FWD_DEFINED__
#define __ILMVUserCallback_FWD_DEFINED__
typedef interface ILMVUserCallback ILMVUserCallback;
#endif 	/* __ILMVUserCallback_FWD_DEFINED__ */


#ifndef __ILMVCallback1_FWD_DEFINED__
#define __ILMVCallback1_FWD_DEFINED__
typedef interface ILMVCallback1 ILMVCallback1;
#endif 	/* __ILMVCallback1_FWD_DEFINED__ */


#ifndef __ILMVCallback_FWD_DEFINED__
#define __ILMVCallback_FWD_DEFINED__
typedef interface ILMVCallback ILMVCallback;
#endif 	/* __ILMVCallback_FWD_DEFINED__ */


#ifndef __LMVCallback_FWD_DEFINED__
#define __LMVCallback_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMVCallback LMVCallback;
#else
typedef struct LMVCallback LMVCallback;
#endif /* __cplusplus */

#endif 	/* __LMVCallback_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LMVCallbackLib_LIBRARY_DEFINED__
#define __LMVCallbackLib_LIBRARY_DEFINED__

/* library LMVCallbackLib */
/* [helpstring][version][uuid] */ 

#ifndef __ILMVCALLBACK2_H__
#define __ILMVCALLBACK2_H__
static const GUID CLSID_CallbackFilter             = {0xe2b7ddb0, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVAboutCallback =           {0xe2b7ddb1, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID LIBID_LMVCallbackLib             = {0xe2b7ddb2, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMVCallback1                = {0xe2b7ddb3, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMVCallback                 = {0xe2b7df61, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMVUserCallback             = {0xe2b7ddb4, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
#endif 
typedef /* [v1_enum] */ 
enum VdCalBkErrConstants
    {	VDCALBK_ERR_OK	= 0,
	VDCALBK_ERR_DROP	= 1,
	VDCALBK_ERR_DELIVERLASTFRAME	= 100
    } 	VdCalBkErrConstants;


EXTERN_C const IID LIBID_LMVCallbackLib;

#ifndef __ILMVUserCallback_INTERFACE_DEFINED__
#define __ILMVUserCallback_INTERFACE_DEFINED__

/* interface ILMVUserCallback */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ILMVUserCallback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DDB4-38C5-11D5-91F6-00104BDB8FF9")
    ILMVUserCallback : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ReceiveProc( 
            /* [in] */ long pData,
            /* [in] */ long lWidth,
            /* [in] */ long lHeight,
            /* [in] */ long lBitCount,
            /* [in] */ long lSize,
            /* [in] */ long bTopDown) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMVUserCallbackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMVUserCallback * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMVUserCallback * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMVUserCallback * This);
        
        HRESULT ( STDMETHODCALLTYPE *ReceiveProc )( 
            ILMVUserCallback * This,
            /* [in] */ long pData,
            /* [in] */ long lWidth,
            /* [in] */ long lHeight,
            /* [in] */ long lBitCount,
            /* [in] */ long lSize,
            /* [in] */ long bTopDown);
        
        END_INTERFACE
    } ILMVUserCallbackVtbl;

    interface ILMVUserCallback
    {
        CONST_VTBL struct ILMVUserCallbackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMVUserCallback_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMVUserCallback_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMVUserCallback_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMVUserCallback_ReceiveProc(This,pData,lWidth,lHeight,lBitCount,lSize,bTopDown)	\
    ( (This)->lpVtbl -> ReceiveProc(This,pData,lWidth,lHeight,lBitCount,lSize,bTopDown) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMVUserCallback_INTERFACE_DEFINED__ */


#ifndef __ILMVCallback1_INTERFACE_DEFINED__
#define __ILMVCallback1_INTERFACE_DEFINED__

/* interface ILMVCallback1 */
/* [unique][helpstring][uuid][dual][local][object] */ 


EXTERN_C const IID IID_ILMVCallback1;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DDB3-38C5-11D5-91F6-00104BDB8FF9")
    ILMVCallback1 : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ReceiveProcObj( 
            /* [in] */ IUnknown *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_InputPalette( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OutputPalette( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OutputPalette( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMVCallback1Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMVCallback1 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMVCallback1 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMVCallback1 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMVCallback1 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMVCallback1 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMVCallback1 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMVCallback1 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ReceiveProcObj )( 
            ILMVCallback1 * This,
            /* [in] */ IUnknown *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InputPalette )( 
            ILMVCallback1 * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OutputPalette )( 
            ILMVCallback1 * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutputPalette )( 
            ILMVCallback1 * This,
            /* [retval][out] */ VARIANT *pVal);
        
        END_INTERFACE
    } ILMVCallback1Vtbl;

    interface ILMVCallback1
    {
        CONST_VTBL struct ILMVCallback1Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMVCallback1_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMVCallback1_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMVCallback1_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMVCallback1_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMVCallback1_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMVCallback1_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMVCallback1_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMVCallback1_put_ReceiveProcObj(This,pVal)	\
    ( (This)->lpVtbl -> put_ReceiveProcObj(This,pVal) ) 

#define ILMVCallback1_get_InputPalette(This,pVal)	\
    ( (This)->lpVtbl -> get_InputPalette(This,pVal) ) 

#define ILMVCallback1_put_OutputPalette(This,newVal)	\
    ( (This)->lpVtbl -> put_OutputPalette(This,newVal) ) 

#define ILMVCallback1_get_OutputPalette(This,pVal)	\
    ( (This)->lpVtbl -> get_OutputPalette(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMVCallback1_INTERFACE_DEFINED__ */


#ifndef __ILMVCallback_INTERFACE_DEFINED__
#define __ILMVCallback_INTERFACE_DEFINED__

/* interface ILMVCallback */
/* [unique][helpstring][uuid][dual][local][object] */ 


EXTERN_C const IID IID_ILMVCallback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DF61-38C5-11D5-91F6-00104BDB8FF9")
    ILMVCallback : public ILMVCallback1
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CurrentPosition( 
            /* [retval][out] */ double *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CurrentFramePosition( 
            /* [retval][out] */ long *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMVCallbackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMVCallback * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMVCallback * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMVCallback * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMVCallback * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMVCallback * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMVCallback * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMVCallback * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ReceiveProcObj )( 
            ILMVCallback * This,
            /* [in] */ IUnknown *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InputPalette )( 
            ILMVCallback * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OutputPalette )( 
            ILMVCallback * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutputPalette )( 
            ILMVCallback * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentPosition )( 
            ILMVCallback * This,
            /* [retval][out] */ double *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentFramePosition )( 
            ILMVCallback * This,
            /* [retval][out] */ long *pVal);
        
        END_INTERFACE
    } ILMVCallbackVtbl;

    interface ILMVCallback
    {
        CONST_VTBL struct ILMVCallbackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMVCallback_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMVCallback_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMVCallback_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMVCallback_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMVCallback_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMVCallback_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMVCallback_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMVCallback_put_ReceiveProcObj(This,pVal)	\
    ( (This)->lpVtbl -> put_ReceiveProcObj(This,pVal) ) 

#define ILMVCallback_get_InputPalette(This,pVal)	\
    ( (This)->lpVtbl -> get_InputPalette(This,pVal) ) 

#define ILMVCallback_put_OutputPalette(This,newVal)	\
    ( (This)->lpVtbl -> put_OutputPalette(This,newVal) ) 

#define ILMVCallback_get_OutputPalette(This,pVal)	\
    ( (This)->lpVtbl -> get_OutputPalette(This,pVal) ) 


#define ILMVCallback_get_CurrentPosition(This,pVal)	\
    ( (This)->lpVtbl -> get_CurrentPosition(This,pVal) ) 

#define ILMVCallback_get_CurrentFramePosition(This,pVal)	\
    ( (This)->lpVtbl -> get_CurrentFramePosition(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMVCallback_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LMVCallback;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DDB0-38C5-11D5-91F6-00104BDB8FF9")
LMVCallback;
#endif
#endif /* __LMVCallbackLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


