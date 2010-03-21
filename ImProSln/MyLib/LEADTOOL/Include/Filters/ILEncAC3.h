

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Nov 05 12:34:01 2009
 */
/* Compiler settings for .\ILEncAC3.idl:
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


#ifndef __ILEncAC3_h__
#define __ILEncAC3_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILMAC3Encoder1_FWD_DEFINED__
#define __ILMAC3Encoder1_FWD_DEFINED__
typedef interface ILMAC3Encoder1 ILMAC3Encoder1;
#endif 	/* __ILMAC3Encoder1_FWD_DEFINED__ */


#ifndef __ILMAC3Encoder_FWD_DEFINED__
#define __ILMAC3Encoder_FWD_DEFINED__
typedef interface ILMAC3Encoder ILMAC3Encoder;
#endif 	/* __ILMAC3Encoder_FWD_DEFINED__ */


#ifndef __LMAC3Encoder_FWD_DEFINED__
#define __LMAC3Encoder_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMAC3Encoder LMAC3Encoder;
#else
typedef struct LMAC3Encoder LMAC3Encoder;
#endif /* __cplusplus */

#endif 	/* __LMAC3Encoder_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LMAC3EncoderLib_LIBRARY_DEFINED__
#define __LMAC3EncoderLib_LIBRARY_DEFINED__

/* library LMAC3EncoderLib */
/* [helpstring][version][uuid] */ 

