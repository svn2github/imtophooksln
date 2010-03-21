

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Nov 05 12:35:04 2009
 */
/* Compiler settings for .\ILEncAAC.idl:
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


#ifndef __ILEncAAC_h__
#define __ILEncAAC_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILMAACEncoder1_FWD_DEFINED__
#define __ILMAACEncoder1_FWD_DEFINED__
typedef interface ILMAACEncoder1 ILMAACEncoder1;
#endif 	/* __ILMAACEncoder1_FWD_DEFINED__ */


#ifndef __ILMAACEncoder_FWD_DEFINED__
#define __ILMAACEncoder_FWD_DEFINED__
typedef interface ILMAACEncoder ILMAACEncoder;
#endif 	/* __ILMAACEncoder_FWD_DEFINED__ */


#ifndef __LMAACEncoder_FWD_DEFINED__
#define __LMAACEncoder_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMAACEncoder LMAACEncoder;
#else
typedef struct LMAACEncoder LMAACEncoder;
#endif /* __cplusplus */

#endif 	/* __LMAACEncoder_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LMAACEncoderLib_LIBRARY_DEFINED__
#define __LMAACEncoderLib_LIBRARY_DEFINED__

/* library LMAACEncoderLib */
/* [helpstring][version][uuid] */ 

#ifndef __ILMAACENCODER_H__
#define __ILMAACENCODER_H__
static const GUID CLSID_LMAACEncoder              = {0xe2b7dd70, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMAACEncoder1              = {0xe2b7dd74, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMAACEncoderPropertyPage	 = {0xe2b7dd72, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMAACEncoderAboutPage     = {0xe2b7dd73, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID LIBID_LMAACEncoderLib	          = {0xe2b7dd71, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMAACEncoder               = {0xe2b7dd75, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
#endif 
typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_ILEncAAC_0000_0000_0001
    {	LAAC_OC_UNCHANGED	= 0,
	LAAC_OC_MONO	= 1,
	LAAC_OC_STEREO	= 2,
	LAAC_OC_6CHANNELS	= 3
    } 	eOutputChannels;

 /* LAAC_ObjectType_LC   Old value, should not be used */
 /* LAAC_ObjectType_MAIN Old value, should not be used */
 /* LAAC_ObjectType_LTP  Old value, should not be used */
typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_ILEncAAC_0000_0000_0002
    {	LAAC_ObjectType_LC	= 0,
	LAAC_ObjectType_MAIN	= 1,
	LAAC_ObjectType_LTP	= 3,
	LAAC_ObjType_MAIN	= 0,
	LAAC_ObjType_LC	= 1,
	LAAC_ObjType_LTP	= 3
    } 	eObjectType;

typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_ILEncAAC_0000_0000_0003
    {	LAAC_MPEGVersion_MPEG4	= 0,
	LAAC_MPEGVersion_MPEG2	= 1
    } 	eMPEGVersion;

typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_ILEncAAC_0000_0000_0004
    {	LAAC_BlockType_NORMAL	= 0,
	LAAC_BlockType_NOSHORT	= 1,
	LAAC_BlockType_NOLONG	= 2
    } 	eBlockType;

typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_ILEncAAC_0000_0000_0005
    {	LAAC_RC_CONST_QUALITY	= 0,
	LAAC_RC_CONST_BITRATE	= 1
    } 	eRateControl;

typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_ILEncAAC_0000_0000_0006
    {	LAAC_STREAMFORMAT_RAW	= 0,
	LAAC_STREAMFORMAT_ADTS	= 1
    } 	eStreamFormat;


EXTERN_C const IID LIBID_LMAACEncoderLib;

#ifndef __ILMAACEncoder1_INTERFACE_DEFINED__
#define __ILMAACEncoder1_INTERFACE_DEFINED__

/* interface ILMAACEncoder1 */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ILMAACEncoder1;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DD74-38C5-11D5-91F6-00104BDB8FF9")
    ILMAACEncoder1 : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OutputBitrate( 
            /* [retval][out] */ long *pOutputBitrate) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OutputBitrate( 
            /* [in] */ long lOutputBitrate) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OutputChannels( 
            /* [retval][out] */ eOutputChannels *pOutputChannelFlag) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OutputChannels( 
            /* [in] */ eOutputChannels lOutputChannelFlag) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SimulateSurround( 
            /* [retval][out] */ VARIANT_BOOL *pSimulateSurround) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SimulateSurround( 
            /* [in] */ VARIANT_BOOL bSimulateSurround) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MPEGVersion( 
            /* [retval][out] */ eMPEGVersion *pMPEGVersion) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MPEGVersion( 
            /* [in] */ eMPEGVersion lMPEGVersion) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BlockType( 
            /* [retval][out] */ eBlockType *pBlockType) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_BlockType( 
            /* [in] */ eBlockType lBlockType) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ObjectType( 
            /* [retval][out] */ eObjectType *pObjectType) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ObjectType( 
            /* [in] */ eObjectType lObjectType) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_QFactor( 
            /* [retval][out] */ long *pQFactor) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_QFactor( 
            /* [in] */ long lQFactor) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RateControl( 
            /* [retval][out] */ eRateControl *pRateControl) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RateControl( 
            /* [in] */ eRateControl lRateControl) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Cutoff( 
            /* [retval][out] */ long *pCutoff) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Cutoff( 
            /* [in] */ long lCutoff) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UseCutoff( 
            /* [retval][out] */ VARIANT_BOOL *pUseCutoff) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_UseCutoff( 
            /* [in] */ VARIANT_BOOL bUseCutoff) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StreamFormat( 
            /* [retval][out] */ eStreamFormat *pStreamFormat) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_StreamFormat( 
            /* [in] */ eStreamFormat lStreamFormat) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OutputSampleRate( 
            /* [retval][out] */ long *plSampleRate) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OutputSampleRate( 
            /* [in] */ long lSampleRate) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IgnoreTimeDiscontinuity( 
            /* [retval][out] */ VARIANT_BOOL *pIgnoreTimeDiscontinuity) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_IgnoreTimeDiscontinuity( 
            /* [in] */ VARIANT_BOOL bIgnoreTimeDiscontinuity) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IgnoreTimeOverlapping( 
            /* [retval][out] */ VARIANT_BOOL *pIgnoreTimeOverlapping) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_IgnoreTimeOverlapping( 
            /* [in] */ VARIANT_BOOL bIgnoreTimeOverlapping) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMAACEncoder1Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMAACEncoder1 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMAACEncoder1 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMAACEncoder1 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMAACEncoder1 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMAACEncoder1 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMAACEncoder1 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMAACEncoder1 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutputBitrate )( 
            ILMAACEncoder1 * This,
            /* [retval][out] */ long *pOutputBitrate);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OutputBitrate )( 
            ILMAACEncoder1 * This,
            /* [in] */ long lOutputBitrate);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutputChannels )( 
            ILMAACEncoder1 * This,
            /* [retval][out] */ eOutputChannels *pOutputChannelFlag);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OutputChannels )( 
            ILMAACEncoder1 * This,
            /* [in] */ eOutputChannels lOutputChannelFlag);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SimulateSurround )( 
            ILMAACEncoder1 * This,
            /* [retval][out] */ VARIANT_BOOL *pSimulateSurround);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SimulateSurround )( 
            ILMAACEncoder1 * This,
            /* [in] */ VARIANT_BOOL bSimulateSurround);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MPEGVersion )( 
            ILMAACEncoder1 * This,
            /* [retval][out] */ eMPEGVersion *pMPEGVersion);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MPEGVersion )( 
            ILMAACEncoder1 * This,
            /* [in] */ eMPEGVersion lMPEGVersion);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BlockType )( 
            ILMAACEncoder1 * This,
            /* [retval][out] */ eBlockType *pBlockType);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BlockType )( 
            ILMAACEncoder1 * This,
            /* [in] */ eBlockType lBlockType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectType )( 
            ILMAACEncoder1 * This,
            /* [retval][out] */ eObjectType *pObjectType);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ObjectType )( 
            ILMAACEncoder1 * This,
            /* [in] */ eObjectType lObjectType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_QFactor )( 
            ILMAACEncoder1 * This,
            /* [retval][out] */ long *pQFactor);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_QFactor )( 
            ILMAACEncoder1 * This,
            /* [in] */ long lQFactor);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RateControl )( 
            ILMAACEncoder1 * This,
            /* [retval][out] */ eRateControl *pRateControl);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RateControl )( 
            ILMAACEncoder1 * This,
            /* [in] */ eRateControl lRateControl);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Cutoff )( 
            ILMAACEncoder1 * This,
            /* [retval][out] */ long *pCutoff);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Cutoff )( 
            ILMAACEncoder1 * This,
            /* [in] */ long lCutoff);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UseCutoff )( 
            ILMAACEncoder1 * This,
            /* [retval][out] */ VARIANT_BOOL *pUseCutoff);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UseCutoff )( 
            ILMAACEncoder1 * This,
            /* [in] */ VARIANT_BOOL bUseCutoff);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StreamFormat )( 
            ILMAACEncoder1 * This,
            /* [retval][out] */ eStreamFormat *pStreamFormat);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_StreamFormat )( 
            ILMAACEncoder1 * This,
            /* [in] */ eStreamFormat lStreamFormat);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutputSampleRate )( 
            ILMAACEncoder1 * This,
            /* [retval][out] */ long *plSampleRate);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OutputSampleRate )( 
            ILMAACEncoder1 * This,
            /* [in] */ long lSampleRate);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IgnoreTimeDiscontinuity )( 
            ILMAACEncoder1 * This,
            /* [retval][out] */ VARIANT_BOOL *pIgnoreTimeDiscontinuity);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IgnoreTimeDiscontinuity )( 
            ILMAACEncoder1 * This,
            /* [in] */ VARIANT_BOOL bIgnoreTimeDiscontinuity);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IgnoreTimeOverlapping )( 
            ILMAACEncoder1 * This,
            /* [retval][out] */ VARIANT_BOOL *pIgnoreTimeOverlapping);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IgnoreTimeOverlapping )( 
            ILMAACEncoder1 * This,
            /* [in] */ VARIANT_BOOL bIgnoreTimeOverlapping);
        
        END_INTERFACE
    } ILMAACEncoder1Vtbl;

    interface ILMAACEncoder1
    {
        CONST_VTBL struct ILMAACEncoder1Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMAACEncoder1_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMAACEncoder1_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMAACEncoder1_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMAACEncoder1_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMAACEncoder1_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMAACEncoder1_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMAACEncoder1_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMAACEncoder1_get_OutputBitrate(This,pOutputBitrate)	\
    ( (This)->lpVtbl -> get_OutputBitrate(This,pOutputBitrate) ) 

#define ILMAACEncoder1_put_OutputBitrate(This,lOutputBitrate)	\
    ( (This)->lpVtbl -> put_OutputBitrate(This,lOutputBitrate) ) 

#define ILMAACEncoder1_get_OutputChannels(This,pOutputChannelFlag)	\
    ( (This)->lpVtbl -> get_OutputChannels(This,pOutputChannelFlag) ) 

#define ILMAACEncoder1_put_OutputChannels(This,lOutputChannelFlag)	\
    ( (This)->lpVtbl -> put_OutputChannels(This,lOutputChannelFlag) ) 

#define ILMAACEncoder1_get_SimulateSurround(This,pSimulateSurround)	\
    ( (This)->lpVtbl -> get_SimulateSurround(This,pSimulateSurround) ) 

#define ILMAACEncoder1_put_SimulateSurround(This,bSimulateSurround)	\
    ( (This)->lpVtbl -> put_SimulateSurround(This,bSimulateSurround) ) 

#define ILMAACEncoder1_get_MPEGVersion(This,pMPEGVersion)	\
    ( (This)->lpVtbl -> get_MPEGVersion(This,pMPEGVersion) ) 

#define ILMAACEncoder1_put_MPEGVersion(This,lMPEGVersion)	\
    ( (This)->lpVtbl -> put_MPEGVersion(This,lMPEGVersion) ) 

#define ILMAACEncoder1_get_BlockType(This,pBlockType)	\
    ( (This)->lpVtbl -> get_BlockType(This,pBlockType) ) 

#define ILMAACEncoder1_put_BlockType(This,lBlockType)	\
    ( (This)->lpVtbl -> put_BlockType(This,lBlockType) ) 

#define ILMAACEncoder1_get_ObjectType(This,pObjectType)	\
    ( (This)->lpVtbl -> get_ObjectType(This,pObjectType) ) 

#define ILMAACEncoder1_put_ObjectType(This,lObjectType)	\
    ( (This)->lpVtbl -> put_ObjectType(This,lObjectType) ) 

#define ILMAACEncoder1_get_QFactor(This,pQFactor)	\
    ( (This)->lpVtbl -> get_QFactor(This,pQFactor) ) 

#define ILMAACEncoder1_put_QFactor(This,lQFactor)	\
    ( (This)->lpVtbl -> put_QFactor(This,lQFactor) ) 

#define ILMAACEncoder1_get_RateControl(This,pRateControl)	\
    ( (This)->lpVtbl -> get_RateControl(This,pRateControl) ) 

#define ILMAACEncoder1_put_RateControl(This,lRateControl)	\
    ( (This)->lpVtbl -> put_RateControl(This,lRateControl) ) 

#define ILMAACEncoder1_get_Cutoff(This,pCutoff)	\
    ( (This)->lpVtbl -> get_Cutoff(This,pCutoff) ) 

#define ILMAACEncoder1_put_Cutoff(This,lCutoff)	\
    ( (This)->lpVtbl -> put_Cutoff(This,lCutoff) ) 

#define ILMAACEncoder1_get_UseCutoff(This,pUseCutoff)	\
    ( (This)->lpVtbl -> get_UseCutoff(This,pUseCutoff) ) 

#define ILMAACEncoder1_put_UseCutoff(This,bUseCutoff)	\
    ( (This)->lpVtbl -> put_UseCutoff(This,bUseCutoff) ) 

#define ILMAACEncoder1_get_StreamFormat(This,pStreamFormat)	\
    ( (This)->lpVtbl -> get_StreamFormat(This,pStreamFormat) ) 

#define ILMAACEncoder1_put_StreamFormat(This,lStreamFormat)	\
    ( (This)->lpVtbl -> put_StreamFormat(This,lStreamFormat) ) 

#define ILMAACEncoder1_get_OutputSampleRate(This,plSampleRate)	\
    ( (This)->lpVtbl -> get_OutputSampleRate(This,plSampleRate) ) 

#define ILMAACEncoder1_put_OutputSampleRate(This,lSampleRate)	\
    ( (This)->lpVtbl -> put_OutputSampleRate(This,lSampleRate) ) 

#define ILMAACEncoder1_get_IgnoreTimeDiscontinuity(This,pIgnoreTimeDiscontinuity)	\
    ( (This)->lpVtbl -> get_IgnoreTimeDiscontinuity(This,pIgnoreTimeDiscontinuity) ) 

#define ILMAACEncoder1_put_IgnoreTimeDiscontinuity(This,bIgnoreTimeDiscontinuity)	\
    ( (This)->lpVtbl -> put_IgnoreTimeDiscontinuity(This,bIgnoreTimeDiscontinuity) ) 

#define ILMAACEncoder1_get_IgnoreTimeOverlapping(This,pIgnoreTimeOverlapping)	\
    ( (This)->lpVtbl -> get_IgnoreTimeOverlapping(This,pIgnoreTimeOverlapping) ) 

#define ILMAACEncoder1_put_IgnoreTimeOverlapping(This,bIgnoreTimeOverlapping)	\
    ( (This)->lpVtbl -> put_IgnoreTimeOverlapping(This,bIgnoreTimeOverlapping) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMAACEncoder1_INTERFACE_DEFINED__ */


#ifndef __ILMAACEncoder_INTERFACE_DEFINED__
#define __ILMAACEncoder_INTERFACE_DEFINED__

/* interface ILMAACEncoder */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ILMAACEncoder;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DD75-38C5-11D5-91F6-00104BDB8FF9")
    ILMAACEncoder : public ILMAACEncoder1
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ResetToDefaults( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMAACEncoderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMAACEncoder * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMAACEncoder * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMAACEncoder * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMAACEncoder * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMAACEncoder * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMAACEncoder * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMAACEncoder * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutputBitrate )( 
            ILMAACEncoder * This,
            /* [retval][out] */ long *pOutputBitrate);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OutputBitrate )( 
            ILMAACEncoder * This,
            /* [in] */ long lOutputBitrate);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutputChannels )( 
            ILMAACEncoder * This,
            /* [retval][out] */ eOutputChannels *pOutputChannelFlag);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OutputChannels )( 
            ILMAACEncoder * This,
            /* [in] */ eOutputChannels lOutputChannelFlag);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SimulateSurround )( 
            ILMAACEncoder * This,
            /* [retval][out] */ VARIANT_BOOL *pSimulateSurround);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SimulateSurround )( 
            ILMAACEncoder * This,
            /* [in] */ VARIANT_BOOL bSimulateSurround);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MPEGVersion )( 
            ILMAACEncoder * This,
            /* [retval][out] */ eMPEGVersion *pMPEGVersion);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MPEGVersion )( 
            ILMAACEncoder * This,
            /* [in] */ eMPEGVersion lMPEGVersion);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BlockType )( 
            ILMAACEncoder * This,
            /* [retval][out] */ eBlockType *pBlockType);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BlockType )( 
            ILMAACEncoder * This,
            /* [in] */ eBlockType lBlockType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectType )( 
            ILMAACEncoder * This,
            /* [retval][out] */ eObjectType *pObjectType);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ObjectType )( 
            ILMAACEncoder * This,
            /* [in] */ eObjectType lObjectType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_QFactor )( 
            ILMAACEncoder * This,
            /* [retval][out] */ long *pQFactor);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_QFactor )( 
            ILMAACEncoder * This,
            /* [in] */ long lQFactor);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RateControl )( 
            ILMAACEncoder * This,
            /* [retval][out] */ eRateControl *pRateControl);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RateControl )( 
            ILMAACEncoder * This,
            /* [in] */ eRateControl lRateControl);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Cutoff )( 
            ILMAACEncoder * This,
            /* [retval][out] */ long *pCutoff);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Cutoff )( 
            ILMAACEncoder * This,
            /* [in] */ long lCutoff);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UseCutoff )( 
            ILMAACEncoder * This,
            /* [retval][out] */ VARIANT_BOOL *pUseCutoff);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UseCutoff )( 
            ILMAACEncoder * This,
            /* [in] */ VARIANT_BOOL bUseCutoff);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StreamFormat )( 
            ILMAACEncoder * This,
            /* [retval][out] */ eStreamFormat *pStreamFormat);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_StreamFormat )( 
            ILMAACEncoder * This,
            /* [in] */ eStreamFormat lStreamFormat);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutputSampleRate )( 
            ILMAACEncoder * This,
            /* [retval][out] */ long *plSampleRate);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OutputSampleRate )( 
            ILMAACEncoder * This,
            /* [in] */ long lSampleRate);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IgnoreTimeDiscontinuity )( 
            ILMAACEncoder * This,
            /* [retval][out] */ VARIANT_BOOL *pIgnoreTimeDiscontinuity);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IgnoreTimeDiscontinuity )( 
            ILMAACEncoder * This,
            /* [in] */ VARIANT_BOOL bIgnoreTimeDiscontinuity);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IgnoreTimeOverlapping )( 
            ILMAACEncoder * This,
            /* [retval][out] */ VARIANT_BOOL *pIgnoreTimeOverlapping);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IgnoreTimeOverlapping )( 
            ILMAACEncoder * This,
            /* [in] */ VARIANT_BOOL bIgnoreTimeOverlapping);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetToDefaults )( 
            ILMAACEncoder * This);
        
        END_INTERFACE
    } ILMAACEncoderVtbl;

    interface ILMAACEncoder
    {
        CONST_VTBL struct ILMAACEncoderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMAACEncoder_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMAACEncoder_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMAACEncoder_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMAACEncoder_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMAACEncoder_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMAACEncoder_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMAACEncoder_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMAACEncoder_get_OutputBitrate(This,pOutputBitrate)	\
    ( (This)->lpVtbl -> get_OutputBitrate(This,pOutputBitrate) ) 

#define ILMAACEncoder_put_OutputBitrate(This,lOutputBitrate)	\
    ( (This)->lpVtbl -> put_OutputBitrate(This,lOutputBitrate) ) 

#define ILMAACEncoder_get_OutputChannels(This,pOutputChannelFlag)	\
    ( (This)->lpVtbl -> get_OutputChannels(This,pOutputChannelFlag) ) 

#define ILMAACEncoder_put_OutputChannels(This,lOutputChannelFlag)	\
    ( (This)->lpVtbl -> put_OutputChannels(This,lOutputChannelFlag) ) 

#define ILMAACEncoder_get_SimulateSurround(This,pSimulateSurround)	\
    ( (This)->lpVtbl -> get_SimulateSurround(This,pSimulateSurround) ) 

#define ILMAACEncoder_put_SimulateSurround(This,bSimulateSurround)	\
    ( (This)->lpVtbl -> put_SimulateSurround(This,bSimulateSurround) ) 

#define ILMAACEncoder_get_MPEGVersion(This,pMPEGVersion)	\
    ( (This)->lpVtbl -> get_MPEGVersion(This,pMPEGVersion) ) 

#define ILMAACEncoder_put_MPEGVersion(This,lMPEGVersion)	\
    ( (This)->lpVtbl -> put_MPEGVersion(This,lMPEGVersion) ) 

#define ILMAACEncoder_get_BlockType(This,pBlockType)	\
    ( (This)->lpVtbl -> get_BlockType(This,pBlockType) ) 

#define ILMAACEncoder_put_BlockType(This,lBlockType)	\
    ( (This)->lpVtbl -> put_BlockType(This,lBlockType) ) 

#define ILMAACEncoder_get_ObjectType(This,pObjectType)	\
    ( (This)->lpVtbl -> get_ObjectType(This,pObjectType) ) 

#define ILMAACEncoder_put_ObjectType(This,lObjectType)	\
    ( (This)->lpVtbl -> put_ObjectType(This,lObjectType) ) 

#define ILMAACEncoder_get_QFactor(This,pQFactor)	\
    ( (This)->lpVtbl -> get_QFactor(This,pQFactor) ) 

#define ILMAACEncoder_put_QFactor(This,lQFactor)	\
    ( (This)->lpVtbl -> put_QFactor(This,lQFactor) ) 

#define ILMAACEncoder_get_RateControl(This,pRateControl)	\
    ( (This)->lpVtbl -> get_RateControl(This,pRateControl) ) 

#define ILMAACEncoder_put_RateControl(This,lRateControl)	\
    ( (This)->lpVtbl -> put_RateControl(This,lRateControl) ) 

#define ILMAACEncoder_get_Cutoff(This,pCutoff)	\
    ( (This)->lpVtbl -> get_Cutoff(This,pCutoff) ) 

#define ILMAACEncoder_put_Cutoff(This,lCutoff)	\
    ( (This)->lpVtbl -> put_Cutoff(This,lCutoff) ) 

#define ILMAACEncoder_get_UseCutoff(This,pUseCutoff)	\
    ( (This)->lpVtbl -> get_UseCutoff(This,pUseCutoff) ) 

#define ILMAACEncoder_put_UseCutoff(This,bUseCutoff)	\
    ( (This)->lpVtbl -> put_UseCutoff(This,bUseCutoff) ) 

#define ILMAACEncoder_get_StreamFormat(This,pStreamFormat)	\
    ( (This)->lpVtbl -> get_StreamFormat(This,pStreamFormat) ) 

#define ILMAACEncoder_put_StreamFormat(This,lStreamFormat)	\
    ( (This)->lpVtbl -> put_StreamFormat(This,lStreamFormat) ) 

#define ILMAACEncoder_get_OutputSampleRate(This,plSampleRate)	\
    ( (This)->lpVtbl -> get_OutputSampleRate(This,plSampleRate) ) 

#define ILMAACEncoder_put_OutputSampleRate(This,lSampleRate)	\
    ( (This)->lpVtbl -> put_OutputSampleRate(This,lSampleRate) ) 

#define ILMAACEncoder_get_IgnoreTimeDiscontinuity(This,pIgnoreTimeDiscontinuity)	\
    ( (This)->lpVtbl -> get_IgnoreTimeDiscontinuity(This,pIgnoreTimeDiscontinuity) ) 

#define ILMAACEncoder_put_IgnoreTimeDiscontinuity(This,bIgnoreTimeDiscontinuity)	\
    ( (This)->lpVtbl -> put_IgnoreTimeDiscontinuity(This,bIgnoreTimeDiscontinuity) ) 

#define ILMAACEncoder_get_IgnoreTimeOverlapping(This,pIgnoreTimeOverlapping)	\
    ( (This)->lpVtbl -> get_IgnoreTimeOverlapping(This,pIgnoreTimeOverlapping) ) 

#define ILMAACEncoder_put_IgnoreTimeOverlapping(This,bIgnoreTimeOverlapping)	\
    ( (This)->lpVtbl -> put_IgnoreTimeOverlapping(This,bIgnoreTimeOverlapping) ) 


#define ILMAACEncoder_ResetToDefaults(This)	\
    ( (This)->lpVtbl -> ResetToDefaults(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMAACEncoder_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LMAACEncoder;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DD70-38C5-11D5-91F6-00104BDB8FF9")
LMAACEncoder;
#endif
#endif /* __LMAACEncoderLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


