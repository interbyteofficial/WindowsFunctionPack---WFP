#ifdef BUILD_DLL
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT __declspec(dllimport)
#endif

#include <windows.h>
#include "Core/eventsystem.h"
#include "Core/window.h"
#include "Core/defines.h"

DLL_EXPORT WFP_EventHolder::WFP_EventHolder(int event,int param,char key)
    : event(event), param(param), key(key)
{

}

DLL_EXPORT WFP_EventSystem::WFP_EventSystem()
{

}

void DLL_EXPORT WFP_EventSystem::setEvent(WFP_EventHolder event)
{
    eventh=event;
}

WFP_EventHolder DLL_EXPORT WFP_EventSystem::getEvent()
{
    return eventh;
}

WFP_EventHolder WFP_EventSystem::eventh;
