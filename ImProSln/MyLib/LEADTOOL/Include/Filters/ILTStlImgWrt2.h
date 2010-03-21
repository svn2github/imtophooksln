

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Nov 05 12:48:29 2009
 */
/* Compiler settings for .\ILTStlImgWrt.idl:
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


#ifndef __ILTStlImgWrt2_h__
#define __ILTStlImgWrt2_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILTStlImgWrtUserCallback_FWD_DEFINED__
#define __ILTStlImgWrtUserCallback_FWD_DEFINED__
typedef interface ILTStlImgWrtUserCallback ILTStlImgWrtUserCallback;
#endif 	/* __ILTStlImgWrtUserCallback_FWD_DEFINED__ */


#ifndef __ILTStlImgWrt_FWD_DEFINED__
#define __ILTStlImgWrt_FWD_DEFINED__
typedef interface ILTStlImgWrt ILTStlImgWrt;
#endif 	/* __ILTStlImgWrt_FWD_DEFINED__ */


#ifndef __LTStlImgWrt_FWD_DEFINED__
#define __LTStlImgWrt_FWD_DEFINED__

#ifdef __cplusplus
typedef class LTStlImgWrt LTStlImgWrt;
#else
typedef struct LTStlImgWrt LTStlImgWrt;
#endif /* __cplusplus */

#endif 	/* __LTStlImgWrt_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LTStlImgWrtLib_LIBRARY_DEFINED__
#define __LTStlImgWrtLib_LIBRARY_DEFINED__

/* library LTStlImgWrtLib */
/* [helpstring][version][uuid] */ 

