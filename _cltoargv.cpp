// _cltoargv.cpp / libstd
// xyn9 <xyn9.mail@gmail.com>
// (CC) Attribution-NonCommercial-ShareAlike; http://creativecommons.org/licenses/by-nc-sa/3.0/





//
#include <windows.h>
#include <tchar.h>
// ------------------------------------------------------------
#pragma warning(disable:4706)





// macros
// ------------------------------------------------------------
#define _TCH(_ch) ((char)(0xFF & _ch))





//
// ------------------------------------------------------------
#ifdef __cplusplus
extern "C"
#endif // __cplusplus
//
size_t __cdecl _commandline_to_argv(
  LPTSTR _cmdline
  , LPTSTR *_argv, size_t _arg_size
){
  //
  size_t argc = 0;
  //
  int cmd_length = lstrlen(_cmdline);
  int pos = 0;
  char q_ch;

  //
  for(argc=0; argc<_arg_size; argc++){
    //
    for(; ((pos<cmd_length) && _istspace(_cmdline[pos])); pos++){ _cmdline[pos] = 0; }
    //
    if(pos >= cmd_length){ break; }
    //
    _argv[argc] = _cmdline + pos;
    q_ch = ' ';
    //
    if((pos<cmd_length) && ((_TCH(_cmdline[pos]) == '"') || (_TCH(_cmdline[pos]) == '\''))){
      //
      q_ch = _TCH(_cmdline[pos]);
      _argv[argc] = _cmdline + (++pos);
    }
    //
    for(; ((pos<cmd_length) && (_TCH(_cmdline[pos]) != q_ch)); pos++);
    (_TCH(_cmdline[pos]) == q_ch) && (_cmdline[pos] = 0);
    pos++;
    //
  }
  //
  return argc;
}





//
