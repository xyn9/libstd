// libstd / _cltoargv.cpp
// xyn9 <xyn9.mail@gmail.com>
// (CC) Attribution-NonCommercial-ShareAlike; http://creativecommons.org/licenses/by-nc-sa/3.0/





//
#include <windows.h>
#include <tchar.h>


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
 	size_t cmd_length = lstrlen(_cmdline);
  int pos;
  char q_ch;
	// ------------------------------------------------------------
	//
	for(
		pos=0,q_ch=0
		; ((argc<_arg_size) && (pos<cmd_length))
		; argc++
	){
		//
		for(; ((pos<=cmd_length) && _istspace(_cmdline[pos])); pos++){
			_cmdline[pos] = 0;
		}
		//
		if((_TCH(_cmdline[pos]) == '"') || (_TCH(_cmdline[pos]) == '\'')){
			//
			q_ch = _TCH(_cmdline[pos]);
			pos++;
			_argv[argc] = _cmdline +pos;
			//
			for(; (pos<cmd_length); pos++){
				//
				if(_TCH(_cmdline[pos]) == q_ch){
					_cmdline[pos] = 0;
					pos++;
					q_ch = 0;
					break;
				}
			}
			//
		}else{
			//
			_argv[argc] = _cmdline +pos;
			//
			for(; ((pos<cmd_length) && (! _istspace(_cmdline[pos]))); pos++){}
		}
		//
	}
  //
  return argc;
  //
}





//
