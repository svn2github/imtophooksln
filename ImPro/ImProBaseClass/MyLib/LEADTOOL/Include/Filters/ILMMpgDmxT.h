

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Nov 05 12:51:59 2009
 */
/* Compiler settings for .\LMMpgDmx.idl:
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


#ifndef __ILMMpgDmxT_h__
#define __ILMMpgDmxT_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __LMMpgDmxT_FWD_DEFINED__
#define __LMMpgDmxT_FWD_DEFINED__

#ifdef __cplusplus
typedef class LMMpgDmxT LMMpgDmxT;
#else
typedef struct LMMpgDmxT LMMpgDmxT;
#endif /* __cplusplus */

#endif 	/* __LMMpgDmxT_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LMMpgDmxTLib_LIBRARY_DEFINED__
#define __LMMpgDmxTLib_LIBRARY_DEFINED__

/* library LMMpgDmxTLib */
/* [helpstring][uuid][version] */ 

#ifndef __LMMpgDmxT_H__
#define __LMMpgDmxT_H__
static const CLSID CLSID_LMMpgDmxT = { 0xE2B7DF1A, 0x38C5, 0x11d5, { 0x91, 0xF6, 0x00, 0x10, 0x4B, 0xDB, 0x8F, 0xF9 } };
static const IID LIBID_LMMpgDmxTLib = { 0xE2B7DF1B, 0x38C5, 0x11d5, { 0x91, 0xF6, 0x00, 0x10, 0x4B, 0xDB, 0x8F, 0xF9 } };
#endif // #ifndef __LMMpgDmxT_H__
#define __LMMpgDmxConstants_MODULE_DEFINED__
#define	KlvKey_UserDefinedTimeStamp	( L"06 0E 2B 34 01 01 01 03 07 02 01 01 01 05 00 00" )

#define	KlvKey_UnixTimeStamp	( L"06 0E 2B 34 01 01 01 04 07 02 01 01 01 05 00 00" )

#define	KlvKey_TimingReconciliationSet	( L"06 0E 2B 34 02 01 01 01 07 02 01 03 01 00 00 00" )

#define	KlvKey_TimingBiasCorrection	( L"06 0E 2B 34 01 01 01 04 03 01 03 03 03 01 00 00" )

#define	KlvKey_TimingBiasCorrectionDescription	( L"06 0E 2B 34 01 01 01 03 03 01 03 03 04 00 00 00" )

#define	KlvKey_TimingItemDesignatorID	( L"06 0E 2B 34 01 01 01 03 01 03 02 00 00 00 00 00" )

#define	KlvKey_StartDateTime_UTC	( L"06 0E 2B 34 01 01 01 01 07 02 01 02 01 01 00 00" )

#define	KlvKey_EventStartDateTime_UTC	( L"06 0E 2B 34 01 01 01 01 07 02 01 02 07 01 00 00" )

#define	KlvKey_SensorRollAngle	( L"06 0E 2B 34 01 01 01 01 07 01 10 01 01 00 00 00" )

#define	KlvKey_AngleToNorth	( L"06 0E 2B 34 01 01 01 01 07 01 10 01 02 00 00 00" )

#define	KlvKey_ObliquityAngle	( L"06 0E 2B 34 01 01 01 01 07 01 10 01 03 00 00 00" )

#define	KlvKey_FieldOfViewVertical	( L"06 0E 2B 34 01 01 01 07 04 20 02 01 01 0A 01 00" )

#define	KlvKey_FieldOfViewHorizontal	( L"06 0E 2B 34 01 01 01 02 04 20 02 01 01 08 00 00" )

#define	KlvKey_DeviceAltitude	( L"06 0E 2B 34 01 01 01 01 07 01 02 01 02 02 00 00" )

#define	KlvKey_DeviceLatitude	( L"06 0E 2B 34 01 01 01 03 07 01 02 01 02 04 02 00" )

#define	KlvKey_DeviceLongitude	( L"06 0E 2B 34 01 01 01 03 07 01 02 01 02 06 02 00" )

#define	KlvKey_ImageSourceDevice	( L"06 0E 2B 34 01 01 01 01 04 20 01 02 01 01 00 00" )

