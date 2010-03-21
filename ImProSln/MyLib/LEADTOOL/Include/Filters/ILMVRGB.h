

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Nov 05 12:37:34 2009
 */
/* Compiler settings for .\IConvRGB.idl:
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


#ifndef __ILMVRGB_h__
#define __ILMVRGB_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILMVConvRGB1_FWD_DEFINED__
#define __ILMVConvRGB1_FWD_DEFINED__
typedef interface ILMVConvRGB1 ILMVConvRGB1;
#endif 	/* __ILMVConvRGB1_FWD_DEFINED__ */


#ifndef __ILMVConvRGB_FWD_DEFINED__
#define __ILMVConvRGB_FWD_DEFINED__
typedef interface ILMVConvRGB ILMVConvRGB;
#endif 	/* __ILMVConvRGB_FWD_DEFINED__ */


#ifndef __ILMVConvRGBDisp1_FWD_DEFINED__
#define __ILMVConvRGBDisp1_FWD_DEFINED__
typedef interface ILMVConvRGBDisp1 ILMVConvRGBDisp1;
#endif 	/* __ILMVConvRGBDisp1_FWD_DEFINED__ */


#ifndef __ILMVConvRGBDisp_FWD_DEFINED__
#define __ILMVConvRGBDisp_FWD_DEFINED__
typedef interface ILMVConvRGBDisp ILMVConvRGBDisp;
#endif 	/* __ILMVConvRGBDisp_FWD_DEFINED__ */


#ifndef __LMVConvRGB_FWD_DEFINED__
#define __LMVConvRGB_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMVConvRGB LMVConvRGB;
#else
typedef struct LMVConvRGB LMVConvRGB;
#endif /* __cplusplus */

#endif 	/* __LMVConvRGB_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LMVConvRGBLib_LIBRARY_DEFINED__
#define __LMVConvRGBLib_LIBRARY_DEFINED__

/* library LMVConvRGBLib */
/* [helpstring][version][uuid] */ 

