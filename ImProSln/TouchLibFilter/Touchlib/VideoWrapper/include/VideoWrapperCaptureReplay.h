//  ==========================================================================================
/// @file	VideoWrapperCaptureReplay.h
///
/// Declares functions for video capture and replay.
/// .
/// Copyright 2005, Georgia Tech Research Corporation, Atlanta, Georgia 30332-0415
/// All Rights Reserved 
///
//  ==========================================================================================

#define _VW_NO_CAPTURE	

#ifndef _VW_NO_CAPTURE	// ignore the entire file if defined

#ifdef __cplusplus
extern "C" {
#endif

// TODO: doc

// ------------------------------------------------------------------------------------------
// captureFrame
// ------------------------------------------------------------------------------------------
void captureFrame( VWHVideo hVideo, unsigned char **ppbFrame, struct timeval *ts);

// ------------------------------------------------------------------------------------------
// isCapturing
// ------------------------------------------------------------------------------------------
VWBool isCapturing( VWHVideo hVideo);


// ------------------------------------------------------------------------------------------
// replay functions
// ------------------------------------------------------------------------------------------

void replayPrint(VWPrintFcn *fcn);
VWResult replayOpenCamera(char *config, VWHCamera*);
VWResult replayGetFrame(VWHCamera, unsigned char **im, struct timeval *ts);
VWResult replayReleaseFrame(VWHCamera);
VWResult replayResetCamera(VWHCamera, bool flag);
VWResult replayShowProperties(VWHCamera);
VWResult replayClose(VWHCamera);
VWResult replayStartVideo(VWHCamera);
VWResult replayStopVideo(VWHCamera);
VWResult replayGetWidth(VWHCamera, int*);
VWResult replayGetHeight(VWHCamera, int*);
VWResult replayGetPixelFormat(VWHCamera, VWPixelFormat*);
VWResult replayGetDepth(VWHCamera, int*);
VWResult replayGetFrameRate(VWHCamera, double*);
VWResult replaySetPropertyLong(VWHCamera, VWCamProp, long, long, VWBool);
VWResult replayGetPropertyLong(VWHCamera, VWCamProp, long*, long*, VWBool*);
VWResult replayGetPropertyRangeLong(VWHCamera, VWCamProp, long*, long*, VWBool*);

VWResult replaySetPlaybackPosition( VWHCamera, timeval);
VWResult replaySetPlaybackLoop( VWHCamera hCam, VWBool bLoop);
VWResult replayIsPlaybackFinished( VWHCamera hCam, VWBool* pbFinished);

#ifdef __cplusplus  
};
#endif

#endif //ndef _VW_NO_CAPTURE
