#ifndef _LGRYTYPE_H_
#define _LGRYTYPE_H_

#include <pshpack1.h>

#define  LGRY_RESCALE_VALID   0x0001   // if set, biRescaleIntercept and biRescaleSlope are valid
#define  LGRY_WINDOW_VALID    0x0002   // if set, biWindowSize and biWindowCenter are valid
#define  LGRY_BITRANGE_VALID  0x0004   // if set, biLowBit and biHighBit are valid
#define  LGRY_MINMAX_VALID    0x0010   // if set, biMinVal and biMaxVal are valid
#define  LGRY_LUT_ISGENERATED 0x0020   // If there is a LUT:
                                       //    if set, the LUT is generated from the valid LGRY-specific fields
                                       //       (The DICOM reader should always set this)
                                       //    if not set, the LUT cannot be regenerated from the other LGRY fields.
                                       //       In this case, the LUT needs to be saved in the file
#define  LGRY_LUT_ISGRAYSCALE 0x0040   // If there is a LUT and this flag is set, then the LUT contains
                                       //    only grayscale values. This flag is set to avoid going 
                                       //    through the LUT every time to detect whether the LUT contains
                                       //    only grayscale colors.
#define  LGRY_LUT_ISCOLOR     0x0080   // If there is a LUT and this flag is set, then the LUT contains
                                       //    non-grayscale values. This flag is set to avoid going 
                                       //    through the LUT every time to detect whether the LUT contains
                                       //    only grayscale colors.
#define  LGRY_LUT_COLORMASK   0x00C0   // This is NOT a flag. It is a MASK which can be used to detect
                                       //    whether a LUT is color, grayscale or unknown.

typedef struct tagLGRYINFOHEADER
{
   // BITMAPINFOHEADER fields
   DWORD    biSize;           // should be sizeof(LGRYINFOHEADER)
   LONG     biWidth;
   LONG     biHeight;
   WORD     biPlanes;         // should be 1
   WORD     biBitCount;       // should be 12 or 16.
                              // if 16, the data is in Intel order
                              // if 12, the data is in LEAD packing with 3 bytes for every 2 pixels
   DWORD    biCompression;    // should be 'LGRY'=mmioFOURCC('L','G','R','Y')
   DWORD    biSizeImage;
   LONG     biXPelsPerMeter;
   LONG     biYPelsPerMeter;
   DWORD    biClrUsed;        // 0 if the LUT is not present (bmiColors field is not used/needed)
                              // != 0 if there is a LUT. bmiColors contains the LUT
                              // biClrUsed should be equal to 1<<(biHighBit - biLowBit + 1)
   DWORD    biClrImportant;   // not used right now. Set this value to 0

   // LGRY-specific fields
   LONG     biLowBit;         // low bit for the pixel data (0 <= biLowBit <= biHighBit <= biBitCount-1)
   LONG     biHighBit;        // high bit for pixel data
   LONG     biMinVal;         // min value of the pixel data only (ignores the non-pixel bits)
   LONG     biMaxVal;         // max value of the pixel data only (ignores the non-pixel bits)
   LONG     biWindowWidth;    // DICOM window width.         This can be used to regenerate the LUT
   LONG     biWindowCenter;   // DICOM window center.        This can be used to regenerate the LUT
   double   biRescaleIntercept;  // DICOM rescale intercept. This can be used to regenerate the LUT
   double   biRescaleSlope;      // DICOM rescale slope.     This can be used to regenerate the LUT
   DWORD    biFlags;          // Tells which fields are valid. 
                              // This will be a combination of LGRY_XXX flags

   // reserved fields for future use
   LONG     nReserved1;
   LONG     nReserved2;
   LONG     nReserved3;
} LGRYINFOHEADER, FAR*pLGRYINFOHEADER;

typedef struct
{
   RECT           rcSource;          // The image portion we really want to use
   RECT           rcTarget;          // Where the video should go
   DWORD          dwBitRate;         // Approximate bit data rate
   DWORD          dwBitErrorRate;    // Bit error rate for this stream
   REFERENCE_TIME AvgTimePerFrame;   // Average time per frame (100ns units)

   LGRYINFOHEADER bmiHeader;

   RGBQUAD        bmiColors[65536];  // Remapping lookup table (LUT)
} LGRYVIDEOINFO, FAR*pLGRYVIDEOINFO;


/*
   12-bit data is packed, every 2 pixels occupy 3 bytes.
   For example, if you have 2 12-bit values and their hex values are 0xABC and 0xDEF,
      they will be stored in memory like this:
         0xBC 0xFA 0xDE
   This has the advantage that you can get each value on INtel processors with one read
      and one operation (and with 0xFFF for first value, shift right 4 bits for the second value).

   The following macros can be used to deal with 12-bit packed data:
*/

// helper macro for incrementing a pointer
#define PTR_INC(p) (((BYTE*)p)+1)

// read first 12-bit value
#define GET12_0(p) ((*(WORD*)p) & 0xFFF)
// read second 12-bit value
#define GET12_1(p) ((*(WORD*)PTR_INC(p)) >> 4)

// write two 12-bit values
#define PUT12(p, val0, val1) *(WORD*)p = (WORD)(((val0) & 0xFFF) | ((WORD)(val1) << 12)); \
                               ((BYTE*)p)[2] = (BYTE)((DWORD)(val1) >> 4)
// write the first 12-bit value
#define PUT12_0(p, val0)      *(WORD*)p = (WORD)( (*(WORD*)(p) & 0xF000) | ((val0) & 0xFFF) )
// write the second 12-bit value
#define PUT12_1(p, val1)      *(WORD*)PTR_INC(p) = (WORD)( (*(WORD*)PTR_INC(p) & 0xF) | ((WORD)(val1) << 4) )

#include <poppack.h>

#endif   // _LGRYTYPE_H_
