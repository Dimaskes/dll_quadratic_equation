#pragma once

#ifdef LIB_EXPORT
#define LIB_API __declspec(dllexport)
#else
#define LIB_API __declspec(dllimport)
#endif

extern "C" LIB_API int discriminant(int a, int b, int c);
extern "C" LIB_API double* quadraticEquation(int a, int b, int c);