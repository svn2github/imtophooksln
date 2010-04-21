

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Nov 05 12:35:26 2009
 */
/* Compiler settings for .\Encoder\Common\ILEncAMR.idl:
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


#ifndef __ILEncAMR_h__
#define __ILEncAMR_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILMAMREncoder_FWD_DEFINED__
#define __ILMAMREncoder_FWD_DEFINED__
typedef interface ILMAMREncoder ILMAMREncoder;
#endif 	/* __ILMAMREncoder_FWD_DEFINED__ */


#ifndef __LMAMREncoder_FWD_DEFINED__
#define __LMAMREncoder_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMAMREncoder LMAMREncoder;
#else
typedef struct LMAMREncoder LMAMREncoder;
#endif /* __cplusplus */

#endif 	/* __LMAMREncoder_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LMAMREncoderLib_LIBRARY_DEFINED__
#define __LMAMREncoderLib_LIBRARY_DEFINED__

/* library LMAMREncoderLib */
/* [helpstring][version][uuid] */ 

#ifndef __ILMAMRENCODER_H__
#define __ILMAMRENCODER_H__
static const GUID CLSID_LMAMREncoder             = {0xe2b7dbbf, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMAMREncoderPropertyPage	= {0xe2b7dd2e, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMAMREncoderAboutPage    = {0xe2b7dd2f, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID LIBID_LMAMREncoderLib	         = {0xe2b7dbbe, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMAMREncoder              = {0xe2b7dc54, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
#endif 
typedef 
enum eBitRate
    {	AMR_BITRATE_475	= 0,
	AMR_BITRATE_515	= 1,
	AMR_BITRATE_59	= 2,
	AMR_BITRATE_67	= 3,
	AMR_BITRATE_74	= 4,
	AMR_BITRATE_795	= 5,
	AMR_BITRATE_102	= 6,
	AMR_BITRATE_122	= 7
    } 	eBitRate;


DEFINE_GUID(LIBID_LMAMREncoderLib,0xE2B7DBBE,0x38C5,0x11D5,0x91,0xF6,0x00,0x10,0x4B,0xDB,0x8F,0xF9);

#ifndef __ILMAMREncoder_INTERFACE_DEFINED__
#define __ILMAMREncoder_INTERFACE_DEFINED__

/* interface ILMAMREncoder */
/* [unique][helpstring][uuid][local][object] */ 


DEFINE_GUID(IID_ILMAMREncoder,0xE2B7DC54,0x38C5,0x11D5,0x91,0xF6,0x00,0x10,0x4B,0xDB,0x8F,0xF9);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DC54-38C5-11D5-91F6-00104BDB8FF9")
    ILMAMREncoder : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BitRate( 
            /* [retval][out] */ eBitRate *pMode) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_BitRate( 
            /* [in] */ eBitRate lMode) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMAMREncoderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMAMREncoder * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMAMREncoder * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMAMREncoder * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMAMREncoder * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMAMREncoder * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMAMREncoder * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMAMREncoder * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BitRate )( 
            ILMAMREncoder * This,
            /* [retval][out] */ eBitRate *pMode);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BitRate )( 
            ILMAMREncoder * This,
            /* [in] */ eBitRate lMode);
        
        END_INTERFACE
    } ILMAMREncoderVtbl;

    interface ILMAMREncoder
    {
        CONST_VTBL struct ILMAMREncoderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMAMREncoder_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMAMREncoder_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMAMREncoder_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMAMREncoder_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMAMREncoder_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMAMREncoder_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMAMREncoder_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMAMREncoder_get_BitRate(This,pMode)	\
    ( (This)->lpVtbl -> get_BitRate(This,pMode) ) 

#define ILMAMREncoder_put_BitRate(This,lMode)	\
    ( (This)->lpVtbl -> put_BitRate(This,lMode) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMAMREncoder_INTERFACE_DEFINED__ */


DEFINE_GUID(CLSID_LMAMREncoder,0xE2B7DBBF,0x38C5,0x11D5,0x91,0xF6,0x00,0x10,0x4B,0xDB,0x8F,0xF9);

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DBBF-38C5-11D5-91F6-00104BDB8FF9")
LMAMREncoder;
#endif
#endif /* __LMAMREncoderLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


