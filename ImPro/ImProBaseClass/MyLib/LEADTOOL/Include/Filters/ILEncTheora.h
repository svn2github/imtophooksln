

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Nov 05 12:53:52 2009
 */
/* Compiler settings for .\ILEncTheora.idl:
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


#ifndef __ILEncTheora_h__
#define __ILEncTheora_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILMTheoraEncoder_FWD_DEFINED__
#define __ILMTheoraEncoder_FWD_DEFINED__
typedef interface ILMTheoraEncoder ILMTheoraEncoder;
#endif 	/* __ILMTheoraEncoder_FWD_DEFINED__ */


#ifndef __LMTheoraEncoder_FWD_DEFINED__
#define __LMTheoraEncoder_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMTheoraEncoder LMTheoraEncoder;
#else
typedef struct LMTheoraEncoder LMTheoraEncoder;
#endif /* __cplusplus */

#endif 	/* __LMTheoraEncoder_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LMTheoraEncoderLib_LIBRARY_DEFINED__
#define __LMTheoraEncoderLib_LIBRARY_DEFINED__

/* library LMTheoraEncoderLib */
/* [helpstring][version][uuid] */ 

#ifndef __ILMTheoraEncoder_H__
#define __ILMTheoraEncoder_H__
static const GUID CLSID_LMTheoraEncoder                        = { 0xE2B7DF5A, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 }};
static const GUID LIBID_LMTheoraEncoderLib                     = { 0xE2B7DF59, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 }};
static const GUID CLSID_LMTheoraEncoderProperty                = { 0xE2B7DF5B, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 }};
static const GUID CLSID_LMTheoraEncoderAbout                   = { 0xE2B7DF5C, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 }};
static const GUID IID_ILMTheoraEncoder                         = { 0xE2B7DF5D, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 }};
#endif 
typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_ILEncTheora_0000_0000_0001
    {	THEORA_CONSTANT_BITRATE	= 0,
	THEORA_CONSTANT_QUALITY	= ( THEORA_CONSTANT_BITRATE + 1 ) 
    } 	eTHEORARATECONTROL;


EXTERN_C const IID LIBID_LMTheoraEncoderLib;

#ifndef __ILMTheoraEncoder_INTERFACE_DEFINED__
#define __ILMTheoraEncoder_INTERFACE_DEFINED__