#define	KlvKey_EpisodeNumber	( L"06 0E 2B 34 01 01 01 01 01 05 05 00 00 00 00 00" )

#define	KlvKey_DeviceDesignation	( L"06 0E 2B 34 01 01 01 01 01 01 20 01 00 00 00 00" )

#define	KlvKey_MissionID	( L"06 0E 2B 34 01 01 01 01 01 05 05 00 00 00 00 00" )

#define	KlvKey_PlatformHeadingAngle	( L"06 0E 2B 34 01 01 01 07 07 01 10 01 06 00 00 00" )

#define	KlvKey_PlatformPitchAngle	( L"06 0E 2B 34 01 01 01 07 07 01 10 01 05 00 00 00" )

#define	KlvKey_PlatformRollAngle	( L"06 0E 2B 34 01 01 01 07 07 01 10 01 04 00 00 00" )

#define	KlvKey_PlatformDesignation	( L"06 0E 2B 34 01 01 01 01 01 01 20 01 00 00 00 00" )

#define	KlvKey_ImageSourceSensor	( L"06 0E 2B 34 01 01 01 01 04 20 01 02 01 01 00 00" )

#define	KlvKey_ImageCoordinateSystem	( L"06 0E 2B 34 01 01 01 01 07 01 01 01 00 00 00 00" )

#define	KlvKey_SensorLatitude	( L"06 0E 2B 34 01 01 01 03 07 01 02 01 02 04 02 00" )

#define	KlvKey_SensorLongitude	( L"06 0E 2B 34 01 01 01 03 07 01 02 01 02 06 02 00" )

#define	KlvKey_SensorTrueAltitude	( L"06 0E 2B 34 01 01 01 01 07 01 02 01 02 02 00 00" )

#define	KlvKey_SensorHorizontalFieldofView	( L"06 0E 2B 34 01 01 01 02 04 20 02 01 01 08 00 00" )

#define	KlvKey_SlantRange	( L"06 0E 2B 34 01 01 01 01 07 01 08 01 01 00 00 00" )

#define	KlvKey_TargetWidth	( L"06 0E 2B 34 01 01 01 01 07 01 09 02 01 00 00 00" )

#define	KlvKey_FrameCenterLatitude	( L"06 0E 2B 34 01 01 01 01 07 01 02 01 03 02 00 00" )

#define	KlvKey_FrameCenterLongitude	( L"06 0E 2B 34 01 01 01 01 07 01 02 01 03 04 00 00" )

#define	KlvKey_FrameCenterElevation	( L"06 0E 2B 34 01 01 01 06 07 01 02 03 10 00 00 00" )

#define	KlvKey_CornerLatitudePoint1	( L"06 0E 2B 34 01 01 01 03 07 01 02 01 03 07 01 00" )

#define	KlvKey_CornerLongitudePoint1	( L"06 0E 2B 34 01 01 01 03 07 01 02 01 03 0B 01 00" )

#define	KlvKey_CornerLatitudePoint2	( L"06 0E 2B 34 01 01 01 03 07 01 02 01 03 08 01 00" )

#define	KlvKey_CornerLongitudePoint2	( L"06 0E 2B 34 01 01 01 03 07 01 02 01 03 0C 01 00" )

#define	KlvKey_CornerLatitudePoint3	( L"06 0E 2B 34 01 01 01 03 07 01 02 01 03 09 01 00" )

#define	KlvKey_CornerLongitudePoint3	( L"06 0E 2B 34 01 01 01 03 07 01 02 01 03 0D 01 00" )

#define	KlvKey_CornerLatitudePoint4	( L"06 0E 2B 34 01 01 01 03 07 01 02 01 03 0A 01 00" )

#define	KlvKey_CornerLongitudePoint4	( L"06 0E 2B 34 01 01 01 03 07 01 02 01 03 0E 01 00" )

#define	KlvKey_SecurityClassification	( L"06 0E 2B 34 01 01 01 03 02 08 02 01 00 00 00 00" )

#define	KlvKey_NonUSClassifyingCountryCodeMethod	( L"06 0E 2B 34 01 01 01 03 07 01 20 01 02 07 00 00" )

#define	KlvKey_NonUSClassifyingCountryCode	( L"06 0E 2B 34 01 01 01 03 07 01 20 01 02 08 00 00" )

