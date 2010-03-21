

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Nov 05 12:41:04 2009
 */
/* Compiler settings for .\IMtnDet.idl:
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


#ifndef __ILMVMtnDet2_h__
#define __ILMVMtnDet2_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILMVMtnDetUserCallback_FWD_DEFINED__
#define __ILMVMtnDetUserCallback_FWD_DEFINED__
typedef interface ILMVMtnDetUserCallback ILMVMtnDetUserCallback;
#endif 	/* __ILMVMtnDetUserCallback_FWD_DEFINED__ */


#ifndef __ILMVMtnDetOld1_FWD_DEFINED__
#define __ILMVMtnDetOld1_FWD_DEFINED__
typedef interface ILMVMtnDetOld1 ILMVMtnDetOld1;
#endif 	/* __ILMVMtnDetOld1_FWD_DEFINED__ */


#ifndef __ILMVMtnDet_FWD_DEFINED__
#define __ILMVMtnDet_FWD_DEFINED__
typedef interface ILMVMtnDet ILMVMtnDet;
#endif 	/* __ILMVMtnDet_FWD_DEFINED__ */


#ifndef __LMVMtnDet_FWD_DEFINED__
#define __LMVMtnDet_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMVMtnDet LMVMtnDet;
#else
typedef struct LMVMtnDet LMVMtnDet;
#endif /* __cplusplus */

#endif 	/* __LMVMtnDet_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LMVMtnDetLib_LIBRARY_DEFINED__
#define __LMVMtnDetLib_LIBRARY_DEFINED__

/* library LMVMtnDetLib */
/* [helpstring][version][uuid] */ 

static const GUID LIBID_LMVMtnDetLib           = {0xE2B7DDFA, 0x38C5, 0x11D5, {0x91, 0xF6, 0x00, 0x10, 0x4B, 0xDB, 0x8F, 0xF9}};
static const GUID CLSID_LMVMtnDet              = {0xE2B7DDFB, 0x38C5, 0x11D5, {0x91, 0xF6, 0x00, 0x10, 0x4B, 0xDB, 0x8F, 0xF9}};
static const GUID CLSID_LMVMtnDetPropertyPage  = {0xE2B7DDFC, 0x38C5, 0x11D5, {0x91, 0xF6, 0x00, 0x10, 0x4B, 0xDB, 0x8F, 0xF9}};
static const GUID CLSID_LMVAboutMtnDet         = {0xE2B7DDFD, 0x38C5, 0x11D5, {0x91, 0xF6, 0x00, 0x10, 0x4B, 0xDB, 0x8F, 0xF9}};
static const GUID IID_ILMVMtnDetOld1           = {0xE2B7DDFE, 0x38C5, 0x11D5, {0x91, 0xF6, 0x00, 0x10, 0x4B, 0xDB, 0x8F, 0xF9}};
static const GUID IID_ILMVMtnDet               = {0xE2B7DF5F, 0x38C5, 0x11D5, {0x91, 0xF6, 0x00, 0x10, 0x4B, 0xDB, 0x8F, 0xF9}};
static const GUID IID_ILMVMtnDetUserCallback   = {0xE2B7DDFF, 0x38C5, 0x11D5, {0x91, 0xF6, 0x00, 0x10, 0x4B, 0xDB, 0x8F, 0xF9}};
typedef /* [v1_enum] */ 
enum MtnCalBkErrConstants
    {	MTNCALBK_ERR_SUCCESS	= 0,
	MTNCALBK_ERR_PRESERVEDATA	= 100
    } 	MtnCalBkErrConstants;

typedef /* [v1_enum] */ 
enum FrameTypeConstants
    {	FRAME_TYPE_STARTMOTION	= 0,
	FRAME_TYPE_MOTION	= 1,
	FRAME_TYPE_STARTSTILL	= 2,
	FRAME_TYPE_STILL	= 3
    } 	FrameTypeConstants;

typedef /* [v1_enum] */ 
enum MtnDetStateConstants
    {	MTNDET_STATE_STOPPED	= 0,
	MTNDET_STATE_RUNNING	= 1
    } 	MtnDetStateConstants;


EXTERN_C const IID LIBID_LMVMtnDetLib;

#ifndef __ILMVMtnDetUserCallback_INTERFACE_DEFINED__
#define __ILMVMtnDetUserCallback_INTERFACE_DEFINED__

