// ATOL.cpp / libstd
// xyn9 <xyn9.mail@gmail.com>
// (CC) Attribution-NonCommercial-ShareAlike; http://creativecommons.org/licenses/by-nc-sa/3.0/





//
#include <windows.h>
#include <tchar.h>


//
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


//
long __cdecl _ttol(LPCTSTR _str){
  //
  long num = 0;
  int sign = (_str[0] == _T('-'));
  // ------------------------------------------------------------
  for(
    int length=sign
    ; ((_str[length] >= _T('0')) && (_str[length] <= _T('9')))
    ; length++
  );
  length--;
  //
  for(int padding=1; (length >= sign); padding*=10, length--){
    num += long((_str[length] - _T('0')) * padding);
  }
  //
  return (sign ? ((~num) +1) : num);
}

//
int __cdecl _ttoi(LPCTSTR _str){ return (int)_ttol(_str); }


//
#ifdef __cplusplus
} // EXTERN_C_END
#endif // __cplusplus





//