/* interface ILMTheoraEncoder */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ILMTheoraEncoder;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DF5D-38C5-11D5-91F6-00104BDB8FF9")
    ILMTheoraEncoder : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteToRegistry( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadFromRegistry( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RateControlMethod( 
            /* [retval][out] */ eTHEORARATECONTROL *pRateControl) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RateControlMethod( 
            /* [in] */ eTHEORARATECONTROL RateControl) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AverageBitrate( 
            /* [retval][out] */ long *pBitrate) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AverageBitrate( 
            /* [in] */ long Bitrate) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MaxQFactor( 
            /* [retval][out] */ long *pQFactor) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MaxQFactor( 
            /* [in] */ long QFactor) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_QFactor( 
            /* [retval][out] */ long *pQFactor) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_QFactor( 
            /* [in] */ long QFactor) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_I_FrameDistance( 
            /* [retval][out] */ long *pI_FrameDistance) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_I_FrameDistance( 
            /* [in] */ long I_FrameDistance) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OutputFrameRate( 
            /* [retval][out] */ double *pFrameRate) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OutputFrameRate( 
            /* [in] */ double FrameRate) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FastCompression( 
            /* [retval][out] */ VARIANT_BOOL *pFastCompression) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FastCompression( 
            /* [in] */ VARIANT_BOOL FastCompression) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Sharpness( 
            /* [retval][out] */ long *pSharpness) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Sharpness( 
            /* [in] */ long Sharpness) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ResetToDefaults( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMTheoraEncoderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMTheoraEncoder * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMTheoraEncoder * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMTheoraEncoder * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMTheoraEncoder * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMTheoraEncoder * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMTheoraEncoder * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMTheoraEncoder * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteToRegistry )( 
            ILMTheoraEncoder * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReadFromRegistry )( 
            ILMTheoraEncoder * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RateControlMethod )( 
            ILMTheoraEncoder * This,
            /* [retval][out] */ eTHEORARATECONTROL *pRateControl);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RateControlMethod )( 
            ILMTheoraEncoder * This,
            /* [in] */ eTHEORARATECONTROL RateControl);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AverageBitrate )( 
            ILMTheoraEncoder * This,
            /* [retval][out] */ long *pBitrate);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AverageBitrate )( 
            ILMTheoraEncoder * This,
            /* [in] */ long Bitrate);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MaxQFactor )( 
            ILMTheoraEncoder * This,
            /* [retval][out] */ long *pQFactor);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MaxQFactor )( 
            ILMTheoraEncoder * This,
            /* [in] */ long QFactor);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_QFactor )( 
            ILMTheoraEncoder * This,
            /* [retval][out] */ long *pQFactor);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_QFactor )( 
            ILMTheoraEncoder * This,
            /* [in] */ long QFactor);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_I_FrameDistance )( 
            ILMTheoraEncoder * This,
            /* [retval][out] */ long *pI_FrameDistance);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_I_FrameDistance )( 
            ILMTheoraEncoder * This,
            /* [in] */ long I_FrameDistance);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutputFrameRate )( 
            ILMTheoraEncoder * This,
            /* [retval][out] */ double *pFrameRate);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OutputFrameRate )( 
            ILMTheoraEncoder * This,
            /* [in] */ double FrameRate);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FastCompression )( 
            ILMTheoraEncoder * This,
            /* [retval][out] */ VARIANT_BOOL *pFastCompression);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FastCompression )( 
            ILMTheoraEncoder * This,
            /* [in] */ VARIANT_BOOL FastCompression);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Sharpness )( 
            ILMTheoraEncoder * This,
            /* [retval][out] */ long *pSharpness);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Sharpness )( 
            ILMTheoraEncoder * This,
            /* [in] */ long Sharpness);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetToDefaults )( 
            ILMTheoraEncoder * This);
        
        END_INTERFACE
    } ILMTheoraEncoderVtbl;

    interface ILMTheoraEncoder
    {
        CONST_VTBL struct ILMTheoraEncoderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMTheoraEncoder_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMTheoraEncoder_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMTheoraEncoder_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMTheoraEncoder_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMTheoraEncoder_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMTheoraEncoder_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMTheoraEncoder_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMTheoraEncoder_WriteToRegistry(This)	\
    ( (This)->lpVtbl -> WriteToRegistry(This) ) 

#define ILMTheoraEncoder_ReadFromRegistry(This)	\
    ( (This)->lpVtbl -> ReadFromRegistry(This) ) 

#define ILMTheoraEncoder_get_RateControlMethod(This,pRateControl)	\
    ( (This)->lpVtbl -> get_RateControlMethod(This,pRateControl) ) 

#define ILMTheoraEncoder_put_RateControlMethod(This,RateControl)	\
    ( (This)->lpVtbl -> put_RateControlMethod(This,RateControl) ) 

#define ILMTheoraEncoder_get_AverageBitrate(This,pBitrate)	\
    ( (This)->lpVtbl -> get_AverageBitrate(This,pBitrate) ) 

#define ILMTheoraEncoder_put_AverageBitrate(This,Bitrate)	\
    ( (This)->lpVtbl -> put_AverageBitrate(This,Bitrate) ) 

#define ILMTheoraEncoder_get_MaxQFactor(This,pQFactor)	\
    ( (This)->lpVtbl -> get_MaxQFactor(This,pQFactor) ) 

#define ILMTheoraEncoder_put_MaxQFactor(This,QFactor)	\
    ( (This)->lpVtbl -> put_MaxQFactor(This,QFactor) ) 

#define ILMTheoraEncoder_get_QFactor(This,pQFactor)	\
    ( (This)->lpVtbl -> get_QFactor(This,pQFactor) ) 

#define ILMTheoraEncoder_put_QFactor(This,QFactor)	\
    ( (This)->lpVtbl -> put_QFactor(This,QFactor) ) 

#define ILMTheoraEncoder_get_I_FrameDistance(This,pI_FrameDistance)	\
    ( (This)->lpVtbl -> get_I_FrameDistance(This,pI_FrameDistance) ) 

#define ILMTheoraEncoder_put_I_FrameDistance(This,I_FrameDistance)	\
    ( (This)->lpVtbl -> put_I_FrameDistance(This,I_FrameDistance) ) 

#define ILMTheoraEncoder_get_OutputFrameRate(This,pFrameRate)	\
    ( (This)->lpVtbl -> get_OutputFrameRate(This,pFrameRate) ) 

#define ILMTheoraEncoder_put_OutputFrameRate(This,FrameRate)	\
    ( (This)->lpVtbl -> put_OutputFrameRate(This,FrameRate) ) 

#define ILMTheoraEncoder_get_FastCompression(This,pFastCompression)	\
    ( (This)->lpVtbl -> get_FastCompression(This,pFastCompression) ) 

#define ILMTheoraEncoder_put_FastCompression(This,FastCompression)	\
    ( (This)->lpVtbl -> put_FastCompression(This,FastCompression) ) 

#define ILMTheoraEncoder_get_Sharpness(This,pSharpness)	\
    ( (This)->lpVtbl -> get_Sharpness(This,pSharpness) ) 

#define ILMTheoraEncoder_put_Sharpness(This,Sharpness)	\
    ( (This)->lpVtbl -> put_Sharpness(This,Sharpness) ) 

#define ILMTheoraEncoder_ResetToDefaults(This)	\
    ( (This)->lpVtbl -> ResetToDefaults(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMTheoraEncoder_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LMTheoraEncoder;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DF5A-38C5-11D5-91F6-00104BDB8FF9")
LMTheoraEncoder;
#endif
#endif /* __LMTheoraEncoderLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


