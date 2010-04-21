

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Nov 05 12:46:39 2009
 */
/* Compiler settings for .\lmisomux.idl:
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


#ifndef __ILMIsoMux_h__
#define __ILMIsoMux_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILMIsoMux1_FWD_DEFINED__
#define __ILMIsoMux1_FWD_DEFINED__
typedef interface ILMIsoMux1 ILMIsoMux1;
#endif 	/* __ILMIsoMux1_FWD_DEFINED__ */


#ifndef __ILMIsoMux_FWD_DEFINED__
#define __ILMIsoMux_FWD_DEFINED__
typedef interface ILMIsoMux ILMIsoMux;
#endif 	/* __ILMIsoMux_FWD_DEFINED__ */


#ifndef __LMIsoMux_FWD_DEFINED__
#define __LMIsoMux_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMIsoMux LMIsoMux;
#else
typedef struct LMIsoMux LMIsoMux;
#endif /* __cplusplus */

#endif 	/* __LMIsoMux_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LMIsoMuxLib_LIBRARY_DEFINED__
#define __LMIsoMuxLib_LIBRARY_DEFINED__

/* library LMIsoMuxLib */
/* [helpstring][version][uuid] */ 

#ifndef __LMISOMUX_H__
#define __LMISOMUX_H__
static const GUID CLSID_LMIsoMux             = {0x990d1978, 0xe48d, 0x43af, {0xb1, 0x2d, 0x24, 0xa7, 0x45, 0x6e, 0xc8, 0x9f}};
static const GUID LIBID_LMIsoMuxLib          = {0xE2B7DF22, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMIsoMux1             = {0xE2B7DF23, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMIsoMux              = {0XE2B7DF69, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
#endif 
typedef 
enum IsoMux_OutputType
    {	IsoMux_OutputType_Default	= 0,
	IsoMux_OutputType_MP4	= 0x1,
	IsoMux_OutputType_PSP	= 0x2,
	IsoMux_OutputType_iPod	= 0x3,
	IsoMux_OutputType_3GP	= 0x4
    } 	IsoMux_OutputType;


DEFINE_GUID(LIBID_LMIsoMuxLib,0xE2B7DF22,0x38C5,0x11D5,0x91,0xF6,0x00,0x10,0x4B,0xDB,0x8F,0xF9);

#ifndef __ILMIsoMux1_INTERFACE_DEFINED__
#define __ILMIsoMux1_INTERFACE_DEFINED__

/* interface ILMIsoMux1 */
/* [unique][helpstring][dual][uuid][object] */ 


DEFINE_GUID(IID_ILMIsoMux1,0xE2B7DF23,0x38C5,0x11D5,0x91,0xF6,0x00,0x10,0x4B,0xDB,0x8F,0xF9);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DF23-38C5-11D5-91F6-00104BDB8FF9")
    ILMIsoMux1 : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Title( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Title( 
            /* [in] */ BSTR newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMIsoMux1Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMIsoMux1 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMIsoMux1 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMIsoMux1 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMIsoMux1 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMIsoMux1 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMIsoMux1 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMIsoMux1 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Title )( 
            ILMIsoMux1 * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Title )( 
            ILMIsoMux1 * This,
            /* [in] */ BSTR newVal);
        
        END_INTERFACE
    } ILMIsoMux1Vtbl;

    interface ILMIsoMux1
    {
        CONST_VTBL struct ILMIsoMux1Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMIsoMux1_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMIsoMux1_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMIsoMux1_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMIsoMux1_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMIsoMux1_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMIsoMux1_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMIsoMux1_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMIsoMux1_get_Title(This,pVal)	\
    ( (This)->lpVtbl -> get_Title(This,pVal) ) 

#define ILMIsoMux1_put_Title(This,newVal)	\
    ( (This)->lpVtbl -> put_Title(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMIsoMux1_INTERFACE_DEFINED__ */


#ifndef __ILMIsoMux_INTERFACE_DEFINED__
#define __ILMIsoMux_INTERFACE_DEFINED__

/* interface ILMIsoMux */
/* [unique][helpstring][dual][uuid][object] */ 


DEFINE_GUID(IID_ILMIsoMux,0xE2B7DF69,0x38C5,0x11D5,0x91,0xF6,0x00,0x10,0x4B,0xDB,0x8F,0xF9);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DF69-38C5-11D5-91F6-00104BDB8FF9")
    ILMIsoMux : public ILMIsoMux1
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OutputType( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OutputType( 
            /* [in] */ long newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMIsoMuxVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMIsoMux * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMIsoMux * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMIsoMux * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMIsoMux * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMIsoMux * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMIsoMux * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMIsoMux * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Title )( 
            ILMIsoMux * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Title )( 
            ILMIsoMux * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutputType )( 
            ILMIsoMux * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OutputType )( 
            ILMIsoMux * This,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } ILMIsoMuxVtbl;

    interface ILMIsoMux
    {
        CONST_VTBL struct ILMIsoMuxVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMIsoMux_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMIsoMux_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMIsoMux_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMIsoMux_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMIsoMux_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMIsoMux_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMIsoMux_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMIsoMux_get_Title(This,pVal)	\
    ( (This)->lpVtbl -> get_Title(This,pVal) ) 

#define ILMIsoMux_put_Title(This,newVal)	\
    ( (This)->lpVtbl -> put_Title(This,newVal) ) 


#define ILMIsoMux_get_OutputType(This,pVal)	\
    ( (This)->lpVtbl -> get_OutputType(This,pVal) ) 

#define ILMIsoMux_put_OutputType(This,newVal)	\
    ( (This)->lpVtbl -> put_OutputType(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMIsoMux_INTERFACE_DEFINED__ */


DEFINE_GUID(CLSID_LMIsoMux,0x990D1978,0xE48D,0x43af,0xB1,0x2D,0x24,0xA7,0x45,0x6E,0xC8,0x9F);

#ifdef __cplusplus

class DECLSPEC_UUID("990D1978-E48D-43af-B12D-24A7456EC89F")
LMIsoMux;
#endif
#endif /* __LMIsoMuxLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


