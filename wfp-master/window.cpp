#ifdef BUILD_DLL
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C"
{

#include <windows.h>
#include <iostream>
#include "Core/window.h"
#include "Core/vector.h"
#include "Core/system.h"
#include "Core/eventsystem.h"
#include "Core/defines.h"
#endif

DLL_EXPORT WFP_Window::WFP_Window()
    : wpos(), wsize(), error(NULL), wrun(false)
{

}

DLL_EXPORT WFP_Window::WFP_Window(WFP_Size size)
    : WFP_Window(size,WFP_Pos(CW_USEDEFAULT,CW_USEDEFAULT),"WFP Window")
{

}

DLL_EXPORT WFP_Window::WFP_Window(WFP_Size size,const char* name)
    : WFP_Window(size,WFP_Pos(CW_USEDEFAULT,CW_USEDEFAULT),name)
{

}
DLL_EXPORT WFP_Window::WFP_Window(WFP_Size size,WFP_Pos pos,const char* name)
    : wpos(pos), wsize(size), wname(name), wclassname((std::string(name)+"_WFP_vladyanchuk").c_str()), error(NULL), wrun(false)
{
    wndclass={};
    wndclass.lpszClassName=wclassname;
    wndclass.hInstance=hinst;
    wndclass.lpfnWndProc=WndProc;
    if(!RegisterClass(&wndclass)){
        error=WFP_CreateError(WFP_ERROR_WNDCLASSREG,"wndclass_null");
        return;
    }

    hwnd = CreateWindowEx(0,                       //window styles
                            wclassname,//class name
                            wname,    //window title
                            WS_OVERLAPPEDWINDOW,     //window style
                            wpos.x,           //position x (default)
                            wpos.y,           //position y (default)
                            wsize.x,                //size w
                            wsize.y,                //size h
                            NULL,                    //parent window
                            NULL,                    //menu
                            hinst,                   //hinstance
                            NULL);                   //additional application data
    if(!hwnd){
        error=WFP_CreateError(WFP_ERROR_HWNDCREATE,"windowhwnd_null");
        return;
    }
    ShowWindow(hwnd,1);
    WFP_EventSystem::setEvent(WFP_EventHolder());
    wrun=true;

}

LRESULT CALLBACK WFP_Window::WndProc(HWND hwnd,UINT msg,WPARAM wparam,LPARAM lparam)
{
    switch(msg)
    {
    case WM_CLOSE:
        WFP_EventSystem::setEvent(WFP_EventHolder(WFP_EVENT_CLOSE));
        break;

    //MOUSE
    //doubleclick
    case WM_LBUTTONDBLCLK:
        WFP_EventSystem::setEvent(WFP_EventHolder(WFP_EVENT_MOUSEDBLCLICK,WFP_EVENTPARAM_LEFT));
        break;
    case WM_RBUTTONDBLCLK:
        WFP_EventSystem::setEvent(WFP_EventHolder(WFP_EVENT_MOUSEDBLCLICK,WFP_EVENTPARAM_RIGHT));
        break;

    //up
    case WM_LBUTTONUP:
        WFP_EventSystem::setEvent(WFP_EventHolder(WFP_EVENT_MOUSEUP,WFP_EVENTPARAM_LEFT));
        break;
    case WM_RBUTTONUP:
        WFP_EventSystem::setEvent(WFP_EventHolder(WFP_EVENT_MOUSEUP,WFP_EVENTPARAM_RIGHT));
        break;

    //down
    case WM_LBUTTONDOWN:
        WFP_EventSystem::setEvent(WFP_EventHolder(WFP_EVENT_MOUSEDOWN,WFP_EVENTPARAM_LEFT));
        break;
    case WM_RBUTTONDOWN:
        WFP_EventSystem::setEvent(WFP_EventHolder(WFP_EVENT_MOUSEDOWN,WFP_EVENTPARAM_RIGHT));
        break;

    //KEYBOARD
    case WM_CHAR:
        switch(wparam){

        }
    default:
        WFP_EventSystem::setEvent(WFP_EventHolder());
        return DefWindowProc(hwnd, msg, wparam, lparam);
    }
}

void DLL_EXPORT WFP_Window::close(){
    PostQuitMessage(0);
}

DLL_EXPORT WFP_EventHolder WFP_Window::getEventHolder(){
    WFP_EventSystem::setEvent(WFP_EventHolder());
    if(GetMessage(&msg,NULL,0,0)){
        DispatchMessage(&msg);
        TranslateMessage(&msg);
        return WFP_EventSystem::getEvent();
    }
    wrun=false;
    return WFP_EventSystem::getEvent();
}

DLL_EXPORT WFP_Error* WFP_Window::getError(){
    return error;
}

DLL_EXPORT bool WFP_Window::isRun(){
    return wrun;
}

#ifdef __cplusplus
}
#endif
