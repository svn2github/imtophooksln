

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Dec 10 09:23:26 2009
 */
/* Compiler settings for .\IFramCtrl.idl:
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


#ifndef __ILMVFramCtrl2_h__
#define __ILMVFramCtrl2_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILMVFrameRateCtrl_FWD_DEFINED__
#define __ILMVFrameRateCtrl_FWD_DEFINED__
typedef interface ILMVFrameRateCtrl ILMVFrameRateCtrl;
#endif 	/* __ILMVFrameRateCtrl_FWD_DEFINED__ */


#ifndef __LMVFramCtrl_FWD_DEFINED__
#define __LMVFramCtrl_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMVFramCtrl LMVFramCtrl;
#else
typedef struct LMVFramCtrl LMVFramCtrl;
#endif /* __cplusplus */

#endif 	/* __LMVFramCtrl_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LMVFrameRateCtrlLib_LIBRARY_DEFINED__
#define __LMVFrameRateCtrlLib_LIBRARY_DEFINED__

/* library LMVFrameRateCtrlLib */
/* [helpstring][version][uuid] */ 

#ifndef __IFRAMCTRL2_H__
#define __IFRAMCTRL2_H__
static const GUID CLSID_LMVFrameRateCtrl             = {0xe2b7dd97, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVFrameRateCtrlPropertyPage = {0xe2b7dd98, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVAboutFrameRateCtrl        = {0xe2b7dd99, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID LIBID_LMVFrameRateCtrlLib          = {0xe2b7dd9a, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMVFrameRateCtrl              = {0xe2b7dd9b, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
#endif 
#define MAX_BUFFERS 10

EXTERN_C const IID LIBID_LMVFrameRateCtrlLib;

#ifndef __ILMVFrameRateCtrl_INTERFACE_DEFINED__
#define __ILMVFrameRateCtrl_INTERFACE_DEFINED__

/* interface ILMVFrameRateCtrl */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILMVFrameRateCtrl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DD9B-38C5-11D5-91F6-00104BDB8FF9")
    ILMVFrameRateCtrl : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Enable( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Enable( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FrameRate( 
            /* [retval][out] */ double *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FrameRate( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_InputFrameRate( 
            /* [retval][out] */ double *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ChangeStreamLength( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ChangeStreamLength( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ResetToDefaults( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMVFrameRateCtrlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMVFrameRateCtrl * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMVFrameRateCtrl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMVFrameRateCtrl * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMVFrameRateCtrl * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMVFrameRateCtrl * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMVFrameRateCtrl * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMVFrameRateCtrl * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Enable )( 
            ILMVFrameRateCtrl * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Enable )( 
            ILMVFrameRateCtrl * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FrameRate )( 
            ILMVFrameRateCtrl * This,
            /* [retval][out] */ double *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FrameRate )( 
            ILMVFrameRateCtrl * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InputFrameRate )( 
            ILMVFrameRateCtrl * This,
            /* [retval][out] */ double *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ChangeStreamLength )( 
            ILMVFrameRateCtrl * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ChangeStreamLength )( 
            ILMVFrameRateCtrl * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetToDefaults )( 
            ILMVFrameRateCtrl * This);
        
        END_INTERFACE
    } ILMVFrameRateCtrlVtbl;

    interface ILMVFrameRateCtrl
    {
        CONST_VTBL struct ILMVFrameRateCtrlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMVFrameRateCtrl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMVFrameRateCtrl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMVFrameRateCtrl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMVFrameRateCtrl_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMVFrameRateCtrl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMVFrameRateCtrl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMVFrameRateCtrl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMVFrameRateCtrl_get_Enable(This,pVal)	\
    ( (This)->lpVtbl -> get_Enable(This,pVal) ) 

#define ILMVFrameRateCtrl_put_Enable(This,newVal)	\
    ( (This)->lpVtbl -> put_Enable(This,newVal) ) 

#define ILMVFrameRateCtrl_get_FrameRate(This,pVal)	\
    ( (This)->lpVtbl -> get_FrameRate(This,pVal) ) 

#define ILMVFrameRateCtrl_put_FrameRate(This,newVal)	\
    ( (This)->lpVtbl -> put_FrameRate(This,newVal) ) 

#define ILMVFrameRateCtrl_get_InputFrameRate(This,pVal)	\
    ( (This)->lpVtbl -> get_InputFrameRate(This,pVal) ) 

#define ILMVFrameRateCtrl_get_ChangeStreamLength(This,pVal)	\
    ( (This)->lpVtbl -> get_ChangeStreamLength(This,pVal) ) 

#define ILMVFrameRateCtrl_put_ChangeStreamLength(This,newVal)	\
    ( (This)->lpVtbl -> put_ChangeStreamLength(This,newVal) ) 

#define ILMVFrameRateCtrl_ResetToDefaults(This)	\
    ( (This)->lpVtbl -> ResetToDefaults(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMVFrameRateCtrl_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LMVFramCtrl;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DD97-38C5-11D5-91F6-00104BDB8FF9")
LMVFramCtrl;
#endif
#endif /* __LMVFrameRateCtrlLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


