

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Nov 05 12:54:56 2009
 */
/* Compiler settings for .\LMNetSnk.idl:
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


#ifndef __ILMNetSnk2_h__
#define __ILMNetSnk2_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILMNetSnkConnection_FWD_DEFINED__
#define __ILMNetSnkConnection_FWD_DEFINED__
typedef interface ILMNetSnkConnection ILMNetSnkConnection;
#endif 	/* __ILMNetSnkConnection_FWD_DEFINED__ */


#ifndef __ILMNetSnk_FWD_DEFINED__
#define __ILMNetSnk_FWD_DEFINED__
typedef interface ILMNetSnk ILMNetSnk;
#endif 	/* __ILMNetSnk_FWD_DEFINED__ */


#ifndef __LMNetSnk_FWD_DEFINED__
#define __LMNetSnk_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMNetSnk LMNetSnk;
#else
typedef struct LMNetSnk LMNetSnk;
#endif /* __cplusplus */

#endif 	/* __LMNetSnk_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LMNetSnkLib_LIBRARY_DEFINED__
#define __LMNetSnkLib_LIBRARY_DEFINED__

/* library LMNetSnkLib */
/* [helpstring][version][uuid] */ 

#ifndef __LMNetSnk2_GUID__
#define __LMNetSnk2_GUID__
static const IID LIBID_LMNetSnkLib         = { 0xe2b7de04, 0x38c5, 0x11d5, { 0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 } };
static const CLSID CLSID_LMNetSnk          = { 0xe2b7de05, 0x38c5, 0x11d5, { 0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 } };
static const IID IID_ILMNetSnk             = { 0xe2b7de06, 0x38c5, 0x11d5, { 0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 } };
static const IID IID_ILMNetSnkConnection   = { 0xe2b7de07, 0x38c5, 0x11d5, { 0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9 } };
#endif 

DEFINE_GUID(LIBID_LMNetSnkLib,0xE2B7DE04,0x38C5,0x11D5,0x91,0xF6,0x00,0x10,0x4B,0xDB,0x8F,0xF9);

#ifndef __ILMNetSnkConnection_INTERFACE_DEFINED__
#define __ILMNetSnkConnection_INTERFACE_DEFINED__

/* interface ILMNetSnkConnection */
/* [unique][helpstring][dual][uuid][object] */ 


