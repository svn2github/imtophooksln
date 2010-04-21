

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Mon Dec 21 16:15:13 2009
 */
/* Compiler settings for .\ITOvrLy.idl:
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


#ifndef __ILMVTOvly2_h__
#define __ILMVTOvly2_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILMVTextOverlayOld1_FWD_DEFINED__
#define __ILMVTextOverlayOld1_FWD_DEFINED__
typedef interface ILMVTextOverlayOld1 ILMVTextOverlayOld1;
#endif 	/* __ILMVTextOverlayOld1_FWD_DEFINED__ */


#ifndef __ILMVTextOverlay_FWD_DEFINED__
#define __ILMVTextOverlay_FWD_DEFINED__
typedef interface ILMVTextOverlay ILMVTextOverlay;
#endif 	/* __ILMVTextOverlay_FWD_DEFINED__ */


#ifndef __LMVTextOverlay_FWD_DEFINED__
#define __LMVTextOverlay_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMVTextOverlay LMVTextOverlay;
#else
typedef struct LMVTextOverlay LMVTextOverlay;
#endif /* __cplusplus */

#endif 	/* __LMVTextOverlay_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LMVTextOverlayLib_LIBRARY_DEFINED__
#define __LMVTextOverlayLib_LIBRARY_DEFINED__

/* library LMVTextOverlayLib */
/* [helpstring][version][uuid] */ 

