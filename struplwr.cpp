// struplwr.cpp / libstd
// xyn9 <xyn9.mail@gmail.com>
// (CC) Attribution-NonCommercial-ShareAlike; http://creativecommons.org/licenses/by-nc-sa/3.0/





//
#include <windows.h>
#include <string.h>
#include <tchar.h>


//
#pragma comment(linker, "/defaultlib:user32.lib")


//
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


//
LPTSTR  __cdecl _tcsupr(LPTSTR _s){
  CharUpperBuff(_s, lstrlen(_s));
  return _s;
}
//
LPTSTR  __cdecl _tcslwr(LPTSTR _s){
  CharLowerBuff(_s, lstrlen(_s));
  return _s;
}


//
#ifdef __cplusplus
} // EXTERN_C_END
#endif // __cplusplus





//
