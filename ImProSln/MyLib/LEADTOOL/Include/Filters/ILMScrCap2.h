

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Nov 05 12:46:55 2009
 */
/* Compiler settings for .\ILMScrCap.idl:
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


#ifndef __ILMScrCap2_h__
#define __ILMScrCap2_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILMScrCapUserCallback_FWD_DEFINED__
#define __ILMScrCapUserCallback_FWD_DEFINED__
typedef interface ILMScrCapUserCallback ILMScrCapUserCallback;
#endif 	/* __ILMScrCapUserCallback_FWD_DEFINED__ */


#ifndef __ILMScrCapUserEventsCallback_FWD_DEFINED__
#define __ILMScrCapUserEventsCallback_FWD_DEFINED__
typedef interface ILMScrCapUserEventsCallback ILMScrCapUserEventsCallback;
#endif 	/* __ILMScrCapUserEventsCallback_FWD_DEFINED__ */


#ifndef __ILMScrCap_FWD_DEFINED__
#define __ILMScrCap_FWD_DEFINED__
typedef interface ILMScrCap ILMScrCap;
#endif 	/* __ILMScrCap_FWD_DEFINED__ */


#ifndef __LMScrCap_FWD_DEFINED__
#define __LMScrCap_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMScrCap LMScrCap;
#else
typedef struct LMScrCap LMScrCap;
#endif /* __cplusplus */

#endif 	/* __LMScrCap_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LMScrCapLib_LIBRARY_DEFINED__
#define __LMScrCapLib_LIBRARY_DEFINED__

/* library LMScrCapLib */
/* [helpstring][version][uuid] */ 

