

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Nov 05 12:42:57 2009
 */
/* Compiler settings for .\IEcho.idl:
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


#ifndef __ILMAEcho_h__
#define __ILMAEcho_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILMAEcho_FWD_DEFINED__
#define __ILMAEcho_FWD_DEFINED__
typedef interface ILMAEcho ILMAEcho;
#endif 	/* __ILMAEcho_FWD_DEFINED__ */


#ifndef __ILMAEchoDisp_FWD_DEFINED__
#define __ILMAEchoDisp_FWD_DEFINED__
typedef interface ILMAEchoDisp ILMAEchoDisp;
#endif 	/* __ILMAEchoDisp_FWD_DEFINED__ */


#ifndef __LMAEcho_FWD_DEFINED__
#define __LMAEcho_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMAEcho LMAEcho;
#else
typedef struct LMAEcho LMAEcho;
#endif /* __cplusplus */

#endif 	/* __LMAEcho_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LMAEchoLib_LIBRARY_DEFINED__
#define __LMAEchoLib_LIBRARY_DEFINED__

/* library LMAEchoLib */
/* [helpstring][version][uuid] */ 

#ifndef __IECHO_H__
#define __IECHO_H__
static const GUID CLSID_LMAEcho             = {0xe2b7db35, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMAEcho              = {0xe2b7db36, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMAEchoPropertyPage = {0xe2b7db37, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMAAboutEcho        = {0xe2b7db49, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID LIBID_LMAEchoLib          = {0xe2b7db60, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMAEchoDisp          = {0xe2b7db61, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
typedef /* [public][public][public] */ struct __MIDL___MIDL_itf_IEcho_0000_0000_0001
    {
    long lDryMix;
    long lWetMix;
    long lDelay;
    long lFeedback;
    BOOL bEnabled;
    long lDDryMix;
    long lDWetMix;
    long lDDelay;
    long lDFeedback;
    BOOL bDEnabled;
    } 	ECHO_ATTRIBUTES;

#endif 

EXTERN_C const IID LIBID_LMAEchoLib;

#ifndef __ILMAEcho_INTERFACE_DEFINED__
#define __ILMAEcho_INTERFACE_DEFINED__

/* interface ILMAEcho */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ILMAEcho;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DB36-38C5-11D5-91F6-00104BDB8FF9")
    ILMAEcho : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetEchoAttributes( 
            /* [in] */ ECHO_ATTRIBUTES EchoAttributes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEchoAttributes( 
            /* [out] */ ECHO_ATTRIBUTES *pEchoAttributes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNumChannels( 
            int *nChannels) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMAEchoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMAEcho * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMAEcho * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMAEcho * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetEchoAttributes )( 
            ILMAEcho * This,
            /* [in] */ ECHO_ATTRIBUTES EchoAttributes);
        
        HRESULT ( STDMETHODCALLTYPE *GetEchoAttributes )( 
            ILMAEcho * This,
            /* [out] */ ECHO_ATTRIBUTES *pEchoAttributes);
        
        HRESULT ( STDMETHODCALLTYPE *GetNumChannels )( 
            ILMAEcho * This,
            int *nChannels);
        
        END_INTERFACE
    } ILMAEchoVtbl;

    interface ILMAEcho
    {
        CONST_VTBL struct ILMAEchoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMAEcho_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMAEcho_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMAEcho_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMAEcho_SetEchoAttributes(This,EchoAttributes)	\
    ( (This)->lpVtbl -> SetEchoAttributes(This,EchoAttributes) ) 

#define ILMAEcho_GetEchoAttributes(This,pEchoAttributes)	\
    ( (This)->lpVtbl -> GetEchoAttributes(This,pEchoAttributes) ) 

#define ILMAEcho_GetNumChannels(This,nChannels)	\
    ( (This)->lpVtbl -> GetNumChannels(This,nChannels) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMAEcho_INTERFACE_DEFINED__ */


#ifndef __ILMAEchoDisp_INTERFACE_DEFINED__
#define __ILMAEchoDisp_INTERFACE_DEFINED__

/* interface ILMAEchoDisp */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILMAEchoDisp;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DB61-38C5-11D5-91F6-00104BDB8FF9")
    ILMAEchoDisp : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DryMix( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DryMix( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_WetMix( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_WetMix( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Delay( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Delay( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Feedback( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Feedback( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Enabled( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Enabled( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultDryMix( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DefaultDryMix( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultWetMix( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DefaultWetMix( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultDelay( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DefaultDelay( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultFeedback( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DefaultFeedback( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultEnabled( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DefaultEnabled( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_NumChannels( 
            /* [retval][out] */ long *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMAEchoDispVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMAEchoDisp * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMAEchoDisp * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMAEchoDisp * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMAEchoDisp * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMAEchoDisp * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMAEchoDisp * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMAEchoDisp * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DryMix )( 
            ILMAEchoDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DryMix )( 
            ILMAEchoDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_WetMix )( 
            ILMAEchoDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_WetMix )( 
            ILMAEchoDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Delay )( 
            ILMAEchoDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Delay )( 
            ILMAEchoDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Feedback )( 
            ILMAEchoDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Feedback )( 
            ILMAEchoDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Enabled )( 
            ILMAEchoDisp * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Enabled )( 
            ILMAEchoDisp * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultDryMix )( 
            ILMAEchoDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultDryMix )( 
            ILMAEchoDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultWetMix )( 
            ILMAEchoDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultWetMix )( 
            ILMAEchoDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultDelay )( 
            ILMAEchoDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultDelay )( 
            ILMAEchoDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultFeedback )( 
            ILMAEchoDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultFeedback )( 
            ILMAEchoDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultEnabled )( 
            ILMAEchoDisp * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultEnabled )( 
            ILMAEchoDisp * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NumChannels )( 
            ILMAEchoDisp * This,
            /* [retval][out] */ long *pVal);
        
        END_INTERFACE
    } ILMAEchoDispVtbl;

    interface ILMAEchoDisp
    {
        CONST_VTBL struct ILMAEchoDispVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMAEchoDisp_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMAEchoDisp_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMAEchoDisp_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMAEchoDisp_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMAEchoDisp_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMAEchoDisp_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMAEchoDisp_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMAEchoDisp_get_DryMix(This,pVal)	\
    ( (This)->lpVtbl -> get_DryMix(This,pVal) ) 

#define ILMAEchoDisp_put_DryMix(This,newVal)	\
    ( (This)->lpVtbl -> put_DryMix(This,newVal) ) 

#define ILMAEchoDisp_get_WetMix(This,pVal)	\
    ( (This)->lpVtbl -> get_WetMix(This,pVal) ) 

#define ILMAEchoDisp_put_WetMix(This,newVal)	\
    ( (This)->lpVtbl -> put_WetMix(This,newVal) ) 

#define ILMAEchoDisp_get_Delay(This,pVal)	\
    ( (This)->lpVtbl -> get_Delay(This,pVal) ) 

#define ILMAEchoDisp_put_Delay(This,newVal)	\
    ( (This)->lpVtbl -> put_Delay(This,newVal) ) 

#define ILMAEchoDisp_get_Feedback(This,pVal)	\
    ( (This)->lpVtbl -> get_Feedback(This,pVal) ) 

#define ILMAEchoDisp_put_Feedback(This,newVal)	\
    ( (This)->lpVtbl -> put_Feedback(This,newVal) ) 

#define ILMAEchoDisp_get_Enabled(This,pVal)	\
    ( (This)->lpVtbl -> get_Enabled(This,pVal) ) 

#define ILMAEchoDisp_put_Enabled(This,newVal)	\
    ( (This)->lpVtbl -> put_Enabled(This,newVal) ) 

#define ILMAEchoDisp_get_DefaultDryMix(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultDryMix(This,pVal) ) 

#define ILMAEchoDisp_put_DefaultDryMix(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultDryMix(This,newVal) ) 

#define ILMAEchoDisp_get_DefaultWetMix(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultWetMix(This,pVal) ) 

#define ILMAEchoDisp_put_DefaultWetMix(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultWetMix(This,newVal) ) 

#define ILMAEchoDisp_get_DefaultDelay(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultDelay(This,pVal) ) 

#define ILMAEchoDisp_put_DefaultDelay(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultDelay(This,newVal) ) 

#define ILMAEchoDisp_get_DefaultFeedback(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultFeedback(This,pVal) ) 

#define ILMAEchoDisp_put_DefaultFeedback(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultFeedback(This,newVal) ) 

#define ILMAEchoDisp_get_DefaultEnabled(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultEnabled(This,pVal) ) 

#define ILMAEchoDisp_put_DefaultEnabled(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultEnabled(This,newVal) ) 

#define ILMAEchoDisp_get_NumChannels(This,pVal)	\
    ( (This)->lpVtbl -> get_NumChannels(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMAEchoDisp_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LMAEcho;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DB35-38C5-11D5-91F6-00104BDB8FF9")
LMAEcho;
#endif
#endif /* __LMAEchoLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


