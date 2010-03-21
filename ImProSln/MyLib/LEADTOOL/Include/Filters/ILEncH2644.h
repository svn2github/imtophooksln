

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Fri Dec 18 13:04:26 2009
 */
/* Compiler settings for .\ILEncH264.idl:
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


#ifndef __ILEncH2644_h__
#define __ILEncH2644_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILMH264EncoderOld1_FWD_DEFINED__
#define __ILMH264EncoderOld1_FWD_DEFINED__
typedef interface ILMH264EncoderOld1 ILMH264EncoderOld1;
#endif 	/* __ILMH264EncoderOld1_FWD_DEFINED__ */


#ifndef __ILMH264EncoderOld2_FWD_DEFINED__
#define __ILMH264EncoderOld2_FWD_DEFINED__
typedef interface ILMH264EncoderOld2 ILMH264EncoderOld2;
#endif 	/* __ILMH264EncoderOld2_FWD_DEFINED__ */


#ifndef __ILMH264EncoderOld3_FWD_DEFINED__
#define __ILMH264EncoderOld3_FWD_DEFINED__
typedef interface ILMH264EncoderOld3 ILMH264EncoderOld3;
#endif 	/* __ILMH264EncoderOld3_FWD_DEFINED__ */


#ifndef __ILMH264EncoderOld4_FWD_DEFINED__
#define __ILMH264EncoderOld4_FWD_DEFINED__
typedef interface ILMH264EncoderOld4 ILMH264EncoderOld4;
#endif 	/* __ILMH264EncoderOld4_FWD_DEFINED__ */


#ifndef __ILMH264Encoder_FWD_DEFINED__
#define __ILMH264Encoder_FWD_DEFINED__
typedef interface ILMH264Encoder ILMH264Encoder;
#endif 	/* __ILMH264Encoder_FWD_DEFINED__ */


#ifndef __LMH264Encoder_FWD_DEFINED__
#define __LMH264Encoder_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMH264Encoder LMH264Encoder;
#else
typedef struct LMH264Encoder LMH264Encoder;
#endif /* __cplusplus */

#endif 	/* __LMH264Encoder_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LMH264EncoderLib_LIBRARY_DEFINED__
#define __LMH264EncoderLib_LIBRARY_DEFINED__

/* library LMH264EncoderLib */
/* [helpstring][version][uuid] */ 

#ifndef __ILMH264ENCODER4_H__
#define __ILMH264ENCODER4_H__
static const GUID CLSID_LMH264Encoder                       = { 0xe2b7df52, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 }};
static const GUID CLSID_LMH264EncoderPropertiy              = { 0xe2b7df53, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 }};
static const GUID CLSID_LMH264EncoderAbout                  = { 0xe2b7df54, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 }};
static const GUID LIBID_LMH264EncoderLib                    = { 0xe2b7df55, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 }};
static const GUID IID_ILMH264EncoderOld1                   = { 0xe2b7df56, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 }};
static const GUID IID_ILMH264EncoderOld2                   = { 0xe2b7de3b, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 }};
static const GUID IID_ILMH264EncoderOld3                   = { 0xe2b7df79, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 }};
static const GUID IID_ILMH264EncoderOld4                   = { 0xe2b7df7a, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 }};
static const GUID IID_ILMH264Encoder                       = { 0xe2b7df7c, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 }};
#endif 
typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_ILEncH264_0000_0000_0001
    {	H264SYMBOL_CAVLC	= 0,
	H264SYMBOL_CABAC	= 1
    } 	eH264SYMBOLMODE;

 /* H264FRESTRICTFORMATS_NONE   No restriction, enumerate all available output formats    */
 /* H264RESTRICTFORMATS_AVC1    List Main and Baseline profiles AVC1 formats only         */
typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_ILEncH264_0000_0000_0002
    {	H264FRESTRICTFORMATS_NONE	= 0,
	H264RESTRICTFORMATS_AVC1	= 1
    } 	eH264RESTRICTFORMATS;

 /* H264FORMAT_AUTO                                                  */
 /* H264FORMAT_STANDARD_H264         Main profile                    */
 /* H264FORMAT_STANDARD_AVC1         Main profile / Flash            */
 /* H264FORMAT_LEAD                  Main profile                    */
 /* H264FORMAT_IPOD                  Baseline profile                */
 /* H264FORMAT_PSP                   Main profile                    */
 /* H264FORMAT_BASELINE_H264         Baseline profile                */
 /* H264FORMAT_BASELINE_AVC1         Baseline profile                */
 /* H264FORMAT_BASELINE_RTP          RTP Packetized Baseline profile */
 /* H264FORMAT_MAIN_RTP              RTP Packetized Main profile     */
typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_ILEncH264_0000_0000_0003
    {	H264FORMAT_AUTO	= 0,
	H264FORMAT_STANDARD_H264	= 1,
	H264FORMAT_STANDARD_AVC1	= 2,
	H264FORMAT_LEAD	= 3,
	H264FORMAT_IPOD	= 4,
	H264FORMAT_PSP	= 5,
	H264FORMAT_BASELINE_H264	= 6,
	H264FORMAT_BASELINE_AVC1	= 7,
	H264FORMAT_BASELINE_RTP	= 8,
	H264FORMAT_MAIN_RTP	= 9
    } 	eH264OUTPUTFORMAT;

typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_ILEncH264_0000_0000_0004
    {	H264SPEED_1	= 1,
	H264SPEED_2	= 2,
	H264SPEED_3	= 3,
	H264SPEED_4	= 4
    } 	eH264ENCODINGSPEED;

typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_ILEncH264_0000_0000_0005
    {	H264THREAD_AUTO	= 0,
	H264THREAD_1	= 1,
	H264THREAD_2	= 2,
	H264THREAD_3	= 3,
	H264THREAD_4	= 4,
	H264THREAD_5	= 5,
	H264THREAD_6	= 6,
	H264THREAD_7	= 7,
	H264THREAD_8	= 8,
	H264THREAD_9	= 9,
	H264THREAD_10	= 10,
	H264THREAD_11	= 11,
	H264THREAD_12	= 12,
	H264THREAD_13	= 13,
	H264THREAD_14	= 14,
	H264THREAD_15	= 15,
	H264THREAD_16	= 16
    } 	eH264ENCODINGTHREADS;

typedef /* [public][public] */ 
enum __MIDL___MIDL_itf_ILEncH264_0000_0000_0006
    {	H264_APILEVEL_1	= 0
    } 	eH264APILEVEL;

typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_ILEncH264_0000_0000_0007
    {	H264INTERVALUNIT_PFRAME	= 0,
	H264INTERVALUNIT_FRAME	= 1
    } 	eH264FRAMEINTERVALUNIT;


EXTERN_C const IID LIBID_LMH264EncoderLib;

#ifndef __ILMH264EncoderOld1_INTERFACE_DEFINED__
#define __ILMH264EncoderOld1_INTERFACE_DEFINED__

