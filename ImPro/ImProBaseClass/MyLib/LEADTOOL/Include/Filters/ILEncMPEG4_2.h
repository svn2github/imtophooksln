

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Nov 05 12:52:53 2009
 */
/* Compiler settings for .\ILEnc.idl:
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


#ifndef __ILEncMPEG4_2_h__
#define __ILEncMPEG4_2_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILMMP42Encoder_FWD_DEFINED__
#define __ILMMP42Encoder_FWD_DEFINED__
typedef interface ILMMP42Encoder ILMMP42Encoder;
#endif 	/* __ILMMP42Encoder_FWD_DEFINED__ */


#ifndef __LMMP4Encoder_FWD_DEFINED__
#define __LMMP4Encoder_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMMP4Encoder LMMP4Encoder;
#else
typedef struct LMMP4Encoder LMMP4Encoder;
#endif /* __cplusplus */

#endif 	/* __LMMP4Encoder_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LMMP4EncoderLib_LIBRARY_DEFINED__
#define __LMMP4EncoderLib_LIBRARY_DEFINED__

/* library LMMP4EncoderLib */
/* [helpstring][version][uuid] */ 

#ifndef __ILMMP4ENCODER_H__
#define __ILMMP4ENCODER_H__
static const GUID CLSID_LMMP4Encoder                      = { 0xe2b7df3f, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 }};
static const GUID CLSID_LMMP4EncoderPropertiy             = { 0xe2b7df40, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 }};
static const GUID CLSID_LMMP4EncoderAbout                 = { 0xe2b7df41, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 }};
static const GUID LIBID_LMMP4EncoderLib                   = { 0xe2b7df42, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 }};
static const GUID IID_ILMMP42Encoder                       = { 0xe2b7df44, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 }};
#endif 
typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_ILEnc_0000_0000_0001
    {	LMP4_MOTIONVECTOR_OnePerMacroblock	= 0,
	LMP4_MOTIONVECTOR_FourPerMacroblock	= 1
    } 	eMotionVectorPerMacroblock;

typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_ILEnc_0000_0000_0002
    {	LMP4_MOTIONALGORITHM_FullSearch	= 0,
	LMP4_MOTIONALGORITHM_FastSearch	= 1
    } 	eMotionAlgorithm;

typedef /* [public][public][public][public][public] */ 
enum __MIDL___MIDL_itf_ILEnc_0000_0000_0003
    {	LMP4_MOTIONACCURACY_FullPixel	= 1,
	LMP4_MOTIONACCURACY_HalfPixel	= 2
    } 	eMotionAccuracy;

typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_ILEnc_0000_0000_0004
    {	LMP4_QUANTTYPE_Linear	= 0,
	LMP4_QUANTTYPE_NonLinear	= 1
    } 	eQuantType;

typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_ILEnc_0000_0000_0005
    {	LMP4_OUTPUTFORMAT_mp4v	= 0,
	LMP4_OUTPUTFORMAT_LMP4	= 1,
	LMP4_OUTPUTFORMAT_XVID	= 2,
	LMP4_OUTPUTFORMAT_iPod	= 3
    } 	eOutputFormat;

typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_ILEnc_0000_0000_0006
    {	LMP4_COMPRESSIONMODE_ConstantQuality	= 0,
	LMP4_COMPRESSIONMODE_VariableBitrate	= 1,
	LMP4_COMPRESSIONMODE_ConstantBitrate	= 2
    } 	eCompressionMode;

typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_ILEnc_0000_0000_0007
    {	LMP4_ENCODINGPASSESCOUNT_ONE	= 1,
	LMP4_ENCODINGPASSESCOUNT_TWO	= 2
    } 	eEncodingPassesCount;

typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_ILEnc_0000_0000_0008
    {	LMP4_THREAD_AUTO	= 0,
	LMP4_THREAD_1	= 1,
	LMP4_THREAD_2	= 2,
	LMP4_THREAD_3	= 3,
	LMP4_THREAD_4	= 4
    } 	eEncodingThreads;


EXTERN_C const IID LIBID_LMMP4EncoderLib;

#ifndef __ILMMP42Encoder_INTERFACE_DEFINED__
#define __ILMMP42Encoder_INTERFACE_DEFINED__

