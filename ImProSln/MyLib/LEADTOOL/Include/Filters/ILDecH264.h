

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Dec 03 17:27:03 2009
 */
/* Compiler settings for .\ILDecH264.idl:
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


#ifndef __ILDecH264_h__
#define __ILDecH264_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILMH264DecoderOld1_FWD_DEFINED__
#define __ILMH264DecoderOld1_FWD_DEFINED__
typedef interface ILMH264DecoderOld1 ILMH264DecoderOld1;
#endif 	/* __ILMH264DecoderOld1_FWD_DEFINED__ */


#ifndef __ILMH264Decoder_FWD_DEFINED__
#define __ILMH264Decoder_FWD_DEFINED__
typedef interface ILMH264Decoder ILMH264Decoder;
#endif 	/* __ILMH264Decoder_FWD_DEFINED__ */


#ifndef __LMH264Decoder_FWD_DEFINED__
#define __LMH264Decoder_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMH264Decoder LMH264Decoder;
#else
typedef struct LMH264Decoder LMH264Decoder;
#endif /* __cplusplus */

#endif 	/* __LMH264Decoder_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LMH264DecoderLib_LIBRARY_DEFINED__
#define __LMH264DecoderLib_LIBRARY_DEFINED__

/* library LMH264DecoderLib */
/* [helpstring][version][uuid] */ 

typedef 
enum ltmmMediaEventCode_
    {	ltmmEC_Sample_Delivered	= 0xa000
    } 	ltmmMediaEventCode_;

typedef /* [public][public] */ 
enum __MIDL___MIDL_itf_ILDecH264_0000_0000_0001
    {	H264DecoderApiLevel_1	= 0
    } 	eH264DecoderApiLevel;

#ifndef __ILMH264Decoder_H__
#define __ILMH264Decoder_H__
static const GUID CLSID_LMH264Decoder                      = { 0xe2b7df25, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 }};
static const GUID CLSID_LMH264DecoderAbout                 = { 0xe2b7df26, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 }};
static const GUID CLSID_LMH264DecoderPropertiy             = { 0xe2b7df70, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 }};
static const GUID LIBID_LMH264DecoderLib                   = { 0xe2b7df71, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 }};
static const GUID IID_ILMH264Decoder_OLD1                  = { 0xe2b7df72, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 }};
static const GUID IID_ILMH264Decoder                       = { 0xe2b7df7b, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 }};
#endif 

 /* H264DecodinFlag_DecodeCorruptedStream:*/
 /* Play corrupted streams/files.*/
 /* When selected, the decoder will play corrupted streams/files at the expense of processing power / speed. */

 /* H264DecodinFlag_FillFrameGaps:*/
 /* Display corrupted data as gray region. */ 
 /* When selected, corrupted data will be displayed as a gray region, otherwise, the previous frame region will be used.*/

 /* H264DecodinFlag_DisplayGrayOnError:*/
 /* Replace missing frames with previous frame. */
 /* When selected, missing frames from the stream will be replaced using the previous frame.  This option may provide jerky playback, and is not recommended.*/

typedef /* [public] */ 
enum __MIDL___MIDL_itf_ILDecH264_0000_0000_0002
    {	H264DecodingFlag_DecodeCorruptedStream	= 0x1,
	H264DecodingFlag_FillFrameGaps	= 0x2,
	H264DecodingFlag_DisplayGrayOnError	= 0x4,
	H264DecodingFlag_UseOneThread	= 0x8
    } 	eH264DecodingFlag;


EXTERN_C const IID LIBID_LMH264DecoderLib;

#ifndef __ILMH264DecoderOld1_INTERFACE_DEFINED__
#define __ILMH264DecoderOld1_INTERFACE_DEFINED__

