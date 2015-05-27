// _startup.cpp / libstd
// xyn9 <xyn9.mail@gmail.com>
// (CC) Attribution-NonCommercial-ShareAlike; http://creativecommons.org/licenses/by-nc-sa/3.0/





//
#include "./libstd.h"


//
#ifdef _CONSOLE
#endif // _CONSOLE


//
#ifdef _WINDOWS
#include <shlwapi.h>
#pragma comment(lib, "shlwapi.lib")
#endif // _WINDOWS


//
// #include ".h"
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
//
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


//
int __stdcall _startup(void);

//
#ifdef _CONSOLE

int __cdecl _tmain(int, TCHAR **, TCHAR **);

#endif // _CONSOLE


//
#ifdef __cplusplus
} // EXTERN_C_END
#endif // __cplusplus





// main
// ------------------------------------------------------------
#ifdef __cplusplus
extern "C"
#endif // __cplusplus
//
int __stdcall _startup(void){
//

  //
  int result = -1;

//
#ifdef _CONSOLE
  int argc;
  LPTSTR argv[_MAX_ARGV +1];
#endif // _CONSOLE

//
#ifdef _WINDOWS
  STARTUPINFO si;
#endif // _WINDOWS

  //
  LPCTSTR raw_cmdline = GetCommandLine();
  LPTSTR cmdline = (LPTSTR)HeapAlloc(
  	GetProcessHeap()
  	, HEAP_ZERO_MEMORY
  	, (sizeof(raw_cmdline[0]) * (lstrlen(raw_cmdline) +1))
  );

  //
  if(cmdline != NULL){
  	//
  	lstrcpy(cmdline, raw_cmdline);
//
#ifdef _CONSOLE
  	argc = _commandline_to_argv(cmdline, argv, _MAX_ARGV);
  	result = _tmain(argc, argv, 0);
  	//
#endif // _CONSOLE

//
#ifdef _WINDOWS
  	//
  	si.dwFlags = 0;
  	GetStartupInfo(&si);
  	//
  	result = _tWinMain(
  		GetModuleHandle(0)
  		, 0
  		, PathGetArgs(cmdline)
      , ((si.dwFlags & STARTF_USESHOWWINDOW) ? si.wShowWindow : SW_SHOWDEFAULT)
  	);
  	//
#endif // _WINDOWS

  	//
  	if(! HeapFree(GetProcessHeap(), 0, cmdline)){ result = -1; }
  	//
  }
  //
  return result;
  //
}





//
