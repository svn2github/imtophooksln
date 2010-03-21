

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Nov 05 12:39:59 2009
 */
/* Compiler settings for .\IMosaic.idl:
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


#ifndef __ILMVMosaic_h__
#define __ILMVMosaic_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILMVMosaic_FWD_DEFINED__
#define __ILMVMosaic_FWD_DEFINED__
typedef interface ILMVMosaic ILMVMosaic;
#endif 	/* __ILMVMosaic_FWD_DEFINED__ */


#ifndef __ILMVMosaicDisp_FWD_DEFINED__
#define __ILMVMosaicDisp_FWD_DEFINED__
typedef interface ILMVMosaicDisp ILMVMosaicDisp;
#endif 	/* __ILMVMosaicDisp_FWD_DEFINED__ */


#ifndef __LMVMosaic_FWD_DEFINED__
#define __LMVMosaic_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMVMosaic LMVMosaic;
#else
typedef struct LMVMosaic LMVMosaic;
#endif /* __cplusplus */

#endif 	/* __LMVMosaic_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LMVMosaicLib_LIBRARY_DEFINED__
#define __LMVMosaicLib_LIBRARY_DEFINED__

/* library LMVMosaicLib */
/* [helpstring][version][uuid] */ 

#ifndef __Mosaic_H__
#define __Mosaic_H__
static const GUID CLSID_LMVMosaic             = {0xe2b7db28, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVMosaicPropertyPage = {0xe2b7db2a, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMVMosaic              = {0xe2b7db29, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVAboutMosaic        = {0xe2b7db43, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID LIBID_LMVMosaicLib          = {0xe2b7db72, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMVMosaicDisp          = {0xe2b7db73, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
#endif 
typedef /* [public][public][public] */ struct __MIDL___MIDL_itf_IMosaic_0000_0000_0001
    {
    long lSquareSize;
    BOOL bEnabled;
    long lDSquareSize;
    BOOL bDEnabled;
    } 	MOSAIC_ATTRIBUTES;

typedef /* [public][public][public] */ struct __MIDL___MIDL_itf_IMosaic_0000_0000_0002
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


EXTERN_C const IID LIBID_LMVMosaicLib;

#ifndef __ILMVMosaic_INTERFACE_DEFINED__
#define __ILMVMosaic_INTERFACE_DEFINED__

/* interface ILMVMosaic */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ILMVMosaic;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DB29-38C5-11D5-91F6-00104BDB8FF9")
    ILMVMosaic : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE IsLEADInputPinConnected( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsLEADOutputPinConnected( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIOBitCount( 
            /* [out] */ int *plInBits,
            /* [out] */ int *plOutBits) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMosaicAttributes( 
            /* [in] */ MOSAIC_ATTRIBUTES mosaic_attributes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMosaicAttributes( 
            /* [out] */ MOSAIC_ATTRIBUTES *mosaic_attributes) = 0;
        
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

    typedef struct ILMVMosaicVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMVMosaic * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMVMosaic * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMVMosaic * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsLEADInputPinConnected )( 
            ILMVMosaic * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsLEADOutputPinConnected )( 
            ILMVMosaic * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetIOBitCount )( 
            ILMVMosaic * This,
            /* [out] */ int *plInBits,
            /* [out] */ int *plOutBits);
        
        HRESULT ( STDMETHODCALLTYPE *SetMosaicAttributes )( 
            ILMVMosaic * This,
            /* [in] */ MOSAIC_ATTRIBUTES mosaic_attributes);
        
        HRESULT ( STDMETHODCALLTYPE *GetMosaicAttributes )( 
            ILMVMosaic * This,
            /* [out] */ MOSAIC_ATTRIBUTES *mosaic_attributes);
        
        HRESULT ( STDMETHODCALLTYPE *SetCropAttributes )( 
            ILMVMosaic * This,
            /* [in] */ CROP_ATTRIBUTES crop_attributes);
        
        HRESULT ( STDMETHODCALLTYPE *GetCropAttributes )( 
            ILMVMosaic * This,
            /* [out] */ CROP_ATTRIBUTES *crop_attributes);
        
        HRESULT ( STDMETHODCALLTYPE *GetIODimensions )( 
            ILMVMosaic * This,
            /* [out] */ long *plInWidth,
            /* [out] */ long *plInHeight,
            /* [out] */ long *plOutWidth,
            /* [out] */ long *plOutHeight);
        
        END_INTERFACE
    } ILMVMosaicVtbl;

    interface ILMVMosaic
    {
        CONST_VTBL struct ILMVMosaicVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMVMosaic_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMVMosaic_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMVMosaic_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMVMosaic_IsLEADInputPinConnected(This)	\
    ( (This)->lpVtbl -> IsLEADInputPinConnected(This) ) 

#define ILMVMosaic_IsLEADOutputPinConnected(This)	\
    ( (This)->lpVtbl -> IsLEADOutputPinConnected(This) ) 

#define ILMVMosaic_GetIOBitCount(This,plInBits,plOutBits)	\
    ( (This)->lpVtbl -> GetIOBitCount(This,plInBits,plOutBits) ) 

#define ILMVMosaic_SetMosaicAttributes(This,mosaic_attributes)	\
    ( (This)->lpVtbl -> SetMosaicAttributes(This,mosaic_attributes) ) 

#define ILMVMosaic_GetMosaicAttributes(This,mosaic_attributes)	\
    ( (This)->lpVtbl -> GetMosaicAttributes(This,mosaic_attributes) ) 

#define ILMVMosaic_SetCropAttributes(This,crop_attributes)	\
    ( (This)->lpVtbl -> SetCropAttributes(This,crop_attributes) ) 

#define ILMVMosaic_GetCropAttributes(This,crop_attributes)	\
    ( (This)->lpVtbl -> GetCropAttributes(This,crop_attributes) ) 

#define ILMVMosaic_GetIODimensions(This,plInWidth,plInHeight,plOutWidth,plOutHeight)	\
    ( (This)->lpVtbl -> GetIODimensions(This,plInWidth,plInHeight,plOutWidth,plOutHeight) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMVMosaic_INTERFACE_DEFINED__ */


#ifndef __ILMVMosaicDisp_INTERFACE_DEFINED__
#define __ILMVMosaicDisp_INTERFACE_DEFINED__

/* interface ILMVMosaicDisp */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILMVMosaicDisp;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DB73-38C5-11D5-91F6-00104BDB8FF9")
    ILMVMosaicDisp : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Enabled( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Enabled( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SquareSize( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SquareSize( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultEnabled( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DefaultEnabled( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultSquareSize( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DefaultSquareSize( 
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

    typedef struct ILMVMosaicDispVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMVMosaicDisp * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMVMosaicDisp * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMVMosaicDisp * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMVMosaicDisp * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMVMosaicDisp * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMVMosaicDisp * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMVMosaicDisp * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Enabled )( 
            ILMVMosaicDisp * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Enabled )( 
            ILMVMosaicDisp * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SquareSize )( 
            ILMVMosaicDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SquareSize )( 
            ILMVMosaicDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultEnabled )( 
            ILMVMosaicDisp * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultEnabled )( 
            ILMVMosaicDisp * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultSquareSize )( 
            ILMVMosaicDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultSquareSize )( 
            ILMVMosaicDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EffectAreaEnabled )( 
            ILMVMosaicDisp * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EffectAreaEnabled )( 
            ILMVMosaicDisp * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Left )( 
            ILMVMosaicDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Left )( 
            ILMVMosaicDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Top )( 
            ILMVMosaicDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Top )( 
            ILMVMosaicDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Right )( 
            ILMVMosaicDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Right )( 
            ILMVMosaicDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Bottom )( 
            ILMVMosaicDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Bottom )( 
            ILMVMosaicDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultEffectAreaEnabled )( 
            ILMVMosaicDisp * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultEffectAreaEnabled )( 
            ILMVMosaicDisp * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultLeft )( 
            ILMVMosaicDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultLeft )( 
            ILMVMosaicDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultTop )( 
            ILMVMosaicDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultTop )( 
            ILMVMosaicDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultRight )( 
            ILMVMosaicDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultRight )( 
            ILMVMosaicDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultBottom )( 
            ILMVMosaicDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultBottom )( 
            ILMVMosaicDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsLEADInputPinConnected )( 
            ILMVMosaicDisp * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsLEADOutputPinConnected )( 
            ILMVMosaicDisp * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InWidth )( 
            ILMVMosaicDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InHeight )( 
            ILMVMosaicDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutWidth )( 
            ILMVMosaicDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutHeight )( 
            ILMVMosaicDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InBits )( 
            ILMVMosaicDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutBits )( 
            ILMVMosaicDisp * This,
            /* [retval][out] */ long *pVal);
        
        END_INTERFACE
    } ILMVMosaicDispVtbl;

    interface ILMVMosaicDisp
    {
        CONST_VTBL struct ILMVMosaicDispVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMVMosaicDisp_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMVMosaicDisp_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMVMosaicDisp_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMVMosaicDisp_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMVMosaicDisp_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMVMosaicDisp_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMVMosaicDisp_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMVMosaicDisp_get_Enabled(This,pVal)	\
    ( (This)->lpVtbl -> get_Enabled(This,pVal) ) 

#define ILMVMosaicDisp_put_Enabled(This,newVal)	\
    ( (This)->lpVtbl -> put_Enabled(This,newVal) ) 

#define ILMVMosaicDisp_get_SquareSize(This,pVal)	\
    ( (This)->lpVtbl -> get_SquareSize(This,pVal) ) 

#define ILMVMosaicDisp_put_SquareSize(This,newVal)	\
    ( (This)->lpVtbl -> put_SquareSize(This,newVal) ) 

#define ILMVMosaicDisp_get_DefaultEnabled(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultEnabled(This,pVal) ) 

#define ILMVMosaicDisp_put_DefaultEnabled(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultEnabled(This,newVal) ) 

#define ILMVMosaicDisp_get_DefaultSquareSize(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultSquareSize(This,pVal) ) 

#define ILMVMosaicDisp_put_DefaultSquareSize(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultSquareSize(This,newVal) ) 

#define ILMVMosaicDisp_get_EffectAreaEnabled(This,pVal)	\
    ( (This)->lpVtbl -> get_EffectAreaEnabled(This,pVal) ) 

#define ILMVMosaicDisp_put_EffectAreaEnabled(This,newVal)	\
    ( (This)->lpVtbl -> put_EffectAreaEnabled(This,newVal) ) 

#define ILMVMosaicDisp_get_Left(This,pVal)	\
    ( (This)->lpVtbl -> get_Left(This,pVal) ) 

#define ILMVMosaicDisp_put_Left(This,newVal)	\
    ( (This)->lpVtbl -> put_Left(This,newVal) ) 

#define ILMVMosaicDisp_get_Top(This,pVal)	\
    ( (This)->lpVtbl -> get_Top(This,pVal) ) 

#define ILMVMosaicDisp_put_Top(This,newVal)	\
    ( (This)->lpVtbl -> put_Top(This,newVal) ) 

#define ILMVMosaicDisp_get_Right(This,pVal)	\
    ( (This)->lpVtbl -> get_Right(This,pVal) ) 

#define ILMVMosaicDisp_put_Right(This,newVal)	\
    ( (This)->lpVtbl -> put_Right(This,newVal) ) 

#define ILMVMosaicDisp_get_Bottom(This,pVal)	\
    ( (This)->lpVtbl -> get_Bottom(This,pVal) ) 

#define ILMVMosaicDisp_put_Bottom(This,newVal)	\
    ( (This)->lpVtbl -> put_Bottom(This,newVal) ) 

#define ILMVMosaicDisp_get_DefaultEffectAreaEnabled(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultEffectAreaEnabled(This,pVal) ) 

#define ILMVMosaicDisp_put_DefaultEffectAreaEnabled(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultEffectAreaEnabled(This,newVal) ) 

#define ILMVMosaicDisp_get_DefaultLeft(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultLeft(This,pVal) ) 

#define ILMVMosaicDisp_put_DefaultLeft(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultLeft(This,newVal) ) 

#define ILMVMosaicDisp_get_DefaultTop(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultTop(This,pVal) ) 

#define ILMVMosaicDisp_put_DefaultTop(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultTop(This,newVal) ) 

#define ILMVMosaicDisp_get_DefaultRight(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultRight(This,pVal) ) 

#define ILMVMosaicDisp_put_DefaultRight(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultRight(This,newVal) ) 

#define ILMVMosaicDisp_get_DefaultBottom(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultBottom(This,pVal) ) 

#define ILMVMosaicDisp_put_DefaultBottom(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultBottom(This,newVal) ) 

#define ILMVMosaicDisp_get_IsLEADInputPinConnected(This,pVal)	\
    ( (This)->lpVtbl -> get_IsLEADInputPinConnected(This,pVal) ) 

#define ILMVMosaicDisp_get_IsLEADOutputPinConnected(This,pVal)	\
    ( (This)->lpVtbl -> get_IsLEADOutputPinConnected(This,pVal) ) 

#define ILMVMosaicDisp_get_InWidth(This,pVal)	\
    ( (This)->lpVtbl -> get_InWidth(This,pVal) ) 

#define ILMVMosaicDisp_get_InHeight(This,pVal)	\
    ( (This)->lpVtbl -> get_InHeight(This,pVal) ) 

#define ILMVMosaicDisp_get_OutWidth(This,pVal)	\
    ( (This)->lpVtbl -> get_OutWidth(This,pVal) ) 

#define ILMVMosaicDisp_get_OutHeight(This,pVal)	\
    ( (This)->lpVtbl -> get_OutHeight(This,pVal) ) 

#define ILMVMosaicDisp_get_InBits(This,pVal)	\
    ( (This)->lpVtbl -> get_InBits(This,pVal) ) 

#define ILMVMosaicDisp_get_OutBits(This,pVal)	\
    ( (This)->lpVtbl -> get_OutBits(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMVMosaicDisp_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LMVMosaic;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DB28-38C5-11D5-91F6-00104BDB8FF9")
LMVMosaic;
#endif
#endif /* __LMVMosaicLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


