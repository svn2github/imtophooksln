

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Nov 05 12:39:14 2009
 */
/* Compiler settings for .\IHistoG.idl:
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


#ifndef __ILMVHstg2_h__
#define __ILMVHstg2_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILMVHistogramEq_FWD_DEFINED__
#define __ILMVHistogramEq_FWD_DEFINED__
typedef interface ILMVHistogramEq ILMVHistogramEq;
#endif 	/* __ILMVHistogramEq_FWD_DEFINED__ */


#ifndef __LMVHistoEq_FWD_DEFINED__
#define __LMVHistoEq_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMVHistoEq LMVHistoEq;
#else
typedef struct LMVHistoEq LMVHistoEq;
#endif /* __cplusplus */

#endif 	/* __LMVHistoEq_FWD_DEFINED__ */


#ifndef __ILMVHistogramView_FWD_DEFINED__
#define __ILMVHistogramView_FWD_DEFINED__
typedef interface ILMVHistogramView ILMVHistogramView;
#endif 	/* __ILMVHistogramView_FWD_DEFINED__ */


#ifndef __LMVHistoView_FWD_DEFINED__
#define __LMVHistoView_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMVHistoView LMVHistoView;
#else
typedef struct LMVHistoView LMVHistoView;
#endif /* __cplusplus */

#endif 	/* __LMVHistoView_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LMVHistogramLib_LIBRARY_DEFINED__
#define __LMVHistogramLib_LIBRARY_DEFINED__

/* library LMVHistogramLib */
/* [helpstring][version][uuid] */ 

