//  ==========================================================================================
/// @file	VideoWrapperTypes.h
///
/// Declares types and symbols used by VideoWrapper and VideoWrapper Library Adapters.
///
/// Copyright 2005, Georgia Tech Research Corporation, Atlanta, Georgia 30332-0415
/// All Rights Reserved 
///
//  ==========================================================================================

#ifndef _VIDEOWRAPPERTYPES_H
#define _VIDEOWRAPPERTYPES_H


#if defined(_WIN32) || defined(WIN32) || defined(__WIN32__)
   #include <windows.h>
#else
    #ifndef UNIX
        #define UNIX
    #endif
#endif

// ------------------------------------------------------------------------------------------
// misc. type definitions
// ------------------------------------------------------------------------------------------

///
/// Boolean type definition.
///
typedef int VWBool;

#ifndef TRUE
	///
	/// TRUE macro definition.
	///
    #define TRUE    1
	///
	/// FALSE macro definition.
	///
    #define FALSE   0
#endif


// ------------------------------------------------------------------------------------------
// video library and camera handles
// ------------------------------------------------------------------------------------------

///
/// Type definition for a handle to a video camera.  This handle identifies both the library
/// instance and the camera instance within the library.  The low byte (bits 0-7) identifies
/// the library.  The high byte (bits 8-15) identifies the camera and is passed to the library
/// as a VWHCamera.
///
/// @see	VWHCamera
typedef unsigned short VWHVideo;

///
/// Type definition for camera handles.  Identifies a camera instance within a video wrapper
/// library.  When a video wrapper library is wrapped by VideoWrapper, the VWHCamera becomes
/// the HIGHBYTE( bits 8-15) of a VWHVideo.
///
/// @see	VWHVideo
///
typedef unsigned char VWHCamera;

//
// Makes a video handle from two bytes representing the video lib id and 
// the camera id within that lib
//
#define MAKE_VIDEO_HANDLE(lib, cam)	((unsigned short)(((unsigned char)((unsigned long)(cam) & 0xff)) | ((unsigned short)((unsigned char)((unsigned long)(lib) & 0xff))) << 8))

//
// Extracts the camera id (low byte) from a video handle.
//
#define VIDEO_HANDLE_CAMBYTE(w)	((unsigned char)((unsigned long)(w) & 0xff))

//
// Extracts the video library id (hight byte) from a video handle.
//
#define VIDEO_HANDLE_LIBBYTE(w)	((unsigned char)((unsigned long)(w) >> 8))

// ------------------------------------------------------------------------------------------
// result codes
// ------------------------------------------------------------------------------------------
//@{
/// @name	Function Result Codes
///
/// VideoWrapper functions return a VWResut indicating the success or failure of the 
/// operation.  Successful functions should return VW_SUCCESS (0), while failed functions 
/// should return a descriptive error code (>0).
///

///
/// Indicates the success or failure of a VideoWrapper function.
///
typedef int VWResult;

// REMEMBER to update the VW_RESULT_DESCRIPTIONS macro when adding or modifying 
// the result code symbols.

#define VW_SUCCESS					0		/**< The function succeeded.*/
#define VW_E_ERROR					1		/**< Unspecified error.*/
#define VW_E_NOT_IMPLEMENTED		100		/**< The function is not implemented.*/
#define VW_E_INVALID_HANDLE			101		/**< The handle is unknown.*/
#define VW_E_INVALID_CONFIG_STRING	102		/**< The configuration string is invalid.*/
#define VW_E_LIB_NOT_LOADED			103		/**< The requested library is not loaded.*/
#define VW_E_LIB_ALREADY_LOADED		104		/**< The requested library is already loaded.*/
#define VW_E_LIB_LOAD_FAILED		105		/**< The library failed to load.*/
#define VW_E_INVALID_CAMERA_ID		106		/**< The camera id specified in the initialization string is not valid.*/
#define VW_E_MEMORY_ALLOCATION		107		/**< Memory allocation failed.*/
#define VW_E_CAM_NOT_INITIALIZED	108		/**< The camera has not been initialized.*/
#define VW_E_STRING_OVERFLOW		109		/**< The string has exceeded its alocated buffer.*/
#define VW_E_NOT_STARTED			110		/**< The camera has not been started.*/
#define VW_E_PLAYING				300		/**< Operation can not complete because playback is in progress.*/
#define VW_E_NOT_PLAYING			301		/**< Operation can not complete because playback is not in progress.*/
#define VW_E_CAPTURING				302		/**< Operation can not complete because capture is in progress.*/
#define VW_E_NOT_CAPTURING			303		/**< Operation can not complete because capture is not in progress.*/
#define VW_E_NO_CAPTURE_DATA		304		/**< No captured data exists.*/
#define VW_E_CANT_CAPTURE_REPLAY	305		/**< Can not capture a replay camera.*/
#define VW_E_WRITE_FAILED			400		/**< Failed to write to file.*/
#define VW_E_READ_FAILED			401		/**< Failed to read from file.*/
#define VW_E_NOT_REPLAY_CAM			402		/**< The camera is not a replay camera.*/
#define VW_E_UNSUPPORTED_PROPERTY	500		/**< The camera property is unsupported.*/
#define VW_E_AUTO_UNSUPPORTED		501		/**< The camera property doesn't support automatic control.*/
#define VW_E_OUT_OF_RANGE			502		/**< The camera property value is out of range.*/
#define VW_E_INTERNAL_ERROR			900		/**< An unexpected, internal error has occurred within the API.*/

