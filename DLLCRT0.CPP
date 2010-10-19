// libstd / DLLCRT0.CPP
// xyn9 <xyn9.mail@gmail.com>
// (CC) Attribution-NonCommercial-ShareAlike; http://creativecommons.org/licenses/by-nc-sa/3.0/





// LIBCTINY - Matt Pietrek 2001
// MSDN Magazine, January 2001
// http://www.wheaty.net/downloads.htm
// FILE: DLLCRT0.CPP


#include <windows.h>
#include "initterm.h"
#pragma comment(linker, "/defaultlib:kernel32.lib")
#pragma comment(linker, "/OPT:NOWIN98")

// #pragma comment(linker, "/nodefaultlib:libc.lib")
// #pragma comment(linker, "/nodefaultlib:libcmt.lib")

// User routine DllMain is called on all notifications

extern BOOL WINAPI DllMain(
        HANDLE  hDllHandle,
        DWORD   dwReason,
        LPVOID  lpreserved
        ) ;

//
// Modified version of the Visual C++ startup code.  Simplified to
// make it easier to read.  Only supports ANSI programs.
//
#ifdef __cplusplus
extern "C"
#endif // __cplusplus
//
BOOL WINAPI _DllMainCRTStartup(
        HANDLE  hDllHandle,
        DWORD   dwReason,
        LPVOID  lpreserved
        )
{
    if ( dwReason == DLL_PROCESS_ATTACH )
    {
        // set up our minimal cheezy atexit table
        _atexit_init();

        // Call C++ constructors
        _initterm( __xc_a, __xc_z );
    }

    BOOL retcode = DllMain(hDllHandle, dwReason, lpreserved);

    if ( dwReason == DLL_PROCESS_DETACH )
    {
        _doexit();
    }

    return retcode ;
}





//
