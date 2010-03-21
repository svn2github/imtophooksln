

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Nov 05 12:42:24 2009
 */
/* Compiler settings for .\ILMAudConv.idl:
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


#ifndef __ILMAConverter_h__
#define __ILMAConverter_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILMAConverter_FWD_DEFINED__
#define __ILMAConverter_FWD_DEFINED__
typedef interface ILMAConverter ILMAConverter;
#endif 	/* __ILMAConverter_FWD_DEFINED__ */


#ifndef __LMAConverter_FWD_DEFINED__
#define __LMAConverter_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMAConverter LMAConverter;
#else
typedef struct LMAConverter LMAConverter;
#endif /* __cplusplus */

#endif 	/* __LMAConverter_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LMAConverterLib_LIBRARY_DEFINED__
#define __LMAConverterLib_LIBRARY_DEFINED__

/* library LMAConverterLib */
/* [helpstring][version][uuid] */ 

#ifndef __ILMACONVERTER_H__
#define __ILMACONVERTER_H__
static const GUID CLSID_LMAConverter       = {0xE2B7DF3B, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMAAboutConverter  = {0xE2B7DF3C, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMAConverter        = {0xE2B7DF3D, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID LIBID_LMAConverterLib    = {0xE2B7DF3A, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMAConverterPropPage = {0xE2B7DF3E, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
#endif 

EXTERN_C const IID LIBID_LMAConverterLib;

#ifndef __ILMAConverter_INTERFACE_DEFINED__
#define __ILMAConverter_INTERFACE_DEFINED__

/* interface ILMAConverter */
/* [unique][helpstring][uuid][dual][local][object] */ 


EXTERN_C const IID IID_ILMAConverter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DF3D-38C5-11D5-91F6-00104BDB8FF9")
    ILMAConverter : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OutputSampleRate( 
            /* [in] */ long rate) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OutputSampleRate( 
            /* [retval][out] */ long *pRate) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMAConverterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMAConverter * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMAConverter * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMAConverter * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMAConverter * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMAConverter * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMAConverter * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMAConverter * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OutputSampleRate )( 
            ILMAConverter * This,
            /* [in] */ long rate);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutputSampleRate )( 
            ILMAConverter * This,
            /* [retval][out] */ long *pRate);
        
        END_INTERFACE
    } ILMAConverterVtbl;

    interface ILMAConverter
    {
        CONST_VTBL struct ILMAConverterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMAConverter_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMAConverter_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMAConverter_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMAConverter_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMAConverter_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMAConverter_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMAConverter_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMAConverter_put_OutputSampleRate(This,rate)	\
    ( (This)->lpVtbl -> put_OutputSampleRate(This,rate) ) 

#define ILMAConverter_get_OutputSampleRate(This,pRate)	\
    ( (This)->lpVtbl -> get_OutputSampleRate(This,pRate) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMAConverter_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LMAConverter;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DF3B-38C5-11D5-91F6-00104BDB8FF9")
LMAConverter;
#endif
#endif /* __LMAConverterLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


