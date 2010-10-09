// libstd / _gettcs.c
// xyn9 <xyn9.mail@gmail.com>
// (CC) Attribution-NonCommercial-ShareAlike; http://creativecommons.org/licenses/by-nc-sa/3.0/





//
#pragma comment(linker, "/defaultlib:kernel32.lib")


//
#include <windows.h>
#include <tchar.h>
// ------------------------------------------------------------
//
_TINT __stdcall _gettch_s(void){
	//
  TCHAR ch = 0;
	HANDLE h_stdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD current_mode = 0;
	DWORD r_size = 0;
  //
	if(h_stdin != INVALID_HANDLE_VALUE){
		GetConsoleMode(h_stdin, &current_mode);
    SetConsoleMode(h_stdin, ENABLE_PROCESSED_INPUT);
    ReadConsole(h_stdin, &ch, 1, &r_size, 0);
		SetConsoleMode(h_stdin, current_mode);
	}
	//
	return ch;
}





// ------------------------------------------------------------
//
TCHAR* __cdecl _getts_s(TCHAR *_buffer, size_t _length){
	//
	HANDLE h_stdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD current_mode = 0;
	DWORD r_size = 0;

	//
	if(_length && (h_stdin != INVALID_HANDLE_VALUE)){
    //
		GetConsoleMode(h_stdin, &current_mode);
    SetConsoleMode(h_stdin, (ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT/* | ENABLE_PROCESSED_INPUT*/));
    //
    if(
	    ReadConsole(h_stdin, &_buffer[0], _length, &r_size, 0)
    	&& r_size
    	&& *_buffer
    ){
      _buffer[(r_size -1)] = 0;
      if(_buffer[(r_size -2)] == _T('\r')){ _buffer[(r_size -2)] = 0; }
    }
    //
		SetConsoleMode(h_stdin, current_mode);
	}
	//
	return _buffer;
}





//
