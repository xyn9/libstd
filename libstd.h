// libstd / libstd.h
// xyn9 <xyn9.mail@gmail.com>
// (CC) Attribution-NonCommercial-ShareAlike; http://creativecommons.org/licenses/by-nc-sa/3.0/



#ifndef ___LIBSTD_H__
#define ___LIBSTD_H__


//
#include <windows.h>
#include <tchar.h>
//
#include <ctype.h>
// ------------------------------------------------------------

//
#ifdef _USE_LIBSTD

	#ifdef _DEBUG
/*
#pragma comment(lib, "./libstd_d.lib")
#pragma comment(linker, "/nodefaultlib:libcd.lib")
 */
	#else // _DEBUG
#pragma comment(lib, "./libstd.lib")
#pragma comment(linker, "/nodefaultlib:libc.lib")
	#endif // _DEBUG

#endif

//
#ifdef _USE_LIBSTD_MT

	#ifdef _DEBUG
/*
#pragma comment(lib, "./libstd_mt_d.lib")
#pragma comment(linker, "/nodefaultlib:libcmtd.lib")
 */
	#else // _DEBUG
#pragma comment(lib, "./libstd_mt.lib")
#pragma comment(linker, "/nodefaultlib:libcmt.lib")
	#endif // _DEBUG

#endif // _USE_LIBSTD_MT





// constants
// ------------------------------------------------------------





// typedef
// ------------------------------------------------------------





// variables
// ------------------------------------------------------------





// macros
// ------------------------------------------------------------
#define _TCH(_ch) ((char)(0xFF & _ch))





// prototypes
// ------------------------------------------------------------


//
#ifdef __cplusplus
  extern "C" { // extern "C"
#endif


//
#ifdef _CONSOLE

//
int __cdecl _commandline_to_argv(LPTSTR, LPTSTR*, const int);

	//
	#ifdef NDEBUG
TCHAR* __cdecl _getts_s(TCHAR*, size_t);
#define _gets(_buffer) _getts_s(_buffer, ((sizeof(_buffer)/sizeof(_buffer[0]))-1))
_TINT __stdcall _gettch_s(void);
#define _getch _gettch_s
	#endif // NDEBUG

//
#endif // _CONSOLE


//
#ifdef __cplusplus
  } // extern "C"
#endif





//
#endif // ___LIBSTD_H__
