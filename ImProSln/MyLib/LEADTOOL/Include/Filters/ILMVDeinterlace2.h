

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Mon Dec 21 12:47:46 2009
 */
/* Compiler settings for .\IDeinterlace.idl:
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


#ifndef __ILMVDeinterlace2_h__
#define __ILMVDeinterlace2_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILMVDeinterlace1_FWD_DEFINED__
#define __ILMVDeinterlace1_FWD_DEFINED__
typedef interface ILMVDeinterlace1 ILMVDeinterlace1;
#endif 	/* __ILMVDeinterlace1_FWD_DEFINED__ */


#ifndef __ILMVDeinterlace_FWD_DEFINED__
#define __ILMVDeinterlace_FWD_DEFINED__
typedef interface ILMVDeinterlace ILMVDeinterlace;
#endif 	/* __ILMVDeinterlace_FWD_DEFINED__ */


#ifndef __LMVDeinterlace_FWD_DEFINED__
#define __LMVDeinterlace_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMVDeinterlace LMVDeinterlace;
#else
typedef struct LMVDeinterlace LMVDeinterlace;
#endif /* __cplusplus */

#endif 	/* __LMVDeinterlace_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LMVDeinterlaceLib_LIBRARY_DEFINED__
#define __LMVDeinterlaceLib_LIBRARY_DEFINED__

/* library LMVDeinterlaceLib */
/* [helpstring][version][uuid] */ 

