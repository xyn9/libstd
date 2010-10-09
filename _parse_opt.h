// libstd / _parse_opt.h
// xyn9 <xyn9.mail@gmail.com>
// (CC) Attribution-NonCommercial-ShareAlike; http://creativecommons.org/licenses/by-nc-sa/3.0/



#ifndef ___PARSE_OPT_H__
#define ___PARSE_OPT_H__





//
#include <windows.h>
#include <tchar.h>
#include <ctype.h>
// ------------------------------------------------------------





// constants
// ------------------------------------------------------------
#define _OPT_UNNAMED  0x00
#define _OPT_NAMED    0x01
#define _OPT_VALUE    0x02





// typedef
// ------------------------------------------------------------





// macros
// ------------------------------------------------------------
#define _TCH(_ch) ((char)(0xFF & _ch))





// prototypes
// ------------------------------------------------------------
#ifdef __cplusplus
  extern "C" {
#endif // __cplusplus


//
size_t __cdecl _parse_opt(LPTSTR _cmdline, LPTSTR _opt[], size_t _opt_size);
LPTSTR __cdecl _opt_pair(LPTSTR _param);
BOOL __cdecl _opt_keycmp(LPCTSTR _key, LPCTSTR _param, BOOL _icase);


#ifdef __cplusplus
  }
#endif // __cplusplus




//
#endif // ___PARSE_OPT_H__
