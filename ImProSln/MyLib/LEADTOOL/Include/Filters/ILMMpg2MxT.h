

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Nov 05 12:55:42 2009
 */
/* Compiler settings for .\mpeg2mux.idl:
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


#ifndef __ILMMpg2MxT_h__
#define __ILMMpg2MxT_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILMKlvBuilder_FWD_DEFINED__
#define __ILMKlvBuilder_FWD_DEFINED__
typedef interface ILMKlvBuilder ILMKlvBuilder;
#endif 	/* __ILMKlvBuilder_FWD_DEFINED__ */


#ifndef __ILMMpg2MxT_FWD_DEFINED__
#define __ILMMpg2MxT_FWD_DEFINED__
typedef interface ILMMpg2MxT ILMMpg2MxT;
#endif 	/* __ILMMpg2MxT_FWD_DEFINED__ */


#ifndef __LMMpg2MxT_FWD_DEFINED__
#define __LMMpg2MxT_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMMpg2MxT LMMpg2MxT;
#else
typedef struct LMMpg2MxT LMMpg2MxT;
#endif /* __cplusplus */

#endif 	/* __LMMpg2MxT_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LMMpg2MxTLib_LIBRARY_DEFINED__
#define __LMMpg2MxTLib_LIBRARY_DEFINED__

/* library LMMpg2MxTLib */
/* [helpstring][version][uuid] */ 

#ifndef __LMMpg2MxT_GUID__
#define __LMMpg2MxT_GUID__
static const IID LIBID_LMMpg2MxTLib = { 0xe2b7df32, 0x38c5, 0x11d5, { 0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 }};
static const IID IID_ILMMpg2MxT = { 0xe2b7df31, 0x38c5, 0x11d5, { 0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 }};
static const CLSID CLSID_LMMpg2MxT = { 0xe2b7df2f, 0x38c5, 0x11d5, { 0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 }};
static const IID IID_ILMKlvBuilder = { 0xe2b7df6a, 0x38c5, 0x11d5, { 0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 }};
#endif 
typedef 
enum Mpg2MxT_OutputType
    {	Mpg2MxT_OutputType_Default	= 0,
	Mpg2MxT_OutputType_Broadcast	= 0x1
    } 	Mpg2MxT_OutputType;

typedef 
enum Mpg2MxT_WriteFlag
    {	Mpg2MxT_WriteFlag_PTSValid	= 0x1,
	Mpg2MxT_WriteFlag_PTSInSeconds	= 0x2,
	Mpg2MxT_WriteFlag_UseStreamPTS	= 0x4,
	Mpg2MxT_WriteFlag_SyncPoint	= 0x8,
	Mpg2MxT_WriteFlag_Discontinuity	= 0x10
    } 	Mpg2MxT_WriteFlags;

typedef 
enum Mpg2MxT_StreamPTS
    {	Mpg2MxT_StreamPTS_InSeconds	= 0x1
    } 	Mpg2MxT_StreamPTS;

typedef 
enum Mpg2MxT_Errors
    {	Mpg2MxT_E_KEY_NOT_FOUND	= 0x80050010,
	Mpg2MxT_E_BAD_KEY	= 0x80050011
    } 	Mpg2MxT_Errors;

typedef 
enum Mpg2MxT_SearchKey
    {	Mpg2MxT_SearchKey_Exact	= 1,
	Mpg2MxT_SearchKey_AnyVersion	= 2,
	Mpg2MxT_SearchKey_DesignatorOnly	= 3
    } 	Mpg2MxT_SearchKey;


DEFINE_GUID(LIBID_LMMpg2MxTLib,0xE2B7DF32,0x38C5,0x11D5,0x91,0xF6,0x00,0x10,0x4B,0xDB,0x8F,0xF9);

#ifndef __ILMKlvBuilder_INTERFACE_DEFINED__
#define __ILMKlvBuilder_INTERFACE_DEFINED__

/* interface ILMKlvBuilder */
/* [unique][helpstring][dual][uuid][object] */ 