#ifndef __ILMScrCap2_H__
#define __ILMScrCap2_H__
static const GUID LIBID_LMScrCapLib                 = {0xe2b7de12, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMScrCap                    = {0xe2b7de13, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMScrCapPropertyPage        = {0xe2b7de14, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMScrCapPropertyPage2       = {0xe2b7de15, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMScrCapPropertyPage3       = {0xe2b7de16, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVAboutScrCap              = {0xe2b7de17, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMScrCap                     = {0xe2b7de18, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMScrCapUserCallback         = {0xe2b7de19, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMScrCapUserEventsCallback   = {0xe2b7de1a, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
#endif 
typedef /* [v1_enum] */ 
enum PanToWindowConstants
    {	PANTO_WINDOWUNDERCURSOR	= -1,
	PANTO_ACTIVEWINDOW	= -2
    } 	PanToWindowConstants;

typedef /* [v1_enum] */ 
enum WindowSelectStatusConstants
    {	WINDOW_SELECT_STATUS_UPDATE	= 0,
	WINDOW_SELECT_STATUS_SELECTED	= 1,
	WINDOW_SELECT_STATUS_CANCELED	= 2
    } 	WindowSelectStatusConstants;

typedef /* [v1_enum] */ 
enum CaptureSourceConstants
    {	CAPTURE_FULLSCREEN	= 0,
	CAPTURE_ACTIVEWINDOW	= 1,
	CAPTURE_ACTIVECLIENT	= 2,
	CAPTURE_SELECTEDWINDOW	= 3
    } 	CaptureSourceConstants;

typedef /* [v1_enum] */ 
enum CursorIconConstants
    {	CURSOR_ARROW	= 0,
	CURSOR_IBEAM	= 1,
	CURSOR_WAIT	= 2,
	CURSOR_CROSS	= 3,
	CURSOR_UPARROW	= 4,
	CURSOR_SIZENWSE	= 5,
	CURSOR_SIZENESW	= 6,
	CURSOR_SIZEWE	= 7,
	CURSOR_SIZENS	= 8,
	CURSOR_SIZEALL	= 9,
	CURSOR_NO	= 10,
	CURSOR_APPSTARTING	= 11,
	CURSOR_HELP	= 12,
	CURSOR_ACTUAL	= 13,
	CURSOR_CUSTOM	= 14
    } 	CursorIconConstants;

typedef /* [v1_enum] */ 
enum WindowCaptureOptionConstants
    {	CAPTUREOPTION_VISIBLE_WINDOW	= 0,
	CAPTUREOPTION_ALL_WINDOW	= 1
    } 	WindowCaptureOptionConstants;

typedef /* [v1_enum] */ 
enum NotifyCallbackConstants
    {	NOTIFY_PRERUN_AREACHANGE	= 0,
	NOTIFY_CLOSE	= 0x1,
	NOTIFY_MINIMIZE	= 0x2,
	NOTIFY_AREACHANGE	= 0x4,
	NOTIFY_CAPWIDTH_EXCEEDED_LIMIT	= 0x8,
	NOTIFY_CAPHEIGHT_EXCEEDED_LIMIT	= 0x10
    } 	NotifyCallbackConstants;

typedef /* [v1_enum] */ 
enum SourceCloseConstants
    {	CLOSE_STOP_CAPTURING	= 0,
	CLOSE_CONTINUE_FROM_LAST_POS	= 1,
	CLOSE_FILL_COLOR	= 2
    } 	SourceCloseConstants;

typedef /* [v1_enum] */ 
enum SourceMinimizeConstants
    {	MINIMIZE_PAUSE_CAPTURING	= 0,
	MINIMIZE_STOP_CAPTURING	= 1,
	MINIMIZE_CONTINUE_FROM_LAST_POS	= 2,
	MINIMIZE_FILL_COLOR	= 3
    } 	SourceMinimizeConstants;

typedef /* [v1_enum] */ 
enum SourceAreaChangeConstants
    {	AREACHANGE_CAPTURE_OTHER_WINDOWS	= 0,
	AREACHANGE_FILL_UNCOVERED_AREA	= 1
    } 	SourceAreaChangeConstants;

typedef /* [v1_enum] */ 
enum EffectShapeConstants
    {	EFFECTSHAPE_NON	= 0,
	EFFECTSHAPE_RINGS	= 1,
	EFFECTSHAPE_CIRCLE	= 2,
	EFFECTSHAPE_SUN	= 3
    } 	EffectShapeConstants;

typedef /* [v1_enum] */ 
enum MouseHighlightConstants
    {	MOUSEHIGHLIGHT_NON	= 0,
	MOUSEHIGHLIGHT_SQUARE	= 1,
	MOUSEHIGHLIGHT_RECTANGLE	= 2,
	MOUSEHIGHLIGHT_ROUNDEDRECTANGLE	= 3,
	MOUSEHIGHLIGHT_CIRCLE	= 4,
	MOUSEHIGHLIGHT_ELLIPSE	= 5
    } 	MouseHighlightConstants;

typedef /* [v1_enum] */ 
enum MouseHighlightModeConstants
    {	HIGHLIGHTMODE_TRANSLUCENT	= 0,
	HIGHLIGHTMODE_OPAQUE	= 1
    } 	MouseHighlightModeConstants;

typedef /* [v1_enum] */ 
enum UserEventsNotifyConstants
    {	USEREVENT_LBUTTONDOWN	= 0x1,
	USEREVENT_LBUTTONUP	= 0x2,
	USEREVENT_RBUTTONDOWN	= 0x4,
	USEREVENT_RBUTTONUP	= 0x8,
	USEREVENT_MOUSEMOVE	= 0x10,
	USEREVENT_MOUSEWHEEL	= 0x20,
	USEREVENT_KEYDOWN	= 0x40,
	USEREVENT_KEYUP	= 0x80,
	USEREVENT_SYSKEYDOWN	= 0x100,
	USEREVENT_SYSKEYUP	= 0x200
    } 	UserEventsNotifyConstants;

typedef /* [v1_enum] */ 
enum OutlineShapeConstants
    {	OUTLINESHAPE_RECTANGLE	= 0,
	OUTLINESHAPE_CORNER	= 0x1
    } 	OutlineShapeConstants;

typedef /* [v1_enum] */ 
enum CaptureAlignmentConstants
    {	CAPALIGNMENT_LEFT	= 0x1,
	CAPALIGNMENT_TOP	= 0x2,
	CAPALIGNMENT_RIGHT	= 0x4,
	CAPALIGNMENT_BOTTOM	= 0x8,
	CAPALIGNMENT_HCENTER	= 0x10,
	CAPALIGNMENT_VCENTER	= 0x20
    } 	CaptureAlignmentConstants;


EXTERN_C const IID LIBID_LMScrCapLib;

#ifndef __ILMScrCapUserCallback_INTERFACE_DEFINED__
#define __ILMScrCapUserCallback_INTERFACE_DEFINED__

/* interface ILMScrCapUserCallback */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ILMScrCapUserCallback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DE19-38C5-11D5-91F6-00104BDB8FF9")
    ILMScrCapUserCallback : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE RegionDataProc( 
            /* [in] */ long lLeft,
            /* [in] */ long lTop,
            /* [in] */ long lRight,
            /* [in] */ long lBottom,
            /* [in] */ long pUserData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WindowDataProc( 
            /* [in] */ long lWindow,
            /* [in] */ WindowSelectStatusConstants WindowStatus,
            /* [in] */ long pUserData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE NotifyCallbackProc( 
            NotifyCallbackConstants NotifyCallback,
            long pUserData) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMScrCapUserCallbackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMScrCapUserCallback * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMScrCapUserCallback * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMScrCapUserCallback * This);
        
        HRESULT ( STDMETHODCALLTYPE *RegionDataProc )( 
            ILMScrCapUserCallback * This,
            /* [in] */ long lLeft,
            /* [in] */ long lTop,
            /* [in] */ long lRight,
            /* [in] */ long lBottom,
            /* [in] */ long pUserData);
        
        HRESULT ( STDMETHODCALLTYPE *WindowDataProc )( 
            ILMScrCapUserCallback * This,
            /* [in] */ long lWindow,
            /* [in] */ WindowSelectStatusConstants WindowStatus,
            /* [in] */ long pUserData);
        
        HRESULT ( STDMETHODCALLTYPE *NotifyCallbackProc )( 
            ILMScrCapUserCallback * This,
            NotifyCallbackConstants NotifyCallback,
            long pUserData);
        
        END_INTERFACE
    } ILMScrCapUserCallbackVtbl;

    interface ILMScrCapUserCallback
    {
        CONST_VTBL struct ILMScrCapUserCallbackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMScrCapUserCallback_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMScrCapUserCallback_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMScrCapUserCallback_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMScrCapUserCallback_RegionDataProc(This,lLeft,lTop,lRight,lBottom,pUserData)	\
    ( (This)->lpVtbl -> RegionDataProc(This,lLeft,lTop,lRight,lBottom,pUserData) ) 

#define ILMScrCapUserCallback_WindowDataProc(This,lWindow,WindowStatus,pUserData)	\
    ( (This)->lpVtbl -> WindowDataProc(This,lWindow,WindowStatus,pUserData) ) 

#define ILMScrCapUserCallback_NotifyCallbackProc(This,NotifyCallback,pUserData)	\
    ( (This)->lpVtbl -> NotifyCallbackProc(This,NotifyCallback,pUserData) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMScrCapUserCallback_INTERFACE_DEFINED__ */


#ifndef __ILMScrCapUserEventsCallback_INTERFACE_DEFINED__
#define __ILMScrCapUserEventsCallback_INTERFACE_DEFINED__

/* interface ILMScrCapUserEventsCallback */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ILMScrCapUserEventsCallback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DE1A-38C5-11D5-91F6-00104BDB8FF9")
    ILMScrCapUserEventsCallback : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE MouseEventsProc( 
            /* [in] */ long lMsg,
            /* [in] */ long lXPos,
            /* [in] */ long lYPos,
            /* [in] */ long lWheelDelta,
            /* [in] */ long pUserData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE KeyboardEventsProc( 
            /* [in] */ long lMsg,
            /* [in] */ long lvKey,
            /* [in] */ VARIANT_BOOL bAltPressed,
            /* [in] */ long pUserData) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMScrCapUserEventsCallbackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMScrCapUserEventsCallback * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMScrCapUserEventsCallback * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMScrCapUserEventsCallback * This);
        
        HRESULT ( STDMETHODCALLTYPE *MouseEventsProc )( 
            ILMScrCapUserEventsCallback * This,
            /* [in] */ long lMsg,
            /* [in] */ long lXPos,
            /* [in] */ long lYPos,
            /* [in] */ long lWheelDelta,
            /* [in] */ long pUserData);
        
        HRESULT ( STDMETHODCALLTYPE *KeyboardEventsProc )( 
            ILMScrCapUserEventsCallback * This,
            /* [in] */ long lMsg,
            /* [in] */ long lvKey,
            /* [in] */ VARIANT_BOOL bAltPressed,
            /* [in] */ long pUserData);
        
        END_INTERFACE
    } ILMScrCapUserEventsCallbackVtbl;

    interface ILMScrCapUserEventsCallback
    {
        CONST_VTBL struct ILMScrCapUserEventsCallbackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMScrCapUserEventsCallback_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMScrCapUserEventsCallback_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMScrCapUserEventsCallback_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMScrCapUserEventsCallback_MouseEventsProc(This,lMsg,lXPos,lYPos,lWheelDelta,pUserData)	\
    ( (This)->lpVtbl -> MouseEventsProc(This,lMsg,lXPos,lYPos,lWheelDelta,pUserData) ) 

#define ILMScrCapUserEventsCallback_KeyboardEventsProc(This,lMsg,lvKey,bAltPressed,pUserData)	\
    ( (This)->lpVtbl -> KeyboardEventsProc(This,lMsg,lvKey,bAltPressed,pUserData) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMScrCapUserEventsCallback_INTERFACE_DEFINED__ */


#ifndef __ILMScrCap_INTERFACE_DEFINED__
#define __ILMScrCap_INTERFACE_DEFINED__

/* interface ILMScrCap */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILMScrCap;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DE18-38C5-11D5-91F6-00104BDB8FF9")
    ILMScrCap : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CaptureSource( 
            /* [retval][out] */ CaptureSourceConstants *pCapSrc) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CaptureSource( 
            /* [in] */ CaptureSourceConstants newCapSrc) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SourceWindowHandle( 
            /* [retval][out] */ long *pWndHandle) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SourceWindowHandle( 
            /* [in] */ long WndHandle) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CaptureFrameRate( 
            /* [retval][out] */ float *pFrameRate) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CaptureFrameRate( 
            /* [in] */ float newFrameRate) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ShowCursor( 
            /* [retval][out] */ VARIANT_BOOL *pShowCursor) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ShowCursor( 
            /* [in] */ VARIANT_BOOL newShowCursor) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CursorIcon( 
            /* [retval][out] */ CursorIconConstants *pCurIcon) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CursorIcon( 
            /* [in] */ CursorIconConstants newCurIcon) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SourceWidth( 
            /* [retval][out] */ long *pWidth) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SourceHeight( 
            /* [retval][out] */ long *pHeight) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EnableRegion( 
            /* [retval][out] */ VARIANT_BOOL *pEnableRgn) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_EnableRegion( 
            /* [in] */ VARIANT_BOOL newEnableRgn) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RegionLeft( 
            /* [retval][out] */ long *pLeft) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RegionLeft( 
            /* [in] */ long newLeft) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RegionTop( 
            /* [retval][out] */ long *pTop) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RegionTop( 
            /* [in] */ long newTop) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RegionRight( 
            /* [retval][out] */ long *pRight) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RegionRight( 
            /* [in] */ long newRight) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RegionBottom( 
            /* [retval][out] */ long *pBottom) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RegionBottom( 
            /* [in] */ long newBottom) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ConnectionStatus( 
            /* [retval][out] */ VARIANT_BOOL *pbConnected) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SelectRegionTool( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ShowPanWindow( 
            /* [retval][out] */ VARIANT_BOOL *pShowPanWindow) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ShowPanWindow( 
            /* [in] */ VARIANT_BOOL newShowPanWindow) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SelectWindowTool( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetCallbackObject( 
            /* [in] */ ILMScrCapUserCallback *pCallbackObject,
            /* [in] */ long pUserData) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ShowCrossLines( 
            /* [retval][out] */ VARIANT_BOOL *pShowCrossLines) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ShowCrossLines( 
            /* [in] */ VARIANT_BOOL newShowCrossLines) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ShowXYPosInfo( 
            /* [retval][out] */ VARIANT_BOOL *pShowXYPosInfo) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ShowXYPosInfo( 
            /* [in] */ VARIANT_BOOL newShowXYPosInfo) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ShowWHInfo( 
            /* [retval][out] */ VARIANT_BOOL *pShowWHInfo) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ShowWHInfo( 
            /* [in] */ VARIANT_BOOL newShowWHInfo) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_WindowCaptureOption( 
            /* [retval][out] */ WindowCaptureOptionConstants *pWindowCaptureOption) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_WindowCaptureOption( 
            /* [in] */ WindowCaptureOptionConstants newWindowCaptureOption) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TrackWindow( 
            /* [retval][out] */ VARIANT_BOOL *pTrackWindow) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_TrackWindow( 
            /* [in] */ VARIANT_BOOL newTrackWindow) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FillColor( 
            /* [retval][out] */ long *pFillColor) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FillColor( 
            /* [in] */ long newFillColor) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_NotifyCallback( 
            /* [retval][out] */ long *pNotifyCallback) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_NotifyCallback( 
            /* [in] */ long newNotifyCallback) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OnSourceClose( 
            /* [retval][out] */ SourceCloseConstants *pOnSourceClose) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OnSourceClose( 
            /* [in] */ SourceCloseConstants newOnSourceClose) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OnSourceMinimize( 
            /* [retval][out] */ SourceMinimizeConstants *pOnSourceMinimize) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OnSourceMinimize( 
            /* [in] */ SourceMinimizeConstants newSourceMinimize) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OnSourceAreaChange( 
            /* [retval][out] */ SourceAreaChangeConstants *pOnSourceAreaChange) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OnSourceAreaChange( 
            /* [in] */ SourceAreaChangeConstants newOnSourceAreaChange) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CustomCursor( 
            /* [retval][out] */ long *pCustomCursor) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CustomCursor( 
            /* [in] */ long newCustomCursor) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ChangeSettings( 
            /* [in] */ VARIANT_BOOL bBegin) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CancelSourceSelection( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RefreshSource( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OnLeftBtnClkEffectShape( 
            /* [retval][out] */ EffectShapeConstants *pShape) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OnLeftBtnClkEffectShape( 
            /* [in] */ EffectShapeConstants newShape) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OnRightBtnClkEffectShape( 
            /* [retval][out] */ EffectShapeConstants *pShape) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OnRightBtnClkEffectShape( 
            /* [in] */ EffectShapeConstants newShape) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OnLeftBtnClkEffectColor( 
            /* [retval][out] */ long *pColor) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OnLeftBtnClkEffectColor( 
            /* [in] */ long newColor) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OnRightBtnClkEffectColor( 
            /* [retval][out] */ long *pColor) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OnRightBtnClkEffectColor( 
            /* [in] */ long newColor) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OnLeftBtnClkEffectSize( 
            /* [retval][out] */ long *pSize) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OnLeftBtnClkEffectSize( 
            /* [in] */ long newSize) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OnRightBtnClkEffectSize( 
            /* [retval][out] */ long *pSize) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OnRightBtnClkEffectSize( 
            /* [in] */ long newSize) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EnablePanning( 
            /* [retval][out] */ VARIANT_BOOL *pEnable) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_EnablePanning( 
            /* [in] */ VARIANT_BOOL newEnable) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ZoomFactor( 
            /* [retval][out] */ long *pZoom) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ZoomFactor( 
            /* [in] */ long newZoom) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EnableOutline( 
            /* [retval][out] */ VARIANT_BOOL *pEnable) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_EnableOutline( 
            /* [in] */ VARIANT_BOOL newEnable) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ManualMode( 
            /* [retval][out] */ VARIANT_BOOL *pMode) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ManualMode( 
            /* [in] */ VARIANT_BOOL newMode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CaptureFrames( 
            /* [in] */ long lFramesNumber) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MouseHighlight( 
            /* [retval][out] */ MouseHighlightConstants *pEffect) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MouseHighlight( 
            /* [in] */ MouseHighlightConstants newEffect) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MouseHighlightSize( 
            /* [retval][out] */ long *pSize) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MouseHighlightSize( 
            /* [in] */ long newSize) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MouseHighlightColor( 
            /* [retval][out] */ long *pColor) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MouseHighlightColor( 
            /* [in] */ long newColor) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MouseHighlightMode( 
            /* [retval][out] */ MouseHighlightModeConstants *pMode) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MouseHighlightMode( 
            /* [in] */ MouseHighlightModeConstants newMode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetUserEventsCallbackObject( 
            /* [in] */ ILMScrCapUserEventsCallback *pCallbackObject,
            /* [in] */ long pUserData) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UserEventsNotifyCallback( 
            /* [retval][out] */ long *pNotifyCallback) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_UserEventsNotifyCallback( 
            /* [in] */ long newNotifyCallback) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OutlineShape( 
            /* [retval][out] */ OutlineShapeConstants *pOutlineShape) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OutlineShape( 
            /* [in] */ OutlineShapeConstants newOutlineShape) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetZoomStepsInfo( 
            /* [in] */ long lSteps,
            /* [in] */ long lMinStepSize) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetPanStepsInfo( 
            /* [in] */ long lSteps,
            /* [in] */ long lMinStepSteps) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetZoomStepsInfo( 
            /* [out] */ long *plSteps,
            /* [out] */ long *plMinStepSize) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPanStepsInfo( 
            /* [out] */ long *plSteps,
            /* [out] */ long *plMinStepSize) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CaptureAlignment( 
            /* [retval][out] */ long *pCaptureAlignment) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CaptureAlignment( 
            /* [in] */ long newCaptureAlignment) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PanToXY( 
            /* [in] */ long lXPos,
            /* [in] */ long lYPos) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PanToWindow( 
            /* [in] */ long lHwnd,
            /* [in] */ VARIANT_BOOL vbFollow,
            /* [in] */ VARIANT_BOOL vbFit) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PanToCursor( 
            /* [in] */ VARIANT_BOOL vbFollow) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OutlineColor( 
            /* [retval][out] */ long *pColor) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OutlineColor( 
            /* [in] */ long newColor) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LowerWidthLimit( 
            /* [retval][out] */ long *pLowerWidthLimit) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_LowerWidthLimit( 
            /* [in] */ long newLowerWidthLimit) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UpperWidthLimit( 
            /* [retval][out] */ long *pUpperWidthLimit) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_UpperWidthLimit( 
            /* [in] */ long newUpperWidthLimit) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LowerHeightLimit( 
            /* [retval][out] */ long *pLowerHeightLimit) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_LowerHeightLimit( 
            /* [in] */ long newLowerHeightLimit) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UpperHeightLimit( 
            /* [retval][out] */ long *pUpperHeightLimit) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_UpperHeightLimit( 
            /* [in] */ long newUpperHeightLimit) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RgnSelToolStepSizeX( 
            /* [retval][out] */ long *pRgnSelToolStepSizeX) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RgnSelToolStepSizeX( 
            /* [in] */ long newRgnSelToolStepSizeX) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RgnSelToolStepSizeY( 
            /* [retval][out] */ long *pRgnSelToolStepSizeY) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RgnSelToolStepSizeY( 
            /* [in] */ long newRgnSelToolStepSizeY) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RgnSelToolWarningColor( 
            /* [retval][out] */ long *pRgnSelToolWarningColor) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RgnSelToolWarningColor( 
            /* [in] */ long newRgnSelToolWarningColor) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RgnSelToolLockSelOnLimit( 
            /* [retval][out] */ VARIANT_BOOL *pRgnSelToolLockSelOnLimit) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RgnSelToolLockSelOnLimit( 
            /* [in] */ VARIANT_BOOL newRgnSelToolLockSelOnLimit) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ResetToDefaults( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMScrCapVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMScrCap * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMScrCap * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMScrCap * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMScrCap * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMScrCap * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMScrCap * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMScrCap * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CaptureSource )( 
            ILMScrCap * This,
            /* [retval][out] */ CaptureSourceConstants *pCapSrc);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CaptureSource )( 
            ILMScrCap * This,
            /* [in] */ CaptureSourceConstants newCapSrc);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SourceWindowHandle )( 
            ILMScrCap * This,
            /* [retval][out] */ long *pWndHandle);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SourceWindowHandle )( 
            ILMScrCap * This,
            /* [in] */ long WndHandle);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CaptureFrameRate )( 
            ILMScrCap * This,
            /* [retval][out] */ float *pFrameRate);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CaptureFrameRate )( 
            ILMScrCap * This,
            /* [in] */ float newFrameRate);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ShowCursor )( 
            ILMScrCap * This,
            /* [retval][out] */ VARIANT_BOOL *pShowCursor);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ShowCursor )( 
            ILMScrCap * This,
            /* [in] */ VARIANT_BOOL newShowCursor);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CursorIcon )( 
            ILMScrCap * This,
            /* [retval][out] */ CursorIconConstants *pCurIcon);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CursorIcon )( 
            ILMScrCap * This,
            /* [in] */ CursorIconConstants newCurIcon);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SourceWidth )( 
            ILMScrCap * This,
            /* [retval][out] */ long *pWidth);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SourceHeight )( 
            ILMScrCap * This,
            /* [retval][out] */ long *pHeight);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableRegion )( 
            ILMScrCap * This,
            /* [retval][out] */ VARIANT_BOOL *pEnableRgn);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableRegion )( 
            ILMScrCap * This,
            /* [in] */ VARIANT_BOOL newEnableRgn);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RegionLeft )( 
            ILMScrCap * This,
            /* [retval][out] */ long *pLeft);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RegionLeft )( 
            ILMScrCap * This,
            /* [in] */ long newLeft);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RegionTop )( 
            ILMScrCap * This,
            /* [retval][out] */ long *pTop);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RegionTop )( 
            ILMScrCap * This,
            /* [in] */ long newTop);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RegionRight )( 
            ILMScrCap * This,
            /* [retval][out] */ long *pRight);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RegionRight )( 
            ILMScrCap * This,
            /* [in] */ long newRight);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RegionBottom )( 
            ILMScrCap * This,
            /* [retval][out] */ long *pBottom);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RegionBottom )( 
            ILMScrCap * This,
            /* [in] */ long newBottom);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ConnectionStatus )( 
            ILMScrCap * This,
            /* [retval][out] */ VARIANT_BOOL *pbConnected);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SelectRegionTool )( 
            ILMScrCap * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ShowPanWindow )( 
            ILMScrCap * This,
            /* [retval][out] */ VARIANT_BOOL *pShowPanWindow);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ShowPanWindow )( 
            ILMScrCap * This,
            /* [in] */ VARIANT_BOOL newShowPanWindow);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SelectWindowTool )( 
            ILMScrCap * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetCallbackObject )( 
            ILMScrCap * This,
            /* [in] */ ILMScrCapUserCallback *pCallbackObject,
            /* [in] */ long pUserData);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ShowCrossLines )( 
            ILMScrCap * This,
            /* [retval][out] */ VARIANT_BOOL *pShowCrossLines);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ShowCrossLines )( 
            ILMScrCap * This,
            /* [in] */ VARIANT_BOOL newShowCrossLines);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ShowXYPosInfo )( 
            ILMScrCap * This,
            /* [retval][out] */ VARIANT_BOOL *pShowXYPosInfo);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ShowXYPosInfo )( 
            ILMScrCap * This,
            /* [in] */ VARIANT_BOOL newShowXYPosInfo);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ShowWHInfo )( 
            ILMScrCap * This,
            /* [retval][out] */ VARIANT_BOOL *pShowWHInfo);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ShowWHInfo )( 
            ILMScrCap * This,
            /* [in] */ VARIANT_BOOL newShowWHInfo);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_WindowCaptureOption )( 
            ILMScrCap * This,
            /* [retval][out] */ WindowCaptureOptionConstants *pWindowCaptureOption);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_WindowCaptureOption )( 
            ILMScrCap * This,
            /* [in] */ WindowCaptureOptionConstants newWindowCaptureOption);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TrackWindow )( 
            ILMScrCap * This,
            /* [retval][out] */ VARIANT_BOOL *pTrackWindow);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TrackWindow )( 
            ILMScrCap * This,
            /* [in] */ VARIANT_BOOL newTrackWindow);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FillColor )( 
            ILMScrCap * This,
            /* [retval][out] */ long *pFillColor);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FillColor )( 
            ILMScrCap * This,
            /* [in] */ long newFillColor);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NotifyCallback )( 
            ILMScrCap * This,
            /* [retval][out] */ long *pNotifyCallback);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_NotifyCallback )( 
            ILMScrCap * This,
            /* [in] */ long newNotifyCallback);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OnSourceClose )( 
            ILMScrCap * This,
            /* [retval][out] */ SourceCloseConstants *pOnSourceClose);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OnSourceClose )( 
            ILMScrCap * This,
            /* [in] */ SourceCloseConstants newOnSourceClose);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OnSourceMinimize )( 
            ILMScrCap * This,
            /* [retval][out] */ SourceMinimizeConstants *pOnSourceMinimize);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OnSourceMinimize )( 
            ILMScrCap * This,
            /* [in] */ SourceMinimizeConstants newSourceMinimize);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OnSourceAreaChange )( 
            ILMScrCap * This,
            /* [retval][out] */ SourceAreaChangeConstants *pOnSourceAreaChange);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OnSourceAreaChange )( 
            ILMScrCap * This,
            /* [in] */ SourceAreaChangeConstants newOnSourceAreaChange);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CustomCursor )( 
            ILMScrCap * This,
            /* [retval][out] */ long *pCustomCursor);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CustomCursor )( 
            ILMScrCap * This,
            /* [in] */ long newCustomCursor);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ChangeSettings )( 
            ILMScrCap * This,
            /* [in] */ VARIANT_BOOL bBegin);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CancelSourceSelection )( 
            ILMScrCap * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RefreshSource )( 
            ILMScrCap * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OnLeftBtnClkEffectShape )( 
            ILMScrCap * This,
            /* [retval][out] */ EffectShapeConstants *pShape);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OnLeftBtnClkEffectShape )( 
            ILMScrCap * This,
            /* [in] */ EffectShapeConstants newShape);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OnRightBtnClkEffectShape )( 
            ILMScrCap * This,
            /* [retval][out] */ EffectShapeConstants *pShape);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OnRightBtnClkEffectShape )( 
            ILMScrCap * This,
            /* [in] */ EffectShapeConstants newShape);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OnLeftBtnClkEffectColor )( 
            ILMScrCap * This,
            /* [retval][out] */ long *pColor);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OnLeftBtnClkEffectColor )( 
            ILMScrCap * This,
            /* [in] */ long newColor);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OnRightBtnClkEffectColor )( 
            ILMScrCap * This,
            /* [retval][out] */ long *pColor);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OnRightBtnClkEffectColor )( 
            ILMScrCap * This,
            /* [in] */ long newColor);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OnLeftBtnClkEffectSize )( 
            ILMScrCap * This,
            /* [retval][out] */ long *pSize);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OnLeftBtnClkEffectSize )( 
            ILMScrCap * This,
            /* [in] */ long newSize);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OnRightBtnClkEffectSize )( 
            ILMScrCap * This,
            /* [retval][out] */ long *pSize);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OnRightBtnClkEffectSize )( 
            ILMScrCap * This,
            /* [in] */ long newSize);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnablePanning )( 
            ILMScrCap * This,
            /* [retval][out] */ VARIANT_BOOL *pEnable);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnablePanning )( 
            ILMScrCap * This,
            /* [in] */ VARIANT_BOOL newEnable);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ZoomFactor )( 
            ILMScrCap * This,
            /* [retval][out] */ long *pZoom);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ZoomFactor )( 
            ILMScrCap * This,
            /* [in] */ long newZoom);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableOutline )( 
            ILMScrCap * This,
            /* [retval][out] */ VARIANT_BOOL *pEnable);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableOutline )( 
            ILMScrCap * This,
            /* [in] */ VARIANT_BOOL newEnable);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ManualMode )( 
            ILMScrCap * This,
            /* [retval][out] */ VARIANT_BOOL *pMode);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ManualMode )( 
            ILMScrCap * This,
            /* [in] */ VARIANT_BOOL newMode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CaptureFrames )( 
            ILMScrCap * This,
            /* [in] */ long lFramesNumber);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MouseHighlight )( 
            ILMScrCap * This,
            /* [retval][out] */ MouseHighlightConstants *pEffect);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MouseHighlight )( 
            ILMScrCap * This,
            /* [in] */ MouseHighlightConstants newEffect);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MouseHighlightSize )( 
            ILMScrCap * This,
            /* [retval][out] */ long *pSize);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MouseHighlightSize )( 
            ILMScrCap * This,
            /* [in] */ long newSize);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MouseHighlightColor )( 
            ILMScrCap * This,
            /* [retval][out] */ long *pColor);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MouseHighlightColor )( 
            ILMScrCap * This,
            /* [in] */ long newColor);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MouseHighlightMode )( 
            ILMScrCap * This,
            /* [retval][out] */ MouseHighlightModeConstants *pMode);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MouseHighlightMode )( 
            ILMScrCap * This,
            /* [in] */ MouseHighlightModeConstants newMode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetUserEventsCallbackObject )( 
            ILMScrCap * This,
            /* [in] */ ILMScrCapUserEventsCallback *pCallbackObject,
            /* [in] */ long pUserData);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UserEventsNotifyCallback )( 
            ILMScrCap * This,
            /* [retval][out] */ long *pNotifyCallback);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UserEventsNotifyCallback )( 
            ILMScrCap * This,
            /* [in] */ long newNotifyCallback);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutlineShape )( 
            ILMScrCap * This,
            /* [retval][out] */ OutlineShapeConstants *pOutlineShape);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OutlineShape )( 
            ILMScrCap * This,
            /* [in] */ OutlineShapeConstants newOutlineShape);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetZoomStepsInfo )( 
            ILMScrCap * This,
            /* [in] */ long lSteps,
            /* [in] */ long lMinStepSize);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetPanStepsInfo )( 
            ILMScrCap * This,
            /* [in] */ long lSteps,
            /* [in] */ long lMinStepSteps);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetZoomStepsInfo )( 
            ILMScrCap * This,
            /* [out] */ long *plSteps,
            /* [out] */ long *plMinStepSize);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPanStepsInfo )( 
            ILMScrCap * This,
            /* [out] */ long *plSteps,
            /* [out] */ long *plMinStepSize);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CaptureAlignment )( 
            ILMScrCap * This,
            /* [retval][out] */ long *pCaptureAlignment);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CaptureAlignment )( 
            ILMScrCap * This,
            /* [in] */ long newCaptureAlignment);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PanToXY )( 
            ILMScrCap * This,
            /* [in] */ long lXPos,
            /* [in] */ long lYPos);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PanToWindow )( 
            ILMScrCap * This,
            /* [in] */ long lHwnd,
            /* [in] */ VARIANT_BOOL vbFollow,
            /* [in] */ VARIANT_BOOL vbFit);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PanToCursor )( 
            ILMScrCap * This,
            /* [in] */ VARIANT_BOOL vbFollow);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutlineColor )( 
            ILMScrCap * This,
            /* [retval][out] */ long *pColor);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OutlineColor )( 
            ILMScrCap * This,
            /* [in] */ long newColor);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LowerWidthLimit )( 
            ILMScrCap * This,
            /* [retval][out] */ long *pLowerWidthLimit);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LowerWidthLimit )( 
            ILMScrCap * This,
            /* [in] */ long newLowerWidthLimit);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UpperWidthLimit )( 
            ILMScrCap * This,
            /* [retval][out] */ long *pUpperWidthLimit);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UpperWidthLimit )( 
            ILMScrCap * This,
            /* [in] */ long newUpperWidthLimit);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LowerHeightLimit )( 
            ILMScrCap * This,
            /* [retval][out] */ long *pLowerHeightLimit);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LowerHeightLimit )( 
            ILMScrCap * This,
            /* [in] */ long newLowerHeightLimit);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UpperHeightLimit )( 
            ILMScrCap * This,
            /* [retval][out] */ long *pUpperHeightLimit);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UpperHeightLimit )( 
            ILMScrCap * This,
            /* [in] */ long newUpperHeightLimit);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RgnSelToolStepSizeX )( 
            ILMScrCap * This,
            /* [retval][out] */ long *pRgnSelToolStepSizeX);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RgnSelToolStepSizeX )( 
            ILMScrCap * This,
            /* [in] */ long newRgnSelToolStepSizeX);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RgnSelToolStepSizeY )( 
            ILMScrCap * This,
            /* [retval][out] */ long *pRgnSelToolStepSizeY);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RgnSelToolStepSizeY )( 
            ILMScrCap * This,
            /* [in] */ long newRgnSelToolStepSizeY);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RgnSelToolWarningColor )( 
            ILMScrCap * This,
            /* [retval][out] */ long *pRgnSelToolWarningColor);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RgnSelToolWarningColor )( 
            ILMScrCap * This,
            /* [in] */ long newRgnSelToolWarningColor);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RgnSelToolLockSelOnLimit )( 
            ILMScrCap * This,
            /* [retval][out] */ VARIANT_BOOL *pRgnSelToolLockSelOnLimit);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RgnSelToolLockSelOnLimit )( 
            ILMScrCap * This,
            /* [in] */ VARIANT_BOOL newRgnSelToolLockSelOnLimit);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetToDefaults )( 
            ILMScrCap * This);
        
        END_INTERFACE
    } ILMScrCapVtbl;

    interface ILMScrCap
    {
        CONST_VTBL struct ILMScrCapVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMScrCap_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMScrCap_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMScrCap_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMScrCap_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMScrCap_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMScrCap_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMScrCap_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMScrCap_get_CaptureSource(This,pCapSrc)	\
    ( (This)->lpVtbl -> get_CaptureSource(This,pCapSrc) ) 

#define ILMScrCap_put_CaptureSource(This,newCapSrc)	\
    ( (This)->lpVtbl -> put_CaptureSource(This,newCapSrc) ) 

#define ILMScrCap_get_SourceWindowHandle(This,pWndHandle)	\
    ( (This)->lpVtbl -> get_SourceWindowHandle(This,pWndHandle) ) 

#define ILMScrCap_put_SourceWindowHandle(This,WndHandle)	\
    ( (This)->lpVtbl -> put_SourceWindowHandle(This,WndHandle) ) 

#define ILMScrCap_get_CaptureFrameRate(This,pFrameRate)	\
    ( (This)->lpVtbl -> get_CaptureFrameRate(This,pFrameRate) ) 

#define ILMScrCap_put_CaptureFrameRate(This,newFrameRate)	\
    ( (This)->lpVtbl -> put_CaptureFrameRate(This,newFrameRate) ) 

#define ILMScrCap_get_ShowCursor(This,pShowCursor)	\
    ( (This)->lpVtbl -> get_ShowCursor(This,pShowCursor) ) 

#define ILMScrCap_put_ShowCursor(This,newShowCursor)	\
    ( (This)->lpVtbl -> put_ShowCursor(This,newShowCursor) ) 

#define ILMScrCap_get_CursorIcon(This,pCurIcon)	\
    ( (This)->lpVtbl -> get_CursorIcon(This,pCurIcon) ) 

#define ILMScrCap_put_CursorIcon(This,newCurIcon)	\
    ( (This)->lpVtbl -> put_CursorIcon(This,newCurIcon) ) 

#define ILMScrCap_get_SourceWidth(This,pWidth)	\
    ( (This)->lpVtbl -> get_SourceWidth(This,pWidth) ) 

#define ILMScrCap_get_SourceHeight(This,pHeight)	\
    ( (This)->lpVtbl -> get_SourceHeight(This,pHeight) ) 

#define ILMScrCap_get_EnableRegion(This,pEnableRgn)	\
    ( (This)->lpVtbl -> get_EnableRegion(This,pEnableRgn) ) 

#define ILMScrCap_put_EnableRegion(This,newEnableRgn)	\
    ( (This)->lpVtbl -> put_EnableRegion(This,newEnableRgn) ) 

#define ILMScrCap_get_RegionLeft(This,pLeft)	\
    ( (This)->lpVtbl -> get_RegionLeft(This,pLeft) ) 

#define ILMScrCap_put_RegionLeft(This,newLeft)	\
    ( (This)->lpVtbl -> put_RegionLeft(This,newLeft) ) 

#define ILMScrCap_get_RegionTop(This,pTop)	\
    ( (This)->lpVtbl -> get_RegionTop(This,pTop) ) 

#define ILMScrCap_put_RegionTop(This,newTop)	\
    ( (This)->lpVtbl -> put_RegionTop(This,newTop) ) 

#define ILMScrCap_get_RegionRight(This,pRight)	\
    ( (This)->lpVtbl -> get_RegionRight(This,pRight) ) 

#define ILMScrCap_put_RegionRight(This,newRight)	\
    ( (This)->lpVtbl -> put_RegionRight(This,newRight) ) 

#define ILMScrCap_get_RegionBottom(This,pBottom)	\
    ( (This)->lpVtbl -> get_RegionBottom(This,pBottom) ) 

#define ILMScrCap_put_RegionBottom(This,newBottom)	\
    ( (This)->lpVtbl -> put_RegionBottom(This,newBottom) ) 

#define ILMScrCap_get_ConnectionStatus(This,pbConnected)	\
    ( (This)->lpVtbl -> get_ConnectionStatus(This,pbConnected) ) 

#define ILMScrCap_SelectRegionTool(This)	\
    ( (This)->lpVtbl -> SelectRegionTool(This) ) 

#define ILMScrCap_get_ShowPanWindow(This,pShowPanWindow)	\
    ( (This)->lpVtbl -> get_ShowPanWindow(This,pShowPanWindow) ) 

#define ILMScrCap_put_ShowPanWindow(This,newShowPanWindow)	\
    ( (This)->lpVtbl -> put_ShowPanWindow(This,newShowPanWindow) ) 

#define ILMScrCap_SelectWindowTool(This)	\
    ( (This)->lpVtbl -> SelectWindowTool(This) ) 

#define ILMScrCap_SetCallbackObject(This,pCallbackObject,pUserData)	\
    ( (This)->lpVtbl -> SetCallbackObject(This,pCallbackObject,pUserData) ) 

#define ILMScrCap_get_ShowCrossLines(This,pShowCrossLines)	\
    ( (This)->lpVtbl -> get_ShowCrossLines(This,pShowCrossLines) ) 

#define ILMScrCap_put_ShowCrossLines(This,newShowCrossLines)	\
    ( (This)->lpVtbl -> put_ShowCrossLines(This,newShowCrossLines) ) 

#define ILMScrCap_get_ShowXYPosInfo(This,pShowXYPosInfo)	\
    ( (This)->lpVtbl -> get_ShowXYPosInfo(This,pShowXYPosInfo) ) 

#define ILMScrCap_put_ShowXYPosInfo(This,newShowXYPosInfo)	\
    ( (This)->lpVtbl -> put_ShowXYPosInfo(This,newShowXYPosInfo) ) 

#define ILMScrCap_get_ShowWHInfo(This,pShowWHInfo)	\
    ( (This)->lpVtbl -> get_ShowWHInfo(This,pShowWHInfo) ) 

#define ILMScrCap_put_ShowWHInfo(This,newShowWHInfo)	\
    ( (This)->lpVtbl -> put_ShowWHInfo(This,newShowWHInfo) ) 

#define ILMScrCap_get_WindowCaptureOption(This,pWindowCaptureOption)	\
    ( (This)->lpVtbl -> get_WindowCaptureOption(This,pWindowCaptureOption) ) 

#define ILMScrCap_put_WindowCaptureOption(This,newWindowCaptureOption)	\
    ( (This)->lpVtbl -> put_WindowCaptureOption(This,newWindowCaptureOption) ) 

#define ILMScrCap_get_TrackWindow(This,pTrackWindow)	\
    ( (This)->lpVtbl -> get_TrackWindow(This,pTrackWindow) ) 

#define ILMScrCap_put_TrackWindow(This,newTrackWindow)	\
    ( (This)->lpVtbl -> put_TrackWindow(This,newTrackWindow) ) 

#define ILMScrCap_get_FillColor(This,pFillColor)	\
    ( (This)->lpVtbl -> get_FillColor(This,pFillColor) ) 

#define ILMScrCap_put_FillColor(This,newFillColor)	\
    ( (This)->lpVtbl -> put_FillColor(This,newFillColor) ) 

#define ILMScrCap_get_NotifyCallback(This,pNotifyCallback)	\
    ( (This)->lpVtbl -> get_NotifyCallback(This,pNotifyCallback) ) 

#define ILMScrCap_put_NotifyCallback(This,newNotifyCallback)	\
    ( (This)->lpVtbl -> put_NotifyCallback(This,newNotifyCallback) ) 

#define ILMScrCap_get_OnSourceClose(This,pOnSourceClose)	\
    ( (This)->lpVtbl -> get_OnSourceClose(This,pOnSourceClose) ) 

#define ILMScrCap_put_OnSourceClose(This,newOnSourceClose)	\
    ( (This)->lpVtbl -> put_OnSourceClose(This,newOnSourceClose) ) 

#define ILMScrCap_get_OnSourceMinimize(This,pOnSourceMinimize)	\
    ( (This)->lpVtbl -> get_OnSourceMinimize(This,pOnSourceMinimize) ) 

#define ILMScrCap_put_OnSourceMinimize(This,newSourceMinimize)	\
    ( (This)->lpVtbl -> put_OnSourceMinimize(This,newSourceMinimize) ) 

#define ILMScrCap_get_OnSourceAreaChange(This,pOnSourceAreaChange)	\
    ( (This)->lpVtbl -> get_OnSourceAreaChange(This,pOnSourceAreaChange) ) 

#define ILMScrCap_put_OnSourceAreaChange(This,newOnSourceAreaChange)	\
    ( (This)->lpVtbl -> put_OnSourceAreaChange(This,newOnSourceAreaChange) ) 

#define ILMScrCap_get_CustomCursor(This,pCustomCursor)	\
    ( (This)->lpVtbl -> get_CustomCursor(This,pCustomCursor) ) 

#define ILMScrCap_put_CustomCursor(This,newCustomCursor)	\
    ( (This)->lpVtbl -> put_CustomCursor(This,newCustomCursor) ) 

#define ILMScrCap_ChangeSettings(This,bBegin)	\
    ( (This)->lpVtbl -> ChangeSettings(This,bBegin) ) 

#define ILMScrCap_CancelSourceSelection(This)	\
    ( (This)->lpVtbl -> CancelSourceSelection(This) ) 

#define ILMScrCap_RefreshSource(This)	\
    ( (This)->lpVtbl -> RefreshSource(This) ) 

#define ILMScrCap_get_OnLeftBtnClkEffectShape(This,pShape)	\
    ( (This)->lpVtbl -> get_OnLeftBtnClkEffectShape(This,pShape) ) 

#define ILMScrCap_put_OnLeftBtnClkEffectShape(This,newShape)	\
    ( (This)->lpVtbl -> put_OnLeftBtnClkEffectShape(This,newShape) ) 

#define ILMScrCap_get_OnRightBtnClkEffectShape(This,pShape)	\
    ( (This)->lpVtbl -> get_OnRightBtnClkEffectShape(This,pShape) ) 

#define ILMScrCap_put_OnRightBtnClkEffectShape(This,newShape)	\
    ( (This)->lpVtbl -> put_OnRightBtnClkEffectShape(This,newShape) ) 

#define ILMScrCap_get_OnLeftBtnClkEffectColor(This,pColor)	\
    ( (This)->lpVtbl -> get_OnLeftBtnClkEffectColor(This,pColor) ) 

#define ILMScrCap_put_OnLeftBtnClkEffectColor(This,newColor)	\
    ( (This)->lpVtbl -> put_OnLeftBtnClkEffectColor(This,newColor) ) 

#define ILMScrCap_get_OnRightBtnClkEffectColor(This,pColor)	\
    ( (This)->lpVtbl -> get_OnRightBtnClkEffectColor(This,pColor) ) 

#define ILMScrCap_put_OnRightBtnClkEffectColor(This,newColor)	\
    ( (This)->lpVtbl -> put_OnRightBtnClkEffectColor(This,newColor) ) 

#define ILMScrCap_get_OnLeftBtnClkEffectSize(This,pSize)	\
    ( (This)->lpVtbl -> get_OnLeftBtnClkEffectSize(This,pSize) ) 

#define ILMScrCap_put_OnLeftBtnClkEffectSize(This,newSize)	\
    ( (This)->lpVtbl -> put_OnLeftBtnClkEffectSize(This,newSize) ) 

#define ILMScrCap_get_OnRightBtnClkEffectSize(This,pSize)	\
    ( (This)->lpVtbl -> get_OnRightBtnClkEffectSize(This,pSize) ) 

#define ILMScrCap_put_OnRightBtnClkEffectSize(This,newSize)	\
    ( (This)->lpVtbl -> put_OnRightBtnClkEffectSize(This,newSize) ) 

#define ILMScrCap_get_EnablePanning(This,pEnable)	\
    ( (This)->lpVtbl -> get_EnablePanning(This,pEnable) ) 

#define ILMScrCap_put_EnablePanning(This,newEnable)	\
    ( (This)->lpVtbl -> put_EnablePanning(This,newEnable) ) 

#define ILMScrCap_get_ZoomFactor(This,pZoom)	\
    ( (This)->lpVtbl -> get_ZoomFactor(This,pZoom) ) 

#define ILMScrCap_put_ZoomFactor(This,newZoom)	\
    ( (This)->lpVtbl -> put_ZoomFactor(This,newZoom) ) 

#define ILMScrCap_get_EnableOutline(This,pEnable)	\
    ( (This)->lpVtbl -> get_EnableOutline(This,pEnable) ) 

#define ILMScrCap_put_EnableOutline(This,newEnable)	\
    ( (This)->lpVtbl -> put_EnableOutline(This,newEnable) ) 

#define ILMScrCap_get_ManualMode(This,pMode)	\
    ( (This)->lpVtbl -> get_ManualMode(This,pMode) ) 

#define ILMScrCap_put_ManualMode(This,newMode)	\
    ( (This)->lpVtbl -> put_ManualMode(This,newMode) ) 

#define ILMScrCap_CaptureFrames(This,lFramesNumber)	\
    ( (This)->lpVtbl -> CaptureFrames(This,lFramesNumber) ) 

#define ILMScrCap_get_MouseHighlight(This,pEffect)	\
    ( (This)->lpVtbl -> get_MouseHighlight(This,pEffect) ) 

#define ILMScrCap_put_MouseHighlight(This,newEffect)	\
    ( (This)->lpVtbl -> put_MouseHighlight(This,newEffect) ) 

#define ILMScrCap_get_MouseHighlightSize(This,pSize)	\
    ( (This)->lpVtbl -> get_MouseHighlightSize(This,pSize) ) 

#define ILMScrCap_put_MouseHighlightSize(This,newSize)	\
    ( (This)->lpVtbl -> put_MouseHighlightSize(This,newSize) ) 

#define ILMScrCap_get_MouseHighlightColor(This,pColor)	\
    ( (This)->lpVtbl -> get_MouseHighlightColor(This,pColor) ) 

#define ILMScrCap_put_MouseHighlightColor(This,newColor)	\
    ( (This)->lpVtbl -> put_MouseHighlightColor(This,newColor) ) 

#define ILMScrCap_get_MouseHighlightMode(This,pMode)	\
    ( (This)->lpVtbl -> get_MouseHighlightMode(This,pMode) ) 

#define ILMScrCap_put_MouseHighlightMode(This,newMode)	\
    ( (This)->lpVtbl -> put_MouseHighlightMode(This,newMode) ) 

#define ILMScrCap_SetUserEventsCallbackObject(This,pCallbackObject,pUserData)	\
    ( (This)->lpVtbl -> SetUserEventsCallbackObject(This,pCallbackObject,pUserData) ) 

#define ILMScrCap_get_UserEventsNotifyCallback(This,pNotifyCallback)	\
    ( (This)->lpVtbl -> get_UserEventsNotifyCallback(This,pNotifyCallback) ) 

#define ILMScrCap_put_UserEventsNotifyCallback(This,newNotifyCallback)	\
    ( (This)->lpVtbl -> put_UserEventsNotifyCallback(This,newNotifyCallback) ) 

#define ILMScrCap_get_OutlineShape(This,pOutlineShape)	\
    ( (This)->lpVtbl -> get_OutlineShape(This,pOutlineShape) ) 

#define ILMScrCap_put_OutlineShape(This,newOutlineShape)	\
    ( (This)->lpVtbl -> put_OutlineShape(This,newOutlineShape) ) 

#define ILMScrCap_SetZoomStepsInfo(This,lSteps,lMinStepSize)	\
    ( (This)->lpVtbl -> SetZoomStepsInfo(This,lSteps,lMinStepSize) ) 

#define ILMScrCap_SetPanStepsInfo(This,lSteps,lMinStepSteps)	\
    ( (This)->lpVtbl -> SetPanStepsInfo(This,lSteps,lMinStepSteps) ) 

#define ILMScrCap_GetZoomStepsInfo(This,plSteps,plMinStepSize)	\
    ( (This)->lpVtbl -> GetZoomStepsInfo(This,plSteps,plMinStepSize) ) 

#define ILMScrCap_GetPanStepsInfo(This,plSteps,plMinStepSize)	\
    ( (This)->lpVtbl -> GetPanStepsInfo(This,plSteps,plMinStepSize) ) 

#define ILMScrCap_get_CaptureAlignment(This,pCaptureAlignment)	\
    ( (This)->lpVtbl -> get_CaptureAlignment(This,pCaptureAlignment) ) 

#define ILMScrCap_put_CaptureAlignment(This,newCaptureAlignment)	\
    ( (This)->lpVtbl -> put_CaptureAlignment(This,newCaptureAlignment) ) 

#define ILMScrCap_PanToXY(This,lXPos,lYPos)	\
    ( (This)->lpVtbl -> PanToXY(This,lXPos,lYPos) ) 

#define ILMScrCap_PanToWindow(This,lHwnd,vbFollow,vbFit)	\
    ( (This)->lpVtbl -> PanToWindow(This,lHwnd,vbFollow,vbFit) ) 

#define ILMScrCap_PanToCursor(This,vbFollow)	\
    ( (This)->lpVtbl -> PanToCursor(This,vbFollow) ) 

#define ILMScrCap_get_OutlineColor(This,pColor)	\
    ( (This)->lpVtbl -> get_OutlineColor(This,pColor) ) 

#define ILMScrCap_put_OutlineColor(This,newColor)	\
    ( (This)->lpVtbl -> put_OutlineColor(This,newColor) ) 

#define ILMScrCap_get_LowerWidthLimit(This,pLowerWidthLimit)	\
    ( (This)->lpVtbl -> get_LowerWidthLimit(This,pLowerWidthLimit) ) 

#define ILMScrCap_put_LowerWidthLimit(This,newLowerWidthLimit)	\
    ( (This)->lpVtbl -> put_LowerWidthLimit(This,newLowerWidthLimit) ) 

#define ILMScrCap_get_UpperWidthLimit(This,pUpperWidthLimit)	\
    ( (This)->lpVtbl -> get_UpperWidthLimit(This,pUpperWidthLimit) ) 

#define ILMScrCap_put_UpperWidthLimit(This,newUpperWidthLimit)	\
    ( (This)->lpVtbl -> put_UpperWidthLimit(This,newUpperWidthLimit) ) 

#define ILMScrCap_get_LowerHeightLimit(This,pLowerHeightLimit)	\
    ( (This)->lpVtbl -> get_LowerHeightLimit(This,pLowerHeightLimit) ) 

#define ILMScrCap_put_LowerHeightLimit(This,newLowerHeightLimit)	\
    ( (This)->lpVtbl -> put_LowerHeightLimit(This,newLowerHeightLimit) ) 

#define ILMScrCap_get_UpperHeightLimit(This,pUpperHeightLimit)	\
    ( (This)->lpVtbl -> get_UpperHeightLimit(This,pUpperHeightLimit) ) 

#define ILMScrCap_put_UpperHeightLimit(This,newUpperHeightLimit)	\
    ( (This)->lpVtbl -> put_UpperHeightLimit(This,newUpperHeightLimit) ) 

#define ILMScrCap_get_RgnSelToolStepSizeX(This,pRgnSelToolStepSizeX)	\
    ( (This)->lpVtbl -> get_RgnSelToolStepSizeX(This,pRgnSelToolStepSizeX) ) 

#define ILMScrCap_put_RgnSelToolStepSizeX(This,newRgnSelToolStepSizeX)	\
    ( (This)->lpVtbl -> put_RgnSelToolStepSizeX(This,newRgnSelToolStepSizeX) ) 

#define ILMScrCap_get_RgnSelToolStepSizeY(This,pRgnSelToolStepSizeY)	\
    ( (This)->lpVtbl -> get_RgnSelToolStepSizeY(This,pRgnSelToolStepSizeY) ) 

#define ILMScrCap_put_RgnSelToolStepSizeY(This,newRgnSelToolStepSizeY)	\
    ( (This)->lpVtbl -> put_RgnSelToolStepSizeY(This,newRgnSelToolStepSizeY) ) 

#define ILMScrCap_get_RgnSelToolWarningColor(This,pRgnSelToolWarningColor)	\
    ( (This)->lpVtbl -> get_RgnSelToolWarningColor(This,pRgnSelToolWarningColor) ) 

#define ILMScrCap_put_RgnSelToolWarningColor(This,newRgnSelToolWarningColor)	\
    ( (This)->lpVtbl -> put_RgnSelToolWarningColor(This,newRgnSelToolWarningColor) ) 

#define ILMScrCap_get_RgnSelToolLockSelOnLimit(This,pRgnSelToolLockSelOnLimit)	\
    ( (This)->lpVtbl -> get_RgnSelToolLockSelOnLimit(This,pRgnSelToolLockSelOnLimit) ) 

#define ILMScrCap_put_RgnSelToolLockSelOnLimit(This,newRgnSelToolLockSelOnLimit)	\
    ( (This)->lpVtbl -> put_RgnSelToolLockSelOnLimit(This,newRgnSelToolLockSelOnLimit) ) 

#define ILMScrCap_ResetToDefaults(This)	\
    ( (This)->lpVtbl -> ResetToDefaults(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMScrCap_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LMScrCap;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DE13-38C5-11D5-91F6-00104BDB8FF9")
LMScrCap;
#endif
#endif /* __LMScrCapLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