/* interface ILMMP42Encoder */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ILMMP42Encoder;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DF44-38C5-11D5-91F6-00104BDB8FF9")
    ILMMP42Encoder : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OutputFrameRate( 
            /* [retval][out] */ double *pfFrameRate) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OutputFrameRate( 
            /* [in] */ double fFrameRate) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PFrames( 
            /* [retval][out] */ long *plPFrames) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PFrames( 
            /* [in] */ long lPFrames) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BFrames( 
            /* [retval][out] */ long *plBFrames) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_BFrames( 
            /* [in] */ long lBFrames) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SearchWidth( 
            /* [retval][out] */ long *plPSearchWidth) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SearchWidth( 
            /* [in] */ long lPSearchWidth) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SearchHeight( 
            /* [retval][out] */ long *plSearchHeight) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SearchHeight( 
            /* [in] */ long lSearchHeight) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_QFactor( 
            /* [retval][out] */ long *plQFactor) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_QFactor( 
            /* [in] */ long lQFactor) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_QuantType( 
            /* [retval][out] */ eQuantType *pQuantType) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_QuantType( 
            /* [in] */ eQuantType QuantType) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MotionAlgorithm( 
            /* [retval][out] */ eMotionAlgorithm *pMotionAlgorithm) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MotionAlgorithm( 
            /* [in] */ eMotionAlgorithm MotionAlgorithm) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MotionAccurancy( 
            /* [retval][out] */ eMotionAccuracy *pMotionAccuracy) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MotionAccurancy( 
            /* [in] */ eMotionAccuracy MotionAccuracy) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MotionVectorPerMacroblock( 
            /* [retval][out] */ eMotionVectorPerMacroblock *plMotionVectorPerMacroblock) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MotionVectorPerMacroblock( 
            /* [in] */ eMotionVectorPerMacroblock lMotionVectorPerMacroblock) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteToRegistry( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OutputFormat( 
            /* [retval][out] */ eOutputFormat *pOutputFormat) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OutputFormat( 
            /* [in] */ eOutputFormat lOutputFormat) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SuperCompression( 
            /* [retval][out] */ VARIANT_BOOL *pbSuperCompression) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SuperCompression( 
            /* [in] */ VARIANT_BOOL bSuperCompression) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ResetToDefaults( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MotionAccuracy( 
            /* [retval][out] */ eMotionAccuracy *pMotionAccuracy) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MotionAccuracy( 
            /* [in] */ eMotionAccuracy MotionAccuracy) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CompressionMode( 
            /* [retval][out] */ eCompressionMode *pRateControl) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CompressionMode( 
            /* [in] */ eCompressionMode RateControl) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BitRate( 
            /* [retval][out] */ long *pBitRate) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_BitRate( 
            /* [in] */ long BitRate) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Interlacing( 
            /* [retval][out] */ VARIANT_BOOL *pInterlacing) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Interlacing( 
            /* [in] */ VARIANT_BOOL Interlacing) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_InsertVOL( 
            /* [retval][out] */ VARIANT_BOOL *pInsertVOL) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_InsertVOL( 
            /* [in] */ VARIANT_BOOL InsertVOL) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_InsertGOV( 
            /* [retval][out] */ VARIANT_BOOL *pInsertGOV) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_InsertGOV( 
            /* [in] */ VARIANT_BOOL InsertGOV) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SceneChangeThreshold( 
            /* [retval][out] */ long *pSceneChangeThreshold) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SceneChangeThreshold( 
            /* [in] */ long SceneChangeThreshold) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EncodingPasses( 
            /* [retval][out] */ eEncodingPassesCount *pEncodingPassesCount) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_EncodingPasses( 
            /* [in] */ eEncodingPassesCount EncodingPassesCount) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EncodingThreads( 
            /* [retval][out] */ eEncodingThreads *pThreads) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_EncodingThreads( 
            /* [in] */ eEncodingThreads Threads) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMMP42EncoderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMMP42Encoder * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMMP42Encoder * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMMP42Encoder * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMMP42Encoder * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMMP42Encoder * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMMP42Encoder * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMMP42Encoder * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutputFrameRate )( 
            ILMMP42Encoder * This,
            /* [retval][out] */ double *pfFrameRate);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OutputFrameRate )( 
            ILMMP42Encoder * This,
            /* [in] */ double fFrameRate);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PFrames )( 
            ILMMP42Encoder * This,
            /* [retval][out] */ long *plPFrames);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PFrames )( 
            ILMMP42Encoder * This,
            /* [in] */ long lPFrames);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BFrames )( 
            ILMMP42Encoder * This,
            /* [retval][out] */ long *plBFrames);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BFrames )( 
            ILMMP42Encoder * This,
            /* [in] */ long lBFrames);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SearchWidth )( 
            ILMMP42Encoder * This,
            /* [retval][out] */ long *plPSearchWidth);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SearchWidth )( 
            ILMMP42Encoder * This,
            /* [in] */ long lPSearchWidth);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SearchHeight )( 
            ILMMP42Encoder * This,
            /* [retval][out] */ long *plSearchHeight);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SearchHeight )( 
            ILMMP42Encoder * This,
            /* [in] */ long lSearchHeight);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_QFactor )( 
            ILMMP42Encoder * This,
            /* [retval][out] */ long *plQFactor);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_QFactor )( 
            ILMMP42Encoder * This,
            /* [in] */ long lQFactor);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_QuantType )( 
            ILMMP42Encoder * This,
            /* [retval][out] */ eQuantType *pQuantType);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_QuantType )( 
            ILMMP42Encoder * This,
            /* [in] */ eQuantType QuantType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MotionAlgorithm )( 
            ILMMP42Encoder * This,
            /* [retval][out] */ eMotionAlgorithm *pMotionAlgorithm);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MotionAlgorithm )( 
            ILMMP42Encoder * This,
            /* [in] */ eMotionAlgorithm MotionAlgorithm);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MotionAccurancy )( 
            ILMMP42Encoder * This,
            /* [retval][out] */ eMotionAccuracy *pMotionAccuracy);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MotionAccurancy )( 
            ILMMP42Encoder * This,
            /* [in] */ eMotionAccuracy MotionAccuracy);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MotionVectorPerMacroblock )( 
            ILMMP42Encoder * This,
            /* [retval][out] */ eMotionVectorPerMacroblock *plMotionVectorPerMacroblock);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MotionVectorPerMacroblock )( 
            ILMMP42Encoder * This,
            /* [in] */ eMotionVectorPerMacroblock lMotionVectorPerMacroblock);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteToRegistry )( 
            ILMMP42Encoder * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutputFormat )( 
            ILMMP42Encoder * This,
            /* [retval][out] */ eOutputFormat *pOutputFormat);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OutputFormat )( 
            ILMMP42Encoder * This,
            /* [in] */ eOutputFormat lOutputFormat);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SuperCompression )( 
            ILMMP42Encoder * This,
            /* [retval][out] */ VARIANT_BOOL *pbSuperCompression);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SuperCompression )( 
            ILMMP42Encoder * This,
            /* [in] */ VARIANT_BOOL bSuperCompression);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetToDefaults )( 
            ILMMP42Encoder * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MotionAccuracy )( 
            ILMMP42Encoder * This,
            /* [retval][out] */ eMotionAccuracy *pMotionAccuracy);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MotionAccuracy )( 
            ILMMP42Encoder * This,
            /* [in] */ eMotionAccuracy MotionAccuracy);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CompressionMode )( 
            ILMMP42Encoder * This,
            /* [retval][out] */ eCompressionMode *pRateControl);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CompressionMode )( 
            ILMMP42Encoder * This,
            /* [in] */ eCompressionMode RateControl);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BitRate )( 
            ILMMP42Encoder * This,
            /* [retval][out] */ long *pBitRate);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BitRate )( 
            ILMMP42Encoder * This,
            /* [in] */ long BitRate);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Interlacing )( 
            ILMMP42Encoder * This,
            /* [retval][out] */ VARIANT_BOOL *pInterlacing);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Interlacing )( 
            ILMMP42Encoder * This,
            /* [in] */ VARIANT_BOOL Interlacing);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InsertVOL )( 
            ILMMP42Encoder * This,
            /* [retval][out] */ VARIANT_BOOL *pInsertVOL);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_InsertVOL )( 
            ILMMP42Encoder * This,
            /* [in] */ VARIANT_BOOL InsertVOL);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InsertGOV )( 
            ILMMP42Encoder * This,
            /* [retval][out] */ VARIANT_BOOL *pInsertGOV);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_InsertGOV )( 
            ILMMP42Encoder * This,
            /* [in] */ VARIANT_BOOL InsertGOV);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SceneChangeThreshold )( 
            ILMMP42Encoder * This,
            /* [retval][out] */ long *pSceneChangeThreshold);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SceneChangeThreshold )( 
            ILMMP42Encoder * This,
            /* [in] */ long SceneChangeThreshold);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EncodingPasses )( 
            ILMMP42Encoder * This,
            /* [retval][out] */ eEncodingPassesCount *pEncodingPassesCount);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EncodingPasses )( 
            ILMMP42Encoder * This,
            /* [in] */ eEncodingPassesCount EncodingPassesCount);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EncodingThreads )( 
            ILMMP42Encoder * This,
            /* [retval][out] */ eEncodingThreads *pThreads);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EncodingThreads )( 
            ILMMP42Encoder * This,
            /* [in] */ eEncodingThreads Threads);
        
        END_INTERFACE
    } ILMMP42EncoderVtbl;

    interface ILMMP42Encoder
    {
        CONST_VTBL struct ILMMP42EncoderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMMP42Encoder_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMMP42Encoder_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMMP42Encoder_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMMP42Encoder_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMMP42Encoder_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMMP42Encoder_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMMP42Encoder_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMMP42Encoder_get_OutputFrameRate(This,pfFrameRate)	\
    ( (This)->lpVtbl -> get_OutputFrameRate(This,pfFrameRate) ) 

#define ILMMP42Encoder_put_OutputFrameRate(This,fFrameRate)	\
    ( (This)->lpVtbl -> put_OutputFrameRate(This,fFrameRate) ) 

#define ILMMP42Encoder_get_PFrames(This,plPFrames)	\
    ( (This)->lpVtbl -> get_PFrames(This,plPFrames) ) 

#define ILMMP42Encoder_put_PFrames(This,lPFrames)	\
    ( (This)->lpVtbl -> put_PFrames(This,lPFrames) ) 

#define ILMMP42Encoder_get_BFrames(This,plBFrames)	\
    ( (This)->lpVtbl -> get_BFrames(This,plBFrames) ) 

#define ILMMP42Encoder_put_BFrames(This,lBFrames)	\
    ( (This)->lpVtbl -> put_BFrames(This,lBFrames) ) 

#define ILMMP42Encoder_get_SearchWidth(This,plPSearchWidth)	\
    ( (This)->lpVtbl -> get_SearchWidth(This,plPSearchWidth) ) 

#define ILMMP42Encoder_put_SearchWidth(This,lPSearchWidth)	\
    ( (This)->lpVtbl -> put_SearchWidth(This,lPSearchWidth) ) 

#define ILMMP42Encoder_get_SearchHeight(This,plSearchHeight)	\
    ( (This)->lpVtbl -> get_SearchHeight(This,plSearchHeight) ) 

#define ILMMP42Encoder_put_SearchHeight(This,lSearchHeight)	\
    ( (This)->lpVtbl -> put_SearchHeight(This,lSearchHeight) ) 

#define ILMMP42Encoder_get_QFactor(This,plQFactor)	\
    ( (This)->lpVtbl -> get_QFactor(This,plQFactor) ) 

#define ILMMP42Encoder_put_QFactor(This,lQFactor)	\
    ( (This)->lpVtbl -> put_QFactor(This,lQFactor) ) 

#define ILMMP42Encoder_get_QuantType(This,pQuantType)	\
    ( (This)->lpVtbl -> get_QuantType(This,pQuantType) ) 

#define ILMMP42Encoder_put_QuantType(This,QuantType)	\
    ( (This)->lpVtbl -> put_QuantType(This,QuantType) ) 

#define ILMMP42Encoder_get_MotionAlgorithm(This,pMotionAlgorithm)	\
    ( (This)->lpVtbl -> get_MotionAlgorithm(This,pMotionAlgorithm) ) 

#define ILMMP42Encoder_put_MotionAlgorithm(This,MotionAlgorithm)	\
    ( (This)->lpVtbl -> put_MotionAlgorithm(This,MotionAlgorithm) ) 

#define ILMMP42Encoder_get_MotionAccurancy(This,pMotionAccuracy)	\
    ( (This)->lpVtbl -> get_MotionAccurancy(This,pMotionAccuracy) ) 

#define ILMMP42Encoder_put_MotionAccurancy(This,MotionAccuracy)	\
    ( (This)->lpVtbl -> put_MotionAccurancy(This,MotionAccuracy) ) 

#define ILMMP42Encoder_get_MotionVectorPerMacroblock(This,plMotionVectorPerMacroblock)	\
    ( (This)->lpVtbl -> get_MotionVectorPerMacroblock(This,plMotionVectorPerMacroblock) ) 

#define ILMMP42Encoder_put_MotionVectorPerMacroblock(This,lMotionVectorPerMacroblock)	\
    ( (This)->lpVtbl -> put_MotionVectorPerMacroblock(This,lMotionVectorPerMacroblock) ) 

#define ILMMP42Encoder_WriteToRegistry(This)	\
    ( (This)->lpVtbl -> WriteToRegistry(This) ) 

#define ILMMP42Encoder_get_OutputFormat(This,pOutputFormat)	\
    ( (This)->lpVtbl -> get_OutputFormat(This,pOutputFormat) ) 

#define ILMMP42Encoder_put_OutputFormat(This,lOutputFormat)	\
    ( (This)->lpVtbl -> put_OutputFormat(This,lOutputFormat) ) 

#define ILMMP42Encoder_get_SuperCompression(This,pbSuperCompression)	\
    ( (This)->lpVtbl -> get_SuperCompression(This,pbSuperCompression) ) 

#define ILMMP42Encoder_put_SuperCompression(This,bSuperCompression)	\
    ( (This)->lpVtbl -> put_SuperCompression(This,bSuperCompression) ) 

#define ILMMP42Encoder_ResetToDefaults(This)	\
    ( (This)->lpVtbl -> ResetToDefaults(This) ) 

#define ILMMP42Encoder_get_MotionAccuracy(This,pMotionAccuracy)	\
    ( (This)->lpVtbl -> get_MotionAccuracy(This,pMotionAccuracy) ) 

#define ILMMP42Encoder_put_MotionAccuracy(This,MotionAccuracy)	\
    ( (This)->lpVtbl -> put_MotionAccuracy(This,MotionAccuracy) ) 

#define ILMMP42Encoder_get_CompressionMode(This,pRateControl)	\
    ( (This)->lpVtbl -> get_CompressionMode(This,pRateControl) ) 

#define ILMMP42Encoder_put_CompressionMode(This,RateControl)	\
    ( (This)->lpVtbl -> put_CompressionMode(This,RateControl) ) 

#define ILMMP42Encoder_get_BitRate(This,pBitRate)	\
    ( (This)->lpVtbl -> get_BitRate(This,pBitRate) ) 

#define ILMMP42Encoder_put_BitRate(This,BitRate)	\
    ( (This)->lpVtbl -> put_BitRate(This,BitRate) ) 

#define ILMMP42Encoder_get_Interlacing(This,pInterlacing)	\
    ( (This)->lpVtbl -> get_Interlacing(This,pInterlacing) ) 

#define ILMMP42Encoder_put_Interlacing(This,Interlacing)	\
    ( (This)->lpVtbl -> put_Interlacing(This,Interlacing) ) 

#define ILMMP42Encoder_get_InsertVOL(This,pInsertVOL)	\
    ( (This)->lpVtbl -> get_InsertVOL(This,pInsertVOL) ) 

#define ILMMP42Encoder_put_InsertVOL(This,InsertVOL)	\
    ( (This)->lpVtbl -> put_InsertVOL(This,InsertVOL) ) 

#define ILMMP42Encoder_get_InsertGOV(This,pInsertGOV)	\
    ( (This)->lpVtbl -> get_InsertGOV(This,pInsertGOV) ) 

#define ILMMP42Encoder_put_InsertGOV(This,InsertGOV)	\
    ( (This)->lpVtbl -> put_InsertGOV(This,InsertGOV) ) 

#define ILMMP42Encoder_get_SceneChangeThreshold(This,pSceneChangeThreshold)	\
    ( (This)->lpVtbl -> get_SceneChangeThreshold(This,pSceneChangeThreshold) ) 

#define ILMMP42Encoder_put_SceneChangeThreshold(This,SceneChangeThreshold)	\
    ( (This)->lpVtbl -> put_SceneChangeThreshold(This,SceneChangeThreshold) ) 

#define ILMMP42Encoder_get_EncodingPasses(This,pEncodingPassesCount)	\
    ( (This)->lpVtbl -> get_EncodingPasses(This,pEncodingPassesCount) ) 

#define ILMMP42Encoder_put_EncodingPasses(This,EncodingPassesCount)	\
    ( (This)->lpVtbl -> put_EncodingPasses(This,EncodingPassesCount) ) 

#define ILMMP42Encoder_get_EncodingThreads(This,pThreads)	\
    ( (This)->lpVtbl -> get_EncodingThreads(This,pThreads) ) 

#define ILMMP42Encoder_put_EncodingThreads(This,Threads)	\
    ( (This)->lpVtbl -> put_EncodingThreads(This,Threads) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMMP42Encoder_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LMMP4Encoder;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DF3F-38C5-11D5-91F6-00104BDB8FF9")
LMMP4Encoder;
#endif
#endif /* __LMMP4EncoderLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


