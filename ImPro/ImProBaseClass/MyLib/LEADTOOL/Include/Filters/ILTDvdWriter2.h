

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Nov 05 12:44:42 2009
 */
/* Compiler settings for .\LTDvdWriter.idl:
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


#ifndef __ILTDvdWriter2_h__
#define __ILTDvdWriter2_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILTDvdWriter_FWD_DEFINED__
#define __ILTDvdWriter_FWD_DEFINED__
typedef interface ILTDvdWriter ILTDvdWriter;
#endif 	/* __ILTDvdWriter_FWD_DEFINED__ */


#ifndef __LTDvdWriter_FWD_DEFINED__
#define __LTDvdWriter_FWD_DEFINED__

#ifdef __cplusplus
typedef class LTDvdWriter LTDvdWriter;
#else
typedef struct LTDvdWriter LTDvdWriter;
#endif /* __cplusplus */

#endif 	/* __LTDvdWriter_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LTDVDWriterLib_LIBRARY_DEFINED__
#define __LTDVDWriterLib_LIBRARY_DEFINED__

/* library LTDVDWriterLib */
/* [helpstring][helpfile][version][uuid] */ 

#ifndef __LTDvdWriter2_GUID__
#define __LTDvdWriter2_GUID__
static const IID LIBID_LTDVDWriterLib = {0xe2b7ddd0, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const IID IID_ILTDvdWriter =     {0xe2b7ddd1, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const CLSID CLSID_LTDvdWriter =  {0xe2b7ddcf, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
#endif 

EXTERN_C const IID LIBID_LTDVDWriterLib;

#ifndef __ILTDvdWriter_INTERFACE_DEFINED__
#define __ILTDvdWriter_INTERFACE_DEFINED__

/* interface ILTDvdWriter */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILTDvdWriter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DDD1-38C5-11D5-91F6-00104BDB8FF9")
    ILTDvdWriter : public IDispatch
    {
    public:
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_Overwrite( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_Overwrite( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_TitleBreak( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_TitleBreak( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][helpcontext][id] */ HRESULT STDMETHODCALLTYPE ClearTitleSet( void) = 0;
        
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_TempPath( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_TempPath( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetBytesWritten( 
            /* [out] */ long *pHigh,
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TitleMenu( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_TitleMenu( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddMenuTitle( 
            /* [in] */ BSTR Title,
            /* [in] */ long Index) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveMenuTitle( 
            /* [in] */ long Index) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveAllMenuTitles( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MenuTitleCount( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetMenuTitle( 
            /* [in] */ long Index,
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MenuLoop( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MenuLoop( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MenulessTitlePlay( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MenulessTitlePlay( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ResetToDefaults( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILTDvdWriterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILTDvdWriter * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILTDvdWriter * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILTDvdWriter * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILTDvdWriter * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILTDvdWriter * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILTDvdWriter * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILTDvdWriter * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Overwrite )( 
            ILTDvdWriter * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][helpcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Overwrite )( 
            ILTDvdWriter * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TitleBreak )( 
            ILTDvdWriter * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][helpcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TitleBreak )( 
            ILTDvdWriter * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][helpcontext][id] */ HRESULT ( STDMETHODCALLTYPE *ClearTitleSet )( 
            ILTDvdWriter * This);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TempPath )( 
            ILTDvdWriter * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][helpcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TempPath )( 
            ILTDvdWriter * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetBytesWritten )( 
            ILTDvdWriter * This,
            /* [out] */ long *pHigh,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TitleMenu )( 
            ILTDvdWriter * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TitleMenu )( 
            ILTDvdWriter * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddMenuTitle )( 
            ILTDvdWriter * This,
            /* [in] */ BSTR Title,
            /* [in] */ long Index);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemoveMenuTitle )( 
            ILTDvdWriter * This,
            /* [in] */ long Index);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemoveAllMenuTitles )( 
            ILTDvdWriter * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MenuTitleCount )( 
            ILTDvdWriter * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetMenuTitle )( 
            ILTDvdWriter * This,
            /* [in] */ long Index,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MenuLoop )( 
            ILTDvdWriter * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MenuLoop )( 
            ILTDvdWriter * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MenulessTitlePlay )( 
            ILTDvdWriter * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MenulessTitlePlay )( 
            ILTDvdWriter * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetToDefaults )( 
            ILTDvdWriter * This);
        
        END_INTERFACE
    } ILTDvdWriterVtbl;

    interface ILTDvdWriter
    {
        CONST_VTBL struct ILTDvdWriterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILTDvdWriter_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILTDvdWriter_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILTDvdWriter_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILTDvdWriter_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILTDvdWriter_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILTDvdWriter_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILTDvdWriter_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILTDvdWriter_get_Overwrite(This,pVal)	\
    ( (This)->lpVtbl -> get_Overwrite(This,pVal) ) 

#define ILTDvdWriter_put_Overwrite(This,newVal)	\
    ( (This)->lpVtbl -> put_Overwrite(This,newVal) ) 

#define ILTDvdWriter_get_TitleBreak(This,pVal)	\
    ( (This)->lpVtbl -> get_TitleBreak(This,pVal) ) 

#define ILTDvdWriter_put_TitleBreak(This,newVal)	\
    ( (This)->lpVtbl -> put_TitleBreak(This,newVal) ) 

#define ILTDvdWriter_ClearTitleSet(This)	\
    ( (This)->lpVtbl -> ClearTitleSet(This) ) 

#define ILTDvdWriter_get_TempPath(This,pVal)	\
    ( (This)->lpVtbl -> get_TempPath(This,pVal) ) 

#define ILTDvdWriter_put_TempPath(This,newVal)	\
    ( (This)->lpVtbl -> put_TempPath(This,newVal) ) 

#define ILTDvdWriter_GetBytesWritten(This,pHigh,pVal)	\
    ( (This)->lpVtbl -> GetBytesWritten(This,pHigh,pVal) ) 

#define ILTDvdWriter_get_TitleMenu(This,pVal)	\
    ( (This)->lpVtbl -> get_TitleMenu(This,pVal) ) 

#define ILTDvdWriter_put_TitleMenu(This,newVal)	\
    ( (This)->lpVtbl -> put_TitleMenu(This,newVal) ) 

#define ILTDvdWriter_AddMenuTitle(This,Title,Index)	\
    ( (This)->lpVtbl -> AddMenuTitle(This,Title,Index) ) 

#define ILTDvdWriter_RemoveMenuTitle(This,Index)	\
    ( (This)->lpVtbl -> RemoveMenuTitle(This,Index) ) 

#define ILTDvdWriter_RemoveAllMenuTitles(This)	\
    ( (This)->lpVtbl -> RemoveAllMenuTitles(This) ) 

#define ILTDvdWriter_get_MenuTitleCount(This,pVal)	\
    ( (This)->lpVtbl -> get_MenuTitleCount(This,pVal) ) 

#define ILTDvdWriter_GetMenuTitle(This,Index,pVal)	\
    ( (This)->lpVtbl -> GetMenuTitle(This,Index,pVal) ) 

#define ILTDvdWriter_get_MenuLoop(This,pVal)	\
    ( (This)->lpVtbl -> get_MenuLoop(This,pVal) ) 

#define ILTDvdWriter_put_MenuLoop(This,newVal)	\
    ( (This)->lpVtbl -> put_MenuLoop(This,newVal) ) 

#define ILTDvdWriter_get_MenulessTitlePlay(This,pVal)	\
    ( (This)->lpVtbl -> get_MenulessTitlePlay(This,pVal) ) 

#define ILTDvdWriter_put_MenulessTitlePlay(This,newVal)	\
    ( (This)->lpVtbl -> put_MenulessTitlePlay(This,newVal) ) 

#define ILTDvdWriter_ResetToDefaults(This)	\
    ( (This)->lpVtbl -> ResetToDefaults(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILTDvdWriter_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LTDvdWriter;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DDCF-38C5-11D5-91F6-00104BDB8FF9")
LTDvdWriter;
#endif
#endif /* __LTDVDWriterLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


