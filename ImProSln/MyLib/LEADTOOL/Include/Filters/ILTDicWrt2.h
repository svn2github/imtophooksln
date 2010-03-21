

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Nov 05 12:47:53 2009
 */
/* Compiler settings for .\ILtDicWrt.idl:
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


#ifndef __ILTDicWrt2_h__
#define __ILTDicWrt2_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILTDicWrt1_FWD_DEFINED__
#define __ILTDicWrt1_FWD_DEFINED__
typedef interface ILTDicWrt1 ILTDicWrt1;
#endif 	/* __ILTDicWrt1_FWD_DEFINED__ */


#ifndef __ILTDicWrt2_FWD_DEFINED__
#define __ILTDicWrt2_FWD_DEFINED__
typedef interface ILTDicWrt2 ILTDicWrt2;
#endif 	/* __ILTDicWrt2_FWD_DEFINED__ */


#ifndef __ILTDicWrt_FWD_DEFINED__
#define __ILTDicWrt_FWD_DEFINED__
typedef interface ILTDicWrt ILTDicWrt;
#endif 	/* __ILTDicWrt_FWD_DEFINED__ */


#ifndef __DICOMWrt_FWD_DEFINED__
#define __DICOMWrt_FWD_DEFINED__

#ifdef __cplusplus
typedef class DICOMWrt DICOMWrt;
#else
typedef struct DICOMWrt DICOMWrt;
#endif /* __cplusplus */

#endif 	/* __DICOMWrt_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LTDicWrtLib_LIBRARY_DEFINED__
#define __LTDicWrtLib_LIBRARY_DEFINED__

/* library LTDicWrtLib */
/* [helpstring][version][uuid] */ 

