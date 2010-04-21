

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Nov 05 12:46:06 2009
 */
/* Compiler settings for .\ILEncH263.idl:
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


#ifndef __ILEncH263_2_h__
#define __ILEncH263_2_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILMH263Encoder1_FWD_DEFINED__
#define __ILMH263Encoder1_FWD_DEFINED__
typedef interface ILMH263Encoder1 ILMH263Encoder1;
#endif 	/* __ILMH263Encoder1_FWD_DEFINED__ */


#ifndef __ILMH263Encoder2_FWD_DEFINED__
#define __ILMH263Encoder2_FWD_DEFINED__
typedef interface ILMH263Encoder2 ILMH263Encoder2;
#endif 	/* __ILMH263Encoder2_FWD_DEFINED__ */


#ifndef __ILMH263Encoder_FWD_DEFINED__
#define __ILMH263Encoder_FWD_DEFINED__
typedef interface ILMH263Encoder ILMH263Encoder;
#endif 	/* __ILMH263Encoder_FWD_DEFINED__ */


#ifndef __LMH263Encoder_FWD_DEFINED__
#define __LMH263Encoder_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMH263Encoder LMH263Encoder;
#else
typedef struct LMH263Encoder LMH263Encoder;
#endif /* __cplusplus */

#endif 	/* __LMH263Encoder_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LMH263EncoderLib_LIBRARY_DEFINED__
#define __LMH263EncoderLib_LIBRARY_DEFINED__

/* library LMH263EncoderLib */
/* [helpstring][version][uuid] */ 

#ifndef __ILMH263ENCODER_H__
#define __ILMH263ENCODER_H__
static const GUID CLSID_LMH263Encoder            = { 0xe2b7df00, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 }};
static const GUID CLSID_LMH263EncoderPropertyPage= { 0xe2b7df01, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 }};
static const GUID CLSID_LMH263EncoderAbout       = { 0xe2b7df02, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 }};
static const GUID LIBID_LMH263EncoderLib         = { 0xe2b7df03, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 }};
static const GUID   IID_ILMH263Encoder           = { 0xe2b7de3a, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 }};
static const GUID   IID_ILMH263Encoder1          = { 0xe2b7df04, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 }};
static const GUID   IID_ILMH263Encoder2          = { 0xe2b7dbac, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 }};
#endif 
#define	MINQUALITYFACTOR	( 1 )

#define	MAXQUALITYFACTOR	( 31 )

typedef /* [public] */ 
enum __MIDL___MIDL_itf_ILEncH263_0000_0000_0001
    {	CST_QUALITYDRIVEN	= 0x1,
	CST_PREDEFINED_RATE	= 0x2,
	CST_PREDEFINED_QUALITY	= 0x4,
	CST_PREDEFINED_SPEED	= 0x8
    } 	eCOMPRESSIONSETTINGTYPE;

typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_ILEncH263_0000_0000_0002
    {	MODEM_56K	= 0,
	ISDN_128K	= ( MODEM_56K + 1 ) ,
	ISDN_256K	= ( ISDN_128K + 1 ) ,
	DSL_384K	= ( ISDN_256K + 1 ) ,
	CABLE_768	= ( DSL_384K + 1 ) ,
	T1_1500K	= ( CABLE_768 + 1 ) ,
	WIRELESS_802_11B_11M	= ( T1_1500K + 1 ) ,
	T3_45M	= ( WIRELESS_802_11B_11M + 1 ) ,
	WIRELESS_802_11G_54M	= ( T3_45M + 1 ) ,
	LAN_100M	= ( WIRELESS_802_11G_54M + 1 ) ,
	LAN_1G	= ( LAN_100M + 1 ) 
    } 	eBITRATE;

typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_ILEncH263_0000_0000_0003
    {	HIGHQUALITY	= 0,
	QUALITYMOREIMPORTANTTHANSPEED	= ( HIGHQUALITY + 1 ) ,
	QUALITYSPEEDEQUALLYIMPORTANT	= ( QUALITYMOREIMPORTANTTHANSPEED + 1 ) ,
	SPEEDMOREIMPORTANTTHANQUALITY	= ( QUALITYSPEEDEQUALLYIMPORTANT + 1 ) ,
	HIGHSPEED	= ( SPEEDMOREIMPORTANTTHANQUALITY + 1 ) 
    } 	eSPEED;

typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_ILEncH263_0000_0000_0004
    {	PERFECTQUALITY	= 0,
	QUALITYMOREIMPORTANTTHANSIZE	= ( PERFECTQUALITY + 1 ) ,
	QUALITYSIZEEQUALLYIMPORTANT	= ( QUALITYMOREIMPORTANTTHANSIZE + 1 ) ,
	SIZEMOREIMPORTANTTHANQUALITY	= ( QUALITYSIZEEQUALLYIMPORTANT + 1 ) ,
	HIGHESTCOMPRESSION	= ( SIZEMOREIMPORTANTTHANQUALITY + 1 ) 
    } 	eQUALITY;

typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_ILEncH263_0000_0000_0005
    {	UNIT_FRAMES	= 0,
	UNIT_SECONDS	= ( UNIT_FRAMES + 1 ) 
    } 	eIDISTANCEUNIT;

typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_ILEncH263_0000_0000_0006
    {	H263COMPATIBILITY_DEFAULT	= 0,
	H263COMPATIBILITY_FLV	= ( H263COMPATIBILITY_DEFAULT + 1 ) 
    } 	eH263COMPATIBILITYMODE;