#ifndef __LTStlImgWrt_H__
#define __LTStlImgWrt_H__
static const GUID LIBID_LTStlImgWrtLib           = {0xe2b7dd84, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LTStlImgWrt              = {0xe2b7dd85, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILTStlImgWrt               = {0xe2b7dd86, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILTStlImgWrtUserCallback   = {0xe2b7dd87, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LTStlImgWrtPropertyPage  = {0xe2b7dd88, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVAboutStlImgWrt        = {0xe2b7dd89, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
#endif 
#define SHOWPROG        0x01
#define SHOWQFACTOR     0x02
#define SHOWMULTIPAGE   0x04
#define SHOWSTAMP       0x08
#define LOSSLESS_JPEG   0x10
typedef /* [v1_enum] */ 
enum FileSaveOptions
    {	SAVE_OPTION_OVERWRITE	= 1,
	SAVE_OPTION_SKIP	= 2,
	SAVE_OPTION_USE_NEXT_NAME	= 4,
	SAVE_OPTION_APPLYTOALL	= 8
    } 	FileSaveOptions;

typedef /* [v1_enum] */ 
enum FileTypeConstants
    {	SAVEFILE_CMP	= 5,
	SAVEFILE_LEAD1BIT	= 26,
	SAVEFILE_JFIF	= 10,
	SAVEFILE_CMW	= 165,
	SAVEFILE_J2K	= 164,
	SAVEFILE_TIF	= 3,
	SAVEFILE_GIF	= 2,
	SAVEFILE_PNG	= 75,
	SAVEFILE_CALS	= 50,
	SAVEFILE_CLP	= 114,
	SAVEFILE_DICOM_GRAY	= 89,
	SAVEFILE_DICOM_COLOR	= 90,
	SAVEFILE_CUT	= 108,
	SAVEFILE_EMF	= 116,
	SAVEFILE_EPS	= 16,
	SAVEFILE_EXIF	= 96,
	SAVEFILE_FAX_G4	= 68,
	SAVEFILE_FLC	= 134,
	SAVEFILE_FPX	= 80,
	SAVEFILE_IMG	= 52,
	SAVEFILE_IFF_ILBM	= 111,
	SAVEFILE_ICA_G4	= 73,
	SAVEFILE_INTERGRAPH_RLE	= 122,
	SAVEFILE_JBIG	= 115,
	SAVEFILE_MAC	= 51,
	SAVEFILE_PCT	= 56,
	SAVEFILE_RAWICA_G4	= 79,
	SAVEFILE_MSP	= 53,
	SAVEFILE_OS2	= 14,
	SAVEFILE_PBM_ASCII	= 106,
	SAVEFILE_PCX	= 1,
	SAVEFILE_PGM_ASCII	= 104,
	SAVEFILE_PPM_ASCII	= 106,
	SAVEFILE_PSD	= 76,
	SAVEFILE_RAW	= 153,
	SAVEFILE_SCT	= 250,
	SAVEFILE_SGI	= 142,
	SAVEFILE_RAS	= 55,
	SAVEFILE_TGA	= 4,
	SAVEFILE_WFX_G4	= 70,
	SAVEFILE_BMP	= 6,
	SAVEFILE_WIN_CUR	= 92,
	SAVEFILE_WIN_ICO	= 91,
	SAVEFILE_WBMP	= 170,
	SAVEFILE_WMF	= 15,
	SAVEFILE_WPG	= 54,
	SAVEFILE_XBM	= 110,
	SAVEFILE_SMP	= 256,
	SAVEFILE_XPM	= 109,
	SAVEFILE_XWD10	= 132,
	SAVEFILE_XWD11	= 133
    } 	FileTypeConstants;

typedef /* [v1_enum] */ 
enum SaveCallbackFlagsConstants
    {	FRAME_OPTION_SAVE	= 0,
	FRAME_OPTION_SKIP	= 1,
	FRAME_OPTION_SKIP_AND_KEEP_NAME	= 2
    } 	SaveCallbackFlagsConstants;


EXTERN_C const IID LIBID_LTStlImgWrtLib;

#ifndef __ILTStlImgWrtUserCallback_INTERFACE_DEFINED__
#define __ILTStlImgWrtUserCallback_INTERFACE_DEFINED__

/* interface ILTStlImgWrtUserCallback */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ILTStlImgWrtUserCallback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DD87-38C5-11D5-91F6-00104BDB8FF9")
    ILTStlImgWrtUserCallback : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SaveOptionsProc( 
            BSTR *pstrFileName,
            SaveCallbackFlagsConstants *pSaveFlags,
            long lFrameNumber,
            VARIANT_BOOL bMultiPage) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILTStlImgWrtUserCallbackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILTStlImgWrtUserCallback * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILTStlImgWrtUserCallback * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILTStlImgWrtUserCallback * This);
        
        HRESULT ( STDMETHODCALLTYPE *SaveOptionsProc )( 
            ILTStlImgWrtUserCallback * This,
            BSTR *pstrFileName,
            SaveCallbackFlagsConstants *pSaveFlags,
            long lFrameNumber,
            VARIANT_BOOL bMultiPage);
        
        END_INTERFACE
    } ILTStlImgWrtUserCallbackVtbl;

    interface ILTStlImgWrtUserCallback
    {
        CONST_VTBL struct ILTStlImgWrtUserCallbackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILTStlImgWrtUserCallback_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILTStlImgWrtUserCallback_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILTStlImgWrtUserCallback_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILTStlImgWrtUserCallback_SaveOptionsProc(This,pstrFileName,pSaveFlags,lFrameNumber,bMultiPage)	\
    ( (This)->lpVtbl -> SaveOptionsProc(This,pstrFileName,pSaveFlags,lFrameNumber,bMultiPage) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILTStlImgWrtUserCallback_INTERFACE_DEFINED__ */


#ifndef __ILTStlImgWrt_INTERFACE_DEFINED__
#define __ILTStlImgWrt_INTERFACE_DEFINED__

/* interface ILTStlImgWrt */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILTStlImgWrt;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DD86-38C5-11D5-91F6-00104BDB8FF9")
    ILTStlImgWrt : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_InputPinStreamingState( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FileName( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FileName( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SupportedFileTypesCount( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_InfoFileTypeString( 
            /* [in] */ long lFileTypeIndex,
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_InfoFileTypeFormat( 
            /* [in] */ long lFileTypeIndex,
            /* [retval][out] */ FileTypeConstants *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_InfoFileTypeBpp( 
            /* [in] */ long lFileTypeIndex,
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_InfoFileTypeExt( 
            /* [in] */ long lFileTypeIndex,
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_InfoFileTypeFlags( 
            /* [in] */ long lFileTypeIndex,
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_InfoFileSubTypesCount( 
            /* [in] */ long lFileTypeIndex,
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_InfoFileSubTypeString( 
            /* [in] */ long lFileTypeIndex,
            /* [in] */ long lFileSubTypeIndex,
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_InfoFileSubTypeFormat( 
            /* [in] */ long lFileTypeIndex,
            /* [in] */ long lFileSubTypeIndex,
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_InfoFileSubTypeFlags( 
            /* [in] */ long lFileTypeIndex,
            /* [in] */ long lFileSubTypeIndex,
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FileTypeIndex( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FileTypeIndex( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FileTypeFormat( 
            /* [retval][out] */ FileTypeConstants *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FileTypeFormat( 
            /* [in] */ FileTypeConstants newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FileSubTypeIndex( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FileSubTypeIndex( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SaveMultipage( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SaveMultipage( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsQFactorSupported( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_QFactor( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_QFactor( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BitsPerPixel( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_BitsPerPixel( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsMultipageSupported( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_NumberingDigits( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_NumberingDigits( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PromptOverwrite( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PromptOverwrite( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HandleExistingFile( 
            /* [retval][out] */ FileSaveOptions *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_HandleExistingFile( 
            /* [in] */ FileSaveOptions newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UseTempFileName( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_UseTempFileName( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LastErrorCode( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LastErrorString( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DialogParentWnd( 
            /* [in] */ long lParentWnd) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DialogParentWnd( 
            /* [retval][out] */ long *plParentWnd) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ResetErrorCode( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EnableMessageBoxes( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_EnableMessageBoxes( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SaveOptionsCallback( 
            /* [in] */ ILTStlImgWrtUserCallback *pCallbackObject) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILTStlImgWrtVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILTStlImgWrt * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILTStlImgWrt * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILTStlImgWrt * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILTStlImgWrt * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILTStlImgWrt * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILTStlImgWrt * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILTStlImgWrt * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InputPinStreamingState )( 
            ILTStlImgWrt * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FileName )( 
            ILTStlImgWrt * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FileName )( 
            ILTStlImgWrt * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SupportedFileTypesCount )( 
            ILTStlImgWrt * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InfoFileTypeString )( 
            ILTStlImgWrt * This,
            /* [in] */ long lFileTypeIndex,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InfoFileTypeFormat )( 
            ILTStlImgWrt * This,
            /* [in] */ long lFileTypeIndex,
            /* [retval][out] */ FileTypeConstants *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InfoFileTypeBpp )( 
            ILTStlImgWrt * This,
            /* [in] */ long lFileTypeIndex,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InfoFileTypeExt )( 
            ILTStlImgWrt * This,
            /* [in] */ long lFileTypeIndex,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InfoFileTypeFlags )( 
            ILTStlImgWrt * This,
            /* [in] */ long lFileTypeIndex,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InfoFileSubTypesCount )( 
            ILTStlImgWrt * This,
            /* [in] */ long lFileTypeIndex,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InfoFileSubTypeString )( 
            ILTStlImgWrt * This,
            /* [in] */ long lFileTypeIndex,
            /* [in] */ long lFileSubTypeIndex,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InfoFileSubTypeFormat )( 
            ILTStlImgWrt * This,
            /* [in] */ long lFileTypeIndex,
            /* [in] */ long lFileSubTypeIndex,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InfoFileSubTypeFlags )( 
            ILTStlImgWrt * This,
            /* [in] */ long lFileTypeIndex,
            /* [in] */ long lFileSubTypeIndex,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FileTypeIndex )( 
            ILTStlImgWrt * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FileTypeIndex )( 
            ILTStlImgWrt * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FileTypeFormat )( 
            ILTStlImgWrt * This,
            /* [retval][out] */ FileTypeConstants *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FileTypeFormat )( 
            ILTStlImgWrt * This,
            /* [in] */ FileTypeConstants newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FileSubTypeIndex )( 
            ILTStlImgWrt * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FileSubTypeIndex )( 
            ILTStlImgWrt * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SaveMultipage )( 
            ILTStlImgWrt * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SaveMultipage )( 
            ILTStlImgWrt * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsQFactorSupported )( 
            ILTStlImgWrt * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_QFactor )( 
            ILTStlImgWrt * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_QFactor )( 
            ILTStlImgWrt * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BitsPerPixel )( 
            ILTStlImgWrt * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BitsPerPixel )( 
            ILTStlImgWrt * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsMultipageSupported )( 
            ILTStlImgWrt * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NumberingDigits )( 
            ILTStlImgWrt * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_NumberingDigits )( 
            ILTStlImgWrt * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PromptOverwrite )( 
            ILTStlImgWrt * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PromptOverwrite )( 
            ILTStlImgWrt * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HandleExistingFile )( 
            ILTStlImgWrt * This,
            /* [retval][out] */ FileSaveOptions *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_HandleExistingFile )( 
            ILTStlImgWrt * This,
            /* [in] */ FileSaveOptions newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UseTempFileName )( 
            ILTStlImgWrt * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UseTempFileName )( 
            ILTStlImgWrt * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LastErrorCode )( 
            ILTStlImgWrt * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LastErrorString )( 
            ILTStlImgWrt * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DialogParentWnd )( 
            ILTStlImgWrt * This,
            /* [in] */ long lParentWnd);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DialogParentWnd )( 
            ILTStlImgWrt * This,
            /* [retval][out] */ long *plParentWnd);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetErrorCode )( 
            ILTStlImgWrt * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableMessageBoxes )( 
            ILTStlImgWrt * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableMessageBoxes )( 
            ILTStlImgWrt * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SaveOptionsCallback )( 
            ILTStlImgWrt * This,
            /* [in] */ ILTStlImgWrtUserCallback *pCallbackObject);
        
        END_INTERFACE
    } ILTStlImgWrtVtbl;

    interface ILTStlImgWrt
    {
        CONST_VTBL struct ILTStlImgWrtVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILTStlImgWrt_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILTStlImgWrt_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILTStlImgWrt_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILTStlImgWrt_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILTStlImgWrt_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILTStlImgWrt_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILTStlImgWrt_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILTStlImgWrt_get_InputPinStreamingState(This,pVal)	\
    ( (This)->lpVtbl -> get_InputPinStreamingState(This,pVal) ) 

#define ILTStlImgWrt_get_FileName(This,pVal)	\
    ( (This)->lpVtbl -> get_FileName(This,pVal) ) 

#define ILTStlImgWrt_put_FileName(This,newVal)	\
    ( (This)->lpVtbl -> put_FileName(This,newVal) ) 

#define ILTStlImgWrt_get_SupportedFileTypesCount(This,pVal)	\
    ( (This)->lpVtbl -> get_SupportedFileTypesCount(This,pVal) ) 

#define ILTStlImgWrt_get_InfoFileTypeString(This,lFileTypeIndex,pVal)	\
    ( (This)->lpVtbl -> get_InfoFileTypeString(This,lFileTypeIndex,pVal) ) 

#define ILTStlImgWrt_get_InfoFileTypeFormat(This,lFileTypeIndex,pVal)	\
    ( (This)->lpVtbl -> get_InfoFileTypeFormat(This,lFileTypeIndex,pVal) ) 

#define ILTStlImgWrt_get_InfoFileTypeBpp(This,lFileTypeIndex,pVal)	\
    ( (This)->lpVtbl -> get_InfoFileTypeBpp(This,lFileTypeIndex,pVal) ) 

#define ILTStlImgWrt_get_InfoFileTypeExt(This,lFileTypeIndex,pVal)	\
    ( (This)->lpVtbl -> get_InfoFileTypeExt(This,lFileTypeIndex,pVal) ) 

#define ILTStlImgWrt_get_InfoFileTypeFlags(This,lFileTypeIndex,pVal)	\
    ( (This)->lpVtbl -> get_InfoFileTypeFlags(This,lFileTypeIndex,pVal) ) 

#define ILTStlImgWrt_get_InfoFileSubTypesCount(This,lFileTypeIndex,pVal)	\
    ( (This)->lpVtbl -> get_InfoFileSubTypesCount(This,lFileTypeIndex,pVal) ) 

#define ILTStlImgWrt_get_InfoFileSubTypeString(This,lFileTypeIndex,lFileSubTypeIndex,pVal)	\
    ( (This)->lpVtbl -> get_InfoFileSubTypeString(This,lFileTypeIndex,lFileSubTypeIndex,pVal) ) 

#define ILTStlImgWrt_get_InfoFileSubTypeFormat(This,lFileTypeIndex,lFileSubTypeIndex,pVal)	\
    ( (This)->lpVtbl -> get_InfoFileSubTypeFormat(This,lFileTypeIndex,lFileSubTypeIndex,pVal) ) 

#define ILTStlImgWrt_get_InfoFileSubTypeFlags(This,lFileTypeIndex,lFileSubTypeIndex,pVal)	\
    ( (This)->lpVtbl -> get_InfoFileSubTypeFlags(This,lFileTypeIndex,lFileSubTypeIndex,pVal) ) 

#define ILTStlImgWrt_get_FileTypeIndex(This,pVal)	\
    ( (This)->lpVtbl -> get_FileTypeIndex(This,pVal) ) 

#define ILTStlImgWrt_put_FileTypeIndex(This,newVal)	\
    ( (This)->lpVtbl -> put_FileTypeIndex(This,newVal) ) 

#define ILTStlImgWrt_get_FileTypeFormat(This,pVal)	\
    ( (This)->lpVtbl -> get_FileTypeFormat(This,pVal) ) 

#define ILTStlImgWrt_put_FileTypeFormat(This,newVal)	\
    ( (This)->lpVtbl -> put_FileTypeFormat(This,newVal) ) 

#define ILTStlImgWrt_get_FileSubTypeIndex(This,pVal)	\
    ( (This)->lpVtbl -> get_FileSubTypeIndex(This,pVal) ) 

#define ILTStlImgWrt_put_FileSubTypeIndex(This,newVal)	\
    ( (This)->lpVtbl -> put_FileSubTypeIndex(This,newVal) ) 

#define ILTStlImgWrt_get_SaveMultipage(This,pVal)	\
    ( (This)->lpVtbl -> get_SaveMultipage(This,pVal) ) 

#define ILTStlImgWrt_put_SaveMultipage(This,newVal)	\
    ( (This)->lpVtbl -> put_SaveMultipage(This,newVal) ) 

#define ILTStlImgWrt_get_IsQFactorSupported(This,pVal)	\
    ( (This)->lpVtbl -> get_IsQFactorSupported(This,pVal) ) 

#define ILTStlImgWrt_get_QFactor(This,pVal)	\
    ( (This)->lpVtbl -> get_QFactor(This,pVal) ) 

#define ILTStlImgWrt_put_QFactor(This,newVal)	\
    ( (This)->lpVtbl -> put_QFactor(This,newVal) ) 

#define ILTStlImgWrt_get_BitsPerPixel(This,pVal)	\
    ( (This)->lpVtbl -> get_BitsPerPixel(This,pVal) ) 

#define ILTStlImgWrt_put_BitsPerPixel(This,newVal)	\
    ( (This)->lpVtbl -> put_BitsPerPixel(This,newVal) ) 

#define ILTStlImgWrt_get_IsMultipageSupported(This,pVal)	\
    ( (This)->lpVtbl -> get_IsMultipageSupported(This,pVal) ) 

#define ILTStlImgWrt_get_NumberingDigits(This,pVal)	\
    ( (This)->lpVtbl -> get_NumberingDigits(This,pVal) ) 

#define ILTStlImgWrt_put_NumberingDigits(This,newVal)	\
    ( (This)->lpVtbl -> put_NumberingDigits(This,newVal) ) 

#define ILTStlImgWrt_get_PromptOverwrite(This,pVal)	\
    ( (This)->lpVtbl -> get_PromptOverwrite(This,pVal) ) 

#define ILTStlImgWrt_put_PromptOverwrite(This,newVal)	\
    ( (This)->lpVtbl -> put_PromptOverwrite(This,newVal) ) 

#define ILTStlImgWrt_get_HandleExistingFile(This,pVal)	\
    ( (This)->lpVtbl -> get_HandleExistingFile(This,pVal) ) 

#define ILTStlImgWrt_put_HandleExistingFile(This,newVal)	\
    ( (This)->lpVtbl -> put_HandleExistingFile(This,newVal) ) 

#define ILTStlImgWrt_get_UseTempFileName(This,pVal)	\
    ( (This)->lpVtbl -> get_UseTempFileName(This,pVal) ) 

#define ILTStlImgWrt_put_UseTempFileName(This,newVal)	\
    ( (This)->lpVtbl -> put_UseTempFileName(This,newVal) ) 

#define ILTStlImgWrt_get_LastErrorCode(This,pVal)	\
    ( (This)->lpVtbl -> get_LastErrorCode(This,pVal) ) 

#define ILTStlImgWrt_get_LastErrorString(This,pVal)	\
    ( (This)->lpVtbl -> get_LastErrorString(This,pVal) ) 

#define ILTStlImgWrt_put_DialogParentWnd(This,lParentWnd)	\
    ( (This)->lpVtbl -> put_DialogParentWnd(This,lParentWnd) ) 

#define ILTStlImgWrt_get_DialogParentWnd(This,plParentWnd)	\
    ( (This)->lpVtbl -> get_DialogParentWnd(This,plParentWnd) ) 

#define ILTStlImgWrt_ResetErrorCode(This)	\
    ( (This)->lpVtbl -> ResetErrorCode(This) ) 

#define ILTStlImgWrt_get_EnableMessageBoxes(This,pVal)	\
    ( (This)->lpVtbl -> get_EnableMessageBoxes(This,pVal) ) 

#define ILTStlImgWrt_put_EnableMessageBoxes(This,newVal)	\
    ( (This)->lpVtbl -> put_EnableMessageBoxes(This,newVal) ) 

#define ILTStlImgWrt_put_SaveOptionsCallback(This,pCallbackObject)	\
    ( (This)->lpVtbl -> put_SaveOptionsCallback(This,pCallbackObject) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILTStlImgWrt_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LTStlImgWrt;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DD85-38C5-11D5-91F6-00104BDB8FF9")
LTStlImgWrt;
#endif
#endif /* __LTStlImgWrtLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


