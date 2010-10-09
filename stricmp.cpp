// libstd / stricmp.cpp
// xyn9 <xyn9.mail@gmail.com>
// (CC) Attribution-NonCommercial-ShareAlike; http://creativecommons.org/licenses/by-nc-sa/3.0/





//
#include <windows.h>
#include <string.h>
#include <tchar.h>


//
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


//
int __cdecl _strcmpi(LPCTSTR _s1, LPCTSTR _s2){
  return lstrcmpi( _s1, _s2 );
}

//
int __cdecl _tcsicmp(LPCTSTR _s1, LPCTSTR _s2){
  return lstrcmpi( _s1, _s2 );
}


//
#ifdef __cplusplus
} // EXTERN_C_END
#endif // __cplusplus





//
