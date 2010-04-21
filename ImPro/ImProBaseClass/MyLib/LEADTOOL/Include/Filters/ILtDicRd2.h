

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Nov 05 12:47:41 2009
 */
/* Compiler settings for .\ILtDicRd.idl:
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


#ifndef __ILtDicRd2_h__
#define __ILtDicRd2_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILTDicRd1_FWD_DEFINED__
#define __ILTDicRd1_FWD_DEFINED__
typedef interface ILTDicRd1 ILTDicRd1;
#endif 	/* __ILTDicRd1_FWD_DEFINED__ */


#ifndef __ILTDicRd_FWD_DEFINED__
#define __ILTDicRd_FWD_DEFINED__
typedef interface ILTDicRd ILTDicRd;
#endif 	/* __ILTDicRd_FWD_DEFINED__ */


#ifndef __LTDicRd_FWD_DEFINED__
#define __LTDicRd_FWD_DEFINED__

#ifdef __cplusplus
typedef class LTDicRd LTDicRd;
#else
typedef struct LTDicRd LTDicRd;
#endif /* __cplusplus */

#endif 	/* __LTDicRd_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LTDicRdLib_LIBRARY_DEFINED__
#define __LTDicRdLib_LIBRARY_DEFINED__

/* library LTDicRdLib */
/* [helpstring][version][uuid] */ 

