#include "Core/system.h"
#include <windows.h>
#include <iostream>

#ifdef BUILD_DLL
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT __declspec(dllimport)
#endif

WFP_Error* DLL_EXPORT WFP_CreateError(int id,const char* error)
{
    WFP_Error wfperror={id,error};
    return &wfperror;
}

void DLL_EXPORT WFP_DisplayError(WFP_Error* error){
    if(error==NULL)
        return;
    const char* text1 = "Program was terminated by runtime error in wpf.dll\n Try to check your code or update library";
    const char* text = (std::string(text1)+std::string("\nERRORID: ")+std::string(std::to_string(error->erorrid))+std::string("\nERRORDESC: ")+std::string(error->error_desc)).c_str();
    MessageBox(NULL,text,"WFP Error",MB_OK | MB_ICONERROR);
}
