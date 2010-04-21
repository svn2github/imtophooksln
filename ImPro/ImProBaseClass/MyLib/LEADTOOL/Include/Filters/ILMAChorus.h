

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Nov 05 12:42:46 2009
 */
/* Compiler settings for .\IChorus.idl:
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


#ifndef __ILMAChorus_h__
#define __ILMAChorus_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILMAChorus_FWD_DEFINED__
#define __ILMAChorus_FWD_DEFINED__
typedef interface ILMAChorus ILMAChorus;
#endif 	/* __ILMAChorus_FWD_DEFINED__ */


#ifndef __ILMAChorusDisp_FWD_DEFINED__
#define __ILMAChorusDisp_FWD_DEFINED__
typedef interface ILMAChorusDisp ILMAChorusDisp;
#endif 	/* __ILMAChorusDisp_FWD_DEFINED__ */


#ifndef __LMAChorus_FWD_DEFINED__
#define __LMAChorus_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMAChorus LMAChorus;
#else
typedef struct LMAChorus LMAChorus;
#endif /* __cplusplus */

#endif 	/* __LMAChorus_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LMAChorusLib_LIBRARY_DEFINED__
#define __LMAChorusLib_LIBRARY_DEFINED__

/* library LMAChorusLib */
/* [helpstring][version][uuid] */ 