/* interface ILMH264EncoderOld1 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILMH264EncoderOld1;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DF56-38C5-11D5-91F6-00104BDB8FF9")
    ILMH264EncoderOld1 : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_QualityFactor( 
            /* [retval][out] */ long *pQualityFactor) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_QualityFactor( 
            /* [in] */ long QualityFactor) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IFrameInterval( 
            /* [retval][out] */ long *pIFrameInterval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_IFrameInterval( 
            /* [in] */ long IFrameInterval) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PFrameInterval( 
            /* [retval][out] */ long *pPFrameInterval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PFrameInterval( 
            /* [in] */ long PFrameInterval) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SymbolMode( 
            /* [retval][out] */ eH264SYMBOLMODE *pSymbolMode) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SymbolMode( 
            /* [in] */ eH264SYMBOLMODE SymbolMode) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FrameRate( 
            /* [retval][out] */ float *pFrameRate) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FrameRate( 
            /* [in] */ float FrameRate) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EnableRateControl( 
            /* [retval][out] */ VARIANT_BOOL *pEnableRateControl) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_EnableRateControl( 
            /* [in] */ VARIANT_BOOL EnableRateControl) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BitRate( 
            /* [retval][out] */ long *pBitRate) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_BitRate( 
            /* [in] */ long BitRate) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EncodingSpeed( 
            /* [retval][out] */ eH264ENCODINGSPEED *pSpeed) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_EncodingSpeed( 
            /* [in] */ eH264ENCODINGSPEED Speed) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EncodingThreads( 
            /* [retval][out] */ eH264ENCODINGTHREADS *pThreads) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_EncodingThreads( 
            /* [in] */ eH264ENCODINGTHREADS Threads) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OutputFormat( 
            /* [retval][out] */ eH264OUTPUTFORMAT *pFormat) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OutputFormat( 
            /* [in] */ eH264OUTPUTFORMAT Format) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EnableSuperCompression( 
            /* [retval][out] */ VARIANT_BOOL *bSuperCompression) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_EnableSuperCompression( 
            /* [in] */ VARIANT_BOOL bSuperCompression) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TimeQualityFactorFileName( 
            /* [retval][out] */ BSTR *pFileName) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_TimeQualityFactorFileName( 
            /* [in] */ BSTR FileName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteToRegistry( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMH264EncoderOld1Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMH264EncoderOld1 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMH264EncoderOld1 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMH264EncoderOld1 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMH264EncoderOld1 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMH264EncoderOld1 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMH264EncoderOld1 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMH264EncoderOld1 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_QualityFactor )( 
            ILMH264EncoderOld1 * This,
            /* [retval][out] */ long *pQualityFactor);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_QualityFactor )( 
            ILMH264EncoderOld1 * This,
            /* [in] */ long QualityFactor);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IFrameInterval )( 
            ILMH264EncoderOld1 * This,
            /* [retval][out] */ long *pIFrameInterval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IFrameInterval )( 
            ILMH264EncoderOld1 * This,
            /* [in] */ long IFrameInterval);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PFrameInterval )( 
            ILMH264EncoderOld1 * This,
            /* [retval][out] */ long *pPFrameInterval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PFrameInterval )( 
            ILMH264EncoderOld1 * This,
            /* [in] */ long PFrameInterval);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SymbolMode )( 
            ILMH264EncoderOld1 * This,
            /* [retval][out] */ eH264SYMBOLMODE *pSymbolMode);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SymbolMode )( 
            ILMH264EncoderOld1 * This,
            /* [in] */ eH264SYMBOLMODE SymbolMode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FrameRate )( 
            ILMH264EncoderOld1 * This,
            /* [retval][out] */ float *pFrameRate);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FrameRate )( 
            ILMH264EncoderOld1 * This,
            /* [in] */ float FrameRate);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableRateControl )( 
            ILMH264EncoderOld1 * This,
            /* [retval][out] */ VARIANT_BOOL *pEnableRateControl);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableRateControl )( 
            ILMH264EncoderOld1 * This,
            /* [in] */ VARIANT_BOOL EnableRateControl);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BitRate )( 
            ILMH264EncoderOld1 * This,
            /* [retval][out] */ long *pBitRate);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BitRate )( 
            ILMH264EncoderOld1 * This,
            /* [in] */ long BitRate);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EncodingSpeed )( 
            ILMH264EncoderOld1 * This,
            /* [retval][out] */ eH264ENCODINGSPEED *pSpeed);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EncodingSpeed )( 
            ILMH264EncoderOld1 * This,
            /* [in] */ eH264ENCODINGSPEED Speed);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EncodingThreads )( 
            ILMH264EncoderOld1 * This,
            /* [retval][out] */ eH264ENCODINGTHREADS *pThreads);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EncodingThreads )( 
            ILMH264EncoderOld1 * This,
            /* [in] */ eH264ENCODINGTHREADS Threads);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutputFormat )( 
            ILMH264EncoderOld1 * This,
            /* [retval][out] */ eH264OUTPUTFORMAT *pFormat);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OutputFormat )( 
            ILMH264EncoderOld1 * This,
            /* [in] */ eH264OUTPUTFORMAT Format);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableSuperCompression )( 
            ILMH264EncoderOld1 * This,
            /* [retval][out] */ VARIANT_BOOL *bSuperCompression);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableSuperCompression )( 
            ILMH264EncoderOld1 * This,
            /* [in] */ VARIANT_BOOL bSuperCompression);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TimeQualityFactorFileName )( 
            ILMH264EncoderOld1 * This,
            /* [retval][out] */ BSTR *pFileName);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TimeQualityFactorFileName )( 
            ILMH264EncoderOld1 * This,
            /* [in] */ BSTR FileName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteToRegistry )( 
            ILMH264EncoderOld1 * This);
        
        END_INTERFACE
    } ILMH264EncoderOld1Vtbl;

    interface ILMH264EncoderOld1
    {
        CONST_VTBL struct ILMH264EncoderOld1Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMH264EncoderOld1_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMH264EncoderOld1_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMH264EncoderOld1_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMH264EncoderOld1_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMH264EncoderOld1_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMH264EncoderOld1_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMH264EncoderOld1_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMH264EncoderOld1_get_QualityFactor(This,pQualityFactor)	\
    ( (This)->lpVtbl -> get_QualityFactor(This,pQualityFactor) ) 

#define ILMH264EncoderOld1_put_QualityFactor(This,QualityFactor)	\
    ( (This)->lpVtbl -> put_QualityFactor(This,QualityFactor) ) 

#define ILMH264EncoderOld1_get_IFrameInterval(This,pIFrameInterval)	\
    ( (This)->lpVtbl -> get_IFrameInterval(This,pIFrameInterval) ) 

#define ILMH264EncoderOld1_put_IFrameInterval(This,IFrameInterval)	\
    ( (This)->lpVtbl -> put_IFrameInterval(This,IFrameInterval) ) 

#define ILMH264EncoderOld1_get_PFrameInterval(This,pPFrameInterval)	\
    ( (This)->lpVtbl -> get_PFrameInterval(This,pPFrameInterval) ) 

#define ILMH264EncoderOld1_put_PFrameInterval(This,PFrameInterval)	\
    ( (This)->lpVtbl -> put_PFrameInterval(This,PFrameInterval) ) 

#define ILMH264EncoderOld1_get_SymbolMode(This,pSymbolMode)	\
    ( (This)->lpVtbl -> get_SymbolMode(This,pSymbolMode) ) 

#define ILMH264EncoderOld1_put_SymbolMode(This,SymbolMode)	\
    ( (This)->lpVtbl -> put_SymbolMode(This,SymbolMode) ) 

#define ILMH264EncoderOld1_get_FrameRate(This,pFrameRate)	\
    ( (This)->lpVtbl -> get_FrameRate(This,pFrameRate) ) 

#define ILMH264EncoderOld1_put_FrameRate(This,FrameRate)	\
    ( (This)->lpVtbl -> put_FrameRate(This,FrameRate) ) 

#define ILMH264EncoderOld1_get_EnableRateControl(This,pEnableRateControl)	\
    ( (This)->lpVtbl -> get_EnableRateControl(This,pEnableRateControl) ) 

#define ILMH264EncoderOld1_put_EnableRateControl(This,EnableRateControl)	\
    ( (This)->lpVtbl -> put_EnableRateControl(This,EnableRateControl) ) 

#define ILMH264EncoderOld1_get_BitRate(This,pBitRate)	\
    ( (This)->lpVtbl -> get_BitRate(This,pBitRate) ) 

#define ILMH264EncoderOld1_put_BitRate(This,BitRate)	\
    ( (This)->lpVtbl -> put_BitRate(This,BitRate) ) 

#define ILMH264EncoderOld1_get_EncodingSpeed(This,pSpeed)	\
    ( (This)->lpVtbl -> get_EncodingSpeed(This,pSpeed) ) 

#define ILMH264EncoderOld1_put_EncodingSpeed(This,Speed)	\
    ( (This)->lpVtbl -> put_EncodingSpeed(This,Speed) ) 

#define ILMH264EncoderOld1_get_EncodingThreads(This,pThreads)	\
    ( (This)->lpVtbl -> get_EncodingThreads(This,pThreads) ) 

#define ILMH264EncoderOld1_put_EncodingThreads(This,Threads)	\
    ( (This)->lpVtbl -> put_EncodingThreads(This,Threads) ) 

#define ILMH264EncoderOld1_get_OutputFormat(This,pFormat)	\
    ( (This)->lpVtbl -> get_OutputFormat(This,pFormat) ) 

#define ILMH264EncoderOld1_put_OutputFormat(This,Format)	\
    ( (This)->lpVtbl -> put_OutputFormat(This,Format) ) 

#define ILMH264EncoderOld1_get_EnableSuperCompression(This,bSuperCompression)	\
    ( (This)->lpVtbl -> get_EnableSuperCompression(This,bSuperCompression) ) 

#define ILMH264EncoderOld1_put_EnableSuperCompression(This,bSuperCompression)	\
    ( (This)->lpVtbl -> put_EnableSuperCompression(This,bSuperCompression) ) 

#define ILMH264EncoderOld1_get_TimeQualityFactorFileName(This,pFileName)	\
    ( (This)->lpVtbl -> get_TimeQualityFactorFileName(This,pFileName) ) 

#define ILMH264EncoderOld1_put_TimeQualityFactorFileName(This,FileName)	\
    ( (This)->lpVtbl -> put_TimeQualityFactorFileName(This,FileName) ) 

#define ILMH264EncoderOld1_WriteToRegistry(This)	\
    ( (This)->lpVtbl -> WriteToRegistry(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMH264EncoderOld1_INTERFACE_DEFINED__ */


#ifndef __ILMH264EncoderOld2_INTERFACE_DEFINED__
#define __ILMH264EncoderOld2_INTERFACE_DEFINED__

/* interface ILMH264EncoderOld2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILMH264EncoderOld2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DE3B-38C5-11D5-91F6-00104BDB8FF9")
    ILMH264EncoderOld2 : public ILMH264EncoderOld1
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RestrictAvailableOutputFormats( 
            /* [retval][out] */ eH264RESTRICTFORMATS *pRestictFormats) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RestrictAvailableOutputFormats( 
            /* [in] */ eH264RESTRICTFORMATS RestrictFormats) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMH264EncoderOld2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMH264EncoderOld2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMH264EncoderOld2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMH264EncoderOld2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMH264EncoderOld2 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMH264EncoderOld2 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMH264EncoderOld2 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMH264EncoderOld2 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_QualityFactor )( 
            ILMH264EncoderOld2 * This,
            /* [retval][out] */ long *pQualityFactor);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_QualityFactor )( 
            ILMH264EncoderOld2 * This,
            /* [in] */ long QualityFactor);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IFrameInterval )( 
            ILMH264EncoderOld2 * This,
            /* [retval][out] */ long *pIFrameInterval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IFrameInterval )( 
            ILMH264EncoderOld2 * This,
            /* [in] */ long IFrameInterval);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PFrameInterval )( 
            ILMH264EncoderOld2 * This,
            /* [retval][out] */ long *pPFrameInterval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PFrameInterval )( 
            ILMH264EncoderOld2 * This,
            /* [in] */ long PFrameInterval);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SymbolMode )( 
            ILMH264EncoderOld2 * This,
            /* [retval][out] */ eH264SYMBOLMODE *pSymbolMode);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SymbolMode )( 
            ILMH264EncoderOld2 * This,
            /* [in] */ eH264SYMBOLMODE SymbolMode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FrameRate )( 
            ILMH264EncoderOld2 * This,
            /* [retval][out] */ float *pFrameRate);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FrameRate )( 
            ILMH264EncoderOld2 * This,
            /* [in] */ float FrameRate);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableRateControl )( 
            ILMH264EncoderOld2 * This,
            /* [retval][out] */ VARIANT_BOOL *pEnableRateControl);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableRateControl )( 
            ILMH264EncoderOld2 * This,
            /* [in] */ VARIANT_BOOL EnableRateControl);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BitRate )( 
            ILMH264EncoderOld2 * This,
            /* [retval][out] */ long *pBitRate);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BitRate )( 
            ILMH264EncoderOld2 * This,
            /* [in] */ long BitRate);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EncodingSpeed )( 
            ILMH264EncoderOld2 * This,
            /* [retval][out] */ eH264ENCODINGSPEED *pSpeed);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EncodingSpeed )( 
            ILMH264EncoderOld2 * This,
            /* [in] */ eH264ENCODINGSPEED Speed);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EncodingThreads )( 
            ILMH264EncoderOld2 * This,
            /* [retval][out] */ eH264ENCODINGTHREADS *pThreads);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EncodingThreads )( 
            ILMH264EncoderOld2 * This,
            /* [in] */ eH264ENCODINGTHREADS Threads);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutputFormat )( 
            ILMH264EncoderOld2 * This,
            /* [retval][out] */ eH264OUTPUTFORMAT *pFormat);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OutputFormat )( 
            ILMH264EncoderOld2 * This,
            /* [in] */ eH264OUTPUTFORMAT Format);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableSuperCompression )( 
            ILMH264EncoderOld2 * This,
            /* [retval][out] */ VARIANT_BOOL *bSuperCompression);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableSuperCompression )( 
            ILMH264EncoderOld2 * This,
            /* [in] */ VARIANT_BOOL bSuperCompression);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TimeQualityFactorFileName )( 
            ILMH264EncoderOld2 * This,
            /* [retval][out] */ BSTR *pFileName);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TimeQualityFactorFileName )( 
            ILMH264EncoderOld2 * This,
            /* [in] */ BSTR FileName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteToRegistry )( 
            ILMH264EncoderOld2 * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RestrictAvailableOutputFormats )( 
            ILMH264EncoderOld2 * This,
            /* [retval][out] */ eH264RESTRICTFORMATS *pRestictFormats);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RestrictAvailableOutputFormats )( 
            ILMH264EncoderOld2 * This,
            /* [in] */ eH264RESTRICTFORMATS RestrictFormats);
        
        END_INTERFACE
    } ILMH264EncoderOld2Vtbl;

    interface ILMH264EncoderOld2
    {
        CONST_VTBL struct ILMH264EncoderOld2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMH264EncoderOld2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMH264EncoderOld2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMH264EncoderOld2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMH264EncoderOld2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMH264EncoderOld2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMH264EncoderOld2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMH264EncoderOld2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMH264EncoderOld2_get_QualityFactor(This,pQualityFactor)	\
    ( (This)->lpVtbl -> get_QualityFactor(This,pQualityFactor) ) 

#define ILMH264EncoderOld2_put_QualityFactor(This,QualityFactor)	\
    ( (This)->lpVtbl -> put_QualityFactor(This,QualityFactor) ) 

#define ILMH264EncoderOld2_get_IFrameInterval(This,pIFrameInterval)	\
    ( (This)->lpVtbl -> get_IFrameInterval(This,pIFrameInterval) ) 

#define ILMH264EncoderOld2_put_IFrameInterval(This,IFrameInterval)	\
    ( (This)->lpVtbl -> put_IFrameInterval(This,IFrameInterval) ) 

#define ILMH264EncoderOld2_get_PFrameInterval(This,pPFrameInterval)	\
    ( (This)->lpVtbl -> get_PFrameInterval(This,pPFrameInterval) ) 

#define ILMH264EncoderOld2_put_PFrameInterval(This,PFrameInterval)	\
    ( (This)->lpVtbl -> put_PFrameInterval(This,PFrameInterval) ) 

#define ILMH264EncoderOld2_get_SymbolMode(This,pSymbolMode)	\
    ( (This)->lpVtbl -> get_SymbolMode(This,pSymbolMode) ) 

#define ILMH264EncoderOld2_put_SymbolMode(This,SymbolMode)	\
    ( (This)->lpVtbl -> put_SymbolMode(This,SymbolMode) ) 

#define ILMH264EncoderOld2_get_FrameRate(This,pFrameRate)	\
    ( (This)->lpVtbl -> get_FrameRate(This,pFrameRate) ) 

#define ILMH264EncoderOld2_put_FrameRate(This,FrameRate)	\
    ( (This)->lpVtbl -> put_FrameRate(This,FrameRate) ) 

#define ILMH264EncoderOld2_get_EnableRateControl(This,pEnableRateControl)	\
    ( (This)->lpVtbl -> get_EnableRateControl(This,pEnableRateControl) ) 

#define ILMH264EncoderOld2_put_EnableRateControl(This,EnableRateControl)	\
    ( (This)->lpVtbl -> put_EnableRateControl(This,EnableRateControl) ) 

#define ILMH264EncoderOld2_get_BitRate(This,pBitRate)	\
    ( (This)->lpVtbl -> get_BitRate(This,pBitRate) ) 

#define ILMH264EncoderOld2_put_BitRate(This,BitRate)	\
    ( (This)->lpVtbl -> put_BitRate(This,BitRate) ) 

#define ILMH264EncoderOld2_get_EncodingSpeed(This,pSpeed)	\
    ( (This)->lpVtbl -> get_EncodingSpeed(This,pSpeed) ) 

#define ILMH264EncoderOld2_put_EncodingSpeed(This,Speed)	\
    ( (This)->lpVtbl -> put_EncodingSpeed(This,Speed) ) 

#define ILMH264EncoderOld2_get_EncodingThreads(This,pThreads)	\
    ( (This)->lpVtbl -> get_EncodingThreads(This,pThreads) ) 

#define ILMH264EncoderOld2_put_EncodingThreads(This,Threads)	\
    ( (This)->lpVtbl -> put_EncodingThreads(This,Threads) ) 

#define ILMH264EncoderOld2_get_OutputFormat(This,pFormat)	\
    ( (This)->lpVtbl -> get_OutputFormat(This,pFormat) ) 

#define ILMH264EncoderOld2_put_OutputFormat(This,Format)	\
    ( (This)->lpVtbl -> put_OutputFormat(This,Format) ) 

#define ILMH264EncoderOld2_get_EnableSuperCompression(This,bSuperCompression)	\
    ( (This)->lpVtbl -> get_EnableSuperCompression(This,bSuperCompression) ) 

#define ILMH264EncoderOld2_put_EnableSuperCompression(This,bSuperCompression)	\
    ( (This)->lpVtbl -> put_EnableSuperCompression(This,bSuperCompression) ) 

#define ILMH264EncoderOld2_get_TimeQualityFactorFileName(This,pFileName)	\
    ( (This)->lpVtbl -> get_TimeQualityFactorFileName(This,pFileName) ) 

#define ILMH264EncoderOld2_put_TimeQualityFactorFileName(This,FileName)	\
    ( (This)->lpVtbl -> put_TimeQualityFactorFileName(This,FileName) ) 

#define ILMH264EncoderOld2_WriteToRegistry(This)	\
    ( (This)->lpVtbl -> WriteToRegistry(This) ) 


#define ILMH264EncoderOld2_get_RestrictAvailableOutputFormats(This,pRestictFormats)	\
    ( (This)->lpVtbl -> get_RestrictAvailableOutputFormats(This,pRestictFormats) ) 

#define ILMH264EncoderOld2_put_RestrictAvailableOutputFormats(This,RestrictFormats)	\
    ( (This)->lpVtbl -> put_RestrictAvailableOutputFormats(This,RestrictFormats) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMH264EncoderOld2_INTERFACE_DEFINED__ */


#ifndef __ILMH264EncoderOld3_INTERFACE_DEFINED__
#define __ILMH264EncoderOld3_INTERFACE_DEFINED__

/* interface ILMH264EncoderOld3 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILMH264EncoderOld3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DF79-38C5-11D5-91F6-00104BDB8FF9")
    ILMH264EncoderOld3 : public ILMH264EncoderOld2
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetNextFrameAsKey( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ResetToDefaults( 
            /* [in] */ eH264APILEVEL ApiLevel) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IFrameIntervalUnit( 
            /* [retval][out] */ eH264FRAMEINTERVALUNIT *pUnit) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_IFrameIntervalUnit( 
            /* [in] */ eH264FRAMEINTERVALUNIT Unit) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMH264EncoderOld3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMH264EncoderOld3 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMH264EncoderOld3 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMH264EncoderOld3 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMH264EncoderOld3 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMH264EncoderOld3 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMH264EncoderOld3 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMH264EncoderOld3 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_QualityFactor )( 
            ILMH264EncoderOld3 * This,
            /* [retval][out] */ long *pQualityFactor);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_QualityFactor )( 
            ILMH264EncoderOld3 * This,
            /* [in] */ long QualityFactor);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IFrameInterval )( 
            ILMH264EncoderOld3 * This,
            /* [retval][out] */ long *pIFrameInterval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IFrameInterval )( 
            ILMH264EncoderOld3 * This,
            /* [in] */ long IFrameInterval);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PFrameInterval )( 
            ILMH264EncoderOld3 * This,
            /* [retval][out] */ long *pPFrameInterval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PFrameInterval )( 
            ILMH264EncoderOld3 * This,
            /* [in] */ long PFrameInterval);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SymbolMode )( 
            ILMH264EncoderOld3 * This,
            /* [retval][out] */ eH264SYMBOLMODE *pSymbolMode);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SymbolMode )( 
            ILMH264EncoderOld3 * This,
            /* [in] */ eH264SYMBOLMODE SymbolMode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FrameRate )( 
            ILMH264EncoderOld3 * This,
            /* [retval][out] */ float *pFrameRate);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FrameRate )( 
            ILMH264EncoderOld3 * This,
            /* [in] */ float FrameRate);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableRateControl )( 
            ILMH264EncoderOld3 * This,
            /* [retval][out] */ VARIANT_BOOL *pEnableRateControl);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableRateControl )( 
            ILMH264EncoderOld3 * This,
            /* [in] */ VARIANT_BOOL EnableRateControl);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BitRate )( 
            ILMH264EncoderOld3 * This,
            /* [retval][out] */ long *pBitRate);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BitRate )( 
            ILMH264EncoderOld3 * This,
            /* [in] */ long BitRate);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EncodingSpeed )( 
            ILMH264EncoderOld3 * This,
            /* [retval][out] */ eH264ENCODINGSPEED *pSpeed);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EncodingSpeed )( 
            ILMH264EncoderOld3 * This,
            /* [in] */ eH264ENCODINGSPEED Speed);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EncodingThreads )( 
            ILMH264EncoderOld3 * This,
            /* [retval][out] */ eH264ENCODINGTHREADS *pThreads);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EncodingThreads )( 
            ILMH264EncoderOld3 * This,
            /* [in] */ eH264ENCODINGTHREADS Threads);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutputFormat )( 
            ILMH264EncoderOld3 * This,
            /* [retval][out] */ eH264OUTPUTFORMAT *pFormat);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OutputFormat )( 
            ILMH264EncoderOld3 * This,
            /* [in] */ eH264OUTPUTFORMAT Format);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableSuperCompression )( 
            ILMH264EncoderOld3 * This,
            /* [retval][out] */ VARIANT_BOOL *bSuperCompression);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableSuperCompression )( 
            ILMH264EncoderOld3 * This,
            /* [in] */ VARIANT_BOOL bSuperCompression);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TimeQualityFactorFileName )( 
            ILMH264EncoderOld3 * This,
            /* [retval][out] */ BSTR *pFileName);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TimeQualityFactorFileName )( 
            ILMH264EncoderOld3 * This,
            /* [in] */ BSTR FileName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteToRegistry )( 
            ILMH264EncoderOld3 * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RestrictAvailableOutputFormats )( 
            ILMH264EncoderOld3 * This,
            /* [retval][out] */ eH264RESTRICTFORMATS *pRestictFormats);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RestrictAvailableOutputFormats )( 
            ILMH264EncoderOld3 * This,
            /* [in] */ eH264RESTRICTFORMATS RestrictFormats);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetNextFrameAsKey )( 
            ILMH264EncoderOld3 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetToDefaults )( 
            ILMH264EncoderOld3 * This,
            /* [in] */ eH264APILEVEL ApiLevel);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IFrameIntervalUnit )( 
            ILMH264EncoderOld3 * This,
            /* [retval][out] */ eH264FRAMEINTERVALUNIT *pUnit);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IFrameIntervalUnit )( 
            ILMH264EncoderOld3 * This,
            /* [in] */ eH264FRAMEINTERVALUNIT Unit);
        
        END_INTERFACE
    } ILMH264EncoderOld3Vtbl;

    interface ILMH264EncoderOld3
    {
        CONST_VTBL struct ILMH264EncoderOld3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMH264EncoderOld3_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMH264EncoderOld3_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMH264EncoderOld3_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMH264EncoderOld3_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMH264EncoderOld3_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMH264EncoderOld3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMH264EncoderOld3_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMH264EncoderOld3_get_QualityFactor(This,pQualityFactor)	\
    ( (This)->lpVtbl -> get_QualityFactor(This,pQualityFactor) ) 

#define ILMH264EncoderOld3_put_QualityFactor(This,QualityFactor)	\
    ( (This)->lpVtbl -> put_QualityFactor(This,QualityFactor) ) 

#define ILMH264EncoderOld3_get_IFrameInterval(This,pIFrameInterval)	\
    ( (This)->lpVtbl -> get_IFrameInterval(This,pIFrameInterval) ) 

#define ILMH264EncoderOld3_put_IFrameInterval(This,IFrameInterval)	\
    ( (This)->lpVtbl -> put_IFrameInterval(This,IFrameInterval) ) 

#define ILMH264EncoderOld3_get_PFrameInterval(This,pPFrameInterval)	\
    ( (This)->lpVtbl -> get_PFrameInterval(This,pPFrameInterval) ) 

#define ILMH264EncoderOld3_put_PFrameInterval(This,PFrameInterval)	\
    ( (This)->lpVtbl -> put_PFrameInterval(This,PFrameInterval) ) 

#define ILMH264EncoderOld3_get_SymbolMode(This,pSymbolMode)	\
    ( (This)->lpVtbl -> get_SymbolMode(This,pSymbolMode) ) 

#define ILMH264EncoderOld3_put_SymbolMode(This,SymbolMode)	\
    ( (This)->lpVtbl -> put_SymbolMode(This,SymbolMode) ) 

#define ILMH264EncoderOld3_get_FrameRate(This,pFrameRate)	\
    ( (This)->lpVtbl -> get_FrameRate(This,pFrameRate) ) 

#define ILMH264EncoderOld3_put_FrameRate(This,FrameRate)	\
    ( (This)->lpVtbl -> put_FrameRate(This,FrameRate) ) 

#define ILMH264EncoderOld3_get_EnableRateControl(This,pEnableRateControl)	\
    ( (This)->lpVtbl -> get_EnableRateControl(This,pEnableRateControl) ) 

#define ILMH264EncoderOld3_put_EnableRateControl(This,EnableRateControl)	\
    ( (This)->lpVtbl -> put_EnableRateControl(This,EnableRateControl) ) 

#define ILMH264EncoderOld3_get_BitRate(This,pBitRate)	\
    ( (This)->lpVtbl -> get_BitRate(This,pBitRate) ) 

#define ILMH264EncoderOld3_put_BitRate(This,BitRate)	\
    ( (This)->lpVtbl -> put_BitRate(This,BitRate) ) 

#define ILMH264EncoderOld3_get_EncodingSpeed(This,pSpeed)	\
    ( (This)->lpVtbl -> get_EncodingSpeed(This,pSpeed) ) 

#define ILMH264EncoderOld3_put_EncodingSpeed(This,Speed)	\
    ( (This)->lpVtbl -> put_EncodingSpeed(This,Speed) ) 

#define ILMH264EncoderOld3_get_EncodingThreads(This,pThreads)	\
    ( (This)->lpVtbl -> get_EncodingThreads(This,pThreads) ) 

#define ILMH264EncoderOld3_put_EncodingThreads(This,Threads)	\
    ( (This)->lpVtbl -> put_EncodingThreads(This,Threads) ) 

#define ILMH264EncoderOld3_get_OutputFormat(This,pFormat)	\
    ( (This)->lpVtbl -> get_OutputFormat(This,pFormat) ) 

#define ILMH264EncoderOld3_put_OutputFormat(This,Format)	\
    ( (This)->lpVtbl -> put_OutputFormat(This,Format) ) 

#define ILMH264EncoderOld3_get_EnableSuperCompression(This,bSuperCompression)	\
    ( (This)->lpVtbl -> get_EnableSuperCompression(This,bSuperCompression) ) 

#define ILMH264EncoderOld3_put_EnableSuperCompression(This,bSuperCompression)	\
    ( (This)->lpVtbl -> put_EnableSuperCompression(This,bSuperCompression) ) 

#define ILMH264EncoderOld3_get_TimeQualityFactorFileName(This,pFileName)	\
    ( (This)->lpVtbl -> get_TimeQualityFactorFileName(This,pFileName) ) 

#define ILMH264EncoderOld3_put_TimeQualityFactorFileName(This,FileName)	\
    ( (This)->lpVtbl -> put_TimeQualityFactorFileName(This,FileName) ) 

#define ILMH264EncoderOld3_WriteToRegistry(This)	\
    ( (This)->lpVtbl -> WriteToRegistry(This) ) 


#define ILMH264EncoderOld3_get_RestrictAvailableOutputFormats(This,pRestictFormats)	\
    ( (This)->lpVtbl -> get_RestrictAvailableOutputFormats(This,pRestictFormats) ) 

#define ILMH264EncoderOld3_put_RestrictAvailableOutputFormats(This,RestrictFormats)	\
    ( (This)->lpVtbl -> put_RestrictAvailableOutputFormats(This,RestrictFormats) ) 


#define ILMH264EncoderOld3_SetNextFrameAsKey(This)	\
    ( (This)->lpVtbl -> SetNextFrameAsKey(This) ) 

#define ILMH264EncoderOld3_ResetToDefaults(This,ApiLevel)	\
    ( (This)->lpVtbl -> ResetToDefaults(This,ApiLevel) ) 

#define ILMH264EncoderOld3_get_IFrameIntervalUnit(This,pUnit)	\
    ( (This)->lpVtbl -> get_IFrameIntervalUnit(This,pUnit) ) 

#define ILMH264EncoderOld3_put_IFrameIntervalUnit(This,Unit)	\
    ( (This)->lpVtbl -> put_IFrameIntervalUnit(This,Unit) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMH264EncoderOld3_INTERFACE_DEFINED__ */


#ifndef __ILMH264EncoderOld4_INTERFACE_DEFINED__
#define __ILMH264EncoderOld4_INTERFACE_DEFINED__

/* interface ILMH264EncoderOld4 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILMH264EncoderOld4;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DF7A-38C5-11D5-91F6-00104BDB8FF9")
    ILMH264EncoderOld4 : public ILMH264EncoderOld3
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MaxRtpPacketLength( 
            /* [retval][out] */ long *pMaxLength) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MaxRtpPacketLength( 
            /* [in] */ long MaxLength) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMH264EncoderOld4Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMH264EncoderOld4 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMH264EncoderOld4 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMH264EncoderOld4 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMH264EncoderOld4 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMH264EncoderOld4 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMH264EncoderOld4 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMH264EncoderOld4 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_QualityFactor )( 
            ILMH264EncoderOld4 * This,
            /* [retval][out] */ long *pQualityFactor);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_QualityFactor )( 
            ILMH264EncoderOld4 * This,
            /* [in] */ long QualityFactor);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IFrameInterval )( 
            ILMH264EncoderOld4 * This,
            /* [retval][out] */ long *pIFrameInterval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IFrameInterval )( 
            ILMH264EncoderOld4 * This,
            /* [in] */ long IFrameInterval);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PFrameInterval )( 
            ILMH264EncoderOld4 * This,
            /* [retval][out] */ long *pPFrameInterval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PFrameInterval )( 
            ILMH264EncoderOld4 * This,
            /* [in] */ long PFrameInterval);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SymbolMode )( 
            ILMH264EncoderOld4 * This,
            /* [retval][out] */ eH264SYMBOLMODE *pSymbolMode);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SymbolMode )( 
            ILMH264EncoderOld4 * This,
            /* [in] */ eH264SYMBOLMODE SymbolMode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FrameRate )( 
            ILMH264EncoderOld4 * This,
            /* [retval][out] */ float *pFrameRate);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FrameRate )( 
            ILMH264EncoderOld4 * This,
            /* [in] */ float FrameRate);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableRateControl )( 
            ILMH264EncoderOld4 * This,
            /* [retval][out] */ VARIANT_BOOL *pEnableRateControl);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableRateControl )( 
            ILMH264EncoderOld4 * This,
            /* [in] */ VARIANT_BOOL EnableRateControl);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BitRate )( 
            ILMH264EncoderOld4 * This,
            /* [retval][out] */ long *pBitRate);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BitRate )( 
            ILMH264EncoderOld4 * This,
            /* [in] */ long BitRate);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EncodingSpeed )( 
            ILMH264EncoderOld4 * This,
            /* [retval][out] */ eH264ENCODINGSPEED *pSpeed);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EncodingSpeed )( 
            ILMH264EncoderOld4 * This,
            /* [in] */ eH264ENCODINGSPEED Speed);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EncodingThreads )( 
            ILMH264EncoderOld4 * This,
            /* [retval][out] */ eH264ENCODINGTHREADS *pThreads);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EncodingThreads )( 
            ILMH264EncoderOld4 * This,
            /* [in] */ eH264ENCODINGTHREADS Threads);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutputFormat )( 
            ILMH264EncoderOld4 * This,
            /* [retval][out] */ eH264OUTPUTFORMAT *pFormat);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OutputFormat )( 
            ILMH264EncoderOld4 * This,
            /* [in] */ eH264OUTPUTFORMAT Format);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableSuperCompression )( 
            ILMH264EncoderOld4 * This,
            /* [retval][out] */ VARIANT_BOOL *bSuperCompression);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableSuperCompression )( 
            ILMH264EncoderOld4 * This,
            /* [in] */ VARIANT_BOOL bSuperCompression);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TimeQualityFactorFileName )( 
            ILMH264EncoderOld4 * This,
            /* [retval][out] */ BSTR *pFileName);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TimeQualityFactorFileName )( 
            ILMH264EncoderOld4 * This,
            /* [in] */ BSTR FileName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteToRegistry )( 
            ILMH264EncoderOld4 * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RestrictAvailableOutputFormats )( 
            ILMH264EncoderOld4 * This,
            /* [retval][out] */ eH264RESTRICTFORMATS *pRestictFormats);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RestrictAvailableOutputFormats )( 
            ILMH264EncoderOld4 * This,
            /* [in] */ eH264RESTRICTFORMATS RestrictFormats);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetNextFrameAsKey )( 
            ILMH264EncoderOld4 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetToDefaults )( 
            ILMH264EncoderOld4 * This,
            /* [in] */ eH264APILEVEL ApiLevel);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IFrameIntervalUnit )( 
            ILMH264EncoderOld4 * This,
            /* [retval][out] */ eH264FRAMEINTERVALUNIT *pUnit);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IFrameIntervalUnit )( 
            ILMH264EncoderOld4 * This,
            /* [in] */ eH264FRAMEINTERVALUNIT Unit);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MaxRtpPacketLength )( 
            ILMH264EncoderOld4 * This,
            /* [retval][out] */ long *pMaxLength);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MaxRtpPacketLength )( 
            ILMH264EncoderOld4 * This,
            /* [in] */ long MaxLength);
        
        END_INTERFACE
    } ILMH264EncoderOld4Vtbl;

    interface ILMH264EncoderOld4
    {
        CONST_VTBL struct ILMH264EncoderOld4Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMH264EncoderOld4_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMH264EncoderOld4_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMH264EncoderOld4_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMH264EncoderOld4_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMH264EncoderOld4_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMH264EncoderOld4_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMH264EncoderOld4_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMH264EncoderOld4_get_QualityFactor(This,pQualityFactor)	\
    ( (This)->lpVtbl -> get_QualityFactor(This,pQualityFactor) ) 

#define ILMH264EncoderOld4_put_QualityFactor(This,QualityFactor)	\
    ( (This)->lpVtbl -> put_QualityFactor(This,QualityFactor) ) 

#define ILMH264EncoderOld4_get_IFrameInterval(This,pIFrameInterval)	\
    ( (This)->lpVtbl -> get_IFrameInterval(This,pIFrameInterval) ) 

#define ILMH264EncoderOld4_put_IFrameInterval(This,IFrameInterval)	\
    ( (This)->lpVtbl -> put_IFrameInterval(This,IFrameInterval) ) 

#define ILMH264EncoderOld4_get_PFrameInterval(This,pPFrameInterval)	\
    ( (This)->lpVtbl -> get_PFrameInterval(This,pPFrameInterval) ) 

#define ILMH264EncoderOld4_put_PFrameInterval(This,PFrameInterval)	\
    ( (This)->lpVtbl -> put_PFrameInterval(This,PFrameInterval) ) 

#define ILMH264EncoderOld4_get_SymbolMode(This,pSymbolMode)	\
    ( (This)->lpVtbl -> get_SymbolMode(This,pSymbolMode) ) 

#define ILMH264EncoderOld4_put_SymbolMode(This,SymbolMode)	\
    ( (This)->lpVtbl -> put_SymbolMode(This,SymbolMode) ) 

#define ILMH264EncoderOld4_get_FrameRate(This,pFrameRate)	\
    ( (This)->lpVtbl -> get_FrameRate(This,pFrameRate) ) 

#define ILMH264EncoderOld4_put_FrameRate(This,FrameRate)	\
    ( (This)->lpVtbl -> put_FrameRate(This,FrameRate) ) 

#define ILMH264EncoderOld4_get_EnableRateControl(This,pEnableRateControl)	\
    ( (This)->lpVtbl -> get_EnableRateControl(This,pEnableRateControl) ) 

#define ILMH264EncoderOld4_put_EnableRateControl(This,EnableRateControl)	\
    ( (This)->lpVtbl -> put_EnableRateControl(This,EnableRateControl) ) 

#define ILMH264EncoderOld4_get_BitRate(This,pBitRate)	\
    ( (This)->lpVtbl -> get_BitRate(This,pBitRate) ) 

#define ILMH264EncoderOld4_put_BitRate(This,BitRate)	\
    ( (This)->lpVtbl -> put_BitRate(This,BitRate) ) 

#define ILMH264EncoderOld4_get_EncodingSpeed(This,pSpeed)	\
    ( (This)->lpVtbl -> get_EncodingSpeed(This,pSpeed) ) 

#define ILMH264EncoderOld4_put_EncodingSpeed(This,Speed)	\
    ( (This)->lpVtbl -> put_EncodingSpeed(This,Speed) ) 

#define ILMH264EncoderOld4_get_EncodingThreads(This,pThreads)	\
    ( (This)->lpVtbl -> get_EncodingThreads(This,pThreads) ) 

#define ILMH264EncoderOld4_put_EncodingThreads(This,Threads)	\
    ( (This)->lpVtbl -> put_EncodingThreads(This,Threads) ) 

#define ILMH264EncoderOld4_get_OutputFormat(This,pFormat)	\
    ( (This)->lpVtbl -> get_OutputFormat(This,pFormat) ) 

#define ILMH264EncoderOld4_put_OutputFormat(This,Format)	\
    ( (This)->lpVtbl -> put_OutputFormat(This,Format) ) 

#define ILMH264EncoderOld4_get_EnableSuperCompression(This,bSuperCompression)	\
    ( (This)->lpVtbl -> get_EnableSuperCompression(This,bSuperCompression) ) 

#define ILMH264EncoderOld4_put_EnableSuperCompression(This,bSuperCompression)	\
    ( (This)->lpVtbl -> put_EnableSuperCompression(This,bSuperCompression) ) 

#define ILMH264EncoderOld4_get_TimeQualityFactorFileName(This,pFileName)	\
    ( (This)->lpVtbl -> get_TimeQualityFactorFileName(This,pFileName) ) 

#define ILMH264EncoderOld4_put_TimeQualityFactorFileName(This,FileName)	\
    ( (This)->lpVtbl -> put_TimeQualityFactorFileName(This,FileName) ) 

#define ILMH264EncoderOld4_WriteToRegistry(This)	\
    ( (This)->lpVtbl -> WriteToRegistry(This) ) 


#define ILMH264EncoderOld4_get_RestrictAvailableOutputFormats(This,pRestictFormats)	\
    ( (This)->lpVtbl -> get_RestrictAvailableOutputFormats(This,pRestictFormats) ) 

#define ILMH264EncoderOld4_put_RestrictAvailableOutputFormats(This,RestrictFormats)	\
    ( (This)->lpVtbl -> put_RestrictAvailableOutputFormats(This,RestrictFormats) ) 


#define ILMH264EncoderOld4_SetNextFrameAsKey(This)	\
    ( (This)->lpVtbl -> SetNextFrameAsKey(This) ) 

#define ILMH264EncoderOld4_ResetToDefaults(This,ApiLevel)	\
    ( (This)->lpVtbl -> ResetToDefaults(This,ApiLevel) ) 

#define ILMH264EncoderOld4_get_IFrameIntervalUnit(This,pUnit)	\
    ( (This)->lpVtbl -> get_IFrameIntervalUnit(This,pUnit) ) 

#define ILMH264EncoderOld4_put_IFrameIntervalUnit(This,Unit)	\
    ( (This)->lpVtbl -> put_IFrameIntervalUnit(This,Unit) ) 


#define ILMH264EncoderOld4_get_MaxRtpPacketLength(This,pMaxLength)	\
    ( (This)->lpVtbl -> get_MaxRtpPacketLength(This,pMaxLength) ) 

#define ILMH264EncoderOld4_put_MaxRtpPacketLength(This,MaxLength)	\
    ( (This)->lpVtbl -> put_MaxRtpPacketLength(This,MaxLength) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMH264EncoderOld4_INTERFACE_DEFINED__ */


#ifndef __ILMH264Encoder_INTERFACE_DEFINED__
#define __ILMH264Encoder_INTERFACE_DEFINED__

/* interface ILMH264Encoder */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILMH264Encoder;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DF7C-38C5-11D5-91F6-00104BDB8FF9")
    ILMH264Encoder : public ILMH264EncoderOld4
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RtpPayloadType( 
            /* [retval][out] */ long *pPayloadType) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RtpPayloadType( 
            /* [in] */ long PayloadType) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RtpSynchronizationSourceIdentifier( 
            /* [retval][out] */ long *pSSRC) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RtpSynchronizationSourceIdentifier( 
            /* [in] */ long SSRC) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMH264EncoderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMH264Encoder * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMH264Encoder * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMH264Encoder * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMH264Encoder * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMH264Encoder * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMH264Encoder * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMH264Encoder * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_QualityFactor )( 
            ILMH264Encoder * This,
            /* [retval][out] */ long *pQualityFactor);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_QualityFactor )( 
            ILMH264Encoder * This,
            /* [in] */ long QualityFactor);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IFrameInterval )( 
            ILMH264Encoder * This,
            /* [retval][out] */ long *pIFrameInterval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IFrameInterval )( 
            ILMH264Encoder * This,
            /* [in] */ long IFrameInterval);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PFrameInterval )( 
            ILMH264Encoder * This,
            /* [retval][out] */ long *pPFrameInterval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PFrameInterval )( 
            ILMH264Encoder * This,
            /* [in] */ long PFrameInterval);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SymbolMode )( 
            ILMH264Encoder * This,
            /* [retval][out] */ eH264SYMBOLMODE *pSymbolMode);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SymbolMode )( 
            ILMH264Encoder * This,
            /* [in] */ eH264SYMBOLMODE SymbolMode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FrameRate )( 
            ILMH264Encoder * This,
            /* [retval][out] */ float *pFrameRate);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FrameRate )( 
            ILMH264Encoder * This,
            /* [in] */ float FrameRate);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableRateControl )( 
            ILMH264Encoder * This,
            /* [retval][out] */ VARIANT_BOOL *pEnableRateControl);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableRateControl )( 
            ILMH264Encoder * This,
            /* [in] */ VARIANT_BOOL EnableRateControl);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BitRate )( 
            ILMH264Encoder * This,
            /* [retval][out] */ long *pBitRate);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BitRate )( 
            ILMH264Encoder * This,
            /* [in] */ long BitRate);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EncodingSpeed )( 
            ILMH264Encoder * This,
            /* [retval][out] */ eH264ENCODINGSPEED *pSpeed);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EncodingSpeed )( 
            ILMH264Encoder * This,
            /* [in] */ eH264ENCODINGSPEED Speed);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EncodingThreads )( 
            ILMH264Encoder * This,
            /* [retval][out] */ eH264ENCODINGTHREADS *pThreads);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EncodingThreads )( 
            ILMH264Encoder * This,
            /* [in] */ eH264ENCODINGTHREADS Threads);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutputFormat )( 
            ILMH264Encoder * This,
            /* [retval][out] */ eH264OUTPUTFORMAT *pFormat);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OutputFormat )( 
            ILMH264Encoder * This,
            /* [in] */ eH264OUTPUTFORMAT Format);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableSuperCompression )( 
            ILMH264Encoder * This,
            /* [retval][out] */ VARIANT_BOOL *bSuperCompression);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableSuperCompression )( 
            ILMH264Encoder * This,
            /* [in] */ VARIANT_BOOL bSuperCompression);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TimeQualityFactorFileName )( 
            ILMH264Encoder * This,
            /* [retval][out] */ BSTR *pFileName);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TimeQualityFactorFileName )( 
            ILMH264Encoder * This,
            /* [in] */ BSTR FileName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteToRegistry )( 
            ILMH264Encoder * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RestrictAvailableOutputFormats )( 
            ILMH264Encoder * This,
            /* [retval][out] */ eH264RESTRICTFORMATS *pRestictFormats);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RestrictAvailableOutputFormats )( 
            ILMH264Encoder * This,
            /* [in] */ eH264RESTRICTFORMATS RestrictFormats);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetNextFrameAsKey )( 
            ILMH264Encoder * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetToDefaults )( 
            ILMH264Encoder * This,
            /* [in] */ eH264APILEVEL ApiLevel);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IFrameIntervalUnit )( 
            ILMH264Encoder * This,
            /* [retval][out] */ eH264FRAMEINTERVALUNIT *pUnit);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IFrameIntervalUnit )( 
            ILMH264Encoder * This,
            /* [in] */ eH264FRAMEINTERVALUNIT Unit);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MaxRtpPacketLength )( 
            ILMH264Encoder * This,
            /* [retval][out] */ long *pMaxLength);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MaxRtpPacketLength )( 
            ILMH264Encoder * This,
            /* [in] */ long MaxLength);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RtpPayloadType )( 
            ILMH264Encoder * This,
            /* [retval][out] */ long *pPayloadType);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RtpPayloadType )( 
            ILMH264Encoder * This,
            /* [in] */ long PayloadType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RtpSynchronizationSourceIdentifier )( 
            ILMH264Encoder * This,
            /* [retval][out] */ long *pSSRC);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RtpSynchronizationSourceIdentifier )( 
            ILMH264Encoder * This,
            /* [in] */ long SSRC);
        
        END_INTERFACE
    } ILMH264EncoderVtbl;

    interface ILMH264Encoder
    {
        CONST_VTBL struct ILMH264EncoderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMH264Encoder_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMH264Encoder_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMH264Encoder_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMH264Encoder_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMH264Encoder_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMH264Encoder_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMH264Encoder_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMH264Encoder_get_QualityFactor(This,pQualityFactor)	\
    ( (This)->lpVtbl -> get_QualityFactor(This,pQualityFactor) ) 

#define ILMH264Encoder_put_QualityFactor(This,QualityFactor)	\
    ( (This)->lpVtbl -> put_QualityFactor(This,QualityFactor) ) 

#define ILMH264Encoder_get_IFrameInterval(This,pIFrameInterval)	\
    ( (This)->lpVtbl -> get_IFrameInterval(This,pIFrameInterval) ) 

#define ILMH264Encoder_put_IFrameInterval(This,IFrameInterval)	\
    ( (This)->lpVtbl -> put_IFrameInterval(This,IFrameInterval) ) 

#define ILMH264Encoder_get_PFrameInterval(This,pPFrameInterval)	\
    ( (This)->lpVtbl -> get_PFrameInterval(This,pPFrameInterval) ) 

#define ILMH264Encoder_put_PFrameInterval(This,PFrameInterval)	\
    ( (This)->lpVtbl -> put_PFrameInterval(This,PFrameInterval) ) 

#define ILMH264Encoder_get_SymbolMode(This,pSymbolMode)	\
    ( (This)->lpVtbl -> get_SymbolMode(This,pSymbolMode) ) 

#define ILMH264Encoder_put_SymbolMode(This,SymbolMode)	\
    ( (This)->lpVtbl -> put_SymbolMode(This,SymbolMode) ) 

#define ILMH264Encoder_get_FrameRate(This,pFrameRate)	\
    ( (This)->lpVtbl -> get_FrameRate(This,pFrameRate) ) 

#define ILMH264Encoder_put_FrameRate(This,FrameRate)	\
    ( (This)->lpVtbl -> put_FrameRate(This,FrameRate) ) 

#define ILMH264Encoder_get_EnableRateControl(This,pEnableRateControl)	\
    ( (This)->lpVtbl -> get_EnableRateControl(This,pEnableRateControl) ) 

#define ILMH264Encoder_put_EnableRateControl(This,EnableRateControl)	\
    ( (This)->lpVtbl -> put_EnableRateControl(This,EnableRateControl) ) 

#define ILMH264Encoder_get_BitRate(This,pBitRate)	\
    ( (This)->lpVtbl -> get_BitRate(This,pBitRate) ) 

#define ILMH264Encoder_put_BitRate(This,BitRate)	\
    ( (This)->lpVtbl -> put_BitRate(This,BitRate) ) 

#define ILMH264Encoder_get_EncodingSpeed(This,pSpeed)	\
    ( (This)->lpVtbl -> get_EncodingSpeed(This,pSpeed) ) 

#define ILMH264Encoder_put_EncodingSpeed(This,Speed)	\
    ( (This)->lpVtbl -> put_EncodingSpeed(This,Speed) ) 

#define ILMH264Encoder_get_EncodingThreads(This,pThreads)	\
    ( (This)->lpVtbl -> get_EncodingThreads(This,pThreads) ) 

#define ILMH264Encoder_put_EncodingThreads(This,Threads)	\
    ( (This)->lpVtbl -> put_EncodingThreads(This,Threads) ) 

#define ILMH264Encoder_get_OutputFormat(This,pFormat)	\
    ( (This)->lpVtbl -> get_OutputFormat(This,pFormat) ) 

#define ILMH264Encoder_put_OutputFormat(This,Format)	\
    ( (This)->lpVtbl -> put_OutputFormat(This,Format) ) 

#define ILMH264Encoder_get_EnableSuperCompression(This,bSuperCompression)	\
    ( (This)->lpVtbl -> get_EnableSuperCompression(This,bSuperCompression) ) 

#define ILMH264Encoder_put_EnableSuperCompression(This,bSuperCompression)	\
    ( (This)->lpVtbl -> put_EnableSuperCompression(This,bSuperCompression) ) 

#define ILMH264Encoder_get_TimeQualityFactorFileName(This,pFileName)	\
    ( (This)->lpVtbl -> get_TimeQualityFactorFileName(This,pFileName) ) 

#define ILMH264Encoder_put_TimeQualityFactorFileName(This,FileName)	\
    ( (This)->lpVtbl -> put_TimeQualityFactorFileName(This,FileName) ) 

#define ILMH264Encoder_WriteToRegistry(This)	\
    ( (This)->lpVtbl -> WriteToRegistry(This) ) 


#define ILMH264Encoder_get_RestrictAvailableOutputFormats(This,pRestictFormats)	\
    ( (This)->lpVtbl -> get_RestrictAvailableOutputFormats(This,pRestictFormats) ) 

#define ILMH264Encoder_put_RestrictAvailableOutputFormats(This,RestrictFormats)	\
    ( (This)->lpVtbl -> put_RestrictAvailableOutputFormats(This,RestrictFormats) ) 


#define ILMH264Encoder_SetNextFrameAsKey(This)	\
    ( (This)->lpVtbl -> SetNextFrameAsKey(This) ) 

#define ILMH264Encoder_ResetToDefaults(This,ApiLevel)	\
    ( (This)->lpVtbl -> ResetToDefaults(This,ApiLevel) ) 

#define ILMH264Encoder_get_IFrameIntervalUnit(This,pUnit)	\
    ( (This)->lpVtbl -> get_IFrameIntervalUnit(This,pUnit) ) 

#define ILMH264Encoder_put_IFrameIntervalUnit(This,Unit)	\
    ( (This)->lpVtbl -> put_IFrameIntervalUnit(This,Unit) ) 


#define ILMH264Encoder_get_MaxRtpPacketLength(This,pMaxLength)	\
    ( (This)->lpVtbl -> get_MaxRtpPacketLength(This,pMaxLength) ) 

#define ILMH264Encoder_put_MaxRtpPacketLength(This,MaxLength)	\
    ( (This)->lpVtbl -> put_MaxRtpPacketLength(This,MaxLength) ) 


#define ILMH264Encoder_get_RtpPayloadType(This,pPayloadType)	\
    ( (This)->lpVtbl -> get_RtpPayloadType(This,pPayloadType) ) 

#define ILMH264Encoder_put_RtpPayloadType(This,PayloadType)	\
    ( (This)->lpVtbl -> put_RtpPayloadType(This,PayloadType) ) 

#define ILMH264Encoder_get_RtpSynchronizationSourceIdentifier(This,pSSRC)	\
    ( (This)->lpVtbl -> get_RtpSynchronizationSourceIdentifier(This,pSSRC) ) 

#define ILMH264Encoder_put_RtpSynchronizationSourceIdentifier(This,SSRC)	\
    ( (This)->lpVtbl -> put_RtpSynchronizationSourceIdentifier(This,SSRC) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMH264Encoder_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LMH264Encoder;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DF52-38C5-11D5-91F6-00104BDB8FF9")
LMH264Encoder;
#endif
#endif /* __LMH264EncoderLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


