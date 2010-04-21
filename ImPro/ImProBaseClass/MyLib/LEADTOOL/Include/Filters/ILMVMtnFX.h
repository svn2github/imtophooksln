

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Nov 05 12:40:12 2009
 */
/* Compiler settings for .\MotionFX.idl:
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


#ifndef __ILMVMtnFX_h__
#define __ILMVMtnFX_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILMVMotionScan_FWD_DEFINED__
#define __ILMVMotionScan_FWD_DEFINED__
typedef interface ILMVMotionScan ILMVMotionScan;
#endif 	/* __ILMVMotionScan_FWD_DEFINED__ */


#ifndef __LMVMotionScan_FWD_DEFINED__
#define __LMVMotionScan_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMVMotionScan LMVMotionScan;
#else
typedef struct LMVMotionScan LMVMotionScan;
#endif /* __cplusplus */

#endif 	/* __LMVMotionScan_FWD_DEFINED__ */


#ifndef __ILMVStreak_FWD_DEFINED__
#define __ILMVStreak_FWD_DEFINED__
typedef interface ILMVStreak ILMVStreak;
#endif 	/* __ILMVStreak_FWD_DEFINED__ */


#ifndef __LMVStreak_FWD_DEFINED__
#define __LMVStreak_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMVStreak LMVStreak;
#else
typedef struct LMVStreak LMVStreak;
#endif /* __cplusplus */

#endif 	/* __LMVStreak_FWD_DEFINED__ */


#ifndef __ILMVFire_FWD_DEFINED__
#define __ILMVFire_FWD_DEFINED__
typedef interface ILMVFire ILMVFire;
#endif 	/* __ILMVFire_FWD_DEFINED__ */


#ifndef __LMVFire_FWD_DEFINED__
#define __LMVFire_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMVFire LMVFire;
#else
typedef struct LMVFire LMVFire;
#endif /* __cplusplus */

#endif 	/* __LMVFire_FWD_DEFINED__ */


#ifndef __ILMVHologram_FWD_DEFINED__
#define __ILMVHologram_FWD_DEFINED__
typedef interface ILMVHologram ILMVHologram;
#endif 	/* __ILMVHologram_FWD_DEFINED__ */


#ifndef __LMVHologram_FWD_DEFINED__
#define __LMVHologram_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMVHologram LMVHologram;
#else
typedef struct LMVHologram LMVHologram;
#endif /* __cplusplus */

#endif 	/* __LMVHologram_FWD_DEFINED__ */


#ifndef __ILMVParticles_FWD_DEFINED__
#define __ILMVParticles_FWD_DEFINED__
typedef interface ILMVParticles ILMVParticles;
#endif 	/* __ILMVParticles_FWD_DEFINED__ */


#ifndef __LMVParticles_FWD_DEFINED__
#define __LMVParticles_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMVParticles LMVParticles;
#else
typedef struct LMVParticles LMVParticles;
#endif /* __cplusplus */

#endif 	/* __LMVParticles_FWD_DEFINED__ */


#ifndef __ILMVMotionMosaic_FWD_DEFINED__
#define __ILMVMotionMosaic_FWD_DEFINED__
typedef interface ILMVMotionMosaic ILMVMotionMosaic;
#endif 	/* __ILMVMotionMosaic_FWD_DEFINED__ */


#ifndef __LMVMotionMosaic_FWD_DEFINED__
#define __LMVMotionMosaic_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMVMotionMosaic LMVMotionMosaic;
#else
typedef struct LMVMotionMosaic LMVMotionMosaic;
#endif /* __cplusplus */

#endif 	/* __LMVMotionMosaic_FWD_DEFINED__ */


#ifndef __ILMVMotionBlur1_FWD_DEFINED__
#define __ILMVMotionBlur1_FWD_DEFINED__
typedef interface ILMVMotionBlur1 ILMVMotionBlur1;
#endif 	/* __ILMVMotionBlur1_FWD_DEFINED__ */


#ifndef __ILMVMotionBlur_FWD_DEFINED__
#define __ILMVMotionBlur_FWD_DEFINED__
typedef interface ILMVMotionBlur ILMVMotionBlur;
#endif 	/* __ILMVMotionBlur_FWD_DEFINED__ */


#ifndef __LMVMotionBlur_FWD_DEFINED__
#define __LMVMotionBlur_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMVMotionBlur LMVMotionBlur;
#else
typedef struct LMVMotionBlur LMVMotionBlur;
#endif /* __cplusplus */

#endif 	/* __LMVMotionBlur_FWD_DEFINED__ */


#ifndef __ILMVWave_FWD_DEFINED__
#define __ILMVWave_FWD_DEFINED__
typedef interface ILMVWave ILMVWave;
#endif 	/* __ILMVWave_FWD_DEFINED__ */


#ifndef __LMVWave_FWD_DEFINED__
#define __LMVWave_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMVWave LMVWave;
#else
typedef struct LMVWave LMVWave;
#endif /* __cplusplus */

#endif 	/* __LMVWave_FWD_DEFINED__ */


#ifndef __ILMVLightning_FWD_DEFINED__
#define __ILMVLightning_FWD_DEFINED__
typedef interface ILMVLightning ILMVLightning;
#endif 	/* __ILMVLightning_FWD_DEFINED__ */


#ifndef __LMVLightning_FWD_DEFINED__
#define __LMVLightning_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMVLightning LMVLightning;
#else
typedef struct LMVLightning LMVLightning;
#endif /* __cplusplus */

#endif 	/* __LMVLightning_FWD_DEFINED__ */


#ifndef __ILMVMotionEmboss_FWD_DEFINED__
#define __ILMVMotionEmboss_FWD_DEFINED__
typedef interface ILMVMotionEmboss ILMVMotionEmboss;
#endif 	/* __ILMVMotionEmboss_FWD_DEFINED__ */


#ifndef __LMVMotionEmboss_FWD_DEFINED__
#define __LMVMotionEmboss_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMVMotionEmboss LMVMotionEmboss;
#else
typedef struct LMVMotionEmboss LMVMotionEmboss;
#endif /* __cplusplus */

#endif 	/* __LMVMotionEmboss_FWD_DEFINED__ */


#ifndef __ILMVGhost_FWD_DEFINED__
#define __ILMVGhost_FWD_DEFINED__
typedef interface ILMVGhost ILMVGhost;
#endif 	/* __ILMVGhost_FWD_DEFINED__ */


#ifndef __LMVGhost_FWD_DEFINED__
#define __LMVGhost_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMVGhost LMVGhost;
#else
typedef struct LMVGhost LMVGhost;
#endif /* __cplusplus */

#endif 	/* __LMVGhost_FWD_DEFINED__ */


#ifndef __ILMVBright_FWD_DEFINED__
#define __ILMVBright_FWD_DEFINED__
typedef interface ILMVBright ILMVBright;
#endif 	/* __ILMVBright_FWD_DEFINED__ */


#ifndef __LMVBright_FWD_DEFINED__
#define __LMVBright_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMVBright LMVBright;
#else
typedef struct LMVBright LMVBright;
#endif /* __cplusplus */

#endif 	/* __LMVBright_FWD_DEFINED__ */


#ifndef __ILMVPredator_FWD_DEFINED__
#define __ILMVPredator_FWD_DEFINED__
typedef interface ILMVPredator ILMVPredator;
#endif 	/* __ILMVPredator_FWD_DEFINED__ */


#ifndef __LMVPredator_FWD_DEFINED__
#define __LMVPredator_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMVPredator LMVPredator;
#else
typedef struct LMVPredator LMVPredator;
#endif /* __cplusplus */

#endif 	/* __LMVPredator_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LMVMotionFXLib_LIBRARY_DEFINED__
#define __LMVMotionFXLib_LIBRARY_DEFINED__