/* interface ILMVMtnDetUserCallback */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ILMVMtnDetUserCallback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DDFF-38C5-11D5-91F6-00104BDB8FF9")
    ILMVMtnDetUserCallback : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CallbackProc( 
            /* [in] */ long lEvent,
            /* [in] */ long pFrame,
            /* [in] */ long lWidth,
            /* [in] */ long lHeight,
            /* [in] */ long lBitCount,
            /* [in] */ long lFrameSize,
            /* [in] */ VARIANT_BOOL bTopDown,
            /* [retval][out] */ long *pRet) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMVMtnDetUserCallbackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMVMtnDetUserCallback * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMVMtnDetUserCallback * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMVMtnDetUserCallback * This);
        
        HRESULT ( STDMETHODCALLTYPE *CallbackProc )( 
            ILMVMtnDetUserCallback * This,
            /* [in] */ long lEvent,
            /* [in] */ long pFrame,
            /* [in] */ long lWidth,
            /* [in] */ long lHeight,
            /* [in] */ long lBitCount,
            /* [in] */ long lFrameSize,
            /* [in] */ VARIANT_BOOL bTopDown,
            /* [retval][out] */ long *pRet);
        
        END_INTERFACE
    } ILMVMtnDetUserCallbackVtbl;

    interface ILMVMtnDetUserCallback
    {
        CONST_VTBL struct ILMVMtnDetUserCallbackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMVMtnDetUserCallback_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMVMtnDetUserCallback_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMVMtnDetUserCallback_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMVMtnDetUserCallback_CallbackProc(This,lEvent,pFrame,lWidth,lHeight,lBitCount,lFrameSize,bTopDown,pRet)	\
    ( (This)->lpVtbl -> CallbackProc(This,lEvent,pFrame,lWidth,lHeight,lBitCount,lFrameSize,bTopDown,pRet) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMVMtnDetUserCallback_INTERFACE_DEFINED__ */


#ifndef __ILMVMtnDetOld1_INTERFACE_DEFINED__
#define __ILMVMtnDetOld1_INTERFACE_DEFINED__

/* interface ILMVMtnDetOld1 */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ILMVMtnDetOld1;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DDFE-38C5-11D5-91F6-00104BDB8FF9")
    ILMVMtnDetOld1 : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Sensitivity( 
            /* [retval][out] */ long *plSensitivity) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Sensitivity( 
            /* [in] */ long newlSensitivity) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ObjectSize( 
            /* [retval][out] */ long *plObjectSize) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ObjectSize( 
            /* [in] */ long newlObjectSize) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ViewContainingRectangle( 
            /* [retval][out] */ VARIANT_BOOL *pbViewRect) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ViewContainingRectangle( 
            /* [in] */ VARIANT_BOOL newbViewRect) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ViewDifferenceFrames( 
            /* [retval][out] */ VARIANT_BOOL *pbViewDiff) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ViewDifferenceFrames( 
            /* [in] */ VARIANT_BOOL newbViewDiff) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CallbackObj( 
            /* [in] */ ILMVMtnDetUserCallback *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RectCount( 
            /* [retval][out] */ long *plRectCount) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RectLeft( 
            /* [in] */ long lIndex,
            /* [retval][out] */ long *plLeft) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RectTop( 
            /* [in] */ long lIndex,
            /* [retval][out] */ long *plTop) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RectWidth( 
            /* [in] */ long lIndex,
            /* [retval][out] */ long *plWidth) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RectHeight( 
            /* [in] */ long lIndex,
            /* [retval][out] */ long *plHeight) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MinStillTime( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MinStillTime( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ScatteredMotionSpacing( 
            /* [retval][out] */ long *plScatteredMotionSpacing) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ScatteredMotionSpacing( 
            /* [in] */ long newlScatteredMotionSpacing) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Interval( 
            /* [retval][out] */ long *plInterval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Interval( 
            /* [in] */ long newlInterval) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Delay( 
            /* [retval][out] */ long *plDelay) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Delay( 
            /* [in] */ long newlDelay) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AutoStart( 
            /* [retval][out] */ VARIANT_BOOL *pbAutoStart) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AutoStart( 
            /* [in] */ VARIANT_BOOL newbAutoStart) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StartDetection( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StopDetection( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_State( 
            /* [retval][out] */ MtnDetStateConstants *pState) = 0;
        
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
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EnableRegion( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_EnableRegion( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_InvertRegionArea( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_InvertRegionArea( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Mosaic( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Mosaic( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EnableMosaic( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_EnableMosaic( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ResetToDefaults( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMVMtnDetOld1Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMVMtnDetOld1 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMVMtnDetOld1 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMVMtnDetOld1 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMVMtnDetOld1 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMVMtnDetOld1 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMVMtnDetOld1 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMVMtnDetOld1 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Sensitivity )( 
            ILMVMtnDetOld1 * This,
            /* [retval][out] */ long *plSensitivity);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Sensitivity )( 
            ILMVMtnDetOld1 * This,
            /* [in] */ long newlSensitivity);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectSize )( 
            ILMVMtnDetOld1 * This,
            /* [retval][out] */ long *plObjectSize);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ObjectSize )( 
            ILMVMtnDetOld1 * This,
            /* [in] */ long newlObjectSize);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ViewContainingRectangle )( 
            ILMVMtnDetOld1 * This,
            /* [retval][out] */ VARIANT_BOOL *pbViewRect);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ViewContainingRectangle )( 
            ILMVMtnDetOld1 * This,
            /* [in] */ VARIANT_BOOL newbViewRect);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ViewDifferenceFrames )( 
            ILMVMtnDetOld1 * This,
            /* [retval][out] */ VARIANT_BOOL *pbViewDiff);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ViewDifferenceFrames )( 
            ILMVMtnDetOld1 * This,
            /* [in] */ VARIANT_BOOL newbViewDiff);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CallbackObj )( 
            ILMVMtnDetOld1 * This,
            /* [in] */ ILMVMtnDetUserCallback *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RectCount )( 
            ILMVMtnDetOld1 * This,
            /* [retval][out] */ long *plRectCount);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RectLeft )( 
            ILMVMtnDetOld1 * This,
            /* [in] */ long lIndex,
            /* [retval][out] */ long *plLeft);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RectTop )( 
            ILMVMtnDetOld1 * This,
            /* [in] */ long lIndex,
            /* [retval][out] */ long *plTop);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RectWidth )( 
            ILMVMtnDetOld1 * This,
            /* [in] */ long lIndex,
            /* [retval][out] */ long *plWidth);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RectHeight )( 
            ILMVMtnDetOld1 * This,
            /* [in] */ long lIndex,
            /* [retval][out] */ long *plHeight);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MinStillTime )( 
            ILMVMtnDetOld1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MinStillTime )( 
            ILMVMtnDetOld1 * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ScatteredMotionSpacing )( 
            ILMVMtnDetOld1 * This,
            /* [retval][out] */ long *plScatteredMotionSpacing);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ScatteredMotionSpacing )( 
            ILMVMtnDetOld1 * This,
            /* [in] */ long newlScatteredMotionSpacing);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Interval )( 
            ILMVMtnDetOld1 * This,
            /* [retval][out] */ long *plInterval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Interval )( 
            ILMVMtnDetOld1 * This,
            /* [in] */ long newlInterval);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Delay )( 
            ILMVMtnDetOld1 * This,
            /* [retval][out] */ long *plDelay);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Delay )( 
            ILMVMtnDetOld1 * This,
            /* [in] */ long newlDelay);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AutoStart )( 
            ILMVMtnDetOld1 * This,
            /* [retval][out] */ VARIANT_BOOL *pbAutoStart);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AutoStart )( 
            ILMVMtnDetOld1 * This,
            /* [in] */ VARIANT_BOOL newbAutoStart);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StartDetection )( 
            ILMVMtnDetOld1 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StopDetection )( 
            ILMVMtnDetOld1 * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_State )( 
            ILMVMtnDetOld1 * This,
            /* [retval][out] */ MtnDetStateConstants *pState);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Left )( 
            ILMVMtnDetOld1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Left )( 
            ILMVMtnDetOld1 * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Top )( 
            ILMVMtnDetOld1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Top )( 
            ILMVMtnDetOld1 * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Right )( 
            ILMVMtnDetOld1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Right )( 
            ILMVMtnDetOld1 * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Bottom )( 
            ILMVMtnDetOld1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Bottom )( 
            ILMVMtnDetOld1 * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableRegion )( 
            ILMVMtnDetOld1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableRegion )( 
            ILMVMtnDetOld1 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InvertRegionArea )( 
            ILMVMtnDetOld1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_InvertRegionArea )( 
            ILMVMtnDetOld1 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Mosaic )( 
            ILMVMtnDetOld1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Mosaic )( 
            ILMVMtnDetOld1 * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableMosaic )( 
            ILMVMtnDetOld1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableMosaic )( 
            ILMVMtnDetOld1 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetToDefaults )( 
            ILMVMtnDetOld1 * This);
        
        END_INTERFACE
    } ILMVMtnDetOld1Vtbl;

    interface ILMVMtnDetOld1
    {
        CONST_VTBL struct ILMVMtnDetOld1Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMVMtnDetOld1_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMVMtnDetOld1_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMVMtnDetOld1_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMVMtnDetOld1_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMVMtnDetOld1_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMVMtnDetOld1_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMVMtnDetOld1_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMVMtnDetOld1_get_Sensitivity(This,plSensitivity)	\
    ( (This)->lpVtbl -> get_Sensitivity(This,plSensitivity) ) 

#define ILMVMtnDetOld1_put_Sensitivity(This,newlSensitivity)	\
    ( (This)->lpVtbl -> put_Sensitivity(This,newlSensitivity) ) 

#define ILMVMtnDetOld1_get_ObjectSize(This,plObjectSize)	\
    ( (This)->lpVtbl -> get_ObjectSize(This,plObjectSize) ) 

#define ILMVMtnDetOld1_put_ObjectSize(This,newlObjectSize)	\
    ( (This)->lpVtbl -> put_ObjectSize(This,newlObjectSize) ) 

#define ILMVMtnDetOld1_get_ViewContainingRectangle(This,pbViewRect)	\
    ( (This)->lpVtbl -> get_ViewContainingRectangle(This,pbViewRect) ) 

#define ILMVMtnDetOld1_put_ViewContainingRectangle(This,newbViewRect)	\
    ( (This)->lpVtbl -> put_ViewContainingRectangle(This,newbViewRect) ) 

#define ILMVMtnDetOld1_get_ViewDifferenceFrames(This,pbViewDiff)	\
    ( (This)->lpVtbl -> get_ViewDifferenceFrames(This,pbViewDiff) ) 

#define ILMVMtnDetOld1_put_ViewDifferenceFrames(This,newbViewDiff)	\
    ( (This)->lpVtbl -> put_ViewDifferenceFrames(This,newbViewDiff) ) 

#define ILMVMtnDetOld1_put_CallbackObj(This,pVal)	\
    ( (This)->lpVtbl -> put_CallbackObj(This,pVal) ) 

#define ILMVMtnDetOld1_get_RectCount(This,plRectCount)	\
    ( (This)->lpVtbl -> get_RectCount(This,plRectCount) ) 

#define ILMVMtnDetOld1_get_RectLeft(This,lIndex,plLeft)	\
    ( (This)->lpVtbl -> get_RectLeft(This,lIndex,plLeft) ) 

#define ILMVMtnDetOld1_get_RectTop(This,lIndex,plTop)	\
    ( (This)->lpVtbl -> get_RectTop(This,lIndex,plTop) ) 

#define ILMVMtnDetOld1_get_RectWidth(This,lIndex,plWidth)	\
    ( (This)->lpVtbl -> get_RectWidth(This,lIndex,plWidth) ) 

#define ILMVMtnDetOld1_get_RectHeight(This,lIndex,plHeight)	\
    ( (This)->lpVtbl -> get_RectHeight(This,lIndex,plHeight) ) 

#define ILMVMtnDetOld1_get_MinStillTime(This,pVal)	\
    ( (This)->lpVtbl -> get_MinStillTime(This,pVal) ) 

#define ILMVMtnDetOld1_put_MinStillTime(This,newVal)	\
    ( (This)->lpVtbl -> put_MinStillTime(This,newVal) ) 

#define ILMVMtnDetOld1_get_ScatteredMotionSpacing(This,plScatteredMotionSpacing)	\
    ( (This)->lpVtbl -> get_ScatteredMotionSpacing(This,plScatteredMotionSpacing) ) 

#define ILMVMtnDetOld1_put_ScatteredMotionSpacing(This,newlScatteredMotionSpacing)	\
    ( (This)->lpVtbl -> put_ScatteredMotionSpacing(This,newlScatteredMotionSpacing) ) 

#define ILMVMtnDetOld1_get_Interval(This,plInterval)	\
    ( (This)->lpVtbl -> get_Interval(This,plInterval) ) 

#define ILMVMtnDetOld1_put_Interval(This,newlInterval)	\
    ( (This)->lpVtbl -> put_Interval(This,newlInterval) ) 

#define ILMVMtnDetOld1_get_Delay(This,plDelay)	\
    ( (This)->lpVtbl -> get_Delay(This,plDelay) ) 

#define ILMVMtnDetOld1_put_Delay(This,newlDelay)	\
    ( (This)->lpVtbl -> put_Delay(This,newlDelay) ) 

#define ILMVMtnDetOld1_get_AutoStart(This,pbAutoStart)	\
    ( (This)->lpVtbl -> get_AutoStart(This,pbAutoStart) ) 

#define ILMVMtnDetOld1_put_AutoStart(This,newbAutoStart)	\
    ( (This)->lpVtbl -> put_AutoStart(This,newbAutoStart) ) 

#define ILMVMtnDetOld1_StartDetection(This)	\
    ( (This)->lpVtbl -> StartDetection(This) ) 

#define ILMVMtnDetOld1_StopDetection(This)	\
    ( (This)->lpVtbl -> StopDetection(This) ) 

#define ILMVMtnDetOld1_get_State(This,pState)	\
    ( (This)->lpVtbl -> get_State(This,pState) ) 

#define ILMVMtnDetOld1_get_Left(This,pVal)	\
    ( (This)->lpVtbl -> get_Left(This,pVal) ) 

#define ILMVMtnDetOld1_put_Left(This,newVal)	\
    ( (This)->lpVtbl -> put_Left(This,newVal) ) 

#define ILMVMtnDetOld1_get_Top(This,pVal)	\
    ( (This)->lpVtbl -> get_Top(This,pVal) ) 

#define ILMVMtnDetOld1_put_Top(This,newVal)	\
    ( (This)->lpVtbl -> put_Top(This,newVal) ) 

#define ILMVMtnDetOld1_get_Right(This,pVal)	\
    ( (This)->lpVtbl -> get_Right(This,pVal) ) 

#define ILMVMtnDetOld1_put_Right(This,newVal)	\
    ( (This)->lpVtbl -> put_Right(This,newVal) ) 

#define ILMVMtnDetOld1_get_Bottom(This,pVal)	\
    ( (This)->lpVtbl -> get_Bottom(This,pVal) ) 

#define ILMVMtnDetOld1_put_Bottom(This,newVal)	\
    ( (This)->lpVtbl -> put_Bottom(This,newVal) ) 

#define ILMVMtnDetOld1_get_EnableRegion(This,pVal)	\
    ( (This)->lpVtbl -> get_EnableRegion(This,pVal) ) 

#define ILMVMtnDetOld1_put_EnableRegion(This,newVal)	\
    ( (This)->lpVtbl -> put_EnableRegion(This,newVal) ) 

#define ILMVMtnDetOld1_get_InvertRegionArea(This,pVal)	\
    ( (This)->lpVtbl -> get_InvertRegionArea(This,pVal) ) 

#define ILMVMtnDetOld1_put_InvertRegionArea(This,newVal)	\
    ( (This)->lpVtbl -> put_InvertRegionArea(This,newVal) ) 

#define ILMVMtnDetOld1_get_Mosaic(This,pVal)	\
    ( (This)->lpVtbl -> get_Mosaic(This,pVal) ) 

#define ILMVMtnDetOld1_put_Mosaic(This,newVal)	\
    ( (This)->lpVtbl -> put_Mosaic(This,newVal) ) 

#define ILMVMtnDetOld1_get_EnableMosaic(This,pVal)	\
    ( (This)->lpVtbl -> get_EnableMosaic(This,pVal) ) 

#define ILMVMtnDetOld1_put_EnableMosaic(This,newVal)	\
    ( (This)->lpVtbl -> put_EnableMosaic(This,newVal) ) 

#define ILMVMtnDetOld1_ResetToDefaults(This)	\
    ( (This)->lpVtbl -> ResetToDefaults(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMVMtnDetOld1_INTERFACE_DEFINED__ */


#ifndef __ILMVMtnDet_INTERFACE_DEFINED__
#define __ILMVMtnDet_INTERFACE_DEFINED__

/* interface ILMVMtnDet */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ILMVMtnDet;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DF5F-38C5-11D5-91F6-00104BDB8FF9")
    ILMVMtnDet : public ILMVMtnDetOld1
    {
    public:
        virtual /* [helpstring][id] */ long STDMETHODCALLTYPE LockRectangleInfo( void) = 0;
        
        virtual /* [helpstring][id] */ long STDMETHODCALLTYPE UnlockRectangleInfo( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMVMtnDetVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMVMtnDet * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMVMtnDet * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMVMtnDet * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMVMtnDet * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMVMtnDet * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMVMtnDet * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMVMtnDet * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Sensitivity )( 
            ILMVMtnDet * This,
            /* [retval][out] */ long *plSensitivity);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Sensitivity )( 
            ILMVMtnDet * This,
            /* [in] */ long newlSensitivity);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectSize )( 
            ILMVMtnDet * This,
            /* [retval][out] */ long *plObjectSize);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ObjectSize )( 
            ILMVMtnDet * This,
            /* [in] */ long newlObjectSize);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ViewContainingRectangle )( 
            ILMVMtnDet * This,
            /* [retval][out] */ VARIANT_BOOL *pbViewRect);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ViewContainingRectangle )( 
            ILMVMtnDet * This,
            /* [in] */ VARIANT_BOOL newbViewRect);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ViewDifferenceFrames )( 
            ILMVMtnDet * This,
            /* [retval][out] */ VARIANT_BOOL *pbViewDiff);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ViewDifferenceFrames )( 
            ILMVMtnDet * This,
            /* [in] */ VARIANT_BOOL newbViewDiff);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CallbackObj )( 
            ILMVMtnDet * This,
            /* [in] */ ILMVMtnDetUserCallback *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RectCount )( 
            ILMVMtnDet * This,
            /* [retval][out] */ long *plRectCount);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RectLeft )( 
            ILMVMtnDet * This,
            /* [in] */ long lIndex,
            /* [retval][out] */ long *plLeft);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RectTop )( 
            ILMVMtnDet * This,
            /* [in] */ long lIndex,
            /* [retval][out] */ long *plTop);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RectWidth )( 
            ILMVMtnDet * This,
            /* [in] */ long lIndex,
            /* [retval][out] */ long *plWidth);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RectHeight )( 
            ILMVMtnDet * This,
            /* [in] */ long lIndex,
            /* [retval][out] */ long *plHeight);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MinStillTime )( 
            ILMVMtnDet * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MinStillTime )( 
            ILMVMtnDet * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ScatteredMotionSpacing )( 
            ILMVMtnDet * This,
            /* [retval][out] */ long *plScatteredMotionSpacing);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ScatteredMotionSpacing )( 
            ILMVMtnDet * This,
            /* [in] */ long newlScatteredMotionSpacing);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Interval )( 
            ILMVMtnDet * This,
            /* [retval][out] */ long *plInterval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Interval )( 
            ILMVMtnDet * This,
            /* [in] */ long newlInterval);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Delay )( 
            ILMVMtnDet * This,
            /* [retval][out] */ long *plDelay);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Delay )( 
            ILMVMtnDet * This,
            /* [in] */ long newlDelay);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AutoStart )( 
            ILMVMtnDet * This,
            /* [retval][out] */ VARIANT_BOOL *pbAutoStart);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AutoStart )( 
            ILMVMtnDet * This,
            /* [in] */ VARIANT_BOOL newbAutoStart);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StartDetection )( 
            ILMVMtnDet * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StopDetection )( 
            ILMVMtnDet * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_State )( 
            ILMVMtnDet * This,
            /* [retval][out] */ MtnDetStateConstants *pState);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Left )( 
            ILMVMtnDet * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Left )( 
            ILMVMtnDet * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Top )( 
            ILMVMtnDet * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Top )( 
            ILMVMtnDet * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Right )( 
            ILMVMtnDet * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Right )( 
            ILMVMtnDet * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Bottom )( 
            ILMVMtnDet * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Bottom )( 
            ILMVMtnDet * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableRegion )( 
            ILMVMtnDet * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableRegion )( 
            ILMVMtnDet * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InvertRegionArea )( 
            ILMVMtnDet * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_InvertRegionArea )( 
            ILMVMtnDet * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Mosaic )( 
            ILMVMtnDet * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Mosaic )( 
            ILMVMtnDet * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableMosaic )( 
            ILMVMtnDet * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableMosaic )( 
            ILMVMtnDet * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetToDefaults )( 
            ILMVMtnDet * This);
        
        /* [helpstring][id] */ long ( STDMETHODCALLTYPE *LockRectangleInfo )( 
            ILMVMtnDet * This);
        
        /* [helpstring][id] */ long ( STDMETHODCALLTYPE *UnlockRectangleInfo )( 
            ILMVMtnDet * This);
        
        END_INTERFACE
    } ILMVMtnDetVtbl;

    interface ILMVMtnDet
    {
        CONST_VTBL struct ILMVMtnDetVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMVMtnDet_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMVMtnDet_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMVMtnDet_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMVMtnDet_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMVMtnDet_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMVMtnDet_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMVMtnDet_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMVMtnDet_get_Sensitivity(This,plSensitivity)	\
    ( (This)->lpVtbl -> get_Sensitivity(This,plSensitivity) ) 

#define ILMVMtnDet_put_Sensitivity(This,newlSensitivity)	\
    ( (This)->lpVtbl -> put_Sensitivity(This,newlSensitivity) ) 

#define ILMVMtnDet_get_ObjectSize(This,plObjectSize)	\
    ( (This)->lpVtbl -> get_ObjectSize(This,plObjectSize) ) 

#define ILMVMtnDet_put_ObjectSize(This,newlObjectSize)	\
    ( (This)->lpVtbl -> put_ObjectSize(This,newlObjectSize) ) 

#define ILMVMtnDet_get_ViewContainingRectangle(This,pbViewRect)	\
    ( (This)->lpVtbl -> get_ViewContainingRectangle(This,pbViewRect) ) 

#define ILMVMtnDet_put_ViewContainingRectangle(This,newbViewRect)	\
    ( (This)->lpVtbl -> put_ViewContainingRectangle(This,newbViewRect) ) 

#define ILMVMtnDet_get_ViewDifferenceFrames(This,pbViewDiff)	\
    ( (This)->lpVtbl -> get_ViewDifferenceFrames(This,pbViewDiff) ) 

#define ILMVMtnDet_put_ViewDifferenceFrames(This,newbViewDiff)	\
    ( (This)->lpVtbl -> put_ViewDifferenceFrames(This,newbViewDiff) ) 

#define ILMVMtnDet_put_CallbackObj(This,pVal)	\
    ( (This)->lpVtbl -> put_CallbackObj(This,pVal) ) 

#define ILMVMtnDet_get_RectCount(This,plRectCount)	\
    ( (This)->lpVtbl -> get_RectCount(This,plRectCount) ) 

#define ILMVMtnDet_get_RectLeft(This,lIndex,plLeft)	\
    ( (This)->lpVtbl -> get_RectLeft(This,lIndex,plLeft) ) 

#define ILMVMtnDet_get_RectTop(This,lIndex,plTop)	\
    ( (This)->lpVtbl -> get_RectTop(This,lIndex,plTop) ) 

#define ILMVMtnDet_get_RectWidth(This,lIndex,plWidth)	\
    ( (This)->lpVtbl -> get_RectWidth(This,lIndex,plWidth) ) 

#define ILMVMtnDet_get_RectHeight(This,lIndex,plHeight)	\
    ( (This)->lpVtbl -> get_RectHeight(This,lIndex,plHeight) ) 

#define ILMVMtnDet_get_MinStillTime(This,pVal)	\
    ( (This)->lpVtbl -> get_MinStillTime(This,pVal) ) 

#define ILMVMtnDet_put_MinStillTime(This,newVal)	\
    ( (This)->lpVtbl -> put_MinStillTime(This,newVal) ) 

#define ILMVMtnDet_get_ScatteredMotionSpacing(This,plScatteredMotionSpacing)	\
    ( (This)->lpVtbl -> get_ScatteredMotionSpacing(This,plScatteredMotionSpacing) ) 

#define ILMVMtnDet_put_ScatteredMotionSpacing(This,newlScatteredMotionSpacing)	\
    ( (This)->lpVtbl -> put_ScatteredMotionSpacing(This,newlScatteredMotionSpacing) ) 

#define ILMVMtnDet_get_Interval(This,plInterval)	\
    ( (This)->lpVtbl -> get_Interval(This,plInterval) ) 

#define ILMVMtnDet_put_Interval(This,newlInterval)	\
    ( (This)->lpVtbl -> put_Interval(This,newlInterval) ) 

#define ILMVMtnDet_get_Delay(This,plDelay)	\
    ( (This)->lpVtbl -> get_Delay(This,plDelay) ) 

#define ILMVMtnDet_put_Delay(This,newlDelay)	\
    ( (This)->lpVtbl -> put_Delay(This,newlDelay) ) 

#define ILMVMtnDet_get_AutoStart(This,pbAutoStart)	\
    ( (This)->lpVtbl -> get_AutoStart(This,pbAutoStart) ) 

#define ILMVMtnDet_put_AutoStart(This,newbAutoStart)	\
    ( (This)->lpVtbl -> put_AutoStart(This,newbAutoStart) ) 

#define ILMVMtnDet_StartDetection(This)	\
    ( (This)->lpVtbl -> StartDetection(This) ) 

#define ILMVMtnDet_StopDetection(This)	\
    ( (This)->lpVtbl -> StopDetection(This) ) 

#define ILMVMtnDet_get_State(This,pState)	\
    ( (This)->lpVtbl -> get_State(This,pState) ) 

#define ILMVMtnDet_get_Left(This,pVal)	\
    ( (This)->lpVtbl -> get_Left(This,pVal) ) 

#define ILMVMtnDet_put_Left(This,newVal)	\
    ( (This)->lpVtbl -> put_Left(This,newVal) ) 

#define ILMVMtnDet_get_Top(This,pVal)	\
    ( (This)->lpVtbl -> get_Top(This,pVal) ) 

#define ILMVMtnDet_put_Top(This,newVal)	\
    ( (This)->lpVtbl -> put_Top(This,newVal) ) 

#define ILMVMtnDet_get_Right(This,pVal)	\
    ( (This)->lpVtbl -> get_Right(This,pVal) ) 

#define ILMVMtnDet_put_Right(This,newVal)	\
    ( (This)->lpVtbl -> put_Right(This,newVal) ) 

#define ILMVMtnDet_get_Bottom(This,pVal)	\
    ( (This)->lpVtbl -> get_Bottom(This,pVal) ) 

#define ILMVMtnDet_put_Bottom(This,newVal)	\
    ( (This)->lpVtbl -> put_Bottom(This,newVal) ) 

#define ILMVMtnDet_get_EnableRegion(This,pVal)	\
    ( (This)->lpVtbl -> get_EnableRegion(This,pVal) ) 

#define ILMVMtnDet_put_EnableRegion(This,newVal)	\
    ( (This)->lpVtbl -> put_EnableRegion(This,newVal) ) 

#define ILMVMtnDet_get_InvertRegionArea(This,pVal)	\
    ( (This)->lpVtbl -> get_InvertRegionArea(This,pVal) ) 

#define ILMVMtnDet_put_InvertRegionArea(This,newVal)	\
    ( (This)->lpVtbl -> put_InvertRegionArea(This,newVal) ) 

#define ILMVMtnDet_get_Mosaic(This,pVal)	\
    ( (This)->lpVtbl -> get_Mosaic(This,pVal) ) 

#define ILMVMtnDet_put_Mosaic(This,newVal)	\
    ( (This)->lpVtbl -> put_Mosaic(This,newVal) ) 

#define ILMVMtnDet_get_EnableMosaic(This,pVal)	\
    ( (This)->lpVtbl -> get_EnableMosaic(This,pVal) ) 

#define ILMVMtnDet_put_EnableMosaic(This,newVal)	\
    ( (This)->lpVtbl -> put_EnableMosaic(This,newVal) ) 

#define ILMVMtnDet_ResetToDefaults(This)	\
    ( (This)->lpVtbl -> ResetToDefaults(This) ) 


#define ILMVMtnDet_LockRectangleInfo(This)	\
    ( (This)->lpVtbl -> LockRectangleInfo(This) ) 

#define ILMVMtnDet_UnlockRectangleInfo(This)	\
    ( (This)->lpVtbl -> UnlockRectangleInfo(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMVMtnDet_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LMVMtnDet;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DDFB-38C5-11D5-91F6-00104BDB8FF9")
LMVMtnDet;
#endif
#endif /* __LMVMtnDetLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


