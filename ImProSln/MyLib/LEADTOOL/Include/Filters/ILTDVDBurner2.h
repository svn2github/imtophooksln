

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Nov 05 12:44:29 2009
 */
/* Compiler settings for .\DVDBurner.idl:
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


#ifndef __ILTDVDBurner2_h__
#define __ILTDVDBurner2_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILTDVDBurner_FWD_DEFINED__
#define __ILTDVDBurner_FWD_DEFINED__
typedef interface ILTDVDBurner ILTDVDBurner;
#endif 	/* __ILTDVDBurner_FWD_DEFINED__ */


#ifndef __LTDVDBurner_FWD_DEFINED__
#define __LTDVDBurner_FWD_DEFINED__

#ifdef __cplusplus
typedef class LTDVDBurner LTDVDBurner;
#else
typedef struct LTDVDBurner LTDVDBurner;
#endif /* __cplusplus */

#endif 	/* __LTDVDBurner_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LTDVDBurnerLib_LIBRARY_DEFINED__
#define __LTDVDBurnerLib_LIBRARY_DEFINED__

/* library LTDVDBurnerLib */
/* [helpstring][version][uuid] */ 

#ifndef __LTDVDBurner2_GUID__
#define __LTDVDBurner2_GUID__
static const IID LIBID_LTDVDBurnerLib   = {0xe2b7de0f,0x38c5,0x11d5,{0x91,0xf6,0x00,0x10,0x4b,0xdb,0x8f,0xf9}};
static const CLSID CLSID_LTDVDBurner    = {0xe2b7de10,0x38c5,0x11d5,{0x91,0xf6,0x00,0x10,0x4b,0xdb,0x8f,0xf9}};
static const IID IID_ILTDVDBurner       = {0xe2b7de11,0x38c5,0x11d5,{0x91,0xf6,0x00,0x10,0x4b,0xdb,0x8f,0xf9}};
#endif 
typedef 
enum LTDVDBurner_State
    {	LTDVDBurner_State_Idle	= 0,
	LTDVDBurner_State_Writing	= 1,
	LTDVDBurner_State_TestWriting	= 2,
	LTDVDBurner_State_Erasing	= 3
    } 	LTDVDBurner_State;

typedef 
enum LTDVDBurner_Progress
    {	LTDVDBurner_Progress_Idle	= 0,
	LTDVDBurner_Progress_Initializing	= 1,
	LTDVDBurner_Progress_Writing	= 2,
	LTDVDBurner_Progress_Finalizing	= 3,
	LTDVDBurner_Progress_Erasing	= 4,
	LTDVDBurner_Progress_Completed	= 5,
	LTDVDBurner_Progress_Aborting	= 6,
	LTDVDBurner_Progress_Aborted	= 7
    } 	LTDVDBurner_Progress;

typedef 
enum LTDVDBurner_DiscType
    {	LTDVDBurner_DiscType_None	= -1,
	LTDVDBurner_DiscType_Unknown	= 0,
	LTDVDBurner_DiscType_CDROM	= 1,
	LTDVDBurner_DiscType_CDR	= 2,
	LTDVDBurner_DiscType_CDRW	= 3,
	LTDVDBurner_DiscType_DVDROM	= 4,
	LTDVDBurner_DiscType_DVDR	= 5,
	LTDVDBurner_DiscType_DVDRW	= 6,
	LTDVDBurner_DiscType_DVDRAM	= 7,
	LTDVDBurner_DiscType_DVDPLUSRW	= 8,
	LTDVDBurner_DiscType_DVDPLUSR	= 9,
	LTDVDBurner_DiscType_DVDPLUSRDL	= 10
    } 	LTDVDBurner_DiscType;


EXTERN_C const IID LIBID_LTDVDBurnerLib;

#ifndef __ILTDVDBurner_INTERFACE_DEFINED__
#define __ILTDVDBurner_INTERFACE_DEFINED__