#ifndef __LtDicWrt_H__
#define __LtDicWrt_H__
static const GUID LIBID_LTDicWrtLib                 = {0xe2b7ddd5, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_DICOMWrt                    = {0xe2b7ddd6, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LTDicWrtPropertyPage        = {0xe2b7ddd8, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LTDicWrtEncoderPropertyPage = {0xe2b7ddd9, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_AboutPropertyPage           = {0xe2b7ddda, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILTDicWrt1                    = {0xe2b7ddd7, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILTDicWrt2                    = {0xE2B7DE36, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILTDicWrt                     = {0xE2B7DE38, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
#endif 
typedef /* [public] */ 
enum __MIDL___MIDL_itf_ILtDicWrt_0000_0000_0001
    {	NM_IMAGE_STORAGE	= 3,
	US_MULTI_FRAME_IMAGE_STORAGE	= 7,
	XA_IMAGE_STORAGE	= 15,
	XRF_IMAGE_STORAGE	= 17,
	SC_MULTI_FRAME_GRAYSCALE_BYTE_IMAGE_STORAGE	= 96,
	SC_MULTI_FRAME_GRAYSCALE_WORD_IMAGE_STORAGE	= 97,
	SC_MULTI_FRAME_TRUE_COLOR_IMAGE_STORAGE	= 98,
	VL_ENDOSCOPIC_IMAGE_STORAGE	= 36,
	VL_MICROSCOPIC_IMAGE_STORAGE	= 37,
	VL_PHOTOGRAPHIC_IMAGE_STORAGE	= 39,
	UNKNOWN	= 65535
    } 	DICOMCLASS;

typedef /* [public] */ 
enum __MIDL___MIDL_itf_ILtDicWrt_0000_0000_0002
    {	COMP_UNCOMPRESSED	= 0,
	COMP_JPEG422	= 1,
	COMP_LOSSLESSJPEG	= 2,
	COMP_JPEG2000	= 3,
	COMP_LOSSLESSJPEG2000	= 4
    } 	DICOMCOMPRESSION;

typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_ILtDicWrt_0000_0000_0003
    {	MPEG2DICOMCOMP_FORCE	= 0,
	MPEG2DICOMCOMP_IGNORE	= ( MPEG2DICOMCOMP_FORCE + 1 ) ,
	MPEG2DICOMCOMP_STOPGRAPH	= ( MPEG2DICOMCOMP_IGNORE + 1 ) 
    } 	MPEG2DicomCompatibilityConstants;


EXTERN_C const IID LIBID_LTDicWrtLib;

#ifndef __ILTDicWrt1_INTERFACE_DEFINED__
#define __ILTDicWrt1_INTERFACE_DEFINED__

/* interface ILTDicWrt1 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILTDicWrt1;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DDD7-38C5-11D5-91F6-00104BDB8FF9")
    ILTDicWrt1 : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DICOMTemplateFile( 
            /* [retval][out] */ BSTR *ppFileName) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DICOMTemplateFile( 
            /* [in] */ LPCOLESTR pFileName) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OutputFileName( 
            /* [retval][out] */ BSTR *ppFileName) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OutputFileName( 
            /* [in] */ LPCOLESTR pFileName) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_InputPinStreamingState( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DicomDSv14( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultDICOMClass( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DefaultDICOMClass( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CompressionFormat( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CompressionFormat( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CompressionQuality( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CompressionQuality( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDicomDSv14( 
            /* [in] */ long newVal,
            long pPixelData,
            /* [in] */ int bAutoSave,
            /* [in] */ int bCopy) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LockDicomDS( 
            int bLock) = 0;
        
        virtual /* [helpstring][hidden][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsMPEG2Stream( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MPEG2DicomCompatibilityOption( 
            /* [retval][out] */ MPEG2DicomCompatibilityConstants *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MPEG2DicomCompatibilityOption( 
            /* [in] */ MPEG2DicomCompatibilityConstants newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ResetToDefaults( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILTDicWrt1Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILTDicWrt1 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILTDicWrt1 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILTDicWrt1 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILTDicWrt1 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILTDicWrt1 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILTDicWrt1 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILTDicWrt1 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DICOMTemplateFile )( 
            ILTDicWrt1 * This,
            /* [retval][out] */ BSTR *ppFileName);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DICOMTemplateFile )( 
            ILTDicWrt1 * This,
            /* [in] */ LPCOLESTR pFileName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutputFileName )( 
            ILTDicWrt1 * This,
            /* [retval][out] */ BSTR *ppFileName);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OutputFileName )( 
            ILTDicWrt1 * This,
            /* [in] */ LPCOLESTR pFileName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InputPinStreamingState )( 
            ILTDicWrt1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DicomDSv14 )( 
            ILTDicWrt1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultDICOMClass )( 
            ILTDicWrt1 * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultDICOMClass )( 
            ILTDicWrt1 * This,
            /* [in] */ int newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CompressionFormat )( 
            ILTDicWrt1 * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CompressionFormat )( 
            ILTDicWrt1 * This,
            /* [in] */ int newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CompressionQuality )( 
            ILTDicWrt1 * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CompressionQuality )( 
            ILTDicWrt1 * This,
            /* [in] */ int newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetDicomDSv14 )( 
            ILTDicWrt1 * This,
            /* [in] */ long newVal,
            long pPixelData,
            /* [in] */ int bAutoSave,
            /* [in] */ int bCopy);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LockDicomDS )( 
            ILTDicWrt1 * This,
            int bLock);
        
        /* [helpstring][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsMPEG2Stream )( 
            ILTDicWrt1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MPEG2DicomCompatibilityOption )( 
            ILTDicWrt1 * This,
            /* [retval][out] */ MPEG2DicomCompatibilityConstants *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MPEG2DicomCompatibilityOption )( 
            ILTDicWrt1 * This,
            /* [in] */ MPEG2DicomCompatibilityConstants newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetToDefaults )( 
            ILTDicWrt1 * This);
        
        END_INTERFACE
    } ILTDicWrt1Vtbl;

    interface ILTDicWrt1
    {
        CONST_VTBL struct ILTDicWrt1Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILTDicWrt1_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILTDicWrt1_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILTDicWrt1_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILTDicWrt1_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILTDicWrt1_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILTDicWrt1_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILTDicWrt1_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILTDicWrt1_get_DICOMTemplateFile(This,ppFileName)	\
    ( (This)->lpVtbl -> get_DICOMTemplateFile(This,ppFileName) ) 

#define ILTDicWrt1_put_DICOMTemplateFile(This,pFileName)	\
    ( (This)->lpVtbl -> put_DICOMTemplateFile(This,pFileName) ) 

#define ILTDicWrt1_get_OutputFileName(This,ppFileName)	\
    ( (This)->lpVtbl -> get_OutputFileName(This,ppFileName) ) 

#define ILTDicWrt1_put_OutputFileName(This,pFileName)	\
    ( (This)->lpVtbl -> put_OutputFileName(This,pFileName) ) 

#define ILTDicWrt1_get_InputPinStreamingState(This,pVal)	\
    ( (This)->lpVtbl -> get_InputPinStreamingState(This,pVal) ) 

#define ILTDicWrt1_get_DicomDSv14(This,pVal)	\
    ( (This)->lpVtbl -> get_DicomDSv14(This,pVal) ) 

#define ILTDicWrt1_get_DefaultDICOMClass(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultDICOMClass(This,pVal) ) 

#define ILTDicWrt1_put_DefaultDICOMClass(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultDICOMClass(This,newVal) ) 

#define ILTDicWrt1_get_CompressionFormat(This,pVal)	\
    ( (This)->lpVtbl -> get_CompressionFormat(This,pVal) ) 

#define ILTDicWrt1_put_CompressionFormat(This,newVal)	\
    ( (This)->lpVtbl -> put_CompressionFormat(This,newVal) ) 

#define ILTDicWrt1_get_CompressionQuality(This,pVal)	\
    ( (This)->lpVtbl -> get_CompressionQuality(This,pVal) ) 

#define ILTDicWrt1_put_CompressionQuality(This,newVal)	\
    ( (This)->lpVtbl -> put_CompressionQuality(This,newVal) ) 

#define ILTDicWrt1_SetDicomDSv14(This,newVal,pPixelData,bAutoSave,bCopy)	\
    ( (This)->lpVtbl -> SetDicomDSv14(This,newVal,pPixelData,bAutoSave,bCopy) ) 

#define ILTDicWrt1_LockDicomDS(This,bLock)	\
    ( (This)->lpVtbl -> LockDicomDS(This,bLock) ) 

#define ILTDicWrt1_get_IsMPEG2Stream(This,pVal)	\
    ( (This)->lpVtbl -> get_IsMPEG2Stream(This,pVal) ) 

#define ILTDicWrt1_get_MPEG2DicomCompatibilityOption(This,pVal)	\
    ( (This)->lpVtbl -> get_MPEG2DicomCompatibilityOption(This,pVal) ) 

#define ILTDicWrt1_put_MPEG2DicomCompatibilityOption(This,newVal)	\
    ( (This)->lpVtbl -> put_MPEG2DicomCompatibilityOption(This,newVal) ) 

#define ILTDicWrt1_ResetToDefaults(This)	\
    ( (This)->lpVtbl -> ResetToDefaults(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILTDicWrt1_INTERFACE_DEFINED__ */


#ifndef __ILTDicWrt2_INTERFACE_DEFINED__
#define __ILTDicWrt2_INTERFACE_DEFINED__

/* interface ILTDicWrt2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILTDicWrt2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DE36-38C5-11D5-91F6-00104BDB8FF9")
    ILTDicWrt2 : public ILTDicWrt1
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DicomDS( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDicomDS( 
            /* [in] */ long newVal,
            long pPixelData,
            /* [in] */ int bAutoSave,
            /* [in] */ int bCopy) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILTDicWrt2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILTDicWrt2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILTDicWrt2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILTDicWrt2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILTDicWrt2 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILTDicWrt2 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILTDicWrt2 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILTDicWrt2 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DICOMTemplateFile )( 
            ILTDicWrt2 * This,
            /* [retval][out] */ BSTR *ppFileName);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DICOMTemplateFile )( 
            ILTDicWrt2 * This,
            /* [in] */ LPCOLESTR pFileName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutputFileName )( 
            ILTDicWrt2 * This,
            /* [retval][out] */ BSTR *ppFileName);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OutputFileName )( 
            ILTDicWrt2 * This,
            /* [in] */ LPCOLESTR pFileName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InputPinStreamingState )( 
            ILTDicWrt2 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DicomDSv14 )( 
            ILTDicWrt2 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultDICOMClass )( 
            ILTDicWrt2 * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultDICOMClass )( 
            ILTDicWrt2 * This,
            /* [in] */ int newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CompressionFormat )( 
            ILTDicWrt2 * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CompressionFormat )( 
            ILTDicWrt2 * This,
            /* [in] */ int newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CompressionQuality )( 
            ILTDicWrt2 * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CompressionQuality )( 
            ILTDicWrt2 * This,
            /* [in] */ int newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetDicomDSv14 )( 
            ILTDicWrt2 * This,
            /* [in] */ long newVal,
            long pPixelData,
            /* [in] */ int bAutoSave,
            /* [in] */ int bCopy);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LockDicomDS )( 
            ILTDicWrt2 * This,
            int bLock);
        
        /* [helpstring][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsMPEG2Stream )( 
            ILTDicWrt2 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MPEG2DicomCompatibilityOption )( 
            ILTDicWrt2 * This,
            /* [retval][out] */ MPEG2DicomCompatibilityConstants *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MPEG2DicomCompatibilityOption )( 
            ILTDicWrt2 * This,
            /* [in] */ MPEG2DicomCompatibilityConstants newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetToDefaults )( 
            ILTDicWrt2 * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DicomDS )( 
            ILTDicWrt2 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetDicomDS )( 
            ILTDicWrt2 * This,
            /* [in] */ long newVal,
            long pPixelData,
            /* [in] */ int bAutoSave,
            /* [in] */ int bCopy);
        
        END_INTERFACE
    } ILTDicWrt2Vtbl;

    interface ILTDicWrt2
    {
        CONST_VTBL struct ILTDicWrt2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILTDicWrt2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILTDicWrt2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILTDicWrt2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILTDicWrt2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILTDicWrt2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILTDicWrt2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILTDicWrt2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILTDicWrt2_get_DICOMTemplateFile(This,ppFileName)	\
    ( (This)->lpVtbl -> get_DICOMTemplateFile(This,ppFileName) ) 

#define ILTDicWrt2_put_DICOMTemplateFile(This,pFileName)	\
    ( (This)->lpVtbl -> put_DICOMTemplateFile(This,pFileName) ) 

#define ILTDicWrt2_get_OutputFileName(This,ppFileName)	\
    ( (This)->lpVtbl -> get_OutputFileName(This,ppFileName) ) 

#define ILTDicWrt2_put_OutputFileName(This,pFileName)	\
    ( (This)->lpVtbl -> put_OutputFileName(This,pFileName) ) 

#define ILTDicWrt2_get_InputPinStreamingState(This,pVal)	\
    ( (This)->lpVtbl -> get_InputPinStreamingState(This,pVal) ) 

#define ILTDicWrt2_get_DicomDSv14(This,pVal)	\
    ( (This)->lpVtbl -> get_DicomDSv14(This,pVal) ) 

#define ILTDicWrt2_get_DefaultDICOMClass(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultDICOMClass(This,pVal) ) 

#define ILTDicWrt2_put_DefaultDICOMClass(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultDICOMClass(This,newVal) ) 

#define ILTDicWrt2_get_CompressionFormat(This,pVal)	\
    ( (This)->lpVtbl -> get_CompressionFormat(This,pVal) ) 

#define ILTDicWrt2_put_CompressionFormat(This,newVal)	\
    ( (This)->lpVtbl -> put_CompressionFormat(This,newVal) ) 

#define ILTDicWrt2_get_CompressionQuality(This,pVal)	\
    ( (This)->lpVtbl -> get_CompressionQuality(This,pVal) ) 

#define ILTDicWrt2_put_CompressionQuality(This,newVal)	\
    ( (This)->lpVtbl -> put_CompressionQuality(This,newVal) ) 

#define ILTDicWrt2_SetDicomDSv14(This,newVal,pPixelData,bAutoSave,bCopy)	\
    ( (This)->lpVtbl -> SetDicomDSv14(This,newVal,pPixelData,bAutoSave,bCopy) ) 

#define ILTDicWrt2_LockDicomDS(This,bLock)	\
    ( (This)->lpVtbl -> LockDicomDS(This,bLock) ) 

#define ILTDicWrt2_get_IsMPEG2Stream(This,pVal)	\
    ( (This)->lpVtbl -> get_IsMPEG2Stream(This,pVal) ) 

#define ILTDicWrt2_get_MPEG2DicomCompatibilityOption(This,pVal)	\
    ( (This)->lpVtbl -> get_MPEG2DicomCompatibilityOption(This,pVal) ) 

#define ILTDicWrt2_put_MPEG2DicomCompatibilityOption(This,newVal)	\
    ( (This)->lpVtbl -> put_MPEG2DicomCompatibilityOption(This,newVal) ) 

#define ILTDicWrt2_ResetToDefaults(This)	\
    ( (This)->lpVtbl -> ResetToDefaults(This) ) 


#define ILTDicWrt2_get_DicomDS(This,pVal)	\
    ( (This)->lpVtbl -> get_DicomDS(This,pVal) ) 

#define ILTDicWrt2_SetDicomDS(This,newVal,pPixelData,bAutoSave,bCopy)	\
    ( (This)->lpVtbl -> SetDicomDS(This,newVal,pPixelData,bAutoSave,bCopy) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILTDicWrt2_INTERFACE_DEFINED__ */


#ifndef __ILTDicWrt_INTERFACE_DEFINED__
#define __ILTDicWrt_INTERFACE_DEFINED__

/* interface ILTDicWrt */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILTDicWrt;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DE38-38C5-11D5-91F6-00104BDB8FF9")
    ILTDicWrt : public ILTDicWrt1
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RasterVersion( 
            /* [retval][out] */ long *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILTDicWrtVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILTDicWrt * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILTDicWrt * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILTDicWrt * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILTDicWrt * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILTDicWrt * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILTDicWrt * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILTDicWrt * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DICOMTemplateFile )( 
            ILTDicWrt * This,
            /* [retval][out] */ BSTR *ppFileName);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DICOMTemplateFile )( 
            ILTDicWrt * This,
            /* [in] */ LPCOLESTR pFileName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OutputFileName )( 
            ILTDicWrt * This,
            /* [retval][out] */ BSTR *ppFileName);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OutputFileName )( 
            ILTDicWrt * This,
            /* [in] */ LPCOLESTR pFileName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InputPinStreamingState )( 
            ILTDicWrt * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DicomDSv14 )( 
            ILTDicWrt * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultDICOMClass )( 
            ILTDicWrt * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultDICOMClass )( 
            ILTDicWrt * This,
            /* [in] */ int newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CompressionFormat )( 
            ILTDicWrt * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CompressionFormat )( 
            ILTDicWrt * This,
            /* [in] */ int newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CompressionQuality )( 
            ILTDicWrt * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CompressionQuality )( 
            ILTDicWrt * This,
            /* [in] */ int newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetDicomDSv14 )( 
            ILTDicWrt * This,
            /* [in] */ long newVal,
            long pPixelData,
            /* [in] */ int bAutoSave,
            /* [in] */ int bCopy);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LockDicomDS )( 
            ILTDicWrt * This,
            int bLock);
        
        /* [helpstring][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsMPEG2Stream )( 
            ILTDicWrt * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MPEG2DicomCompatibilityOption )( 
            ILTDicWrt * This,
            /* [retval][out] */ MPEG2DicomCompatibilityConstants *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MPEG2DicomCompatibilityOption )( 
            ILTDicWrt * This,
            /* [in] */ MPEG2DicomCompatibilityConstants newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetToDefaults )( 
            ILTDicWrt * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RasterVersion )( 
            ILTDicWrt * This,
            /* [retval][out] */ long *pVal);
        
        END_INTERFACE
    } ILTDicWrtVtbl;

    interface ILTDicWrt
    {
        CONST_VTBL struct ILTDicWrtVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILTDicWrt_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILTDicWrt_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILTDicWrt_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILTDicWrt_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILTDicWrt_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILTDicWrt_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILTDicWrt_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILTDicWrt_get_DICOMTemplateFile(This,ppFileName)	\
    ( (This)->lpVtbl -> get_DICOMTemplateFile(This,ppFileName) ) 

#define ILTDicWrt_put_DICOMTemplateFile(This,pFileName)	\
    ( (This)->lpVtbl -> put_DICOMTemplateFile(This,pFileName) ) 

#define ILTDicWrt_get_OutputFileName(This,ppFileName)	\
    ( (This)->lpVtbl -> get_OutputFileName(This,ppFileName) ) 

#define ILTDicWrt_put_OutputFileName(This,pFileName)	\
    ( (This)->lpVtbl -> put_OutputFileName(This,pFileName) ) 

#define ILTDicWrt_get_InputPinStreamingState(This,pVal)	\
    ( (This)->lpVtbl -> get_InputPinStreamingState(This,pVal) ) 

#define ILTDicWrt_get_DicomDSv14(This,pVal)	\
    ( (This)->lpVtbl -> get_DicomDSv14(This,pVal) ) 

#define ILTDicWrt_get_DefaultDICOMClass(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultDICOMClass(This,pVal) ) 

#define ILTDicWrt_put_DefaultDICOMClass(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultDICOMClass(This,newVal) ) 

#define ILTDicWrt_get_CompressionFormat(This,pVal)	\
    ( (This)->lpVtbl -> get_CompressionFormat(This,pVal) ) 

#define ILTDicWrt_put_CompressionFormat(This,newVal)	\
    ( (This)->lpVtbl -> put_CompressionFormat(This,newVal) ) 

#define ILTDicWrt_get_CompressionQuality(This,pVal)	\
    ( (This)->lpVtbl -> get_CompressionQuality(This,pVal) ) 

#define ILTDicWrt_put_CompressionQuality(This,newVal)	\
    ( (This)->lpVtbl -> put_CompressionQuality(This,newVal) ) 

#define ILTDicWrt_SetDicomDSv14(This,newVal,pPixelData,bAutoSave,bCopy)	\
    ( (This)->lpVtbl -> SetDicomDSv14(This,newVal,pPixelData,bAutoSave,bCopy) ) 

#define ILTDicWrt_LockDicomDS(This,bLock)	\
    ( (This)->lpVtbl -> LockDicomDS(This,bLock) ) 

#define ILTDicWrt_get_IsMPEG2Stream(This,pVal)	\
    ( (This)->lpVtbl -> get_IsMPEG2Stream(This,pVal) ) 

#define ILTDicWrt_get_MPEG2DicomCompatibilityOption(This,pVal)	\
    ( (This)->lpVtbl -> get_MPEG2DicomCompatibilityOption(This,pVal) ) 

#define ILTDicWrt_put_MPEG2DicomCompatibilityOption(This,newVal)	\
    ( (This)->lpVtbl -> put_MPEG2DicomCompatibilityOption(This,newVal) ) 

#define ILTDicWrt_ResetToDefaults(This)	\
    ( (This)->lpVtbl -> ResetToDefaults(This) ) 


#define ILTDicWrt_get_RasterVersion(This,pVal)	\
    ( (This)->lpVtbl -> get_RasterVersion(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILTDicWrt_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_DICOMWrt;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DDD6-38C5-11D5-91F6-00104BDB8FF9")
DICOMWrt;
#endif
#endif /* __LTDicWrtLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