#ifndef __ILMAC3ENCODER_H__
#define __ILMAC3ENCODER_H__
static const GUID CLSID_LMAC3Encoder              = {0xe2b7dd48, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMAC3Encoder1              = {0xe2b7dd4a, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMAC3EncoderPropertyPage	 = {0xe2b7dd49, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMAC3EncoderAboutPage     = {0xe2b7dd4b, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID LIBID_LMAC3EncoderLib	          = {0xe2b7dd4c, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMAC3Encoder               = {0xe2b7de31, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
#define LENCAC3_UNCHANGED       0x0000
#define LENCAC3_FORCE_MONO      0x0001
#define LENCAC3_FORCE_STEREO    0x0002
#define LENCAC3_FORCE_6CHANNELS 0x0006
#endif 

EXTERN_C const IID LIBID_LMAC3EncoderLib;

#ifndef __ILMAC3Encoder1_INTERFACE_DEFINED__
#define __ILMAC3Encoder1_INTERFACE_DEFINED__

/* interface ILMAC3Encoder1 */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ILMAC3Encoder1;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DD4A-38C5-11D5-91F6-00104BDB8FF9")
    ILMAC3Encoder1 : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OutputBitrate( 
            /* [retval][out] */ long *OutputBitrate) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OutputBitrate( 
            /* [in] */ long OutputBitrate) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OutputChannelsFlag( 
            /* [retval][out] */ long *OutputChannelFlag) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OutputChannelsFlag( 
            /* [in] */ long OutputChannelFlag) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SimulateSurround( 
            /* [retval][out] */ BOOL *SimulateSurround) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SimulateSurround( 
            /* [in] */ BOOL SimulateSurround) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMAC3Encoder1Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMAC3Encoder1 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMAC3Encoder1 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMAC3Encoder1 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMAC3Encoder1 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMAC3Encoder1 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMAC3Encoder1 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMAC3Encoder1 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutputBitrate )( 
            ILMAC3Encoder1 * This,
            /* [retval][out] */ long *OutputBitrate);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OutputBitrate )( 
            ILMAC3Encoder1 * This,
            /* [in] */ long OutputBitrate);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutputChannelsFlag )( 
            ILMAC3Encoder1 * This,
            /* [retval][out] */ long *OutputChannelFlag);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OutputChannelsFlag )( 
            ILMAC3Encoder1 * This,
            /* [in] */ long OutputChannelFlag);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SimulateSurround )( 
            ILMAC3Encoder1 * This,
            /* [retval][out] */ BOOL *SimulateSurround);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SimulateSurround )( 
            ILMAC3Encoder1 * This,
            /* [in] */ BOOL SimulateSurround);
        
        END_INTERFACE
    } ILMAC3Encoder1Vtbl;

    interface ILMAC3Encoder1
    {
        CONST_VTBL struct ILMAC3Encoder1Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMAC3Encoder1_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMAC3Encoder1_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMAC3Encoder1_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMAC3Encoder1_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMAC3Encoder1_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMAC3Encoder1_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMAC3Encoder1_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMAC3Encoder1_get_OutputBitrate(This,OutputBitrate)	\
    ( (This)->lpVtbl -> get_OutputBitrate(This,OutputBitrate) ) 

#define ILMAC3Encoder1_put_OutputBitrate(This,OutputBitrate)	\
    ( (This)->lpVtbl -> put_OutputBitrate(This,OutputBitrate) ) 

#define ILMAC3Encoder1_get_OutputChannelsFlag(This,OutputChannelFlag)	\
    ( (This)->lpVtbl -> get_OutputChannelsFlag(This,OutputChannelFlag) ) 

#define ILMAC3Encoder1_put_OutputChannelsFlag(This,OutputChannelFlag)	\
    ( (This)->lpVtbl -> put_OutputChannelsFlag(This,OutputChannelFlag) ) 

#define ILMAC3Encoder1_get_SimulateSurround(This,SimulateSurround)	\
    ( (This)->lpVtbl -> get_SimulateSurround(This,SimulateSurround) ) 

#define ILMAC3Encoder1_put_SimulateSurround(This,SimulateSurround)	\
    ( (This)->lpVtbl -> put_SimulateSurround(This,SimulateSurround) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMAC3Encoder1_INTERFACE_DEFINED__ */


#ifndef __ILMAC3Encoder_INTERFACE_DEFINED__
#define __ILMAC3Encoder_INTERFACE_DEFINED__

/* interface ILMAC3Encoder */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ILMAC3Encoder;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DE31-38C5-11D5-91F6-00104BDB8FF9")
    ILMAC3Encoder : public ILMAC3Encoder1
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ResetToDefaults( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMAC3EncoderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMAC3Encoder * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMAC3Encoder * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMAC3Encoder * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMAC3Encoder * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMAC3Encoder * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMAC3Encoder * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMAC3Encoder * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutputBitrate )( 
            ILMAC3Encoder * This,
            /* [retval][out] */ long *OutputBitrate);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OutputBitrate )( 
            ILMAC3Encoder * This,
            /* [in] */ long OutputBitrate);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutputChannelsFlag )( 
            ILMAC3Encoder * This,
            /* [retval][out] */ long *OutputChannelFlag);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OutputChannelsFlag )( 
            ILMAC3Encoder * This,
            /* [in] */ long OutputChannelFlag);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SimulateSurround )( 
            ILMAC3Encoder * This,
            /* [retval][out] */ BOOL *SimulateSurround);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SimulateSurround )( 
            ILMAC3Encoder * This,
            /* [in] */ BOOL SimulateSurround);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetToDefaults )( 
            ILMAC3Encoder * This);
        
        END_INTERFACE
    } ILMAC3EncoderVtbl;

    interface ILMAC3Encoder
    {
        CONST_VTBL struct ILMAC3EncoderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMAC3Encoder_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMAC3Encoder_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMAC3Encoder_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMAC3Encoder_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMAC3Encoder_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMAC3Encoder_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMAC3Encoder_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMAC3Encoder_get_OutputBitrate(This,OutputBitrate)	\
    ( (This)->lpVtbl -> get_OutputBitrate(This,OutputBitrate) ) 

#define ILMAC3Encoder_put_OutputBitrate(This,OutputBitrate)	\
    ( (This)->lpVtbl -> put_OutputBitrate(This,OutputBitrate) ) 

#define ILMAC3Encoder_get_OutputChannelsFlag(This,OutputChannelFlag)	\
    ( (This)->lpVtbl -> get_OutputChannelsFlag(This,OutputChannelFlag) ) 

#define ILMAC3Encoder_put_OutputChannelsFlag(This,OutputChannelFlag)	\
    ( (This)->lpVtbl -> put_OutputChannelsFlag(This,OutputChannelFlag) ) 

#define ILMAC3Encoder_get_SimulateSurround(This,SimulateSurround)	\
    ( (This)->lpVtbl -> get_SimulateSurround(This,SimulateSurround) ) 

#define ILMAC3Encoder_put_SimulateSurround(This,SimulateSurround)	\
    ( (This)->lpVtbl -> put_SimulateSurround(This,SimulateSurround) ) 


#define ILMAC3Encoder_ResetToDefaults(This)	\
    ( (This)->lpVtbl -> ResetToDefaults(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMAC3Encoder_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LMAC3Encoder;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DD48-38C5-11D5-91F6-00104BDB8FF9")
LMAC3Encoder;
#endif
#endif /* __LMAC3EncoderLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


