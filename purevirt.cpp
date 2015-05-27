// purevirt.cpp / libstd
// xyn9 <xyn9.mail@gmail.com>
// (CC) Attribution-NonCommercial-ShareAlike; http://creativecommons.org/licenses/by-nc-sa/3.0/





// LIBCTINY - Matt Pietrek 2001
// MSDN Magazine, January 2001
// http://www.wheaty.net/downloads.htm


#include <windows.h>


int __cdecl _purecall(void)
  {
  ExitProcess(13);
  // egad! this is never reached!
  return 0;
  }





//
