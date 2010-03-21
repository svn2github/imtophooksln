

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Nov 05 12:41:58 2009
 */
/* Compiler settings for .\IVOvrLy.idl:
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


#ifndef __ILMVIOvLy2_h__
#define __ILMVIOvLy2_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILMVIOvLy_FWD_DEFINED__
#define __ILMVIOvLy_FWD_DEFINED__
typedef interface ILMVIOvLy ILMVIOvLy;
#endif 	/* __ILMVIOvLy_FWD_DEFINED__ */


#ifndef __LMVIOvLy_FWD_DEFINED__
#define __LMVIOvLy_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMVIOvLy LMVIOvLy;
#else
typedef struct LMVIOvLy LMVIOvLy;
#endif /* __cplusplus */

#endif 	/* __LMVIOvLy_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LMVIOvLyLib_LIBRARY_DEFINED__
#define __LMVIOvLyLib_LIBRARY_DEFINED__

/* library LMVIOvLyLib */
/* [helpstring][version][uuid] */ 

#ifndef __IIOvLy2_H__
#define __IIOvLy2_H__
static const GUID LIBID_LMVIOvLyLib          = {0xe2b7df62, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVIOvLy             = {0xe2b7df63, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVIOvLyPropertyPage = {0xe2b7df64, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVAboutIOvLy        = {0xe2b7df65, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMVIOvLy              = {0xe2b7df66, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
#endif 
typedef /* [v1_enum] */ 
enum RegionConstants
    {	REGION_NONE	= 0,
	REGION_RECT	= 1,
	REGION_ROUNDRECT	= 2,
	REGION_ELLIPSE	= 3
    } 	RegionConstants;

typedef /* [v1_enum] */ 
enum LayerTypeConstants
    {	LAYERTYPE_BACKGROUND	= 0,
	LAYERTYPE_VIDEO	= 1,
	LAYERTYPE_OVERLAYIMAGE	= 2
    } 	LayerTypeConstants;


EXTERN_C const IID LIBID_LMVIOvLyLib;

#ifndef __ILMVIOvLy_INTERFACE_DEFINED__
#define __ILMVIOvLy_INTERFACE_DEFINED__

/* interface ILMVIOvLy */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ILMVIOvLy;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DF66-38C5-11D5-91F6-00104BDB8FF9")
    ILMVIOvLy : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActiveLayersCount( 
            /* [retval][out] */ long *pCount) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsLayerActive( 
            /* [in] */ LayerTypeConstants LayerType,
            /* [retval][out] */ VARIANT_BOOL *pActive) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LayerOrder( 
            /* [in] */ LayerTypeConstants LayerType,
            /* [retval][out] */ long *pIndex) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_LayerOrder( 
            /* [in] */ LayerTypeConstants LayerType,
            /* [in] */ long Index) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetLayerInfo( 
            /* [in] */ LayerTypeConstants LayerType,
            /* [out] */ long *pWidth,
            /* [out] */ long *pHeight,
            /* [out] */ long *pBitsPerPixel) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OverlayImageFileName( 
            /* [retval][out] */ BSTR *pImageFileName) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OverlayImageFileName( 
            /* [in] */ BSTR ImageFileName) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OverlayImageDIBPointer( 
            /* [in] */ long pDIB) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsOverlayImageLoaded( 
            /* [retval][out] */ VARIANT_BOOL *pLoaded) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BkLayerColor( 
            /* [retval][out] */ long *pColor) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_BkLayerColor( 
            /* [in] */ long Color) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EnableMaskBitmap( 
            /* [in] */ LayerTypeConstants LayerType,
            /* [retval][out] */ VARIANT_BOOL *pEnable) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_EnableMaskBitmap( 
            /* [in] */ LayerTypeConstants LayerType,
            /* [in] */ VARIANT_BOOL Enable) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MaskImageFileName( 
            /* [in] */ LayerTypeConstants LayerType,
            /* [retval][out] */ BSTR *pMaskImageFileName) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MaskImageFileName( 
            /* [in] */ LayerTypeConstants LayerType,
            /* [in] */ BSTR MaskImageFileName) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MaskImageDIBPointer( 
            /* [in] */ LayerTypeConstants LayerType,
            /* [in] */ long pDIB) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsMaskImageLoaded( 
            /* [in] */ LayerTypeConstants LayerType,
            /* [retval][out] */ VARIANT_BOOL *pLoaded) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EnableOpacity( 
            /* [in] */ LayerTypeConstants LayerType,
            /* [retval][out] */ VARIANT_BOOL *pEnable) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_EnableOpacity( 
            /* [in] */ LayerTypeConstants LayerType,
            /* [in] */ VARIANT_BOOL Enable) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Opacity( 
            /* [in] */ LayerTypeConstants LayerType,
            /* [retval][out] */ long *pOpacity) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Opacity( 
            /* [in] */ LayerTypeConstants LayerType,
            /* [in] */ long Opacity) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EnableTransparency( 
            /* [in] */ LayerTypeConstants LayerType,
            /* [retval][out] */ VARIANT_BOOL *pEnable) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_EnableTransparency( 
            /* [in] */ LayerTypeConstants LayerType,
            /* [in] */ VARIANT_BOOL bEnable) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TransparentColor( 
            /* [in] */ LayerTypeConstants LayerType,
            /* [retval][out] */ long *pColor) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_TransparentColor( 
            /* [in] */ LayerTypeConstants LayerType,
            /* [in] */ long Color) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_XPos( 
            /* [in] */ LayerTypeConstants LayerType,
            /* [retval][out] */ long *pXPos) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_XPos( 
            /* [in] */ LayerTypeConstants LayerType,
            /* [in] */ long XPos) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_YPos( 
            /* [in] */ LayerTypeConstants LayerType,
            /* [retval][out] */ long *pYPos) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_YPos( 
            /* [in] */ LayerTypeConstants LayerType,
            /* [in] */ long YPos) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Region( 
            /* [in] */ LayerTypeConstants LayerType,
            /* [retval][out] */ RegionConstants *pRegion) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Region( 
            /* [in] */ LayerTypeConstants LayerType,
            /* [in] */ RegionConstants Region) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RgnLeft( 
            /* [in] */ LayerTypeConstants LayerType,
            /* [retval][out] */ long *pLeft) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RgnLeft( 
            /* [in] */ LayerTypeConstants LayerType,
            /* [in] */ long Left) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RgnTop( 
            /* [in] */ LayerTypeConstants LayerType,
            /* [retval][out] */ long *pTop) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RgnTop( 
            /* [in] */ LayerTypeConstants LayerType,
            /* [in] */ long Top) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RgnRight( 
            /* [in] */ LayerTypeConstants LayerType,
            /* [retval][out] */ long *pRight) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RgnRight( 
            /* [in] */ LayerTypeConstants LayerType,
            /* [in] */ long Right) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RgnBottom( 
            /* [in] */ LayerTypeConstants LayerType,
            /* [retval][out] */ long *pBottom) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RgnBottom( 
            /* [in] */ LayerTypeConstants LayerType,
            /* [in] */ long Bottom) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RgnRoundRectEllipseWidth( 
            /* [in] */ LayerTypeConstants LayerType,
            /* [retval][out] */ long *pWidth) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RgnRoundRectEllipseWidth( 
            /* [in] */ LayerTypeConstants LayerType,
            /* [in] */ long Width) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RgnRoundRectEllipseHeight( 
            /* [in] */ LayerTypeConstants LayerType,
            /* [retval][out] */ long *pHeight) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RgnRoundRectEllipseHeight( 
            /* [in] */ LayerTypeConstants LayerType,
            /* [in] */ long Height) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMVIOvLyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMVIOvLy * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMVIOvLy * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMVIOvLy * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMVIOvLy * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMVIOvLy * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMVIOvLy * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMVIOvLy * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveLayersCount )( 
            ILMVIOvLy * This,
            /* [retval][out] */ long *pCount);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsLayerActive )( 
            ILMVIOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [retval][out] */ VARIANT_BOOL *pActive);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LayerOrder )( 
            ILMVIOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [retval][out] */ long *pIndex);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LayerOrder )( 
            ILMVIOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [in] */ long Index);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetLayerInfo )( 
            ILMVIOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [out] */ long *pWidth,
            /* [out] */ long *pHeight,
            /* [out] */ long *pBitsPerPixel);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OverlayImageFileName )( 
            ILMVIOvLy * This,
            /* [retval][out] */ BSTR *pImageFileName);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OverlayImageFileName )( 
            ILMVIOvLy * This,
            /* [in] */ BSTR ImageFileName);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OverlayImageDIBPointer )( 
            ILMVIOvLy * This,
            /* [in] */ long pDIB);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsOverlayImageLoaded )( 
            ILMVIOvLy * This,
            /* [retval][out] */ VARIANT_BOOL *pLoaded);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BkLayerColor )( 
            ILMVIOvLy * This,
            /* [retval][out] */ long *pColor);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BkLayerColor )( 
            ILMVIOvLy * This,
            /* [in] */ long Color);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableMaskBitmap )( 
            ILMVIOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [retval][out] */ VARIANT_BOOL *pEnable);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableMaskBitmap )( 
            ILMVIOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [in] */ VARIANT_BOOL Enable);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MaskImageFileName )( 
            ILMVIOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [retval][out] */ BSTR *pMaskImageFileName);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MaskImageFileName )( 
            ILMVIOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [in] */ BSTR MaskImageFileName);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MaskImageDIBPointer )( 
            ILMVIOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [in] */ long pDIB);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsMaskImageLoaded )( 
            ILMVIOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [retval][out] */ VARIANT_BOOL *pLoaded);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableOpacity )( 
            ILMVIOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [retval][out] */ VARIANT_BOOL *pEnable);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableOpacity )( 
            ILMVIOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [in] */ VARIANT_BOOL Enable);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Opacity )( 
            ILMVIOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [retval][out] */ long *pOpacity);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Opacity )( 
            ILMVIOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [in] */ long Opacity);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableTransparency )( 
            ILMVIOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [retval][out] */ VARIANT_BOOL *pEnable);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableTransparency )( 
            ILMVIOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [in] */ VARIANT_BOOL bEnable);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TransparentColor )( 
            ILMVIOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [retval][out] */ long *pColor);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TransparentColor )( 
            ILMVIOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [in] */ long Color);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_XPos )( 
            ILMVIOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [retval][out] */ long *pXPos);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_XPos )( 
            ILMVIOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [in] */ long XPos);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_YPos )( 
            ILMVIOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [retval][out] */ long *pYPos);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_YPos )( 
            ILMVIOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [in] */ long YPos);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Region )( 
            ILMVIOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [retval][out] */ RegionConstants *pRegion);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Region )( 
            ILMVIOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [in] */ RegionConstants Region);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RgnLeft )( 
            ILMVIOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [retval][out] */ long *pLeft);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RgnLeft )( 
            ILMVIOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [in] */ long Left);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RgnTop )( 
            ILMVIOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [retval][out] */ long *pTop);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RgnTop )( 
            ILMVIOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [in] */ long Top);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RgnRight )( 
            ILMVIOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [retval][out] */ long *pRight);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RgnRight )( 
            ILMVIOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [in] */ long Right);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RgnBottom )( 
            ILMVIOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [retval][out] */ long *pBottom);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RgnBottom )( 
            ILMVIOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [in] */ long Bottom);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RgnRoundRectEllipseWidth )( 
            ILMVIOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [retval][out] */ long *pWidth);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RgnRoundRectEllipseWidth )( 
            ILMVIOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [in] */ long Width);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RgnRoundRectEllipseHeight )( 
            ILMVIOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [retval][out] */ long *pHeight);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RgnRoundRectEllipseHeight )( 
            ILMVIOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [in] */ long Height);
        
        END_INTERFACE
    } ILMVIOvLyVtbl;

    interface ILMVIOvLy
    {
        CONST_VTBL struct ILMVIOvLyVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMVIOvLy_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMVIOvLy_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMVIOvLy_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMVIOvLy_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMVIOvLy_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMVIOvLy_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMVIOvLy_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMVIOvLy_get_ActiveLayersCount(This,pCount)	\
    ( (This)->lpVtbl -> get_ActiveLayersCount(This,pCount) ) 

#define ILMVIOvLy_get_IsLayerActive(This,LayerType,pActive)	\
    ( (This)->lpVtbl -> get_IsLayerActive(This,LayerType,pActive) ) 

#define ILMVIOvLy_get_LayerOrder(This,LayerType,pIndex)	\
    ( (This)->lpVtbl -> get_LayerOrder(This,LayerType,pIndex) ) 

#define ILMVIOvLy_put_LayerOrder(This,LayerType,Index)	\
    ( (This)->lpVtbl -> put_LayerOrder(This,LayerType,Index) ) 

#define ILMVIOvLy_GetLayerInfo(This,LayerType,pWidth,pHeight,pBitsPerPixel)	\
    ( (This)->lpVtbl -> GetLayerInfo(This,LayerType,pWidth,pHeight,pBitsPerPixel) ) 

#define ILMVIOvLy_get_OverlayImageFileName(This,pImageFileName)	\
    ( (This)->lpVtbl -> get_OverlayImageFileName(This,pImageFileName) ) 

#define ILMVIOvLy_put_OverlayImageFileName(This,ImageFileName)	\
    ( (This)->lpVtbl -> put_OverlayImageFileName(This,ImageFileName) ) 

#define ILMVIOvLy_put_OverlayImageDIBPointer(This,pDIB)	\
    ( (This)->lpVtbl -> put_OverlayImageDIBPointer(This,pDIB) ) 

#define ILMVIOvLy_get_IsOverlayImageLoaded(This,pLoaded)	\
    ( (This)->lpVtbl -> get_IsOverlayImageLoaded(This,pLoaded) ) 

#define ILMVIOvLy_get_BkLayerColor(This,pColor)	\
    ( (This)->lpVtbl -> get_BkLayerColor(This,pColor) ) 

#define ILMVIOvLy_put_BkLayerColor(This,Color)	\
    ( (This)->lpVtbl -> put_BkLayerColor(This,Color) ) 

#define ILMVIOvLy_get_EnableMaskBitmap(This,LayerType,pEnable)	\
    ( (This)->lpVtbl -> get_EnableMaskBitmap(This,LayerType,pEnable) ) 

#define ILMVIOvLy_put_EnableMaskBitmap(This,LayerType,Enable)	\
    ( (This)->lpVtbl -> put_EnableMaskBitmap(This,LayerType,Enable) ) 

#define ILMVIOvLy_get_MaskImageFileName(This,LayerType,pMaskImageFileName)	\
    ( (This)->lpVtbl -> get_MaskImageFileName(This,LayerType,pMaskImageFileName) ) 

#define ILMVIOvLy_put_MaskImageFileName(This,LayerType,MaskImageFileName)	\
    ( (This)->lpVtbl -> put_MaskImageFileName(This,LayerType,MaskImageFileName) ) 

#define ILMVIOvLy_put_MaskImageDIBPointer(This,LayerType,pDIB)	\
    ( (This)->lpVtbl -> put_MaskImageDIBPointer(This,LayerType,pDIB) ) 

#define ILMVIOvLy_get_IsMaskImageLoaded(This,LayerType,pLoaded)	\
    ( (This)->lpVtbl -> get_IsMaskImageLoaded(This,LayerType,pLoaded) ) 

#define ILMVIOvLy_get_EnableOpacity(This,LayerType,pEnable)	\
    ( (This)->lpVtbl -> get_EnableOpacity(This,LayerType,pEnable) ) 

#define ILMVIOvLy_put_EnableOpacity(This,LayerType,Enable)	\
    ( (This)->lpVtbl -> put_EnableOpacity(This,LayerType,Enable) ) 

#define ILMVIOvLy_get_Opacity(This,LayerType,pOpacity)	\
    ( (This)->lpVtbl -> get_Opacity(This,LayerType,pOpacity) ) 

#define ILMVIOvLy_put_Opacity(This,LayerType,Opacity)	\
    ( (This)->lpVtbl -> put_Opacity(This,LayerType,Opacity) ) 

#define ILMVIOvLy_get_EnableTransparency(This,LayerType,pEnable)	\
    ( (This)->lpVtbl -> get_EnableTransparency(This,LayerType,pEnable) ) 

#define ILMVIOvLy_put_EnableTransparency(This,LayerType,bEnable)	\
    ( (This)->lpVtbl -> put_EnableTransparency(This,LayerType,bEnable) ) 

#define ILMVIOvLy_get_TransparentColor(This,LayerType,pColor)	\
    ( (This)->lpVtbl -> get_TransparentColor(This,LayerType,pColor) ) 

#define ILMVIOvLy_put_TransparentColor(This,LayerType,Color)	\
    ( (This)->lpVtbl -> put_TransparentColor(This,LayerType,Color) ) 

#define ILMVIOvLy_get_XPos(This,LayerType,pXPos)	\
    ( (This)->lpVtbl -> get_XPos(This,LayerType,pXPos) ) 

#define ILMVIOvLy_put_XPos(This,LayerType,XPos)	\
    ( (This)->lpVtbl -> put_XPos(This,LayerType,XPos) ) 

#define ILMVIOvLy_get_YPos(This,LayerType,pYPos)	\
    ( (This)->lpVtbl -> get_YPos(This,LayerType,pYPos) ) 

#define ILMVIOvLy_put_YPos(This,LayerType,YPos)	\
    ( (This)->lpVtbl -> put_YPos(This,LayerType,YPos) ) 

#define ILMVIOvLy_get_Region(This,LayerType,pRegion)	\
    ( (This)->lpVtbl -> get_Region(This,LayerType,pRegion) ) 

#define ILMVIOvLy_put_Region(This,LayerType,Region)	\
    ( (This)->lpVtbl -> put_Region(This,LayerType,Region) ) 

#define ILMVIOvLy_get_RgnLeft(This,LayerType,pLeft)	\
    ( (This)->lpVtbl -> get_RgnLeft(This,LayerType,pLeft) ) 

#define ILMVIOvLy_put_RgnLeft(This,LayerType,Left)	\
    ( (This)->lpVtbl -> put_RgnLeft(This,LayerType,Left) ) 

#define ILMVIOvLy_get_RgnTop(This,LayerType,pTop)	\
    ( (This)->lpVtbl -> get_RgnTop(This,LayerType,pTop) ) 

#define ILMVIOvLy_put_RgnTop(This,LayerType,Top)	\
    ( (This)->lpVtbl -> put_RgnTop(This,LayerType,Top) ) 

#define ILMVIOvLy_get_RgnRight(This,LayerType,pRight)	\
    ( (This)->lpVtbl -> get_RgnRight(This,LayerType,pRight) ) 

#define ILMVIOvLy_put_RgnRight(This,LayerType,Right)	\
    ( (This)->lpVtbl -> put_RgnRight(This,LayerType,Right) ) 

#define ILMVIOvLy_get_RgnBottom(This,LayerType,pBottom)	\
    ( (This)->lpVtbl -> get_RgnBottom(This,LayerType,pBottom) ) 

#define ILMVIOvLy_put_RgnBottom(This,LayerType,Bottom)	\
    ( (This)->lpVtbl -> put_RgnBottom(This,LayerType,Bottom) ) 

#define ILMVIOvLy_get_RgnRoundRectEllipseWidth(This,LayerType,pWidth)	\
    ( (This)->lpVtbl -> get_RgnRoundRectEllipseWidth(This,LayerType,pWidth) ) 

#define ILMVIOvLy_put_RgnRoundRectEllipseWidth(This,LayerType,Width)	\
    ( (This)->lpVtbl -> put_RgnRoundRectEllipseWidth(This,LayerType,Width) ) 

#define ILMVIOvLy_get_RgnRoundRectEllipseHeight(This,LayerType,pHeight)	\
    ( (This)->lpVtbl -> get_RgnRoundRectEllipseHeight(This,LayerType,pHeight) ) 

#define ILMVIOvLy_put_RgnRoundRectEllipseHeight(This,LayerType,Height)	\
    ( (This)->lpVtbl -> put_RgnRoundRectEllipseHeight(This,LayerType,Height) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMVIOvLy_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LMVIOvLy;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DF63-38C5-11D5-91F6-00104BDB8FF9")
LMVIOvLy;
#endif
#endif /* __LMVIOvLyLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


