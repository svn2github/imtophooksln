

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Nov 05 12:51:58 2009
 */
/* Compiler settings for .\LMMpgDmxCommon.idl:
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

#ifndef __ILMMpgDmxCommon_h__
#define __ILMMpgDmxCommon_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILMMpgDmxCallback_FWD_DEFINED__
#define __ILMMpgDmxCallback_FWD_DEFINED__
typedef interface ILMMpgDmxCallback ILMMpgDmxCallback;
#endif 	/* __ILMMpgDmxCallback_FWD_DEFINED__ */


#ifndef __ILMKlvParser_FWD_DEFINED__
#define __ILMKlvParser_FWD_DEFINED__
typedef interface ILMKlvParser ILMKlvParser;
#endif 	/* __ILMKlvParser_FWD_DEFINED__ */


#ifndef __ILMMpgDmx1_FWD_DEFINED__
#define __ILMMpgDmx1_FWD_DEFINED__
typedef interface ILMMpgDmx1 ILMMpgDmx1;
#endif 	/* __ILMMpgDmx1_FWD_DEFINED__ */


#ifndef __ILMMpgDmx2_FWD_DEFINED__
#define __ILMMpgDmx2_FWD_DEFINED__
typedef interface ILMMpgDmx2 ILMMpgDmx2;
#endif 	/* __ILMMpgDmx2_FWD_DEFINED__ */


#ifndef __ILMMpgDmx3_FWD_DEFINED__
#define __ILMMpgDmx3_FWD_DEFINED__
typedef interface ILMMpgDmx3 ILMMpgDmx3;
#endif 	/* __ILMMpgDmx3_FWD_DEFINED__ */


#ifndef __ILMMpgDmx4_FWD_DEFINED__
#define __ILMMpgDmx4_FWD_DEFINED__
typedef interface ILMMpgDmx4 ILMMpgDmx4;
#endif 	/* __ILMMpgDmx4_FWD_DEFINED__ */


#ifndef __ILMMpgDmx5_FWD_DEFINED__
#define __ILMMpgDmx5_FWD_DEFINED__
typedef interface ILMMpgDmx5 ILMMpgDmx5;
#endif 	/* __ILMMpgDmx5_FWD_DEFINED__ */


#ifndef __ILMMpgDmx_FWD_DEFINED__
#define __ILMMpgDmx_FWD_DEFINED__
typedef interface ILMMpgDmx ILMMpgDmx;
#endif 	/* __ILMMpgDmx_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_LMMpgDmxCommon_0000_0000 */
/* [local] */ 

#ifndef __LMMpgDmxCommon_H__
#define __LMMpgDmxCommon_H__
static const IID IID_ILMMpgDmx1 = { 0xE2B7DF18, 0x38C5, 0x11d5, { 0x91, 0xF6, 0x00, 0x10, 0x4B, 0xDB, 0x8F, 0xF9 } };
static const IID IID_ILMMpgDmx2 = { 0xE2B7DDE4, 0x38C5, 0x11d5, { 0x91, 0xF6, 0x00, 0x10, 0x4B, 0xDB, 0x8F, 0xF9 } };
static const IID IID_ILMMpgDmx3 = { 0xE2B7DE33, 0x38C5, 0x11d5, { 0x91, 0xF6, 0x00, 0x10, 0x4B, 0xDB, 0x8F, 0xF9 } };
static const IID IID_ILMMpgDmx4 = { 0xE2B7DE39, 0x38C5, 0x11d5, { 0x91, 0xF6, 0x00, 0x10, 0x4B, 0xDB, 0x8F, 0xF9 } };
static const IID IID_ILMMpgDmx5 = { 0xE2B7DE41, 0x38C5, 0x11d5, { 0x91, 0xF6, 0x00, 0x10, 0x4B, 0xDB, 0x8F, 0xF9 } };
static const IID IID_ILMMpgDmx  = { 0xE2B7DE42, 0x38C5, 0x11d5, { 0x91, 0xF6, 0x00, 0x10, 0x4B, 0xDB, 0x8F, 0xF9 } };
static const IID IID_ILMMpgDmxCallback = {0xE2B7DF19, 0x38C5, 0x11d5, { 0x91, 0xF6, 0x00, 0x10, 0x4B, 0xDB, 0x8F, 0xF9 } };
static const IID IID_ILMKlvParser = {0xE2B7DF14, 0x38C5, 0x11d5, { 0x91, 0xF6, 0x00, 0x10, 0x4B, 0xDB, 0x8F, 0xF9 } };
#endif
typedef /* [v1_enum] */ 
enum FileTypeConstants
    {	Mpeg2_Other_Stream	= 0,
	Mpeg2_Program_Stream	= ( Mpeg2_Other_Stream + 1 ) ,
	Mpeg2_Transport_Stream	= ( Mpeg2_Program_Stream + 1 ) 
    } 	FileTypeConstants;

typedef /* [v1_enum] */ 
enum PTSTypeConstants
    {	PTS_Invalid	= 0,
	PTS_Calculated	= ( PTS_Invalid + 1 ) ,
	PTS_Valid	= ( PTS_Calculated + 1 ) 
    } 	PTSTypeConstants;

typedef /* [v1_enum] */ 
enum DemuxFlagConstants
    {	DemuxFlag_IgnoreCorruptedPackets	= 1
    } 	DemuxFlagConstants;

typedef /* [v1_enum] */ 
enum DataFlagConstants
    {	DataFlag_BeginSample	= 1,
	DataFlag_EndSample	= 2,
	DataFlag_IsKLV	= 4,
	DataFlag_IsAscii	= 8,
	DataFlag_IsBinary	= 0x10
    } 	DataFlagConstants;

typedef /* [v1_enum] */ 
enum EventNotificationConstants
    {	EVENTTYPE_DISCONTINUITY	= 0,
	EVENTTYPE_REBUILDNEEDED	= ( EVENTTYPE_DISCONTINUITY + 1 ) ,
	EVENTTYPE_CORRUPTEDPACKET	= ( EVENTTYPE_REBUILDNEEDED + 1 ) ,
	EVENTTYPE_COMPRESSIONCHANGED	= ( EVENTTYPE_CORRUPTEDPACKET + 1 ) ,
	EVENTTYPE_SIZECHANGED	= ( EVENTTYPE_COMPRESSIONCHANGED + 1 ) ,
	EVENTTYPE_DECODINGSTOPPED	= ( EVENTTYPE_SIZECHANGED + 1 ) ,
	EVENTTYPE_ENDOFSTREAM	= ( EVENTTYPE_DECODINGSTOPPED + 1 ) ,
	EVENTTYPE_PROGRAMMAPPACKET	= ( EVENTTYPE_ENDOFSTREAM + 1 ) 
    } 	EventNotificationConstants;

typedef /* [v1_enum] */ 
enum SearchKeyConstants
    {	SearchKey_Exact	= 1,
	SearchKey_AnyVersion	= 2,
	SearchKey_DesignatorOnly	= 3
    } 	SearchKeyConstants;

typedef /* [v1_enum] */ 
enum ErrorConstants
    {	KLV_KEY_NOT_FOUND	= 0x80050010,
	KLV_BAD_KEY	= 0x80050011,
	E_REBUILDNEEDED	= 0x80050012
    } 	ErrorConstants;

typedef /* [v1_enum] */ 
enum KlvOffsetConstants
    {	KLVOFFSET_REGISTRYCATEGORY	= 4,
	KLVOFFSET_REGISTRYDESIGNATOR	= 5,
	KLVOFFSET_STRUCTUREDESIGNATOR	= 6,
	KLVOFFSET_VERSIONNUMBER	= 7,
	KLVOFFSET_ITEMDESIGNATOR	= 8
    } 	KlvOffsetConstants;

typedef /* [v1_enum] */ 
enum RegistryCategoryConstants
    {	REGISTRYCATEGORY_DICTIONARY	= 1,
	REGISTRYCATEGORY_GROUPS	= 2,
	REGISTRYCATEGORY_WRAPPERS	= 3,
	REGISTRYCATEGORY_LABELS	= 4
    } 	RegistryCategoryConstants;

typedef /* [v1_enum] */ 
enum KlvDictionaryConstants
    {	KLVDICTIONARY_METADATA	= 1,
	KLVDICTIONARY_ESSENCE	= 2,
	KLVDICTIONARY_CONTROL	= 3,
	KLVDICTIONARY_TYPES	= 4
    } 	KlvDictionaryConstants;

