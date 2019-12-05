#ifndef WINDOW_H_INCLUDED
#define WINDOW_H_INCLUDED

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
#include "vector.h"
#include "system.h"
#include "eventsystem.h"
#include "defines.h"

class DLL_EXPORT WFP_Window
{
private:
    WFP_Pos wpos;
    WFP_Size wsize;
    const char* wclassname;
    const char* wname;

    WNDCLASS wndclass;
    HINSTANCE hinst;
    HWND hwnd;
    MSG msg;

    WFP_Error* error;

    bool wrun;

    static LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
public:
    WFP_Window();
    WFP_Window(WFP_Size);
    WFP_Window(WFP_Size,const char*);
    WFP_Window(WFP_Size,WFP_Pos,const char* ="WFP Window");

    void close();

    bool isRun();
    WFP_Error* getError();
    WFP_EventHolder getEventHolder();
};

#ifdef __cplusplus
}
#endif
#endif // WINDOW_H_INCLUDED
