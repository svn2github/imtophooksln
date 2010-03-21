

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Nov 05 12:38:40 2009
 */
/* Compiler settings for .\ILMEmboss.idl:
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


#ifndef __ILMVEmboss_h__
#define __ILMVEmboss_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILMVEmboss_FWD_DEFINED__
#define __ILMVEmboss_FWD_DEFINED__
typedef interface ILMVEmboss ILMVEmboss;
#endif 	/* __ILMVEmboss_FWD_DEFINED__ */


#ifndef __ILMVEmbossDisp_FWD_DEFINED__
#define __ILMVEmbossDisp_FWD_DEFINED__
typedef interface ILMVEmbossDisp ILMVEmbossDisp;
#endif 	/* __ILMVEmbossDisp_FWD_DEFINED__ */


#ifndef __LMVEmboss_FWD_DEFINED__
#define __LMVEmboss_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMVEmboss LMVEmboss;
#else
typedef struct LMVEmboss LMVEmboss;
#endif /* __cplusplus */

#endif 	/* __LMVEmboss_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LMVEmbossLib_LIBRARY_DEFINED__
#define __LMVEmbossLib_LIBRARY_DEFINED__

/* library LMVEmbossLib */
/* [helpstring][version][uuid] */ 

#ifndef __LMEmboss_H__
#define __LMEmboss_H__
static const GUID CLSID_LMVEmboss             = {0xe2b7db17, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVEmbossPropertyPage = {0xe2b7db19, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMVEmboss              = {0xe2b7db18, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVAboutEmboss        = {0xe2b7db4a, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID LIBID_LMVEmbossLib          = {0xe2b7db6e, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMVEmbossDisp          = {0xe2b7db6f, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
#endif 
typedef /* [public][public][public] */ struct __MIDL___MIDL_itf_ILMEmboss_0000_0000_0001
    {
    long lLightAngle;
    long lElevation;
    long lDepth;
    BOOL bEmbossp;
    BOOL bEnabled;
    long lDLightAngle;
    long lDElevation;
    long lDDepth;
    BOOL bDEmbossp;
    BOOL bDEnabled;
    } 	EMBOSS_ATTRIBUTES;

typedef /* [public][public][public] */ struct __MIDL___MIDL_itf_ILMEmboss_0000_0000_0002
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


EXTERN_C const IID LIBID_LMVEmbossLib;

#ifndef __ILMVEmboss_INTERFACE_DEFINED__
#define __ILMVEmboss_INTERFACE_DEFINED__

/* interface ILMVEmboss */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ILMVEmboss;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DB18-38C5-11D5-91F6-00104BDB8FF9")
    ILMVEmboss : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE IsLEADInputPinConnected( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsLEADOutputPinConnected( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIOBitCount( 
            /* [out] */ int *plInBits,
            /* [out] */ int *plOutBits) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetEmbossAttributes( 
            /* [in] */ EMBOSS_ATTRIBUTES emboss_attributes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEmbossAttributes( 
            /* [out] */ EMBOSS_ATTRIBUTES *emboss_attributes) = 0;
        
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

    typedef struct ILMVEmbossVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMVEmboss * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMVEmboss * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMVEmboss * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsLEADInputPinConnected )( 
            ILMVEmboss * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsLEADOutputPinConnected )( 
            ILMVEmboss * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetIOBitCount )( 
            ILMVEmboss * This,
            /* [out] */ int *plInBits,
            /* [out] */ int *plOutBits);
        
        HRESULT ( STDMETHODCALLTYPE *SetEmbossAttributes )( 
            ILMVEmboss * This,
            /* [in] */ EMBOSS_ATTRIBUTES emboss_attributes);
        
        HRESULT ( STDMETHODCALLTYPE *GetEmbossAttributes )( 
            ILMVEmboss * This,
            /* [out] */ EMBOSS_ATTRIBUTES *emboss_attributes);
        
        HRESULT ( STDMETHODCALLTYPE *SetCropAttributes )( 
            ILMVEmboss * This,
            /* [in] */ CROP_ATTRIBUTES crop_attributes);
        
        HRESULT ( STDMETHODCALLTYPE *GetCropAttributes )( 
            ILMVEmboss * This,
            /* [out] */ CROP_ATTRIBUTES *crop_attributes);
        
        HRESULT ( STDMETHODCALLTYPE *GetIODimensions )( 
            ILMVEmboss * This,
            /* [out] */ long *plInWidth,
            /* [out] */ long *plInHeight,
            /* [out] */ long *plOutWidth,
            /* [out] */ long *plOutHeight);
        
        END_INTERFACE
    } ILMVEmbossVtbl;

    interface ILMVEmboss
    {
        CONST_VTBL struct ILMVEmbossVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMVEmboss_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMVEmboss_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMVEmboss_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMVEmboss_IsLEADInputPinConnected(This)	\
    ( (This)->lpVtbl -> IsLEADInputPinConnected(This) ) 

#define ILMVEmboss_IsLEADOutputPinConnected(This)	\
    ( (This)->lpVtbl -> IsLEADOutputPinConnected(This) ) 

#define ILMVEmboss_GetIOBitCount(This,plInBits,plOutBits)	\
    ( (This)->lpVtbl -> GetIOBitCount(This,plInBits,plOutBits) ) 

#define ILMVEmboss_SetEmbossAttributes(This,emboss_attributes)	\
    ( (This)->lpVtbl -> SetEmbossAttributes(This,emboss_attributes) ) 

#define ILMVEmboss_GetEmbossAttributes(This,emboss_attributes)	\
    ( (This)->lpVtbl -> GetEmbossAttributes(This,emboss_attributes) ) 

#define ILMVEmboss_SetCropAttributes(This,crop_attributes)	\
    ( (This)->lpVtbl -> SetCropAttributes(This,crop_attributes) ) 

#define ILMVEmboss_GetCropAttributes(This,crop_attributes)	\
    ( (This)->lpVtbl -> GetCropAttributes(This,crop_attributes) ) 

#define ILMVEmboss_GetIODimensions(This,plInWidth,plInHeight,plOutWidth,plOutHeight)	\
    ( (This)->lpVtbl -> GetIODimensions(This,plInWidth,plInHeight,plOutWidth,plOutHeight) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMVEmboss_INTERFACE_DEFINED__ */


#ifndef __ILMVEmbossDisp_INTERFACE_DEFINED__
#define __ILMVEmbossDisp_INTERFACE_DEFINED__

/* interface ILMVEmbossDisp */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILMVEmbossDisp;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DB6F-38C5-11D5-91F6-00104BDB8FF9")
    ILMVEmbossDisp : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Enabled( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Enabled( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Embossp( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Embossp( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Depth( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Depth( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Elevation( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Elevation( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LightAngle( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_LightAngle( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultEnabled( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DefaultEnabled( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultEmbossp( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DefaultEmbossp( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultDepth( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DefaultDepth( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultElevation( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DefaultElevation( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultLightAngle( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DefaultLightAngle( 
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

    typedef struct ILMVEmbossDispVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMVEmbossDisp * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMVEmbossDisp * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMVEmbossDisp * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMVEmbossDisp * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMVEmbossDisp * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMVEmbossDisp * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMVEmbossDisp * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Enabled )( 
            ILMVEmbossDisp * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Enabled )( 
            ILMVEmbossDisp * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Embossp )( 
            ILMVEmbossDisp * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Embossp )( 
            ILMVEmbossDisp * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Depth )( 
            ILMVEmbossDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Depth )( 
            ILMVEmbossDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Elevation )( 
            ILMVEmbossDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Elevation )( 
            ILMVEmbossDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LightAngle )( 
            ILMVEmbossDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LightAngle )( 
            ILMVEmbossDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultEnabled )( 
            ILMVEmbossDisp * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultEnabled )( 
            ILMVEmbossDisp * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultEmbossp )( 
            ILMVEmbossDisp * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultEmbossp )( 
            ILMVEmbossDisp * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultDepth )( 
            ILMVEmbossDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultDepth )( 
            ILMVEmbossDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultElevation )( 
            ILMVEmbossDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultElevation )( 
            ILMVEmbossDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultLightAngle )( 
            ILMVEmbossDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultLightAngle )( 
            ILMVEmbossDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EffectAreaEnabled )( 
            ILMVEmbossDisp * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EffectAreaEnabled )( 
            ILMVEmbossDisp * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Left )( 
            ILMVEmbossDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Left )( 
            ILMVEmbossDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Top )( 
            ILMVEmbossDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Top )( 
            ILMVEmbossDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Right )( 
            ILMVEmbossDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Right )( 
            ILMVEmbossDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Bottom )( 
            ILMVEmbossDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Bottom )( 
            ILMVEmbossDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultEffectAreaEnabled )( 
            ILMVEmbossDisp * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultEffectAreaEnabled )( 
            ILMVEmbossDisp * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultLeft )( 
            ILMVEmbossDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultLeft )( 
            ILMVEmbossDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultTop )( 
            ILMVEmbossDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultTop )( 
            ILMVEmbossDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultRight )( 
            ILMVEmbossDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultRight )( 
            ILMVEmbossDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultBottom )( 
            ILMVEmbossDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultBottom )( 
            ILMVEmbossDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsLEADInputPinConnected )( 
            ILMVEmbossDisp * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsLEADOutputPinConnected )( 
            ILMVEmbossDisp * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InWidth )( 
            ILMVEmbossDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InHeight )( 
            ILMVEmbossDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutWidth )( 
            ILMVEmbossDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutHeight )( 
            ILMVEmbossDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InBits )( 
            ILMVEmbossDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutBits )( 
            ILMVEmbossDisp * This,
            /* [retval][out] */ long *pVal);
        
        END_INTERFACE
    } ILMVEmbossDispVtbl;

    interface ILMVEmbossDisp
    {
        CONST_VTBL struct ILMVEmbossDispVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMVEmbossDisp_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMVEmbossDisp_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMVEmbossDisp_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMVEmbossDisp_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMVEmbossDisp_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMVEmbossDisp_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMVEmbossDisp_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMVEmbossDisp_get_Enabled(This,pVal)	\
    ( (This)->lpVtbl -> get_Enabled(This,pVal) ) 

#define ILMVEmbossDisp_put_Enabled(This,newVal)	\
    ( (This)->lpVtbl -> put_Enabled(This,newVal) ) 

#define ILMVEmbossDisp_get_Embossp(This,pVal)	\
    ( (This)->lpVtbl -> get_Embossp(This,pVal) ) 

#define ILMVEmbossDisp_put_Embossp(This,newVal)	\
    ( (This)->lpVtbl -> put_Embossp(This,newVal) ) 

#define ILMVEmbossDisp_get_Depth(This,pVal)	\
    ( (This)->lpVtbl -> get_Depth(This,pVal) ) 

#define ILMVEmbossDisp_put_Depth(This,newVal)	\
    ( (This)->lpVtbl -> put_Depth(This,newVal) ) 

#define ILMVEmbossDisp_get_Elevation(This,pVal)	\
    ( (This)->lpVtbl -> get_Elevation(This,pVal) ) 

#define ILMVEmbossDisp_put_Elevation(This,newVal)	\
    ( (This)->lpVtbl -> put_Elevation(This,newVal) ) 

#define ILMVEmbossDisp_get_LightAngle(This,pVal)	\
    ( (This)->lpVtbl -> get_LightAngle(This,pVal) ) 

#define ILMVEmbossDisp_put_LightAngle(This,newVal)	\
    ( (This)->lpVtbl -> put_LightAngle(This,newVal) ) 

#define ILMVEmbossDisp_get_DefaultEnabled(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultEnabled(This,pVal) ) 

#define ILMVEmbossDisp_put_DefaultEnabled(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultEnabled(This,newVal) ) 

#define ILMVEmbossDisp_get_DefaultEmbossp(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultEmbossp(This,pVal) ) 

#define ILMVEmbossDisp_put_DefaultEmbossp(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultEmbossp(This,newVal) ) 

#define ILMVEmbossDisp_get_DefaultDepth(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultDepth(This,pVal) ) 

#define ILMVEmbossDisp_put_DefaultDepth(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultDepth(This,newVal) ) 

#define ILMVEmbossDisp_get_DefaultElevation(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultElevation(This,pVal) ) 

#define ILMVEmbossDisp_put_DefaultElevation(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultElevation(This,newVal) ) 

#define ILMVEmbossDisp_get_DefaultLightAngle(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultLightAngle(This,pVal) ) 

#define ILMVEmbossDisp_put_DefaultLightAngle(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultLightAngle(This,newVal) ) 

#define ILMVEmbossDisp_get_EffectAreaEnabled(This,pVal)	\
    ( (This)->lpVtbl -> get_EffectAreaEnabled(This,pVal) ) 

#define ILMVEmbossDisp_put_EffectAreaEnabled(This,newVal)	\
    ( (This)->lpVtbl -> put_EffectAreaEnabled(This,newVal) ) 

#define ILMVEmbossDisp_get_Left(This,pVal)	\
    ( (This)->lpVtbl -> get_Left(This,pVal) ) 

#define ILMVEmbossDisp_put_Left(This,newVal)	\
    ( (This)->lpVtbl -> put_Left(This,newVal) ) 

#define ILMVEmbossDisp_get_Top(This,pVal)	\
    ( (This)->lpVtbl -> get_Top(This,pVal) ) 

#define ILMVEmbossDisp_put_Top(This,newVal)	\
    ( (This)->lpVtbl -> put_Top(This,newVal) ) 

#define ILMVEmbossDisp_get_Right(This,pVal)	\
    ( (This)->lpVtbl -> get_Right(This,pVal) ) 

#define ILMVEmbossDisp_put_Right(This,newVal)	\
    ( (This)->lpVtbl -> put_Right(This,newVal) ) 

#define ILMVEmbossDisp_get_Bottom(This,pVal)	\
    ( (This)->lpVtbl -> get_Bottom(This,pVal) ) 

#define ILMVEmbossDisp_put_Bottom(This,newVal)	\
    ( (This)->lpVtbl -> put_Bottom(This,newVal) ) 

#define ILMVEmbossDisp_get_DefaultEffectAreaEnabled(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultEffectAreaEnabled(This,pVal) ) 

#define ILMVEmbossDisp_put_DefaultEffectAreaEnabled(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultEffectAreaEnabled(This,newVal) ) 

#define ILMVEmbossDisp_get_DefaultLeft(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultLeft(This,pVal) ) 

#define ILMVEmbossDisp_put_DefaultLeft(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultLeft(This,newVal) ) 

#define ILMVEmbossDisp_get_DefaultTop(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultTop(This,pVal) ) 

#define ILMVEmbossDisp_put_DefaultTop(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultTop(This,newVal) ) 

#define ILMVEmbossDisp_get_DefaultRight(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultRight(This,pVal) ) 

#define ILMVEmbossDisp_put_DefaultRight(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultRight(This,newVal) ) 

#define ILMVEmbossDisp_get_DefaultBottom(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultBottom(This,pVal) ) 

#define ILMVEmbossDisp_put_DefaultBottom(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultBottom(This,newVal) ) 

#define ILMVEmbossDisp_get_IsLEADInputPinConnected(This,pVal)	\
    ( (This)->lpVtbl -> get_IsLEADInputPinConnected(This,pVal) ) 

#define ILMVEmbossDisp_get_IsLEADOutputPinConnected(This,pVal)	\
    ( (This)->lpVtbl -> get_IsLEADOutputPinConnected(This,pVal) ) 

#define ILMVEmbossDisp_get_InWidth(This,pVal)	\
    ( (This)->lpVtbl -> get_InWidth(This,pVal) ) 

#define ILMVEmbossDisp_get_InHeight(This,pVal)	\
    ( (This)->lpVtbl -> get_InHeight(This,pVal) ) 

#define ILMVEmbossDisp_get_OutWidth(This,pVal)	\
    ( (This)->lpVtbl -> get_OutWidth(This,pVal) ) 

#define ILMVEmbossDisp_get_OutHeight(This,pVal)	\
    ( (This)->lpVtbl -> get_OutHeight(This,pVal) ) 

#define ILMVEmbossDisp_get_InBits(This,pVal)	\
    ( (This)->lpVtbl -> get_InBits(This,pVal) ) 

#define ILMVEmbossDisp_get_OutBits(This,pVal)	\
    ( (This)->lpVtbl -> get_OutBits(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMVEmbossDisp_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LMVEmboss;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DB17-38C5-11D5-91F6-00104BDB8FF9")
LMVEmboss;
#endif
#endif /* __LMVEmbossLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