typedef /* [v1_enum] */ 
enum KlvGroupConstants
    {	KLVGROUPS_UNIVERSAL	= 1,
	KLVGROUPS_GLOBAL	= 2,
	KLVGROUPS_LOCAL	= 3,
	KLVGROUPS_VARIABLEPACK	= 4,
	KLVGROUPS_FIXEDPACK	= 5
    } 	KlvGroupConstants;

typedef /* [v1_enum] */ 
enum KlvWrapperConstants
    {	KLVWRAPPERS_SIMPLE	= 1,
	KLVWRAPPERS_COMPLEX	= 2
    } 	KlvWrapperConstants;

typedef /* [v1_enum] */ 
enum KlvLabelConstants
    {	KLVLABELS_LABEL	= 4
    } 	KlvLabelConstants;

typedef /* [v1_enum] */ 
enum StreamFlagConstants
    {	StreamFlag_IsImportant	= 0x1
    } 	StreamFlagConstants;

typedef /* [v1_enum] */ 
enum LOADSTATUSConstant
    {	AM_LOADSTATUS_PROGRAM_PACKET_RECEIVED	= 0x100
    } 	LOADSTATUSConstant;



extern RPC_IF_HANDLE __MIDL_itf_LMMpgDmxCommon_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_LMMpgDmxCommon_0000_0000_v0_0_s_ifspec;

#ifndef __ILMMpgDmxCallback_INTERFACE_DEFINED__
#define __ILMMpgDmxCallback_INTERFACE_DEFINED__

