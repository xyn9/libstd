// printf.cpp / libstd
// xyn9 <xyn9.mail@gmail.com>
// (CC) Attribution-NonCommercial-ShareAlike; http://creativecommons.org/licenses/by-nc-sa/3.0/





//
#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <stdarg.h>


//
#pragma comment(linker, "/defaultlib:user32.lib")


//
#ifdef __cplusplus
extern "C"
#endif // __cplusplus
//
int __cdecl _tprintf(LPCTSTR _format, ...){
  //
  TCHAR buff[1024];
  va_list argptr;
  DWORD writed_size = 0;
  //
  va_start(argptr, _format);
  writed_size = wvsprintf(buff, _format, argptr);
  va_end(argptr);
  writed_size = writed_size ? _putts(buff) : 0;
  //
  return writed_size;
}





//