/* interface ILTDVDBurner */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILTDVDBurner;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DE11-38C5-11D5-91F6-00104BDB8FF9")
    ILTDVDBurner : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Write( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Erase( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Cancel( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RefreshDriveList( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DriveCount( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CurrentDrive( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CurrentDrive( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDriveName( 
            /* [in] */ long Index,
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_InputPath( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_InputPath( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_VolumeName( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_VolumeName( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LastError( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_State( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetProgress( 
            /* [out] */ long *pState,
            /* [out] */ long *pProgress,
            /* [out] */ long *pComplete,
            /* [out] */ BSTR *pDescription) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EjectDisc( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AutoEject( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AutoEject( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Eraseable( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Writeable( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Ejectable( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ISOOutputFile( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ISOOutputFile( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TestWrite( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DiscType( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDiscTypeName( 
            /* [in] */ long type,
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RefreshSpeedList( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CurrentSpeed( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CurrentSpeed( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetSpeedValue( 
            /* [in] */ long Index,
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetSpeedName( 
            /* [in] */ long Index,
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SpeedListChanged( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DiscCapacity( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LoadDisc( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Loadable( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TestWriteable( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SpeedCount( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SystemSupported( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDriveId( 
            /* [in] */ long Index,
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ImageSize( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDriveDiscTypeCount( 
            /* [in] */ long Drive,
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDriveDiscType( 
            /* [in] */ long Drive,
            /* [in] */ long Index,
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDiscTypeWriteable( 
            /* [in] */ long type,
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ResetToDefaults( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILTDVDBurnerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILTDVDBurner * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILTDVDBurner * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILTDVDBurner * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILTDVDBurner * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILTDVDBurner * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILTDVDBurner * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILTDVDBurner * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Write )( 
            ILTDVDBurner * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Erase )( 
            ILTDVDBurner * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Cancel )( 
            ILTDVDBurner * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RefreshDriveList )( 
            ILTDVDBurner * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DriveCount )( 
            ILTDVDBurner * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentDrive )( 
            ILTDVDBurner * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CurrentDrive )( 
            ILTDVDBurner * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDriveName )( 
            ILTDVDBurner * This,
            /* [in] */ long Index,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InputPath )( 
            ILTDVDBurner * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_InputPath )( 
            ILTDVDBurner * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VolumeName )( 
            ILTDVDBurner * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_VolumeName )( 
            ILTDVDBurner * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LastError )( 
            ILTDVDBurner * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_State )( 
            ILTDVDBurner * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetProgress )( 
            ILTDVDBurner * This,
            /* [out] */ long *pState,
            /* [out] */ long *pProgress,
            /* [out] */ long *pComplete,
            /* [out] */ BSTR *pDescription);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EjectDisc )( 
            ILTDVDBurner * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AutoEject )( 
            ILTDVDBurner * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AutoEject )( 
            ILTDVDBurner * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Eraseable )( 
            ILTDVDBurner * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Writeable )( 
            ILTDVDBurner * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Ejectable )( 
            ILTDVDBurner * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ISOOutputFile )( 
            ILTDVDBurner * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ISOOutputFile )( 
            ILTDVDBurner * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TestWrite )( 
            ILTDVDBurner * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DiscType )( 
            ILTDVDBurner * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDiscTypeName )( 
            ILTDVDBurner * This,
            /* [in] */ long type,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RefreshSpeedList )( 
            ILTDVDBurner * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentSpeed )( 
            ILTDVDBurner * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CurrentSpeed )( 
            ILTDVDBurner * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetSpeedValue )( 
            ILTDVDBurner * This,
            /* [in] */ long Index,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetSpeedName )( 
            ILTDVDBurner * This,
            /* [in] */ long Index,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SpeedListChanged )( 
            ILTDVDBurner * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DiscCapacity )( 
            ILTDVDBurner * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LoadDisc )( 
            ILTDVDBurner * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Loadable )( 
            ILTDVDBurner * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TestWriteable )( 
            ILTDVDBurner * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SpeedCount )( 
            ILTDVDBurner * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SystemSupported )( 
            ILTDVDBurner * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDriveId )( 
            ILTDVDBurner * This,
            /* [in] */ long Index,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ImageSize )( 
            ILTDVDBurner * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDriveDiscTypeCount )( 
            ILTDVDBurner * This,
            /* [in] */ long Drive,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDriveDiscType )( 
            ILTDVDBurner * This,
            /* [in] */ long Drive,
            /* [in] */ long Index,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDiscTypeWriteable )( 
            ILTDVDBurner * This,
            /* [in] */ long type,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetToDefaults )( 
            ILTDVDBurner * This);
        
        END_INTERFACE
    } ILTDVDBurnerVtbl;

    interface ILTDVDBurner
    {
        CONST_VTBL struct ILTDVDBurnerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILTDVDBurner_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILTDVDBurner_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILTDVDBurner_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILTDVDBurner_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILTDVDBurner_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILTDVDBurner_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILTDVDBurner_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILTDVDBurner_Write(This)	\
    ( (This)->lpVtbl -> Write(This) ) 

#define ILTDVDBurner_Erase(This)	\
    ( (This)->lpVtbl -> Erase(This) ) 

#define ILTDVDBurner_Cancel(This)	\
    ( (This)->lpVtbl -> Cancel(This) ) 

#define ILTDVDBurner_RefreshDriveList(This)	\
    ( (This)->lpVtbl -> RefreshDriveList(This) ) 

#define ILTDVDBurner_get_DriveCount(This,pVal)	\
    ( (This)->lpVtbl -> get_DriveCount(This,pVal) ) 

#define ILTDVDBurner_get_CurrentDrive(This,pVal)	\
    ( (This)->lpVtbl -> get_CurrentDrive(This,pVal) ) 

#define ILTDVDBurner_put_CurrentDrive(This,newVal)	\
    ( (This)->lpVtbl -> put_CurrentDrive(This,newVal) ) 

#define ILTDVDBurner_GetDriveName(This,Index,pVal)	\
    ( (This)->lpVtbl -> GetDriveName(This,Index,pVal) ) 

#define ILTDVDBurner_get_InputPath(This,pVal)	\
    ( (This)->lpVtbl -> get_InputPath(This,pVal) ) 

#define ILTDVDBurner_put_InputPath(This,newVal)	\
    ( (This)->lpVtbl -> put_InputPath(This,newVal) ) 

#define ILTDVDBurner_get_VolumeName(This,pVal)	\
    ( (This)->lpVtbl -> get_VolumeName(This,pVal) ) 

#define ILTDVDBurner_put_VolumeName(This,newVal)	\
    ( (This)->lpVtbl -> put_VolumeName(This,newVal) ) 

#define ILTDVDBurner_get_LastError(This,pVal)	\
    ( (This)->lpVtbl -> get_LastError(This,pVal) ) 

#define ILTDVDBurner_get_State(This,pVal)	\
    ( (This)->lpVtbl -> get_State(This,pVal) ) 

#define ILTDVDBurner_GetProgress(This,pState,pProgress,pComplete,pDescription)	\
    ( (This)->lpVtbl -> GetProgress(This,pState,pProgress,pComplete,pDescription) ) 

#define ILTDVDBurner_EjectDisc(This)	\
    ( (This)->lpVtbl -> EjectDisc(This) ) 

#define ILTDVDBurner_get_AutoEject(This,pVal)	\
    ( (This)->lpVtbl -> get_AutoEject(This,pVal) ) 

#define ILTDVDBurner_put_AutoEject(This,newVal)	\
    ( (This)->lpVtbl -> put_AutoEject(This,newVal) ) 

#define ILTDVDBurner_get_Eraseable(This,pVal)	\
    ( (This)->lpVtbl -> get_Eraseable(This,pVal) ) 

#define ILTDVDBurner_get_Writeable(This,pVal)	\
    ( (This)->lpVtbl -> get_Writeable(This,pVal) ) 

#define ILTDVDBurner_get_Ejectable(This,pVal)	\
    ( (This)->lpVtbl -> get_Ejectable(This,pVal) ) 

#define ILTDVDBurner_get_ISOOutputFile(This,pVal)	\
    ( (This)->lpVtbl -> get_ISOOutputFile(This,pVal) ) 

#define ILTDVDBurner_put_ISOOutputFile(This,newVal)	\
    ( (This)->lpVtbl -> put_ISOOutputFile(This,newVal) ) 

#define ILTDVDBurner_TestWrite(This)	\
    ( (This)->lpVtbl -> TestWrite(This) ) 

#define ILTDVDBurner_get_DiscType(This,pVal)	\
    ( (This)->lpVtbl -> get_DiscType(This,pVal) ) 

#define ILTDVDBurner_GetDiscTypeName(This,type,pVal)	\
    ( (This)->lpVtbl -> GetDiscTypeName(This,type,pVal) ) 

#define ILTDVDBurner_RefreshSpeedList(This)	\
    ( (This)->lpVtbl -> RefreshSpeedList(This) ) 

#define ILTDVDBurner_get_CurrentSpeed(This,pVal)	\
    ( (This)->lpVtbl -> get_CurrentSpeed(This,pVal) ) 

#define ILTDVDBurner_put_CurrentSpeed(This,newVal)	\
    ( (This)->lpVtbl -> put_CurrentSpeed(This,newVal) ) 

#define ILTDVDBurner_GetSpeedValue(This,Index,pVal)	\
    ( (This)->lpVtbl -> GetSpeedValue(This,Index,pVal) ) 

#define ILTDVDBurner_GetSpeedName(This,Index,pVal)	\
    ( (This)->lpVtbl -> GetSpeedName(This,Index,pVal) ) 

#define ILTDVDBurner_get_SpeedListChanged(This,pVal)	\
    ( (This)->lpVtbl -> get_SpeedListChanged(This,pVal) ) 

#define ILTDVDBurner_get_DiscCapacity(This,pVal)	\
    ( (This)->lpVtbl -> get_DiscCapacity(This,pVal) ) 

#define ILTDVDBurner_LoadDisc(This)	\
    ( (This)->lpVtbl -> LoadDisc(This) ) 

#define ILTDVDBurner_get_Loadable(This,pVal)	\
    ( (This)->lpVtbl -> get_Loadable(This,pVal) ) 

#define ILTDVDBurner_get_TestWriteable(This,pVal)	\
    ( (This)->lpVtbl -> get_TestWriteable(This,pVal) ) 

#define ILTDVDBurner_get_SpeedCount(This,pVal)	\
    ( (This)->lpVtbl -> get_SpeedCount(This,pVal) ) 

#define ILTDVDBurner_get_SystemSupported(This,pVal)	\
    ( (This)->lpVtbl -> get_SystemSupported(This,pVal) ) 

#define ILTDVDBurner_GetDriveId(This,Index,pVal)	\
    ( (This)->lpVtbl -> GetDriveId(This,Index,pVal) ) 

#define ILTDVDBurner_get_ImageSize(This,pVal)	\
    ( (This)->lpVtbl -> get_ImageSize(This,pVal) ) 

#define ILTDVDBurner_GetDriveDiscTypeCount(This,Drive,pVal)	\
    ( (This)->lpVtbl -> GetDriveDiscTypeCount(This,Drive,pVal) ) 

#define ILTDVDBurner_GetDriveDiscType(This,Drive,Index,pVal)	\
    ( (This)->lpVtbl -> GetDriveDiscType(This,Drive,Index,pVal) ) 

#define ILTDVDBurner_GetDiscTypeWriteable(This,type,pVal)	\
    ( (This)->lpVtbl -> GetDiscTypeWriteable(This,type,pVal) ) 

#define ILTDVDBurner_ResetToDefaults(This)	\
    ( (This)->lpVtbl -> ResetToDefaults(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILTDVDBurner_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LTDVDBurner;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DE10-38C5-11D5-91F6-00104BDB8FF9")
LTDVDBurner;
#endif
#endif /* __LTDVDBurnerLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


