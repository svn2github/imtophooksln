

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Dec 17 17:31:15 2009
 */
/* Compiler settings for .\ILEADCommon.idl:
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

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __ILMMCommon_h__
#define __ILMMCommon_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILMMCommon1_FWD_DEFINED__
#define __ILMMCommon1_FWD_DEFINED__
typedef interface ILMMCommon1 ILMMCommon1;
#endif 	/* __ILMMCommon1_FWD_DEFINED__ */


#ifndef __ILMMCommon_FWD_DEFINED__
#define __ILMMCommon_FWD_DEFINED__
typedef interface ILMMCommon ILMMCommon;
#endif 	/* __ILMMCommon_FWD_DEFINED__ */


#ifndef __ILEADMobilePropertiesDlg_FWD_DEFINED__
#define __ILEADMobilePropertiesDlg_FWD_DEFINED__
typedef interface ILEADMobilePropertiesDlg ILEADMobilePropertiesDlg;
#endif 	/* __ILEADMobilePropertiesDlg_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_ILEADCommon_0000_0000 */
/* [local] */ 

#ifndef __LMMCOMMON_H__
#define __LMMCOMMON_H__
static const GUID IID_ILMMCommon1  = {0xe2b7dc49, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMMCommon   = {0xe2b7dd6d, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILEADMobilePropertiesDlg   = {0xE2B7DDC5, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
#endif 
typedef /* [public] */ 
enum __MIDL___MIDL_itf_ILEADCommon_0000_0000_0001
    {	AudioStream	= 0,
	VideoStream	= 1,
	TextStream	= 2
    } 	StreamType;



extern RPC_IF_HANDLE __MIDL_itf_ILEADCommon_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ILEADCommon_0000_0000_v0_0_s_ifspec;

#ifndef __ILMMCommon1_INTERFACE_DEFINED__
#define __ILMMCommon1_INTERFACE_DEFINED__

/* interface ILMMCommon1 */
/* [uuid][local][object] */ 


EXTERN_C const IID IID_ILMMCommon1;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DC49-38C5-11D5-91F6-00104BDB8FF9")
    ILMMCommon1 : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FilterName( 
            /* [out] */ BSTR *pName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ExportSettings( 
            /* [in] */ BSTR FileName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ImportSettings( 
            /* [in] */ BSTR FileName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LoadSettings( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CommitSettings( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LoadFromMemory( 
            /* [in] */ unsigned char *pMem) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteToMemory( 
            /* [in] */ unsigned char *pMem,
            /* [retval][out] */ long *lSize) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FilterState( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_InputPinsCount( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OutputPinsCount( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_InputPinName( 
            /* [in] */ long nPinIndex,
            /* [out] */ BSTR *pName) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OutputPinName( 
            /* [in] */ long nPinIndex,
            /* [out] */ BSTR *pName) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsLEADInputPinConnected( 
            /* [in] */ long nPinIndex,
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsLEADOutputPinConnected( 
            /* [in] */ long nPinIndex,
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_InputPinStreamType( 
            /* [in] */ long nPinIndex,
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OutputPinStreamType( 
            /* [in] */ long nPinIndex,
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_InWidth( 
            /* [in] */ long nPinIndex,
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_InHeight( 
            /* [in] */ long nPinIndex,
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OutWidth( 
            /* [in] */ long nPinIndex,
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OutHeight( 
            /* [in] */ long nPinIndex,
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_InBits( 
            /* [in] */ long nPinIndex,
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OutBits( 
            /* [in] */ long nPinIndex,
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_InChannels( 
            /* [in] */ long nPinIndex,
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OutChannels( 
            /* [in] */ long nPinIndex,
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_InBitsPerSample( 
            /* [in] */ long nPinIndex,
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OutBitsPerSample( 
            /* [in] */ long nPinIndex,
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_InSamplesPerSec( 
            /* [in] */ long nPinIndex,
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OutSamplesPerSec( 
            /* [in] */ long nPinIndex,
            /* [retval][out] */ long *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMMCommon1Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMMCommon1 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMMCommon1 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMMCommon1 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMMCommon1 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMMCommon1 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMMCommon1 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMMCommon1 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FilterName )( 
            ILMMCommon1 * This,
            /* [out] */ BSTR *pName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ExportSettings )( 
            ILMMCommon1 * This,
            /* [in] */ BSTR FileName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ImportSettings )( 
            ILMMCommon1 * This,
            /* [in] */ BSTR FileName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LoadSettings )( 
            ILMMCommon1 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CommitSettings )( 
            ILMMCommon1 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LoadFromMemory )( 
            ILMMCommon1 * This,
            /* [in] */ unsigned char *pMem);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteToMemory )( 
            ILMMCommon1 * This,
            /* [in] */ unsigned char *pMem,
            /* [retval][out] */ long *lSize);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FilterState )( 
            ILMMCommon1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InputPinsCount )( 
            ILMMCommon1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutputPinsCount )( 
            ILMMCommon1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InputPinName )( 
            ILMMCommon1 * This,
            /* [in] */ long nPinIndex,
            /* [out] */ BSTR *pName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutputPinName )( 
            ILMMCommon1 * This,
            /* [in] */ long nPinIndex,
            /* [out] */ BSTR *pName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsLEADInputPinConnected )( 
            ILMMCommon1 * This,
            /* [in] */ long nPinIndex,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsLEADOutputPinConnected )( 
            ILMMCommon1 * This,
            /* [in] */ long nPinIndex,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InputPinStreamType )( 
            ILMMCommon1 * This,
            /* [in] */ long nPinIndex,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutputPinStreamType )( 
            ILMMCommon1 * This,
            /* [in] */ long nPinIndex,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InWidth )( 
            ILMMCommon1 * This,
            /* [in] */ long nPinIndex,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InHeight )( 
            ILMMCommon1 * This,
            /* [in] */ long nPinIndex,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutWidth )( 
            ILMMCommon1 * This,
            /* [in] */ long nPinIndex,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutHeight )( 
            ILMMCommon1 * This,
            /* [in] */ long nPinIndex,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InBits )( 
            ILMMCommon1 * This,
            /* [in] */ long nPinIndex,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutBits )( 
            ILMMCommon1 * This,
            /* [in] */ long nPinIndex,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InChannels )( 
            ILMMCommon1 * This,
            /* [in] */ long nPinIndex,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutChannels )( 
            ILMMCommon1 * This,
            /* [in] */ long nPinIndex,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InBitsPerSample )( 
            ILMMCommon1 * This,
            /* [in] */ long nPinIndex,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutBitsPerSample )( 
            ILMMCommon1 * This,
            /* [in] */ long nPinIndex,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InSamplesPerSec )( 
            ILMMCommon1 * This,
            /* [in] */ long nPinIndex,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutSamplesPerSec )( 
            ILMMCommon1 * This,
            /* [in] */ long nPinIndex,
            /* [retval][out] */ long *pVal);
        
        END_INTERFACE
    } ILMMCommon1Vtbl;

    interface ILMMCommon1
    {
        CONST_VTBL struct ILMMCommon1Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMMCommon1_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMMCommon1_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMMCommon1_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMMCommon1_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMMCommon1_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMMCommon1_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMMCommon1_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMMCommon1_get_FilterName(This,pName)	\
    ( (This)->lpVtbl -> get_FilterName(This,pName) ) 

#define ILMMCommon1_ExportSettings(This,FileName)	\
    ( (This)->lpVtbl -> ExportSettings(This,FileName) ) 

#define ILMMCommon1_ImportSettings(This,FileName)	\
    ( (This)->lpVtbl -> ImportSettings(This,FileName) ) 

#define ILMMCommon1_LoadSettings(This)	\
    ( (This)->lpVtbl -> LoadSettings(This) ) 

#define ILMMCommon1_CommitSettings(This)	\
    ( (This)->lpVtbl -> CommitSettings(This) ) 

#define ILMMCommon1_LoadFromMemory(This,pMem)	\
    ( (This)->lpVtbl -> LoadFromMemory(This,pMem) ) 

#define ILMMCommon1_WriteToMemory(This,pMem,lSize)	\
    ( (This)->lpVtbl -> WriteToMemory(This,pMem,lSize) ) 

#define ILMMCommon1_get_FilterState(This,pVal)	\
    ( (This)->lpVtbl -> get_FilterState(This,pVal) ) 

#define ILMMCommon1_get_InputPinsCount(This,pVal)	\
    ( (This)->lpVtbl -> get_InputPinsCount(This,pVal) ) 

#define ILMMCommon1_get_OutputPinsCount(This,pVal)	\
    ( (This)->lpVtbl -> get_OutputPinsCount(This,pVal) ) 

#define ILMMCommon1_get_InputPinName(This,nPinIndex,pName)	\
    ( (This)->lpVtbl -> get_InputPinName(This,nPinIndex,pName) ) 

#define ILMMCommon1_get_OutputPinName(This,nPinIndex,pName)	\
    ( (This)->lpVtbl -> get_OutputPinName(This,nPinIndex,pName) ) 

#define ILMMCommon1_get_IsLEADInputPinConnected(This,nPinIndex,pVal)	\
    ( (This)->lpVtbl -> get_IsLEADInputPinConnected(This,nPinIndex,pVal) ) 

#define ILMMCommon1_get_IsLEADOutputPinConnected(This,nPinIndex,pVal)	\
    ( (This)->lpVtbl -> get_IsLEADOutputPinConnected(This,nPinIndex,pVal) ) 

#define ILMMCommon1_get_InputPinStreamType(This,nPinIndex,pVal)	\
    ( (This)->lpVtbl -> get_InputPinStreamType(This,nPinIndex,pVal) ) 

#define ILMMCommon1_get_OutputPinStreamType(This,nPinIndex,pVal)	\
    ( (This)->lpVtbl -> get_OutputPinStreamType(This,nPinIndex,pVal) ) 

#define ILMMCommon1_get_InWidth(This,nPinIndex,pVal)	\
    ( (This)->lpVtbl -> get_InWidth(This,nPinIndex,pVal) ) 

#define ILMMCommon1_get_InHeight(This,nPinIndex,pVal)	\
    ( (This)->lpVtbl -> get_InHeight(This,nPinIndex,pVal) ) 

#define ILMMCommon1_get_OutWidth(This,nPinIndex,pVal)	\
    ( (This)->lpVtbl -> get_OutWidth(This,nPinIndex,pVal) ) 

#define ILMMCommon1_get_OutHeight(This,nPinIndex,pVal)	\
    ( (This)->lpVtbl -> get_OutHeight(This,nPinIndex,pVal) ) 

#define ILMMCommon1_get_InBits(This,nPinIndex,pVal)	\
    ( (This)->lpVtbl -> get_InBits(This,nPinIndex,pVal) ) 

#define ILMMCommon1_get_OutBits(This,nPinIndex,pVal)	\
    ( (This)->lpVtbl -> get_OutBits(This,nPinIndex,pVal) ) 

#define ILMMCommon1_get_InChannels(This,nPinIndex,pVal)	\
    ( (This)->lpVtbl -> get_InChannels(This,nPinIndex,pVal) ) 

#define ILMMCommon1_get_OutChannels(This,nPinIndex,pVal)	\
    ( (This)->lpVtbl -> get_OutChannels(This,nPinIndex,pVal) ) 

#define ILMMCommon1_get_InBitsPerSample(This,nPinIndex,pVal)	\
    ( (This)->lpVtbl -> get_InBitsPerSample(This,nPinIndex,pVal) ) 

#define ILMMCommon1_get_OutBitsPerSample(This,nPinIndex,pVal)	\
    ( (This)->lpVtbl -> get_OutBitsPerSample(This,nPinIndex,pVal) ) 

#define ILMMCommon1_get_InSamplesPerSec(This,nPinIndex,pVal)	\
    ( (This)->lpVtbl -> get_InSamplesPerSec(This,nPinIndex,pVal) ) 

#define ILMMCommon1_get_OutSamplesPerSec(This,nPinIndex,pVal)	\
    ( (This)->lpVtbl -> get_OutSamplesPerSec(This,nPinIndex,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMMCommon1_INTERFACE_DEFINED__ */


#ifndef __ILMMCommon_INTERFACE_DEFINED__
#define __ILMMCommon_INTERFACE_DEFINED__

/* interface ILMMCommon */
/* [uuid][local][object] */ 


EXTERN_C const IID IID_ILMMCommon;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DD6D-38C5-11D5-91F6-00104BDB8FF9")
    ILMMCommon : public ILMMCommon1
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_InputAspectRatioX( 
            long nPinIndex,
            long *AspectRatioX) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_InputAspectRatioY( 
            long nPinIndex,
            long *AspectRatioY) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_InputPinStreamSubType( 
            /* [in] */ long nPinIndex,
            /* [retval][out] */ BSTR *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMMCommonVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMMCommon * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMMCommon * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMMCommon * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMMCommon * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMMCommon * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMMCommon * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMMCommon * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FilterName )( 
            ILMMCommon * This,
            /* [out] */ BSTR *pName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ExportSettings )( 
            ILMMCommon * This,
            /* [in] */ BSTR FileName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ImportSettings )( 
            ILMMCommon * This,
            /* [in] */ BSTR FileName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LoadSettings )( 
            ILMMCommon * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CommitSettings )( 
            ILMMCommon * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LoadFromMemory )( 
            ILMMCommon * This,
            /* [in] */ unsigned char *pMem);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteToMemory )( 
            ILMMCommon * This,
            /* [in] */ unsigned char *pMem,
            /* [retval][out] */ long *lSize);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FilterState )( 
            ILMMCommon * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InputPinsCount )( 
            ILMMCommon * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutputPinsCount )( 
            ILMMCommon * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InputPinName )( 
            ILMMCommon * This,
            /* [in] */ long nPinIndex,
            /* [out] */ BSTR *pName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutputPinName )( 
            ILMMCommon * This,
            /* [in] */ long nPinIndex,
            /* [out] */ BSTR *pName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsLEADInputPinConnected )( 
            ILMMCommon * This,
            /* [in] */ long nPinIndex,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsLEADOutputPinConnected )( 
            ILMMCommon * This,
            /* [in] */ long nPinIndex,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InputPinStreamType )( 
            ILMMCommon * This,
            /* [in] */ long nPinIndex,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutputPinStreamType )( 
            ILMMCommon * This,
            /* [in] */ long nPinIndex,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InWidth )( 
            ILMMCommon * This,
            /* [in] */ long nPinIndex,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InHeight )( 
            ILMMCommon * This,
            /* [in] */ long nPinIndex,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutWidth )( 
            ILMMCommon * This,
            /* [in] */ long nPinIndex,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutHeight )( 
            ILMMCommon * This,
            /* [in] */ long nPinIndex,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InBits )( 
            ILMMCommon * This,
            /* [in] */ long nPinIndex,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutBits )( 
            ILMMCommon * This,
            /* [in] */ long nPinIndex,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InChannels )( 
            ILMMCommon * This,
            /* [in] */ long nPinIndex,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutChannels )( 
            ILMMCommon * This,
            /* [in] */ long nPinIndex,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InBitsPerSample )( 
            ILMMCommon * This,
            /* [in] */ long nPinIndex,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutBitsPerSample )( 
            ILMMCommon * This,
            /* [in] */ long nPinIndex,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InSamplesPerSec )( 
            ILMMCommon * This,
            /* [in] */ long nPinIndex,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutSamplesPerSec )( 
            ILMMCommon * This,
            /* [in] */ long nPinIndex,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InputAspectRatioX )( 
            ILMMCommon * This,
            long nPinIndex,
            long *AspectRatioX);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InputAspectRatioY )( 
            ILMMCommon * This,
            long nPinIndex,
            long *AspectRatioY);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InputPinStreamSubType )( 
            ILMMCommon * This,
            /* [in] */ long nPinIndex,
            /* [retval][out] */ BSTR *pVal);
        
        END_INTERFACE
    } ILMMCommonVtbl;

    interface ILMMCommon
    {
        CONST_VTBL struct ILMMCommonVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMMCommon_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMMCommon_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMMCommon_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMMCommon_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMMCommon_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMMCommon_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMMCommon_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMMCommon_get_FilterName(This,pName)	\
    ( (This)->lpVtbl -> get_FilterName(This,pName) ) 

#define ILMMCommon_ExportSettings(This,FileName)	\
    ( (This)->lpVtbl -> ExportSettings(This,FileName) ) 

#define ILMMCommon_ImportSettings(This,FileName)	\
    ( (This)->lpVtbl -> ImportSettings(This,FileName) ) 

#define ILMMCommon_LoadSettings(This)	\
    ( (This)->lpVtbl -> LoadSettings(This) ) 

#define ILMMCommon_CommitSettings(This)	\
    ( (This)->lpVtbl -> CommitSettings(This) ) 

#define ILMMCommon_LoadFromMemory(This,pMem)	\
    ( (This)->lpVtbl -> LoadFromMemory(This,pMem) ) 

#define ILMMCommon_WriteToMemory(This,pMem,lSize)	\
    ( (This)->lpVtbl -> WriteToMemory(This,pMem,lSize) ) 

#define ILMMCommon_get_FilterState(This,pVal)	\
    ( (This)->lpVtbl -> get_FilterState(This,pVal) ) 

#define ILMMCommon_get_InputPinsCount(This,pVal)	\
    ( (This)->lpVtbl -> get_InputPinsCount(This,pVal) ) 

#define ILMMCommon_get_OutputPinsCount(This,pVal)	\
    ( (This)->lpVtbl -> get_OutputPinsCount(This,pVal) ) 

#define ILMMCommon_get_InputPinName(This,nPinIndex,pName)	\
    ( (This)->lpVtbl -> get_InputPinName(This,nPinIndex,pName) ) 

#define ILMMCommon_get_OutputPinName(This,nPinIndex,pName)	\
    ( (This)->lpVtbl -> get_OutputPinName(This,nPinIndex,pName) ) 

#define ILMMCommon_get_IsLEADInputPinConnected(This,nPinIndex,pVal)	\
    ( (This)->lpVtbl -> get_IsLEADInputPinConnected(This,nPinIndex,pVal) ) 

#define ILMMCommon_get_IsLEADOutputPinConnected(This,nPinIndex,pVal)	\
    ( (This)->lpVtbl -> get_IsLEADOutputPinConnected(This,nPinIndex,pVal) ) 

#define ILMMCommon_get_InputPinStreamType(This,nPinIndex,pVal)	\
    ( (This)->lpVtbl -> get_InputPinStreamType(This,nPinIndex,pVal) ) 

#define ILMMCommon_get_OutputPinStreamType(This,nPinIndex,pVal)	\
    ( (This)->lpVtbl -> get_OutputPinStreamType(This,nPinIndex,pVal) ) 

#define ILMMCommon_get_InWidth(This,nPinIndex,pVal)	\
    ( (This)->lpVtbl -> get_InWidth(This,nPinIndex,pVal) ) 

#define ILMMCommon_get_InHeight(This,nPinIndex,pVal)	\
    ( (This)->lpVtbl -> get_InHeight(This,nPinIndex,pVal) ) 

#define ILMMCommon_get_OutWidth(This,nPinIndex,pVal)	\
    ( (This)->lpVtbl -> get_OutWidth(This,nPinIndex,pVal) ) 

#define ILMMCommon_get_OutHeight(This,nPinIndex,pVal)	\
    ( (This)->lpVtbl -> get_OutHeight(This,nPinIndex,pVal) ) 

#define ILMMCommon_get_InBits(This,nPinIndex,pVal)	\
    ( (This)->lpVtbl -> get_InBits(This,nPinIndex,pVal) ) 

#define ILMMCommon_get_OutBits(This,nPinIndex,pVal)	\
    ( (This)->lpVtbl -> get_OutBits(This,nPinIndex,pVal) ) 

#define ILMMCommon_get_InChannels(This,nPinIndex,pVal)	\
    ( (This)->lpVtbl -> get_InChannels(This,nPinIndex,pVal) ) 

#define ILMMCommon_get_OutChannels(This,nPinIndex,pVal)	\
    ( (This)->lpVtbl -> get_OutChannels(This,nPinIndex,pVal) ) 

#define ILMMCommon_get_InBitsPerSample(This,nPinIndex,pVal)	\
    ( (This)->lpVtbl -> get_InBitsPerSample(This,nPinIndex,pVal) ) 

#define ILMMCommon_get_OutBitsPerSample(This,nPinIndex,pVal)	\
    ( (This)->lpVtbl -> get_OutBitsPerSample(This,nPinIndex,pVal) ) 

#define ILMMCommon_get_InSamplesPerSec(This,nPinIndex,pVal)	\
    ( (This)->lpVtbl -> get_InSamplesPerSec(This,nPinIndex,pVal) ) 

#define ILMMCommon_get_OutSamplesPerSec(This,nPinIndex,pVal)	\
    ( (This)->lpVtbl -> get_OutSamplesPerSec(This,nPinIndex,pVal) ) 


#define ILMMCommon_get_InputAspectRatioX(This,nPinIndex,AspectRatioX)	\
    ( (This)->lpVtbl -> get_InputAspectRatioX(This,nPinIndex,AspectRatioX) ) 

#define ILMMCommon_get_InputAspectRatioY(This,nPinIndex,AspectRatioY)	\
    ( (This)->lpVtbl -> get_InputAspectRatioY(This,nPinIndex,AspectRatioY) ) 

#define ILMMCommon_get_InputPinStreamSubType(This,nPinIndex,pVal)	\
    ( (This)->lpVtbl -> get_InputPinStreamSubType(This,nPinIndex,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMMCommon_INTERFACE_DEFINED__ */


#ifndef __ILEADMobilePropertiesDlg_INTERFACE_DEFINED__
#define __ILEADMobilePropertiesDlg_INTERFACE_DEFINED__

/* interface ILEADMobilePropertiesDlg */
/* [uuid][local][object] */ 


EXTERN_C const IID IID_ILEADMobilePropertiesDlg;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DDC5-38C5-11D5-91F6-00104BDB8FF9")
    ILEADMobilePropertiesDlg : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ShowDialog( 
            long hWnd) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILEADMobilePropertiesDlgVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILEADMobilePropertiesDlg * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILEADMobilePropertiesDlg * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILEADMobilePropertiesDlg * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILEADMobilePropertiesDlg * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILEADMobilePropertiesDlg * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILEADMobilePropertiesDlg * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILEADMobilePropertiesDlg * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ShowDialog )( 
            ILEADMobilePropertiesDlg * This,
            long hWnd);
        
        END_INTERFACE
    } ILEADMobilePropertiesDlgVtbl;

    interface ILEADMobilePropertiesDlg
    {
        CONST_VTBL struct ILEADMobilePropertiesDlgVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILEADMobilePropertiesDlg_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILEADMobilePropertiesDlg_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILEADMobilePropertiesDlg_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILEADMobilePropertiesDlg_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILEADMobilePropertiesDlg_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILEADMobilePropertiesDlg_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILEADMobilePropertiesDlg_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILEADMobilePropertiesDlg_ShowDialog(This,hWnd)	\
    ( (This)->lpVtbl -> ShowDialog(This,hWnd) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILEADMobilePropertiesDlg_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


