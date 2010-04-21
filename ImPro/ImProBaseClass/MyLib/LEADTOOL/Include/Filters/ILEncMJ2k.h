

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Nov 05 12:44:17 2009
 */
/* Compiler settings for .\ILEncJ2k.idl:
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


#ifndef __ILEncMJ2k_h__
#define __ILEncMJ2k_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILMMJ2KEncoder_FWD_DEFINED__
#define __ILMMJ2KEncoder_FWD_DEFINED__
typedef interface ILMMJ2KEncoder ILMMJ2KEncoder;
#endif 	/* __ILMMJ2KEncoder_FWD_DEFINED__ */


#ifndef __LMMJ2KEncoder_FWD_DEFINED__
#define __LMMJ2KEncoder_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMMJ2KEncoder LMMJ2KEncoder;
#else
typedef struct LMMJ2KEncoder LMMJ2KEncoder;
#endif /* __cplusplus */

#endif 	/* __LMMJ2KEncoder_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LMMJ2KEncoderLib_LIBRARY_DEFINED__
#define __LMMJ2KEncoderLib_LIBRARY_DEFINED__

/* library LMMJ2KEncoderLib */
/* [helpstring][version][uuid] */ 

#ifndef __ILMMJ2KENCODER_H__
#define __ILMMJ2KENCODER_H__
static const GUID  IID_ILMMJ2KEncoder            = { 0xe2b7df05, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 }};
static const GUID LIBID_LMMJ2KEncoderLib         = { 0xe2b7df06, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 }};
static const GUID CLSID_LMJ2KEncoder             = { 0xe2b7dcd2, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 }};
static const GUID CLSID_LMJ2KDecoder             = { 0xe2b7dcd3, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 }};
static const GUID CLSID_LMJ2KEncoderPropertyPage = { 0xe2b7dcd6, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 }};
static const GUID CLSID_LMJ2KDecoderPropertyPage = { 0xe2b7dcd7, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 }};
#endif 
typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_ILEncJ2k_0000_0000_0001
    {	PerfectQuality_1	= 18,
	PerfectQuality_2	= 24,
	QualityFarMoreImportantThanSize	= 30,
	QualityMoreImportantThanSize	= 40,
	QualityAndSizeAreEquallyImportant	= 55,
	SizeMoreImportantThanQuality_1	= 70,
	SizeMoreImportantThanQuality_2	= 90,
	HighCompressionKeepQuality	= 110,
	HighCompression	= 140,
	HighcompressionFast	= 180,
	HypercompressionFast	= 220,
	Custom	= 18
    } 	MJ2KQUALITYFACTOR;


EXTERN_C const IID LIBID_LMMJ2KEncoderLib;

#ifndef __ILMMJ2KEncoder_INTERFACE_DEFINED__
#define __ILMMJ2KEncoder_INTERFACE_DEFINED__

/* interface ILMMJ2KEncoder */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ILMMJ2KEncoder;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DF05-38C5-11D5-91F6-00104BDB8FF9")
    ILMMJ2KEncoder : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_QualityFactor( 
            /* [retval][out] */ MJ2KQUALITYFACTOR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_QualityFactor( 
            /* [in] */ MJ2KQUALITYFACTOR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CompressionRatio( 
            /* [retval][out] */ DWORD *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CompressionRatio( 
            /* [in] */ DWORD newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AvgTimePerFrame( 
            /* [retval][out] */ DWORD *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FrameWidth( 
            /* [retval][out] */ DWORD *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FrameHeight( 
            /* [retval][out] */ DWORD *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BitsPerPixel( 
            /* [retval][out] */ DWORD *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMMJ2KEncoderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMMJ2KEncoder * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMMJ2KEncoder * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMMJ2KEncoder * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMMJ2KEncoder * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMMJ2KEncoder * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMMJ2KEncoder * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMMJ2KEncoder * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_QualityFactor )( 
            ILMMJ2KEncoder * This,
            /* [retval][out] */ MJ2KQUALITYFACTOR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_QualityFactor )( 
            ILMMJ2KEncoder * This,
            /* [in] */ MJ2KQUALITYFACTOR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CompressionRatio )( 
            ILMMJ2KEncoder * This,
            /* [retval][out] */ DWORD *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CompressionRatio )( 
            ILMMJ2KEncoder * This,
            /* [in] */ DWORD newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AvgTimePerFrame )( 
            ILMMJ2KEncoder * This,
            /* [retval][out] */ DWORD *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FrameWidth )( 
            ILMMJ2KEncoder * This,
            /* [retval][out] */ DWORD *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FrameHeight )( 
            ILMMJ2KEncoder * This,
            /* [retval][out] */ DWORD *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BitsPerPixel )( 
            ILMMJ2KEncoder * This,
            /* [retval][out] */ DWORD *pVal);
        
        END_INTERFACE
    } ILMMJ2KEncoderVtbl;

    interface ILMMJ2KEncoder
    {
        CONST_VTBL struct ILMMJ2KEncoderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMMJ2KEncoder_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMMJ2KEncoder_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMMJ2KEncoder_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMMJ2KEncoder_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMMJ2KEncoder_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMMJ2KEncoder_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMMJ2KEncoder_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMMJ2KEncoder_get_QualityFactor(This,pVal)	\
    ( (This)->lpVtbl -> get_QualityFactor(This,pVal) ) 

#define ILMMJ2KEncoder_put_QualityFactor(This,newVal)	\
    ( (This)->lpVtbl -> put_QualityFactor(This,newVal) ) 

#define ILMMJ2KEncoder_get_CompressionRatio(This,pVal)	\
    ( (This)->lpVtbl -> get_CompressionRatio(This,pVal) ) 

#define ILMMJ2KEncoder_put_CompressionRatio(This,newVal)	\
    ( (This)->lpVtbl -> put_CompressionRatio(This,newVal) ) 

#define ILMMJ2KEncoder_get_AvgTimePerFrame(This,pVal)	\
    ( (This)->lpVtbl -> get_AvgTimePerFrame(This,pVal) ) 

#define ILMMJ2KEncoder_get_FrameWidth(This,pVal)	\
    ( (This)->lpVtbl -> get_FrameWidth(This,pVal) ) 

#define ILMMJ2KEncoder_get_FrameHeight(This,pVal)	\
    ( (This)->lpVtbl -> get_FrameHeight(This,pVal) ) 

#define ILMMJ2KEncoder_get_BitsPerPixel(This,pVal)	\
    ( (This)->lpVtbl -> get_BitsPerPixel(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMMJ2KEncoder_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LMMJ2KEncoder;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DCD2-38C5-11D5-91F6-00104BDB8FF9")
LMMJ2KEncoder;
#endif
#endif /* __LMMJ2KEncoderLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


