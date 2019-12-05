#ifndef __MAIN_H__
#define __MAIN_H__

#ifdef BUILD_DLL
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT __declspec(dllimport)
#endif


#ifdef __cplusplus
extern "C"
{
#endif

#include <windows.h>

#ifdef __cplusplus
}
#endif

#endif // __MAIN_H__
