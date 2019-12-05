#ifndef VIDEO_H_INCLUDED
#define VIDEO_H_INCLUDED

#ifdef BUILD_DLL
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT __declspec(dllimport)
#endif

#include <malloc.h>

#ifdef __cplusplus
extern "C"
{
#endif

#include <windows.h>
#include "vector.h"
#include "defines.h"

struct DLL_EXPORT WFP_PixelBuffSector
{
    unsigned short id;

    unsigned char* pixels = new unsigned char [WFP_PIXBUFFSECTOR_SIZERGBA];

    WFP_PixelBuffSector *ptr_next=new WFP_PixelBuffSector;

    WFP_PixelBuffSector();
    WFP_PixelBuffSector(void *bytes,unsigned short size,short id,bool type);
};

class DLL_EXPORT WFP_PixelBuff
{
private:
    WFP_PixelBuffSector *ptr_begin=new WFP_PixelBuffSector;
    WFP_PixelBuffSector *ptr_end=new WFP_PixelBuffSector;
    unsigned int size;
    unsigned int endid;
public:
    WFP_PixBuff();
    WFP_PixBuff(unsigned int size,WFP_PixelBuffSector*);
    WFP_PixBuff(unsigned int size,unsigned int endid,WFP_PixelBuffSector*,WFP_PixelBuffSector*);
    WFP_PixelBuffSector* getPBSbegin();
    WFP_PixelBuffSector* getPBSend();
};
class DLL_EXPORT WFP_Texture
{
private:
    unsigned short w,h;
    WFP_PixelBuff* pixelbuff=new WFP_PixelBuff;

public:
    WFP_Texture();
    WFP_Texture(WFP_PixelBuff*,int w,int h);

    //getters
    int getW();
    int getH();

};

#ifdef __cplusplus
}
#endif
#endif // VIDEO_H_INCLUDED
