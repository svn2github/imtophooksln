

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Nov 05 12:41:10 2009
 */
/* Compiler settings for .\IResize.idl:
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


#ifndef __ILMVRsz2_h__
#define __ILMVRsz2_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILMVResize1_FWD_DEFINED__
#define __ILMVResize1_FWD_DEFINED__
typedef interface ILMVResize1 ILMVResize1;
#endif 	/* __ILMVResize1_FWD_DEFINED__ */


#ifndef __ILMVResize_FWD_DEFINED__
#define __ILMVResize_FWD_DEFINED__
typedef interface ILMVResize ILMVResize;
#endif 	/* __ILMVResize_FWD_DEFINED__ */


#ifndef __LMVResize_FWD_DEFINED__
#define __LMVResize_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMVResize LMVResize;
#else
typedef struct LMVResize LMVResize;
#endif /* __cplusplus */

#endif 	/* __LMVResize_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LMVResizeLib_LIBRARY_DEFINED__
#define __LMVResizeLib_LIBRARY_DEFINED__

/* library LMVResizeLib */
/* [helpstring][version][uuid] */ 

#ifndef __IRESIZE2_H__
#define __IRESIZE2_H__
static const GUID CLSID_LMVResize             = {0xE2B7DCA5, 0x38C5, 0x11D5, {0x91, 0xF6, 0x00, 0x10, 0x4B, 0xDB, 0x8F, 0xF9}};
static const GUID CLSID_LMVResizePropertyPage = {0xE2B7DCA6, 0x38C5, 0x11D5, {0x91, 0xF6, 0x00, 0x10, 0x4B, 0xDB, 0x8F, 0xF9}};
static const GUID CLSID_LMVAboutResize        = {0xE2B7DCA7, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID LIBID_LMVResizeLib          = {0xE2B7DCA8, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMVResize1             = {0xE2B7DCA9, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMVResize              = {0xE2B7DF67, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
#endif 
typedef 
enum AutoResizeModeConstants
    {	AUTORESIZEMODE_INCREASE	= 0,
	AUTORESIZEMODE_FITWIDTH	= 0,
	AUTORESIZEMODE_DECREASE	= 0x1,
	AUTORESIZEMODE_FITHEIGHT	= 0x1
    } 	AutoResizeModeConstants;

typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_IResize_0000_0000_0001
    {	SIZE_1OVER8	= 0,
	SIZE_1OVER4	= 1,
	SIZE_1OVER2	= 2,
	SIZE_NORMAL	= 3,
	SIZE_X2	= 4,
	SIZE_X4	= 5,
	SIZE_X8	= 6
    } 	QUICKRESIZE;

typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_IResize_0000_0000_0002
    {	RESIZE_NORMAL	= 0,
	RESIZE_BRESENHAM	= 0x1,
	RESIZE_RESAMPLE	= 0x2,
	RESIZE_BICUBIC	= 0x4
    } 	SIZETYPES;

typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_IResize_0000_0000_0003
    {	INPUTASPECTRATIO_SQUAREPIXELS	= 0,
	INPUTASPECTRATIO_USEINPUT	= 1,
	INPUTASPECTRATIO_CUSTOM	= 2,
	INPUTASPECTRATIO_4_3	= 10,
	INPUTASPECTRATIO_16_9	= 11
    } 	InputAspectRatioModeConstants;

typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_IResize_0000_0000_0004
    {	OUTPUTASPECTRATIO_SQUAREPIXELS	= 0,
	OUTPUTASPECTRATIO_USEINPUT	= 1,
	OUTPUTASPECTRATIO_CUSTOM	= 2,
	OUTPUTASPECTRATIO_4_3	= 10,
	OUTPUTASPECTRATIO_16_9	= 11
    } 	OutputAspectRatioModeConstants;

typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_IResize_0000_0000_0005
    {	STRETCHMODE_STRETCH	= 0,
	STRETCHMODE_FITWIDTH	= ( STRETCHMODE_STRETCH + 1 ) ,
	STRETCHMODE_FITHEIGHT	= ( STRETCHMODE_FITWIDTH + 1 ) ,
	STRETCHMODE_FIT	= ( STRETCHMODE_FITHEIGHT + 1 ) ,
	STRETCHMODE_ENLARGEDFIT	= ( STRETCHMODE_FIT + 1 ) 
    } 	StretchModeConstants;

typedef /* [public][public][public][public][public] */ 
enum __MIDL___MIDL_itf_IResize_0000_0000_0006
    {	SIZECONTROL_FIXED	= 0,
	SIZECONTROL_ADJUSTABLE	= ( SIZECONTROL_FIXED + 1 ) 
    } 	SizeControlModeConstants;

typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_IResize_0000_0000_0007
    {	SQUAREPIXELOUTPUT_SAMESIZE	= 0,
	SQUAREPIXELOUTPUT_FITWIDTH	= ( SQUAREPIXELOUTPUT_SAMESIZE + 1 ) ,
	SQUAREPIXELOUTPUT_FITHEIGHT	= ( SQUAREPIXELOUTPUT_FITWIDTH + 1 ) ,
	SQUAREPIXELOUTPUT_INCREASESIZE	= ( SQUAREPIXELOUTPUT_FITHEIGHT + 1 ) ,
	SQUAREPIXELOUTPUT_DECREASESIZE	= ( SQUAREPIXELOUTPUT_INCREASESIZE + 1 ) 
    } 	SquarePixelOutputModeConstants;

typedef /* [public][public] */ 
enum __MIDL___MIDL_itf_IResize_0000_0000_0008
    {	LMVResize_APILEVEL_1	= 0,
	LMVResize_APILEVEL_2	= 1
    } 	LMVResize_APILEVEL;


EXTERN_C const IID LIBID_LMVResizeLib;

#ifndef __ILMVResize1_INTERFACE_DEFINED__
#define __ILMVResize1_INTERFACE_DEFINED__

/* interface ILMVResize1 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILMVResize1;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DCA9-38C5-11D5-91F6-00104BDB8FF9")
    ILMVResize1 : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Enabled( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Enabled( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EnableQuickResize( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_EnableQuickResize( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AspectRatio( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AspectRatio( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AutoStop( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AutoStop( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Width( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Width( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Height( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Height( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_QuickResize( 
            /* [retval][out] */ QUICKRESIZE *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_QuickResize( 
            /* [in] */ QUICKRESIZE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Flags( 
            /* [retval][out] */ SIZETYPES *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Flags( 
            /* [in] */ SIZETYPES newVal) = 0;
        
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
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AutoSize( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AutoSize( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FillColor( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FillColor( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AutoResizeMode( 
            /* [retval][out] */ AutoResizeModeConstants *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AutoResizeMode( 
            /* [in] */ AutoResizeModeConstants newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StartChangingAttributes( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StopChangingAttributes( 
            /* [in] */ VARIANT_BOOL bCancelChanges) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ResetToDefaults( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMVResize1Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMVResize1 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMVResize1 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMVResize1 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMVResize1 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMVResize1 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMVResize1 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMVResize1 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Enabled )( 
            ILMVResize1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Enabled )( 
            ILMVResize1 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableQuickResize )( 
            ILMVResize1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableQuickResize )( 
            ILMVResize1 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AspectRatio )( 
            ILMVResize1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AspectRatio )( 
            ILMVResize1 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AutoStop )( 
            ILMVResize1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AutoStop )( 
            ILMVResize1 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Width )( 
            ILMVResize1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Width )( 
            ILMVResize1 * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Height )( 
            ILMVResize1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Height )( 
            ILMVResize1 * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_QuickResize )( 
            ILMVResize1 * This,
            /* [retval][out] */ QUICKRESIZE *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_QuickResize )( 
            ILMVResize1 * This,
            /* [in] */ QUICKRESIZE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Flags )( 
            ILMVResize1 * This,
            /* [retval][out] */ SIZETYPES *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Flags )( 
            ILMVResize1 * This,
            /* [in] */ SIZETYPES newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsLEADInputPinConnected )( 
            ILMVResize1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsLEADOutputPinConnected )( 
            ILMVResize1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InWidth )( 
            ILMVResize1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InHeight )( 
            ILMVResize1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutWidth )( 
            ILMVResize1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutHeight )( 
            ILMVResize1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InBits )( 
            ILMVResize1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutBits )( 
            ILMVResize1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AutoSize )( 
            ILMVResize1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AutoSize )( 
            ILMVResize1 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FillColor )( 
            ILMVResize1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FillColor )( 
            ILMVResize1 * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AutoResizeMode )( 
            ILMVResize1 * This,
            /* [retval][out] */ AutoResizeModeConstants *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AutoResizeMode )( 
            ILMVResize1 * This,
            /* [in] */ AutoResizeModeConstants newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StartChangingAttributes )( 
            ILMVResize1 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StopChangingAttributes )( 
            ILMVResize1 * This,
            /* [in] */ VARIANT_BOOL bCancelChanges);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetToDefaults )( 
            ILMVResize1 * This);
        
        END_INTERFACE
    } ILMVResize1Vtbl;

    interface ILMVResize1
    {
        CONST_VTBL struct ILMVResize1Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMVResize1_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMVResize1_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMVResize1_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMVResize1_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMVResize1_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMVResize1_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMVResize1_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMVResize1_get_Enabled(This,pVal)	\
    ( (This)->lpVtbl -> get_Enabled(This,pVal) ) 

#define ILMVResize1_put_Enabled(This,newVal)	\
    ( (This)->lpVtbl -> put_Enabled(This,newVal) ) 

#define ILMVResize1_get_EnableQuickResize(This,pVal)	\
    ( (This)->lpVtbl -> get_EnableQuickResize(This,pVal) ) 

#define ILMVResize1_put_EnableQuickResize(This,newVal)	\
    ( (This)->lpVtbl -> put_EnableQuickResize(This,newVal) ) 

#define ILMVResize1_get_AspectRatio(This,pVal)	\
    ( (This)->lpVtbl -> get_AspectRatio(This,pVal) ) 

#define ILMVResize1_put_AspectRatio(This,newVal)	\
    ( (This)->lpVtbl -> put_AspectRatio(This,newVal) ) 

#define ILMVResize1_get_AutoStop(This,pVal)	\
    ( (This)->lpVtbl -> get_AutoStop(This,pVal) ) 

#define ILMVResize1_put_AutoStop(This,newVal)	\
    ( (This)->lpVtbl -> put_AutoStop(This,newVal) ) 

#define ILMVResize1_get_Width(This,pVal)	\
    ( (This)->lpVtbl -> get_Width(This,pVal) ) 

#define ILMVResize1_put_Width(This,newVal)	\
    ( (This)->lpVtbl -> put_Width(This,newVal) ) 

#define ILMVResize1_get_Height(This,pVal)	\
    ( (This)->lpVtbl -> get_Height(This,pVal) ) 

#define ILMVResize1_put_Height(This,newVal)	\
    ( (This)->lpVtbl -> put_Height(This,newVal) ) 

#define ILMVResize1_get_QuickResize(This,pVal)	\
    ( (This)->lpVtbl -> get_QuickResize(This,pVal) ) 

#define ILMVResize1_put_QuickResize(This,newVal)	\
    ( (This)->lpVtbl -> put_QuickResize(This,newVal) ) 

#define ILMVResize1_get_Flags(This,pVal)	\
    ( (This)->lpVtbl -> get_Flags(This,pVal) ) 

#define ILMVResize1_put_Flags(This,newVal)	\
    ( (This)->lpVtbl -> put_Flags(This,newVal) ) 

#define ILMVResize1_get_IsLEADInputPinConnected(This,pVal)	\
    ( (This)->lpVtbl -> get_IsLEADInputPinConnected(This,pVal) ) 

#define ILMVResize1_get_IsLEADOutputPinConnected(This,pVal)	\
    ( (This)->lpVtbl -> get_IsLEADOutputPinConnected(This,pVal) ) 

#define ILMVResize1_get_InWidth(This,pVal)	\
    ( (This)->lpVtbl -> get_InWidth(This,pVal) ) 

#define ILMVResize1_get_InHeight(This,pVal)	\
    ( (This)->lpVtbl -> get_InHeight(This,pVal) ) 

#define ILMVResize1_get_OutWidth(This,pVal)	\
    ( (This)->lpVtbl -> get_OutWidth(This,pVal) ) 

#define ILMVResize1_get_OutHeight(This,pVal)	\
    ( (This)->lpVtbl -> get_OutHeight(This,pVal) ) 

#define ILMVResize1_get_InBits(This,pVal)	\
    ( (This)->lpVtbl -> get_InBits(This,pVal) ) 

#define ILMVResize1_get_OutBits(This,pVal)	\
    ( (This)->lpVtbl -> get_OutBits(This,pVal) ) 

#define ILMVResize1_get_AutoSize(This,pVal)	\
    ( (This)->lpVtbl -> get_AutoSize(This,pVal) ) 

#define ILMVResize1_put_AutoSize(This,newVal)	\
    ( (This)->lpVtbl -> put_AutoSize(This,newVal) ) 

#define ILMVResize1_get_FillColor(This,pVal)	\
    ( (This)->lpVtbl -> get_FillColor(This,pVal) ) 

#define ILMVResize1_put_FillColor(This,newVal)	\
    ( (This)->lpVtbl -> put_FillColor(This,newVal) ) 

#define ILMVResize1_get_AutoResizeMode(This,pVal)	\
    ( (This)->lpVtbl -> get_AutoResizeMode(This,pVal) ) 

#define ILMVResize1_put_AutoResizeMode(This,newVal)	\
    ( (This)->lpVtbl -> put_AutoResizeMode(This,newVal) ) 

#define ILMVResize1_StartChangingAttributes(This)	\
    ( (This)->lpVtbl -> StartChangingAttributes(This) ) 

#define ILMVResize1_StopChangingAttributes(This,bCancelChanges)	\
    ( (This)->lpVtbl -> StopChangingAttributes(This,bCancelChanges) ) 

#define ILMVResize1_ResetToDefaults(This)	\
    ( (This)->lpVtbl -> ResetToDefaults(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMVResize1_INTERFACE_DEFINED__ */


#ifndef __ILMVResize_INTERFACE_DEFINED__
#define __ILMVResize_INTERFACE_DEFINED__

/* interface ILMVResize */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILMVResize;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DF67-38C5-11D5-91F6-00104BDB8FF9")
    ILMVResize : public ILMVResize1
    {
    public:
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_InputAspectRatioMode( 
            /* [in] */ InputAspectRatioModeConstants newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_InputAspectRatioMode( 
            /* [retval][out] */ InputAspectRatioModeConstants *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CustomInputAspectRatioWidth( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CustomInputAspectRatioWidth( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CustomInputAspectRatioHeight( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CustomInputAspectRatioHeight( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OutputAspectRatioMode( 
            /* [in] */ OutputAspectRatioModeConstants newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OutputAspectRatioMode( 
            /* [retval][out] */ OutputAspectRatioModeConstants *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CustomOutputAspectRatioWidth( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CustomOutputAspectRatioWidth( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CustomOutputAspectRatioHeight( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CustomOutputAspectRatioHeight( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_StretchMode( 
            /* [in] */ StretchModeConstants newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StretchMode( 
            /* [retval][out] */ StretchModeConstants *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_WidthControlMode( 
            /* [in] */ SizeControlModeConstants newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_WidthControlMode( 
            /* [retval][out] */ SizeControlModeConstants *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_HeightControlMode( 
            /* [in] */ SizeControlModeConstants newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HeightControlMode( 
            /* [retval][out] */ SizeControlModeConstants *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SquarePixelOutputMode( 
            /* [in] */ SquarePixelOutputModeConstants newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SquarePixelOutputMode( 
            /* [retval][out] */ SquarePixelOutputModeConstants *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ForceSquarePixelOutput( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ForceSquarePixelOutput( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ResetToDefaultsEx( 
            /* [in] */ LMVResize_APILEVEL ApiLevel) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMVResizeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMVResize * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMVResize * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMVResize * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMVResize * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMVResize * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMVResize * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMVResize * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Enabled )( 
            ILMVResize * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Enabled )( 
            ILMVResize * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableQuickResize )( 
            ILMVResize * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableQuickResize )( 
            ILMVResize * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AspectRatio )( 
            ILMVResize * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AspectRatio )( 
            ILMVResize * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AutoStop )( 
            ILMVResize * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AutoStop )( 
            ILMVResize * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Width )( 
            ILMVResize * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Width )( 
            ILMVResize * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Height )( 
            ILMVResize * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Height )( 
            ILMVResize * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_QuickResize )( 
            ILMVResize * This,
            /* [retval][out] */ QUICKRESIZE *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_QuickResize )( 
            ILMVResize * This,
            /* [in] */ QUICKRESIZE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Flags )( 
            ILMVResize * This,
            /* [retval][out] */ SIZETYPES *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Flags )( 
            ILMVResize * This,
            /* [in] */ SIZETYPES newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsLEADInputPinConnected )( 
            ILMVResize * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsLEADOutputPinConnected )( 
            ILMVResize * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InWidth )( 
            ILMVResize * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InHeight )( 
            ILMVResize * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutWidth )( 
            ILMVResize * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutHeight )( 
            ILMVResize * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InBits )( 
            ILMVResize * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutBits )( 
            ILMVResize * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AutoSize )( 
            ILMVResize * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AutoSize )( 
            ILMVResize * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FillColor )( 
            ILMVResize * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FillColor )( 
            ILMVResize * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AutoResizeMode )( 
            ILMVResize * This,
            /* [retval][out] */ AutoResizeModeConstants *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AutoResizeMode )( 
            ILMVResize * This,
            /* [in] */ AutoResizeModeConstants newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StartChangingAttributes )( 
            ILMVResize * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StopChangingAttributes )( 
            ILMVResize * This,
            /* [in] */ VARIANT_BOOL bCancelChanges);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetToDefaults )( 
            ILMVResize * This);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_InputAspectRatioMode )( 
            ILMVResize * This,
            /* [in] */ InputAspectRatioModeConstants newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InputAspectRatioMode )( 
            ILMVResize * This,
            /* [retval][out] */ InputAspectRatioModeConstants *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CustomInputAspectRatioWidth )( 
            ILMVResize * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CustomInputAspectRatioWidth )( 
            ILMVResize * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CustomInputAspectRatioHeight )( 
            ILMVResize * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CustomInputAspectRatioHeight )( 
            ILMVResize * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OutputAspectRatioMode )( 
            ILMVResize * This,
            /* [in] */ OutputAspectRatioModeConstants newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutputAspectRatioMode )( 
            ILMVResize * This,
            /* [retval][out] */ OutputAspectRatioModeConstants *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CustomOutputAspectRatioWidth )( 
            ILMVResize * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CustomOutputAspectRatioWidth )( 
            ILMVResize * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CustomOutputAspectRatioHeight )( 
            ILMVResize * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CustomOutputAspectRatioHeight )( 
            ILMVResize * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_StretchMode )( 
            ILMVResize * This,
            /* [in] */ StretchModeConstants newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StretchMode )( 
            ILMVResize * This,
            /* [retval][out] */ StretchModeConstants *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_WidthControlMode )( 
            ILMVResize * This,
            /* [in] */ SizeControlModeConstants newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_WidthControlMode )( 
            ILMVResize * This,
            /* [retval][out] */ SizeControlModeConstants *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_HeightControlMode )( 
            ILMVResize * This,
            /* [in] */ SizeControlModeConstants newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HeightControlMode )( 
            ILMVResize * This,
            /* [retval][out] */ SizeControlModeConstants *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SquarePixelOutputMode )( 
            ILMVResize * This,
            /* [in] */ SquarePixelOutputModeConstants newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SquarePixelOutputMode )( 
            ILMVResize * This,
            /* [retval][out] */ SquarePixelOutputModeConstants *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ForceSquarePixelOutput )( 
            ILMVResize * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ForceSquarePixelOutput )( 
            ILMVResize * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetToDefaultsEx )( 
            ILMVResize * This,
            /* [in] */ LMVResize_APILEVEL ApiLevel);
        
        END_INTERFACE
    } ILMVResizeVtbl;

    interface ILMVResize
    {
        CONST_VTBL struct ILMVResizeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMVResize_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMVResize_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMVResize_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMVResize_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMVResize_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMVResize_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMVResize_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMVResize_get_Enabled(This,pVal)	\
    ( (This)->lpVtbl -> get_Enabled(This,pVal) ) 

#define ILMVResize_put_Enabled(This,newVal)	\
    ( (This)->lpVtbl -> put_Enabled(This,newVal) ) 

#define ILMVResize_get_EnableQuickResize(This,pVal)	\
    ( (This)->lpVtbl -> get_EnableQuickResize(This,pVal) ) 

#define ILMVResize_put_EnableQuickResize(This,newVal)	\
    ( (This)->lpVtbl -> put_EnableQuickResize(This,newVal) ) 

#define ILMVResize_get_AspectRatio(This,pVal)	\
    ( (This)->lpVtbl -> get_AspectRatio(This,pVal) ) 

#define ILMVResize_put_AspectRatio(This,newVal)	\
    ( (This)->lpVtbl -> put_AspectRatio(This,newVal) ) 

#define ILMVResize_get_AutoStop(This,pVal)	\
    ( (This)->lpVtbl -> get_AutoStop(This,pVal) ) 

#define ILMVResize_put_AutoStop(This,newVal)	\
    ( (This)->lpVtbl -> put_AutoStop(This,newVal) ) 

#define ILMVResize_get_Width(This,pVal)	\
    ( (This)->lpVtbl -> get_Width(This,pVal) ) 

#define ILMVResize_put_Width(This,newVal)	\
    ( (This)->lpVtbl -> put_Width(This,newVal) ) 

#define ILMVResize_get_Height(This,pVal)	\
    ( (This)->lpVtbl -> get_Height(This,pVal) ) 

#define ILMVResize_put_Height(This,newVal)	\
    ( (This)->lpVtbl -> put_Height(This,newVal) ) 

#define ILMVResize_get_QuickResize(This,pVal)	\
    ( (This)->lpVtbl -> get_QuickResize(This,pVal) ) 

#define ILMVResize_put_QuickResize(This,newVal)	\
    ( (This)->lpVtbl -> put_QuickResize(This,newVal) ) 

#define ILMVResize_get_Flags(This,pVal)	\
    ( (This)->lpVtbl -> get_Flags(This,pVal) ) 

#define ILMVResize_put_Flags(This,newVal)	\
    ( (This)->lpVtbl -> put_Flags(This,newVal) ) 

#define ILMVResize_get_IsLEADInputPinConnected(This,pVal)	\
    ( (This)->lpVtbl -> get_IsLEADInputPinConnected(This,pVal) ) 

#define ILMVResize_get_IsLEADOutputPinConnected(This,pVal)	\
    ( (This)->lpVtbl -> get_IsLEADOutputPinConnected(This,pVal) ) 

#define ILMVResize_get_InWidth(This,pVal)	\
    ( (This)->lpVtbl -> get_InWidth(This,pVal) ) 

#define ILMVResize_get_InHeight(This,pVal)	\
    ( (This)->lpVtbl -> get_InHeight(This,pVal) ) 

#define ILMVResize_get_OutWidth(This,pVal)	\
    ( (This)->lpVtbl -> get_OutWidth(This,pVal) ) 

#define ILMVResize_get_OutHeight(This,pVal)	\
    ( (This)->lpVtbl -> get_OutHeight(This,pVal) ) 

#define ILMVResize_get_InBits(This,pVal)	\
    ( (This)->lpVtbl -> get_InBits(This,pVal) ) 

#define ILMVResize_get_OutBits(This,pVal)	\
    ( (This)->lpVtbl -> get_OutBits(This,pVal) ) 

#define ILMVResize_get_AutoSize(This,pVal)	\
    ( (This)->lpVtbl -> get_AutoSize(This,pVal) ) 

#define ILMVResize_put_AutoSize(This,newVal)	\
    ( (This)->lpVtbl -> put_AutoSize(This,newVal) ) 

#define ILMVResize_get_FillColor(This,pVal)	\
    ( (This)->lpVtbl -> get_FillColor(This,pVal) ) 

#define ILMVResize_put_FillColor(This,newVal)	\
    ( (This)->lpVtbl -> put_FillColor(This,newVal) ) 

#define ILMVResize_get_AutoResizeMode(This,pVal)	\
    ( (This)->lpVtbl -> get_AutoResizeMode(This,pVal) ) 

#define ILMVResize_put_AutoResizeMode(This,newVal)	\
    ( (This)->lpVtbl -> put_AutoResizeMode(This,newVal) ) 

#define ILMVResize_StartChangingAttributes(This)	\
    ( (This)->lpVtbl -> StartChangingAttributes(This) ) 

#define ILMVResize_StopChangingAttributes(This,bCancelChanges)	\
    ( (This)->lpVtbl -> StopChangingAttributes(This,bCancelChanges) ) 

#define ILMVResize_ResetToDefaults(This)	\
    ( (This)->lpVtbl -> ResetToDefaults(This) ) 


#define ILMVResize_put_InputAspectRatioMode(This,newVal)	\
    ( (This)->lpVtbl -> put_InputAspectRatioMode(This,newVal) ) 

#define ILMVResize_get_InputAspectRatioMode(This,pVal)	\
    ( (This)->lpVtbl -> get_InputAspectRatioMode(This,pVal) ) 

#define ILMVResize_put_CustomInputAspectRatioWidth(This,newVal)	\
    ( (This)->lpVtbl -> put_CustomInputAspectRatioWidth(This,newVal) ) 

#define ILMVResize_get_CustomInputAspectRatioWidth(This,pVal)	\
    ( (This)->lpVtbl -> get_CustomInputAspectRatioWidth(This,pVal) ) 

#define ILMVResize_put_CustomInputAspectRatioHeight(This,newVal)	\
    ( (This)->lpVtbl -> put_CustomInputAspectRatioHeight(This,newVal) ) 

#define ILMVResize_get_CustomInputAspectRatioHeight(This,pVal)	\
    ( (This)->lpVtbl -> get_CustomInputAspectRatioHeight(This,pVal) ) 

#define ILMVResize_put_OutputAspectRatioMode(This,newVal)	\
    ( (This)->lpVtbl -> put_OutputAspectRatioMode(This,newVal) ) 

#define ILMVResize_get_OutputAspectRatioMode(This,pVal)	\
    ( (This)->lpVtbl -> get_OutputAspectRatioMode(This,pVal) ) 

#define ILMVResize_put_CustomOutputAspectRatioWidth(This,newVal)	\
    ( (This)->lpVtbl -> put_CustomOutputAspectRatioWidth(This,newVal) ) 

#define ILMVResize_get_CustomOutputAspectRatioWidth(This,pVal)	\
    ( (This)->lpVtbl -> get_CustomOutputAspectRatioWidth(This,pVal) ) 

#define ILMVResize_put_CustomOutputAspectRatioHeight(This,newVal)	\
    ( (This)->lpVtbl -> put_CustomOutputAspectRatioHeight(This,newVal) ) 

#define ILMVResize_get_CustomOutputAspectRatioHeight(This,pVal)	\
    ( (This)->lpVtbl -> get_CustomOutputAspectRatioHeight(This,pVal) ) 

#define ILMVResize_put_StretchMode(This,newVal)	\
    ( (This)->lpVtbl -> put_StretchMode(This,newVal) ) 

#define ILMVResize_get_StretchMode(This,pVal)	\
    ( (This)->lpVtbl -> get_StretchMode(This,pVal) ) 

#define ILMVResize_put_WidthControlMode(This,newVal)	\
    ( (This)->lpVtbl -> put_WidthControlMode(This,newVal) ) 

#define ILMVResize_get_WidthControlMode(This,pVal)	\
    ( (This)->lpVtbl -> get_WidthControlMode(This,pVal) ) 

#define ILMVResize_put_HeightControlMode(This,newVal)	\
    ( (This)->lpVtbl -> put_HeightControlMode(This,newVal) ) 

#define ILMVResize_get_HeightControlMode(This,pVal)	\
    ( (This)->lpVtbl -> get_HeightControlMode(This,pVal) ) 

#define ILMVResize_put_SquarePixelOutputMode(This,newVal)	\
    ( (This)->lpVtbl -> put_SquarePixelOutputMode(This,newVal) ) 

#define ILMVResize_get_SquarePixelOutputMode(This,pVal)	\
    ( (This)->lpVtbl -> get_SquarePixelOutputMode(This,pVal) ) 

#define ILMVResize_get_ForceSquarePixelOutput(This,pVal)	\
    ( (This)->lpVtbl -> get_ForceSquarePixelOutput(This,pVal) ) 

#define ILMVResize_put_ForceSquarePixelOutput(This,newVal)	\
    ( (This)->lpVtbl -> put_ForceSquarePixelOutput(This,newVal) ) 

#define ILMVResize_ResetToDefaultsEx(This,ApiLevel)	\
    ( (This)->lpVtbl -> ResetToDefaultsEx(This,ApiLevel) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMVResize_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LMVResize;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DCA5-38C5-11D5-91F6-00104BDB8FF9")
LMVResize;
#endif
#endif /* __LMVResizeLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


