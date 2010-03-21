

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Nov 05 12:43:28 2009
 */
/* Compiler settings for .\IVolume.idl:
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


#ifndef __ILMAVol_h__
#define __ILMAVol_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILMAVolume_FWD_DEFINED__
#define __ILMAVolume_FWD_DEFINED__
typedef interface ILMAVolume ILMAVolume;
#endif 	/* __ILMAVolume_FWD_DEFINED__ */


#ifndef __ILMAVolumeDisp_FWD_DEFINED__
#define __ILMAVolumeDisp_FWD_DEFINED__
typedef interface ILMAVolumeDisp ILMAVolumeDisp;
#endif 	/* __ILMAVolumeDisp_FWD_DEFINED__ */


#ifndef __LMAVolume_FWD_DEFINED__
#define __LMAVolume_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMAVolume LMAVolume;
#else
typedef struct LMAVolume LMAVolume;
#endif /* __cplusplus */

#endif 	/* __LMAVolume_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LMAVolumeLib_LIBRARY_DEFINED__
#define __LMAVolumeLib_LIBRARY_DEFINED__

/* library LMAVolumeLib */
/* [helpstring][version][uuid] */ 

#ifndef __IVOLUME_H__
#define __IVOLUME_H__
static const GUID CLSID_LMAVolume             = {0xe2b7db31, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMAVolume              = {0xe2b7db32, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMAVolumePropertyPage = {0xe2b7db33, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMAAboutVolume        = {0xe2b7db51, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID LIBID_LMAVolumeLib          = {0xe2b7db8D, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMAVolumeDisp          = {0xe2b7db8E, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
#endif 

EXTERN_C const IID LIBID_LMAVolumeLib;

#ifndef __ILMAVolume_INTERFACE_DEFINED__
#define __ILMAVolume_INTERFACE_DEFINED__

/* interface ILMAVolume */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ILMAVolume;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("e2b7db32-38c5-11d5-91f6-00104bdb8ff9")
    ILMAVolume : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetAmplitude( 
            /* [in] */ int lAmplitude) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAmplitude( 
            /* [out] */ int *lAmplitude) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMute( 
            BOOL bMute) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMute( 
            BOOL *bMute) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNumChannels( 
            int *nChannels) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMAVolumeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMAVolume * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMAVolume * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMAVolume * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetAmplitude )( 
            ILMAVolume * This,
            /* [in] */ int lAmplitude);
        
        HRESULT ( STDMETHODCALLTYPE *GetAmplitude )( 
            ILMAVolume * This,
            /* [out] */ int *lAmplitude);
        
        HRESULT ( STDMETHODCALLTYPE *SetMute )( 
            ILMAVolume * This,
            BOOL bMute);
        
        HRESULT ( STDMETHODCALLTYPE *GetMute )( 
            ILMAVolume * This,
            BOOL *bMute);
        
        HRESULT ( STDMETHODCALLTYPE *GetNumChannels )( 
            ILMAVolume * This,
            int *nChannels);
        
        END_INTERFACE
    } ILMAVolumeVtbl;

    interface ILMAVolume
    {
        CONST_VTBL struct ILMAVolumeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMAVolume_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMAVolume_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMAVolume_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMAVolume_SetAmplitude(This,lAmplitude)	\
    ( (This)->lpVtbl -> SetAmplitude(This,lAmplitude) ) 

#define ILMAVolume_GetAmplitude(This,lAmplitude)	\
    ( (This)->lpVtbl -> GetAmplitude(This,lAmplitude) ) 

#define ILMAVolume_SetMute(This,bMute)	\
    ( (This)->lpVtbl -> SetMute(This,bMute) ) 

#define ILMAVolume_GetMute(This,bMute)	\
    ( (This)->lpVtbl -> GetMute(This,bMute) ) 

#define ILMAVolume_GetNumChannels(This,nChannels)	\
    ( (This)->lpVtbl -> GetNumChannels(This,nChannels) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMAVolume_INTERFACE_DEFINED__ */


#ifndef __ILMAVolumeDisp_INTERFACE_DEFINED__
#define __ILMAVolumeDisp_INTERFACE_DEFINED__

/* interface ILMAVolumeDisp */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILMAVolumeDisp;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DB8E-38C5-11D5-91F6-00104BDB8FF9")
    ILMAVolumeDisp : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Amplitude( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Amplitude( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Mute( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Mute( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_NumChannels( 
            /* [retval][out] */ long *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMAVolumeDispVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMAVolumeDisp * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMAVolumeDisp * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMAVolumeDisp * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMAVolumeDisp * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMAVolumeDisp * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMAVolumeDisp * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMAVolumeDisp * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Amplitude )( 
            ILMAVolumeDisp * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Amplitude )( 
            ILMAVolumeDisp * This,
            /* [in] */ int newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Mute )( 
            ILMAVolumeDisp * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Mute )( 
            ILMAVolumeDisp * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NumChannels )( 
            ILMAVolumeDisp * This,
            /* [retval][out] */ long *pVal);
        
        END_INTERFACE
    } ILMAVolumeDispVtbl;

    interface ILMAVolumeDisp
    {
        CONST_VTBL struct ILMAVolumeDispVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMAVolumeDisp_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMAVolumeDisp_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMAVolumeDisp_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMAVolumeDisp_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMAVolumeDisp_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMAVolumeDisp_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMAVolumeDisp_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMAVolumeDisp_get_Amplitude(This,pVal)	\
    ( (This)->lpVtbl -> get_Amplitude(This,pVal) ) 

#define ILMAVolumeDisp_put_Amplitude(This,newVal)	\
    ( (This)->lpVtbl -> put_Amplitude(This,newVal) ) 

#define ILMAVolumeDisp_get_Mute(This,pVal)	\
    ( (This)->lpVtbl -> get_Mute(This,pVal) ) 

#define ILMAVolumeDisp_put_Mute(This,newVal)	\
    ( (This)->lpVtbl -> put_Mute(This,newVal) ) 

#define ILMAVolumeDisp_get_NumChannels(This,pVal)	\
    ( (This)->lpVtbl -> get_NumChannels(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMAVolumeDisp_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LMAVolume;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DB31-38C5-11D5-91F6-00104BDB8FF9")
LMAVolume;
#endif
#endif /* __LMAVolumeLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


