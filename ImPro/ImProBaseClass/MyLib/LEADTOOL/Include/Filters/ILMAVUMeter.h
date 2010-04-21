

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Nov 05 12:43:39 2009
 */
/* Compiler settings for .\IVUMeter.idl:
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


#ifndef __ILMAVUMeter_h__
#define __ILMAVUMeter_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILMAVUMeter_FWD_DEFINED__
#define __ILMAVUMeter_FWD_DEFINED__
typedef interface ILMAVUMeter ILMAVUMeter;
#endif 	/* __ILMAVUMeter_FWD_DEFINED__ */


#ifndef __ILMAVUMeterDisp_FWD_DEFINED__
#define __ILMAVUMeterDisp_FWD_DEFINED__
typedef interface ILMAVUMeterDisp ILMAVUMeterDisp;
#endif 	/* __ILMAVUMeterDisp_FWD_DEFINED__ */


#ifndef __LMAVUMeter_FWD_DEFINED__
#define __LMAVUMeter_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMAVUMeter LMAVUMeter;
#else
typedef struct LMAVUMeter LMAVUMeter;
#endif /* __cplusplus */

#endif 	/* __LMAVUMeter_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LMAVUMeterLib_LIBRARY_DEFINED__
#define __LMAVUMeterLib_LIBRARY_DEFINED__

/* library LMAVUMeterLib */
/* [helpstring][version][uuid] */ 

#ifndef __IVUMETER_H__
#define __IVUMETER_H__
static const GUID CLSID_LMAVUMeter = {0xe2b7db5c, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMAVUMeter = {0xe2b7db5d, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMAVUMeterPropertyPage = {0xe2b7db5e, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMAAboutVUMeter = {0xe2b7db5f, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID LIBID_LMAVUMeterLib = {0xe2b7db07, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMAVUMeterDisp = {0xe2b7db08, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
typedef /* [public][public] */ struct __MIDL___MIDL_itf_IVUMeter_0000_0000_0001
    {
    long lLeft;
    long lRight;
    } 	VUMETER_LEVEL;

#endif 

EXTERN_C const IID LIBID_LMAVUMeterLib;

#ifndef __ILMAVUMeter_INTERFACE_DEFINED__
#define __ILMAVUMeter_INTERFACE_DEFINED__

/* interface ILMAVUMeter */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ILMAVUMeter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("e2b7db5d-38c5-11d5-91f6-00104bdb8ff9")
    ILMAVUMeter : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetLevel( 
            /* [out] */ VUMETER_LEVEL *pLevel) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMAVUMeterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMAVUMeter * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMAVUMeter * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMAVUMeter * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetLevel )( 
            ILMAVUMeter * This,
            /* [out] */ VUMETER_LEVEL *pLevel);
        
        END_INTERFACE
    } ILMAVUMeterVtbl;

    interface ILMAVUMeter
    {
        CONST_VTBL struct ILMAVUMeterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMAVUMeter_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMAVUMeter_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMAVUMeter_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMAVUMeter_GetLevel(This,pLevel)	\
    ( (This)->lpVtbl -> GetLevel(This,pLevel) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMAVUMeter_INTERFACE_DEFINED__ */


#ifndef __ILMAVUMeterDisp_INTERFACE_DEFINED__
#define __ILMAVUMeterDisp_INTERFACE_DEFINED__

/* interface ILMAVUMeterDisp */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILMAVUMeterDisp;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("e2b7db08-38c5-11d5-91f6-00104bdb8ff9")
    ILMAVUMeterDisp : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LeftLevel( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RightLevel( 
            /* [retval][out] */ long *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMAVUMeterDispVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMAVUMeterDisp * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMAVUMeterDisp * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMAVUMeterDisp * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMAVUMeterDisp * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMAVUMeterDisp * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMAVUMeterDisp * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMAVUMeterDisp * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LeftLevel )( 
            ILMAVUMeterDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RightLevel )( 
            ILMAVUMeterDisp * This,
            /* [retval][out] */ long *pVal);
        
        END_INTERFACE
    } ILMAVUMeterDispVtbl;

    interface ILMAVUMeterDisp
    {
        CONST_VTBL struct ILMAVUMeterDispVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMAVUMeterDisp_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMAVUMeterDisp_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMAVUMeterDisp_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMAVUMeterDisp_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMAVUMeterDisp_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMAVUMeterDisp_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMAVUMeterDisp_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMAVUMeterDisp_get_LeftLevel(This,pVal)	\
    ( (This)->lpVtbl -> get_LeftLevel(This,pVal) ) 

#define ILMAVUMeterDisp_get_RightLevel(This,pVal)	\
    ( (This)->lpVtbl -> get_RightLevel(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMAVUMeterDisp_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LMAVUMeter;

#ifdef __cplusplus

class DECLSPEC_UUID("e2b7db5c-38c5-11d5-91f6-00104bdb8ff9")
LMAVUMeter;
#endif
#endif /* __LMAVUMeterLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


