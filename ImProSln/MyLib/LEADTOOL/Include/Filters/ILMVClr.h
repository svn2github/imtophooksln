

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Nov 05 12:37:06 2009
 */
/* Compiler settings for .\IBrightness.idl:
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


#ifndef __ILMVClr_h__
#define __ILMVClr_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILMVColor_FWD_DEFINED__
#define __ILMVColor_FWD_DEFINED__
typedef interface ILMVColor ILMVColor;
#endif 	/* __ILMVColor_FWD_DEFINED__ */


#ifndef __ILMVColorDisp_FWD_DEFINED__
#define __ILMVColorDisp_FWD_DEFINED__
typedef interface ILMVColorDisp ILMVColorDisp;
#endif 	/* __ILMVColorDisp_FWD_DEFINED__ */


#ifndef __LMVColor_FWD_DEFINED__
#define __LMVColor_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMVColor LMVColor;
#else
typedef struct LMVColor LMVColor;
#endif /* __cplusplus */

#endif 	/* __LMVColor_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LMVColorLib_LIBRARY_DEFINED__
#define __LMVColorLib_LIBRARY_DEFINED__

/* library LMVColorLib */
/* [helpstring][version][uuid] */ 

#ifndef __Color_H__
#define __Color_H__
static const GUID CLSID_LMVColor             = {0xe2b7db10, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVColorPropertyPage = {0xe2b7db11, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMVColor              = {0xe2b7db12, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVAboutColor        = {0xe2b7db45, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID LIBID_LMVColorLib          = {0xe2b7db6a, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMVColorDisp          = {0xe2b7db6b, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
#endif 
typedef /* [public][public][public] */ struct __MIDL___MIDL_itf_IBrightness_0000_0000_0001
    {
    BOOL bEnabled;
    long lBrightness;
    long lContrast;
    long lHue;
    long lSaturation;
    BOOL bInvert;
    BOOL bDEnabled;
    long lDBrightness;
    long lDContrast;
    long lDHue;
    long lDSaturation;
    BOOL bDInvert;
    } 	COLOR_ATTRIBUTES;

typedef /* [public][public][public] */ struct __MIDL___MIDL_itf_IBrightness_0000_0000_0002
    {
    long lLeft;
    long lTop;
    long lRight;
    long lBottom;
    BOOL bEnabled;
    long lDLeft;
    long lDTop;
    long lDRight;
    long lDBottom;
    BOOL bDEnabled;
    } 	CROP_ATTRIBUTES;


EXTERN_C const IID LIBID_LMVColorLib;

#ifndef __ILMVColor_INTERFACE_DEFINED__
#define __ILMVColor_INTERFACE_DEFINED__

/* interface ILMVColor */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ILMVColor;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DB12-38C5-11D5-91F6-00104BDB8FF9")
    ILMVColor : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE IsLEADInputPinConnected( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsLEADOutputPinConnected( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetColorAttributes( 
            /* [in] */ COLOR_ATTRIBUTES color_attributes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetColorAttributes( 
            /* [out] */ COLOR_ATTRIBUTES *color_attributes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIOBitCount( 
            /* [out] */ int *plInBits,
            /* [out] */ int *plOutBits) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCropAttributes( 
            /* [in] */ CROP_ATTRIBUTES crop_attributes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCropAttributes( 
            /* [out] */ CROP_ATTRIBUTES *crop_attributes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIODimensions( 
            /* [out] */ long *plInWidth,
            /* [out] */ long *plInHeight,
            /* [out] */ long *plOutWidth,
            /* [out] */ long *plOutHeight) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMVColorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMVColor * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMVColor * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMVColor * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsLEADInputPinConnected )( 
            ILMVColor * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsLEADOutputPinConnected )( 
            ILMVColor * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetColorAttributes )( 
            ILMVColor * This,
            /* [in] */ COLOR_ATTRIBUTES color_attributes);
        
        HRESULT ( STDMETHODCALLTYPE *GetColorAttributes )( 
            ILMVColor * This,
            /* [out] */ COLOR_ATTRIBUTES *color_attributes);
        
        HRESULT ( STDMETHODCALLTYPE *GetIOBitCount )( 
            ILMVColor * This,
            /* [out] */ int *plInBits,
            /* [out] */ int *plOutBits);
        
        HRESULT ( STDMETHODCALLTYPE *SetCropAttributes )( 
            ILMVColor * This,
            /* [in] */ CROP_ATTRIBUTES crop_attributes);
        
        HRESULT ( STDMETHODCALLTYPE *GetCropAttributes )( 
            ILMVColor * This,
            /* [out] */ CROP_ATTRIBUTES *crop_attributes);
        
        HRESULT ( STDMETHODCALLTYPE *GetIODimensions )( 
            ILMVColor * This,
            /* [out] */ long *plInWidth,
            /* [out] */ long *plInHeight,
            /* [out] */ long *plOutWidth,
            /* [out] */ long *plOutHeight);
        
        END_INTERFACE
    } ILMVColorVtbl;

    interface ILMVColor
    {
        CONST_VTBL struct ILMVColorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMVColor_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMVColor_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMVColor_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMVColor_IsLEADInputPinConnected(This)	\
    ( (This)->lpVtbl -> IsLEADInputPinConnected(This) ) 

#define ILMVColor_IsLEADOutputPinConnected(This)	\
    ( (This)->lpVtbl -> IsLEADOutputPinConnected(This) ) 

#define ILMVColor_SetColorAttributes(This,color_attributes)	\
    ( (This)->lpVtbl -> SetColorAttributes(This,color_attributes) ) 

#define ILMVColor_GetColorAttributes(This,color_attributes)	\
    ( (This)->lpVtbl -> GetColorAttributes(This,color_attributes) ) 

#define ILMVColor_GetIOBitCount(This,plInBits,plOutBits)	\
    ( (This)->lpVtbl -> GetIOBitCount(This,plInBits,plOutBits) ) 

#define ILMVColor_SetCropAttributes(This,crop_attributes)	\
    ( (This)->lpVtbl -> SetCropAttributes(This,crop_attributes) ) 

#define ILMVColor_GetCropAttributes(This,crop_attributes)	\
    ( (This)->lpVtbl -> GetCropAttributes(This,crop_attributes) ) 

#define ILMVColor_GetIODimensions(This,plInWidth,plInHeight,plOutWidth,plOutHeight)	\
    ( (This)->lpVtbl -> GetIODimensions(This,plInWidth,plInHeight,plOutWidth,plOutHeight) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMVColor_INTERFACE_DEFINED__ */


#ifndef __ILMVColorDisp_INTERFACE_DEFINED__
#define __ILMVColorDisp_INTERFACE_DEFINED__

/* interface ILMVColorDisp */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILMVColorDisp;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DB6B-38C5-11D5-91F6-00104BDB8FF9")
    ILMVColorDisp : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Enabled( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Enabled( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Invert( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Invert( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Brightness( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Brightness( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Contrast( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Contrast( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Hue( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Hue( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Saturation( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Saturation( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultEnabled( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DefaultEnabled( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultInvert( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DefaultInvert( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultBrightness( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DefaultBrightness( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultContrast( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DefaultContrast( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultHue( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DefaultHue( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultSaturation( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DefaultSaturation( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EffectAreaEnabled( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_EffectAreaEnabled( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Left( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Left( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Top( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Top( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Right( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Right( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Bottom( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Bottom( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultEffectAreaEnabled( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DefaultEffectAreaEnabled( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultLeft( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DefaultLeft( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultTop( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DefaultTop( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultRight( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DefaultRight( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultBottom( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DefaultBottom( 
            /* [in] */ long newVal) = 0;
        
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
        
    };
    
#else 	/* C style interface */

    typedef struct ILMVColorDispVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMVColorDisp * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMVColorDisp * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMVColorDisp * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMVColorDisp * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMVColorDisp * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMVColorDisp * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMVColorDisp * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Enabled )( 
            ILMVColorDisp * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Enabled )( 
            ILMVColorDisp * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Invert )( 
            ILMVColorDisp * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Invert )( 
            ILMVColorDisp * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Brightness )( 
            ILMVColorDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Brightness )( 
            ILMVColorDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Contrast )( 
            ILMVColorDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Contrast )( 
            ILMVColorDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Hue )( 
            ILMVColorDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Hue )( 
            ILMVColorDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Saturation )( 
            ILMVColorDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Saturation )( 
            ILMVColorDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultEnabled )( 
            ILMVColorDisp * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultEnabled )( 
            ILMVColorDisp * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultInvert )( 
            ILMVColorDisp * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultInvert )( 
            ILMVColorDisp * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultBrightness )( 
            ILMVColorDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultBrightness )( 
            ILMVColorDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultContrast )( 
            ILMVColorDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultContrast )( 
            ILMVColorDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultHue )( 
            ILMVColorDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultHue )( 
            ILMVColorDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultSaturation )( 
            ILMVColorDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultSaturation )( 
            ILMVColorDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EffectAreaEnabled )( 
            ILMVColorDisp * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EffectAreaEnabled )( 
            ILMVColorDisp * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Left )( 
            ILMVColorDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Left )( 
            ILMVColorDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Top )( 
            ILMVColorDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Top )( 
            ILMVColorDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Right )( 
            ILMVColorDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Right )( 
            ILMVColorDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Bottom )( 
            ILMVColorDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Bottom )( 
            ILMVColorDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultEffectAreaEnabled )( 
            ILMVColorDisp * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultEffectAreaEnabled )( 
            ILMVColorDisp * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultLeft )( 
            ILMVColorDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultLeft )( 
            ILMVColorDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultTop )( 
            ILMVColorDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultTop )( 
            ILMVColorDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultRight )( 
            ILMVColorDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultRight )( 
            ILMVColorDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultBottom )( 
            ILMVColorDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultBottom )( 
            ILMVColorDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsLEADInputPinConnected )( 
            ILMVColorDisp * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsLEADOutputPinConnected )( 
            ILMVColorDisp * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InWidth )( 
            ILMVColorDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InHeight )( 
            ILMVColorDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutWidth )( 
            ILMVColorDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutHeight )( 
            ILMVColorDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InBits )( 
            ILMVColorDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutBits )( 
            ILMVColorDisp * This,
            /* [retval][out] */ long *pVal);
        
        END_INTERFACE
    } ILMVColorDispVtbl;

    interface ILMVColorDisp
    {
        CONST_VTBL struct ILMVColorDispVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMVColorDisp_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMVColorDisp_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMVColorDisp_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMVColorDisp_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMVColorDisp_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMVColorDisp_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMVColorDisp_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMVColorDisp_get_Enabled(This,pVal)	\
    ( (This)->lpVtbl -> get_Enabled(This,pVal) ) 

#define ILMVColorDisp_put_Enabled(This,newVal)	\
    ( (This)->lpVtbl -> put_Enabled(This,newVal) ) 

#define ILMVColorDisp_get_Invert(This,pVal)	\
    ( (This)->lpVtbl -> get_Invert(This,pVal) ) 

#define ILMVColorDisp_put_Invert(This,newVal)	\
    ( (This)->lpVtbl -> put_Invert(This,newVal) ) 

#define ILMVColorDisp_get_Brightness(This,pVal)	\
    ( (This)->lpVtbl -> get_Brightness(This,pVal) ) 

#define ILMVColorDisp_put_Brightness(This,newVal)	\
    ( (This)->lpVtbl -> put_Brightness(This,newVal) ) 

#define ILMVColorDisp_get_Contrast(This,pVal)	\
    ( (This)->lpVtbl -> get_Contrast(This,pVal) ) 

#define ILMVColorDisp_put_Contrast(This,newVal)	\
    ( (This)->lpVtbl -> put_Contrast(This,newVal) ) 

#define ILMVColorDisp_get_Hue(This,pVal)	\
    ( (This)->lpVtbl -> get_Hue(This,pVal) ) 

#define ILMVColorDisp_put_Hue(This,newVal)	\
    ( (This)->lpVtbl -> put_Hue(This,newVal) ) 

#define ILMVColorDisp_get_Saturation(This,pVal)	\
    ( (This)->lpVtbl -> get_Saturation(This,pVal) ) 

#define ILMVColorDisp_put_Saturation(This,newVal)	\
    ( (This)->lpVtbl -> put_Saturation(This,newVal) ) 

#define ILMVColorDisp_get_DefaultEnabled(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultEnabled(This,pVal) ) 

#define ILMVColorDisp_put_DefaultEnabled(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultEnabled(This,newVal) ) 

#define ILMVColorDisp_get_DefaultInvert(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultInvert(This,pVal) ) 

#define ILMVColorDisp_put_DefaultInvert(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultInvert(This,newVal) ) 

#define ILMVColorDisp_get_DefaultBrightness(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultBrightness(This,pVal) ) 

#define ILMVColorDisp_put_DefaultBrightness(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultBrightness(This,newVal) ) 

#define ILMVColorDisp_get_DefaultContrast(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultContrast(This,pVal) ) 

#define ILMVColorDisp_put_DefaultContrast(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultContrast(This,newVal) ) 

#define ILMVColorDisp_get_DefaultHue(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultHue(This,pVal) ) 

#define ILMVColorDisp_put_DefaultHue(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultHue(This,newVal) ) 

#define ILMVColorDisp_get_DefaultSaturation(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultSaturation(This,pVal) ) 

#define ILMVColorDisp_put_DefaultSaturation(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultSaturation(This,newVal) ) 

#define ILMVColorDisp_get_EffectAreaEnabled(This,pVal)	\
    ( (This)->lpVtbl -> get_EffectAreaEnabled(This,pVal) ) 

#define ILMVColorDisp_put_EffectAreaEnabled(This,newVal)	\
    ( (This)->lpVtbl -> put_EffectAreaEnabled(This,newVal) ) 

#define ILMVColorDisp_get_Left(This,pVal)	\
    ( (This)->lpVtbl -> get_Left(This,pVal) ) 

#define ILMVColorDisp_put_Left(This,newVal)	\
    ( (This)->lpVtbl -> put_Left(This,newVal) ) 

#define ILMVColorDisp_get_Top(This,pVal)	\
    ( (This)->lpVtbl -> get_Top(This,pVal) ) 

#define ILMVColorDisp_put_Top(This,newVal)	\
    ( (This)->lpVtbl -> put_Top(This,newVal) ) 

#define ILMVColorDisp_get_Right(This,pVal)	\
    ( (This)->lpVtbl -> get_Right(This,pVal) ) 

#define ILMVColorDisp_put_Right(This,newVal)	\
    ( (This)->lpVtbl -> put_Right(This,newVal) ) 

#define ILMVColorDisp_get_Bottom(This,pVal)	\
    ( (This)->lpVtbl -> get_Bottom(This,pVal) ) 

#define ILMVColorDisp_put_Bottom(This,newVal)	\
    ( (This)->lpVtbl -> put_Bottom(This,newVal) ) 

#define ILMVColorDisp_get_DefaultEffectAreaEnabled(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultEffectAreaEnabled(This,pVal) ) 

#define ILMVColorDisp_put_DefaultEffectAreaEnabled(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultEffectAreaEnabled(This,newVal) ) 

#define ILMVColorDisp_get_DefaultLeft(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultLeft(This,pVal) ) 

#define ILMVColorDisp_put_DefaultLeft(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultLeft(This,newVal) ) 

#define ILMVColorDisp_get_DefaultTop(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultTop(This,pVal) ) 

#define ILMVColorDisp_put_DefaultTop(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultTop(This,newVal) ) 

#define ILMVColorDisp_get_DefaultRight(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultRight(This,pVal) ) 

#define ILMVColorDisp_put_DefaultRight(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultRight(This,newVal) ) 

#define ILMVColorDisp_get_DefaultBottom(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultBottom(This,pVal) ) 

#define ILMVColorDisp_put_DefaultBottom(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultBottom(This,newVal) ) 

#define ILMVColorDisp_get_IsLEADInputPinConnected(This,pVal)	\
    ( (This)->lpVtbl -> get_IsLEADInputPinConnected(This,pVal) ) 

#define ILMVColorDisp_get_IsLEADOutputPinConnected(This,pVal)	\
    ( (This)->lpVtbl -> get_IsLEADOutputPinConnected(This,pVal) ) 

#define ILMVColorDisp_get_InWidth(This,pVal)	\
    ( (This)->lpVtbl -> get_InWidth(This,pVal) ) 

#define ILMVColorDisp_get_InHeight(This,pVal)	\
    ( (This)->lpVtbl -> get_InHeight(This,pVal) ) 

#define ILMVColorDisp_get_OutWidth(This,pVal)	\
    ( (This)->lpVtbl -> get_OutWidth(This,pVal) ) 

#define ILMVColorDisp_get_OutHeight(This,pVal)	\
    ( (This)->lpVtbl -> get_OutHeight(This,pVal) ) 

#define ILMVColorDisp_get_InBits(This,pVal)	\
    ( (This)->lpVtbl -> get_InBits(This,pVal) ) 

#define ILMVColorDisp_get_OutBits(This,pVal)	\
    ( (This)->lpVtbl -> get_OutBits(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMVColorDisp_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LMVColor;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DB10-38C5-11D5-91F6-00104BDB8FF9")
LMVColor;
#endif
#endif /* __LMVColorLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


