

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Nov 05 12:32:45 2009
 */
/* Compiler settings for .\ILEncMPEG2.idl:
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


#ifndef __ILEncMPEG2_3_h__
#define __ILEncMPEG2_3_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILMMPG2EncoderOld1_FWD_DEFINED__
#define __ILMMPG2EncoderOld1_FWD_DEFINED__
typedef interface ILMMPG2EncoderOld1 ILMMPG2EncoderOld1;
#endif 	/* __ILMMPG2EncoderOld1_FWD_DEFINED__ */


#ifndef __ILMMPG2Encoder_FWD_DEFINED__
#define __ILMMPG2Encoder_FWD_DEFINED__
typedef interface ILMMPG2Encoder ILMMPG2Encoder;
#endif 	/* __ILMMPG2Encoder_FWD_DEFINED__ */


#ifndef __LMMPEG2Encoder_FWD_DEFINED__
#define __LMMPEG2Encoder_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMMPEG2Encoder LMMPEG2Encoder;
#else
typedef struct LMMPEG2Encoder LMMPEG2Encoder;
#endif /* __cplusplus */

#endif 	/* __LMMPEG2Encoder_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LMMPEG2EncoderLib_LIBRARY_DEFINED__
#define __LMMPEG2EncoderLib_LIBRARY_DEFINED__

/* library LMMPEG2EncoderLib */
/* [helpstring][version][uuid] */ 

#ifndef __ILMMPEG2ENCODER_H__
#define __ILMMPEG2ENCODER_H__
static const GUID CLSID_LMMPEG2ProfessionalEncoder            = { 0xe2b7dcc1, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 }};
static const GUID CLSID_LMMPEG2ProfessionalEncoderProperty    = { 0xe2b7dcc2, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 }};
static const GUID CLSID_LMMPEG2ProfessionalEncoderAbout       = { 0xe2b7dcc3, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 }};
static const GUID LIBID_LMMPEG2ProfessionalEncoderLib         = { 0xe2b7dcc4, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 }};
static const GUID CLSID_LMMPEG2Encoder                        = { 0xe2b7df4b, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 }};
static const GUID CLSID_LMMPEG2EncoderProperty                = { 0xe2b7df4c, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 }};
static const GUID CLSID_LMMPEG2EncoderAbout                   = { 0xe2b7df4d, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 }};
static const GUID LIBID_LMMPEG2EncoderLib                     = { 0xe2b7df4e, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 }};
static const GUID IID_ILMMPG2EncoderOld1                     = {  0xe2b7df4f, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 }};
static const GUID IID_ILMMPG2Encoder                         = {  0xE2B7DF68, 0x38C5, 0x11D5, {0x91, 0xF6, 0x00, 0x10, 0x4B, 0xDB, 0x8F, 0xF9 }};
#endif 
typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_ILEncMPEG2_0000_0000_0001
    {	MPEG2Type_MPEG1	= 0,
	MPEG2Type_VCD	= 1,
	MPEG2Type_MPEG2	= 2,
	MPEG2Type_SVCD	= 3,
	MPEG2Type_DVD	= 4,
	MPEG2Type_DICOM	= 5
    } 	eMPEG2VIDEOTYPE;

typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_ILEncMPEG2_0000_0000_0002
    {	MPEG2MODE_GENERAL	= 1,
	MPEG2MODE_DVD	= 2,
	MPEG2MODE_DICOM	= 3,
	MPEG2MODE_MPEG1	= 4,
	MPEG2MODE_VCD	= 5,
	MPEG2MODE_MPEG2	= 6,
	MPEG2MODE_SVCD	= 7
    } 	eMPEG2DEFAULTMODE;

typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_ILEncMPEG2_0000_0000_0003
    {	FRAMERATE_23_98	= 0,
	FRAMERATE_24_00	= 1,
	FRAMERATE_25_00	= 2,
	FRAMERATE_29_97	= 3,
	FRAMERATE_30_00	= 4,
	FRAMERATE_50_00	= 5,
	FRAMERATE_59_94	= 6,
	FRAMERATE_60_00	= 7
    } 	eMPEG2FRAMERATE;

typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_ILEncMPEG2_0000_0000_0004
    {	MPEG2Profile_Simple	= 0,
	MPEG2Profile_Main	= 1,
	MPEG2Profile_High	= 2
    } 	eMPEG2PROFILE;

typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_ILEncMPEG2_0000_0000_0005
    {	MPEG2Level_Low	= 0,
	MPEG2Level_Main	= 1,
	MPEG2Level_High1440	= 2,
	MPEG2Level_High	= 3
    } 	eMPEG2LEVEL;

typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_ILEncMPEG2_0000_0000_0006
    {	MPEG1_AR_1_0000	= 0,
	MPEG1_AR_0_6735	= ( MPEG1_AR_1_0000 + 1 ) ,
	MPEG1_AR_0_7031	= ( MPEG1_AR_0_6735 + 1 ) ,
	MPEG1_AR_0_7615	= ( MPEG1_AR_0_7031 + 1 ) ,
	MPEG1_AR_0_8055	= ( MPEG1_AR_0_7615 + 1 ) ,
	MPEG1_AR_0_8437	= ( MPEG1_AR_0_8055 + 1 ) ,
	MPEG1_AR_0_8935	= ( MPEG1_AR_0_8437 + 1 ) ,
	MPEG1_AR_0_9375	= ( MPEG1_AR_0_8935 + 1 ) ,
	MPEG1_AR_0_9815	= ( MPEG1_AR_0_9375 + 1 ) ,
	MPEG1_AR_1_0255	= ( MPEG1_AR_0_9815 + 1 ) ,
	MPEG1_AR_1_0695	= ( MPEG1_AR_1_0255 + 1 ) ,
	MPEG1_AR_1_1250	= ( MPEG1_AR_1_0695 + 1 ) ,
	MPEG1_AR_1_1575	= ( MPEG1_AR_1_1250 + 1 ) ,
	MPEG1_AR_1_2015	= ( MPEG1_AR_1_1575 + 1 ) ,
	MPEG2_AR_1_0000	= ( MPEG1_AR_1_2015 + 1 ) ,
	MPEG2_AR_4_3	= ( MPEG2_AR_1_0000 + 1 ) ,
	MPEG2_AR_16_9	= ( MPEG2_AR_4_3 + 1 ) ,
	MPEG2_AR_2_21_1	= ( MPEG2_AR_16_9 + 1 ) 
    } 	eMPEGASPECTRATIO;

typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_ILEncMPEG2_0000_0000_0007
    {	MPEG2_VF_PAL	= 1,
	MPEG2_VF_NTSC	= 2,
	MPEG2_VF_HDTV_720	= 3,
	MPEG2_VF_HDTV_1080	= 4
    } 	eMPEG2VIDEOFORMAT;

typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_ILEncMPEG2_0000_0000_0008
    {	MPEG2_DS_PROGRESSIVE	= 0,
	MPEG2_DS_INTERLACED	= 1
    } 	eMPEG2DISPLAYSCAN;

typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_ILEncMPEG2_0000_0000_0009
    {	MPEG2_VARIABLE_BITRATE	= 0,
	MPEG2_CONSTANT_QUALITY	= ( MPEG2_VARIABLE_BITRATE + 1 ) ,
	MPEG2_CONSTANT_BITRATE	= ( MPEG2_CONSTANT_QUALITY + 1 ) 
    } 	eRATECONTROL;

typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_ILEncMPEG2_0000_0000_0010
    {	MPEG2_THREAD_AUTO	= 0,
	MPEG2_THREAD_1	= 1,
	MPEG2_THREAD_2	= 2,
	MPEG2_THREAD_3	= 3,
	MPEG2_THREAD_4	= 4
    } 	eMpeg2EncodingThreads;

typedef /* [public][public] */ 
enum __MIDL___MIDL_itf_ILEncMPEG2_0000_0000_0011
    {	MPEG2_APILEVEL_1	= 0,
	MPEG2_APILEVEL_2	= 1
    } 	eMpeg2ApiLevel;


EXTERN_C const IID LIBID_LMMPEG2EncoderLib;

#ifndef __ILMMPG2EncoderOld1_INTERFACE_DEFINED__
#define __ILMMPG2EncoderOld1_INTERFACE_DEFINED__