#ifndef __Deinterlace2_H__
#define __Deinterlace2_H__
static const GUID CLSID_LMVDeinterlace				= {0xe2b7dd90, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVDeinterlacePropertyPage	= {0xe2b7dd91, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVDeinterlaceROIPropertyPage = {0xe2b7dd92, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVDeinterlaceIOPropertyPage  = {0xe2b7dd93, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b,0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMVDeinterlace1					= {0xe2b7dd94, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMVDeinterlace					= {0xe2b7df60, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVAboutDeinterlace			= {0xe2b7dd95, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID LIBID_LMVDeinterlaceLib				= {0xe2b7dd96, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
#endif 
typedef 
enum sSEGMENT_OPERATION_MODE
    {	MODE_NO_DEINTERLACE	= 0,
	MODE_DEINTERLACE_ALL	= ( MODE_NO_DEINTERLACE + 1 ) ,
	MODE_DEINTERLACE_PATTERN	= ( MODE_DEINTERLACE_ALL + 1 ) 
    } 	SEGMENT_OPERATION_MODE;

typedef 
enum sSEGMENT_TIME_FORMAT
    {	SEGMENT_TIME_FORMAT_FRAME	= 0,
	SEGMENT_TIME_FORMAT_TIME	= ( SEGMENT_TIME_FORMAT_FRAME + 1 ) 
    } 	SEGMENT_TIME_FORMAT;

typedef 
enum _LMVDeinterlace_APILEVEL
    {	LMVDeinterlace_APILEVEL_1	= 0,
	LMVDeinterlace_APILEVEL_2	= 1
    } 	_LMVDeinterlace_APILEVEL;


EXTERN_C const IID LIBID_LMVDeinterlaceLib;

#ifndef __ILMVDeinterlace1_INTERFACE_DEFINED__
#define __ILMVDeinterlace1_INTERFACE_DEFINED__

/* interface ILMVDeinterlace1 */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ILMVDeinterlace1;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DD94-38C5-11D5-91F6-00104BDB8FF9")
    ILMVDeinterlace1 : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Enabled( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Enabled( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Even( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Even( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Resize( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Resize( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsLEADInputPinConnected( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsLEADOutputPinConnected( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_InWidth( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_InHeight( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OutWidth( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OutHeight( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_InBits( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OutBits( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DoubleFrameRate( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DoubleFrameRate( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StartWithEvenFrame( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_StartWithEvenFrame( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EnableROI( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_EnableROI( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ROILeft( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ROILeft( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ROITop( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ROITop( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ROIRight( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ROIRight( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ROIBottom( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ROIBottom( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EnableGlobalPattern( 
            /* [retval][out] */ VARIANT_BOOL *pDintPre) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_EnableGlobalPattern( 
            /* [in] */ VARIANT_BOOL DintPre) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetGlobalPattern( 
            long PreambleFrames,
            long NoDeinterlaceFrames,
            long DeinterlaceFrames,
            VARIANT_BOOL DeintPreamble) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetGlobalPattern( 
            long *pPreambleFrames,
            long *pNoDeinterlaceFrames,
            long *pDeinterlaceFrames,
            VARIANT_BOOL *pDeintPreamble) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddSegment( 
            long Index) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveSegment( 
            long Index) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetSegmentData( 
            long Index,
            long SegmentData) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetSegmentData( 
            long Index,
            long *pSegmentData) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SegmentsCount( 
            long *pCount) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SegmentsTimeFormat( 
            /* [retval][out] */ SEGMENT_TIME_FORMAT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SegmentsTimeFormat( 
            /* [in] */ SEGMENT_TIME_FORMAT newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetSegmentStartTime( 
            long Index,
            long *pHours,
            long *pMinutes,
            long *pSeconds,
            long *pMilliSeconds) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetSegmentStartTime( 
            long Index,
            long Hours,
            long Minutes,
            long Seconds,
            long MilliSeconds) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetSegmentStartFrame( 
            long Index,
            LONGLONG *pStartFrame) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetSegmentStartFrame( 
            long Index,
            LONGLONG StartFrame) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetSegmentOperationMode( 
            long Index,
            SEGMENT_OPERATION_MODE *pOperationMode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetSegmentOperationMode( 
            long Index,
            SEGMENT_OPERATION_MODE OperationMode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetSegmentPattern( 
            long Index,
            long *pPreambleFrames,
            long *pIgnoreFrames,
            long *pDeinterlaceFrames,
            VARIANT_BOOL *pDeintPreamble) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetSegmentPattern( 
            long Index,
            long PreambleFrames,
            long IgnoreFrames,
            long DeinterlaceFrames,
            VARIANT_BOOL DeintPreamble) = 0;
        
        virtual /* [helpstring][id][hidden][propget] */ HRESULT STDMETHODCALLTYPE get_FrameRate( 
            /* [retval][out] */ double *pFrameRate) = 0;
        
        virtual /* [helpstring][id][hidden][propput] */ HRESULT STDMETHODCALLTYPE put_FrameRate( 
            /* [in] */ double FrameRate) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EnableProtectedArea( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_EnableProtectedArea( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetProtectedAreaParams( 
            /* [in] */ long Left,
            /* [in] */ long Right,
            /* [in] */ long Top,
            /* [in] */ long Bottom) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetProtectedAreaParams( 
            /* [out] */ long *Left,
            /* [out] */ long *Right,
            /* [out] */ long *Top,
            /* [out] */ long *Bottom) = 0;
        
        virtual /* [helpstring][id][hidden][propget] */ HRESULT STDMETHODCALLTYPE get_DeinterlaceSettingsImportState( 
            /* [retval][out] */ VARIANT_BOOL *pNew) = 0;
        
        virtual /* [helpstring][id][hidden][propput] */ HRESULT STDMETHODCALLTYPE put_DeinterlaceSettingsImportState( 
            /* [in] */ VARIANT_BOOL New) = 0;
        
        virtual /* [helpstring][id][hidden][propget] */ HRESULT STDMETHODCALLTYPE get_ROISettingsImportState( 
            /* [retval][out] */ VARIANT_BOOL *pNew) = 0;
        
        virtual /* [helpstring][id][hidden][propput] */ HRESULT STDMETHODCALLTYPE put_ROISettingsImportState( 
            /* [in] */ VARIANT_BOOL New) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AutoDeinterlace( 
            /* [retval][out] */ VARIANT_BOOL *pNew) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AutoDeinterlace( 
            /* [in] */ VARIANT_BOOL New) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ResetToDefaults( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMVDeinterlace1Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMVDeinterlace1 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMVDeinterlace1 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMVDeinterlace1 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMVDeinterlace1 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMVDeinterlace1 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMVDeinterlace1 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMVDeinterlace1 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Enabled )( 
            ILMVDeinterlace1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Enabled )( 
            ILMVDeinterlace1 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Even )( 
            ILMVDeinterlace1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Even )( 
            ILMVDeinterlace1 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Resize )( 
            ILMVDeinterlace1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Resize )( 
            ILMVDeinterlace1 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsLEADInputPinConnected )( 
            ILMVDeinterlace1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsLEADOutputPinConnected )( 
            ILMVDeinterlace1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InWidth )( 
            ILMVDeinterlace1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InHeight )( 
            ILMVDeinterlace1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutWidth )( 
            ILMVDeinterlace1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutHeight )( 
            ILMVDeinterlace1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InBits )( 
            ILMVDeinterlace1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutBits )( 
            ILMVDeinterlace1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DoubleFrameRate )( 
            ILMVDeinterlace1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DoubleFrameRate )( 
            ILMVDeinterlace1 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StartWithEvenFrame )( 
            ILMVDeinterlace1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_StartWithEvenFrame )( 
            ILMVDeinterlace1 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableROI )( 
            ILMVDeinterlace1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableROI )( 
            ILMVDeinterlace1 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ROILeft )( 
            ILMVDeinterlace1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ROILeft )( 
            ILMVDeinterlace1 * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ROITop )( 
            ILMVDeinterlace1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ROITop )( 
            ILMVDeinterlace1 * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ROIRight )( 
            ILMVDeinterlace1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ROIRight )( 
            ILMVDeinterlace1 * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ROIBottom )( 
            ILMVDeinterlace1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ROIBottom )( 
            ILMVDeinterlace1 * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableGlobalPattern )( 
            ILMVDeinterlace1 * This,
            /* [retval][out] */ VARIANT_BOOL *pDintPre);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableGlobalPattern )( 
            ILMVDeinterlace1 * This,
            /* [in] */ VARIANT_BOOL DintPre);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetGlobalPattern )( 
            ILMVDeinterlace1 * This,
            long PreambleFrames,
            long NoDeinterlaceFrames,
            long DeinterlaceFrames,
            VARIANT_BOOL DeintPreamble);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetGlobalPattern )( 
            ILMVDeinterlace1 * This,
            long *pPreambleFrames,
            long *pNoDeinterlaceFrames,
            long *pDeinterlaceFrames,
            VARIANT_BOOL *pDeintPreamble);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddSegment )( 
            ILMVDeinterlace1 * This,
            long Index);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemoveSegment )( 
            ILMVDeinterlace1 * This,
            long Index);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetSegmentData )( 
            ILMVDeinterlace1 * This,
            long Index,
            long SegmentData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetSegmentData )( 
            ILMVDeinterlace1 * This,
            long Index,
            long *pSegmentData);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SegmentsCount )( 
            ILMVDeinterlace1 * This,
            long *pCount);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SegmentsTimeFormat )( 
            ILMVDeinterlace1 * This,
            /* [retval][out] */ SEGMENT_TIME_FORMAT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SegmentsTimeFormat )( 
            ILMVDeinterlace1 * This,
            /* [in] */ SEGMENT_TIME_FORMAT newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetSegmentStartTime )( 
            ILMVDeinterlace1 * This,
            long Index,
            long *pHours,
            long *pMinutes,
            long *pSeconds,
            long *pMilliSeconds);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetSegmentStartTime )( 
            ILMVDeinterlace1 * This,
            long Index,
            long Hours,
            long Minutes,
            long Seconds,
            long MilliSeconds);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetSegmentStartFrame )( 
            ILMVDeinterlace1 * This,
            long Index,
            LONGLONG *pStartFrame);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetSegmentStartFrame )( 
            ILMVDeinterlace1 * This,
            long Index,
            LONGLONG StartFrame);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetSegmentOperationMode )( 
            ILMVDeinterlace1 * This,
            long Index,
            SEGMENT_OPERATION_MODE *pOperationMode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetSegmentOperationMode )( 
            ILMVDeinterlace1 * This,
            long Index,
            SEGMENT_OPERATION_MODE OperationMode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetSegmentPattern )( 
            ILMVDeinterlace1 * This,
            long Index,
            long *pPreambleFrames,
            long *pIgnoreFrames,
            long *pDeinterlaceFrames,
            VARIANT_BOOL *pDeintPreamble);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetSegmentPattern )( 
            ILMVDeinterlace1 * This,
            long Index,
            long PreambleFrames,
            long IgnoreFrames,
            long DeinterlaceFrames,
            VARIANT_BOOL DeintPreamble);
        
        /* [helpstring][id][hidden][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FrameRate )( 
            ILMVDeinterlace1 * This,
            /* [retval][out] */ double *pFrameRate);
        
        /* [helpstring][id][hidden][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FrameRate )( 
            ILMVDeinterlace1 * This,
            /* [in] */ double FrameRate);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableProtectedArea )( 
            ILMVDeinterlace1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableProtectedArea )( 
            ILMVDeinterlace1 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetProtectedAreaParams )( 
            ILMVDeinterlace1 * This,
            /* [in] */ long Left,
            /* [in] */ long Right,
            /* [in] */ long Top,
            /* [in] */ long Bottom);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetProtectedAreaParams )( 
            ILMVDeinterlace1 * This,
            /* [out] */ long *Left,
            /* [out] */ long *Right,
            /* [out] */ long *Top,
            /* [out] */ long *Bottom);
        
        /* [helpstring][id][hidden][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DeinterlaceSettingsImportState )( 
            ILMVDeinterlace1 * This,
            /* [retval][out] */ VARIANT_BOOL *pNew);
        
        /* [helpstring][id][hidden][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DeinterlaceSettingsImportState )( 
            ILMVDeinterlace1 * This,
            /* [in] */ VARIANT_BOOL New);
        
        /* [helpstring][id][hidden][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ROISettingsImportState )( 
            ILMVDeinterlace1 * This,
            /* [retval][out] */ VARIANT_BOOL *pNew);
        
        /* [helpstring][id][hidden][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ROISettingsImportState )( 
            ILMVDeinterlace1 * This,
            /* [in] */ VARIANT_BOOL New);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AutoDeinterlace )( 
            ILMVDeinterlace1 * This,
            /* [retval][out] */ VARIANT_BOOL *pNew);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AutoDeinterlace )( 
            ILMVDeinterlace1 * This,
            /* [in] */ VARIANT_BOOL New);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetToDefaults )( 
            ILMVDeinterlace1 * This);
        
        END_INTERFACE
    } ILMVDeinterlace1Vtbl;

    interface ILMVDeinterlace1
    {
        CONST_VTBL struct ILMVDeinterlace1Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMVDeinterlace1_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMVDeinterlace1_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMVDeinterlace1_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMVDeinterlace1_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMVDeinterlace1_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMVDeinterlace1_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMVDeinterlace1_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMVDeinterlace1_get_Enabled(This,pVal)	\
    ( (This)->lpVtbl -> get_Enabled(This,pVal) ) 

#define ILMVDeinterlace1_put_Enabled(This,newVal)	\
    ( (This)->lpVtbl -> put_Enabled(This,newVal) ) 

#define ILMVDeinterlace1_get_Even(This,pVal)	\
    ( (This)->lpVtbl -> get_Even(This,pVal) ) 

#define ILMVDeinterlace1_put_Even(This,newVal)	\
    ( (This)->lpVtbl -> put_Even(This,newVal) ) 

#define ILMVDeinterlace1_get_Resize(This,pVal)	\
    ( (This)->lpVtbl -> get_Resize(This,pVal) ) 

#define ILMVDeinterlace1_put_Resize(This,newVal)	\
    ( (This)->lpVtbl -> put_Resize(This,newVal) ) 

#define ILMVDeinterlace1_get_IsLEADInputPinConnected(This,pVal)	\
    ( (This)->lpVtbl -> get_IsLEADInputPinConnected(This,pVal) ) 

#define ILMVDeinterlace1_get_IsLEADOutputPinConnected(This,pVal)	\
    ( (This)->lpVtbl -> get_IsLEADOutputPinConnected(This,pVal) ) 

#define ILMVDeinterlace1_get_InWidth(This,pVal)	\
    ( (This)->lpVtbl -> get_InWidth(This,pVal) ) 

#define ILMVDeinterlace1_get_InHeight(This,pVal)	\
    ( (This)->lpVtbl -> get_InHeight(This,pVal) ) 

#define ILMVDeinterlace1_get_OutWidth(This,pVal)	\
    ( (This)->lpVtbl -> get_OutWidth(This,pVal) ) 

#define ILMVDeinterlace1_get_OutHeight(This,pVal)	\
    ( (This)->lpVtbl -> get_OutHeight(This,pVal) ) 

#define ILMVDeinterlace1_get_InBits(This,pVal)	\
    ( (This)->lpVtbl -> get_InBits(This,pVal) ) 

#define ILMVDeinterlace1_get_OutBits(This,pVal)	\
    ( (This)->lpVtbl -> get_OutBits(This,pVal) ) 

#define ILMVDeinterlace1_get_DoubleFrameRate(This,pVal)	\
    ( (This)->lpVtbl -> get_DoubleFrameRate(This,pVal) ) 

#define ILMVDeinterlace1_put_DoubleFrameRate(This,newVal)	\
    ( (This)->lpVtbl -> put_DoubleFrameRate(This,newVal) ) 

#define ILMVDeinterlace1_get_StartWithEvenFrame(This,pVal)	\
    ( (This)->lpVtbl -> get_StartWithEvenFrame(This,pVal) ) 

#define ILMVDeinterlace1_put_StartWithEvenFrame(This,newVal)	\
    ( (This)->lpVtbl -> put_StartWithEvenFrame(This,newVal) ) 

#define ILMVDeinterlace1_get_EnableROI(This,pVal)	\
    ( (This)->lpVtbl -> get_EnableROI(This,pVal) ) 

#define ILMVDeinterlace1_put_EnableROI(This,newVal)	\
    ( (This)->lpVtbl -> put_EnableROI(This,newVal) ) 

#define ILMVDeinterlace1_get_ROILeft(This,pVal)	\
    ( (This)->lpVtbl -> get_ROILeft(This,pVal) ) 

#define ILMVDeinterlace1_put_ROILeft(This,newVal)	\
    ( (This)->lpVtbl -> put_ROILeft(This,newVal) ) 

#define ILMVDeinterlace1_get_ROITop(This,pVal)	\
    ( (This)->lpVtbl -> get_ROITop(This,pVal) ) 

#define ILMVDeinterlace1_put_ROITop(This,newVal)	\
    ( (This)->lpVtbl -> put_ROITop(This,newVal) ) 

#define ILMVDeinterlace1_get_ROIRight(This,pVal)	\
    ( (This)->lpVtbl -> get_ROIRight(This,pVal) ) 

#define ILMVDeinterlace1_put_ROIRight(This,newVal)	\
    ( (This)->lpVtbl -> put_ROIRight(This,newVal) ) 

#define ILMVDeinterlace1_get_ROIBottom(This,pVal)	\
    ( (This)->lpVtbl -> get_ROIBottom(This,pVal) ) 

#define ILMVDeinterlace1_put_ROIBottom(This,newVal)	\
    ( (This)->lpVtbl -> put_ROIBottom(This,newVal) ) 

#define ILMVDeinterlace1_get_EnableGlobalPattern(This,pDintPre)	\
    ( (This)->lpVtbl -> get_EnableGlobalPattern(This,pDintPre) ) 

#define ILMVDeinterlace1_put_EnableGlobalPattern(This,DintPre)	\
    ( (This)->lpVtbl -> put_EnableGlobalPattern(This,DintPre) ) 

#define ILMVDeinterlace1_SetGlobalPattern(This,PreambleFrames,NoDeinterlaceFrames,DeinterlaceFrames,DeintPreamble)	\
    ( (This)->lpVtbl -> SetGlobalPattern(This,PreambleFrames,NoDeinterlaceFrames,DeinterlaceFrames,DeintPreamble) ) 

#define ILMVDeinterlace1_GetGlobalPattern(This,pPreambleFrames,pNoDeinterlaceFrames,pDeinterlaceFrames,pDeintPreamble)	\
    ( (This)->lpVtbl -> GetGlobalPattern(This,pPreambleFrames,pNoDeinterlaceFrames,pDeinterlaceFrames,pDeintPreamble) ) 

#define ILMVDeinterlace1_AddSegment(This,Index)	\
    ( (This)->lpVtbl -> AddSegment(This,Index) ) 

#define ILMVDeinterlace1_RemoveSegment(This,Index)	\
    ( (This)->lpVtbl -> RemoveSegment(This,Index) ) 

#define ILMVDeinterlace1_SetSegmentData(This,Index,SegmentData)	\
    ( (This)->lpVtbl -> SetSegmentData(This,Index,SegmentData) ) 

#define ILMVDeinterlace1_GetSegmentData(This,Index,pSegmentData)	\
    ( (This)->lpVtbl -> GetSegmentData(This,Index,pSegmentData) ) 

#define ILMVDeinterlace1_get_SegmentsCount(This,pCount)	\
    ( (This)->lpVtbl -> get_SegmentsCount(This,pCount) ) 

#define ILMVDeinterlace1_get_SegmentsTimeFormat(This,pVal)	\
    ( (This)->lpVtbl -> get_SegmentsTimeFormat(This,pVal) ) 

#define ILMVDeinterlace1_put_SegmentsTimeFormat(This,newVal)	\
    ( (This)->lpVtbl -> put_SegmentsTimeFormat(This,newVal) ) 

#define ILMVDeinterlace1_GetSegmentStartTime(This,Index,pHours,pMinutes,pSeconds,pMilliSeconds)	\
    ( (This)->lpVtbl -> GetSegmentStartTime(This,Index,pHours,pMinutes,pSeconds,pMilliSeconds) ) 

#define ILMVDeinterlace1_SetSegmentStartTime(This,Index,Hours,Minutes,Seconds,MilliSeconds)	\
    ( (This)->lpVtbl -> SetSegmentStartTime(This,Index,Hours,Minutes,Seconds,MilliSeconds) ) 

#define ILMVDeinterlace1_GetSegmentStartFrame(This,Index,pStartFrame)	\
    ( (This)->lpVtbl -> GetSegmentStartFrame(This,Index,pStartFrame) ) 

#define ILMVDeinterlace1_SetSegmentStartFrame(This,Index,StartFrame)	\
    ( (This)->lpVtbl -> SetSegmentStartFrame(This,Index,StartFrame) ) 

#define ILMVDeinterlace1_GetSegmentOperationMode(This,Index,pOperationMode)	\
    ( (This)->lpVtbl -> GetSegmentOperationMode(This,Index,pOperationMode) ) 

#define ILMVDeinterlace1_SetSegmentOperationMode(This,Index,OperationMode)	\
    ( (This)->lpVtbl -> SetSegmentOperationMode(This,Index,OperationMode) ) 

#define ILMVDeinterlace1_GetSegmentPattern(This,Index,pPreambleFrames,pIgnoreFrames,pDeinterlaceFrames,pDeintPreamble)	\
    ( (This)->lpVtbl -> GetSegmentPattern(This,Index,pPreambleFrames,pIgnoreFrames,pDeinterlaceFrames,pDeintPreamble) ) 

#define ILMVDeinterlace1_SetSegmentPattern(This,Index,PreambleFrames,IgnoreFrames,DeinterlaceFrames,DeintPreamble)	\
    ( (This)->lpVtbl -> SetSegmentPattern(This,Index,PreambleFrames,IgnoreFrames,DeinterlaceFrames,DeintPreamble) ) 

#define ILMVDeinterlace1_get_FrameRate(This,pFrameRate)	\
    ( (This)->lpVtbl -> get_FrameRate(This,pFrameRate) ) 

#define ILMVDeinterlace1_put_FrameRate(This,FrameRate)	\
    ( (This)->lpVtbl -> put_FrameRate(This,FrameRate) ) 

#define ILMVDeinterlace1_get_EnableProtectedArea(This,pVal)	\
    ( (This)->lpVtbl -> get_EnableProtectedArea(This,pVal) ) 

#define ILMVDeinterlace1_put_EnableProtectedArea(This,newVal)	\
    ( (This)->lpVtbl -> put_EnableProtectedArea(This,newVal) ) 

#define ILMVDeinterlace1_SetProtectedAreaParams(This,Left,Right,Top,Bottom)	\
    ( (This)->lpVtbl -> SetProtectedAreaParams(This,Left,Right,Top,Bottom) ) 

#define ILMVDeinterlace1_GetProtectedAreaParams(This,Left,Right,Top,Bottom)	\
    ( (This)->lpVtbl -> GetProtectedAreaParams(This,Left,Right,Top,Bottom) ) 

#define ILMVDeinterlace1_get_DeinterlaceSettingsImportState(This,pNew)	\
    ( (This)->lpVtbl -> get_DeinterlaceSettingsImportState(This,pNew) ) 

#define ILMVDeinterlace1_put_DeinterlaceSettingsImportState(This,New)	\
    ( (This)->lpVtbl -> put_DeinterlaceSettingsImportState(This,New) ) 

#define ILMVDeinterlace1_get_ROISettingsImportState(This,pNew)	\
    ( (This)->lpVtbl -> get_ROISettingsImportState(This,pNew) ) 

#define ILMVDeinterlace1_put_ROISettingsImportState(This,New)	\
    ( (This)->lpVtbl -> put_ROISettingsImportState(This,New) ) 

#define ILMVDeinterlace1_get_AutoDeinterlace(This,pNew)	\
    ( (This)->lpVtbl -> get_AutoDeinterlace(This,pNew) ) 

#define ILMVDeinterlace1_put_AutoDeinterlace(This,New)	\
    ( (This)->lpVtbl -> put_AutoDeinterlace(This,New) ) 

#define ILMVDeinterlace1_ResetToDefaults(This)	\
    ( (This)->lpVtbl -> ResetToDefaults(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMVDeinterlace1_INTERFACE_DEFINED__ */


#ifndef __ILMVDeinterlace_INTERFACE_DEFINED__
#define __ILMVDeinterlace_INTERFACE_DEFINED__

/* interface ILMVDeinterlace */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ILMVDeinterlace;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DF60-38C5-11D5-91F6-00104BDB8FF9")
    ILMVDeinterlace : public ILMVDeinterlace1
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MergeFields( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MergeFields( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ResetToDefaultsEx( 
            /* [in] */ long ApiLevel) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMVDeinterlaceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMVDeinterlace * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMVDeinterlace * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMVDeinterlace * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMVDeinterlace * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMVDeinterlace * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMVDeinterlace * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMVDeinterlace * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Enabled )( 
            ILMVDeinterlace * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Enabled )( 
            ILMVDeinterlace * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Even )( 
            ILMVDeinterlace * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Even )( 
            ILMVDeinterlace * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Resize )( 
            ILMVDeinterlace * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Resize )( 
            ILMVDeinterlace * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsLEADInputPinConnected )( 
            ILMVDeinterlace * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsLEADOutputPinConnected )( 
            ILMVDeinterlace * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InWidth )( 
            ILMVDeinterlace * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InHeight )( 
            ILMVDeinterlace * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutWidth )( 
            ILMVDeinterlace * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutHeight )( 
            ILMVDeinterlace * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InBits )( 
            ILMVDeinterlace * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutBits )( 
            ILMVDeinterlace * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DoubleFrameRate )( 
            ILMVDeinterlace * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DoubleFrameRate )( 
            ILMVDeinterlace * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StartWithEvenFrame )( 
            ILMVDeinterlace * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_StartWithEvenFrame )( 
            ILMVDeinterlace * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableROI )( 
            ILMVDeinterlace * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableROI )( 
            ILMVDeinterlace * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ROILeft )( 
            ILMVDeinterlace * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ROILeft )( 
            ILMVDeinterlace * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ROITop )( 
            ILMVDeinterlace * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ROITop )( 
            ILMVDeinterlace * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ROIRight )( 
            ILMVDeinterlace * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ROIRight )( 
            ILMVDeinterlace * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ROIBottom )( 
            ILMVDeinterlace * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ROIBottom )( 
            ILMVDeinterlace * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableGlobalPattern )( 
            ILMVDeinterlace * This,
            /* [retval][out] */ VARIANT_BOOL *pDintPre);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableGlobalPattern )( 
            ILMVDeinterlace * This,
            /* [in] */ VARIANT_BOOL DintPre);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetGlobalPattern )( 
            ILMVDeinterlace * This,
            long PreambleFrames,
            long NoDeinterlaceFrames,
            long DeinterlaceFrames,
            VARIANT_BOOL DeintPreamble);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetGlobalPattern )( 
            ILMVDeinterlace * This,
            long *pPreambleFrames,
            long *pNoDeinterlaceFrames,
            long *pDeinterlaceFrames,
            VARIANT_BOOL *pDeintPreamble);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddSegment )( 
            ILMVDeinterlace * This,
            long Index);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemoveSegment )( 
            ILMVDeinterlace * This,
            long Index);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetSegmentData )( 
            ILMVDeinterlace * This,
            long Index,
            long SegmentData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetSegmentData )( 
            ILMVDeinterlace * This,
            long Index,
            long *pSegmentData);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SegmentsCount )( 
            ILMVDeinterlace * This,
            long *pCount);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SegmentsTimeFormat )( 
            ILMVDeinterlace * This,
            /* [retval][out] */ SEGMENT_TIME_FORMAT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SegmentsTimeFormat )( 
            ILMVDeinterlace * This,
            /* [in] */ SEGMENT_TIME_FORMAT newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetSegmentStartTime )( 
            ILMVDeinterlace * This,
            long Index,
            long *pHours,
            long *pMinutes,
            long *pSeconds,
            long *pMilliSeconds);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetSegmentStartTime )( 
            ILMVDeinterlace * This,
            long Index,
            long Hours,
            long Minutes,
            long Seconds,
            long MilliSeconds);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetSegmentStartFrame )( 
            ILMVDeinterlace * This,
            long Index,
            LONGLONG *pStartFrame);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetSegmentStartFrame )( 
            ILMVDeinterlace * This,
            long Index,
            LONGLONG StartFrame);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetSegmentOperationMode )( 
            ILMVDeinterlace * This,
            long Index,
            SEGMENT_OPERATION_MODE *pOperationMode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetSegmentOperationMode )( 
            ILMVDeinterlace * This,
            long Index,
            SEGMENT_OPERATION_MODE OperationMode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetSegmentPattern )( 
            ILMVDeinterlace * This,
            long Index,
            long *pPreambleFrames,
            long *pIgnoreFrames,
            long *pDeinterlaceFrames,
            VARIANT_BOOL *pDeintPreamble);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetSegmentPattern )( 
            ILMVDeinterlace * This,
            long Index,
            long PreambleFrames,
            long IgnoreFrames,
            long DeinterlaceFrames,
            VARIANT_BOOL DeintPreamble);
        
        /* [helpstring][id][hidden][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FrameRate )( 
            ILMVDeinterlace * This,
            /* [retval][out] */ double *pFrameRate);
        
        /* [helpstring][id][hidden][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FrameRate )( 
            ILMVDeinterlace * This,
            /* [in] */ double FrameRate);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableProtectedArea )( 
            ILMVDeinterlace * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableProtectedArea )( 
            ILMVDeinterlace * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetProtectedAreaParams )( 
            ILMVDeinterlace * This,
            /* [in] */ long Left,
            /* [in] */ long Right,
            /* [in] */ long Top,
            /* [in] */ long Bottom);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetProtectedAreaParams )( 
            ILMVDeinterlace * This,
            /* [out] */ long *Left,
            /* [out] */ long *Right,
            /* [out] */ long *Top,
            /* [out] */ long *Bottom);
        
        /* [helpstring][id][hidden][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DeinterlaceSettingsImportState )( 
            ILMVDeinterlace * This,
            /* [retval][out] */ VARIANT_BOOL *pNew);
        
        /* [helpstring][id][hidden][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DeinterlaceSettingsImportState )( 
            ILMVDeinterlace * This,
            /* [in] */ VARIANT_BOOL New);
        
        /* [helpstring][id][hidden][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ROISettingsImportState )( 
            ILMVDeinterlace * This,
            /* [retval][out] */ VARIANT_BOOL *pNew);
        
        /* [helpstring][id][hidden][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ROISettingsImportState )( 
            ILMVDeinterlace * This,
            /* [in] */ VARIANT_BOOL New);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AutoDeinterlace )( 
            ILMVDeinterlace * This,
            /* [retval][out] */ VARIANT_BOOL *pNew);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AutoDeinterlace )( 
            ILMVDeinterlace * This,
            /* [in] */ VARIANT_BOOL New);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetToDefaults )( 
            ILMVDeinterlace * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MergeFields )( 
            ILMVDeinterlace * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MergeFields )( 
            ILMVDeinterlace * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetToDefaultsEx )( 
            ILMVDeinterlace * This,
            /* [in] */ long ApiLevel);
        
        END_INTERFACE
    } ILMVDeinterlaceVtbl;

    interface ILMVDeinterlace
    {
        CONST_VTBL struct ILMVDeinterlaceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMVDeinterlace_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMVDeinterlace_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMVDeinterlace_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMVDeinterlace_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMVDeinterlace_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMVDeinterlace_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMVDeinterlace_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMVDeinterlace_get_Enabled(This,pVal)	\
    ( (This)->lpVtbl -> get_Enabled(This,pVal) ) 

#define ILMVDeinterlace_put_Enabled(This,newVal)	\
    ( (This)->lpVtbl -> put_Enabled(This,newVal) ) 

#define ILMVDeinterlace_get_Even(This,pVal)	\
    ( (This)->lpVtbl -> get_Even(This,pVal) ) 

#define ILMVDeinterlace_put_Even(This,newVal)	\
    ( (This)->lpVtbl -> put_Even(This,newVal) ) 

#define ILMVDeinterlace_get_Resize(This,pVal)	\
    ( (This)->lpVtbl -> get_Resize(This,pVal) ) 

#define ILMVDeinterlace_put_Resize(This,newVal)	\
    ( (This)->lpVtbl -> put_Resize(This,newVal) ) 

#define ILMVDeinterlace_get_IsLEADInputPinConnected(This,pVal)	\
    ( (This)->lpVtbl -> get_IsLEADInputPinConnected(This,pVal) ) 

#define ILMVDeinterlace_get_IsLEADOutputPinConnected(This,pVal)	\
    ( (This)->lpVtbl -> get_IsLEADOutputPinConnected(This,pVal) ) 

#define ILMVDeinterlace_get_InWidth(This,pVal)	\
    ( (This)->lpVtbl -> get_InWidth(This,pVal) ) 

#define ILMVDeinterlace_get_InHeight(This,pVal)	\
    ( (This)->lpVtbl -> get_InHeight(This,pVal) ) 

#define ILMVDeinterlace_get_OutWidth(This,pVal)	\
    ( (This)->lpVtbl -> get_OutWidth(This,pVal) ) 

#define ILMVDeinterlace_get_OutHeight(This,pVal)	\
    ( (This)->lpVtbl -> get_OutHeight(This,pVal) ) 

#define ILMVDeinterlace_get_InBits(This,pVal)	\
    ( (This)->lpVtbl -> get_InBits(This,pVal) ) 

#define ILMVDeinterlace_get_OutBits(This,pVal)	\
    ( (This)->lpVtbl -> get_OutBits(This,pVal) ) 

#define ILMVDeinterlace_get_DoubleFrameRate(This,pVal)	\
    ( (This)->lpVtbl -> get_DoubleFrameRate(This,pVal) ) 

#define ILMVDeinterlace_put_DoubleFrameRate(This,newVal)	\
    ( (This)->lpVtbl -> put_DoubleFrameRate(This,newVal) ) 

#define ILMVDeinterlace_get_StartWithEvenFrame(This,pVal)	\
    ( (This)->lpVtbl -> get_StartWithEvenFrame(This,pVal) ) 

#define ILMVDeinterlace_put_StartWithEvenFrame(This,newVal)	\
    ( (This)->lpVtbl -> put_StartWithEvenFrame(This,newVal) ) 

#define ILMVDeinterlace_get_EnableROI(This,pVal)	\
    ( (This)->lpVtbl -> get_EnableROI(This,pVal) ) 

#define ILMVDeinterlace_put_EnableROI(This,newVal)	\
    ( (This)->lpVtbl -> put_EnableROI(This,newVal) ) 

#define ILMVDeinterlace_get_ROILeft(This,pVal)	\
    ( (This)->lpVtbl -> get_ROILeft(This,pVal) ) 

#define ILMVDeinterlace_put_ROILeft(This,newVal)	\
    ( (This)->lpVtbl -> put_ROILeft(This,newVal) ) 

#define ILMVDeinterlace_get_ROITop(This,pVal)	\
    ( (This)->lpVtbl -> get_ROITop(This,pVal) ) 

#define ILMVDeinterlace_put_ROITop(This,newVal)	\
    ( (This)->lpVtbl -> put_ROITop(This,newVal) ) 

#define ILMVDeinterlace_get_ROIRight(This,pVal)	\
    ( (This)->lpVtbl -> get_ROIRight(This,pVal) ) 

#define ILMVDeinterlace_put_ROIRight(This,newVal)	\
    ( (This)->lpVtbl -> put_ROIRight(This,newVal) ) 

#define ILMVDeinterlace_get_ROIBottom(This,pVal)	\
    ( (This)->lpVtbl -> get_ROIBottom(This,pVal) ) 

#define ILMVDeinterlace_put_ROIBottom(This,newVal)	\
    ( (This)->lpVtbl -> put_ROIBottom(This,newVal) ) 

#define ILMVDeinterlace_get_EnableGlobalPattern(This,pDintPre)	\
    ( (This)->lpVtbl -> get_EnableGlobalPattern(This,pDintPre) ) 

#define ILMVDeinterlace_put_EnableGlobalPattern(This,DintPre)	\
    ( (This)->lpVtbl -> put_EnableGlobalPattern(This,DintPre) ) 

#define ILMVDeinterlace_SetGlobalPattern(This,PreambleFrames,NoDeinterlaceFrames,DeinterlaceFrames,DeintPreamble)	\
    ( (This)->lpVtbl -> SetGlobalPattern(This,PreambleFrames,NoDeinterlaceFrames,DeinterlaceFrames,DeintPreamble) ) 

#define ILMVDeinterlace_GetGlobalPattern(This,pPreambleFrames,pNoDeinterlaceFrames,pDeinterlaceFrames,pDeintPreamble)	\
    ( (This)->lpVtbl -> GetGlobalPattern(This,pPreambleFrames,pNoDeinterlaceFrames,pDeinterlaceFrames,pDeintPreamble) ) 

#define ILMVDeinterlace_AddSegment(This,Index)	\
    ( (This)->lpVtbl -> AddSegment(This,Index) ) 

#define ILMVDeinterlace_RemoveSegment(This,Index)	\
    ( (This)->lpVtbl -> RemoveSegment(This,Index) ) 

#define ILMVDeinterlace_SetSegmentData(This,Index,SegmentData)	\
    ( (This)->lpVtbl -> SetSegmentData(This,Index,SegmentData) ) 

#define ILMVDeinterlace_GetSegmentData(This,Index,pSegmentData)	\
    ( (This)->lpVtbl -> GetSegmentData(This,Index,pSegmentData) ) 

#define ILMVDeinterlace_get_SegmentsCount(This,pCount)	\
    ( (This)->lpVtbl -> get_SegmentsCount(This,pCount) ) 

#define ILMVDeinterlace_get_SegmentsTimeFormat(This,pVal)	\
    ( (This)->lpVtbl -> get_SegmentsTimeFormat(This,pVal) ) 

#define ILMVDeinterlace_put_SegmentsTimeFormat(This,newVal)	\
    ( (This)->lpVtbl -> put_SegmentsTimeFormat(This,newVal) ) 

#define ILMVDeinterlace_GetSegmentStartTime(This,Index,pHours,pMinutes,pSeconds,pMilliSeconds)	\
    ( (This)->lpVtbl -> GetSegmentStartTime(This,Index,pHours,pMinutes,pSeconds,pMilliSeconds) ) 

#define ILMVDeinterlace_SetSegmentStartTime(This,Index,Hours,Minutes,Seconds,MilliSeconds)	\
    ( (This)->lpVtbl -> SetSegmentStartTime(This,Index,Hours,Minutes,Seconds,MilliSeconds) ) 

#define ILMVDeinterlace_GetSegmentStartFrame(This,Index,pStartFrame)	\
    ( (This)->lpVtbl -> GetSegmentStartFrame(This,Index,pStartFrame) ) 

#define ILMVDeinterlace_SetSegmentStartFrame(This,Index,StartFrame)	\
    ( (This)->lpVtbl -> SetSegmentStartFrame(This,Index,StartFrame) ) 

#define ILMVDeinterlace_GetSegmentOperationMode(This,Index,pOperationMode)	\
    ( (This)->lpVtbl -> GetSegmentOperationMode(This,Index,pOperationMode) ) 

#define ILMVDeinterlace_SetSegmentOperationMode(This,Index,OperationMode)	\
    ( (This)->lpVtbl -> SetSegmentOperationMode(This,Index,OperationMode) ) 

#define ILMVDeinterlace_GetSegmentPattern(This,Index,pPreambleFrames,pIgnoreFrames,pDeinterlaceFrames,pDeintPreamble)	\
    ( (This)->lpVtbl -> GetSegmentPattern(This,Index,pPreambleFrames,pIgnoreFrames,pDeinterlaceFrames,pDeintPreamble) ) 

#define ILMVDeinterlace_SetSegmentPattern(This,Index,PreambleFrames,IgnoreFrames,DeinterlaceFrames,DeintPreamble)	\
    ( (This)->lpVtbl -> SetSegmentPattern(This,Index,PreambleFrames,IgnoreFrames,DeinterlaceFrames,DeintPreamble) ) 

#define ILMVDeinterlace_get_FrameRate(This,pFrameRate)	\
    ( (This)->lpVtbl -> get_FrameRate(This,pFrameRate) ) 

#define ILMVDeinterlace_put_FrameRate(This,FrameRate)	\
    ( (This)->lpVtbl -> put_FrameRate(This,FrameRate) ) 

#define ILMVDeinterlace_get_EnableProtectedArea(This,pVal)	\
    ( (This)->lpVtbl -> get_EnableProtectedArea(This,pVal) ) 

#define ILMVDeinterlace_put_EnableProtectedArea(This,newVal)	\
    ( (This)->lpVtbl -> put_EnableProtectedArea(This,newVal) ) 

#define ILMVDeinterlace_SetProtectedAreaParams(This,Left,Right,Top,Bottom)	\
    ( (This)->lpVtbl -> SetProtectedAreaParams(This,Left,Right,Top,Bottom) ) 

#define ILMVDeinterlace_GetProtectedAreaParams(This,Left,Right,Top,Bottom)	\
    ( (This)->lpVtbl -> GetProtectedAreaParams(This,Left,Right,Top,Bottom) ) 

#define ILMVDeinterlace_get_DeinterlaceSettingsImportState(This,pNew)	\
    ( (This)->lpVtbl -> get_DeinterlaceSettingsImportState(This,pNew) ) 

#define ILMVDeinterlace_put_DeinterlaceSettingsImportState(This,New)	\
    ( (This)->lpVtbl -> put_DeinterlaceSettingsImportState(This,New) ) 

#define ILMVDeinterlace_get_ROISettingsImportState(This,pNew)	\
    ( (This)->lpVtbl -> get_ROISettingsImportState(This,pNew) ) 

#define ILMVDeinterlace_put_ROISettingsImportState(This,New)	\
    ( (This)->lpVtbl -> put_ROISettingsImportState(This,New) ) 

#define ILMVDeinterlace_get_AutoDeinterlace(This,pNew)	\
    ( (This)->lpVtbl -> get_AutoDeinterlace(This,pNew) ) 

#define ILMVDeinterlace_put_AutoDeinterlace(This,New)	\
    ( (This)->lpVtbl -> put_AutoDeinterlace(This,New) ) 

#define ILMVDeinterlace_ResetToDefaults(This)	\
    ( (This)->lpVtbl -> ResetToDefaults(This) ) 


#define ILMVDeinterlace_get_MergeFields(This,pVal)	\
    ( (This)->lpVtbl -> get_MergeFields(This,pVal) ) 

#define ILMVDeinterlace_put_MergeFields(This,newVal)	\
    ( (This)->lpVtbl -> put_MergeFields(This,newVal) ) 

#define ILMVDeinterlace_ResetToDefaultsEx(This,ApiLevel)	\
    ( (This)->lpVtbl -> ResetToDefaultsEx(This,ApiLevel) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMVDeinterlace_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LMVDeinterlace;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DD90-38C5-11D5-91F6-00104BDB8FF9")
LMVDeinterlace;
#endif
#endif /* __LMVDeinterlaceLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


