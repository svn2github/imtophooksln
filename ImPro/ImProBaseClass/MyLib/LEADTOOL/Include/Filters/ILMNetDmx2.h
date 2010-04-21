

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Nov 05 12:54:42 2009
 */
/* Compiler settings for .\LMNetDmx.idl:
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


#ifndef __ILMNetDmx2_h__
#define __ILMNetDmx2_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILMNetDmx_FWD_DEFINED__
#define __ILMNetDmx_FWD_DEFINED__
typedef interface ILMNetDmx ILMNetDmx;
#endif 	/* __ILMNetDmx_FWD_DEFINED__ */


#ifndef __LMNetDmx_FWD_DEFINED__
#define __LMNetDmx_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMNetDmx LMNetDmx;
#else
typedef struct LMNetDmx LMNetDmx;
#endif /* __cplusplus */

#endif 	/* __LMNetDmx_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LMNetDmxLib_LIBRARY_DEFINED__
#define __LMNetDmxLib_LIBRARY_DEFINED__

/* library LMNetDmxLib */
/* [helpstring][helpfile][version][uuid] */ 

#ifndef __LMNetDmx_GUID__
#define __LMNetDmx_GUID__
static const IID LIBID_LMNetDmxLib   = {0xe2b7ddf4, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const CLSID CLSID_LMNetDmx    = {0xe2b7ddf5, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const IID IID_ILMNetDmx       = {0xe2b7ddf6, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
#endif 

DEFINE_GUID(LIBID_LMNetDmxLib,0xE2B7DDF4,0x38C5,0x11D5,0x91,0xF6,0x00,0x10,0x4B,0xDB,0x8F,0xF9);

#ifndef __ILMNetDmx_INTERFACE_DEFINED__
#define __ILMNetDmx_INTERFACE_DEFINED__

/* interface ILMNetDmx */
/* [unique][helpstring][dual][uuid][object] */ 


DEFINE_GUID(IID_ILMNetDmx,0xE2B7DDF6,0x38C5,0x11D5,0x91,0xF6,0x00,0x10,0x4B,0xDB,0x8F,0xF9);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DDF6-38C5-11D5-91F6-00104BDB8FF9")
    ILMNetDmx : public IDispatch
    {
    public:
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_BitRate( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][helpcontext][id] */ HRESULT STDMETHODCALLTYPE ReadMessage( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OutputFileName( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OutputFileName( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ResetToDefaults( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMNetDmxVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMNetDmx * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMNetDmx * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMNetDmx * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMNetDmx * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMNetDmx * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMNetDmx * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMNetDmx * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BitRate )( 
            ILMNetDmx * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][helpcontext][id] */ HRESULT ( STDMETHODCALLTYPE *ReadMessage )( 
            ILMNetDmx * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutputFileName )( 
            ILMNetDmx * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OutputFileName )( 
            ILMNetDmx * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetToDefaults )( 
            ILMNetDmx * This);
        
        END_INTERFACE
    } ILMNetDmxVtbl;

    interface ILMNetDmx
    {
        CONST_VTBL struct ILMNetDmxVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMNetDmx_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMNetDmx_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMNetDmx_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMNetDmx_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMNetDmx_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMNetDmx_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMNetDmx_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMNetDmx_get_BitRate(This,pVal)	\
    ( (This)->lpVtbl -> get_BitRate(This,pVal) ) 

#define ILMNetDmx_ReadMessage(This,pVal)	\
    ( (This)->lpVtbl -> ReadMessage(This,pVal) ) 

#define ILMNetDmx_get_OutputFileName(This,pVal)	\
    ( (This)->lpVtbl -> get_OutputFileName(This,pVal) ) 

#define ILMNetDmx_put_OutputFileName(This,newVal)	\
    ( (This)->lpVtbl -> put_OutputFileName(This,newVal) ) 

#define ILMNetDmx_ResetToDefaults(This)	\
    ( (This)->lpVtbl -> ResetToDefaults(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMNetDmx_INTERFACE_DEFINED__ */


DEFINE_GUID(CLSID_LMNetDmx,0xE2B7DDF5,0x38C5,0x11D5,0x91,0xF6,0x00,0x10,0x4B,0xDB,0x8F,0xF9);

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DDF5-38C5-11D5-91F6-00104BDB8FF9")
LMNetDmx;
#endif
#endif /* __LMNetDmxLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


