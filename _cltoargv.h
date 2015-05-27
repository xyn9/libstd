// _cltoargv.h / libstd
// xyn9 <xyn9.mail@gmail.com>
// (CC) Attribution-NonCommercial-ShareAlike; http://creativecommons.org/licenses/by-nc-sa/3.0/



#ifndef ____CLTOARGV_H__
#define ____CLTOARGV_H__


//
#include <windows.h>
#include <tchar.h>


//
// ------------------------------------------------------------
#ifdef __cplusplus
extern "C"
#endif // __cplusplus

size_t __cdecl _commandline_to_argv(LPTSTR _cmdline, LPTSTR *_argv, size_t _arg_size);





#endif // ____CLTOARGV_H__