/* interface ILMMPG2EncoderOld1 */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ILMMPG2EncoderOld1;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DF4F-38C5-11D5-91F6-00104BDB8FF9")
    ILMMPG2EncoderOld1 : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MpegVideoType( 
            /* [retval][out] */ eMPEG2VIDEOTYPE *pMpegVideoType) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MpegVideoType( 
            /* [in] */ eMPEG2VIDEOTYPE MpegVideoType) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MPEG2Profile( 
            /* [retval][out] */ eMPEG2PROFILE *pProfile) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MPEG2Profile( 
            /* [in] */ eMPEG2PROFILE Profile) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MPEG2Level( 
            /* [retval][out] */ eMPEG2LEVEL *pLevel) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MPEG2Level( 
            /* [in] */ eMPEG2LEVEL Level) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PlaybackFramerate( 
            /* [retval][out] */ eMPEG2FRAMERATE *pFrameRate) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PlaybackFramerate( 
            /* [in] */ eMPEG2FRAMERATE FrameRate) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RateControlMethod( 
            /* [retval][out] */ eRATECONTROL *pRateControl) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RateControlMethod( 
            /* [in] */ eRATECONTROL RateControl) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Bitrate( 
            /* [retval][out] */ long *pBitrate) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Bitrate( 
            /* [in] */ long Bitrate) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_I_FrameDistance( 
            /* [retval][out] */ long *pI_FrameDistance) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_I_FrameDistance( 
            /* [in] */ long I_FrameDistance) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_P_FrameDistance( 
            /* [retval][out] */ long *pP_FrameDistance) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_P_FrameDistance( 
            /* [in] */ long P_FrameDistance) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_QuantizerValue( 
            /* [retval][out] */ long *pQuantizerValue) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_QuantizerValue( 
            /* [in] */ long QuantizerValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MinQuantizerValue( 
            /* [retval][out] */ long *pMinQuantizerValue) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MinQuantizerValue( 
            /* [in] */ long MinQuantizerValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MaxQuantizerValue( 
            /* [retval][out] */ long *pMaxQuantizerValue) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MaxQuantizerValue( 
            /* [in] */ long MaxQuantizerValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AspectRatio( 
            /* [retval][out] */ eMPEGASPECTRATIO *pAspectRatio) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AspectRatio( 
            /* [in] */ eMPEGASPECTRATIO AspectRatio) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_VideoFormat( 
            /* [retval][out] */ eMPEG2VIDEOFORMAT *pVideoFormat) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_VideoFormat( 
            /* [in] */ eMPEG2VIDEOFORMAT VideoFormat) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ShowWarningMessage( 
            /* [retval][out] */ VARIANT_BOOL *pIsShow) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ShowWarningMessage( 
            /* [in] */ VARIANT_BOOL IsShow) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EstimatedBitrate( 
            /* [retval][out] */ unsigned long *pEstimatedBitrate) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultMpegMode( 
            /* [retval][out] */ eMPEG2DEFAULTMODE *pMpegDefaultMode) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DefaultMpegMode( 
            /* [in] */ eMPEG2DEFAULTMODE MpegDefaultMode) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TimeQualityFactorFileName( 
            /* [retval][out] */ BSTR *pFileName) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_TimeQualityFactorFileName( 
            /* [in] */ BSTR FileName) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DisplayScan( 
            /* [retval][out] */ eMPEG2DISPLAYSCAN *pDisplayScan) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DisplayScan( 
            /* [in] */ eMPEG2DISPLAYSCAN DisplayScan) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EncodingThreads( 
            /* [retval][out] */ eMpeg2EncodingThreads *pThreads) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_EncodingThreads( 
            /* [in] */ eMpeg2EncodingThreads Threads) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PictureCodingType( 
            /* [retval][out] */ VARIANT_BOOL *pIsFieldCoding) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PictureCodingType( 
            /* [in] */ VARIANT_BOOL IsFieldCoding) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteToRegistry( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMMPG2EncoderOld1Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMMPG2EncoderOld1 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMMPG2EncoderOld1 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMMPG2EncoderOld1 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMMPG2EncoderOld1 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMMPG2EncoderOld1 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMMPG2EncoderOld1 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMMPG2EncoderOld1 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MpegVideoType )( 
            ILMMPG2EncoderOld1 * This,
            /* [retval][out] */ eMPEG2VIDEOTYPE *pMpegVideoType);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MpegVideoType )( 
            ILMMPG2EncoderOld1 * This,
            /* [in] */ eMPEG2VIDEOTYPE MpegVideoType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MPEG2Profile )( 
            ILMMPG2EncoderOld1 * This,
            /* [retval][out] */ eMPEG2PROFILE *pProfile);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MPEG2Profile )( 
            ILMMPG2EncoderOld1 * This,
            /* [in] */ eMPEG2PROFILE Profile);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MPEG2Level )( 
            ILMMPG2EncoderOld1 * This,
            /* [retval][out] */ eMPEG2LEVEL *pLevel);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MPEG2Level )( 
            ILMMPG2EncoderOld1 * This,
            /* [in] */ eMPEG2LEVEL Level);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PlaybackFramerate )( 
            ILMMPG2EncoderOld1 * This,
            /* [retval][out] */ eMPEG2FRAMERATE *pFrameRate);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PlaybackFramerate )( 
            ILMMPG2EncoderOld1 * This,
            /* [in] */ eMPEG2FRAMERATE FrameRate);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RateControlMethod )( 
            ILMMPG2EncoderOld1 * This,
            /* [retval][out] */ eRATECONTROL *pRateControl);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RateControlMethod )( 
            ILMMPG2EncoderOld1 * This,
            /* [in] */ eRATECONTROL RateControl);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Bitrate )( 
            ILMMPG2EncoderOld1 * This,
            /* [retval][out] */ long *pBitrate);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Bitrate )( 
            ILMMPG2EncoderOld1 * This,
            /* [in] */ long Bitrate);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_I_FrameDistance )( 
            ILMMPG2EncoderOld1 * This,
            /* [retval][out] */ long *pI_FrameDistance);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_I_FrameDistance )( 
            ILMMPG2EncoderOld1 * This,
            /* [in] */ long I_FrameDistance);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_P_FrameDistance )( 
            ILMMPG2EncoderOld1 * This,
            /* [retval][out] */ long *pP_FrameDistance);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_P_FrameDistance )( 
            ILMMPG2EncoderOld1 * This,
            /* [in] */ long P_FrameDistance);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_QuantizerValue )( 
            ILMMPG2EncoderOld1 * This,
            /* [retval][out] */ long *pQuantizerValue);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_QuantizerValue )( 
            ILMMPG2EncoderOld1 * This,
            /* [in] */ long QuantizerValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MinQuantizerValue )( 
            ILMMPG2EncoderOld1 * This,
            /* [retval][out] */ long *pMinQuantizerValue);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MinQuantizerValue )( 
            ILMMPG2EncoderOld1 * This,
            /* [in] */ long MinQuantizerValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MaxQuantizerValue )( 
            ILMMPG2EncoderOld1 * This,
            /* [retval][out] */ long *pMaxQuantizerValue);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MaxQuantizerValue )( 
            ILMMPG2EncoderOld1 * This,
            /* [in] */ long MaxQuantizerValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AspectRatio )( 
            ILMMPG2EncoderOld1 * This,
            /* [retval][out] */ eMPEGASPECTRATIO *pAspectRatio);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AspectRatio )( 
            ILMMPG2EncoderOld1 * This,
            /* [in] */ eMPEGASPECTRATIO AspectRatio);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VideoFormat )( 
            ILMMPG2EncoderOld1 * This,
            /* [retval][out] */ eMPEG2VIDEOFORMAT *pVideoFormat);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_VideoFormat )( 
            ILMMPG2EncoderOld1 * This,
            /* [in] */ eMPEG2VIDEOFORMAT VideoFormat);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ShowWarningMessage )( 
            ILMMPG2EncoderOld1 * This,
            /* [retval][out] */ VARIANT_BOOL *pIsShow);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ShowWarningMessage )( 
            ILMMPG2EncoderOld1 * This,
            /* [in] */ VARIANT_BOOL IsShow);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EstimatedBitrate )( 
            ILMMPG2EncoderOld1 * This,
            /* [retval][out] */ unsigned long *pEstimatedBitrate);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultMpegMode )( 
            ILMMPG2EncoderOld1 * This,
            /* [retval][out] */ eMPEG2DEFAULTMODE *pMpegDefaultMode);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultMpegMode )( 
            ILMMPG2EncoderOld1 * This,
            /* [in] */ eMPEG2DEFAULTMODE MpegDefaultMode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TimeQualityFactorFileName )( 
            ILMMPG2EncoderOld1 * This,
            /* [retval][out] */ BSTR *pFileName);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TimeQualityFactorFileName )( 
            ILMMPG2EncoderOld1 * This,
            /* [in] */ BSTR FileName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DisplayScan )( 
            ILMMPG2EncoderOld1 * This,
            /* [retval][out] */ eMPEG2DISPLAYSCAN *pDisplayScan);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DisplayScan )( 
            ILMMPG2EncoderOld1 * This,
            /* [in] */ eMPEG2DISPLAYSCAN DisplayScan);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EncodingThreads )( 
            ILMMPG2EncoderOld1 * This,
            /* [retval][out] */ eMpeg2EncodingThreads *pThreads);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EncodingThreads )( 
            ILMMPG2EncoderOld1 * This,
            /* [in] */ eMpeg2EncodingThreads Threads);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PictureCodingType )( 
            ILMMPG2EncoderOld1 * This,
            /* [retval][out] */ VARIANT_BOOL *pIsFieldCoding);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PictureCodingType )( 
            ILMMPG2EncoderOld1 * This,
            /* [in] */ VARIANT_BOOL IsFieldCoding);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteToRegistry )( 
            ILMMPG2EncoderOld1 * This);
        
        END_INTERFACE
    } ILMMPG2EncoderOld1Vtbl;

    interface ILMMPG2EncoderOld1
    {
        CONST_VTBL struct ILMMPG2EncoderOld1Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMMPG2EncoderOld1_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMMPG2EncoderOld1_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMMPG2EncoderOld1_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMMPG2EncoderOld1_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMMPG2EncoderOld1_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMMPG2EncoderOld1_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMMPG2EncoderOld1_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMMPG2EncoderOld1_get_MpegVideoType(This,pMpegVideoType)	\
    ( (This)->lpVtbl -> get_MpegVideoType(This,pMpegVideoType) ) 

#define ILMMPG2EncoderOld1_put_MpegVideoType(This,MpegVideoType)	\
    ( (This)->lpVtbl -> put_MpegVideoType(This,MpegVideoType) ) 

#define ILMMPG2EncoderOld1_get_MPEG2Profile(This,pProfile)	\
    ( (This)->lpVtbl -> get_MPEG2Profile(This,pProfile) ) 

#define ILMMPG2EncoderOld1_put_MPEG2Profile(This,Profile)	\
    ( (This)->lpVtbl -> put_MPEG2Profile(This,Profile) ) 

#define ILMMPG2EncoderOld1_get_MPEG2Level(This,pLevel)	\
    ( (This)->lpVtbl -> get_MPEG2Level(This,pLevel) ) 

#define ILMMPG2EncoderOld1_put_MPEG2Level(This,Level)	\
    ( (This)->lpVtbl -> put_MPEG2Level(This,Level) ) 

#define ILMMPG2EncoderOld1_get_PlaybackFramerate(This,pFrameRate)	\
    ( (This)->lpVtbl -> get_PlaybackFramerate(This,pFrameRate) ) 

#define ILMMPG2EncoderOld1_put_PlaybackFramerate(This,FrameRate)	\
    ( (This)->lpVtbl -> put_PlaybackFramerate(This,FrameRate) ) 

#define ILMMPG2EncoderOld1_get_RateControlMethod(This,pRateControl)	\
    ( (This)->lpVtbl -> get_RateControlMethod(This,pRateControl) ) 

#define ILMMPG2EncoderOld1_put_RateControlMethod(This,RateControl)	\
    ( (This)->lpVtbl -> put_RateControlMethod(This,RateControl) ) 

#define ILMMPG2EncoderOld1_get_Bitrate(This,pBitrate)	\
    ( (This)->lpVtbl -> get_Bitrate(This,pBitrate) ) 

#define ILMMPG2EncoderOld1_put_Bitrate(This,Bitrate)	\
    ( (This)->lpVtbl -> put_Bitrate(This,Bitrate) ) 

#define ILMMPG2EncoderOld1_get_I_FrameDistance(This,pI_FrameDistance)	\
    ( (This)->lpVtbl -> get_I_FrameDistance(This,pI_FrameDistance) ) 

#define ILMMPG2EncoderOld1_put_I_FrameDistance(This,I_FrameDistance)	\
    ( (This)->lpVtbl -> put_I_FrameDistance(This,I_FrameDistance) ) 

#define ILMMPG2EncoderOld1_get_P_FrameDistance(This,pP_FrameDistance)	\
    ( (This)->lpVtbl -> get_P_FrameDistance(This,pP_FrameDistance) ) 

#define ILMMPG2EncoderOld1_put_P_FrameDistance(This,P_FrameDistance)	\
    ( (This)->lpVtbl -> put_P_FrameDistance(This,P_FrameDistance) ) 

#define ILMMPG2EncoderOld1_get_QuantizerValue(This,pQuantizerValue)	\
    ( (This)->lpVtbl -> get_QuantizerValue(This,pQuantizerValue) ) 

#define ILMMPG2EncoderOld1_put_QuantizerValue(This,QuantizerValue)	\
    ( (This)->lpVtbl -> put_QuantizerValue(This,QuantizerValue) ) 

#define ILMMPG2EncoderOld1_get_MinQuantizerValue(This,pMinQuantizerValue)	\
    ( (This)->lpVtbl -> get_MinQuantizerValue(This,pMinQuantizerValue) ) 

#define ILMMPG2EncoderOld1_put_MinQuantizerValue(This,MinQuantizerValue)	\
    ( (This)->lpVtbl -> put_MinQuantizerValue(This,MinQuantizerValue) ) 

#define ILMMPG2EncoderOld1_get_MaxQuantizerValue(This,pMaxQuantizerValue)	\
    ( (This)->lpVtbl -> get_MaxQuantizerValue(This,pMaxQuantizerValue) ) 

#define ILMMPG2EncoderOld1_put_MaxQuantizerValue(This,MaxQuantizerValue)	\
    ( (This)->lpVtbl -> put_MaxQuantizerValue(This,MaxQuantizerValue) ) 

#define ILMMPG2EncoderOld1_get_AspectRatio(This,pAspectRatio)	\
    ( (This)->lpVtbl -> get_AspectRatio(This,pAspectRatio) ) 

#define ILMMPG2EncoderOld1_put_AspectRatio(This,AspectRatio)	\
    ( (This)->lpVtbl -> put_AspectRatio(This,AspectRatio) ) 

#define ILMMPG2EncoderOld1_get_VideoFormat(This,pVideoFormat)	\
    ( (This)->lpVtbl -> get_VideoFormat(This,pVideoFormat) ) 

#define ILMMPG2EncoderOld1_put_VideoFormat(This,VideoFormat)	\
    ( (This)->lpVtbl -> put_VideoFormat(This,VideoFormat) ) 

#define ILMMPG2EncoderOld1_get_ShowWarningMessage(This,pIsShow)	\
    ( (This)->lpVtbl -> get_ShowWarningMessage(This,pIsShow) ) 

#define ILMMPG2EncoderOld1_put_ShowWarningMessage(This,IsShow)	\
    ( (This)->lpVtbl -> put_ShowWarningMessage(This,IsShow) ) 

#define ILMMPG2EncoderOld1_get_EstimatedBitrate(This,pEstimatedBitrate)	\
    ( (This)->lpVtbl -> get_EstimatedBitrate(This,pEstimatedBitrate) ) 

#define ILMMPG2EncoderOld1_get_DefaultMpegMode(This,pMpegDefaultMode)	\
    ( (This)->lpVtbl -> get_DefaultMpegMode(This,pMpegDefaultMode) ) 

#define ILMMPG2EncoderOld1_put_DefaultMpegMode(This,MpegDefaultMode)	\
    ( (This)->lpVtbl -> put_DefaultMpegMode(This,MpegDefaultMode) ) 

#define ILMMPG2EncoderOld1_get_TimeQualityFactorFileName(This,pFileName)	\
    ( (This)->lpVtbl -> get_TimeQualityFactorFileName(This,pFileName) ) 

#define ILMMPG2EncoderOld1_put_TimeQualityFactorFileName(This,FileName)	\
    ( (This)->lpVtbl -> put_TimeQualityFactorFileName(This,FileName) ) 

#define ILMMPG2EncoderOld1_get_DisplayScan(This,pDisplayScan)	\
    ( (This)->lpVtbl -> get_DisplayScan(This,pDisplayScan) ) 

#define ILMMPG2EncoderOld1_put_DisplayScan(This,DisplayScan)	\
    ( (This)->lpVtbl -> put_DisplayScan(This,DisplayScan) ) 

#define ILMMPG2EncoderOld1_get_EncodingThreads(This,pThreads)	\
    ( (This)->lpVtbl -> get_EncodingThreads(This,pThreads) ) 

#define ILMMPG2EncoderOld1_put_EncodingThreads(This,Threads)	\
    ( (This)->lpVtbl -> put_EncodingThreads(This,Threads) ) 

#define ILMMPG2EncoderOld1_get_PictureCodingType(This,pIsFieldCoding)	\
    ( (This)->lpVtbl -> get_PictureCodingType(This,pIsFieldCoding) ) 

#define ILMMPG2EncoderOld1_put_PictureCodingType(This,IsFieldCoding)	\
    ( (This)->lpVtbl -> put_PictureCodingType(This,IsFieldCoding) ) 

#define ILMMPG2EncoderOld1_WriteToRegistry(This)	\
    ( (This)->lpVtbl -> WriteToRegistry(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMMPG2EncoderOld1_INTERFACE_DEFINED__ */


#ifndef __ILMMPG2Encoder_INTERFACE_DEFINED__
#define __ILMMPG2Encoder_INTERFACE_DEFINED__

/* interface ILMMPG2Encoder */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ILMMPG2Encoder;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DF68-38C5-11D5-91F6-00104BDB8FF9")
    ILMMPG2Encoder : public ILMMPG2EncoderOld1
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IgnoreInputAspectRatio( 
            /* [retval][out] */ VARIANT_BOOL *pbIgnoreInputAspectRatio) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_IgnoreInputAspectRatio( 
            /* [in] */ VARIANT_BOOL bIgnoreInputAspectRatio) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ResetToDefaultsEx( 
            /* [in] */ eMpeg2ApiLevel ApiLevel) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMMPG2EncoderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMMPG2Encoder * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMMPG2Encoder * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMMPG2Encoder * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMMPG2Encoder * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMMPG2Encoder * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMMPG2Encoder * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMMPG2Encoder * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MpegVideoType )( 
            ILMMPG2Encoder * This,
            /* [retval][out] */ eMPEG2VIDEOTYPE *pMpegVideoType);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MpegVideoType )( 
            ILMMPG2Encoder * This,
            /* [in] */ eMPEG2VIDEOTYPE MpegVideoType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MPEG2Profile )( 
            ILMMPG2Encoder * This,
            /* [retval][out] */ eMPEG2PROFILE *pProfile);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MPEG2Profile )( 
            ILMMPG2Encoder * This,
            /* [in] */ eMPEG2PROFILE Profile);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MPEG2Level )( 
            ILMMPG2Encoder * This,
            /* [retval][out] */ eMPEG2LEVEL *pLevel);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MPEG2Level )( 
            ILMMPG2Encoder * This,
            /* [in] */ eMPEG2LEVEL Level);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PlaybackFramerate )( 
            ILMMPG2Encoder * This,
            /* [retval][out] */ eMPEG2FRAMERATE *pFrameRate);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PlaybackFramerate )( 
            ILMMPG2Encoder * This,
            /* [in] */ eMPEG2FRAMERATE FrameRate);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RateControlMethod )( 
            ILMMPG2Encoder * This,
            /* [retval][out] */ eRATECONTROL *pRateControl);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RateControlMethod )( 
            ILMMPG2Encoder * This,
            /* [in] */ eRATECONTROL RateControl);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Bitrate )( 
            ILMMPG2Encoder * This,
            /* [retval][out] */ long *pBitrate);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Bitrate )( 
            ILMMPG2Encoder * This,
            /* [in] */ long Bitrate);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_I_FrameDistance )( 
            ILMMPG2Encoder * This,
            /* [retval][out] */ long *pI_FrameDistance);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_I_FrameDistance )( 
            ILMMPG2Encoder * This,
            /* [in] */ long I_FrameDistance);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_P_FrameDistance )( 
            ILMMPG2Encoder * This,
            /* [retval][out] */ long *pP_FrameDistance);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_P_FrameDistance )( 
            ILMMPG2Encoder * This,
            /* [in] */ long P_FrameDistance);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_QuantizerValue )( 
            ILMMPG2Encoder * This,
            /* [retval][out] */ long *pQuantizerValue);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_QuantizerValue )( 
            ILMMPG2Encoder * This,
            /* [in] */ long QuantizerValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MinQuantizerValue )( 
            ILMMPG2Encoder * This,
            /* [retval][out] */ long *pMinQuantizerValue);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MinQuantizerValue )( 
            ILMMPG2Encoder * This,
            /* [in] */ long MinQuantizerValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MaxQuantizerValue )( 
            ILMMPG2Encoder * This,
            /* [retval][out] */ long *pMaxQuantizerValue);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MaxQuantizerValue )( 
            ILMMPG2Encoder * This,
            /* [in] */ long MaxQuantizerValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AspectRatio )( 
            ILMMPG2Encoder * This,
            /* [retval][out] */ eMPEGASPECTRATIO *pAspectRatio);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AspectRatio )( 
            ILMMPG2Encoder * This,
            /* [in] */ eMPEGASPECTRATIO AspectRatio);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VideoFormat )( 
            ILMMPG2Encoder * This,
            /* [retval][out] */ eMPEG2VIDEOFORMAT *pVideoFormat);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_VideoFormat )( 
            ILMMPG2Encoder * This,
            /* [in] */ eMPEG2VIDEOFORMAT VideoFormat);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ShowWarningMessage )( 
            ILMMPG2Encoder * This,
            /* [retval][out] */ VARIANT_BOOL *pIsShow);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ShowWarningMessage )( 
            ILMMPG2Encoder * This,
            /* [in] */ VARIANT_BOOL IsShow);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EstimatedBitrate )( 
            ILMMPG2Encoder * This,
            /* [retval][out] */ unsigned long *pEstimatedBitrate);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultMpegMode )( 
            ILMMPG2Encoder * This,
            /* [retval][out] */ eMPEG2DEFAULTMODE *pMpegDefaultMode);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultMpegMode )( 
            ILMMPG2Encoder * This,
            /* [in] */ eMPEG2DEFAULTMODE MpegDefaultMode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TimeQualityFactorFileName )( 
            ILMMPG2Encoder * This,
            /* [retval][out] */ BSTR *pFileName);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TimeQualityFactorFileName )( 
            ILMMPG2Encoder * This,
            /* [in] */ BSTR FileName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DisplayScan )( 
            ILMMPG2Encoder * This,
            /* [retval][out] */ eMPEG2DISPLAYSCAN *pDisplayScan);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DisplayScan )( 
            ILMMPG2Encoder * This,
            /* [in] */ eMPEG2DISPLAYSCAN DisplayScan);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EncodingThreads )( 
            ILMMPG2Encoder * This,
            /* [retval][out] */ eMpeg2EncodingThreads *pThreads);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EncodingThreads )( 
            ILMMPG2Encoder * This,
            /* [in] */ eMpeg2EncodingThreads Threads);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PictureCodingType )( 
            ILMMPG2Encoder * This,
            /* [retval][out] */ VARIANT_BOOL *pIsFieldCoding);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PictureCodingType )( 
            ILMMPG2Encoder * This,
            /* [in] */ VARIANT_BOOL IsFieldCoding);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteToRegistry )( 
            ILMMPG2Encoder * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IgnoreInputAspectRatio )( 
            ILMMPG2Encoder * This,
            /* [retval][out] */ VARIANT_BOOL *pbIgnoreInputAspectRatio);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IgnoreInputAspectRatio )( 
            ILMMPG2Encoder * This,
            /* [in] */ VARIANT_BOOL bIgnoreInputAspectRatio);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetToDefaultsEx )( 
            ILMMPG2Encoder * This,
            /* [in] */ eMpeg2ApiLevel ApiLevel);
        
        END_INTERFACE
    } ILMMPG2EncoderVtbl;

    interface ILMMPG2Encoder
    {
        CONST_VTBL struct ILMMPG2EncoderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMMPG2Encoder_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMMPG2Encoder_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMMPG2Encoder_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMMPG2Encoder_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMMPG2Encoder_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMMPG2Encoder_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMMPG2Encoder_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMMPG2Encoder_get_MpegVideoType(This,pMpegVideoType)	\
    ( (This)->lpVtbl -> get_MpegVideoType(This,pMpegVideoType) ) 

#define ILMMPG2Encoder_put_MpegVideoType(This,MpegVideoType)	\
    ( (This)->lpVtbl -> put_MpegVideoType(This,MpegVideoType) ) 

#define ILMMPG2Encoder_get_MPEG2Profile(This,pProfile)	\
    ( (This)->lpVtbl -> get_MPEG2Profile(This,pProfile) ) 

#define ILMMPG2Encoder_put_MPEG2Profile(This,Profile)	\
    ( (This)->lpVtbl -> put_MPEG2Profile(This,Profile) ) 

#define ILMMPG2Encoder_get_MPEG2Level(This,pLevel)	\
    ( (This)->lpVtbl -> get_MPEG2Level(This,pLevel) ) 

#define ILMMPG2Encoder_put_MPEG2Level(This,Level)	\
    ( (This)->lpVtbl -> put_MPEG2Level(This,Level) ) 

#define ILMMPG2Encoder_get_PlaybackFramerate(This,pFrameRate)	\
    ( (This)->lpVtbl -> get_PlaybackFramerate(This,pFrameRate) ) 

#define ILMMPG2Encoder_put_PlaybackFramerate(This,FrameRate)	\
    ( (This)->lpVtbl -> put_PlaybackFramerate(This,FrameRate) ) 

#define ILMMPG2Encoder_get_RateControlMethod(This,pRateControl)	\
    ( (This)->lpVtbl -> get_RateControlMethod(This,pRateControl) ) 

#define ILMMPG2Encoder_put_RateControlMethod(This,RateControl)	\
    ( (This)->lpVtbl -> put_RateControlMethod(This,RateControl) ) 

#define ILMMPG2Encoder_get_Bitrate(This,pBitrate)	\
    ( (This)->lpVtbl -> get_Bitrate(This,pBitrate) ) 

#define ILMMPG2Encoder_put_Bitrate(This,Bitrate)	\
    ( (This)->lpVtbl -> put_Bitrate(This,Bitrate) ) 

#define ILMMPG2Encoder_get_I_FrameDistance(This,pI_FrameDistance)	\
    ( (This)->lpVtbl -> get_I_FrameDistance(This,pI_FrameDistance) ) 

#define ILMMPG2Encoder_put_I_FrameDistance(This,I_FrameDistance)	\
    ( (This)->lpVtbl -> put_I_FrameDistance(This,I_FrameDistance) ) 

#define ILMMPG2Encoder_get_P_FrameDistance(This,pP_FrameDistance)	\
    ( (This)->lpVtbl -> get_P_FrameDistance(This,pP_FrameDistance) ) 

#define ILMMPG2Encoder_put_P_FrameDistance(This,P_FrameDistance)	\
    ( (This)->lpVtbl -> put_P_FrameDistance(This,P_FrameDistance) ) 

#define ILMMPG2Encoder_get_QuantizerValue(This,pQuantizerValue)	\
    ( (This)->lpVtbl -> get_QuantizerValue(This,pQuantizerValue) ) 

#define ILMMPG2Encoder_put_QuantizerValue(This,QuantizerValue)	\
    ( (This)->lpVtbl -> put_QuantizerValue(This,QuantizerValue) ) 

#define ILMMPG2Encoder_get_MinQuantizerValue(This,pMinQuantizerValue)	\
    ( (This)->lpVtbl -> get_MinQuantizerValue(This,pMinQuantizerValue) ) 

#define ILMMPG2Encoder_put_MinQuantizerValue(This,MinQuantizerValue)	\
    ( (This)->lpVtbl -> put_MinQuantizerValue(This,MinQuantizerValue) ) 

#define ILMMPG2Encoder_get_MaxQuantizerValue(This,pMaxQuantizerValue)	\
    ( (This)->lpVtbl -> get_MaxQuantizerValue(This,pMaxQuantizerValue) ) 

#define ILMMPG2Encoder_put_MaxQuantizerValue(This,MaxQuantizerValue)	\
    ( (This)->lpVtbl -> put_MaxQuantizerValue(This,MaxQuantizerValue) ) 

#define ILMMPG2Encoder_get_AspectRatio(This,pAspectRatio)	\
    ( (This)->lpVtbl -> get_AspectRatio(This,pAspectRatio) ) 

#define ILMMPG2Encoder_put_AspectRatio(This,AspectRatio)	\
    ( (This)->lpVtbl -> put_AspectRatio(This,AspectRatio) ) 

#define ILMMPG2Encoder_get_VideoFormat(This,pVideoFormat)	\
    ( (This)->lpVtbl -> get_VideoFormat(This,pVideoFormat) ) 

#define ILMMPG2Encoder_put_VideoFormat(This,VideoFormat)	\
    ( (This)->lpVtbl -> put_VideoFormat(This,VideoFormat) ) 

#define ILMMPG2Encoder_get_ShowWarningMessage(This,pIsShow)	\
    ( (This)->lpVtbl -> get_ShowWarningMessage(This,pIsShow) ) 

#define ILMMPG2Encoder_put_ShowWarningMessage(This,IsShow)	\
    ( (This)->lpVtbl -> put_ShowWarningMessage(This,IsShow) ) 

#define ILMMPG2Encoder_get_EstimatedBitrate(This,pEstimatedBitrate)	\
    ( (This)->lpVtbl -> get_EstimatedBitrate(This,pEstimatedBitrate) ) 

#define ILMMPG2Encoder_get_DefaultMpegMode(This,pMpegDefaultMode)	\
    ( (This)->lpVtbl -> get_DefaultMpegMode(This,pMpegDefaultMode) ) 

#define ILMMPG2Encoder_put_DefaultMpegMode(This,MpegDefaultMode)	\
    ( (This)->lpVtbl -> put_DefaultMpegMode(This,MpegDefaultMode) ) 

#define ILMMPG2Encoder_get_TimeQualityFactorFileName(This,pFileName)	\
    ( (This)->lpVtbl -> get_TimeQualityFactorFileName(This,pFileName) ) 

#define ILMMPG2Encoder_put_TimeQualityFactorFileName(This,FileName)	\
    ( (This)->lpVtbl -> put_TimeQualityFactorFileName(This,FileName) ) 

#define ILMMPG2Encoder_get_DisplayScan(This,pDisplayScan)	\
    ( (This)->lpVtbl -> get_DisplayScan(This,pDisplayScan) ) 

#define ILMMPG2Encoder_put_DisplayScan(This,DisplayScan)	\
    ( (This)->lpVtbl -> put_DisplayScan(This,DisplayScan) ) 

#define ILMMPG2Encoder_get_EncodingThreads(This,pThreads)	\
    ( (This)->lpVtbl -> get_EncodingThreads(This,pThreads) ) 

#define ILMMPG2Encoder_put_EncodingThreads(This,Threads)	\
    ( (This)->lpVtbl -> put_EncodingThreads(This,Threads) ) 

#define ILMMPG2Encoder_get_PictureCodingType(This,pIsFieldCoding)	\
    ( (This)->lpVtbl -> get_PictureCodingType(This,pIsFieldCoding) ) 

#define ILMMPG2Encoder_put_PictureCodingType(This,IsFieldCoding)	\
    ( (This)->lpVtbl -> put_PictureCodingType(This,IsFieldCoding) ) 

#define ILMMPG2Encoder_WriteToRegistry(This)	\
    ( (This)->lpVtbl -> WriteToRegistry(This) ) 


#define ILMMPG2Encoder_get_IgnoreInputAspectRatio(This,pbIgnoreInputAspectRatio)	\
    ( (This)->lpVtbl -> get_IgnoreInputAspectRatio(This,pbIgnoreInputAspectRatio) ) 

#define ILMMPG2Encoder_put_IgnoreInputAspectRatio(This,bIgnoreInputAspectRatio)	\
    ( (This)->lpVtbl -> put_IgnoreInputAspectRatio(This,bIgnoreInputAspectRatio) ) 

#define ILMMPG2Encoder_ResetToDefaultsEx(This,ApiLevel)	\
    ( (This)->lpVtbl -> ResetToDefaultsEx(This,ApiLevel) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMMPG2Encoder_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LMMPEG2Encoder;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DF4B-38C5-11D5-91F6-00104BDB8FF9")
LMMPEG2Encoder;
#endif
#endif /* __LMMPEG2EncoderLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


