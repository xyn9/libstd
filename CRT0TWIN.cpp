// CRT0TWIN.cpp / libstd
// xyn9 <xyn9.mail@gmail.com>
// (CC) Attribution-NonCommercial-ShareAlike; http://creativecommons.org/licenses/by-nc-sa/3.0/





#pragma comment(linker, "/defaultlib:kernel32.lib")
#pragma comment(linker, "/OPT:NOWIN98")


// #pragma comment(linker, "/nodefaultlib:libc.lib")
// #pragma comment(linker, "/nodefaultlib:libcmt.lib")


//
#include <windows.h>
#include <tchar.h>
#include <shlwapi.h>
#pragma comment(lib, "shlwapi.lib")


//
#include "initterm.h"
// ------------------------------------------------------------





// ------------------------------------------------------------
//
#ifdef __cplusplus
extern "C"
#endif // __cplusplus
//
void __cdecl
//
#ifdef UNICODE
wWinMainCRTStartup(void)
#else
WinMainCRTStartup(void)
#endif
//
{
  //
  int result = -1;
  //
  STARTUPINFO si;
  //
  LPCTSTR raw_cmdline = GetCommandLine();
  LPTSTR cmdline = (LPTSTR)HeapAlloc(
  	GetProcessHeap()
  	, HEAP_ZERO_MEMORY
  	, (sizeof(raw_cmdline[0]) * (lstrlen(raw_cmdline) +1))
  );

  //
  _atexit_init();	// set up our minimal cheezy atexit table
  _initterm(__xc_a, __xc_z);	// Call C++ constructors
  //
  if(cmdline != NULL){
    //
    lstrcpy(cmdline, PathGetArgs(raw_cmdline));
  	//
  	si.dwFlags = 0;
  	GetStartupInfo(&si);
    //
    result = _tWinMain(
      GetModuleHandle(0)
      , 0
      , cmdline
      , (si.dwFlags&STARTF_USESHOWWINDOW ? si.wShowWindow : SW_SHOWDEFAULT)
    );
    //
    if(! HeapFree(GetProcessHeap(), 0, cmdline)){ result = -1; }
  }
  //
  _doexit();
  ExitProcess(result);
  //
}





//
