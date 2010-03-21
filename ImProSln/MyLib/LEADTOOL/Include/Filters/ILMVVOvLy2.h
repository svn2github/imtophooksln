

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Nov 05 12:42:05 2009
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


#ifndef __ILMVVOvLy2_h__
#define __ILMVVOvLy2_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILMVVOvLy_FWD_DEFINED__
#define __ILMVVOvLy_FWD_DEFINED__
typedef interface ILMVVOvLy ILMVVOvLy;
#endif 	/* __ILMVVOvLy_FWD_DEFINED__ */


#ifndef __LMVVOvLy_FWD_DEFINED__
#define __LMVVOvLy_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMVVOvLy LMVVOvLy;
#else
typedef struct LMVVOvLy LMVVOvLy;
#endif /* __cplusplus */

#endif 	/* __LMVVOvLy_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LMVVOvLyLib_LIBRARY_DEFINED__
#define __LMVVOvLyLib_LIBRARY_DEFINED__

/* library LMVVOvLyLib */
/* [helpstring][version][uuid] */ 

#ifndef __IVOvLy2_H__
#define __IVOvLy2_H__
static const GUID LIBID_LMVVOvLyLib          = {0xe2b7de25, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVVOvLy             = {0xe2b7de26, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVVOvLyPropertyPage = {0xe2b7de27, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVAboutVOvLy        = {0xe2b7de28, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMVVOvLy              = {0xe2b7de29, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
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
	LAYERTYPE_VIDEO1	= 1,
	LAYERTYPE_VIDEO2	= 2,
	LAYERTYPE_OVERLAYIMAGE	= 3
    } 	LayerTypeConstants;


EXTERN_C const IID LIBID_LMVVOvLyLib;

#ifndef __ILMVVOvLy_INTERFACE_DEFINED__
#define __ILMVVOvLy_INTERFACE_DEFINED__

/* interface ILMVVOvLy */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ILMVVOvLy;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DE29-38C5-11D5-91F6-00104BDB8FF9")
    ILMVVOvLy : public IDispatch
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

    typedef struct ILMVVOvLyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMVVOvLy * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMVVOvLy * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMVVOvLy * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMVVOvLy * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMVVOvLy * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMVVOvLy * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMVVOvLy * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveLayersCount )( 
            ILMVVOvLy * This,
            /* [retval][out] */ long *pCount);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsLayerActive )( 
            ILMVVOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [retval][out] */ VARIANT_BOOL *pActive);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LayerOrder )( 
            ILMVVOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [retval][out] */ long *pIndex);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LayerOrder )( 
            ILMVVOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [in] */ long Index);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetLayerInfo )( 
            ILMVVOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [out] */ long *pWidth,
            /* [out] */ long *pHeight,
            /* [out] */ long *pBitsPerPixel);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OverlayImageFileName )( 
            ILMVVOvLy * This,
            /* [retval][out] */ BSTR *pImageFileName);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OverlayImageFileName )( 
            ILMVVOvLy * This,
            /* [in] */ BSTR ImageFileName);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OverlayImageDIBPointer )( 
            ILMVVOvLy * This,
            /* [in] */ long pDIB);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsOverlayImageLoaded )( 
            ILMVVOvLy * This,
            /* [retval][out] */ VARIANT_BOOL *pLoaded);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BkLayerColor )( 
            ILMVVOvLy * This,
            /* [retval][out] */ long *pColor);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BkLayerColor )( 
            ILMVVOvLy * This,
            /* [in] */ long Color);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableMaskBitmap )( 
            ILMVVOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [retval][out] */ VARIANT_BOOL *pEnable);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableMaskBitmap )( 
            ILMVVOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [in] */ VARIANT_BOOL Enable);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MaskImageFileName )( 
            ILMVVOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [retval][out] */ BSTR *pMaskImageFileName);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MaskImageFileName )( 
            ILMVVOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [in] */ BSTR MaskImageFileName);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MaskImageDIBPointer )( 
            ILMVVOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [in] */ long pDIB);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsMaskImageLoaded )( 
            ILMVVOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [retval][out] */ VARIANT_BOOL *pLoaded);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableOpacity )( 
            ILMVVOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [retval][out] */ VARIANT_BOOL *pEnable);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableOpacity )( 
            ILMVVOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [in] */ VARIANT_BOOL Enable);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Opacity )( 
            ILMVVOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [retval][out] */ long *pOpacity);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Opacity )( 
            ILMVVOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [in] */ long Opacity);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableTransparency )( 
            ILMVVOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [retval][out] */ VARIANT_BOOL *pEnable);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableTransparency )( 
            ILMVVOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [in] */ VARIANT_BOOL bEnable);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TransparentColor )( 
            ILMVVOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [retval][out] */ long *pColor);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TransparentColor )( 
            ILMVVOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [in] */ long Color);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_XPos )( 
            ILMVVOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [retval][out] */ long *pXPos);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_XPos )( 
            ILMVVOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [in] */ long XPos);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_YPos )( 
            ILMVVOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [retval][out] */ long *pYPos);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_YPos )( 
            ILMVVOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [in] */ long YPos);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Region )( 
            ILMVVOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [retval][out] */ RegionConstants *pRegion);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Region )( 
            ILMVVOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [in] */ RegionConstants Region);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RgnLeft )( 
            ILMVVOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [retval][out] */ long *pLeft);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RgnLeft )( 
            ILMVVOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [in] */ long Left);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RgnTop )( 
            ILMVVOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [retval][out] */ long *pTop);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RgnTop )( 
            ILMVVOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [in] */ long Top);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RgnRight )( 
            ILMVVOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [retval][out] */ long *pRight);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RgnRight )( 
            ILMVVOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [in] */ long Right);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RgnBottom )( 
            ILMVVOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [retval][out] */ long *pBottom);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RgnBottom )( 
            ILMVVOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [in] */ long Bottom);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RgnRoundRectEllipseWidth )( 
            ILMVVOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [retval][out] */ long *pWidth);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RgnRoundRectEllipseWidth )( 
            ILMVVOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [in] */ long Width);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RgnRoundRectEllipseHeight )( 
            ILMVVOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [retval][out] */ long *pHeight);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RgnRoundRectEllipseHeight )( 
            ILMVVOvLy * This,
            /* [in] */ LayerTypeConstants LayerType,
            /* [in] */ long Height);
        
        END_INTERFACE
    } ILMVVOvLyVtbl;

    interface ILMVVOvLy
    {
        CONST_VTBL struct ILMVVOvLyVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMVVOvLy_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMVVOvLy_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMVVOvLy_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMVVOvLy_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMVVOvLy_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMVVOvLy_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMVVOvLy_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMVVOvLy_get_ActiveLayersCount(This,pCount)	\
    ( (This)->lpVtbl -> get_ActiveLayersCount(This,pCount) ) 

#define ILMVVOvLy_get_IsLayerActive(This,LayerType,pActive)	\
    ( (This)->lpVtbl -> get_IsLayerActive(This,LayerType,pActive) ) 

#define ILMVVOvLy_get_LayerOrder(This,LayerType,pIndex)	\
    ( (This)->lpVtbl -> get_LayerOrder(This,LayerType,pIndex) ) 

#define ILMVVOvLy_put_LayerOrder(This,LayerType,Index)	\
    ( (This)->lpVtbl -> put_LayerOrder(This,LayerType,Index) ) 

#define ILMVVOvLy_GetLayerInfo(This,LayerType,pWidth,pHeight,pBitsPerPixel)	\
    ( (This)->lpVtbl -> GetLayerInfo(This,LayerType,pWidth,pHeight,pBitsPerPixel) ) 

#define ILMVVOvLy_get_OverlayImageFileName(This,pImageFileName)	\
    ( (This)->lpVtbl -> get_OverlayImageFileName(This,pImageFileName) ) 

#define ILMVVOvLy_put_OverlayImageFileName(This,ImageFileName)	\
    ( (This)->lpVtbl -> put_OverlayImageFileName(This,ImageFileName) ) 

#define ILMVVOvLy_put_OverlayImageDIBPointer(This,pDIB)	\
    ( (This)->lpVtbl -> put_OverlayImageDIBPointer(This,pDIB) ) 

#define ILMVVOvLy_get_IsOverlayImageLoaded(This,pLoaded)	\
    ( (This)->lpVtbl -> get_IsOverlayImageLoaded(This,pLoaded) ) 

#define ILMVVOvLy_get_BkLayerColor(This,pColor)	\
    ( (This)->lpVtbl -> get_BkLayerColor(This,pColor) ) 

#define ILMVVOvLy_put_BkLayerColor(This,Color)	\
    ( (This)->lpVtbl -> put_BkLayerColor(This,Color) ) 

#define ILMVVOvLy_get_EnableMaskBitmap(This,LayerType,pEnable)	\
    ( (This)->lpVtbl -> get_EnableMaskBitmap(This,LayerType,pEnable) ) 

#define ILMVVOvLy_put_EnableMaskBitmap(This,LayerType,Enable)	\
    ( (This)->lpVtbl -> put_EnableMaskBitmap(This,LayerType,Enable) ) 

#define ILMVVOvLy_get_MaskImageFileName(This,LayerType,pMaskImageFileName)	\
    ( (This)->lpVtbl -> get_MaskImageFileName(This,LayerType,pMaskImageFileName) ) 

#define ILMVVOvLy_put_MaskImageFileName(This,LayerType,MaskImageFileName)	\
    ( (This)->lpVtbl -> put_MaskImageFileName(This,LayerType,MaskImageFileName) ) 

#define ILMVVOvLy_put_MaskImageDIBPointer(This,LayerType,pDIB)	\
    ( (This)->lpVtbl -> put_MaskImageDIBPointer(This,LayerType,pDIB) ) 

#define ILMVVOvLy_get_IsMaskImageLoaded(This,LayerType,pLoaded)	\
    ( (This)->lpVtbl -> get_IsMaskImageLoaded(This,LayerType,pLoaded) ) 

#define ILMVVOvLy_get_EnableOpacity(This,LayerType,pEnable)	\
    ( (This)->lpVtbl -> get_EnableOpacity(This,LayerType,pEnable) ) 

#define ILMVVOvLy_put_EnableOpacity(This,LayerType,Enable)	\
    ( (This)->lpVtbl -> put_EnableOpacity(This,LayerType,Enable) ) 

#define ILMVVOvLy_get_Opacity(This,LayerType,pOpacity)	\
    ( (This)->lpVtbl -> get_Opacity(This,LayerType,pOpacity) ) 

#define ILMVVOvLy_put_Opacity(This,LayerType,Opacity)	\
    ( (This)->lpVtbl -> put_Opacity(This,LayerType,Opacity) ) 

#define ILMVVOvLy_get_EnableTransparency(This,LayerType,pEnable)	\
    ( (This)->lpVtbl -> get_EnableTransparency(This,LayerType,pEnable) ) 

#define ILMVVOvLy_put_EnableTransparency(This,LayerType,bEnable)	\
    ( (This)->lpVtbl -> put_EnableTransparency(This,LayerType,bEnable) ) 

#define ILMVVOvLy_get_TransparentColor(This,LayerType,pColor)	\
    ( (This)->lpVtbl -> get_TransparentColor(This,LayerType,pColor) ) 

#define ILMVVOvLy_put_TransparentColor(This,LayerType,Color)	\
    ( (This)->lpVtbl -> put_TransparentColor(This,LayerType,Color) ) 

#define ILMVVOvLy_get_XPos(This,LayerType,pXPos)	\
    ( (This)->lpVtbl -> get_XPos(This,LayerType,pXPos) ) 

#define ILMVVOvLy_put_XPos(This,LayerType,XPos)	\
    ( (This)->lpVtbl -> put_XPos(This,LayerType,XPos) ) 

#define ILMVVOvLy_get_YPos(This,LayerType,pYPos)	\
    ( (This)->lpVtbl -> get_YPos(This,LayerType,pYPos) ) 

#define ILMVVOvLy_put_YPos(This,LayerType,YPos)	\
    ( (This)->lpVtbl -> put_YPos(This,LayerType,YPos) ) 

#define ILMVVOvLy_get_Region(This,LayerType,pRegion)	\
    ( (This)->lpVtbl -> get_Region(This,LayerType,pRegion) ) 

#define ILMVVOvLy_put_Region(This,LayerType,Region)	\
    ( (This)->lpVtbl -> put_Region(This,LayerType,Region) ) 

#define ILMVVOvLy_get_RgnLeft(This,LayerType,pLeft)	\
    ( (This)->lpVtbl -> get_RgnLeft(This,LayerType,pLeft) ) 

#define ILMVVOvLy_put_RgnLeft(This,LayerType,Left)	\
    ( (This)->lpVtbl -> put_RgnLeft(This,LayerType,Left) ) 

#define ILMVVOvLy_get_RgnTop(This,LayerType,pTop)	\
    ( (This)->lpVtbl -> get_RgnTop(This,LayerType,pTop) ) 

#define ILMVVOvLy_put_RgnTop(This,LayerType,Top)	\
    ( (This)->lpVtbl -> put_RgnTop(This,LayerType,Top) ) 

#define ILMVVOvLy_get_RgnRight(This,LayerType,pRight)	\
    ( (This)->lpVtbl -> get_RgnRight(This,LayerType,pRight) ) 

#define ILMVVOvLy_put_RgnRight(This,LayerType,Right)	\
    ( (This)->lpVtbl -> put_RgnRight(This,LayerType,Right) ) 

#define ILMVVOvLy_get_RgnBottom(This,LayerType,pBottom)	\
    ( (This)->lpVtbl -> get_RgnBottom(This,LayerType,pBottom) ) 

#define ILMVVOvLy_put_RgnBottom(This,LayerType,Bottom)	\
    ( (This)->lpVtbl -> put_RgnBottom(This,LayerType,Bottom) ) 

#define ILMVVOvLy_get_RgnRoundRectEllipseWidth(This,LayerType,pWidth)	\
    ( (This)->lpVtbl -> get_RgnRoundRectEllipseWidth(This,LayerType,pWidth) ) 

#define ILMVVOvLy_put_RgnRoundRectEllipseWidth(This,LayerType,Width)	\
    ( (This)->lpVtbl -> put_RgnRoundRectEllipseWidth(This,LayerType,Width) ) 

#define ILMVVOvLy_get_RgnRoundRectEllipseHeight(This,LayerType,pHeight)	\
    ( (This)->lpVtbl -> get_RgnRoundRectEllipseHeight(This,LayerType,pHeight) ) 

#define ILMVVOvLy_put_RgnRoundRectEllipseHeight(This,LayerType,Height)	\
    ( (This)->lpVtbl -> put_RgnRoundRectEllipseHeight(This,LayerType,Height) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMVVOvLy_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LMVVOvLy;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DE26-38C5-11D5-91F6-00104BDB8FF9")
LMVVOvLy;
#endif
#endif /* __LMVVOvLyLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