DEFINE_GUID(IID_ILMNetSnkConnection,0xE2B7DE07,0x38C5,0x11D5,0x91,0xF6,0x00,0x10,0x4B,0xDB,0x8F,0xF9);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DE07-38C5-11D5-91F6-00104BDB8FF9")
    ILMNetSnkConnection : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PrevConnection( 
            /* [retval][out] */ ILMNetSnkConnection **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_NextConnection( 
            /* [retval][out] */ ILMNetSnkConnection **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ID( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Username( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Address( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Enabled( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Enabled( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Connected( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMNetSnkConnectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMNetSnkConnection * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMNetSnkConnection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMNetSnkConnection * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMNetSnkConnection * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMNetSnkConnection * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMNetSnkConnection * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMNetSnkConnection * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PrevConnection )( 
            ILMNetSnkConnection * This,
            /* [retval][out] */ ILMNetSnkConnection **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NextConnection )( 
            ILMNetSnkConnection * This,
            /* [retval][out] */ ILMNetSnkConnection **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ID )( 
            ILMNetSnkConnection * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Username )( 
            ILMNetSnkConnection * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Address )( 
            ILMNetSnkConnection * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Enabled )( 
            ILMNetSnkConnection * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Enabled )( 
            ILMNetSnkConnection * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Connected )( 
            ILMNetSnkConnection * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            ILMNetSnkConnection * This);
        
        END_INTERFACE
    } ILMNetSnkConnectionVtbl;

    interface ILMNetSnkConnection
    {
        CONST_VTBL struct ILMNetSnkConnectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMNetSnkConnection_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMNetSnkConnection_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMNetSnkConnection_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMNetSnkConnection_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMNetSnkConnection_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMNetSnkConnection_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMNetSnkConnection_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMNetSnkConnection_get_PrevConnection(This,pVal)	\
    ( (This)->lpVtbl -> get_PrevConnection(This,pVal) ) 

#define ILMNetSnkConnection_get_NextConnection(This,pVal)	\
    ( (This)->lpVtbl -> get_NextConnection(This,pVal) ) 

#define ILMNetSnkConnection_get_ID(This,pVal)	\
    ( (This)->lpVtbl -> get_ID(This,pVal) ) 

#define ILMNetSnkConnection_get_Username(This,pVal)	\
    ( (This)->lpVtbl -> get_Username(This,pVal) ) 

#define ILMNetSnkConnection_get_Address(This,pVal)	\
    ( (This)->lpVtbl -> get_Address(This,pVal) ) 

#define ILMNetSnkConnection_get_Enabled(This,pVal)	\
    ( (This)->lpVtbl -> get_Enabled(This,pVal) ) 

#define ILMNetSnkConnection_put_Enabled(This,newVal)	\
    ( (This)->lpVtbl -> put_Enabled(This,newVal) ) 

#define ILMNetSnkConnection_get_Connected(This,pVal)	\
    ( (This)->lpVtbl -> get_Connected(This,pVal) ) 

#define ILMNetSnkConnection_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMNetSnkConnection_INTERFACE_DEFINED__ */


#ifndef __ILMNetSnk_INTERFACE_DEFINED__
#define __ILMNetSnk_INTERFACE_DEFINED__

/* interface ILMNetSnk */
/* [unique][helpstring][dual][uuid][object] */ 


DEFINE_GUID(IID_ILMNetSnk,0xE2B7DE06,0x38C5,0x11D5,0x91,0xF6,0x00,0x10,0x4B,0xDB,0x8F,0xF9);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DE06-38C5-11D5-91F6-00104BDB8FF9")
    ILMNetSnk : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ConnectionCount( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FirstConnection( 
            /* [retval][out] */ ILMNetSnkConnection **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LastConnection( 
            /* [retval][out] */ ILMNetSnkConnection **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CloseAll( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FindConnection( 
            /* [in] */ long ID,
            /* [retval][out] */ ILMNetSnkConnection **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ConnectionVersion( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RestrictionCount( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddRestriction( 
            /* [in] */ BSTR Address,
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveRestriction( 
            /* [in] */ long index) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetRestriction( 
            /* [in] */ long Index,
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FindRestriction( 
            /* [in] */ BSTR Address,
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveAllRestrictions( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RequireLogin( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RequireLogin( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UserCount( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddUser( 
            /* [in] */ BSTR Username,
            /* [in] */ BSTR Password,
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveUser( 
            /* [in] */ long index) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetUsername( 
            /* [in] */ long Index,
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPassword( 
            /* [in] */ long Index,
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetPassword( 
            /* [in] */ long Index,
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FindUser( 
            /* [in] */ BSTR Username,
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveAllUsers( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMNetSnkVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMNetSnk * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMNetSnk * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMNetSnk * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMNetSnk * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMNetSnk * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMNetSnk * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMNetSnk * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ConnectionCount )( 
            ILMNetSnk * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FirstConnection )( 
            ILMNetSnk * This,
            /* [retval][out] */ ILMNetSnkConnection **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LastConnection )( 
            ILMNetSnk * This,
            /* [retval][out] */ ILMNetSnkConnection **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CloseAll )( 
            ILMNetSnk * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FindConnection )( 
            ILMNetSnk * This,
            /* [in] */ long ID,
            /* [retval][out] */ ILMNetSnkConnection **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ConnectionVersion )( 
            ILMNetSnk * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RestrictionCount )( 
            ILMNetSnk * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddRestriction )( 
            ILMNetSnk * This,
            /* [in] */ BSTR Address,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemoveRestriction )( 
            ILMNetSnk * This,
            /* [in] */ long index);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetRestriction )( 
            ILMNetSnk * This,
            /* [in] */ long Index,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FindRestriction )( 
            ILMNetSnk * This,
            /* [in] */ BSTR Address,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemoveAllRestrictions )( 
            ILMNetSnk * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RequireLogin )( 
            ILMNetSnk * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RequireLogin )( 
            ILMNetSnk * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UserCount )( 
            ILMNetSnk * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddUser )( 
            ILMNetSnk * This,
            /* [in] */ BSTR Username,
            /* [in] */ BSTR Password,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemoveUser )( 
            ILMNetSnk * This,
            /* [in] */ long index);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetUsername )( 
            ILMNetSnk * This,
            /* [in] */ long Index,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPassword )( 
            ILMNetSnk * This,
            /* [in] */ long Index,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetPassword )( 
            ILMNetSnk * This,
            /* [in] */ long Index,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FindUser )( 
            ILMNetSnk * This,
            /* [in] */ BSTR Username,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemoveAllUsers )( 
            ILMNetSnk * This);
        
        END_INTERFACE
    } ILMNetSnkVtbl;

    interface ILMNetSnk
    {
        CONST_VTBL struct ILMNetSnkVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMNetSnk_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMNetSnk_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMNetSnk_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMNetSnk_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMNetSnk_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMNetSnk_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMNetSnk_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMNetSnk_get_ConnectionCount(This,pVal)	\
    ( (This)->lpVtbl -> get_ConnectionCount(This,pVal) ) 

#define ILMNetSnk_get_FirstConnection(This,pVal)	\
    ( (This)->lpVtbl -> get_FirstConnection(This,pVal) ) 

#define ILMNetSnk_get_LastConnection(This,pVal)	\
    ( (This)->lpVtbl -> get_LastConnection(This,pVal) ) 

#define ILMNetSnk_CloseAll(This)	\
    ( (This)->lpVtbl -> CloseAll(This) ) 

#define ILMNetSnk_FindConnection(This,ID,pVal)	\
    ( (This)->lpVtbl -> FindConnection(This,ID,pVal) ) 

#define ILMNetSnk_get_ConnectionVersion(This,pVal)	\
    ( (This)->lpVtbl -> get_ConnectionVersion(This,pVal) ) 

#define ILMNetSnk_get_RestrictionCount(This,pVal)	\
    ( (This)->lpVtbl -> get_RestrictionCount(This,pVal) ) 

#define ILMNetSnk_AddRestriction(This,Address,pVal)	\
    ( (This)->lpVtbl -> AddRestriction(This,Address,pVal) ) 

#define ILMNetSnk_RemoveRestriction(This,index)	\
    ( (This)->lpVtbl -> RemoveRestriction(This,index) ) 

#define ILMNetSnk_GetRestriction(This,Index,pVal)	\
    ( (This)->lpVtbl -> GetRestriction(This,Index,pVal) ) 

#define ILMNetSnk_FindRestriction(This,Address,pVal)	\
    ( (This)->lpVtbl -> FindRestriction(This,Address,pVal) ) 

#define ILMNetSnk_RemoveAllRestrictions(This)	\
    ( (This)->lpVtbl -> RemoveAllRestrictions(This) ) 

#define ILMNetSnk_get_RequireLogin(This,pVal)	\
    ( (This)->lpVtbl -> get_RequireLogin(This,pVal) ) 

#define ILMNetSnk_put_RequireLogin(This,newVal)	\
    ( (This)->lpVtbl -> put_RequireLogin(This,newVal) ) 

#define ILMNetSnk_get_UserCount(This,pVal)	\
    ( (This)->lpVtbl -> get_UserCount(This,pVal) ) 

#define ILMNetSnk_AddUser(This,Username,Password,pVal)	\
    ( (This)->lpVtbl -> AddUser(This,Username,Password,pVal) ) 

#define ILMNetSnk_RemoveUser(This,index)	\
    ( (This)->lpVtbl -> RemoveUser(This,index) ) 

#define ILMNetSnk_GetUsername(This,Index,pVal)	\
    ( (This)->lpVtbl -> GetUsername(This,Index,pVal) ) 

#define ILMNetSnk_GetPassword(This,Index,pVal)	\
    ( (This)->lpVtbl -> GetPassword(This,Index,pVal) ) 

#define ILMNetSnk_SetPassword(This,Index,newVal)	\
    ( (This)->lpVtbl -> SetPassword(This,Index,newVal) ) 

#define ILMNetSnk_FindUser(This,Username,pVal)	\
    ( (This)->lpVtbl -> FindUser(This,Username,pVal) ) 

#define ILMNetSnk_RemoveAllUsers(This)	\
    ( (This)->lpVtbl -> RemoveAllUsers(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMNetSnk_INTERFACE_DEFINED__ */


DEFINE_GUID(CLSID_LMNetSnk,0xE2B7DE05,0x38C5,0x11D5,0x91,0xF6,0x00,0x10,0x4B,0xDB,0x8F,0xF9);

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DE05-38C5-11D5-91F6-00104BDB8FF9")
LMNetSnk;
#endif
#endif /* __LMNetSnkLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


