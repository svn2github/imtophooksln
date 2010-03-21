

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Nov 05 12:36:52 2009
 */
/* Compiler settings for .\IAutoInt.idl:
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


#ifndef __ILMVAutoInt_h__
#define __ILMVAutoInt_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILMVAutoInt_FWD_DEFINED__
#define __ILMVAutoInt_FWD_DEFINED__
typedef interface ILMVAutoInt ILMVAutoInt;
#endif 	/* __ILMVAutoInt_FWD_DEFINED__ */


#ifndef __LMVAutoInt_FWD_DEFINED__
#define __LMVAutoInt_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMVAutoInt LMVAutoInt;
#else
typedef struct LMVAutoInt LMVAutoInt;
#endif /* __cplusplus */

#endif 	/* __LMVAutoInt_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LMVAutoIntLib_LIBRARY_DEFINED__
#define __LMVAutoIntLib_LIBRARY_DEFINED__

/* library LMVAutoIntLib */
/* [helpstring][version][uuid] */ 

#ifndef __IAutoInt_H__
#define __IAutoInt_H__
static const GUID CLSID_LMVAutoInt             = {0xe2b7dd13, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVAutoIntPropertyPage = {0xe2b7dd14, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMVAutoInt              = {0xe2b7dd15, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVAboutAutoInt        = {0xe2b7dd16, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID LIBID_LMVAutoIntLib          = {0xe2b7dd17, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
#endif 

EXTERN_C const IID LIBID_LMVAutoIntLib;

#ifndef __ILMVAutoInt_INTERFACE_DEFINED__
#define __ILMVAutoInt_INTERFACE_DEFINED__

/* interface ILMVAutoInt */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ILMVAutoInt;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DD15-38C5-11D5-91F6-00104BDB8FF9")
    ILMVAutoInt : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EnableAutoInt( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_EnableAutoInt( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMVAutoIntVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMVAutoInt * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMVAutoInt * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMVAutoInt * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMVAutoInt * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMVAutoInt * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMVAutoInt * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMVAutoInt * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableAutoInt )( 
            ILMVAutoInt * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableAutoInt )( 
            ILMVAutoInt * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        END_INTERFACE
    } ILMVAutoIntVtbl;

    interface ILMVAutoInt
    {
        CONST_VTBL struct ILMVAutoIntVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMVAutoInt_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMVAutoInt_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMVAutoInt_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMVAutoInt_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMVAutoInt_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMVAutoInt_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMVAutoInt_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMVAutoInt_get_EnableAutoInt(This,pVal)	\
    ( (This)->lpVtbl -> get_EnableAutoInt(This,pVal) ) 

#define ILMVAutoInt_put_EnableAutoInt(This,newVal)	\
    ( (This)->lpVtbl -> put_EnableAutoInt(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMVAutoInt_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LMVAutoInt;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DD13-38C5-11D5-91F6-00104BDB8FF9")
LMVAutoInt;
#endif
#endif /* __LMVAutoIntLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


