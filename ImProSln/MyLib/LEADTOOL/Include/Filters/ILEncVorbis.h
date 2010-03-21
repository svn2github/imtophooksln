

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Nov 05 12:55:25 2009
 */
/* Compiler settings for .\ILEncVORBIS.idl:
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


#ifndef __ILEncVorbis_h__
#define __ILEncVorbis_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILMVorbisEncoder_FWD_DEFINED__
#define __ILMVorbisEncoder_FWD_DEFINED__
typedef interface ILMVorbisEncoder ILMVorbisEncoder;
#endif 	/* __ILMVorbisEncoder_FWD_DEFINED__ */


#ifndef __LMVorbisEncoder_FWD_DEFINED__
#define __LMVorbisEncoder_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMVorbisEncoder LMVorbisEncoder;
#else
typedef struct LMVorbisEncoder LMVorbisEncoder;
#endif /* __cplusplus */

#endif 	/* __LMVorbisEncoder_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LMVorbisEncoderLib_LIBRARY_DEFINED__
#define __LMVorbisEncoderLib_LIBRARY_DEFINED__

/* library LMVorbisEncoderLib */
/* [helpstring][version][uuid] */ 

#ifndef __ILMVORBISENCODER_H__
#define __ILMVORBISENCODER_H__
static const GUID CLSID_LMVorbisEncoder			    = {0xe2b7dc69, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVorbisEncoderProperty   = {0xe2b7dc6a, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVorbisAboutEncoder      = {0xe2b7dc6b, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID LIBID_LMVorbisEncoderLib        = {0xe2b7dc6c, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMVorbisEncoder            = {0xe2b7dc6d, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
#endif 
typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_ILEncVORBIS_0000_0000_0001
    {	R_08K	= 1,
	R_11K	= 2,
	R_22K	= 3,
	R_32K	= 4,
	R_44K	= 5,
	R_48K	= 6
    } 	eVORBISMAXRATE;

typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_ILEncVORBIS_0000_0000_0002
    {	C_1	= 1,
	C_2	= 2
    } 	eVORBISMAXCHANNELS;


EXTERN_C const IID LIBID_LMVorbisEncoderLib;

#ifndef __ILMVorbisEncoder_INTERFACE_DEFINED__
#define __ILMVorbisEncoder_INTERFACE_DEFINED__

/* interface ILMVorbisEncoder */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_ILMVorbisEncoder;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DC6D-38C5-11D5-91F6-00104BDB8FF9")
    ILMVorbisEncoder : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_QualityFactor( 
            /* [retval][out] */ long *plQualityFactor) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_QualityFactor( 
            /* [in] */ long newlQualityFactor) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MaximumByteRate( 
            /* [retval][out] */ long *plMaximumByteRate) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MaximumByteRate( 
            /* [in] */ long newlMaximumByteRate) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_NominalByteRate( 
            /* [retval][out] */ long *plNominalByteRate) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_NominalByteRate( 
            /* [in] */ long newlNominalByteRate) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MinimumByteRate( 
            /* [retval][out] */ long *plMinimumByteRate) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MinimumByteRate( 
            /* [in] */ long newlMinimumByteRate) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EnableQualityFactor( 
            /* [retval][out] */ VARIANT_BOOL *pbEnableQF) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_EnableQualityFactor( 
            /* [in] */ VARIANT_BOOL newbEnableQF) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SamplePerSec( 
            /* [retval][out] */ long *SamplePerSec) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Channels( 
            /* [retval][out] */ long *Channels) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MaximumInputRate( 
            /* [retval][out] */ eVORBISMAXRATE *pMaxRate) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MaximumInputRate( 
            /* [in] */ eVORBISMAXRATE eMaxRate) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MaximumInputChannels( 
            /* [retval][out] */ eVORBISMAXCHANNELS *pMaxChannels) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MaximumInputChannels( 
            /* [in] */ eVORBISMAXCHANNELS eMaxChannels) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsAVIMuxConnected( 
            /* [retval][out] */ VARIANT_BOOL *pbAviConnected) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMVorbisEncoderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMVorbisEncoder * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMVorbisEncoder * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMVorbisEncoder * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMVorbisEncoder * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMVorbisEncoder * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMVorbisEncoder * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMVorbisEncoder * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_QualityFactor )( 
            ILMVorbisEncoder * This,
            /* [retval][out] */ long *plQualityFactor);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_QualityFactor )( 
            ILMVorbisEncoder * This,
            /* [in] */ long newlQualityFactor);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MaximumByteRate )( 
            ILMVorbisEncoder * This,
            /* [retval][out] */ long *plMaximumByteRate);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MaximumByteRate )( 
            ILMVorbisEncoder * This,
            /* [in] */ long newlMaximumByteRate);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NominalByteRate )( 
            ILMVorbisEncoder * This,
            /* [retval][out] */ long *plNominalByteRate);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_NominalByteRate )( 
            ILMVorbisEncoder * This,
            /* [in] */ long newlNominalByteRate);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MinimumByteRate )( 
            ILMVorbisEncoder * This,
            /* [retval][out] */ long *plMinimumByteRate);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MinimumByteRate )( 
            ILMVorbisEncoder * This,
            /* [in] */ long newlMinimumByteRate);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableQualityFactor )( 
            ILMVorbisEncoder * This,
            /* [retval][out] */ VARIANT_BOOL *pbEnableQF);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableQualityFactor )( 
            ILMVorbisEncoder * This,
            /* [in] */ VARIANT_BOOL newbEnableQF);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SamplePerSec )( 
            ILMVorbisEncoder * This,
            /* [retval][out] */ long *SamplePerSec);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Channels )( 
            ILMVorbisEncoder * This,
            /* [retval][out] */ long *Channels);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MaximumInputRate )( 
            ILMVorbisEncoder * This,
            /* [retval][out] */ eVORBISMAXRATE *pMaxRate);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MaximumInputRate )( 
            ILMVorbisEncoder * This,
            /* [in] */ eVORBISMAXRATE eMaxRate);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MaximumInputChannels )( 
            ILMVorbisEncoder * This,
            /* [retval][out] */ eVORBISMAXCHANNELS *pMaxChannels);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MaximumInputChannels )( 
            ILMVorbisEncoder * This,
            /* [in] */ eVORBISMAXCHANNELS eMaxChannels);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsAVIMuxConnected )( 
            ILMVorbisEncoder * This,
            /* [retval][out] */ VARIANT_BOOL *pbAviConnected);
        
        END_INTERFACE
    } ILMVorbisEncoderVtbl;

    interface ILMVorbisEncoder
    {
        CONST_VTBL struct ILMVorbisEncoderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMVorbisEncoder_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMVorbisEncoder_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMVorbisEncoder_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMVorbisEncoder_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMVorbisEncoder_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMVorbisEncoder_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMVorbisEncoder_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMVorbisEncoder_get_QualityFactor(This,plQualityFactor)	\
    ( (This)->lpVtbl -> get_QualityFactor(This,plQualityFactor) ) 

#define ILMVorbisEncoder_put_QualityFactor(This,newlQualityFactor)	\
    ( (This)->lpVtbl -> put_QualityFactor(This,newlQualityFactor) ) 

#define ILMVorbisEncoder_get_MaximumByteRate(This,plMaximumByteRate)	\
    ( (This)->lpVtbl -> get_MaximumByteRate(This,plMaximumByteRate) ) 

#define ILMVorbisEncoder_put_MaximumByteRate(This,newlMaximumByteRate)	\
    ( (This)->lpVtbl -> put_MaximumByteRate(This,newlMaximumByteRate) ) 

#define ILMVorbisEncoder_get_NominalByteRate(This,plNominalByteRate)	\
    ( (This)->lpVtbl -> get_NominalByteRate(This,plNominalByteRate) ) 

#define ILMVorbisEncoder_put_NominalByteRate(This,newlNominalByteRate)	\
    ( (This)->lpVtbl -> put_NominalByteRate(This,newlNominalByteRate) ) 

#define ILMVorbisEncoder_get_MinimumByteRate(This,plMinimumByteRate)	\
    ( (This)->lpVtbl -> get_MinimumByteRate(This,plMinimumByteRate) ) 

#define ILMVorbisEncoder_put_MinimumByteRate(This,newlMinimumByteRate)	\
    ( (This)->lpVtbl -> put_MinimumByteRate(This,newlMinimumByteRate) ) 

#define ILMVorbisEncoder_get_EnableQualityFactor(This,pbEnableQF)	\
    ( (This)->lpVtbl -> get_EnableQualityFactor(This,pbEnableQF) ) 

#define ILMVorbisEncoder_put_EnableQualityFactor(This,newbEnableQF)	\
    ( (This)->lpVtbl -> put_EnableQualityFactor(This,newbEnableQF) ) 

#define ILMVorbisEncoder_get_SamplePerSec(This,SamplePerSec)	\
    ( (This)->lpVtbl -> get_SamplePerSec(This,SamplePerSec) ) 

#define ILMVorbisEncoder_get_Channels(This,Channels)	\
    ( (This)->lpVtbl -> get_Channels(This,Channels) ) 

#define ILMVorbisEncoder_get_MaximumInputRate(This,pMaxRate)	\
    ( (This)->lpVtbl -> get_MaximumInputRate(This,pMaxRate) ) 

#define ILMVorbisEncoder_put_MaximumInputRate(This,eMaxRate)	\
    ( (This)->lpVtbl -> put_MaximumInputRate(This,eMaxRate) ) 

#define ILMVorbisEncoder_get_MaximumInputChannels(This,pMaxChannels)	\
    ( (This)->lpVtbl -> get_MaximumInputChannels(This,pMaxChannels) ) 

#define ILMVorbisEncoder_put_MaximumInputChannels(This,eMaxChannels)	\
    ( (This)->lpVtbl -> put_MaximumInputChannels(This,eMaxChannels) ) 

#define ILMVorbisEncoder_get_IsAVIMuxConnected(This,pbAviConnected)	\
    ( (This)->lpVtbl -> get_IsAVIMuxConnected(This,pbAviConnected) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMVorbisEncoder_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LMVorbisEncoder;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DC69-38C5-11D5-91F6-00104BDB8FF9")
LMVorbisEncoder;
#endif
#endif /* __LMVorbisEncoderLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


