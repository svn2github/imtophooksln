

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Nov 05 12:55:04 2009
 */
/* Compiler settings for .\lmnetsrc.idl:
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


#ifndef __ILMNetSrc2_h__
#define __ILMNetSrc2_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILMNetSrc_FWD_DEFINED__
#define __ILMNetSrc_FWD_DEFINED__
typedef interface ILMNetSrc ILMNetSrc;
#endif 	/* __ILMNetSrc_FWD_DEFINED__ */


#ifndef __LMNetSrc_FWD_DEFINED__
#define __LMNetSrc_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMNetSrc LMNetSrc;
#else
typedef struct LMNetSrc LMNetSrc;
#endif /* __cplusplus */

#endif 	/* __LMNetSrc_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LMNetSrcLib_LIBRARY_DEFINED__
#define __LMNetSrcLib_LIBRARY_DEFINED__

/* library LMNetSrcLib */
/* [helpstring][version][uuid] */ 

#ifndef __LMNetSrc_H__
#define __LMNetSrc_H__
static const GUID CLSID_LMNetSrc             = {0xe2b7de03, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID LIBID_LMNetSrcLib          = {0xe2b7df27, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMNetSrc              = {0xe2b7df28, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
#endif 
typedef 
enum NetSrc_CC_Flag
    {	NetSrc_CC_ForceConnection	= 0x1
    } 	NetSrc_CC_Flag;


DEFINE_GUID(LIBID_LMNetSrcLib,0xE2B7DF27,0x38C5,0x11D5,0x91,0xF6,0x00,0x10,0x4B,0xDB,0x8F,0xF9);

#ifndef __ILMNetSrc_INTERFACE_DEFINED__
#define __ILMNetSrc_INTERFACE_DEFINED__

/* interface ILMNetSrc */
/* [unique][helpstring][dual][uuid][object] */ 


DEFINE_GUID(IID_ILMNetSrc,0xE2B7DF28,0x38C5,0x11D5,0x91,0xF6,0x00,0x10,0x4B,0xDB,0x8F,0xF9);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DF28-38C5-11D5-91F6-00104BDB8FF9")
    ILMNetSrc : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CheckConnection( 
            /* [in] */ BSTR url,
            /* [in] */ long flags,
            /* [in] */ long timeout) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMNetSrcVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMNetSrc * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMNetSrc * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMNetSrc * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMNetSrc * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMNetSrc * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMNetSrc * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMNetSrc * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CheckConnection )( 
            ILMNetSrc * This,
            /* [in] */ BSTR url,
            /* [in] */ long flags,
            /* [in] */ long timeout);
        
        END_INTERFACE
    } ILMNetSrcVtbl;

    interface ILMNetSrc
    {
        CONST_VTBL struct ILMNetSrcVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMNetSrc_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMNetSrc_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMNetSrc_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMNetSrc_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMNetSrc_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMNetSrc_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMNetSrc_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMNetSrc_CheckConnection(This,url,flags,timeout)	\
    ( (This)->lpVtbl -> CheckConnection(This,url,flags,timeout) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMNetSrc_INTERFACE_DEFINED__ */


DEFINE_GUID(CLSID_LMNetSrc,0xE2B7DE03,0x38C5,0x11D5,0x91,0xF6,0x00,0x10,0x4B,0xDB,0x8F,0xF9);

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DE03-38C5-11D5-91F6-00104BDB8FF9")
LMNetSrc;
#endif
#endif /* __LMNetSrcLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