#ifndef __ICONVRGB_H__
#define __ICONVRGB_H__
static const GUID CLSID_LMVConvRGB             = {0xE2B7DB22, 0x38C5, 0x11D5, {0x91, 0xF6, 0x00, 0x10, 0x4B, 0xDB, 0x8F, 0xF9}};
static const GUID IID_ILMVConvRGB1           = {0xE2B7DB23, 0x38C5, 0x11D5, {0x91, 0xF6, 0x00, 0x10, 0x4B, 0xDB, 0x8F, 0xF9}};
static const GUID IID_ILMVConvRGB              = {0xe2b7dd31, 0x38C5, 0x11D5, {0x91, 0xF6, 0x00, 0x10, 0x4B, 0xDB, 0x8F, 0xF9}};
static const GUID CLSID_LMVConvRGBPropertyPage = {0xE2B7DB24, 0x38C5, 0x11D5, {0x91, 0xF6, 0x00, 0x10, 0x4B, 0xDB, 0x8F, 0xF9}};
static const GUID CLSID_LMVAboutConvRGB        = {0xe2b7db47, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID LIBID_LMVConvRGBLib          = {0xe2b7db85, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMVConvRGBDisp1       = {0xe2b7db86, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMVConvRGBDisp          = {0xe2b7dd32, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
#endif 
typedef /* [public] */ 
enum __MIDL___MIDL_itf_IConvRGB_0000_0000_0001
    {	USEUPPERBITS	= 1,
	USELOWERBITS	= ( USEUPPERBITS + 1 ) ,
	USEFULLRANGE	= ( USELOWERBITS + 1 ) ,
	NOCHANGE	= ( USEFULLRANGE + 1 ) 
    } 	USEDBITS;

typedef /* [public] */ 
enum __MIDL___MIDL_itf_IConvRGB_0000_0000_0002
    {	LM_MEDIATYPE_AUTO	= 0,
	LM_MEDIATYPE_RGB1	= 0x1,
	LM_MEDIATYPE_RGB4	= 0x4,
	LM_MEDIATYPE_RGB8	= 0x8,
	LM_MEDIATYPE_RGB555	= 0xf,
	LM_MEDIATYPE_RGB565	= 0x10,
	LM_MEDIATYPE_RGB24	= 0x18,
	LM_MEDIATYPE_RGB32	= 0x20,
	LM_MEDIATYPE_ARGB32	= 0x21,
	LM_MEDIATYPE_LGRY12	= 0xc,
	LM_MEDIATYPE_LGRY16	= 0x11,
	LM_MEDIATYPE_YUY2	= 0x33
    } 	LM_MEDIATYPES;

typedef /* [public][public][public][public][public][public][public][public][public] */ 
enum __MIDL___MIDL_itf_IConvRGB_0000_0000_0003
    {	LM_FORMATTYPE_VIDEOINFO	= 0,
	LM_FORMATTYPE_VIDEOINFO2	= 1
    } 	LM_FORMATTYPE;


EXTERN_C const IID LIBID_LMVConvRGBLib;

#ifndef __ILMVConvRGB1_INTERFACE_DEFINED__
#define __ILMVConvRGB1_INTERFACE_DEFINED__

/* interface ILMVConvRGB1 */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ILMVConvRGB1;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DB23-38C5-11D5-91F6-00104BDB8FF9")
    ILMVConvRGB1 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetInputType( 
            /* [in] */ int nType,
            /* [in] */ BOOL bPalette) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetInputType( 
            /* [out] */ int *pnType,
            /* [out] */ BOOL *pbPalette) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetOutputType( 
            /* [in] */ int nType,
            /* [in] */ BOOL bPalette) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOutputType( 
            /* [out] */ int *pnType,
            /* [out] */ BOOL *pbPalette) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRGBOrder( 
            /* [in] */ BOOL bRGBOrder) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRGBOrder( 
            /* [out] */ BOOL *bRGBOrder) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetUsedBit( 
            int __MIDL__ILMVConvRGB10000) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUsedBit( 
            int *__MIDL__ILMVConvRGB10001) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAutoStop( 
            /* [in] */ BOOL bAutoStop) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAutoStop( 
            /* [out] */ BOOL *pbAutoStop) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsLEADInputPinConnected( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsLEADOutputPinConnected( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIODimensions( 
            /* [out] */ long *plInWidth,
            /* [out] */ long *plInHeight,
            /* [out] */ long *plOutWidth,
            /* [out] */ long *plOutHeight) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetInputOutputMediaType( 
            /* [out] */ GUID *Input,
            /* [out] */ GUID *Output) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIOBitCount( 
            /* [out] */ int *plInBits,
            /* [out] */ int *plOutBits) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMVConvRGB1Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMVConvRGB1 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMVConvRGB1 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMVConvRGB1 * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetInputType )( 
            ILMVConvRGB1 * This,
            /* [in] */ int nType,
            /* [in] */ BOOL bPalette);
        
        HRESULT ( STDMETHODCALLTYPE *GetInputType )( 
            ILMVConvRGB1 * This,
            /* [out] */ int *pnType,
            /* [out] */ BOOL *pbPalette);
        
        HRESULT ( STDMETHODCALLTYPE *SetOutputType )( 
            ILMVConvRGB1 * This,
            /* [in] */ int nType,
            /* [in] */ BOOL bPalette);
        
        HRESULT ( STDMETHODCALLTYPE *GetOutputType )( 
            ILMVConvRGB1 * This,
            /* [out] */ int *pnType,
            /* [out] */ BOOL *pbPalette);
        
        HRESULT ( STDMETHODCALLTYPE *SetRGBOrder )( 
            ILMVConvRGB1 * This,
            /* [in] */ BOOL bRGBOrder);
        
        HRESULT ( STDMETHODCALLTYPE *GetRGBOrder )( 
            ILMVConvRGB1 * This,
            /* [out] */ BOOL *bRGBOrder);
        
        HRESULT ( STDMETHODCALLTYPE *SetUsedBit )( 
            ILMVConvRGB1 * This,
            int __MIDL__ILMVConvRGB10000);
        
        HRESULT ( STDMETHODCALLTYPE *GetUsedBit )( 
            ILMVConvRGB1 * This,
            int *__MIDL__ILMVConvRGB10001);
        
        HRESULT ( STDMETHODCALLTYPE *SetAutoStop )( 
            ILMVConvRGB1 * This,
            /* [in] */ BOOL bAutoStop);
        
        HRESULT ( STDMETHODCALLTYPE *GetAutoStop )( 
            ILMVConvRGB1 * This,
            /* [out] */ BOOL *pbAutoStop);
        
        HRESULT ( STDMETHODCALLTYPE *IsLEADInputPinConnected )( 
            ILMVConvRGB1 * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsLEADOutputPinConnected )( 
            ILMVConvRGB1 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetIODimensions )( 
            ILMVConvRGB1 * This,
            /* [out] */ long *plInWidth,
            /* [out] */ long *plInHeight,
            /* [out] */ long *plOutWidth,
            /* [out] */ long *plOutHeight);
        
        HRESULT ( STDMETHODCALLTYPE *GetInputOutputMediaType )( 
            ILMVConvRGB1 * This,
            /* [out] */ GUID *Input,
            /* [out] */ GUID *Output);
        
        HRESULT ( STDMETHODCALLTYPE *GetIOBitCount )( 
            ILMVConvRGB1 * This,
            /* [out] */ int *plInBits,
            /* [out] */ int *plOutBits);
        
        END_INTERFACE
    } ILMVConvRGB1Vtbl;

    interface ILMVConvRGB1
    {
        CONST_VTBL struct ILMVConvRGB1Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMVConvRGB1_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMVConvRGB1_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMVConvRGB1_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMVConvRGB1_SetInputType(This,nType,bPalette)	\
    ( (This)->lpVtbl -> SetInputType(This,nType,bPalette) ) 

#define ILMVConvRGB1_GetInputType(This,pnType,pbPalette)	\
    ( (This)->lpVtbl -> GetInputType(This,pnType,pbPalette) ) 

#define ILMVConvRGB1_SetOutputType(This,nType,bPalette)	\
    ( (This)->lpVtbl -> SetOutputType(This,nType,bPalette) ) 

#define ILMVConvRGB1_GetOutputType(This,pnType,pbPalette)	\
    ( (This)->lpVtbl -> GetOutputType(This,pnType,pbPalette) ) 

#define ILMVConvRGB1_SetRGBOrder(This,bRGBOrder)	\
    ( (This)->lpVtbl -> SetRGBOrder(This,bRGBOrder) ) 

#define ILMVConvRGB1_GetRGBOrder(This,bRGBOrder)	\
    ( (This)->lpVtbl -> GetRGBOrder(This,bRGBOrder) ) 

#define ILMVConvRGB1_SetUsedBit(This,__MIDL__ILMVConvRGB10000)	\
    ( (This)->lpVtbl -> SetUsedBit(This,__MIDL__ILMVConvRGB10000) ) 

#define ILMVConvRGB1_GetUsedBit(This,__MIDL__ILMVConvRGB10001)	\
    ( (This)->lpVtbl -> GetUsedBit(This,__MIDL__ILMVConvRGB10001) ) 

#define ILMVConvRGB1_SetAutoStop(This,bAutoStop)	\
    ( (This)->lpVtbl -> SetAutoStop(This,bAutoStop) ) 

#define ILMVConvRGB1_GetAutoStop(This,pbAutoStop)	\
    ( (This)->lpVtbl -> GetAutoStop(This,pbAutoStop) ) 

#define ILMVConvRGB1_IsLEADInputPinConnected(This)	\
    ( (This)->lpVtbl -> IsLEADInputPinConnected(This) ) 

#define ILMVConvRGB1_IsLEADOutputPinConnected(This)	\
    ( (This)->lpVtbl -> IsLEADOutputPinConnected(This) ) 

#define ILMVConvRGB1_GetIODimensions(This,plInWidth,plInHeight,plOutWidth,plOutHeight)	\
    ( (This)->lpVtbl -> GetIODimensions(This,plInWidth,plInHeight,plOutWidth,plOutHeight) ) 

#define ILMVConvRGB1_GetInputOutputMediaType(This,Input,Output)	\
    ( (This)->lpVtbl -> GetInputOutputMediaType(This,Input,Output) ) 

#define ILMVConvRGB1_GetIOBitCount(This,plInBits,plOutBits)	\
    ( (This)->lpVtbl -> GetIOBitCount(This,plInBits,plOutBits) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMVConvRGB1_INTERFACE_DEFINED__ */


#ifndef __ILMVConvRGB_INTERFACE_DEFINED__
#define __ILMVConvRGB_INTERFACE_DEFINED__

/* interface ILMVConvRGB */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ILMVConvRGB;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DD31-38C5-11D5-91F6-00104BDB8FF9")
    ILMVConvRGB : public ILMVConvRGB1
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetInputVideoType( 
            LM_FORMATTYPE *pVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetInputVideoType( 
            LM_FORMATTYPE newVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOutputVideoType( 
            LM_FORMATTYPE *pVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetOutputVideoType( 
            LM_FORMATTYPE newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMVConvRGBVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMVConvRGB * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMVConvRGB * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMVConvRGB * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetInputType )( 
            ILMVConvRGB * This,
            /* [in] */ int nType,
            /* [in] */ BOOL bPalette);
        
        HRESULT ( STDMETHODCALLTYPE *GetInputType )( 
            ILMVConvRGB * This,
            /* [out] */ int *pnType,
            /* [out] */ BOOL *pbPalette);
        
        HRESULT ( STDMETHODCALLTYPE *SetOutputType )( 
            ILMVConvRGB * This,
            /* [in] */ int nType,
            /* [in] */ BOOL bPalette);
        
        HRESULT ( STDMETHODCALLTYPE *GetOutputType )( 
            ILMVConvRGB * This,
            /* [out] */ int *pnType,
            /* [out] */ BOOL *pbPalette);
        
        HRESULT ( STDMETHODCALLTYPE *SetRGBOrder )( 
            ILMVConvRGB * This,
            /* [in] */ BOOL bRGBOrder);
        
        HRESULT ( STDMETHODCALLTYPE *GetRGBOrder )( 
            ILMVConvRGB * This,
            /* [out] */ BOOL *bRGBOrder);
        
        HRESULT ( STDMETHODCALLTYPE *SetUsedBit )( 
            ILMVConvRGB * This,
            int __MIDL__ILMVConvRGB10000);
        
        HRESULT ( STDMETHODCALLTYPE *GetUsedBit )( 
            ILMVConvRGB * This,
            int *__MIDL__ILMVConvRGB10001);
        
        HRESULT ( STDMETHODCALLTYPE *SetAutoStop )( 
            ILMVConvRGB * This,
            /* [in] */ BOOL bAutoStop);
        
        HRESULT ( STDMETHODCALLTYPE *GetAutoStop )( 
            ILMVConvRGB * This,
            /* [out] */ BOOL *pbAutoStop);
        
        HRESULT ( STDMETHODCALLTYPE *IsLEADInputPinConnected )( 
            ILMVConvRGB * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsLEADOutputPinConnected )( 
            ILMVConvRGB * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetIODimensions )( 
            ILMVConvRGB * This,
            /* [out] */ long *plInWidth,
            /* [out] */ long *plInHeight,
            /* [out] */ long *plOutWidth,
            /* [out] */ long *plOutHeight);
        
        HRESULT ( STDMETHODCALLTYPE *GetInputOutputMediaType )( 
            ILMVConvRGB * This,
            /* [out] */ GUID *Input,
            /* [out] */ GUID *Output);
        
        HRESULT ( STDMETHODCALLTYPE *GetIOBitCount )( 
            ILMVConvRGB * This,
            /* [out] */ int *plInBits,
            /* [out] */ int *plOutBits);
        
        HRESULT ( STDMETHODCALLTYPE *GetInputVideoType )( 
            ILMVConvRGB * This,
            LM_FORMATTYPE *pVal);
        
        HRESULT ( STDMETHODCALLTYPE *SetInputVideoType )( 
            ILMVConvRGB * This,
            LM_FORMATTYPE newVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetOutputVideoType )( 
            ILMVConvRGB * This,
            LM_FORMATTYPE *pVal);
        
        HRESULT ( STDMETHODCALLTYPE *SetOutputVideoType )( 
            ILMVConvRGB * This,
            LM_FORMATTYPE newVal);
        
        END_INTERFACE
    } ILMVConvRGBVtbl;

    interface ILMVConvRGB
    {
        CONST_VTBL struct ILMVConvRGBVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMVConvRGB_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMVConvRGB_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMVConvRGB_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMVConvRGB_SetInputType(This,nType,bPalette)	\
    ( (This)->lpVtbl -> SetInputType(This,nType,bPalette) ) 

#define ILMVConvRGB_GetInputType(This,pnType,pbPalette)	\
    ( (This)->lpVtbl -> GetInputType(This,pnType,pbPalette) ) 

#define ILMVConvRGB_SetOutputType(This,nType,bPalette)	\
    ( (This)->lpVtbl -> SetOutputType(This,nType,bPalette) ) 

#define ILMVConvRGB_GetOutputType(This,pnType,pbPalette)	\
    ( (This)->lpVtbl -> GetOutputType(This,pnType,pbPalette) ) 

#define ILMVConvRGB_SetRGBOrder(This,bRGBOrder)	\
    ( (This)->lpVtbl -> SetRGBOrder(This,bRGBOrder) ) 

#define ILMVConvRGB_GetRGBOrder(This,bRGBOrder)	\
    ( (This)->lpVtbl -> GetRGBOrder(This,bRGBOrder) ) 

#define ILMVConvRGB_SetUsedBit(This,__MIDL__ILMVConvRGB10000)	\
    ( (This)->lpVtbl -> SetUsedBit(This,__MIDL__ILMVConvRGB10000) ) 

#define ILMVConvRGB_GetUsedBit(This,__MIDL__ILMVConvRGB10001)	\
    ( (This)->lpVtbl -> GetUsedBit(This,__MIDL__ILMVConvRGB10001) ) 

#define ILMVConvRGB_SetAutoStop(This,bAutoStop)	\
    ( (This)->lpVtbl -> SetAutoStop(This,bAutoStop) ) 

#define ILMVConvRGB_GetAutoStop(This,pbAutoStop)	\
    ( (This)->lpVtbl -> GetAutoStop(This,pbAutoStop) ) 

#define ILMVConvRGB_IsLEADInputPinConnected(This)	\
    ( (This)->lpVtbl -> IsLEADInputPinConnected(This) ) 

#define ILMVConvRGB_IsLEADOutputPinConnected(This)	\
    ( (This)->lpVtbl -> IsLEADOutputPinConnected(This) ) 

#define ILMVConvRGB_GetIODimensions(This,plInWidth,plInHeight,plOutWidth,plOutHeight)	\
    ( (This)->lpVtbl -> GetIODimensions(This,plInWidth,plInHeight,plOutWidth,plOutHeight) ) 

#define ILMVConvRGB_GetInputOutputMediaType(This,Input,Output)	\
    ( (This)->lpVtbl -> GetInputOutputMediaType(This,Input,Output) ) 

#define ILMVConvRGB_GetIOBitCount(This,plInBits,plOutBits)	\
    ( (This)->lpVtbl -> GetIOBitCount(This,plInBits,plOutBits) ) 


#define ILMVConvRGB_GetInputVideoType(This,pVal)	\
    ( (This)->lpVtbl -> GetInputVideoType(This,pVal) ) 

#define ILMVConvRGB_SetInputVideoType(This,newVal)	\
    ( (This)->lpVtbl -> SetInputVideoType(This,newVal) ) 

#define ILMVConvRGB_GetOutputVideoType(This,pVal)	\
    ( (This)->lpVtbl -> GetOutputVideoType(This,pVal) ) 

#define ILMVConvRGB_SetOutputVideoType(This,newVal)	\
    ( (This)->lpVtbl -> SetOutputVideoType(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMVConvRGB_INTERFACE_DEFINED__ */


#ifndef __ILMVConvRGBDisp1_INTERFACE_DEFINED__
#define __ILMVConvRGBDisp1_INTERFACE_DEFINED__

/* interface ILMVConvRGBDisp1 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILMVConvRGBDisp1;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DB86-38C5-11D5-91F6-00104BDB8FF9")
    ILMVConvRGBDisp1 : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetInputType( 
            /* [in] */ long nType,
            /* [in] */ VARIANT_BOOL bPalette) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetInputType( 
            /* [out] */ long *pnType,
            /* [out] */ VARIANT_BOOL *pbPalette) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetOutputType( 
            /* [in] */ long nType,
            /* [in] */ VARIANT_BOOL bPalette) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetOutputType( 
            /* [out] */ long *pnType,
            /* [out] */ VARIANT_BOOL *pbPalette) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RGBOrder( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RGBOrder( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UsedBit( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_UsedBit( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AutoStop( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AutoStop( 
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
        
    };
    
#else 	/* C style interface */

    typedef struct ILMVConvRGBDisp1Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMVConvRGBDisp1 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMVConvRGBDisp1 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMVConvRGBDisp1 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMVConvRGBDisp1 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMVConvRGBDisp1 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMVConvRGBDisp1 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMVConvRGBDisp1 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetInputType )( 
            ILMVConvRGBDisp1 * This,
            /* [in] */ long nType,
            /* [in] */ VARIANT_BOOL bPalette);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetInputType )( 
            ILMVConvRGBDisp1 * This,
            /* [out] */ long *pnType,
            /* [out] */ VARIANT_BOOL *pbPalette);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetOutputType )( 
            ILMVConvRGBDisp1 * This,
            /* [in] */ long nType,
            /* [in] */ VARIANT_BOOL bPalette);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetOutputType )( 
            ILMVConvRGBDisp1 * This,
            /* [out] */ long *pnType,
            /* [out] */ VARIANT_BOOL *pbPalette);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RGBOrder )( 
            ILMVConvRGBDisp1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RGBOrder )( 
            ILMVConvRGBDisp1 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UsedBit )( 
            ILMVConvRGBDisp1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UsedBit )( 
            ILMVConvRGBDisp1 * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AutoStop )( 
            ILMVConvRGBDisp1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AutoStop )( 
            ILMVConvRGBDisp1 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsLEADInputPinConnected )( 
            ILMVConvRGBDisp1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsLEADOutputPinConnected )( 
            ILMVConvRGBDisp1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InWidth )( 
            ILMVConvRGBDisp1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InHeight )( 
            ILMVConvRGBDisp1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutWidth )( 
            ILMVConvRGBDisp1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutHeight )( 
            ILMVConvRGBDisp1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InBits )( 
            ILMVConvRGBDisp1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutBits )( 
            ILMVConvRGBDisp1 * This,
            /* [retval][out] */ long *pVal);
        
        END_INTERFACE
    } ILMVConvRGBDisp1Vtbl;

    interface ILMVConvRGBDisp1
    {
        CONST_VTBL struct ILMVConvRGBDisp1Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMVConvRGBDisp1_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMVConvRGBDisp1_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMVConvRGBDisp1_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMVConvRGBDisp1_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMVConvRGBDisp1_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMVConvRGBDisp1_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMVConvRGBDisp1_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMVConvRGBDisp1_SetInputType(This,nType,bPalette)	\
    ( (This)->lpVtbl -> SetInputType(This,nType,bPalette) ) 

#define ILMVConvRGBDisp1_GetInputType(This,pnType,pbPalette)	\
    ( (This)->lpVtbl -> GetInputType(This,pnType,pbPalette) ) 

#define ILMVConvRGBDisp1_SetOutputType(This,nType,bPalette)	\
    ( (This)->lpVtbl -> SetOutputType(This,nType,bPalette) ) 

#define ILMVConvRGBDisp1_GetOutputType(This,pnType,pbPalette)	\
    ( (This)->lpVtbl -> GetOutputType(This,pnType,pbPalette) ) 

#define ILMVConvRGBDisp1_get_RGBOrder(This,pVal)	\
    ( (This)->lpVtbl -> get_RGBOrder(This,pVal) ) 

#define ILMVConvRGBDisp1_put_RGBOrder(This,newVal)	\
    ( (This)->lpVtbl -> put_RGBOrder(This,newVal) ) 

#define ILMVConvRGBDisp1_get_UsedBit(This,pVal)	\
    ( (This)->lpVtbl -> get_UsedBit(This,pVal) ) 

#define ILMVConvRGBDisp1_put_UsedBit(This,newVal)	\
    ( (This)->lpVtbl -> put_UsedBit(This,newVal) ) 

#define ILMVConvRGBDisp1_get_AutoStop(This,pVal)	\
    ( (This)->lpVtbl -> get_AutoStop(This,pVal) ) 

#define ILMVConvRGBDisp1_put_AutoStop(This,newVal)	\
    ( (This)->lpVtbl -> put_AutoStop(This,newVal) ) 

#define ILMVConvRGBDisp1_get_IsLEADInputPinConnected(This,pVal)	\
    ( (This)->lpVtbl -> get_IsLEADInputPinConnected(This,pVal) ) 

#define ILMVConvRGBDisp1_get_IsLEADOutputPinConnected(This,pVal)	\
    ( (This)->lpVtbl -> get_IsLEADOutputPinConnected(This,pVal) ) 

#define ILMVConvRGBDisp1_get_InWidth(This,pVal)	\
    ( (This)->lpVtbl -> get_InWidth(This,pVal) ) 

#define ILMVConvRGBDisp1_get_InHeight(This,pVal)	\
    ( (This)->lpVtbl -> get_InHeight(This,pVal) ) 

#define ILMVConvRGBDisp1_get_OutWidth(This,pVal)	\
    ( (This)->lpVtbl -> get_OutWidth(This,pVal) ) 

#define ILMVConvRGBDisp1_get_OutHeight(This,pVal)	\
    ( (This)->lpVtbl -> get_OutHeight(This,pVal) ) 

#define ILMVConvRGBDisp1_get_InBits(This,pVal)	\
    ( (This)->lpVtbl -> get_InBits(This,pVal) ) 

#define ILMVConvRGBDisp1_get_OutBits(This,pVal)	\
    ( (This)->lpVtbl -> get_OutBits(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMVConvRGBDisp1_INTERFACE_DEFINED__ */


#ifndef __ILMVConvRGBDisp_INTERFACE_DEFINED__
#define __ILMVConvRGBDisp_INTERFACE_DEFINED__

/* interface ILMVConvRGBDisp */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILMVConvRGBDisp;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DD32-38C5-11D5-91F6-00104BDB8FF9")
    ILMVConvRGBDisp : public ILMVConvRGBDisp1
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_InputVideoType( 
            /* [retval][out] */ LM_FORMATTYPE *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_InputVideoType( 
            /* [in] */ LM_FORMATTYPE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OutputVideoType( 
            /* [retval][out] */ LM_FORMATTYPE *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OutputVideoType( 
            /* [in] */ LM_FORMATTYPE newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMVConvRGBDispVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMVConvRGBDisp * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMVConvRGBDisp * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMVConvRGBDisp * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMVConvRGBDisp * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMVConvRGBDisp * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMVConvRGBDisp * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMVConvRGBDisp * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetInputType )( 
            ILMVConvRGBDisp * This,
            /* [in] */ long nType,
            /* [in] */ VARIANT_BOOL bPalette);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetInputType )( 
            ILMVConvRGBDisp * This,
            /* [out] */ long *pnType,
            /* [out] */ VARIANT_BOOL *pbPalette);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetOutputType )( 
            ILMVConvRGBDisp * This,
            /* [in] */ long nType,
            /* [in] */ VARIANT_BOOL bPalette);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetOutputType )( 
            ILMVConvRGBDisp * This,
            /* [out] */ long *pnType,
            /* [out] */ VARIANT_BOOL *pbPalette);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RGBOrder )( 
            ILMVConvRGBDisp * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RGBOrder )( 
            ILMVConvRGBDisp * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UsedBit )( 
            ILMVConvRGBDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UsedBit )( 
            ILMVConvRGBDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AutoStop )( 
            ILMVConvRGBDisp * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AutoStop )( 
            ILMVConvRGBDisp * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsLEADInputPinConnected )( 
            ILMVConvRGBDisp * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsLEADOutputPinConnected )( 
            ILMVConvRGBDisp * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InWidth )( 
            ILMVConvRGBDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InHeight )( 
            ILMVConvRGBDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutWidth )( 
            ILMVConvRGBDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutHeight )( 
            ILMVConvRGBDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InBits )( 
            ILMVConvRGBDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutBits )( 
            ILMVConvRGBDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InputVideoType )( 
            ILMVConvRGBDisp * This,
            /* [retval][out] */ LM_FORMATTYPE *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_InputVideoType )( 
            ILMVConvRGBDisp * This,
            /* [in] */ LM_FORMATTYPE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutputVideoType )( 
            ILMVConvRGBDisp * This,
            /* [retval][out] */ LM_FORMATTYPE *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OutputVideoType )( 
            ILMVConvRGBDisp * This,
            /* [in] */ LM_FORMATTYPE newVal);
        
        END_INTERFACE
    } ILMVConvRGBDispVtbl;

    interface ILMVConvRGBDisp
    {
        CONST_VTBL struct ILMVConvRGBDispVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMVConvRGBDisp_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMVConvRGBDisp_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMVConvRGBDisp_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMVConvRGBDisp_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMVConvRGBDisp_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMVConvRGBDisp_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMVConvRGBDisp_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMVConvRGBDisp_SetInputType(This,nType,bPalette)	\
    ( (This)->lpVtbl -> SetInputType(This,nType,bPalette) ) 

#define ILMVConvRGBDisp_GetInputType(This,pnType,pbPalette)	\
    ( (This)->lpVtbl -> GetInputType(This,pnType,pbPalette) ) 

#define ILMVConvRGBDisp_SetOutputType(This,nType,bPalette)	\
    ( (This)->lpVtbl -> SetOutputType(This,nType,bPalette) ) 

#define ILMVConvRGBDisp_GetOutputType(This,pnType,pbPalette)	\
    ( (This)->lpVtbl -> GetOutputType(This,pnType,pbPalette) ) 

#define ILMVConvRGBDisp_get_RGBOrder(This,pVal)	\
    ( (This)->lpVtbl -> get_RGBOrder(This,pVal) ) 

#define ILMVConvRGBDisp_put_RGBOrder(This,newVal)	\
    ( (This)->lpVtbl -> put_RGBOrder(This,newVal) ) 

#define ILMVConvRGBDisp_get_UsedBit(This,pVal)	\
    ( (This)->lpVtbl -> get_UsedBit(This,pVal) ) 

#define ILMVConvRGBDisp_put_UsedBit(This,newVal)	\
    ( (This)->lpVtbl -> put_UsedBit(This,newVal) ) 

#define ILMVConvRGBDisp_get_AutoStop(This,pVal)	\
    ( (This)->lpVtbl -> get_AutoStop(This,pVal) ) 

#define ILMVConvRGBDisp_put_AutoStop(This,newVal)	\
    ( (This)->lpVtbl -> put_AutoStop(This,newVal) ) 

#define ILMVConvRGBDisp_get_IsLEADInputPinConnected(This,pVal)	\
    ( (This)->lpVtbl -> get_IsLEADInputPinConnected(This,pVal) ) 

#define ILMVConvRGBDisp_get_IsLEADOutputPinConnected(This,pVal)	\
    ( (This)->lpVtbl -> get_IsLEADOutputPinConnected(This,pVal) ) 

#define ILMVConvRGBDisp_get_InWidth(This,pVal)	\
    ( (This)->lpVtbl -> get_InWidth(This,pVal) ) 

#define ILMVConvRGBDisp_get_InHeight(This,pVal)	\
    ( (This)->lpVtbl -> get_InHeight(This,pVal) ) 

#define ILMVConvRGBDisp_get_OutWidth(This,pVal)	\
    ( (This)->lpVtbl -> get_OutWidth(This,pVal) ) 

#define ILMVConvRGBDisp_get_OutHeight(This,pVal)	\
    ( (This)->lpVtbl -> get_OutHeight(This,pVal) ) 

#define ILMVConvRGBDisp_get_InBits(This,pVal)	\
    ( (This)->lpVtbl -> get_InBits(This,pVal) ) 

#define ILMVConvRGBDisp_get_OutBits(This,pVal)	\
    ( (This)->lpVtbl -> get_OutBits(This,pVal) ) 


#define ILMVConvRGBDisp_get_InputVideoType(This,pVal)	\
    ( (This)->lpVtbl -> get_InputVideoType(This,pVal) ) 

#define ILMVConvRGBDisp_put_InputVideoType(This,newVal)	\
    ( (This)->lpVtbl -> put_InputVideoType(This,newVal) ) 

#define ILMVConvRGBDisp_get_OutputVideoType(This,pVal)	\
    ( (This)->lpVtbl -> get_OutputVideoType(This,pVal) ) 

#define ILMVConvRGBDisp_put_OutputVideoType(This,newVal)	\
    ( (This)->lpVtbl -> put_OutputVideoType(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMVConvRGBDisp_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LMVConvRGB;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DB22-38C5-11D5-91F6-00104BDB8FF9")
LMVConvRGB;
#endif
#endif /* __LMVConvRGBLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