#ifndef __ITOvLy2_H__
#define __ITOvLy2_H__
static const GUID CLSID_LMVTextOverlay                 = {0xe2b7dd9c, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVTextOverlayPropertyPage     = {0xe2b7dd9d, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVTextOverlayPropertyPage2    = {0xe2b7dd9e, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMVTextOverlayOld1              = {0xe2b7dd9f, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMVTextOverlay                  = {0xe2b7de40, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVAboutTextOverlay            = {0xe2b7dda0, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID LIBID_LMVTextOverlayLib              = {0xe2b7dda1, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
#endif 
typedef /* [v1_enum] */ 
enum TextAlignmentConstants
    {	ALIGN_TOP	= 0x1,
	ALIGN_LEFT	= 0x2,
	ALIGN_RIGHT	= 0x4,
	ALIGN_BOTTOM	= 0x8,
	ALIGN_VCENTER	= 0x10,
	ALIGN_HCENTER	= 0x20
    } 	TextAlignmentConstants;

typedef /* [v1_enum] */ 
enum ScrollDirectionConstants
    {	SCROLL_LEFT_RIGHT	= 1,
	SCROLL_RIGHT_LEFT	= 2,
	SCROLL_TOP_BOTTOM	= 3,
	SCROLL_BOTTOM_TOP	= 4
    } 	ScrollDirectionConstants;

typedef /* [v1_enum] */ 
enum PenStyleConstants
    {	PENS_SOLID	= 0,
	PENS_DASH	= 1,
	PENS_DOT	= 2,
	PENS_DASHDOT	= 3,
	PENS_DASHDOTDOT	= 4
    } 	PenStyleConstants;

typedef /* [v1_enum] */ 
enum BrushStyleConstants
    {	BRUSHS_NULL	= -1,
	BRUSHS_SOLID	= 0,
	BRUSHS_HORIZONTAL	= 1,
	BRUSHS_VERTICAL	= 2,
	BRUSHS_FDIAGONAL	= 3,
	BRUSHS_BDIAGONAL	= 4,
	BRUSHS_CROSS	= 5,
	BRUSHS_DIAGCROSS	= 6
    } 	BrushStyleConstants;

typedef /* [v1_enum] */ 
enum RotationCenterConstants
    {	ROTATIONCENTER_LEFT_TOP	= 0,
	ROTATIONCENTER_RIGHT_TOP	= 1,
	ROTATIONCENTER_CENTER	= 2,
	ROTATIONCENTER_AUTO	= 3
    } 	RotationCenterConstants;


EXTERN_C const IID LIBID_LMVTextOverlayLib;

#ifndef __ILMVTextOverlayOld1_INTERFACE_DEFINED__
#define __ILMVTextOverlayOld1_INTERFACE_DEFINED__

/* interface ILMVTextOverlayOld1 */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ILMVTextOverlayOld1;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DD9F-38C5-11D5-91F6-00104BDB8FF9")
    ILMVTextOverlayOld1 : public IDispatch
    {
    public:
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
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EnableTextOverLay( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_EnableTextOverLay( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OverlayText( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OverlayText( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FontName( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FontName( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FontSize( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FontSize( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FontColor( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FontColor( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FontBKColor( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FontBKColor( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Bold( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Bold( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Italic( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Italic( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UnderLine( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_UnderLine( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StrikeOut( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_StrikeOut( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RotationAngle( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RotationAngle( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EnableXYPosition( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_EnableXYPosition( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_XPos( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_XPos( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_YPos( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_YPos( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EnableTextFromFile( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_EnableTextFromFile( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TextFileName( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_TextFileName( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TextAlignment( 
            /* [retval][out] */ TextAlignmentConstants *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_TextAlignment( 
            /* [in] */ TextAlignmentConstants newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EnableOutline( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_EnableOutline( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OutlineWidth( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OutlineWidth( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OutlinePenColor( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OutlinePenColor( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OutlineBrushColor( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OutlineBrushColor( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PenStyle( 
            /* [retval][out] */ PenStyleConstants *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PenStyle( 
            /* [in] */ PenStyleConstants newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BrushStyle( 
            /* [retval][out] */ BrushStyleConstants *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_BrushStyle( 
            /* [in] */ BrushStyleConstants newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TransparentOutline( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_TransparentOutline( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ScrollDirection( 
            /* [retval][out] */ ScrollDirectionConstants *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ScrollDirection( 
            /* [in] */ ScrollDirectionConstants newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TextRepeating( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_TextRepeating( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_WordWrap( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_WordWrap( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EnableOpacity( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_EnableOpacity( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Opacity( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Opacity( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ViewBackground( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ViewBackground( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AvgCharWidth( 
            /* [retval][out] */ long *ppVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MaxCharWidth( 
            /* [retval][out] */ long *ppVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CharHeight( 
            /* [retval][out] */ long *ppVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ViewRectLeft( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ViewRectLeft( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ViewRectRight( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ViewRectRight( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ViewRectTop( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ViewRectTop( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ViewRectBottom( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ViewRectBottom( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AutoReposToViewRect( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AutoReposToViewRect( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CurrentText( 
            /* [in] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RotationCenter( 
            /* [retval][out] */ RotationCenterConstants *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RotationCenter( 
            /* [in] */ RotationCenterConstants newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TextAlwaysVisible( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_TextAlwaysVisible( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IgnoreHTMLTags( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_IgnoreHTMLTags( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ResetToDefaults( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMVTextOverlayOld1Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMVTextOverlayOld1 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMVTextOverlayOld1 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMVTextOverlayOld1 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMVTextOverlayOld1 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMVTextOverlayOld1 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMVTextOverlayOld1 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMVTextOverlayOld1 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsLEADInputPinConnected )( 
            ILMVTextOverlayOld1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsLEADOutputPinConnected )( 
            ILMVTextOverlayOld1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InWidth )( 
            ILMVTextOverlayOld1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InHeight )( 
            ILMVTextOverlayOld1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutWidth )( 
            ILMVTextOverlayOld1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutHeight )( 
            ILMVTextOverlayOld1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InBits )( 
            ILMVTextOverlayOld1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutBits )( 
            ILMVTextOverlayOld1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableTextOverLay )( 
            ILMVTextOverlayOld1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableTextOverLay )( 
            ILMVTextOverlayOld1 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OverlayText )( 
            ILMVTextOverlayOld1 * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OverlayText )( 
            ILMVTextOverlayOld1 * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FontName )( 
            ILMVTextOverlayOld1 * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FontName )( 
            ILMVTextOverlayOld1 * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FontSize )( 
            ILMVTextOverlayOld1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FontSize )( 
            ILMVTextOverlayOld1 * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FontColor )( 
            ILMVTextOverlayOld1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FontColor )( 
            ILMVTextOverlayOld1 * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FontBKColor )( 
            ILMVTextOverlayOld1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FontBKColor )( 
            ILMVTextOverlayOld1 * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Bold )( 
            ILMVTextOverlayOld1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Bold )( 
            ILMVTextOverlayOld1 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Italic )( 
            ILMVTextOverlayOld1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Italic )( 
            ILMVTextOverlayOld1 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UnderLine )( 
            ILMVTextOverlayOld1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UnderLine )( 
            ILMVTextOverlayOld1 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StrikeOut )( 
            ILMVTextOverlayOld1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_StrikeOut )( 
            ILMVTextOverlayOld1 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RotationAngle )( 
            ILMVTextOverlayOld1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RotationAngle )( 
            ILMVTextOverlayOld1 * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableXYPosition )( 
            ILMVTextOverlayOld1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableXYPosition )( 
            ILMVTextOverlayOld1 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_XPos )( 
            ILMVTextOverlayOld1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_XPos )( 
            ILMVTextOverlayOld1 * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_YPos )( 
            ILMVTextOverlayOld1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_YPos )( 
            ILMVTextOverlayOld1 * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableTextFromFile )( 
            ILMVTextOverlayOld1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableTextFromFile )( 
            ILMVTextOverlayOld1 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TextFileName )( 
            ILMVTextOverlayOld1 * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TextFileName )( 
            ILMVTextOverlayOld1 * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TextAlignment )( 
            ILMVTextOverlayOld1 * This,
            /* [retval][out] */ TextAlignmentConstants *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TextAlignment )( 
            ILMVTextOverlayOld1 * This,
            /* [in] */ TextAlignmentConstants newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableOutline )( 
            ILMVTextOverlayOld1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableOutline )( 
            ILMVTextOverlayOld1 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutlineWidth )( 
            ILMVTextOverlayOld1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OutlineWidth )( 
            ILMVTextOverlayOld1 * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutlinePenColor )( 
            ILMVTextOverlayOld1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OutlinePenColor )( 
            ILMVTextOverlayOld1 * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutlineBrushColor )( 
            ILMVTextOverlayOld1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OutlineBrushColor )( 
            ILMVTextOverlayOld1 * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PenStyle )( 
            ILMVTextOverlayOld1 * This,
            /* [retval][out] */ PenStyleConstants *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PenStyle )( 
            ILMVTextOverlayOld1 * This,
            /* [in] */ PenStyleConstants newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BrushStyle )( 
            ILMVTextOverlayOld1 * This,
            /* [retval][out] */ BrushStyleConstants *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BrushStyle )( 
            ILMVTextOverlayOld1 * This,
            /* [in] */ BrushStyleConstants newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TransparentOutline )( 
            ILMVTextOverlayOld1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TransparentOutline )( 
            ILMVTextOverlayOld1 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ScrollDirection )( 
            ILMVTextOverlayOld1 * This,
            /* [retval][out] */ ScrollDirectionConstants *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ScrollDirection )( 
            ILMVTextOverlayOld1 * This,
            /* [in] */ ScrollDirectionConstants newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TextRepeating )( 
            ILMVTextOverlayOld1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TextRepeating )( 
            ILMVTextOverlayOld1 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_WordWrap )( 
            ILMVTextOverlayOld1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_WordWrap )( 
            ILMVTextOverlayOld1 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableOpacity )( 
            ILMVTextOverlayOld1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableOpacity )( 
            ILMVTextOverlayOld1 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Opacity )( 
            ILMVTextOverlayOld1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Opacity )( 
            ILMVTextOverlayOld1 * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ViewBackground )( 
            ILMVTextOverlayOld1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ViewBackground )( 
            ILMVTextOverlayOld1 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AvgCharWidth )( 
            ILMVTextOverlayOld1 * This,
            /* [retval][out] */ long *ppVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MaxCharWidth )( 
            ILMVTextOverlayOld1 * This,
            /* [retval][out] */ long *ppVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CharHeight )( 
            ILMVTextOverlayOld1 * This,
            /* [retval][out] */ long *ppVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ViewRectLeft )( 
            ILMVTextOverlayOld1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ViewRectLeft )( 
            ILMVTextOverlayOld1 * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ViewRectRight )( 
            ILMVTextOverlayOld1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ViewRectRight )( 
            ILMVTextOverlayOld1 * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ViewRectTop )( 
            ILMVTextOverlayOld1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ViewRectTop )( 
            ILMVTextOverlayOld1 * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ViewRectBottom )( 
            ILMVTextOverlayOld1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ViewRectBottom )( 
            ILMVTextOverlayOld1 * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AutoReposToViewRect )( 
            ILMVTextOverlayOld1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AutoReposToViewRect )( 
            ILMVTextOverlayOld1 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentText )( 
            ILMVTextOverlayOld1 * This,
            /* [in] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RotationCenter )( 
            ILMVTextOverlayOld1 * This,
            /* [retval][out] */ RotationCenterConstants *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RotationCenter )( 
            ILMVTextOverlayOld1 * This,
            /* [in] */ RotationCenterConstants newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TextAlwaysVisible )( 
            ILMVTextOverlayOld1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TextAlwaysVisible )( 
            ILMVTextOverlayOld1 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IgnoreHTMLTags )( 
            ILMVTextOverlayOld1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IgnoreHTMLTags )( 
            ILMVTextOverlayOld1 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetToDefaults )( 
            ILMVTextOverlayOld1 * This);
        
        END_INTERFACE
    } ILMVTextOverlayOld1Vtbl;

    interface ILMVTextOverlayOld1
    {
        CONST_VTBL struct ILMVTextOverlayOld1Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMVTextOverlayOld1_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMVTextOverlayOld1_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMVTextOverlayOld1_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMVTextOverlayOld1_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMVTextOverlayOld1_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMVTextOverlayOld1_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMVTextOverlayOld1_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMVTextOverlayOld1_get_IsLEADInputPinConnected(This,pVal)	\
    ( (This)->lpVtbl -> get_IsLEADInputPinConnected(This,pVal) ) 

#define ILMVTextOverlayOld1_get_IsLEADOutputPinConnected(This,pVal)	\
    ( (This)->lpVtbl -> get_IsLEADOutputPinConnected(This,pVal) ) 

#define ILMVTextOverlayOld1_get_InWidth(This,pVal)	\
    ( (This)->lpVtbl -> get_InWidth(This,pVal) ) 

#define ILMVTextOverlayOld1_get_InHeight(This,pVal)	\
    ( (This)->lpVtbl -> get_InHeight(This,pVal) ) 

#define ILMVTextOverlayOld1_get_OutWidth(This,pVal)	\
    ( (This)->lpVtbl -> get_OutWidth(This,pVal) ) 

#define ILMVTextOverlayOld1_get_OutHeight(This,pVal)	\
    ( (This)->lpVtbl -> get_OutHeight(This,pVal) ) 

#define ILMVTextOverlayOld1_get_InBits(This,pVal)	\
    ( (This)->lpVtbl -> get_InBits(This,pVal) ) 

#define ILMVTextOverlayOld1_get_OutBits(This,pVal)	\
    ( (This)->lpVtbl -> get_OutBits(This,pVal) ) 

#define ILMVTextOverlayOld1_get_EnableTextOverLay(This,pVal)	\
    ( (This)->lpVtbl -> get_EnableTextOverLay(This,pVal) ) 

#define ILMVTextOverlayOld1_put_EnableTextOverLay(This,newVal)	\
    ( (This)->lpVtbl -> put_EnableTextOverLay(This,newVal) ) 

#define ILMVTextOverlayOld1_get_OverlayText(This,pVal)	\
    ( (This)->lpVtbl -> get_OverlayText(This,pVal) ) 

#define ILMVTextOverlayOld1_put_OverlayText(This,newVal)	\
    ( (This)->lpVtbl -> put_OverlayText(This,newVal) ) 

#define ILMVTextOverlayOld1_get_FontName(This,pVal)	\
    ( (This)->lpVtbl -> get_FontName(This,pVal) ) 

#define ILMVTextOverlayOld1_put_FontName(This,newVal)	\
    ( (This)->lpVtbl -> put_FontName(This,newVal) ) 

#define ILMVTextOverlayOld1_get_FontSize(This,pVal)	\
    ( (This)->lpVtbl -> get_FontSize(This,pVal) ) 

#define ILMVTextOverlayOld1_put_FontSize(This,newVal)	\
    ( (This)->lpVtbl -> put_FontSize(This,newVal) ) 

#define ILMVTextOverlayOld1_get_FontColor(This,pVal)	\
    ( (This)->lpVtbl -> get_FontColor(This,pVal) ) 

#define ILMVTextOverlayOld1_put_FontColor(This,newVal)	\
    ( (This)->lpVtbl -> put_FontColor(This,newVal) ) 

#define ILMVTextOverlayOld1_get_FontBKColor(This,pVal)	\
    ( (This)->lpVtbl -> get_FontBKColor(This,pVal) ) 

#define ILMVTextOverlayOld1_put_FontBKColor(This,newVal)	\
    ( (This)->lpVtbl -> put_FontBKColor(This,newVal) ) 

#define ILMVTextOverlayOld1_get_Bold(This,pVal)	\
    ( (This)->lpVtbl -> get_Bold(This,pVal) ) 

#define ILMVTextOverlayOld1_put_Bold(This,newVal)	\
    ( (This)->lpVtbl -> put_Bold(This,newVal) ) 

#define ILMVTextOverlayOld1_get_Italic(This,pVal)	\
    ( (This)->lpVtbl -> get_Italic(This,pVal) ) 

#define ILMVTextOverlayOld1_put_Italic(This,newVal)	\
    ( (This)->lpVtbl -> put_Italic(This,newVal) ) 

#define ILMVTextOverlayOld1_get_UnderLine(This,pVal)	\
    ( (This)->lpVtbl -> get_UnderLine(This,pVal) ) 

#define ILMVTextOverlayOld1_put_UnderLine(This,newVal)	\
    ( (This)->lpVtbl -> put_UnderLine(This,newVal) ) 

#define ILMVTextOverlayOld1_get_StrikeOut(This,pVal)	\
    ( (This)->lpVtbl -> get_StrikeOut(This,pVal) ) 

#define ILMVTextOverlayOld1_put_StrikeOut(This,newVal)	\
    ( (This)->lpVtbl -> put_StrikeOut(This,newVal) ) 

#define ILMVTextOverlayOld1_get_RotationAngle(This,pVal)	\
    ( (This)->lpVtbl -> get_RotationAngle(This,pVal) ) 

#define ILMVTextOverlayOld1_put_RotationAngle(This,newVal)	\
    ( (This)->lpVtbl -> put_RotationAngle(This,newVal) ) 

#define ILMVTextOverlayOld1_get_EnableXYPosition(This,pVal)	\
    ( (This)->lpVtbl -> get_EnableXYPosition(This,pVal) ) 

#define ILMVTextOverlayOld1_put_EnableXYPosition(This,newVal)	\
    ( (This)->lpVtbl -> put_EnableXYPosition(This,newVal) ) 

#define ILMVTextOverlayOld1_get_XPos(This,pVal)	\
    ( (This)->lpVtbl -> get_XPos(This,pVal) ) 

#define ILMVTextOverlayOld1_put_XPos(This,newVal)	\
    ( (This)->lpVtbl -> put_XPos(This,newVal) ) 

#define ILMVTextOverlayOld1_get_YPos(This,pVal)	\
    ( (This)->lpVtbl -> get_YPos(This,pVal) ) 

#define ILMVTextOverlayOld1_put_YPos(This,newVal)	\
    ( (This)->lpVtbl -> put_YPos(This,newVal) ) 

#define ILMVTextOverlayOld1_get_EnableTextFromFile(This,pVal)	\
    ( (This)->lpVtbl -> get_EnableTextFromFile(This,pVal) ) 

#define ILMVTextOverlayOld1_put_EnableTextFromFile(This,newVal)	\
    ( (This)->lpVtbl -> put_EnableTextFromFile(This,newVal) ) 

#define ILMVTextOverlayOld1_get_TextFileName(This,pVal)	\
    ( (This)->lpVtbl -> get_TextFileName(This,pVal) ) 

#define ILMVTextOverlayOld1_put_TextFileName(This,newVal)	\
    ( (This)->lpVtbl -> put_TextFileName(This,newVal) ) 

#define ILMVTextOverlayOld1_get_TextAlignment(This,pVal)	\
    ( (This)->lpVtbl -> get_TextAlignment(This,pVal) ) 

#define ILMVTextOverlayOld1_put_TextAlignment(This,newVal)	\
    ( (This)->lpVtbl -> put_TextAlignment(This,newVal) ) 

#define ILMVTextOverlayOld1_get_EnableOutline(This,pVal)	\
    ( (This)->lpVtbl -> get_EnableOutline(This,pVal) ) 

#define ILMVTextOverlayOld1_put_EnableOutline(This,newVal)	\
    ( (This)->lpVtbl -> put_EnableOutline(This,newVal) ) 

#define ILMVTextOverlayOld1_get_OutlineWidth(This,pVal)	\
    ( (This)->lpVtbl -> get_OutlineWidth(This,pVal) ) 

#define ILMVTextOverlayOld1_put_OutlineWidth(This,newVal)	\
    ( (This)->lpVtbl -> put_OutlineWidth(This,newVal) ) 

#define ILMVTextOverlayOld1_get_OutlinePenColor(This,pVal)	\
    ( (This)->lpVtbl -> get_OutlinePenColor(This,pVal) ) 

#define ILMVTextOverlayOld1_put_OutlinePenColor(This,newVal)	\
    ( (This)->lpVtbl -> put_OutlinePenColor(This,newVal) ) 

#define ILMVTextOverlayOld1_get_OutlineBrushColor(This,pVal)	\
    ( (This)->lpVtbl -> get_OutlineBrushColor(This,pVal) ) 

#define ILMVTextOverlayOld1_put_OutlineBrushColor(This,newVal)	\
    ( (This)->lpVtbl -> put_OutlineBrushColor(This,newVal) ) 

#define ILMVTextOverlayOld1_get_PenStyle(This,pVal)	\
    ( (This)->lpVtbl -> get_PenStyle(This,pVal) ) 

#define ILMVTextOverlayOld1_put_PenStyle(This,newVal)	\
    ( (This)->lpVtbl -> put_PenStyle(This,newVal) ) 

#define ILMVTextOverlayOld1_get_BrushStyle(This,pVal)	\
    ( (This)->lpVtbl -> get_BrushStyle(This,pVal) ) 

#define ILMVTextOverlayOld1_put_BrushStyle(This,newVal)	\
    ( (This)->lpVtbl -> put_BrushStyle(This,newVal) ) 

#define ILMVTextOverlayOld1_get_TransparentOutline(This,pVal)	\
    ( (This)->lpVtbl -> get_TransparentOutline(This,pVal) ) 

#define ILMVTextOverlayOld1_put_TransparentOutline(This,newVal)	\
    ( (This)->lpVtbl -> put_TransparentOutline(This,newVal) ) 

#define ILMVTextOverlayOld1_get_ScrollDirection(This,pVal)	\
    ( (This)->lpVtbl -> get_ScrollDirection(This,pVal) ) 

#define ILMVTextOverlayOld1_put_ScrollDirection(This,newVal)	\
    ( (This)->lpVtbl -> put_ScrollDirection(This,newVal) ) 

#define ILMVTextOverlayOld1_get_TextRepeating(This,pVal)	\
    ( (This)->lpVtbl -> get_TextRepeating(This,pVal) ) 

#define ILMVTextOverlayOld1_put_TextRepeating(This,newVal)	\
    ( (This)->lpVtbl -> put_TextRepeating(This,newVal) ) 

#define ILMVTextOverlayOld1_get_WordWrap(This,pVal)	\
    ( (This)->lpVtbl -> get_WordWrap(This,pVal) ) 

#define ILMVTextOverlayOld1_put_WordWrap(This,newVal)	\
    ( (This)->lpVtbl -> put_WordWrap(This,newVal) ) 

#define ILMVTextOverlayOld1_get_EnableOpacity(This,pVal)	\
    ( (This)->lpVtbl -> get_EnableOpacity(This,pVal) ) 

#define ILMVTextOverlayOld1_put_EnableOpacity(This,newVal)	\
    ( (This)->lpVtbl -> put_EnableOpacity(This,newVal) ) 

#define ILMVTextOverlayOld1_get_Opacity(This,pVal)	\
    ( (This)->lpVtbl -> get_Opacity(This,pVal) ) 

#define ILMVTextOverlayOld1_put_Opacity(This,newVal)	\
    ( (This)->lpVtbl -> put_Opacity(This,newVal) ) 

#define ILMVTextOverlayOld1_get_ViewBackground(This,pVal)	\
    ( (This)->lpVtbl -> get_ViewBackground(This,pVal) ) 

#define ILMVTextOverlayOld1_put_ViewBackground(This,newVal)	\
    ( (This)->lpVtbl -> put_ViewBackground(This,newVal) ) 

#define ILMVTextOverlayOld1_get_AvgCharWidth(This,ppVal)	\
    ( (This)->lpVtbl -> get_AvgCharWidth(This,ppVal) ) 

#define ILMVTextOverlayOld1_get_MaxCharWidth(This,ppVal)	\
    ( (This)->lpVtbl -> get_MaxCharWidth(This,ppVal) ) 

#define ILMVTextOverlayOld1_get_CharHeight(This,ppVal)	\
    ( (This)->lpVtbl -> get_CharHeight(This,ppVal) ) 

#define ILMVTextOverlayOld1_get_ViewRectLeft(This,pVal)	\
    ( (This)->lpVtbl -> get_ViewRectLeft(This,pVal) ) 

#define ILMVTextOverlayOld1_put_ViewRectLeft(This,newVal)	\
    ( (This)->lpVtbl -> put_ViewRectLeft(This,newVal) ) 

#define ILMVTextOverlayOld1_get_ViewRectRight(This,pVal)	\
    ( (This)->lpVtbl -> get_ViewRectRight(This,pVal) ) 

#define ILMVTextOverlayOld1_put_ViewRectRight(This,newVal)	\
    ( (This)->lpVtbl -> put_ViewRectRight(This,newVal) ) 

#define ILMVTextOverlayOld1_get_ViewRectTop(This,pVal)	\
    ( (This)->lpVtbl -> get_ViewRectTop(This,pVal) ) 

#define ILMVTextOverlayOld1_put_ViewRectTop(This,newVal)	\
    ( (This)->lpVtbl -> put_ViewRectTop(This,newVal) ) 

#define ILMVTextOverlayOld1_get_ViewRectBottom(This,pVal)	\
    ( (This)->lpVtbl -> get_ViewRectBottom(This,pVal) ) 

#define ILMVTextOverlayOld1_put_ViewRectBottom(This,newVal)	\
    ( (This)->lpVtbl -> put_ViewRectBottom(This,newVal) ) 

#define ILMVTextOverlayOld1_get_AutoReposToViewRect(This,pVal)	\
    ( (This)->lpVtbl -> get_AutoReposToViewRect(This,pVal) ) 

#define ILMVTextOverlayOld1_put_AutoReposToViewRect(This,newVal)	\
    ( (This)->lpVtbl -> put_AutoReposToViewRect(This,newVal) ) 

#define ILMVTextOverlayOld1_get_CurrentText(This,pVal)	\
    ( (This)->lpVtbl -> get_CurrentText(This,pVal) ) 

#define ILMVTextOverlayOld1_get_RotationCenter(This,pVal)	\
    ( (This)->lpVtbl -> get_RotationCenter(This,pVal) ) 

#define ILMVTextOverlayOld1_put_RotationCenter(This,newVal)	\
    ( (This)->lpVtbl -> put_RotationCenter(This,newVal) ) 

#define ILMVTextOverlayOld1_get_TextAlwaysVisible(This,pVal)	\
    ( (This)->lpVtbl -> get_TextAlwaysVisible(This,pVal) ) 

#define ILMVTextOverlayOld1_put_TextAlwaysVisible(This,newVal)	\
    ( (This)->lpVtbl -> put_TextAlwaysVisible(This,newVal) ) 

#define ILMVTextOverlayOld1_get_IgnoreHTMLTags(This,pVal)	\
    ( (This)->lpVtbl -> get_IgnoreHTMLTags(This,pVal) ) 

#define ILMVTextOverlayOld1_put_IgnoreHTMLTags(This,newVal)	\
    ( (This)->lpVtbl -> put_IgnoreHTMLTags(This,newVal) ) 

#define ILMVTextOverlayOld1_ResetToDefaults(This)	\
    ( (This)->lpVtbl -> ResetToDefaults(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMVTextOverlayOld1_INTERFACE_DEFINED__ */


#ifndef __ILMVTextOverlay_INTERFACE_DEFINED__
#define __ILMVTextOverlay_INTERFACE_DEFINED__

/* interface ILMVTextOverlay */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ILMVTextOverlay;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DE40-38C5-11D5-91F6-00104BDB8FF9")
    ILMVTextOverlay : public ILMVTextOverlayOld1
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CodePage( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CodePage( 
            /* [in] */ long newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMVTextOverlayVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMVTextOverlay * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMVTextOverlay * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMVTextOverlay * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMVTextOverlay * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMVTextOverlay * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMVTextOverlay * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMVTextOverlay * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsLEADInputPinConnected )( 
            ILMVTextOverlay * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsLEADOutputPinConnected )( 
            ILMVTextOverlay * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InWidth )( 
            ILMVTextOverlay * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InHeight )( 
            ILMVTextOverlay * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutWidth )( 
            ILMVTextOverlay * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutHeight )( 
            ILMVTextOverlay * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InBits )( 
            ILMVTextOverlay * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutBits )( 
            ILMVTextOverlay * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableTextOverLay )( 
            ILMVTextOverlay * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableTextOverLay )( 
            ILMVTextOverlay * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OverlayText )( 
            ILMVTextOverlay * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OverlayText )( 
            ILMVTextOverlay * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FontName )( 
            ILMVTextOverlay * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FontName )( 
            ILMVTextOverlay * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FontSize )( 
            ILMVTextOverlay * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FontSize )( 
            ILMVTextOverlay * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FontColor )( 
            ILMVTextOverlay * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FontColor )( 
            ILMVTextOverlay * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FontBKColor )( 
            ILMVTextOverlay * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FontBKColor )( 
            ILMVTextOverlay * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Bold )( 
            ILMVTextOverlay * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Bold )( 
            ILMVTextOverlay * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Italic )( 
            ILMVTextOverlay * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Italic )( 
            ILMVTextOverlay * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UnderLine )( 
            ILMVTextOverlay * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UnderLine )( 
            ILMVTextOverlay * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StrikeOut )( 
            ILMVTextOverlay * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_StrikeOut )( 
            ILMVTextOverlay * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RotationAngle )( 
            ILMVTextOverlay * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RotationAngle )( 
            ILMVTextOverlay * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableXYPosition )( 
            ILMVTextOverlay * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableXYPosition )( 
            ILMVTextOverlay * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_XPos )( 
            ILMVTextOverlay * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_XPos )( 
            ILMVTextOverlay * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_YPos )( 
            ILMVTextOverlay * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_YPos )( 
            ILMVTextOverlay * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableTextFromFile )( 
            ILMVTextOverlay * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableTextFromFile )( 
            ILMVTextOverlay * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TextFileName )( 
            ILMVTextOverlay * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TextFileName )( 
            ILMVTextOverlay * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TextAlignment )( 
            ILMVTextOverlay * This,
            /* [retval][out] */ TextAlignmentConstants *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TextAlignment )( 
            ILMVTextOverlay * This,
            /* [in] */ TextAlignmentConstants newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableOutline )( 
            ILMVTextOverlay * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableOutline )( 
            ILMVTextOverlay * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutlineWidth )( 
            ILMVTextOverlay * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OutlineWidth )( 
            ILMVTextOverlay * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutlinePenColor )( 
            ILMVTextOverlay * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OutlinePenColor )( 
            ILMVTextOverlay * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutlineBrushColor )( 
            ILMVTextOverlay * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OutlineBrushColor )( 
            ILMVTextOverlay * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PenStyle )( 
            ILMVTextOverlay * This,
            /* [retval][out] */ PenStyleConstants *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PenStyle )( 
            ILMVTextOverlay * This,
            /* [in] */ PenStyleConstants newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BrushStyle )( 
            ILMVTextOverlay * This,
            /* [retval][out] */ BrushStyleConstants *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BrushStyle )( 
            ILMVTextOverlay * This,
            /* [in] */ BrushStyleConstants newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TransparentOutline )( 
            ILMVTextOverlay * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TransparentOutline )( 
            ILMVTextOverlay * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ScrollDirection )( 
            ILMVTextOverlay * This,
            /* [retval][out] */ ScrollDirectionConstants *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ScrollDirection )( 
            ILMVTextOverlay * This,
            /* [in] */ ScrollDirectionConstants newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TextRepeating )( 
            ILMVTextOverlay * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TextRepeating )( 
            ILMVTextOverlay * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_WordWrap )( 
            ILMVTextOverlay * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_WordWrap )( 
            ILMVTextOverlay * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableOpacity )( 
            ILMVTextOverlay * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableOpacity )( 
            ILMVTextOverlay * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Opacity )( 
            ILMVTextOverlay * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Opacity )( 
            ILMVTextOverlay * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ViewBackground )( 
            ILMVTextOverlay * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ViewBackground )( 
            ILMVTextOverlay * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AvgCharWidth )( 
            ILMVTextOverlay * This,
            /* [retval][out] */ long *ppVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MaxCharWidth )( 
            ILMVTextOverlay * This,
            /* [retval][out] */ long *ppVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CharHeight )( 
            ILMVTextOverlay * This,
            /* [retval][out] */ long *ppVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ViewRectLeft )( 
            ILMVTextOverlay * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ViewRectLeft )( 
            ILMVTextOverlay * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ViewRectRight )( 
            ILMVTextOverlay * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ViewRectRight )( 
            ILMVTextOverlay * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ViewRectTop )( 
            ILMVTextOverlay * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ViewRectTop )( 
            ILMVTextOverlay * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ViewRectBottom )( 
            ILMVTextOverlay * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ViewRectBottom )( 
            ILMVTextOverlay * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AutoReposToViewRect )( 
            ILMVTextOverlay * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AutoReposToViewRect )( 
            ILMVTextOverlay * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentText )( 
            ILMVTextOverlay * This,
            /* [in] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RotationCenter )( 
            ILMVTextOverlay * This,
            /* [retval][out] */ RotationCenterConstants *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RotationCenter )( 
            ILMVTextOverlay * This,
            /* [in] */ RotationCenterConstants newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TextAlwaysVisible )( 
            ILMVTextOverlay * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TextAlwaysVisible )( 
            ILMVTextOverlay * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IgnoreHTMLTags )( 
            ILMVTextOverlay * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IgnoreHTMLTags )( 
            ILMVTextOverlay * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetToDefaults )( 
            ILMVTextOverlay * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CodePage )( 
            ILMVTextOverlay * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CodePage )( 
            ILMVTextOverlay * This,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } ILMVTextOverlayVtbl;

    interface ILMVTextOverlay
    {
        CONST_VTBL struct ILMVTextOverlayVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMVTextOverlay_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMVTextOverlay_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMVTextOverlay_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMVTextOverlay_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMVTextOverlay_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMVTextOverlay_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMVTextOverlay_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMVTextOverlay_get_IsLEADInputPinConnected(This,pVal)	\
    ( (This)->lpVtbl -> get_IsLEADInputPinConnected(This,pVal) ) 

#define ILMVTextOverlay_get_IsLEADOutputPinConnected(This,pVal)	\
    ( (This)->lpVtbl -> get_IsLEADOutputPinConnected(This,pVal) ) 

#define ILMVTextOverlay_get_InWidth(This,pVal)	\
    ( (This)->lpVtbl -> get_InWidth(This,pVal) ) 

#define ILMVTextOverlay_get_InHeight(This,pVal)	\
    ( (This)->lpVtbl -> get_InHeight(This,pVal) ) 

#define ILMVTextOverlay_get_OutWidth(This,pVal)	\
    ( (This)->lpVtbl -> get_OutWidth(This,pVal) ) 

#define ILMVTextOverlay_get_OutHeight(This,pVal)	\
    ( (This)->lpVtbl -> get_OutHeight(This,pVal) ) 

#define ILMVTextOverlay_get_InBits(This,pVal)	\
    ( (This)->lpVtbl -> get_InBits(This,pVal) ) 

#define ILMVTextOverlay_get_OutBits(This,pVal)	\
    ( (This)->lpVtbl -> get_OutBits(This,pVal) ) 

#define ILMVTextOverlay_get_EnableTextOverLay(This,pVal)	\
    ( (This)->lpVtbl -> get_EnableTextOverLay(This,pVal) ) 

#define ILMVTextOverlay_put_EnableTextOverLay(This,newVal)	\
    ( (This)->lpVtbl -> put_EnableTextOverLay(This,newVal) ) 

#define ILMVTextOverlay_get_OverlayText(This,pVal)	\
    ( (This)->lpVtbl -> get_OverlayText(This,pVal) ) 

#define ILMVTextOverlay_put_OverlayText(This,newVal)	\
    ( (This)->lpVtbl -> put_OverlayText(This,newVal) ) 

#define ILMVTextOverlay_get_FontName(This,pVal)	\
    ( (This)->lpVtbl -> get_FontName(This,pVal) ) 

#define ILMVTextOverlay_put_FontName(This,newVal)	\
    ( (This)->lpVtbl -> put_FontName(This,newVal) ) 

#define ILMVTextOverlay_get_FontSize(This,pVal)	\
    ( (This)->lpVtbl -> get_FontSize(This,pVal) ) 

#define ILMVTextOverlay_put_FontSize(This,newVal)	\
    ( (This)->lpVtbl -> put_FontSize(This,newVal) ) 

#define ILMVTextOverlay_get_FontColor(This,pVal)	\
    ( (This)->lpVtbl -> get_FontColor(This,pVal) ) 

#define ILMVTextOverlay_put_FontColor(This,newVal)	\
    ( (This)->lpVtbl -> put_FontColor(This,newVal) ) 

#define ILMVTextOverlay_get_FontBKColor(This,pVal)	\
    ( (This)->lpVtbl -> get_FontBKColor(This,pVal) ) 

#define ILMVTextOverlay_put_FontBKColor(This,newVal)	\
    ( (This)->lpVtbl -> put_FontBKColor(This,newVal) ) 

#define ILMVTextOverlay_get_Bold(This,pVal)	\
    ( (This)->lpVtbl -> get_Bold(This,pVal) ) 

#define ILMVTextOverlay_put_Bold(This,newVal)	\
    ( (This)->lpVtbl -> put_Bold(This,newVal) ) 

#define ILMVTextOverlay_get_Italic(This,pVal)	\
    ( (This)->lpVtbl -> get_Italic(This,pVal) ) 

#define ILMVTextOverlay_put_Italic(This,newVal)	\
    ( (This)->lpVtbl -> put_Italic(This,newVal) ) 

#define ILMVTextOverlay_get_UnderLine(This,pVal)	\
    ( (This)->lpVtbl -> get_UnderLine(This,pVal) ) 

#define ILMVTextOverlay_put_UnderLine(This,newVal)	\
    ( (This)->lpVtbl -> put_UnderLine(This,newVal) ) 

#define ILMVTextOverlay_get_StrikeOut(This,pVal)	\
    ( (This)->lpVtbl -> get_StrikeOut(This,pVal) ) 

#define ILMVTextOverlay_put_StrikeOut(This,newVal)	\
    ( (This)->lpVtbl -> put_StrikeOut(This,newVal) ) 

#define ILMVTextOverlay_get_RotationAngle(This,pVal)	\
    ( (This)->lpVtbl -> get_RotationAngle(This,pVal) ) 

#define ILMVTextOverlay_put_RotationAngle(This,newVal)	\
    ( (This)->lpVtbl -> put_RotationAngle(This,newVal) ) 

#define ILMVTextOverlay_get_EnableXYPosition(This,pVal)	\
    ( (This)->lpVtbl -> get_EnableXYPosition(This,pVal) ) 

#define ILMVTextOverlay_put_EnableXYPosition(This,newVal)	\
    ( (This)->lpVtbl -> put_EnableXYPosition(This,newVal) ) 

#define ILMVTextOverlay_get_XPos(This,pVal)	\
    ( (This)->lpVtbl -> get_XPos(This,pVal) ) 

#define ILMVTextOverlay_put_XPos(This,newVal)	\
    ( (This)->lpVtbl -> put_XPos(This,newVal) ) 

#define ILMVTextOverlay_get_YPos(This,pVal)	\
    ( (This)->lpVtbl -> get_YPos(This,pVal) ) 

#define ILMVTextOverlay_put_YPos(This,newVal)	\
    ( (This)->lpVtbl -> put_YPos(This,newVal) ) 

#define ILMVTextOverlay_get_EnableTextFromFile(This,pVal)	\
    ( (This)->lpVtbl -> get_EnableTextFromFile(This,pVal) ) 

#define ILMVTextOverlay_put_EnableTextFromFile(This,newVal)	\
    ( (This)->lpVtbl -> put_EnableTextFromFile(This,newVal) ) 

#define ILMVTextOverlay_get_TextFileName(This,pVal)	\
    ( (This)->lpVtbl -> get_TextFileName(This,pVal) ) 

#define ILMVTextOverlay_put_TextFileName(This,newVal)	\
    ( (This)->lpVtbl -> put_TextFileName(This,newVal) ) 

#define ILMVTextOverlay_get_TextAlignment(This,pVal)	\
    ( (This)->lpVtbl -> get_TextAlignment(This,pVal) ) 

#define ILMVTextOverlay_put_TextAlignment(This,newVal)	\
    ( (This)->lpVtbl -> put_TextAlignment(This,newVal) ) 

#define ILMVTextOverlay_get_EnableOutline(This,pVal)	\
    ( (This)->lpVtbl -> get_EnableOutline(This,pVal) ) 

#define ILMVTextOverlay_put_EnableOutline(This,newVal)	\
    ( (This)->lpVtbl -> put_EnableOutline(This,newVal) ) 

#define ILMVTextOverlay_get_OutlineWidth(This,pVal)	\
    ( (This)->lpVtbl -> get_OutlineWidth(This,pVal) ) 

#define ILMVTextOverlay_put_OutlineWidth(This,newVal)	\
    ( (This)->lpVtbl -> put_OutlineWidth(This,newVal) ) 

#define ILMVTextOverlay_get_OutlinePenColor(This,pVal)	\
    ( (This)->lpVtbl -> get_OutlinePenColor(This,pVal) ) 

#define ILMVTextOverlay_put_OutlinePenColor(This,newVal)	\
    ( (This)->lpVtbl -> put_OutlinePenColor(This,newVal) ) 

#define ILMVTextOverlay_get_OutlineBrushColor(This,pVal)	\
    ( (This)->lpVtbl -> get_OutlineBrushColor(This,pVal) ) 

#define ILMVTextOverlay_put_OutlineBrushColor(This,newVal)	\
    ( (This)->lpVtbl -> put_OutlineBrushColor(This,newVal) ) 

#define ILMVTextOverlay_get_PenStyle(This,pVal)	\
    ( (This)->lpVtbl -> get_PenStyle(This,pVal) ) 

#define ILMVTextOverlay_put_PenStyle(This,newVal)	\
    ( (This)->lpVtbl -> put_PenStyle(This,newVal) ) 

#define ILMVTextOverlay_get_BrushStyle(This,pVal)	\
    ( (This)->lpVtbl -> get_BrushStyle(This,pVal) ) 

#define ILMVTextOverlay_put_BrushStyle(This,newVal)	\
    ( (This)->lpVtbl -> put_BrushStyle(This,newVal) ) 

#define ILMVTextOverlay_get_TransparentOutline(This,pVal)	\
    ( (This)->lpVtbl -> get_TransparentOutline(This,pVal) ) 

#define ILMVTextOverlay_put_TransparentOutline(This,newVal)	\
    ( (This)->lpVtbl -> put_TransparentOutline(This,newVal) ) 

#define ILMVTextOverlay_get_ScrollDirection(This,pVal)	\
    ( (This)->lpVtbl -> get_ScrollDirection(This,pVal) ) 

#define ILMVTextOverlay_put_ScrollDirection(This,newVal)	\
    ( (This)->lpVtbl -> put_ScrollDirection(This,newVal) ) 

#define ILMVTextOverlay_get_TextRepeating(This,pVal)	\
    ( (This)->lpVtbl -> get_TextRepeating(This,pVal) ) 

#define ILMVTextOverlay_put_TextRepeating(This,newVal)	\
    ( (This)->lpVtbl -> put_TextRepeating(This,newVal) ) 

#define ILMVTextOverlay_get_WordWrap(This,pVal)	\
    ( (This)->lpVtbl -> get_WordWrap(This,pVal) ) 

#define ILMVTextOverlay_put_WordWrap(This,newVal)	\
    ( (This)->lpVtbl -> put_WordWrap(This,newVal) ) 

#define ILMVTextOverlay_get_EnableOpacity(This,pVal)	\
    ( (This)->lpVtbl -> get_EnableOpacity(This,pVal) ) 

#define ILMVTextOverlay_put_EnableOpacity(This,newVal)	\
    ( (This)->lpVtbl -> put_EnableOpacity(This,newVal) ) 

#define ILMVTextOverlay_get_Opacity(This,pVal)	\
    ( (This)->lpVtbl -> get_Opacity(This,pVal) ) 

#define ILMVTextOverlay_put_Opacity(This,newVal)	\
    ( (This)->lpVtbl -> put_Opacity(This,newVal) ) 

#define ILMVTextOverlay_get_ViewBackground(This,pVal)	\
    ( (This)->lpVtbl -> get_ViewBackground(This,pVal) ) 

#define ILMVTextOverlay_put_ViewBackground(This,newVal)	\
    ( (This)->lpVtbl -> put_ViewBackground(This,newVal) ) 

#define ILMVTextOverlay_get_AvgCharWidth(This,ppVal)	\
    ( (This)->lpVtbl -> get_AvgCharWidth(This,ppVal) ) 

#define ILMVTextOverlay_get_MaxCharWidth(This,ppVal)	\
    ( (This)->lpVtbl -> get_MaxCharWidth(This,ppVal) ) 

#define ILMVTextOverlay_get_CharHeight(This,ppVal)	\
    ( (This)->lpVtbl -> get_CharHeight(This,ppVal) ) 

#define ILMVTextOverlay_get_ViewRectLeft(This,pVal)	\
    ( (This)->lpVtbl -> get_ViewRectLeft(This,pVal) ) 

#define ILMVTextOverlay_put_ViewRectLeft(This,newVal)	\
    ( (This)->lpVtbl -> put_ViewRectLeft(This,newVal) ) 

#define ILMVTextOverlay_get_ViewRectRight(This,pVal)	\
    ( (This)->lpVtbl -> get_ViewRectRight(This,pVal) ) 

#define ILMVTextOverlay_put_ViewRectRight(This,newVal)	\
    ( (This)->lpVtbl -> put_ViewRectRight(This,newVal) ) 

#define ILMVTextOverlay_get_ViewRectTop(This,pVal)	\
    ( (This)->lpVtbl -> get_ViewRectTop(This,pVal) ) 

#define ILMVTextOverlay_put_ViewRectTop(This,newVal)	\
    ( (This)->lpVtbl -> put_ViewRectTop(This,newVal) ) 

#define ILMVTextOverlay_get_ViewRectBottom(This,pVal)	\
    ( (This)->lpVtbl -> get_ViewRectBottom(This,pVal) ) 

#define ILMVTextOverlay_put_ViewRectBottom(This,newVal)	\
    ( (This)->lpVtbl -> put_ViewRectBottom(This,newVal) ) 

#define ILMVTextOverlay_get_AutoReposToViewRect(This,pVal)	\
    ( (This)->lpVtbl -> get_AutoReposToViewRect(This,pVal) ) 

#define ILMVTextOverlay_put_AutoReposToViewRect(This,newVal)	\
    ( (This)->lpVtbl -> put_AutoReposToViewRect(This,newVal) ) 

#define ILMVTextOverlay_get_CurrentText(This,pVal)	\
    ( (This)->lpVtbl -> get_CurrentText(This,pVal) ) 

#define ILMVTextOverlay_get_RotationCenter(This,pVal)	\
    ( (This)->lpVtbl -> get_RotationCenter(This,pVal) ) 

#define ILMVTextOverlay_put_RotationCenter(This,newVal)	\
    ( (This)->lpVtbl -> put_RotationCenter(This,newVal) ) 

#define ILMVTextOverlay_get_TextAlwaysVisible(This,pVal)	\
    ( (This)->lpVtbl -> get_TextAlwaysVisible(This,pVal) ) 

#define ILMVTextOverlay_put_TextAlwaysVisible(This,newVal)	\
    ( (This)->lpVtbl -> put_TextAlwaysVisible(This,newVal) ) 

#define ILMVTextOverlay_get_IgnoreHTMLTags(This,pVal)	\
    ( (This)->lpVtbl -> get_IgnoreHTMLTags(This,pVal) ) 

#define ILMVTextOverlay_put_IgnoreHTMLTags(This,newVal)	\
    ( (This)->lpVtbl -> put_IgnoreHTMLTags(This,newVal) ) 

#define ILMVTextOverlay_ResetToDefaults(This)	\
    ( (This)->lpVtbl -> ResetToDefaults(This) ) 


#define ILMVTextOverlay_get_CodePage(This,pVal)	\
    ( (This)->lpVtbl -> get_CodePage(This,pVal) ) 

#define ILMVTextOverlay_put_CodePage(This,newVal)	\
    ( (This)->lpVtbl -> put_CodePage(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMVTextOverlay_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LMVTextOverlay;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DD9C-38C5-11D5-91F6-00104BDB8FF9")
LMVTextOverlay;
#endif
#endif /* __LMVTextOverlayLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


