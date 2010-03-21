

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Nov 05 12:39:07 2009
 */
/* Compiler settings for .\IGamma.idl:
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


#ifndef __ILMVGamma_h__
#define __ILMVGamma_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILMVGamma_FWD_DEFINED__
#define __ILMVGamma_FWD_DEFINED__
typedef interface ILMVGamma ILMVGamma;
#endif 	/* __ILMVGamma_FWD_DEFINED__ */


#ifndef __ILMVGammaDisp_FWD_DEFINED__
#define __ILMVGammaDisp_FWD_DEFINED__
typedef interface ILMVGammaDisp ILMVGammaDisp;
#endif 	/* __ILMVGammaDisp_FWD_DEFINED__ */


#ifndef __LMVGamma_FWD_DEFINED__
#define __LMVGamma_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMVGamma LMVGamma;
#else
typedef struct LMVGamma LMVGamma;
#endif /* __cplusplus */

#endif 	/* __LMVGamma_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LMVGammaLib_LIBRARY_DEFINED__
#define __LMVGammaLib_LIBRARY_DEFINED__

/* library LMVGammaLib */
/* [helpstring][version][uuid] */ 

#ifndef __IGamma_H__
#define __IGamma_H__
static const GUID CLSID_LMVGamma             = {0xe2b7db14, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVGammaPropertyPage = {0xe2b7db16, 0x38c5, 0x11d5,{ 0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMVGamma              = {0xe2b7db15, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVAboutGamma        = {0xe2b7db4c, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID LIBID_LMVGammaLib          = {0xe2b7db70, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMVGammaDisp          = {0xe2b7db71, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
enum{RGB8 = 1035,RGB24,REDCHANNEL,GREENCHANNEL,BLUECHANNEL,ALLCHANNELS};
typedef /* [public][public][public] */ struct __MIDL___MIDL_itf_IGamma_0000_0000_0001
    {
    long lGamma;
    BOOL bGammaEqualize;
    long lDGamma;
    BOOL bDGammaEqualize;
    } 	GAMMA_ATTRIBUTES;

#endif 

EXTERN_C const IID LIBID_LMVGammaLib;

#ifndef __ILMVGamma_INTERFACE_DEFINED__
#define __ILMVGamma_INTERFACE_DEFINED__

/* interface ILMVGamma */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ILMVGamma;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DB15-38C5-11D5-91F6-00104BDB8FF9")
    ILMVGamma : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE IsLEADInputPinConnected( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsLEADOutputPinConnected( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetGamma_Attributes( 
            GAMMA_ATTRIBUTES *__MIDL__ILMVGamma0000) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetGamma_Attributes( 
            GAMMA_ATTRIBUTES __MIDL__ILMVGamma0001) = 0;
        
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

    typedef struct ILMVGammaVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMVGamma * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMVGamma * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMVGamma * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsLEADInputPinConnected )( 
            ILMVGamma * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsLEADOutputPinConnected )( 
            ILMVGamma * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetGamma_Attributes )( 
            ILMVGamma * This,
            GAMMA_ATTRIBUTES *__MIDL__ILMVGamma0000);
        
        HRESULT ( STDMETHODCALLTYPE *SetGamma_Attributes )( 
            ILMVGamma * This,
            GAMMA_ATTRIBUTES __MIDL__ILMVGamma0001);
        
        HRESULT ( STDMETHODCALLTYPE *GetIODimensions )( 
            ILMVGamma * This,
            /* [out] */ long *plInWidth,
            /* [out] */ long *plInHeight,
            /* [out] */ long *plOutWidth,
            /* [out] */ long *plOutHeight);
        
        HRESULT ( STDMETHODCALLTYPE *GetIOBitCount )( 
            ILMVGamma * This,
            /* [out] */ int *plInBits,
            /* [out] */ int *plOutBits);
        
        END_INTERFACE
    } ILMVGammaVtbl;

    interface ILMVGamma
    {
        CONST_VTBL struct ILMVGammaVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMVGamma_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMVGamma_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMVGamma_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMVGamma_IsLEADInputPinConnected(This)	\
    ( (This)->lpVtbl -> IsLEADInputPinConnected(This) ) 

#define ILMVGamma_IsLEADOutputPinConnected(This)	\
    ( (This)->lpVtbl -> IsLEADOutputPinConnected(This) ) 

#define ILMVGamma_GetGamma_Attributes(This,__MIDL__ILMVGamma0000)	\
    ( (This)->lpVtbl -> GetGamma_Attributes(This,__MIDL__ILMVGamma0000) ) 

#define ILMVGamma_SetGamma_Attributes(This,__MIDL__ILMVGamma0001)	\
    ( (This)->lpVtbl -> SetGamma_Attributes(This,__MIDL__ILMVGamma0001) ) 

#define ILMVGamma_GetIODimensions(This,plInWidth,plInHeight,plOutWidth,plOutHeight)	\
    ( (This)->lpVtbl -> GetIODimensions(This,plInWidth,plInHeight,plOutWidth,plOutHeight) ) 

#define ILMVGamma_GetIOBitCount(This,plInBits,plOutBits)	\
    ( (This)->lpVtbl -> GetIOBitCount(This,plInBits,plOutBits) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMVGamma_INTERFACE_DEFINED__ */


#ifndef __ILMVGammaDisp_INTERFACE_DEFINED__
#define __ILMVGammaDisp_INTERFACE_DEFINED__

/* interface ILMVGammaDisp */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILMVGammaDisp;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DB71-38C5-11D5-91F6-00104BDB8FF9")
    ILMVGammaDisp : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EnableGammaEqualize( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_EnableGammaEqualize( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Gamma( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Gamma( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultEnableGammaEqualize( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DefaultEnableGammaEqualize( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultGamma( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DefaultGamma( 
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

    typedef struct ILMVGammaDispVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMVGammaDisp * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMVGammaDisp * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMVGammaDisp * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMVGammaDisp * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMVGammaDisp * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMVGammaDisp * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMVGammaDisp * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableGammaEqualize )( 
            ILMVGammaDisp * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableGammaEqualize )( 
            ILMVGammaDisp * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Gamma )( 
            ILMVGammaDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Gamma )( 
            ILMVGammaDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultEnableGammaEqualize )( 
            ILMVGammaDisp * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultEnableGammaEqualize )( 
            ILMVGammaDisp * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultGamma )( 
            ILMVGammaDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultGamma )( 
            ILMVGammaDisp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsLEADInputPinConnected )( 
            ILMVGammaDisp * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsLEADOutputPinConnected )( 
            ILMVGammaDisp * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InWidth )( 
            ILMVGammaDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InHeight )( 
            ILMVGammaDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutWidth )( 
            ILMVGammaDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutHeight )( 
            ILMVGammaDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InBits )( 
            ILMVGammaDisp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutBits )( 
            ILMVGammaDisp * This,
            /* [retval][out] */ long *pVal);
        
        END_INTERFACE
    } ILMVGammaDispVtbl;

    interface ILMVGammaDisp
    {
        CONST_VTBL struct ILMVGammaDispVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMVGammaDisp_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMVGammaDisp_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMVGammaDisp_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMVGammaDisp_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMVGammaDisp_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMVGammaDisp_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMVGammaDisp_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMVGammaDisp_get_EnableGammaEqualize(This,pVal)	\
    ( (This)->lpVtbl -> get_EnableGammaEqualize(This,pVal) ) 

#define ILMVGammaDisp_put_EnableGammaEqualize(This,newVal)	\
    ( (This)->lpVtbl -> put_EnableGammaEqualize(This,newVal) ) 

#define ILMVGammaDisp_get_Gamma(This,pVal)	\
    ( (This)->lpVtbl -> get_Gamma(This,pVal) ) 

#define ILMVGammaDisp_put_Gamma(This,newVal)	\
    ( (This)->lpVtbl -> put_Gamma(This,newVal) ) 

#define ILMVGammaDisp_get_DefaultEnableGammaEqualize(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultEnableGammaEqualize(This,pVal) ) 

#define ILMVGammaDisp_put_DefaultEnableGammaEqualize(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultEnableGammaEqualize(This,newVal) ) 

#define ILMVGammaDisp_get_DefaultGamma(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultGamma(This,pVal) ) 

#define ILMVGammaDisp_put_DefaultGamma(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultGamma(This,newVal) ) 

#define ILMVGammaDisp_get_IsLEADInputPinConnected(This,pVal)	\
    ( (This)->lpVtbl -> get_IsLEADInputPinConnected(This,pVal) ) 

#define ILMVGammaDisp_get_IsLEADOutputPinConnected(This,pVal)	\
    ( (This)->lpVtbl -> get_IsLEADOutputPinConnected(This,pVal) ) 

#define ILMVGammaDisp_get_InWidth(This,pVal)	\
    ( (This)->lpVtbl -> get_InWidth(This,pVal) ) 

#define ILMVGammaDisp_get_InHeight(This,pVal)	\
    ( (This)->lpVtbl -> get_InHeight(This,pVal) ) 

#define ILMVGammaDisp_get_OutWidth(This,pVal)	\
    ( (This)->lpVtbl -> get_OutWidth(This,pVal) ) 

#define ILMVGammaDisp_get_OutHeight(This,pVal)	\
    ( (This)->lpVtbl -> get_OutHeight(This,pVal) ) 

#define ILMVGammaDisp_get_InBits(This,pVal)	\
    ( (This)->lpVtbl -> get_InBits(This,pVal) ) 

#define ILMVGammaDisp_get_OutBits(This,pVal)	\
    ( (This)->lpVtbl -> get_OutBits(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMVGammaDisp_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LMVGamma;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DB14-38C5-11D5-91F6-00104BDB8FF9")
LMVGamma;
#endif
#endif /* __LMVGammaLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


