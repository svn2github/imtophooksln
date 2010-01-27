//  ==========================================================================================
/// @file	VideoWrapperConvert.h
///
/// Declares functions that may be used for image conversion.
///
/// Copyright 2009, Georgia Tech Research Corporation, Atlanta, Georgia 30332-0415
/// All Rights Reserved 
///
//  ==========================================================================================

#include "VideoWrapper.h"

#ifndef	_VIDEOWRAPPERCONVERT_H
#define	_VIDEOWRAPPERCONVERT_H

#ifdef __cplusplus
extern "C"
{
#endif
	
// ------------------------------------------------------------------------------------------
// byteToFloatBuffer
// ------------------------------------------------------------------------------------------
///
/// Converts a byte array buffer to a float array buffer
///
/// @param	src		Source image buffer.
/// @param	dst		Destination image buffer.
/// @param	width	Width of source image.
/// @param	height	Height of source image.
///
VW_API void HELPER_ByteXYZAToFloatZYXA(void *src, void *dst,
									   unsigned int width, unsigned int height);

VW_API void HELPER_ByteXYZToFloatXYZA(void *src, void *dst,
									  unsigned int width, unsigned int height);

// ------------------------------------------------------------------------------------------
// TestPattern
// ------------------------------------------------------------------------------------------
///
/// Converts a byte array buffer to a float array buffer
///
/// @param	src		Source image buffer.
/// @param	dst		Destination image buffer.
/// @param	width	Width of source image.
/// @param	height	Height of source image.
///
VW_API void HELPER_TestPaternFloatXYZA(void *dst,
									  unsigned int width, unsigned int height, float time);
#ifdef __cplusplus
}
#endif

#endif	// ndef	_VIDEOWRAPPERCONVERT_H
