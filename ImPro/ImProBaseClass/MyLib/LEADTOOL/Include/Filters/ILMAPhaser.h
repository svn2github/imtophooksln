

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Nov 05 12:43:18 2009
 */
/* Compiler settings for .\IPhaser.idl:
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


#ifndef __ILMAPhaser_h__
#define __ILMAPhaser_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILMAPhaser_FWD_DEFINED__
#define __ILMAPhaser_FWD_DEFINED__
typedef interface ILMAPhaser ILMAPhaser;
#endif 	/* __ILMAPhaser_FWD_DEFINED__ */


#ifndef __ILMAPhaserDisp_FWD_DEFINED__
#define __ILMAPhaserDisp_FWD_DEFINED__
typedef interface ILMAPhaserDisp ILMAPhaserDisp;
#endif 	/* __ILMAPhaserDisp_FWD_DEFINED__ */


#ifndef __LMAPhaser_FWD_DEFINED__
#define __LMAPhaser_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMAPhaser LMAPhaser;
#else
typedef struct LMAPhaser LMAPhaser;
#endif /* __cplusplus */

#endif 	/* __LMAPhaser_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LMAPhaserLib_LIBRARY_DEFINED__
#define __LMAPhaserLib_LIBRARY_DEFINED__

/* library LMAPhaserLib */
/* [helpstring][version][uuid] */ 

