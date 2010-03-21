

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Nov 05 12:36:59 2009
 */
/* Compiler settings for .\IAutoLvl.idl:
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


#ifndef __ILMVAutoLvl_h__
#define __ILMVAutoLvl_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILMVAutoLvl_FWD_DEFINED__
#define __ILMVAutoLvl_FWD_DEFINED__
typedef interface ILMVAutoLvl ILMVAutoLvl;
#endif 	/* __ILMVAutoLvl_FWD_DEFINED__ */


#ifndef __LMVAutoLvl_FWD_DEFINED__
#define __LMVAutoLvl_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMVAutoLvl LMVAutoLvl;
#else
typedef struct LMVAutoLvl LMVAutoLvl;
#endif /* __cplusplus */

#endif 	/* __LMVAutoLvl_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LMVAutoLvlLib_LIBRARY_DEFINED__
#define __LMVAutoLvlLib_LIBRARY_DEFINED__

/* library LMVAutoLvlLib */
/* [helpstring][version][uuid] */ 

#ifndef __IAutoLvl_H__
#define __IAutoLvl_H__
static const GUID CLSID_LMVAutoLvl             = {0xe2b7dd09, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVAutoLvlPropertyPage = {0xe2b7dd0a, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMVAutoLvl              = {0xe2b7dd0b, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVAboutAutoLvl        = {0xe2b7dd0c, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID LIBID_LMVAutoLvlLib          = {0xe2b7dd0d, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
#endif 

EXTERN_C const IID LIBID_LMVAutoLvlLib;

#ifndef __ILMVAutoLvl_INTERFACE_DEFINED__
#define __ILMVAutoLvl_INTERFACE_DEFINED__

/* interface ILMVAutoLvl */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ILMVAutoLvl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DD0B-38C5-11D5-91F6-00104BDB8FF9")
    ILMVAutoLvl : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EnableAutoLvl( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_EnableAutoLvl( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMVAutoLvlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMVAutoLvl * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMVAutoLvl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMVAutoLvl * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMVAutoLvl * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMVAutoLvl * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMVAutoLvl * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMVAutoLvl * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableAutoLvl )( 
            ILMVAutoLvl * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableAutoLvl )( 
            ILMVAutoLvl * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        END_INTERFACE
    } ILMVAutoLvlVtbl;

    interface ILMVAutoLvl
    {
        CONST_VTBL struct ILMVAutoLvlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMVAutoLvl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMVAutoLvl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMVAutoLvl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMVAutoLvl_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMVAutoLvl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMVAutoLvl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMVAutoLvl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMVAutoLvl_get_EnableAutoLvl(This,pVal)	\
    ( (This)->lpVtbl -> get_EnableAutoLvl(This,pVal) ) 

#define ILMVAutoLvl_put_EnableAutoLvl(This,newVal)	\
    ( (This)->lpVtbl -> put_EnableAutoLvl(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMVAutoLvl_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LMVAutoLvl;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DD09-38C5-11D5-91F6-00104BDB8FF9")
LMVAutoLvl;
#endif
#endif /* __LMVAutoLvlLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


