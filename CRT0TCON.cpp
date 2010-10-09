// libstd / CRT0TCON.cpp
// xyn9 <xyn9.mail@gmail.com>
// (CC) Attribution-NonCommercial-ShareAlike; http://creativecommons.org/licenses/by-nc-sa/3.0/





//
#pragma comment(linker, "/defaultlib:kernel32.lib")
#pragma comment(linker, "/OPT:NOWIN98")
//
//#pragma comment(linker, "/nodefaultlib:libc.lib")
//#pragma comment(linker, "/nodefaultlib:libcmt.lib")


//
#include <windows.h>
#include <tchar.h>


//
#include "initterm.h"
#include "_cltoargv.h"
// ------------------------------------------------------------





// constants
// ------------------------------------------------------------
#define _MAX_ARGV 32





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


int __cdecl _tmain(int, TCHAR **, TCHAR **);





// ------------------------------------------------------------
//
void __cdecl
//
#ifdef UNICODE
wmainCRTStartup(void)
#else
mainCRTStartup(void)
#endif
//
{
	//
	int result = -1;
	//
	LPCTSTR raw_cmdline = GetCommandLine();
  LPTSTR cmdline = (LPTSTR)HeapAlloc(
  	GetProcessHeap()
  	, HEAP_ZERO_MEMORY
  	, (sizeof(raw_cmdline[0]) * (lstrlen(raw_cmdline) +1))
  );
	//
	int argc;
	LPTSTR argv[_MAX_ARGV +1];

  //
	_atexit_init();	// set up our minimal cheezy atexit table
	_initterm(__xc_a, __xc_z);	// Call C++ constructors
  //
  if(cmdline != NULL){
	  //
    lstrcpy(cmdline, raw_cmdline);
    argc = _commandline_to_argv(cmdline, argv, _MAX_ARGV);
    //
	  result = _tmain(argc, argv, 0);
	  //
    if(! HeapFree(GetProcessHeap(), 0, cmdline)){ result = -1; }
  }
  //
	_doexit();
	ExitProcess(result);
	//
}


//
#ifdef __cplusplus
} // EXTERN_C_END
#endif // __cplusplus





//
