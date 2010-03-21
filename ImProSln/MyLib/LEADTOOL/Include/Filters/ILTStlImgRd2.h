

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Nov 05 12:48:13 2009
 */
/* Compiler settings for .\ILTStlImgRd.idl:
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


#ifndef __ILTStlImgRd2_h__
#define __ILTStlImgRd2_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILTStlImgRd_FWD_DEFINED__
#define __ILTStlImgRd_FWD_DEFINED__
typedef interface ILTStlImgRd ILTStlImgRd;
#endif 	/* __ILTStlImgRd_FWD_DEFINED__ */


#ifndef __LTStlImgRd_FWD_DEFINED__
#define __LTStlImgRd_FWD_DEFINED__

#ifdef __cplusplus
typedef class LTStlImgRd LTStlImgRd;
#else
typedef struct LTStlImgRd LTStlImgRd;
#endif /* __cplusplus */

#endif 	/* __LTStlImgRd_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LTStlImgRdLib_LIBRARY_DEFINED__
#define __LTStlImgRdLib_LIBRARY_DEFINED__

/* library LTStlImgRdLib */
/* [helpstring][version][uuid] */ 

#ifndef __IStlImg_H__
#define __IStlImg_H__
static const GUID LIBID_LTStlImgRdLib            = {0xe2b7dd8a, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LTStlImgRd               = {0xe2b7dd8b, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILTStlImgRd                = {0xe2b7dd8c, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LTStlImgRdPropertyPage   = {0xe2b7dd8d, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_AboutPropertyPage        = {0xe2b7dd8e, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
#endif 

EXTERN_C const IID LIBID_LTStlImgRdLib;

#ifndef __ILTStlImgRd_INTERFACE_DEFINED__
#define __ILTStlImgRd_INTERFACE_DEFINED__

/* interface ILTStlImgRd */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILTStlImgRd;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DD8C-38C5-11D5-91F6-00104BDB8FF9")
    ILTStlImgRd : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_InputFileName( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_InputFileName( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ConnectionState( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FrameRate( 
            /* [retval][out] */ float *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FrameRate( 
            /* [in] */ float newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FrameRateControl( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FrameRateControl( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PageNumber( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PageNumber( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TotalPages( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AudioExtension( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SaveSettingsToRegistry( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SaveSettingsToRegistry( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RegisterExtensions( 
            /* [in] */ BSTR strExtensions) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UnRegisterExtensions( 
            /* [in] */ BSTR strExtensions) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RegisteredExtensions( 
            /* [retval][out] */ BSTR *pExtensions) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Format( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LastErrorCode( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LastErrorString( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Loop( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Loop( 
            /* [in] */ long newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILTStlImgRdVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILTStlImgRd * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILTStlImgRd * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILTStlImgRd * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILTStlImgRd * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILTStlImgRd * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILTStlImgRd * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILTStlImgRd * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InputFileName )( 
            ILTStlImgRd * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_InputFileName )( 
            ILTStlImgRd * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ConnectionState )( 
            ILTStlImgRd * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FrameRate )( 
            ILTStlImgRd * This,
            /* [retval][out] */ float *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FrameRate )( 
            ILTStlImgRd * This,
            /* [in] */ float newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FrameRateControl )( 
            ILTStlImgRd * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FrameRateControl )( 
            ILTStlImgRd * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PageNumber )( 
            ILTStlImgRd * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PageNumber )( 
            ILTStlImgRd * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TotalPages )( 
            ILTStlImgRd * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AudioExtension )( 
            ILTStlImgRd * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SaveSettingsToRegistry )( 
            ILTStlImgRd * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SaveSettingsToRegistry )( 
            ILTStlImgRd * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RegisterExtensions )( 
            ILTStlImgRd * This,
            /* [in] */ BSTR strExtensions);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UnRegisterExtensions )( 
            ILTStlImgRd * This,
            /* [in] */ BSTR strExtensions);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RegisteredExtensions )( 
            ILTStlImgRd * This,
            /* [retval][out] */ BSTR *pExtensions);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Format )( 
            ILTStlImgRd * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LastErrorCode )( 
            ILTStlImgRd * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LastErrorString )( 
            ILTStlImgRd * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Loop )( 
            ILTStlImgRd * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Loop )( 
            ILTStlImgRd * This,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } ILTStlImgRdVtbl;

    interface ILTStlImgRd
    {
        CONST_VTBL struct ILTStlImgRdVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILTStlImgRd_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILTStlImgRd_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILTStlImgRd_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILTStlImgRd_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILTStlImgRd_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILTStlImgRd_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILTStlImgRd_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILTStlImgRd_get_InputFileName(This,pVal)	\
    ( (This)->lpVtbl -> get_InputFileName(This,pVal) ) 

#define ILTStlImgRd_put_InputFileName(This,newVal)	\
    ( (This)->lpVtbl -> put_InputFileName(This,newVal) ) 

#define ILTStlImgRd_get_ConnectionState(This,pVal)	\
    ( (This)->lpVtbl -> get_ConnectionState(This,pVal) ) 

#define ILTStlImgRd_get_FrameRate(This,pVal)	\
    ( (This)->lpVtbl -> get_FrameRate(This,pVal) ) 

#define ILTStlImgRd_put_FrameRate(This,newVal)	\
    ( (This)->lpVtbl -> put_FrameRate(This,newVal) ) 

#define ILTStlImgRd_get_FrameRateControl(This,pVal)	\
    ( (This)->lpVtbl -> get_FrameRateControl(This,pVal) ) 

#define ILTStlImgRd_put_FrameRateControl(This,newVal)	\
    ( (This)->lpVtbl -> put_FrameRateControl(This,newVal) ) 

#define ILTStlImgRd_get_PageNumber(This,pVal)	\
    ( (This)->lpVtbl -> get_PageNumber(This,pVal) ) 

#define ILTStlImgRd_put_PageNumber(This,newVal)	\
    ( (This)->lpVtbl -> put_PageNumber(This,newVal) ) 

#define ILTStlImgRd_get_TotalPages(This,pVal)	\
    ( (This)->lpVtbl -> get_TotalPages(This,pVal) ) 

#define ILTStlImgRd_get_AudioExtension(This,pVal)	\
    ( (This)->lpVtbl -> get_AudioExtension(This,pVal) ) 

#define ILTStlImgRd_get_SaveSettingsToRegistry(This,pVal)	\
    ( (This)->lpVtbl -> get_SaveSettingsToRegistry(This,pVal) ) 

#define ILTStlImgRd_put_SaveSettingsToRegistry(This,newVal)	\
    ( (This)->lpVtbl -> put_SaveSettingsToRegistry(This,newVal) ) 

#define ILTStlImgRd_RegisterExtensions(This,strExtensions)	\
    ( (This)->lpVtbl -> RegisterExtensions(This,strExtensions) ) 

#define ILTStlImgRd_UnRegisterExtensions(This,strExtensions)	\
    ( (This)->lpVtbl -> UnRegisterExtensions(This,strExtensions) ) 

#define ILTStlImgRd_get_RegisteredExtensions(This,pExtensions)	\
    ( (This)->lpVtbl -> get_RegisteredExtensions(This,pExtensions) ) 

#define ILTStlImgRd_get_Format(This,pVal)	\
    ( (This)->lpVtbl -> get_Format(This,pVal) ) 

#define ILTStlImgRd_get_LastErrorCode(This,pVal)	\
    ( (This)->lpVtbl -> get_LastErrorCode(This,pVal) ) 

#define ILTStlImgRd_get_LastErrorString(This,pVal)	\
    ( (This)->lpVtbl -> get_LastErrorString(This,pVal) ) 

#define ILTStlImgRd_get_Loop(This,pVal)	\
    ( (This)->lpVtbl -> get_Loop(This,pVal) ) 

#define ILTStlImgRd_put_Loop(This,newVal)	\
    ( (This)->lpVtbl -> put_Loop(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILTStlImgRd_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LTStlImgRd;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DD8B-38C5-11D5-91F6-00104BDB8FF9")
LTStlImgRd;
#endif
#endif /* __LTStlImgRdLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