#ifndef __IHistoG2_H__
#define __IHistoG2_H__
static const GUID LIBID_LMVHistogramLib              = {0xe2b7ddea, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVHistogramEq               = {0xe2b7ddeb, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMVHistogramEq                = {0xe2b7ddec, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVHistogramEqPropertyPage   = {0xe2b7dded, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVAboutHistogramEq          = {0xe2b7ddee, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVHistogramView             = {0xe2b7ddef, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMVHistogramView              = {0xe2b7ddf0, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVHistogramViewPropertyPage = {0xe2b7ddf1, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVAboutHistogramView        = {0xe2b7ddf2, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
#endif 
enum{RGB8 = 1035,RGB24,REDCHANNEL,GREENCHANNEL,BLUECHANNEL,ALLCHANNELS};

EXTERN_C const IID LIBID_LMVHistogramLib;

#ifndef __ILMVHistogramEq_INTERFACE_DEFINED__
#define __ILMVHistogramEq_INTERFACE_DEFINED__

/* interface ILMVHistogramEq */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILMVHistogramEq;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DDEC-38C5-11D5-91F6-00104BDB8FF9")
    ILMVHistogramEq : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EnableEqualize( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_EnableEqualize( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RGBMode( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RGBMode( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HistogramType( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_HistogramType( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultEnableEqualize( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DefaultEnableEqualize( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultRGBMode( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DefaultRGBMode( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultHistogramType( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DefaultHistogramType( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_YUVHistogram( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_YUVHistogram( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_YUVInput( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMVHistogramEqVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMVHistogramEq * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMVHistogramEq * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMVHistogramEq * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMVHistogramEq * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMVHistogramEq * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMVHistogramEq * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMVHistogramEq * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableEqualize )( 
            ILMVHistogramEq * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableEqualize )( 
            ILMVHistogramEq * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RGBMode )( 
            ILMVHistogramEq * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RGBMode )( 
            ILMVHistogramEq * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HistogramType )( 
            ILMVHistogramEq * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_HistogramType )( 
            ILMVHistogramEq * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultEnableEqualize )( 
            ILMVHistogramEq * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultEnableEqualize )( 
            ILMVHistogramEq * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultRGBMode )( 
            ILMVHistogramEq * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultRGBMode )( 
            ILMVHistogramEq * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultHistogramType )( 
            ILMVHistogramEq * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultHistogramType )( 
            ILMVHistogramEq * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_YUVHistogram )( 
            ILMVHistogramEq * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_YUVHistogram )( 
            ILMVHistogramEq * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_YUVInput )( 
            ILMVHistogramEq * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        END_INTERFACE
    } ILMVHistogramEqVtbl;

    interface ILMVHistogramEq
    {
        CONST_VTBL struct ILMVHistogramEqVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMVHistogramEq_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMVHistogramEq_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMVHistogramEq_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMVHistogramEq_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMVHistogramEq_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMVHistogramEq_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMVHistogramEq_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMVHistogramEq_get_EnableEqualize(This,pVal)	\
    ( (This)->lpVtbl -> get_EnableEqualize(This,pVal) ) 

#define ILMVHistogramEq_put_EnableEqualize(This,newVal)	\
    ( (This)->lpVtbl -> put_EnableEqualize(This,newVal) ) 

#define ILMVHistogramEq_get_RGBMode(This,pVal)	\
    ( (This)->lpVtbl -> get_RGBMode(This,pVal) ) 

#define ILMVHistogramEq_put_RGBMode(This,newVal)	\
    ( (This)->lpVtbl -> put_RGBMode(This,newVal) ) 

#define ILMVHistogramEq_get_HistogramType(This,pVal)	\
    ( (This)->lpVtbl -> get_HistogramType(This,pVal) ) 

#define ILMVHistogramEq_put_HistogramType(This,newVal)	\
    ( (This)->lpVtbl -> put_HistogramType(This,newVal) ) 

#define ILMVHistogramEq_get_DefaultEnableEqualize(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultEnableEqualize(This,pVal) ) 

#define ILMVHistogramEq_put_DefaultEnableEqualize(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultEnableEqualize(This,newVal) ) 

#define ILMVHistogramEq_get_DefaultRGBMode(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultRGBMode(This,pVal) ) 

#define ILMVHistogramEq_put_DefaultRGBMode(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultRGBMode(This,newVal) ) 

#define ILMVHistogramEq_get_DefaultHistogramType(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultHistogramType(This,pVal) ) 

#define ILMVHistogramEq_put_DefaultHistogramType(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultHistogramType(This,newVal) ) 

#define ILMVHistogramEq_get_YUVHistogram(This,pVal)	\
    ( (This)->lpVtbl -> get_YUVHistogram(This,pVal) ) 

#define ILMVHistogramEq_put_YUVHistogram(This,newVal)	\
    ( (This)->lpVtbl -> put_YUVHistogram(This,newVal) ) 

#define ILMVHistogramEq_get_YUVInput(This,pVal)	\
    ( (This)->lpVtbl -> get_YUVInput(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMVHistogramEq_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LMVHistoEq;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DDEB-38C5-11D5-91F6-00104BDB8FF9")
LMVHistoEq;
#endif

#ifndef __ILMVHistogramView_INTERFACE_DEFINED__
#define __ILMVHistogramView_INTERFACE_DEFINED__

/* interface ILMVHistogramView */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILMVHistogramView;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DDF0-38C5-11D5-91F6-00104BDB8FF9")
    ILMVHistogramView : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RGBMode( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RGBMode( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HistogramType( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_HistogramType( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultRGBMode( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DefaultRGBMode( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultHistogramType( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DefaultHistogramType( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetHistogramArray( 
            /* [out][in] */ long *HistogramArray,
            long *lFrameCount) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMVHistogramViewVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMVHistogramView * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMVHistogramView * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMVHistogramView * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMVHistogramView * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMVHistogramView * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMVHistogramView * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMVHistogramView * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RGBMode )( 
            ILMVHistogramView * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RGBMode )( 
            ILMVHistogramView * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HistogramType )( 
            ILMVHistogramView * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_HistogramType )( 
            ILMVHistogramView * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultRGBMode )( 
            ILMVHistogramView * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultRGBMode )( 
            ILMVHistogramView * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultHistogramType )( 
            ILMVHistogramView * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultHistogramType )( 
            ILMVHistogramView * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetHistogramArray )( 
            ILMVHistogramView * This,
            /* [out][in] */ long *HistogramArray,
            long *lFrameCount);
        
        END_INTERFACE
    } ILMVHistogramViewVtbl;

    interface ILMVHistogramView
    {
        CONST_VTBL struct ILMVHistogramViewVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMVHistogramView_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMVHistogramView_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMVHistogramView_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMVHistogramView_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMVHistogramView_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMVHistogramView_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMVHistogramView_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMVHistogramView_get_RGBMode(This,pVal)	\
    ( (This)->lpVtbl -> get_RGBMode(This,pVal) ) 

#define ILMVHistogramView_put_RGBMode(This,newVal)	\
    ( (This)->lpVtbl -> put_RGBMode(This,newVal) ) 

#define ILMVHistogramView_get_HistogramType(This,pVal)	\
    ( (This)->lpVtbl -> get_HistogramType(This,pVal) ) 

#define ILMVHistogramView_put_HistogramType(This,newVal)	\
    ( (This)->lpVtbl -> put_HistogramType(This,newVal) ) 

#define ILMVHistogramView_get_DefaultRGBMode(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultRGBMode(This,pVal) ) 

#define ILMVHistogramView_put_DefaultRGBMode(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultRGBMode(This,newVal) ) 

#define ILMVHistogramView_get_DefaultHistogramType(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultHistogramType(This,pVal) ) 

#define ILMVHistogramView_put_DefaultHistogramType(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultHistogramType(This,newVal) ) 

#define ILMVHistogramView_GetHistogramArray(This,HistogramArray,lFrameCount)	\
    ( (This)->lpVtbl -> GetHistogramArray(This,HistogramArray,lFrameCount) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMVHistogramView_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LMVHistoView;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DDEF-38C5-11D5-91F6-00104BDB8FF9")
LMVHistoView;
#endif
#endif /* __LMVHistogramLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