/* interface ILMMpgDmxCallback */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ILMMpgDmxCallback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DF19-38C5-11D5-91F6-00104BDB8FF9")
    ILMMpgDmxCallback : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE DataAvailable( 
            /* [size_is][in] */ VARIANT *pData,
            /* [in] */ long lDataSize,
            /* [in] */ FileTypeConstants fileType,
            /* [in] */ long streamPID,
            /* [in] */ long streamType,
            /* [in] */ PTSTypeConstants PTSType,
            /* [in] */ double PTS,
            /* [in] */ long flags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EventNotification( 
            /* [in] */ EventNotificationConstants lEventType,
            /* [in] */ double Param1,
            /* [in] */ double Param2) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMMpgDmxCallbackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMMpgDmxCallback * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMMpgDmxCallback * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMMpgDmxCallback * This);
        
        HRESULT ( STDMETHODCALLTYPE *DataAvailable )( 
            ILMMpgDmxCallback * This,
            /* [size_is][in] */ VARIANT *pData,
            /* [in] */ long lDataSize,
            /* [in] */ FileTypeConstants fileType,
            /* [in] */ long streamPID,
            /* [in] */ long streamType,
            /* [in] */ PTSTypeConstants PTSType,
            /* [in] */ double PTS,
            /* [in] */ long flags);
        
        HRESULT ( STDMETHODCALLTYPE *EventNotification )( 
            ILMMpgDmxCallback * This,
            /* [in] */ EventNotificationConstants lEventType,
            /* [in] */ double Param1,
            /* [in] */ double Param2);
        
        END_INTERFACE
    } ILMMpgDmxCallbackVtbl;

    interface ILMMpgDmxCallback
    {
        CONST_VTBL struct ILMMpgDmxCallbackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMMpgDmxCallback_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMMpgDmxCallback_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMMpgDmxCallback_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMMpgDmxCallback_DataAvailable(This,pData,lDataSize,fileType,streamPID,streamType,PTSType,PTS,flags)	\
    ( (This)->lpVtbl -> DataAvailable(This,pData,lDataSize,fileType,streamPID,streamType,PTSType,PTS,flags) ) 

#define ILMMpgDmxCallback_EventNotification(This,lEventType,Param1,Param2)	\
    ( (This)->lpVtbl -> EventNotification(This,lEventType,Param1,Param2) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMMpgDmxCallback_INTERFACE_DEFINED__ */


#ifndef __ILMKlvParser_INTERFACE_DEFINED__
#define __ILMKlvParser_INTERFACE_DEFINED__

/* interface ILMKlvParser */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILMKlvParser;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DF14-38C5-11D5-91F6-00104BDB8FF9")
    ILMKlvParser : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddData( 
            /* [in] */ VARIANT *pData,
            /* [in] */ long lDataSize,
            /* [in] */ long Flags) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pCount) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetKey( 
            /* [in] */ long keyIndex,
            /* [out] */ VARIANT *pKey,
            /* [out] */ VARIANT *pKeyData,
            /* [out] */ long *pDataSize) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FindKey( 
            /* [in] */ VARIANT *pKeyToFind,
            /* [in] */ long searchFlags,
            /* [out] */ VARIANT *pKey,
            /* [out] */ VARIANT *pKeyData,
            /* [out] */ long *pDataSize) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FindKeyStr( 
            /* [in] */ BSTR pKeyToFind,
            /* [in] */ long searchFlags,
            /* [out] */ VARIANT *pKey,
            /* [out] */ VARIANT *pKeyData,
            /* [out] */ long *pDataSize) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMKlvParserVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMKlvParser * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMKlvParser * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMKlvParser * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMKlvParser * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMKlvParser * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMKlvParser * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMKlvParser * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddData )( 
            ILMKlvParser * This,
            /* [in] */ VARIANT *pData,
            /* [in] */ long lDataSize,
            /* [in] */ long Flags);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            ILMKlvParser * This,
            /* [retval][out] */ long *pCount);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetKey )( 
            ILMKlvParser * This,
            /* [in] */ long keyIndex,
            /* [out] */ VARIANT *pKey,
            /* [out] */ VARIANT *pKeyData,
            /* [out] */ long *pDataSize);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FindKey )( 
            ILMKlvParser * This,
            /* [in] */ VARIANT *pKeyToFind,
            /* [in] */ long searchFlags,
            /* [out] */ VARIANT *pKey,
            /* [out] */ VARIANT *pKeyData,
            /* [out] */ long *pDataSize);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FindKeyStr )( 
            ILMKlvParser * This,
            /* [in] */ BSTR pKeyToFind,
            /* [in] */ long searchFlags,
            /* [out] */ VARIANT *pKey,
            /* [out] */ VARIANT *pKeyData,
            /* [out] */ long *pDataSize);
        
        END_INTERFACE
    } ILMKlvParserVtbl;

    interface ILMKlvParser
    {
        CONST_VTBL struct ILMKlvParserVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMKlvParser_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMKlvParser_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMKlvParser_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMKlvParser_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMKlvParser_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMKlvParser_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMKlvParser_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMKlvParser_AddData(This,pData,lDataSize,Flags)	\
    ( (This)->lpVtbl -> AddData(This,pData,lDataSize,Flags) ) 

#define ILMKlvParser_get_Count(This,pCount)	\
    ( (This)->lpVtbl -> get_Count(This,pCount) ) 

#define ILMKlvParser_GetKey(This,keyIndex,pKey,pKeyData,pDataSize)	\
    ( (This)->lpVtbl -> GetKey(This,keyIndex,pKey,pKeyData,pDataSize) ) 

#define ILMKlvParser_FindKey(This,pKeyToFind,searchFlags,pKey,pKeyData,pDataSize)	\
    ( (This)->lpVtbl -> FindKey(This,pKeyToFind,searchFlags,pKey,pKeyData,pDataSize) ) 

#define ILMKlvParser_FindKeyStr(This,pKeyToFind,searchFlags,pKey,pKeyData,pDataSize)	\
    ( (This)->lpVtbl -> FindKeyStr(This,pKeyToFind,searchFlags,pKey,pKeyData,pDataSize) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMKlvParser_INTERFACE_DEFINED__ */


#ifndef __ILMMpgDmx1_INTERFACE_DEFINED__
#define __ILMMpgDmx1_INTERFACE_DEFINED__

/* interface ILMMpgDmx1 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILMMpgDmx1;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DF18-38C5-11D5-91F6-00104BDB8FF9")
    ILMMpgDmx1 : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CallbackObj( 
            /* [in] */ IUnknown *pCallback) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CallbackObj( 
            /* [retval][out] */ IUnknown **pCallback) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CallInSameThread( 
            /* [in] */ VARIANT_BOOL bVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CallInSameThread( 
            /* [retval][out] */ VARIANT_BOOL *pbVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetKlvParser( 
            /* [in] */ long streamPID,
            /* [retval][out] */ ILMKlvParser **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsStreaming( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [hidden][helpstring][id] */ HRESULT STDMETHODCALLTYPE EventNotification( 
            /* [in] */ EventNotificationConstants lEventType,
            /* [in] */ double Param1,
            /* [in] */ double Param2) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Flags( 
            /* [in] */ long val) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Flags( 
            /* [retval][out] */ long *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMMpgDmx1Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMMpgDmx1 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMMpgDmx1 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMMpgDmx1 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMMpgDmx1 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMMpgDmx1 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMMpgDmx1 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMMpgDmx1 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CallbackObj )( 
            ILMMpgDmx1 * This,
            /* [in] */ IUnknown *pCallback);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CallbackObj )( 
            ILMMpgDmx1 * This,
            /* [retval][out] */ IUnknown **pCallback);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CallInSameThread )( 
            ILMMpgDmx1 * This,
            /* [in] */ VARIANT_BOOL bVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CallInSameThread )( 
            ILMMpgDmx1 * This,
            /* [retval][out] */ VARIANT_BOOL *pbVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetKlvParser )( 
            ILMMpgDmx1 * This,
            /* [in] */ long streamPID,
            /* [retval][out] */ ILMKlvParser **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsStreaming )( 
            ILMMpgDmx1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [hidden][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EventNotification )( 
            ILMMpgDmx1 * This,
            /* [in] */ EventNotificationConstants lEventType,
            /* [in] */ double Param1,
            /* [in] */ double Param2);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Flags )( 
            ILMMpgDmx1 * This,
            /* [in] */ long val);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Flags )( 
            ILMMpgDmx1 * This,
            /* [retval][out] */ long *pVal);
        
        END_INTERFACE
    } ILMMpgDmx1Vtbl;

    interface ILMMpgDmx1
    {
        CONST_VTBL struct ILMMpgDmx1Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMMpgDmx1_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMMpgDmx1_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMMpgDmx1_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMMpgDmx1_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMMpgDmx1_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMMpgDmx1_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMMpgDmx1_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMMpgDmx1_put_CallbackObj(This,pCallback)	\
    ( (This)->lpVtbl -> put_CallbackObj(This,pCallback) ) 

#define ILMMpgDmx1_get_CallbackObj(This,pCallback)	\
    ( (This)->lpVtbl -> get_CallbackObj(This,pCallback) ) 

#define ILMMpgDmx1_put_CallInSameThread(This,bVal)	\
    ( (This)->lpVtbl -> put_CallInSameThread(This,bVal) ) 

#define ILMMpgDmx1_get_CallInSameThread(This,pbVal)	\
    ( (This)->lpVtbl -> get_CallInSameThread(This,pbVal) ) 

#define ILMMpgDmx1_GetKlvParser(This,streamPID,pVal)	\
    ( (This)->lpVtbl -> GetKlvParser(This,streamPID,pVal) ) 

#define ILMMpgDmx1_get_IsStreaming(This,pVal)	\
    ( (This)->lpVtbl -> get_IsStreaming(This,pVal) ) 

#define ILMMpgDmx1_EventNotification(This,lEventType,Param1,Param2)	\
    ( (This)->lpVtbl -> EventNotification(This,lEventType,Param1,Param2) ) 

#define ILMMpgDmx1_put_Flags(This,val)	\
    ( (This)->lpVtbl -> put_Flags(This,val) ) 

#define ILMMpgDmx1_get_Flags(This,pVal)	\
    ( (This)->lpVtbl -> get_Flags(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMMpgDmx1_INTERFACE_DEFINED__ */


#ifndef __ILMMpgDmx2_INTERFACE_DEFINED__
#define __ILMMpgDmx2_INTERFACE_DEFINED__

/* interface ILMMpgDmx2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILMMpgDmx2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DDE4-38C5-11D5-91F6-00104BDB8FF9")
    ILMMpgDmx2 : public ILMMpgDmx1
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ConvertPTSToStreamPosition( 
            /* [in] */ double PTS,
            /* [out] */ double *pStreamPosition) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StreamPosition( 
            /* [retval][out] */ double *pStreamPosition) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMMpgDmx2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMMpgDmx2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMMpgDmx2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMMpgDmx2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMMpgDmx2 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMMpgDmx2 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMMpgDmx2 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMMpgDmx2 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CallbackObj )( 
            ILMMpgDmx2 * This,
            /* [in] */ IUnknown *pCallback);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CallbackObj )( 
            ILMMpgDmx2 * This,
            /* [retval][out] */ IUnknown **pCallback);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CallInSameThread )( 
            ILMMpgDmx2 * This,
            /* [in] */ VARIANT_BOOL bVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CallInSameThread )( 
            ILMMpgDmx2 * This,
            /* [retval][out] */ VARIANT_BOOL *pbVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetKlvParser )( 
            ILMMpgDmx2 * This,
            /* [in] */ long streamPID,
            /* [retval][out] */ ILMKlvParser **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsStreaming )( 
            ILMMpgDmx2 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [hidden][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EventNotification )( 
            ILMMpgDmx2 * This,
            /* [in] */ EventNotificationConstants lEventType,
            /* [in] */ double Param1,
            /* [in] */ double Param2);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Flags )( 
            ILMMpgDmx2 * This,
            /* [in] */ long val);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Flags )( 
            ILMMpgDmx2 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ConvertPTSToStreamPosition )( 
            ILMMpgDmx2 * This,
            /* [in] */ double PTS,
            /* [out] */ double *pStreamPosition);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StreamPosition )( 
            ILMMpgDmx2 * This,
            /* [retval][out] */ double *pStreamPosition);
        
        END_INTERFACE
    } ILMMpgDmx2Vtbl;

    interface ILMMpgDmx2
    {
        CONST_VTBL struct ILMMpgDmx2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMMpgDmx2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMMpgDmx2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMMpgDmx2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMMpgDmx2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMMpgDmx2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMMpgDmx2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMMpgDmx2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMMpgDmx2_put_CallbackObj(This,pCallback)	\
    ( (This)->lpVtbl -> put_CallbackObj(This,pCallback) ) 

#define ILMMpgDmx2_get_CallbackObj(This,pCallback)	\
    ( (This)->lpVtbl -> get_CallbackObj(This,pCallback) ) 

#define ILMMpgDmx2_put_CallInSameThread(This,bVal)	\
    ( (This)->lpVtbl -> put_CallInSameThread(This,bVal) ) 

#define ILMMpgDmx2_get_CallInSameThread(This,pbVal)	\
    ( (This)->lpVtbl -> get_CallInSameThread(This,pbVal) ) 

#define ILMMpgDmx2_GetKlvParser(This,streamPID,pVal)	\
    ( (This)->lpVtbl -> GetKlvParser(This,streamPID,pVal) ) 

#define ILMMpgDmx2_get_IsStreaming(This,pVal)	\
    ( (This)->lpVtbl -> get_IsStreaming(This,pVal) ) 

#define ILMMpgDmx2_EventNotification(This,lEventType,Param1,Param2)	\
    ( (This)->lpVtbl -> EventNotification(This,lEventType,Param1,Param2) ) 

#define ILMMpgDmx2_put_Flags(This,val)	\
    ( (This)->lpVtbl -> put_Flags(This,val) ) 

#define ILMMpgDmx2_get_Flags(This,pVal)	\
    ( (This)->lpVtbl -> get_Flags(This,pVal) ) 


#define ILMMpgDmx2_ConvertPTSToStreamPosition(This,PTS,pStreamPosition)	\
    ( (This)->lpVtbl -> ConvertPTSToStreamPosition(This,PTS,pStreamPosition) ) 

#define ILMMpgDmx2_get_StreamPosition(This,pStreamPosition)	\
    ( (This)->lpVtbl -> get_StreamPosition(This,pStreamPosition) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMMpgDmx2_INTERFACE_DEFINED__ */


#ifndef __ILMMpgDmx3_INTERFACE_DEFINED__
#define __ILMMpgDmx3_INTERFACE_DEFINED__

/* interface ILMMpgDmx3 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILMMpgDmx3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DE33-38C5-11D5-91F6-00104BDB8FF9")
    ILMMpgDmx3 : public ILMMpgDmx2
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RefreshPosition( 
            /* [in] */ long Flags) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CurrentStreamPTS( 
            /* [retval][out] */ double *pPTS) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CurrentStreamPTS( 
            /* [in] */ double PTS) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BaseStreamPTS( 
            /* [retval][out] */ double *PTS) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LastStreamPTS( 
            /* [retval][out] */ double *PTS) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMMpgDmx3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMMpgDmx3 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMMpgDmx3 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMMpgDmx3 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMMpgDmx3 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMMpgDmx3 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMMpgDmx3 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMMpgDmx3 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CallbackObj )( 
            ILMMpgDmx3 * This,
            /* [in] */ IUnknown *pCallback);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CallbackObj )( 
            ILMMpgDmx3 * This,
            /* [retval][out] */ IUnknown **pCallback);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CallInSameThread )( 
            ILMMpgDmx3 * This,
            /* [in] */ VARIANT_BOOL bVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CallInSameThread )( 
            ILMMpgDmx3 * This,
            /* [retval][out] */ VARIANT_BOOL *pbVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetKlvParser )( 
            ILMMpgDmx3 * This,
            /* [in] */ long streamPID,
            /* [retval][out] */ ILMKlvParser **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsStreaming )( 
            ILMMpgDmx3 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [hidden][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EventNotification )( 
            ILMMpgDmx3 * This,
            /* [in] */ EventNotificationConstants lEventType,
            /* [in] */ double Param1,
            /* [in] */ double Param2);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Flags )( 
            ILMMpgDmx3 * This,
            /* [in] */ long val);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Flags )( 
            ILMMpgDmx3 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ConvertPTSToStreamPosition )( 
            ILMMpgDmx3 * This,
            /* [in] */ double PTS,
            /* [out] */ double *pStreamPosition);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StreamPosition )( 
            ILMMpgDmx3 * This,
            /* [retval][out] */ double *pStreamPosition);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RefreshPosition )( 
            ILMMpgDmx3 * This,
            /* [in] */ long Flags);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentStreamPTS )( 
            ILMMpgDmx3 * This,
            /* [retval][out] */ double *pPTS);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CurrentStreamPTS )( 
            ILMMpgDmx3 * This,
            /* [in] */ double PTS);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BaseStreamPTS )( 
            ILMMpgDmx3 * This,
            /* [retval][out] */ double *PTS);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LastStreamPTS )( 
            ILMMpgDmx3 * This,
            /* [retval][out] */ double *PTS);
        
        END_INTERFACE
    } ILMMpgDmx3Vtbl;

    interface ILMMpgDmx3
    {
        CONST_VTBL struct ILMMpgDmx3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMMpgDmx3_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMMpgDmx3_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMMpgDmx3_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMMpgDmx3_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMMpgDmx3_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMMpgDmx3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMMpgDmx3_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMMpgDmx3_put_CallbackObj(This,pCallback)	\
    ( (This)->lpVtbl -> put_CallbackObj(This,pCallback) ) 

#define ILMMpgDmx3_get_CallbackObj(This,pCallback)	\
    ( (This)->lpVtbl -> get_CallbackObj(This,pCallback) ) 

#define ILMMpgDmx3_put_CallInSameThread(This,bVal)	\
    ( (This)->lpVtbl -> put_CallInSameThread(This,bVal) ) 

#define ILMMpgDmx3_get_CallInSameThread(This,pbVal)	\
    ( (This)->lpVtbl -> get_CallInSameThread(This,pbVal) ) 

#define ILMMpgDmx3_GetKlvParser(This,streamPID,pVal)	\
    ( (This)->lpVtbl -> GetKlvParser(This,streamPID,pVal) ) 

#define ILMMpgDmx3_get_IsStreaming(This,pVal)	\
    ( (This)->lpVtbl -> get_IsStreaming(This,pVal) ) 

#define ILMMpgDmx3_EventNotification(This,lEventType,Param1,Param2)	\
    ( (This)->lpVtbl -> EventNotification(This,lEventType,Param1,Param2) ) 

#define ILMMpgDmx3_put_Flags(This,val)	\
    ( (This)->lpVtbl -> put_Flags(This,val) ) 

#define ILMMpgDmx3_get_Flags(This,pVal)	\
    ( (This)->lpVtbl -> get_Flags(This,pVal) ) 


#define ILMMpgDmx3_ConvertPTSToStreamPosition(This,PTS,pStreamPosition)	\
    ( (This)->lpVtbl -> ConvertPTSToStreamPosition(This,PTS,pStreamPosition) ) 

#define ILMMpgDmx3_get_StreamPosition(This,pStreamPosition)	\
    ( (This)->lpVtbl -> get_StreamPosition(This,pStreamPosition) ) 


#define ILMMpgDmx3_RefreshPosition(This,Flags)	\
    ( (This)->lpVtbl -> RefreshPosition(This,Flags) ) 

#define ILMMpgDmx3_get_CurrentStreamPTS(This,pPTS)	\
    ( (This)->lpVtbl -> get_CurrentStreamPTS(This,pPTS) ) 

#define ILMMpgDmx3_put_CurrentStreamPTS(This,PTS)	\
    ( (This)->lpVtbl -> put_CurrentStreamPTS(This,PTS) ) 

#define ILMMpgDmx3_get_BaseStreamPTS(This,PTS)	\
    ( (This)->lpVtbl -> get_BaseStreamPTS(This,PTS) ) 

#define ILMMpgDmx3_get_LastStreamPTS(This,PTS)	\
    ( (This)->lpVtbl -> get_LastStreamPTS(This,PTS) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMMpgDmx3_INTERFACE_DEFINED__ */


#ifndef __ILMMpgDmx4_INTERFACE_DEFINED__
#define __ILMMpgDmx4_INTERFACE_DEFINED__

/* interface ILMMpgDmx4 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILMMpgDmx4;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DE39-38C5-11D5-91F6-00104BDB8FF9")
    ILMMpgDmx4 : public ILMMpgDmx3
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FirstStreamPTS( 
            /* [retval][out] */ double *PTS) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StartStreamPTS( 
            /* [retval][out] */ double *PTS) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetKlvSubkeyParser( 
            /* [in] */ VARIANT Key,
            /* [retval][out] */ ILMKlvParser **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DurationCheckInterval( 
            /* [retval][out] */ double *Interval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DurationCheckInterval( 
            /* [in] */ double Interval) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ConvertPTSToFrame( 
            /* [in] */ double PTS,
            /* [out] */ double *pFrame) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ConvertFrameToPTS( 
            /* [in] */ double Frame,
            /* [out] */ double *pPTS) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StreamCount( 
            /* [retval][out] */ long *pCount) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetStreamInfo( 
            /* [in] */ long streamIndex,
            /* [out] */ long *pStreamPID,
            /* [out] */ long *pStreamType,
            /* [out] */ VARIANT *pStreamDescriptor) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_StreamFlags( 
            /* [in] */ long nStreamPID,
            /* [in] */ long Flags) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMMpgDmx4Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMMpgDmx4 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMMpgDmx4 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMMpgDmx4 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMMpgDmx4 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMMpgDmx4 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMMpgDmx4 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMMpgDmx4 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CallbackObj )( 
            ILMMpgDmx4 * This,
            /* [in] */ IUnknown *pCallback);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CallbackObj )( 
            ILMMpgDmx4 * This,
            /* [retval][out] */ IUnknown **pCallback);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CallInSameThread )( 
            ILMMpgDmx4 * This,
            /* [in] */ VARIANT_BOOL bVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CallInSameThread )( 
            ILMMpgDmx4 * This,
            /* [retval][out] */ VARIANT_BOOL *pbVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetKlvParser )( 
            ILMMpgDmx4 * This,
            /* [in] */ long streamPID,
            /* [retval][out] */ ILMKlvParser **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsStreaming )( 
            ILMMpgDmx4 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [hidden][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EventNotification )( 
            ILMMpgDmx4 * This,
            /* [in] */ EventNotificationConstants lEventType,
            /* [in] */ double Param1,
            /* [in] */ double Param2);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Flags )( 
            ILMMpgDmx4 * This,
            /* [in] */ long val);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Flags )( 
            ILMMpgDmx4 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ConvertPTSToStreamPosition )( 
            ILMMpgDmx4 * This,
            /* [in] */ double PTS,
            /* [out] */ double *pStreamPosition);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StreamPosition )( 
            ILMMpgDmx4 * This,
            /* [retval][out] */ double *pStreamPosition);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RefreshPosition )( 
            ILMMpgDmx4 * This,
            /* [in] */ long Flags);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentStreamPTS )( 
            ILMMpgDmx4 * This,
            /* [retval][out] */ double *pPTS);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CurrentStreamPTS )( 
            ILMMpgDmx4 * This,
            /* [in] */ double PTS);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BaseStreamPTS )( 
            ILMMpgDmx4 * This,
            /* [retval][out] */ double *PTS);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LastStreamPTS )( 
            ILMMpgDmx4 * This,
            /* [retval][out] */ double *PTS);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FirstStreamPTS )( 
            ILMMpgDmx4 * This,
            /* [retval][out] */ double *PTS);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StartStreamPTS )( 
            ILMMpgDmx4 * This,
            /* [retval][out] */ double *PTS);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetKlvSubkeyParser )( 
            ILMMpgDmx4 * This,
            /* [in] */ VARIANT Key,
            /* [retval][out] */ ILMKlvParser **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DurationCheckInterval )( 
            ILMMpgDmx4 * This,
            /* [retval][out] */ double *Interval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DurationCheckInterval )( 
            ILMMpgDmx4 * This,
            /* [in] */ double Interval);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ConvertPTSToFrame )( 
            ILMMpgDmx4 * This,
            /* [in] */ double PTS,
            /* [out] */ double *pFrame);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ConvertFrameToPTS )( 
            ILMMpgDmx4 * This,
            /* [in] */ double Frame,
            /* [out] */ double *pPTS);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StreamCount )( 
            ILMMpgDmx4 * This,
            /* [retval][out] */ long *pCount);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetStreamInfo )( 
            ILMMpgDmx4 * This,
            /* [in] */ long streamIndex,
            /* [out] */ long *pStreamPID,
            /* [out] */ long *pStreamType,
            /* [out] */ VARIANT *pStreamDescriptor);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_StreamFlags )( 
            ILMMpgDmx4 * This,
            /* [in] */ long nStreamPID,
            /* [in] */ long Flags);
        
        END_INTERFACE
    } ILMMpgDmx4Vtbl;

    interface ILMMpgDmx4
    {
        CONST_VTBL struct ILMMpgDmx4Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMMpgDmx4_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMMpgDmx4_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMMpgDmx4_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMMpgDmx4_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMMpgDmx4_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMMpgDmx4_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMMpgDmx4_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMMpgDmx4_put_CallbackObj(This,pCallback)	\
    ( (This)->lpVtbl -> put_CallbackObj(This,pCallback) ) 

#define ILMMpgDmx4_get_CallbackObj(This,pCallback)	\
    ( (This)->lpVtbl -> get_CallbackObj(This,pCallback) ) 

#define ILMMpgDmx4_put_CallInSameThread(This,bVal)	\
    ( (This)->lpVtbl -> put_CallInSameThread(This,bVal) ) 

#define ILMMpgDmx4_get_CallInSameThread(This,pbVal)	\
    ( (This)->lpVtbl -> get_CallInSameThread(This,pbVal) ) 

#define ILMMpgDmx4_GetKlvParser(This,streamPID,pVal)	\
    ( (This)->lpVtbl -> GetKlvParser(This,streamPID,pVal) ) 

#define ILMMpgDmx4_get_IsStreaming(This,pVal)	\
    ( (This)->lpVtbl -> get_IsStreaming(This,pVal) ) 

#define ILMMpgDmx4_EventNotification(This,lEventType,Param1,Param2)	\
    ( (This)->lpVtbl -> EventNotification(This,lEventType,Param1,Param2) ) 

#define ILMMpgDmx4_put_Flags(This,val)	\
    ( (This)->lpVtbl -> put_Flags(This,val) ) 

#define ILMMpgDmx4_get_Flags(This,pVal)	\
    ( (This)->lpVtbl -> get_Flags(This,pVal) ) 


#define ILMMpgDmx4_ConvertPTSToStreamPosition(This,PTS,pStreamPosition)	\
    ( (This)->lpVtbl -> ConvertPTSToStreamPosition(This,PTS,pStreamPosition) ) 

#define ILMMpgDmx4_get_StreamPosition(This,pStreamPosition)	\
    ( (This)->lpVtbl -> get_StreamPosition(This,pStreamPosition) ) 


#define ILMMpgDmx4_RefreshPosition(This,Flags)	\
    ( (This)->lpVtbl -> RefreshPosition(This,Flags) ) 

#define ILMMpgDmx4_get_CurrentStreamPTS(This,pPTS)	\
    ( (This)->lpVtbl -> get_CurrentStreamPTS(This,pPTS) ) 

#define ILMMpgDmx4_put_CurrentStreamPTS(This,PTS)	\
    ( (This)->lpVtbl -> put_CurrentStreamPTS(This,PTS) ) 

#define ILMMpgDmx4_get_BaseStreamPTS(This,PTS)	\
    ( (This)->lpVtbl -> get_BaseStreamPTS(This,PTS) ) 

#define ILMMpgDmx4_get_LastStreamPTS(This,PTS)	\
    ( (This)->lpVtbl -> get_LastStreamPTS(This,PTS) ) 


#define ILMMpgDmx4_get_FirstStreamPTS(This,PTS)	\
    ( (This)->lpVtbl -> get_FirstStreamPTS(This,PTS) ) 

#define ILMMpgDmx4_get_StartStreamPTS(This,PTS)	\
    ( (This)->lpVtbl -> get_StartStreamPTS(This,PTS) ) 

#define ILMMpgDmx4_GetKlvSubkeyParser(This,Key,pVal)	\
    ( (This)->lpVtbl -> GetKlvSubkeyParser(This,Key,pVal) ) 

#define ILMMpgDmx4_get_DurationCheckInterval(This,Interval)	\
    ( (This)->lpVtbl -> get_DurationCheckInterval(This,Interval) ) 

#define ILMMpgDmx4_put_DurationCheckInterval(This,Interval)	\
    ( (This)->lpVtbl -> put_DurationCheckInterval(This,Interval) ) 

#define ILMMpgDmx4_ConvertPTSToFrame(This,PTS,pFrame)	\
    ( (This)->lpVtbl -> ConvertPTSToFrame(This,PTS,pFrame) ) 

#define ILMMpgDmx4_ConvertFrameToPTS(This,Frame,pPTS)	\
    ( (This)->lpVtbl -> ConvertFrameToPTS(This,Frame,pPTS) ) 

#define ILMMpgDmx4_get_StreamCount(This,pCount)	\
    ( (This)->lpVtbl -> get_StreamCount(This,pCount) ) 

#define ILMMpgDmx4_GetStreamInfo(This,streamIndex,pStreamPID,pStreamType,pStreamDescriptor)	\
    ( (This)->lpVtbl -> GetStreamInfo(This,streamIndex,pStreamPID,pStreamType,pStreamDescriptor) ) 

#define ILMMpgDmx4_put_StreamFlags(This,nStreamPID,Flags)	\
    ( (This)->lpVtbl -> put_StreamFlags(This,nStreamPID,Flags) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMMpgDmx4_INTERFACE_DEFINED__ */


#ifndef __ILMMpgDmx5_INTERFACE_DEFINED__
#define __ILMMpgDmx5_INTERFACE_DEFINED__

/* interface ILMMpgDmx5 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILMMpgDmx5;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DE41-38C5-11D5-91F6-00104BDB8FF9")
    ILMMpgDmx5 : public ILMMpgDmx4
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LastStreamOffset( 
            /* [retval][out] */ double *pOffset) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CurrentStreamOffset( 
            /* [retval][out] */ double *pOffset) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CurrentStreamOffset( 
            /* [in] */ double Offset) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FirstStreamOffset( 
            /* [retval][out] */ double *pOffset) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BaseStreamOffset( 
            /* [retval][out] */ double *pOffset) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StartStreamOffset( 
            /* [retval][out] */ double *pOffset) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AutoLive( 
            /* [retval][out] */ VARIANT_BOOL *pAutoLive) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AutoLive( 
            /* [in] */ VARIANT_BOOL AutoLive) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AutoLiveTolerance( 
            /* [retval][out] */ double *pAutoLiveTolerance) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AutoLiveTolerance( 
            /* [in] */ double AutoLiveTolerance) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMMpgDmx5Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMMpgDmx5 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMMpgDmx5 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMMpgDmx5 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMMpgDmx5 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMMpgDmx5 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMMpgDmx5 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMMpgDmx5 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CallbackObj )( 
            ILMMpgDmx5 * This,
            /* [in] */ IUnknown *pCallback);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CallbackObj )( 
            ILMMpgDmx5 * This,
            /* [retval][out] */ IUnknown **pCallback);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CallInSameThread )( 
            ILMMpgDmx5 * This,
            /* [in] */ VARIANT_BOOL bVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CallInSameThread )( 
            ILMMpgDmx5 * This,
            /* [retval][out] */ VARIANT_BOOL *pbVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetKlvParser )( 
            ILMMpgDmx5 * This,
            /* [in] */ long streamPID,
            /* [retval][out] */ ILMKlvParser **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsStreaming )( 
            ILMMpgDmx5 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [hidden][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EventNotification )( 
            ILMMpgDmx5 * This,
            /* [in] */ EventNotificationConstants lEventType,
            /* [in] */ double Param1,
            /* [in] */ double Param2);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Flags )( 
            ILMMpgDmx5 * This,
            /* [in] */ long val);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Flags )( 
            ILMMpgDmx5 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ConvertPTSToStreamPosition )( 
            ILMMpgDmx5 * This,
            /* [in] */ double PTS,
            /* [out] */ double *pStreamPosition);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StreamPosition )( 
            ILMMpgDmx5 * This,
            /* [retval][out] */ double *pStreamPosition);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RefreshPosition )( 
            ILMMpgDmx5 * This,
            /* [in] */ long Flags);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentStreamPTS )( 
            ILMMpgDmx5 * This,
            /* [retval][out] */ double *pPTS);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CurrentStreamPTS )( 
            ILMMpgDmx5 * This,
            /* [in] */ double PTS);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BaseStreamPTS )( 
            ILMMpgDmx5 * This,
            /* [retval][out] */ double *PTS);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LastStreamPTS )( 
            ILMMpgDmx5 * This,
            /* [retval][out] */ double *PTS);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FirstStreamPTS )( 
            ILMMpgDmx5 * This,
            /* [retval][out] */ double *PTS);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StartStreamPTS )( 
            ILMMpgDmx5 * This,
            /* [retval][out] */ double *PTS);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetKlvSubkeyParser )( 
            ILMMpgDmx5 * This,
            /* [in] */ VARIANT Key,
            /* [retval][out] */ ILMKlvParser **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DurationCheckInterval )( 
            ILMMpgDmx5 * This,
            /* [retval][out] */ double *Interval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DurationCheckInterval )( 
            ILMMpgDmx5 * This,
            /* [in] */ double Interval);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ConvertPTSToFrame )( 
            ILMMpgDmx5 * This,
            /* [in] */ double PTS,
            /* [out] */ double *pFrame);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ConvertFrameToPTS )( 
            ILMMpgDmx5 * This,
            /* [in] */ double Frame,
            /* [out] */ double *pPTS);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StreamCount )( 
            ILMMpgDmx5 * This,
            /* [retval][out] */ long *pCount);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetStreamInfo )( 
            ILMMpgDmx5 * This,
            /* [in] */ long streamIndex,
            /* [out] */ long *pStreamPID,
            /* [out] */ long *pStreamType,
            /* [out] */ VARIANT *pStreamDescriptor);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_StreamFlags )( 
            ILMMpgDmx5 * This,
            /* [in] */ long nStreamPID,
            /* [in] */ long Flags);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LastStreamOffset )( 
            ILMMpgDmx5 * This,
            /* [retval][out] */ double *pOffset);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentStreamOffset )( 
            ILMMpgDmx5 * This,
            /* [retval][out] */ double *pOffset);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CurrentStreamOffset )( 
            ILMMpgDmx5 * This,
            /* [in] */ double Offset);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FirstStreamOffset )( 
            ILMMpgDmx5 * This,
            /* [retval][out] */ double *pOffset);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BaseStreamOffset )( 
            ILMMpgDmx5 * This,
            /* [retval][out] */ double *pOffset);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StartStreamOffset )( 
            ILMMpgDmx5 * This,
            /* [retval][out] */ double *pOffset);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AutoLive )( 
            ILMMpgDmx5 * This,
            /* [retval][out] */ VARIANT_BOOL *pAutoLive);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AutoLive )( 
            ILMMpgDmx5 * This,
            /* [in] */ VARIANT_BOOL AutoLive);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AutoLiveTolerance )( 
            ILMMpgDmx5 * This,
            /* [retval][out] */ double *pAutoLiveTolerance);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AutoLiveTolerance )( 
            ILMMpgDmx5 * This,
            /* [in] */ double AutoLiveTolerance);
        
        END_INTERFACE
    } ILMMpgDmx5Vtbl;

    interface ILMMpgDmx5
    {
        CONST_VTBL struct ILMMpgDmx5Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMMpgDmx5_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMMpgDmx5_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMMpgDmx5_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMMpgDmx5_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMMpgDmx5_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMMpgDmx5_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMMpgDmx5_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMMpgDmx5_put_CallbackObj(This,pCallback)	\
    ( (This)->lpVtbl -> put_CallbackObj(This,pCallback) ) 

#define ILMMpgDmx5_get_CallbackObj(This,pCallback)	\
    ( (This)->lpVtbl -> get_CallbackObj(This,pCallback) ) 

#define ILMMpgDmx5_put_CallInSameThread(This,bVal)	\
    ( (This)->lpVtbl -> put_CallInSameThread(This,bVal) ) 

#define ILMMpgDmx5_get_CallInSameThread(This,pbVal)	\
    ( (This)->lpVtbl -> get_CallInSameThread(This,pbVal) ) 

#define ILMMpgDmx5_GetKlvParser(This,streamPID,pVal)	\
    ( (This)->lpVtbl -> GetKlvParser(This,streamPID,pVal) ) 

#define ILMMpgDmx5_get_IsStreaming(This,pVal)	\
    ( (This)->lpVtbl -> get_IsStreaming(This,pVal) ) 

#define ILMMpgDmx5_EventNotification(This,lEventType,Param1,Param2)	\
    ( (This)->lpVtbl -> EventNotification(This,lEventType,Param1,Param2) ) 

#define ILMMpgDmx5_put_Flags(This,val)	\
    ( (This)->lpVtbl -> put_Flags(This,val) ) 

#define ILMMpgDmx5_get_Flags(This,pVal)	\
    ( (This)->lpVtbl -> get_Flags(This,pVal) ) 


#define ILMMpgDmx5_ConvertPTSToStreamPosition(This,PTS,pStreamPosition)	\
    ( (This)->lpVtbl -> ConvertPTSToStreamPosition(This,PTS,pStreamPosition) ) 

#define ILMMpgDmx5_get_StreamPosition(This,pStreamPosition)	\
    ( (This)->lpVtbl -> get_StreamPosition(This,pStreamPosition) ) 


#define ILMMpgDmx5_RefreshPosition(This,Flags)	\
    ( (This)->lpVtbl -> RefreshPosition(This,Flags) ) 

#define ILMMpgDmx5_get_CurrentStreamPTS(This,pPTS)	\
    ( (This)->lpVtbl -> get_CurrentStreamPTS(This,pPTS) ) 

#define ILMMpgDmx5_put_CurrentStreamPTS(This,PTS)	\
    ( (This)->lpVtbl -> put_CurrentStreamPTS(This,PTS) ) 

#define ILMMpgDmx5_get_BaseStreamPTS(This,PTS)	\
    ( (This)->lpVtbl -> get_BaseStreamPTS(This,PTS) ) 

#define ILMMpgDmx5_get_LastStreamPTS(This,PTS)	\
    ( (This)->lpVtbl -> get_LastStreamPTS(This,PTS) ) 


#define ILMMpgDmx5_get_FirstStreamPTS(This,PTS)	\
    ( (This)->lpVtbl -> get_FirstStreamPTS(This,PTS) ) 

#define ILMMpgDmx5_get_StartStreamPTS(This,PTS)	\
    ( (This)->lpVtbl -> get_StartStreamPTS(This,PTS) ) 

#define ILMMpgDmx5_GetKlvSubkeyParser(This,Key,pVal)	\
    ( (This)->lpVtbl -> GetKlvSubkeyParser(This,Key,pVal) ) 

#define ILMMpgDmx5_get_DurationCheckInterval(This,Interval)	\
    ( (This)->lpVtbl -> get_DurationCheckInterval(This,Interval) ) 

#define ILMMpgDmx5_put_DurationCheckInterval(This,Interval)	\
    ( (This)->lpVtbl -> put_DurationCheckInterval(This,Interval) ) 

#define ILMMpgDmx5_ConvertPTSToFrame(This,PTS,pFrame)	\
    ( (This)->lpVtbl -> ConvertPTSToFrame(This,PTS,pFrame) ) 

#define ILMMpgDmx5_ConvertFrameToPTS(This,Frame,pPTS)	\
    ( (This)->lpVtbl -> ConvertFrameToPTS(This,Frame,pPTS) ) 

#define ILMMpgDmx5_get_StreamCount(This,pCount)	\
    ( (This)->lpVtbl -> get_StreamCount(This,pCount) ) 

#define ILMMpgDmx5_GetStreamInfo(This,streamIndex,pStreamPID,pStreamType,pStreamDescriptor)	\
    ( (This)->lpVtbl -> GetStreamInfo(This,streamIndex,pStreamPID,pStreamType,pStreamDescriptor) ) 

#define ILMMpgDmx5_put_StreamFlags(This,nStreamPID,Flags)	\
    ( (This)->lpVtbl -> put_StreamFlags(This,nStreamPID,Flags) ) 


#define ILMMpgDmx5_get_LastStreamOffset(This,pOffset)	\
    ( (This)->lpVtbl -> get_LastStreamOffset(This,pOffset) ) 

#define ILMMpgDmx5_get_CurrentStreamOffset(This,pOffset)	\
    ( (This)->lpVtbl -> get_CurrentStreamOffset(This,pOffset) ) 

#define ILMMpgDmx5_put_CurrentStreamOffset(This,Offset)	\
    ( (This)->lpVtbl -> put_CurrentStreamOffset(This,Offset) ) 

#define ILMMpgDmx5_get_FirstStreamOffset(This,pOffset)	\
    ( (This)->lpVtbl -> get_FirstStreamOffset(This,pOffset) ) 

#define ILMMpgDmx5_get_BaseStreamOffset(This,pOffset)	\
    ( (This)->lpVtbl -> get_BaseStreamOffset(This,pOffset) ) 

#define ILMMpgDmx5_get_StartStreamOffset(This,pOffset)	\
    ( (This)->lpVtbl -> get_StartStreamOffset(This,pOffset) ) 

#define ILMMpgDmx5_get_AutoLive(This,pAutoLive)	\
    ( (This)->lpVtbl -> get_AutoLive(This,pAutoLive) ) 

#define ILMMpgDmx5_put_AutoLive(This,AutoLive)	\
    ( (This)->lpVtbl -> put_AutoLive(This,AutoLive) ) 

#define ILMMpgDmx5_get_AutoLiveTolerance(This,pAutoLiveTolerance)	\
    ( (This)->lpVtbl -> get_AutoLiveTolerance(This,pAutoLiveTolerance) ) 

#define ILMMpgDmx5_put_AutoLiveTolerance(This,AutoLiveTolerance)	\
    ( (This)->lpVtbl -> put_AutoLiveTolerance(This,AutoLiveTolerance) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMMpgDmx5_INTERFACE_DEFINED__ */


#ifndef __ILMMpgDmx_INTERFACE_DEFINED__
#define __ILMMpgDmx_INTERFACE_DEFINED__

/* interface ILMMpgDmx */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILMMpgDmx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DE42-38C5-11D5-91F6-00104BDB8FF9")
    ILMMpgDmx : public ILMMpgDmx5
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FirstStreamTime( 
            /* [retval][out] */ double *pTime) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BaseStreamTime( 
            /* [retval][out] */ double *pTime) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CurrentStreamTime( 
            /* [retval][out] */ double *pTime) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CurrentStreamTime( 
            /* [in] */ double Time) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LastStreamTime( 
            /* [retval][out] */ double *pTime) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMMpgDmxVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMMpgDmx * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMMpgDmx * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMMpgDmx * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMMpgDmx * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMMpgDmx * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMMpgDmx * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMMpgDmx * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CallbackObj )( 
            ILMMpgDmx * This,
            /* [in] */ IUnknown *pCallback);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CallbackObj )( 
            ILMMpgDmx * This,
            /* [retval][out] */ IUnknown **pCallback);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CallInSameThread )( 
            ILMMpgDmx * This,
            /* [in] */ VARIANT_BOOL bVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CallInSameThread )( 
            ILMMpgDmx * This,
            /* [retval][out] */ VARIANT_BOOL *pbVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetKlvParser )( 
            ILMMpgDmx * This,
            /* [in] */ long streamPID,
            /* [retval][out] */ ILMKlvParser **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsStreaming )( 
            ILMMpgDmx * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [hidden][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EventNotification )( 
            ILMMpgDmx * This,
            /* [in] */ EventNotificationConstants lEventType,
            /* [in] */ double Param1,
            /* [in] */ double Param2);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Flags )( 
            ILMMpgDmx * This,
            /* [in] */ long val);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Flags )( 
            ILMMpgDmx * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ConvertPTSToStreamPosition )( 
            ILMMpgDmx * This,
            /* [in] */ double PTS,
            /* [out] */ double *pStreamPosition);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StreamPosition )( 
            ILMMpgDmx * This,
            /* [retval][out] */ double *pStreamPosition);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RefreshPosition )( 
            ILMMpgDmx * This,
            /* [in] */ long Flags);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentStreamPTS )( 
            ILMMpgDmx * This,
            /* [retval][out] */ double *pPTS);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CurrentStreamPTS )( 
            ILMMpgDmx * This,
            /* [in] */ double PTS);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BaseStreamPTS )( 
            ILMMpgDmx * This,
            /* [retval][out] */ double *PTS);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LastStreamPTS )( 
            ILMMpgDmx * This,
            /* [retval][out] */ double *PTS);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FirstStreamPTS )( 
            ILMMpgDmx * This,
            /* [retval][out] */ double *PTS);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StartStreamPTS )( 
            ILMMpgDmx * This,
            /* [retval][out] */ double *PTS);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetKlvSubkeyParser )( 
            ILMMpgDmx * This,
            /* [in] */ VARIANT Key,
            /* [retval][out] */ ILMKlvParser **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DurationCheckInterval )( 
            ILMMpgDmx * This,
            /* [retval][out] */ double *Interval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DurationCheckInterval )( 
            ILMMpgDmx * This,
            /* [in] */ double Interval);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ConvertPTSToFrame )( 
            ILMMpgDmx * This,
            /* [in] */ double PTS,
            /* [out] */ double *pFrame);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ConvertFrameToPTS )( 
            ILMMpgDmx * This,
            /* [in] */ double Frame,
            /* [out] */ double *pPTS);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StreamCount )( 
            ILMMpgDmx * This,
            /* [retval][out] */ long *pCount);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetStreamInfo )( 
            ILMMpgDmx * This,
            /* [in] */ long streamIndex,
            /* [out] */ long *pStreamPID,
            /* [out] */ long *pStreamType,
            /* [out] */ VARIANT *pStreamDescriptor);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_StreamFlags )( 
            ILMMpgDmx * This,
            /* [in] */ long nStreamPID,
            /* [in] */ long Flags);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LastStreamOffset )( 
            ILMMpgDmx * This,
            /* [retval][out] */ double *pOffset);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentStreamOffset )( 
            ILMMpgDmx * This,
            /* [retval][out] */ double *pOffset);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CurrentStreamOffset )( 
            ILMMpgDmx * This,
            /* [in] */ double Offset);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FirstStreamOffset )( 
            ILMMpgDmx * This,
            /* [retval][out] */ double *pOffset);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BaseStreamOffset )( 
            ILMMpgDmx * This,
            /* [retval][out] */ double *pOffset);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StartStreamOffset )( 
            ILMMpgDmx * This,
            /* [retval][out] */ double *pOffset);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AutoLive )( 
            ILMMpgDmx * This,
            /* [retval][out] */ VARIANT_BOOL *pAutoLive);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AutoLive )( 
            ILMMpgDmx * This,
            /* [in] */ VARIANT_BOOL AutoLive);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AutoLiveTolerance )( 
            ILMMpgDmx * This,
            /* [retval][out] */ double *pAutoLiveTolerance);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AutoLiveTolerance )( 
            ILMMpgDmx * This,
            /* [in] */ double AutoLiveTolerance);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FirstStreamTime )( 
            ILMMpgDmx * This,
            /* [retval][out] */ double *pTime);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BaseStreamTime )( 
            ILMMpgDmx * This,
            /* [retval][out] */ double *pTime);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentStreamTime )( 
            ILMMpgDmx * This,
            /* [retval][out] */ double *pTime);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CurrentStreamTime )( 
            ILMMpgDmx * This,
            /* [in] */ double Time);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LastStreamTime )( 
            ILMMpgDmx * This,
            /* [retval][out] */ double *pTime);
        
        END_INTERFACE
    } ILMMpgDmxVtbl;

    interface ILMMpgDmx
    {
        CONST_VTBL struct ILMMpgDmxVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMMpgDmx_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMMpgDmx_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMMpgDmx_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMMpgDmx_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMMpgDmx_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMMpgDmx_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMMpgDmx_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMMpgDmx_put_CallbackObj(This,pCallback)	\
    ( (This)->lpVtbl -> put_CallbackObj(This,pCallback) ) 

#define ILMMpgDmx_get_CallbackObj(This,pCallback)	\
    ( (This)->lpVtbl -> get_CallbackObj(This,pCallback) ) 

#define ILMMpgDmx_put_CallInSameThread(This,bVal)	\
    ( (This)->lpVtbl -> put_CallInSameThread(This,bVal) ) 

#define ILMMpgDmx_get_CallInSameThread(This,pbVal)	\
    ( (This)->lpVtbl -> get_CallInSameThread(This,pbVal) ) 

#define ILMMpgDmx_GetKlvParser(This,streamPID,pVal)	\
    ( (This)->lpVtbl -> GetKlvParser(This,streamPID,pVal) ) 

#define ILMMpgDmx_get_IsStreaming(This,pVal)	\
    ( (This)->lpVtbl -> get_IsStreaming(This,pVal) ) 

#define ILMMpgDmx_EventNotification(This,lEventType,Param1,Param2)	\
    ( (This)->lpVtbl -> EventNotification(This,lEventType,Param1,Param2) ) 

#define ILMMpgDmx_put_Flags(This,val)	\
    ( (This)->lpVtbl -> put_Flags(This,val) ) 

#define ILMMpgDmx_get_Flags(This,pVal)	\
    ( (This)->lpVtbl -> get_Flags(This,pVal) ) 


#define ILMMpgDmx_ConvertPTSToStreamPosition(This,PTS,pStreamPosition)	\
    ( (This)->lpVtbl -> ConvertPTSToStreamPosition(This,PTS,pStreamPosition) ) 

#define ILMMpgDmx_get_StreamPosition(This,pStreamPosition)	\
    ( (This)->lpVtbl -> get_StreamPosition(This,pStreamPosition) ) 


#define ILMMpgDmx_RefreshPosition(This,Flags)	\
    ( (This)->lpVtbl -> RefreshPosition(This,Flags) ) 

#define ILMMpgDmx_get_CurrentStreamPTS(This,pPTS)	\
    ( (This)->lpVtbl -> get_CurrentStreamPTS(This,pPTS) ) 

#define ILMMpgDmx_put_CurrentStreamPTS(This,PTS)	\
    ( (This)->lpVtbl -> put_CurrentStreamPTS(This,PTS) ) 

#define ILMMpgDmx_get_BaseStreamPTS(This,PTS)	\
    ( (This)->lpVtbl -> get_BaseStreamPTS(This,PTS) ) 

#define ILMMpgDmx_get_LastStreamPTS(This,PTS)	\
    ( (This)->lpVtbl -> get_LastStreamPTS(This,PTS) ) 


#define ILMMpgDmx_get_FirstStreamPTS(This,PTS)	\
    ( (This)->lpVtbl -> get_FirstStreamPTS(This,PTS) ) 

#define ILMMpgDmx_get_StartStreamPTS(This,PTS)	\
    ( (This)->lpVtbl -> get_StartStreamPTS(This,PTS) ) 

#define ILMMpgDmx_GetKlvSubkeyParser(This,Key,pVal)	\
    ( (This)->lpVtbl -> GetKlvSubkeyParser(This,Key,pVal) ) 

#define ILMMpgDmx_get_DurationCheckInterval(This,Interval)	\
    ( (This)->lpVtbl -> get_DurationCheckInterval(This,Interval) ) 

#define ILMMpgDmx_put_DurationCheckInterval(This,Interval)	\
    ( (This)->lpVtbl -> put_DurationCheckInterval(This,Interval) ) 

#define ILMMpgDmx_ConvertPTSToFrame(This,PTS,pFrame)	\
    ( (This)->lpVtbl -> ConvertPTSToFrame(This,PTS,pFrame) ) 

#define ILMMpgDmx_ConvertFrameToPTS(This,Frame,pPTS)	\
    ( (This)->lpVtbl -> ConvertFrameToPTS(This,Frame,pPTS) ) 

#define ILMMpgDmx_get_StreamCount(This,pCount)	\
    ( (This)->lpVtbl -> get_StreamCount(This,pCount) ) 

#define ILMMpgDmx_GetStreamInfo(This,streamIndex,pStreamPID,pStreamType,pStreamDescriptor)	\
    ( (This)->lpVtbl -> GetStreamInfo(This,streamIndex,pStreamPID,pStreamType,pStreamDescriptor) ) 

#define ILMMpgDmx_put_StreamFlags(This,nStreamPID,Flags)	\
    ( (This)->lpVtbl -> put_StreamFlags(This,nStreamPID,Flags) ) 


#define ILMMpgDmx_get_LastStreamOffset(This,pOffset)	\
    ( (This)->lpVtbl -> get_LastStreamOffset(This,pOffset) ) 

#define ILMMpgDmx_get_CurrentStreamOffset(This,pOffset)	\
    ( (This)->lpVtbl -> get_CurrentStreamOffset(This,pOffset) ) 

#define ILMMpgDmx_put_CurrentStreamOffset(This,Offset)	\
    ( (This)->lpVtbl -> put_CurrentStreamOffset(This,Offset) ) 

#define ILMMpgDmx_get_FirstStreamOffset(This,pOffset)	\
    ( (This)->lpVtbl -> get_FirstStreamOffset(This,pOffset) ) 

#define ILMMpgDmx_get_BaseStreamOffset(This,pOffset)	\
    ( (This)->lpVtbl -> get_BaseStreamOffset(This,pOffset) ) 

#define ILMMpgDmx_get_StartStreamOffset(This,pOffset)	\
    ( (This)->lpVtbl -> get_StartStreamOffset(This,pOffset) ) 

#define ILMMpgDmx_get_AutoLive(This,pAutoLive)	\
    ( (This)->lpVtbl -> get_AutoLive(This,pAutoLive) ) 

#define ILMMpgDmx_put_AutoLive(This,AutoLive)	\
    ( (This)->lpVtbl -> put_AutoLive(This,AutoLive) ) 

#define ILMMpgDmx_get_AutoLiveTolerance(This,pAutoLiveTolerance)	\
    ( (This)->lpVtbl -> get_AutoLiveTolerance(This,pAutoLiveTolerance) ) 

#define ILMMpgDmx_put_AutoLiveTolerance(This,AutoLiveTolerance)	\
    ( (This)->lpVtbl -> put_AutoLiveTolerance(This,AutoLiveTolerance) ) 


#define ILMMpgDmx_get_FirstStreamTime(This,pTime)	\
    ( (This)->lpVtbl -> get_FirstStreamTime(This,pTime) ) 

#define ILMMpgDmx_get_BaseStreamTime(This,pTime)	\
    ( (This)->lpVtbl -> get_BaseStreamTime(This,pTime) ) 

#define ILMMpgDmx_get_CurrentStreamTime(This,pTime)	\
    ( (This)->lpVtbl -> get_CurrentStreamTime(This,pTime) ) 

#define ILMMpgDmx_put_CurrentStreamTime(This,Time)	\
    ( (This)->lpVtbl -> put_CurrentStreamTime(This,Time) ) 

#define ILMMpgDmx_get_LastStreamTime(This,pTime)	\
    ( (This)->lpVtbl -> get_LastStreamTime(This,pTime) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMMpgDmx_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


