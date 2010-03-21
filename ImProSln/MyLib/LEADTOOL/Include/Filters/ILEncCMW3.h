

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Nov 05 12:44:01 2009
 */
/* Compiler settings for .\ILEncCMW2.idl:
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


#ifndef __ILEncCMW3_h__
#define __ILEncCMW3_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILMCMW2Encoder_FWD_DEFINED__
#define __ILMCMW2Encoder_FWD_DEFINED__
typedef interface ILMCMW2Encoder ILMCMW2Encoder;
#endif 	/* __ILMCMW2Encoder_FWD_DEFINED__ */


#ifndef __LMCMW2Encoder_FWD_DEFINED__
#define __LMCMW2Encoder_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMCMW2Encoder LMCMW2Encoder;
#else
typedef struct LMCMW2Encoder LMCMW2Encoder;
#endif /* __cplusplus */

#endif 	/* __LMCMW2Encoder_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LMCMW2EncoderLib_LIBRARY_DEFINED__
#define __LMCMW2EncoderLib_LIBRARY_DEFINED__

/* library LMCMW2EncoderLib */
/* [helpstring][version][uuid] */ 

#ifndef __ILMCMW2ENCODER_H__
#define __ILMCMW2ENCODER_H__
static const GUID CLSID_LMCMW2Encoder            = { 0xe2b7dccc, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 }};
static const GUID CLSID_LMCMW2EncoderProperty    = { 0xe2b7dccd, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 }};
static const GUID LIBID_LMCMW2EncoderLib         = { 0xe2b7dcce, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 }};
static const GUID   IID_ILMCMW2Encoder           = { 0xe2b7dccf, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 }};
static const GUID CLSID_LMCMW2Decoder            = { 0xe2b7dcd0, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 }};
static const GUID CLSID_LMCMW2DecoderProperty    = { 0xe2b7dcd1, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 }};
#endif 
typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_ILEncCMW2_0000_0000_0001
    {	PerfectQuality_1	= 18,
	PerfectQuality_2	= 24,
	QualityFarMoreImportantThanSize	= 30,
	QualityMoreImportantThanSize	= 40,
	QualityAndSizeAreEquallyImportant	= 55,
	SizeMoreImportantThanQuality_1	= 70,
	SizeMoreImportantThanQuality_2	= 90,
	HighCompressionKeepQuality	= 110,
	HighCompression	= 140,
	HighcompressionFast	= 180,
	HypercompressionFast	= 220,
	Custom	= 18
    } 	CMWQUALITYFACTOR;


EXTERN_C const IID LIBID_LMCMW2EncoderLib;

#ifndef __ILMCMW2Encoder_INTERFACE_DEFINED__
#define __ILMCMW2Encoder_INTERFACE_DEFINED__

/* interface ILMCMW2Encoder */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ILMCMW2Encoder;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DCCF-38C5-11D5-91F6-00104BDB8FF9")
    ILMCMW2Encoder : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_QualityFactor( 
            /* [retval][out] */ CMWQUALITYFACTOR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_QualityFactor( 
            /* [in] */ CMWQUALITYFACTOR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CompressionRatio( 
            /* [retval][out] */ DWORD *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CompressionRatio( 
            /* [in] */ DWORD newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AvgTimePerFrame( 
            /* [retval][out] */ DWORD *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FrameWidth( 
            /* [retval][out] */ DWORD *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FrameHeight( 
            /* [retval][out] */ DWORD *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BitsPerPixel( 
            /* [retval][out] */ DWORD *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMCMW2EncoderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMCMW2Encoder * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMCMW2Encoder * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMCMW2Encoder * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMCMW2Encoder * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMCMW2Encoder * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMCMW2Encoder * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMCMW2Encoder * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_QualityFactor )( 
            ILMCMW2Encoder * This,
            /* [retval][out] */ CMWQUALITYFACTOR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_QualityFactor )( 
            ILMCMW2Encoder * This,
            /* [in] */ CMWQUALITYFACTOR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CompressionRatio )( 
            ILMCMW2Encoder * This,
            /* [retval][out] */ DWORD *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CompressionRatio )( 
            ILMCMW2Encoder * This,
            /* [in] */ DWORD newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AvgTimePerFrame )( 
            ILMCMW2Encoder * This,
            /* [retval][out] */ DWORD *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FrameWidth )( 
            ILMCMW2Encoder * This,
            /* [retval][out] */ DWORD *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FrameHeight )( 
            ILMCMW2Encoder * This,
            /* [retval][out] */ DWORD *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BitsPerPixel )( 
            ILMCMW2Encoder * This,
            /* [retval][out] */ DWORD *pVal);
        
        END_INTERFACE
    } ILMCMW2EncoderVtbl;

    interface ILMCMW2Encoder
    {
        CONST_VTBL struct ILMCMW2EncoderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMCMW2Encoder_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMCMW2Encoder_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMCMW2Encoder_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMCMW2Encoder_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMCMW2Encoder_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMCMW2Encoder_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMCMW2Encoder_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMCMW2Encoder_get_QualityFactor(This,pVal)	\
    ( (This)->lpVtbl -> get_QualityFactor(This,pVal) ) 

#define ILMCMW2Encoder_put_QualityFactor(This,newVal)	\
    ( (This)->lpVtbl -> put_QualityFactor(This,newVal) ) 

#define ILMCMW2Encoder_get_CompressionRatio(This,pVal)	\
    ( (This)->lpVtbl -> get_CompressionRatio(This,pVal) ) 

#define ILMCMW2Encoder_put_CompressionRatio(This,newVal)	\
    ( (This)->lpVtbl -> put_CompressionRatio(This,newVal) ) 

#define ILMCMW2Encoder_get_AvgTimePerFrame(This,pVal)	\
    ( (This)->lpVtbl -> get_AvgTimePerFrame(This,pVal) ) 

#define ILMCMW2Encoder_get_FrameWidth(This,pVal)	\
    ( (This)->lpVtbl -> get_FrameWidth(This,pVal) ) 

#define ILMCMW2Encoder_get_FrameHeight(This,pVal)	\
    ( (This)->lpVtbl -> get_FrameHeight(This,pVal) ) 

#define ILMCMW2Encoder_get_BitsPerPixel(This,pVal)	\
    ( (This)->lpVtbl -> get_BitsPerPixel(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMCMW2Encoder_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LMCMW2Encoder;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DCCC-38C5-11D5-91F6-00104BDB8FF9")
LMCMW2Encoder;
#endif
#endif /* __LMCMW2EncoderLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