#ifndef __IChorus_H__
#define __IChorus_H__
static const GUID CLSID_LMAChorus             = {0xe2b7db38, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMAChorus              = {0xe2b7db39, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMAChorusPropertyPage = {0xe2b7db3a, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMAAboutChorus        = {0xe2b7db46, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID LIBID_LMAChorusLib          = {0xe2b7db62, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMAChorusDisp          = {0xe2b7db63, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
typedef /* [public][public][public] */ struct __MIDL___MIDL_itf_IChorus_0000_0000_0001
    {
    long lDryMix;
    long lWetMix;
    long lDelay;
    long lFeedback;
    long lStereo;
    BOOL bEnabled;
    long lDDryMix;
    long lDWetMix;
    long lDDelay;
    long lDFeedback;
    long lDStereo;
    BOOL bDEnabled;
    } 	CHORUS_ATTRIBUTES;

#endif 

EXTERN_C const IID LIBID_LMAChorusLib;

#ifndef __ILMAChorus_INTERFACE_DEFINED__
#define __ILMAChorus_INTERFACE_DEFINED__

/* interface ILMAChorus */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ILMAChorus;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DB39-38C5-11D5-91F6-00104BDB8FF9")
    ILMAChorus : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetChorusAttributes( 
            /* [in] */ CHORUS_ATTRIBUTES ChorusAttributes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetChorusAttributes( 
            /* [out] */ CHORUS_ATTRIBUTES *pChorusAttributes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNumChannels( 
            int *nChannels) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMAChorusVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMAChorus * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMAChorus * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMAChorus * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetChorusAttributes )( 
            ILMAChorus * This,
            /* [in] */ CHORUS_ATTRIBUTES ChorusAttributes);
        
        HRESULT ( STDMETHODCALLTYPE *GetChorusAttributes )( 
            ILMAChorus * This,
            /* [out] */ CHORUS_ATTRIBUTES *pChorusAttributes);
        
        HRESULT ( STDMETHODCALLTYPE *GetNumChannels )( 
            ILMAChorus * This,
            int *nChannels);
        
        END_INTERFACE
    } ILMAChorusVtbl;

    interface ILMAChorus
    {
        CONST_VTBL struct ILMAChorusVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMAChorus_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMAChorus_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMAChorus_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMAChorus_SetChorusAttributes(This,ChorusAttributes)	\
    ( (This)->lpVtbl -> SetChorusAttributes(This,ChorusAttributes) ) 

#define ILMAChorus_GetChorusAttributes(This,pChorusAttributes)	\
    ( (This)->lpVtbl -> GetChorusAttributes(This,pChorusAttributes) ) 

#define ILMAChorus_GetNumChannels(This,nChannels)	\
    ( (This)->lpVtbl -> GetNumChannels(This,nChannels) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMAChorus_INTERFACE_DEFINED__ */


#ifndef __ILMAChorusDisp_INTERFACE_DEFINED__
#define __ILMAChorusDisp_INTERFACE_DEFINED__

/* interface ILMAChorusDisp */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILMAChorusDisp;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DB63-38C5-11D5-91F6-00104BDB8FF9")
    ILMAChorusDisp : public IDispatch
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
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Stereo( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Stereo( 
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
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultStereo( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DefaultStereo( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultEnabled( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DefaultEnabled( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_NumChannels( 
            /* [retval][out] */ long *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMAChorusDispVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMAChorusDisp * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMAChorusDisp * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMAChorusDisp * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMAChorusDisp * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMAChorusDisp * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMAChorusDisp * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMAChorusDisp * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DryMix )( 
            ILMAChorusDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DryMix )( 
            ILMAChorusDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_WetMix )( 
            ILMAChorusDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_WetMix )( 
            ILMAChorusDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Delay )( 
            ILMAChorusDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Delay )( 
            ILMAChorusDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Feedback )( 
            ILMAChorusDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Feedback )( 
            ILMAChorusDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Stereo )( 
            ILMAChorusDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Stereo )( 
            ILMAChorusDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Enabled )( 
            ILMAChorusDisp * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Enabled )( 
            ILMAChorusDisp * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultDryMix )( 
            ILMAChorusDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultDryMix )( 
            ILMAChorusDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultWetMix )( 
            ILMAChorusDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultWetMix )( 
            ILMAChorusDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultDelay )( 
            ILMAChorusDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultDelay )( 
            ILMAChorusDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultFeedback )( 
            ILMAChorusDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultFeedback )( 
            ILMAChorusDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultStereo )( 
            ILMAChorusDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultStereo )( 
            ILMAChorusDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultEnabled )( 
            ILMAChorusDisp * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultEnabled )( 
            ILMAChorusDisp * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NumChannels )( 
            ILMAChorusDisp * This,
            /* [retval][out] */ long *pVal);
        
        END_INTERFACE
    } ILMAChorusDispVtbl;

    interface ILMAChorusDisp
    {
        CONST_VTBL struct ILMAChorusDispVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMAChorusDisp_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMAChorusDisp_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMAChorusDisp_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMAChorusDisp_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMAChorusDisp_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMAChorusDisp_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMAChorusDisp_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMAChorusDisp_get_DryMix(This,pVal)	\
    ( (This)->lpVtbl -> get_DryMix(This,pVal) ) 

#define ILMAChorusDisp_put_DryMix(This,newVal)	\
    ( (This)->lpVtbl -> put_DryMix(This,newVal) ) 

#define ILMAChorusDisp_get_WetMix(This,pVal)	\
    ( (This)->lpVtbl -> get_WetMix(This,pVal) ) 

#define ILMAChorusDisp_put_WetMix(This,newVal)	\
    ( (This)->lpVtbl -> put_WetMix(This,newVal) ) 

#define ILMAChorusDisp_get_Delay(This,pVal)	\
    ( (This)->lpVtbl -> get_Delay(This,pVal) ) 

#define ILMAChorusDisp_put_Delay(This,newVal)	\
    ( (This)->lpVtbl -> put_Delay(This,newVal) ) 

#define ILMAChorusDisp_get_Feedback(This,pVal)	\
    ( (This)->lpVtbl -> get_Feedback(This,pVal) ) 

#define ILMAChorusDisp_put_Feedback(This,newVal)	\
    ( (This)->lpVtbl -> put_Feedback(This,newVal) ) 

#define ILMAChorusDisp_get_Stereo(This,pVal)	\
    ( (This)->lpVtbl -> get_Stereo(This,pVal) ) 

#define ILMAChorusDisp_put_Stereo(This,newVal)	\
    ( (This)->lpVtbl -> put_Stereo(This,newVal) ) 

#define ILMAChorusDisp_get_Enabled(This,pVal)	\
    ( (This)->lpVtbl -> get_Enabled(This,pVal) ) 

#define ILMAChorusDisp_put_Enabled(This,newVal)	\
    ( (This)->lpVtbl -> put_Enabled(This,newVal) ) 

#define ILMAChorusDisp_get_DefaultDryMix(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultDryMix(This,pVal) ) 

#define ILMAChorusDisp_put_DefaultDryMix(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultDryMix(This,newVal) ) 

#define ILMAChorusDisp_get_DefaultWetMix(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultWetMix(This,pVal) ) 

#define ILMAChorusDisp_put_DefaultWetMix(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultWetMix(This,newVal) ) 

#define ILMAChorusDisp_get_DefaultDelay(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultDelay(This,pVal) ) 

#define ILMAChorusDisp_put_DefaultDelay(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultDelay(This,newVal) ) 

#define ILMAChorusDisp_get_DefaultFeedback(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultFeedback(This,pVal) ) 

#define ILMAChorusDisp_put_DefaultFeedback(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultFeedback(This,newVal) ) 

#define ILMAChorusDisp_get_DefaultStereo(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultStereo(This,pVal) ) 

#define ILMAChorusDisp_put_DefaultStereo(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultStereo(This,newVal) ) 

#define ILMAChorusDisp_get_DefaultEnabled(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultEnabled(This,pVal) ) 

#define ILMAChorusDisp_put_DefaultEnabled(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultEnabled(This,newVal) ) 

#define ILMAChorusDisp_get_NumChannels(This,pVal)	\
    ( (This)->lpVtbl -> get_NumChannels(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMAChorusDisp_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LMAChorus;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DB38-38C5-11D5-91F6-00104BDB8FF9")
LMAChorus;
#endif
#endif /* __LMAChorusLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


