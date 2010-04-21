

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Nov 05 12:36:38 2009
 */
/* Compiler settings for .\IAdd.idl:
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


#ifndef __ILMVAdd_h__
#define __ILMVAdd_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILMVAdd_FWD_DEFINED__
#define __ILMVAdd_FWD_DEFINED__
typedef interface ILMVAdd ILMVAdd;
#endif 	/* __ILMVAdd_FWD_DEFINED__ */


#ifndef __ILMVAddDisp_FWD_DEFINED__
#define __ILMVAddDisp_FWD_DEFINED__
typedef interface ILMVAddDisp ILMVAddDisp;
#endif 	/* __ILMVAddDisp_FWD_DEFINED__ */


#ifndef __LMVAdd_FWD_DEFINED__
#define __LMVAdd_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMVAdd LMVAdd;
#else
typedef struct LMVAdd LMVAdd;
#endif /* __cplusplus */

#endif 	/* __LMVAdd_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LMVAddLib_LIBRARY_DEFINED__
#define __LMVAddLib_LIBRARY_DEFINED__

/* library LMVAddLib */
/* [helpstring][version][uuid] */ 

#ifndef __IADD_H__
#define __IADD_H__
static const GUID CLSID_LMVAdd             = {0xE2B7DB1F, 0x38C5, 0x11D5, {0x91, 0xF6, 0x00, 0x10, 0x4B, 0xDB, 0x8F, 0xF9}};
static const GUID IID_ILMVAdd              = {0xE2B7DB20, 0x38C5, 0x11D5, {0x91, 0xF6, 0x00, 0x10, 0x4B, 0xDB, 0x8F, 0xF9}};
static const GUID CLSID_LMVAddPropertyPage = {0xE2B7DB21, 0x38C5, 0x11D5, {0x91, 0xF6, 0x00, 0x10, 0x4B, 0xDB, 0x8F, 0xF9}};
static const GUID CLSID_LMVAboutAdd        = {0xe2b7db44, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID LIBID_LMVAddLib          = {0xe2b7db68, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMVAddDisp          = {0xe2b7db69, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
#endif 
#define MAX_BUFFERS 10
typedef struct _ADDATTRIBUTES
    {
    BOOL bEnable;
    BOOL bPreserveFrameRate;
    BOOL bAverage;
    INT nFrames;
    INT nFactors[ 10 ];
    INT nCurFrame;
    } 	ADDATTRIBUTES;


EXTERN_C const IID LIBID_LMVAddLib;

#ifndef __ILMVAdd_INTERFACE_DEFINED__
#define __ILMVAdd_INTERFACE_DEFINED__

/* interface ILMVAdd */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ILMVAdd;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DB20-38C5-11D5-91F6-00104BDB8FF9")
    ILMVAdd : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetAddAttributes( 
            /* [out][in] */ ADDATTRIBUTES *pAddAttributes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAddAttributes( 
            /* [in] */ ADDATTRIBUTES AddAttributes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsLEADInputPinConnected( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsLEADOutputPinConnected( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIODimensions( 
            /* [out] */ long *plInWidth,
            /* [out] */ long *plInHeight,
            /* [out] */ long *plOutWidth,
            /* [out] */ long *plOutHeight) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIOBitCount( 
            /* [out] */ int *plInBits,
            /* [out] */ int *plOutBits) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMVAddVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMVAdd * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMVAdd * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMVAdd * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetAddAttributes )( 
            ILMVAdd * This,
            /* [out][in] */ ADDATTRIBUTES *pAddAttributes);
        
        HRESULT ( STDMETHODCALLTYPE *SetAddAttributes )( 
            ILMVAdd * This,
            /* [in] */ ADDATTRIBUTES AddAttributes);
        
        HRESULT ( STDMETHODCALLTYPE *IsLEADInputPinConnected )( 
            ILMVAdd * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsLEADOutputPinConnected )( 
            ILMVAdd * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetIODimensions )( 
            ILMVAdd * This,
            /* [out] */ long *plInWidth,
            /* [out] */ long *plInHeight,
            /* [out] */ long *plOutWidth,
            /* [out] */ long *plOutHeight);
        
        HRESULT ( STDMETHODCALLTYPE *GetIOBitCount )( 
            ILMVAdd * This,
            /* [out] */ int *plInBits,
            /* [out] */ int *plOutBits);
        
        END_INTERFACE
    } ILMVAddVtbl;

    interface ILMVAdd
    {
        CONST_VTBL struct ILMVAddVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMVAdd_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMVAdd_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMVAdd_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMVAdd_GetAddAttributes(This,pAddAttributes)	\
    ( (This)->lpVtbl -> GetAddAttributes(This,pAddAttributes) ) 

#define ILMVAdd_SetAddAttributes(This,AddAttributes)	\
    ( (This)->lpVtbl -> SetAddAttributes(This,AddAttributes) ) 

#define ILMVAdd_IsLEADInputPinConnected(This)	\
    ( (This)->lpVtbl -> IsLEADInputPinConnected(This) ) 

#define ILMVAdd_IsLEADOutputPinConnected(This)	\
    ( (This)->lpVtbl -> IsLEADOutputPinConnected(This) ) 

#define ILMVAdd_GetIODimensions(This,plInWidth,plInHeight,plOutWidth,plOutHeight)	\
    ( (This)->lpVtbl -> GetIODimensions(This,plInWidth,plInHeight,plOutWidth,plOutHeight) ) 

#define ILMVAdd_GetIOBitCount(This,plInBits,plOutBits)	\
    ( (This)->lpVtbl -> GetIOBitCount(This,plInBits,plOutBits) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMVAdd_INTERFACE_DEFINED__ */


#ifndef __ILMVAddDisp_INTERFACE_DEFINED__
#define __ILMVAddDisp_INTERFACE_DEFINED__

/* interface ILMVAddDisp */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILMVAddDisp;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DB69-38C5-11D5-91F6-00104BDB8FF9")
    ILMVAddDisp : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Enabled( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Enabled( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PreserveFrameRate( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PreserveFrameRate( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Average( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Average( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Frames( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Frames( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetFrameFactor( 
            /* [in] */ int index,
            /* [out] */ int *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetFrameFactor( 
            /* [in] */ int index,
            /* [in] */ int newVal) = 0;
        
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

    typedef struct ILMVAddDispVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMVAddDisp * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMVAddDisp * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMVAddDisp * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMVAddDisp * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMVAddDisp * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMVAddDisp * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMVAddDisp * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Enabled )( 
            ILMVAddDisp * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Enabled )( 
            ILMVAddDisp * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PreserveFrameRate )( 
            ILMVAddDisp * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PreserveFrameRate )( 
            ILMVAddDisp * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Average )( 
            ILMVAddDisp * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Average )( 
            ILMVAddDisp * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Frames )( 
            ILMVAddDisp * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Frames )( 
            ILMVAddDisp * This,
            /* [in] */ int newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetFrameFactor )( 
            ILMVAddDisp * This,
            /* [in] */ int index,
            /* [out] */ int *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetFrameFactor )( 
            ILMVAddDisp * This,
            /* [in] */ int index,
            /* [in] */ int newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsLEADInputPinConnected )( 
            ILMVAddDisp * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsLEADOutputPinConnected )( 
            ILMVAddDisp * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InWidth )( 
            ILMVAddDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InHeight )( 
            ILMVAddDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutWidth )( 
            ILMVAddDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutHeight )( 
            ILMVAddDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InBits )( 
            ILMVAddDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutBits )( 
            ILMVAddDisp * This,
            /* [retval][out] */ long *pVal);
        
        END_INTERFACE
    } ILMVAddDispVtbl;

    interface ILMVAddDisp
    {
        CONST_VTBL struct ILMVAddDispVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMVAddDisp_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMVAddDisp_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMVAddDisp_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMVAddDisp_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMVAddDisp_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMVAddDisp_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMVAddDisp_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMVAddDisp_get_Enabled(This,pVal)	\
    ( (This)->lpVtbl -> get_Enabled(This,pVal) ) 

#define ILMVAddDisp_put_Enabled(This,newVal)	\
    ( (This)->lpVtbl -> put_Enabled(This,newVal) ) 

#define ILMVAddDisp_get_PreserveFrameRate(This,pVal)	\
    ( (This)->lpVtbl -> get_PreserveFrameRate(This,pVal) ) 

#define ILMVAddDisp_put_PreserveFrameRate(This,newVal)	\
    ( (This)->lpVtbl -> put_PreserveFrameRate(This,newVal) ) 

#define ILMVAddDisp_get_Average(This,pVal)	\
    ( (This)->lpVtbl -> get_Average(This,pVal) ) 

#define ILMVAddDisp_put_Average(This,newVal)	\
    ( (This)->lpVtbl -> put_Average(This,newVal) ) 

#define ILMVAddDisp_get_Frames(This,pVal)	\
    ( (This)->lpVtbl -> get_Frames(This,pVal) ) 

#define ILMVAddDisp_put_Frames(This,newVal)	\
    ( (This)->lpVtbl -> put_Frames(This,newVal) ) 

#define ILMVAddDisp_GetFrameFactor(This,index,pVal)	\
    ( (This)->lpVtbl -> GetFrameFactor(This,index,pVal) ) 

#define ILMVAddDisp_SetFrameFactor(This,index,newVal)	\
    ( (This)->lpVtbl -> SetFrameFactor(This,index,newVal) ) 

#define ILMVAddDisp_get_IsLEADInputPinConnected(This,pVal)	\
    ( (This)->lpVtbl -> get_IsLEADInputPinConnected(This,pVal) ) 

#define ILMVAddDisp_get_IsLEADOutputPinConnected(This,pVal)	\
    ( (This)->lpVtbl -> get_IsLEADOutputPinConnected(This,pVal) ) 

#define ILMVAddDisp_get_InWidth(This,pVal)	\
    ( (This)->lpVtbl -> get_InWidth(This,pVal) ) 

#define ILMVAddDisp_get_InHeight(This,pVal)	\
    ( (This)->lpVtbl -> get_InHeight(This,pVal) ) 

#define ILMVAddDisp_get_OutWidth(This,pVal)	\
    ( (This)->lpVtbl -> get_OutWidth(This,pVal) ) 

#define ILMVAddDisp_get_OutHeight(This,pVal)	\
    ( (This)->lpVtbl -> get_OutHeight(This,pVal) ) 

#define ILMVAddDisp_get_InBits(This,pVal)	\
    ( (This)->lpVtbl -> get_InBits(This,pVal) ) 

#define ILMVAddDisp_get_OutBits(This,pVal)	\
    ( (This)->lpVtbl -> get_OutBits(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMVAddDisp_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LMVAdd;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DB1F-38C5-11D5-91F6-00104BDB8FF9")
LMVAdd;
#endif
#endif /* __LMVAddLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