#define	KlvKey_SecurityCaveats	( L"06 0E 2B 34 01 01 01 03 02 08 02 02 00 00 00 00" )

#define	KlvKey_ReleasingInstructions	( L"06 0E 2B 34 01 01 01 03 07 01 20 01 02 09 00 00" )

#define	KlvKey_ClassifiedBy	( L"06 0E 2B 34 01 01 01 03 02 08 02 03 00 00 00 00" )

#define	KlvKey_ClassificationReason	( L"06 0E 2B 34 01 01 01 03 02 08 02 04 00 00 00 00" )

#define	KlvKey_DeclassificationDate	( L"06 0E 2B 34 01 01 01 03 02 08 02 05 00 00 00 00" )

#define	KlvKey_DerivedFrom	( L"06 0E 2B 34 01 01 01 03 02 08 02 06 00 00 00 00" )

#define	KlvKey_ClassificationAndMarkingSystem	( L"06 0E 2B 34 01 01 01 03 02 08 02 08 00 00 00 00" )

#define	KlvKey_ObjectCountryCodeMethod	( L"06 0E 2B 34 01 01 01 03 07 01 20 01 02 06 00 00" )

#define	KlvKey_ObjectCountryCode	( L"06 0E 2B 34 01 01 01 03 07 01 20 01 02 01 01 00" )

#define	KlvKey_ClassificationComment	( L"06 0E 2B 34 01 01 01 03 02 08 02 07 00 00 00 00" )

#define	KlvKey_UMIDVideo	( L"06 0E 2B 34 01 01 01 01 01 01 01 XY 00 00 00 00" )

#define	KlvKey_UMIDAudio	( L"06 0E 2B 34 01 01 01 01 01 01 02 XY 00 00 00 00" )

#define	KlvKey_UMIDData	( L"06 0E 2B 34 01 01 01 01 01 01 03 XY 00 00 00 00" )

#define	KlvKey_UMIDSystem	( L"06 0E 2B 34 01 01 01 01 01 01 04 XY 00 00 00 00" )

#define	KlvKey_StreamID	( L"06 0E 2B 34 01 01 01 03 01 03 04 02 00 00 00 00" )

#define	KlvKey_TransportStreamID	( L"06 0E 2B 34 01 01 01 03 01 03 04 03 00 00 00 00" )

#define	KlvKey_SecurityItemDesignatorID	( L"06 0E 2B 34 01 01 01 03 01 03 06 01 00 00 00 00" )


EXTERN_C const IID LIBID_LMMpgDmxTLib;


#ifndef __LMMpgDmxConstants_MODULE_DEFINED__
#define __LMMpgDmxConstants_MODULE_DEFINED__


/* module LMMpgDmxConstants */
/* [uuid][dllname] */ 

const LPSTR KlvKey_UserDefinedTimeStamp	=	"06 0E 2B 34 01 01 01 03 07 02 01 01 01 05 00 00";

const LPSTR KlvKey_UnixTimeStamp	=	"06 0E 2B 34 01 01 01 04 07 02 01 01 01 05 00 00";

const LPSTR KlvKey_TimingReconciliationSet	=	"06 0E 2B 34 02 01 01 01 07 02 01 03 01 00 00 00";

const LPSTR KlvKey_TimingBiasCorrection	=	"06 0E 2B 34 01 01 01 04 03 01 03 03 03 01 00 00";

const LPSTR KlvKey_TimingBiasCorrectionDescription	=	"06 0E 2B 34 01 01 01 03 03 01 03 03 04 00 00 00";

const LPSTR KlvKey_TimingItemDesignatorID	=	"06 0E 2B 34 01 01 01 03 01 03 02 00 00 00 00 00";

const LPSTR KlvKey_StartDateTime_UTC	=	"06 0E 2B 34 01 01 01 01 07 02 01 02 01 01 00 00";

const LPSTR KlvKey_EventStartDateTime_UTC	=	"06 0E 2B 34 01 01 01 01 07 02 01 02 07 01 00 00";

const LPSTR KlvKey_SensorRollAngle	=	"06 0E 2B 34 01 01 01 01 07 01 10 01 01 00 00 00";

const LPSTR KlvKey_AngleToNorth	=	"06 0E 2B 34 01 01 01 01 07 01 10 01 02 00 00 00";

