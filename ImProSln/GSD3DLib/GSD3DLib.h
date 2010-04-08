#pragma once

#ifdef GSD3DLIB_EXPORTS
#define GSD3DLIB_API __declspec(dllexport)
#else
#define GSD3DLIB_API __declspec(dllimport)
#endif