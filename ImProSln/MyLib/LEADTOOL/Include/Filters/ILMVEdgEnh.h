

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Nov 05 12:38:32 2009
 */
/* Compiler settings for .\IEdgEnh.idl:
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


#ifndef __ILMVEdgEnh_h__
#define __ILMVEdgEnh_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILMVEdgEnh_FWD_DEFINED__
#define __ILMVEdgEnh_FWD_DEFINED__
typedef interface ILMVEdgEnh ILMVEdgEnh;
#endif 	/* __ILMVEdgEnh_FWD_DEFINED__ */


#ifndef __LMVEdgEnh_FWD_DEFINED__
#define __LMVEdgEnh_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMVEdgEnh LMVEdgEnh;
#else
typedef struct LMVEdgEnh LMVEdgEnh;
#endif /* __cplusplus */

#endif 	/* __LMVEdgEnh_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LMVEgHncLib_LIBRARY_DEFINED__
#define __LMVEgHncLib_LIBRARY_DEFINED__

/* library LMVEgHncLib */
/* [helpstring][version][uuid] */ 

#ifndef __IEdgEnh_H__
#define __IEdgEnh_H__
static const GUID CLSID_LMVEdgEnh             = {0xe2b7dbeb, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVEdgEnhPropertyPage = {0xe2b7dbec, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVAboutEdgEnh        = {0xe2b7dbed, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID LIBID_LMVEdgEnhLib          = {0xe2b7dbee, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMVEdgEnh              = {0xe2b7dbef, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
#endif 

EXTERN_C const IID LIBID_LMVEgHncLib;

#ifndef __ILMVEdgEnh_INTERFACE_DEFINED__
#define __ILMVEdgEnh_INTERFACE_DEFINED__

/* interface ILMVEdgEnh */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILMVEdgEnh;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DBEF-38C5-11D5-91F6-00104BDB8FF9")
    ILMVEdgEnh : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsLEADInputPinConnected( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsLEADOutputPinConnected( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_InWidth( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_InHeight( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OutWidth( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OutHeight( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_InBits( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OutBits( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Enabled( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Enabled( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EnableMultiplier( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_EnableMultiplier( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Multiplier( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Multiplier( 
            /* [in] */ long newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMVEdgEnhVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMVEdgEnh * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMVEdgEnh * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMVEdgEnh * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMVEdgEnh * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMVEdgEnh * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMVEdgEnh * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMVEdgEnh * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsLEADInputPinConnected )( 
            ILMVEdgEnh * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsLEADOutputPinConnected )( 
            ILMVEdgEnh * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InWidth )( 
            ILMVEdgEnh * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InHeight )( 
            ILMVEdgEnh * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutWidth )( 
            ILMVEdgEnh * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutHeight )( 
            ILMVEdgEnh * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InBits )( 
            ILMVEdgEnh * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutBits )( 
            ILMVEdgEnh * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Enabled )( 
            ILMVEdgEnh * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Enabled )( 
            ILMVEdgEnh * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableMultiplier )( 
            ILMVEdgEnh * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableMultiplier )( 
            ILMVEdgEnh * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Multiplier )( 
            ILMVEdgEnh * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Multiplier )( 
            ILMVEdgEnh * This,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } ILMVEdgEnhVtbl;

    interface ILMVEdgEnh
    {
        CONST_VTBL struct ILMVEdgEnhVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMVEdgEnh_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMVEdgEnh_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMVEdgEnh_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMVEdgEnh_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMVEdgEnh_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMVEdgEnh_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMVEdgEnh_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMVEdgEnh_get_IsLEADInputPinConnected(This,pVal)	\
    ( (This)->lpVtbl -> get_IsLEADInputPinConnected(This,pVal) ) 

#define ILMVEdgEnh_get_IsLEADOutputPinConnected(This,pVal)	\
    ( (This)->lpVtbl -> get_IsLEADOutputPinConnected(This,pVal) ) 

#define ILMVEdgEnh_get_InWidth(This,pVal)	\
    ( (This)->lpVtbl -> get_InWidth(This,pVal) ) 

#define ILMVEdgEnh_get_InHeight(This,pVal)	\
    ( (This)->lpVtbl -> get_InHeight(This,pVal) ) 

#define ILMVEdgEnh_get_OutWidth(This,pVal)	\
    ( (This)->lpVtbl -> get_OutWidth(This,pVal) ) 

#define ILMVEdgEnh_get_OutHeight(This,pVal)	\
    ( (This)->lpVtbl -> get_OutHeight(This,pVal) ) 

#define ILMVEdgEnh_get_InBits(This,pVal)	\
    ( (This)->lpVtbl -> get_InBits(This,pVal) ) 

#define ILMVEdgEnh_get_OutBits(This,pVal)	\
    ( (This)->lpVtbl -> get_OutBits(This,pVal) ) 

#define ILMVEdgEnh_get_Enabled(This,pVal)	\
    ( (This)->lpVtbl -> get_Enabled(This,pVal) ) 

#define ILMVEdgEnh_put_Enabled(This,newVal)	\
    ( (This)->lpVtbl -> put_Enabled(This,newVal) ) 

#define ILMVEdgEnh_get_EnableMultiplier(This,pVal)	\
    ( (This)->lpVtbl -> get_EnableMultiplier(This,pVal) ) 

#define ILMVEdgEnh_put_EnableMultiplier(This,newVal)	\
    ( (This)->lpVtbl -> put_EnableMultiplier(This,newVal) ) 

#define ILMVEdgEnh_get_Multiplier(This,pVal)	\
    ( (This)->lpVtbl -> get_Multiplier(This,pVal) ) 

#define ILMVEdgEnh_put_Multiplier(This,newVal)	\
    ( (This)->lpVtbl -> put_Multiplier(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMVEdgEnh_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LMVEdgEnh;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DBEB-38C5-11D5-91F6-00104BDB8FF9")
LMVEdgEnh;
#endif
#endif /* __LMVEgHncLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


