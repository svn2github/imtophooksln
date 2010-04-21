

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Nov 05 12:36:44 2009
 */
/* Compiler settings for .\IAutoCont.idl:
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


#ifndef __ILMVAutoCont_h__
#define __ILMVAutoCont_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILMVAutoCont_FWD_DEFINED__
#define __ILMVAutoCont_FWD_DEFINED__
typedef interface ILMVAutoCont ILMVAutoCont;
#endif 	/* __ILMVAutoCont_FWD_DEFINED__ */


#ifndef __LMVAutoCont_FWD_DEFINED__
#define __LMVAutoCont_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMVAutoCont LMVAutoCont;
#else
typedef struct LMVAutoCont LMVAutoCont;
#endif /* __cplusplus */

#endif 	/* __LMVAutoCont_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LMVAutoContLib_LIBRARY_DEFINED__
#define __LMVAutoContLib_LIBRARY_DEFINED__

/* library LMVAutoContLib */
/* [helpstring][version][uuid] */ 

#ifndef __IAutoCont_H__
#define __IAutoCont_H__
static const GUID CLSID_LMVAutoCont             = {0xe2b7dd0e, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVAutoContPropertyPage = {0xe2b7dd0f, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMVAutoCont              = {0xe2b7dd10, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVAboutAutoCont        = {0xe2b7dd11, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID LIBID_LMVAutoContLib          = {0xe2b7dd12, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
#endif 

EXTERN_C const IID LIBID_LMVAutoContLib;

#ifndef __ILMVAutoCont_INTERFACE_DEFINED__
#define __ILMVAutoCont_INTERFACE_DEFINED__

/* interface ILMVAutoCont */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ILMVAutoCont;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DD10-38C5-11D5-91F6-00104BDB8FF9")
    ILMVAutoCont : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EnableAutoCont( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_EnableAutoCont( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMVAutoContVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMVAutoCont * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMVAutoCont * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMVAutoCont * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMVAutoCont * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMVAutoCont * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMVAutoCont * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMVAutoCont * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableAutoCont )( 
            ILMVAutoCont * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableAutoCont )( 
            ILMVAutoCont * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        END_INTERFACE
    } ILMVAutoContVtbl;

    interface ILMVAutoCont
    {
        CONST_VTBL struct ILMVAutoContVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMVAutoCont_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMVAutoCont_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMVAutoCont_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMVAutoCont_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMVAutoCont_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMVAutoCont_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMVAutoCont_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMVAutoCont_get_EnableAutoCont(This,pVal)	\
    ( (This)->lpVtbl -> get_EnableAutoCont(This,pVal) ) 

#define ILMVAutoCont_put_EnableAutoCont(This,newVal)	\
    ( (This)->lpVtbl -> put_EnableAutoCont(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMVAutoCont_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LMVAutoCont;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DD0E-38C5-11D5-91F6-00104BDB8FF9")
LMVAutoCont;
#endif
#endif /* __LMVAutoContLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