// This macro is used by VIDEO_getErrDescription in VideoWrapper to generate descriptions of result codes.
// There shouldn't be any need for this macro elsewhere.
/// @cond DOXYGEN_IGNORE
#define VW_RESULT_DESCRIPTIONS	\
	VW_RESULT_DESC( VW_SUCCESS,					"The function succeeded.")\
	VW_RESULT_DESC( VW_E_ERROR,					"Unspecified error.")\
	VW_RESULT_DESC( VW_E_NOT_IMPLEMENTED,		"The function is not implemented.")\
	VW_RESULT_DESC( VW_E_INVALID_HANDLE,		"The handle is unknown.")\
	VW_RESULT_DESC( VW_E_INVALID_CONFIG_STRING,	"The configuration string is invalid.")\
	VW_RESULT_DESC( VW_E_LIB_NOT_LOADED,		"The requested library is not loaded.")\
	VW_RESULT_DESC( VW_E_LIB_ALREADY_LOADED,	"The requested library is already loaded.")\
	VW_RESULT_DESC( VW_E_LIB_LOAD_FAILED,		"The library failed to load.")\
	VW_RESULT_DESC( VW_E_INVALID_CAMERA_ID,		"The camera id specified in the initialization string is not valid.")\
	VW_RESULT_DESC( VW_E_MEMORY_ALLOCATION,		"Memory allocation failed.")\
	VW_RESULT_DESC( VW_E_CAM_NOT_INITIALIZED,	"The camera has not been initialized.")\
	VW_RESULT_DESC( VW_E_STRING_OVERFLOW,		"The string has exceeded its alocated buffer.")\
	VW_RESULT_DESC( VW_E_NOT_STARTED,			"The camera has not been started.")\
	VW_RESULT_DESC( VW_E_PLAYING,				"Operation can not complete because playback is in progress.")\
	VW_RESULT_DESC( VW_E_NOT_PLAYING,			"Operation can not complete because playback is not in progress.")\
	VW_RESULT_DESC( VW_E_CAPTURING,				"Operation can not complete because capture is in progress.")\
	VW_RESULT_DESC( VW_E_NOT_CAPTURING,			"Operation can not complete because capture is not in progress.")\
	VW_RESULT_DESC( VW_E_NO_CAPTURE_DATA,		"No captured data exists.")\
	VW_RESULT_DESC( VW_E_CANT_CAPTURE_REPLAY,	"Can not capture a replay camera.")\
	VW_RESULT_DESC( VW_E_WRITE_FAILED,			"Failed to write to file.")\
	VW_RESULT_DESC( VW_E_READ_FAILED,			"Failed to read from file.")\
	VW_RESULT_DESC( VW_E_NOT_REPLAY_CAM,		"The camera is not a replay camera.")\
	VW_RESULT_DESC( VW_E_UNSUPPORTED_PROPERTY,	"The camera property is unsupported.")\
	VW_RESULT_DESC( VW_E_AUTO_UNSUPPORTED,		"The camera property doesn't support automatic control.")\
	VW_RESULT_DESC( VW_E_OUT_OF_RANGE,			"The camera property value is out of range.")\
	VW_RESULT_DESC( VW_E_INTERNAL_ERROR,		"An unexpected, internal error has occurred within the API.")
/// @endcond

///
/// Tests result code for success.
///
#define VW_SUCCEEDED(code)	(code == VW_SUCCESS)

//@}

// ------------------------------------------------------------------------------------------
// pixel format
// ------------------------------------------------------------------------------------------
//@{
/// @name	Pixel Formats
///
/// These symbols identify the pixel format of a frame buffer.  They mirror the pixel format 
/// constants used by OpenGL.
///
/// @note	These identifiers are value-compatible with their OpenGL counterparts shipped with
///			Microsoft Visual Studio 2003.  They may not be value-compatible with other 
///			implementations.
///
/// @see	VIDEO_getPixelFormat
///