/* interface ILMH264DecoderOld1 */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ILMH264DecoderOld1;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DF72-38C5-11D5-91F6-00104BDB8FF9")
    ILMH264DecoderOld1 : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteToRegistry( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DecodingOptions( 
            /* [retval][out] */ long *pValue) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DecodingOptions( 
            /* [in] */ long Value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMH264DecoderOld1Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMH264DecoderOld1 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMH264DecoderOld1 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMH264DecoderOld1 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMH264DecoderOld1 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMH264DecoderOld1 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMH264DecoderOld1 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMH264DecoderOld1 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteToRegistry )( 
            ILMH264DecoderOld1 * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DecodingOptions )( 
            ILMH264DecoderOld1 * This,
            /* [retval][out] */ long *pValue);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DecodingOptions )( 
            ILMH264DecoderOld1 * This,
            /* [in] */ long Value);
        
        END_INTERFACE
    } ILMH264DecoderOld1Vtbl;

    interface ILMH264DecoderOld1
    {
        CONST_VTBL struct ILMH264DecoderOld1Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMH264DecoderOld1_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMH264DecoderOld1_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMH264DecoderOld1_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMH264DecoderOld1_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMH264DecoderOld1_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMH264DecoderOld1_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMH264DecoderOld1_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMH264DecoderOld1_WriteToRegistry(This)	\
    ( (This)->lpVtbl -> WriteToRegistry(This) ) 

#define ILMH264DecoderOld1_get_DecodingOptions(This,pValue)	\
    ( (This)->lpVtbl -> get_DecodingOptions(This,pValue) ) 

#define ILMH264DecoderOld1_put_DecodingOptions(This,Value)	\
    ( (This)->lpVtbl -> put_DecodingOptions(This,Value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMH264DecoderOld1_INTERFACE_DEFINED__ */


#ifndef __ILMH264Decoder_INTERFACE_DEFINED__
#define __ILMH264Decoder_INTERFACE_DEFINED__

/* interface ILMH264Decoder */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ILMH264Decoder;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DF7B-38C5-11D5-91F6-00104BDB8FF9")
    ILMH264Decoder : public ILMH264DecoderOld1
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DeliveredFrameNotificationInterval( 
            /* [retval][out] */ double *pNotifyInterval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DeliveredFrameNotificationInterval( 
            /* [in] */ double NotifyInterval) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ResetToDefaultsEx( 
            /* [in] */ eH264DecoderApiLevel ApiLevel) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMH264DecoderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMH264Decoder * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMH264Decoder * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMH264Decoder * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMH264Decoder * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMH264Decoder * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMH264Decoder * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMH264Decoder * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteToRegistry )( 
            ILMH264Decoder * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DecodingOptions )( 
            ILMH264Decoder * This,
            /* [retval][out] */ long *pValue);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DecodingOptions )( 
            ILMH264Decoder * This,
            /* [in] */ long Value);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DeliveredFrameNotificationInterval )( 
            ILMH264Decoder * This,
            /* [retval][out] */ double *pNotifyInterval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DeliveredFrameNotificationInterval )( 
            ILMH264Decoder * This,
            /* [in] */ double NotifyInterval);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetToDefaultsEx )( 
            ILMH264Decoder * This,
            /* [in] */ eH264DecoderApiLevel ApiLevel);
        
        END_INTERFACE
    } ILMH264DecoderVtbl;

    interface ILMH264Decoder
    {
        CONST_VTBL struct ILMH264DecoderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMH264Decoder_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMH264Decoder_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMH264Decoder_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMH264Decoder_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMH264Decoder_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMH264Decoder_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMH264Decoder_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMH264Decoder_WriteToRegistry(This)	\
    ( (This)->lpVtbl -> WriteToRegistry(This) ) 

#define ILMH264Decoder_get_DecodingOptions(This,pValue)	\
    ( (This)->lpVtbl -> get_DecodingOptions(This,pValue) ) 

#define ILMH264Decoder_put_DecodingOptions(This,Value)	\
    ( (This)->lpVtbl -> put_DecodingOptions(This,Value) ) 


#define ILMH264Decoder_get_DeliveredFrameNotificationInterval(This,pNotifyInterval)	\
    ( (This)->lpVtbl -> get_DeliveredFrameNotificationInterval(This,pNotifyInterval) ) 

#define ILMH264Decoder_put_DeliveredFrameNotificationInterval(This,NotifyInterval)	\
    ( (This)->lpVtbl -> put_DeliveredFrameNotificationInterval(This,NotifyInterval) ) 

#define ILMH264Decoder_ResetToDefaultsEx(This,ApiLevel)	\
    ( (This)->lpVtbl -> ResetToDefaultsEx(This,ApiLevel) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMH264Decoder_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LMH264Decoder;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DF25-38C5-11D5-91F6-00104BDB8FF9")
LMH264Decoder;
#endif
#endif /* __LMH264DecoderLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


