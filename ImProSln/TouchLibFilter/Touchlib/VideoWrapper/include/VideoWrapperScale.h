//  ==========================================================================================
/// @file	VideoWrapperScale.h
///
/// Declares functions that may be used for image scaling.
///
/// Copyright 2004-5, Georgia Tech Research Corporation, Atlanta, Georgia 30332-0415
/// All Rights Reserved 
///
//  ==========================================================================================

#ifndef	_VIDEOWRAPPERSCALE_H
#define	_VIDEOWRAPPERSCALE_H

#include "CommonSupport.h"

// ------------------------------------------------------------------------------------------
// scaleDownPower2Fast
// ------------------------------------------------------------------------------------------
///
/// Scales down an image.  Faster than scaleDownPower2Slow(), but with less acurate 
/// down sampling.
///
/// @param	src		Source image buffer.
/// @param	dst		Destination image buffer.
/// @param	width	Width of source image.
/// @param	height	Height of source image.
/// @param	factor	Factor by which to down sample the image.
///
CS_API void CS_API_ENTRY scaleDownPower2Fast(unsigned char* src, unsigned char* dst,
					     unsigned int width, unsigned int height, int factor);
// ------------------------------------------------------------------------------------------
// scaleDownPower2Slow
// ------------------------------------------------------------------------------------------
///
/// Scales down an image.  Slower than scaleDownPower2Slow(), but with more acurate 
/// down sampling.
///
/// @param	src		Source image buffer.
/// @param	dst		Destination image buffer.
/// @param	width	Width of source image.
/// @param	height	Height of source image.
/// @param	factor	Factor by which to down sample the image.
///
CS_API void CS_API_ENTRY scaleDownPower2Slow(unsigned char* src, unsigned char* dst,
					     unsigned int width, unsigned int height, int factor);



#endif	// ndef	_VIDEOWRAPPERSCALE_H