///
/// Indicates the success or failure of a VideoWrapper function.
///
typedef int VWPixelFormat;

// TODO: determine if all of these are needed.
// TODO: doc pixel formats
#define VW_PF_COLOR_INDEX			0x1900	/**< OpenGL compatible pixel format. */
#define VW_PF_STENCIL_INDEX			0x1901	/**< OpenGL compatible pixel format. */
#define VW_PF_DEPTH_COMPONENT		0x1902	/**< OpenGL compatible pixel format. */
#define VW_PF_RED					0x1903	/**< OpenGL compatible pixel format. */
#define VW_PF_GREEN					0x1904	/**< OpenGL compatible pixel format. */
#define VW_PF_BLUE					0x1905	/**< OpenGL compatible pixel format. */
#define VW_PF_ALPHA					0x1906	/**< OpenGL compatible pixel format. */
#define VW_PF_RGB					0x1907	/**< OpenGL compatible pixel format. */
#define VW_PF_RGBA					0x1908	/**< OpenGL compatible pixel format. */
#define VW_PF_LUMINANCE				0x1909	/**< OpenGL compatible pixel format. */
#define VW_PF_LUMINANCE_ALPHA		0x190A	/**< OpenGL compatible pixel format. */

#define VW_PF_BGR_EXT               0x80E0	/**< OpenGL compatible pixel format. */
#define VW_PF_BGRA_EXT              0x80E1	/**< OpenGL compatible pixel format. */

//@}

// ------------------------------------------------------------------------------------------
// camera image properties
// ------------------------------------------------------------------------------------------
//@{
/// @name	Camera Image Properties
///
/// These identifiers may be used to manipulate image properties of the camera.  A given
/// camera is likely to support only a subset of these properties, and some may not
/// not support any at all.
///
/// @see VIDEO_setPropertyLong
/// @see VIDEO_getPropertyLong
/// @see VIDEO_setPropertyString
/// @see VIDEO_getPropertyString
///

///
/// Identifies a camera image property
///
typedef int VWCamProp;

// built-in properties
#define VWCAMPROP_BRIGHTNESS				100	/**< The brightness property of the camera.*/
#define VWCAMPROP_CONTRAST					101	/**< The contrast property of the camera.*/
#define VWCAMPROP_HUE						102	/**< The hue property of the camera.*/	
#define VWCAMPROP_SATURATION				103	/**< The saturation property of the camera.*/
#define VWCAMPROP_SHARPNESS					104	/**< The sharpness property of the camera.*/
#define VWCAMPROP_GAMMA						105	/**< The gamma property of the camera.*/
#define VWCAMPROP_COLORENABLE				106	/**< Property to enable color on the camera.*/
#define VWCAMPROP_WHITEBALANCE				107	/**< The white balance property of the camera.*/
#define VWCAMPROP_BACKLIGHTCOMPENSATION		108	/**< The backlight compensation property of the camera.*/
#define VWCAMPROP_GAIN						109	/**< The gain property of the camera.*/
#define VWCAMPROP_EXPOSURE					110	/**< The exposure property of the camera.*/
#define VWCAMPROP_IRIS						111	/**< The iris property of the camera.*/
#define VWCAMPROP_FOCUS						112	/**< The focus property of the camera.*/
#define VWCAMPROP_ZOOM						113	/**< The zoom property of the camera.*/
#define VWCAMPROP_PAN						114	/**< The pan property of the camera.*/
#define VWCAMPROP_TILT						115	/**< The tilt property of the camera.*/
#define VWCAMPROP_SHUTTER					116	/**< The shutter property of the camera.*/
#define VWCAMPROP_TRIGGER_DELAY				117	/**< The trigger delay property of the camera.*/

///
/// VWCAMPROP_CUSTOM provides a base value for defining custom properties.  Custom
/// properties must have a value greater-than-or-equal-to VWCAMPROP_CUSTOM.
/// 
/// Example:
/// @code
/// #define MYCUSTOMPROP_FOO    VWCAMPROP_CUSTOM + 1
/// #define MYCUSTOMPROP_BAR    VWCAMPROP_CUSTOM + 2
/// @endcode
///
#define VWCAMPROP_CUSTOM					1000

//@}

// ------------------------------------------------------------------------------------------
// misc. symbols
// ------------------------------------------------------------------------------------------

///
/// Symbol indicating no buffer limits for VIDEO_StartCapture.
///
#define VW_UNLIMITED_BUFFER		-1


#endif // ifndef _VIDEOWRAPPERTYPES_H