const LPSTR KlvKey_ObliquityAngle	=	"06 0E 2B 34 01 01 01 01 07 01 10 01 03 00 00 00";

const LPSTR KlvKey_FieldOfViewVertical	=	"06 0E 2B 34 01 01 01 07 04 20 02 01 01 0A 01 00";

const LPSTR KlvKey_FieldOfViewHorizontal	=	"06 0E 2B 34 01 01 01 02 04 20 02 01 01 08 00 00";

const LPSTR KlvKey_DeviceAltitude	=	"06 0E 2B 34 01 01 01 01 07 01 02 01 02 02 00 00";

const LPSTR KlvKey_DeviceLatitude	=	"06 0E 2B 34 01 01 01 03 07 01 02 01 02 04 02 00";

const LPSTR KlvKey_DeviceLongitude	=	"06 0E 2B 34 01 01 01 03 07 01 02 01 02 06 02 00";

const LPSTR KlvKey_ImageSourceDevice	=	"06 0E 2B 34 01 01 01 01 04 20 01 02 01 01 00 00";

const LPSTR KlvKey_EpisodeNumber	=	"06 0E 2B 34 01 01 01 01 01 05 05 00 00 00 00 00";

const LPSTR KlvKey_DeviceDesignation	=	"06 0E 2B 34 01 01 01 01 01 01 20 01 00 00 00 00";

const LPSTR KlvKey_MissionID	=	"06 0E 2B 34 01 01 01 01 01 05 05 00 00 00 00 00";

const LPSTR KlvKey_PlatformHeadingAngle	=	"06 0E 2B 34 01 01 01 07 07 01 10 01 06 00 00 00";

const LPSTR KlvKey_PlatformPitchAngle	=	"06 0E 2B 34 01 01 01 07 07 01 10 01 05 00 00 00";

const LPSTR KlvKey_PlatformRollAngle	=	"06 0E 2B 34 01 01 01 07 07 01 10 01 04 00 00 00";

const LPSTR KlvKey_PlatformDesignation	=	"06 0E 2B 34 01 01 01 01 01 01 20 01 00 00 00 00";

const LPSTR KlvKey_ImageSourceSensor	=	"06 0E 2B 34 01 01 01 01 04 20 01 02 01 01 00 00";

const LPSTR KlvKey_ImageCoordinateSystem	=	"06 0E 2B 34 01 01 01 01 07 01 01 01 00 00 00 00";

const LPSTR KlvKey_SensorLatitude	=	"06 0E 2B 34 01 01 01 03 07 01 02 01 02 04 02 00";

const LPSTR KlvKey_SensorLongitude	=	"06 0E 2B 34 01 01 01 03 07 01 02 01 02 06 02 00";

const LPSTR KlvKey_SensorTrueAltitude	=	"06 0E 2B 34 01 01 01 01 07 01 02 01 02 02 00 00";

const LPSTR KlvKey_SensorHorizontalFieldofView	=	"06 0E 2B 34 01 01 01 02 04 20 02 01 01 08 00 00";

const LPSTR KlvKey_SlantRange	=	"06 0E 2B 34 01 01 01 01 07 01 08 01 01 00 00 00";

const LPSTR KlvKey_TargetWidth	=	"06 0E 2B 34 01 01 01 01 07 01 09 02 01 00 00 00";

const LPSTR KlvKey_FrameCenterLatitude	=	"06 0E 2B 34 01 01 01 01 07 01 02 01 03 02 00 00";

const LPSTR KlvKey_FrameCenterLongitude	=	"06 0E 2B 34 01 01 01 01 07 01 02 01 03 04 00 00";

const LPSTR KlvKey_FrameCenterElevation	=	"06 0E 2B 34 01 01 01 06 07 01 02 03 10 00 00 00";

const LPSTR KlvKey_CornerLatitudePoint1	=	"06 0E 2B 34 01 01 01 03 07 01 02 01 03 07 01 00";

const LPSTR KlvKey_CornerLongitudePoint1	=	"06 0E 2B 34 01 01 01 03 07 01 02 01 03 0B 01 00";

const LPSTR KlvKey_CornerLatitudePoint2	=	"06 0E 2B 34 01 01 01 03 07 01 02 01 03 08 01 00";