/* library LMVMotionFXLib */
/* [helpstring][version][uuid] */ 

#ifndef __MOTIONFX_H__
#define __MOTIONFX_H__
static const GUID LIBID_LMVMotionFXLib = {0xe2b7dbf6, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVMotionScan             = {0xe2b7dbf7, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVMotionScanPropertyPage = {0xe2b7dbf8, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVAboutMotionScan        = {0xe2b7dbf9, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMVMotionScan              = {0xe2b7dbfa, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVStreak             = {0xe2b7dbfb, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVStreakPropertyPage = {0xe2b7dbfc, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVAboutStreak        = {0xe2b7dbfd, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMVStreak              = {0xe2b7dbfe, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVFire             = {0xe2b7dbff, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVFirePropertyPage = {0xe2b7dc00, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVAboutFire        = {0xe2b7dc01, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMVFire              = {0xe2b7dc02, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVHologram             = {0xe2b7dc03, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVHologramPropertyPage = {0xe2b7dc04, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVAboutHologram        = {0xe2b7dc05, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMVHologram              = {0xe2b7dc06, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVParticles             = {0xe2b7dc07, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVParticlesPropertyPage = {0xe2b7dc08, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVAboutParticles        = {0xe2b7dc09, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMVParticles              = {0xe2b7dc0a, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVMotionMosaic             = {0xe2b7dc0b, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVMotionMosaicPropertyPage = {0xe2b7dc0c, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVAboutMotionMosaic        = {0xe2b7dc0d, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMVMotionMosaic              = {0xe2b7dc0e, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVMotionBlur             = {0xe2b7dc0f, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVMotionBlurPropertyPage = {0xe2b7dc10, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVAboutMotionBlur        = {0xe2b7dc11, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMVMotionBlur1             = {0xe2b7dc12, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMVMotionBlur              = {0xe2b7dd30, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVWave             = {0xe2b7dc13, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVWavePropertyPage = {0xe2b7dc14, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVAboutWave        = {0xe2b7dc15, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMVWave              = {0xe2b7dc16, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVLightning             = {0xe2b7dc17, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVLightningPropertyPage = {0xe2b7dc18, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVAboutLightning        = {0xe2b7dc19, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMVLightning              = {0xe2b7dc1a, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVMotionEmboss             = {0xe2b7dc1b, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVMotionEmbossPropertyPage = {0xe2b7dc1c, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVAboutMotionEmboss        = {0xe2b7dc1d, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMVMotionEmboss              = {0xe2b7dc1e, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVGhost             = {0xe2b7dc1f, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVGhostPropertyPage = {0xe2b7dc20, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVAboutGhost        = {0xe2b7dc21, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMVGhost              = {0xe2b7dc22, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVBright             = {0xe2b7dd1d, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVBrightPropertyPage = {0xe2b7dd1e, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVAboutBright        = {0xe2b7dd1f, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMVBright              = {0xe2b7dd20, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVPredator             = {0xe2b7dd2a, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVPredatorPropertyPage = {0xe2b7dd2b, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID CLSID_LMVAboutPredator        = {0xe2b7dd2c, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
static const GUID IID_ILMVPredator              = {0xe2b7dd2d, 0x38c5, 0x11d5, {0x91, 0xf6, 0x00, 0x10, 0x4b, 0xdb, 0x8f, 0xf9}};
#endif
typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_MotionFX_0001_0065_0001
    {	DIR_NORTH	= 1,
	DIR_SOUTH	= 2,
	DIR_EAST	= 4,
	DIR_WEST	= 8,
	DIR_NORTHEAST	= 16,
	DIR_NORTHWEST	= 32,
	DIR_SOUTHEAST	= 64,
	DIR_SOUTHWEST	= 128,
	DIR_GLOW	= 256
    } 	DIRECTION;

typedef /* [public][public][public][public][public][public][public][public][public] */ 
enum __MIDL___MIDL_itf_MotionFX_0001_0065_0002
    {	REF_USEBUFFER	= 0,
	REF_USENEXTFRAME	= ( REF_USEBUFFER + 1 ) ,
	REF_USECOLOR	= ( REF_USENEXTFRAME + 1 ) 
    } 	REFERENCE_FRAME;

typedef /* [v1_enum] */ 
enum HorizontalDirectionConstants
    {	HORIZONTAL_DIRECTION_LEFT	= 0,
	HORIZONTAL_DIRECTION_RIGHT	= 1
    } 	HorizontalDirectionConstants;

typedef /* [v1_enum] */ 
enum VerticalDirectionConstants
    {	VERTICAL_DIRECTION_UP	= 0,
	VERTICAL_DIRECTION_DOWN	= 1
    } 	VerticalDirectionConstants;


EXTERN_C const IID LIBID_LMVMotionFXLib;

#ifndef __ILMVMotionScan_INTERFACE_DEFINED__
#define __ILMVMotionScan_INTERFACE_DEFINED__

/* interface ILMVMotionScan */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILMVMotionScan;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DBFA-38C5-11D5-91F6-00104BDB8FF9")
    ILMVMotionScan : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Enabled( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Enabled( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Left( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Left( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Top( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Top( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Right( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Right( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Bottom( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Bottom( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EffectAreaEnabled( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_EffectAreaEnabled( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LineIncrement( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_LineIncrement( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ShowScanLine( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ShowScanLine( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMVMotionScanVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMVMotionScan * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMVMotionScan * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMVMotionScan * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMVMotionScan * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMVMotionScan * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMVMotionScan * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMVMotionScan * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Enabled )( 
            ILMVMotionScan * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Enabled )( 
            ILMVMotionScan * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Left )( 
            ILMVMotionScan * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Left )( 
            ILMVMotionScan * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Top )( 
            ILMVMotionScan * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Top )( 
            ILMVMotionScan * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Right )( 
            ILMVMotionScan * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Right )( 
            ILMVMotionScan * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Bottom )( 
            ILMVMotionScan * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Bottom )( 
            ILMVMotionScan * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EffectAreaEnabled )( 
            ILMVMotionScan * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EffectAreaEnabled )( 
            ILMVMotionScan * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LineIncrement )( 
            ILMVMotionScan * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LineIncrement )( 
            ILMVMotionScan * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ShowScanLine )( 
            ILMVMotionScan * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ShowScanLine )( 
            ILMVMotionScan * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        END_INTERFACE
    } ILMVMotionScanVtbl;

    interface ILMVMotionScan
    {
        CONST_VTBL struct ILMVMotionScanVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMVMotionScan_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMVMotionScan_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMVMotionScan_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMVMotionScan_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMVMotionScan_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMVMotionScan_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMVMotionScan_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMVMotionScan_get_Enabled(This,pVal)	\
    ( (This)->lpVtbl -> get_Enabled(This,pVal) ) 

#define ILMVMotionScan_put_Enabled(This,newVal)	\
    ( (This)->lpVtbl -> put_Enabled(This,newVal) ) 

#define ILMVMotionScan_get_Left(This,pVal)	\
    ( (This)->lpVtbl -> get_Left(This,pVal) ) 

#define ILMVMotionScan_put_Left(This,newVal)	\
    ( (This)->lpVtbl -> put_Left(This,newVal) ) 

#define ILMVMotionScan_get_Top(This,pVal)	\
    ( (This)->lpVtbl -> get_Top(This,pVal) ) 

#define ILMVMotionScan_put_Top(This,newVal)	\
    ( (This)->lpVtbl -> put_Top(This,newVal) ) 

#define ILMVMotionScan_get_Right(This,pVal)	\
    ( (This)->lpVtbl -> get_Right(This,pVal) ) 

#define ILMVMotionScan_put_Right(This,newVal)	\
    ( (This)->lpVtbl -> put_Right(This,newVal) ) 

#define ILMVMotionScan_get_Bottom(This,pVal)	\
    ( (This)->lpVtbl -> get_Bottom(This,pVal) ) 

#define ILMVMotionScan_put_Bottom(This,newVal)	\
    ( (This)->lpVtbl -> put_Bottom(This,newVal) ) 

#define ILMVMotionScan_get_EffectAreaEnabled(This,pVal)	\
    ( (This)->lpVtbl -> get_EffectAreaEnabled(This,pVal) ) 

#define ILMVMotionScan_put_EffectAreaEnabled(This,newVal)	\
    ( (This)->lpVtbl -> put_EffectAreaEnabled(This,newVal) ) 

#define ILMVMotionScan_get_LineIncrement(This,pVal)	\
    ( (This)->lpVtbl -> get_LineIncrement(This,pVal) ) 

#define ILMVMotionScan_put_LineIncrement(This,newVal)	\
    ( (This)->lpVtbl -> put_LineIncrement(This,newVal) ) 

#define ILMVMotionScan_get_ShowScanLine(This,pVal)	\
    ( (This)->lpVtbl -> get_ShowScanLine(This,pVal) ) 

#define ILMVMotionScan_put_ShowScanLine(This,newVal)	\
    ( (This)->lpVtbl -> put_ShowScanLine(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMVMotionScan_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LMVMotionScan;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DBF7-38C5-11D5-91F6-00104BDB8FF9")
LMVMotionScan;
#endif

#ifndef __ILMVStreak_INTERFACE_DEFINED__
#define __ILMVStreak_INTERFACE_DEFINED__

/* interface ILMVStreak */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILMVStreak;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DBFE-38C5-11D5-91F6-00104BDB8FF9")
    ILMVStreak : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Enabled( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Enabled( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HeavyMode( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_HeavyMode( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMVStreakVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMVStreak * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMVStreak * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMVStreak * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMVStreak * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMVStreak * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMVStreak * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMVStreak * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Enabled )( 
            ILMVStreak * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Enabled )( 
            ILMVStreak * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HeavyMode )( 
            ILMVStreak * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_HeavyMode )( 
            ILMVStreak * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        END_INTERFACE
    } ILMVStreakVtbl;

    interface ILMVStreak
    {
        CONST_VTBL struct ILMVStreakVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMVStreak_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMVStreak_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMVStreak_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMVStreak_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMVStreak_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMVStreak_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMVStreak_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMVStreak_get_Enabled(This,pVal)	\
    ( (This)->lpVtbl -> get_Enabled(This,pVal) ) 

#define ILMVStreak_put_Enabled(This,newVal)	\
    ( (This)->lpVtbl -> put_Enabled(This,newVal) ) 

#define ILMVStreak_get_HeavyMode(This,pVal)	\
    ( (This)->lpVtbl -> get_HeavyMode(This,pVal) ) 

#define ILMVStreak_put_HeavyMode(This,newVal)	\
    ( (This)->lpVtbl -> put_HeavyMode(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMVStreak_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LMVStreak;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DBFB-38C5-11D5-91F6-00104BDB8FF9")
LMVStreak;
#endif

#ifndef __ILMVFire_INTERFACE_DEFINED__
#define __ILMVFire_INTERFACE_DEFINED__

/* interface ILMVFire */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILMVFire;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DC02-38C5-11D5-91F6-00104BDB8FF9")
    ILMVFire : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Enabled( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Enabled( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Direction( 
            /* [retval][out] */ DIRECTION *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Direction( 
            /* [in] */ DIRECTION newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Decay( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Decay( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ColorsOffset( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ColorsOffset( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_GradientLevel( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_GradientLevel( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetReferenceFrame( 
            /* [in] */ byte *pBuffer,
            /* [in] */ long lRGBColor,
            /* [in] */ REFERENCE_FRAME opt) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Burn( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Burn( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Fire( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Fire( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ShowBackground( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ShowBackground( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FirstFrameIsReference( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FirstFrameIsReference( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Threshold( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Threshold( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_NoReferenceFrame( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_NoReferenceFrame( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMVFireVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMVFire * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMVFire * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMVFire * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMVFire * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMVFire * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMVFire * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMVFire * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Enabled )( 
            ILMVFire * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Enabled )( 
            ILMVFire * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Direction )( 
            ILMVFire * This,
            /* [retval][out] */ DIRECTION *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Direction )( 
            ILMVFire * This,
            /* [in] */ DIRECTION newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Decay )( 
            ILMVFire * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Decay )( 
            ILMVFire * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ColorsOffset )( 
            ILMVFire * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ColorsOffset )( 
            ILMVFire * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_GradientLevel )( 
            ILMVFire * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_GradientLevel )( 
            ILMVFire * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetReferenceFrame )( 
            ILMVFire * This,
            /* [in] */ byte *pBuffer,
            /* [in] */ long lRGBColor,
            /* [in] */ REFERENCE_FRAME opt);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Burn )( 
            ILMVFire * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Burn )( 
            ILMVFire * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Fire )( 
            ILMVFire * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Fire )( 
            ILMVFire * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ShowBackground )( 
            ILMVFire * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ShowBackground )( 
            ILMVFire * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FirstFrameIsReference )( 
            ILMVFire * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FirstFrameIsReference )( 
            ILMVFire * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Threshold )( 
            ILMVFire * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Threshold )( 
            ILMVFire * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NoReferenceFrame )( 
            ILMVFire * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_NoReferenceFrame )( 
            ILMVFire * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        END_INTERFACE
    } ILMVFireVtbl;

    interface ILMVFire
    {
        CONST_VTBL struct ILMVFireVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMVFire_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMVFire_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMVFire_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMVFire_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMVFire_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMVFire_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMVFire_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMVFire_get_Enabled(This,pVal)	\
    ( (This)->lpVtbl -> get_Enabled(This,pVal) ) 

#define ILMVFire_put_Enabled(This,newVal)	\
    ( (This)->lpVtbl -> put_Enabled(This,newVal) ) 

#define ILMVFire_get_Direction(This,pVal)	\
    ( (This)->lpVtbl -> get_Direction(This,pVal) ) 

#define ILMVFire_put_Direction(This,newVal)	\
    ( (This)->lpVtbl -> put_Direction(This,newVal) ) 

#define ILMVFire_get_Decay(This,pVal)	\
    ( (This)->lpVtbl -> get_Decay(This,pVal) ) 

#define ILMVFire_put_Decay(This,newVal)	\
    ( (This)->lpVtbl -> put_Decay(This,newVal) ) 

#define ILMVFire_get_ColorsOffset(This,pVal)	\
    ( (This)->lpVtbl -> get_ColorsOffset(This,pVal) ) 

#define ILMVFire_put_ColorsOffset(This,newVal)	\
    ( (This)->lpVtbl -> put_ColorsOffset(This,newVal) ) 

#define ILMVFire_get_GradientLevel(This,pVal)	\
    ( (This)->lpVtbl -> get_GradientLevel(This,pVal) ) 

#define ILMVFire_put_GradientLevel(This,newVal)	\
    ( (This)->lpVtbl -> put_GradientLevel(This,newVal) ) 

#define ILMVFire_SetReferenceFrame(This,pBuffer,lRGBColor,opt)	\
    ( (This)->lpVtbl -> SetReferenceFrame(This,pBuffer,lRGBColor,opt) ) 

#define ILMVFire_get_Burn(This,pVal)	\
    ( (This)->lpVtbl -> get_Burn(This,pVal) ) 

#define ILMVFire_put_Burn(This,newVal)	\
    ( (This)->lpVtbl -> put_Burn(This,newVal) ) 

#define ILMVFire_get_Fire(This,pVal)	\
    ( (This)->lpVtbl -> get_Fire(This,pVal) ) 

#define ILMVFire_put_Fire(This,newVal)	\
    ( (This)->lpVtbl -> put_Fire(This,newVal) ) 

#define ILMVFire_get_ShowBackground(This,pVal)	\
    ( (This)->lpVtbl -> get_ShowBackground(This,pVal) ) 

#define ILMVFire_put_ShowBackground(This,newVal)	\
    ( (This)->lpVtbl -> put_ShowBackground(This,newVal) ) 

#define ILMVFire_get_FirstFrameIsReference(This,pVal)	\
    ( (This)->lpVtbl -> get_FirstFrameIsReference(This,pVal) ) 

#define ILMVFire_put_FirstFrameIsReference(This,newVal)	\
    ( (This)->lpVtbl -> put_FirstFrameIsReference(This,newVal) ) 

#define ILMVFire_get_Threshold(This,pVal)	\
    ( (This)->lpVtbl -> get_Threshold(This,pVal) ) 

#define ILMVFire_put_Threshold(This,newVal)	\
    ( (This)->lpVtbl -> put_Threshold(This,newVal) ) 

#define ILMVFire_get_NoReferenceFrame(This,pVal)	\
    ( (This)->lpVtbl -> get_NoReferenceFrame(This,pVal) ) 

#define ILMVFire_put_NoReferenceFrame(This,newVal)	\
    ( (This)->lpVtbl -> put_NoReferenceFrame(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMVFire_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LMVFire;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DBFF-38C5-11D5-91F6-00104BDB8FF9")
LMVFire;
#endif

#ifndef __ILMVHologram_INTERFACE_DEFINED__
#define __ILMVHologram_INTERFACE_DEFINED__

/* interface ILMVHologram */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILMVHologram;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DC06-38C5-11D5-91F6-00104BDB8FF9")
    ILMVHologram : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Enabled( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Enabled( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Hue( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Hue( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetReferenceFrame( 
            /* [in] */ byte *pBuffer,
            /* [in] */ long lRGBColor,
            /* [in] */ REFERENCE_FRAME opt) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FirstFrameIsReference( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FirstFrameIsReference( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LineNoise( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_LineNoise( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Noise( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Noise( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Threshold( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Threshold( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_NoReferenceFrame( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_NoReferenceFrame( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMVHologramVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMVHologram * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMVHologram * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMVHologram * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMVHologram * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMVHologram * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMVHologram * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMVHologram * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Enabled )( 
            ILMVHologram * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Enabled )( 
            ILMVHologram * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Hue )( 
            ILMVHologram * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Hue )( 
            ILMVHologram * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetReferenceFrame )( 
            ILMVHologram * This,
            /* [in] */ byte *pBuffer,
            /* [in] */ long lRGBColor,
            /* [in] */ REFERENCE_FRAME opt);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FirstFrameIsReference )( 
            ILMVHologram * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FirstFrameIsReference )( 
            ILMVHologram * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LineNoise )( 
            ILMVHologram * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LineNoise )( 
            ILMVHologram * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Noise )( 
            ILMVHologram * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Noise )( 
            ILMVHologram * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Threshold )( 
            ILMVHologram * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Threshold )( 
            ILMVHologram * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NoReferenceFrame )( 
            ILMVHologram * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_NoReferenceFrame )( 
            ILMVHologram * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        END_INTERFACE
    } ILMVHologramVtbl;

    interface ILMVHologram
    {
        CONST_VTBL struct ILMVHologramVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMVHologram_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMVHologram_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMVHologram_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMVHologram_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMVHologram_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMVHologram_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMVHologram_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMVHologram_get_Enabled(This,pVal)	\
    ( (This)->lpVtbl -> get_Enabled(This,pVal) ) 

#define ILMVHologram_put_Enabled(This,newVal)	\
    ( (This)->lpVtbl -> put_Enabled(This,newVal) ) 

#define ILMVHologram_get_Hue(This,pVal)	\
    ( (This)->lpVtbl -> get_Hue(This,pVal) ) 

#define ILMVHologram_put_Hue(This,newVal)	\
    ( (This)->lpVtbl -> put_Hue(This,newVal) ) 

#define ILMVHologram_SetReferenceFrame(This,pBuffer,lRGBColor,opt)	\
    ( (This)->lpVtbl -> SetReferenceFrame(This,pBuffer,lRGBColor,opt) ) 

#define ILMVHologram_get_FirstFrameIsReference(This,pVal)	\
    ( (This)->lpVtbl -> get_FirstFrameIsReference(This,pVal) ) 

#define ILMVHologram_put_FirstFrameIsReference(This,newVal)	\
    ( (This)->lpVtbl -> put_FirstFrameIsReference(This,newVal) ) 

#define ILMVHologram_get_LineNoise(This,pVal)	\
    ( (This)->lpVtbl -> get_LineNoise(This,pVal) ) 

#define ILMVHologram_put_LineNoise(This,newVal)	\
    ( (This)->lpVtbl -> put_LineNoise(This,newVal) ) 

#define ILMVHologram_get_Noise(This,pVal)	\
    ( (This)->lpVtbl -> get_Noise(This,pVal) ) 

#define ILMVHologram_put_Noise(This,newVal)	\
    ( (This)->lpVtbl -> put_Noise(This,newVal) ) 

#define ILMVHologram_get_Threshold(This,pVal)	\
    ( (This)->lpVtbl -> get_Threshold(This,pVal) ) 

#define ILMVHologram_put_Threshold(This,newVal)	\
    ( (This)->lpVtbl -> put_Threshold(This,newVal) ) 

#define ILMVHologram_get_NoReferenceFrame(This,pVal)	\
    ( (This)->lpVtbl -> get_NoReferenceFrame(This,pVal) ) 

#define ILMVHologram_put_NoReferenceFrame(This,newVal)	\
    ( (This)->lpVtbl -> put_NoReferenceFrame(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMVHologram_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LMVHologram;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DC03-38C5-11D5-91F6-00104BDB8FF9")
LMVHologram;
#endif

#ifndef __ILMVParticles_INTERFACE_DEFINED__
#define __ILMVParticles_INTERFACE_DEFINED__

/* interface ILMVParticles */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILMVParticles;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DC0A-38C5-11D5-91F6-00104BDB8FF9")
    ILMVParticles : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Enabled( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Enabled( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Distortion( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Distortion( 
            /* [in] */ long newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMVParticlesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMVParticles * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMVParticles * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMVParticles * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMVParticles * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMVParticles * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMVParticles * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMVParticles * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Enabled )( 
            ILMVParticles * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Enabled )( 
            ILMVParticles * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Distortion )( 
            ILMVParticles * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Distortion )( 
            ILMVParticles * This,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } ILMVParticlesVtbl;

    interface ILMVParticles
    {
        CONST_VTBL struct ILMVParticlesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMVParticles_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMVParticles_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMVParticles_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMVParticles_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMVParticles_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMVParticles_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMVParticles_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMVParticles_get_Enabled(This,pVal)	\
    ( (This)->lpVtbl -> get_Enabled(This,pVal) ) 

#define ILMVParticles_put_Enabled(This,newVal)	\
    ( (This)->lpVtbl -> put_Enabled(This,newVal) ) 

#define ILMVParticles_get_Distortion(This,pVal)	\
    ( (This)->lpVtbl -> get_Distortion(This,pVal) ) 

#define ILMVParticles_put_Distortion(This,newVal)	\
    ( (This)->lpVtbl -> put_Distortion(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMVParticles_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LMVParticles;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DC07-38C5-11D5-91F6-00104BDB8FF9")
LMVParticles;
#endif

#ifndef __ILMVMotionMosaic_INTERFACE_DEFINED__
#define __ILMVMotionMosaic_INTERFACE_DEFINED__

/* interface ILMVMotionMosaic */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILMVMotionMosaic;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DC0E-38C5-11D5-91F6-00104BDB8FF9")
    ILMVMotionMosaic : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Enabled( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Enabled( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SquareSize( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SquareSize( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Threshold( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Threshold( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetReferenceFrame( 
            /* [in] */ byte *pBuffer,
            /* [in] */ long lRGBColor,
            /* [in] */ REFERENCE_FRAME opt) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FirstFrameIsReference( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FirstFrameIsReference( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_NoReferenceFrame( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_NoReferenceFrame( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMVMotionMosaicVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMVMotionMosaic * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMVMotionMosaic * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMVMotionMosaic * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMVMotionMosaic * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMVMotionMosaic * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMVMotionMosaic * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMVMotionMosaic * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Enabled )( 
            ILMVMotionMosaic * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Enabled )( 
            ILMVMotionMosaic * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SquareSize )( 
            ILMVMotionMosaic * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SquareSize )( 
            ILMVMotionMosaic * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Threshold )( 
            ILMVMotionMosaic * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Threshold )( 
            ILMVMotionMosaic * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetReferenceFrame )( 
            ILMVMotionMosaic * This,
            /* [in] */ byte *pBuffer,
            /* [in] */ long lRGBColor,
            /* [in] */ REFERENCE_FRAME opt);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FirstFrameIsReference )( 
            ILMVMotionMosaic * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FirstFrameIsReference )( 
            ILMVMotionMosaic * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NoReferenceFrame )( 
            ILMVMotionMosaic * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_NoReferenceFrame )( 
            ILMVMotionMosaic * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        END_INTERFACE
    } ILMVMotionMosaicVtbl;

    interface ILMVMotionMosaic
    {
        CONST_VTBL struct ILMVMotionMosaicVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMVMotionMosaic_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMVMotionMosaic_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMVMotionMosaic_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMVMotionMosaic_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMVMotionMosaic_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMVMotionMosaic_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMVMotionMosaic_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMVMotionMosaic_get_Enabled(This,pVal)	\
    ( (This)->lpVtbl -> get_Enabled(This,pVal) ) 

#define ILMVMotionMosaic_put_Enabled(This,newVal)	\
    ( (This)->lpVtbl -> put_Enabled(This,newVal) ) 

#define ILMVMotionMosaic_get_SquareSize(This,pVal)	\
    ( (This)->lpVtbl -> get_SquareSize(This,pVal) ) 

#define ILMVMotionMosaic_put_SquareSize(This,newVal)	\
    ( (This)->lpVtbl -> put_SquareSize(This,newVal) ) 

#define ILMVMotionMosaic_get_Threshold(This,pVal)	\
    ( (This)->lpVtbl -> get_Threshold(This,pVal) ) 

#define ILMVMotionMosaic_put_Threshold(This,newVal)	\
    ( (This)->lpVtbl -> put_Threshold(This,newVal) ) 

#define ILMVMotionMosaic_SetReferenceFrame(This,pBuffer,lRGBColor,opt)	\
    ( (This)->lpVtbl -> SetReferenceFrame(This,pBuffer,lRGBColor,opt) ) 

#define ILMVMotionMosaic_get_FirstFrameIsReference(This,pVal)	\
    ( (This)->lpVtbl -> get_FirstFrameIsReference(This,pVal) ) 

#define ILMVMotionMosaic_put_FirstFrameIsReference(This,newVal)	\
    ( (This)->lpVtbl -> put_FirstFrameIsReference(This,newVal) ) 

#define ILMVMotionMosaic_get_NoReferenceFrame(This,pVal)	\
    ( (This)->lpVtbl -> get_NoReferenceFrame(This,pVal) ) 

#define ILMVMotionMosaic_put_NoReferenceFrame(This,newVal)	\
    ( (This)->lpVtbl -> put_NoReferenceFrame(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMVMotionMosaic_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LMVMotionMosaic;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DC0B-38C5-11D5-91F6-00104BDB8FF9")
LMVMotionMosaic;
#endif

#ifndef __ILMVMotionBlur1_INTERFACE_DEFINED__
#define __ILMVMotionBlur1_INTERFACE_DEFINED__

/* interface ILMVMotionBlur1 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILMVMotionBlur1;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DC12-38C5-11D5-91F6-00104BDB8FF9")
    ILMVMotionBlur1 : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Enabled( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Enabled( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Hue( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Hue( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Threshold( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Threshold( 
            /* [in] */ long newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMVMotionBlur1Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMVMotionBlur1 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMVMotionBlur1 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMVMotionBlur1 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMVMotionBlur1 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMVMotionBlur1 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMVMotionBlur1 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMVMotionBlur1 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Enabled )( 
            ILMVMotionBlur1 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Enabled )( 
            ILMVMotionBlur1 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Hue )( 
            ILMVMotionBlur1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Hue )( 
            ILMVMotionBlur1 * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Threshold )( 
            ILMVMotionBlur1 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Threshold )( 
            ILMVMotionBlur1 * This,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } ILMVMotionBlur1Vtbl;

    interface ILMVMotionBlur1
    {
        CONST_VTBL struct ILMVMotionBlur1Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMVMotionBlur1_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMVMotionBlur1_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMVMotionBlur1_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMVMotionBlur1_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMVMotionBlur1_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMVMotionBlur1_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMVMotionBlur1_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMVMotionBlur1_get_Enabled(This,pVal)	\
    ( (This)->lpVtbl -> get_Enabled(This,pVal) ) 

#define ILMVMotionBlur1_put_Enabled(This,newVal)	\
    ( (This)->lpVtbl -> put_Enabled(This,newVal) ) 

#define ILMVMotionBlur1_get_Hue(This,pVal)	\
    ( (This)->lpVtbl -> get_Hue(This,pVal) ) 

#define ILMVMotionBlur1_put_Hue(This,newVal)	\
    ( (This)->lpVtbl -> put_Hue(This,newVal) ) 

#define ILMVMotionBlur1_get_Threshold(This,pVal)	\
    ( (This)->lpVtbl -> get_Threshold(This,pVal) ) 

#define ILMVMotionBlur1_put_Threshold(This,newVal)	\
    ( (This)->lpVtbl -> put_Threshold(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMVMotionBlur1_INTERFACE_DEFINED__ */


#ifndef __ILMVMotionBlur_INTERFACE_DEFINED__
#define __ILMVMotionBlur_INTERFACE_DEFINED__

/* interface ILMVMotionBlur */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILMVMotionBlur;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DD30-38C5-11D5-91F6-00104BDB8FF9")
    ILMVMotionBlur : public ILMVMotionBlur1
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Interval( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Interval( 
            /* [in] */ long newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMVMotionBlurVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMVMotionBlur * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMVMotionBlur * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMVMotionBlur * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMVMotionBlur * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMVMotionBlur * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMVMotionBlur * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMVMotionBlur * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Enabled )( 
            ILMVMotionBlur * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Enabled )( 
            ILMVMotionBlur * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Hue )( 
            ILMVMotionBlur * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Hue )( 
            ILMVMotionBlur * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Threshold )( 
            ILMVMotionBlur * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Threshold )( 
            ILMVMotionBlur * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Interval )( 
            ILMVMotionBlur * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Interval )( 
            ILMVMotionBlur * This,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } ILMVMotionBlurVtbl;

    interface ILMVMotionBlur
    {
        CONST_VTBL struct ILMVMotionBlurVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMVMotionBlur_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMVMotionBlur_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMVMotionBlur_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMVMotionBlur_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMVMotionBlur_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMVMotionBlur_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMVMotionBlur_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMVMotionBlur_get_Enabled(This,pVal)	\
    ( (This)->lpVtbl -> get_Enabled(This,pVal) ) 

#define ILMVMotionBlur_put_Enabled(This,newVal)	\
    ( (This)->lpVtbl -> put_Enabled(This,newVal) ) 

#define ILMVMotionBlur_get_Hue(This,pVal)	\
    ( (This)->lpVtbl -> get_Hue(This,pVal) ) 

#define ILMVMotionBlur_put_Hue(This,newVal)	\
    ( (This)->lpVtbl -> put_Hue(This,newVal) ) 

#define ILMVMotionBlur_get_Threshold(This,pVal)	\
    ( (This)->lpVtbl -> get_Threshold(This,pVal) ) 

#define ILMVMotionBlur_put_Threshold(This,newVal)	\
    ( (This)->lpVtbl -> put_Threshold(This,newVal) ) 


#define ILMVMotionBlur_get_Interval(This,pVal)	\
    ( (This)->lpVtbl -> get_Interval(This,pVal) ) 

#define ILMVMotionBlur_put_Interval(This,newVal)	\
    ( (This)->lpVtbl -> put_Interval(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMVMotionBlur_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LMVMotionBlur;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DC0F-38C5-11D5-91F6-00104BDB8FF9")
LMVMotionBlur;
#endif

#ifndef __ILMVWave_INTERFACE_DEFINED__
#define __ILMVWave_INTERFACE_DEFINED__

/* interface ILMVWave */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILMVWave;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DC16-38C5-11D5-91F6-00104BDB8FF9")
    ILMVWave : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Enabled( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Enabled( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_WaveSpeed( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_WaveSpeed( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Threshold( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Threshold( 
            /* [in] */ long newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMVWaveVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMVWave * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMVWave * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMVWave * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMVWave * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMVWave * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMVWave * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMVWave * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Enabled )( 
            ILMVWave * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Enabled )( 
            ILMVWave * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_WaveSpeed )( 
            ILMVWave * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_WaveSpeed )( 
            ILMVWave * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Threshold )( 
            ILMVWave * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Threshold )( 
            ILMVWave * This,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } ILMVWaveVtbl;

    interface ILMVWave
    {
        CONST_VTBL struct ILMVWaveVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMVWave_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMVWave_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMVWave_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMVWave_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMVWave_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMVWave_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMVWave_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMVWave_get_Enabled(This,pVal)	\
    ( (This)->lpVtbl -> get_Enabled(This,pVal) ) 

#define ILMVWave_put_Enabled(This,newVal)	\
    ( (This)->lpVtbl -> put_Enabled(This,newVal) ) 

#define ILMVWave_get_WaveSpeed(This,pVal)	\
    ( (This)->lpVtbl -> get_WaveSpeed(This,pVal) ) 

#define ILMVWave_put_WaveSpeed(This,newVal)	\
    ( (This)->lpVtbl -> put_WaveSpeed(This,newVal) ) 

#define ILMVWave_get_Threshold(This,pVal)	\
    ( (This)->lpVtbl -> get_Threshold(This,pVal) ) 

#define ILMVWave_put_Threshold(This,newVal)	\
    ( (This)->lpVtbl -> put_Threshold(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMVWave_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LMVWave;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DC13-38C5-11D5-91F6-00104BDB8FF9")
LMVWave;
#endif

#ifndef __ILMVLightning_INTERFACE_DEFINED__
#define __ILMVLightning_INTERFACE_DEFINED__

/* interface ILMVLightning */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILMVLightning;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DC1A-38C5-11D5-91F6-00104BDB8FF9")
    ILMVLightning : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Enabled( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Enabled( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetReferenceFrame( 
            /* [in] */ byte *pBuffer,
            /* [in] */ long lRGBColor,
            /* [in] */ REFERENCE_FRAME opt) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FirstFrameIsReference( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FirstFrameIsReference( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Threshold( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Threshold( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_NoReferenceFrame( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_NoReferenceFrame( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMVLightningVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMVLightning * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMVLightning * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMVLightning * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMVLightning * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMVLightning * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMVLightning * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMVLightning * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Enabled )( 
            ILMVLightning * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Enabled )( 
            ILMVLightning * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetReferenceFrame )( 
            ILMVLightning * This,
            /* [in] */ byte *pBuffer,
            /* [in] */ long lRGBColor,
            /* [in] */ REFERENCE_FRAME opt);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FirstFrameIsReference )( 
            ILMVLightning * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FirstFrameIsReference )( 
            ILMVLightning * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Threshold )( 
            ILMVLightning * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Threshold )( 
            ILMVLightning * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NoReferenceFrame )( 
            ILMVLightning * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_NoReferenceFrame )( 
            ILMVLightning * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        END_INTERFACE
    } ILMVLightningVtbl;

    interface ILMVLightning
    {
        CONST_VTBL struct ILMVLightningVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMVLightning_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMVLightning_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMVLightning_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMVLightning_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMVLightning_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMVLightning_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMVLightning_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMVLightning_get_Enabled(This,pVal)	\
    ( (This)->lpVtbl -> get_Enabled(This,pVal) ) 

#define ILMVLightning_put_Enabled(This,newVal)	\
    ( (This)->lpVtbl -> put_Enabled(This,newVal) ) 

#define ILMVLightning_SetReferenceFrame(This,pBuffer,lRGBColor,opt)	\
    ( (This)->lpVtbl -> SetReferenceFrame(This,pBuffer,lRGBColor,opt) ) 

#define ILMVLightning_get_FirstFrameIsReference(This,pVal)	\
    ( (This)->lpVtbl -> get_FirstFrameIsReference(This,pVal) ) 

#define ILMVLightning_put_FirstFrameIsReference(This,newVal)	\
    ( (This)->lpVtbl -> put_FirstFrameIsReference(This,newVal) ) 

#define ILMVLightning_get_Threshold(This,pVal)	\
    ( (This)->lpVtbl -> get_Threshold(This,pVal) ) 

#define ILMVLightning_put_Threshold(This,newVal)	\
    ( (This)->lpVtbl -> put_Threshold(This,newVal) ) 

#define ILMVLightning_get_NoReferenceFrame(This,pVal)	\
    ( (This)->lpVtbl -> get_NoReferenceFrame(This,pVal) ) 

#define ILMVLightning_put_NoReferenceFrame(This,newVal)	\
    ( (This)->lpVtbl -> put_NoReferenceFrame(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMVLightning_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LMVLightning;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DC17-38C5-11D5-91F6-00104BDB8FF9")
LMVLightning;
#endif

#ifndef __ILMVMotionEmboss_INTERFACE_DEFINED__
#define __ILMVMotionEmboss_INTERFACE_DEFINED__

/* interface ILMVMotionEmboss */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILMVMotionEmboss;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DC1E-38C5-11D5-91F6-00104BDB8FF9")
    ILMVMotionEmboss : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Enabled( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Enabled( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetReferenceFrame( 
            /* [in] */ byte *pBuffer,
            /* [in] */ long lRGBColor,
            /* [in] */ REFERENCE_FRAME opt) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FirstFrameIsReference( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FirstFrameIsReference( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Threshold( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Threshold( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Embossp( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Embossp( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Depth( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Depth( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Elevation( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Elevation( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LightAngle( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_LightAngle( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_NoReferenceFrame( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_NoReferenceFrame( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMVMotionEmbossVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMVMotionEmboss * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMVMotionEmboss * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMVMotionEmboss * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMVMotionEmboss * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMVMotionEmboss * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMVMotionEmboss * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMVMotionEmboss * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Enabled )( 
            ILMVMotionEmboss * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Enabled )( 
            ILMVMotionEmboss * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetReferenceFrame )( 
            ILMVMotionEmboss * This,
            /* [in] */ byte *pBuffer,
            /* [in] */ long lRGBColor,
            /* [in] */ REFERENCE_FRAME opt);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FirstFrameIsReference )( 
            ILMVMotionEmboss * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FirstFrameIsReference )( 
            ILMVMotionEmboss * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Threshold )( 
            ILMVMotionEmboss * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Threshold )( 
            ILMVMotionEmboss * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Embossp )( 
            ILMVMotionEmboss * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Embossp )( 
            ILMVMotionEmboss * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Depth )( 
            ILMVMotionEmboss * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Depth )( 
            ILMVMotionEmboss * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Elevation )( 
            ILMVMotionEmboss * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Elevation )( 
            ILMVMotionEmboss * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LightAngle )( 
            ILMVMotionEmboss * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LightAngle )( 
            ILMVMotionEmboss * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NoReferenceFrame )( 
            ILMVMotionEmboss * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_NoReferenceFrame )( 
            ILMVMotionEmboss * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        END_INTERFACE
    } ILMVMotionEmbossVtbl;

    interface ILMVMotionEmboss
    {
        CONST_VTBL struct ILMVMotionEmbossVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMVMotionEmboss_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMVMotionEmboss_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMVMotionEmboss_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMVMotionEmboss_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMVMotionEmboss_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMVMotionEmboss_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMVMotionEmboss_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMVMotionEmboss_get_Enabled(This,pVal)	\
    ( (This)->lpVtbl -> get_Enabled(This,pVal) ) 

#define ILMVMotionEmboss_put_Enabled(This,newVal)	\
    ( (This)->lpVtbl -> put_Enabled(This,newVal) ) 

#define ILMVMotionEmboss_SetReferenceFrame(This,pBuffer,lRGBColor,opt)	\
    ( (This)->lpVtbl -> SetReferenceFrame(This,pBuffer,lRGBColor,opt) ) 

#define ILMVMotionEmboss_get_FirstFrameIsReference(This,pVal)	\
    ( (This)->lpVtbl -> get_FirstFrameIsReference(This,pVal) ) 

#define ILMVMotionEmboss_put_FirstFrameIsReference(This,newVal)	\
    ( (This)->lpVtbl -> put_FirstFrameIsReference(This,newVal) ) 

#define ILMVMotionEmboss_get_Threshold(This,pVal)	\
    ( (This)->lpVtbl -> get_Threshold(This,pVal) ) 

#define ILMVMotionEmboss_put_Threshold(This,newVal)	\
    ( (This)->lpVtbl -> put_Threshold(This,newVal) ) 

#define ILMVMotionEmboss_get_Embossp(This,pVal)	\
    ( (This)->lpVtbl -> get_Embossp(This,pVal) ) 

#define ILMVMotionEmboss_put_Embossp(This,newVal)	\
    ( (This)->lpVtbl -> put_Embossp(This,newVal) ) 

#define ILMVMotionEmboss_get_Depth(This,pVal)	\
    ( (This)->lpVtbl -> get_Depth(This,pVal) ) 

#define ILMVMotionEmboss_put_Depth(This,newVal)	\
    ( (This)->lpVtbl -> put_Depth(This,newVal) ) 

#define ILMVMotionEmboss_get_Elevation(This,pVal)	\
    ( (This)->lpVtbl -> get_Elevation(This,pVal) ) 

#define ILMVMotionEmboss_put_Elevation(This,newVal)	\
    ( (This)->lpVtbl -> put_Elevation(This,newVal) ) 

#define ILMVMotionEmboss_get_LightAngle(This,pVal)	\
    ( (This)->lpVtbl -> get_LightAngle(This,pVal) ) 

#define ILMVMotionEmboss_put_LightAngle(This,newVal)	\
    ( (This)->lpVtbl -> put_LightAngle(This,newVal) ) 

#define ILMVMotionEmboss_get_NoReferenceFrame(This,pVal)	\
    ( (This)->lpVtbl -> get_NoReferenceFrame(This,pVal) ) 

#define ILMVMotionEmboss_put_NoReferenceFrame(This,newVal)	\
    ( (This)->lpVtbl -> put_NoReferenceFrame(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMVMotionEmboss_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LMVMotionEmboss;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DC1B-38C5-11D5-91F6-00104BDB8FF9")
LMVMotionEmboss;
#endif

#ifndef __ILMVGhost_INTERFACE_DEFINED__
#define __ILMVGhost_INTERFACE_DEFINED__

/* interface ILMVGhost */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILMVGhost;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DC22-38C5-11D5-91F6-00104BDB8FF9")
    ILMVGhost : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Enabled( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Enabled( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetReferenceFrame( 
            /* [in] */ byte *pBuffer,
            /* [in] */ long lRGBColor,
            /* [in] */ REFERENCE_FRAME opt) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FirstFrameIsReference( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FirstFrameIsReference( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Threshold( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Threshold( 
            /* [in] */ long newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMVGhostVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMVGhost * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMVGhost * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMVGhost * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMVGhost * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMVGhost * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMVGhost * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMVGhost * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Enabled )( 
            ILMVGhost * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Enabled )( 
            ILMVGhost * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetReferenceFrame )( 
            ILMVGhost * This,
            /* [in] */ byte *pBuffer,
            /* [in] */ long lRGBColor,
            /* [in] */ REFERENCE_FRAME opt);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FirstFrameIsReference )( 
            ILMVGhost * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FirstFrameIsReference )( 
            ILMVGhost * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Threshold )( 
            ILMVGhost * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Threshold )( 
            ILMVGhost * This,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } ILMVGhostVtbl;

    interface ILMVGhost
    {
        CONST_VTBL struct ILMVGhostVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMVGhost_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMVGhost_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMVGhost_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMVGhost_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMVGhost_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMVGhost_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMVGhost_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMVGhost_get_Enabled(This,pVal)	\
    ( (This)->lpVtbl -> get_Enabled(This,pVal) ) 

#define ILMVGhost_put_Enabled(This,newVal)	\
    ( (This)->lpVtbl -> put_Enabled(This,newVal) ) 

#define ILMVGhost_SetReferenceFrame(This,pBuffer,lRGBColor,opt)	\
    ( (This)->lpVtbl -> SetReferenceFrame(This,pBuffer,lRGBColor,opt) ) 

#define ILMVGhost_get_FirstFrameIsReference(This,pVal)	\
    ( (This)->lpVtbl -> get_FirstFrameIsReference(This,pVal) ) 

#define ILMVGhost_put_FirstFrameIsReference(This,newVal)	\
    ( (This)->lpVtbl -> put_FirstFrameIsReference(This,newVal) ) 

#define ILMVGhost_get_Threshold(This,pVal)	\
    ( (This)->lpVtbl -> get_Threshold(This,pVal) ) 

#define ILMVGhost_put_Threshold(This,newVal)	\
    ( (This)->lpVtbl -> put_Threshold(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMVGhost_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LMVGhost;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DC1F-38C5-11D5-91F6-00104BDB8FF9")
LMVGhost;
#endif

#ifndef __ILMVBright_INTERFACE_DEFINED__
#define __ILMVBright_INTERFACE_DEFINED__

/* interface ILMVBright */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILMVBright;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DD20-38C5-11D5-91F6-00104BDB8FF9")
    ILMVBright : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Enabled( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Enabled( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetReferenceFrame( 
            /* [in] */ byte *pBuffer,
            /* [in] */ long lRGBColor,
            /* [in] */ REFERENCE_FRAME opt) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FirstFrameIsReference( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FirstFrameIsReference( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Threshold( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Threshold( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Brightness( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Brightness( 
            /* [in] */ long newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMVBrightVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMVBright * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMVBright * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMVBright * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMVBright * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMVBright * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMVBright * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMVBright * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Enabled )( 
            ILMVBright * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Enabled )( 
            ILMVBright * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetReferenceFrame )( 
            ILMVBright * This,
            /* [in] */ byte *pBuffer,
            /* [in] */ long lRGBColor,
            /* [in] */ REFERENCE_FRAME opt);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FirstFrameIsReference )( 
            ILMVBright * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FirstFrameIsReference )( 
            ILMVBright * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Threshold )( 
            ILMVBright * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Threshold )( 
            ILMVBright * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Brightness )( 
            ILMVBright * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Brightness )( 
            ILMVBright * This,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } ILMVBrightVtbl;

    interface ILMVBright
    {
        CONST_VTBL struct ILMVBrightVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMVBright_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMVBright_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMVBright_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMVBright_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMVBright_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMVBright_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMVBright_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMVBright_get_Enabled(This,pVal)	\
    ( (This)->lpVtbl -> get_Enabled(This,pVal) ) 

#define ILMVBright_put_Enabled(This,newVal)	\
    ( (This)->lpVtbl -> put_Enabled(This,newVal) ) 

#define ILMVBright_SetReferenceFrame(This,pBuffer,lRGBColor,opt)	\
    ( (This)->lpVtbl -> SetReferenceFrame(This,pBuffer,lRGBColor,opt) ) 

#define ILMVBright_get_FirstFrameIsReference(This,pVal)	\
    ( (This)->lpVtbl -> get_FirstFrameIsReference(This,pVal) ) 

#define ILMVBright_put_FirstFrameIsReference(This,newVal)	\
    ( (This)->lpVtbl -> put_FirstFrameIsReference(This,newVal) ) 

#define ILMVBright_get_Threshold(This,pVal)	\
    ( (This)->lpVtbl -> get_Threshold(This,pVal) ) 

#define ILMVBright_put_Threshold(This,newVal)	\
    ( (This)->lpVtbl -> put_Threshold(This,newVal) ) 

#define ILMVBright_get_Brightness(This,pVal)	\
    ( (This)->lpVtbl -> get_Brightness(This,pVal) ) 

#define ILMVBright_put_Brightness(This,newVal)	\
    ( (This)->lpVtbl -> put_Brightness(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMVBright_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LMVBright;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DD1D-38C5-11D5-91F6-00104BDB8FF9")
LMVBright;
#endif

#ifndef __ILMVPredator_INTERFACE_DEFINED__
#define __ILMVPredator_INTERFACE_DEFINED__

/* interface ILMVPredator */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILMVPredator;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2B7DD2D-38C5-11D5-91F6-00104BDB8FF9")
    ILMVPredator : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Enabled( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Enabled( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetReferenceFrame( 
            /* [in] */ byte *pBuffer,
            /* [in] */ long lRGBColor,
            /* [in] */ REFERENCE_FRAME opt) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FirstFrameIsReference( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FirstFrameIsReference( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Threshold( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Threshold( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HorizontalPixels( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_HorizontalPixels( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_VerticalPixels( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_VerticalPixels( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HorizontalDirection( 
            /* [retval][out] */ HorizontalDirectionConstants *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_HorizontalDirection( 
            /* [in] */ HorizontalDirectionConstants newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_VerticalDirection( 
            /* [retval][out] */ VerticalDirectionConstants *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_VerticalDirection( 
            /* [in] */ VerticalDirectionConstants newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILMVPredatorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILMVPredator * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILMVPredator * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILMVPredator * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILMVPredator * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILMVPredator * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILMVPredator * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILMVPredator * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Enabled )( 
            ILMVPredator * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Enabled )( 
            ILMVPredator * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetReferenceFrame )( 
            ILMVPredator * This,
            /* [in] */ byte *pBuffer,
            /* [in] */ long lRGBColor,
            /* [in] */ REFERENCE_FRAME opt);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FirstFrameIsReference )( 
            ILMVPredator * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FirstFrameIsReference )( 
            ILMVPredator * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Threshold )( 
            ILMVPredator * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Threshold )( 
            ILMVPredator * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HorizontalPixels )( 
            ILMVPredator * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_HorizontalPixels )( 
            ILMVPredator * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VerticalPixels )( 
            ILMVPredator * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_VerticalPixels )( 
            ILMVPredator * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HorizontalDirection )( 
            ILMVPredator * This,
            /* [retval][out] */ HorizontalDirectionConstants *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_HorizontalDirection )( 
            ILMVPredator * This,
            /* [in] */ HorizontalDirectionConstants newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VerticalDirection )( 
            ILMVPredator * This,
            /* [retval][out] */ VerticalDirectionConstants *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_VerticalDirection )( 
            ILMVPredator * This,
            /* [in] */ VerticalDirectionConstants newVal);
        
        END_INTERFACE
    } ILMVPredatorVtbl;

    interface ILMVPredator
    {
        CONST_VTBL struct ILMVPredatorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILMVPredator_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILMVPredator_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILMVPredator_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILMVPredator_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILMVPredator_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILMVPredator_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILMVPredator_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILMVPredator_get_Enabled(This,pVal)	\
    ( (This)->lpVtbl -> get_Enabled(This,pVal) ) 

#define ILMVPredator_put_Enabled(This,newVal)	\
    ( (This)->lpVtbl -> put_Enabled(This,newVal) ) 

#define ILMVPredator_SetReferenceFrame(This,pBuffer,lRGBColor,opt)	\
    ( (This)->lpVtbl -> SetReferenceFrame(This,pBuffer,lRGBColor,opt) ) 

#define ILMVPredator_get_FirstFrameIsReference(This,pVal)	\
    ( (This)->lpVtbl -> get_FirstFrameIsReference(This,pVal) ) 

#define ILMVPredator_put_FirstFrameIsReference(This,newVal)	\
    ( (This)->lpVtbl -> put_FirstFrameIsReference(This,newVal) ) 

#define ILMVPredator_get_Threshold(This,pVal)	\
    ( (This)->lpVtbl -> get_Threshold(This,pVal) ) 

#define ILMVPredator_put_Threshold(This,newVal)	\
    ( (This)->lpVtbl -> put_Threshold(This,newVal) ) 

#define ILMVPredator_get_HorizontalPixels(This,pVal)	\
    ( (This)->lpVtbl -> get_HorizontalPixels(This,pVal) ) 

#define ILMVPredator_put_HorizontalPixels(This,newVal)	\
    ( (This)->lpVtbl -> put_HorizontalPixels(This,newVal) ) 

#define ILMVPredator_get_VerticalPixels(This,pVal)	\
    ( (This)->lpVtbl -> get_VerticalPixels(This,pVal) ) 

#define ILMVPredator_put_VerticalPixels(This,newVal)	\
    ( (This)->lpVtbl -> put_VerticalPixels(This,newVal) ) 

#define ILMVPredator_get_HorizontalDirection(This,pVal)	\
    ( (This)->lpVtbl -> get_HorizontalDirection(This,pVal) ) 

#define ILMVPredator_put_HorizontalDirection(This,newVal)	\
    ( (This)->lpVtbl -> put_HorizontalDirection(This,newVal) ) 

#define ILMVPredator_get_VerticalDirection(This,pVal)	\
    ( (This)->lpVtbl -> get_VerticalDirection(This,pVal) ) 

#define ILMVPredator_put_VerticalDirection(This,newVal)	\
    ( (This)->lpVtbl -> put_VerticalDirection(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILMVPredator_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LMVPredator;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DD2A-38C5-11D5-91F6-00104BDB8FF9")
LMVPredator;
#endif
#endif /* __LMVMotionFXLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


