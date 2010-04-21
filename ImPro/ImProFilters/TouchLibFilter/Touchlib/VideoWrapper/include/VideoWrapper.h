//  ==========================================================================================
/// @file	VideoWrapper.h
///
/// Declares VideoWrapper, an interface adapter for multiple video capture APIs.
///
/// Copyright 2003-5, Georgia Tech Research Corporation, Atlanta, Georgia 30332-0415
/// All Rights Reserved 
///
//  ==========================================================================================

#ifndef _VIDEOWRAPPER_H
#define _VIDEOWRAPPER_H

#include "VideoWrapperTypes.h"

// uncomment this if you do not want to include the capture functionality
#define _VW_NO_CAPTURE	

// for the timeval definition
#ifdef UNIX
	#include <sys/time.h>
#else
	#include <time.h>
#endif

#ifdef __cplusplus
extern "C"
{
#endif

// ==========================================================================================
// entry point macros
// ==========================================================================================
// This defines the calling conventions of the entry points for
// dynamic libraries. This varies depending upon the operating system.

#ifdef _LIB // static library
    #define	VW_API 
    #define	VW_API_ENTRY __cdecl
    typedef void (* DLL_EP)(void);
    #define	DLL_EP_PTR __cdecl *
#else
#if defined (_WIN32) || defined(WIN32) || defined(__WIN32__)
	#ifdef VW_API_EXPORTS
		#define	VW_API __declspec(dllexport)
	#else
		#define	VW_API __declspec(dllimport)
	#endif
    #define	VW_API_ENTRY __cdecl
    typedef void (* DLL_EP)(void);
    #define	DLL_EP_PTR __cdecl *
#else
    #define	VW_API
    #define	VW_API_ENTRY
    typedef void (* DLL_EP)(void);
    #define	DLL_EP_PTR *
#endif
#endif


// ==========================================================================================
// api management functions
// ==========================================================================================
//@{
/// @name	Camera Library Management Functions

// ------------------------------------------------------------------------------------------
// VIDEO_loadLibrary
// ------------------------------------------------------------------------------------------
///
/// Dynamically loads support for a camera library.  Some camera libraries are 'preset'
/// and VideoWrapper can load them automatically, however this function allows VideoWrapper
/// to be extended at runtime to support additional camera libraries.
///
/// @param[in]	szLibIdentifier			Identifier to represent library in calls to VIDEO_openVideo.
/// @param[in]	szLibImplementation		Platform-specific implementation string.
///										- Windows: File name of DLL implementing support.
///										- Apple: Unsupported.
///
/// @return		VWResult indicating success or failure.
///
VW_API VWResult VW_API_ENTRY VIDEO_loadLibrary(char* szLibIdentifier, char* szLibImplementation);

///
/// Type definition for print callback functions.
///
typedef void (VW_API_ENTRY VWPrintFcn)(char *);

// ------------------------------------------------------------------------------------------
// VIDEO_setPrintFunction
// ------------------------------------------------------------------------------------------
///
/// Sets a callback function that may be used for printing messages from the video libraries.
///
/// @param	function:	ptr to print function
///
VW_API VWResult VW_API_ENTRY VIDEO_setPrintFunction(VWPrintFcn *fp);

//@}

// ==========================================================================================
// camera management functions 
// ==========================================================================================

//@{
/// @name	Camera Management Functions

// ------------------------------------------------------------------------------------------
// VIDEO_openVideo
// ------------------------------------------------------------------------------------------
///
/// Intializes a video camera.
///
/// @param[in]	szInit	An implementation-dependent string used to configure the camera. 
///				.
///				Consult the 'VideoWrapper_xxx Details' page for the API adapter you are instantiating for
///				the string format.  Generally, however, the string is formatted as follows:
///				.
///				"libId: camNum width frameRate colorMode scale outputMode" 
///				.
///				where
///				- \c libId \c is the identifier for the API adapter library.
///				- \c camNum \c is a number (starting at 0) representing the camera to open.
///				- \c width \c is the desired frame width.
///				- \c frameRate \c is the desired frame rate
///				- \c colorMode \c is a string specifying the format of the desired color mode (e.g. rgb, yuv).
///				- \c scale \c is 0 or 1. 1 means a mode of 2x or 4x the size can be used, and scaled to the correct size.
///				.
///				A noteable exception is the "replay" camera library, which will replay
///				video frames that have been previously saved.  In this case szInit takes the
///				form: 
///				.
///				\c "replay: directory" \c
///				.
///				where 
///				- \c replay \c is the identifier of the replay camera library.
///				- \c directory \c is the path to the directory containing the saved video frames.
/// @param[out]	phVideo		Pointer to the handle for opened camera.
///
/// @return		VWResult indicating success or failure.
///
///
VW_API VWResult VW_API_ENTRY VIDEO_openVideo(char* szInit, VWHVideo* phVideo);


// ------------------------------------------------------------------------------------------
// VIDEO_close
// ------------------------------------------------------------------------------------------
///
/// Close the video camera.
///
/// @param		hVideo			Handle to video camera.
///
/// @return		VWResult indicating success or failure.
///
VW_API VWResult VW_API_ENTRY VIDEO_close(VWHVideo hVideo);

// ------------------------------------------------------------------------------------------
// VIDEO_startVideo
// ------------------------------------------------------------------------------------------
///
/// Starts aquiring frames from the camera.
///
/// @param		hCam	Handle to video camera.
///
/// @return		VWResult indicating success or failure.
///
VW_API VWResult VW_API_ENTRY VIDEO_startVideo(VWHVideo hVideo);

// ------------------------------------------------------------------------------------------
// VIDEO_stopVideo
// ------------------------------------------------------------------------------------------
///
/// Stops aquiring frames from the camera.
///
/// @param		hCam	Handle to video camera.
///
/// @return		VWResult indicating success or failure.
///
VW_API VWResult VW_API_ENTRY VIDEO_stopVideo(VWHVideo hVideo);


// ------------------------------------------------------------------------------------------
// VIDEO_resetVideo
// ------------------------------------------------------------------------------------------
///
/// Resets all the camera parameters to defaults.
///
/// @param		hVideo			Handle to video camera.
/// @param		bAutomatic		If true, allow the camera to auto-adust.
///
/// @return		VWResult indicating success or failure.
///
VW_API VWResult VW_API_ENTRY VIDEO_resetVideo(VWHVideo hVideo, VWBool bAutomatic);

//@}


// ==========================================================================================
// frame capture functions
// ==========================================================================================
//@{
/// @name	 Frame Capture Functions

// ------------------------------------------------------------------------------------------
// VIDEO_getFrame
// ------------------------------------------------------------------------------------------
///
/// Polls for new video frame.
///
/// @param		hVideo			Handle to video camera.
/// @param[out]	ppbFrame		Pointer returning the captured video frame.  Memory is alocated
///								by the camera library.  If no frame is availible, ppbFrame returns
///								NULL.
/// @param[out]	pTimestamp		Pointer returning the timestamp of the captured video frame.
/// 
/// @return		VWResult indicating success or failure.
///
VW_API VWResult VW_API_ENTRY VIDEO_getFrame(VWHVideo hVideo, unsigned char** ppbFrame, timeval* pTimestamp);

// ------------------------------------------------------------------------------------------
// VIDEO_releaseFrame
// ------------------------------------------------------------------------------------------
///
/// Releases the frame so that memory may be deallocated.
///
/// @param		hVideo			Handle to video camera.
///
/// @return		VWResult indicating success or failure.
///
VW_API VWResult VW_API_ENTRY VIDEO_releaseFrame(VWHVideo hVideo);

// ------------------------------------------------------------------------------------------
// VIDEO_getFrameRate
// ------------------------------------------------------------------------------------------
///
/// Gets the frame rate of the camera as frames per second.
///
/// @param		hVideo			Handle to video camera.
/// @param[out]	pdFrameRate		Pointer returning the frame rate of the camera.
///
/// @return		VWResult indicating success or failure.
///
VW_API VWResult VW_API_ENTRY  VIDEO_getFrameRate(VWHVideo hVideo, double* pdFrameRate);

//@}

// ==========================================================================================
// image format accessor functions
// ==========================================================================================
//@{
/// @name	Image Format Accessor Functions

// ------------------------------------------------------------------------------------------
// VIDEO_getWidth
// ------------------------------------------------------------------------------------------
///
/// Gets the video width. 
///
/// @param		hVideo			Handle to video camera.
/// @param[out]	pnWidth			Pointer returning the width of the video.
///
/// @return		VWResult indicating success or failure.
///
VW_API VWResult VW_API_ENTRY VIDEO_getWidth(VWHVideo hVideo, int* pnWidth);


// ------------------------------------------------------------------------------------------
// VIDEO_getHeight
// ------------------------------------------------------------------------------------------
///
/// Gets the video height.
///
/// @param		hVideo			Handle to video camera.
/// @param[out]	pnHeight		Pointer returning the height of the video.
///
/// @return		VWResult indicating success or failure.
///
VW_API VWResult VW_API_ENTRY VIDEO_getHeight(VWHVideo hVideo, int* pnHeight);


// ------------------------------------------------------------------------------------------
// VIDEO_getPixelFormat
// ------------------------------------------------------------------------------------------
// TODO: doc
///
/// Gets the pixel format.
///
/// @param		hVideo			Handle to video camera.
/// @param[out]	pnFormat		Pointer returning an integer expressing the pixel format.
///
/// @return		VWResult indicating success or failure.
///
/// @see		VWPixelFormat
///
VW_API VWResult VW_API_ENTRY VIDEO_getPixelFormat(VWHVideo hVideo, int* pnFormat);

// ------------------------------------------------------------------------------------------
// VIDEO_getDepth
// ------------------------------------------------------------------------------------------
///
/// Gets color depth as bits per pixel 
///
/// @param		hVideo			Handle to video camera.
/// @param[out]	pnDepth			Pointer returning the bits per pixel.
///
/// @return		VWResult indicating success or failure.
///
VW_API VWResult VW_API_ENTRY VIDEO_getDepth(VWHVideo hVideo, int* pnDepth);

//@}

// ==========================================================================================
// error reporting
// ==========================================================================================
//@{
/// @name	Error Reporting Functions

// ------------------------------------------------------------------------------------------
// VIDEO_getErrDescription
// ------------------------------------------------------------------------------------------
///
/// Gets a string describing the given VWResult code.
///
/// @param		resultCode		VWResult code to describe.
///
/// @return		A string describing the VWResult code
///
VW_API char* VW_API_ENTRY VIDEO_getErrDescription( VWResult resultCode);

// @}

// ==========================================================================================
// camera property functions
// ==========================================================================================
//@{
///	@name	Camera Property Functions

// ------------------------------------------------------------------------------------------
// VIDEO_showPropertiesDialog
// ------------------------------------------------------------------------------------------
///
/// Displays the a pop-up property window associated with this device.  Not supported by all 
/// camera libraries.
///
/// @param		hVideo			Handle to video camera.
///
/// @return		VWResult indicating success or failure.
///
VW_API VWResult VW_API_ENTRY VIDEO_showPropertiesDialog(VWHVideo hVideo);

// ------------------------------------------------------------------------------------------
// VIDEO_setPropertyLong
// ------------------------------------------------------------------------------------------
///
/// Sets a long-typed camera property such as white balance, gain, etc.  Some properties
/// are composed of two values.  Symbols for camera properties are defined in 
/// VideoWrapperTypes.h.
///
/// @param		propId		Identifier of the property.
/// @param		lValue1		First property value.
/// @param		lValue2		Second property value.  Not used with most properties.
///
/// @return		VWResult indicating success or failure.
///
/// @see		VWCamProp
///
VW_API VWResult VW_API_ENTRY VIDEO_setPropertyLong( VWHVideo hVideo, VWCamProp propId, long lValue1, long lValue2 = 0L, VWBool bAuto = FALSE);

// ------------------------------------------------------------------------------------------
// VIDEO_getPropertyLong
// ------------------------------------------------------------------------------------------
///
/// Gets a long-typed camera property such as white balance, gain, etc.  Some properties
/// are composed of two values.  Symbols for camera properties are defined in 
/// VideoWrapperTypes.h.
///
/// @param		propId		Identifier of the property.
/// @param[out]	plValue1	Pointer returning first property value.
/// @param[out]	plValue2	Pointer returning second property value.  Not used with most properties.
///
/// @return		VWResult indicating success or failure.
///
/// @see		VWCamProp
///
VW_API VWResult VW_API_ENTRY VIDEO_getPropertyLong( VWHVideo hVideo, VWCamProp propId, long* plValue1 = NULL, long* plValue2 = NULL, VWBool* pbAuto = NULL);


// ------------------------------------------------------------------------------------------
// VIDEO_getPropertyRangeLong
// ------------------------------------------------------------------------------------------
///
/// Gets the valid range for a  long-typed camera property such as white balance, gain, etc.
/// Symbols for camera properties are defined in VideoWrapperTypes.h.
///
/// @param		propId		Identifier of the property.
/// @param		lValue1		First property value.
/// @param		lValue2		Second property value.  Not used with most properties.
///
/// @return		VWResult indicating success or failure.
///
/// @see		VWCamProp
///
VW_API VWResult VW_API_ENTRY VIDEO_getPropertyRangeLong( VWHVideo hVideo, VWCamProp propId, long* plMinValue = NULL, long* plMaxValue = NULL, VWBool* pbAuto = NULL);

// TODO: keep double property functions?
/*
VW_API VWResult VW_API_ENTRY VIDEO_setPropertyDouble( VWHVideo hVideo, VWCamProp propId, long lValue1, long lValue2 = 0L, VWBool bAuto = FALSE);
VW_API VWResult VW_API_ENTRY VIDEO_getPropertyDouble( VWHVideo hVideo, VWCamProp propId, long* plValue1 = NULL, long* plValue2 = NULL, VWBool* pbAuto = NULL);
VW_API VWResult VW_API_ENTRY VIDEO_getPropertRangeDouble( VWHVideo hVideo, VWCamProp propId, long* plMinValue = NULL, long* plMaxValue = NULL, VWBool* pbAuto = NULL);
*/

// ------------------------------------------------------------------------------------------
// VIDEO_setPropertyString
// ------------------------------------------------------------------------------------------
///
/// Sets a string-typed camera property.
///
/// @param		propId		Identifier of the property.
/// @param[in]	szValue		Property value.
///
/// @return		VWResult indicating success or failure.
///
/// @see		VWCamProp
///
VW_API VWResult VW_API_ENTRY VIDEO_setPropertyString( VWHVideo hVideo, VWCamProp propId, char* szValue);

// ------------------------------------------------------------------------------------------
// VIDEO_getPropertyString
// ------------------------------------------------------------------------------------------
///
/// Gets a string-typed camera property.
///
/// @param		propId		Identifier of the property.
/// @param[in]	szValue		Property value.
///
/// @return		VWResult indicating success or failure.
///
/// @see		VWCamProp
///
VW_API VWResult VW_API_ENTRY VIDEO_getPropertyString( VWHVideo hVideo, VWCamProp propId, char* szValue, int nSize);

// ------------------------------------------------------------------------------------------
// VIDEO_getAvailablePropertyStrings
// ------------------------------------------------------------------------------------------
///
/// Gets all the available property strings for all the supported and available cameras.
///
/// @param		propertyStringsCount		A pointer to a user reserved integer where the number of available property strings will be stored.
/// @param[in]	propertyStrings		A pointer to a 2 dimensional array of characters. The function itself will reserve the necessary amount of memory, so the user should deallocate it using releaseAvailablePropertyStrings.
///
/// @return		VWResult indicating success or failure.
///
/// @see		VWCamProp
///
VW_API VWResult VW_API_ENTRY VIDEO_getAvailablePropertyStrings( int* propertyStringsCount, char*** propertyStrings);

// ------------------------------------------------------------------------------------------
// VIDEO_getAvailablePropertyStrings
// ------------------------------------------------------------------------------------------
///
/// Release the reserved all the available property strings for all the supported and available cameras.
///
/// @return		VWResult indicating success or failure.
///
/// @see		VWCamProp
///
VW_API VWResult VW_API_ENTRY VIDEO_releaseAvailablePropertyStrings();

//@}

// ==========================================================================================
// disk capture functions
// ==========================================================================================
//@{
/// @name Disk Capture Functions

// ------------------------------------------------------------------------------------------
// VIDEO_startFramesToDisk
// ------------------------------------------------------------------------------------------
///
/// Starts the capture of video frames to disk.  Frames are written as TIFFs.  This version
/// does not write frames to disk until VIDEO_stopFramesToDisk is executed.  Unless lBufferSizeLimit
/// is set to VW_UNLIMITED_BUFFER, frames will be discarded when the buffer limit is reached.
///
/// @param		hVideo					Handle to video camera.
/// @param		szOutputDirectory		Directory to write frames.
///										start-time for video capture.
/// @param		lBufferSizeLimit		Limit for capture buffer in bytes.  Set to VW_UNLIMITED_BUFFER 
///										for unlimited buffer size.
/// 
/// @return		VWResult indicating success or failure.
///
/// @note		The current implementation is not very efficient and recommended only for 
/// small captures.
///
VW_API VWResult VW_API_ENTRY VIDEO_startFramesToDisk(VWHVideo hVideo, char* szOutputDirectory, long lBufferSizeLimit = VW_UNLIMITED_BUFFER);


// ------------------------------------------------------------------------------------------
// VIDEO_stopFramesToDisk
// ------------------------------------------------------------------------------------------
///
/// Stops the capture of frames to disk.
///
/// @param		hVideo			Handle to video camera.
/// @param[out]	pnFrames		Pointer returning the number of frames captured.
///
/// @return		VWResult indicating success or failure.
///
VW_API VWResult VW_API_ENTRY VIDEO_stopFramesToDisk(VWHVideo hVideo, int* pnFrames = NULL);

//@}

// ==========================================================================================
// replay camera functions
// ==========================================================================================
//{@
/// @name	Replay Camera Functions
///
/// These functions operate only on the "replay" camera.
///

// ------------------------------------------------------------------------------------------
// VIDEO_replaySetPlaybackPosition
// ------------------------------------------------------------------------------------------
///
/// Sets the current position for video playback to permit random access
///
/// @param		hVideo			Handle to video camera.
/// @param		tvNewPosition	Time offset from the beginning of the captured video.
///
/// @return		VWResult indicating success or failure.
///
VW_API VWResult VW_API_ENTRY VIDEO_replaySetPlaybackPosition( VWHVideo hVideo, timeval tvNewPosition);

// ------------------------------------------------------------------------------------------
// VIDEO_replaySetPlaybackLoop
// ------------------------------------------------------------------------------------------
///
/// Sets the loop state of the replay camera.  Has no effect with other camera libraries.
/// If the loop state is true, video playback will loop when the end is reached.
///
/// @param		hVideo		Handle to video camera.
/// @param		bLoop		The new loop state.
///
/// @return		VWResult indicating success or failure.
///
VW_API VWResult VW_API_ENTRY VIDEO_replaySetPlaybackLoop( VWHVideo hVideo, VWBool bLoop);

// ------------------------------------------------------------------------------------------
// VIDEO_replayIsPlaybackFinished
// ------------------------------------------------------------------------------------------
///
/// Checks to see if playback is finished.  Will return true after a call to getNextFrame 
/// goes past the last saved frame.
///
/// @param		hVideo			Handle to video camera.
/// @param[out]	pbFinished		Pointer returning TRUE if playback is finished, otherwise FALSE.
///
/// @return		VWResult indicating success or failure.
///
VW_API VWBool VW_API_ENTRY VIDEO_replayIsPlaybackFinished( VWHVideo hVideo, VWBool* pbFinished);

// ------------------------------------------------------------------------------------------
// VIDEO_getPropertyName
// ------------------------------------------------------------------------------------------
///
/// Returns a string that represents the name of a property (the same as the constant).
///
/// @param		property			The property to get tha name from.
/// @param[out]	name		Pointer returning the name of the property. Enough memory should be reserved.
///
/// @return		VWResult indicating success or failure.
///
VW_API VWResult VW_API_ENTRY VIDEO_getPropertyName( VWCamProp property, char* name);

//@}

#ifdef __cplusplus
}
#endif

#endif // ifndef _VIDEOWRAPPER_H