const LPSTR KlvKey_CornerLongitudePoint2	=	"06 0E 2B 34 01 01 01 03 07 01 02 01 03 0C 01 00";

const LPSTR KlvKey_CornerLatitudePoint3	=	"06 0E 2B 34 01 01 01 03 07 01 02 01 03 09 01 00";

const LPSTR KlvKey_CornerLongitudePoint3	=	"06 0E 2B 34 01 01 01 03 07 01 02 01 03 0D 01 00";

const LPSTR KlvKey_CornerLatitudePoint4	=	"06 0E 2B 34 01 01 01 03 07 01 02 01 03 0A 01 00";

const LPSTR KlvKey_CornerLongitudePoint4	=	"06 0E 2B 34 01 01 01 03 07 01 02 01 03 0E 01 00";

const LPSTR KlvKey_SecurityClassification	=	"06 0E 2B 34 01 01 01 03 02 08 02 01 00 00 00 00";

const LPSTR KlvKey_NonUSClassifyingCountryCodeMethod	=	"06 0E 2B 34 01 01 01 03 07 01 20 01 02 07 00 00";

const LPSTR KlvKey_NonUSClassifyingCountryCode	=	"06 0E 2B 34 01 01 01 03 07 01 20 01 02 08 00 00";

const LPSTR KlvKey_SecurityCaveats	=	"06 0E 2B 34 01 01 01 03 02 08 02 02 00 00 00 00";

const LPSTR KlvKey_ReleasingInstructions	=	"06 0E 2B 34 01 01 01 03 07 01 20 01 02 09 00 00";

const LPSTR KlvKey_ClassifiedBy	=	"06 0E 2B 34 01 01 01 03 02 08 02 03 00 00 00 00";

const LPSTR KlvKey_ClassificationReason	=	"06 0E 2B 34 01 01 01 03 02 08 02 04 00 00 00 00";

const LPSTR KlvKey_DeclassificationDate	=	"06 0E 2B 34 01 01 01 03 02 08 02 05 00 00 00 00";

const LPSTR KlvKey_DerivedFrom	=	"06 0E 2B 34 01 01 01 03 02 08 02 06 00 00 00 00";

const LPSTR KlvKey_ClassificationAndMarkingSystem	=	"06 0E 2B 34 01 01 01 03 02 08 02 08 00 00 00 00";

const LPSTR KlvKey_ObjectCountryCodeMethod	=	"06 0E 2B 34 01 01 01 03 07 01 20 01 02 06 00 00";

const LPSTR KlvKey_ObjectCountryCode	=	"06 0E 2B 34 01 01 01 03 07 01 20 01 02 01 01 00";

const LPSTR KlvKey_ClassificationComment	=	"06 0E 2B 34 01 01 01 03 02 08 02 07 00 00 00 00";

const LPSTR KlvKey_UMIDVideo	=	"06 0E 2B 34 01 01 01 01 01 01 01 XY 00 00 00 00";

const LPSTR KlvKey_UMIDAudio	=	"06 0E 2B 34 01 01 01 01 01 01 02 XY 00 00 00 00";

const LPSTR KlvKey_UMIDData	=	"06 0E 2B 34 01 01 01 01 01 01 03 XY 00 00 00 00";

const LPSTR KlvKey_UMIDSystem	=	"06 0E 2B 34 01 01 01 01 01 01 04 XY 00 00 00 00";

const LPSTR KlvKey_StreamID	=	"06 0E 2B 34 01 01 01 03 01 03 04 02 00 00 00 00";

const LPSTR KlvKey_TransportStreamID	=	"06 0E 2B 34 01 01 01 03 01 03 04 03 00 00 00 00";

const LPSTR KlvKey_SecurityItemDesignatorID	=	"06 0E 2B 34 01 01 01 03 01 03 06 01 00 00 00 00";

#endif /* __LMMpgDmxConstants_MODULE_DEFINED__ */

EXTERN_C const CLSID CLSID_LMMpgDmxT;

#ifdef __cplusplus

class DECLSPEC_UUID("E2B7DF1A-38C5-11D5-91F6-00104BDB8FF9")
LMMpgDmxT;
#endif
#endif /* __LMMpgDmxTLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