#ifndef __LtDicRd_H__
#define __LtDicRd_H__
static const GUID LIBID_LTDicRdLib         =  {0xe2b7ddb7, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LTDicRd            =  {0xe2b7ddb8, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LTDicRdPropertyPage=  {0xe2b7ddb9, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_AboutPropertyPage  =  {0xe2b7ddba, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILTDicRd1            =  {0xe2b7ddbb, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILTDicRd             =  {0xE2B7DE35, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
#endif 

EXTERN_C const IID LIBID_LTDicRdLib;

#ifndef __ILTDicRd1_INTERFACE_DEFINED__
#define __ILTDicRd1_INTERFACE_DEFINED__

/* interface ILTDicRd1 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILTDicRd1;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DDBB-38C5-11D5-91F6-00104BDB8FF9")
    ILTDicRd1 : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_InputFileName( 
            /* [retval][out] */ BSTR *ppFileName) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_InputFileName( 
            /* [in] */ LPCOLESTR pFileName) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ConnectionState( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DicomDSv14( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FrameTime( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FrameTime( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FrameControl( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FrameControl( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FrameDropping( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FrameDropping( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDicomDSv14( 
            /* [in] */ long newVal,
            /* [in] */ int bCopy) = 0;
        
        virtual /* [helpstring][hidden][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsMPEG2Stream( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ResetToDefaults( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILTDicRd1Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILTDicRd1 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILTDicRd1 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILTDicRd1 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILTDicRd1 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILTDicRd1 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILTDicRd1 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILTDicRd1 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InputFileName )( 
            ILTDicRd1 * This,
            /* [retval][out] */ BSTR *ppFileName);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_InputFileName )( 
            ILTDicRd1 * This,
            /* [in] */ LPCOLESTR pFileName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ConnectionState )( 
            ILTDicRd1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DicomDSv14 )( 
            ILTDicRd1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FrameTime )( 
            ILTDicRd1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FrameTime )( 
            ILTDicRd1 * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FrameControl )( 
            ILTDicRd1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FrameControl )( 
            ILTDicRd1 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FrameDropping )( 
            ILTDicRd1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FrameDropping )( 
            ILTDicRd1 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetDicomDSv14 )( 
            ILTDicRd1 * This,
            /* [in] */ long newVal,
            /* [in] */ int bCopy);
        
        /* [helpstring][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsMPEG2Stream )( 
            ILTDicRd1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetToDefaults )( 
            ILTDicRd1 * This);
        
        END_INTERFACE
    } ILTDicRd1Vtbl;

    interface ILTDicRd1
    {
        CONST_VTBL struct ILTDicRd1Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILTDicRd1_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILTDicRd1_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILTDicRd1_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILTDicRd1_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILTDicRd1_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILTDicRd1_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILTDicRd1_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILTDicRd1_get_InputFileName(This,ppFileName)	\
    ( (This)->lpVtbl -> get_InputFileName(This,ppFileName) ) 

#define ILTDicRd1_put_InputFileName(This,pFileName)	\
    ( (This)->lpVtbl -> put_InputFileName(This,pFileName) ) 

#define ILTDicRd1_get_ConnectionState(This,pVal)	\
    ( (This)->lpVtbl -> get_ConnectionState(This,pVal) ) 

#define ILTDicRd1_get_DicomDSv14(This,pVal)	\
    ( (This)->lpVtbl -> get_DicomDSv14(This,pVal) ) 

#define ILTDicRd1_get_FrameTime(This,pVal)	\
    ( (This)->lpVtbl -> get_FrameTime(This,pVal) ) 

#define ILTDicRd1_put_FrameTime(This,newVal)	\
    ( (This)->lpVtbl -> put_FrameTime(This,newVal) ) 

#define ILTDicRd1_get_FrameControl(This,pVal)	\
    ( (This)->lpVtbl -> get_FrameControl(This,pVal) ) 

#define ILTDicRd1_put_FrameControl(This,newVal)	\
    ( (This)->lpVtbl -> put_FrameControl(This,newVal) ) 

#define ILTDicRd1_get_FrameDropping(This,pVal)	\
    ( (This)->lpVtbl -> get_FrameDropping(This,pVal) ) 

#define ILTDicRd1_put_FrameDropping(This,newVal)	\
    ( (This)->lpVtbl -> put_FrameDropping(This,newVal) ) 

#define ILTDicRd1_SetDicomDSv14(This,newVal,bCopy)	\
    ( (This)->lpVtbl -> SetDicomDSv14(This,newVal,bCopy) ) 

#define ILTDicRd1_get_IsMPEG2Stream(This,pVal)	\
    ( (This)->lpVtbl -> get_IsMPEG2Stream(This,pVal) ) 

#define ILTDicRd1_ResetToDefaults(This)	\
    ( (This)->lpVtbl -> ResetToDefaults(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILTDicRd1_INTERFACE_DEFINED__ */


#ifndef __ILTDicRd_INTERFACE_DEFINED__
#define __ILTDicRd_INTERFACE_DEFINED__

/* interface ILTDicRd */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILTDicRd;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DE35-38C5-11D5-91F6-00104BDB8FF9")
    ILTDicRd : public ILTDicRd1
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DicomDS( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDicomDS( 
            /* [in] */ long newVal,
            /* [in] */ int bCopy) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILTDicRdVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILTDicRd * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILTDicRd * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILTDicRd * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILTDicRd * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILTDicRd * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILTDicRd * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILTDicRd * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InputFileName )( 
            ILTDicRd * This,
            /* [retval][out] */ BSTR *ppFileName);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_InputFileName )( 
            ILTDicRd * This,
            /* [in] */ LPCOLESTR pFileName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ConnectionState )( 
            ILTDicRd * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DicomDSv14 )( 
            ILTDicRd * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FrameTime )( 
            ILTDicRd * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FrameTime )( 
            ILTDicRd * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FrameControl )( 
            ILTDicRd * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FrameControl )( 
            ILTDicRd * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FrameDropping )( 
            ILTDicRd * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FrameDropping )( 
            ILTDicRd * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetDicomDSv14 )( 
            ILTDicRd * This,
            /* [in] */ long newVal,
            /* [in] */ int bCopy);
        
        /* [helpstring][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsMPEG2Stream )( 
            ILTDicRd * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetToDefaults )( 
            ILTDicRd * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DicomDS )( 
            ILTDicRd * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetDicomDS )( 
            ILTDicRd * This,
            /* [in] */ long newVal,
            /* [in] */ int bCopy);
        
        END_INTERFACE
    } ILTDicRdVtbl;

    interface ILTDicRd
    {
        CONST_VTBL struct ILTDicRdVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILTDicRd_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILTDicRd_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILTDicRd_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILTDicRd_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILTDicRd_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILTDicRd_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILTDicRd_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILTDicRd_get_InputFileName(This,ppFileName)	\
    ( (This)->lpVtbl -> get_InputFileName(This,ppFileName) ) 

#define ILTDicRd_put_InputFileName(This,pFileName)	\
    ( (This)->lpVtbl -> put_InputFileName(This,pFileName) ) 

#define ILTDicRd_get_ConnectionState(This,pVal)	\
    ( (This)->lpVtbl -> get_ConnectionState(This,pVal) ) 

#define ILTDicRd_get_DicomDSv14(This,pVal)	\
    ( (This)->lpVtbl -> get_DicomDSv14(This,pVal) ) 

#define ILTDicRd_get_FrameTime(This,pVal)	\
    ( (This)->lpVtbl -> get_FrameTime(This,pVal) ) 

#define ILTDicRd_put_FrameTime(This,newVal)	\
    ( (This)->lpVtbl -> put_FrameTime(This,newVal) ) 

#define ILTDicRd_get_FrameControl(This,pVal)	\
    ( (This)->lpVtbl -> get_FrameControl(This,pVal) ) 

#define ILTDicRd_put_FrameControl(This,newVal)	\
    ( (This)->lpVtbl -> put_FrameControl(This,newVal) ) 

#define ILTDicRd_get_FrameDropping(This,pVal)	\
    ( (This)->lpVtbl -> get_FrameDropping(This,pVal) ) 

#define ILTDicRd_put_FrameDropping(This,newVal)	\
    ( (This)->lpVtbl -> put_FrameDropping(This,newVal) ) 

#define ILTDicRd_SetDicomDSv14(This,newVal,bCopy)	\
    ( (This)->lpVtbl -> SetDicomDSv14(This,newVal,bCopy) ) 

#define ILTDicRd_get_IsMPEG2Stream(This,pVal)	\
    ( (This)->lpVtbl -> get_IsMPEG2Stream(This,pVal) ) 

#define ILTDicRd_ResetToDefaults(This)	\
    ( (This)->lpVtbl -> ResetToDefaults(This) ) 


#define ILTDicRd_get_DicomDS(This,pVal)	\
    ( (This)->lpVtbl -> get_DicomDS(This,pVal) ) 

#define ILTDicRd_SetDicomDS(This,newVal,bCopy)	\
    ( (This)->lpVtbl -> SetDicomDS(This,newVal,bCopy) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILTDicRd_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LTDicRd;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DDB8-38C5-11D5-91F6-00104BDB8FF9")
LTDicRd;
#endif
#endif /* __LTDicRdLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