typedef /* [public][public] */ 
enum __MIDL___MIDL_itf_ILEncH263_0000_0000_0007
    {	H263_APILEVEL_1	= 0
    } 	eH263_APILEVEL;


EXTERN_C const IID LIBID_LMH263EncoderLib;

#ifndef __ILMH263Encoder1_INTERFACE_DEFINED__
#define __ILMH263Encoder1_INTERFACE_DEFINED__

/* interface ILMH263Encoder1 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILMH263Encoder1;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DF04-38C5-11D5-91F6-00104BDB8FF9")
    ILMH263Encoder1 : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UseQuality( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_UseQuality( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UsePredefinedQuality( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_UsePredefinedQuality( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PredefinedQuality( 
            /* [retval][out] */ eQUALITY *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PredefinedQuality( 
            /* [in] */ eQUALITY newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CustomQuality( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CustomQuality( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UsePredefinedBitrate( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_UsePredefinedBitrate( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PredefinedBitrate( 
            /* [retval][out] */ eBITRATE *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PredefinedBitrate( 
            /* [in] */ eBITRATE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CustomBitrate( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CustomBitrate( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UsePredefinedSpeed( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_UsePredefinedSpeed( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PredefinedSpeed( 
            /* [retval][out] */ eSPEED *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PredefinedSpeed( 
            /* [in] */ eSPEED newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UseUnrestrictedMotionVector( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_UseUnrestrictedMotionVector( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UsePBFrame( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_UsePBFrame( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UseDeblockingFilter( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_UseDeblockingFilter( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UseAdvancedIntraCoding( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_UseAdvancedIntraCoding( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UseAdvancedPredictionMode( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_UseAdvancedPredictionMode( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_InputFrameRate( 
            /* [retval][out] */ float *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OutputFrameRate( 
            /* [retval][out] */ float *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OutputFrameRate( 
            /* [in] */ float newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UseRTP( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_UseRTP( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UseSuperCompression( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_UseSuperCompression( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IDistanceUnit( 
            /* [retval][out] */ eIDISTANCEUNIT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_IDistanceUnit( 
            /* [in] */ eIDISTANCEUNIT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IDistance( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_IDistance( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PDistance( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PDistance( 
            /* [in] */ long newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMH263Encoder1Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMH263Encoder1 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMH263Encoder1 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMH263Encoder1 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMH263Encoder1 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMH263Encoder1 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMH263Encoder1 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMH263Encoder1 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UseQuality )( 
            ILMH263Encoder1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UseQuality )( 
            ILMH263Encoder1 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UsePredefinedQuality )( 
            ILMH263Encoder1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UsePredefinedQuality )( 
            ILMH263Encoder1 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PredefinedQuality )( 
            ILMH263Encoder1 * This,
            /* [retval][out] */ eQUALITY *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PredefinedQuality )( 
            ILMH263Encoder1 * This,
            /* [in] */ eQUALITY newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CustomQuality )( 
            ILMH263Encoder1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CustomQuality )( 
            ILMH263Encoder1 * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UsePredefinedBitrate )( 
            ILMH263Encoder1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UsePredefinedBitrate )( 
            ILMH263Encoder1 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PredefinedBitrate )( 
            ILMH263Encoder1 * This,
            /* [retval][out] */ eBITRATE *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PredefinedBitrate )( 
            ILMH263Encoder1 * This,
            /* [in] */ eBITRATE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CustomBitrate )( 
            ILMH263Encoder1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CustomBitrate )( 
            ILMH263Encoder1 * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UsePredefinedSpeed )( 
            ILMH263Encoder1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UsePredefinedSpeed )( 
            ILMH263Encoder1 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PredefinedSpeed )( 
            ILMH263Encoder1 * This,
            /* [retval][out] */ eSPEED *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PredefinedSpeed )( 
            ILMH263Encoder1 * This,
            /* [in] */ eSPEED newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UseUnrestrictedMotionVector )( 
            ILMH263Encoder1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UseUnrestrictedMotionVector )( 
            ILMH263Encoder1 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UsePBFrame )( 
            ILMH263Encoder1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UsePBFrame )( 
            ILMH263Encoder1 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UseDeblockingFilter )( 
            ILMH263Encoder1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UseDeblockingFilter )( 
            ILMH263Encoder1 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UseAdvancedIntraCoding )( 
            ILMH263Encoder1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UseAdvancedIntraCoding )( 
            ILMH263Encoder1 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UseAdvancedPredictionMode )( 
            ILMH263Encoder1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UseAdvancedPredictionMode )( 
            ILMH263Encoder1 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InputFrameRate )( 
            ILMH263Encoder1 * This,
            /* [retval][out] */ float *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutputFrameRate )( 
            ILMH263Encoder1 * This,
            /* [retval][out] */ float *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OutputFrameRate )( 
            ILMH263Encoder1 * This,
            /* [in] */ float newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UseRTP )( 
            ILMH263Encoder1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UseRTP )( 
            ILMH263Encoder1 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UseSuperCompression )( 
            ILMH263Encoder1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UseSuperCompression )( 
            ILMH263Encoder1 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IDistanceUnit )( 
            ILMH263Encoder1 * This,
            /* [retval][out] */ eIDISTANCEUNIT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IDistanceUnit )( 
            ILMH263Encoder1 * This,
            /* [in] */ eIDISTANCEUNIT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IDistance )( 
            ILMH263Encoder1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IDistance )( 
            ILMH263Encoder1 * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PDistance )( 
            ILMH263Encoder1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PDistance )( 
            ILMH263Encoder1 * This,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } ILMH263Encoder1Vtbl;

    interface ILMH263Encoder1
    {
        CONST_VTBL struct ILMH263Encoder1Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMH263Encoder1_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMH263Encoder1_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMH263Encoder1_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMH263Encoder1_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMH263Encoder1_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMH263Encoder1_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMH263Encoder1_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMH263Encoder1_get_UseQuality(This,pVal)	\
    ( (This)->lpVtbl -> get_UseQuality(This,pVal) ) 

#define ILMH263Encoder1_put_UseQuality(This,newVal)	\
    ( (This)->lpVtbl -> put_UseQuality(This,newVal) ) 

#define ILMH263Encoder1_get_UsePredefinedQuality(This,pVal)	\
    ( (This)->lpVtbl -> get_UsePredefinedQuality(This,pVal) ) 

#define ILMH263Encoder1_put_UsePredefinedQuality(This,newVal)	\
    ( (This)->lpVtbl -> put_UsePredefinedQuality(This,newVal) ) 

#define ILMH263Encoder1_get_PredefinedQuality(This,pVal)	\
    ( (This)->lpVtbl -> get_PredefinedQuality(This,pVal) ) 

#define ILMH263Encoder1_put_PredefinedQuality(This,newVal)	\
    ( (This)->lpVtbl -> put_PredefinedQuality(This,newVal) ) 

#define ILMH263Encoder1_get_CustomQuality(This,pVal)	\
    ( (This)->lpVtbl -> get_CustomQuality(This,pVal) ) 

#define ILMH263Encoder1_put_CustomQuality(This,newVal)	\
    ( (This)->lpVtbl -> put_CustomQuality(This,newVal) ) 

#define ILMH263Encoder1_get_UsePredefinedBitrate(This,pVal)	\
    ( (This)->lpVtbl -> get_UsePredefinedBitrate(This,pVal) ) 

#define ILMH263Encoder1_put_UsePredefinedBitrate(This,newVal)	\
    ( (This)->lpVtbl -> put_UsePredefinedBitrate(This,newVal) ) 

#define ILMH263Encoder1_get_PredefinedBitrate(This,pVal)	\
    ( (This)->lpVtbl -> get_PredefinedBitrate(This,pVal) ) 

#define ILMH263Encoder1_put_PredefinedBitrate(This,newVal)	\
    ( (This)->lpVtbl -> put_PredefinedBitrate(This,newVal) ) 

#define ILMH263Encoder1_get_CustomBitrate(This,pVal)	\
    ( (This)->lpVtbl -> get_CustomBitrate(This,pVal) ) 

#define ILMH263Encoder1_put_CustomBitrate(This,newVal)	\
    ( (This)->lpVtbl -> put_CustomBitrate(This,newVal) ) 

#define ILMH263Encoder1_get_UsePredefinedSpeed(This,pVal)	\
    ( (This)->lpVtbl -> get_UsePredefinedSpeed(This,pVal) ) 

#define ILMH263Encoder1_put_UsePredefinedSpeed(This,newVal)	\
    ( (This)->lpVtbl -> put_UsePredefinedSpeed(This,newVal) ) 

#define ILMH263Encoder1_get_PredefinedSpeed(This,pVal)	\
    ( (This)->lpVtbl -> get_PredefinedSpeed(This,pVal) ) 

#define ILMH263Encoder1_put_PredefinedSpeed(This,newVal)	\
    ( (This)->lpVtbl -> put_PredefinedSpeed(This,newVal) ) 

#define ILMH263Encoder1_get_UseUnrestrictedMotionVector(This,pVal)	\
    ( (This)->lpVtbl -> get_UseUnrestrictedMotionVector(This,pVal) ) 

#define ILMH263Encoder1_put_UseUnrestrictedMotionVector(This,newVal)	\
    ( (This)->lpVtbl -> put_UseUnrestrictedMotionVector(This,newVal) ) 

#define ILMH263Encoder1_get_UsePBFrame(This,pVal)	\
    ( (This)->lpVtbl -> get_UsePBFrame(This,pVal) ) 

#define ILMH263Encoder1_put_UsePBFrame(This,newVal)	\
    ( (This)->lpVtbl -> put_UsePBFrame(This,newVal) ) 

#define ILMH263Encoder1_get_UseDeblockingFilter(This,pVal)	\
    ( (This)->lpVtbl -> get_UseDeblockingFilter(This,pVal) ) 

#define ILMH263Encoder1_put_UseDeblockingFilter(This,newVal)	\
    ( (This)->lpVtbl -> put_UseDeblockingFilter(This,newVal) ) 

#define ILMH263Encoder1_get_UseAdvancedIntraCoding(This,pVal)	\
    ( (This)->lpVtbl -> get_UseAdvancedIntraCoding(This,pVal) ) 

#define ILMH263Encoder1_put_UseAdvancedIntraCoding(This,newVal)	\
    ( (This)->lpVtbl -> put_UseAdvancedIntraCoding(This,newVal) ) 

#define ILMH263Encoder1_get_UseAdvancedPredictionMode(This,pVal)	\
    ( (This)->lpVtbl -> get_UseAdvancedPredictionMode(This,pVal) ) 

#define ILMH263Encoder1_put_UseAdvancedPredictionMode(This,newVal)	\
    ( (This)->lpVtbl -> put_UseAdvancedPredictionMode(This,newVal) ) 

#define ILMH263Encoder1_get_InputFrameRate(This,pVal)	\
    ( (This)->lpVtbl -> get_InputFrameRate(This,pVal) ) 

#define ILMH263Encoder1_get_OutputFrameRate(This,pVal)	\
    ( (This)->lpVtbl -> get_OutputFrameRate(This,pVal) ) 

#define ILMH263Encoder1_put_OutputFrameRate(This,newVal)	\
    ( (This)->lpVtbl -> put_OutputFrameRate(This,newVal) ) 

#define ILMH263Encoder1_get_UseRTP(This,pVal)	\
    ( (This)->lpVtbl -> get_UseRTP(This,pVal) ) 

#define ILMH263Encoder1_put_UseRTP(This,newVal)	\
    ( (This)->lpVtbl -> put_UseRTP(This,newVal) ) 

#define ILMH263Encoder1_get_UseSuperCompression(This,pVal)	\
    ( (This)->lpVtbl -> get_UseSuperCompression(This,pVal) ) 

#define ILMH263Encoder1_put_UseSuperCompression(This,newVal)	\
    ( (This)->lpVtbl -> put_UseSuperCompression(This,newVal) ) 

#define ILMH263Encoder1_get_IDistanceUnit(This,pVal)	\
    ( (This)->lpVtbl -> get_IDistanceUnit(This,pVal) ) 

#define ILMH263Encoder1_put_IDistanceUnit(This,newVal)	\
    ( (This)->lpVtbl -> put_IDistanceUnit(This,newVal) ) 

#define ILMH263Encoder1_get_IDistance(This,pVal)	\
    ( (This)->lpVtbl -> get_IDistance(This,pVal) ) 

#define ILMH263Encoder1_put_IDistance(This,newVal)	\
    ( (This)->lpVtbl -> put_IDistance(This,newVal) ) 

#define ILMH263Encoder1_get_PDistance(This,pVal)	\
    ( (This)->lpVtbl -> get_PDistance(This,pVal) ) 

#define ILMH263Encoder1_put_PDistance(This,newVal)	\
    ( (This)->lpVtbl -> put_PDistance(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMH263Encoder1_INTERFACE_DEFINED__ */


#ifndef __ILMH263Encoder2_INTERFACE_DEFINED__
#define __ILMH263Encoder2_INTERFACE_DEFINED__

/* interface ILMH263Encoder2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILMH263Encoder2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DBAC-38C5-11D5-91F6-00104BDB8FF9")
    ILMH263Encoder2 : public ILMH263Encoder1
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SorensonOutput( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SorensonOutput( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMH263Encoder2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMH263Encoder2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMH263Encoder2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMH263Encoder2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMH263Encoder2 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMH263Encoder2 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMH263Encoder2 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMH263Encoder2 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UseQuality )( 
            ILMH263Encoder2 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UseQuality )( 
            ILMH263Encoder2 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UsePredefinedQuality )( 
            ILMH263Encoder2 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UsePredefinedQuality )( 
            ILMH263Encoder2 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PredefinedQuality )( 
            ILMH263Encoder2 * This,
            /* [retval][out] */ eQUALITY *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PredefinedQuality )( 
            ILMH263Encoder2 * This,
            /* [in] */ eQUALITY newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CustomQuality )( 
            ILMH263Encoder2 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CustomQuality )( 
            ILMH263Encoder2 * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UsePredefinedBitrate )( 
            ILMH263Encoder2 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UsePredefinedBitrate )( 
            ILMH263Encoder2 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PredefinedBitrate )( 
            ILMH263Encoder2 * This,
            /* [retval][out] */ eBITRATE *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PredefinedBitrate )( 
            ILMH263Encoder2 * This,
            /* [in] */ eBITRATE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CustomBitrate )( 
            ILMH263Encoder2 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CustomBitrate )( 
            ILMH263Encoder2 * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UsePredefinedSpeed )( 
            ILMH263Encoder2 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UsePredefinedSpeed )( 
            ILMH263Encoder2 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PredefinedSpeed )( 
            ILMH263Encoder2 * This,
            /* [retval][out] */ eSPEED *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PredefinedSpeed )( 
            ILMH263Encoder2 * This,
            /* [in] */ eSPEED newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UseUnrestrictedMotionVector )( 
            ILMH263Encoder2 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UseUnrestrictedMotionVector )( 
            ILMH263Encoder2 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UsePBFrame )( 
            ILMH263Encoder2 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UsePBFrame )( 
            ILMH263Encoder2 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UseDeblockingFilter )( 
            ILMH263Encoder2 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UseDeblockingFilter )( 
            ILMH263Encoder2 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UseAdvancedIntraCoding )( 
            ILMH263Encoder2 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UseAdvancedIntraCoding )( 
            ILMH263Encoder2 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UseAdvancedPredictionMode )( 
            ILMH263Encoder2 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UseAdvancedPredictionMode )( 
            ILMH263Encoder2 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InputFrameRate )( 
            ILMH263Encoder2 * This,
            /* [retval][out] */ float *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutputFrameRate )( 
            ILMH263Encoder2 * This,
            /* [retval][out] */ float *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OutputFrameRate )( 
            ILMH263Encoder2 * This,
            /* [in] */ float newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UseRTP )( 
            ILMH263Encoder2 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UseRTP )( 
            ILMH263Encoder2 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UseSuperCompression )( 
            ILMH263Encoder2 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UseSuperCompression )( 
            ILMH263Encoder2 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IDistanceUnit )( 
            ILMH263Encoder2 * This,
            /* [retval][out] */ eIDISTANCEUNIT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IDistanceUnit )( 
            ILMH263Encoder2 * This,
            /* [in] */ eIDISTANCEUNIT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IDistance )( 
            ILMH263Encoder2 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IDistance )( 
            ILMH263Encoder2 * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PDistance )( 
            ILMH263Encoder2 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PDistance )( 
            ILMH263Encoder2 * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SorensonOutput )( 
            ILMH263Encoder2 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SorensonOutput )( 
            ILMH263Encoder2 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        END_INTERFACE
    } ILMH263Encoder2Vtbl;

    interface ILMH263Encoder2
    {
        CONST_VTBL struct ILMH263Encoder2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMH263Encoder2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMH263Encoder2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMH263Encoder2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMH263Encoder2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMH263Encoder2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMH263Encoder2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMH263Encoder2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMH263Encoder2_get_UseQuality(This,pVal)	\
    ( (This)->lpVtbl -> get_UseQuality(This,pVal) ) 

#define ILMH263Encoder2_put_UseQuality(This,newVal)	\
    ( (This)->lpVtbl -> put_UseQuality(This,newVal) ) 

#define ILMH263Encoder2_get_UsePredefinedQuality(This,pVal)	\
    ( (This)->lpVtbl -> get_UsePredefinedQuality(This,pVal) ) 

#define ILMH263Encoder2_put_UsePredefinedQuality(This,newVal)	\
    ( (This)->lpVtbl -> put_UsePredefinedQuality(This,newVal) ) 

#define ILMH263Encoder2_get_PredefinedQuality(This,pVal)	\
    ( (This)->lpVtbl -> get_PredefinedQuality(This,pVal) ) 

#define ILMH263Encoder2_put_PredefinedQuality(This,newVal)	\
    ( (This)->lpVtbl -> put_PredefinedQuality(This,newVal) ) 

#define ILMH263Encoder2_get_CustomQuality(This,pVal)	\
    ( (This)->lpVtbl -> get_CustomQuality(This,pVal) ) 

#define ILMH263Encoder2_put_CustomQuality(This,newVal)	\
    ( (This)->lpVtbl -> put_CustomQuality(This,newVal) ) 

#define ILMH263Encoder2_get_UsePredefinedBitrate(This,pVal)	\
    ( (This)->lpVtbl -> get_UsePredefinedBitrate(This,pVal) ) 

#define ILMH263Encoder2_put_UsePredefinedBitrate(This,newVal)	\
    ( (This)->lpVtbl -> put_UsePredefinedBitrate(This,newVal) ) 

#define ILMH263Encoder2_get_PredefinedBitrate(This,pVal)	\
    ( (This)->lpVtbl -> get_PredefinedBitrate(This,pVal) ) 

#define ILMH263Encoder2_put_PredefinedBitrate(This,newVal)	\
    ( (This)->lpVtbl -> put_PredefinedBitrate(This,newVal) ) 

#define ILMH263Encoder2_get_CustomBitrate(This,pVal)	\
    ( (This)->lpVtbl -> get_CustomBitrate(This,pVal) ) 

#define ILMH263Encoder2_put_CustomBitrate(This,newVal)	\
    ( (This)->lpVtbl -> put_CustomBitrate(This,newVal) ) 

#define ILMH263Encoder2_get_UsePredefinedSpeed(This,pVal)	\
    ( (This)->lpVtbl -> get_UsePredefinedSpeed(This,pVal) ) 

#define ILMH263Encoder2_put_UsePredefinedSpeed(This,newVal)	\
    ( (This)->lpVtbl -> put_UsePredefinedSpeed(This,newVal) ) 

#define ILMH263Encoder2_get_PredefinedSpeed(This,pVal)	\
    ( (This)->lpVtbl -> get_PredefinedSpeed(This,pVal) ) 

#define ILMH263Encoder2_put_PredefinedSpeed(This,newVal)	\
    ( (This)->lpVtbl -> put_PredefinedSpeed(This,newVal) ) 

#define ILMH263Encoder2_get_UseUnrestrictedMotionVector(This,pVal)	\
    ( (This)->lpVtbl -> get_UseUnrestrictedMotionVector(This,pVal) ) 

#define ILMH263Encoder2_put_UseUnrestrictedMotionVector(This,newVal)	\
    ( (This)->lpVtbl -> put_UseUnrestrictedMotionVector(This,newVal) ) 

#define ILMH263Encoder2_get_UsePBFrame(This,pVal)	\
    ( (This)->lpVtbl -> get_UsePBFrame(This,pVal) ) 

#define ILMH263Encoder2_put_UsePBFrame(This,newVal)	\
    ( (This)->lpVtbl -> put_UsePBFrame(This,newVal) ) 

#define ILMH263Encoder2_get_UseDeblockingFilter(This,pVal)	\
    ( (This)->lpVtbl -> get_UseDeblockingFilter(This,pVal) ) 

#define ILMH263Encoder2_put_UseDeblockingFilter(This,newVal)	\
    ( (This)->lpVtbl -> put_UseDeblockingFilter(This,newVal) ) 

#define ILMH263Encoder2_get_UseAdvancedIntraCoding(This,pVal)	\
    ( (This)->lpVtbl -> get_UseAdvancedIntraCoding(This,pVal) ) 

#define ILMH263Encoder2_put_UseAdvancedIntraCoding(This,newVal)	\
    ( (This)->lpVtbl -> put_UseAdvancedIntraCoding(This,newVal) ) 

#define ILMH263Encoder2_get_UseAdvancedPredictionMode(This,pVal)	\
    ( (This)->lpVtbl -> get_UseAdvancedPredictionMode(This,pVal) ) 

#define ILMH263Encoder2_put_UseAdvancedPredictionMode(This,newVal)	\
    ( (This)->lpVtbl -> put_UseAdvancedPredictionMode(This,newVal) ) 

#define ILMH263Encoder2_get_InputFrameRate(This,pVal)	\
    ( (This)->lpVtbl -> get_InputFrameRate(This,pVal) ) 

#define ILMH263Encoder2_get_OutputFrameRate(This,pVal)	\
    ( (This)->lpVtbl -> get_OutputFrameRate(This,pVal) ) 

#define ILMH263Encoder2_put_OutputFrameRate(This,newVal)	\
    ( (This)->lpVtbl -> put_OutputFrameRate(This,newVal) ) 

#define ILMH263Encoder2_get_UseRTP(This,pVal)	\
    ( (This)->lpVtbl -> get_UseRTP(This,pVal) ) 

#define ILMH263Encoder2_put_UseRTP(This,newVal)	\
    ( (This)->lpVtbl -> put_UseRTP(This,newVal) ) 

#define ILMH263Encoder2_get_UseSuperCompression(This,pVal)	\
    ( (This)->lpVtbl -> get_UseSuperCompression(This,pVal) ) 

#define ILMH263Encoder2_put_UseSuperCompression(This,newVal)	\
    ( (This)->lpVtbl -> put_UseSuperCompression(This,newVal) ) 

#define ILMH263Encoder2_get_IDistanceUnit(This,pVal)	\
    ( (This)->lpVtbl -> get_IDistanceUnit(This,pVal) ) 

#define ILMH263Encoder2_put_IDistanceUnit(This,newVal)	\
    ( (This)->lpVtbl -> put_IDistanceUnit(This,newVal) ) 

#define ILMH263Encoder2_get_IDistance(This,pVal)	\
    ( (This)->lpVtbl -> get_IDistance(This,pVal) ) 

#define ILMH263Encoder2_put_IDistance(This,newVal)	\
    ( (This)->lpVtbl -> put_IDistance(This,newVal) ) 

#define ILMH263Encoder2_get_PDistance(This,pVal)	\
    ( (This)->lpVtbl -> get_PDistance(This,pVal) ) 

#define ILMH263Encoder2_put_PDistance(This,newVal)	\
    ( (This)->lpVtbl -> put_PDistance(This,newVal) ) 


#define ILMH263Encoder2_get_SorensonOutput(This,pVal)	\
    ( (This)->lpVtbl -> get_SorensonOutput(This,pVal) ) 

#define ILMH263Encoder2_put_SorensonOutput(This,newVal)	\
    ( (This)->lpVtbl -> put_SorensonOutput(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMH263Encoder2_INTERFACE_DEFINED__ */


#ifndef __ILMH263Encoder_INTERFACE_DEFINED__
#define __ILMH263Encoder_INTERFACE_DEFINED__

/* interface ILMH263Encoder */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILMH263Encoder;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DE3A-38C5-11D5-91F6-00104BDB8FF9")
    ILMH263Encoder : public ILMH263Encoder2
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ResetToDefaultsEx( 
            /* [in] */ eH263_APILEVEL ApiLevel) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CompatibilityMode( 
            /* [retval][out] */ eH263COMPATIBILITYMODE *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CompatibilityMode( 
            /* [in] */ eH263COMPATIBILITYMODE newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StartChangingAttributes( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StopChangingAttributes( 
            /* [in] */ VARIANT_BOOL bCancelChanges) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMH263EncoderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMH263Encoder * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMH263Encoder * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMH263Encoder * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMH263Encoder * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMH263Encoder * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMH263Encoder * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMH263Encoder * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UseQuality )( 
            ILMH263Encoder * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UseQuality )( 
            ILMH263Encoder * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UsePredefinedQuality )( 
            ILMH263Encoder * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UsePredefinedQuality )( 
            ILMH263Encoder * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PredefinedQuality )( 
            ILMH263Encoder * This,
            /* [retval][out] */ eQUALITY *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PredefinedQuality )( 
            ILMH263Encoder * This,
            /* [in] */ eQUALITY newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CustomQuality )( 
            ILMH263Encoder * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CustomQuality )( 
            ILMH263Encoder * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UsePredefinedBitrate )( 
            ILMH263Encoder * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UsePredefinedBitrate )( 
            ILMH263Encoder * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PredefinedBitrate )( 
            ILMH263Encoder * This,
            /* [retval][out] */ eBITRATE *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PredefinedBitrate )( 
            ILMH263Encoder * This,
            /* [in] */ eBITRATE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CustomBitrate )( 
            ILMH263Encoder * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CustomBitrate )( 
            ILMH263Encoder * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UsePredefinedSpeed )( 
            ILMH263Encoder * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UsePredefinedSpeed )( 
            ILMH263Encoder * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PredefinedSpeed )( 
            ILMH263Encoder * This,
            /* [retval][out] */ eSPEED *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PredefinedSpeed )( 
            ILMH263Encoder * This,
            /* [in] */ eSPEED newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UseUnrestrictedMotionVector )( 
            ILMH263Encoder * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UseUnrestrictedMotionVector )( 
            ILMH263Encoder * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UsePBFrame )( 
            ILMH263Encoder * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UsePBFrame )( 
            ILMH263Encoder * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UseDeblockingFilter )( 
            ILMH263Encoder * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UseDeblockingFilter )( 
            ILMH263Encoder * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UseAdvancedIntraCoding )( 
            ILMH263Encoder * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UseAdvancedIntraCoding )( 
            ILMH263Encoder * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UseAdvancedPredictionMode )( 
            ILMH263Encoder * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UseAdvancedPredictionMode )( 
            ILMH263Encoder * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InputFrameRate )( 
            ILMH263Encoder * This,
            /* [retval][out] */ float *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutputFrameRate )( 
            ILMH263Encoder * This,
            /* [retval][out] */ float *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OutputFrameRate )( 
            ILMH263Encoder * This,
            /* [in] */ float newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UseRTP )( 
            ILMH263Encoder * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UseRTP )( 
            ILMH263Encoder * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UseSuperCompression )( 
            ILMH263Encoder * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UseSuperCompression )( 
            ILMH263Encoder * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IDistanceUnit )( 
            ILMH263Encoder * This,
            /* [retval][out] */ eIDISTANCEUNIT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IDistanceUnit )( 
            ILMH263Encoder * This,
            /* [in] */ eIDISTANCEUNIT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IDistance )( 
            ILMH263Encoder * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IDistance )( 
            ILMH263Encoder * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PDistance )( 
            ILMH263Encoder * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PDistance )( 
            ILMH263Encoder * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SorensonOutput )( 
            ILMH263Encoder * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SorensonOutput )( 
            ILMH263Encoder * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetToDefaultsEx )( 
            ILMH263Encoder * This,
            /* [in] */ eH263_APILEVEL ApiLevel);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CompatibilityMode )( 
            ILMH263Encoder * This,
            /* [retval][out] */ eH263COMPATIBILITYMODE *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CompatibilityMode )( 
            ILMH263Encoder * This,
            /* [in] */ eH263COMPATIBILITYMODE newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StartChangingAttributes )( 
            ILMH263Encoder * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StopChangingAttributes )( 
            ILMH263Encoder * This,
            /* [in] */ VARIANT_BOOL bCancelChanges);
        
        END_INTERFACE
    } ILMH263EncoderVtbl;

    interface ILMH263Encoder
    {
        CONST_VTBL struct ILMH263EncoderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMH263Encoder_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMH263Encoder_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMH263Encoder_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMH263Encoder_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMH263Encoder_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMH263Encoder_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMH263Encoder_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMH263Encoder_get_UseQuality(This,pVal)	\
    ( (This)->lpVtbl -> get_UseQuality(This,pVal) ) 

#define ILMH263Encoder_put_UseQuality(This,newVal)	\
    ( (This)->lpVtbl -> put_UseQuality(This,newVal) ) 

#define ILMH263Encoder_get_UsePredefinedQuality(This,pVal)	\
    ( (This)->lpVtbl -> get_UsePredefinedQuality(This,pVal) ) 

#define ILMH263Encoder_put_UsePredefinedQuality(This,newVal)	\
    ( (This)->lpVtbl -> put_UsePredefinedQuality(This,newVal) ) 

#define ILMH263Encoder_get_PredefinedQuality(This,pVal)	\
    ( (This)->lpVtbl -> get_PredefinedQuality(This,pVal) ) 

#define ILMH263Encoder_put_PredefinedQuality(This,newVal)	\
    ( (This)->lpVtbl -> put_PredefinedQuality(This,newVal) ) 

#define ILMH263Encoder_get_CustomQuality(This,pVal)	\
    ( (This)->lpVtbl -> get_CustomQuality(This,pVal) ) 

#define ILMH263Encoder_put_CustomQuality(This,newVal)	\
    ( (This)->lpVtbl -> put_CustomQuality(This,newVal) ) 

#define ILMH263Encoder_get_UsePredefinedBitrate(This,pVal)	\
    ( (This)->lpVtbl -> get_UsePredefinedBitrate(This,pVal) ) 

#define ILMH263Encoder_put_UsePredefinedBitrate(This,newVal)	\
    ( (This)->lpVtbl -> put_UsePredefinedBitrate(This,newVal) ) 

#define ILMH263Encoder_get_PredefinedBitrate(This,pVal)	\
    ( (This)->lpVtbl -> get_PredefinedBitrate(This,pVal) ) 

#define ILMH263Encoder_put_PredefinedBitrate(This,newVal)	\
    ( (This)->lpVtbl -> put_PredefinedBitrate(This,newVal) ) 

#define ILMH263Encoder_get_CustomBitrate(This,pVal)	\
    ( (This)->lpVtbl -> get_CustomBitrate(This,pVal) ) 

#define ILMH263Encoder_put_CustomBitrate(This,newVal)	\
    ( (This)->lpVtbl -> put_CustomBitrate(This,newVal) ) 

#define ILMH263Encoder_get_UsePredefinedSpeed(This,pVal)	\
    ( (This)->lpVtbl -> get_UsePredefinedSpeed(This,pVal) ) 

#define ILMH263Encoder_put_UsePredefinedSpeed(This,newVal)	\
    ( (This)->lpVtbl -> put_UsePredefinedSpeed(This,newVal) ) 

#define ILMH263Encoder_get_PredefinedSpeed(This,pVal)	\
    ( (This)->lpVtbl -> get_PredefinedSpeed(This,pVal) ) 

#define ILMH263Encoder_put_PredefinedSpeed(This,newVal)	\
    ( (This)->lpVtbl -> put_PredefinedSpeed(This,newVal) ) 

#define ILMH263Encoder_get_UseUnrestrictedMotionVector(This,pVal)	\
    ( (This)->lpVtbl -> get_UseUnrestrictedMotionVector(This,pVal) ) 

#define ILMH263Encoder_put_UseUnrestrictedMotionVector(This,newVal)	\
    ( (This)->lpVtbl -> put_UseUnrestrictedMotionVector(This,newVal) ) 

#define ILMH263Encoder_get_UsePBFrame(This,pVal)	\
    ( (This)->lpVtbl -> get_UsePBFrame(This,pVal) ) 

#define ILMH263Encoder_put_UsePBFrame(This,newVal)	\
    ( (This)->lpVtbl -> put_UsePBFrame(This,newVal) ) 

#define ILMH263Encoder_get_UseDeblockingFilter(This,pVal)	\
    ( (This)->lpVtbl -> get_UseDeblockingFilter(This,pVal) ) 

#define ILMH263Encoder_put_UseDeblockingFilter(This,newVal)	\
    ( (This)->lpVtbl -> put_UseDeblockingFilter(This,newVal) ) 

#define ILMH263Encoder_get_UseAdvancedIntraCoding(This,pVal)	\
    ( (This)->lpVtbl -> get_UseAdvancedIntraCoding(This,pVal) ) 

#define ILMH263Encoder_put_UseAdvancedIntraCoding(This,newVal)	\
    ( (This)->lpVtbl -> put_UseAdvancedIntraCoding(This,newVal) ) 

#define ILMH263Encoder_get_UseAdvancedPredictionMode(This,pVal)	\
    ( (This)->lpVtbl -> get_UseAdvancedPredictionMode(This,pVal) ) 

#define ILMH263Encoder_put_UseAdvancedPredictionMode(This,newVal)	\
    ( (This)->lpVtbl -> put_UseAdvancedPredictionMode(This,newVal) ) 

#define ILMH263Encoder_get_InputFrameRate(This,pVal)	\
    ( (This)->lpVtbl -> get_InputFrameRate(This,pVal) ) 

#define ILMH263Encoder_get_OutputFrameRate(This,pVal)	\
    ( (This)->lpVtbl -> get_OutputFrameRate(This,pVal) ) 

#define ILMH263Encoder_put_OutputFrameRate(This,newVal)	\
    ( (This)->lpVtbl -> put_OutputFrameRate(This,newVal) ) 

#define ILMH263Encoder_get_UseRTP(This,pVal)	\
    ( (This)->lpVtbl -> get_UseRTP(This,pVal) ) 

#define ILMH263Encoder_put_UseRTP(This,newVal)	\
    ( (This)->lpVtbl -> put_UseRTP(This,newVal) ) 

#define ILMH263Encoder_get_UseSuperCompression(This,pVal)	\
    ( (This)->lpVtbl -> get_UseSuperCompression(This,pVal) ) 

#define ILMH263Encoder_put_UseSuperCompression(This,newVal)	\
    ( (This)->lpVtbl -> put_UseSuperCompression(This,newVal) ) 

#define ILMH263Encoder_get_IDistanceUnit(This,pVal)	\
    ( (This)->lpVtbl -> get_IDistanceUnit(This,pVal) ) 

#define ILMH263Encoder_put_IDistanceUnit(This,newVal)	\
    ( (This)->lpVtbl -> put_IDistanceUnit(This,newVal) ) 

#define ILMH263Encoder_get_IDistance(This,pVal)	\
    ( (This)->lpVtbl -> get_IDistance(This,pVal) ) 

#define ILMH263Encoder_put_IDistance(This,newVal)	\
    ( (This)->lpVtbl -> put_IDistance(This,newVal) ) 

#define ILMH263Encoder_get_PDistance(This,pVal)	\
    ( (This)->lpVtbl -> get_PDistance(This,pVal) ) 

#define ILMH263Encoder_put_PDistance(This,newVal)	\
    ( (This)->lpVtbl -> put_PDistance(This,newVal) ) 


#define ILMH263Encoder_get_SorensonOutput(This,pVal)	\
    ( (This)->lpVtbl -> get_SorensonOutput(This,pVal) ) 

#define ILMH263Encoder_put_SorensonOutput(This,newVal)	\
    ( (This)->lpVtbl -> put_SorensonOutput(This,newVal) ) 


#define ILMH263Encoder_ResetToDefaultsEx(This,ApiLevel)	\
    ( (This)->lpVtbl -> ResetToDefaultsEx(This,ApiLevel) ) 

#define ILMH263Encoder_get_CompatibilityMode(This,pVal)	\
    ( (This)->lpVtbl -> get_CompatibilityMode(This,pVal) ) 

#define ILMH263Encoder_put_CompatibilityMode(This,newVal)	\
    ( (This)->lpVtbl -> put_CompatibilityMode(This,newVal) ) 

#define ILMH263Encoder_StartChangingAttributes(This)	\
    ( (This)->lpVtbl -> StartChangingAttributes(This) ) 

#define ILMH263Encoder_StopChangingAttributes(This,bCancelChanges)	\
    ( (This)->lpVtbl -> StopChangingAttributes(This,bCancelChanges) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMH263Encoder_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LMH263Encoder;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DF00-38C5-11D5-91F6-00104BDB8FF9")
LMH263Encoder;
#endif
#endif /* __LMH263EncoderLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