DEFINE_GUID(IID_ILMKlvBuilder,0xE2B7DF6A,0x38C5,0x11D5,0x91,0xF6,0x00,0x10,0x4B,0xDB,0x8F,0xF9);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DF6A-38C5-11D5-91F6-00104BDB8FF9")
    ILMKlvBuilder : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddData( 
            /* [in] */ VARIANT Data,
            /* [in] */ long DataLength) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetKey( 
            /* [in] */ long keyIndex,
            /* [out] */ VARIANT *pKey,
            /* [out] */ VARIANT *pKeyData,
            /* [out] */ long *pDataSize) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetKey( 
            /* [in] */ long keyIndex,
            /* [in] */ VARIANT Key,
            /* [in] */ VARIANT KeyData,
            /* [in] */ long DataSize) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InsertKey( 
            /* [in] */ long keyIndex,
            /* [in] */ VARIANT Key,
            /* [in] */ VARIANT KeyData,
            /* [in] */ long DataSize) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteKey( 
            /* [in] */ long keyIndex) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetData( 
            /* [retval][out] */ VARIANT *pData) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FindKey( 
            /* [in] */ VARIANT KeyToFind,
            /* [in] */ long searchFlags,
            /* [retval][out] */ long *pkeyIndex) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateSubBuilder( 
            /* [in] */ VARIANT BaseKey,
            /* [retval][out] */ ILMKlvBuilder **pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMKlvBuilderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMKlvBuilder * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMKlvBuilder * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMKlvBuilder * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMKlvBuilder * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMKlvBuilder * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMKlvBuilder * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMKlvBuilder * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Clear )( 
            ILMKlvBuilder * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddData )( 
            ILMKlvBuilder * This,
            /* [in] */ VARIANT Data,
            /* [in] */ long DataLength);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            ILMKlvBuilder * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetKey )( 
            ILMKlvBuilder * This,
            /* [in] */ long keyIndex,
            /* [out] */ VARIANT *pKey,
            /* [out] */ VARIANT *pKeyData,
            /* [out] */ long *pDataSize);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetKey )( 
            ILMKlvBuilder * This,
            /* [in] */ long keyIndex,
            /* [in] */ VARIANT Key,
            /* [in] */ VARIANT KeyData,
            /* [in] */ long DataSize);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InsertKey )( 
            ILMKlvBuilder * This,
            /* [in] */ long keyIndex,
            /* [in] */ VARIANT Key,
            /* [in] */ VARIANT KeyData,
            /* [in] */ long DataSize);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteKey )( 
            ILMKlvBuilder * This,
            /* [in] */ long keyIndex);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetData )( 
            ILMKlvBuilder * This,
            /* [retval][out] */ VARIANT *pData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FindKey )( 
            ILMKlvBuilder * This,
            /* [in] */ VARIANT KeyToFind,
            /* [in] */ long searchFlags,
            /* [retval][out] */ long *pkeyIndex);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateSubBuilder )( 
            ILMKlvBuilder * This,
            /* [in] */ VARIANT BaseKey,
            /* [retval][out] */ ILMKlvBuilder **pVal);
        
        END_INTERFACE
    } ILMKlvBuilderVtbl;

    interface ILMKlvBuilder
    {
        CONST_VTBL struct ILMKlvBuilderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMKlvBuilder_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMKlvBuilder_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMKlvBuilder_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMKlvBuilder_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMKlvBuilder_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMKlvBuilder_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMKlvBuilder_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMKlvBuilder_Clear(This)	\
    ( (This)->lpVtbl -> Clear(This) ) 

#define ILMKlvBuilder_AddData(This,Data,DataLength)	\
    ( (This)->lpVtbl -> AddData(This,Data,DataLength) ) 

#define ILMKlvBuilder_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#define ILMKlvBuilder_GetKey(This,keyIndex,pKey,pKeyData,pDataSize)	\
    ( (This)->lpVtbl -> GetKey(This,keyIndex,pKey,pKeyData,pDataSize) ) 

#define ILMKlvBuilder_SetKey(This,keyIndex,Key,KeyData,DataSize)	\
    ( (This)->lpVtbl -> SetKey(This,keyIndex,Key,KeyData,DataSize) ) 

#define ILMKlvBuilder_InsertKey(This,keyIndex,Key,KeyData,DataSize)	\
    ( (This)->lpVtbl -> InsertKey(This,keyIndex,Key,KeyData,DataSize) ) 

#define ILMKlvBuilder_DeleteKey(This,keyIndex)	\
    ( (This)->lpVtbl -> DeleteKey(This,keyIndex) ) 

#define ILMKlvBuilder_GetData(This,pData)	\
    ( (This)->lpVtbl -> GetData(This,pData) ) 

#define ILMKlvBuilder_FindKey(This,KeyToFind,searchFlags,pkeyIndex)	\
    ( (This)->lpVtbl -> FindKey(This,KeyToFind,searchFlags,pkeyIndex) ) 

#define ILMKlvBuilder_CreateSubBuilder(This,BaseKey,pVal)	\
    ( (This)->lpVtbl -> CreateSubBuilder(This,BaseKey,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMKlvBuilder_INTERFACE_DEFINED__ */


#ifndef __ILMMpg2MxT_INTERFACE_DEFINED__
#define __ILMMpg2MxT_INTERFACE_DEFINED__

/* interface ILMMpg2MxT */
/* [unique][helpstring][dual][uuid][object] */ 


DEFINE_GUID(IID_ILMMpg2MxT,0xE2B7DF31,0x38C5,0x11D5,0x91,0xF6,0x00,0x10,0x4B,0xDB,0x8F,0xF9);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DF31-38C5-11D5-91F6-00104BDB8FF9")
    ILMMpg2MxT : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OutputType( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OutputType( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EnablePrivateData( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_EnablePrivateData( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PrivateDataPID( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PrivateDataPID( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PrivateDataFormatID( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PrivateDataFormatID( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPrivateDataFormatInfo( 
            /* [retval][out] */ VARIANT *pInfo) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetPrivateDataFormatInfo( 
            /* [in] */ VARIANT Info,
            /* [in] */ long InfoLength) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WritePrivateData( 
            /* [in] */ long Flags,
            /* [in] */ double PTS,
            /* [in] */ VARIANT Data,
            /* [in] */ long DataLength) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_KlvBuilder( 
            /* [retval][out] */ ILMKlvBuilder **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetStreamPTS( 
            /* [in] */ long Flags,
            /* [retval][out] */ double *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsEndOfStream( 
            /* [retval][out] */ VARIANT_BOOL *pBal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ClosePrivateData( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AutoClosePrivateData( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AutoClosePrivateData( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ResyncInterval( 
            /* [retval][out] */ double *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ResyncInterval( 
            /* [in] */ double newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMMpg2MxTVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMMpg2MxT * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMMpg2MxT * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMMpg2MxT * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMMpg2MxT * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMMpg2MxT * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMMpg2MxT * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMMpg2MxT * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutputType )( 
            ILMMpg2MxT * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OutputType )( 
            ILMMpg2MxT * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnablePrivateData )( 
            ILMMpg2MxT * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnablePrivateData )( 
            ILMMpg2MxT * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PrivateDataPID )( 
            ILMMpg2MxT * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PrivateDataPID )( 
            ILMMpg2MxT * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PrivateDataFormatID )( 
            ILMMpg2MxT * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PrivateDataFormatID )( 
            ILMMpg2MxT * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPrivateDataFormatInfo )( 
            ILMMpg2MxT * This,
            /* [retval][out] */ VARIANT *pInfo);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetPrivateDataFormatInfo )( 
            ILMMpg2MxT * This,
            /* [in] */ VARIANT Info,
            /* [in] */ long InfoLength);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WritePrivateData )( 
            ILMMpg2MxT * This,
            /* [in] */ long Flags,
            /* [in] */ double PTS,
            /* [in] */ VARIANT Data,
            /* [in] */ long DataLength);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_KlvBuilder )( 
            ILMMpg2MxT * This,
            /* [retval][out] */ ILMKlvBuilder **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetStreamPTS )( 
            ILMMpg2MxT * This,
            /* [in] */ long Flags,
            /* [retval][out] */ double *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsEndOfStream )( 
            ILMMpg2MxT * This,
            /* [retval][out] */ VARIANT_BOOL *pBal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClosePrivateData )( 
            ILMMpg2MxT * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AutoClosePrivateData )( 
            ILMMpg2MxT * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AutoClosePrivateData )( 
            ILMMpg2MxT * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ResyncInterval )( 
            ILMMpg2MxT * This,
            /* [retval][out] */ double *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ResyncInterval )( 
            ILMMpg2MxT * This,
            /* [in] */ double newVal);
        
        END_INTERFACE
    } ILMMpg2MxTVtbl;

    interface ILMMpg2MxT
    {
        CONST_VTBL struct ILMMpg2MxTVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMMpg2MxT_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMMpg2MxT_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMMpg2MxT_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMMpg2MxT_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMMpg2MxT_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMMpg2MxT_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMMpg2MxT_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMMpg2MxT_get_OutputType(This,pVal)	\
    ( (This)->lpVtbl -> get_OutputType(This,pVal) ) 

#define ILMMpg2MxT_put_OutputType(This,newVal)	\
    ( (This)->lpVtbl -> put_OutputType(This,newVal) ) 

#define ILMMpg2MxT_get_EnablePrivateData(This,pVal)	\
    ( (This)->lpVtbl -> get_EnablePrivateData(This,pVal) ) 

#define ILMMpg2MxT_put_EnablePrivateData(This,newVal)	\
    ( (This)->lpVtbl -> put_EnablePrivateData(This,newVal) ) 

#define ILMMpg2MxT_get_PrivateDataPID(This,pVal)	\
    ( (This)->lpVtbl -> get_PrivateDataPID(This,pVal) ) 

#define ILMMpg2MxT_put_PrivateDataPID(This,newVal)	\
    ( (This)->lpVtbl -> put_PrivateDataPID(This,newVal) ) 

#define ILMMpg2MxT_get_PrivateDataFormatID(This,pVal)	\
    ( (This)->lpVtbl -> get_PrivateDataFormatID(This,pVal) ) 

#define ILMMpg2MxT_put_PrivateDataFormatID(This,newVal)	\
    ( (This)->lpVtbl -> put_PrivateDataFormatID(This,newVal) ) 

#define ILMMpg2MxT_GetPrivateDataFormatInfo(This,pInfo)	\
    ( (This)->lpVtbl -> GetPrivateDataFormatInfo(This,pInfo) ) 

#define ILMMpg2MxT_SetPrivateDataFormatInfo(This,Info,InfoLength)	\
    ( (This)->lpVtbl -> SetPrivateDataFormatInfo(This,Info,InfoLength) ) 

#define ILMMpg2MxT_WritePrivateData(This,Flags,PTS,Data,DataLength)	\
    ( (This)->lpVtbl -> WritePrivateData(This,Flags,PTS,Data,DataLength) ) 

#define ILMMpg2MxT_get_KlvBuilder(This,pVal)	\
    ( (This)->lpVtbl -> get_KlvBuilder(This,pVal) ) 

#define ILMMpg2MxT_GetStreamPTS(This,Flags,pVal)	\
    ( (This)->lpVtbl -> GetStreamPTS(This,Flags,pVal) ) 

#define ILMMpg2MxT_get_IsEndOfStream(This,pBal)	\
    ( (This)->lpVtbl -> get_IsEndOfStream(This,pBal) ) 

#define ILMMpg2MxT_ClosePrivateData(This)	\
    ( (This)->lpVtbl -> ClosePrivateData(This) ) 

#define ILMMpg2MxT_get_AutoClosePrivateData(This,pVal)	\
    ( (This)->lpVtbl -> get_AutoClosePrivateData(This,pVal) ) 

#define ILMMpg2MxT_put_AutoClosePrivateData(This,newVal)	\
    ( (This)->lpVtbl -> put_AutoClosePrivateData(This,newVal) ) 

#define ILMMpg2MxT_get_ResyncInterval(This,pVal)	\
    ( (This)->lpVtbl -> get_ResyncInterval(This,pVal) ) 

#define ILMMpg2MxT_put_ResyncInterval(This,newVal)	\
    ( (This)->lpVtbl -> put_ResyncInterval(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMMpg2MxT_INTERFACE_DEFINED__ */


DEFINE_GUID(CLSID_LMMpg2MxT,0xE2B7DF2F,0x38C5,0x11D5,0x91,0xF6,0x00,0x10,0x4B,0xDB,0x8F,0xF9);

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DF2F-38C5-11D5-91F6-00104BDB8FF9")
LMMpg2MxT;
#endif
#endif /* __LMMpg2MxTLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


