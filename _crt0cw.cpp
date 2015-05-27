// _crt0cw.cpp / libstd
// xyn9 <xyn9.mail@gmail.com>
// (CC) Attribution-NonCommercial-ShareAlike; http://creativecommons.org/licenses/by-nc-sa/3.0/






// LIBCTINY - Matt Pietrek 2001
// MSDN Magazine, January 2001
// http://www.wheaty.net/downloads.htm


#pragma comment(linker, "/defaultlib:kernel32.lib")
#pragma comment(linker, "/opt:nowin98")

//#pragma comment(linker, "/nodefaultlib:libc.lib")
//#pragma comment(linker, "/nodefaultlib:libcmt.lib")


//
#include <windows.h>


//
#include "initterm.h"
// ------------------------------------------------------------





// constants
// ------------------------------------------------------------
#ifdef _CONSOLE
#define _MAX_ARGV 32
#endif // _CONSOLE





// typedef
// ------------------------------------------------------------





// variables
// ------------------------------------------------------------





// prototypes
// ------------------------------------------------------------
#ifdef __cplusplus
extern "C"
#endif // __cplusplus
//
int __stdcall _startup(void);





// ------------------------------------------------------------
//
#ifdef __cplusplus
extern "C"
#endif // __cplusplus
//
void __cdecl

#ifdef _CONSOLE // _CONSOLE

  #ifdef UNICODE
wmainCRTStartup(void)
  #else
mainCRTStartup(void)
  #endif

#else

  #ifdef UNICODE
wWinMainCRTStartup(void)
  #else
WinMainCRTStartup(void)
  #endif

#endif
//
{
  //
  int result = -1;
  //
  _atexit_init();	// set up our minimal cheezy atexit table
  _initterm(__xc_a, __xc_z);	// Call C++ constructors
  //
  result = _startup();
  //
  _doexit();
  ExitProcess(result);
  //
}





//
