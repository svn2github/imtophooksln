

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Nov 05 12:55:53 2009
 */
/* Compiler settings for .\MCMPCodec.idl:
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


#ifndef __IMCMPCodec2_h__
#define __IMCMPCodec2_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IMCMPEncoderOption_FWD_DEFINED__
#define __IMCMPEncoderOption_FWD_DEFINED__
typedef interface IMCMPEncoderOption IMCMPEncoderOption;
#endif 	/* __IMCMPEncoderOption_FWD_DEFINED__ */


#ifndef __MCMPEncoder_FWD_DEFINED__
#define __MCMPEncoder_FWD_DEFINED__

#ifdef __cplusplus
typedef class MCMPEncoder MCMPEncoder;
#else
typedef struct MCMPEncoder MCMPEncoder;
#endif /* __cplusplus */

#endif 	/* __MCMPEncoder_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __MCMPCodecLib_LIBRARY_DEFINED__
#define __MCMPCodecLib_LIBRARY_DEFINED__

/* library MCMPCodecLib */
/* [helpstring][version][uuid] */ 

#ifndef __MCMPCODEC_H__
#define __MCMPCODEC_H__
static const GUID CLSID_MCMPEncoder                 = {0xe2b7dcba, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_MCMPDecoder                 = {0xe2b7dcbb, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_MCMPEncoderPropertyPage     = {0xe2b7dcbc, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_MCMPAboutPropertyPage       = {0xe2b7dcbd, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_IMCMPEncoderOption            = {0xe2b7dcbe, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_MCMPDecoderPropertyPage     = {0xe2b7dcbf, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID LIBID_MCMPCodecLib                = {0xe2b7dcc0, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
#endif 
typedef /* [v1_enum] */ 
enum MCMPFormatConstants
    {	FORMAT_MCMP	= 5,
	FORMAT_LOSSLESSJPEG	= -1,
	FORMAT_MJPEG_411	= 21,
	FORMAT_MJPEG_422	= 23,
	FORMAT_MJPEG_444	= 10
    } 	MCMPFormatConstants;

typedef /* [v1_enum] */ 
enum MCMPPredefinedQFactorConstants
    {	QFACTOR_PQ1	= -1,
	QFACTOR_PQ2	= -2,
	QFACTOR_QFS	= -3,
	QFACTOR_QMS	= -4,
	QFACTOR_QS	= -5,
	QFACTOR_SQS	= -6,
	QFACTOR_SQT	= -7,
	QFACTOR_MCQ	= -8,
	QFACTOR_MC	= -9
    } 	MCMPPredefinedQFactorConstants;

typedef /* [v1_enum] */ 
enum MCMPFilterStateConstants
    {	FilterState_Stopped	= 0,
	FilterState_Paused	= 1,
	FilterState_Running	= 2
    } 	MCMPFilterStateConstants;


DEFINE_GUID(LIBID_MCMPCodecLib,0xe2b7dcc0,0x38c5,0x11d5,0x91,0xf6,0x00,0x10,0x4b,0xdb,0x8f,0xf9);

#ifndef __IMCMPEncoderOption_INTERFACE_DEFINED__
#define __IMCMPEncoderOption_INTERFACE_DEFINED__

/* interface IMCMPEncoderOption */
/* [unique][helpstring][dual][uuid][object] */ 


DEFINE_GUID(IID_IMCMPEncoderOption,0xe2b7dcbe,0x38c5,0x11d5,0x91,0xf6,0x00,0x10,0x4b,0xdb,0x8f,0xf9);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("e2b7dcbe-38c5-11d5-91f6-00104bdb8ff9")
    IMCMPEncoderOption : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Format( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Format( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_QFactor( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_QFactor( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Flags( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Flags( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [hidden][id][propget] */ HRESULT STDMETHODCALLTYPE get_CompFlags( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FilterState( 
            /* [retval][out] */ long *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMCMPEncoderOptionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMCMPEncoderOption * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMCMPEncoderOption * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMCMPEncoderOption * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMCMPEncoderOption * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMCMPEncoderOption * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMCMPEncoderOption * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMCMPEncoderOption * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Format )( 
            IMCMPEncoderOption * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Format )( 
            IMCMPEncoderOption * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_QFactor )( 
            IMCMPEncoderOption * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_QFactor )( 
            IMCMPEncoderOption * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Flags )( 
            IMCMPEncoderOption * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Flags )( 
            IMCMPEncoderOption * This,
            /* [in] */ long newVal);
        
        /* [hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CompFlags )( 
            IMCMPEncoderOption * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FilterState )( 
            IMCMPEncoderOption * This,
            /* [retval][out] */ long *pVal);
        
        END_INTERFACE
    } IMCMPEncoderOptionVtbl;

    interface IMCMPEncoderOption
    {
        CONST_VTBL struct IMCMPEncoderOptionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMCMPEncoderOption_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMCMPEncoderOption_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMCMPEncoderOption_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMCMPEncoderOption_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMCMPEncoderOption_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMCMPEncoderOption_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMCMPEncoderOption_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMCMPEncoderOption_get_Format(This,pVal)	\
    ( (This)->lpVtbl -> get_Format(This,pVal) ) 

#define IMCMPEncoderOption_put_Format(This,newVal)	\
    ( (This)->lpVtbl -> put_Format(This,newVal) ) 

#define IMCMPEncoderOption_get_QFactor(This,pVal)	\
    ( (This)->lpVtbl -> get_QFactor(This,pVal) ) 

#define IMCMPEncoderOption_put_QFactor(This,newVal)	\
    ( (This)->lpVtbl -> put_QFactor(This,newVal) ) 

#define IMCMPEncoderOption_get_Flags(This,pVal)	\
    ( (This)->lpVtbl -> get_Flags(This,pVal) ) 

#define IMCMPEncoderOption_put_Flags(This,newVal)	\
    ( (This)->lpVtbl -> put_Flags(This,newVal) ) 

#define IMCMPEncoderOption_get_CompFlags(This,pVal)	\
    ( (This)->lpVtbl -> get_CompFlags(This,pVal) ) 

#define IMCMPEncoderOption_get_FilterState(This,pVal)	\
    ( (This)->lpVtbl -> get_FilterState(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMCMPEncoderOption_INTERFACE_DEFINED__ */


DEFINE_GUID(CLSID_MCMPEncoder,0xe2b7dcba,0x38c5,0x11d5,0x91,0xf6,0x00,0x10,0x4b,0xdb,0x8f,0xf9);

#ifdef __cplusplus

class DECLSPEC_UUID("e2b7dcba-38c5-11d5-91f6-00104bdb8ff9")
MCMPEncoder;
#endif
#endif /* __MCMPCodecLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


