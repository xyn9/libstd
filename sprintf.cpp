// sprintf.cpp / libstd
// xyn9 <xyn9.mail@gmail.com>
// (CC) Attribution-NonCommercial-ShareAlike; http://creativecommons.org/licenses/by-nc-sa/3.0/





// Tiny C Runtime Library
// By Mike_V
// http://www.codeproject.com/KB/library/tlibc.aspx
// based on:
// LIBCTINY - Matt Pietrek 2001
// MSDN Magazine, January 2001
// http://www.wheaty.net/downloads.htm
// 08/13/06 (mv)


//
#include <windows.h>
#include <stdio.h>

#define EOF     (-1)
#pragma comment(linker, "/defaultlib:user32.lib")


//
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


//
int sprintf(char *buffer, const char *format, ...)
{
    int retValue;
    va_list argptr;

    va_start(argptr, format);
    retValue = vsprintf(buffer, format, argptr);
    va_end(argptr);

    return retValue;
}

//
int _snprintf(char *dest, size_t n, const char *fmt, ...)
{
  n;

  va_list args;
  va_start(args, fmt);
  int retValue = vsprintf(dest, fmt, args);
  va_end(args);
  return retValue;
}

//
int vsnprintf(char *dest, size_t n, const char *fmt, va_list args)
{
  n;
  return vsprintf(dest, fmt, args);
}


//
#ifdef __cplusplus
} // EXTERN_C_END
#endif // __cplusplus





//
