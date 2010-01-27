//  ==========================================================================================
/// @file	VideoWrapperTime.h
///
/// Declares time functions to support video wrappers.  Most functions have been copied
/// from VRPN.
///
/// Copyright 2005, Georgia Tech Research Corporation, Atlanta, Georgia 30332-0415
/// All Rights Reserved 
///
//  ==========================================================================================

#ifndef _VIDEOWRAPPERTIME_H
#define _VIDEOWRAPPERTIME_H

#include "CommonSupport.h"

#if defined(_WIN32) || defined(WIN32) || defined(__WIN32__)
   #include <windows.h>
#else
    #ifndef UNIX
        #define UNIX
    #endif
#endif

#ifdef WIN32
#include <sys/timeb.h>
#include <time.h>
#else
#include <sys/time.h>
#endif 

// ------------------------------------------------------------------------------------------
// struct timezone
// ------------------------------------------------------------------------------------------
// TODO: doc
// these are not defined for windows!
// copied from from HP-UX

#ifndef UNIX
  #ifndef _STRUCT_TIMEZONE
	#define _STRUCT_TIMEZONE

	struct timezone 
	{
		int     tz_minuteswest; // minutes west of Greenwich
		int     tz_dsttime;     // type of dst correction
	};
  #endif
#endif


// ------------------------------------------------------------------------------------------
// vw_gettimeofday
// ------------------------------------------------------------------------------------------
///
/// Implementation of 'gettimeofday'.
///
/// Although VC++ doesn't include a gettimeofday
/// call, Cygnus Solutions Cygwin32 environment does,
/// so this is not used when compiling with gcc under WIN32.
///
/// @param[out]	tp			Pointer to a timeval structure receiving the current time.
/// @param[out]	tzp			Pointer to a timezon structure receiving the current time zone information.
/// 
/// @return		Returns 0 if successful.
///
CS_API int CS_API_ENTRY vw_gettimeofday(timeval *tp, struct timezone *tzp);


// ==========================================================================================
// timeval operations copied from vrpn
// ==========================================================================================

// ------------------------------------------------------------------------------------------
// TimevalSum
// ------------------------------------------------------------------------------------------
///
/// Calculates the sum of tv1 and tv2.  Returns the sum in an timeval struct.
/// Calculates negative times properly, with the appropriate sign on both tv_sec
/// and tv_usec (these signs will match unless one of them is 0).
/// NOTE: both abs(tv_usec)'s must be < 1000000 (ie, normal timeval format)
///
/// @param		tv1			a timeval structure.
/// @param		tv2			another timeval structure.
/// 
/// @return		Sub of tv1 and tv2.
///
//
CS_API timeval CS_API_ENTRY TimevalSum( const timeval& tv1, const timeval& tv2 );

// ------------------------------------------------------------------------------------------
// TimevalDiff
// ------------------------------------------------------------------------------------------
///
/// Calculates the diff between tv1 and tv2.  Returns the diff in a timeval struct.
/// Calculates negative times properly, with the appropriate sign on both tv_sec
/// and tv_usec (these signs will match unless one of them is 0)
///
/// @param		tv1			a timeval structure.
/// @param		tv2			another timeval structure.
/// 
/// @return		Returns diff of tv1 and tv2.
///
CS_API timeval CS_API_ENTRY TimevalDiff( const timeval& tv1, const timeval& tv2 );

// ------------------------------------------------------------------------------------------
// TimevalGreater
// ------------------------------------------------------------------------------------------
///
/// Tests two timeval structures for a greater-than relationship.
///
/// @param		tv1			a timeval structure.
/// @param		tv2			another timeval structure.
/// 
/// @return		Returns 1 if tv1 is greater than tv2; 0 otherwise.
///
CS_API int CS_API_ENTRY TimevalGreater (const timeval & tv1, const timeval & tv2);

// ------------------------------------------------------------------------------------------
// TimevalEqual
// ------------------------------------------------------------------------------------------
///
/// Tests two timeval structures for equality.
///
/// @param		tv1			a timeval structure.
/// @param		tv2			another timeval structure.
/// 
/// @return		Returns 1 if tv1 is equal to tv2; 0 otherwise.
///
//
CS_API int CS_API_ENTRY TimevalEqual( const timeval& tv1, const timeval& tv2 );


// ------------------------------------------------------------------------------------------
// TimevalMsecs
// ------------------------------------------------------------------------------------------
///
/// Converts a timeval structure to milliseonds.
///
/// @param		tv			a timeval structure.
/// 
/// @return		Milliseconds equivalent to tv.
///
CS_API double CS_API_ENTRY TimevalMsecs( const timeval& tv );


// ------------------------------------------------------------------------------------------
// MsecsTimeval
// ------------------------------------------------------------------------------------------
///
/// Converts milliseconds to a timeval structure.
///
/// @param		dMsecs			Milliseconds.
/// 
/// @return		timeval equivalent to dMsecs.
///
//
CS_API timeval CS_API_ENTRY MsecsTimeval( const double dMsecs );


#endif // ifndef _VIDEOWRAPPERTIME_H

