#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

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

struct DLL_EXPORT WFP_Vec2i{
    union{ int x; int w; };
    union{ int y; int h; };
    WFP_Vec2i();
    WFP_Vec2i(int,int);
};

struct DLL_EXPORT WFP_Vec3i{
    union{ int x; int r; };
    union{ int y; int g; };
    union{ int z; int b; };
    WFP_Vec3i();
    WFP_Vec3i(int,int,int);
};

struct DLL_EXPORT WFP_Vec4i{
    union{ int x; int r; };
    union{ int y; int g; };
    union{ int w; int b; };
    union{ int h; int a; };
    WFP_Vec4i();
    WFP_Vec4i(int,int,int,int);
    WFP_Vec4i(WFP_Vec2i&,WFP_Vec2i&);
    WFP_Vec4i(WFP_Vec3i&,int);
};

struct DLL_EXPORT WFP_Pos : public WFP_Vec2i{
    WFP_Pos();
    WFP_Pos(int,int);
};

struct DLL_EXPORT WFP_Size : public WFP_Vec2i{
    WFP_Size();
    WFP_Size(int,int);
};

struct DLL_EXPORT WFP_PixelBuffer
{
    static unsigned long int maxw;
    static unsigned long int maxh;
    unsigned int w;
    unsigned int h;
    unsigned char* pixels;

};
#ifdef __cplusplus
}
#endif
#endif // VECTOR_H_INCLUDED