#ifndef __IPhaser_H__
#define __IPhaser_H__
static const GUID CLSID_LMAPhaser             = {0xe2b7db3e, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMAPhaser              = {0xe2b7db3f, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMAPhaserPropertyPage = {0xe2b7db40, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMAAboutPhaser        = {0xe2b7db4f, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID LIBID_LMAPhaserLib          = {0xe2b7db66, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMAPhaserDisp          = {0xe2b7db67, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
typedef /* [public][public][public] */ struct __MIDL___MIDL_itf_IPhaser_0000_0000_0001
    {
    long lDryMix;
    long lWetMix;
    long lDelay;
    long lFeedback;
    long lStereo;
    long lDepth;
    long lRate;
    BOOL bEnabled;
    long lDDryMix;
    long lDWetMix;
    long lDDelay;
    long lDFeedback;
    long lDStereo;
    long lDDepth;
    long lDRate;
    BOOL bDEnabled;
    } 	PHASER_ATTRIBUTES;

#endif 

EXTERN_C const IID LIBID_LMAPhaserLib;

#ifndef __ILMAPhaser_INTERFACE_DEFINED__
#define __ILMAPhaser_INTERFACE_DEFINED__

/* interface ILMAPhaser */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ILMAPhaser;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DB3F-38C5-11D5-91F6-00104BDB8FF9")
    ILMAPhaser : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetPhaserAttributes( 
            /* [in] */ PHASER_ATTRIBUTES PhaserAttributes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPhaserAttributes( 
            /* [out] */ PHASER_ATTRIBUTES *pPhaserAttributes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNumChannels( 
            int *nChannels) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMAPhaserVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMAPhaser * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMAPhaser * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMAPhaser * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetPhaserAttributes )( 
            ILMAPhaser * This,
            /* [in] */ PHASER_ATTRIBUTES PhaserAttributes);
        
        HRESULT ( STDMETHODCALLTYPE *GetPhaserAttributes )( 
            ILMAPhaser * This,
            /* [out] */ PHASER_ATTRIBUTES *pPhaserAttributes);
        
        HRESULT ( STDMETHODCALLTYPE *GetNumChannels )( 
            ILMAPhaser * This,
            int *nChannels);
        
        END_INTERFACE
    } ILMAPhaserVtbl;

    interface ILMAPhaser
    {
        CONST_VTBL struct ILMAPhaserVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMAPhaser_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMAPhaser_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMAPhaser_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMAPhaser_SetPhaserAttributes(This,PhaserAttributes)	\
    ( (This)->lpVtbl -> SetPhaserAttributes(This,PhaserAttributes) ) 

#define ILMAPhaser_GetPhaserAttributes(This,pPhaserAttributes)	\
    ( (This)->lpVtbl -> GetPhaserAttributes(This,pPhaserAttributes) ) 

#define ILMAPhaser_GetNumChannels(This,nChannels)	\
    ( (This)->lpVtbl -> GetNumChannels(This,nChannels) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMAPhaser_INTERFACE_DEFINED__ */


#ifndef __ILMAPhaserDisp_INTERFACE_DEFINED__
#define __ILMAPhaserDisp_INTERFACE_DEFINED__

/* interface ILMAPhaserDisp */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILMAPhaserDisp;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DB67-38C5-11D5-91F6-00104BDB8FF9")
    ILMAPhaserDisp : public IDispatch
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
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Depth( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Depth( 
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
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultDepth( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DefaultDepth( 
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

    typedef struct ILMAPhaserDispVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMAPhaserDisp * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMAPhaserDisp * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMAPhaserDisp * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMAPhaserDisp * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMAPhaserDisp * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMAPhaserDisp * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMAPhaserDisp * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DryMix )( 
            ILMAPhaserDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DryMix )( 
            ILMAPhaserDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_WetMix )( 
            ILMAPhaserDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_WetMix )( 
            ILMAPhaserDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Delay )( 
            ILMAPhaserDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Delay )( 
            ILMAPhaserDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Feedback )( 
            ILMAPhaserDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Feedback )( 
            ILMAPhaserDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Rate )( 
            ILMAPhaserDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Rate )( 
            ILMAPhaserDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Depth )( 
            ILMAPhaserDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Depth )( 
            ILMAPhaserDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Stereo )( 
            ILMAPhaserDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Stereo )( 
            ILMAPhaserDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Enabled )( 
            ILMAPhaserDisp * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Enabled )( 
            ILMAPhaserDisp * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultDryMix )( 
            ILMAPhaserDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultDryMix )( 
            ILMAPhaserDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultWetMix )( 
            ILMAPhaserDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultWetMix )( 
            ILMAPhaserDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultDelay )( 
            ILMAPhaserDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultDelay )( 
            ILMAPhaserDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultFeedback )( 
            ILMAPhaserDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultFeedback )( 
            ILMAPhaserDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultRate )( 
            ILMAPhaserDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultRate )( 
            ILMAPhaserDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultDepth )( 
            ILMAPhaserDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultDepth )( 
            ILMAPhaserDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultStereo )( 
            ILMAPhaserDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultStereo )( 
            ILMAPhaserDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultEnabled )( 
            ILMAPhaserDisp * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultEnabled )( 
            ILMAPhaserDisp * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NumChannels )( 
            ILMAPhaserDisp * This,
            /* [retval][out] */ long *pVal);
        
        END_INTERFACE
    } ILMAPhaserDispVtbl;

    interface ILMAPhaserDisp
    {
        CONST_VTBL struct ILMAPhaserDispVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMAPhaserDisp_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMAPhaserDisp_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMAPhaserDisp_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMAPhaserDisp_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMAPhaserDisp_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMAPhaserDisp_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMAPhaserDisp_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMAPhaserDisp_get_DryMix(This,pVal)	\
    ( (This)->lpVtbl -> get_DryMix(This,pVal) ) 

#define ILMAPhaserDisp_put_DryMix(This,newVal)	\
    ( (This)->lpVtbl -> put_DryMix(This,newVal) ) 

#define ILMAPhaserDisp_get_WetMix(This,pVal)	\
    ( (This)->lpVtbl -> get_WetMix(This,pVal) ) 

#define ILMAPhaserDisp_put_WetMix(This,newVal)	\
    ( (This)->lpVtbl -> put_WetMix(This,newVal) ) 

#define ILMAPhaserDisp_get_Delay(This,pVal)	\
    ( (This)->lpVtbl -> get_Delay(This,pVal) ) 

#define ILMAPhaserDisp_put_Delay(This,newVal)	\
    ( (This)->lpVtbl -> put_Delay(This,newVal) ) 

#define ILMAPhaserDisp_get_Feedback(This,pVal)	\
    ( (This)->lpVtbl -> get_Feedback(This,pVal) ) 

#define ILMAPhaserDisp_put_Feedback(This,newVal)	\
    ( (This)->lpVtbl -> put_Feedback(This,newVal) ) 

#define ILMAPhaserDisp_get_Rate(This,pVal)	\
    ( (This)->lpVtbl -> get_Rate(This,pVal) ) 

#define ILMAPhaserDisp_put_Rate(This,newVal)	\
    ( (This)->lpVtbl -> put_Rate(This,newVal) ) 

#define ILMAPhaserDisp_get_Depth(This,pVal)	\
    ( (This)->lpVtbl -> get_Depth(This,pVal) ) 

#define ILMAPhaserDisp_put_Depth(This,newVal)	\
    ( (This)->lpVtbl -> put_Depth(This,newVal) ) 

#define ILMAPhaserDisp_get_Stereo(This,pVal)	\
    ( (This)->lpVtbl -> get_Stereo(This,pVal) ) 

#define ILMAPhaserDisp_put_Stereo(This,newVal)	\
    ( (This)->lpVtbl -> put_Stereo(This,newVal) ) 

#define ILMAPhaserDisp_get_Enabled(This,pVal)	\
    ( (This)->lpVtbl -> get_Enabled(This,pVal) ) 

#define ILMAPhaserDisp_put_Enabled(This,newVal)	\
    ( (This)->lpVtbl -> put_Enabled(This,newVal) ) 

#define ILMAPhaserDisp_get_DefaultDryMix(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultDryMix(This,pVal) ) 

#define ILMAPhaserDisp_put_DefaultDryMix(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultDryMix(This,newVal) ) 

#define ILMAPhaserDisp_get_DefaultWetMix(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultWetMix(This,pVal) ) 

#define ILMAPhaserDisp_put_DefaultWetMix(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultWetMix(This,newVal) ) 

#define ILMAPhaserDisp_get_DefaultDelay(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultDelay(This,pVal) ) 

#define ILMAPhaserDisp_put_DefaultDelay(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultDelay(This,newVal) ) 

#define ILMAPhaserDisp_get_DefaultFeedback(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultFeedback(This,pVal) ) 

#define ILMAPhaserDisp_put_DefaultFeedback(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultFeedback(This,newVal) ) 

#define ILMAPhaserDisp_get_DefaultRate(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultRate(This,pVal) ) 

#define ILMAPhaserDisp_put_DefaultRate(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultRate(This,newVal) ) 

#define ILMAPhaserDisp_get_DefaultDepth(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultDepth(This,pVal) ) 

#define ILMAPhaserDisp_put_DefaultDepth(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultDepth(This,newVal) ) 

#define ILMAPhaserDisp_get_DefaultStereo(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultStereo(This,pVal) ) 

#define ILMAPhaserDisp_put_DefaultStereo(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultStereo(This,newVal) ) 

#define ILMAPhaserDisp_get_DefaultEnabled(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultEnabled(This,pVal) ) 

#define ILMAPhaserDisp_put_DefaultEnabled(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultEnabled(This,newVal) ) 

#define ILMAPhaserDisp_get_NumChannels(This,pVal)	\
    ( (This)->lpVtbl -> get_NumChannels(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMAPhaserDisp_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LMAPhaser;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DB3E-38C5-11D5-91F6-00104BDB8FF9")
LMAPhaser;
#endif
#endif /* __LMAPhaserLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


