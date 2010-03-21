

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Nov 05 12:43:08 2009
 */
/* Compiler settings for .\IFlanger.idl:
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


#ifndef __ILMAFlanger_h__
#define __ILMAFlanger_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILMAFlanger_FWD_DEFINED__
#define __ILMAFlanger_FWD_DEFINED__
typedef interface ILMAFlanger ILMAFlanger;
#endif 	/* __ILMAFlanger_FWD_DEFINED__ */


#ifndef __ILMAFlangerDisp_FWD_DEFINED__
#define __ILMAFlangerDisp_FWD_DEFINED__
typedef interface ILMAFlangerDisp ILMAFlangerDisp;
#endif 	/* __ILMAFlangerDisp_FWD_DEFINED__ */


#ifndef __LMAFlanger_FWD_DEFINED__
#define __LMAFlanger_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMAFlanger LMAFlanger;
#else
typedef struct LMAFlanger LMAFlanger;
#endif /* __cplusplus */

#endif 	/* __LMAFlanger_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LMAFlangerLib_LIBRARY_DEFINED__
#define __LMAFlangerLib_LIBRARY_DEFINED__

/* library LMAFlangerLib */
/* [helpstring][version][uuid] */ 

#ifndef __IFlanger_H__
#define __IFlanger_H__
static const GUID CLSID_LMAFlanger             = {0xe2b7db3b, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMAFlanger              = {0xe2b7db3c, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMAFlangerPropertyPage = {0xe2b7db3d, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMAAboutFlanger        = {0xe2b7db4b, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID LIBID_LMAFlangerLib          = {0xe2b7db64, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMAFlangerDisp          = {0xe2b7db65, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
typedef /* [public][public][public] */ struct __MIDL___MIDL_itf_IFlanger_0000_0000_0001
    {
    long lDryMix;
    long lWetMix;
    long lDelay;
    long lFeedback;
    long lRate;
    long lSweep;
    long lStereo;
    BOOL bEnabled;
    long lDDryMix;
    long lDWetMix;
    long lDDelay;
    long lDFeedback;
    long lDRate;
    long lDSweep;
    long lDStereo;
    BOOL bDEnabled;
    } 	FLANGER_ATTRIBUTES;

#endif 

EXTERN_C const IID LIBID_LMAFlangerLib;

#ifndef __ILMAFlanger_INTERFACE_DEFINED__
#define __ILMAFlanger_INTERFACE_DEFINED__

/* interface ILMAFlanger */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ILMAFlanger;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DB3C-38C5-11D5-91F6-00104BDB8FF9")
    ILMAFlanger : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetFlangerAttributes( 
            /* [in] */ FLANGER_ATTRIBUTES FlangerAttributes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFlangerAttributes( 
            /* [out] */ FLANGER_ATTRIBUTES *pFlangerAttributes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNumChannels( 
            int *nChannels) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMAFlangerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMAFlanger * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMAFlanger * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMAFlanger * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetFlangerAttributes )( 
            ILMAFlanger * This,
            /* [in] */ FLANGER_ATTRIBUTES FlangerAttributes);
        
        HRESULT ( STDMETHODCALLTYPE *GetFlangerAttributes )( 
            ILMAFlanger * This,
            /* [out] */ FLANGER_ATTRIBUTES *pFlangerAttributes);
        
        HRESULT ( STDMETHODCALLTYPE *GetNumChannels )( 
            ILMAFlanger * This,
            int *nChannels);
        
        END_INTERFACE
    } ILMAFlangerVtbl;

    interface ILMAFlanger
    {
        CONST_VTBL struct ILMAFlangerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMAFlanger_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMAFlanger_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMAFlanger_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMAFlanger_SetFlangerAttributes(This,FlangerAttributes)	\
    ( (This)->lpVtbl -> SetFlangerAttributes(This,FlangerAttributes) ) 

#define ILMAFlanger_GetFlangerAttributes(This,pFlangerAttributes)	\
    ( (This)->lpVtbl -> GetFlangerAttributes(This,pFlangerAttributes) ) 

#define ILMAFlanger_GetNumChannels(This,nChannels)	\
    ( (This)->lpVtbl -> GetNumChannels(This,nChannels) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMAFlanger_INTERFACE_DEFINED__ */


#ifndef __ILMAFlangerDisp_INTERFACE_DEFINED__
#define __ILMAFlangerDisp_INTERFACE_DEFINED__

/* interface ILMAFlangerDisp */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILMAFlangerDisp;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DB65-38C5-11D5-91F6-00104BDB8FF9")
    ILMAFlangerDisp : public IDispatch
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
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Rate( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Rate( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Sweep( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Sweep( 
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
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultRate( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DefaultRate( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultSweep( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DefaultSweep( 
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

    typedef struct ILMAFlangerDispVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMAFlangerDisp * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMAFlangerDisp * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMAFlangerDisp * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMAFlangerDisp * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMAFlangerDisp * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMAFlangerDisp * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMAFlangerDisp * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DryMix )( 
            ILMAFlangerDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DryMix )( 
            ILMAFlangerDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_WetMix )( 
            ILMAFlangerDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_WetMix )( 
            ILMAFlangerDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Delay )( 
            ILMAFlangerDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Delay )( 
            ILMAFlangerDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Feedback )( 
            ILMAFlangerDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Feedback )( 
            ILMAFlangerDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Rate )( 
            ILMAFlangerDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Rate )( 
            ILMAFlangerDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Sweep )( 
            ILMAFlangerDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Sweep )( 
            ILMAFlangerDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Stereo )( 
            ILMAFlangerDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Stereo )( 
            ILMAFlangerDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Enabled )( 
            ILMAFlangerDisp * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Enabled )( 
            ILMAFlangerDisp * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultDryMix )( 
            ILMAFlangerDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultDryMix )( 
            ILMAFlangerDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultWetMix )( 
            ILMAFlangerDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultWetMix )( 
            ILMAFlangerDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultDelay )( 
            ILMAFlangerDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultDelay )( 
            ILMAFlangerDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultFeedback )( 
            ILMAFlangerDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultFeedback )( 
            ILMAFlangerDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultRate )( 
            ILMAFlangerDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultRate )( 
            ILMAFlangerDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultSweep )( 
            ILMAFlangerDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultSweep )( 
            ILMAFlangerDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultStereo )( 
            ILMAFlangerDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultStereo )( 
            ILMAFlangerDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultEnabled )( 
            ILMAFlangerDisp * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultEnabled )( 
            ILMAFlangerDisp * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NumChannels )( 
            ILMAFlangerDisp * This,
            /* [retval][out] */ long *pVal);
        
        END_INTERFACE
    } ILMAFlangerDispVtbl;

    interface ILMAFlangerDisp
    {
        CONST_VTBL struct ILMAFlangerDispVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMAFlangerDisp_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMAFlangerDisp_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMAFlangerDisp_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMAFlangerDisp_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMAFlangerDisp_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMAFlangerDisp_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMAFlangerDisp_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMAFlangerDisp_get_DryMix(This,pVal)	\
    ( (This)->lpVtbl -> get_DryMix(This,pVal) ) 

#define ILMAFlangerDisp_put_DryMix(This,newVal)	\
    ( (This)->lpVtbl -> put_DryMix(This,newVal) ) 

#define ILMAFlangerDisp_get_WetMix(This,pVal)	\
    ( (This)->lpVtbl -> get_WetMix(This,pVal) ) 

#define ILMAFlangerDisp_put_WetMix(This,newVal)	\
    ( (This)->lpVtbl -> put_WetMix(This,newVal) ) 

#define ILMAFlangerDisp_get_Delay(This,pVal)	\
    ( (This)->lpVtbl -> get_Delay(This,pVal) ) 

#define ILMAFlangerDisp_put_Delay(This,newVal)	\
    ( (This)->lpVtbl -> put_Delay(This,newVal) ) 

#define ILMAFlangerDisp_get_Feedback(This,pVal)	\
    ( (This)->lpVtbl -> get_Feedback(This,pVal) ) 

#define ILMAFlangerDisp_put_Feedback(This,newVal)	\
    ( (This)->lpVtbl -> put_Feedback(This,newVal) ) 

#define ILMAFlangerDisp_get_Rate(This,pVal)	\
    ( (This)->lpVtbl -> get_Rate(This,pVal) ) 

#define ILMAFlangerDisp_put_Rate(This,newVal)	\
    ( (This)->lpVtbl -> put_Rate(This,newVal) ) 

#define ILMAFlangerDisp_get_Sweep(This,pVal)	\
    ( (This)->lpVtbl -> get_Sweep(This,pVal) ) 

#define ILMAFlangerDisp_put_Sweep(This,newVal)	\
    ( (This)->lpVtbl -> put_Sweep(This,newVal) ) 

#define ILMAFlangerDisp_get_Stereo(This,pVal)	\
    ( (This)->lpVtbl -> get_Stereo(This,pVal) ) 

#define ILMAFlangerDisp_put_Stereo(This,newVal)	\
    ( (This)->lpVtbl -> put_Stereo(This,newVal) ) 

#define ILMAFlangerDisp_get_Enabled(This,pVal)	\
    ( (This)->lpVtbl -> get_Enabled(This,pVal) ) 

#define ILMAFlangerDisp_put_Enabled(This,newVal)	\
    ( (This)->lpVtbl -> put_Enabled(This,newVal) ) 

#define ILMAFlangerDisp_get_DefaultDryMix(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultDryMix(This,pVal) ) 

#define ILMAFlangerDisp_put_DefaultDryMix(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultDryMix(This,newVal) ) 

#define ILMAFlangerDisp_get_DefaultWetMix(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultWetMix(This,pVal) ) 

#define ILMAFlangerDisp_put_DefaultWetMix(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultWetMix(This,newVal) ) 

#define ILMAFlangerDisp_get_DefaultDelay(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultDelay(This,pVal) ) 

#define ILMAFlangerDisp_put_DefaultDelay(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultDelay(This,newVal) ) 

#define ILMAFlangerDisp_get_DefaultFeedback(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultFeedback(This,pVal) ) 

#define ILMAFlangerDisp_put_DefaultFeedback(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultFeedback(This,newVal) ) 

#define ILMAFlangerDisp_get_DefaultRate(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultRate(This,pVal) ) 

#define ILMAFlangerDisp_put_DefaultRate(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultRate(This,newVal) ) 

#define ILMAFlangerDisp_get_DefaultSweep(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultSweep(This,pVal) ) 

#define ILMAFlangerDisp_put_DefaultSweep(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultSweep(This,newVal) ) 

#define ILMAFlangerDisp_get_DefaultStereo(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultStereo(This,pVal) ) 

#define ILMAFlangerDisp_put_DefaultStereo(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultStereo(This,newVal) ) 

#define ILMAFlangerDisp_get_DefaultEnabled(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultEnabled(This,pVal) ) 

#define ILMAFlangerDisp_put_DefaultEnabled(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultEnabled(This,newVal) ) 

#define ILMAFlangerDisp_get_NumChannels(This,pVal)	\
    ( (This)->lpVtbl -> get_NumChannels(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMAFlangerDisp_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LMAFlanger;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DB3B-38C5-11D5-91F6-00104BDB8FF9")
LMAFlanger;
#endif
#endif /* __LMAFlangerLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


