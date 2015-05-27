// _putts.c / libstd
// xyn9 <xyn9.mail@gmail.com>
// (CC) Attribution-NonCommercial-ShareAlike; http://creativecommons.org/licenses/by-nc-sa/3.0/





//
#include <windows.h>
#include <tchar.h>


//
#pragma comment(linker, "/defaultlib:user32.lib")


//
DWORD __cdecl _putts(LPCTSTR _buff){
  //
  DWORD writed_size;
  HANDLE h_std = GetStdHandle(STD_OUTPUT_HANDLE);
  //
  return (
    (h_std && WriteFile(h_std, _buff, lstrlen(_buff), &writed_size, NULL))
    ? writed_size
    : 0
  );
}





//
